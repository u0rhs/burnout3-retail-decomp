// NONMATCHING: FindClosestAILaneSegment__9CB3AILaneFPP9CB3AILanePUsPScQ29GtMathPs26CGtV3dSc -- retail 95 / ours 97 instructions, 47 in changed runs
// a193: logic+structure right, 1.0/0.25/pos hoisted by b119p. Left: hoisted VU reg numbering (retail pos=vf4,0.25=vf5,1.0=vf6; ours one=vf4,pos=vf5,q=vf6), last lqc2 vf1 not folded (lq+qmtc2, since qmtc2 inside asm text), lhu scheduling, 2 extra instrs; IsZero (mtsab/qfsrv/or x/y/z, sign-masked) is a local inline asm - not in header
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3AILane;
struct UnkStruct_00147290_q {
    unsigned short* field_0;
    unsigned char pad_4[0x8];
    unsigned short field_C;
};
class CB3AILane {
public:
    static void FindClosestAILaneSegment(CB3AILane** out, unsigned short* seg, signed char* flag, CGtV3d pos, signed char p4);
    unsigned char pad_0[0x4];
    UnkStruct_00147290_q* field_4;
};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x2C]; CB3AILane field_2C[1]; };
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_D_0064D354 { u_long128* field_0; int pad_4[3]; };
extern UnkStruct_D_0064D354 D_0064D354;
struct UnkStruct_D_0064D358 { int field_0; int pad_4[3]; };
extern UnkStruct_D_0064D358 D_0064D358;
extern float D_004E0C14;

static inline int func_00147290_iszero(CGtV3d p)
{
    unsigned long r, t;
    asm("mtsab $0, 4" "\n\t" "qfsrv %0, %2, %2" "\n\t" "or %1, %2, %0" "\n\t" "qfsrv %0, %0, %0" "\n\t" "or %1, %1, %0" "\n\t"
        "dsll32 %0, %1, 1" "\n\t" "dsrl32 %0, %0, 1" : "=&r"(r), "=&r"(t) : "r"(p.mData));
    return r == 0;
}

// 0x00147290
void CB3AILane::FindClosestAILaneSegment(CB3AILane** out, unsigned short* seg, signed char* flag, CGtV3d pos, signed char p4)
{
    *out = 0;
    *seg = 0xFFFF;
    CGtV3d c = pos;
    if (D_0064D358.field_0 != 0 && !func_00147290_iszero(c)) {
        float best = D_004E0C14;
        u_long128 q, one;
        asm("qmtc2.ni %1, %0" : "=j"(q) : "r"(0.25f));
        for (int i = 0; i < D_0064D358.field_0; i++) {
            CB3AILane* lane = &D_00522660.field_2C[i];
            for (int j = 0; j < lane->field_4->field_C; j++) {
                unsigned short* ix = lane->field_4->field_0 + j * 2;
                u_long128* v = D_0064D354.field_0;
                u_long128 a = v[ix[1]], b = v[ix[0]], c2 = v[ix[2]], d = v[ix[3]];
                u_long128 m;
                asm("qmtc2 %1, $vf3" "\n\t" "qmtc2 %2, $vf2" "\n\t" "qmtc2 %3, $vf1" "\n\t" "vadd.xyz $vf2, $vf3, $vf2" "\n\t" "vadd.xyz $vf2, $vf2, $vf1" "\n\t"
                    "qmtc2 %4, $vf1" "\n\t" "vadd.xyz $vf1, $vf2, $vf1" "\n\t" "vmulx.xyz $vf1, $vf1, %5x" "\n\t" "vsub.xyz $vf1, $vf1, %6" "\n\t"
                    "vmul.xyz $vf1, $vf1, $vf1" "\n\t" "vadday.x $ACC, $vf1, $vf1y"
                    : "=j"(m) : "r"(b), "r"(a), "r"(c2), "r"(d), "j"(q), "j"(c.mData));
                asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));
                u_long128 r;
                asm("vmaddz.x $vf1, %2, $vf1z" "\n\t" "qmfc2.ni %0, $vf1" : "=r"(r) : "j"(m), "j"(one));
                float dist = XAxisType(r);
                if (dist < best) {
                    *out = lane;
                    best = dist;
                    *seg = j;
                    *flag = 0;
                }
            }
        }
    }
}
