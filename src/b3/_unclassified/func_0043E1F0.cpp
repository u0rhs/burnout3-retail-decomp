// func_0043E1F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

struct UnkStruct_0043E1F0;

struct UnkStruct_0043E1F0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x6];
    CGt2dObject * field_10[3];
    CGt2dObject * field_1C[3];
    CGt2dObject * field_28[3];
    CGt2dObject * field_34[3];
    unsigned char pad_40[0xC];
    CGt2dObject * field_4C[3];
    CGt2dObject * field_58[3];
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, CGt2dObject *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// 0x0043E1F0
extern "C" void func_0043E1F0(UnkStruct_0043E1F0 * self)
{
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    for (int i = 0; i < 3; i++) {
        if (self->field_10[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 1, self->field_10[i]);
            self->field_10[i] = 0;
        }
        if (self->field_1C[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 1, self->field_1C[i]);
            self->field_1C[i] = 0;
        }
        if (self->field_28[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 1, self->field_28[i]);
            self->field_28[i] = 0;
        }
        if (self->field_34[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 2, self->field_34[i]);
            self->field_34[i] = 0;
        }
        if (self->field_4C[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 2, self->field_4C[i]);
            self->field_4C[i] = 0;
        }
        if (self->field_58[i] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, self->field_8 + 2, self->field_58[i]);
            self->field_58[i] = 0;
        }
    }
}
