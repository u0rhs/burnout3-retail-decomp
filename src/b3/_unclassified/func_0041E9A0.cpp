// func_0041E9A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2A14.h"

extern UnkStruct_D_004E2A14 D_004E2A14;
extern "C" void func_002C0390(int, unsigned short);

// 0x0041E9A0
extern "C" void func_0041E9A0(void *n0_)
{
    int n0 = (int)n0_;
    unsigned short v0 = D_004E2A14.field_0;
    if (D_004E2A14.field_0 == 65535) {
        v0 = 0;
    }
    func_002C0390(n0, v0);
}
