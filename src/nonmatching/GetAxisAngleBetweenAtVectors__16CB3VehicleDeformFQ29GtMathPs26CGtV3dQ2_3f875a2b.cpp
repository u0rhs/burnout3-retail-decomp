// NONMATCHING: GetAxisAngleBetweenAtVectors__16CB3VehicleDeformFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPf -- retail 227 / ours 227 instructions, 8 in changed runs
// retune1 (N239): N140 pad inside inl9 (static inline wrapper) restores frame 0xC0; 15 -> 8, only slot permutation left
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: GetAxisAngleBetweenAtVectors__16CB3VehicleDeformFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPf -- retail 227 / ours 227 instructions, 15 in changed runs
// pass3c: the old 5-off archive re-runs at 18 off (229 instrs) under today's header (N232/N234): inl3's in-place normalise got parked through a GPR. inl3 now runs vmulq.xyz "+j" outside any region and qmfc2.i in its own region (lst1 rule) -> 227/227, 15 off. Left: frame 0xB0 vs 0xC0 (retail has a dead slot at 0xA0) and the na/nb/axis/r slot order; a ctor/dtor N140 pad restores the frame but perturbs the GPRs (36-44 off).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_003E0780_pad { int x[4]; UnkStruct_003E0780_pad() {} ~UnkStruct_003E0780_pad() {} };

extern "C" float func_0011E328(float);

// [L] N185: XAxisType -> float without the address-taken read (as func_00287970_inl2).
static inline float func_003E0780_inl1(u_long128 x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x)); return f; }

// [L] N185: stands in for a missing GtMathPs2 inline (Normalise that also forms 1.0*Q, result unused; perhaps
// CGtV3d::NormaliseFast, B3O0PCH 188 bytes [G]); hard-coded $vf1 as the header's Normalise, result by value.
static inline u_long128 func_003E0780_inl2(CGtV3d &v)
{
    u_long128 l = v.GetSquaredLength().lVector;
    u_long128 r;
    u_long128 one;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2 %1, $vf1" "\n\t" "vwaitq" "\n\t"
        "qmtc2 %2, $vf1" "\n\t" "vmulq.xyz $vf1, $vf1, $Q" "\n\t" "qmfc2 %0, $vf1" "\n\t"
        "qmtc2 %1, $vf1" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2 %1, $vf1" : "=r"(r), "=&r"(one) : "r"(v.mData));
    asm(".set reorder");
    return r;
}

// [L] N185: in-place Normalise on the vector's compiler-chosen register, the result moved out .i (N190).
static inline void func_003E0780_inl3(CGtV3d &v)
{
    u_long128 l = v.GetSquaredLength().lVector;
    u_long128 t;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq");
    asm(".set reorder");
    asm("vmulq.xyz %0, %0, $Q" : "+j"(v.mData));
    asm(".set noreorder");
    asm("qmfc2.i %0, %1" : "=r"(t) : "j"(v.mData));
    asm(".set reorder");
    v.mData = t;
}

// [L] N185: CrossProduct with both operands moved in from GPRs (as func_00147EE0_inl1).
static inline u_long128 func_003E0780_inl4(u_long128 a, u_long128 b)
{
    u_long128 t;
    asm("qmtc2.i %0, $vf2" "\n\t" "qmtc2.i %1, $vf1" : : "r"(a), "r"(b));
    asm(".set noreorder");
    asm("vopmula.xyz $ACC, $vf2, $vf1" "\n\t" "vopmsub.xyz $vf1, $vf1, $vf2" "\n\t" "qmfc2.i %0, $vf1" : "=r"(t));
    asm(".set reorder");
    return t;
}
// [L] N185: DotProduct with both operands moved in from GPRs onto $vf2/$vf1.
static inline u_long128 func_003E0780_inl6(u_long128 a, u_long128 b)
{
    u_long128 m, one, t, d;
    asm("qmtc2 %1, $vf2" "\n\t" "qmtc2 %2, $vf1" "\n\t" "vmul.xyz %0, $vf2, $vf1" : "=j"(m) : "r"(a), "r"(b));
    asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));
    asm(".set noreorder");
    asm("vadday.x $ACC, %1, %1y" "\n\t" "vmaddz.x %0, %2, %1z" : "=j"(t) : "j"(m), "j"(one));
    asm(".set reorder");
    asm("qmfc2 %0, %1" : "=r"(d) : "j"(t));
    return d;
}
// [L] N185: the same dot product with every register hard-coded ($vf2/$vf1, the 1.0 parked in a GPR).
static inline u_long128 func_003E0780_inl8(u_long128 a, u_long128 b)
{
    u_long128 one, d;
    asm("qmtc2 %1, $vf2" "\n\t" "qmtc2 %2, $vf1" "\n\t" "vmul.xyz $vf2, $vf2, $vf1" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(one) : "r"(a), "r"(b));
    asm(".set noreorder");
    asm("vadday.x $ACC, $vf2, $vf2y" "\n\t" "qmtc2.i %1, $vf1" "\n\t" "vmaddz.x $vf1, $vf1, $vf2z" "\n\t" "qmfc2 %0, $vf1" : "=r"(d) : "r"(one));
    asm(".set reorder");
    return d;
}
// [L] N185: CosAngleBetweenNormalisedVectors on that dot product.
static inline u_long128 func_003E0780_inl7(u_long128 a, u_long128 b)
{
    XAxisType d(func_003E0780_inl6(a, b));
    u_long128 m;
    asm("vsubw.x %0, $vf0, $vf0w" : "=j"(m));
    asm("vmax.x %0, %0, %1" "\n\t" "vminiw.x %0, %0, $vf0w" : "+j"(d.lVector) : "j"(m));
    return d.lVector;
}

// [L] N185: GtMathPs2::AngleBetweenVectors(CGtV3d, CGtV3d, CGtV3d) (B3O0PCH map, 352 bytes) stand-in: the angle in degrees
// between a and b, signed by the side of axis [G body].
static inline float func_003E0780_inl5(CGtV3d &a, CGtV3d &b, u_long128 axis)
{
    u_long128 na = func_003E0780_inl2(a);
    u_long128 nb = func_003E0780_inl2(b);
    float ang = 57.29578f * func_0011E328(func_003E0780_inl1(func_003E0780_inl7(na, nb)));
    if (func_003E0780_inl1(func_003E0780_inl8(func_003E0780_inl4(na, nb), axis)) < 0.0f) return 360.0f - ang;
    return ang;
}
// [L] N185: CGtV3d::Normalise() (header body) without its locals (retail's frame has no slots for them).
static inline void func_003E0780_inl9(CGtV3d &v)
{
    UnkStruct_003E0780_pad pq;
    u_long128 l = v.GetSquaredLength().lVector;
    u_long128 r;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "qmtc2 %1, $vf1" "\n\t" "vmulq.xyz $vf1, $vf1, $Q" "\n\t" "qmfc2 %0, $vf1" : "=r"(r) : "r"(v.mData));
    asm(".set reorder");
    v.mData = r;
}

class CB3VehicleDeform {
public:
    CGtV3d GetAxisAngleBetweenAtVectors(CGtV3d a, CGtV3d b, float *angle);
};

// N182 [G] scoped to this function: opt_repositioncode off
#pragma push
#pragma opt_repositioncode off
// 0x003E0780
CGtV3d CB3VehicleDeform::GetAxisAngleBetweenAtVectors(CGtV3d a, CGtV3d b, float *angle)
{
    CGtV3d nb = b;
    CGtV3d na;
    CGtV3d axis;
    float l;
    if (func_003E0780_inl1(a.GetSquaredLength().lVector) >= 2.3283064e-10f && func_003E0780_inl1(nb.GetSquaredLength().lVector) >= 2.3283064e-10f) {
        na = a;
        func_003E0780_inl3(na);
        func_003E0780_inl3(nb);
        axis = CGtV3d(func_003E0780_inl4(na.mData, nb.mData));
        l = func_003E0780_inl1(axis.GetSquaredLength().lVector);
    } else {
        *angle = 0.0f;
        axis.Set(0.0f, 1.0f, 0.0f);
        return axis;
    }
    if (l < 2.3283064e-10f) axis.Set(0.0f, 1.0f, 0.0f);
    func_003E0780_inl9(axis);
    CGtV3d r = axis;
    float ang = func_003E0780_inl5(na, nb, r.mData);
    *angle = ang;
    if (ang >= 180.0f) goto wrap;
ret:
    return r;
wrap:
    *angle = ang - 360.0f;
    goto ret;
}
#pragma pop
