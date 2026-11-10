// BUILD-HOST: wine
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004BA018.h"

struct UnkStruct_00230480 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    unsigned char pad_C[0x8];
    char field_14[0x10];
    int field_24;
    int field_28;
    unsigned char pad_2C[0x484];
    unsigned char field_4B0;
};

extern UnkStruct_D_004BA018 D_004BA018;
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" int sscanf(const char *, const void *, ...);

// 0x00230480
extern "C" int func_00230480(UnkStruct_00230480 * self, const char * p0, int p1, int p2, int p3)
{
    int a[4];
    strncpy(self->field_14, p0, 16);
    sscanf(self->field_14, &D_004BA018, &a[0], &a[1], &a[2], &a[3]);
    self->field_24 = (a[0] << 24) + (a[1] << 16) + (a[2] << 8) + a[3];
    self->field_28 = p1;
    self->field_4 = p2;
    self->field_8 = p3;
    self->field_4B0 = 0;
    return 1;
}
