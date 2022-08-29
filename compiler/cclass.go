package compiler

import (
	"fmt"

	"github.com/richinsley/goflav/symbol"
)

// determine if a class is a pure abstract class
func c_is_pure_abstract(sp *symbol.Symbol_t) bool {
	if sp.Id == nil || sp.Abstract == 0 || sp.Derived != nil {
		return false
	}
	return !c_is_pure_abstract(sp)
}

// generate put part of variable declarations of type class (simple)
func (c *CompilerContext) c_var_decl_put_class_simple(sp *symbol.Symbol_t, param *symbol.Node_t, dims int) {
	sc := c.OutputFiles["source"]
	c.c_outi(sc, "%sret += %s", c.Prefix, sp.Name)
	if dims > 0 {
		c.c_array_proper(sp, dims)
	}

	if param != nil {
		c.c_out(sc, "%sput(%sbs, ", c.c_scope, c.Prefix)
		c.c_expression(sc, param, false)
		// if param.Left.GetSymbol().Ptype != nil && param.Left.GetSymbol().Ptype.Ident == symbol.CLASS_TYPE {
		// 	c.c_out(sc, ".data()") // append .data for qt style data access
		// }
		c.c_out(sc, ");\n")
	} else {
		c.c_out(sc, "%sput(%sbs);\n", c.c_scope, c.Prefix)
	}
}

func (c *CompilerContext) c_new_class(sp *symbol.Symbol_t, dims int) {
	sc := c.OutputFiles["source"]

	c.c_outi(sc, "%s", sp.Name)
	if dims > 0 {
		c.c_array_proper(sp, dims)
	}

	c.c_out(sc, " = std::make_shared<%s>();\n", sp.Ptype.Name)
}

func (c *CompilerContext) c_var_decl_get_class_simple(sp *symbol.Symbol_t, param *symbol.Node_t, dims int, dim *[]*symbol.Node_t) {
	sc := c.OutputFiles["source"]

	if c.Gen_trace {
		// c_trace_entering_class(sp, dims)
	}

	// align, if necessary
	if sp.Ptype.Align != nil {
		if c.Gen_trace {
			// // save parse size
			// c_outi("%sparse = ", prefix);
			// c_expression(sp->ptype->align, 0);
			// c_out(";\n");
			// // do the align
			// c_outi("%sbs.align(%sparse);\n", prefix, prefix);
			// // trace
			// c_trace_aligned();
		} else {
			c.c_outi(sc, "%sbs.align(", c.Prefix)
			c.c_expression(sc, sp.Ptype.Align, false)
			c.c_out(sc, ");\n")
		}
	}

	if c_is_pure_abstract(sp.Ptype) {
		if c.w_abstract {
			c.lineno = sp.Lineno
			fmt.Printf("abstract class '%s' is pure (has no non-abstract parsable derived classes)", sp.Ptype.Name)
		}
		// construct a base class so that we have something to work with
		c.c_new_class(sp, dims)
	} else if sp.Ptype.Id != nil {
		c.c_var_decl_class_poly(sp, param, dims, dim)
	} else {
		c.c_new_class(sp, dims)
	}

	// now call the get() method of the class
	c.c_outi(sc, "%sret += %s", c.Prefix, sp.Name)
	if dims > 0 {
		c.c_array_proper(sp, dims)
	}

	if param != nil {
		c.c_out(sc, "%sget(%sbs, ", c.c_scope, c.Prefix)
		c.c_expression(sc, param, false)
		// if(!angelscript() && cpp() && cpp_qt() && param->left.sp->ptype && param->left.sp->ptype->ident == CLASS_TYPE)
		// s := param.Left.GetSymbol()
		// if s.Ptype != nil && s.Ptype.Ident == symbol.CLASS_TYPE {
		// 	c.c_out(sc, ".data()")
		// }
		c.c_out(sc, ");\n")
	} else {
		c.c_out(sc, "%sget(%sbs);\n", c.c_scope, c.Prefix)
	}
}

func (c *CompilerContext) c_var_decl_class_poly(sp *symbol.Symbol_t, param *symbol.Node_t, dims int, dim *[]*symbol.Node_t) {
	sc := c.OutputFiles["source"]

	// if non-pure and has ID, check its value
	if sp.Ptype.Id.Init == nil {
		fatal("Internal error: ID without value")
	}

	// align, if needed
	if sp.Ptype.Id.Align != nil {
		if c.Gen_trace {
			// // save parse size
			// c_outi("%sparse = ", prefix);
			// c_expression(sp->ptype->id->align, 0);
			// c_out(";\n");
			// // do the align
			// c_outi("%sbs.align(%sparse);\n", prefix, prefix);
			// // trace
			// c_trace_aligned();
		} else {
			c.c_outi(sc, "%sbs.align(", c.Prefix)
			c.c_expression(sc, sp.Ptype.Id.Align, false)
			c.c_out(sc, ");\n")
		}
	}

	// declare temp variable to hold probed id value; call the nextbits/nextvlc function
	if sp.Ptype.Id.Parse.Op == symbol.MAP_TYPE {
		c.c_var_decl_get_class_probe_id_map(sp, dims)
	} else {
		c.c_var_decl_get_class_probe_id_simple(sp)
	}

	// Generate comparison statements with IDs of this and all derived classes.
	// We use 'if's so that float and double can be used as IDs.
	/* numIDs */
	_ = c.c_var_decl_get_class_id(sp, dims, sp.Ptype, 0)

	// generate default statement
	c.c_outi(sc, "else {\n")
	c.indent()

	// trace failed ID lookup (simple; map-based is reported separately)
	if c.Gen_trace {
		// c_trace_failed_id_simple(sp, dims)
	}

	c.c_outi(sc, "%s(\"Unknown ID value for class '%s'", c.ErrorFunc, sp.Name)
	for i := 0; i < dims; i++ {
		c.c_out(sc, "[%%d]")
	}

	c.c_out(sc, " of type '%s': ", sp.Ptype.Name)
	if sp.Ptype.Id.Ptype.Ident <= symbol.INT {
		c.c_out(sc, "%%d")
	} else {
		c.c_outi(sc, "%%g")
	}

	c.c_out(sc, "\\n\", ")
	for i := 0; i < dims; i++ {
		c.c_out(sc, "%s, ", c.c_gentmp_dim(i))
	}
	c.c_out(sc, "%s%s_id);\n", c.Prefix, sp.Name)

	c.c_new_class(sp, dims)

	c.outdent()
	c.c_outi(sc, "}\n")
}

// jl - getvlc and putvlc need to receive pointer to the actual objects stored in std::shared_ptr
// generate get part of variable declarations of type class (map)
func (c *CompilerContext) c_var_decl_get_class_map(sp *symbol.Symbol_t, m *symbol.Symbol_t, dims int, dim *[]*symbol.Node_t, usenext int) {
	sc := c.OutputFiles["source"]

	if c.Gen_trace {
		// c_trace_entering_mapped_class(sp, dims, map)
	}

	// align, if necessary
	if sp.Ptype.Align != nil {
		if c.Gen_trace {
			/*
				// save parse size
				c_outi("%sparse = ", prefix);
				c_expression(sp->ptype->align, 0);
				c_out(";\n");
				// do the align
				c_outi("%sbs.align(%sparse);\n", prefix, prefix);
				// trace
				c_trace_aligned();
			*/
		} else {
			c.c_outi(sc, "%sbs.align(", c.Prefix)
			c.c_expression(sc, sp.Ptype.Align, false)
			c.c_out(sc, ");\n")
		}
	}

	// call nextvlc()/getvlc() - without address-of operator; classes always use pointers
	c.c_new_class(sp, dims)

	// qt specific
	var method string
	if usenext != 0 {
		method = "nextvlc"
	} else {
		method = "getvlc"
	}
	c.c_outi(sc, "if (%s%s%s(%sbs, %s.data()", m.Name, c.c_static_scope, method, c.Prefix, sp.Name)

	if dims > 0 {
		c.c_array_proper(sp, dims)
	}

	// if we are tracing or need lengthof, get number of bits
	if c.Gen_trace || sp.Lengthof != 0 {
		c.c_out(sc, ", &%sparse", c.Prefix)
	}

	// if we are tracing, we also need code value
	if c.Gen_trace {
		// c.c_out(sc, ", &%scode", prefix)
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
		// c.c_trace_failed_map(m, sp, dims)
	}

	c.outdent()
	c.c_outi(sc, "}\n")

	// update length, if necessary (ignore usenext)
	if sp.Lengthof != 0 {
		c.c_outi(sc, "%s", sp.Name)
		if dims > 0 {
			c.c_array_proper(sp, dims)
		}
		c.c_out(sc, c.c_scope)
		c.c_out(sc, sp.Plengthof.Name, c.Prefix)
		c.c_out(sc, " = %sparse;\n", c.Prefix)
	}

	// no expected value for classes -- just trace
	if c.Gen_trace {
		// c_trace_class_map(sp, m, dims, usenext)
	}
}

// generate put part of variable declaration of type class (map)
// jl - putvlc for qt needs data property to send pointer as parameter
func (c *CompilerContext) c_var_decl_put_class_map(sp *symbol.Symbol_t, m *symbol.Symbol_t, dims int) {
	sc := c.OutputFiles["source"]
	c.c_outi(sc, "if (%s%sputvlc(%sbs, %s.data()", m.Name, c.c_static_scope, c.Prefix, sp.Name)

	if dims > 0 {
		c.c_array_proper(sp, dims)
	}

	// if we need lengthof, get number of bits
	if sp.Lengthof != 0 {
		c.c_out(sc, ", &%s", sp.Name)
		if dims > 0 {
			for i := 0; i < dims; i++ {
				c.c_out(sc, "[%s]", c.c_gentmp_dim(i))
			}
		}
		c.c_out(sc, "%s%slengthof", c.c_scope, c.Prefix)
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

func (c *CompilerContext) c_var_decl_get_bac(sp *symbol.Symbol_t, param *symbol.Node_t, parse *symbol.Node_t, dims int, dim *[]*symbol.Node_t, usenext int) {
	sc := c.OutputFiles["source"]

	bac := parse.Left.GetSymbol()

	if c.Gen_trace {
		// c_trace_entering_mapped_class(sp, dims, bac)
	}

	c.c_outi(sc, "%s", sp.Name)
	if dims > 0 {
		c.c_array_proper(sp, dims)
	}
	c.c_out(sc, " = %s%sad_code(%sbs, ", bac.Name, c.c_static_scope, c.Prefix)
	c.c_expression(sc, param, false)
	c.c_out(sc, ");\n")
}

func (c *CompilerContext) c_var_decl_get_class(sp *symbol.Symbol_t, parse *symbol.Node_t, param *symbol.Node_t, dims int, dim *[]*symbol.Node_t, usenext int) {
	if dims > 0 {
		c.c_array_prologue(sp, dims, dim)
	}

	if parse != nil && parse.Op == symbol.MAP_TYPE {
		c.c_var_decl_get_class_map(sp, parse.Left.GetSymbol(), dims, dim, usenext)
	} else {
		c.c_var_decl_get_class_simple(sp, param, dims, dim)
	}

	if dims > 0 {
		c.c_array_epilogue(sp, dims, dim)
	}
}

// generate the put part of variable declarations of type class
func (c *CompilerContext) c_var_decl_put_class(sp *symbol.Symbol_t, param *symbol.Node_t, parse *symbol.Node_t, dims int, dim *[]*symbol.Node_t, usenext int) {
	if dims > 0 {
		c.c_array_prologue(sp, dims, dim)
	}

	if parse == nil {
		c.c_var_decl_put_class_simple(sp, param, dims)
	} else if parse.Op == symbol.MAP_TYPE {
		if usenext == 0 {
			c.c_var_decl_put_class_map(sp, parse.Left.GetSymbol(), dims)
		}
	} else {
		fatal("Internal error: Class with non-map parse size")
	}

	if dims > 0 {
		c.c_array_epilogue(sp, dims, dim)
	}
}

func (c *CompilerContext) c_var_decl_put_bac(sp *symbol.Symbol_t, param *symbol.Node_t, parse *symbol.Node_t, dims int, dim *[]*symbol.Node_t, usenext int) {
	sc := c.OutputFiles["source"]
	bac := parse.Left.GetSymbol()

	if dims > 0 {
		c.c_array_prologue(sp, dims, dim)
	}

	c.c_outi(sc, "%s%sae_code(%sbs, ", bac.Name, c.c_static_scope, c.Prefix)

	if dims > 0 {
		c.c_out(sc, "%s", sp.Name)
		c.c_array_proper(sp, dims)
		c.c_out(sc, ", ")
	} else {
		c.c_out(sc, "%s, ", sp.Name)
	}

	c.c_expression(sc, param, false)
	c.c_out(sc, ");\n")

	if dims > 0 {
		c.c_array_epilogue(sp, dims, dim)
	}
}
