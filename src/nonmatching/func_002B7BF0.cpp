// NONMATCHING: func_002B7BF0 -- retail 111 / ours 113 instructions, 28 in changed runs
// ghvu5: logic complete ([L] DNAT GetHullPenetration). Left (28): the plane row is loaded once into a GPR (lq; qmtc2 for the dot; sq for the Distance() W copy) where retail loads it into VU (lqc2) and folds the W copy to sqc2 -- the WAxisType copy ctor's "r" operand wins (const& dot stand-in, plane local, Normal() local tried); cur's in-loop load numbered late (ours vf2, retail vf7); frame 0x180 vs 0x130 (5 extra temp slots).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_002B7BF0 -- hand-written (ghvu5, Ghidra draft). Unnamed: placeholder with C linkage.
// [L] DNAT: CB3ConvexHullCollide::GetHullPenetration(int*, unsigned char, CB3ConvexHullPlane*, GtMathPs2::CGtPlane*,
// GtMathPs2::CGtV3d, GtMathPs2::CGtV3d, ...) (research/proto/new_names.csv, low). a2 is not read.
// [G] walks a point from pos + dir*100 back towards pos through the planes; returns the penetration depth (min 0.005).
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;
// [L] N185: stands in for a missing GtMathPs2 inline -- operator-(WAxisType, float) (as the header's YAxisType one)
static inline WAxisType func_002B7BF0_inl1(WAxisType a, float f)
{
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vsubx.w %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s));
    return WAxisType(r);
}
// [L] N185: CGtV3d subtraction on compiler-chosen registers (retail vsub.xyz $vf1,$vf7,$vf5 / $vf1,$vf3,$vf2)
static inline CGtV3d func_002B7BF0_inl2(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
static inline CGtV3d func_002B7BF0_inl3(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vadd.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
// 0x002B7BF0
extern "C" float func_002B7BF0(int *out, unsigned char n, void *hull, CGtPlane *planes, CGtV3d pos, CGtV3d dir)
{
    CGtV3d p = pos;
    float d[44];
    CGtV3d cur = dir * 100.0f;
    cur += p;
    *out = -1;
    for (int i = 0; i < n; i++) {
        d[i] = DotProduct(cur, planes[i].Normal());
        if (!(d[i] < planes[i].Distance())) {
            *out = i;
            float e = DotProduct(p, planes[i].Normal());
            if (!(e < planes[i].Distance())) return 0.005f;
            float diff = d[i] - e;
            if (!(GtMath::Abs(diff) <= 0.0001f)) {
                CGtV3d v = func_002B7BF0_inl2(cur, p);
                float t = func_002B7BF0_inl1(planes[i].Distance(), e) / diff;
                cur = func_002B7BF0_inl3(p, v * t);
            }
        }
    }
    if (*out < 0) {
        *out = 0;
        return 0.005f;
    }
    float len = func_002B7BF0_inl2(p, cur).GetLength();
    if (len < 0.005f) len = 0.005f;
    return len;
}

