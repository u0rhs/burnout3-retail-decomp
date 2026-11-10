// NONMATCHING: UpdateCurrentAILaneSegment__9CB3AILaneFPP9CB3AILanePUsPScPfQ29GtMathPs26CGtV3db -- retail 176 / ours 172 instructions, 79 in changed runs
// ghvu10 draft: logic from retail (IsZero/count guards, FindClosestAILaneSegment fallback with the seg == -1 compare retail keeps, WalkLanesToFindPosition, param = clamp01(|p - m1| / |m0 - m1|) with a float-bits zero test, else func_00148DF0). 172/176, 79 changed: retail reuses VU registers for the segment midpoints (vf2/vf3 reloaded in place, 0.5 in vf5), keeps two extra 16-byte frame slots, and orders the lhu/lqc2 loads differently.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3AILane::UpdateCurrentAILaneSegment(CB3AILane**, unsigned short*, signed char*, float*, CGtV3d, bool) -- hand-written
// (ghvu10, Ghidra draft). [C] name: the mangled symbol in retail's tables; Area not evidenced, so _unclassified/ (docs/conventions.md).
// Field names are placeholders and every type is [G]. Static: a0 is the lane pointer's address (no `this`).

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

struct UnkStruct_00147950_e { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_00147950_r { UnkStruct_00147950_e *field_0; };
struct UnkStruct_00147950_v { CGtV3d field_0; };
struct UnkStruct_D_0064D354 { UnkStruct_00147950_v *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064D358 { int field_0; unsigned char pad_4[0xC]; };
class CB3AILane {
public:
    static bool UpdateCurrentAILaneSegment(CB3AILane **, unsigned short *, signed char *, float *, CGtV3d, bool);
    unsigned char pad_0[4];
    UnkStruct_00147950_r *field_4;
};
extern UnkStruct_D_0064D354 D_0064D354;
extern UnkStruct_D_0064D358 D_0064D358;
// [G] by-value CGtV3d parameters passed as the caller's own slot (no copy): mangled externs taking a pointer.
extern "C" CB3AILane *WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(CB3AILane *, unsigned short *, const CGtV3d *);
extern "C" void FindClosestAILaneSegment__9CB3AILaneFPP9CB3AILanePUsPScQ29GtMathPs26CGtV3dSc(CB3AILane **, unsigned short *, signed char *, const CGtV3d *, signed char);
extern "C" float func_00148DF0(CB3AILane *, const CGtV3d *, unsigned short);

// [L] N185: CGtV3d + / - on compiler-chosen registers.
static inline CGtV3d func_00147950_inl1(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline CGtV3d func_00147950_inl2(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
// [L] N185: XAxisType -> float without the address-taken read.
static inline float func_00147950_inl3(XAxisType x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x.lVector)); return f; }

// 0x00147950
bool CB3AILane::UpdateCurrentAILaneSegment(CB3AILane **plane, unsigned short *pseg, signed char *flag, float *param, CGtV3d pos, bool exact)
{
    CGtV3d p = pos;
    CB3AILane *lane = *plane;
    unsigned short seg = *pseg;
    if (p.IsZero()) return false;
    if (D_0064D358.field_0 <= 0) return false;
    if (lane == 0 || seg == -1) {
        FindClosestAILaneSegment__9CB3AILaneFPP9CB3AILanePUsPScQ29GtMathPs26CGtV3dSc(&lane, &seg, flag, &p, *flag);
        if (lane == 0) return false;
        *plane = lane;
        *pseg = seg;
        *flag = 0;
    }
    unsigned short s = seg;
    lane = WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(lane, &s, &p);
    *plane = lane;
    *pseg = s;
    *flag = 0;
    if (param != 0) {
        if (exact) {
            UnkStruct_00147950_e *e = &lane->field_4->field_0[s];
            UnkStruct_00147950_v *pts = D_0064D354.field_0;
            CGtV3d m0 = func_00147950_inl1(pts[e[1].field_2].field_0, pts[e[1].field_0].field_0) * 0.5f;
            CGtV3d m1 = func_00147950_inl1(pts[e[0].field_2].field_0, pts[e[0].field_0].field_0) * 0.5f;
            XAxisType len = func_00147950_inl2(m0, m1).GetLength();
            if (((unsigned long)len.lVector & 0x7F800000) <= 0x37800000) {
                *param = 0.0f;
            } else {
                *param = GtMath::Min(GtMath::Max(func_00147950_inl3(func_00147950_inl2(p, m1).GetLength()) / func_00147950_inl3(len), 0.0f), 1.0f);
            }
        } else {
            *param = func_00148DF0(lane, &p, s);
        }
    }
    return true;
}
