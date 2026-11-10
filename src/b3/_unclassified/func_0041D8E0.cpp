// func_0041D8E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E25D8.h"

struct UnkStruct_0041D8E0;

struct UnkStruct_0041D8E0 {
    int field_0;
    int field_4;
};

extern UnkStruct_D_004E25D8 D_004E25D8;

// 0x0041D8E0
extern "C" void func_0041D8E0(UnkStruct_0041D8E0 * self)
{
    self->field_0 = 0;
    self->field_4 = 0;
    if (D_004E25D8.field_0 == -1) {
        D_004E25D8.field_0 = 0;
    }
}
