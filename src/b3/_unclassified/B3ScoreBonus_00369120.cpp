// CB3ScoreBonus::ClearAttackData() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a103: row[6]{float,int,float[6]} at 0x14 + float[6] at 0xF8).

struct UnkStruct_00369120_row {
    float field_0;
    int field_4;
    float field_8[6];
};
struct UnkStruct_00369120 {
    int field_0;
    unsigned char field_4;
    unsigned char field_5;
    unsigned char field_6;
    unsigned char field_7;
    unsigned char pad_8[0x1];
    unsigned char field_9;
    unsigned char pad_A[0x2];
    int field_C;
    unsigned char pad_10[0x4];
    UnkStruct_00369120_row field_14[6];
    int field_D4;
    float field_D8;
    float field_DC;
    int field_E0;
    int field_E4;
    int field_E8;
    unsigned char field_EC;
    unsigned char pad_ED[0x3];
    int field_F0;
    float field_F4;
    float field_F8[6];
    float field_110;
    int field_114;
    float field_118;
    int field_11C;
    float field_120;
    int field_124;
    int field_128;
};
extern "C" void ClearAttackData__13CB3ScoreBonusFv(UnkStruct_00369120 * self)
{
    for (int i = 0; i < 6; i++) {
        self->field_14[i].field_4 = 0;
        self->field_14[i].field_0 = -1.0f;
        for (int j = 0; j < 6; j++) {
            self->field_14[i].field_8[j] = -1.0f;
        }
    }
    self->field_D4 = 0;
    self->field_D8 = -1.0f;
    self->field_DC = -1.0f;
    self->field_E0 = 7;
    self->field_E4 = 0;
    self->field_E8 = 0;
    self->field_EC = 0;
    self->field_F0 = 0;
    self->field_F4 = -1.0f;
    self->field_0 = 0;
    self->field_4 = 0;
    self->field_5 = 0;
    self->field_6 = 0;
    self->field_7 = 0;
    self->field_9 = 0;
    self->field_C = 0;
    self->field_110 = -1.0f;
    self->field_114 = 0;
    self->field_118 = -1.0f;
    self->field_11C = 0;
    self->field_120 = -1.0f;
    self->field_124 = 0;
    self->field_128 = 0;
    for (int k = 0; k < 6; k++) {
        self->field_F8[k] = -1.0f;
    }
}
