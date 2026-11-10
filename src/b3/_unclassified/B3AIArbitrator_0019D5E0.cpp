// CB3AIArbitrator::CalculateCatchup() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIArbitrator.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (a74: field_760 typed as D_0064D3B0*, &global in const local, merged (p==0||p==field_760) with field read inside the condition).

// CB3AIArbitrator::CalculateCatchup() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIArbitrator.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3AIArbitrator;
class CB3Score;
struct UnkStruct_0019D5E0_3;
struct UnkStruct_D_0064D3A0;
struct UnkStruct_D_0064D3B0;

class CB3Score {
public:
    float GetTotalRaceDistFromAILaneStart();
};

struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064D3B0 {
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
};

struct UnkStruct_0019D5E0_3 {
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
};

class CB3AIArbitrator {
public:
    void CalculateCatchup();

    unsigned char pad_0[0x760];
    UnkStruct_D_0064D3B0 * field_760;
    unsigned char pad_764[0x28];
    int field_78C;
};

extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_0064D3B0 D_0064D3B0;

extern "C" int func_001419B0(UnkStruct_D_0064D3B0 *);

// 0x0019D5E0
void CB3AIArbitrator::CalculateCatchup()
{
    if (D_0064D3A0.field_0 == 0) {
        field_78C = 0;
        return;
    }
    UnkStruct_D_0064D3B0 * const p = &D_0064D3B0;
    if (p == 0 || p == field_760) {
        field_78C = 0;
        return;
    }
    int r0 = func_001419B0(field_760);
    if (r0 == 0) {
        float r1 = field_760->field_10C0.GetTotalRaceDistFromAILaneStart();
        float r2 = p->field_10C0.GetTotalRaceDistFromAILaneStart();
        if (r2 > r1) {
            field_78C = 2;
        } else {
            field_78C = 1;
        }
        return;
    }
    field_78C = 0;
}
