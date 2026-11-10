// NONMATCHING: IntersectLine__14GtIntersectionFRC7CGtLineQ29GtMathPs29CGtSphere -- retail 109 / ours 109 instructions, 21 in changed runs
// ghvu5: control flow and head exact (N185 stand-ins: W*W lane mul, vsub with o on hard-coded vf1). Left (21): the t = Dot(d0,dir)/|dir|^2 block -- retail st=vf1, end/dir=vf2 (in place), d0=vf3 with the 1.0 made first and parked; ours dir=vf4/st=vf3/d0=vf2 (inline wrappers, assignment forms, operand copies tried); frame 0x110 vs 0xE0 (retail st copy at sp+0 lowest, W lane copy 0x60, d0 0xF0, sphere copy 0x100).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// GtIntersection::IntersectLine(const CGtLine&, GtMathPs2::CGtSphere) -- hand-written (ghvu5, Ghidra draft).
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/ (docs/conventions.md).
// [G] 2 = both line ends inside the sphere, 1 = one end inside or the closest point within the radius, 0 = miss.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct CGtLine { CGtV3d field_0; CGtV3d field_10; };   // [G] start, end
class GtIntersection { public: static int IntersectLine(const CGtLine &line, CGtSphere s); };
// [L] N185: stands in for a missing GtMathPs2 inline -- operator*(WAxisType, WAxisType) (B3O0PCH map, 80 bytes)
static inline WAxisType func_002BF5F0_inl1(WAxisType a, WAxisType b) { u_long128 t; asm("vmulw.w %0, %1, %2w" : "=j"(t) : "j"(a.lVector), "j"(b.lVector)); return WAxisType(t); }
// [L] N185: CGtV3d subtraction on compiler-chosen registers (retail vsub.xyz $vf1,$vf3,$vf1 here)
static inline CGtV3d func_002BF5F0_inl2(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
static inline CGtV3d func_002BF5F0_inl3(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vadd.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
// [L] N185: CGtV3d::operator- with the other operand on a hard-coded $vf1 and this on a compiler-chosen register (retail
// `qmtc2.ni v0,$vf1; vsub.xyz $vf1,$vf3,$vf1`; the header form has this on $vf2)
static inline CGtV3d func_002BF5F0_inl4(const CGtV3d &a, const CGtV3d &o)
{
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "vsub.xyz $vf1, %2, $vf1" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(o.mData), "j"(a.mData));
    return CGtV3d(t);
}
// [L] N185: CGtV3d::operator- with both operands on hard-coded registers and the result over this ($vf2)
static inline CGtV3d func_002BF5F0_inl5(const CGtV3d &a, const CGtV3d &o)
{
    u_long128 t;
    asm("qmtc2 %1, $vf1" "\n\t" "qmtc2 %2, $vf2" "\n\t" "vsub.xyz $vf2, $vf2, $vf1" "\n\t" "qmfc2 %0, $vf2" : "=r"(t) : "r"(o.mData), "r"(a.mData));
    return CGtV3d(t);
}
// 0x002BF5F0
int GtIntersection::IntersectLine(const CGtLine &line, CGtSphere s)
{
    float rr = func_002BF5F0_inl1(s.Radius(), s.Radius());
    float de = func_002BF5F0_inl4(s.Position(), line.field_10).GetSquaredLength();
    CGtV3d st = line.field_0;
    CGtV3d d0 = func_002BF5F0_inl4(s.Position(), st);
    float ds = d0.GetSquaredLength();
    if (de <= rr && ds <= rr) return 2;
    if (de <= rr) return 1;
    if (ds <= rr) return 1;
    CGtV3d dir = line.field_10;
    dir -= st;
    float t = DotProduct(d0, dir) / dir.GetSquaredLength();
    if (!(t < 0.0f) && t <= 1.0f) {
        CGtV3d p = func_002BF5F0_inl3(line.field_0, dir * t);
        if (func_002BF5F0_inl2(p, s.Position()).GetSquaredLength() <= rr) return 1;
    }
    return 0;
}


