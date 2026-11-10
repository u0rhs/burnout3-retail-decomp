// func_00383F10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E1E50.h"

struct UnkStruct_00383F10;

struct UnkStruct_00383F10 {
    unsigned char pad_0[0x398];
    int field_398;
    int field_39C;
    unsigned char pad_3A0[0x4];
    int field_3A4;
    unsigned char field_3A8;
    unsigned char field_3A9;
    unsigned char pad_3AA[0x1];
    unsigned char field_3AB;
};

extern UnkStruct_D_004E1E50 D_004E1E50;

// 0x00383F10
extern "C" void func_00383F10(UnkStruct_00383F10 * self)
{
    self->field_39C = 0;
    self->field_398 = 0;
    self->field_3A9 = 0;
    self->field_3A8 = 0;
    self->field_3A4 = 1;
    self->field_3AB = 0;
    if (D_004E1E50.field_0 == -1) {
        D_004E1E50.field_0 = 0;
    }
}
