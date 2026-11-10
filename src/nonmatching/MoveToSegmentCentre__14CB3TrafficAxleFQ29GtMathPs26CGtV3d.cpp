// NONMATCHING: MoveToSegmentCentre__14CB3TrafficAxleFQ29GtMathPs26CGtV3d -- retail 101 / ours 101 instructions, 25 in changed runs
// repair1: header DotProduct/GetLength/operator*(float)/operator-=/SetGtV3d, compiler-chosen vadd (operands listed b,a)/vsub/Normalise stand-ins func_0015F270_inl1-3, one || early-return chain, p copied first (retail's early lq), field_0 read through a const ref; left: VU numbering only (0.5 on vf6 vs retail vf5, everything after shifted by one; dir moved to vf2 for DotProduct)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// [G] a - b / a + b with compiler-chosen VU registers (retail `vsub.xyz $vf4,$vf4,$vf3`, `vadd.xyz $vf3,$vf4,$vf3`); the
// header's binary operators hard-code $vf1/$vf2 inputs
static inline CGtV3d func_0015F270_inl1(const CGtV3d& a, const CGtV3d& b)
{
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
static inline CGtV3d func_0015F270_inl2(const CGtV3d& a, const CGtV3d& b)
{
    u_long128 r;
    asm("vadd.xyz %0, %2, %1" : "=j"(r) : "j"(b.mData), "j"(a.mData));
    return CGtV3d(r);
}
// [G] CGtV3d::Normalise inlined with the vector kept on its own VU register (retail `vmulq.xyz $vf4,$vf4,$Q`)
static inline void func_0015F270_inl3(CGtV3d& v)
{
    XAxisType l = v.GetSquaredLength();
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(v.mData));
    asm(".set reorder");
}
class CB3TrafficAxle {
public:
    void MoveToSegmentCentre(CGtV3d p);
    CGtV3dPlus field_0;
    unsigned char pad_10[0x10];
    unsigned short field_20;
    unsigned short field_22;
    unsigned short field_24;
    unsigned short field_26;
    CGtV3d * field_28;
};

// 0x0015F270
void CB3TrafficAxle::MoveToSegmentCentre(CGtV3d p)
{
    CGtV3d q = p;
    if (field_20 == 0xFFFF || field_22 == 0xFFFF || field_24 == 0xFFFF || field_26 == 0xFFFF) return;
    CGtV3d * pts = field_28;
    const CGtV3d& pos = *(const CGtV3d*)&field_0;
    CGtV3d m23 = func_0015F270_inl2(pts[field_24], pts[field_26]) * 0.5f;
    CGtV3d m01 = func_0015F270_inl2(pts[field_20], pts[field_22]) * 0.5f;
    CGtV3d dir = m23;
    dir -= m01;
    func_0015F270_inl3(dir);
    CGtV3d rel = func_0015F270_inl1(pos, m01);
    float d = DotProduct(dir, rel);
    CGtV3d pc = func_0015F270_inl2(m01, dir * d);
    float len = func_0015F270_inl1(pos, q).GetLength();
    CGtV3d dir2 = func_0015F270_inl1(pc, q);
    func_0015F270_inl3(dir2);
    CGtV3d r = func_0015F270_inl2(q, dir2 * len);
    field_0.SetGtV3d(r);
}
