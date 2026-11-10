// func_003BC610 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dFrame.h"
#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

struct UnkStruct_003BC610;

struct UnkStruct_003BC610 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0xA];
    CGt2dObject * field_14[9];
    CGt2dObject * field_38[9];
    CGt2dObject * field_5C[9];
    CGt2dObject * field_80[9];
    CGt2dObject * field_A4;
    CGt2dObject * field_A8;
    int field_AC[9];
    CGt2dObject * field_D0;
    CGt2dFrame * field_D4;
    CGt2dFrame * field_D8;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(UnkStruct_D_01E903E0 *, int, CGt2dObject *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void Destruct__10CGt2dFrameFv(CGt2dFrame *);  // CGt2dFrame::Destruct()

// 0x003BC610
extern "C" void func_003BC610(UnkStruct_003BC610 * self)
{
    Release__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    int i;
    short t0 = self->field_8;
    int k1 = t0 + 1;
    int k4 = t0 + 4;
    int k3 = t0 + 3;
    int k2 = t0 + 2;
    int k0 = t0;
    int m = D_01E90424.field_0;
    if (m == 6 || m == 3 || m == 4) {
        for (int j = 0; j < 9; j++) {
            self->field_AC[j] = 0;
        }
    }
    for (i = 0; i < 9; i++) {
        if (self->field_14[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k1, self->field_14[i]);
            self->field_14[i] = 0;
        }
        if (self->field_38[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k2, self->field_38[i]);
            self->field_38[i] = 0;
        }
        if (self->field_5C[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k3, self->field_5C[i]);
            self->field_5C[i] = 0;
        }
        if (self->field_80[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k4, self->field_80[i]);
            self->field_80[i] = 0;
        }
    }
    if (self->field_A4 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k2, self->field_A4);
        self->field_A4 = 0;
    }
    if (self->field_A8 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k2, self->field_A8);
        self->field_A8 = 0;
    }
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, k0, self->field_D0);
    self->field_D0 = 0;
    int idx = self->field_8 + 3;
    scene->field_2C[idx].field_C = 0;
    Destruct__10CGt2dFrameFv(self->field_D4);
    self->field_D4 = 0;
    Destruct__10CGt2dFrameFv(self->field_D8);
    self->field_D8 = 0;
}
