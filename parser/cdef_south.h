#ifndef CDEF_SOUTH_H
#define CDEF_SOUTH_H

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

// cdef_south - defs that are required by the code gen end

//#include "compile.h"
#include "cout.h"
#include "cverbatim.h"
#include "cpragma.h"
#include "carray.h"
#include "cexpr.h"
#include "ctrace.h"
#include "cclass.h"
#include "cvar.h"
#include "cgetput.h"
#include "cid.h"
#include "cmap.h"
#include "cbac.h"
#include "cxml.h"

/* generate correct scoping operator */
#define c_scope() ((cpp() && !angelscript()) ? "->" : ".")

/* generate correct static scoping operator */
#define c_static_scope() (cpp() ? "::" : ".")

#endif // CDEF_SOUTH_H
