// NONMATCHING: func_003356A0 -- retail 210 / ours 211 instructions, 32 in changed runs
// v294: logic + frame exact (N140 pad, CGtV2d tail ok); 32 left = Interpolate(CGtV4d) shape: retail a/result on $vf1, t $vf2, mfc1 of t before the asm, first call's a not folded to lqc2, results stored before the next call's loads (N94 family; volatile header form gives vf3)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003356A0 -- [L] B3HUDPos.cpp neighbour (research/proto/new_names.csv: the next function is CB3HUDPos::Update).
// Placeholder with C linkage (the asm label); every type [G] unless noted.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

// [L] a colour table (same object as B3HelpBarComponent_0031BD60.cpp's). Padded for N51.
struct UnkStruct_D_0066A4C0 {
    unsigned char pad0[0x30];
    CGtV4d field_30;
    unsigned char pad40[0x10];
    CGtV4d field_50;
    CGtV4d field_60;
    unsigned char pad70[0x100];
};
extern UnkStruct_D_0066A4C0 D_0066A4C0;

struct UnkStruct_D_0064D384 {
    int field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_0064D384 D_0064D384;

struct UnkStruct_D_0052267C {
    float field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_0052267C D_0052267C;

struct UnkStruct_003356A0_7 {
    unsigned char pad_0[0x10];
    float field_10;
};
struct UnkStruct_D_00665ED0 {
    UnkStruct_003356A0_7 *field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_00665ED0 D_00665ED0;

struct UnkStruct_D_01E7A800 {
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E7A800 D_01E7A800;

struct UnkStruct_003356A0_3 {
    short field_0;
    unsigned char pad_2[0x2];
    int field_4;
};

struct UnkStruct_003356A0 {
    unsigned char pad_0[0x24];
    CGt2dObject *field_24;
    unsigned char pad_28[0x4];
    CGt2dObject *field_2C;
    UnkStruct_003356A0_3 *field_30;
    int field_34;
    int field_38;
    float field_3C;
    unsigned short field_40[6];   // [L] the text passed to func_003824D0 (digits written as '0' + n)
    float field_4C;
    unsigned char field_50;
    unsigned char field_51;
    unsigned char field_52;
};

extern "C" void func_00284970(UnkStruct_D_01E7A800 *self, float f0);
// Same declaration as B3HelpBarComponent_0031BD60.cpp.
extern "C" void func_003824D0(CGt2dObject *obj, const CGtV2d &a, const CGtV2d &b, float c, CGtV4d d, CGtV4d e,
                              const unsigned short *text, int f, float g, float h);

// [L] N185: stands in for GtMathPs2::Interpolate(CGtV4d, CGtV4d, float) (header N94 body: `"+j"` a on a compiler-chosen
// register, moves folded); retail here has a and the result on $vf1, t on $vf2, b's and the result's moves kept.
static inline CGtV4d v294_interp(CGtV4d a, const CGtV4d &b, float t)
{
    u_long128 r;
    asm("qmtc2 %1, $vf1" "\n\t" "vaddax.xyzw $ACC, $vf1, $vf0x" "\n\t" "qmtc2.i %3, $vf2" "\n\t"
        "vmsubax.xyzw $ACC, $vf1, $vf2x" "\n\t" "qmtc2.i %2, $vf1" "\n\t" "vmaddx.xyzw $vf1, $vf1, $vf2x" "\n\t"
        "qmfc2.i %0, $vf1" : "=r"(r) : "r"(a.mData), "r"(b.mData), "r"(t));
    return CGtV4d(r);
}

struct UnkStruct_003356A0_pad { int x[4]; UnkStruct_003356A0_pad() {} ~UnkStruct_003356A0_pad() {} };

// 0x003356A0
extern "C" void func_003356A0(UnkStruct_003356A0 *self)
{
    float s = 2.5f * self->field_3C;
    UnkStruct_D_0066A4C0 *const colours = &D_0066A4C0;
    CGtV4d base;
    CGtV4d blend = v294_interp(colours->field_60, colours->field_30, 0.75f);
    UnkStruct_003356A0_pad pad;  // [G] N140 frame pad
    base = colours->field_60;
    if (self->field_51) {
        self->field_34 = self->field_30->field_4;
    } else {
        self->field_34 = self->field_30->field_0;
    }
    self->field_38 = D_0064D384.field_0;
    if (self->field_50 && self->field_30->field_0 == D_0064D384.field_0) {
        float v = 0.0f;
        float t = self->field_4C;
        if (t <= v) {
            self->field_4C = 1.0f;
        } else {
            if (t <= 0.5f) {
                v = 2.0f * t;
                if (!(v <= 0.95f)) {
                    func_00284970(&D_01E7A800, 0.9f);
                }
            }
            self->field_4C -= D_0052267C.field_0;
        }
        s = 0.25f * (v * v);
        base = v294_interp(base, colours->field_30, v);
        blend = v294_interp(blend, colours->field_50, v);
    }
    self->field_40[0] = self->field_34 + 48;
    self->field_40[3] = self->field_38 + 48;
    CGtV2d pos;
    CGtV2d anchor;
    float c;
    float g;
    if (self->field_52) {
        CGt2dObject *o = self->field_24;
        pos.Set(4.0f + (o->mObjectSpace.mTopLeftPos.marValues[0] + o->mObjectSpace.mSize.marValues[0]),
                o->mObjectSpace.mTopLeftPos.marValues[1]);
        anchor.Set(0.0f, 0.06f);
        c = 40.0f;
        g = 1.5f;
    } else {
        pos.Set(0.0f, 47.0f);
        anchor.Set(0.0f, D_00665ED0.field_0->field_10);
        c = 56.0f;
        g = 1.5f;
    }
    func_003824D0(self->field_2C, pos, anchor, c, base, blend, self->field_40, 65, g, 3.402823466e+38f);
    CGt2dObject *o = self->field_2C;
    o->mObjectSpace.mTopLeftPos = o->mObjectSpace.mTopLeftPos - o->mObjectSpace.mSize * s * 0.5f;
    o = self->field_2C;
    o->mObjectSpace.mSize = o->mObjectSpace.mSize * (1.0f + s);
}
