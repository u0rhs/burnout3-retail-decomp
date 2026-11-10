// Hand-written; the lifter refused it (near1: Out-twin shape: outer size assigned, adda/madd s, (float)(d-0.5f) cast, t=0.5f;t-=d, 3 pads).

// near1: Out-twin shape (v291) -- one outer CGtV2d size assigned (size = field_20 * s), `0.0f + 1.0f + 0.25f*k` (adda/madd),
// `4.0f * (float)(d - 0.5f)` cast for FP numbering, `t = 0.5f; t -= d;`, three 16-byte pads for the 0xD0 frame [G shape].

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;

class CGt2dObject;

struct UnkStruct_003D4990_2 {
    CGtV2d field_0;
    CGtV2d field_8;
    GtMathPs2::CGtV4d field_10;
};

struct UnkStruct_003D4990_4 {
    unsigned char pad_0[0x10];
    GtMathPs2::CGtV4d field_10;
    unsigned char pad_20[0xC];
    float field_2C;
    float field_30;
};

struct UnkStruct_003D4990 {
    void * field_0;
    int field_4;
    unsigned char pad_8[0x4];
    UnkStruct_003D4990_2 * field_C;
    UnkStruct_003D4990_2 * field_10;
    UnkStruct_003D4990_4 * field_14;
    CGtV2d field_18;
    CGtV2d field_20;
    CGtV2d field_28;
    CGtV2d field_30;
    unsigned char pad_38[0x118];
    float field_150;
    float field_154;
};

extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, CGt2dObject *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

struct UnkStruct_003D4990_pad { int x[4]; UnkStruct_003D4990_pad() {} ~UnkStruct_003D4990_pad() {} };

// 0x003D4990
extern "C" bool UpdateSpinAnimationOut2__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler(UnkStruct_003D4990 * self)
{
    UnkStruct_003D4990_pad p0, p1, p2;
    float d = self->field_150 - self->field_154;
    if (d > 0.5f) {
        float k = 4.0f * (float)(d - 0.5f);
        k = k * k;
        float s = 0.0f + 1.0f + 0.25f * k;
        float a = 1.0f - k;
        CGtV2d size;
        size = self->field_20 * s;
        self->field_C->field_0 = self->field_18 - size * 0.5f;
        self->field_C->field_8 = size;
        self->field_C->field_10.SetA(a);
        if (self->field_10 != 0) {
            size = self->field_30 * s;
            self->field_10->field_0 = self->field_28 - size * 0.5f;
            self->field_10->field_8 = size;
            self->field_10->field_10.SetA(a);
        }
    }
    UnkStruct_003D4990_4 * o = self->field_14;
    if (o != 0) {
        float x;
        float y;
        if (d <= 0.25f) {
            float m = 4.0f;
            m = m * d;
            x = 1.0f - m;
            y = (1.0f + m) + m;
        } else {
            x = 0.0f;
            y = 1.0f;
        }
        o->field_2C = x;
        o->field_30 = y;
        if (!(d <= 0.25f)) {
            if (d < 0.5f) {
                float t = 0.5f;
                t -= d;
                float m = 4.0f;
                m = m * t;
                self->field_14->field_10.SetA(m);
            } else {
                DestructObject__10CGt2dSceneFiP11CGt2dObject(self->field_0, self->field_4, (CGt2dObject *)self->field_14);
                self->field_14 = 0;
            }
        }
    }
    return !(d >= 0.75f);
}
