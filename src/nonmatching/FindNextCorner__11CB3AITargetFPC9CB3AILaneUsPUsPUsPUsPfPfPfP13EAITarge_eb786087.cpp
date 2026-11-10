// NONMATCHING: FindNextCorner__11CB3AITargetFPC9CB3AILaneUsPUsPUsPUsPfPfPfP13EAITargetTurnP20EAITargetCornerStatePbPb -- retail 436 / ours 405 instructions, 267 in changed runs
// psweep: scoped #pragma inline_depth(4) [G] improves 396 -> 391
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma inline_depth(4)
using namespace GtMathPs2;

struct UnkStruct_14B4B0_laneinfo {   // [G] CB3AILane::field_4
    unsigned char pad_0[0xC];
    unsigned short field_C;
    unsigned char field_E;
};
class CB3AILane {
public:
    unsigned short IncrementSegmentIndexClamped(unsigned short, short) const;
    void GetAvgForwardsVector(unsigned short, CGtV3d *) const;
    int field_0;
    UnkStruct_14B4B0_laneinfo *field_4;
};
struct UnkStruct_14B4B0_corner {   // [G] 12-byte entry of D_0064D34C
    unsigned short field_0;
    unsigned short field_2;
    unsigned short field_4;
    unsigned short field_6;
    unsigned char field_8;
    unsigned char pad_9;
    signed char field_A;
    unsigned char pad_B;
};
struct UnkStruct_14B4B0_cam2 { unsigned char pad_0[0xB0]; CGtV4d field_B0; };
struct UnkStruct_14B4B0_cam { unsigned char pad_0[0x2430]; UnkStruct_14B4B0_cam2 *field_2430; };
enum EAITargetTurn { UnkEnum_14B4B0_t };
enum EAITargetCornerState { UnkEnum_14B4B0_s };
extern UnkStruct_14B4B0_corner *D_0064D34C;
extern int D_0064D35C;
extern float D_004E069C, D_004E0D6C;
extern int D_01E75584, D_01E75588, D_01E7558C, D_01E75590;
extern "C" float func_0011E328(float);

class CB3AITarget {
public:
    bool FindNextCorner(const CB3AILane *, unsigned short, unsigned short *, unsigned short *, unsigned short *, float *, float *, float *, EAITargetTurn *, EAITargetCornerState *, bool *, bool *);
    unsigned char pad_0[0x4];
    UnkStruct_14B4B0_cam *field_4;
    unsigned char pad_8[0x1E4];
    float field_1EC;
    unsigned char pad_1F0[0x24];
    unsigned short field_214;
    unsigned char pad_216[2];
    unsigned short field_218;
    unsigned char pad_21A[0x86];
    float field_2A0;
};

static inline void func_0014B4B0_tail(CB3AITarget *self, const CB3AILane *lane)
{
    CGtV3d a, b;
    lane->GetAvgForwardsVector(self->field_214, &a);
    lane->GetAvgForwardsVector(self->field_218, &b);
    a.Normalise();
    b.Normalise();
    self->field_2A0 = DotProduct(a, b);
    self->field_2A0 = D_004E069C * func_0011E328(self->field_2A0);
}

// 0x0014B4B0
bool CB3AITarget::FindNextCorner(const CB3AILane *lane, unsigned short seg, unsigned short *o0, unsigned short *o1, unsigned short *o2, float *of0, float *of1, float *of2, EAITargetTurn *turn, EAITargetCornerState *state, bool *b0, bool *b1)
{
    int best = 10000;
    for (int i = 0; i < D_0064D35C; i++) {
        if (lane->field_0 == D_0064D34C[i].field_8) {
            int d = D_0064D34C[i].field_2 - seg;
            if (d < 0) {
                if (lane->field_4->field_E != 0) {
                    d += lane->field_4->field_C;
                } else {
                    d = 10000;
                }
            }
            if (d < best && d > 0) {
                *o0 = D_0064D34C[i].field_0;
                *o1 = D_0064D34C[i].field_2;
                *o2 = D_0064D34C[i].field_4;
                *of0 = (float)D_0064D34C[i].field_6;
                *b1 = (D_0064D34C[i].field_A & 4) == 4;
                *of1 = 0.0f;
                *of2 = 0.0f;
                int k = D_0064D34C[i].field_A & 3;
                best = d;
                if (k == 0) {
                    *turn = (EAITargetTurn)0;
                    *state = (EAITargetCornerState)1;
                    *b0 = false;
                } else if (k == 1) {
                    *turn = (EAITargetTurn)2;
                    *state = (EAITargetCornerState)0;
                } else {
                    *turn = (EAITargetTurn)4;
                    *state = (EAITargetCornerState)0;
                }
            }
        } else if (lane->field_0 < D_0064D34C[i].field_8) {
            break;
        }
    }
    if (best < 10000) {
        float f = GtMath::Min(D_004E0D6C * field_4->field_2430->field_B0.f[3] / 150.0f, 1.0f);
        unsigned short s4;
        if (*of0 < field_1EC) {
            *b0 = true;
            s4 = (int)(f * (float)D_01E75590) + D_01E75588;
        } else {
            *b0 = false;
            s4 = (int)(f * (float)D_01E7558C) + D_01E75584;
        }
        *o0 = lane->IncrementSegmentIndexClamped(*o0, -s4);
        *o2 = lane->IncrementSegmentIndexClamped(*o2, s4);
        func_0014B4B0_tail(this, lane);
        return true;
    }
    for (int i = 0; i < D_0064D35C; i++) {
        if (lane->field_0 == D_0064D34C[i].field_8) {
            int d = D_0064D34C[i].field_4 - seg;
            if (d < 0) {
                if (lane->field_4->field_E != 0) {
                    d += lane->field_4->field_C;
                } else {
                    d = 10000;
                }
            }
            if (d < 10000 && d > 0) {
                *o0 = D_0064D34C[i].field_0;
                *o1 = D_0064D34C[i].field_2;
                *o2 = D_0064D34C[i].field_4;
                *of0 = (float)D_0064D34C[i].field_6;
                *b1 = (D_0064D34C[i].field_A & 4) == 4;
                *of1 = 0.0f;
                *of2 = 0.0f;
                int k = D_0064D34C[i].field_A & 3;
                if (k == 0) {
                    *turn = (EAITargetTurn)0;
                    *state = (EAITargetCornerState)1;
                } else if (k == 1) {
                    *turn = (EAITargetTurn)2;
                    *state = (EAITargetCornerState)0;
                } else {
                    *turn = (EAITargetTurn)4;
                    *state = (EAITargetCornerState)0;
                }
                *b0 = false;
                func_0014B4B0_tail(this, lane);
                return true;
            }
        } else if (lane->field_0 < D_0064D34C[i].field_8) {
            break;
        }
    }
    return false;
}

#pragma pop
