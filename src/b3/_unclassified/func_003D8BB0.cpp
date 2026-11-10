// func_003D8BB0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3HUDEscapeDistance.h"
#include "b3/classes/EHUDAlign.h"

extern "C" void func_003D8920(CB3HUDEscapeDistance *);

// 0x003D8BB0
// pass1: forwards its own entry register(s) untouched to the callee, which reads them (retail live-in)
extern "C" void func_003D8BB0(CB3HUDEscapeDistance *self)
{
    func_003D8920(self);
}
