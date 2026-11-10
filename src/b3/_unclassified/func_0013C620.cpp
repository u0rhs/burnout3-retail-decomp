// func_0013C620 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051BA44.h"

struct UnkStruct_0013C620;

struct UnkStruct_0013C620 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x38];
    int field_40;
    int field_44;
    int field_48[1];  // [G] element count unknown
    unsigned char pad_4C[0x108];
    int field_154[1];  // [G] element count unknown
    unsigned char pad_158[0x18];
    int field_170[1];  // [G] element count unknown
    unsigned char pad_174[0x8C];
    int field_200;
    int field_204;
    int field_208;
    int field_20C[1];  // [G] element count unknown
    unsigned char pad_210[0x8C];
    int field_29C;
    int field_2A0[1];  // [G] element count unknown
    unsigned char pad_2A4[0x8C];
    int field_330;
    int field_334;
    int field_338;
    int field_33C;
    int field_340;
    int field_344;
    int field_348;
    int field_34C;
    int field_350;
    int field_354;
    int field_358;
    int field_35C;
    int field_360;
    int field_364;
    int field_368;
    int field_36C;
    int field_370;
    int field_374;
    int field_378;
    int field_37C;
    int field_380;
    unsigned char field_384;
    unsigned char pad_385[0x1];
    signed char field_386[1];  // [G] element count unknown
    unsigned char pad_387[0x48];
    signed char field_3CF[1];  // [G] element count unknown
    unsigned char pad_3D0[0x63];
    unsigned char field_433[1];  // [G] element count unknown
    unsigned char pad_434[0x13];
    unsigned char field_447[1];  // [G] element count unknown
    unsigned char pad_448[0x9];
    unsigned char field_451[1];  // [G] element count unknown
    unsigned char pad_452[0x42];
    signed char field_494;
    signed char field_495;
    signed char field_496;
    signed char field_497;
    signed char field_498;
    signed char field_499;
    unsigned char field_49A;
    unsigned char field_49B;
};

extern UnkStruct_D_0051BA44 D_0051BA44;
extern "C" int func_00271A00(void *, int);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(void *, int, int);

// 0x0013C620
extern "C" int func_0013C620(UnkStruct_0013C620 * self)
{
    self->field_4 = 0;
    int r0 = func_00271A00(&D_0051BA44, 221);
    CopyN__10CGtUnicodeFPUsiPCUs(((char *)self + 0x8), 9, r0);
    int r2 = func_00271A00(&D_0051BA44, 441);
    CopyN__10CGtUnicodeFPUsiPCUs(((char *)self + 0x1A), 9, r2);
    int r4 = func_00271A00(&D_0051BA44, 442);
    CopyN__10CGtUnicodeFPUsiPCUs(((char *)self + 0x2C), 9, r4);
    self->field_40 = 0;
    self->field_44 = 0;
    for (int i = 0; (i < 67); i++) {
        self->field_48[i] = 0;
    }
    for (int i1 = 0; (i1 < 7); i1++) {
        self->field_154[i1] = 0;
    }
    for (int i2 = 0; (i2 < 36); i2++) {
        self->field_170[i2] = 0;
    }
    self->field_200 = 0;
    self->field_204 = 0;
    self->field_208 = 0;
    for (int i3 = 0; (i3 < 36); i3++) {
        self->field_20C[i3] = 0;
        self->field_2A0[i3] = 0;
    }
    self->field_29C = 0;
    self->field_330 = 0;
    self->field_334 = 0;
    self->field_338 = 0;
    self->field_33C = 0;
    self->field_340 = 0;
    self->field_348 = 0;
    self->field_34C = 0;
    self->field_354 = 0;
    self->field_358 = 0;
    self->field_35C = 0;
    self->field_360 = 0;
    self->field_364 = 0;
    self->field_368 = 0;
    self->field_378 = 0;
    self->field_37C = 0;
    self->field_344 = 0;
    self->field_350 = 0;
    self->field_370 = 0;
    self->field_374 = 0;
    self->field_36C = 0;
    for (int i4 = 0; (i4 < 73); i4++) {
        self->field_386[i4] = -1;
    }
    for (int i5 = 0; (i5 < 100); i5++) {
        self->field_3CF[i5] = -1;
    }
    for (int i6 = 0; (i6 < 20); i6++) {
        self->field_433[i6] = 0;
    }
    for (int i7 = 0; (i7 < 10); i7++) {
        self->field_447[i7] = 0;
    }
    for (int i8 = 0; (i8 < 67); i8++) {
        self->field_451[i8] = 0;
    }
    self->field_380 = -1;
    self->field_384 = 0;
    self->field_49B = 1;
    self->field_494 = -1;
    self->field_495 = -1;
    self->field_496 = -1;
    self->field_497 = -1;
    self->field_498 = -1;
    self->field_499 = -1;
    self->field_49A = 1;
    return 1;
}
