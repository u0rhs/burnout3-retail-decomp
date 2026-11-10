// NONMATCHING: func_002F0440 -- retail 127 / ours 127 instructions, 17 in changed runs
// mat1 (N239): real CGtMatrix3x4 types replace the char[16] stand-ins: product through an out-param stand-in into p, then u = p (row-0 sq + three lb/sb loops), t = u (4-quad block copy; t passed by const& = sp+0xE0), 3 N140 pads, frame exact. Left 17: retail loads b2 first and reuses its register for row 0's result (ours loads a0 first, result in b1's register); 23 operand orders, split-asm (hdr16 opmul) and local-row forms tried
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

// [G] the matrix by reference: retail passes sp+0xE0, a local filled by a 4-quad block copy (N239 staging: product temp ->
// u by row-0 sq + three lb/sb loops -> t by lq/sq loop, the shape of `u = prod; t = u;` with t address-taken; mat1 probe m5 f23)
extern "C" bool func_002F0640(void * p0, void * p1, const CGtMatrix3x4 & m, void * p3, CGtV3d * o1, CGtV3d * o2);

// [L] N185: CGtMatrix3x4::operator*(const CGtMatrix3x4&) (B3O0PCH map, 340 bytes) stand-in, returned by value
static inline void v256_mul(CGtMatrix3x4 & r, const CGtMatrix3x4 & a, const CGtMatrix3x4 & b)
{

    asm("qmtc2.i %0, $vf4" "\n\t" "qmtc2.i %3, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "qmtc2.i %1, $vf3" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "qmtc2.i %2, $vf2" : : "r"(b.mRight.mData), "r"(b.mUp.mData), "r"(b.mAt.mData), "r"(a.mRight.mData));
    asm("vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mRight.mData));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mUp.mData) : "r"(a.mUp.mData));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mAt.mData) : "r"(a.mAt.mData));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddaz.xyz $ACC, $vf2, $vf1z" "\n\t" "qmtc2.i %2, $vf1" "\n\t" "vmaddw.xyz $vf1, $vf1, $vf0w" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mPos.mData) : "r"(a.mPos.mData), "r"(b.mPos.mData));
}
// [L] N185: TransformPoint with the point listed first (v241)
static inline CGtV3d v256_xform(const CGtMatrix3x4& m, CGtV3d v) {
    u_long128 t;
    asm("vmulax.xyz $ACC, %2, %1x" "\n\t" "qmtc2.i %3, $vf1" "\n\t" "vmadday.xyz $ACC, $vf1, %1y" "\n\t" "qmtc2.i %4, $vf1" "\n\t"
        "vmaddaz.xyz $ACC, $vf1, %1z" "\n\t" "qmtc2.i %5, $vf1" "\n\t" "vmaddw.xyz $vf1, $vf1, $vf0w" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(t) : "j"(v.mData), "j"(m.mRight.mData), "r"(m.mUp.mData), "r"(m.mAt.mData), "r"(m.mPos.mData));
    return CGtV3d(t);
}
// [L] N185: TransformVector(const CGtMatrix3x4&, CGtV3d) (B3O0PCH map, 100 bytes) stand-in, point first


struct UnkStruct_002F0440_pad { int x[4]; UnkStruct_002F0440_pad() {} ~UnkStruct_002F0440_pad() {} };
// 0x002F0440
extern "C" bool func_002F0440(void * p0, const CGtMatrix3x4 * a, void * p2, const CGtMatrix3x4 * m, const CGtMatrix3x4 * b,
    void * p5, CGtV3d * o1, CGtV3d * o2)
{
    UnkStruct_002F0440_pad pad0;
    CGtMatrix3x4 t;
    CGtMatrix3x4 u;
    UnkStruct_002F0440_pad pad1;
    UnkStruct_002F0440_pad pad2;
    CGtMatrix3x4 p;
    v256_mul(p, *a, *b);
    u = p;
    t = u;
    bool r = func_002F0640(p0, p2, t, p5, o1, o2);
    if (o1) *o1 = v256_xform(*m, *o1);
    if (o2) *o2 = TransformVector(*m, *o2);
    return r;
}






