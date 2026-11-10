// func_00435F50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dFrame.h"
#include "b3/classes/UnkStruct_D_004F509C.h"
#include "b3/classes/UnkStruct_D_00665ED0.h"
#include "b3/classes/UnkStruct_D_0066A4C0.h"

struct UnkStruct_00435F50;
struct UnkStruct_00435F50_1;
struct UnkStruct_00435F50_3;
struct UnkStruct_00435F50_e0;

struct UnkStruct_00435F50_1 {
    unsigned char pad_0[0x10C8];
    int field_10C8;
};

struct UnkStruct_00435F50_3 {
    unsigned char pad_0[0x8];
    int field_8;
    int field_C;
};

struct UnkStruct_00435F50_e0 {
    unsigned char pad_0[0x14];
    unsigned char field_14[0x5C];
};

struct UnkStruct_00435F50 {
    unsigned char pad_0[0x4];
    UnkStruct_00435F50_e0 * field_4;
    int field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0x6];
    int field_18;
    signed char field_1C;
    unsigned char pad_1D[0x3];
    int field_20;
    unsigned char pad_24[0x4];
    UnkStruct_00435F50_1 * field_28;
    float field_2C;
    unsigned char pad_30[0x100];
    int field_130;
    int field_134;
};

extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" int func_00435DB0(UnkStruct_00435F50 *);
extern "C" void func_001A0760(UnkStruct_00435F50_3 *, UnkStruct_00435F50_e0 *, int);
extern "C" void func_003D0710(void *, void *, UnkStruct_00435F50_3 *, void *, int, int, int, void *, void *, int, float, float);

// 0x00435F50
extern "C" void func_00435F50(UnkStruct_00435F50 * self)
{
    UnkStruct_00435F50_3 local;
    void * scene = self->field_4[self->field_1C].field_14;
    int t2 = self->field_10;
    UnkStruct_D_0066A4C0 * const g = &D_0066A4C0;
    if (self->field_28->field_10C8 != 0) {
        if (-1.0f == self->field_2C) {
            self->field_2C = 0.5f;
        }
        if (self->field_2C > 0.0f) {
            float t = self->field_2C - D_004F509C.field_0;
            self->field_2C = t;
            if (t <= 0.0f) {
                if (func_00435DB0(self) != 0) {
                self->field_2C = 0.0f;
                self->field_20 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, t2, (CGt2dFrame*)self->field_8);
                int t5 = self->field_18;
                local.field_8 = 0;
                local.field_C = 0;
                func_001A0760(&local, self->field_4, t5);
                func_003D0710((void *)(self->field_20), ((char *)&local + 0x8), &local, ((char *)g + 0x10), self->field_130, self->field_134, 0, (void *)(D_00665ED0.field_0), ((char *)self + 0x30), 0, 64.0f, 3.4028235e+38f);
                } else {
                    self->field_2C += D_004F509C.field_0;
                }
            }
        }
    }
}
