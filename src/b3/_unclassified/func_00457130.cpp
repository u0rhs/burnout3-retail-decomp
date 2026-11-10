// func_00457130 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dObject.h"

struct UnkStruct_00457130;

struct UnkStruct_00457130 {
    void * field_0;
    int field_4;
    int field_8;
    CGt2dObject * field_C;
    CGt2dObject * field_10[2];  // [G] element count from the loop bound
    CGt2dObject * field_18[2];  // [G] element count from the loop bound
};

extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// 0x00457130
extern "C" void func_00457130(UnkStruct_00457130 * self, int a1 /* passed by every caller, not read here */)
{
    CGt2dObject * t0 = self->field_C;
    if (t0 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(self->field_0, self->field_4, (CGt2dObject*)t0);
        self->field_C = 0;
    }
    for (int i = 0; (i < 2); i++) {
        CGt2dObject * t1 = self->field_10[i];
        if (t1 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(self->field_0, self->field_4, (CGt2dObject*)t1);
            self->field_10[i] = 0;
        }
    }
    for (int i1 = 0; (i1 < 2); i1++) {
        CGt2dObject * t2 = self->field_18[i1];
        if (t2 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(self->field_0, self->field_8, (CGt2dObject*)t2);
            self->field_18[i1] = 0;
        }
    }
}
