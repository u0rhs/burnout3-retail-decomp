// NONMATCHING: func_00250160 -- retail 91 / ours 92 instructions, 21 in changed runs
// ghvu3: logic exact (sibling of proven func_001BEEE0: SetGtV3d/SetPlus, NGL stand-in); left: the w-lane copies (retail other@0x20/self@0x30 lwc1 off sp, 2nd copy via qmtc2 vf1 + sqc2; ours lane address in a register, 2nd copy from GPR), frame 0x90 vs 0x80, vmulx dest vf1 vs vf2 | N275 header APIs (gapK)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (ghvu3, Ghidra draft); the lifter refused it. Unlinks this object from its partner (field_2424, both
// ways); first, when this one's plus (w) is under a quarter of the partner's, takes a quarter of the partner's plus
// along field_C0 as its own xyz and renormalises field_C0 with the length as the new plus (or resets it to the body's
// at-row with plus 0 when the vector is tiny).
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;
// [L] N185: stands in for CGtV3dPlus::Plus() (B3O0PCH map, 52 bytes, as CGtV4d::W()): the w lane
static inline WAxisType func_00250160_inl1(const CGtV3dPlus &p) { return WAxisType(p.mData); }
struct UnkStruct_00250160 {
    unsigned char pad_0[0xB0];
    CGtV3dPlus field_B0;
    CGtV3d field_C0;
    unsigned char pad_D0[0x134];
    CGtMatrix3x4 *field_204;
    unsigned char pad_208[0x221C];
    UnkStruct_00250160 *field_2424;
    unsigned char field_2428;
};
// [L] N185: stands in for CGtV3d::NormaliseGetLength() as the proven sibling func_001BEEE0's (the header body with `.set noreorder`
// also inside the asm string: the separate-statement region leaves b119's hazard nops after the mtc1 and the mfc1, N217)
static inline XAxisType func_00250160_inl2(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 t, r;
    float f;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm(".set noreorder" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "qmfc2 %1, $vf1" "\n\t" "mtc1 %1, %2" "\n\t" "sqrt.s %2, %2" "\n\t" "mfc1 %1, %2" "\n\t"
        "qmtc2 %1, $vf1" "\n\t" "qmfc2 %1, $vf1" "\n\t" "vwaitq" "\n\t" "qmtc2 %3, $vf1" "\n\t" "vmulq.xyz $vf1, $vf1, $Q" "\n\t"
        "qmfc2 %0, $vf1" "\n\t" ".set reorder" : "=r"(t), "=&r"(r), "=&f"(f) : "r"(v.mData));
    asm(".set reorder");
    v.mData = t;
    return XAxisType(r);
}
// 0x00250160
extern "C" void func_00250160(UnkStruct_00250160 *self)
{
    self->field_2428 = 0;
    UnkStruct_00250160 *o = self->field_2424;
    if (o != 0) {
        if (func_00250160_inl1(self->field_B0) < 0.25f * (float)func_00250160_inl1(o->field_B0)) {  // [C] retail FPU form, not a VU lane op: 0x25019C / 0x2501C4 mul.s (the cast keeps the port's PS2 float model)
            CGtV3d v = self->field_C0 * (0.25f * (float)func_00250160_inl1(o->field_B0));  // [C] retail FPU form, not a VU lane op: 0x25019C / 0x2501C4 mul.s (the cast keeps the port's PS2 float model)
            self->field_B0.SetGtV3d(v);
            if (v.IsEffectivelyZero()) {
                self->field_B0.SetPlus(0.0f);
                self->field_C0 = self->field_204->mAt;
            } else {
                self->field_C0 = v;
                self->field_B0.SetPlus(func_00250160_inl2(self->field_C0));
            }
        }
        self->field_2424->field_2424 = 0;
        self->field_2424 = 0;
    }
}
