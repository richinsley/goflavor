package compiler

import (
	"fmt"
	"io"
	"os"
	"strings"

	"example.com/goflav/symbol"
)

type CompilerContext struct {
	Symbols         *symbol.List_t
	Program         string
	Filename        string
	OutputFiles     map[string]io.Writer
	OutputFileNames map[string]string
	ErrorFunc       string
	TraceFunc       string
	BitstreamClass  string
	MaxArraySize    int
	// prefix to use for Flavor variables
	Prefix string

	// original globals
	// generate put method
	Gen_put bool

	// generate get method
	Gen_get bool

	// generate include directives
	Gen_includes bool

	// generate tracing code
	Gen_trace bool

	// do we need to declare tracing functions; this is set when we hit a 'trace' pragma
	Decl_trace bool

	// generate MSVC-style error messages
	Msvc bool

	// current indenttion level
	c_identlevel int

	// indentation string
	c_ident_str string

	// current line limber
	lineno int

	// language scope
	c_scope string

	// language static scope
	c_static_scope string

	// language shared pointer type
	c_shared_pointer_type string

	// language array type
	c_array_type string

	w_abstract bool

	// parse only - don't generate any code
	parse_only bool
}

func NewCompilerContext(symbols *symbol.List_t) *CompilerContext {
	retv := &CompilerContext{}
	retv.Symbols = symbols
	retv.OutputFileNames = make(map[string]string)
	retv.OutputFiles = make(map[string]io.Writer)
	retv.MaxArraySize = 64
	retv.ErrorFunc = "flerror"
	retv.TraceFunc = "trace"
	retv.BitstreamClass = "IBitstream"
	retv.Prefix = "_F_"
	retv.Gen_put = true
	retv.Gen_get = true
	retv.Gen_trace = false
	retv.Decl_trace = false
	retv.TraceFunc = "trace"
	retv.Msvc = false
	retv.c_identlevel = 0
	retv.c_ident_str = "    "
	retv.lineno = 0
	retv.c_scope = "->"
	retv.c_static_scope = "::"
	retv.c_shared_pointer_type = "std::shared_ptr"
	retv.c_array_type = "flavor::SmallVector"
	retv.w_abstract = false
	retv.parse_only = false
	return retv
}

func (c *CompilerContext) Compile() {
	// generate the headers for hpp and cpp
	c.header()

	// output our default max array size value
	c.c_out(c.OutputFiles["header"], "#include <flavor.h>\n")
	c.c_out(c.OutputFiles["header"], "// initial prealloc size of parsable arrays: %d\n\n", c.MaxArraySize)

	// declare error reporting function
	// moved to flavor.h
	// c.c_out(c.OutputFiles["header"], "// bitstream error reporting function\nvoid %s(const char* fmt, ...);\n\n", c.ErrorFunc)

	// declare tracing functions
	if (c.Gen_get) && (c.Gen_trace || c.Decl_trace) {
		c.c_out(c.OutputFiles["header"], "// tracing functions\n"+
			"void %s(int pos, int size, unsigned int val, char* fmt, ...);\n"+
			"void %s(int pos, int size, double val, char* fmt, ...);\n\n", c.TraceFunc, c.TraceFunc)
	}

	// disable unreferenced local variable warning for MS Visual C++
	if c.Msvc {
		c.c_out(c.OutputFiles["header"], "// disable unreferenced local variable warning in MS Visual C++\n")
		c.c_out(c.OutputFiles["header"], "#pragma warning(disable: 4101)\n")
	}

	p := c.Symbols
	for p != nil {
		// skip included statements
		if p.Included != 0 {
			p = p.Next
			continue
		}

		switch p.Type {
		case symbol.DECL:
			if p.Sp.Included == 0 {
				c.c_var_decl_ext(c.OutputFiles["header"], p.Sp, p.Dims, p.Dim)
				c.c_var_decl(c.OutputFiles["source"], p.Sp, p.Dims, p.Dim)
			}
		case symbol.VERBATIM:
			c.Verbatim(c.OutputFiles["header"], p.Vp)
		case symbol.CLASS:
			if p.Sp.Included == 0 {
				c.Class_decl(p.Sp, p.Sub1)
			}
		case symbol.MAP:
			if p.Sp.Included == 0 {
				c.Map_decl(p.Sp, p.Sub1)
			}
		case symbol.INCLUDE:
			c.c_out(c.OutputFiles["header"], "#include \"%s.hpp\"\n", p.E1.Left.GetString())
		case symbol.PUSHINCLUDE:
			c.c_out(c.OutputFiles["header"], "#include \"%s.hpp\"\n", p.E1.Left.GetString())
		case symbol.POPINCLUDE:
		case symbol.IMPORT:
			c.c_outi(c.OutputFiles["header"], "// import \"%s\"\n", p.E1.Left.GetString())
		default:
			fmt.Printf("Unknown symbol id %d", p.Type)
		}
		p = p.Next
	}

	// dump the trailer
	c.Trailer()

	// clean up cgo
	// symbol.Cleanup()
}

func (c *CompilerContext) Trailer() {
	if !c.parse_only {
		// sc := c.OutputFiles["source"]
		h := c.OutputFiles["header"]

		// translate '.' to '_'
		name := strings.ReplaceAll(basename(c.OutputFileNames["header"]), ".", "_")
		c.c_out(h, "\n#endif /* ! %s%s_ */\n", c.Prefix, name)
	}
}

// output error and terminate
func fatal(format string, data ...any) {
	fmt.Printf(format, data...)
	os.Exit(1)
}

var slineno int = 1

// output non-indented text
func (c *CompilerContext) c_out(w io.Writer, format string, data ...any) {
	f := fmt.Sprintf(format, data...)
	fmt.Fprintf(w, "%s", f)

	// if strings.Contains(f, "4294967295") {
	// 	fmt.Print("here")
	// }

	// fmt.Fprintf(w, format, data...)
}

// output indented text
func (c *CompilerContext) c_outi(w io.Writer, format string, data ...any) {
	f := fmt.Sprintf(format, data...)
	c.c_ident(w)
	c.c_out(w, "%s", f)
}

// generate correct identation, according to c_identlevel
func (c *CompilerContext) c_ident(w io.Writer) {
	for i := 0; i < c.c_identlevel; i++ {
		c.c_out(w, c.c_ident_str)
	}
}

func (c *CompilerContext) indent() {
	c.c_identlevel++
}

func (c *CompilerContext) outdent() {
	c.c_identlevel--
}
