// func_00393710 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051BAA4.h"
#include "b3/classes/UnkStruct_D_0051BACC.h"
#include "b3/classes/UnkStruct_D_00665EA0.h"

struct UnkStruct_00393710;

struct UnkStruct_00393710 {
    unsigned char pad_0[0x50];
    unsigned char field_50;
};

extern UnkStruct_D_0051BACC D_0051BACC;
extern UnkStruct_D_0051BAA4 D_0051BAA4;
extern UnkStruct_D_00665EA0 D_00665EA0;

// 0x00393710
extern "C" void func_00393710(UnkStruct_00393710 * self)
{
    D_0051BACC.field_0 = 4;
    D_0051BAA4.field_0 = 0;
    D_00665EA0.field_0 = 0;
    self->field_50 = 1;
}
