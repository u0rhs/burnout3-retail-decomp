// func_0044CEF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

#include "b3/classes/UnkStruct_D_01E90350.h"

struct UnkStruct_0044CEF0;
struct UnkStruct_0044CEF0_1;
struct UnkStruct_0044CEF0_5;
struct UnkStruct_0044CEF0_6;
struct UnkStruct_0044CEF0_e1;

struct UnkStruct_0044CEF0_1 {
    GtMathPs2::CGtV4d field_0;
    unsigned char pad_10[0x10];
};

struct UnkStruct_0044CEF0_e1 {
    UnkStruct_0044CEF0_5 * field_0;
    unsigned char pad_4[0x4];
    UnkStruct_0044CEF0_6 * field_8;
    unsigned char pad_C[0x18];
};

struct UnkStruct_0044CEF0_5 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
    unsigned char pad_20[0xC];
    float field_2C;
};

struct UnkStruct_0044CEF0_6 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
    unsigned char pad_20[0xC];
    float field_2C;
};

struct UnkStruct_0044CEF0 {
    unsigned char pad_0[0x24];
    UnkStruct_0044CEF0_e1 field_24[1];  // [G] element count unknown
    unsigned char pad_48[0xF0];
    int field_138;
    unsigned char pad_13C[0x8C];
    signed char field_1C8[1];  // [G] element count unknown
};

extern UnkStruct_D_01E90350 D_01E90350;

// 0x0044CEF0
extern "C" void func_0044CEF0(UnkStruct_0044CEF0 * self, float f0, float f1)
{
    GtMathPs2::CGtV4d t0;
    t0 = D_01E90350.field_0;
    t0.SetA(f1);
    for (int i = 0; (i < self->field_138); i++) {
        if (self->field_1C8[i] == 0) {
            char *e = (char *)self + i * 36 + 0xC;
            UnkStruct_0044CEF0_5 * t1 = self->field_24[i].field_0;
            if (t1 != 0) {
                t1->field_2C = f0;
                t1->field_10 = t0.mData;
            }
            UnkStruct_0044CEF0_6 * t2 = *(UnkStruct_0044CEF0_6 **)((char *)e + 0x20);
            if (t2 != 0) {
                t2->field_2C = f0;
                t2->field_10 = t0.mData;
            }
        }
    }
}
