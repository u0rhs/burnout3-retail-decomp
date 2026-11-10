// CB3OnlineLobbyPage::SetupTableData() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (draftAA aa7b (745/745); re-queued by tidy1 after adding PROVIDE(D_01EA4808) (the +8 half of bss D_01EA4800) to config/undefined_syms_manual.txt).

// SetupTableData__18CB3OnlineLobbyPageFv -- CB3OnlineLobbyPage::SetupTableData() @ 0x00313B30
// [C] name: config/symbol_addrs_b3names.txt. Hand-written from the retail asm, shaped like the matched
// sibling func_003774D0 (CB3OnlineRecordsDisplayMenuPage::SetupTableData). Field names are placeholders;
// types [G] from instruction widths.
#include "b3/GtMathPs2.h"
class CGtTexture;
using GtMathPs2::CGtV2d;

// [G] a CGt2dObjectTable text cell's data (RenderText's const void* argument)
struct UnkStruct_00313B30_text {
    unsigned char pad_0[0x20];
    u_long128 field_20;          // colour
    CGtV2d field_30;
    unsigned char pad_38[0x8];
    float field_40;              // 24.0
    int field_44;                // D_00665ED8 (font?)
    unsigned short * field_48;   // text
    int field_4C;
};
// [G] a CGt2dObjectTable image cell's data (RenderImage's const void* argument)
struct UnkStruct_00313B30_image {
    u_long128 field_0;           // colour
    CGtV2d field_10;             // size?
    CGtV2d field_18;
    CGtV2d field_20;             // uv corner
    CGtV2d field_28;             // uv corner
    CGtTexture * field_30;       // texture
    unsigned char pad_34[0xC];
};
struct UnkStruct_00313B30_image2 {
    u_long128 field_0;
    CGtV2d field_10;
    CGtV2d field_18;
    CGtV2d field_20;
    CGtV2d field_28;
    CGtTexture * field_30;
    unsigned char pad_34[0xC];
    CGtV2d field_40;
    int field_48;
    unsigned char pad_4C[0x4];
};
struct UnkStruct_00313B30_rowinfo {
    unsigned char pad_0[0x10];
    CGtV2d field_10;
    CGtV2d field_18;
};
struct UnkStruct_00313B30_desc {
    float field_0;
    float field_4;
    unsigned char field_8;
};
struct UnkStruct_00313B30_entry {
    void * field_0;
    void * field_4;
    void * field_8;
};

class CB3OnlineLobbyPage {
public:
    void SetupTableData();

    unsigned char pad_0[0x60];
    CGtV2d field_60;
    int field_68;
    int field_6C;
    UnkStruct_00313B30_desc * field_70;
    UnkStruct_00313B30_desc * field_74;
    UnkStruct_00313B30_entry * field_78;
    int field_7C;
    UnkStruct_00313B30_desc field_80[7];
    UnkStruct_00313B30_desc field_D4[6];
    UnkStruct_00313B30_entry field_11C[7][6];
    unsigned char pad_314[0xC];
    UnkStruct_00313B30_text field_320;
    UnkStruct_00313B30_text field_370[6];
    UnkStruct_00313B30_text field_550[6];
    UnkStruct_00313B30_text field_730;
    UnkStruct_00313B30_text field_780;
    UnkStruct_00313B30_rowinfo field_7D0[6];
    UnkStruct_00313B30_image field_890[6];
    UnkStruct_00313B30_image field_A10[6][3];
    UnkStruct_00313B30_text field_E90;
    UnkStruct_00313B30_image field_EE0;
    UnkStruct_00313B30_image2 field_F20[6];
    UnkStruct_00313B30_image field_1100[6];
    unsigned char pad_1280[0xC4];
    unsigned short * field_1344[6];
    unsigned short * field_135C[6];
    int field_1374;
    unsigned short * field_1378;
    unsigned char pad_137C[0x4];
    unsigned short * field_1380;
};

struct UnkStruct_D_01E90240 {
    u_long128 field_0;
    unsigned char pad_10[0x100];
    u_long128 field_110;
};
struct UnkStruct_D_00665ED8 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
// [C] UV corners passed with the texture table D_01EA46B0 (same form as B3HeadingComponent_00319E80.cpp)
struct UnkStruct_D_01EA4790 {
    CGtV2d uv;
    unsigned char pad[0x100];
};

extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_00665ED8 D_00665ED8;
extern UnkStruct_D_0051BA44 D_0051BA44;
class CGtTexture;
extern CGtTexture * D_01EA46B0[0x38];
struct UnkStruct_D_01EA4674 { CGtTexture * field_0; unsigned char pad[0xC]; };
extern UnkStruct_D_01EA4674 D_01EA4674;
extern UnkStruct_D_01EA4790 D_01EA47A0, D_01EA47A8, D_01EA47B0, D_01EA47B8, D_01EA47D0, D_01EA47D8;
extern UnkStruct_D_01EA4790 D_01EA47E0, D_01EA47E8, D_01EA47F0, D_01EA47F8, D_01EA4790, D_01EA4798;
extern UnkStruct_D_01EA4790 D_01EA4800, D_01EA4808, D_01EA4810, D_01EA4818;
extern char D_004C5018[];
extern "C" unsigned short * func_00271A00(void *, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, unsigned short *, int);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);
extern "C" void RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);
extern "C" void _RenderImage__18CB3OnlineLobbyPageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(void *, void *, void *, void *, void *);
extern "C" void _GetImageSize__18CB3OnlineLobbyPageFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, const void *, void *);

// 0x00313B30
void CB3OnlineLobbyPage::SetupTableData()
{
    UnkStruct_D_01E90240 * const colours = &D_01E90240;
    int i, j;
    field_68 = 7;
    field_6C = 6;
    field_70 = field_80;
    field_74 = field_D4;
    field_78 = &field_11C[0][0];
    field_7C = field_1374;
    field_60 = CGtV2d(-1.0f, -1.0f);
    field_D4[0].field_0 = 5.0f; field_D4[0].field_4 = 24.0f; field_D4[0].field_8 = 0;
    field_D4[1].field_0 = 10.0f; field_D4[1].field_4 = 310.0f; field_D4[1].field_8 = 0;
    field_D4[2].field_0 = 5.0f; field_D4[2].field_4 = 74.0f; field_D4[2].field_8 = 0;
    field_D4[3].field_0 = 10.0f; field_D4[3].field_4 = 21.0f; field_D4[3].field_8 = 0;
    field_D4[4].field_0 = 5.0f; field_D4[4].field_4 = 32.0f; field_D4[4].field_8 = 0;
    field_D4[5].field_0 = 5.0f; field_D4[5].field_4 = 23.0f; field_D4[5].field_8 = 0;
    field_80[0].field_0 = 0.0f; field_80[0].field_4 = 24.0f; field_80[0].field_8 = 0;
    field_80[1].field_0 = 1.0f; field_80[1].field_4 = 24.0f; field_80[1].field_8 = 0;
    field_80[2].field_0 = 1.0f; field_80[2].field_4 = 24.0f; field_80[2].field_8 = 0;
    field_80[3].field_0 = 1.0f; field_80[3].field_4 = 24.0f; field_80[3].field_8 = 0;
    field_80[4].field_0 = 1.0f; field_80[4].field_4 = 24.0f; field_80[4].field_8 = 0;
    field_80[5].field_0 = 1.0f; field_80[5].field_4 = 24.0f; field_80[5].field_8 = 0;
    field_80[6].field_0 = 1.0f; field_80[6].field_4 = 24.0f; field_80[6].field_8 = 0;
    for (i = 0; i < 6; i++) {
        if (i == 1) {
            field_730.field_20 = colours->field_0;
            field_730.field_30 = CGtV2d(0.0f, 0.0f);
            field_730.field_40 = 24.0f;
            field_730.field_44 = D_00665ED8.field_0;
            field_730.field_4C = 0;
            field_730.field_48 = func_00271A00(&D_0051BA44, 0x3A9);
            field_730.field_48 = func_00271A00(&D_0051BA44, 0x3A9);
            field_730.field_30 = CGtV2d(0.0f, 0.0f);
        } else if (i == 2) {
            field_780.field_20 = colours->field_0;
            field_780.field_30 = CGtV2d(0.0f, 0.0f);
            field_780.field_40 = 24.0f;
            field_780.field_44 = D_00665ED8.field_0;
            field_780.field_4C = 0;
            field_780.field_48 = func_00271A00(&D_0051BA44, 0xC04);
            field_780.field_30 = CGtV2d(1.0f, 0.0f);
        } else {
            if (i == 3) {
                field_890[i].field_10 = CGtV2d(21.0f, 14.0f);
                field_890[i].field_20 = D_01EA47D0.uv;
                field_890[i].field_28 = D_01EA47D8.uv;
            } else if (i == 4) {
                field_890[i].field_10 = CGtV2d(21.0f, 11.0f);
                field_890[i].field_20 = D_01EA47A0.uv;
                field_890[i].field_28 = D_01EA47A8.uv;
            } else if (i == 5) {
                field_890[i].field_10 = CGtV2d(18.0f, 11.0f);
                field_890[i].field_20 = D_01EA47B0.uv;
                field_890[i].field_28 = D_01EA47B8.uv;
            }
            field_890[i].field_0 = colours->field_0;
            field_890[i].field_30 = D_01EA46B0[18];
            field_890[i].field_18 = CGtV2d(0.5f, 0.5f);
        }
    }
    field_320.field_20 = colours->field_0;
    field_320.field_30 = CGtV2d(0.5f, 0.0f);
    field_320.field_40 = 24.0f;
    field_320.field_44 = D_00665ED8.field_0;
    field_320.field_4C = 0;
    field_320.field_48 = field_1380;
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(D_004C5018, field_1380, 2);
    field_EE0.field_10 = CGtV2d(14.0f, 14.0f);
    field_EE0.field_0 = colours->field_0;
    field_EE0.field_30 = D_01EA46B0[18];
    field_EE0.field_20 = D_01EA4810.uv;
    field_EE0.field_28 = D_01EA4818.uv;
    field_EE0.field_18 = CGtV2d(0.0f, 0.5f);
    field_E90.field_20 = colours->field_0;
    field_E90.field_40 = 24.0f;
    field_E90.field_44 = D_00665ED8.field_0;
    field_E90.field_4C = 0;
    field_E90.field_48 = field_1378;
    field_E90.field_30 = CGtV2d(0.0f, 0.5f);
    for (i = 0; i < 6; i++) {
        field_370[i].field_20 = colours->field_0;
        field_370[i].field_40 = 24.0f;
        field_370[i].field_44 = D_00665ED8.field_0;
        field_370[i].field_4C = 0;
        field_370[i].field_48 = field_1344[i];
        field_370[i].field_30 = CGtV2d(0.0f, 0.0f);
        field_550[i].field_20 = colours->field_0;
        field_550[i].field_40 = 24.0f;
        field_550[i].field_44 = D_00665ED8.field_0;
        field_550[i].field_4C = 0;
        field_550[i].field_48 = field_135C[i];
        field_550[i].field_30 = CGtV2d(1.0f, 0.0f);
        field_7D0[i].field_18 = CGtV2d(42.0f, 21.0f);
        field_7D0[i].field_10 = CGtV2d(0.5f, 0.5f);
        field_A10[i][0].field_10 = CGtV2d(13.0f, 15.0f);
        field_A10[i][0].field_0 = colours->field_0;
        field_A10[i][0].field_30 = D_01EA46B0[18];
        field_A10[i][0].field_20 = D_01EA47E0.uv;
        field_A10[i][0].field_28 = D_01EA47E8.uv;
        field_A10[i][0].field_18 = CGtV2d(0.5f, 0.5f);
        field_A10[i][1].field_10 = CGtV2d(10.0f, 16.0f);
        field_A10[i][1].field_0 = colours->field_0;
        field_A10[i][1].field_30 = D_01EA46B0[18];
        field_A10[i][1].field_20 = D_01EA47F0.uv;
        field_A10[i][1].field_28 = D_01EA47F8.uv;
        field_A10[i][1].field_18 = CGtV2d(0.5f, 0.5f);
        field_A10[i][2].field_10 = CGtV2d(21.0f, 16.0f);
        field_A10[i][2].field_0 = colours->field_0;
        field_A10[i][2].field_30 = D_01EA46B0[18];
        field_A10[i][2].field_20 = D_01EA47D0.uv;
        field_A10[i][2].field_28 = D_01EA47D8.uv;
        field_A10[i][2].field_18 = CGtV2d(0.5f, 0.5f);
        field_1100[i].field_10 = CGtV2d(20.0f, 22.0f);
        field_1100[i].field_0 = colours->field_110;
        field_1100[i].field_30 = D_01EA4674.field_0;
        field_1100[i].field_20 = D_01EA4790.uv;
        field_1100[i].field_28 = D_01EA4798.uv;
        field_1100[i].field_18 = CGtV2d(0.5f, 0.5f);
        field_F20[i].field_10 = CGtV2d(3.0f, 12.0f);
        field_F20[i].field_0 = colours->field_0;
        field_F20[i].field_30 = D_01EA46B0[18];
        field_F20[i].field_20 = D_01EA4800.uv;
        field_F20[i].field_28 = D_01EA4808.uv;
        field_F20[i].field_18 = CGtV2d(0.0f, 0.0f);
        field_F20[i].field_48 = 0;
        field_F20[i].field_40 = CGtV2d(0.5f, 0.5f);
    }
    for (int r = 0; r < 7; r++) {
        for (int c = 0; c < 6; c++) {
            if (r == 0 && c == 1) {
                field_11C[r][c].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                field_11C[r][c].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                field_11C[r][c].field_8 = &field_730;
            } else if (r == 0 && c == 0) {
                field_11C[r][c].field_0 = 0;
                field_11C[r][c].field_4 = 0;
            } else if (r == 0 && c == 2) {
                field_11C[r][c].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                field_11C[r][c].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                field_11C[r][c].field_8 = &field_780;
            } else if (r == 0 && c == 5) {
                field_11C[r][c].field_0 = (void *)_RenderImage__18CB3OnlineLobbyPageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                field_11C[r][c].field_4 = (void *)_GetImageSize__18CB3OnlineLobbyPageFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                field_11C[r][c].field_8 = &field_890[c];
            } else if (r == 0) {
                field_11C[r][c].field_0 = (void *)RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                field_11C[r][c].field_4 = (void *)GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                field_11C[r][c].field_8 = &field_890[c];
            } else if (c == 0) {
                field_11C[r][c].field_0 = 0;
                field_11C[r][c].field_4 = 0;
                field_11C[r][c].field_8 = &field_1100[r - 1];
            } else if (c == 1) {
                field_11C[r][c].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                field_11C[r][c].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                field_11C[r][c].field_8 = &field_370[r - 1];
            } else if (c == 2) {
                field_11C[r][c].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                field_11C[r][c].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                field_11C[r][c].field_8 = &field_550[r - 1];
            } else if (c == 4) {
                field_11C[r][c].field_0 = 0;
                field_11C[r][c].field_4 = 0;
                field_11C[r][c].field_8 = &field_7D0[r - 1];
            } else if (c == 3) {
                field_11C[r][c].field_0 = 0;
                field_11C[r][c].field_4 = 0;
                field_11C[r][c].field_8 = &field_A10[r - 1][2];
            } else if (c == 5) {
                field_11C[r][c].field_0 = 0;
                field_11C[r][c].field_4 = 0;
                field_11C[r][c].field_8 = &field_F20[r - 1];
            }
        }
    }
}
