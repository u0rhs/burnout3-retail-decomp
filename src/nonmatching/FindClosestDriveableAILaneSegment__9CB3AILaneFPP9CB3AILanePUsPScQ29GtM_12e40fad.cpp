// NONMATCHING: FindClosestDriveableAILaneSegment__9CB3AILaneFPP9CB3AILanePUsPScQ29GtMathPs26CGtV3dSc -- retail 101 / ours 100 instructions, 45 in changed runs
// fam1: 45 off: header operator*(float) for the 0.25 + SUB/GetSquaredLength in a by-value inline gets lp=vf4, 0.25=vf5 as retail; left: header GetSquaredLength 1.0 always numbered just below lp (retail 1.0=vf6), sum regs, GPR numbering. ~30 inline-depth variants tried
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// near35: .lit4 D_004E0C14 -> 3.402823466e+38f; header CGtV3d::IsZero() replaces the local stand-in; D_0064D354/D_0064D358 padded to 16 bytes (retail lui, not gp); two N140 UnkStruct_00148A80_pad -> frame 0x40 exact; ADD operands listed b,a. 100 vs 101. Left: retail keeps &D_0064D354 in a register (lui/addiu, lw 0(v1)); VU numbering p->vf4/1.0->vf6 (ours swapped) and the 4-point sum (retail q1 vf2, q0 vf3, q2 vf1, results in place); t-register rotation

// a194: logic right; 1.0 hoist into vf4 matches in the inner loop. local asm IsZero stand-in [L] N185 (mtsab/qfsrv/or x2 then dword mask; CGtV3d::IsZero missing in header). Left: retail keeps p in a3 across IsZero and qmtc2.ni a3->vf4 (we lqc2 it from a stack copy -> vf6), frame 0x40 vs 0x20 (N140 pad did nothing), ptr/const regs t0/a3 swapped

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_148A80_p { unsigned char pad_0[3]; unsigned char field_3; };
struct UnkStruct_148A80_c { unsigned short* field_0; unsigned char pad_4[4]; UnkStruct_148A80_p* field_8; unsigned short field_C; };
class CB3AILane {
public:
    static void FindClosestDriveableAILaneSegment(CB3AILane** pLane, unsigned short* pSeg, signed char* pFlag, CGtV3d p, signed char c);
    unsigned char pad_0[4];
    UnkStruct_148A80_c* field_4;
};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x2C]; CB3AILane field_2C[1]; };
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_D_0064D354 { CGtV3d* field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064D354 D_0064D354;
struct UnkStruct_D_0064D358 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064D358 D_0064D358;
static inline CGtV3d ADD(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vadd.xyz %0, %2, %1" : "=j"(t) : "j"(b.mData), "j"(a.mData));
    return CGtV3d(t);
}
static inline CGtV3d SUB(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(t);
}
static inline CGtV3d MULX(CGtV3d a, float s)
{
    u_long128 t;
    asm("qmtc2.ni %2, $vf5" "\n\t" "vmulx.xyz %0, %1, $vf5x" : "=j"(t) : "j"(a.mData), "r"(s));
    return CGtV3d(t);
}
static inline CGtV3d func_00148A80_inl1(CGtV3d s, CGtV3d p) { return SUB(s * 0.25f, p); }
static inline float func_00148A80_inl2(CGtV3d s, CGtV3d p) { return SUB(s * 0.25f, p).GetSquaredLength(); }
static inline float func_00148A80_inl4(CGtV3d s) { return s.GetSquaredLength(); }
static inline CGtV3d func_00148A80_inl5(CGtV3d *pts, unsigned short *q) { return ADD(ADD(ADD(pts[q[0]], pts[q[1]]), pts[q[2]]), pts[q[3]]); }
static inline float func_00148A80_inl6(CGtV3d m, CGtV3d p) { return SUB(m, p).GetSquaredLength(); }
static inline float func_00148A80_inl7(CGtV3d s, CGtV3d p) { return func_00148A80_inl4(SUB(s * 0.25f, p)); }
static inline CGtV3d func_00148A80_inl8(CGtV3d s) { return s * 0.25f; }
struct UnkStruct_00148A80_pad { int x[4]; UnkStruct_00148A80_pad() {} ~UnkStruct_00148A80_pad() {} };
// 0x00148A80
void CB3AILane::FindClosestDriveableAILaneSegment(CB3AILane** pLane, unsigned short* pSeg, signed char* pFlag, CGtV3d p, signed char c)
{
    UnkStruct_00148A80_pad pad0;
    UnkStruct_00148A80_pad pad1;
    CGtV3d lp = p;
    *pLane = 0;
    *pSeg = 0xFFFF;
    if (D_0064D358.field_0 == 0 || lp.IsZero()) return;
    float best = 3.402823466e+38f;
    for (int i = 0; i < D_0064D358.field_0; i++) {
        CB3AILane* e = &D_00522660.field_2C[i];
        if ((e->field_4->field_8->field_3 & 7) == 5) continue;
        for (int j = 0; j < (int)e->field_4->field_C; j++) {
            unsigned short* q = (unsigned short*)((char*)e->field_4->field_0 + j * 4);
            CGtV3d* pts = D_0064D354.field_0;
            CGtV3d s = ADD(ADD(ADD(pts[q[0]], pts[q[1]]), pts[q[2]]), pts[q[3]]);
            float d = func_00148A80_inl2(s, lp);
            if (d < best) { *pLane = e; best = d; *pSeg = j; *pFlag = 0; }
        }
    }
}
