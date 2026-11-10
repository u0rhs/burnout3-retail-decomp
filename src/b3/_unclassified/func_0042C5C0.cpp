// func_0042C5C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E90424.h"

extern UnkStruct_D_01E90424 D_01E90424;
extern "C" void func_0042C600(void *, float);

// 0x0042C5C0
// pass1: f12 (dt; a virtual's float parameter) goes to func_0042C600((void *)(self), float dt) untouched
extern "C" void func_0042C5C0(int n0, float dt)
{
    int t0 = D_01E90424.field_0;
    if (t0 == 5) {
        func_0042C600((void *)(n0), dt);
    }
}
