// CB3CrashCombo::DetectSkid() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (hdr9: exact with the N217 GetLength).


// CB3CrashCombo::DetectSkid() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3CrashCombo;
struct UnkStruct_00361E60_1;
struct UnkStruct_00361E60_2;
struct UnkStruct_D_00522680;

struct UnkStruct_00361E60_1 {
    unsigned char pad_0[0xB0];
    GtMathPs2::CGtV3d field_B0;
    unsigned char pad_C0[0x144];
    UnkStruct_00361E60_2 * field_204;
    unsigned char pad_208[0x6];
    unsigned char field_20E;
};

struct UnkStruct_00361E60_2 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
};

struct UnkStruct_D_00522680 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3CrashCombo {
public:
    void DetectSkid();

    unsigned char pad_0[0x119];
    unsigned char field_119;
    unsigned char pad_11A[0xE];
    float field_128;
    unsigned char pad_12C[0x6C];
    int field_198;
    unsigned char pad_19C[0x21];
    unsigned char field_1BD;
    unsigned char pad_1BE[0x2];
    float field_1C0;
    unsigned char pad_1C4[0x1C];
    u_long128 field_1E0;
    unsigned char pad_1F0[0x1];
    unsigned char field_1F1;
    unsigned char field_1F2;
    unsigned char pad_1F3[0x2D];
    int field_220;
    unsigned char pad_224[0x4];
    UnkStruct_00361E60_1 * field_228;
};

extern UnkStruct_D_00522680 D_00522680;

// 0x00361E60
void CB3CrashCombo::DetectSkid()
{
    if (field_1BD != 0) {
        field_1E0 = field_228->field_204->field_30;
        field_1F1 = 0;
        field_1F2 = 0;
        field_220 = field_198;
        return;
    }
    float t0 = D_00522680.field_0;
    if (!(field_128 <= t0)) {
        return;
    }
    if (field_1F1 != 0 || !(field_1C0 <= 0.2f) || field_119 != 0) {
        field_1F1 = 1;
        return;
    }
    float len = field_228->field_B0.GetLength();
    if (field_228->field_20E != 0 || len < 5.0f) {
        field_1F1 = 1;
        return;
    }
    field_1F2 = 1;
}
