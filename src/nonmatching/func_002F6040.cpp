// NONMATCHING: func_002F6040 -- retail 64 / ours 63 instructions, 38 in changed runs
// psweep: scoped #pragma opt_dead_assignments off [G] improves 50 -> 42
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_dead_assignments off
using namespace GtMathPs2;
struct CGtPolygonIntersectionResult;
struct CGtLine { CGtV3d field_0; CGtV3d field_10; };   // [G] layout: two points (start sp+0xE0, end sp+0xF0)
struct UnkStruct_002F6040_d { float field_0; float field_4; };
extern "C" int TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(void *, CGtV3d);
extern "C" int IntersectLineWithUnit__16CB3StreamedTrackFUiRC7CGtLinePFRC28CGtPolygonIntersectionResultPv_bPv(void *, unsigned int, const CGtLine &, bool (*)(const CGtPolygonIntersectionResult &, void *), void *);
extern "C" bool func_002F6140(const CGtPolygonIntersectionResult &, void *);
extern unsigned char D_00522660[];
extern __declspec(sdata) float D_004E0C14;
// [L] N185: stands in for a missing GtMathPs2 inline -- operator+(YAxisType, float), operator-(YAxisType, float)'s shape with vaddx.y
static inline YAxisType func_002F6040_inl1(YAxisType a, float f)
{
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vaddx.y %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s));
    return YAxisType(r);
}
static inline float func_002F6040_inl2(const UnkStruct_002F6040_d *p) { return p->field_4; }
// 0x002F6040
extern "C" CGtV3d func_002F6040(CGtV3d pos, int unit)
{
    UnkStruct_002F6040_d d;
    d.field_4 = D_004E0C14;
    d.field_0 = pos.Y();
    CGtLine line;
    line.field_0 = pos;
    line.field_0.SetY(func_002F6040_inl1(pos.Y(), 30.0f));
    line.field_10 = pos;
    line.field_10.SetY(pos.Y() - 30.0f);
    void *t = D_00522660 + unit * 0x1CC + 0x12A348;
    CGtV3d r = pos;
    IntersectLineWithUnit__16CB3StreamedTrackFUiRC7CGtLinePFRC28CGtPolygonIntersectionResultPv_bPv(t, TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(t, pos), line, func_002F6140, &d);
    float dist = func_002F6040_inl2(&d);
    if (D_004E0C14 != dist) r.SetY(func_002F6040_inl1(r.Y(), dist));
    return r;
}

#pragma pop
