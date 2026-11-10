// func_004697D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004B13C0.h"

struct UnkStruct_004697D0;

struct UnkStruct_004697D0 {
    int field_0;
};

extern UnkStruct_D_004B13C0 D_004B13C0;

// 0x004697D0
extern "C" int func_004697D0(UnkStruct_004697D0 * self)
{
    if (D_004B13C0.field_0 == 0) {
        return 6;
    }
    if (self == 0) {
        return 2;
    }
    self->field_0 = 4;
    return 0;
}
