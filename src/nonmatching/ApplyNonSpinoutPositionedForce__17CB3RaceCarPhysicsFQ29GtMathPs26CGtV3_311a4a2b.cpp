// NONMATCHING: ApplyNonSpinoutPositionedForce__17CB3RaceCarPhysicsFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d -- retail 75 / ours 70 instructions, 96 in changed runs
// a215: twin of Impulse (lin 0xF0, ang 0x100, krSpinForceThreshold); same gaps, retail frame 0x140
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
static inline float fabsf(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
struct UnkStruct_001BEAA0_body { unsigned char pad_0[0x30]; CGtV3d field_30; };
extern float krSpinForceThreshold;
static inline float func_001BEAA0_inl0(float x) {
    union { float f; unsigned int u; } a, b;
    a.f = x;
    b.u = (a.u & 0x80000000) | 0x3F800000;
    return b.f;
}
class CB3RaceCarPhysics {
public:
    void ApplyNonSpinoutPositionedForce(CGtV3d, CGtV3d);
    unsigned char pad_0[0xD0];
    CGtV3d field_D0;
    unsigned char pad_E0[0x10];
    CGtV3d field_lin;
    CGtV3d field_ang;
    unsigned char pad_x[0xf4];
    UnkStruct_001BEAA0_body * field_204;
    unsigned char pad_208[0x131C];
    int field_1524;
};
void CB3RaceCarPhysics::ApplyNonSpinoutPositionedForce(CGtV3d p, CGtV3d f) {
    CGtV3d r = p - field_204->field_30;
    CGtV3d t = CrossProduct(r, f);
    int c = 0;
    if ((unsigned)(field_1524 - 1) < 2) c = 1;
    else { float dy = field_D0.Y(); if (!(fabsf(dy) <= krSpinForceThreshold)) { float s1 = func_001BEAA0_inl0(dy); float s2 = func_001BEAA0_inl0(t.Y()); if (s1 == s2) c = 1; } }
    if (c) {
        field_lin += f; // [C] w = field_lin.w: 0x1BECA4..0x1BECB4 lqc2 vf2 this+0xF0, vadd.xyz vf2, vf2, vf1, sqc2 vf2 (`a + b` took f's w)
    } else {
        field_lin += f; // [C] w = field_lin.w: 0x1BECB8..0x1BECC8, vadd.xyz vf1, vf1, vf3 into field_lin's register
        CGtV3d r2 = p - field_204->field_30;
        field_ang += CrossProduct(r2, f); // [C] w = field_ang.w: 0x1BECE4..0x1BECF0 lqc2 vf2 this+0x100, vadd.xyz vf2, vf2, vf1, sqc2 vf2
    }
}
