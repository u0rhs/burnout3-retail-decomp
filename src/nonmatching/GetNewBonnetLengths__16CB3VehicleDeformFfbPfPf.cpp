// NONMATCHING: GetNewBonnetLengths__16CB3VehicleDeformFfbPfPf -- retail 284 / ours 280 instructions, 95 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: v300: logic complete (GetFlyingObjectIndex x2 inlined, in-place Normalise+1/len tail stand-in, clamp/acos angle, cross+dot sign, midpoints, TransformPoint x2, -= pos, flag SetZ as goto block). Left: VU register numbering (normalise vf4/vf3 vs retail vf3/vf2 once hard cross is used), mid/TransformPoi
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3VehicleDeform::GetNewBonnetLengths(float,bool,float*,float*) -- hand-written (v300); the lifter refused it.
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3VehicleDeform.cpp.
// Area not evidenced, so _unclassified/. Field names are placeholders; every type is [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

extern CGtV3d D_004CAD80;
extern "C" float func_0011E328(float);

struct UnkStruct_003E4BD0_pr { CGtV3d a; unsigned char pad_10[0x30]; CGtV3d b; unsigned char pad_50[0x30]; };
struct UnkStruct_003E4BD0_bn {
    unsigned char pad_0[0x180];
    CGtMatrix3x4 field_180[1];
};
struct UnkStruct_003E4BD0_b2 {
    unsigned char pad_0[0xC30];
    UnkStruct_003E4BD0_pr field_C30[1];
};
struct UnkStruct_003E4BD0_b4 {
    unsigned char pad_0[0x4B2];
    signed char field_4B2[1];
};
struct UnkStruct_003E4BD0_d {
    unsigned char pad_0[0xC];
    signed char field_C;
    unsigned char pad_D[0x2A0 - 0xD];
    UnkStruct_003E4BD0_pr field_2A0[1];
};
struct UnkStruct_003E4BD0_d2 { unsigned char pad_0[0xAC4]; int field_AC4[1]; };
struct UnkStruct_003E4BD0_d3 { unsigned char pad_0[0xD00]; CGtMatrix3x4 field_D00[1]; };

// [L] CB3VehicleDeform::GetFlyingObjectIndex (0x3E7600, proven) inlined
static inline int func_003E4BD0_inl1(UnkStruct_003E4BD0_d *d, int p0)
{
    int i;
    for (i = 0; i < d->field_C; i++) {
        if (p0 == ((UnkStruct_003E4BD0_d2 *)d)->field_AC4[i]) return i;
    }
    return -1;
}
// [L] N185: stands in for a missing GtMathPs2 inline (clamp of a lane to [-1, 1])
static inline XAxisType func_003E4BD0_inl2(XAxisType a)
{
    u_long128 m;
    asm("vsubw.x %0, $vf0, $vf0w" : "=j"(m));
    asm("vmax.x %0, %0, %1" : "+j"(a.lVector) : "j"(m));
    asm("vminiw.x %0, %0, $vf0w" : "+j"(a.lVector));
    return a;
}
// [L] N185: Normalise in place on a compiler-chosen register, with the 1.0 * Q tail (retail's second Normalise shape, N214)
static inline void func_003E4BD0_inl4(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 t, one, r;
    asm(".set noreorder");
    asm("qmtc2.i %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %1, $vf1" "\n\t" "vwaitq" "\n\t"
        "vmulq.xyz %3, %3, $Q" "\n\t" "qmtc2.i %1, $vf1" "\n\t" "qmfc2.i %0, %3" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %2, $vf1"
        : "=r"(t), "=&r"(one), "=&r"(r), "+j"(v.mData));
    asm(".set reorder");
    v.mData = t;
}
// [L] N185: CrossProduct with the result moved out .i (N188)
static inline CGtV3d func_003E4BD0_inl5(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b.mData) : "j"(a.mData));
    return CGtV3d(t);
}
static inline bool func_003E4BD0_inl6(float x) { return (*(unsigned int *)&x & 0x7F800000) <= 0x37800000; }
// [L] N185: clamp, one statement
static inline XAxisType func_003E4BD0_inl7(XAxisType a)
{
    u_long128 m;
    asm("vsubw.x %1, $vf0, $vf0w" "\n\t" "vmax.x %0, %0, %1" : "+j"(a.lVector), "=&j"(m));
    asm("vminiw.x %0, %0, $vf0w" : "+j"(a.lVector));
    return a;
}
// [L] N185: clamp to [-1, 1], hard-coded registers
static inline XAxisType func_003E4BD0_inl8(XAxisType a)
{
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "vsubw.x $vf2, $vf0, $vf0w" "\n\t" "vmax.x $vf1, $vf1, $vf2" "\n\t" "vminiw.x $vf1, $vf1, $vf0w" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(a.lVector));
    return XAxisType(t);
}
// [L] N185: cross product, hard-coded registers
static inline CGtV3d func_003E4BD0_inl9(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("qmtc2 %1, $vf2" "\n\t" "qmtc2 %2, $vf1" "\n\t" "vopmula.xyz $ACC, $vf2, $vf1" "\n\t" "vopmsub.xyz $vf1, $vf1, $vf2" "\n\t" "qmfc2.i %0, $vf1" : "=r"(t) : "r"(a.mData), "r"(b.mData));
    return CGtV3d(t);
}
// [L] N185: compiler-chosen a + b
static inline CGtV3d func_003E4BD0_inla(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 t;
    asm("vadd.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(t);
}
// [L] N185: ZAxisType - ZAxisType
static inline ZAxisType func_003E4BD0_inl3(ZAxisType a, ZAxisType b)
{
    u_long128 r;
    asm("vsubz.z %0, %1, %2z" : "=j"(r) : "j"(a.lVector), "j"(b.lVector));
    return ZAxisType(r);
}

class CB3VehicleDeform {
public:
    float GetNewBonnetLengths(float p0, bool p1, float *p2, float *p3);
    unsigned char pad_0[0x14];
    void *field_14;
    UnkStruct_003E4BD0_d *field_18;
};

// 0x003E4BD0
float CB3VehicleDeform::GetNewBonnetLengths(float p0, bool p1, float *p2, float *p3)
{
    int bon = func_003E4BD0_inl1(field_18, 4);
    int bmp = func_003E4BD0_inl1(field_18, 2);
    if (bon < 0 || bmp < 0) return 0.0f;
    if (((UnkStruct_003E4BD0_b4 *)(bon + (char *)field_14))->field_4B2[0] == 3) return 0.0f;
    CGtV3d up = D_004CAD80;
    CGtV3d b = ((UnkStruct_003E4BD0_bn *)field_14)->field_180[bmp].mRight;
    CGtV3d a = ((UnkStruct_003E4BD0_d3 *)field_18)->field_D00[bmp].mRight;
    func_003E4BD0_inl4(a);
    func_003E4BD0_inl4(b);
    float ang = 57.29578f * func_0011E328(func_003E4BD0_inl2(DotProduct(a, b)));
    CGtV3d c = func_003E4BD0_inl9(a, b);
    if (DotProduct(c, up) < 0.0f) ang = 360.0f - ang;
    *p3 = ang;
    UnkStruct_003E4BD0_pr &q = ((UnkStruct_003E4BD0_b2 *)field_14)->field_C30[bmp];
    CGtV3d m1 = func_003E4BD0_inla(q.a, q.b) * 0.5f;
    UnkStruct_003E4BD0_pr &r = field_18->field_2A0[bmp];
    CGtV3d m2 = func_003E4BD0_inla(r.a, r.b) * 0.5f;
    CGtV3d d1 = TransformPoint(((UnkStruct_003E4BD0_bn *)field_14)->field_180[bmp], m1);
    CGtV3d d2 = TransformPoint(((UnkStruct_003E4BD0_d3 *)field_18)->field_D00[bmp], m2);
    CGtV3d pos = ((UnkStruct_003E4BD0_bn *)field_14)->field_180[bon].mPos;
    d1 -= pos;
    d2 -= pos;
    if (p1) goto flag;
back:
    *p2 = func_003E4BD0_inl3(d2.Z(), d1.Z());
    XAxisType l2 = d2.GetLength();
    float f2 = l2;
    if (((unsigned long)l2.lVector & 0x7F800000) <= 0x37800000) return 0.0f;
    return (float)(d1.GetLength() * p0) / f2;
flag:
    d1.SetZ(d1.Z() * 0.9f);
    goto back;
}
