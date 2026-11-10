// func_003935A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_00516E40.h"
#include "b3/classes/UnkStruct_D_005179F0.h"

struct UnkStruct_003935A0;

struct UnkStruct_003935A0 {
    unsigned char pad_0[0x40];
    int field_40;
    unsigned char pad_44[0xD];
    unsigned char field_51;
};

extern UnkStruct_D_00516E40 D_00516E40;
extern UnkStruct_D_005179F0 D_005179F0;

// 0x003935A0
extern "C" int func_003935A0(UnkStruct_003935A0 * self)
{
    self->field_51 = 0;
    self->field_40 = 3;
    ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(20, 0);
    ((UnkStruct_D_005179F0 *)&D_005179F0)->vfunc_14(20, 0);
    return 1;
}
