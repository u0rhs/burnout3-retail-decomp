// func_0038E480 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0057BAF0.h"
#include "b3/classes/UnkStruct_D_0058B190.h"
#include "b3/classes/UnkStruct_D_00645170.h"
#include "b3/classes/UnkStruct_D_00645178.h"

struct UnkStruct_0038E480;
struct UnkStruct_0038E480_2;
struct UnkStruct_0038E480_4;

struct UnkStruct_0038E480_2 {
    unsigned char pad_0[0x218];
    signed char field_218;
};

struct UnkStruct_0038E480_4 {
    unsigned char pad_0[0x218];
    signed char field_218;
};

struct UnkStruct_0038E480 {
    unsigned char pad_0[0x6D];
    unsigned char field_6D;
    unsigned char field_6E;
};

extern UnkStruct_D_00645170 D_00645170;
extern UnkStruct_D_00645178 D_00645178;
extern UnkStruct_D_0057BAF0 D_0057BAF0;
extern UnkStruct_D_0058B190 D_0058B190;

// 0x0038E480
extern "C" int func_0038E480(UnkStruct_0038E480 * self, int p0)
{
    UnkStruct_0038E480_2 * v0;
    if (0 < D_00645170.field_0) {
        v0 = (UnkStruct_0038E480_2 *)&D_0057BAF0;
    } else {
        v0 = 0;
    }
    UnkStruct_0038E480_4 * v1;
    if (0 < D_00645178.field_0) {
        v1 = (UnkStruct_0038E480_4 *)&D_0058B190;
    } else {
        v1 = 0;
    }
    if (p0 == v0->field_218) {
        self->field_6D = 1;
    }
    if (p0 == v1->field_218) {
        self->field_6E = 1;
    }
    return 0;
}
