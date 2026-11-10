// NONMATCHING: func_002F5DC0 -- retail 96 / ours 97 instructions, 18 in changed runs
// ghvu3: logic right (GetPositionAtParam inlined twice as the proven 0x2F5D40 body with a fresh-dest lerp, in-place Normalise, fresh sub/add [L] N185); left: frame 0x100 vs 0x110 (retail dead slots: 2 above the first lerp copies, 1 between, 5 below), rel = pos - a coalesces onto pos's VU reg (retail fresh vf1), an extra qmtc2/qmfc2 pair after the normalise
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (ghvu3, Ghidra draft); the lifter refused it. The point on the AI lane nearest to pos: the lane segment
// holding pos, its left/right edges interpolated at the forward distance (CB3CameraUtils::GetPositionAtParam inlined
// twice [L], same body as the proven B3CameraUtils_002F5D40), then pos projected onto the line between those points.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_002F5DC0_e0 { unsigned short field_0[2]; };
struct UnkStruct_002F5DC0_ls { UnkStruct_002F5DC0_e0 *field_0; };
struct UnkStruct_002F5DC0_lane { unsigned char pad_0[4]; UnkStruct_002F5DC0_ls *field_4; };
struct UnkStruct_002F5DC0_ai { unsigned char pad_0[0x18B4]; void *field_18B4; unsigned short field_18B8; };
struct UnkStruct_002F5DC0_e3 { CGtV3d field_0; };
struct UnkStruct_D_0064D354 { UnkStruct_002F5DC0_e3 *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064D354 D_0064D354;
struct UnkStruct_002F5DC0_2 { u_long128 field_0; u_long128 field_10; };
// The CGtV3d arguments by value are declared as references: retail passes the local's own slot, no copy (as B3CrashCameraDirector_00357250) [G]
extern "C" UnkStruct_002F5DC0_lane *WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(void *, unsigned short *, const CGtV3d &);
extern "C" float func_00148DF0(UnkStruct_002F5DC0_lane *, const CGtV3d &, unsigned short);
// [G] N140 pad (as the proven GetPositionAtParam's)
struct UnkStruct_002F5DC0_pad { int x[12]; UnkStruct_002F5DC0_pad() {} ~UnkStruct_002F5DC0_pad() {} };
// [G] N148 stand-in as B3CameraUtils_002F5D40's: a + (b - a) * t with compiler-chosen VU registers
static inline CGtV3d func_002F5DC0_inl1(u_long128 a, u_long128 b, float t)
{
    u_long128 s, p, r;
    asm("vsub.xyz %0, %0, %1" : "+j"(b) : "j"(a));
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(t));
    asm("vmulx.xyz %0, %1, %2x" : "=j"(p) : "j"(b), "j"(s));
    asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a), "j"(p));
    return CGtV3d(r);
}
// [L] N185: compiler-chosen CGtV3d subtract / add (fresh destination; the header operators hard-code $vf1/$vf2)
static inline CGtV3d func_002F5DC0_inl3(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline CGtV3d func_002F5DC0_inl4(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
// [L] N185: CGtV3d::Normalise() in place (retail's second tail shape, N217; as the proven B3AICar_001419F0 near20_norm)
static inline void func_002F5DC0_inl5(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 t;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %1, %1, $Q" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(v.mData));
    asm(".set reorder");
    v.mData = t;
}
// [L] CB3CameraUtils::GetPositionAtParam(CB3AILaneStruct*, unsigned short, float, EAISegmentLinkType) inlined (retail 0x2F5D40's body)
static inline CGtV3d func_002F5DC0_inl2(UnkStruct_002F5DC0_ls *p0, unsigned short p1, float p2, int p3)
{
    UnkStruct_002F5DC0_e3 *t1 = D_0064D354.field_0;
    unsigned short t2 = p0->field_0[p1].field_0[p3];
    unsigned short t3 = p0->field_0[(p1 + 1)].field_0[p3];
    UnkStruct_002F5DC0_2 local;
    UnkStruct_002F5DC0_pad pad;
    local.field_0 = t1[t2].field_0.mData;
    local.field_10 = t1[t3].field_0.mData;
    return func_002F5DC0_inl1(local.field_0, local.field_10, p2);
}
// 0x002F5DC0
extern "C" CGtV3d func_002F5DC0(UnkStruct_002F5DC0_ai *ai, const CGtV3d &pos0)
{
    CGtV3d pos = pos0;
    unsigned short seg = ai->field_18B8;
    UnkStruct_002F5DC0_lane *lane = WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(ai->field_18B4, &seg, pos);
    float t = func_00148DF0(lane, pos, seg);
    CGtV3d a = func_002F5DC0_inl2(lane->field_4, seg, t, 0);
    CGtV3d b = func_002F5DC0_inl2(lane->field_4, seg, t, 1);
    CGtV3d dir = func_002F5DC0_inl3(b, a);
    CGtV3d rel = func_002F5DC0_inl3(pos, a);
    func_002F5DC0_inl5(dir);
    return func_002F5DC0_inl4(a, dir * DotProduct(dir, rel));
}
