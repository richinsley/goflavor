package compiler

import (
	"github.com/richinsley/goflavor/symbol"
)

func (c *CompilerContext) Map_decl(sp *symbol.Symbol_t, stmts *symbol.List_t) {
	if sp == nil {
		return
	}

	if sp.Ptype == nil {
		fatal("Internal error: Map without type information")
	}

	// emplace in header
	h := c.OutputFiles["header"]

	c.c_out(h, "\nclass %s {\n", sp.Name)

	c.indent()

	// declare nextvlc()/getvlc()/putvlc() and switch output files
	// nextvlc(), getvlc()
	if c.Gen_get {
		mod := sp.Modifiers & ^uint(symbol.M_CONST)
		s := S_mods2stdint(mod, sp.Ptype.Name)

		c.c_outi(h, "public: static int nextvlc(%s &%sbs, %s *%sarg, int *%sparse=NULL, int *%scode=NULL);\n",
			c.BitstreamClass, c.Prefix,
			s, c.Prefix, c.Prefix, c.Prefix)
		c.c_outi(h, "public: static int getvlc(%s &%sbs, %s *%sarg, int *%sparse=NULL, int *%scode=NULL);\n",
			c.BitstreamClass, c.Prefix,
			s, c.Prefix, c.Prefix, c.Prefix)
	}

	// putvlc()
	if c.Gen_put {
		if sp.Ptype.Ident == symbol.CLASS_TYPE {
			// if CLASS_TYPE pass a pointer to argument
			isunsigned := ""
			if uint64(sp.Modifiers)&symbol.M_UNSIGNED == symbol.M_UNSIGNED {
				isunsigned = "unsigned "
			}
			c.c_outi(h, "public: static int putvlc(%s &%sbs, %s%s *%sarg, int *%sparse=NULL, int *%scode=NULL);\n",
				c.BitstreamClass, c.Prefix,
				isunsigned,
				sp.Ptype.Name, c.Prefix, c.Prefix, c.Prefix)
		} else {
			mod := sp.Modifiers & ^uint(symbol.M_CONST)
			s := S_mods2stdint(mod, sp.Ptype.Name)

			// otherwise, just value
			c.c_outi(h, "public: static int putvlc(%s &%sbs, %s %sarg, int *%sparse=NULL, int *%scode=NULL);\n",
				c.BitstreamClass, c.Prefix,
				s, c.Prefix, c.Prefix, c.Prefix)
		}
	}

	// generate getvlc function; no next, if the map uses escape
	if c.Gen_get && sp.Escape == 0 {
		c.c_map_next(sp, stmts)
	}

	// generate getvlc function
	if c.Gen_get {
		c.c_map_get(sp, stmts)
	}

	// generate putvlc function
	if c.Gen_put {
		c.c_map_put(sp, stmts)
	}

	c.outdent()
	c.c_out(h, "};\n")
}

func (c *CompilerContext) c_map_next(sp *symbol.Symbol_t, stmts *symbol.List_t) {
	sc := c.OutputFiles["source"]

	c.c_out(sc, "\n")

	mod := sp.Modifiers & ^uint(symbol.M_CONST)
	s := S_mods2stdint(mod, sp.Ptype.Name)

	c.c_outi(sc, "int %s::nextvlc(%s &%sbs, %s *%sarg, int *%sparse, int *%scode) {\n",
		sp.Name, c.BitstreamClass, c.Prefix,
		s, c.Prefix, c.Prefix, c.Prefix)

	c.indent()
	// declare hit variable (used for return value), data and size
	c.c_outi(sc, "int %sdata = 0, %ssize = 0;\n", c.Prefix, c.Prefix)
	// no escape code allowed if look-ahead parsing
	c.c_outi(sc, "int %shit = 1;\n\n", c.Prefix)

	// output the core nextvlc code (series of nextbits with case statements)
	c.c_map_next_core(sp, stmts, true)

	// return code and size, if requested
	c.c_outi(sc, "if (%sparse != NULL) *%sparse = %ssize;\n", c.Prefix, c.Prefix, c.Prefix)
	c.c_outi(sc, "if (%scode != NULL) *%scode = %sdata;\n", c.Prefix, c.Prefix, c.Prefix)
	c.c_outi(sc, "return %shit;\n", c.Prefix)

	c.outdent()
	c.c_outi(sc, "}\n")
}

func (c *CompilerContext) c_map_next_core(sp *symbol.Symbol_t, stmts *symbol.List_t, usenext bool) {
	sc := c.OutputFiles["source"]
	lp := stmts

	// sanity check
	if lp.E1 == nil || lp.E1.Op != symbol.BIT_LITERAL || lp.E1.Left.GetBit() == nil {
		fatal("Internal error: Expected code entry with bit literal")
	}

	size := lp.E1.Left.GetBit().Len

	// get data
	c.c_outi(sc, "%sdata = %sbs.nextbits(%d);\n", c.Prefix, c.Prefix, size)
	c.c_outi(sc, "switch (%sdata) {\n", c.Prefix)
	for lp != nil {
		// sanity check
		if lp.E1 == nil || lp.E1.Op != symbol.BIT_LITERAL || lp.E1.Left.GetBit() == nil {
			fatal("Internal error: Expected code entry with bit literal")
		}

		// did the size change?
		if lp.E1.Left.GetBit().Len != size {
			c.c_outi(sc, "default:\n")
			c.indent()
			c.c_map_next_core(sp, lp, usenext)
			c.outdent()
			break
		}

		// check for match
		c.c_outi(sc, "case %d:\n", lp.E1.Left.GetBit().Val)
		c.indent()

		// skip bits, if we are doing get - must be done here so that escapes read correctly
		if !usenext {
			c.c_outi(sc, "%sbs.skipbits(%d);\n", c.Prefix, size)
		}

		// output assignment code
		c.c_map_get_assign(sp, lp)

		// save size
		c.c_outi(sc, "%ssize = %d;\n", c.Prefix, lp.E1.Left.GetBit().Len)

		c.c_outi(sc, "break;\n")
		c.outdent()

		// if at the end, set hit to 0 and use last entry
		if lp.Next == nil {
			c.c_outi(sc, "default:\n")
			c.indent()
			c.c_outi(sc, "%shit = 0;\n", c.Prefix)
			c.outdent()
		}
		// next code
		lp = lp.Next
	}
	// close switch statement
	c.c_outi(sc, "}\n")
}

func (c *CompilerContext) c_map_get_assign(sp *symbol.Symbol_t, entry *symbol.List_t) {
	// different handling depending on if we have simple or class type
	if sp.Ptype.Ident != symbol.CLASS_TYPE {
		c.c_map_get_assign_simple(sp, entry)
	} else {
		c.c_map_get_assign_class(sp, entry)
	}
}

func (c *CompilerContext) c_map_get_assign_simple(sp *symbol.Symbol_t, entry *symbol.List_t) {
	sc := c.OutputFiles["source"]

	p := entry.Sub1

	if p.Type == symbol.ESC_FTYPE || p.Type == symbol.ESC_MAP {
		c.c_outi(sc, "%sesc_bits = ", c.Prefix)
		c.c_expression(sc, p.E3, false)
		c.c_out(sc, ";\n")
	}

	c.c_outi(sc, "*%sarg = ", c.Prefix)

	// figure out if we have simple assignment or escape
	if p.Type == symbol.ESC_FTYPE || p.Type == symbol.ESC_MAP {
		c.c_map_get_assign_esc(p)
	} else {
		if sp.Ptype.Ident == symbol.FLOAT && p.E1.Type == symbol.DOUBLE {
			c.c_out(sc, "(float)")
		}
		c.c_expression(sc, p.E1, false)
	}
	c.c_out(sc, ";\n")
}

func (c *CompilerContext) c_map_get_assign_esc(entry *symbol.List_t) {
	sc := c.OutputFiles["source"]
	esc_type := entry.E2
	mod := entry.E1.Left.GetUint64()

	// no map cascades at this time
	if entry.Type == symbol.ESC_MAP {
		fatal("Internal error: Map cascading not supported")
	}

	// parse length should be a literal
	if !is_literal(entry.E3.Op) {
		c.c_out(sc, "0") // error already reported - just assign 0
		return
	}

	islittle := ""
	if mod&symbol.M_LITTLE == symbol.M_LITTLE {
		islittle = "little_"
	}
	isunsigned := "s"
	if mod&symbol.M_UNSIGNED == symbol.M_UNSIGNED || esc_type.Ptype.Ident > symbol.INT {
		isunsigned = ""
	}

	c.c_out(sc, "%sbs.%s%sget", c.Prefix, islittle, isunsigned)

	if esc_type.Ptype.Ident <= symbol.INT {
		c.c_out(sc, "bits(%sesc_bits)", c.Prefix)
	} else if esc_type.Ptype.Ident == symbol.FLOAT {
		c.c_out(sc, "float()")
	} else if esc_type.Ptype.Ident == symbol.DOUBLE && (esc_type.Ptype.Modifiers&uint(symbol.M_LONG) == uint(symbol.M_LONG)) {
		c.c_out(sc, "ldouble()")
	} else {
		c.c_out(sc, "double()")
	}
}

func (c *CompilerContext) c_map_get_assign_class(sp *symbol.Symbol_t, entry *symbol.List_t) {
	sc := c.OutputFiles["source"]
	var p *symbol.List_t

	// find the statements for this class
	stmts := c.find_class_stmts(sp.Ptype)
	if stmts == nil {
		fatal("Internal error: Cannot find declaration of class '%s'", sp.Name)
	}

	if entry.Sub1.Type == symbol.ESC_FTYPE || entry.Sub1.Type == symbol.ESC_MAP {
		p = entry.Sub1
	} else {
		p = entry.Sub1.Sub1
	}

	// traverse declarations and output assignment code for each variable
	for stmts != nil {
		switch stmts.Type {
		case symbol.DECL:
			if p == nil {
				return
			}
			if p.Type == symbol.ESC_FTYPE || p.Type == symbol.ESC_MAP {
				c.c_outi(sc, "%sesc_bits = ", c.Prefix)
				c.c_expression(sc, p.E3, false)
				c.c_out(sc, ";\n")
			}

			c.c_outi(sc, "%sarg%s%s = ", c.Prefix, c.c_scope, stmts.Sp.Name)

			// figure out if we have simple assignment or escape
			if p.Type == symbol.ESC_FTYPE || p.Type == symbol.ESC_MAP {
				c.c_map_get_assign_esc(p)
			} else {
				if stmts.Sp.Ptype.Ident == symbol.FLOAT && p.E1.Type == symbol.DOUBLE {
					c.c_out(sc, "(float)")
				}
				c.c_expression(sc, p.E1, false)
			}
			c.c_out(sc, ";\n")

			p = p.Next
		default:
			return
		}
		stmts = stmts.Next
	}
}

func (c *CompilerContext) c_map_get(sp *symbol.Symbol_t, stmts *symbol.List_t) {
	sc := c.OutputFiles["source"]
	c.c_out(sc, "\n")

	mod := sp.Modifiers & ^uint(symbol.M_CONST)
	s := S_mods2stdint(mod, sp.Ptype.Name)

	c.c_outi(sc, "int %s::getvlc(%s &%sbs, %s *%sarg, int *%sparse, int *%scode) {\n",
		sp.Name, c.BitstreamClass, c.Prefix,
		s, c.Prefix, c.Prefix, c.Prefix)

	c.indent()
	// declare hit variable (used for return value), data and size
	c.c_outi(sc, "int %sdata = 0, %ssize = 0;\n", c.Prefix, c.Prefix)
	c.c_outi(sc, "int %sesc_bits = 0;\n", c.Prefix)
	c.c_outi(sc, "int %shit = 1;\n\n", c.Prefix)

	// output the core getvlc code (series of getbits with case statements)
	c.c_map_next_core(sp, stmts, false)

	// return code and size, if requested
	c.c_outi(sc, "if (%sparse != NULL) *%sparse = %ssize;\n", c.Prefix, c.Prefix, c.Prefix)
	c.c_outi(sc, "if (%scode != NULL) *%scode = %sdata;\n", c.Prefix, c.Prefix, c.Prefix)
	c.c_outi(sc, "return %shit;\n", c.Prefix)

	c.outdent()
	c.c_outi(sc, "}\n")
}

func (c *CompilerContext) c_map_put(sp *symbol.Symbol_t, stmts *symbol.List_t) {
	sc := c.OutputFiles["source"]
	c.c_outi(sc, "\n")

	if sp.Ptype.Ident == symbol.CLASS_TYPE {
		isunsigned := ""
		if sp.Modifiers&uint(symbol.M_UNSIGNED) == uint(symbol.M_UNSIGNED) {
			isunsigned = "unsigned "
		}
		c.c_outi(sc, "int %s::putvlc(%s &%sbs, %s%s *%sarg, int *%sparse, int *%scode) {\n",
			sp.Name, c.BitstreamClass, c.Prefix,
			isunsigned,
			sp.Ptype.Name, c.Prefix, c.Prefix, c.Prefix)
	} else {
		mod := sp.Modifiers & ^uint(symbol.M_CONST)
		s := S_mods2stdint(mod, sp.Ptype.Name)

		c.c_outi(sc, "int %s::putvlc(%s &%sbs, %s %sarg, int *%sparse, int *%scode) {\n",
			sp.Name, c.BitstreamClass, c.Prefix,
			s, c.Prefix, c.Prefix, c.Prefix)
	}
	c.indent()

	// declare hit variable (used for return value), data and size
	c.c_outi(sc, "int %sdata = 0, %ssize = 0;\n", c.Prefix, c.Prefix)
	c.c_outi(sc, "int %sesc_bits = 0;\n", c.Prefix)

	c.c_outi(sc, "int %shit = 1;\n\n", c.Prefix)

	// output the core putvlc code (series of putbits with case statements
	c.c_map_put_core(sp, stmts)

	c.outdent()
	c.c_outi(sc, "}\n")
}

func (c *CompilerContext) c_map_put_core(sp *symbol.Symbol_t, stmts *symbol.List_t) {
	sc := c.OutputFiles["source"]

	lp := stmts
	var last *symbol.List_t = nil
	var size int

	// put data
	for lp != nil {
		// sanity check
		if lp.E1 == nil || lp.E1.Op != symbol.BIT_LITERAL || lp.E1.Left.GetBit() == nil {
			fatal("Internal error: Expected code entry with bit literal")
		}

		if lp.Sub1.Type == symbol.ESC_FTYPE || lp.Sub1.Type == symbol.ESC_MAP {
			// save one and only escape code for last
			last = lp
			lp = lp.Next
			continue
		}

		// get bit length
		size = lp.E1.Left.GetBit().Len

		// check for match
		c.c_outi(sc, "if (")
		c.c_map_put_compare(sp, lp.Sub1)
		c.c_out(sc, ") {\n")
		c.indent()

		// put bits
		if lp.Sp == nil {
			c.c_outi(sc, "%sbs.putbits(%d,%d);\n", c.Prefix, lp.E1.Left.GetBit().Val, size)
		} else {
			islittle := ""
			if sp.Ptype.Id.Modifiers&uint(symbol.M_LITTLE) == uint(symbol.M_LITTLE) {
				islittle = "little_"
			}
			c.c_outi(sc, "%sbs.%sputbits(%d,%d);\n", c.Prefix,
				islittle, lp.E1.Left.GetBit().Val, size)
		}

		// save size
		c.c_outi(sc, "%ssize = %d;\n", c.Prefix, lp.E1.Left.GetBit().Len)
		// save data
		c.c_outi(sc, "%sdata = %d;\n", c.Prefix, lp.E1.Left.GetBit().Val)

		// return code and size, if requested
		c.c_outi(sc, "if (%sparse != NULL) *%sparse = %ssize;\n", c.Prefix, c.Prefix, c.Prefix)
		c.c_outi(sc, "if (%scode != NULL) *%scode = %sdata;\n", c.Prefix, c.Prefix, c.Prefix)
		c.c_outi(sc, "return %shit;\n", c.Prefix)

		c.outdent()
		c.c_outi(sc, "}\n")

		// next code
		lp = lp.Next
	}

	// no escape code
	if last == nil {
		c.c_outi(sc, "%shit = 0;\n", c.Prefix)
		c.c_outi(sc, "if (%sparse != NULL) *%sparse = %ssize;\n", c.Prefix, c.Prefix, c.Prefix)
		c.c_outi(sc, "if (%scode != NULL) *%scode = %sdata;\n", c.Prefix, c.Prefix, c.Prefix)
		c.c_outi(sc, "return %shit;\n", c.Prefix)
	} else {
		// get bit length
		size = last.E1.Left.GetBit().Len

		// put bits
		if last.Sp == nil {
			c.c_outi(sc, "%sbs.putbits(%d,%d);\n", c.Prefix, last.E1.Left.GetBit().Val, size)
		} else {
			islittle := ""
			if sp.Ptype.Id.Modifiers&uint(symbol.M_LITTLE) == uint(symbol.M_LITTLE) {
				islittle = "little_"
			}
			c.c_outi(sc, "%sbs.%sputbits(%d,%d);\n", c.Prefix,
				islittle, last.E1.Left.GetBit().Val, size)
		}

		// save size
		c.c_outi(sc, "%ssize = %d;\n", c.Prefix, last.E1.Left.GetBit().Len)
		// save data
		c.c_outi(sc, "%sdata = %d;\n", c.Prefix, last.E1.Left.GetBit().Val)

		if sp.Ptype.Ident != symbol.CLASS_TYPE {
			c.c_map_put_esc_simple(sp, last.Sub1)
		} else {
			c.c_map_put_esc_class(sp, last.Sub1)
		}

		c.c_outi(sc, "if (%sparse != NULL) *%sparse = %ssize;\n", c.Prefix, c.Prefix, c.Prefix)
		c.c_outi(sc, "if (%scode != NULL) *%scode = %sdata;\n", c.Prefix, c.Prefix, c.Prefix)
		c.c_outi(sc, "return %shit;\n", c.Prefix)
	}
}

func (c *CompilerContext) c_map_put_compare(sp *symbol.Symbol_t, entry *symbol.List_t) {
	if sp.Ptype.Ident != symbol.CLASS_TYPE {
		c.c_map_put_compare_simple(sp, entry)
	} else {
		c.c_map_put_compare_class(sp, entry)
	}
}

func (c *CompilerContext) c_map_put_compare_simple(sp *symbol.Symbol_t, entry *symbol.List_t) {
	sc := c.OutputFiles["source"]
	c.c_out(sc, "%sarg == ", c.Prefix)
	if sp.Ptype.Ident == symbol.FLOAT && entry.E1.Type == symbol.DOUBLE {
		c.c_out(sc, "(float)")
	}
	c.c_expression(sc, entry.E1, false)
}

func (c *CompilerContext) c_map_put_compare_class(sp *symbol.Symbol_t, entry *symbol.List_t) {
	sc := c.OutputFiles["source"]
	p := entry.Sub1

	// find the statements for this class
	stmts := c.find_class_stmts(sp.Ptype)
	if stmts == nil {
		fatal("Internal error: Cannot find declaration of class '%s'", sp.Name)
	}

	// traverse declarations and output assignment code for each variable
	for stmts != nil {
		switch stmts.Type {
		case symbol.DECL:
			// declarations are ok, even parsable ones, but not with classes
			if stmts.Sp.Ptype.Ident == symbol.CLASS_TYPE {
				return
			}

			if p == nil {
				return
			}

			c.c_out(sc, "(%sarg%s%s == ", c.Prefix, c.c_scope, stmts.Sp.Name)

			if stmts.Sp.Ptype.Ident == symbol.FLOAT && p.E1.Type == symbol.DOUBLE {
				c.c_out(sc, "(float)")
			}
			c.c_expression(sc, p.E1, false)
			c.c_out(sc, ")")
			if stmts.Next != nil && !is_verbatim(stmts.Next.Type) {
				c.c_out(sc, " && ")
			}
			p = p.Next

		default:
			// everything else, isn't - has been reported already
			return
		}
		stmts = stmts.Next
	}
}

func (c *CompilerContext) c_map_put_esc_simple(sp *symbol.Symbol_t, entry *symbol.List_t) {
	sc := c.OutputFiles["source"]
	pp := entry.E3
	if !is_literal(pp.Op) {
		c.c_out(sc, "0")
		return
	}

	// no map cascades at this time
	if entry.Type == symbol.ESC_MAP {
		fatal("Internal error: Map cascading not supported")
	}

	islittle := ""
	if uint64(sp.Modifiers)&symbol.M_LITTLE == symbol.M_LITTLE {
		islittle = "little_"
	}
	isunsigned := "s"
	if uint64(sp.Modifiers)&symbol.M_UNSIGNED == symbol.M_UNSIGNED || sp.Ptype.Ident > symbol.INT {
		isunsigned = ""
	}
	c.c_outi(sc, "%sbs.%s%s%s", c.Prefix, islittle, isunsigned, "put")

	if sp.Ptype.Ident <= symbol.INT {
		c.c_out(sc, "bits(%sarg,", c.Prefix)
		c.c_expression(sc, pp, false)
		c.c_out(sc, ");\n")
	} else if sp.Ptype.Ident == symbol.FLOAT {
		c.c_out(sc, "float(%sarg);\n", c.Prefix)
	} else if sp.Ptype.Ident == symbol.DOUBLE && (uint64(sp.Modifiers)&symbol.M_LONG == symbol.M_LONG) {
		c.c_out(sc, "ldouble(%sarg);\n", c.Prefix)
	} else {
		c.c_out(sc, "double(%sarg);\n", c.Prefix)
	}
}

func (c *CompilerContext) c_map_put_esc_class(sp *symbol.Symbol_t, entry *symbol.List_t) {
	sc := c.OutputFiles["source"]
	pp := entry
	stmts := c.find_class_stmts(sp.Ptype)
	if stmts == nil {
		fatal("Internal error: Cannot find declaration of class '%s'", sp.Name)
	}

	// no map cascades at this time
	if entry.Type == symbol.ESC_MAP {
		fatal("Internal error: Map cascading not supported")
	}

	for stmts != nil {
		switch stmts.Type {
		case symbol.DECL:
			// declarations are ok, even parsable ones, but not with classes
			if stmts.Sp.Ptype.Ident == symbol.CLASS_TYPE {
				return
			}
			if pp == nil {
				return
			}
			if !is_literal(pp.E3.Op) {
				c.c_out(sc, "0")
				return
			}

			islittle := ""
			if uint64(stmts.Sp.Modifiers)&symbol.M_LITTLE == symbol.M_LITTLE {
				islittle = "little_"
			}
			c.c_outi(sc, "%sbs.%sput", c.Prefix, islittle)

			if stmts.Sp.Ptype.Ident <= symbol.INT {
				c.c_out(sc, "bits(%sarg%s%s,", c.Prefix, c.c_scope, stmts.Sp.Name)
				c.c_expression(sc, pp.E3, false)
				c.c_out(sc, ");\n")
			} else if stmts.Sp.Ptype.Ident == symbol.FLOAT {
				c.c_out(sc, "float(%sarg%s%s);\n", c.Prefix, c.c_scope, stmts.Sp.Name)
			} else if stmts.Sp.Ptype.Ident == symbol.DOUBLE && (uint64(stmts.Sp.Modifiers)&symbol.M_LONG == symbol.M_LONG) {
				c.c_out(sc, "ldouble(%sarg%s%s);\n", c.Prefix, c.c_scope, stmts.Sp.Name)
			} else {
				c.c_out(sc, "double(%sarg%s%s);\n", c.Prefix, c.c_scope, stmts.Sp.Name)
			}

			pp = pp.Next

		default:
			// everything else, isn't - has been reported already
			return
		}
		stmts = stmts.Next
	}
}
