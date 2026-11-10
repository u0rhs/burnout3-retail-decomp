// CB3Score::GetTotalRaceDistFromStartPos() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (float: 0.0f + prev + frac*len [+ (lap+1)*total] fused adda/madd; if (lap == 0) prev = 0 else table[lap-1]; early return 0 for -1.0f start).

// CB3Score::GetTotalRaceDistFromStartPos() -- hand-written (a69; the lifter refused a label reached from outside an if body).
// [L] DNAT: no row. Layout [G] from instruction widths. D_0064D364 points at a table of 8-byte entries (cumulative lap
// distances [G]); D_0064D368 is its count; D_0064D378 selects a single-lap measure.
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
    float GetTotalRaceDistFromStartPos();

    unsigned char pad_0[0x28C];
    float field_28C;
    unsigned char pad_290[0xB8];
    float field_348;
    int field_34C;
    int field_350;
};

// 0x0015AB10
float CB3Score::GetTotalRaceDistFromStartPos()
{
    float start = field_28C;
    float d;
    if (start == -1.0f) {
        return 0.0f;
    }
    int n = D_0064D368.field_0;
    if (n == 0) {
        d = 0.0f;
    } else {
        int lap = field_34C;
        float prev;
        if (lap == 0) {
            prev = 0.0f;
        } else {
            prev = D_0064D364.field_0[lap - 1].field_0;
        }
        float len = D_0064D364.field_0[lap].field_0 - prev;
        if (D_0064D378.field_0 != 0) {
            d = 0.0f + prev + field_348 * len;
        } else {
            float total = D_0064D364.field_0[n - 1].field_0;
            d = 0.0f + prev + field_348 * len + (float)(field_350 + 1) * total;
        }
    }
    return d - start;
}
