// Hand-written; the lifter refused it (CB3TipComponent::Release: stride-8 row accessed via a row struct cast at (char*)self + j*8 with fields at 0x20/0x24 (keeps s0=self+j*8 base)).

#include "b3/classes/CGt2dObject.h"
#include "b3/classes/UnkStruct_D_01E903E0.h"

struct UnkStruct_00342E10_pair {
    CGt2dObject * field_0;
    CGt2dObject * field_4;
};

struct UnkStruct_00342E10_row {
    unsigned char pad_0[0x20];
    CGt2dObject * field_20;
    CGt2dObject * field_24;
};

struct UnkStruct_00342E10 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[2];
    CGt2dObject * field_C;
    CGt2dObject * field_10;
    CGt2dObject * field_14;
    CGt2dObject * field_18[2];
    UnkStruct_00342E10_pair field_20[2];
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// 0x00342E10
extern "C" void Release__15CB3TipComponentFv(UnkStruct_00342E10 * self)
{
    void * scene = &D_01E903E0;
    int layer = self->field_8;
    int layer1 = layer + 1;
    Release__20CB3MenuComponentBaseFv(self);
    if (self->field_18[0] != 0) {
        for (int i = 0; i < 2; i++) {
            CGt2dObject ** pp = &self->field_18[i];
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, layer1, *pp);
            *pp = 0;
        }
    }
    for (int j = 0; j < 2; j++) {
        UnkStruct_00342E10_row * e = (UnkStruct_00342E10_row *)((char *)self + j * 8);
        if (e->field_20 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, layer, e->field_20);
            e->field_20 = 0;
            CGt2dObject ** pp = &e->field_24;
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, layer, *pp);
            *pp = 0;
        }
    }
    if (self->field_C != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, layer1, self->field_C);
        self->field_C = 0;
    }
    if (self->field_14 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, layer, self->field_14);
        self->field_14 = 0;
    }
    if (self->field_10 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, layer, self->field_10);
        self->field_10 = 0;
    }
}
