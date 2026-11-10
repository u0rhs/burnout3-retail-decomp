// func_003B6280 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

struct UnkStruct_003B6280;

struct UnkStruct_003B6280 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x16];
    CGt2dObject * field_20;
    unsigned char pad_24[0xC];
    CGt2dObject * field_30;
    CGt2dObject * field_34;
    CGt2dObject * field_38;
    CGt2dObject * field_3C;
    CGt2dObject * field_40;
    CGt2dObject * field_44;
    CGt2dObject * field_48;
    CGt2dObject * field_4C;
    CGt2dObject * field_50;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, CGt2dObject *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void Release__16CB3Globe2dObjectFv(CGt2dObject *);

// 0x003B6280
extern "C" void func_003B6280(UnkStruct_003B6280 * self)
{
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    Release__20CB3MenuComponentBaseFv(self);
    Release__16CB3Globe2dObjectFv(self->field_20);
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8, self->field_20);
    self->field_20 = 0;
    if (self->field_30 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 1, self->field_30);
        self->field_30 = 0;
    }
    if (self->field_34 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 2, self->field_34);
        self->field_34 = 0;
    }
    if (self->field_38 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 2, self->field_38);
        self->field_38 = 0;
    }
    if (self->field_3C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 2, self->field_3C);
        self->field_3C = 0;
    }
    if (self->field_40 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 2, self->field_40);
        self->field_40 = 0;
    }
    if (self->field_44 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 2, self->field_44);
        self->field_44 = 0;
    }
    if (self->field_48 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 2, self->field_48);
        self->field_48 = 0;
    }
    if (self->field_4C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 2, self->field_4C);
        self->field_4C = 0;
    }
    if (self->field_50 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 2, self->field_50);
        self->field_50 = 0;
    }
}
