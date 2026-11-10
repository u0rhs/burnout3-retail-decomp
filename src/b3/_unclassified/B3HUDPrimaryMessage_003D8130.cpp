// CB3HUDPrimaryMessage::UpdateCrashText(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDPrimaryMessage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (func_00131E40 takes only a0 (phantom args dropped); element-pointer local; nested ifs).

// CB3HUDPrimaryMessage::UpdateCrashText(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDPrimaryMessage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EScoreBonusEvent {};

class CB3HUDPrimaryMessage;
class CB3ScoreBonus;
struct UnkStruct_003D8130_1;
struct UnkStruct_003D8130_2;
struct UnkStruct_003D8130_e0;
struct UnkStruct_D_004EE040;

class CB3ScoreBonus {
public:
    void OnEvent(EScoreBonusEvent, int, int, bool);
};

struct UnkStruct_003D8130_1 {
    unsigned char pad_0[0xC8];
    UnkStruct_003D8130_2 * field_C8;
    unsigned char pad_CC[0x58];
    CB3ScoreBonus field_124;
    unsigned char pad_125[0x3E1];
    unsigned char field_506;
    unsigned char pad_507[0xB8];
    unsigned char field_5BF;
};

struct UnkStruct_003D8130_2 {
    unsigned char pad_0[0x18EA];
    unsigned char field_18EA;
};

struct UnkStruct_003D8130_e0 {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x68];
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3HUDPrimaryMessage {
public:
    void UpdateCrashText(float p0);

    unsigned char pad_0[0x4];
    UnkStruct_003D8130_e0 * field_4;
    unsigned char pad_8[0x18];
    int field_20;
    UnkStruct_003D8130_1 * field_24;
    unsigned char pad_28[0xC];
    float field_34;
    int field_38;
};

extern UnkStruct_D_004EE040 D_004EE040;

extern "C" int func_00131E40(void *);

void CB3HUDPrimaryMessage::UpdateCrashText(float p0)
{
    if (field_24->field_C8->field_18EA == 0) {
        return;
    }
    UnkStruct_003D8130_e0 * e = &field_4[field_20];
    if (e->field_4 != 2) {
        return;
    }
    field_34 -= p0;
    if (field_34 <= 0.0f) {
        field_34 = 0.0f;
        int v1;
        if (field_24->field_5BF != 0) {
            v1 = 129;
        } else if (field_24->field_506 != 0) {
            v1 = 128;
        } else {
            v1 = 127;
        }
        if (field_38 < v1 && func_00131E40(&D_004EE040) == 0) {
            field_38 = v1;
            field_24->field_124.OnEvent((EScoreBonusEvent)field_38, 0, -1, 0);
        }
    }
}
