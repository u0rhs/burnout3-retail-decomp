// Hand-written; the lifter refused it (N140 0x20 pad (16-aligned, below the CGtV2d temps) + one alpha float reused for both SetA calls).

// UpdateWibbleAnimationIn__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;

struct UnkStruct_003D47D0_2 {
    CGtV2d field_0;
    CGtV2d field_8;
    GtMathPs2::CGtV4d field_10;
    unsigned char pad_20[0x4];
    float field_24;
};

struct UnkStruct_003D47D0_9 {
    unsigned char pad_0[0x10];
    GtMathPs2::CGtV4d field_10;
    unsigned char pad_20[0xC];
    float field_2C;
};

struct UnkStruct_003D47D0 {
    unsigned char pad_0[0xC];
    UnkStruct_003D47D0_9 * field_C;
    UnkStruct_003D47D0_2 * field_10;
    unsigned char pad_14[0x14];
    CGtV2d field_28;
    CGtV2d field_30;
    unsigned char pad_38[0x118];
    float field_150;
};

// 0x003D47D0
// [G] N140 pad (stack investigator): an unused 0x20-byte local object. Retail's frame (0x60) keeps 0x20 unused
// bytes below all its CGtV2d temporaries, which is where MWCC puts 16-aligned (>= 16-byte) locals.
struct UnkStruct_003D47D0_pad { unsigned char field_0[0x20]; UnkStruct_003D47D0_pad() {} ~UnkStruct_003D47D0_pad() {} };
extern "C" int UpdateWibbleAnimationIn__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler(UnkStruct_003D47D0 * self)
{
    UnkStruct_003D47D0_pad pad0;  // [G] frame pad, see above
    float t = self->field_150;
    float a;
    if (self->field_10 != 0) {
        self->field_10->field_24 = 1.0f;
        a = 1.0f;
        float s = 1.0f;
        if (t < 0.33f) {
            a = 3.030303001f * t;
            if (t < 0.231f) {
                s = 6.493506432f * t;
            } else {
                s = 1.5f + -5.050504684f * (t - 0.231f);
            }
        }
        self->field_10->field_10.SetA(a);
        CGtV2d size = self->field_30 * s;
        CGtV2d size2 = size;
        self->field_10->field_0 = self->field_28 - size * 0.5f;
        self->field_10->field_8 = size2;
    }
    a = 1.0f;
    if (t < 0.05f) {
        a = 20.0f * t;
    }
    self->field_C->field_10.SetA(a);
    float v = 1.0f;
    if (t < 0.75f) {
        v = 1.333333373f * t;
    }
    self->field_C->field_2C = v;
    if (!(t < 0.75f)) {
        return 0;
    }
    return 1;
}
