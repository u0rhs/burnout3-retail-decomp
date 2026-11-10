// CB3SoundCrashManager::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (1.0f held in a float local (kept mul by 1.0f)).

// lifter variant 0
// CB3SoundCrashManager::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SoundCrashManager;
struct UnkStruct_00282930_e1;
struct UnkStruct_D_004E1AE4;
struct UnkStruct_D_004E1AE8;

struct UnkStruct_D_004E1AE4 {
    float field_0;
};

struct UnkStruct_D_004E1AE8 {
    int field_0;
};

struct UnkStruct_00282930_e1 {
    unsigned char pad_0[0x40];
};

class CB3SoundCrashManager {
public:
    void Construct();
    void RegisterVariables();

    int field_0;
    unsigned char pad_4[0x510];
    unsigned char field_514[1];  // [G] element count unknown
    unsigned char pad_515[0x13];
    float field_528;
    float field_52C;
    float field_530;
    float field_534;
    float field_538;
    float field_53C;
    float field_540;
    float field_544;
    float field_548;
    float field_54C;
    float field_550;
    float field_554;
    float field_558;
    float field_55C;
    int field_560;
    int field_564;
    float field_568;
    float field_56C;
    float field_570;
    float field_574;
    unsigned char pad_578[0x24C];
    int field_7C4;
    int field_7C8;
    unsigned char pad_7CC[0x68];
    float field_834;
    float field_838;
    float field_83C;
    unsigned char pad_840[0x3C];
    int field_87C;
    unsigned char pad_880[0x4];
    int field_884;
    int field_888;
    unsigned char pad_88C[0x37];
    unsigned char field_8C3;
    unsigned char field_8C4;
    unsigned char field_8C5;
    unsigned char field_8C6;
    unsigned char field_8C7;
    unsigned char pad_8C8[0x3];
    unsigned char field_8CB;
    unsigned char field_8CC;
    unsigned char field_8CD;
    unsigned char field_8CE;
    unsigned char field_8CF;
    unsigned char pad_8D0[0x8];
    unsigned char field_8D8;
    unsigned char pad_8D9[0x3];
    unsigned char field_8DC;
    unsigned char pad_8DD[0x5];
    unsigned char field_8E2;
    unsigned char field_8E3;
    unsigned char pad_8E4[0x5A];
    unsigned char field_93E;
};

extern UnkStruct_D_004E1AE4 D_004E1AE4;
extern UnkStruct_D_004E1AE8 D_004E1AE8;

extern "C" void func_00283B20(void *);

// 0x00282930
void CB3SoundCrashManager::Construct()
{
    field_8C5 = 0;
    field_7C4 = 0;
    field_8C6 = 0;
    field_7C8 = 0;
    field_8C7 = 0;
    field_8CB = 0;
    field_8CC = 0;
    field_8CD = 0;
    field_8C3 = 0;
    field_8C4 = 0;
    field_8CE = 0;
    field_8CF = 0;
    for (int i = 0; (i < 8); i++) {
        field_514[i] = 0;
    }
    for (int i1 = 0; (i1 < 6); i1++) {
        func_00283B20(((char *)((char *)this + (i1 << 6)) + 0x10));
    }
    float one = 1.0f;
    field_52C = 55.0f;
    field_534 = 2.5f;
    field_54C = 1.2f;
    field_554 = one;
    field_53C = 15.0f;
    field_544 = 5.5f;
    field_55C = 0.2f;
    field_564 = 0;
    field_56C = one;
    field_574 = one;
    field_528 = 50.0f;
    field_530 = 2.0f;
    field_548 = 0.9f;
    field_550 = 0.6f;
    field_538 = 20.0f;
    field_540 = 4.0f;
    field_558 = 0.5f;
    field_560 = 0;
    field_568 = 0.9f;
    field_570 = one;
    field_834 = one;
    field_838 = 0.85f;
    field_83C = (one * D_004E1AE4.field_0);
    field_884 = 0;
    field_8DC = 0;
    field_888 = 0;
    field_8E2 = 0;
    field_8E3 = 0;
    field_87C = 0;
    RegisterVariables();
    field_8D8 = 0;
    field_93E = 0;
    if (D_004E1AE8.field_0 == -1) {
        D_004E1AE8.field_0 = 0;
    }
    field_0 = 1;
}
