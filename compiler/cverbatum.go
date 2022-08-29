package compiler

import (
	"io"

	"example.com/goflav/symbol"
)

func (c *CompilerContext) Verbatim(w io.Writer, vp *symbol.Verbatim_t) {
	if vp == nil || vp.Str == "" {
		return
	}

	// c.c_out(w, "line %d \"%s\"\n", vp.Lineno, filename)
	c.c_outi(w, "%s\n", vp.Str)
}