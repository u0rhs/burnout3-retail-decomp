// CB3StageLogic::OnPostCrashReset(CB3RaceCarPhysics*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StageLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3RaceCarPhysics;

class CB3StageLogic;
struct CB3RaceCarPhysics;
struct UnkStruct_00395930_1;

struct CB3RaceCarPhysics {
    unsigned char pad_0[0x13F4];
    UnkStruct_00395930_1 * field_13F4;
};

struct UnkStruct_00395930_1 {
    unsigned char pad_0[0x1914];
    int field_1914;
    unsigned char pad_1918[0xEA8];
    int field_27C0;
};

class CB3StageLogic {
public:
    void OnPostCrashReset(CB3RaceCarPhysics* p0);

    unsigned char pad_0[0x10];
    float field_10[1];  // [G] element count unknown
    unsigned char pad_14[0x4];
    float field_18[1];  // [G] element count unknown
};

// 0x00395930
void CB3StageLogic::OnPostCrashReset(CB3RaceCarPhysics* p0)
{
    UnkStruct_00395930_1 * t0 = p0->field_13F4;
    if (t0->field_1914 == 0) {
        int t1 = t0->field_27C0;
        field_10[t1] = 4.0f;
        field_18[t1] = 4.0f;
    }
}
