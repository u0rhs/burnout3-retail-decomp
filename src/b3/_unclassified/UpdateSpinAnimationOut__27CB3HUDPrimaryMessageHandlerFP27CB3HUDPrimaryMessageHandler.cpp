// Hand-written; the lifter refused it (v291: Out2-twin shape; size assigned to one outer CGtV2d; (float)(0.75f-d) cast + t=0.5f;t-=d fix FP numbering/layout).

// v291: hand-written (lifter had no draft). Twin of the archived UpdateSpinAnimationOut2 (0x3D4990): `size = a * CGtV2d(x, y);`
// as an assignment to one outer CGtV2d gives retail's return-temp copies and slot order; `t = 0.5f; t -= d;` and the
// `(float)(0.75f - d)` cast fix FP-register numbering / block layout [G shape]. Float literals = retail .lit4 values.
#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;

class CGt2dObject;

struct UnkStruct_003D4C70_2 {
    CGtV2d field_0;
    CGtV2d field_8;
    unsigned char pad_10[0x22];
    unsigned char field_32;     // [G] an alpha byte: (int)(255.99f * a)
};

struct UnkStruct_003D4C70_4 {
    unsigned char pad_0[0x10];
    GtMathPs2::CGtV4d field_10;
    unsigned char pad_20[0xC];
    float field_2C;
    float field_30;
};

struct UnkStruct_003D4C70 {
    void * field_0;
    int field_4;
    unsigned char pad_8[0x4];
    UnkStruct_003D4C70_2 * field_C;
    UnkStruct_003D4C70_2 * field_10;
    UnkStruct_003D4C70_4 * field_14;
    CGtV2d field_18;
    CGtV2d field_20;
    CGtV2d field_28;
    CGtV2d field_30;
    unsigned char pad_38[0x118];
    float field_150;
    float field_154;
};

extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, CGt2dObject *);  // CGt2dScene::DestructObject(int,CGt2dObject*)

// 0x003D4C70
extern "C" bool UpdateSpinAnimationOut__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler(UnkStruct_003D4C70 * self)
{
    float d = self->field_150 - self->field_154;
    if (d > 0.5f) {
        float x;
        float a;
        float y;
        if (d < 0.56f) {
            a = 0.0f;
            x = 0.0f + 1.0f + 23.333336f * (d - 0.5f);
        } else {
            x = 0.0f + 0.4f + 10.526316f * (0.75f - d);
            a = 5.263158f * (d - 0.56f);
            if (a > 1.0f) a = 1.0f;
        }
        self->field_C->field_32 = (int)(255.99f * a);
        if (d < 0.7f) y = 0.0f + 0.1f + 4.5f * (float)(0.75f - d);
        else y = 0.1f;
        CGtV2d size;
        size = self->field_20 * CGtV2d(x, y);
        self->field_C->field_0 = self->field_18 - size * 0.5f;
        self->field_C->field_8 = size;
        if (self->field_10 != 0) {
            size = self->field_30 * CGtV2d(x, y);
            self->field_10->field_0 = self->field_28 - size * 0.5f;
            self->field_10->field_8 = size;
        }
    }
    UnkStruct_003D4C70_4 * o = self->field_14;
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
