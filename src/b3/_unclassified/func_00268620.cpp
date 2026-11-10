// func_00268620 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

struct UnkStruct_00268620;
struct UnkStruct_00268620_1;
struct UnkStruct_00268620_2;

struct UnkStruct_00268620_1 {
    unsigned char pad_0[0x1161];
    unsigned char field_1161;
    unsigned char pad_1162[0x836];
    unsigned char field_1998;
};

struct UnkStruct_00268620_2 {
    unsigned char pad_0[0x1A90];
    unsigned char field_1A90;
};

struct UnkStruct_00268620 {
    unsigned char pad_0[0x160];
    GtMathPs2::CGtV3d field_160;
    GtMathPs2::CGtV3d field_170;
    unsigned char pad_180[0x10];
    short field_190;
    unsigned char pad_192[0x2];
    int field_194;
    int field_198;
    unsigned char pad_19C[0x76];
    unsigned char field_212;
    unsigned char pad_213[0x1140];
    unsigned char field_1353;
    unsigned char pad_1354[0xA0];
    UnkStruct_00268620_1 * field_13F4;
    unsigned char pad_13F8[0x158];
    UnkStruct_00268620_2 * field_1550;
};

extern "C" void * memset(void *, int, unsigned int);

// 0x00268620
extern "C" void func_00268620(UnkStruct_00268620 * self)
{
    if (self->field_13F4->field_1998 == 0) {
        self->field_1353 = (self->field_1353 | 1);
        self->field_1353 = (self->field_1353 | 2);
        self->field_1353 = (self->field_1353 | 4);
        self->field_212 = 0;
        memset(((char *)self + 0x160), 0, 96);
        self->field_160.Zero();
        self->field_170.Zero();
        self->field_190 = 0;
        self->field_194 = 0;
        self->field_198 = 0;
    }
    if (self->field_1550->field_1A90 == 0) {
        self->field_1353 = (self->field_1353 | 1);
        self->field_1353 = (self->field_1353 | 2);
        self->field_1353 = (self->field_1353 | 4);
        self->field_212 = 0;
        memset(((char *)self + 0x160), 0, 96);
        self->field_160.Zero();
        self->field_170.Zero();
        self->field_190 = 0;
        self->field_194 = 0;
        self->field_198 = 0;
    }
    if (self->field_13F4->field_1161 != 0) {
        self->field_1353 = (self->field_1353 | 2);
    }
}
