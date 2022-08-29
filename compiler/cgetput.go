package compiler

import (
	"io"

	"github.com/richinsley/goflav/symbol"
)

func (c *CompilerContext) c_class_isidof(sp *symbol.Symbol_t) {
	sc := c.OutputFiles["source"]
	c.c_outi(sc, "\n")
	c.c_outi(sc, "int %s::%sisidof(%s tag) {\n", sp.Name, c.Prefix, sp.Id.Ptype.Name)
	c.indent()
	cnt := c.c_class_isidof_check_id(sp, 0)
	if cnt > 0 {
		c.c_outi(sc, "else\n")
		c.indent()
		c.c_outi(sc, "return 0;\n")
		c.outdent()
	} else {
		c.c_outi(sc, "return 0;\n")
	}
	c.outdent()
	c.c_outi(sc, "}\n")
}

// for cpp, can target header or source
func (c *CompilerContext) c_param_list(w io.Writer, vars *symbol.List_t) {
	lp := vars
	for lp != nil {
		if lp.Type != symbol.DECL {
			fatal("Internal error: Expected declaration in parameter list")
		}
		c.c_out(w, "%s%s", S_mods2str(lp.Sp.Modifiers), lp.Sp.Ptype.Name)

		if lp.Sp.Ptype.Ident == symbol.CLASS_TYPE {
			// class variable
			c.c_out(w, " *%s", lp.Sp.Name)
		} else {
			// regular variable
			if lp.Sp.Dims == 0 {
				c.c_out(w, " %s", lp.Sp.Name)
			} else {
				c.c_out(w, " (&%s)", lp.Sp.Name)
				if lp.Sp.Dims > 0 {
					for i := 0; i < lp.Sp.Dims; i++ {
						c.c_out(w, "[%d]", c.MaxArraySize)
					}
				}
			}
		}

		if lp.Next != nil {
			c.c_out(w, ", ")
		}
		lp = lp.Next
	}
}

func (c *CompilerContext) c_param_list_getput(vars *symbol.List_t) {
	sc := c.OutputFiles["source"]
	lp := vars
	for lp != nil {
		if lp.Type != symbol.DECL {
			fatal("Internal error CG: Expected declaration in parameter list")
		}
		c.c_out(sc, "%s", lp.Sp.Name)
		if lp.Next != nil {
			c.c_out(sc, ", ")
		}
		lp = lp.Next
	}
}

func (c *CompilerContext) c_class_put(sp *symbol.Symbol_t, stmts *symbol.List_t) {
	sc := c.OutputFiles["source"]
	c.c_out(sc, "\n")

	c.c_outi(sc, "int %s::put(%s &%sbs", sp.Name, c.BitstreamClass, c.Prefix)

	// if we have parameters, declare them
	if sp.Param != nil {
		c.c_out(sc, ", ")
		c.c_param_list(sc, sp.Param)
	}

	// we need to pass id parse info if this or a base class has ID
	if c_find_id_notabstract(sp) != nil {
		c.c_out(sc, ", int %sid_parsed", c.Prefix)
	}
	c.c_out(sc, ")")

	c.c_out(sc, " {\n")
	c.indent()

	// declare our return value (0 means no errors)
	c.c_outi(sc, "int %sret = 0;\n", c.Prefix)

	// if the class contains array variables, then we need to declare appropriate tmp variables
	if sp.Max_dims > 0 {
		c.c_array_tmp_decl(sc, sp.Max_dims, sp.Dimx_end_var)
	}

	// declare tmp var that saves parse size (to preserve order of parse and init evaluations)
	if sp.Put_needs_parse_var != 0 {
		c.c_outi(sc, "int %sparse = 0;\n", c.Prefix)
	}

	// align, if necessary; note that the top clas-level align is *NOT* included in bit accounting
	if sp.Align != nil {
		c.c_outi(sc, "%sbs.align(", c.Prefix)
		c.c_expression(sc, sp.Align, false)
		c.c_out(sc, ");\n")
	}

	// if lengthof requested, mark bit position of start of class
	if sp.Lengthof != 0 {
		c.c_outi(sc, "%slengthof = %sbs.getpos();\n", c.Prefix, c.Prefix)
	}

	// output our id, if needed
	c.c_class_id_put(sp)

	// see if it is a derived class
	if sp.Ptype != nil {
		c.c_outi(sc, "%sret += %s::put(%sbs", c.Prefix, sp.Ptype.Name, c.Prefix)

		// if we have params, include them
		if sp.Param != nil {
			c.c_out(sc, ", ")
			c.c_param_list_getput(sp.Param)
		}

		// pass along id parse info
		if c_find_id_notabstract(sp.Ptype) != nil {
			c.c_out(sc, ", %sid_parsed", c.Prefix)
		}
		c.c_out(sc, ");\n")
	}

	c.c_stmts_put(stmts)

	// if lengthof requested, compute total bits
	if sp.Lengthof != 0 {
		c.c_outi(sc, "%slengthof = %sbs.getpos()-%slengthof;\n", c.Prefix, c.Prefix, c.Prefix)
	}

	// output return statement
	c.c_outi(sc, "return %sret;\n", c.Prefix)

	c.outdent()
	c.c_outi(sc, "}\n")

	// Item_t is broken.  Pointer getter always returns nil
	// refactor c item_t to have an enum that specifies the type
	// we can then use a normal golang struct to hold the various types

	// the type is specified y.tab.h and is generated via %union
	// in the Bison parser.y file:
	// https://www.gnu.org/software/bison/manual/html_node/Union-Decl.html

	// the first point of failure occurs in GetNode in item.go always returning nil
	// @ln 70

	// good article on golang yacc here:
	// https://mhamrah.medium.com/lexing-with-ragel-and-parsing-with-yacc-using-go-81e50475f88f
}

func (c *CompilerContext) c_class_get(sp *symbol.Symbol_t, stmts *symbol.List_t) {
	sc := c.OutputFiles["source"]
	c.c_out(sc, "\n")

	// We need to pass ID parse info if this or a superclass has an ID.
	c.c_outi(sc, "int %s::get(%s &%sbs", sp.Name, c.BitstreamClass, c.Prefix)

	if sp.Param != nil {
		c.c_out(sc, ", ")
		c.c_param_list(sc, sp.Param)
	}

	// we need to pass id parse info if this or a superclass (non-abstract) has ID
	if c_find_id_notabstract(sp) != nil {
		c.c_out(sc, ", int %sid_parsed", c.Prefix)
	}
	c.c_out(sc, ")")
	c.c_out(sc, " {\n")

	// now we are inside the get() method
	c.indent()

	// declare our return value (0 means no errors)
	c.c_outi(sc, "int %sret = 0;\n", c.Prefix)

	// if the class contains array variables, then we need to declare appropriate tmp variables
	if sp.Max_dims > 0 {
		c.c_array_tmp_decl(sc, sp.Max_dims, sp.Dimx_end_var)
	}

	// declare id probe vars for all contained class vars with id
	c.c_class_get_decl_probe_id_vars(sp)

	// we may need to declare tmp var that saves parse size (so that parse expressions are evaluated once)
	if sp.Get_needs_parse_var != 0 {
		c.c_outi(sc, "int %sparse = 0;\n", c.Prefix)
	}
	if sp.Get_needs_code_var != 0 {
		c.c_outi(sc, "int %scode;\n", c.Prefix)
	}

	if c.Gen_trace {
		// c.c_trace_get_begin(sp)
	}

	// align, if needed; note that the top clas-level align is *NOT* included in bit accounting
	if sp.Align != nil {
		if c.Gen_trace {
			// // wave parse size
			// c_outi("%sparse = ", prefix);
			// c_expression(sp->align, 0);
			// c_out(";\n");
			// // do the align
			// c_outi("%sbs.align(%sparse);\n", prefix, prefix);
			// // trace
			// c_trace_aligned();
		} else {
			c.c_outi(sc, "%sbs.align(", c.Prefix)
			c.c_expression(sc, sp.Align, false)
			c.c_out(sc, ");\n")
		}
	}

	// if lengthof requested, mark bit position of start of class
	if sp.Lengthof != 0 {
		c.c_outi(sc, "%slengthof = %sbs.getpos();\n", c.Prefix, c.Prefix)
	}

	// get our id, if needed
	c.c_class_id_get(sp)

	// see if it is a derived class
	if sp.Ptype != nil {
		c.c_outi(sc, "%sret += %s::get(%sbs", c.Prefix, sp.Ptype.Name, c.Prefix)

		if sp.Param != nil {
			c.c_out(sc, ", ")
			c.c_param_list_getput(sp.Param)
		}

		// pass along id parse info
		if c_find_id_notabstract(sp.Ptype) != nil {
			c.c_out(sc, ", %sid_parsed", c.Prefix)
		}
		c.c_out(sc, ");\n")
	}

	c.c_stmts_get(stmts)

	// if lengthof requested, compute total bits
	if sp.Lengthof != 0 {
		c.c_outi(sc, "%slengthof = %sbs.getpos()-%slengthof;\n", c.Prefix, c.Prefix, c.Prefix)
	}

	// if tracing, signal the end of the get()
	if c.Gen_trace {
		// c_trace_get_end(sp)
	}

	// output return statement
	c.c_outi(sc, "return %sret;\n", c.Prefix)

	c.outdent()
	c.c_outi(sc, "}\n")
}

func (c *CompilerContext) c_stmts_get(stmts *symbol.List_t) {
	sc := c.OutputFiles["source"]

	lp := stmts
	for lp != nil {
		// skip included statements (and their sub-statements)
		if lp.Included != 0 {
			lp = lp.Next
			continue
		}

		switch lp.Type {
		case symbol.DECL:
			c.c_var_decl_get(lp.Sp, lp.E1, lp.E2, lp.E3, lp.Align, lp.Dims, lp.Dim, lp.Usenext)
		case '{':
			c.c_outi(sc, "{\n")
			c.indent()
			c.c_stmts_get(lp.Sub1)
			c.outdent()
			c.c_outi(sc, "}\n")
		case symbol.EXPR:
			c.c_ident(sc)
			c.c_expression(sc, lp.E1, false)
			c.c_out(sc, ";\n")
		case symbol.LABEL:
			c.outdent()
			c.c_outi(sc, "%s:\n", lp.Sp.Name)
			c.indent()
		case symbol.CASE:
			c.outdent()
			c.c_outi(sc, "case ")
			c.c_expression(sc, lp.E1, false)
			c.c_out(sc, ":\n")
			c.indent()
			c.c_stmts_get(lp.Sub1)
		case symbol.DEFAULT:
			c.outdent()
			c.c_outi(sc, "default:\n")
			c.indent()
			c.c_stmts_get(lp.Sub1)
		case symbol.IF:
			c.c_outi(sc, "if (")
			c.c_expression(sc, lp.E1, true)

			if lp.Sub1.Type != '{' {
				c.c_out(sc, ") {\n")
				c.indent()
				c.c_stmts_get(lp.Sub1)
				c.outdent()
				c.c_outi(sc, "}\n")
			} else {
				c.c_out(sc, ")\n")
				c.c_stmts_get(lp.Sub1)
			}

			if lp.Sub2 != nil {
				if lp.Sub2.Type != '{' {
					c.c_outi(sc, "else {\n")
					c.indent()
					c.c_stmts_get(lp.Sub2)
					c.outdent()
					c.c_outi(sc, "}\n")
				} else {
					c.c_outi(sc, "else\n")
					c.c_stmts_get(lp.Sub2)
				}
			}
			c.c_outi(sc, "\n")
		case symbol.SWITCH:
			c.c_outi(sc, "switch (")
			c.c_expression(sc, lp.E1, false)

			if lp.Sub1.Type != '{' {
				c.c_out(sc, ") {\n")
				c.indent()
				c.c_stmts_get(lp.Sub1)
				c.outdent()
				c.c_outi(sc, "}\n")
			} else {
				c.c_out(sc, ")\n")
				c.c_stmts_get(lp.Sub1)
			}
			c.c_outi(sc, "\n")
		case symbol.WHILE:
			c.c_outi(sc, "while (")
			c.c_expression(sc, lp.E1, true)
			c.c_out(sc, ") {\n")
			c.indent()

			if lp.Sub1.Type != '{' {
				c.c_stmts_get(lp.Sub1)
			} else {
				c.c_stmts_get(lp.Sub1.Sub1)
			}

			c.outdent()
			c.c_outi(sc, "}\n")
		case symbol.DO:
			c.c_outi(sc, "do {\n")
			c.indent()
			if lp.Sub1.Type != '{' {
				c.c_stmts_get(lp.Sub1)
			} else {
				c.c_stmts_get(lp.Sub1.Sub1)
			}

			c.outdent()
			c.c_outi(sc, "} while (")
			c.c_expression(sc, lp.E1, true)
			c.c_out(sc, ");\n")
		case symbol.FOR:
			c.c_outi(sc, "for (")
			c.c_expression(sc, lp.E1, false)
			c.c_out(sc, "; ")
			c.c_expression(sc, lp.E2, true)
			c.c_out(sc, "; ")
			c.c_expression(sc, lp.E3, false)
			c.c_out(sc, ") {\n")
			c.indent()
			if lp.Sub1.Type != '{' {
				c.c_stmts_get(lp.Sub1)
			} else {
				c.c_stmts_get(lp.Sub1.Sub1)
			}

			c.outdent()
			c.c_outi(sc, "}\n")
		case symbol.GOTO:
			c.c_outi(sc, "goto %s;\n", lp.Sp.Name)
		case symbol.CONTINUE:
			c.c_outi(sc, "continue;")
		case symbol.BREAK:
			c.c_outi(sc, "break;\n")
		case symbol.VERBATIM_GET, symbol.VERBATIM_BOTH:
			c.Verbatim(sc, lp.Vp)
		case symbol.VERBATIM_GET_C, symbol.VERBATIM_BOTH_C:
			c.Verbatim(sc, lp.Vp)
		case symbol.VERBATIM_GET_J, symbol.VERBATIM_BOTH_J:
		case symbol.VERBATIM_GET_A, symbol.VERBATIM_BOTH_A:
		case symbol.VERBATIM_A, symbol.VERBATIM_PUT_A, symbol.VERBATIM, symbol.VERBATIM_C, symbol.VERBATIM_J, symbol.VERBATIM_PUT, symbol.VERBATIM_PUT_C, symbol.VERBATIM_PUT_J, symbol.VERBATIM_C_CPP:
		case symbol.PRAGMA:
		case symbol.INCLUDE:
		case symbol.IMPORT:
			c.c_outi(sc, "// import \"%s\"\n", lp.E1.Left.GetString())
		case symbol.BAC_TYPE:
			if lp.E2.Left.GetUint64() != 0 {
				c.c_outi(sc, "%s::ad_init(%sbs);\n", lp.E1.Left.GetSymbol().Name, c.Prefix)
			} else {
				c.c_outi(sc, "%s::ad_end(%sbs);\n", lp.E1.Left.GetSymbol().Name, c.Prefix)
			}
		default:
			fatal("Internal error: Unknown statement type %d", lp.Type)
		}
		lp = lp.Next
	}
}

func (c *CompilerContext) c_class_get_decl_probe_id_vars(sp *symbol.Symbol_t) {
	sc := c.OutputFiles["source"]
	var p *symbol.Symbol_t
	var slp *symbol.Symlink_t

	for i := 0; i < symbol.ST_SIZE; i++ {
		slp = sp.Cxt.St[i]
		for slp != nil {
			if slp.Sp == nil {
				fatal("Internal error: Symbol link without symbol")
			}
			p = slp.Sp
			if p.Ptype != nil && p.Ptype.Ident == symbol.CLASS_TYPE && p.Isparam == 0 && p.Ptype.Id != nil && p.Owner == sp {
				tname := p.Ptype.Id.Ptype.Name

				// declare tmp for id
				m := p.Ptype.Id.Modifiers
				nm := ^uint(symbol.M_CONST)
				c.c_outi(sc, "%s%s %s%s_id;\n", S_mods2str(m&nm), tname, c.Prefix, p.Name)

				// tracing, then the parent class needs parse var for id probing
				if c.Gen_trace {
					sp.Get_needs_parse_var = 1
				}
			}
			slp = slp.Next
		}
	}
}

func (c *CompilerContext) Class_decl(sp *symbol.Symbol_t, stmts *symbol.List_t) {

	if sp == nil {
		return
	}

	h := c.OutputFiles["header"]

	// see if a forward declaration was given, but no definition
	if sp.Forward > 0 {
		if sp.Forward == 1 {
			c.lineno = sp.Lineno
			fatal("class '%s' was declared but never defined", sp.Name)
		} else if sp.Forward == 2 {
			sp.Forward = 0
		}

		c.c_out(h, "\nclass %s;\n", sp.Name)
		return
	}

	// see if it is a derived class or not
	if sp.Ptype == nil {
		c.c_out(h, "\nclass %s {\npublic:\n", sp.Name)
	} else {
		c.c_out(h, "\nclass %s : public %s {\npublic:\n", sp.Name, sp.Ptype.Name)
	}
	c.indent()

	if sp.Id != nil {
		if sp.Abstract == 0 {
			// parse var is needed in both get and put, unless the id has type larger than 'int' (float or double)
			if sp.Id.Ptype.Ident <= symbol.INT {
				sp.Put_needs_parse_var = 1
				sp.Get_needs_parse_var = 1
			}
		}

		if c_find_id(sp.Ptype) == nil {
			c.c_var_decl_inclass(sp.Id, sp.Id.Init, nil, 0, nil)
			// if abstract, reset put_needs_parse_var, which is set by the above call
			if sp.Abstract != 0 {
				sp.Put_needs_parse_var = 0
				sp.Get_needs_code_var = 0
			}
		} else {
			// declare lengthof variable, if needed
			if sp.Id.Lengthof != 0 {
				c.c_outi(h, "int ")
				c.c_out(h, sp.Id.Plengthof.Name, c.Prefix)
				c.c_out(h, ";\n")
			}
			// mark the id as declared
			sp.Id.Declared = 1
			sp.Id.Declared_get = 1
			sp.Id.Declared_put = 1
			sp.Id.Declared_putxml = 1
		}
	}

	// declare lengthof variable, if needed
	if sp.Lengthof != 0 {
		c.c_outi(h, "int %slengthof;\n", c.Prefix)
	}

	// process class variable declarations
	c.c_stmts(stmts)

	// declare isidof method, if needed
	if sp.Isidof != 0 {
		c.c_outi(h, "public: static int %sisidof(%s tag);\n", c.Prefix, sp.Id.Ptype.Name)
	}

	// declare get()/put()/putxml() and switch output files
	c.c_class_decl_methods(sp)
	c.c_identlevel = 0

	// switch to source file here

	// generate get() method
	if c.Gen_get {
		c.c_class_get(sp, stmts)
	}

	// generate put() method
	if c.Gen_put {
		c.c_class_put(sp, stmts)
	}

	// generate isidof() method, if needed
	if sp.Isidof != 0 {
		c.c_class_isidof(sp)
	}

	// we are back in the header file output
	c.c_identlevel = 0

	c.c_out(h, "};\n")
}

func (c *CompilerContext) c_class_decl_methods(sp *symbol.Symbol_t) {
	// should go to header
	h := c.OutputFiles["header"]

	if c.Gen_get {
		c.c_outi(h, "public: virtual int get(%s &%sbs", c.BitstreamClass, c.Prefix)
		// if we have parameters, declare them
		if sp.Param != nil {
			c.c_out(h, ", ")
			c.c_param_list(h, sp.Param)
		}
		// we need to pass id parse info if this or a superclass has ID
		if c_find_id_notabstract(sp) != nil {
			c.c_out(h, ", int %sid_parsed = 0", c.Prefix)
		}

		c.c_out(h, ");\n")
	}

	if c.Gen_put {
		c.c_outi(h, "public: virtual int put(%s &%sbs", c.BitstreamClass, c.Prefix)
		if sp.Param != nil {
			c.c_out(h, ", ")
			c.c_param_list(h, sp.Param)
		}
		if c_find_id_notabstract(sp) != nil {
			c.c_out(h, ", int %sid_parsed = 0", c.Prefix)
		}
		c.c_out(h, ");\n")
	}
}

func (c *CompilerContext) c_stmts(stmts *symbol.List_t) {
	sc := c.OutputFiles["source"]
	h := c.OutputFiles["header"]
	lp := stmts
	for lp != nil {
		// skip included statements (and their sub-statements)
		if lp.Included != 0 {
			lp = lp.Next
			continue
		}

		switch lp.Type {
		case symbol.DECL:
			// only declare level 1 variables as class members
			c.c_var_decl_inclass(lp.Sp, lp.E1, lp.E2, lp.Dims, lp.Dim)
		case '{':
			// block of statements
			c.c_stmts(lp.Sub1)
		case symbol.EXPR:
		case symbol.LABEL:
		case symbol.CASE:
			c.c_stmts(lp.Sub1)
		case symbol.DEFAULT:
			c.c_stmts(lp.Sub1)
		case symbol.IF:
			c.c_stmts(lp.Sub1)
			if lp.Sub2 != nil {
				c.c_stmts((lp.Sub2))
			}
		case symbol.SWITCH:
			c.c_stmts(lp.Sub1)
		case symbol.WHILE:
			c.c_stmts(lp.Sub1)
		case symbol.DO:
			c.c_stmts(lp.Sub1)
		case symbol.FOR:
			c.c_stmts(lp.Sub1)
		case symbol.GOTO:
		case symbol.CONTINUE:
		case symbol.BREAK:
		case symbol.VERBATIM:
			c.Verbatim(h, lp.Vp)
		case symbol.VERBATIM_C:
			c.Verbatim(h, lp.Vp)
		case symbol.VERBATIM_J:
		case symbol.VERBATIM_A:
		case symbol.VERBATIM_GET_A:
		case symbol.VERBATIM_PUT_A:
		case symbol.VERBATIM_BOTH_A:
		case symbol.VERBATIM_GET:
		case symbol.VERBATIM_PUT:
		case symbol.VERBATIM_BOTH:
		case symbol.VERBATIM_C_CPP:
		case symbol.VERBATIM_GET_C:
		case symbol.VERBATIM_PUT_C:
		case symbol.VERBATIM_BOTH_C:
		case symbol.VERBATIM_GET_J:
		case symbol.VERBATIM_PUT_J:
		case symbol.VERBATIM_BOTH_J:
		case symbol.PRAGMA:
			c.pragma(lp.Sub1)
		case symbol.INCLUDE:
			c.c_out(sc, "#include \"%s.hpp\"\n", lp.E1.Left.GetString())
		case symbol.IMPORT:
			c.c_outi(sc, "// import \"%s\"\n", lp.E1.Left.GetString())
		case symbol.BAC_TYPE:
		default:
			fatal("Internal error CG: Unknown statement type %d", lp.Type)
		}
		lp = lp.Next
	}
}

func (c *CompilerContext) c_stmts_put(stmts *symbol.List_t) {
	sc := c.OutputFiles["source"]
	lp := stmts
	for lp != nil {
		// skip included statements (and their sub-statements)
		if lp.Included != 0 {
			lp = lp.Next
			continue
		}

		switch lp.Type {
		case symbol.DECL:
			c.c_var_decl_put(lp.Sp, lp.E1, lp.E2, lp.E3, lp.Align, lp.Dims, lp.Dim, lp.Usenext)
		case '{':
			c.c_outi(sc, "{\n")
			c.indent()
			c.c_stmts_put(lp.Sub1)
			c.outdent()
			c.c_outi(sc, "}\n")
		case symbol.EXPR:
			c.c_ident(sc)
			c.c_expression(sc, lp.E1, false)
			c.c_out(sc, ";\n")
		case symbol.LABEL:
			c.outdent()
			c.c_outi(sc, "%s:\n", lp.Sp.Name)
			c.indent()
		case symbol.CASE:
			c.outdent()
			c.c_outi(sc, "case ")
			c.c_expression(sc, lp.E1, false)
			c.c_out(sc, ":\n")
			c.indent()
			c.c_stmts_put(lp.Sub1)
		case symbol.DEFAULT:
			c.outdent()
			c.c_outi(sc, "default:\n")
			c.indent()
			c.c_stmts_put(lp.Sub1)
		case symbol.IF:
			c.c_outi(sc, "if (")
			c.c_expression(sc, lp.E1, true)

			if lp.Sub1.Type != '{' {
				c.c_out(sc, ") {\n")
				c.indent()
				c.c_stmts_put(lp.Sub1)
				c.outdent()
				c.c_outi(sc, "}\n")
			} else {
				c.c_out(sc, ")\n")
				c.c_stmts_put(lp.Sub1)
			}
			if lp.Sub2 != nil {
				if lp.Sub2.Type != '{' {
					c.c_outi(sc, "else {\n")
					c.indent()
					c.c_stmts_put(lp.Sub2)
					c.outdent()
					c.c_outi(sc, "}\n")
				} else {
					c.c_outi(sc, "else\n")
					c.c_stmts_put(lp.Sub2)
				}
			}
			c.c_outi(sc, "\n")
		case symbol.SWITCH:
			c.c_outi(sc, "switch (")
			c.c_expression(sc, lp.E1, false)

			if lp.Sub1.Type != '{' {
				c.c_out(sc, ") {\n")
				c.indent()
				c.c_stmts_put(lp.Sub1)
				c.outdent()
				c.c_outi(sc, "}\n")
			} else {
				c.c_out(sc, ")\n")
				c.c_stmts_put(lp.Sub1)
			}
			c.c_outi(sc, "\n")
		case symbol.WHILE:
			c.c_outi(sc, "while (")
			c.c_expression(sc, lp.E1, true)
			c.c_out(sc, ") {\n")
			c.indent()
			if lp.Sub1.Type != '{' {
				c.c_stmts_put(lp.Sub1)
			} else {
				c.c_stmts_put(lp.Sub1.Sub1)
			}

			c.outdent()
			c.c_outi(sc, "}\n")
		case symbol.DO:
			c.c_outi(sc, "do {\n")
			c.indent()
			if lp.Sub1.Type != '{' {
				c.c_stmts_put(lp.Sub1)
			} else {
				c.c_stmts_put(lp.Sub1.Sub1)
			}

			c.outdent()
			c.c_outi(sc, "} while (")
			c.c_expression(sc, lp.E1, true)
			c.c_out(sc, ");\n")
		case symbol.FOR:
			c.c_outi(sc, "for (")
			c.c_expression(sc, lp.E1, false)
			c.c_out(sc, "; ")
			c.c_expression(sc, lp.E2, true)
			c.c_out(sc, "; ")
			c.c_expression(sc, lp.E3, false)
			c.c_out(sc, ") {\n")
			c.indent()
			if lp.Sub1.Type != '{' {
				c.c_stmts_put(lp.Sub1)
			} else {
				c.c_stmts_put(lp.Sub1.Sub1)
			}

			c.outdent()
			c.c_outi(sc, "}\n")
		case symbol.GOTO:
			c.c_outi(sc, "goto %s;\n", lp.Sp.Name)
		case symbol.CONTINUE:
			c.c_outi(sc, "continue;")
		case symbol.BREAK:
			c.c_outi(sc, "break;\n")
		case symbol.VERBATIM_PUT, symbol.VERBATIM_BOTH:
			c.Verbatim(sc, lp.Vp)
		case symbol.VERBATIM_PUT_C, symbol.VERBATIM_BOTH_C:
			c.Verbatim(sc, lp.Vp)
		case symbol.VERBATIM_PUT_J, symbol.VERBATIM_BOTH_J, symbol.VERBATIM_PUT_A,
			symbol.VERBATIM_BOTH_A, symbol.VERBATIM_A, symbol.VERBATIM_GET_A,
			symbol.VERBATIM, symbol.VERBATIM_C, symbol.VERBATIM_J,
			symbol.VERBATIM_GET, symbol.VERBATIM_GET_C, symbol.VERBATIM_GET_J,
			symbol.VERBATIM_C_CPP, symbol.PRAGMA, symbol.INCLUDE:
		case symbol.IMPORT:
			c.c_outi(sc, "// import \"%s\"\n", lp.E1.Left.GetString())
		case symbol.BAC_TYPE:
			if lp.E2.Left.GetInt64() != 0 {
				c.c_outi(sc, "%s::ae_init(%sbs);\n", lp.E1.Left.GetSymbol().Name, c.Prefix)
			} else {
				c.c_outi(sc, "%s::ae_end(%sbs);\n", lp.E1.Left.GetSymbol().Name, c.Prefix)
			}
		default:
			fatal("Internal error CG: Unknown statement type %d", lp.Type)
		}
		lp = lp.Next
	}
}
