package compiler

import (
	"github.com/richinsley/goflavor/symbol"
)

// 'sp' (used by c_variable_decl_get_class_boot); cnt is the number of comparisons already produced.
// Returns cnt + number of comparisons produced in this run.
func (c *CompilerContext) c_var_decl_get_class_id(orig *symbol.Symbol_t, dims int, sp *symbol.Symbol_t, cnt int) int {
	sc := c.OutputFiles["source"]

	if sp.Id != nil && sp.Abstract == 0 {
		// output ID check code, but only if the class is not abstract
		if sp.Id.Init == nil {
			fatal("Internal error: ID without value")
		}

		c.c_ident(sc)

		// if we are not the first to output an ID, prepend an 'else'
		if cnt > 0 {
			c.c_out(sc, "else ")
		}

		// id range
		if sp.Id.Range != 0 {
			c.c_out(sc, "if (")
			c.c_expression(sc, sp.Id.Init, false)
			c.c_out(sc, " <= %s%s_id && %s%s_id <= ", c.Prefix, orig.Name, c.Prefix, orig.Name)
			c.c_expression(sc, sp.Id.Init.Third.GetNode(), false)
			c.c_out(sc, ") {\n")
			c.indent()
			c.c_outi(sc, "%s", orig.Name)
			if dims > 0 {
				c.c_array_proper(orig, dims)
			}

			c.c_out(sc, " = std::make_shared<%s>();\n", sp.Name)

			c.outdent()
			c.c_outi(sc, "}\n")
		} else {
			c.c_out(sc, "if (%s%s_id == ", c.Prefix, orig.Name)
			c.c_expression(sc, sp.Id.Init, false)
			c.c_out(sc, ") {\n")
			c.indent()
			c.c_outi(sc, "%s", orig.Name)
			if dims > 0 {
				c.c_array_proper(orig, dims)
			}
			c.c_out(sc, " = std::make_shared<%s>();\n", sp.Name)

			c.outdent()
			c.c_outi(sc, "}\n")
		}
		// one more comparison
		cnt++
	}

	// try all derived classes as well
	if sp.Derived != nil {
		for _, p := range *sp.Derived {
			cnt = c.c_var_decl_get_class_id(orig, dims, p, cnt)
		}
	}

	return cnt
}

func (c *CompilerContext) c_var_decl_get_class_probe_id_simple(sp *symbol.Symbol_t) {
	sc := c.OutputFiles["source"]

	islittle := ""
	isunsigned := "s"
	if sp.Ptype.Id.Modifiers&uint(symbol.M_LITTLE) == uint(symbol.M_LITTLE) {
		islittle = "little_"
	}
	if sp.Ptype.Id.Modifiers&uint(symbol.M_UNSIGNED) == uint(symbol.M_UNSIGNED) {
		isunsigned = ""
	}

	switch sp.Ptype.Id.Ptype.Ident {
	case symbol.BIT:
		fallthrough
	case symbol.CHAR:
		fallthrough
	case symbol.INT:
		// if we are tracing, save size
		if c.Gen_trace {
			// c_outi("%sparse = ", prefix);
			// c_expression(sp->ptype->id->parse, 0);
			// c_out(";\n");
			// c_outi("%s%s_id = %sbs.%s%snextbits( %sparse );\n",
			// 			prefix, sp->name, prefix,
			// 			(sp->ptype->id->modifiers & M_LITTLE ? "little_" : ""),
			// 			(sp->ptype->id->modifiers & M_UNSIGNED ? "" : "s"), prefix);
		} else {

			c.c_outi(sc, "%s%s_id = %sbs.%s%snextbits(",
				c.Prefix, sp.Name, c.Prefix,
				islittle,
				isunsigned)

			c.c_expression(sc, sp.Ptype.Id.Parse, false)
			c.c_out(sc, ");\n")
		}
	case symbol.FLOAT:
		// if we are tracing save size
		if c.Gen_trace {
			// c_outi("%sparse = 32;\n", prefix)
		}
		c.c_outi(sc, "%s%s_id = %sbs.%snextfloat();\n",
			c.Prefix, sp.Name, c.Prefix,
			islittle)
	case symbol.DOUBLE:
		if uint64(sp.Modifiers)&symbol.M_LONG != symbol.M_LONG {
			// if we are tracing save size
			if c.Gen_trace {
				// c_outi("%sparse = 64;\n", prefix)
			}
			c.c_outi(sc, "%s%s_id = %sbs.%snextdouble();\n",
				c.Prefix, sp.Name, c.Prefix,
				islittle)
		} else {
			// if we are tracing save size
			if c.Gen_trace {
				// c_outi("%sparse = 64;\n", prefix)
			}
			c.c_outi(sc, "%s%s_id = %sbs.%snextldouble();\n",
				c.Prefix, sp.Name, c.Prefix,
				islittle)
		}
		break
	default:
		fatal("Internal error: Unknown ID type: '%s'", sp.Ptype.Id.Ptype.Name)
	}
}

func (c *CompilerContext) c_class_id_put(sp *symbol.Symbol_t) {
	sc := c.OutputFiles["source"]

	// generate put ID code, but not for abstract classes
	if sp == nil || sp.Abstract != 0 || sp.Id == nil {
		return
	}

	c.c_outi(sc, "if (%sid_parsed == 0) {\n", c.Prefix)
	c.indent()
	c.c_var_decl_put(sp.Id, nil, nil, nil, nil, 0, nil, 0)
	c.c_outi(sc, "%sid_parsed = 1;\n", c.Prefix)
	c.outdent()
	c.c_outi(sc, "}\n")
}

func c_find_id_notabstract(sp *symbol.Symbol_t) *symbol.Symbol_t {
	if sp == nil {
		return nil
	}

	if sp.Id != nil {
		return sp
	}

	if sp.Ptype == nil {
		return nil
	} else {
		return c_find_id_notabstract(sp.Ptype)
	}
}

// check if a class or a base class has an ID; returns the class where an ID was first found
func c_find_id(sp *symbol.Symbol_t) *symbol.Symbol_t {
	if sp == nil {
		return nil
	}

	if sp.Id != nil {
		return sp
	}

	if sp.Ptype == nil {
		return nil
	}
	return c_find_id(sp.Ptype)
}

// get the ID of a class
func (c *CompilerContext) c_class_id_get(sp *symbol.Symbol_t) {
	if sp == nil || sp.Abstract != 0 || sp.Id == nil {
		return
	}

	sc := c.OutputFiles["source"]
	c.c_outi(sc, "if (%sid_parsed == 0) {\n", c.Prefix)
	c.indent()
	c.c_var_decl_get(sp.Id, nil, nil, nil, nil, 0, nil, 0)
	c.c_outi(sc, "%sid_parsed = 1;\n", c.Prefix)
	c.outdent()
	c.c_outi(sc, "}\n")
}

func (c *CompilerContext) c_class_isidof_check_id(sp *symbol.Symbol_t, cnt int) int {
	var p *symbol.Symbol_t
	var derivedp *[]*symbol.Symbol_t
	sc := c.OutputFiles["source"]

	// output ID check code, but only if the class is not abstract
	if sp.Id != nil && sp.Abstract == 0 {
		if sp.Id.Init == nil {
			fatal("Internal error: ID without value")
		}

		c.c_ident(sc)

		// if we are not the first to output an ID prepend an 'else'
		if cnt > 0 {
			c.c_out(sc, "else ")
		}

		if sp.Id.Range == 0 {
			c.c_out(sc, "if (tag == ")
			c.c_expression(sc, sp.Id.Init, false)
		} else {
			c.c_out(sc, "if (tag >= ")
			c.c_expression(sc, sp.Id.Init, false)
			c.c_out(sc, " && tag <= ")
			c.c_expression(sc, sp.Id.Init.Third.GetNode(), false)
		}

		c.c_out(sc, ")\n")
		c.indent()
		c.c_outi(sc, "return 1;\n")
		c.outdent()

		// one more comparison
		cnt++
	}

	// try all derived classes as well
	// spat
	derivedp = sp.Derived
	if derivedp != nil {
		for _, p = range *derivedp {
			cnt = c.c_class_isidof_check_id(p, cnt)
		}
	}

	return cnt
}

func (c *CompilerContext) c_var_decl_get_class_probe_id_map(sp *symbol.Symbol_t, dims int) {
	sc := c.OutputFiles["source"]

	m := sp.Ptype.Id.Parse.Left.GetSymbol()

	//  call getvlc()
	c.c_outi(sc, "if (%s%snextvlc(%sbs, &%s%s_id", m.Name, c.c_static_scope, c.Prefix, c.Prefix, sp.Name)

	// if we are tracing, get number of bits and code value
	if c.Gen_trace {
		// c.c_out(sc, ", &%sparse, &%scode", prefix, prefix)
	}

	c.c_out(sc, ") != 0) {\n")

	// lookup failed
	c.indent()
	c.c_outi(sc, "%s(\"Map '%s' lookup for ID '%s", c.ErrorFunc, m.Name, sp.Name)
	if dims > 0 {
		for i := 0; i < dims; i++ {
			c.c_out(sc, "[%%d]")
		}
	}

	c.c_out(sc, ".%s' failed\"", sp.Ptype.Id.Name)
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

	if c.Gen_trace {
		// c_trace_failed_id_map(sp, sp->ptype->id->parse->left.sp, dims)
	}

	c.outdent()
	c.c_outi(sc, "}\n")
}
