// Release__25CB3EventFinishedComponentFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dFrame.h"
#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

struct UnkStruct_003B89C0;

struct UnkStruct_003B89C0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject * field_C;
    CGt2dObject * field_10;
    void * field_14;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void Destruct__10CGt2dFrameFv(void *);  // CGt2dFrame::Destruct()

// 0x003B89C0
extern "C" void Release__25CB3EventFinishedComponentFv(UnkStruct_003B89C0 * self)
{
    UnkStruct_D_01E903E0 * const s = &D_01E903E0;
    int t0 = self->field_8;
    Release__20CB3MenuComponentBaseFv(self);
    if (self->field_C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(s, t0, self->field_C);
        self->field_C = 0;
    }
    Destruct__10CGt2dFrameFv(self->field_14);
    self->field_14 = 0;
    if (self->field_10 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(s, t0, self->field_10);
        self->field_10 = 0;
    }
}
