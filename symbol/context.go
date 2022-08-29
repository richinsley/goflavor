package symbol

// Context (doubly linked list).
// Contexts work as follows. Top is the global one where only class decls,
// consts, and maps are allowed. First level holds class variables. Second
// level holds parameter variables for classes. Third level is always empty.
// This is because the variables that would go there, are put in the 1st
// level (class variables). Fourth and so on contain local scope variables
// (defined within blocks). Note that all parsable variables have class
// scope (i.e., are placed in the 1st level context).
type Context_t struct {
	// context type; CLASS or regular context (blocks etc.)
	Type int

	// context level (how deep we are)
	Level int

	// the symbol table
	St [ST_SIZE]*Symlink_t

	// forward/backward pointers
	Prev *Context_t
	Next *Context_t
}
