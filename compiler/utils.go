package compiler

import (
	"path/filepath"

	"example.com/goflav/symbol"
)

func basename(path string) string {
	_, f := filepath.Split(path)
	return f
}

func is_literal(id int) bool {
	if id == symbol.BIT_LITERAL || id == symbol.INT_LITERAL || id == symbol.DOUBLE_LITERAL || id == symbol.STRING_LITERAL {
		return true
	}
	return false
}

// find the statements of a particular class
func (c *CompilerContext) find_class_stmts(sp *symbol.Symbol_t) *symbol.List_t {
	p := c.Symbols
	for p != nil {
		if p.Sp == sp {
			return p.Sub1
		}
		p = p.Next
	}
	return nil
}

func is_verbatim(Type int) bool {
	if symbol.VERBATIM <= Type && Type <= symbol.VERBATIM_BOTH_J {
		return true
	}
	return false
}
