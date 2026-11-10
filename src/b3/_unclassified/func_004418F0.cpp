// func_004418F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dFrame.h"
#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

struct UnkStruct_004418F0;

struct UnkStruct_004418F0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject * field_C;
    CGt2dObject * field_10;
    CGt2dObject * field_14;
    CGt2dObject * field_18;
    CGt2dObject * field_1C;
    CGt2dObject * field_20;
    void * field_24;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void Destruct__10CGt2dFrameFv(void *);  // CGt2dFrame::Destruct()
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()

// 0x004418F0
extern "C" void func_004418F0(UnkStruct_004418F0 * self)
{
    void * const scene = &D_01E903E0;
    int t0 = self->field_8;
    int t1 = t0 + 1;
    if (self->field_C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, t1, self->field_C);
        self->field_C = 0;
    }
    if (self->field_10 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, t1, self->field_10);
        self->field_10 = 0;
    }
    if (self->field_14 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, t1, self->field_14);
        self->field_14 = 0;
    }
    if (self->field_18 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, t0, self->field_18);
        self->field_18 = 0;
    }
    if (self->field_1C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, t0, self->field_1C);
        self->field_1C = 0;
    }
    if (self->field_20 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, t0, self->field_20);
        self->field_20 = 0;
    }
    if (self->field_24 != 0) {
        Destruct__10CGt2dFrameFv(self->field_24);
        self->field_24 = 0;
    }
    Release__20CB3MenuComponentBaseFv(self);
}
