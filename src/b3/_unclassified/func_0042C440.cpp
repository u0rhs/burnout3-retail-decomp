// func_0042C440 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dFrame.h"
#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

struct UnkStruct_0042C440;

struct UnkStruct_0042C440 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x1E2];
    CGt2dObject * field_1EC[4];  // [G] 4 from the loop bound
    CGt2dObject * field_1FC[4];  // [G] 4 from the loop bound
    CGt2dObject * field_20C;
    CGt2dObject * field_210;
    void * field_214;  // [G] passed to CGt2dFrame::Destruct
    CGt2dObject * field_218;
    CGt2dObject * field_21C;
    CGt2dObject * field_220[4];  // [G] 4 from the loop bound
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void Destruct__10CGt2dFrameFv(void *);  // CGt2dFrame::Destruct()

// 0x0042C440
extern "C" void func_0042C440(UnkStruct_0042C440 * self)
{
    Release__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    if (self->field_20C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8, self->field_20C);
        self->field_20C = 0;
    }
    for (int i = 0; i < 4; i++) {
        UnkStruct_D_01E903E0 * const scene2 = &D_01E903E0;  // [G] own scene pointer: retail keeps a second &D_01E903E0 register for this loop
        if (self->field_1EC[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene2, self->field_8 + 1, self->field_1EC[i]);
            self->field_1EC[i] = 0;
        }
        if (self->field_1FC[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene2, self->field_8 + 1, self->field_1FC[i]);
            self->field_1FC[i] = 0;
        }
    }
    for (int i = 0; i < 4; i++) {
        if (self->field_220[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 3, self->field_220[i]);
            self->field_220[i] = 0;
        }
    }
    if (self->field_214 != 0) {
        Destruct__10CGt2dFrameFv(self->field_214);
        self->field_214 = 0;
    }
    if (self->field_210 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 2, self->field_210);
        self->field_210 = 0;
    }
    if (self->field_218 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 2, self->field_218);
        self->field_218 = 0;
    }
    if (self->field_21C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 2, self->field_21C);
        self->field_21C = 0;
    }
}
