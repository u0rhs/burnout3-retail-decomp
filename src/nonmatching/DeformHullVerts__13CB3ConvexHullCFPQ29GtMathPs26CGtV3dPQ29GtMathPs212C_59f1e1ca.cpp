// NONMATCHING: DeformHullVerts__13CB3ConvexHullCFPQ29GtMathPs26CGtV3dPQ29GtMathPs212CGtMatrix3x4 -- retail 171 / ours 171 instructions, 26 in changed runs
// v287: logic/frame/length exact; 26 off wibo = t-register ties only (count t2 vs t5 shifting acc-row pointers, w pointer s1 vs t9); wine host 7 off. Local stand-ins: compiler-chosen Zero, TransformPoint with chosen work reg in noreorder, SetIdentity with pos row zeroed last
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3ConvexHull::DeformHullVerts(GtMathPs2::CGtV3d*,GtMathPs2::CGtMatrix3x4*) const
// [C] name: research/retail_names.csv 0x2BA0F0 -> B3ConvexHull.cpp. Fields are placeholders, types [G] (instruction widths).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_002BA0F0_w {       // 12 bytes per vertex: two bone weights, two bone indices [G]
    float field_0[2];
    unsigned char field_8[2];
    unsigned char pad_A[2];
};
class CB3ConvexHull {
public:
    bool DeformHullVerts(CGtV3d *, CGtMatrix3x4 *) const;
    int field_0;
    int field_4;
    CGtV3d *field_8;
    int field_C;
    UnkStruct_002BA0F0_w *field_10;
    int field_14;
    unsigned char field_18;
};
// [L] N185 stand-in: CGtV3d::Zero() on a compiler-chosen register
static inline void func_002BA0F0_inl1(CGtV3d &v) { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); v.mData = r; }
// [L] N185 stand-in: TransformPoint(const CGtMatrix3x4&, CGtV3d) with a compiler-chosen work register (retail $vf5 here)
static inline CGtV3d func_002BA0F0_inl2(const CGtMatrix3x4 &m, CGtV3d v)
{
    u_long128 t, w;
    asm(".set noreorder");
    asm("vmulax.xyz $ACC, %2, %3x" "\n\t" "qmtc2.i %4, %1" "\n\t" "vmadday.xyz $ACC, %1, %3y" "\n\t" "qmtc2.i %5, %1" "\n\t"
        "vmaddaz.xyz $ACC, %1, %3z" "\n\t" "qmtc2.i %6, %1" "\n\t" "vmaddw.xyz %1, %1, $vf0w" "\n\t" "qmfc2.i %0, %1"
        : "=r"(t), "=&j"(w) : "j"(m.mRight.mData), "j"(v.mData), "r"(m.mUp.mData), "r"(m.mAt.mData), "r"(m.mPos.mData));
    asm(".set reorder");
    return CGtV3d(t);
}
struct UnkStruct_002BA0F0_pad { int x[0x44]; UnkStruct_002BA0F0_pad() {} ~UnkStruct_002BA0F0_pad() {} };   // N140 pad: 17 dead 16-byte inline temp slots
// [L] N185 stand-in: CGtMatrix3x4::SetIdentity() (row order probe)
static inline void func_002BA0F0_inl4(CGtMatrix3x4 &m)
{
    { u_long128 q; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(q)); m.mRight.mData = q; }
    { u_long128 q; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(q)); m.mUp.mData = q; }
    { u_long128 q; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(q)); m.mAt.mData = q; }
    { u_long128 q = m.mRight.mData; asm("vaddw.x %0, $vf0, $vf0w" : "+j"(q)); m.mRight.mData = q; }
    { u_long128 q = m.mUp.mData; asm("vaddw.y %0, $vf0, $vf0w" : "+j"(q)); m.mUp.mData = q; }
    { u_long128 q = m.mAt.mData; asm("vaddw.z %0, $vf0, $vf0w" : "+j"(q)); m.mAt.mData = q; }
    { u_long128 q; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(q)); m.mPos.mData = q; }
}
// 0x002BA0F0
bool CB3ConvexHull::DeformHullVerts(CGtV3d *out, CGtMatrix3x4 *mats) const
{
    if (!(field_14 & 2))
        return false;
    CGtMatrix3x4 m;
    CGtMatrix3x4 acc;
    CGtMatrix3x4 ident;
    UnkStruct_002BA0F0_pad pad;
    func_002BA0F0_inl4(ident);
    for (unsigned char i = 0; i < field_18; i++) {
        func_002BA0F0_inl1(acc.mRight);
        func_002BA0F0_inl1(acc.mUp);
        func_002BA0F0_inl1(acc.mAt);
        func_002BA0F0_inl1(acc.mPos);
        const UnkStruct_002BA0F0_w &wt = field_10[i];
        float sum = 0.0f;
        unsigned int j = 0;
        goto test;
    top:
        {
            float w = wt.field_0[j];
            sum += w;
            m = mats[wt.field_8[j]];
            acc.mRight += m.mRight * w;
            acc.mUp += m.mUp * w;
            acc.mAt += m.mAt * w;
            acc.mPos += m.mPos * w;
        }
        j++;
    test:
        if (j < 2) goto top;
        float r = 1.0f - sum;
        acc.mRight += ident.mRight * r;
        acc.mUp += ident.mUp * r;
        acc.mAt += ident.mAt * r;
        acc.mPos += ident.mPos * r;
        out[i] = func_002BA0F0_inl2(acc, field_8[i]);
    }
    return true;
}
