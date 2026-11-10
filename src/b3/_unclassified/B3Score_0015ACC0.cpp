// CB3Score::IsAheadOfIgnoringLaps(CB3Score*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (flat early returns: d==0 float tie-break ending if (cmp) return true; return false; lap window as (d>0 && half>d), (d>0 && !(d<half)), (d<0 && !(d<-half))).

// CB3Score::IsAheadOfIgnoringLaps(CB3Score*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3Score;

class CB3Score;
struct UnkStruct_0015ACC0_4;
struct UnkStruct_0015ACC0_5;
struct UnkStruct_D_0064D368;
struct UnkStruct_D_0064D378;

struct UnkStruct_D_0064D368 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064D378 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0015ACC0_4 {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

struct UnkStruct_0015ACC0_5 {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

class CB3Score {
public:
    bool IsAheadOfIgnoringLaps(CB3Score* p0);

    unsigned char pad_0[0xC8];
    UnkStruct_0015ACC0_4 * field_C8;
    unsigned char pad_CC[0x27C];
    float field_348;
    int field_34C;
};

extern UnkStruct_D_0064D368 D_0064D368;
extern UnkStruct_D_0064D378 D_0064D378;

// 0x0015ACC0
bool CB3Score::IsAheadOfIgnoringLaps(CB3Score* p0)
{
    int half = D_0064D368.field_0 / 2;
    int d = field_34C - p0->field_34C;
    if (d == 0) {
        if (field_348 > p0->field_348) return true;
        if (field_348 < p0->field_348) return false;
        if (p0->field_C8->field_19AC < ((UnkStruct_0015ACC0_5 *)field_C8)->field_19AC) return true;
        return false;
    }
    if (D_0064D378.field_0 != 0) {
        return 0 < d;
    }
    if (d > 0 && half > d) return true;
    if (d > 0 && !(d < half)) return false;
    if (d < 0 && !(d < -half)) return false;
    return true;
}
