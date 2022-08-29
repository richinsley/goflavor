package symbol

// this would need to be redone each time code is generated from lexerl.l
const (
	CHAR                 int = 258
	BIT                      = 259
	INT                      = 260
	FLOAT                    = 261
	DOUBLE                   = 262
	CLASS                    = 263
	IF                       = 264
	ELSE                     = 265
	DO                       = 266
	WHILE                    = 267
	FOR                      = 268
	GOTO                     = 269
	BREAK                    = 270
	CONTINUE                 = 271
	REPEAT                   = 272
	MAP                      = 273
	EXTENDS                  = 274
	SWITCH                   = 275
	CASE                     = 276
	DEFAULT                  = 277
	BAC                      = 278
	PRAGMA                   = 279
	PRAGMA_ARRAY             = 280
	PRAGMA_GET               = 281
	PRAGMA_NOGET             = 282
	PRAGMA_PUT               = 283
	PRAGMA_NOPUT             = 284
	PRAGMA_PUTXML            = 285
	PRAGMA_NOPUTXML          = 286
	PRAGMA_TRACE             = 287
	PRAGMA_NOTRACE           = 288
	PRAGMA_LINE              = 289
	PRAGMA_NOLINE            = 290
	PRAGMA_INCLUDES          = 291
	PRAGMA_NULLSTRINGS       = 292
	PRAGMA_NONULLSTRINGS     = 293
	PRAGMA_NOINCLUDES        = 294
	PRAGMA_BITSTREAM         = 295
	PRAGMA_PREFIX            = 296
	PRAGMA_ERROR_FUNC        = 297
	PRAGMA_TRACE_FUNC        = 298
	BAC_PREC                 = 299
	BAC_OOC                  = 300
	BAC_SOC                  = 301
	BAC_TE                   = 302
	BAC_RENORM               = 303
	BAC_BS                   = 304
	BAC_INIT                 = 305
	BAC_END                  = 306
	BAC_RTABLE               = 307
	BAC_NEXTI                = 308
	BAC_TRANS                = 309
	BAC_EXCH                 = 310
	INCLUDE                  = 311
	IMPORT                   = 312
	PUSHINCLUDE              = 313
	POPINCLUDE               = 314
	UNSIGNED                 = 315
	SIGNED                   = 316
	SHORT                    = 317
	LONG                     = 318
	CONST                    = 319
	ALIGNED                  = 320
	STATIC                   = 321
	ABSTRACT                 = 322
	LITTLE                   = 323
	BIG                      = 324
	EXPGOLOMB                = 325
	VARLEN                   = 326
	INT_LITERAL              = 327
	DOUBLE_LITERAL           = 328
	BIT_LITERAL              = 329
	STRING_LITERAL           = 330
	VARIABLE                 = 331
	CLASS_TYPE               = 332
	MAP_TYPE                 = 333
	BAC_TYPE                 = 334
	LABEL                    = 335
	LS                       = 336
	RS                       = 337
	GE                       = 338
	LE                       = 339
	NE                       = 340
	EQ                       = 341
	OR                       = 342
	AND                      = 343
	INC                      = 344
	DEC                      = 345
	RANGE                    = 346
	CLCL                     = 347
	MUL_ASSIGN               = 348
	DIV_ASSIGN               = 349
	MOD_ASSIGN               = 350
	ADD_ASSIGN               = 351
	SUB_ASSIGN               = 352
	LS_ASSIGN                = 353
	RS_ASSIGN                = 354
	AND_ASSIGN               = 355
	XOR_ASSIGN               = 356
	OR_ASSIGN                = 357
	DBL_BRACE_L              = 358
	DBL_BRACE_R              = 359
	DECL                     = 360
	EXPR                     = 361
	VERBATIM                 = 362
	VERBATIM_GET             = 363
	VERBATIM_PUT             = 364
	VERBATIM_BOTH            = 365
	VERBATIM_C               = 366
	VERBATIM_C_CPP           = 367
	VERBATIM_GET_C           = 368
	VERBATIM_PUT_C           = 369
	VERBATIM_BOTH_C          = 370
	VERBATIM_J               = 371
	VERBATIM_GET_J           = 372
	VERBATIM_PUT_J           = 373
	VERBATIM_BOTH_J          = 374
	VERBATIM_A               = 375
	VERBATIM_GET_A           = 376
	VERBATIM_PUT_A           = 377
	VERBATIM_BOTH_A          = 378
	LENGTHOF                 = 379
	ISIDOF                   = 380
	SKIPBITS                 = 381
	NEXTBITS                 = 382
	SNEXTBITS                = 383
	LITTLE_NEXTBITS          = 384
	LITTLE_SNEXTBITS         = 385
	NEXTCODE                 = 386
	NUMBITS                  = 387
	ESC_FTYPE                = 388
	ESC_MAP                  = 389
	ARRAY                    = 390
	LOWER_THAN_ELSE          = 391
)

func S_op2str(op int) string {
	switch op {
	case LS:
		return "<<"
	case RS:
		return ">>"
	case GE:
		return ">="
	case LE:
		return "<="
	case NE:
		return "!="
	case EQ:
		return "=="
	case OR:
		return "||"
	case AND:
		return "&&"
	case INC:
		return "++"
	case DEC:
		return "--"
	case MUL_ASSIGN:
		return "*="
	case DIV_ASSIGN:
		return "/="
	case MOD_ASSIGN:
		return "%="
	case ADD_ASSIGN:
		return "+="
	case SUB_ASSIGN:
		return "-="
	case LS_ASSIGN:
		return "<<="
	case RS_ASSIGN:
		return ">>="
	case AND_ASSIGN:
		return "&="
	case OR_ASSIGN:
		return "|="
	case XOR_ASSIGN:
		return "^="
	default:
		return string(uint8(op))
	}
}

// native Flavor types
type Bit_t struct {
	Val uint64
	Len int
}

// verbatim section
type Verbatim_t struct {
	// the code
	Str string
	// the source line it starts at
	Lineno int
}

// symbol table size (PJW hashing works best if it is a prime number)
const ST_SIZE = 257

// Symbol Table
// Note: The symbol table contains all reserved words, as well as  built-in types.

// variable modifier flags
const (
	M_NONE      uint64 = 0x000
	M_UNSIGNED  uint64 = 0x001
	M_SIGNED    uint64 = 0x002
	M_SHORT     uint64 = 0x004
	M_LONG      uint64 = 0x008
	M_CONST     uint64 = 0x010
	M_STATIC    uint64 = 0x020
	M_LITTLE    uint64 = 0x040
	M_BIG       uint64 = 0x080
	M_EXPGOLOMB uint64 = 0x100
	M_VARLEN    uint64 = 0x200
)

// symbol table entry type (entered in hashed array of linked lists)
type Symbol_t struct {
	// name
	Name string

	// line where it was defined
	Lineno int

	// Type indication.
	// Member declaration (including methods), parameter in
	// a method or class, reserved word or built-in type
	// (the different types are declared as tokens in the parser).
	Ident int

	// set to 1 for internal symbol table entries
	Internal int16

	// Set if we should treat this node as if it is an external symbol, even if 'internal' is set.
	// This is used in the lexer (getsymbol()) to decide if it should be passed to the parser as an <sp> or <ival>.
	// Currently all internals except built-in types have it set.
	Exported int16

	// owning class (or NULL, if global scope var)
	Owner *Symbol_t

	// for variables, set (by the code generator) if they have been declared in the class methods
	Declared        int16
	Declared_get    int16
	Declared_put    int16
	Declared_putxml int16
	Declared_xsd    int16

	// set if the symbol is parsable
	Parsable int16

	// for constant parsable vars that are not classes, a node_t * to the parse expression
	Parse *Node_t

	// When a parsable variable has an initial expression, <prefix>parse
	// is used as a tmp variable in the code generator to save the parse
	// size in the put() method. This ensure that the order of evaluation
	// of parse and init expressions is preserved (parse first). When no
	// variable has initial value, the <prefix>parse generates an
	// 'unused variable' warning. The following is a flag that is set
	// when we are generating the class variable declarations, and tells us
	// if the put() method should declare a <prefix>parse.
	// This is only meaningful for class symbols.
	Put_needs_parse_var int

	// Similarly to 'put_needs_parse_var', when we are tracing, a parsable
	// variable requires that <prefix>parse is defined to save the parse size
	// (so that it can be passed along to the tracing function without
	// evaluating the expression twice).
	Get_needs_parse_var int

	// When we want to trace vlc codes, we need to save the code value.
	// A <prefic>code variable is used, and is declared when the flag below is set.
	Get_needs_code_var int

	// Similarly to 'needs_parse_var', when we are parsing arrays we need
	// tmp variables. Since we don't know the number of dimensions, we
	// use this variable that is set when we are generating class variable
	// declarations to create the right number of them.
	Max_dims int

	// To avoid declaration of unused variables in arrays (the dimx_end)
	// we keep an array of flags that tell us if dimension x has at least one
	// non-partial use (so it needs the dimx_end var).
	Dimx_end_var []int

	// If a variable declaration, pointer to type definition (includes built-in types);
	// if a class declaration, pointer to base class (if any).
	Ptype *Symbol_t

	// if a class variable, pointer to its context
	Cxt *Context_t

	// For all variables, context level they are defined.
	// This is used to figure out in the code generator which
	// are class variables (they are at level 1).
	Cxt_level int

	// if a class with parameter types, pointer to list with symbol pointers, used only if var is a constant
	Param *List_t

	// For classes, this is set to 1 when we see a forward declaration.
	// When we find the actual declaration, it is set to 2.
	// NOTE: it will be ***reset*** in the code generator, after it skips the first encounter of this class.
	Forward int

	// Flag to signal an abstract polymorphic class -- i.e., its use triggers a nextbits() in the
	// space of the IDs of only its derived (non-abstract) classes.
	Abstract int

	// In order to detect cyclic references with forward declarations, the following NULL
	// terminated array of pointers is used to store in a forward-declared class all classes
	// that use it as a member.
	Forwardref *[]*Symbol_t

	// pointer to initial value expression, used only if var is a constant
	Init *Node_t

	// pointer to align expression, used only if var is a constant and for class ID variables
	Align *Node_t

	// for class types, pointer to class ID symbol table entry
	Id *Symbol_t

	// for expected range of values
	Range int16

	// how many times this symbol has been accessed
	Accessed uint

	// if a variable, it it has been assigned to
	Assigned int16

	// type modifiers ('const', 'static', etc.); see 'modifier_t' above
	Modifiers uint

	// dimensions, if it is an array
	Dims int

	// if dims>0, array of ptrs to dimension expressions (node_t *'s), used only for constants
	Dim *[]*Node_t

	// if a class, NULL-terminated array of classes directly derived from this one
	Derived *[]*Symbol_t

	// set if lengthof() is used for this variable (set by check_lengthof())
	Lengthof int

	// Set to point to the lengthof variable of this symbol.
	// These variables always shadow their parent variables; they are generated
	// by the parser (eval_builtin) when a 'lengthof' operator is found for them.
	Plengthof *Symbol_t

	// set if isidof() is used for this variable
	Isidof int

	// for maps, set if an escape is present (so that 'type(map)*' can be flagged as an error)
	Escape int

	// Set if this is a parameter type var (this is used for class parameter vars, to avoid declaring their
	// probe id variable - it is not needed).
	Isparam int

	// set if symbol declared from included file (no code will be generated)
	Included int
}

// linked list of symbols at a given hash position
type Symlink_t struct {
	Sp   *Symbol_t
	Next *Symlink_t
}
