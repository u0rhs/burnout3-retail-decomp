// func_0042FA60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051BF9C.h"

struct UnkStruct_0042FA60;

struct UnkStruct_0042FA60 {
    unsigned char pad_0[0x28];
    int field_28[1];  // [G] element count unknown
    unsigned char pad_2C[0xC];
    int field_38[1];  // [G] element count unknown
    unsigned char pad_3C[0x8];
    int field_44[1];  // [G] element count unknown
    unsigned char pad_48[0xC];
    int field_54[1];  // [G] element count unknown
    unsigned char pad_58[0x8];
    int field_60;
    int field_64;
    int field_68;
    unsigned char field_6C;
    unsigned char field_6D;
    unsigned char field_6E;
    unsigned char pad_6F[0x1];
    unsigned char field_70;
    unsigned char field_71;
    unsigned char pad_72[0x6];
    int field_78;
    int field_7C;
    int field_80;
    unsigned char pad_84[0x60];
    int field_E4;
    unsigned char pad_E8[0x50];
    int field_138;
    unsigned char pad_13C[0x10];
    int field_14C;
    unsigned char pad_150[0x50];
    int field_1A0;
    unsigned char pad_1A4[0x28];
    int field_1CC;
    unsigned char pad_1D0[0x28];
    int field_1F8;
    unsigned char pad_1FC[0x10C];
    int field_308;
    unsigned char pad_30C[0x28];
    int field_334;
    unsigned char pad_338[0x14];
    int field_34C;
    unsigned char pad_350[0xC];
    signed char field_35C[1];  // [G] element count unknown
    unsigned char pad_35D[0xB];
    int field_368[1];  // [G] element count unknown
    unsigned char pad_36C[0x31];
    unsigned char field_39D;
};

extern UnkStruct_D_0051BF9C D_0051BF9C;
extern "C" int func_0013B660(void *);
extern "C" int func_0013B200(void *, unsigned long, int);
extern "C" int func_0013B570(void *);

// 0x0042FA60
extern "C" void func_0042FA60(UnkStruct_0042FA60 * self)
{
    if (self->field_39D == 0) {
        return;
    }
    void * t0 = D_0051BF9C.field_0;
    for (int i = 0; (i < 4); i++) {
        self->field_28[i] = 0;
        self->field_44[i] = 0;
    }
    for (int i1 = 0; (i1 < 3); i1++) {
        self->field_38[i1] = 0;
        self->field_54[i1] = 0;
    }
    self->field_60 = 0;
    self->field_64 = 0;
    if (t0 == 0) {
        self->field_78 = 0;
        self->field_7C = 0;
        self->field_80 = 0;
    } else {
        int r0 = func_0013B660(t0);
        self->field_78 = r0;
        int r1 = func_0013B200(t0, 0, 1);
        int r2 = func_0013B200(t0, 0, 0);
        self->field_7C = (r1 + r2);
        int r3 = func_0013B570(t0);
        self->field_80 = r3;
    }
    self->field_68 = 9;
    self->field_6C = 1;
    self->field_6D = 0;
    self->field_6E = 0;
    self->field_70 = 0;
    self->field_71 = 0;
    self->field_39D = 0;
    self->field_E4 = -1;
    self->field_138 = -1;
    self->field_14C = -1;
    self->field_1A0 = -1;
    self->field_1CC = -1;
    self->field_1F8 = -1;
    self->field_308 = -1;
    self->field_334 = -1;
    self->field_34C = -1;
    for (int i2 = 0; (i2 < 12); i2++) {
        self->field_35C[i2] = 1;
        self->field_368[i2] = self->field_35C[i2];
    }
}
