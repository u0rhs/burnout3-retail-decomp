// func_003A8A90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

struct UnkStruct_003A8A90;
struct UnkStruct_003A8A90_e0;

struct UnkStruct_003A8A90_e0 {
    CGt2dObject * field_0;  // [G] pointer: null-tested then passed (int typing parks the then-blocks)
    CGt2dObject * field_4;
    CGt2dObject * field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_003A8A90 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x36];
    UnkStruct_003A8A90_e0 field_40[1];  // [G] element count unknown
    unsigned char pad_50[0x30];
    CGt2dObject * field_80;
    CGt2dObject * field_84;
    CGt2dObject * field_88;
    CGt2dObject * field_8C;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// 0x003A8A90
extern "C" void func_003A8A90(UnkStruct_003A8A90 * self)
{
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    int i;
    short t0 = self->field_8;
    int a = t0 + 10;
    int b = t0 + 11;
    int c = t0 + 12;
    int d = t0 + 13;
    for (i = 0; i < 4; i++) {
        UnkStruct_003A8A90_e0 * e = &self->field_40[i];
        if (e->field_0 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, e->field_0);
            e->field_0 = 0;
        }
        if (e->field_4 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, d, e->field_4);
            e->field_4 = 0;
        }
        if (e->field_8 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, d, e->field_8);
            e->field_8 = 0;
        }
    }
    if (self->field_88 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, d, self->field_88);
        self->field_88 = 0;
    }
    if (self->field_8C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, d, self->field_8C);
        self->field_8C = 0;
    }
    if (self->field_84 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, b, self->field_84);
        self->field_84 = 0;
    }
    if (self->field_80 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, c, self->field_80);
        self->field_80 = 0;
    }
}
