// func_003922D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_00516E40.h"

struct UnkStruct_003922D0;

struct UnkStruct_003922D0 {
    unsigned char pad_0[0x5];
    unsigned char field_5;
    unsigned char pad_6[0x3E];
    int field_44;
    unsigned char pad_48[0x4];
    short field_4C;
    short field_4E;
    unsigned char pad_50[0xC];
    unsigned char field_5C;
    unsigned char field_5D;
};

extern UnkStruct_D_00516E40 D_00516E40;

// 0x003922D0
extern "C" int func_003922D0(UnkStruct_003922D0 * self)
{
    ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(15, 0);
    self->field_4C = 0;
    self->field_4E = 0;
    self->field_5 = 1;
    self->field_5C = 0;
    self->field_5D = 0;
    self->field_44 = -1;
    return 1;
}
