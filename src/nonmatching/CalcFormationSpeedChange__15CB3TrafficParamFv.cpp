// NONMATCHING: CalcFormationSpeedChange__15CB3TrafficParamFv -- retail 293 / ours 295 instructions, 60 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: L269: logic complete, 293/295 instrs, 21 opcode diffs. Left: retail lays the 'change = 0' else-arm after the main arm (bc1t) -- every if/else/goto/inline/pragma form gives bc1f with it inline; the adda.s zero-trick operand is a mov.s copy of f20 in ours; the sign-block's D_004E124C load scheduled ea
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMath.h"
extern "C" float floorf(float);

struct UnkStruct_001605C0_seg {
    unsigned short field_0[6];
    unsigned char field_C[4];
    unsigned char pad_10[0x2];
};
struct UnkStruct_001605C0_ld {
    unsigned char pad_0[0x8];
    UnkStruct_001605C0_seg * field_8;
};
struct UnkStruct_001605C0_sp {
    float * field_0;
    float * field_4;
    float * field_8;
    float field_C;
};
class CB3TrafficParam;
class CB3TrafficLane {
public:
    UnkStruct_001605C0_ld * field_0;
    CB3TrafficParam * GetNearestParamInSameLane(CB3TrafficParam *);
    CB3TrafficParam * GetNearestParam(float);
    float GetSignedForwardDistBetweenParams(float, float);
};
struct UnkStruct_001605C0_e3 { unsigned char pad_0[0x4C]; };
struct UnkStruct_D_00522660 { UnkStruct_001605C0_e3 field_0[1]; };
extern UnkStruct_D_00522660 D_00522660;

class CB3TrafficParam {
public:
    float CalcFormationSpeedChange();

    float field_0;
    unsigned char pad_4[0x28];
    float field_2C;
    float field_30;
    unsigned char pad_34[0x4];
    UnkStruct_001605C0_sp * field_38;
    unsigned short field_3C;
    unsigned short field_3E;
    unsigned char pad_40[0x1];
    unsigned char field_41;
    unsigned char field_42;
    unsigned char field_43;
    unsigned char pad_44[0x3];
    unsigned char field_47;
    unsigned char pad_48[0x3];
    unsigned char field_4B;
};

static inline CB3TrafficLane * func_001605C0_inl2(unsigned char i)
{
    if (i == 255) return 0;
    return (CB3TrafficLane *)((char *)&D_00522660.field_0[i] + 0x22C);
}

static inline float func_001605C0_inl1(const float &d)
{
    unsigned int s = (*(unsigned int *)&d & 0x80000000) | 0x3F800000;
    return *(float *)&s;
}

// 0x001605C0
float CB3TrafficParam::CalcFormationSpeedChange()
{
    CB3TrafficLane * lane;
    if (field_41 == 255) {
        lane = 0;
    } else {
        lane = (CB3TrafficLane *)((char *)&D_00522660.field_0[field_41] + 0x22C);
    }
    if (field_38->field_0[field_47] < 0.0f) return 0.0f;
    float g;
    float change = 0.0f;
    int count = 0;
    bool side = false;
    CB3TrafficParam * p = lane->GetNearestParamInSameLane(this);
    if (p != 0) {
        float d = lane->GetSignedForwardDistBetweenParams(p->field_30, field_30);
        float gap = field_38->field_0[field_47];
        if (GtMath::Abs(d) < gap) {
            if (!(GtMath::Abs(field_2C - 0.44704f * field_0) <= GtMath::Abs(p->field_2C - 0.44704f * p->field_0))) {
                count++;
                if (p->field_38 != 0 && p->field_47 != 255) {
                    gap = (gap + p->field_38->field_0[p->field_47]) / 2.0f;
                }
                float diff = GtMath::Abs(d) - gap;
                if (!(GtMath::Abs(diff) <= 0.12f * gap)) {
                    side = true;
                    change = 0.15f * diff * func_001605C0_inl1((float)d);
                } else {
                    change = 0.0f;
                }
            }
        }
    }
    if (field_4B & 1) {
        UnkStruct_001605C0_seg * e = &lane->field_0->field_8[(int)field_30];
        field_42 = e->field_C[2];
        field_43 = e->field_C[3];
        field_3C = e->field_0[2];
        field_3E = e->field_0[3];
    }
    if (!side) {
        for (int i = 0; i < 2; i++) {
            int seg;
            CB3TrafficLane * ol;
            if (i == 0) {
                g = field_38->field_4[field_47];
                seg = field_3C;
                ol = func_001605C0_inl2(field_42);
            } else {
                g = field_38->field_8[field_47];
                seg = field_3E;
                ol = func_001605C0_inl2(field_43);
            }
            if (g < 0.0f) continue;
            if (ol == 0) continue;
            if (seg == 65535) continue;
            float pos = (float)seg + (field_30 - floorf(field_30));
            CB3TrafficParam * q = ol->GetNearestParam(pos);
            if (q == 0) continue;
            float d = lane->GetSignedForwardDistBetweenParams(q->field_30, pos);
            if (!(GtMath::Abs(d) < field_38->field_C)) continue;
            count++;
            if (q->field_38 != 0 && q->field_47 != 255) {
                if (i == 0) g = (g + q->field_38->field_8[q->field_47]) / 2.0f;
                else g = (g + q->field_38->field_4[q->field_47]) / 2.0f;
            }
            change = 0.15f * (GtMath::Abs(d) - g) * func_001605C0_inl1((float)d);
        }
    }
    if (count == 0) return 0.0f;
    float z = 0.0f;
    float avg = (z + (change + z)) / (float)count;
    float lim = 0.12f * field_0;
    return GtMath::Min(GtMath::Max(avg, -lim), lim);
}
