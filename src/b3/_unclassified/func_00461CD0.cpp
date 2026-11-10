// func_00461CD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dFrame.h"
#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

struct UnkStruct_00461CD0;

struct UnkStruct_00461CD0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject *field_C[1];  // [G] element count unknown
    unsigned char pad_10[0x80];
    int field_90;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void Destruct__10CGt2dFrameFv(void *);  // CGt2dFrame::Destruct()

// 0x00461CD0
extern "C" void func_00461CD0(UnkStruct_00461CD0 * self)
{
    Release__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    for (int i = 0; (i < 32); i++) {
        CGt2dObject **pp = &self->field_C[i];
        if (*pp) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8, *pp);
            *pp = 0;
        }
    }
    Destruct__10CGt2dFrameFv((void *)self->field_90);
    self->field_90 = 0;
}
