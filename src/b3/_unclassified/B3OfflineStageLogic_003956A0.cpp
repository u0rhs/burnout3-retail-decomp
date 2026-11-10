// CB3OfflineStageLogic::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OfflineStageLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (D_00522660 element array placed at +0x12AD50 (stride 0x27D0) reached through one element pointer e; e->field_19AC indexes field_3C960).

// CB3OfflineStageLogic::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OfflineStageLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3OfflineStageLogic;
class CGtTimer;
struct UnkStruct_003956A0_6;
struct UnkStruct_003956A0_e0;
struct UnkStruct_003956A0_e2;
struct UnkStruct_003956A0_e3;
struct UnkStruct_003956A0_e4;

struct UnkStruct_003956A0_e4 {
    unsigned char pad_0[0x27D0];
};

struct UnkStruct_003956A0_e3 {
    unsigned char pad_0[0x2C];
    UnkStruct_003956A0_6 * field_2C;
};

struct UnkStruct_003956A0_e2 {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
    unsigned char pad_19AD[0xAA0];
    unsigned char field_244D;
    unsigned char pad_244E[0x382];
};

class CGtTimer {
public:
    void SetSlowMo(int);

    UnkStruct_003956A0_e4 field_0[1];  // [G] element count unknown
    unsigned char pad_27D0[0x3A190];
    UnkStruct_003956A0_e3 field_3C960[1];  // [G] element count unknown
    unsigned char pad_3C990[0xEDFF0];
    unsigned char pad_12A980[0x3D0];
    UnkStruct_003956A0_e2 field_12AD50[1];  // [G] element count unknown
};

struct UnkStruct_003956A0_e0 {
    int field_0;
    float field_4;
    int field_8;
    unsigned char field_C;
    unsigned char pad_D[0x1];
    unsigned char field_E;
    unsigned char field_F;
};

struct UnkStruct_003956A0_6 {
    unsigned char pad_0[0x1524];
    int field_1524;
};

class CB3OfflineStageLogic {
public:
    int Prepare();

    unsigned char pad_0[0x5];
    unsigned char field_5;
    unsigned char pad_6[0x1A];
    UnkStruct_003956A0_e0 field_20[1];  // [G] element count unknown
};

extern CGtTimer D_00522660;

extern "C" void func_00150280(void *, int);

// 0x003956A0
int CB3OfflineStageLogic::Prepare()
{
    for (int i = 0; i < 2; i++) {
        if (field_20[i].field_E != 0) {
            UnkStruct_003956A0_e2 * e = &D_00522660.field_12AD50[field_20[i].field_8];
            e->field_244D = 0;
            func_00150280(e, 0);
            UnkStruct_003956A0_6 * t2 = D_00522660.field_3C960[e->field_19AC].field_2C;
            if (t2->field_1524 == 4) {
                t2->field_1524 = 0;
            }
            D_00522660.SetSlowMo(1);
            field_20[i].field_C = 0;
            field_20[i].field_E = 0;
            field_20[i].field_4 = -1.0f;
            field_20[i].field_0 = 0;
        }
        field_20[i].field_4 = -1.0f;
        field_20[i].field_E = 0;
        field_20[i].field_C = 0;
        field_20[i].field_F = 0;
        field_20[i].field_0 = 0;
    }
    field_5 = 1;
    return 1;
}
