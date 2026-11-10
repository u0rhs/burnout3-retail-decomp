// NONMATCHING: func_001D0930 -- retail 86 / ours 88 instructions, 19 in changed runs
// ghvu3: logic exact (impulse: header DotProduct/TransformVector/operator-, [L] N185 CrossProduct with fresh dest + XAxisType+float stand-ins); left: XAxisType*float / +float scalar-vs-value VU regs swapped, 2nd DotProduct keeps an m GPR round trip retail lacks, frame 0x70 vs 0xB0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (ghvu3, Ghidra draft); the lifter refused it. A collision impulse [G]: j = -(1 + e) * (v . n) /
// (n . ((I * (r x n)) x r) + 1 / m), r = p - body position; *out = n * |j|; returns j.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
extern "C" float fabsf(float);
struct UnkStruct_001D0930_b { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_001D0930 {
    unsigned char pad_0[0x30];
    CGtMatrix3x4 field_30;
    unsigned char pad_70[0x44];
    float field_B4;
    UnkStruct_001D0930_b *field_B8;
};
// [L] N185: stands in for GtMathPs2::CrossProduct with a compiler-chosen result register (retail `vopmula.xyz $ACC, a, b;
// vopmsub.xyz d, b, a` with d a fresh register or a's), result moved out .i (vu0_ni_fixup restores .ni)
static inline CGtV3d func_001D0930_inl1(CGtV3d a, CGtV3d b)
{
    u_long128 t, r;
    asm("vopmula.xyz $ACC, %1, %2" "\n\t" "vopmsub.xyz %0, %2, %1" : "=j"(t) : "j"(a.mData), "j"(b.mData));
    asm("qmfc2.i %0, %1" : "=r"(r) : "j"(t));
    return CGtV3d(r);
}
// [L] N185: stands in for GtMathPs2::operator+(XAxisType, float) (B3O0PCH map, 80 bytes): as the header's operator*(XAxisType, float)
static inline XAxisType func_001D0930_inl2(XAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vaddx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return XAxisType(r); }
// 0x001D0930
extern "C" float func_001D0930(float e, UnkStruct_001D0930 *body, const CGtV3d &p0, const CGtV3d &v, const CGtV3d &n0, CGtV3d *out)
{
    CGtV3d n = n0;
    CGtV3d p = p0;
    float num = DotProduct(n, v) * -(1.0f + e);
    CGtV3d r = p - body->field_B8->field_30;
    CGtV3d c = func_001D0930_inl1(r, n);
    CGtV3d t = TransformVector(body->field_30, c);
    CGtV3d c2 = func_001D0930_inl1(t, r);
    float den = func_001D0930_inl2(DotProduct(c2, n), 1.0f / body->field_B4);
    float j = num / den;
    *out = n * fabsf(j);
    return j;
}
