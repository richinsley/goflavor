package compiler

import (
	"strings"
)

func (c *CompilerContext) header() {
	for k, v := range c.OutputFileNames {
		file := c.OutputFiles[k]

		c.c_out(file, "/* @goflavor\n"+
			" *\n"+
			" * %s\n"+
			" * \n"+
			" * This file was automatically generated by %s\n"+
			" * from the source file:\n"+
			" *     '%s'\n"+
			" *\n"+
			" * For information on %s, visit the goflavor Web site at:\n"+
			" *     http://flavor.sourceforge.net\n"+
			" *\n"+
			" * -- Do not edit by hand --\n"+
			" *\n"+
			" */\n\n",
			v, c.Program, c.Filename, c.Program)

		if k == "header" {
			// translate '.' to '_'
			b := strings.ReplaceAll(basename(v), ".", "_")
			c.c_out(file, "#ifndef %s%s_\n#define %s%s_\n\n", c.Prefix, b, c.Prefix, b)
		} else {
			c.c_out(file, "#include <flavor.h>\n#include \"%s\"\n\n", basename(c.OutputFileNames["header"]))
		}
	}
}