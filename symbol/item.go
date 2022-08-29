package symbol

/*
#include "../parser/cdef_north.h"
*/
import "C"
import (
	"encoding/binary"
	"fmt"
	"unsafe"
)

// node entry (same as yylval)
// type Item_t struct {
// 	String string
// 	Ival   int
// 	Dval   float64
// 	Uival  uint64
// 	Bit    *Bit_t
// 	Sp     *Symbol_t
// 	Np     *Node_t
// 	Tp     uintptr
// 	Vp     *Verbatim_t
// }

// node entry (same as yylval)
// this is originaly a union, so we'll use 'interface{}' as a variant to store the potential values
type Item_t struct {
	value [8]byte
}

func NewItem(unionbuffer [8]byte) *Item_t {
	retv := &Item_t{
		value: unionbuffer,
	}
	return retv
}

func (t *Item_t) GetBit() *Bit_t {
	var addr *byte = &t.value[0]
	var cparsed **C.bit_t = (**C.bit_t)(unsafe.Pointer(addr))
	return CtoGo_bit(nil, *cparsed)
}

func (t *Item_t) GetUint64() uint64 {
	var addr *byte = &t.value[0]
	var cparsed *C.ulonglong = (*C.ulonglong)(unsafe.Pointer(addr))
	return uint64(*cparsed)
}

func (t *Item_t) GetFloat64() float64 {
	var addr *byte = &t.value[0]
	var cparsed *C.double = (*C.double)(unsafe.Pointer(addr))
	return float64(*cparsed)
}

func (t *Item_t) GetInt64() int64 {
	var addr *byte = &t.value[0]
	var cparsed *C.longlong = (*C.longlong)(unsafe.Pointer(addr))
	retv := int64(*cparsed)
	if retv == 4294967295 {
		fmt.Print("here")
	}
	return retv
}

func (t *Item_t) GetString() string {
	var addr *byte = &t.value[0]
	var cparsed **C.char = (**C.char)(unsafe.Pointer(addr))
	return C.GoString(*cparsed)
}

func isBigEndian() (ret bool) {
	var i uint64 = 0x1
	bs := (*[8]byte)(unsafe.Pointer(&i))
	if bs[0] == 0 {
		return true
	} else {
		return false
	}
}

func (t *Item_t) GetPointer() uintptr {
	// sloppy :(
	if isBigEndian() {
		return uintptr(binary.BigEndian.Uint64(t.value[:]))
	} else {
		return uintptr(binary.LittleEndian.Uint64(t.value[:]))
	}
}

func (t *Item_t) GetNode() *Node_t {
	p := t.GetPointer()
	if p == 0 {
		return nil
	}
	retv := GetNode(p)
	if retv == nil {
		fmt.Print("nil node pointer")
	}
	return retv
}

func (t *Item_t) GetSymbol() *Symbol_t {
	return GetSymbol(t.GetPointer())
}

// https://stackoverflow.com/questions/14581063/golang-cgo-converting-union-field-to-go-type
// var addr *byte = &union[0]
// var cast **C.guint32 = (**C.guint32)(unsafe.Pointer(addr))
// var guint32_star *C.guint32 = *cast
