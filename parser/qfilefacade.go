package parser

/*
#include "qfilefacade.h"
*/
import "C"
import (
	"io"
	"os"
	"runtime/cgo"
	"unsafe"
)

//export MyGoPrint
func MyGoPrint(handle C.uintptr_t) {
	h := cgo.Handle(handle)
	val := h.Value().(string)
	println(val)
	h.Delete()
}

// here we call into c code
func GoPrint(val string) {
	C.myprint(C.uintptr_t(cgo.NewHandle(val)))
}

type qfFile struct {
	f       *os.File
	r       io.Reader
	w       io.Writer
	lasterr error
}

//export GF_Close
func GF_Close(handle C.uintptr_t) C.int64_t {
	h := cgo.Handle(handle)
	wrapped := h.Value().(*qfFile)
	f := wrapped.f
	var err error
	if f != nil {
		err = f.Close()
	}

	// we need to destroy the handle also
	h.Delete()

	if err != nil {
		return -1
	}
	return 0
}

func GF_WrapFile(file *os.File) C.uintptr_t {
	wrapped := &qfFile{
		f:       file,
		lasterr: nil,
	}

	wrapped.r = file
	wrapped.w = file
	return C.uintptr_t(cgo.NewHandle(wrapped))
}

func GF_WrapReader(r io.Reader) C.uintptr_t {
	wrapped := &qfFile{
		r:       r,
		lasterr: nil,
	}
	return C.uintptr_t(cgo.NewHandle(wrapped))
}

func GF_WrapWriter(w io.Writer) C.uintptr_t {
	wrapped := &qfFile{
		w:       w,
		lasterr: nil,
	}
	return C.uintptr_t(cgo.NewHandle(wrapped))
}

//export GF_Open
func GF_Open(filename *C.char, mode *C.char) C.uintptr_t {
	var retv *os.File
	var err error
	// convert filename char* to go string
	fname := C.GoString(filename)
	m := C.GoString(mode)
	if m[0] == 'r' {
		// read only
		retv, err = os.OpenFile(fname, os.O_RDONLY, 0755)
		if err != nil {
			return C.uintptr_t(0)
		}
	} else {
		// write only
		retv, err = os.OpenFile(fname, os.O_RDWR|os.O_CREATE, 0755)
		if err != nil {
			return C.uintptr_t(0)
		}
	}
	wrapped := &qfFile{
		f:       retv,
		lasterr: nil,
	}
	return C.uintptr_t(cgo.NewHandle(wrapped))
}

func charToBytes(src *C.char, sz int) []byte {
	dest := make([]byte, sz)
	copy(dest, (*(*[1024]byte)(unsafe.Pointer(src)))[:sz:sz])
	return dest
}

//export GF_Write
func GF_Write(file C.uintptr_t, buffer *C.char, size C.int64_t) C.int64_t {
	h := cgo.Handle(file)
	wrapped := h.Value().(*qfFile)
	f := wrapped.w

	// cast buffer to go byte[]
	arr := C.GoBytes(unsafe.Pointer(buffer), C.int(size))
	retv, err := f.Write(arr)
	if err != nil {
		wrapped.lasterr = err
		return -1
	}
	wrapped.lasterr = nil
	return C.int64_t(retv)
}

//export GF_Read
func GF_Read(buffer *C.char, size C.uint64_t, count C.uint64_t, file C.uintptr_t) C.uint64_t {
	h := cgo.Handle(file)
	wrapped := h.Value().(*qfFile)
	f := wrapped.r
	rsize := (int)(size * count)
	// turn buffer into an arbitrarily large array then slize to the desired size
	bufslice := (*[1 << 30]byte)(unsafe.Pointer(buffer))[:rsize:rsize]
	retv, err := f.Read(bufslice)
	if err != nil {
		wrapped.lasterr = err
		return 0
	}
	if retv != rsize {
		wrapped.lasterr = io.EOF
	} else {
		wrapped.lasterr = nil
	}
	return C.uint64_t(retv)
}

//export GF_EOF
func GF_EOF(handle C.uintptr_t) C.int64_t {
	h := cgo.Handle(handle)
	wrapped := h.Value().(*qfFile)
	if wrapped.lasterr != nil {
		return 1
	}
	return 0
}

//export GF_FError
func GF_FError(handle C.uintptr_t) C.int64_t {
	h := cgo.Handle(handle)
	wrapped := h.Value().(*qfFile)
	if wrapped.lasterr != nil {
		return 1
	}
	return 0
}
