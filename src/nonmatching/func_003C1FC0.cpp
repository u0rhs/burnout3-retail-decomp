// NONMATCHING: func_003C1FC0 -- retail 137 / ours 141 instructions, 252 in changed runs
// logic believed right (table-data init: rows/cols/cells pointers, style at +0x1480, item template at +0x14C0, CGtV2d temps). Written as one D_01EA5630 object, which gives retail's CGtV2d copy shapes (ld/sd for +0, swc1 for the 0.0 temp) but the harness can't compare its sym+addend relocations; field-by-field externs compare but turn every CGtV2d store into ld/sd. Needs a harness that normalises addends, or per-address padded externs with member stores
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003C1FC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;

struct UnkStruct_003C1FC0_row {   // 12 bytes
    int field_0;
    int field_4;
    unsigned char field_8;
    unsigned char pad_9[0x3];
};

struct UnkStruct_003C1FC0_col {   // 12 bytes
    float field_0;
    float field_4;
    unsigned char field_8;
    unsigned char pad_9[0x3];
};

struct UnkStruct_003C1FC0_cell {  // 12 bytes
    int field_0;
    int field_4;
    int field_8;
};

struct UnkStruct_003C1FC0_style { // 0x40 bytes
    u_long128 field_0;
    CGtV2d field_10;
    CGtV2d field_18;
    float field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    unsigned char pad_34[0xC];
};

struct UnkStruct_003C1FC0_item {  // 0x50 bytes
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    CGtV2d field_30;
    CGtV2d field_38;
    float field_40;
    int field_44;
    int field_48;
    int field_4C;
};

// [G] one object from D_01EA5630 (every address below is an offset into it)
struct UnkStruct_D_01EA5630 {
    CGtV2d field_0;
    int field_8;
    int field_C;
    UnkStruct_003C1FC0_row * field_10;
    UnkStruct_003C1FC0_col * field_14;
    UnkStruct_003C1FC0_cell (* field_18)[5];
    void * field_1C;
    UnkStruct_003C1FC0_row field_20[9];
    unsigned char pad_8C[0x4];
    UnkStruct_003C1FC0_col field_90[5];
    unsigned char pad_CC[0x1194];
    UnkStruct_003C1FC0_cell field_1260[9][5];
    unsigned char pad_147C[0x4];
    UnkStruct_003C1FC0_style field_1480;
    UnkStruct_003C1FC0_item field_14C0;
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
    unsigned char pad_20[0xF0];
    u_long128 field_110;
};

struct UnkStruct_D_00665ED0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA77C0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01EA5630 D_01EA5630;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_01EA77C0 D_01EA77C0;

// 0x003C1FC0
extern "C" void func_003C1FC0()
{
    D_01EA5630.field_C = 5;
    D_01EA5630.field_1C = &D_01EA77C0;
    D_01EA5630.field_0 = CGtV2d(-1.0f, -1.0f);
    D_01EA5630.field_10 = D_01EA5630.field_20;
    D_01EA5630.field_14 = D_01EA5630.field_90;
    D_01EA5630.field_18 = D_01EA5630.field_1260;
    for (int i = 0; i < 9; i++) {
        D_01EA5630.field_20[i].field_8 = 1;
        D_01EA5630.field_20[i].field_4 = 0;
        D_01EA5630.field_20[i].field_0 = 0;
        for (int j = 0; j < 5; j++) {
            D_01EA5630.field_1260[i][j].field_0 = 0;
            D_01EA5630.field_1260[i][j].field_8 = 0;
            D_01EA5630.field_1260[i][j].field_4 = 0;
        }
    }
    for (int k = 0; k < 5; k++) {
        D_01EA5630.field_90[k].field_8 = 0;
        D_01EA5630.field_90[k].field_4 = 0;
        D_01EA5630.field_90[k].field_0 = 0;
    }
    D_01EA5630.field_1480.field_0 = D_01E90240.field_110;
    D_01EA5630.field_1480.field_10 = CGtV2d(0.0f, 0.0f);
    D_01EA5630.field_1480.field_18 = CGtV2d(1.4f, 1.4f);
    D_01EA5630.field_1480.field_20 = 25.0f;
    D_01EA5630.field_1480.field_24 = D_00665ED0.field_0;
    D_01EA5630.field_1480.field_28 = 0;
    D_01EA5630.field_1480.field_2C = 1;
    D_01EA5630.field_1480.field_30 = 1;
    D_01EA5630.field_14C0.field_20 = D_01E90240.field_10;
    D_01EA5630.field_14C0.field_30 = CGtV2d(0.5f, 0.5f);
    D_01EA5630.field_14C0.field_38 = CGtV2d(1.4f, 1.4f);
    D_01EA5630.field_14C0.field_40 = 25.0f;
    D_01EA5630.field_14C0.field_44 = D_00665ED0.field_0;
    D_01EA5630.field_14C0.field_48 = 0;
    D_01EA5630.field_14C0.field_4C = 2;
    D_01EA5630.field_10 = D_01EA5630.field_20;
    D_01EA5630.field_14 = D_01EA5630.field_90;
    D_01EA5630.field_18 = D_01EA5630.field_1260;
}
