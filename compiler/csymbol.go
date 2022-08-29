package compiler

import (
	"github.com/richinsley/goflavor/symbol"
)

// generate a modifiers string from symbol modifiers (note: uses static memory)
func S_mods2str(mod uint) string {
	var s string = ""

	if mod == uint(symbol.M_NONE) {
		return s
	}

	if uint64(mod)&uint64(symbol.M_CONST) == symbol.M_CONST {
		s = s + "const "
	}
	if uint64(mod)&uint64(symbol.M_STATIC) == symbol.M_STATIC {
		s = s + "static "
	}
	if uint64(mod)&uint64(symbol.M_UNSIGNED) == symbol.M_UNSIGNED {
		s = s + "unsigned "
	}
	if uint64(mod)&uint64(symbol.M_SIGNED) == symbol.M_SIGNED {
		s = s + "signed "
	}
	if uint64(mod)&uint64(symbol.M_LONG) == symbol.M_LONG {
		s = s + "long "
	}
	if uint64(mod)&uint64(symbol.M_SHORT) == symbol.M_SHORT {
		s = s + "short "
	}
	return s
}

// jl - modified version of s_mods2str to generate the stdint version of modified ints for cpp
func S_mods2stdint(mod uint, t string) string {
	var s string = ""

	if t == "int" {
		if mod == uint(symbol.M_NONE) {
			// default int is int32_t
			s = s + "int32_t"
			return s
		}

		if uint64(mod)&uint64(symbol.M_CONST) == symbol.M_CONST {
			s = s + "const "
		}
		if uint64(mod)&uint64(symbol.M_STATIC) == symbol.M_STATIC {
			s = s + "static "
		}
		if uint64(mod)&uint64(symbol.M_UNSIGNED) == symbol.M_UNSIGNED {
			s = s + "u"
		}
		// signed is default so do nothing

		s = s + "int"

		if uint64(mod)&uint64(symbol.M_LONG) == symbol.M_LONG {
			s = s + "64_t"
		} else if uint64(mod)&uint64(symbol.M_SHORT) == symbol.M_SHORT {
			s = s + "16_t"
		} else {
			s = s + "32_t"
		}
		return s
	} else if t == "char" {
		if mod == uint(symbol.M_NONE) {
			// default char is int8_t
			s = s + "int8_t"
			return s
		}

		if uint64(mod)&uint64(symbol.M_CONST) == symbol.M_CONST {
			s = s + "const "
		}
		if uint64(mod)&uint64(symbol.M_STATIC) == symbol.M_STATIC {
			s = s + "static "
		}

		if uint64(mod)&uint64(symbol.M_UNSIGNED) == symbol.M_UNSIGNED {
			s = s + "u"
		} else if uint64(mod)&uint64(symbol.M_SIGNED) == symbol.M_SIGNED {
			// signed is default so do nothing
		}

		s = s + "int8_t"
		return s
	}

	s = s + S_mods2str(mod)
	s = s + t
	return s
}
