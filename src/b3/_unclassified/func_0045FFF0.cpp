// func_0045FFF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

struct UnkStruct_0045FFF0;

struct UnkStruct_0045FFF0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x676];
    CGt2dObject * field_680[1];  // [G] element count unknown
    unsigned char pad_684[0x4];
    CGt2dObject * field_688;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, CGt2dObject *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// 0x0045FFF0
extern "C" void func_0045FFF0(UnkStruct_0045FFF0 * self)
{
    Release__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    for (int i = 0; (i < 2); i++) {
        CGt2dObject ** pp = &self->field_680[i];
        if (*pp != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 1, *pp);
            *pp = 0;
        }
    }
    if (self->field_688 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 1, self->field_688);
        self->field_688 = 0;
    }
}
