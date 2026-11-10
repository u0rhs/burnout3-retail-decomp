// Hand-written; the lifter refused it (draftAB: table setup (func_003774D0 shape); switch 0/1/default return; mode-1 j==0 reads field_8[i] into a local first (retail's extra spill); CGtV2d(...) dead temps).

// func_00321A50 -- [G] table page setup (mode 0/1 rows of label + value cells; mode 1 has an image column).
// Hand-written (draftAB) from retail asm + Ghidra draft; layout mirrors func_003774D0 (SetupTableData shape).
// Called by func_00321870 with its event 0/1/7 (7 -> nothing).
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;

struct UnkStruct_00321A50_cell {
    unsigned char pad_0[0x20];
    u_long128 field_20;
    CGtV2d field_30;
    unsigned char pad_38[0x8];
    int field_40;
    int field_44;
    void * field_48;
    int field_4C;
};

struct UnkStruct_00321A50_img {
    u_long128 field_0;
    CGtV2d field_10;
    CGtV2d field_18;
    CGtV2d field_20;
    CGtV2d field_28;
    int field_30;
    unsigned char pad_34[0xC];
};

struct UnkStruct_00321A50_desc {
    float field_0;
    float field_4;
    unsigned char field_8;
};

struct UnkStruct_00321A50_entry {
    void * field_0;
    void * field_4;
    void * field_8;
};

struct UnkStruct_00321A50_a2 {
    int field_0;
};

struct UnkStruct_00321A50 {
    unsigned char pad_0[0x8];
    int field_8[5];
    unsigned short field_1C[5][0x10];
    unsigned char pad_BC[0x4];
    UnkStruct_00321A50_cell field_C0[5][3];
    int field_570;
    unsigned char pad_574[0xC];
    UnkStruct_00321A50_img field_580[5];
    CGtV2d field_6C0;
    int field_6C8;
    int field_6CC;
    UnkStruct_00321A50_desc * field_6D0;
    UnkStruct_00321A50_desc * field_6D4;
    UnkStruct_00321A50_entry * field_6D8;
    int field_6DC;
    UnkStruct_00321A50_desc field_6E0[5];
    UnkStruct_00321A50_desc field_71C[3];
    UnkStruct_00321A50_entry field_740[5][3];
    unsigned char field_7F4[4];
};

struct UnkStruct_D_01E90240 {
    u_long128 field_0;
    unsigned char pad_10[0x100];
    u_long128 field_110;
};
struct UnkStruct_D_00665ED0 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA4690 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051BF9C { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E8D450 { unsigned char pad_0[0x10]; };

extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_01EA4690 D_01EA4690;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern u_long128 D_01EA31D0;
extern const CGtV2d D_004C5400;
extern const CGtV2d D_004C5408;
extern const CGtV2d D_004C5410[5];
extern const CGtV2d D_004C5440[5];
extern CGtV2d D_004E2D70;

extern "C" int func_00271A00(void *, int);
extern "C" int func_00137D50(void *);
extern "C" int func_0013A650(void *);
extern "C" int func_0013A7F0(void *);
extern "C" int func_0013A880(void *);
extern "C" int func_0013A7D0(void *);
extern "C" int func_0013A5B0(void *);
extern "C" int func_0013AD00(void *);
extern "C" int func_0013B660(void *);
extern "C" int func_0013B200(void *, unsigned long, int);
extern "C" int func_0013B570(void *);
extern "C" void func_003B8840(unsigned short *, int);
extern "C" void func_00322620(unsigned short *, void *, const UnkStruct_00321A50_a2 *, const UnkStruct_00321A50_a2 *);
extern "C" unsigned short * ustrFromInt(unsigned short *, int, int, int);
extern "C" unsigned short * PrintInt__10CGtUnicodeFPUsii(unsigned short *, int, int, int);
extern "C" int func_0033FF10(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, bool, void *, void *, int);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);
extern "C" void RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);

// 0x00321A50
extern "C" void func_00321A50(UnkStruct_00321A50 * self, int mode)
{
    void * prof = D_0051BF9C.field_0;
    UnkStruct_D_01E90240 * const colours = &D_01E90240;
    int i, j;
    switch (mode) {
    case 0: {
        self->field_8[0] = func_00271A00(&D_0051BA44, 0xBEC);
        PrintInt__10CGtUnicodeFPUsii(self->field_1C[0], func_0013A5B0(prof), 1, 0);
        self->field_8[1] = func_00271A00(&D_0051BA44, 0x4D3);
        UnkStruct_00321A50_a2 v1;
        UnkStruct_00321A50_a2 k1;
        k1.field_0 = 0xAD;
        v1.field_0 = func_0013AD00(prof);
        func_00322620(self->field_1C[1], (void *)(func_00271A00(&D_0051BA44, 0x3CA)), &v1, &k1);
        self->field_8[2] = func_00271A00(&D_0051BA44, 0x4C5);
        ustrFromInt(self->field_1C[2], func_0013B660(prof), 1, 0);
        self->field_8[3] = func_00271A00(&D_0051BA44, 0x25E);
        int a = func_0013B200(prof, 0, 1);
        int b = func_0013B200(prof, 0, 0);
        ustrFromInt(self->field_1C[3], a + b, 1, 0);
        self->field_8[4] = func_00271A00(&D_0051BA44, 0x4C6);
        func_003B8840(self->field_1C[4], func_0013B570(prof));
        self->field_6C8 = 5;
        self->field_6CC = 3;
        self->field_6D0 = self->field_6E0;
        self->field_6D4 = self->field_71C;
        self->field_6D8 = &self->field_740[0][0];
        self->field_6DC = self->field_570;
        self->field_6C0 = CGtV2d(-1.0f, -1.0f);
        self->field_71C[0].field_0 = 40.0f; self->field_71C[0].field_4 = 176.0f; self->field_71C[0].field_8 = 0;
        self->field_71C[1].field_0 = 0.0f; self->field_71C[1].field_4 = 48.0f; self->field_71C[1].field_8 = 0;
        self->field_71C[2].field_0 = 0.0f; self->field_71C[2].field_4 = 48.0f; self->field_71C[2].field_8 = 0;
        self->field_6E0[0].field_0 = 0.0f; self->field_6E0[0].field_4 = 32.0f; self->field_6E0[0].field_8 = 0;
        for (i = 1; i < 5; i++) {
            self->field_6E0[i].field_0 = 12.0f; self->field_6E0[i].field_4 = 32.0f; self->field_6E0[i].field_8 = 0;
        }
        for (i = 0; i < self->field_6C8; i++) {
            for (j = 0; j < self->field_6CC; j++) {
                void * str;
                if (j == 0) {
                    str = (void *)self->field_8[i];
                    self->field_C0[i][j].field_30 = CGtV2d(0.0f, 0.5f);
                } else {
                    str = self->field_1C[i];
                    self->field_C0[i][j].field_30 = CGtV2d(1.0f, 0.5f);
                }
                self->field_C0[i][j].field_20 = colours->field_0;
                self->field_C0[i][j].field_48 = str;
                self->field_C0[i][j].field_40 = 0x41A00000;
                self->field_C0[i][j].field_44 = D_00665ED0.field_0;
                self->field_C0[i][j].field_4C = 0;
                if (j == 1) {
                    self->field_C0[i][j].field_20 = D_01EA31D0;
                }
            }
        }
        for (i = 0; i < self->field_6C8; i++) {
            for (j = 0; j < self->field_6CC; j++) {
                self->field_740[i][j].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                self->field_740[i][j].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                self->field_740[i][j].field_8 = &self->field_C0[i][j];
            }
        }
        break;
    }
    case 1: {
        self->field_8[0] = func_00271A00(&D_0051BA44, 0x1C7);
        UnkStruct_00321A50_a2 v0, k0;
        k0.field_0 = 4;
        v0.field_0 = func_00137D50(prof);
        func_00322620(self->field_1C[0], (void *)(func_00271A00(&D_0051BA44, 0x3CA)), &v0, &k0);
        self->field_8[1] = func_00271A00(&D_0051BA44, 0x1C8);
        UnkStruct_00321A50_a2 v1, k1;
        k1.field_0 = 0x43;
        v1.field_0 = func_0013A650(prof);
        func_00322620(self->field_1C[1], (void *)(func_00271A00(&D_0051BA44, 0x3CA)), &v1, &k1);
        self->field_8[2] = func_00271A00(&D_0051BA44, 0x6EE);
        UnkStruct_00321A50_a2 v2, k2;
        k2.field_0 = 0x14;
        v2.field_0 = func_0013A7F0(prof);
        func_00322620(self->field_1C[2], (void *)(func_00271A00(&D_0051BA44, 0x3CA)), &v2, &k2);
        self->field_8[3] = func_00271A00(&D_0051BA44, 0xBED);
        UnkStruct_00321A50_a2 v3, k3;
        k3.field_0 = 10;
        v3.field_0 = func_0013A880(prof);
        func_00322620(self->field_1C[3], (void *)(func_00271A00(&D_0051BA44, 0x3CA)), &v3, &k3);
        self->field_8[4] = func_00271A00(&D_0051BA44, 0xBEE);
        UnkStruct_00321A50_a2 v4, k4;
        k4.field_0 = 10;
        v4.field_0 = func_0013A7D0(prof);
        func_00322620(self->field_1C[4], (void *)(func_00271A00(&D_0051BA44, 0x3CA)), &v4, &k4);
        self->field_6C8 = 5;
        self->field_6CC = 3;
        self->field_6D0 = self->field_6E0;
        self->field_6D4 = self->field_71C;
        self->field_6D8 = &self->field_740[0][0];
        self->field_6DC = self->field_570;
        self->field_6C0 = CGtV2d(-1.0f, -1.0f);
        self->field_71C[0].field_0 = 40.0f; self->field_71C[0].field_4 = 176.0f; self->field_71C[0].field_8 = 0;
        self->field_71C[1].field_0 = 0.0f; self->field_71C[1].field_4 = 48.0f; self->field_71C[1].field_8 = 0;
        self->field_71C[2].field_0 = 0.0f; self->field_71C[2].field_4 = 48.0f; self->field_71C[2].field_8 = 0;
        self->field_6E0[0].field_0 = 0.0f; self->field_6E0[0].field_4 = 32.0f; self->field_6E0[0].field_8 = 0;
        for (i = 1; i < 5; i++) {
            self->field_6E0[i].field_0 = 12.0f; self->field_6E0[i].field_4 = 32.0f; self->field_6E0[i].field_8 = 0;
        }
        for (i = 0; i < self->field_6C8; i++) {
            for (j = 0; j < self->field_6CC; j++) {
                if (j == 0) {
                    void * str = (void *)self->field_8[i];
                    self->field_C0[i][j].field_30 = CGtV2d(0.0f, 0.5f);
                    self->field_C0[i][j].field_20 = colours->field_0;
                    self->field_C0[i][j].field_48 = str;
                    self->field_C0[i][j].field_40 = 0x41A00000;
                    self->field_C0[i][j].field_44 = D_00665ED0.field_0;
                    self->field_C0[i][j].field_4C = 0;
                    self->field_740[i][j].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                    self->field_740[i][j].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                    self->field_740[i][j].field_8 = &self->field_C0[i][j];
                } else if (j == 1) {
                    self->field_580[i].field_0 = colours->field_110;
                    self->field_580[i].field_10 = D_004C5408;
                    self->field_580[i].field_18 = D_004E2D70;
                    self->field_580[i].field_20 = D_004C5410[i];
                    self->field_580[i].field_28 = D_004C5440[i];
                    self->field_580[i].field_30 = D_01EA4690.field_0;
                    self->field_740[i][j].field_0 = (void *)RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                    self->field_740[i][j].field_4 = (void *)GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                    self->field_740[i][j].field_8 = &self->field_580[i];
                } else {
                    self->field_C0[i][j].field_30 = CGtV2d(1.0f, 0.5f);
                    self->field_C0[i][j].field_20 = colours->field_0;
                    self->field_C0[i][j].field_48 = self->field_1C[i];
                    self->field_C0[i][j].field_40 = 0x41A00000;
                    self->field_C0[i][j].field_44 = D_00665ED0.field_0;
                    self->field_C0[i][j].field_4C = 0;
                    self->field_740[i][j].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                    self->field_740[i][j].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                    self->field_740[i][j].field_8 = &self->field_C0[i][j];
                }
            }
        }
        break;
    }
    default:
        return;
    }
    func_0033FF10(&D_01E8D450, CGtV2d(288.0f, 112.0f), CGtV2d(0.0f, 0.0f), D_004C5400, true, &self->field_6C0, self->field_7F4, 0);
}
