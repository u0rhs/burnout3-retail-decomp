// NONMATCHING: func_003A9040 -- retail 132 / ours 132 instructions, 32 in changed runs
// near28: 32 off (was 35). D_004E06CC/D_004E07F4 are .lit4 (1.2f/0.4f) -> literals; offset as static inline taking the call result by const& (div after the call). Left: retail reads the call-result temp through addiu v0,sp,K (ours direct sp), slot order of the call temp vs the arg copy, 1.25f/diff f0/f1 swap
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;

struct UnkStruct_003A9040;
struct UnkStruct_003A9040_3;
struct UnkStruct_003A9040_4;
struct UnkStruct_003A9040_5;
struct UnkStruct_003A9040_6;
struct UnkStruct_D_004E06CC;
struct UnkStruct_D_004E07F4;

struct UnkStruct_D_004E06CC {
    float field_0;
};

struct UnkStruct_D_004E07F4 {
    float field_0;
};

struct UnkStruct_003A9040_3 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    unsigned long field_18;
    unsigned char pad_20[0x8];
    float field_28;
    float field_2C;
    unsigned long field_30;
    unsigned char pad_38[0x8];
};

struct UnkStruct_003A9040_4 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003A9040_5 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003A9040_6 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003A9040_s40 {
    UnkStruct_003A9040_6 * field_0;
    unsigned char pad_4[0x8];
    signed char field_C;
    unsigned char pad_D[0x33];
};

struct UnkStruct_003A9040_s80 {
    unsigned char pad_0[0x4];
    UnkStruct_003A9040_4 * field_4;
};

struct UnkStruct_003A9040 {
    unsigned char pad_0[0x40];
    UnkStruct_003A9040_s40 field_40;
    UnkStruct_003A9040_s80 field_80;
    unsigned char pad_88[0x1A0];
    UnkStruct_003A9040_5 * field_228;
    unsigned char pad_22C[0x28];
    int field_254;
    unsigned char pad_258[0x24];
    int field_27C;
    unsigned char pad_280[0x488];
    float field_708;
    unsigned char pad_70C[0x1DA];
    unsigned char field_8E6;
};


extern "C" void func_003A8A90(UnkStruct_003A9040 *);
extern "C" void func_003A9250(UnkStruct_003A9040 *);
extern "C" CGtV2d func_003F5C70(int, int, int);
extern "C" void func_003B10A0(UnkStruct_003A9040_s80 *, const CGtV2d &, int, float);
extern "C" void Update__Q218CB3SatNavComponent9CPopupBoxFfRCQ29GtMathPs26CGtV2d(UnkStruct_003A9040_s40 *, const CGtV2d &, float);

// [G] offset helpers (placeholder names): the position by reference, the division after the call
static inline CGtV2d func_003A9040_inl1(const CGtV2d &q, float n, float d) { return q + CGtV2d(n / d, 0.0f); }
static inline CGtV2d func_003A9040_inl2(const CGtV2d &q, float n, float d) { return q - CGtV2d(n / d, 0.0f); }
extern "C" void func_003A9040(UnkStruct_003A9040 * self, float f0)
{
    float v = GtMath::Min(GtMath::Max(self->field_708 + f0, 0.0f), 1.2f);
    float lo = 0.4f;
    self->field_708 = v;
    if (v < lo) {
        func_003A8A90(self);
        return;
    }
    float scale = v - 0.4f;
    scale = 1.25f * scale;
    UnkStruct_003A9040_s40 * a = &self->field_40;
    UnkStruct_003A9040_s80 * b = &self->field_80;
    if (a->field_0 == 0) {
        func_003A9250(self);
    }
    if (a->field_C == 0) {
        CGtV2d p = func_003F5C70(self->field_254, self->field_27C, (self->field_8E6 != 0) ^ 1);
        Update__Q218CB3SatNavComponent9CPopupBoxFfRCQ29GtMathPs26CGtV2d(a, p, scale);
        float n = a->field_0->field_8;
        float d = self->field_228->field_8;
        func_003B10A0(b, func_003A9040_inl1(func_003F5C70(self->field_254, self->field_27C, (self->field_8E6 != 0) ^ 1), n, d), 0, scale);
    } else {
        CGtV2d p = func_003F5C70(self->field_254, self->field_27C, (self->field_8E6 != 0) ^ 1);
        func_003B10A0(b, p, 0, scale);
        float n = b->field_4->field_8;
        float d = self->field_228->field_8;
        Update__Q218CB3SatNavComponent9CPopupBoxFfRCQ29GtMathPs26CGtV2d(a, func_003A9040_inl2(func_003F5C70(self->field_254, self->field_27C, (self->field_8E6 != 0) ^ 1), n, d), scale);
    }
}


