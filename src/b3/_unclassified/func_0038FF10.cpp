// func_0038FF10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051BAA8.h"

struct UnkStruct_0038FF10;

struct UnkStruct_0038FF10 {
    unsigned char pad_0[0x60];
    int field_60;
    float field_64[1];  // [G] element count unknown
    unsigned char pad_68[0x14];
    int field_7C;
    int field_80;
};

extern UnkStruct_D_0051BAA8 D_0051BAA8;
extern "C" int func_003922D0(UnkStruct_0038FF10 *);

// Returns the tail call's value (retail `j func_003922D0`: v0 passes through to the caller).
// 0x0038FF10
extern "C" int func_0038FF10(UnkStruct_0038FF10 * self)
{
    self->field_60 = 1;
    D_0051BAA8.field_0 = 2;
    for (int i = 0; (i < 6); i++) {
        self->field_64[i] = 100.0f;
    }
    self->field_7C = 0;
    self->field_80 = 0;
    return func_003922D0(self);
}
