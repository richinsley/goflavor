package symbol

/*
#include "../parser/cdef_north.h"

node_t * nodeFromVoid(void * p) {
	return (node_t *)p;
}

symbol_t * symbolFromVoid(void * p) {
	return (symbol_t *)p;
}

bit_t * bitFromVoid(void * p) {
	return (bit_t *)p;
}
*/
import "C"
import (
	"unsafe"
)

// uintptr(unsafe.Pointer(cparsed))
var isparsed bool = false
var symlinks map[uintptr]*Symlink_t = make(map[uintptr]*Symlink_t)
var contexts map[uintptr]*Context_t = make(map[uintptr]*Context_t)
var bits map[uintptr]*Bit_t = make(map[uintptr]*Bit_t)
var items map[uintptr]*Item_t = make(map[uintptr]*Item_t)
var symbols map[uintptr]*Symbol_t = make(map[uintptr]*Symbol_t)
var nodes map[uintptr]*Node_t = make(map[uintptr]*Node_t)
var verbatims map[uintptr]*Verbatim_t = make(map[uintptr]*Verbatim_t)
var lists map[uintptr]*List_t = make(map[uintptr]*List_t)

// we need to be able to tell if we are already parsed
func SetCtoGoParsed() {
	isparsed = true
}

func GetNode(p uintptr) *Node_t {
	if p == 0 {
		return nil
	}

	retv := nodes[p]
	if retv == nil {

		// ss := symlinks
		// cc := contexts
		// bb := bits
		// ii := items
		// sy := symbols
		// nn := nodes
		// vv := verbatims
		// ll := lists
		// fmt.Print(ss, cc, bb, ii, sy, nn, vv, ll)

		// the crashy part is because an item symbol is being accessed
		// as an item node.  The symbol is "BPC"
		r := C.nodeFromVoid(unsafe.Pointer(p))
		retv = CtoGo_node(nil, r)
	}
	return retv
}

func GetVerbatim(p uintptr) *Verbatim_t {
	if p == 0 {
		return nil
	}
	return verbatims[p]
}

func GetBit(p uintptr) *Bit_t {
	if p == 0 {
		return nil
	}

	retv := bits[p]
	if retv == nil {
		r := C.bitFromVoid(unsafe.Pointer(p))
		retv = CtoGo_bit(nil, r)
	}
	return retv
}

func GetSymbol(p uintptr) *Symbol_t {
	if p == 0 {
		return nil
	}
	retv := symbols[p]
	if retv == nil {
		r := C.symbolFromVoid(unsafe.Pointer(p))
		retv = CtoGo_symbol(nil, r)
	}
	return retv
}

func CtoGo_symlink(org *Symlink_t, cparsed *C.symlink_t) *Symlink_t {
	if cparsed == nil {
		return nil
	}

	if org != nil {
		return org
	}

	if x, found := symlinks[uintptr(unsafe.Pointer(cparsed))]; found {
		return x
	}

	retv := &Symlink_t{}
	symlinks[uintptr(unsafe.Pointer(cparsed))] = retv

	retv.Sp = CtoGo_symbol(retv.Sp, cparsed.sp)
	retv.Next = CtoGo_symlink(retv.Next, cparsed.next)

	return retv
}

func CtoGo_context(org *Context_t, cparsed *C.context_t) *Context_t {
	if cparsed == nil {
		return nil
	}

	if org != nil {
		return org
	}

	if x, found := contexts[uintptr(unsafe.Pointer(cparsed))]; found {
		return x
	}

	retv := &Context_t{}
	contexts[uintptr(unsafe.Pointer(cparsed))] = retv

	retv.Type = int(cparsed._type)
	retv.Level = int(cparsed.level)
	for i := 0; i < ST_SIZE; i++ {
		retv.St[i] = CtoGo_symlink(nil, cparsed.st[i])
	}
	retv.Prev = CtoGo_context(retv.Prev, cparsed.prev)
	retv.Next = CtoGo_context(retv.Next, cparsed.next)

	return retv
}

func CtoGo_bit(org *Bit_t, cparsed *C.bit_t) *Bit_t {
	if cparsed == nil {
		return nil
	}

	if org != nil {
		return org
	}

	if x, found := bits[uintptr(unsafe.Pointer(cparsed))]; found {
		return x
	}

	retv := &Bit_t{
		Val: uint64(cparsed.val),
		Len: int(cparsed.len),
	}

	bits[uintptr(unsafe.Pointer(cparsed))] = retv

	return retv
}

func CtoGo_item(org *Item_t, cparsed *C.item_t) *Item_t {
	if cparsed == nil {
		return nil
	}

	if org != nil {
		return org
	}

	if x, found := items[uintptr(unsafe.Pointer(cparsed))]; found {
		return x
	}

	// this was originally a union, but we'll just pack it into struct for now and use accessors
	unionbuffer := (*[8]byte)(cparsed)
	retv := NewItem(*unionbuffer)
	items[uintptr(unsafe.Pointer(cparsed))] = retv

	return retv
}

func CtoGo_symbol(org *Symbol_t, cparsed *C.symbol_t) *Symbol_t {
	if cparsed == nil {
		return nil
	}

	if org != nil {
		return org
	}

	if x, found := symbols[uintptr(unsafe.Pointer(cparsed))]; found {
		return x
	}

	retv := &Symbol_t{}
	symbols[uintptr(unsafe.Pointer(cparsed))] = retv

	retv.Name = C.GoString(cparsed.name)
	retv.Lineno = int(cparsed.lineno)
	retv.Ident = int(cparsed.ident)
	retv.Internal = int16(cparsed.internal)
	retv.Exported = int16(cparsed.exported)
	retv.Owner = CtoGo_symbol(retv.Owner, cparsed.owner)
	retv.Declared = int16(cparsed.declared)
	retv.Declared_get = int16(cparsed.declared_get)
	retv.Declared_put = int16(cparsed.declared_put)
	retv.Declared_putxml = int16(cparsed.declared_putxml)
	retv.Declared_xsd = int16(cparsed.declared_xsd)
	retv.Parsable = int16(cparsed.parsable)
	retv.Parse = CtoGo_node(retv.Parse, cparsed.parse)
	retv.Put_needs_parse_var = int(cparsed.put_needs_parse_var)
	retv.Get_needs_parse_var = int(cparsed.get_needs_parse_var)
	retv.Get_needs_code_var = int(cparsed.get_needs_code_var)
	retv.Max_dims = int(cparsed.max_dims)
	retv.Ptype = CtoGo_symbol(retv.Ptype, cparsed.ptype)
	retv.Cxt = CtoGo_context(retv.Cxt, cparsed.cxt)
	retv.Cxt_level = int(cparsed.cxt_level)
	retv.Param = CtoGo_list(retv.Param, cparsed.param)
	retv.Forward = int(cparsed.forward)
	retv.Abstract = int(cparsed.abstract)
	retv.Init = CtoGo_node(retv.Init, cparsed.init)
	retv.Align = CtoGo_node(retv.Align, cparsed.align)
	retv.Id = CtoGo_symbol(retv.Id, cparsed.id)
	retv.Range = int16(cparsed._range)
	retv.Accessed = uint(cparsed.accessed)
	retv.Assigned = int16(cparsed.assigned)
	retv.Modifiers = uint(cparsed.modifiers)
	retv.Dims = int(cparsed.dims)

	// dims can be non-zero And dim can be null - see here ptree.c @ln 365
	if retv.Dims != 0 && cparsed.dim != nil {
		f := make([]*Node_t, retv.Dims)
		p2 := (*[1 << 30]*C.node_t)(unsafe.Pointer(cparsed.dim))

		for i := 0; i < retv.Dims; i++ {
			f[i] = CtoGo_node(nil, p2[i])
		}
		retv.Dim = &f
	}

	if cparsed.derived != nil {
		// make any empty array of Symbol_t pointers
		f := make([]*Symbol_t, 0)
		i := 0
		p2 := (*[1 << 30]*C.symbol_t)(unsafe.Pointer(cparsed.derived))
		for p2[i] != nil {
			f = append(f, CtoGo_symbol(nil, p2[i]))
			i++
		}
		retv.Derived = &f
	}

	retv.Lengthof = int(cparsed.lengthof)
	retv.Plengthof = CtoGo_symbol(retv.Plengthof, cparsed.plengthof)
	retv.Isidof = int(cparsed.isidof)
	retv.Escape = int(cparsed.escape)
	retv.Isparam = int(cparsed.isparam)
	retv.Included = int(cparsed.included)

	if cparsed.forwardref != nil {
		// make any empty array of Symbol_t pointers
		f := make([]*Symbol_t, 0)
		i := 0
		p2 := (*[1 << 30]*C.symbol_t)(unsafe.Pointer(cparsed.forwardref))
		for p2[i] != nil {
			f = append(f, CtoGo_symbol(nil, p2[i]))
			i++
		}
		retv.Forwardref = &f
	}

	// dimx is -1 terminated
	if cparsed.dimx_end_var != nil {
		i := 0
		p2 := (*[1 << 30]C.int)(unsafe.Pointer(cparsed.dimx_end_var))
		for p2[i] != -1 {
			retv.Dimx_end_var = append(retv.Dimx_end_var, int(p2[i]))
			i++
		}
	}

	return retv
}

func CtoGo_node(org *Node_t, cparsed *C.node_t) *Node_t {
	if cparsed == nil {
		return nil
	}

	if org != nil {
		return org
	}

	if x, found := nodes[uintptr(unsafe.Pointer(cparsed))]; found {
		return x
	}

	retv := &Node_t{}
	nodes[uintptr(unsafe.Pointer(cparsed))] = retv

	retv.Op = int(cparsed.op)
	retv.Type = int(cparsed._type)
	retv.Ptype = CtoGo_symbol(retv.Ptype, cparsed.ptype)
	retv.Leaf = int16(cparsed.leaf)
	retv.Paren = int16(cparsed.paren)
	retv.Eval = CtoGo_node(retv.Eval, cparsed.eval)
	retv.Left = CtoGo_item(retv.Left, &cparsed.left)
	retv.Right = CtoGo_item(retv.Right, &cparsed.right)
	retv.Third = CtoGo_item(retv.Third, &cparsed.third)

	return retv
}

func CtoGo_verbatim(org *Verbatim_t, cparsed *C.verbatim_t) *Verbatim_t {
	if cparsed == nil {
		return nil
	}

	if org != nil {
		return org
	}

	if x, found := verbatims[uintptr(unsafe.Pointer(cparsed))]; found {
		return x
	}

	retv := &Verbatim_t{}
	verbatims[uintptr(unsafe.Pointer(cparsed))] = retv

	retv.Str = C.GoString(cparsed.str)
	retv.Lineno = int(cparsed.lineno)

	return retv
}

func CtoGo_list(org *List_t, cparsed *C.list_t) *List_t {
	if cparsed == nil {
		return nil
	}

	if org != nil {
		return org
	}

	if x, found := lists[uintptr(unsafe.Pointer(cparsed))]; found {
		return x
	}

	retv := &List_t{}
	lists[uintptr(unsafe.Pointer(cparsed))] = retv

	retv.Type = int(cparsed._type)
	retv.E1 = CtoGo_node(retv.E1, cparsed.e1)
	retv.E2 = CtoGo_node(retv.E2, cparsed.e2)
	retv.E3 = CtoGo_node(retv.E3, cparsed.e3)
	retv.Sp = CtoGo_symbol(retv.Sp, cparsed.sp)
	retv.Align = CtoGo_node(retv.Align, cparsed.align)
	retv.Usenext = int(cparsed.usenext)
	retv.Dims = int(cparsed.dims)

	if retv.Dims != 0 {
		f := make([]*Node_t, retv.Dims)
		p2 := (*[1 << 30]*C.node_t)(unsafe.Pointer(cparsed.dim))

		for i := 0; i < retv.Dims; i++ {
			f[i] = CtoGo_node(nil, p2[i])
		}
		retv.Dim = &f
	}

	retv.Vp = CtoGo_verbatim(retv.Vp, cparsed.vp)
	retv.Lineno = int(cparsed.lineno)
	retv.Included = int(cparsed.included)
	retv.Next = CtoGo_list(retv.Next, cparsed.next)
	retv.Sub1 = CtoGo_list(retv.Sub1, cparsed.sub1)
	retv.Sub2 = CtoGo_list(retv.Sub2, cparsed.sub2)

	return retv
}

func CtoGo_list_unsafe(cp unsafe.Pointer) *List_t {
	return CtoGo_list(nil, (*C.list_t)(cp))
}
