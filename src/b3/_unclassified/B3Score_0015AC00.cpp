// CB3Score::GetTotalRaceDistFromAILaneStart() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a73: sibling-shaped; early return 0 then straight-line, single d joined at end).

// [L] DNAT: no row in research/proto/new_names.csv. Sibling of CB3Score::GetTotalRaceDistFromStartPos (B3Score_0015AB10.cpp): same lap-distance table, [G] layout.
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

    unsigned char pad_0[0x348];
    float field_348;
    int field_34C;
    int field_350;
};

// 0x0015AC00
float CB3Score::GetTotalRaceDistFromAILaneStart()
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
