// func_00155A40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004EE040.h"
#include "b3/classes/UnkStruct_D_0055EF6C.h"
#include "b3/classes/UnkStruct_D_006481A0.h"

struct UnkStruct_00155A40;
struct UnkStruct_00155A40_2;
struct UnkStruct_00155A40_3;

struct UnkStruct_00155A40_2 {
    unsigned char pad_0[0x1914];
    int field_1914;
};

struct UnkStruct_00155A40_3 {
    int field_0;
    int field_4;
    int field_8;
};

struct UnkStruct_00155A40 {
    unsigned char pad_0[0x8];
    int field_8;
    float field_C;
    unsigned char pad_10[0x8];
    int field_18;
    unsigned char pad_1C[0x20];
    float field_3C;
    unsigned char pad_40[0x38];
    int field_78;
    unsigned char pad_7C[0x1C];
    int field_98;
    unsigned char pad_9C[0x4];
    unsigned char field_A0;
    unsigned char field_A1;
    unsigned char field_A2;
    unsigned char pad_A3[0x25];
    UnkStruct_00155A40_2 * field_C8;
    unsigned char pad_CC[0x1B0];
    int field_27C;
};

extern UnkStruct_D_0055EF6C D_0055EF6C;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_006481A0 D_006481A0;
extern "C" int func_00131E40(void *);
extern "C" void func_00155BC0(UnkStruct_00155A40 *);
extern "C" void func_0014E7E0(void *, int *, int *, int *);

// 0x00155A40
extern "C" void func_00155A40(UnkStruct_00155A40 * self, int p0)
{
    int x2;
    int x1;
    int x0;
    self->field_8 = p0;
    self->field_27C = 3;
    int r0 = func_00131E40(&D_004EE040);
    if (r0 != 0) {
        if (D_0055EF6C.field_0 == 0) {
            func_00155BC0(self);
        }
    }
    if (self->field_A0 == 0) {
        if (p0 == 1) {
            if (self->field_C8->field_1914 == 0) {
                self->field_A2 = 1;
            }
        }
    }
    int r2 = func_00131E40(&D_004EE040);
    if (r2 != 0) {
        if (D_0055EF6C.field_0 == 0) {
            int t0 = self->field_98;
            func_0014E7E0(&D_006481A0, &x0, &x1, &x2);
            if (t0 >= x2) {
                self->field_78 = 2;
            } else {
                if (t0 >= x1) {
                    self->field_78 = 1;
                } else {
                    if (!(t0 < x0)) {
                        self->field_78 = 0;
                    } else {
                        self->field_78 = 4;
                    }
                }
            }
        }
    }
    if ((unsigned int)(p0 + -2) < (unsigned int)2) {
    self->field_C = 3.4028235e+38f;
    if (self->field_18 == 0) {
        self->field_3C = 3.4028235e+38f;
    }
    if (self->field_A0 == 0) {
        self->field_A1 = 1;
    }
    }
}
