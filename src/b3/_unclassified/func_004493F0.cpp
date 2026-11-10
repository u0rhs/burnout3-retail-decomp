// func_004493F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E8D450.h"
#include "b3/classes/UnkStruct_D_01E8D45A.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

struct UnkStruct_004493F0;

struct UnkStruct_004493F0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2E];
    CGt2dObject * field_38[5];
    CGt2dObject * field_4C;
    unsigned char pad_50[0x38];
    int field_88;
    int field_8C;
    signed char field_90;
};

extern UnkStruct_D_01E8D45A D_01E8D45A;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// 0x004493F0
extern "C" void func_004493F0(UnkStruct_004493F0 * self)
{
    Release__20CB3MenuComponentBaseFv(self);
    void * const scene = &D_01E903E0;
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8, (CGt2dObject*)self->field_88);
    if (self->field_90 != 5) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 1, (CGt2dObject*)self->field_8C);
    }
    if (self->field_4C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 1, self->field_4C);
        self->field_4C = 0;
    }
    for (int i = 0; i < 5; i++) {
        if (self->field_38[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 1, self->field_38[i]);
            self->field_38[i] = 0;
        }
    }
    if (D_01E8D45A.field_0 != 0) {
        ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
    }
    self->field_88 = 0;
    self->field_8C = 0;
}
