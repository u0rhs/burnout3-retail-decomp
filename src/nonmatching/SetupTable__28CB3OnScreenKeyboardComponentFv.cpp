// NONMATCHING: SetupTable__28CB3OnScreenKeyboardComponentFv -- retail 1009 / ours 962 instructions, 640 in changed runs
// retail 1009 / ours 962: every store/branch from the asm; left: loop-invariant hoisting (retail spills more key/colour loads to stack, frame 0x390 vs 0x340), per-branch index recomputation counts, CGtV2d temp slots
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm + Ghidra draft: 5x15 cell loop (enable flag chain, render-fn selection, 4 help-image cells with texture-name lookup, 2 arrow cells, per-cell init and size chain), 7 trailing string lookups; every store accounted for

// CB3OnScreenKeyboardComponent::SetupTable -- hand-written (draft2) from the retail asm + Ghidra draft; never attempted before.
// [C] name: the mangled symbol. Struct layout from the instruction offsets; field names are placeholders, types [G].
// Same table layout as SetupTable__21CB3OnlineJoinGamePageFv (row/col descs {float,float,u8}, 12-byte entries
// {render fn, size fn, data}); CB3OnScreenKeyboardCell::operator== as in the proven B3OnScreenKeyboardComponent_003509C0.cpp.
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;

class CB3OnScreenKeyboardCell { public: int field_0; int field_4;
    bool operator==(const CB3OnScreenKeyboardCell &o) const { int b = o.field_4; bool r = field_0 == o.field_0; if (r) r = field_4 == b; return r; } };
struct UnkStruct_kKey { CB3OnScreenKeyboardCell c; };
extern const UnkStruct_kKey kB3OnScreenKeyboardShiftHelpKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardCapsLockHelpKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardAlphabetHelpKey;
extern const UnkStruct_kKey D_004C7000;   // [G] fourth help key (unnamed, between AlphabetHelpKey and ShiftKey)
extern const UnkStruct_kKey kB3OnScreenKeyboardShiftKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardCapsLockKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardAlphabetKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardAccentsKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardBackspaceKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardSpaceKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardDoneKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardLeftArrowKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardRightArrowKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardBlankKey;
extern u_long128 kB3OnScreenKeyboardUnSelectedBoxColour;
extern u_long128 D_004C7060;
extern const CGtV2d D_004C70D0;                    // [G] help button 0 size (label split from the next symbol)
extern const CGtV2d kB3KeyboardHelpButtonSize[3];
extern const char kB3KeyboardHelpButtonTexture[];  // three 9-byte names (+0, +9, +0x12)
extern const char D_004C710B[];                    // fourth name
struct UnkStruct_D_01E90240 { u_long128 field_0; unsigned char pad_10[0x30]; u_long128 field_40; };
extern UnkStruct_D_01E90240 D_01E90240;
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_I D_00665ED8;
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };   // [G] size: absolute addressing needs > 8 bytes (N50)
extern UnkStruct_F D_01EA3F40, D_01EA3F44, D_01EA3F48, D_01EA3F4C, D_01EA3F50, D_01EA3F54, D_01EA3F58, D_01EA3F5C,
    D_01EA3F60, D_01EA3F64, D_01EA3F68, D_01EA3F6C, D_01EA3F70, D_01EA3F74, D_01EA3F78, D_01EA3F7C;
struct UnkStruct_0034F860_te { unsigned char pad_0[0x8]; int field_8; unsigned char pad_C[0x4]; };
struct UnkStruct_0034F860_td { unsigned char pad_0[0x8]; int field_8; UnkStruct_0034F860_te * field_C; };
struct UnkStruct_D_0051A868 { UnkStruct_0034F860_td * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051A868 D_0051A868;
struct UnkStruct_0034F860_blk { unsigned char pad_0[0x18]; char field_18[8]; };
extern "C" int strcasecmp(const char *, const void *);
extern char D_0051BA44[];
extern "C" int func_00271A00(void *, int);
extern "C" void RenderCell__28CB3OnScreenKeyboardComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(void *, void *, void *, void *, void *);
extern "C" void RenderCellWithTriangle__28CB3OnScreenKeyboardComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(void *, void *, void *, void *, void *);
extern "C" void RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetTableCellSize__28CB3OnScreenKeyboardComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, void *);

struct UnkStruct_0034F860_desc { float field_0; float field_4; unsigned char field_8; unsigned char pad_9[0x3]; };
struct UnkStruct_0034F860_entry { void * field_0; void * field_4; void * field_8; };
struct UnkStruct_0034F860_cell {        // 0x90: text cell
    unsigned char pad_0[0x20];
    u_long128 field_20;
    CGtV2d field_30;
    unsigned char pad_38[0x8];
    float field_40;
    int field_44;
    int field_48;
    int field_4C;
    u_long128 field_50;
    unsigned char pad_60[0x8];
    CGtV2d field_68;
    CGtV2d field_70;
    CGtV2d field_78;
    unsigned char field_80;
    unsigned char field_81;
    unsigned char pad_82[0xE];
};
struct UnkStruct_0034F860_img {         // 0x40: help-button image
    u_long128 field_0;
    CGtV2d field_10;
    CGtV2d field_18;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    int field_30;
    unsigned char pad_34[0xC];
};
struct UnkStruct_0034F860_tri {         // 0x40: arrow cell
    u_long128 field_0;
    unsigned char pad_10[0x8];
    CGtV2d field_18;
    u_long128 field_20;
    CGtV2d field_30;
    unsigned char field_38;
    unsigned char field_39;
    unsigned char field_3A;
    unsigned char pad_3B[0x5];
};
class CB3OnScreenKeyboardComponent {
public:
    void SetupTable();

    unsigned char pad_0[0x28];
    CGtV2d field_28;
    int field_30;
    int field_34;
    UnkStruct_0034F860_desc * field_38;
    UnkStruct_0034F860_desc * field_3C;
    UnkStruct_0034F860_entry * field_40;
    int field_44;
    unsigned char pad_48[0x8];
    UnkStruct_0034F860_desc field_50[5];
    UnkStruct_0034F860_desc field_8C[15];
    UnkStruct_0034F860_entry field_140[5][15];
    UnkStruct_0034F860_img field_4D0[4];
    UnkStruct_0034F860_cell field_5D0[5][15];
    UnkStruct_0034F860_tri field_3000;
    UnkStruct_0034F860_tri field_3040;
    unsigned char pad_3080[0x58];
    int field_30D8;
    int field_30DC[5][15];
};

// texture lookup by name in the frontend dictionary (inlined in retail; as B3MenuImages_00371870.cpp)
static inline int func_0034F860_inl1(const void * name)
{
    int t;
    UnkStruct_0034F860_td * d = D_0051A868.field_0;
    int i;
    for (i = 0; i < d->field_8; i++) {
        t = d->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_0034F860_blk *)(t + 0x90))->field_18, name) == 0) {
            goto found;
        }
    }
    t = 0;
found:
    return t;
}

void CB3OnScreenKeyboardComponent::SetupTable()
{
    UnkStruct_D_01E90240 * const colours = &D_01E90240;
    int i;
    int j;
    field_30 = 5;
    field_34 = 15;
    field_38 = field_50;
    field_3C = field_8C;
    field_40 = &field_140[0][0];
    field_44 = 0;
    field_28 = CGtV2d(-1.0f, -1.0f);
    field_50[0].field_0 = 0.0f; field_50[0].field_4 = 29.0f; field_50[0].field_8 = 0;
    field_50[1].field_0 = 9.0f; field_50[1].field_4 = 29.0f; field_50[1].field_8 = 0;
    field_50[2].field_0 = 4.0f; field_50[2].field_4 = 29.0f; field_50[2].field_8 = 0;
    field_50[3].field_0 = 4.0f; field_50[3].field_4 = 29.0f; field_50[3].field_8 = 0;
    field_50[4].field_0 = 4.0f; field_50[4].field_4 = 29.0f; field_50[4].field_8 = 0;
    field_8C[0].field_0 = 0.0f; field_8C[0].field_4 = 29.0f; field_8C[0].field_8 = 0;
    field_8C[1].field_0 = 2.0f; field_8C[1].field_4 = 76.0f; field_8C[1].field_8 = 0;
    for (i = 2; i < 15; i++) {
        if (i == 1 || i == 12) {
            field_8C[i].field_0 = 9.0f;
        } else {
            field_8C[i].field_0 = 4.0f;
        }
        field_8C[i].field_4 = 29.0f;
        field_8C[i].field_8 = 0;
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 15; j++) {
            CB3OnScreenKeyboardCell cell;
            cell.field_0 = i;
            cell.field_4 = j;
            if (i == 0 && j != 1) {
                field_5D0[i][j].field_81 = 0;
            } else if (i == kB3OnScreenKeyboardBackspaceKey.c.field_0 && j > kB3OnScreenKeyboardBackspaceKey.c.field_4 && j < kB3OnScreenKeyboardLeftArrowKey.c.field_4) {
                field_5D0[i][j].field_81 = 0;
            } else if (i == kB3OnScreenKeyboardSpaceKey.c.field_0 && j > kB3OnScreenKeyboardSpaceKey.c.field_4 && j < kB3OnScreenKeyboardDoneKey.c.field_4) {
                field_5D0[i][j].field_81 = 0;
            } else if (i == kB3OnScreenKeyboardDoneKey.c.field_0 && j > kB3OnScreenKeyboardDoneKey.c.field_4 && j < kB3OnScreenKeyboardLeftArrowKey.c.field_4) {
                field_5D0[i][j].field_81 = 0;
            } else if (i == kB3OnScreenKeyboardBlankKey.c.field_0 && j == kB3OnScreenKeyboardBlankKey.c.field_4) {
                field_5D0[i][j].field_81 = 0;
            } else if (j < 1 && !(cell == kB3OnScreenKeyboardShiftHelpKey.c) && !(cell == kB3OnScreenKeyboardCapsLockHelpKey.c)
                       && !(cell == kB3OnScreenKeyboardAlphabetHelpKey.c) && !(cell == D_004C7000.c)) {
                field_5D0[i][j].field_81 = 0;
            } else {
                field_5D0[i][j].field_81 = 1;
            }
            if (cell == kB3OnScreenKeyboardLeftArrowKey.c || cell == kB3OnScreenKeyboardRightArrowKey.c) {
                field_140[i][j].field_0 = (void *)RenderCellWithTriangle__28CB3OnScreenKeyboardComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                if (j == kB3OnScreenKeyboardLeftArrowKey.c.field_4) {
                    field_140[i][j].field_8 = &field_3000;
                    field_3000.field_0 = kB3OnScreenKeyboardUnSelectedBoxColour;
                    field_3000.field_18 = CGtV2d(29.0f, 29.0f);
                    field_3000.field_38 = 0;
                    field_3000.field_39 = 1;
                    field_3000.field_3A = 1;
                    field_3000.field_20 = colours->field_0;
                    field_3000.field_30 = CGtV2d(0.5f, 0.5f);
                } else {
                    field_140[i][j].field_8 = &field_3040;
                    field_3040.field_0 = kB3OnScreenKeyboardUnSelectedBoxColour;
                    field_3040.field_18 = CGtV2d(29.0f, 29.0f);
                    field_3040.field_38 = 0;
                    field_3040.field_39 = 1;
                    field_3040.field_3A = 0;
                    field_3040.field_20 = colours->field_0;
                    field_3040.field_30 = CGtV2d(0.5f, 0.5f);
                }
            } else if (cell == kB3OnScreenKeyboardShiftHelpKey.c) {
                field_140[i][j].field_0 = (void *)RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                field_140[i][j].field_8 = &field_4D0[0];
                field_4D0[0].field_10 = D_004C70D0;
                field_4D0[0].field_0 = D_004C7060;
                field_4D0[0].field_30 = func_0034F860_inl1(&kB3KeyboardHelpButtonTexture[0]);
                field_4D0[0].field_20 = D_01EA3F40.field_0; field_4D0[0].field_24 = D_01EA3F44.field_0;
                field_4D0[0].field_28 = D_01EA3F48.field_0; field_4D0[0].field_2C = D_01EA3F4C.field_0;
                field_4D0[0].field_18 = CGtV2d(0.5f, 0.5f);
            } else if (cell == kB3OnScreenKeyboardCapsLockHelpKey.c) {
                field_140[i][j].field_0 = (void *)RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                field_140[i][j].field_8 = &field_4D0[1];
                field_4D0[1].field_10 = kB3KeyboardHelpButtonSize[0];
                field_4D0[1].field_0 = D_004C7060;
                field_4D0[1].field_30 = func_0034F860_inl1(&kB3KeyboardHelpButtonTexture[9]);
                field_4D0[1].field_20 = D_01EA3F50.field_0; field_4D0[1].field_24 = D_01EA3F54.field_0;
                field_4D0[1].field_28 = D_01EA3F58.field_0; field_4D0[1].field_2C = D_01EA3F5C.field_0;
                field_4D0[1].field_18 = CGtV2d(0.5f, 0.5f);
            } else if (cell == kB3OnScreenKeyboardAlphabetHelpKey.c) {
                field_140[i][j].field_0 = (void *)RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                field_140[i][j].field_8 = &field_4D0[2];
                field_4D0[2].field_10 = kB3KeyboardHelpButtonSize[1];
                field_4D0[2].field_0 = D_004C7060;
                field_4D0[2].field_30 = func_0034F860_inl1(&kB3KeyboardHelpButtonTexture[0x12]);
                field_4D0[2].field_20 = D_01EA3F60.field_0; field_4D0[2].field_24 = D_01EA3F64.field_0;
                field_4D0[2].field_28 = D_01EA3F68.field_0; field_4D0[2].field_2C = D_01EA3F6C.field_0;
                field_4D0[2].field_18 = CGtV2d(0.5f, 0.5f);
            } else if (cell == D_004C7000.c) {
                field_140[i][j].field_0 = (void *)RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                field_140[i][j].field_8 = &field_4D0[3];
                field_4D0[3].field_10 = kB3KeyboardHelpButtonSize[2];
                field_4D0[3].field_0 = D_004C7060;
                field_4D0[3].field_30 = func_0034F860_inl1(D_004C710B);
                field_4D0[3].field_20 = D_01EA3F70.field_0; field_4D0[3].field_24 = D_01EA3F74.field_0;
                field_4D0[3].field_28 = D_01EA3F78.field_0; field_4D0[3].field_2C = D_01EA3F7C.field_0;
                field_4D0[3].field_18 = CGtV2d(0.5f, 0.5f);
            } else {
                field_140[i][j].field_0 = (void *)RenderCell__28CB3OnScreenKeyboardComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                field_140[i][j].field_8 = &field_5D0[i][j];
            }
            field_140[i][j].field_4 = (void *)GetTableCellSize__28CB3OnScreenKeyboardComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
            field_5D0[i][j].field_78 = CGtV2d(-1.0f, -1.0f);
            field_5D0[i][j].field_80 = 0;
            field_5D0[i][j].field_70 = CGtV2d(0.0f, 0.0f);
            field_5D0[i][j].field_50 = kB3OnScreenKeyboardUnSelectedBoxColour;
            field_5D0[i][j].field_20 = colours->field_0;
            field_5D0[i][j].field_30 = CGtV2d(0.5f, 0.5f);
            field_5D0[i][j].field_40 = 25.0f;
            field_5D0[i][j].field_44 = D_00665ED8.field_0;
            field_5D0[i][j].field_4C = 0;
            field_5D0[i][j].field_48 = field_30DC[i][j];
            if (j == 1) {
                if (i == 0) {
                    field_5D0[i][j].field_40 = 29.0f;
                    field_5D0[i][j].field_30 = CGtV2d(0.0f, 0.5f);
                    field_5D0[i][j].field_68 = CGtV2d(516.0f, 29.0f);
                    field_5D0[i][j].field_80 = 1;
                    field_5D0[i][j].field_70 = CGtV2d(5.0f, -1.0f);
                    field_5D0[i][j].field_48 = field_30D8;
                } else {
                    field_5D0[i][j].field_68 = CGtV2d(76.0f, 29.0f);
                }
            } else if (cell == kB3OnScreenKeyboardSpaceKey.c) {
                field_5D0[i][j].field_68 = CGtV2d(194.0f, 29.0f);
                field_5D0[i][j].field_80 = 1;
            } else if (cell == kB3OnScreenKeyboardDoneKey.c) {
                field_5D0[i][j].field_68 = CGtV2d(128.0f, 29.0f);
                field_5D0[i][j].field_80 = 1;
            } else if (cell == kB3OnScreenKeyboardBackspaceKey.c) {
                field_5D0[i][j].field_68 = CGtV2d(95.0f, 29.0f);
                field_5D0[i][j].field_80 = 1;
            } else {
                field_5D0[i][j].field_68 = CGtV2d(29.0f, 29.0f);
            }
        }
    }
    field_5D0[kB3OnScreenKeyboardShiftKey.c.field_0][kB3OnScreenKeyboardShiftKey.c.field_4].field_48 = func_00271A00(D_0051BA44, 0x289);
    field_5D0[kB3OnScreenKeyboardCapsLockKey.c.field_0][kB3OnScreenKeyboardCapsLockKey.c.field_4].field_48 = func_00271A00(D_0051BA44, 0x28A);
    field_5D0[kB3OnScreenKeyboardAlphabetKey.c.field_0][kB3OnScreenKeyboardAlphabetKey.c.field_4].field_48 = func_00271A00(D_0051BA44, 0x28D);
    field_5D0[kB3OnScreenKeyboardAccentsKey.c.field_0][kB3OnScreenKeyboardAccentsKey.c.field_4].field_48 = func_00271A00(D_0051BA44, 0x28C);
    field_5D0[kB3OnScreenKeyboardBackspaceKey.c.field_0][kB3OnScreenKeyboardBackspaceKey.c.field_4].field_48 = func_00271A00(D_0051BA44, 0x291);
    field_5D0[kB3OnScreenKeyboardSpaceKey.c.field_0][kB3OnScreenKeyboardSpaceKey.c.field_4].field_48 = func_00271A00(D_0051BA44, 0x290);
    field_5D0[kB3OnScreenKeyboardDoneKey.c.field_0][kB3OnScreenKeyboardDoneKey.c.field_4].field_48 = func_00271A00(D_0051BA44, 0x292);
}
