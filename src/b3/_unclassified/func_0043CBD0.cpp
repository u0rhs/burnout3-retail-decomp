// func_0043CBD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004F50A0.h"

struct UnkStruct_0043CBD0;

struct UnkStruct_0043CBD0 {
    unsigned char pad_0[0xD4];
    float field_D4;
    float field_D8;
};

extern UnkStruct_D_004F50A0 D_004F50A0;

// 0x0043CBD0
extern "C" bool func_0043CBD0(UnkStruct_0043CBD0 * self)
{
    return D_004F50A0.field_0 > (self->field_D4 + self->field_D8);
}
