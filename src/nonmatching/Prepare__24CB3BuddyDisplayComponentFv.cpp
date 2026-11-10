// NONMATCHING: Prepare__24CB3BuddyDisplayComponentFv -- retail 419 / ours 423 instructions, 264 in changed runs
// L269 first full draft (extern C with the a1 buffer param [G]): logic complete, 419/423 instrs, 264 in changed runs. Open: retail keeps the seven loop-invariant CGtV2d constants in memory (sw bits, then hoisted lwc1 -- probably by-value args of an inline cell-setup helper); hoists the 10 table/UV luis into s2-s7/fp/t5-t9; per-iteration CGtV4d(1,1,1,1) stack temps at 0xD0/0xC0; column if-chain 3,2,0,1 with bodies 3/2/0 out of line after the epilogue; header-cell (0,0.5) temp at 0x148. Texture/UV globals follow B3HeadingComponent_00319E80 (D_01EA46B0[0x12], D_01EA4790/98/D0/D8 uv).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_003677B0_row { float field_0; float field_4; unsigned char field_8; };
struct UnkStruct_003677B0_ent { void * field_0; void * field_4; void * field_8; };
struct UnkStruct_003677B0_img {
    CGtV4d field_0;
    CGtV2d field_10;
    CGtV2d field_18;
    CGtV2d field_20;
    CGtV2d field_28;
    int field_30;
    unsigned char pad_34[0xC];
};
struct UnkStruct_003677B0_txt {
    unsigned char pad_0[0x20];
    u_long128 field_20;
    CGtV2d field_30;
    unsigned char pad_38[0x8];
    float field_40;
    int field_44;
    void * field_48;
    int field_4C;
};
struct UnkStruct_003677B0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    int field_C;
    unsigned char field_10;
    unsigned char pad_11[0x7];
    CGtV2d field_18;
    int field_20;
    int field_24;
    UnkStruct_003677B0_row * field_28;
    UnkStruct_003677B0_row * field_2C;
    UnkStruct_003677B0_ent * field_30;
    char * field_34;
    UnkStruct_003677B0_row field_38[10];
    UnkStruct_003677B0_row field_B0[4];
    UnkStruct_003677B0_ent field_E0[10][4];
    UnkStruct_003677B0_img field_2C0[9];
    UnkStruct_003677B0_img field_500[9];
    UnkStruct_003677B0_txt field_740[9];
    UnkStruct_003677B0_txt field_A10[9];
    UnkStruct_003677B0_txt field_CE0[2];
    UnkStruct_003677B0_txt field_D80;
    UnkStruct_003677B0_txt field_DD0;
    char * field_E20[9];
    unsigned short * field_E44[9];
    char * field_E68;
    void * field_E6C;
    void * field_E70;
    CGtV2d * field_E74;
    short field_E78;
    short field_E7A;
    int field_E7C;
    int field_E80;
    unsigned char field_E84;
};
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_V2dPad { CGtV2d field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_D_00665ED8 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x14]; void * field_14; unsigned char pad_18[0x8]; };
struct UnkStruct_D_01E90240 { u_long128 field_0; unsigned char pad_10[0x10]; u_long128 field_20; unsigned char pad_30[0xD0]; CGtV4d field_100; };
struct UnkStruct_D_01E3D4B0 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E3D4A8 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_00665ED8 D_00665ED8;
extern UnkStruct_D_Pad16 D_0051BA44, D_01E3D390;
extern UnkStruct_D_01E3D4B0 D_01E3D4B0;
extern UnkStruct_D_01E3D4A8 D_01E3D4A8;
extern UnkStruct_D_V2dPad kB3BuddyDisplayPos, krB3BuddyTableSize, krB3BuddyBackgroundSize;
struct UnkStruct_D_01EA4670 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01EA4670 D_01EA4670;
extern int D_01EA46B0[0x38];   // [L] the texture table of B3HeadingComponent_00319E80.cpp ([0x12] here)
struct UnkStruct_D_01EA4790 { CGtV2d uv; unsigned char pad[0x100]; };   // as B3HeadingComponent_00319E80.cpp
extern UnkStruct_D_01EA4790 D_01EA4790, D_01EA4798, D_01EA47D0, D_01EA47D8;
extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" void * ConstructChild__10CGt2dFrameFv(void *);
extern "C" void SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(void *);
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void * func_00271A00(void *, int);
extern "C" bool Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, unsigned int, int);
extern "C" void Prepare__16CGt2dObjectTableFPC20CGt2dObjectTableDataRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(void *, const void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, const void *);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);
extern "C" void GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);
extern "C" void RecalculateSize__16CGt2dObjectTableFv(void *);
extern "C" void func_00366980(void *, int);
extern "C" int GetNumBuddies__22CGtBuddiesPS2DirtySockFv(void *);
extern "C" void GetBuddyName__22CGtBuddiesPS2DirtySockFiPc(void *, int, char *);
extern "C" void * HLBListGetBuddyByName(int, char *);
extern "C" int HLBMsgListGetTotalCount(void *);

// 0x003677B0
extern "C" bool Prepare__24CB3BuddyDisplayComponentFv(UnkStruct_003677B0 * self, char * buf)
{
    Prepare__20CB3MenuComponentBaseFv(self);
    int i;
    for (i = 0; i < 9; i++) {
        self->field_E20[i] = buf;
        self->field_E44[i] = (unsigned short *)(buf + 0xC8);
        buf += 0xE8;
    }
    self->field_E68 = buf;
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    self->field_E80 = 0;
    self->field_E84 = 0;
    self->field_E7C = 0;
    self->field_E78 = 0;
    self->field_E7A = 1;
    self->field_E74 = (CGtV2d *)ConstructChild__10CGt2dFrameFv(scene->field_14);
    SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(self->field_E74);
    *self->field_E74 = kB3BuddyDisplayPos.field_0;
    self->field_E70 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8, self->field_E74);
    Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(self->field_E70, CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 0.0f), krB3BuddyBackgroundSize.field_0, 0x1F, 0);
    self->field_E6C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 2, self->field_E74);
    Prepare__16CGt2dObjectTableFPC20CGt2dObjectTableDataRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(self->field_E6C, &self->field_18, CGtV2d(0.0f, 1.0f), CGtV2d(0.0f, 0.0f), krB3BuddyTableSize.field_0, &mgr->field_100);
    self->field_20 = 10;
    self->field_24 = 4;
    self->field_28 = self->field_38;
    self->field_2C = self->field_B0;
    self->field_30 = &self->field_E0[0][0];
    self->field_34 = self->field_E68;
    self->field_18 = krB3BuddyTableSize.field_0;
    self->field_B0[0].field_0 = 9.0f; self->field_B0[0].field_4 = 24.0f; self->field_B0[0].field_8 = 1;
    self->field_B0[1].field_0 = 10.0f; self->field_B0[1].field_4 = 24.0f; self->field_B0[1].field_8 = 1;
    self->field_B0[2].field_0 = 10.0f; self->field_B0[2].field_4 = 155.0f; self->field_B0[2].field_8 = 0;
    self->field_B0[3].field_0 = 10.0f; self->field_B0[3].field_4 = 0.0f; self->field_B0[3].field_8 = 1;
    self->field_38[0].field_0 = 1.0f; self->field_38[0].field_4 = 24.0f; self->field_38[0].field_8 = 0;
    for (i = 1; i < 10; i++) {
        self->field_38[i].field_0 = 1.0f; self->field_38[i].field_4 = 24.0f; self->field_38[i].field_8 = 0;
    }
    self->field_D80.field_20 = mgr->field_20;
    self->field_D80.field_40 = 24.0f;
    self->field_D80.field_44 = D_00665ED8.field_0;
    self->field_D80.field_4C = 0;
    self->field_D80.field_48 = func_00271A00(&D_0051BA44, 0x15);
    self->field_D80.field_30 = CGtV2d(0.0f, 0.5f);
    CGtV2d h(0.0f, 0.5f);
    self->field_DD0.field_20 = mgr->field_20;
    self->field_DD0.field_40 = 24.0f;
    self->field_DD0.field_44 = D_00665ED8.field_0;
    self->field_DD0.field_4C = 0;
    self->field_DD0.field_48 = func_00271A00(&D_0051BA44, 0x16);
    self->field_DD0.field_30 = h;
    self->field_E0[0][0].field_0 = 0;
    self->field_E0[0][0].field_4 = 0;
    self->field_E0[0][0].field_8 = 0;
    self->field_E0[0][2].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
    self->field_E0[0][2].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
    self->field_E0[0][2].field_8 = &self->field_D80;
    self->field_E0[0][3].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
    self->field_E0[0][3].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
    self->field_E0[0][3].field_8 = &self->field_DD0;
    CGtV2d z0(0.0f, 0.5f);
    CGtV2d isz(24.0f, 24.0f);
    CGtV2d ia(0.5f, 0.5f);
    CGtV2d jsz(21.0f, 14.0f);
    CGtV2d ja(0.0f, 0.5f);
    CGtV2d ta(0.0f, 0.5f);
    CGtV2d tb(0.0f, 0.5f);
    for (i = 0; i < 9; i++) {
        self->field_2C0[i].field_0 = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
        self->field_2C0[i].field_10 = isz;
        self->field_2C0[i].field_30 = D_01EA4670.field_0;
        self->field_2C0[i].field_20 = D_01EA4790.uv;
        self->field_2C0[i].field_28 = D_01EA4798.uv;
        self->field_2C0[i].field_18 = ia;
        self->field_500[i].field_0 = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
        self->field_500[i].field_10 = jsz;
        self->field_500[i].field_30 = D_01EA46B0[0x12];
        self->field_500[i].field_20 = D_01EA47D0.uv;
        self->field_500[i].field_28 = D_01EA47D8.uv;
        self->field_500[i].field_18 = ja;
        self->field_740[i].field_20 = mgr->field_0;
        self->field_740[i].field_40 = 24.0f;
        self->field_740[i].field_44 = D_00665ED8.field_0;
        self->field_740[i].field_4C = 0;
        self->field_740[i].field_48 = self->field_E20[i];
        self->field_740[i].field_30 = ta;
        self->field_A10[i].field_20 = mgr->field_0;
        self->field_A10[i].field_40 = 24.0f;
        self->field_A10[i].field_44 = D_00665ED8.field_0;
        self->field_A10[i].field_4C = 0;
        self->field_A10[i].field_48 = self->field_E44[i];
        self->field_A10[i].field_30 = tb;
        self->field_E44[i][0] = 0;
        for (int j = 0; j < 4; j++) {
            if (j == 3) {
                self->field_E0[i + 1][j].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                self->field_E0[i + 1][j].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                self->field_E0[i + 1][j].field_8 = &self->field_740[i];
            } else if (j == 2) {
                self->field_E0[i + 1][j].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                self->field_E0[i + 1][j].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                self->field_E0[i + 1][j].field_8 = &self->field_A10[i];
            } else if (j == 0) {
                self->field_E0[i + 1][j].field_0 = 0;
                self->field_E0[i + 1][j].field_4 = (void *)GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                self->field_E0[i + 1][j].field_8 = &self->field_2C0[i];
            } else if (j == 1) {
                self->field_E0[i + 1][j].field_0 = 0;
                self->field_E0[i + 1][j].field_4 = (void *)GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                self->field_E0[i + 1][j].field_8 = &self->field_500[i];
            }
        }
    }
    self->field_C = -1;
    if (D_01E3D4B0.field_0 != 0) {
        func_00366980(self, 0);
    } else {
        RecalculateSize__16CGt2dObjectTableFv(self->field_E6C);
    }
    for (int k = self->field_E80; k < GetNumBuddies__22CGtBuddiesPS2DirtySockFv(&D_01E3D390) && k < self->field_E80 + 9; k++) {
        char name[16];
        GetBuddyName__22CGtBuddiesPS2DirtySockFiPc(&D_01E3D390, k, name);
        void * b = HLBListGetBuddyByName(D_01E3D4A8.field_0, name);
        int n;
        if (b != 0) n = HLBMsgListGetTotalCount(b);
        else n = 0;
        if (n > 0) self->field_10 = 1;
    }
    return true;
}
