// NONMATCHING: ScaleAndFillInHullDetails__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d -- retail 145 / ours 145 instructions, 17 in changed runs
// repair1: header CGtV3d::Set(X,Y,Z) with temporaries (z evaluated first, no Y/Z copy-ctor stack slots), DotProduct, SetNormal/SetDistance(XAxisType); lane ops/vsub/cross/Normalise as compiler-chosen stand-ins func_002BA7A0_inl1-12; a/b copied to locals (retail's lq+qmtc2); p0,p2,p1 by-value copies; edge loop as a goto loop with out-of-line add blocks and a>b compares; left: VU numbering in the scale loop (a vf3 vs retail vf7, temps vf5 vs vf1) and the cross result lands on b's register (vf4; retail vf1 then qmfc2/qmtc2 to vf4)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// [L] N185 stand-ins: lane-wise XAxisType/YAxisType/ZAxisType arithmetic on compiler-chosen registers, result in a fresh register
// (B3O0PCH map names operator-/+/*(X/Y/ZAxisType, ...); retail `vsubz.z $vf8,$vf1,$vf7z`, `vmuly.y $vf1,$vf6,$vf4y`, `vaddy.y $vf3,$vf7,$vf1y`)
static inline XAxisType func_002BA7A0_inl1(const XAxisType& a, const XAxisType& b) { u_long128 r; asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return XAxisType(r); }
static inline YAxisType func_002BA7A0_inl2(const YAxisType& a, const YAxisType& b) { u_long128 r; asm("vsuby.y %0, %1, %2y" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return YAxisType(r); }
static inline ZAxisType func_002BA7A0_inl3(const ZAxisType& a, const ZAxisType& b) { u_long128 r; asm("vsubz.z %0, %1, %2z" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return ZAxisType(r); }
static inline XAxisType func_002BA7A0_inl4(const XAxisType& a, const XAxisType& b) { u_long128 r; asm("vmulx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return XAxisType(r); }
static inline YAxisType func_002BA7A0_inl5(const YAxisType& a, const YAxisType& b) { u_long128 r; asm("vmuly.y %0, %1, %2y" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return YAxisType(r); }
static inline ZAxisType func_002BA7A0_inl6(const ZAxisType& a, const ZAxisType& b) { u_long128 r; asm("vmulz.z %0, %1, %2z" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return ZAxisType(r); }
static inline XAxisType func_002BA7A0_inl7(const XAxisType& a, const XAxisType& b) { u_long128 r; asm("vaddx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return XAxisType(r); }
static inline YAxisType func_002BA7A0_inl8(const YAxisType& a, const YAxisType& b) { u_long128 r; asm("vaddy.y %0, %1, %2y" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return YAxisType(r); }
static inline ZAxisType func_002BA7A0_inl9(const ZAxisType& a, const ZAxisType& b) { u_long128 r; asm("vaddz.z %0, %1, %2z" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return ZAxisType(r); }
// [G] a - b on compiler-chosen registers (retail `vsub.xyz $vf4,$vf4,$vf3`; the header's binary operator- hard-codes $vf1/$vf2)
static inline CGtV3d func_002BA7A0_inl10(const CGtV3d& a, const CGtV3d& b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
// [G] CrossProduct with the result on a's register (retail `vopmula.xyz $ACC,$vf1,$vf4; vopmsub.xyz $vf1,$vf4,$vf1`)
static inline CGtV3d func_002BA7A0_inl11(CGtV3d a, CGtV3d b)
{
    u_long128 r, t;
    asm("vopmula.xyz $ACC, %1, %2" "\n\t" "vopmsub.xyz %0, %2, %1" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    asm("qmfc2 %0, %1" : "=r"(t) : "j"(r));
    return CGtV3d(t);
}
// [G] CGtV3d::Normalise inlined with the vector kept on its own VU register (retail `vmulq.xyz $vf4,$vf4,$Q`)
static inline void func_002BA7A0_inl12(CGtV3d& v)
{
    XAxisType l = v.GetSquaredLength();
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(v.mData));
    asm(".set reorder");
}
struct CB3ConvexHull {
    unsigned char (*field_0)[3];
    CGtPlane *field_4;
    CGtV3d *field_8;
    unsigned char (*field_C)[2];
    int field_10;
    int field_14;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
    void ScaleAndFillInHullDetails(CGtV3d a, CGtV3d b);
};
// 0x002BA7A0
void CB3ConvexHull::ScaleAndFillInHullDetails(CGtV3d a, CGtV3d b)
{
    CGtV3d ca = a;
    CGtV3d cb = b;
    field_14 = 0;
    for (int k = 0; k < field_18; k++) {
        CGtV3d &v = field_8[k];
        v.Set(func_002BA7A0_inl7(ca.X(), func_002BA7A0_inl4(v.X(), func_002BA7A0_inl1(cb.X(), ca.X()))),
              func_002BA7A0_inl8(ca.Y(), func_002BA7A0_inl5(v.Y(), func_002BA7A0_inl2(cb.Y(), ca.Y()))),
              func_002BA7A0_inl9(ca.Z(), func_002BA7A0_inl6(v.Z(), func_002BA7A0_inl3(cb.Z(), ca.Z()))));
    }
    for (int i = 0; i < field_19; i++) {
        CGtV3d *vt = field_8;
        unsigned char *t = field_0[i];
        CGtV3d p0 = vt[t[0]];
        CGtV3d p2 = vt[t[2]];
        CGtV3d p1 = vt[t[1]];
        CGtV3d n = func_002BA7A0_inl11(func_002BA7A0_inl10(p1, p0), func_002BA7A0_inl10(p2, p0));
        func_002BA7A0_inl12(n);
        XAxisType d = DotProduct(p0, n);
        field_4[i].SetNormal(n);
        field_4[i].SetDistance(d);
    }
    field_1A = 0;
    int i = 0;
    int a0, b0, c0;
    goto test;
body:
    {
        unsigned char *t = field_0[i];
        a0 = t[0]; b0 = t[1]; c0 = t[2];
    }
    if (a0 > b0) goto ea;
la: if (b0 > c0) goto eb;
lb: if (c0 > a0) goto ec;
inc: i++;
test: if (i < field_19) goto body;
    return;
ea: { int n = field_1A; field_1A = n + 1; unsigned char *e = field_C[n]; e[0] = a0; e[1] = b0; } goto la;
eb: { int n = field_1A; field_1A = n + 1; unsigned char *e = field_C[n]; e[0] = b0; e[1] = c0; } goto lb;
ec: { int n = field_1A; field_1A = n + 1; unsigned char *e = field_C[n]; e[0] = c0; e[1] = a0; } goto inc;
}
