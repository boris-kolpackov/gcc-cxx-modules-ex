// { dg-additional-options "-fmodules-ts -Wno-pedantic" }

export module foo;
// { dg-module-cmi !foo }
;

#pragma pack(2)
import baz; // { dg-error "must be within preamble" }

int i;

// { dg-warning "not writing module" "" { target *-*-* } 0 }
