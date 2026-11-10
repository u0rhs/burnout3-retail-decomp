// CB3Score::GetTotalRaceAmount() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a93: laps/total locals, total*lp; early e==-1 || laps<=0).

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

class CB3Score {
public:
    float GetTotalRaceDistFromAILaneStart();
    float GetTotalRaceAmount();
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
        float total = D_0064D364.field_0[n - 1].field_0;
        d = 0.0f + prev + field_348 * len + (float)(field_350 + 1) * total;
    }
    return d;
}
// 0x0015A9C0
float CB3Score::GetTotalRaceAmount()
{
    float e = field_28C;
    if (e == -1.0f || field_2C4 <= 0) {
        return 0.0f;
    }
    float d;
    if (e == -1.0f) {
        d = 0.0f;
    } else {
        d = GetTotalRaceDistFromAILaneStart() - e;
    }
    float lp = (float)field_2C4;
    float total = D_0064D364.field_0[D_0064D368.field_0 - 1].field_0;
    return d / (total * lp);
}
