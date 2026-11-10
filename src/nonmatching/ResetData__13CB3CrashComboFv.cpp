// NONMATCHING: ResetData__13CB3CrashComboFv -- retail 105 / ours 105 instructions, 2 in changed runs
// ghvu5: 2 off -- retail hoists mtc1 zero,f0 for the field_128 = 0.0f store (swc1) after the daddu a3; a plain literal gives sw zero; here a float local + scoped opt_propagation off [G] + do-while loops gives the swc1 but the mtc1 is scheduled before the daddu. Without pragma (zero stand-ins only) it is 1 instr off (sw zero vs mtc1/swc1).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3CrashCombo::ResetData() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3CrashCombo;
struct UnkStruct_003640C0_e0;

struct UnkStruct_003640C0_e0 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

class CB3CrashCombo {
public:
    void ResetData();

    UnkStruct_003640C0_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_10[0xF0];
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    unsigned char field_118;
    unsigned char field_119;
    unsigned char field_11A;
    unsigned char field_11B;
    unsigned char field_11C;
    unsigned char pad_11D[0x3];
    float field_120;
    float field_124;
    float field_128;
    int field_12C;
    GtMathPs2::CGtV3d field_130;
    GtMathPs2::CGtV3d field_140;
    GtMathPs2::CGtV3d field_150;
    unsigned char field_160[1];  // [G] element count unknown
    unsigned char pad_161[0x3];
    int field_164[1];  // [G] element count unknown
    unsigned char pad_168[0x8];
    int field_170[1];  // [G] element count unknown
    unsigned char pad_174[0x8];
    int field_17C;
    int field_180[1];  // [G] element count unknown
    unsigned char pad_184[0x8];
    int field_18C[1];  // [G] element count unknown
    unsigned char pad_190[0x8];
    int field_198;
    int field_19C[1];  // [G] element count unknown
    unsigned char pad_1A0[0x18];
    int field_1B8;
    unsigned char field_1BC;
    unsigned char field_1BD;
    unsigned char field_1BE;
    unsigned char pad_1BF[0x1];
    int field_1C0;
    int field_1C4;
    int field_1C8;
    unsigned char pad_1CC[0x4];
    int field_1D0;
    int field_1D4;
    int field_1D8;
    unsigned char pad_1DC[0x4];
    GtMathPs2::CGtV3d field_1E0;
    unsigned char field_1F0;
    unsigned char field_1F1;
    unsigned char field_1F2;
    unsigned char field_1F3;
    unsigned char field_1F4;
    unsigned char pad_1F5[0x3];
    int field_1F8;
    int field_1FC;
    int field_200;
    int field_204[1];  // [G] element count unknown
    unsigned char pad_208[0x18];
    int field_220;
    unsigned char pad_224[0x8];
    short field_22C;
    unsigned char field_22E;
    unsigned char pad_22F[0x1];
    int field_230[1];  // [G] element count unknown
    unsigned char pad_234[0xFC];
    int field_330;
    int field_334;
    int field_338;
    int field_33C;
    int field_340;
    int field_344;
    int field_348;
};

// [L] N185: stands in for the header Zero() (retail: compiler-chosen registers vf3/vf2/vf1, sqc2 straight to the field)
#define ZERO_V3(v) { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); (v).mData = r; }
// N182: opt_propagation off, [G] scoped to this function
#pragma push
#pragma opt_propagation off
// 0x003640C0
void CB3CrashCombo::ResetData()
{
    float z = 0.0f;
    {
        int i = 0;
        do {
            field_0[i].field_4 = 31;
            field_0[i].field_8 = 0;
            field_0[i].field_0 = 0;
            field_0[i].field_C = 0;
            i++;
        } while (i < 16);
    }
    field_100 = 0;
    field_104 = 0;
    field_108 = 0;
    field_118 = 0;
    field_119 = 0;
    field_10C = 0;
    field_110 = 0;
    field_114 = 0;
    field_11A = 0;
    field_11B = 0;
    field_11C = 0;
    field_120 = -1.0f;
    field_124 = -1.0f;
    field_128 = z;
    field_12C = 0;
    ZERO_V3(field_130);
    ZERO_V3(field_140);
    ZERO_V3(field_150);
    field_17C = 0;
    field_1B8 = 0;
    field_198 = 0;
    {
        int i1 = 0;
        do {
            field_160[i1] = 0;
            field_164[i1] = 0;
            field_170[i1] = 0;
            field_180[i1] = 0;
            field_18C[i1] = 0;
            i1++;
        } while (i1 < 3);
    }
    {
        int i2 = 0;
        do {
            field_19C[i2] = 0;
            i2++;
        } while (i2 < 7);
    }
    field_1BC = 0;
    field_1BD = 0;
    field_1BE = 0;
    field_1C0 = 0;
    field_1C4 = 0;
    field_1C8 = 0;
    field_1D4 = 0;
    field_1D8 = 0;
    field_1D0 = 0;
    ZERO_V3(field_1E0);
    field_1F0 = 0;
    field_1F1 = 0;
    field_1F2 = 0;
    field_1F3 = 0;
    field_1F4 = 0;
    field_1F8 = 0;
    field_1FC = 0;
    field_200 = 0;
    field_220 = 0;
    {
        int i3 = 0;
        do {
            field_204[i3] = 0;
            i3++;
        } while (i3 < 7);
    }
    field_22C = -1;
    field_22E = 0;
    field_330 = 0;
    field_334 = 0;
    field_338 = 0;
    field_33C = 0;
    field_340 = 0;
    field_344 = 0;
    field_348 = 0;
    {
        int i4 = 0;
        do {
            field_230[i4] = 0;
            i4++;
        } while (i4 < 64);
    }
}
#pragma pop


