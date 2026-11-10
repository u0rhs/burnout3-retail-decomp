// func_00341D00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E91C3E.h"

struct UnkStruct_00341D00;

struct UnkStruct_00341D00 {
    unsigned char pad_0[0x62];
    unsigned char field_62;
};

extern UnkStruct_D_01E91C3E D_01E91C3E;

// 0x00341D00
extern "C" void func_00341D00(UnkStruct_00341D00 * self)
{
    if (self->field_62 == 0) {
        D_01E91C3E.field_0 = 0;
    }
}
