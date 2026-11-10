// NONMATCHING: NearestPointOnTriangle__16CB3VehicleDeformFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dfPQ29GtMathPs26CGtV3d -- retail 189 / ours 196 instructions, 171 in changed runs
// ghvu11 first draft: logic believed right (centroid, plane distance, edge select via cross/dot signs, edge clamp, edge-normal push; static, returns bool); VU numbering and scheduling differ throughout (retail loads all 5 vectors first, n copied to sp+0x1C0, edge ends e0/e1 kept at sp+0x190/0x180) and retail's frame is 0x210 (many dead by-value inline slots) vs ours 0x60
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3VehicleDeform::NearestPointOnTriangle(CGtV3d, CGtV3d, CGtV3d, CGtV3d, CGtV3d, float, CGtV3d *) -- hand-written from
// the Ghidra draft (ghvu11). [C] name: the mangled symbol in retail's tables (high). Static: no `this` (a0 is the first
// vector). Every type is [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

// [L] N185: compiler-chosen VU stand-ins (vadd / vsub / lane-scaled product / cross with a .i move out)
static inline CGtV3d func_003DABE0_inl1(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline CGtV3d func_003DABE0_inl2(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline CGtV3d func_003DABE0_inl3(const CGtV3d &a, float s)
{
    u_long128 sv, r;
    asm("qmtc2.ni %1, %0" : "=j"(sv) : "r"(s));
    asm("vmulx.xyz %0, %1, %2x" : "=j"(r) : "j"(a.mData), "j"(sv));
    return CGtV3d(r);
}
static inline CGtV3d func_003DABE0_inl4(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r, t;
    asm("vopmula.xyz $ACC, %1, %2" "\n\t" "vopmsub.xyz %0, %2, %1" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    asm("qmfc2.i %0, %1" : "=r"(t) : "j"(r));
    return CGtV3d(t);
}
static inline float func_003DABE0_inl5(u_long128 x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x)); return f; }

class CB3VehicleDeform {
public:
    static bool NearestPointOnTriangle(CGtV3d, CGtV3d, CGtV3d, CGtV3d, CGtV3d, float, CGtV3d *);
};

// 0x003DABE0
bool CB3VehicleDeform::NearestPointOnTriangle(CGtV3d p, CGtV3d a, CGtV3d b, CGtV3d c, CGtV3d n, float maxSq, CGtV3d *out)
{
    CGtV3d centre = func_003DABE0_inl3(func_003DABE0_inl1(func_003DABE0_inl1(a, b), c), 0.33333334f);
    float dist = func_003DABE0_inl5(DotProduct(func_003DABE0_inl2(p, centre), n).lVector);
    if (!(dist * dist <= maxSq)) return false;
    CGtV3d d0 = func_003DABE0_inl2(a, centre);
    *out = func_003DABE0_inl2(p, func_003DABE0_inl3(n, dist));
    CGtV3d pc = func_003DABE0_inl2(*out, centre);
    CGtV3d e0, e1;
    if (func_003DABE0_inl5(DotProduct(func_003DABE0_inl4(d0, n), pc).lVector) > 0.0f) {
        if (func_003DABE0_inl5(DotProduct(func_003DABE0_inl4(func_003DABE0_inl2(b, centre), n), pc).lVector) > 0.0f) {
            e0 = b; e1 = c;
        } else {
            e0 = a; e1 = b;
        }
    } else {
        if (func_003DABE0_inl5(DotProduct(func_003DABE0_inl4(func_003DABE0_inl2(c, centre), n), pc).lVector) > 0.0f) {
            e0 = c; e1 = a;
        } else {
            e0 = b; e1 = c;
        }
    }
    CGtV3d edge = func_003DABE0_inl2(e1, e0);
    if (func_003DABE0_inl5(DotProduct(func_003DABE0_inl2(*out, e0), edge).lVector) <= 0.0f) {
        *out = e0;
        return true;
    }
    if (!(func_003DABE0_inl5(DotProduct(func_003DABE0_inl2(*out, e1), edge).lVector) < 0.0f)) {
        *out = e1;
        return true;
    }
    CGtV3d m = func_003DABE0_inl4(n, edge);
    m.Normalise();
    float d = func_003DABE0_inl5(DotProduct(func_003DABE0_inl2(*out, e0), m).lVector);
    if (d > 0.0f) *out = func_003DABE0_inl2(*out, func_003DABE0_inl3(m, d));
    return true;
}
