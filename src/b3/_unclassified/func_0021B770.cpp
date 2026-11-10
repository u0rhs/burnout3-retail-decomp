// func_0021B770 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2910.h"
#include "b3/classes/UnkStruct_D_004E2914.h"
#include "b3/classes/UnkStruct_D_004E2918.h"
#include "b3/classes/UnkStruct_D_004EE040.h"

struct UnkStruct_0021B770;

struct UnkStruct_0021B770 {
    unsigned char pad_0[0x2C];
    unsigned char field_2C[1];  // [G] element count unknown
    unsigned char pad_2D[0x3];
    unsigned char field_30;
    unsigned char field_31;
    unsigned char pad_32[0x1];
    unsigned char field_33;
    unsigned char field_34;
    unsigned char field_35;
    unsigned char field_36;
    unsigned char field_37;
    unsigned char field_38;
    unsigned char field_39;
    unsigned char field_3A;
    unsigned char field_3B;
    unsigned char field_3C;
    unsigned char field_3D;
    unsigned char field_3E;
    unsigned char field_3F;
};

extern UnkStruct_D_004E2910 D_004E2910;
extern UnkStruct_D_004E2914 D_004E2914;
extern UnkStruct_D_004E2918 D_004E2918;
extern UnkStruct_D_004EE040 D_004EE040;
extern "C" void * memset(void *, int, unsigned int);
extern "C" void func_00131B30(void *);

// 0x0021B770
extern "C" void func_0021B770(UnkStruct_0021B770 * self)
{
    D_004E2910.field_0 = 0;
    D_004E2914.field_0 = 0;
    self->field_30 = 0;
    self->field_31 = 0;
    self->field_33 = 0;
    self->field_34 = 90;
    self->field_35 = 90;
    self->field_36 = 90;
    self->field_37 = 0;
    self->field_38 = 0;
    self->field_39 = 1;
    self->field_3A = 1;
    self->field_3B = 1;
    self->field_3C = 0;
    self->field_3D = 1;
    self->field_3E = 1;
    self->field_3F = 0;
    D_004E2918.field_0 = 1;
    func_00131B30(&D_004EE040);
    memset(self, 15, 44);
    for (int i = 0; (i < 4); i++) {
        self->field_2C[i] = 1;
    }
}
