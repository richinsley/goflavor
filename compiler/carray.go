package compiler

import (
	"fmt"
	"io"

	"example.com/goflav/symbol"
)

func (c *CompilerContext) c_array_decl(w io.Writer, sp *symbol.Symbol_t, dims int, dim *[]*symbol.Node_t) {
	for i := 0; i < dims; i++ {
		c.c_out(w, "[%d]", c.MaxArraySize)
	}
}

func (c *CompilerContext) c_array_decl_actual(w io.Writer, sp *symbol.Symbol_t, dims int, dim *[]*symbol.Node_t) {
	for i := 0; i < dims; i++ {
		c.c_out(w, "[")
		c.c_expression(w, (*dim)[i].Left.GetNode(), false)
		c.c_out(w, "]")
	}
}

func (c *CompilerContext) c_gentmp_dim(i int) string {
	return fmt.Sprintf("%sdim%d", c.Prefix, i)
}

func (c *CompilerContext) c_array_tmp_decl(w io.Writer, dims int, dimx_end_var []int) {
	if dims <= 0 {
		return
	}

	c.c_outi(w, "int ")
	for i := 0; i < dims; i++ {
		pvar := c.c_gentmp_dim(i)
		if dimx_end_var[i] != 0 {
			c.c_out(w, "%s, %s_end", pvar, pvar)
		} else {
			c.c_out(w, "%s", pvar)
		}

		if i != dims-1 {
			c.c_out(w, ", ")
		}
	}
	c.c_out(w, ";\n")
}

// array prologue ('for' loops)
func (c *CompilerContext) c_array_prologue(sp *symbol.Symbol_t, dims int, dim *[]*symbol.Node_t) {
	sc := c.OutputFiles["source"]
	var np *symbol.Node_t
	// compute array bounds
	for i := 0; i < dims; i++ {
		tmp := c.c_gentmp_dim(i) // get the tmp dimension variable -- e.g., _F_dim0
		np = (*dim)[i]
		// sanity check
		if np == nil || np.Left.GetNode() == nil {
			fatal("Internal error: Invalid dimension expression")
		}
		if np.Op == symbol.DBL_BRACE_L {
			c.c_outi(sc, "%s = ", tmp)
		} else {
			c.c_outi(sc, "%s_end = ", tmp)
		}
		c.c_expression(sc, np.Left.GetNode(), false)
		c.c_out(sc, ";\n")
	}
	// generate 'for' loops
	for i := 0; i < dims; i++ {
		tmp := c.c_gentmp_dim(i)
		np = (*dim)[i]
		if np.Op == '[' {
			c.c_outi(sc, "for (%s = 0; %s < %s_end; %s++) {\n", tmp, tmp, tmp, tmp)
			c.indent()
		}
	}
}

// array proper (the indices with the tmp variables)
func (c *CompilerContext) c_array_proper(sp *symbol.Symbol_t, dims int) {
	sc := c.OutputFiles["source"]
	for i := 0; i < dims; i++ {
		tmp := c.c_gentmp_dim(i)
		c.c_out(sc, "[%s]", tmp)
	}
}

// array epilogue ('for' loops)
func (c *CompilerContext) c_array_epilogue(sp *symbol.Symbol_t, dims int, dim *[]*symbol.Node_t) {
	sc := c.OutputFiles["source"]
	var n *symbol.Node_t

	// close 'for' loops
	for i := 0; i < dims; i++ {
		n = (*dim)[i]
		if n.Op == '[' {
			c.outdent()
			c.c_outi(sc, "}\n")
		}
	}
}
