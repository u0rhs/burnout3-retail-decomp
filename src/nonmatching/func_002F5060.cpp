// NONMATCHING: func_002F5060 -- retail 449 / ours 457 instructions, 410 in changed runs
// draftAI: logic complete; retail 449 / ours 457; leaf (no calls); every VU op count identical (header CGtV3d -, * float, Normalise); left: retail re-indexes per use (sll/addu -6), reloads the segment lengths (lwc1 +6), moves the pending tangent through GPRs (lq +3 for lqc2), frame 0x280 (0x230 bytes unused below the three pending-tangent slots: an unused local array?) vs 0x30
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm op for op: inner-point unit tangents, natural end conditions, three identical length-weighted smoothing passes with a one-behind write (each its own 0x270/0x250/0x230 slot)

// func_002F5060 -- draftAI (C-first draft, 0x2F5060, 0x704). Unnamed in every table, so the asm label with C linkage.
// [L] finishes the camera path built by func_002F5770 (its only caller is func_00446300, after the points are appended):
// it sets the Hermite tangents (field_10, used by func_002F4F90 / func_002F5860 scaled by each segment's length): first the
// unit bisector-style direction at every inner point (normalise(normalise(next - p) - normalise(prev - p))), then the
// natural end conditions, then three smoothing passes that replace every tangent by the length-weighted average of the
// two neighbouring end-condition estimates (written one point behind, so each pass reads the previous pass's values).
// Field names are placeholders; the layout is func_002F4F90's (field_0 point, field_10 tangent, field_20 segment length).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_002F5060_e { CGtV3d field_0; CGtV3d field_10; float field_20; unsigned char pad_24[0xC]; };
struct UnkStruct_002F5060 { UnkStruct_002F5060_e field_0[0x32]; float field_960; int field_964; };

// [L] one end condition: the tangent at b from the chord a -> b (length len) and the tangent at the other end
static inline CGtV3d func_002F5060_inl1(const CGtV3d &a, const CGtV3d &b, float len, const CGtV3d &t)
{
    return ((b - a) * 3.0f * (1.0f / len) - t) * 0.5f;
}

// [L] one smoothing pass (inlined three times: retail keeps each copy's pending tangent in its own stack slot)
static inline void func_002F5060_inl2(UnkStruct_002F5060 *self)
{
    UnkStruct_002F5060_e *e = self->field_0;
    CGtV3d prev = func_002F5060_inl1(e[0].field_0, e[1].field_0, e[0].field_20, e[1].field_10);
    for (int i = 1; i < self->field_964 - 1; i++) {
        CGtV3d b = func_002F5060_inl1(e[i].field_0, e[i + 1].field_0, e[i].field_20, e[i + 1].field_10);
        CGtV3d a = func_002F5060_inl1(e[i - 1].field_0, e[i].field_0, e[i - 1].field_20, e[i - 1].field_10);
        CGtV3d r = (a * e[i].field_20 + b * e[i - 1].field_20) * (1.0f / (e[i - 1].field_20 + e[i].field_20));
        e[i - 1].field_10 = prev;
        prev = r;
    }
    int k = self->field_964 - 1;
    e[k].field_10 = func_002F5060_inl1(e[k - 1].field_0, e[k].field_0, e[k - 1].field_20, e[k - 1].field_10);
    e[self->field_964 - 2].field_10 = prev;
}

// 0x002F5060
extern "C" void func_002F5060(UnkStruct_002F5060 *self)
{
    UnkStruct_002F5060_e *e = self->field_0;
    for (int i = 1; i < self->field_964 - 1; i++) {
        CGtV3d a = e[i - 1].field_0 - e[i].field_0;
        CGtV3d b = e[i + 1].field_0 - e[i].field_0;
        b.Normalise();
        a.Normalise();
        e[i].field_10 = b - a;
        ((float *)&e[i].field_10)[3] = ((const float *)&a)[3]; // [C] 0x2F50E8 qmfc2 a2, vf5 (a, normalised second), 0x2F50F4 qmtc2 a2, vf1;
        // 0x2F50F8 vsub.xyz vf1, vf5, vf1 keeps a's w; 0x2F50FC sqc2 vf1, 0x10(v1) -- `a - b` took b's (the minuend's) w
        e[i].field_10.Normalise();
    }
    e[0].field_10 = func_002F5060_inl1(e[0].field_0, e[1].field_0, e[0].field_20, e[1].field_10);
    int k = self->field_964 - 1;
    e[k].field_10 = func_002F5060_inl1(e[k - 1].field_0, e[k].field_0, e[k - 1].field_20, e[k - 1].field_10);
    func_002F5060_inl2(self);
    func_002F5060_inl2(self);
    func_002F5060_inl2(self);
}
