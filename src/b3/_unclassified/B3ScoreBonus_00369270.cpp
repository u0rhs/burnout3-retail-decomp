// CB3ScoreBonus::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (nested-if tail with merged (field_18EA==0 && field_130<148) guard; -1.0f/false literals).

// lifter variant 0
// CB3ScoreBonus::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EScoreBonusEvent {};

class CB3ScoreBonus;
struct UnkStruct_00369270_1;
struct UnkStruct_D_0052267C;

struct UnkStruct_00369270_1 {
    unsigned char pad_0[0x10CC];
    float field_10CC;
    unsigned char pad_10D0[0x81A];
    unsigned char field_18EA;
};

struct UnkStruct_D_0052267C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3ScoreBonus {
public:
    void Update();
    void OnEvent(EScoreBonusEvent, int, int, bool);

    unsigned char pad_0[0xD8];
    float field_D8;
    unsigned char pad_DC[0x8];
    int field_E4;
    unsigned char pad_E8[0x8];
    int field_F0;
    float field_F4;
    unsigned char pad_F8[0x18];
    float field_110;
    int field_114;
    float field_118;
    int field_11C;
    float field_120;
    int field_124;
    unsigned char pad_128[0x8];
    int field_130;
    unsigned char pad_134[0x4];
    float field_138;
    unsigned char pad_13C[0x4];
    int field_140;
    float field_144;
    UnkStruct_00369270_1 * field_148;
};

extern UnkStruct_D_0052267C D_0052267C;

extern "C" int func_00369090(CB3ScoreBonus *, int);

// 0x00369270
void CB3ScoreBonus::Update()
{
    UnkStruct_00369270_1 * t0 = field_148;
    float t1 = field_138;
    float t2 = t0->field_10CC;
    if (!(t1 <= 0.0f)) {
        if (!(t2 < (0.25f + t1))) {
            int r0 = func_00369090(this, field_130);
            if (r0 != 0) {
                field_130 = 0;
            }
        }
    }
    if (!(t2 < (8.0f + field_F4))) {
        field_F0 = 0;
    }
    if (field_E4 != 0) {
        if (!(t2 < (8.0f + field_D8))) {
            field_E4 = 0;
        }
    }
    if (field_114 != 0) {
        if (!(t2 < field_110)) {
            field_114 = 0;
            *(int *)&field_110 = 0xBF800000;
        }
    }
    if (field_11C != 0) {
        if (!(t2 < field_118)) {
            field_11C = 0;
            *(int *)&field_118 = 0xBF800000;
        }
    }
    if (field_124 != 0) {
        if (!(t2 < field_120)) {
            field_124 = 0;
            *(int *)&field_120 = 0xBF800000;
        }
    }
    float t3 = field_144;
    if (-1.0f != t3) {
        float t4 = D_0052267C.field_0;
        field_144 = (t3 - t4);
        if ((t3 - t4) <= 0.0f) {
            field_144 = 0.0f;
            if (field_148->field_18EA == 0 && field_130 < 148) {
                OnEvent((EScoreBonusEvent)field_140, 0, -1, false);
                field_140 = 209;
                field_144 = -1.0f;
            }
        }
    }
}
