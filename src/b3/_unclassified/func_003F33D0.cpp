// func_003F33D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E91C3E.h"

struct UnkStruct_003F33D0;

struct UnkStruct_003F33D0 {
    unsigned char pad_0[0x34];
    unsigned char field_34;
};

extern UnkStruct_D_01E91C3E D_01E91C3E;

// 0x003F33D0
extern "C" void func_003F33D0(UnkStruct_003F33D0 * self)
{
    if (self->field_34 == 0) {
        D_01E91C3E.field_0 = 0;
    }
}
