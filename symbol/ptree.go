package symbol

// The actual parsing tree node.  All expressions are parsed into node_t trees, and
// attached to statement list_t structures (see below).
type Node_t struct {
	// operator to be applied
	Op int

	// track the type of subexpressions
	Type int

	// pointer to type symbol table entry
	Ptype *Symbol_t

	// set if this is a leaf node (so we don't have to check operator)
	Leaf int16

	// set if we need to maintain the parenthesis
	Paren int16

	// when doing eval substitution on constants, we save
	// here the original expr (this is used by lengthof())
	Eval *Node_t

	// 3 entries (to cover ?: )
	Left  *Item_t
	Right *Item_t
	Third *Item_t
}

// Linked list of statements and declarations.
//
// Statements and declarations are stored sequentially;
// if, while, etc. also have sub-statements (the block of statements that
// they refer to; the 'e' entries are used to store the expressions for the
// entries required (e.g., for requires 3 such entries).
//
// This is also used in a special way to pass type info in a
// list of declarations (see 'declaration_list' in parser.y);
// 'type' gets the modifiers, 'e1' the init expression, 'e2' the parse
// expression, 'sp' the type pointer, and 'e3' the argument list
// (for parameter types).
type List_t struct {
	// identify a statement (expression, for, while, etc.), declaration or verbatim section
	Type int

	// expression pointers for the statement's components
	E1 *Node_t
	E2 *Node_t
	E3 *Node_t

	// if a declaration, pointer to the symbol table entry
	Sp *Symbol_t

	// if alignment argument is specified, it goes here
	Align *Node_t

	// If a declaration of a parsable variable, the following flag signals that the next*()
	// function version should be used (e.g., nextbits() instead of getbits()).
	Usenext int

	// if an array declaration, save number of dims and dimension expressions
	Dims int
	Dim  *[]*Node_t

	// if a verbatim section, pointer to the verbatim string
	Vp *Verbatim_t

	// next in the list
	Next *List_t

	// sub-statements, e.g., 'if (a) stmt' will put 'a' in e1 and 'stmt' in sub1
	Sub1 *List_t
	// only used for the 'else' part of if statements
	Sub2 *List_t

	// line number where the entry was inserted
	Lineno int

	// set if the list entry is from included file (so no code generation will happen)
	Included int
}
