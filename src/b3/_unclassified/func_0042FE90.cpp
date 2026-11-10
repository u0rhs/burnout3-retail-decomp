// func_0042FE90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_0064D37C.h"
#include "b3/classes/UnkStruct_D_0064EA72.h"

struct UnkStruct_0042FE90;

struct UnkStruct_0042FE90 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[0x4];
    int field_14;
    unsigned char pad_18[0x4];
    int field_1C;
    int field_20;
    unsigned char pad_24[0xA0];
    int field_C4;
};

extern UnkStruct_D_0064EA72 D_0064EA72;
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern "C" int func_00271A00(void *, int);

// 0x0042FE90
extern "C" void func_0042FE90(UnkStruct_0042FE90 * self)
{
    self->field_1C = 13;
    self->field_20 = 9;
    self->field_14 = 2506;
    int v1 = 1;
    short t0 = D_0064EA72.field_0;
    if (t0 != -1) {
        v1 = D_0064D37C.field_0 - (t0 - 1);
    }
    int b;
    int a;
    switch (v1) {
    case 1:
        self->field_C = 1;
        self->field_C4 = 0;
        b = 829;
        a = 810;
        break;
    case 2:
        b = 830;
        a = 811;
        self->field_C = 2;
        self->field_C4 = 1;
        break;
    case 3:
        b = 830;
        a = 812;
        self->field_C = 3;
        self->field_C4 = 2;
        break;
    default:
        b = 830;
        a = 813;
        self->field_C = 4;
        break;
    }
    int c = v1 + 801;
    if (c < 4005) {
        self->field_0 = func_00271A00(&D_0051BA44, c);
    }
    if (b < 4005) {
        self->field_4 = func_00271A00(&D_0051BA44, b);
    }
    if (a < 4005) {
        self->field_8 = func_00271A00(&D_0051BA44, a);
    }
}
