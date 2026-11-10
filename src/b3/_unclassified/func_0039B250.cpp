// func_0039B250 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

struct UnkStruct_0039B250;

struct UnkStruct_0039B250 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0xA];
    int field_14[1];  // [G] element count unknown
    unsigned char pad_18[0x18];
    int field_30[1];  // [G] element count unknown
    unsigned char pad_34[0x4];
    int field_38;
    unsigned char pad_3C[0x1C];
    signed char field_58;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// 0x0039B250
extern "C" void func_0039B250(UnkStruct_0039B250 * self)
{
    Release__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    int i;
    int t0 = self->field_8;
    int t1 = t0 + 1;
    int i1;
    for (i = 0; (i < self->field_58); i++) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, t1, (CGt2dObject*)self->field_14[i]);
        self->field_14[i] = 0;
    }
    for (i1 = 0; (i1 < 2); i1++) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, t0, (CGt2dObject*)self->field_30[i1]);
        self->field_30[i1] = 0;
    }
    DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, t0, (CGt2dObject*)self->field_38);
    self->field_38 = 0;
}
