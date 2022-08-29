package parser

/*

#include "cdef_north.h"

// jl - count of current c_outi calls
int current_c_outi_count;

// do we need to declare tracing functions; this is set when we hit a 'trace' pragma
int decl_trace = 0;

// currently processed file
char *filename;

// generate include directives
int gen_includes = 1;

// language to use for code generation; default is C++
lang_t lang = L_CPP;

// current line in current file
int lineno;

// initial maximum size of arrays
int init_max_array_size = 64;

// generate MSVC-style error messages
int msvc = 0;

// number of errors encountered
int nerrors = 0;

// generate null-terminated strings for arrays
int null_strings = 0;

// output file name and pointer used by the code generator (.h file, .java file, or .xsd file)
char ofile[MAX_LEN];
void* ofp = NULL;

// maximum size of arrays -- may change dynamically via pragma statements
int max_array_size;

// option settings
int w_cyclic = 0;
int w_includes = 0;

// our program name
const char program[] = "goflavor";

// this is the list of parsed statements; the entire input file ends up in this list
list_t *parsed_code = NULL;

extern uintptr_t yyin;
extern int yyparse();
extern int yylex_destroy();

*/
import "C"
import (
	"io"
	"os"
	"unsafe"

	"github.com/richinsley/goflavor/symbol"
)

func ParseReader(reader io.Reader, filename string) *symbol.List_t {
	C.filename = C.CString(filename)
	wf := GF_WrapReader(reader)
	C.yyin = wf
	C.s_init()
	C.lineno = 1
	C.current_c_outi_count = 0
	C.max_array_size = C.init_max_array_size
	C.yyparse()
	GF_Close(C.yyin)

	// CtoGo_list wants (symbol._Ctype_struct__list_t not our own import *_Ctype_struct__list_t
	pi := unsafe.Pointer(C.parsed_code)
	return symbol.CtoGo_list_unsafe(pi)
}

func ParseFile(filename string) *symbol.List_t {
	C.filename = C.CString(filename)
	f, _ := os.OpenFile(filename, os.O_RDONLY, 0755)
	wf := GF_WrapFile(f)
	C.yyin = wf
	C.s_init()
	C.lineno = 1
	C.current_c_outi_count = 0
	C.max_array_size = C.init_max_array_size
	C.yyparse()
	GF_Close(C.yyin)

	// CtoGo_list wants (symbol._Ctype_struct__list_t not our own import *_Ctype_struct__list_t
	pi := unsafe.Pointer(C.parsed_code)
	return symbol.CtoGo_list_unsafe(pi)
}

func Cleanup() {
	C.yylex_destroy()
	C.parsed_code = nil
}
