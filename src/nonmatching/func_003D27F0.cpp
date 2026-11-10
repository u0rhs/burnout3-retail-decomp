// NONMATCHING: func_003D27F0 -- retail 171 / ours 177 instructions, 146 in changed runs
// Structure recovered (visibility toggle, then four CGtV2d layouts and an optional fade box); the control flow matches. Left: GtMathPs2 header gap -- retail keeps one pos/off pair on the stack and updates it in place through address registers (addiu v1,sp,0xBC / a0,sp,0xB4: an in-place -=/+= API the header lacks); also the record base is a +0x14 sub-struct (lw 0x2C(s0)). Return type void (f0 is never set deliberately). (a61)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003D27F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_003D27F0_13 {
    CGtV2d field_0;
    CGtV2d field_8;
    CGtV4d field_10;
};

struct UnkStruct_003D27F0_e1 {
    int field_0;
    unsigned char pad_4[0xC];
};

struct UnkStruct_003D27F0_e0 {
    unsigned char pad_0[0x40];
    UnkStruct_003D27F0_e1 * field_40;
    unsigned char pad_44[0x2C];
};

struct UnkStruct_D_004CA638 {
    CGtV2d field_0;
    unsigned char pad_8[0x4];
    float field_C;
};

struct UnkStruct_D_004CA658 {
    CGtV2d field_0;
    unsigned char pad_8[0x4];
    float field_C;
};

struct UnkStruct_D_004CA670 {
    CGtV2d field_0;
    unsigned char pad_8[0x8];
};

struct UnkStruct_003D27F0 {
    unsigned char pad_0[0x4];
    UnkStruct_003D27F0_e0 * field_4;
    unsigned char pad_8[0x8];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    CGtV2d * field_20;
    CGtV2d * field_24;
    CGtV2d * field_28;
    CGtV2d * field_2C;
    unsigned char pad_30[0x4];
    UnkStruct_003D27F0_13 * field_34;
};

extern UnkStruct_D_004CA638 D_004CA638;
extern UnkStruct_D_004CA658 D_004CA658;
extern UnkStruct_D_004CA670 D_004CA670;

extern "C" void SetAllLayerVisible__15CB3HUDComponentFb(void *, bool);  // CB3HUDComponent::SetAllLayerVisible(bool)
extern "C" void func_003D2AA0(UnkStruct_003D27F0 *, int);

// 0x003D27F0
extern "C" void func_003D27F0(UnkStruct_003D27F0 * self, bool p0, int p1, int p2, float t)
{
    int idx = self->field_10 + 2;
    UnkStruct_003D27F0_e0 * e = &self->field_4[self->field_1C];
    if ((1.0f == t && !p0) || (0.0f == t && p0)) {
        if (p1 != p2) {
            func_003D2AA0(self, p1);
        }
        SetAllLayerVisible__15CB3HUDComponentFb(self, p0);
    }
    if (p0) {
        t = 1.0f - t;
    }
    CGtV2d pos = D_004CA638.field_0;
    CGtV2d off(0.0f * t, D_004CA638.field_C * t);
    pos.marValues[0] -= off.marValues[0];
    pos.marValues[1] -= off.marValues[1];
    *self->field_20 = pos;
    *self->field_24 = CGtV2d(D_004CA638.field_0.marValues[0], pos.marValues[1] + D_004CA638.field_C);
    pos = D_004CA658.field_0;
    off = CGtV2d(0.0f * t, D_004CA658.field_C * t);
    pos += off;
    *self->field_28 = pos;
    *self->field_2C = CGtV2d(D_004CA658.field_0.marValues[0], pos.marValues[1] - 2.0f);
    *self->field_28 = pos + off;
    if ((e->field_40[idx].field_0 & 1) == 0) {
        pos = D_004CA670.field_0;
        off = CGtV2d(0.0f * t, (480.0f - D_004CA670.field_0.marValues[1]) * t);
        CGtV4d c(1.0f, 1.0f, 1.0f, 1.0f - t);
        pos += off;
        pos.marValues[0] -= self->field_34->field_8.marValues[0];
        pos.marValues[1] -= self->field_34->field_8.marValues[1];
        self->field_34->field_0 = pos;
        self->field_34->field_10 = c;
    }
}
