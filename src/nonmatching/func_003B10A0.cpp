// NONMATCHING: func_003B10A0 -- retail 261 / ours 260 instructions, 161 in changed runs
// 161 instrs: logic per retail (inline Interpolate stand-in, branch-assigned lo/hi floats keep retail's unfolded 50-50); frame 0x110 vs 0x140: CGtV2d locals' slots (retail size 0x138, c 0x130, pos 0x128, o2/off 0x120/0x118 read through y pointers) not reproduced
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003B10A0 -- hand-written (fresh6). Unnamed in every table, so the asm label with C linkage; `self` is whatever
// a0 points to. Every type is [G] (instruction widths).
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_003B10A0_obj {
    CGtV2d field_0;
    CGtV2d field_8;
    CGtV4d field_10;
};
struct UnkStruct_003B10A0 {
    UnkStruct_003B10A0_obj *field_0;
    UnkStruct_003B10A0_obj *field_4;
    UnkStruct_003B10A0_obj *field_8;
    UnkStruct_003B10A0_obj *field_C;
    unsigned char pad_10[0x12];
    signed char field_22;
};
struct UnkStruct_003B10A0_xf { CGtV2d field_0; CGtV2d field_8; };
struct UnkStruct_D_01E88D18 { UnkStruct_003B10A0_xf *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x10]; CGtV4d field_10; };

extern UnkStruct_D_01E88D18 D_01E88D18;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void Prepare__16CB3Panel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUif(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, unsigned int, float);

// [L] stands in for GtMathPs2::Interpolate(const CGtV2d&, const CGtV2d&, float) (B3O0PCH map, 116 bytes; not in the header)
static inline CGtV2d func_003B10A0_inl1(const CGtV2d &a, const CGtV2d &b, float t)
{
    return a + (b - a) * t;
}

// 0x003B10A0
extern "C" void func_003B10A0(UnkStruct_003B10A0 *self, const CGtV2d &p, int big, float t)
{
    if (self->field_4 == 0) return;
    float k;
    float alpha;
    if (t < 0.3000000119f) {
        alpha = 0.0f;
        k = 3.333333254f * t;
    } else {
        alpha = 1.428571463f * (t - 0.3000000119f);
        k = 1.0f;
    }
    UnkStruct_003B10A0_xf *xf = D_01E88D18.field_0;
    CGtV2d c = p * xf->field_8 + xf->field_0;
    float side;
    if (self->field_22 < 0) {
        if (c.marValues[0] > 320.0f) side = 1.0f;
        else side = 0.0f;
    } else {
        side = (float)self->field_22;
    }
    CGtV2d pos;
    if (side > 0.0f) pos = c + CGtV2d(-5.0f, 5.0f);
    else pos = c + CGtV2d(5.0f, 5.0f);
    float lx, ly, hx, hy;
    if (big) {
        lx = 50.0f; ly = 2.0f; hx = 50.0f; hy = 30.0f;
    } else {
        lx = 50.0f; ly = 2.0f; hx = 50.0f; hy = 50.0f;
    }
    CGtV2d anchor(side, 0.0f);
    CGtV2d size = func_003B10A0_inl1(CGtV2d(lx, ly), CGtV2d(hx, hy), k);
    Prepare__16CB3Panel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUif(self->field_4, pos, anchor, size, 0x31, 8.0f);
    if (self->field_8 != 0) {
        float dx = 25.0f - 0.5f * (self->field_8->field_8.marValues[0] + self->field_C->field_8.marValues[0]);
        float dy = 25.0f - 0.25f * self->field_8->field_8.marValues[1];
        CGtV2d o2(dx + self->field_8->field_8.marValues[0], dy + 13.0f);
        self->field_8->field_0 = self->field_4->field_0 + CGtV2d(dx, dy);
        self->field_C->field_0 = self->field_4->field_0 + o2;
        CGtV4d col = D_01E90240.field_10;
        col.SetA(alpha);
        self->field_8->field_10 = col;
        self->field_C->field_10 = col;
    }
    if (self->field_0 != 0) {
        CGtV4d col(1.0f, 1.0f, 1.0f, 1.0f);
        col.SetA(alpha);
        CGtV2d off;
        off.marValues[0] = (self->field_4->field_8.marValues[0] - self->field_0->field_8.marValues[0]) * 0.5f;
        off.marValues[1] = (self->field_4->field_8.marValues[1] - self->field_0->field_8.marValues[1]) * 0.5f;
        if (self->field_8 != 0) off.marValues[1] -= 7.0f;
        self->field_0->field_0 = self->field_4->field_0 + off;
        self->field_0->field_10 = col;
    }
}
