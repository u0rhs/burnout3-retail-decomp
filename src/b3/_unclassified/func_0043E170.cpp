// func_0043E170 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

struct UnkStruct_0043E170;

struct UnkStruct_0043E170 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject * field_C;
    unsigned char pad_10[0x9C];
    CGt2dObject * field_AC;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void func_0043E1F0(UnkStruct_0043E170 *);

// 0x0043E170
extern "C" void func_0043E170(UnkStruct_0043E170 * self)
{
    Release__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 * const s = &D_01E903E0;
    if (self->field_C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(s, self->field_8, self->field_C);
        self->field_C = 0;
    }
    if (self->field_AC != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(s, self->field_8 + 2, self->field_AC);
        self->field_AC = 0;
    }
    func_0043E1F0(self);
}
