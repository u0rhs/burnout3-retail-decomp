// func_00434BF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dFrame.h"
#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

struct UnkStruct_00434BF0;

struct UnkStruct_00434BF0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject * field_C[2];

    CGt2dObject * field_14[2];

    CGt2dObject * field_1C[2];
    unsigned char pad_24[0x10];
    int field_34;
    int field_38;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, CGt2dObject *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void Destruct__10CGt2dFrameFv(void *);  // CGt2dFrame::Destruct()

// 0x00434BF0
extern "C" void func_00434BF0(UnkStruct_00434BF0 * self)
{
    Release__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    for (int i = 0; i < 2; i++) {
        if (self->field_1C[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8, self->field_1C[i]);
            self->field_1C[i] = 0;
        }
        if (self->field_C[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 1, self->field_C[i]);
            self->field_C[i] = 0;
        }
        if (self->field_14[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 2, self->field_14[i]);
            self->field_14[i] = 0;
        }
    }
    for (int j = 0; j < 3; j++) {
        scene->field_2C[self->field_8 + j].field_C = 0;
    }
    Destruct__10CGt2dFrameFv((void *)self->field_38);
    self->field_38 = 0;
    Destruct__10CGt2dFrameFv((void *)self->field_34);
    self->field_34 = 0;
}
