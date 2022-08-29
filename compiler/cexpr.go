package compiler

import (
	"io"
	"strings"

	"github.com/richinsley/goflav/symbol"
)

func (c *CompilerContext) c_expression(w io.Writer, exp *symbol.Node_t, bool_needed bool) {
	var op int
	if exp == nil {
		return
	}

	if exp.Paren == 1 {
		c.c_out(w, "(")
	}

	op = exp.Op
	switch op {
	case symbol.INT_LITERAL:
		c.c_out(w, "%d", exp.Left.GetInt64())
	case symbol.DOUBLE_LITERAL:
		c.c_out(w, "%f", exp.Left.GetFloat64())
	case symbol.BIT_LITERAL:
		c.c_out(w, "0x%x", exp.Left.GetBit().Val)
	case symbol.VARIABLE:
		// Prefix is used here to insert the prefix in 'lengthof' and other translator-generated
		// variables. In other variables it will be simply ignored (no '%s' in the name).
		sp := exp.Left.GetSymbol().Name
		if strings.Contains(sp, "%s") {
			c.c_out(w, sp, c.Prefix)
		} else {
			c.c_out(w, sp)
		}
	case symbol.ISIDOF:
		c.c_out(w, "%s", exp.Left.GetNode().Left.GetSymbol().Name)
		c.c_out(w, "::%sisidof(", c.Prefix)
		c.c_expression(w, exp.Right.GetNode(), false)
		c.c_out(w, ")")
	case symbol.SKIPBITS:
		c.c_out(w, "%sbs.skipbits(", c.Prefix)
		c.c_expression(w, exp.Left.GetNode(), false)
		c.c_out(w, ")")
	case symbol.NEXTBITS, symbol.SNEXTBITS, symbol.LITTLE_NEXTBITS, symbol.LITTLE_SNEXTBITS:
		c.c_out(w, "%sbs.next(", c.Prefix)
		c.c_expression(w, exp.Left.GetNode(), false)
		c.c_out(w, ", ")

		if op == symbol.NEXTBITS {
			c.c_out(w, "1, 0, ")
		} else if op == symbol.SNEXTBITS {
			c.c_out(w, "1, 1, ")
		} else if op == symbol.LITTLE_NEXTBITS {
			c.c_out(w, "0, 0, ")
		} else {
			c.c_out(w, "0, 1, ")
		}
		// if alignment expression is given, take care of it
		if exp.Right.GetNode() != nil {
			c.c_expression(w, exp.Right.GetNode(), false)
		} else {
			c.c_out(w, "0")
		}
		c.c_out(w, ")")
	case symbol.NEXTCODE:
		c.c_out(w, "%sbs.nextcode(0x%x, %d, ", c.Prefix, exp.Left.GetNode().Left.GetBit().Val, exp.Left.GetNode().Left.GetBit().Len)
		if exp.Right.GetNode() != nil {
			c.c_expression(w, exp.Right.GetNode(), false)
		} else {
			c.c_out(w, "0")
		}
		c.c_out(w, ")")
	case symbol.NUMBITS:
		c.c_out(w, "%sbs.getpos()", c.Prefix)
	case symbol.ARRAY:
		c.c_out(w, "{")
		c.c_expression(w, exp.Left.GetNode(), false)
		c.c_out(w, "}")
	default:
		// it is an operator
		if op == '?' {
			// ternary
			c.c_out(w, "(")
			c.c_expression(w, exp.Left.GetNode(), true)
			c.c_out(w, " ? ")
			c.c_expression(w, exp.Right.GetNode(), false)
			c.c_out(w, " : ")
			c.c_expression(w, exp.Third.GetNode(), false)
			c.c_out(w, ")")
		} else if exp.Left.GetNode() == nil && exp.Right.GetNode() != nil {
			// unary prefix
			c.c_out(w, "%s", symbol.S_op2str(op))
			c.c_expression(w, exp.Right.GetNode(), false)
		} else if exp.Left.GetNode() != nil && exp.Right.GetNode() == nil {
			// unary postfix
			c.c_expression(w, exp.Left.GetNode(), false)
			c.c_out(w, "%s", symbol.S_op2str(op))
		} else {
			// binary
			c.c_expression(w, exp.Left.GetNode(), false)

			// if '.', C++ uses a pointer
			if op == '.' && exp.Right.GetNode().Op == symbol.VARIABLE {
				c.c_out(w, "->")
			} else {
				c.c_out(w, "%s", symbol.S_op2str(op))
				// leave a blank after a comma
				if op == ',' {
					c.c_out(w, " ")
				}
			}

			c.c_expression(w, exp.Right.GetNode(), false)

			if op == '[' {
				c.c_out(w, "]")
			}
		}
	}

	if exp.Paren == 1 {
		c.c_out(w, ")")
	}
}
