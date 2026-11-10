// NONMATCHING: func_0015A7F0 -- retail 114 / ours 113 instructions, 22 in changed runs
// near29: per-branch t = inl0()*lp; e loaded after t; GetTotalRaceAmount's d = (e == -1) ? 0 : Get() - e form -> 22. Left: branch-1 inlined n==0 zero arm goes out of line (retail inline, bnez), D_0064D364/D_0064D368 load order, branch-2 FPR e/total swapped (f4/f5)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)



struct UnkStruct_Score_el {
    float field_0;
    float field_4;
};
struct UnkStruct_D_0064D364 {
    UnkStruct_Score_el *field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_0064D368 {
    int field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_0064D378 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
};
extern UnkStruct_D_0064D364 D_0064D364;
extern UnkStruct_D_0064D368 D_0064D368;
extern UnkStruct_D_0064D378 D_0064D378;

static inline float func_0015A7F0_inl0() { return D_0064D364.field_0[D_0064D368.field_0 - 1].field_0; }
class CB3Score {
public:
    float GetTotalRaceDistFromAILaneStart();
    float Calc();
    unsigned char pad_0[0x28C];
    float field_28C;
    unsigned char pad_290[0x34];
    int field_2C4;
    unsigned char pad_2C8[0x80];
    float field_348;
    int field_34C;
    int field_350;
    unsigned char pad_354[0x2A8];
    float field_5FC;
};
inline float CB3Score::GetTotalRaceDistFromAILaneStart()
{
    int n = D_0064D368.field_0;
    if (n == 0) {
        return 0.0f;
    }
    int lap = field_34C;
    float prev;
    if (lap == 0) {
        prev = 0.0f;
    } else {
        prev = D_0064D364.field_0[lap - 1].field_0;
    }
    float len = D_0064D364.field_0[lap].field_0 - prev;
    float d;
    if (D_0064D378.field_0 != 0) {
        d = 0.0f + prev + field_348 * len;
    } else {
        float total = func_0015A7F0_inl0();
        d = 0.0f + prev + field_348 * len + (float)(field_350 + 1) * total;
    }
    return d;
}
extern "C" float func_0015A7F0(CB3Score *self);
float func_0015A7F0(CB3Score *self)
{
    if (D_0064D378.field_0 != 0) {
        float lp = (float)self->field_2C4;
        float total = func_0015A7F0_inl0();
        float t = total * lp;
        float e = self->field_5FC;
        return t - self->GetTotalRaceDistFromAILaneStart() - e;
    }
    float lp = (float)self->field_2C4;
    float total = func_0015A7F0_inl0();
    float t = total * lp;
    float e = self->field_28C;
    float d;
    if (e == -1.0f) {
        d = 0.0f;
    } else {
        d = self->GetTotalRaceDistFromAILaneStart() - e;
    }
    return t - d;
}

