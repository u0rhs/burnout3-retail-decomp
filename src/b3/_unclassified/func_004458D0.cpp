// func_004458D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

struct UnkStruct_004458D0;

struct UnkStruct_004458D0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject * field_C[1];  // [G] element count unknown
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// 0x004458D0
extern "C" void func_004458D0(UnkStruct_004458D0 * self)
{
    Release__20CB3MenuComponentBaseFv(self);
    short t0 = self->field_8;
    UnkStruct_D_01E903E0 * const sc = &D_01E903E0;
    for (int i = 0; (i < 6); i++) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(sc, t0, self->field_C[i]);
        self->field_C[i] = 0;
    }
}
