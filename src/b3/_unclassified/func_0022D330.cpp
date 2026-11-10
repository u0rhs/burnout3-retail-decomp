// func_0022D330 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004B9E10.h"

struct UnkStruct_0022D330;

struct UnkStruct_0022D330 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[0x4];
    int field_14;
    int field_18;
    unsigned char pad_1C[0x20];
    int field_3C;
    unsigned char field_40;
};

extern UnkStruct_D_004B9E10 D_004B9E10;
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" void * memset(void *, int, unsigned int);

// 0x0022D330
extern "C" void func_0022D330(UnkStruct_0022D330 * self)
{
    self->field_4 = 0;
    self->field_8 = -1;
    self->field_C = -1;
    self->field_14 = 0;
    self->field_18 = 0;
    self->field_40 = 0;
    self->field_3C = 0;
    strncpy((char *)((char *)self + 0x1C), (const char *)&D_004B9E10, 16);
    memset(((char *)self + 0x2C), 0, 16);
}
