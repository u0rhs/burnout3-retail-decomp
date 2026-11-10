// func_003FC700 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051BA44.h"
#include "b3/classes/UnkStruct_D_01ECDE90.h"

struct UnkStruct_003FC700;
struct UnkStruct_003FC700_1;

struct UnkStruct_003FC700_1 {
    unsigned char pad_0[0x8];
    int field_8;
    int field_C;
    int field_10;
};

struct UnkStruct_003FC700 {
    unsigned char pad_0[0xC0];
    void * field_C0;
    UnkStruct_003FC700_1 * field_C4;
    unsigned char pad_C8[0x8];
    int field_D0;
    unsigned char pad_D4[0x10];
    int field_E4;
    unsigned char field_E8;
    unsigned char field_E9;
};

extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01ECDE90 D_01ECDE90;
extern "C" bool func_00386010(void *);
extern "C" int func_00386080(void *, int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_00438F10(void *, int, int, int);
extern "C" void func_00438F00(void *);

// 0x003FC700
extern "C" void func_003FC700(UnkStruct_003FC700 * self)
{
    switch (self->field_D0) {
    case 1:
        if (self->field_C4 == 0) {
            return;
        }
        if (self->field_E9 != 0) {
            return;
        }
        if (self->field_C0 == 0) {
            return;
        }
        if (func_00386010(self->field_C0) == false) {
            return;
        }
        self->field_D0 = 2;
    case 2:
        if ((self->field_E8 & 8) == 0) {
            self->field_E4 = func_00386080(self->field_C0, 1) + 5000;
        }
        {
            int r2 = func_00271A00(&D_0051BA44, self->field_C4->field_C);
            int r3 = func_00271A00(&D_0051BA44, self->field_C4->field_10);
            func_00438F10(&D_01ECDE90, func_00271A00(&D_0051BA44, self->field_C4->field_8), r3, r2);
        }
        self->field_D0 = 4;
    case 4:
        if (func_00386080(self->field_C0, 1) < self->field_E4) {
            return;
        }
        self->field_D0 = 5;
    case 3:
    case 5:
        func_00438F00(&D_01ECDE90);
        if (self->field_D0 == 3) {
            self->field_E9 = 0;
            self->field_E8 |= 8;
        } else {
            self->field_E9 = 1;
            self->field_E8 &= ~8;
        }
        self->field_D0 = 1;
        break;
    }
}
