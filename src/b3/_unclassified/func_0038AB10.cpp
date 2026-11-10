// func_0038AB10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051BAA8.h"

struct UnkStruct_0038AB10;

struct UnkStruct_0038AB10 {
    unsigned char pad_0[0x60];
    int field_60;
};

extern UnkStruct_D_0051BAA8 D_0051BAA8;
extern "C" int func_003922D0(UnkStruct_0038AB10 *);

// Returns the tail call's value (retail `j func_003922D0`: v0 passes through to the caller).
// 0x0038AB10
extern "C" int func_0038AB10(UnkStruct_0038AB10 * self)
{
    self->field_60 = 1;
    D_0051BAA8.field_0 = 2;
    return func_003922D0(self);
}
