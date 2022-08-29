package compiler

import (
	"io"

	"example.com/goflav/symbol"
)

func (c *CompilerContext) c_var_decl(w io.Writer, sp *symbol.Symbol_t, dims int, dim *[]*symbol.Node_t) {
	if sp == nil {
		return
	}

	var doarray int
	var doname int = 1
	var mod uint
	var t string

	// convert 'bit' to 'unsigned int'
	if sp.Ptype.Name == "bit" {
		t = "int"
	} else {
		t = sp.Ptype.Name
	}

	// ignore M_CONST if var not global (it is modified by get()/put())
	if sp.Cxt_level > 0 {
		mod = sp.Modifiers & uint(^symbol.M_CONST)

		doarray = 1

		// qt_cpp
		s := S_mods2stdint(mod, t)
		// for arrays of classes in c++, we'll need to use:\
		// flavor::SmallVector< std::shared_ptr<T> ,len> classname;
		// instead of arrays of pointers
		if dims == 0 {
			if sp.Ptype.Ident == symbol.CLASS_TYPE {
				c.c_outi(w, "%s<%s> ", c.c_shared_pointer_type, s)
			} else {
				c.c_outi(w, "%s ", s)
			}
		} else {
			// we'll handle qt arrays
			doarray = 0
			for i := 0; i < dims; i++ {
				if i == 0 {
					c.c_outi(w, "%s< ", c.c_array_type)
				} else {
					c.c_out(w, "%s< ", c.c_array_type)
				}
			}

			if sp.Ptype.Ident == symbol.CLASS_TYPE {
				c.c_out(w, "%s<%s> ", c.c_shared_pointer_type, s)
			} else {
				c.c_out(w, "%s ", s)
			}

			for i := 0; i < dims; i++ {
				c.c_out(w, " , %d> ", c.MaxArraySize)
			}
		}

		// write out the array's name
		if doname != 0 {
			c.c_out(w, "%s", sp.Name)
		}

		if doarray != 0 {
			c.c_array_decl(w, sp, dims, dim)
		}
		c.c_out(w, ";\n")
	} else {
		mod = sp.Modifiers
		c.c_outi(w, "%s %s", S_mods2stdint(mod, t), sp.Name)
		// c.c_out(w, "%s %s", S_mods2stdint(mod, t), sp.Name)
		c.c_array_decl_actual(w, sp, dims, dim)

		// if a global var, it must have an initial value
		if sp.Init != nil {
			c.c_out(w, " = ")
			c.c_expression(w, sp.Init, false)
		}
		c.c_out(w, ";\n")
	}

	// declare lengthof variable, if needed
	if sp.Ptype.Ident != symbol.CLASS_TYPE && sp.Lengthof != 0 {
		c.c_outi(w, "int ")
		c.c_out(w, sp.Plengthof.Name, c.Prefix)
		c.c_array_decl(w, sp.Plengthof, dims, dim)
		c.c_out(w, ";\n")
	}
}

func (c *CompilerContext) c_var_decl_ext(w io.Writer, sp *symbol.Symbol_t, dims int, dim *[]*symbol.Node_t) {
	var t string
	if sp == nil {
		return
	}

	// convert 'bit' to 'unsigned int' for C++ and 'int' for Java
	if sp.Ptype.Name == "bit" {
		t = "int"
	} else {
		t = sp.Ptype.Name
	}

	if sp.Cxt_level > 0 {
		panic("Internal error: Encountered extern declaration of non-global variable")
	}

	// cpp_qt
	c.c_out(w, "extern %s %s", S_mods2stdint(sp.Modifiers, t), sp.Name)

	c.c_array_decl_actual(w, sp, dims, dim)
	c.c_out(w, ";\n")
}

// generate variable declarations for those vars that have class or deeper scope
func (c *CompilerContext) c_var_decl_inclass(sp *symbol.Symbol_t, init *symbol.Node_t, parse *symbol.Node_t, dims int, dim *[]*symbol.Node_t) {
	if sp == nil {
		return
	}

	if sp.Owner == nil {
		fatal("Internal error: Expected class member variable")
	}

	// figure out if we need a tmp parse var -- only relevant for parsables
	if sp.Parsable != 0 {
		// for put(), if doing lengthof for non-class, or we have init value and type is 'int' or less
		if (sp.Lengthof != 0 && sp.Ptype.Ident != symbol.CLASS_TYPE) || (init != nil && sp.Ptype.Ident <= symbol.INT) {
			sp.Owner.Put_needs_parse_var = 1
		}

		// For get(), if we are tracing and it is not a class, if we are doing lengthof
		// and is not a class, or if it is a class with an ID and not pure abstract.

		if sp.Ptype.Ident != symbol.CLASS_TYPE && (c.Gen_trace || sp.Lengthof != 0) ||
			(sp.Ptype.Ident == symbol.CLASS_TYPE && sp.Id != nil && !c_is_pure_abstract(sp.Ptype)) {
			sp.Owner.Get_needs_parse_var = 1
		}
	}

	// if parsable, we are tracing, and uses map, then get needs code var
	if c.Gen_trace && sp.Parsable != 0 && parse != nil && parse.Op == symbol.MAP_TYPE {
		if sp.Owner == nil {
			fatal("Internal error: Expected class member variable")
		}
		sp.Owner.Get_needs_code_var = 1
	}

	// Save maximum nr of dimensions (so that the appropriate number of tmp.\
	// vars is generated in put/get). Only parsables, variables with initialization,
	// or classes are relevant here.
	//
	// NOTE: This is needed regardless if the variable is a class member or
	//       has deeper scope. These tmps are also used in, e.g., int b[10] = 1;
	if sp.Owner != nil {
		if init != nil || sp.Parsable != 0 || sp.Ptype.Ident == symbol.CLASS_TYPE {
			if sp.Owner.Max_dims < dims {
				sp.Owner.Max_dims = dims
			}
		}
	}

	if sp.Declared == 0 && sp.Cxt_level == 1 {
		c.c_var_decl(c.OutputFiles["header"], sp, dims, dim)
		sp.Declared = 1
		sp.Declared_get = 1
		sp.Declared_put = 1
		sp.Declared_putxml = 1
	}
}

func (c *CompilerContext) c_var_decl_get(
	sp *symbol.Symbol_t, // symbol to be declared/defined
	init *symbol.Node_t, // initialization expression
	parse *symbol.Node_t, // parse expression
	param *symbol.Node_t, // parameters
	align *symbol.Node_t, // alignment expression
	dims int, // array dimensions for the symbol
	dim *[]*symbol.Node_t,
	// if > 0 --> lookahead parsing
	usenext int) {

	if sp == nil {
		return
	}

	sc := c.OutputFiles["source"]

	// declare, if necessary
	if sp.Declared_get == 0 {
		c.c_var_decl(sc, sp, dims, dim)
		sp.Declared_get = 1
	}

	// see if we need to align
	if align != nil {
		if c.Gen_trace {
			/*
				// save parse size
				c.c_outi(sc, "%sparse = ", prefix)
				c.c_expression(sc, align, false)
				c.c_out(sc, ";\n")

				// do the align
				c.c_outi(sc, "%sbs.align(%sparse);\n", c.Prefix, c.Prefix)

				// trace
				c_trace_aligned()
			*/
		} else {
			c.c_outi(sc, "%sbs.align(", c.Prefix)
			c.c_expression(sc, align, false)
			c.c_out(sc, ");\n")
		}
	}

	// class variable
	if sp.Ptype.Ident == symbol.CLASS_TYPE {
		c.c_var_decl_get_class(sp, parse, param, dims, dim, usenext)
		return
	}

	// binary-arithmetically coded variable
	if sp.Parsable != 0 && parse != nil && parse.Op == symbol.BAC_TYPE {
		c.c_var_decl_get_bac(sp, param, parse, dims, dim, usenext)
		return
	}

	// all other parsable variables
	if sp.Parsable != 0 {
		c.c_var_decl_get_parse(sp, init, parse, dims, dim, usenext)
		return
	}

	// regular variable; only relevant if initial value is given
	if init != nil || sp.Init != nil {
		if dims > 0 {
			c.c_array_prologue(sp, dims, dim)
		}
		c.c_outi(sc, "%s", sp.Name)
		if dims > 0 {
			c.c_array_proper(sp, dims)
		}
		c.c_out(sc, " = ")

		// if a constant, use the symbol's init; otherwise the expression's
		if uint64(sp.Modifiers)&symbol.M_CONST == symbol.M_CONST {
			c.c_expression(sc, sp.Init, false)
		} else {
			c.c_expression(sc, init, false)
		}
		c.c_out(sc, ";\n")
		if dims > 0 {
			c.c_array_epilogue(sp, dims, dim)
		}
	}
}

func (c *CompilerContext) c_var_decl_get_parse(sp *symbol.Symbol_t, init *symbol.Node_t, parse *symbol.Node_t, dims int, dim *[]*symbol.Node_t, usenext int) {
	sc := c.OutputFiles["source"]
	var pp *symbol.Node_t
	var ip *symbol.Node_t

	if uint64(sp.Modifiers)&symbol.M_CONST == symbol.M_CONST || sp.Range != 0 {
		pp = sp.Parse
		ip = sp.Init
	} else {
		pp = parse
		ip = init
	}

	// sanity check
	if pp == nil {
		fatal("Internal error: Expected parsable variable")
	}

	// if parse size is 0, we don't call getbits(); we just set the initial value, if any
	if is_literal(pp.Op) {
		if pp.Op != symbol.INT_LITERAL {
			fatal("Internal error: Expected integer literal")
		}

		if pp.Left.GetInt64() == 0 {
			if ip != nil {
				// just set initial value, if any
				if dims > 0 {
					c.c_array_prologue(sp, dims, dim)
				}
				c.c_outi(sc, "%s", sp.Name)
				if dims > 0 {
					c.c_array_proper(sp, dims)
				}
				c.c_out(sc, " = ")
				c.c_expression(sc, ip, false)
				c.c_out(sc, ";\n")
				// update lengthof
				if sp.Lengthof != 0 {
					c.c_outi(sc, sp.Plengthof.Name, c.Prefix)
					if dims > 0 {
						c.c_array_proper(sp.Plengthof, sp.Plengthof.Dims)
					}
					c.c_out(sc, " = 0;\n")
				}
				// done
				if dims > 0 {
					c.c_array_epilogue(sp, dims, dim)
				}
			}
			return
		}
		// we fall over to the code below
	}

	// parse size non-zero or not a constant

	if dims > 0 {
		c.c_array_prologue(sp, dims, dim)
	}

	// call appropriate function depending on map/simple expression for parse expression
	if pp.Op == symbol.MAP_TYPE {
		c.c_var_decl_get_parse_map(sp, ip, pp.Left.GetSymbol(), dims, dim, usenext)
	} else {
		c.c_var_decl_get_parse_simple(sp, ip, pp, dims, dim, usenext)
	}

	if dims > 0 {
		c.c_array_epilogue(sp, dims, dim)
	}
}

func (c *CompilerContext) c_var_decl_get_parse_map(sp *symbol.Symbol_t, ip *symbol.Node_t, m *symbol.Symbol_t, dims int, dim *[]*symbol.Node_t, usenext int) {

	sc := c.OutputFiles["source"]

	if c.Gen_trace {
		// c_trace_entering_mapped_class(sp, dims, map)
	}

	if usenext != 0 {
		c.c_outi(sc, "if (%s%s%s(%sbs, &%s", m.Name, c.c_static_scope, "nextvlc", c.Prefix, sp.Name)
	} else {
		c.c_outi(sc, "if (%s%s%s(%sbs, &%s", m.Name, c.c_static_scope, "getvlc", c.Prefix, sp.Name)
	}
	if dims > 0 {
		c.c_array_proper(sp, dims)
	}
	// if we are tracing or need lengthof, get number of bits
	if c.Gen_trace || sp.Lengthof != 0 {
		c.c_out(sc, ", &%sparse", c.Prefix)
	}

	// if we are tracing, we also need code value
	if c.Gen_trace {
		// c_out(", &%scode", prefix)
	}
	c.c_out(sc, ") == 0) {\n")

	// lookup failed
	c.indent()
	c.c_outi(sc, "%s(\"Map '%s' lookup for '%s", c.ErrorFunc, m.Name, sp.Name)

	if dims > 0 {
		for i := 0; i < dims; i++ {
			c.c_out(sc, "[%%d]")
		}
	}
	c.c_out(sc, "' failed\"")
	if dims > 0 {
		c.c_out(sc, ", ")
		for i := 0; i < dims; i++ {
			c.c_out(sc, "%s", c.c_gentmp_dim(i))
			if i != dims-1 {
				c.c_out(sc, ", ")
			}
		}
	}
	c.c_out(sc, ");\n")

	// increase error count
	c.c_outi(sc, "%sret++;\n", c.Prefix)

	// trace failed lookup
	if c.Gen_trace {
		// c_trace_failed_map(m, sp, dims)
	}

	c.outdent()
	c.c_outi(sc, "}\n")

	// update length, if necessary (ignore usenext)
	if sp.Lengthof != 0 {
		c.c_outi(sc, sp.Plengthof.Name, c.Prefix)
		if dims > 0 {
			c.c_array_proper(sp.Plengthof, sp.Plengthof.Dims)
		}
		c.c_out(sc, " = %sparse;\n", c.Prefix)
	}

	// if a value is specified, check the parsed value against it
	if ip != nil {
		c.c_outi(sc, "if (%s", sp.Name)
		if dims > 0 {
			c.c_array_proper(sp, dims)
		}
		c.c_out(sc, " != ")
		c.c_expression(sc, ip, false)
		c.c_out(sc, ") {\n")
		c.indent()
		c.c_outi(sc, "%s(\"Const value mismatch for '%s", c.ErrorFunc, sp.Name)
		if dims > 0 {
			for i := 0; i < dims; i++ {
				c.c_out(sc, "[%%d]")
			}
		}
		c.c_out(sc, "'\"")
		if dims > 0 {
			c.c_out(sc, ", ")
			for i := 0; i < dims; i++ {
				c.c_out(sc, "%s", c.c_gentmp_dim(i))
				if i != dims-1 {
					c.c_out(sc, ", ")
				}
			}
		}

		// trace, flagging mismatch
		if c.Gen_trace {
			// c_trace_var_map(sp, map, dims, usenext, 1)
		}

		c.outdent()
		c.c_outi(sc, "}\n")

		if c.Gen_trace {
			// c_outi("else {\n");
			// c_identlevel++;
			// c_trace_var_map(sp, m, dims, usenext, 0);
			// c_identlevel--;
			// c_outi("}\n");
		}
	} else {
		if c.Gen_trace {
			// c_trace_var_map(sp, m, dims, usenext, 0)
		}
	}
}

func (c *CompilerContext) c_var_decl_get_parse_simple(sp *symbol.Symbol_t, ip *symbol.Node_t, pp *symbol.Node_t, dims int, dim *[]*symbol.Node_t, usenext int) {
	sc := c.OutputFiles["source"]

	// if we are tracing or need lengthof, save parse size
	if c.Gen_trace || sp.Lengthof != 0 {
		c.c_outi(sc, "%sparse = ", c.Prefix)
		c.c_expression(sc, pp, false)
		c.c_out(sc, ";\n")
	}

	c.c_outi(sc, "%s", sp.Name)
	if dims > 0 {
		c.c_array_proper(sp, dims)
	}

	// see which get function to call
	c.c_out(sc, " = ")

	islittle := ""
	isunsigned := "s"
	if uint64(sp.Modifiers)&symbol.M_LITTLE == symbol.M_LITTLE {
		islittle = "little_"
	}
	if uint64(sp.Modifiers)&symbol.M_UNSIGNED == symbol.M_UNSIGNED || sp.Ptype.Ident > symbol.INT {
		isunsigned = ""
	}

	if usenext != 0 {
		c.c_out(sc, "%sbs.%s%s%s", c.Prefix, islittle, isunsigned, "next")
	} else {
		c.c_out(sc, "%sbs.%s%s%s", c.Prefix, islittle, isunsigned, "get")
	}

	if sp.Ptype.Ident <= symbol.INT {
		if uint64(sp.Modifiers)&symbol.M_EXPGOLOMB == symbol.M_EXPGOLOMB {
			c.c_out(sc, "bits_expgolomb(")
		} else {
			c.c_out(sc, "bits(")
		}

		if c.Gen_trace || sp.Lengthof != 0 {
			c.c_out(sc, "%sparse", c.Prefix)
		} else {
			c.c_expression(sc, pp, false)
		}
	} else if sp.Ptype.Ident == symbol.FLOAT {
		c.c_out(sc, "float(")
	} else if sp.Ptype.Ident == symbol.FLOAT && (uint64(sp.Modifiers)&symbol.M_LONG == symbol.M_LONG) {
		c.c_out(sc, "ldouble(")
	} else {
		c.c_out(sc, "double(")
	}

	c.c_out(sc, ");\n")

	// update length, if necessary (ignore usenext)
	if sp.Lengthof != 0 {
		c.c_outi(sc, sp.Plengthof.Name, c.Prefix)
		if dims > 0 {
			c.c_array_proper(sp.Plengthof, sp.Plengthof.Dims)
		}
		c.c_out(sc, " = %sparse;\n", c.Prefix)
	}

	// if a value is specified, check the parsed value against it
	if ip != nil {

		// id range; in this case, the ? : operator is not used
		if sp.Range != 0 {
			c.c_outi(sc, "if (!(")
			c.c_expression(sc, ip, false)
			c.c_out(sc, " <= %s && %s <= ", sp.Name, sp.Name)
			c.c_expression(sc, ip.Third.GetNode(), false)
			c.c_out(sc, ")) {\n")
			c.indent()

			c.c_outi(sc, "%s(\"Const value mismatch for '%s", c.ErrorFunc, sp.Name)

			if dims > 0 {
				for i := 0; i < dims; i++ {
					c.c_out(sc, "[%%d]")
				}
			}
			c.c_out(sc, "'\"")
			if dims > 0 {
				c.c_out(sc, ", ")
				for i := 0; i < dims; i++ {
					c.c_out(sc, "%s", c.c_gentmp_dim(i))
					if i != dims-1 {
						c.c_out(sc, ", ")
					}
				}
			}

			c.c_out(sc, ");\n")

			// increase error count
			c.c_outi(sc, "%sret++;\n", c.Prefix)

			if c.Gen_trace {
				// c_trace_var_simple(sp, dims, usenext, 1)
			}

			c.outdent()
			c.c_outi(sc, "}\n")

			if c.Gen_trace {
				// c_outi("else {\n");
				// c_identlevel++;
				// c_trace_var_simple(sp, dims, usenext, 0);
				// c_identlevel--;
				// c_outi("}\n");
			}
		} else {
			c.c_outi(sc, "if (%s", sp.Name)
			if dims > 0 {
				c.c_array_proper(sp, dims)
			}
			c.c_out(sc, " != ")
			if sp.Ptype.Ident == symbol.FLOAT {
				c.c_out(sc, "(float)")
			}
			c.c_expression(sc, ip, false)
			c.c_out(sc, ") {\n")
			c.indent()

			c.c_outi(sc, "%s(\"Const value mismatch for '%s", c.ErrorFunc, sp.Name)

			if dims > 0 {
				for i := 0; i < dims; i++ {
					c.c_out(sc, "[%%d]")
				}
			}
			c.c_out(sc, "'\"")
			if dims > 0 {
				c.c_out(sc, ", ")
				for i := 0; i < dims; i++ {
					c.c_out(sc, "%s", c.c_gentmp_dim(i))
					if i != dims-1 {
						c.c_out(sc, ", ")
					}
				}
			}
			c.c_out(sc, ");\n")

			// increase error count
			c.c_outi(sc, "%sret++;\n", c.Prefix)

			if c.Gen_trace {
				// c_trace_var_simple(sp, dims, usenext, 1)
			}

			c.outdent()
			c.c_outi(sc, "}\n")

			if c.Gen_trace {
				// c_outi("else {\n");
				// c_identlevel++;
				// c_trace_var_simple(sp, dims, usenext, 0);
				// c_identlevel--;
				// c_outi("}\n");
			}
		}
	} else {
		if c.Gen_trace {
			// c_trace_var_simple(sp, dims, usenext, 0)
		}
	}
}

func (c *CompilerContext) c_var_decl_put(
	sp *symbol.Symbol_t, // symbol to be declared/defined
	init *symbol.Node_t, // initialization expression
	parse *symbol.Node_t, // parse expression
	param *symbol.Node_t, // parameters
	align *symbol.Node_t, // alignment expression
	dims int, // array dimensions for the symbol
	dim *[]*symbol.Node_t,
	// if > 0 --> lookahead parsing
	usenext int) {

	sc := c.OutputFiles["source"]

	if sp == nil {
		return
	}

	// declare, if necessary
	if sp.Declared_put == 0 {
		c.c_var_decl(sc, sp, dims, dim)
		sp.Declared_put = 1
	}

	// see if we need to align
	if align != nil {
		c.c_outi(sc, "%sbs.align(", c.Prefix)
		c.c_expression(sc, align, false)
		c.c_out(sc, ");\n")
	}

	// class variable
	if sp.Ptype.Ident == symbol.CLASS_TYPE {
		c.c_var_decl_put_class(sp, param, parse, dims, dim, usenext)
		return
	}

	// binary-arithmetically coded variable
	if sp.Parsable != 0 && parse != nil && parse.Op == symbol.BAC_TYPE {
		c.c_var_decl_put_bac(sp, param, parse, dims, dim, usenext)
		return
	}

	// all other parsable variables
	if sp.Parsable != 0 {
		c.c_var_decl_put_parse(sp, init, parse, dims, dim, usenext)
		return
	}

	// regular variable; only relevant if initial value is given
	if init != nil || sp.Init != nil {
		if dims > 0 {
			c.c_array_prologue(sp, dims, dim)
		}

		c.c_outi(sc, "%s", sp.Name)
		if dims > 0 {
			c.c_array_proper(sp, dims)
		}
		c.c_out(sc, " = ")

		// if a constant, use the symbol's init; otherwise the expression's
		if (uint64(sp.Modifiers) & symbol.M_CONST) == symbol.M_CONST {
			c.c_expression(sc, sp.Init, false)
		} else {
			c.c_expression(sc, init, false)
		}
		c.c_out(sc, ";\n")
		if dims > 0 {
			c.c_array_epilogue(sp, dims, dim)
		}
	}
}

func (c *CompilerContext) c_var_decl_put_parse_simple(sp *symbol.Symbol_t, ip *symbol.Node_t, pp *symbol.Node_t, dims int, dim *[]*symbol.Node_t) {
	sc := c.OutputFiles["source"]

	// see which put function to call
	c.c_outi(sc, "%sbs.", c.Prefix)
	if sp.Ptype.Ident <= symbol.INT {
		vlmodifier := ""
		if uint64(sp.Modifiers)&symbol.M_EXPGOLOMB == symbol.M_EXPGOLOMB {
			if uint64(sp.Modifiers)&symbol.M_SIGNED == symbol.M_SIGNED {
				vlmodifier = "_sexpgolomb"
			} else {
				vlmodifier = "_expgolomb"
			}
		} else if uint64(sp.Modifiers)&symbol.M_VARLEN == symbol.M_VARLEN {
			vlmodifier = "_varlen"
		}
		if uint64(sp.Modifiers)&symbol.M_LITTLE == symbol.M_LITTLE {
			c.c_out(sc, "%sputbits%s(%s", "little_", vlmodifier, sp.Name)
		} else {
			c.c_out(sc, "%sputbits%s(%s", "", vlmodifier, sp.Name)
		}

		if dims > 0 {
			c.c_array_proper(sp, dims)
		}
		c.c_out(sc, ", ")
		if sp.Lengthof != 0 || ip != nil {
			c.c_out(sc, "%sparse", c.Prefix)
		} else {
			c.c_expression(sc, pp, false)
		}
	} else if sp.Ptype.Ident == symbol.FLOAT {
		if uint64(sp.Modifiers)&symbol.M_LITTLE == symbol.M_LITTLE {
			c.c_out(sc, "%sputfloat(%s", "little_", sp.Name)
		} else {
			c.c_out(sc, "%sputfloat(%s", "", sp.Name)
		}

		if dims > 0 {
			c.c_array_proper(sp, dims)
		}
	} else if sp.Ptype.Ident == symbol.DOUBLE && (uint64(sp.Modifiers)&symbol.M_LONG == symbol.M_LONG) {
		if uint64(sp.Modifiers)&symbol.M_LITTLE == symbol.M_LITTLE {
			c.c_out(sc, "%sputldouble(%s", "little_", sp.Name)
		} else {
			c.c_out(sc, "%sputldouble(%s", "", sp.Name)
		}
		if dims > 0 {
			c.c_array_proper(sp, dims)
		}
	} else {
		if uint64(sp.Modifiers)&symbol.M_LITTLE == symbol.M_LITTLE {
			c.c_out(sc, "%sputdouble(%s", "little_", sp.Name)
		} else {
			c.c_out(sc, "%sputdouble(%s", "", sp.Name)
		}
		if dims > 0 {
			c.c_array_proper(sp, dims)
		}
	}
	c.c_out(sc, ");\n")
}

func (c *CompilerContext) c_var_decl_put_parse_map(sp *symbol.Symbol_t, ip *symbol.Node_t, m *symbol.Symbol_t, dims int, dim *[]*symbol.Node_t, usenext int) {
	sc := c.OutputFiles["source"]

	// call putvlc()
	c.c_outi(sc, "if (%s%s%s(%sbs, %s", m.Name, c.c_static_scope, "putvlc", c.Prefix, sp.Name)
	if dims > 0 {
		c.c_array_proper(sp, dims)
	}
	// if we need lengthof, get number of bits
	if sp.Lengthof != 0 {
		c.c_out(sc, ", &%sparse", c.Prefix)
	}
	c.c_out(sc, ") == 0) {\n")

	// lookup failed
	c.indent()
	c.c_outi(sc, "%s(\"Map '%s' lookup for '%s", c.ErrorFunc, m.Name, sp.Name)
	if dims > 0 {
		for i := 0; i < dims; i++ {
			c.c_out(sc, "[%%d]")
		}
	}
	c.c_out(sc, "' failed\"")
	if dims > 0 {
		c.c_out(sc, ", ")
		for i := 0; i < dims; i++ {
			c.c_out(sc, "%s", c.c_gentmp_dim(i))
			if i != dims-1 {
				c.c_out(sc, ", ")
			}
		}
	}
	c.c_out(sc, ");\n")
	// increase error count
	c.c_outi(sc, "%sret++;\n", c.Prefix)
	c.outdent()
	c.c_outi(sc, "}\n")
}

func (c *CompilerContext) c_var_decl_put_parse(sp *symbol.Symbol_t, init *symbol.Node_t, parse *symbol.Node_t, dims int, dim *[]*symbol.Node_t, usenext int) {
	sc := c.OutputFiles["source"]

	var pp *symbol.Node_t
	var ip *symbol.Node_t

	if uint64(sp.Modifiers)&symbol.M_CONST == symbol.M_CONST || sp.Range != 0 {
		pp = sp.Parse
		ip = sp.Init
	} else {
		pp = parse
		ip = init
	}

	// if parse size is 0, we don't call putbits(); we just set the initial value, if any
	if is_literal(pp.Op) {
		if pp.Op != symbol.INT_LITERAL {
			fatal("Internal error: Expected integer literal")
		}

		if pp.Left.GetInt64() == 0 {
			if ip != nil {
				// just set initial value, if any
				if dims > 0 {
					c.c_array_prologue(sp, dims, dim)
				}
				c.c_outi(sc, "%s", sp.Name)
				if dims > 0 {
					c.c_array_proper(sp, dims)
				}
				c.c_out(sc, " = ")
				if sp.Ptype.Ident == symbol.FLOAT {
					c.c_out(sc, "(float)")
				}
				c.c_expression(sc, ip, false)
				c.c_out(sc, ";\n")

				// update lengthof
				if sp.Lengthof != 0 {
					c.c_outi(sc, sp.Plengthof.Name, c.Prefix)
					if dims > 0 {
						c.c_array_proper(sp.Plengthof, sp.Plengthof.Dims)
					}
					c.c_out(sc, " = 0;\n")
				}
				// done
				if dims > 0 {
					c.c_array_epilogue(sp, dims, dim)
				}
			}
			return
		}
		// we fall over to the code below
	}

	// parse size non-zero
	if dims > 0 {
		c.c_array_prologue(sp, dims, dim)
	}

	// if we use lengthof, or there is initial value, save parse (if not a map)
	if pp.Op != symbol.MAP_TYPE && (sp.Lengthof != 0 || ip != nil) {
		// Set the parse size before computing the init.
		// This is crucial, to preserve the order of expression
		// evaluation between get and put (parse expressions come first).
		// Not needed if type is greater than 'int', unless doing lengthof().

		if sp.Lengthof != 0 || sp.Ptype.Ident <= symbol.INT {
			c.c_outi(sc, "%sparse = ", c.Prefix)
			c.c_expression(sc, pp, false)
			c.c_out(sc, ";\n")
		}
	}

	// if a value is specified, set the var beforehand

	// set init
	if ip != nil {
		// id range; in this case, the ? : operator is not used
		if sp.Range != 0 {
			c.c_outi(sc, "if (!(")
			c.c_expression(sc, ip, false)
			c.c_out(sc, " <= %s && %s <= ", sp.Name, sp.Name)
			c.c_expression(sc, ip.Third.GetNode(), false)
			c.c_out(sc, ")) {\n")
			c.indent()
			c.c_outi(sc, "%s", sp.Name)
			if dims > 0 {
				c.c_array_proper(sp, dims)
			}
			c.c_out(sc, " = ")
			c.c_expression(sc, ip, false)
			c.c_out(sc, ";\n")
			c.outdent()
			c.c_outi(sc, "}\n")
		} else {
			c.c_outi(sc, "%s", sp.Name)
			if dims > 0 {
				c.c_array_proper(sp, dims)
			}
			c.c_out(sc, " = ")
			if sp.Ptype.Ident == symbol.FLOAT {
				c.c_out(sc, "(float)")
			}
			c.c_expression(sc, ip, false)
			c.c_out(sc, ";\n")
		}
	}

	if pp.Op == symbol.MAP_TYPE {
		// we have to do map no matter what so that it can be checked
		c.c_var_decl_put_parse_map(sp, ip, pp.Left.GetSymbol(), dims, dim, usenext)
	} else {
		// do simple only of we are not doing nextbits
		if usenext == 0 {
			c.c_var_decl_put_parse_simple(sp, ip, pp, dims, dim)
		}
	}

	// update length, if necessary (ignore usenext)
	if sp.Lengthof != 0 {
		c.c_outi(sc, sp.Plengthof.Name, c.Prefix)
		if dims > 0 {
			c.c_array_proper(sp.Plengthof, sp.Plengthof.Dims)
		}
		c.c_out(sc, " = %sparse;\n", c.Prefix)
	}

	if dims > 0 {
		c.c_array_epilogue(sp, dims, dim)
	}
}
