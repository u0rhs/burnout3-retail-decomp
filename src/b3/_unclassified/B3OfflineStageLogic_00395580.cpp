// CB3OfflineStageLogic::StartReplay() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OfflineStageLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (pointer local to field_20[i].field_E held across calls; car object pointer local (D_00522660 + idx*0x27D0 + 0x12AD50) with its own field struct).

// CB3OfflineStageLogic::StartReplay() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OfflineStageLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3OfflineStageLogic;
class CGtTimer;
struct UnkStruct_00395580_6;
struct UnkStruct_00395580_e0;
struct UnkStruct_00395580_e1;
struct UnkStruct_00395580_e2;
struct UnkStruct_00395580_e3;
struct UnkStruct_00395580_e4;

struct UnkStruct_00395580_car {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
    unsigned char pad_19AD[0xAA0];
    unsigned char field_244D;
};

struct UnkStruct_00395580_e4 {
    unsigned char pad_0[0x27D0];
};

struct UnkStruct_00395580_e3 {
    unsigned char pad_0[0x2C];
    UnkStruct_00395580_6 * field_2C;
};

struct UnkStruct_00395580_e2 {
    unsigned char pad_0[0x1D7C];
    signed char field_1D7C;
    unsigned char pad_1D7D[0xA53];
};

struct UnkStruct_00395580_e1 {
    unsigned char pad_0[0x4D];
    unsigned char field_4D;
    unsigned char pad_4E[0x2782];
};

class CGtTimer {
public:
    void SetSlowMo(int);

    UnkStruct_00395580_e4 field_0[1];  // [G] element count unknown
    unsigned char pad_27D0[0x3A190];
    UnkStruct_00395580_e3 field_3C960[1];  // [G] element count unknown
    unsigned char pad_3C990[0xEDFF0];
    UnkStruct_00395580_e2 field_12A980[1];  // [G] element count unknown
    UnkStruct_00395580_e1 field_12D150[1];  // [G] element count unknown
};

struct UnkStruct_00395580_e0 {
    int field_0;
    float field_4;
    int field_8;
    unsigned char field_C;
    unsigned char pad_D[0x1];
    unsigned char field_E;
    unsigned char field_F;
};

struct UnkStruct_00395580_6 {
    unsigned char pad_0[0x1524];
    int field_1524;
};

class CB3OfflineStageLogic {
public:
    int StartReplay();

    unsigned char pad_0[0x20];
    UnkStruct_00395580_e0 field_20[1];  // [G] element count unknown
};

extern CGtTimer D_00522660;

extern "C" void func_00150280(UnkStruct_00395580_car *, int);

// 0x00395580
int CB3OfflineStageLogic::StartReplay()
{
    for (int i = 0; (i < 2); i++) {
        unsigned char * pe = &field_20[i].field_E;
        if (*pe != 0) {
            UnkStruct_00395580_car * car = (UnkStruct_00395580_car *)((char *)&D_00522660.field_0[field_20[i].field_8] + 0x12AD50);
            car->field_244D = 0;
            func_00150280(car, 0);
            UnkStruct_00395580_6 * t2 = D_00522660.field_3C960[car->field_19AC].field_2C;
            if (t2->field_1524 == 4) {
                t2->field_1524 = 0;
            }
            D_00522660.SetSlowMo(1);
            field_20[i].field_C = 0;
            *pe = 0;
            field_20[i].field_4 = -1.0f;
            field_20[i].field_0 = 0;
        }
        field_20[i].field_4 = -1.0f;
        *pe = 0;
        field_20[i].field_C = 0;
        field_20[i].field_F = 0;
        field_20[i].field_0 = 0;
    }
    return 1;
}
