// NONMATCHING: func_0043A990 -- retail 341 / ours 341 instructions, 22 in changed runs
// near28: 22 off (was 35). Texture find inline reads D_0051A868 itself with 'int i;' declared before t0 (dic/counter s1/s2 exact); cell loop as natural 'if (j == 0) {A} else {B}' with A's field_30 store before its 't = field_44[i]' (arm order + constant regs right). Left: the j==0 arm's field_44 load placement (retail loads it first) and the t3/t4 row-base pair swapped
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// NONMATCHING: func_0043A990 -- retail 341 / ours 341 instructions, 35 in changed runs
// L265: table-page setup (cf. proven func_003774D0) logic complete, 341/341. Left: (1) the 6x2 cell loop's j==0/j!=0 arms -- natural 'if (j == 0)' order (l265dg, 48 off) gets the block order right but the temp registers rotated; 'if (j != 0) {B} else {A}' (this file) gets the registers but swaps the arm order/temp slots; (2) the texture find at the end: dic/counter s1/s2 swapped. Helped: buf as char[12] (8-byte slot class; now [13], the bytes written), field_5C[5] into a local before the PrintString call, &D_01E90240 const pointer declared after the first store, vfunc_C via cast (else devirtualised).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_0043A990 -- hand-written (L265; lifter refused): a CB3TableComponent-style table setup (cf. func_003774D0).
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;

class CGtTexture;
struct UnkStruct_0043A990_cell {
    unsigned char pad_0[0x20];
    u_long128 field_20;
    CGtV2d field_30;
    unsigned char pad_38[0x8];
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
};
struct UnkStruct_0043A990_desc {
    float field_0;
    float field_4;
    unsigned char field_8;
};
struct UnkStruct_0043A990_entry {
    void * field_0;
    void * field_4;
    void * field_8;
};
struct UnkStruct_0043A990_txt {
    CGtV2d field_0;
    int field_8;
    int field_C;
    int field_10;
    short field_14;
    short field_16;
};
struct UnkStruct_0043A990 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    unsigned char pad_14[0x18];
    int field_2C;
    int field_30;
    unsigned char pad_34[0x10];
    int field_44[6];
    unsigned short * field_5C[6];
    unsigned char pad_74[0xC];
    UnkStruct_0043A990_cell field_80[6][2];
    int field_440;
    unsigned char pad_444[0xC];
    u_long128 field_450;
    CGtV2d field_460;
    CGtV2d field_468;
    int field_470;
    UnkStruct_0043A990_txt * field_474;
    int field_478;
    int field_47C;
    UnkStruct_0043A990_txt field_480;
    unsigned char pad_498[0x8];
    u_long128 field_4A0;
    CGtV2d field_4B0;
    CGtV2d field_4B8;
    CGtV2d field_4C0;
    CGtV2d field_4C8;
    CGtTexture * field_4D0;
    unsigned char pad_4D4[0xC];
    CGtV2d field_4E0;
    int field_4E8;
    int field_4EC;
    UnkStruct_0043A990_desc * field_4F0;
    UnkStruct_0043A990_desc * field_4F4;
    UnkStruct_0043A990_entry * field_4F8;
    int field_4FC;
    UnkStruct_0043A990_desc field_500[6];
    UnkStruct_0043A990_desc field_548[2];
    UnkStruct_0043A990_entry field_560[6][2];
    unsigned char field_5F0[0x18];
    void * field_608;
    unsigned char pad_60C[0x60C];
    unsigned short * field_C18;
    unsigned char field_C1C;
};
struct UnkStruct_D_01E90240 {
    u_long128 field_0;
    unsigned char pad_10[0x100];
    u_long128 field_110;
};
struct UnkStruct_D_00665ED8 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_0043A990_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};
struct UnkStruct_0043A990_dic {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_0043A990_e0 * field_C;
};
struct UnkStruct_D_0051A868 { UnkStruct_0043A990_dic * field_0; unsigned char pad_4[0xC]; };
// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113).
struct UnkStruct_0043A990_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};
struct UnkStruct_D_01E8D450 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E8D45A { unsigned char field_0; unsigned char pad_1[0xF]; };

extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_00665ED8 D_00665ED8;
extern UnkStruct_D_00665ED8 D_00665ED0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_0051A868 D_0051A868;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_D_01E8D45A D_01E8D45A;
extern "C" int func_00271A00(void *, int);
extern "C" void Copy__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" void ustrFromInt(unsigned short *, int, int, int);
extern "C" void func_003B8840(unsigned short *, int);
extern "C" void func_00322620(unsigned short *, void *, const int *, const int *);
extern "C" unsigned long GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(int);  // CB3HardCodedVehicleList::GetRaceVehicleGtID(int), static
extern "C" void func_0021AB40(unsigned long, char *);  // [L] DNAT: GtIDConvertToString(unsigned long, char*)
extern "C" int strcasecmp(const char *, const char *);
extern "C" int func_0033FCF0(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV2d *, void *, void *);
extern "C" void func_0033E220(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void func_0033DC80(CGtV2d *, void *, const void *);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);
extern "C" void RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);

static inline CGtTexture * func_0043A990_inl1(const char * name)
{
    int i;
    UnkStruct_0043A990_dic * t0 = D_0051A868.field_0;
    for (i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_0043A990_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return (CGtTexture *)t2;
        }
    }
    return 0;
}

// 0x0043A990
extern "C" void func_0043A990(UnkStruct_0043A990 * self)
{
    int dc;
    int d8;
    // [C] 13 bytes: func_0021AB40 writes out[0..12] (GtID.cpp: out[12] = 0); char[12] overran by one natively. Retail:
    // buf at sp+0xC8 (0x43ADF4), next slot sp+0xD8.
    char buf[13];
    int i, j;
    self->field_C1C = 1;
    UnkStruct_D_01E90240 * const colours = &D_01E90240;
    self->field_44[0] = func_00271A00(&D_0051BA44, 0x1AD);
    self->field_5C[0][0] = 0;
    self->field_44[1] = func_00271A00(&D_0051BA44, 0x1AE);
    Copy__10CGtUnicodeFPUsPCUs(self->field_5C[1], self->field_C18);
    self->field_44[2] = func_00271A00(&D_0051BA44, 0x4C5);
    ustrFromInt(self->field_5C[2], self->field_4, 1, 0);
    self->field_44[3] = func_00271A00(&D_0051BA44, 0x4C6);
    func_003B8840(self->field_5C[3], self->field_8);
    self->field_44[4] = func_00271A00(&D_0051BA44, 0x25E);
    ustrFromInt(self->field_5C[4], self->field_10, 1, 0);
    self->field_44[5] = func_00271A00(&D_0051BA44, 0x4D3);
    d8 = 0xAD;
    dc = self->field_2C + self->field_30;
    unsigned short * p5 = self->field_5C[5];
    func_00322620(p5, (void *)(func_00271A00(&D_0051BA44, 0x3CA)), &dc, &d8);
    self->field_4E8 = 6;
    self->field_4EC = 2;
    self->field_4F0 = self->field_500;
    self->field_4F4 = self->field_548;
    self->field_4F8 = &self->field_560[0][0];
    self->field_4FC = self->field_440;
    self->field_4E0 = CGtV2d(-1.0f, -1.0f);
    self->field_548[0].field_0 = 40.0f; self->field_548[0].field_4 = 144.0f; self->field_548[0].field_8 = 0;
    self->field_548[1].field_0 = 8.0f; self->field_548[1].field_4 = 144.0f; self->field_548[1].field_8 = 0;
    self->field_500[0].field_0 = 0.0f; self->field_500[0].field_4 = 80.0f; self->field_500[0].field_8 = 0;
    for (i = 1; i < 6; i++) {
        self->field_500[i].field_0 = 8.0f; self->field_500[i].field_4 = 32.0f; self->field_500[i].field_8 = 0;
    }
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 2; j++) {
            int t;
            if (j == 0) {
                self->field_80[i][j].field_30 = CGtV2d(0.0f, 0.5f);
                t = self->field_44[i];
            } else {
                t = (int)self->field_5C[i];
                self->field_80[i][j].field_30 = CGtV2d(1.0f, 0.5f);
            }
            self->field_80[i][j].field_20 = colours->field_0;
            self->field_80[i][j].field_48 = t;
            self->field_80[i][j].field_40 = 0x41A00000;
            self->field_80[i][j].field_44 = D_00665ED8.field_0;
            self->field_80[i][j].field_4C = 0;
        }
    }
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 2; j++) {
            self->field_560[i][j].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
            self->field_560[i][j].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
            self->field_560[i][j].field_8 = &self->field_80[i][j];
        }
    }
    self->field_480.field_0 = CGtV2d(0.0f, 0.0f);
    self->field_480.field_10 = D_00665ED0.field_0;
    self->field_480.field_C = 0x3F800000;
    self->field_480.field_8 = 0x41A00000;
    self->field_480.field_14 = -1;
    self->field_480.field_16 = -1;
    self->field_450 = colours->field_0;
    self->field_460 = CGtV2d(0.0f, 0.5f);
    self->field_468.Set(144.0f, 144.0f);
    self->field_470 = self->field_44[0];
    self->field_478 = 1;
    self->field_47C = 0;
    self->field_474 = &self->field_480;
    self->field_560[0][0].field_0 = (void *)func_0033E220;
    self->field_560[0][0].field_4 = (void *)func_0033DC80;
    self->field_560[0][0].field_8 = &self->field_450;
    unsigned long id = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(self->field_C);
    if (id == 0) {
        id = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(0);
    }
    if (id != 0) {
        func_0021AB40(id, buf);
        self->field_4A0 = colours->field_110;
        self->field_4B0 = CGtV2d(112.0f, 56.0f);
        self->field_4B8 = CGtV2d(1.0f, 0.5f);
        self->field_4C0 = CGtV2d(0.0f, 0.0f);
        self->field_4C8 = CGtV2d(1.0f, 1.0f);
        self->field_4D0 = func_0043A990_inl1(buf);
        self->field_560[0][1].field_0 = (void *)RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        self->field_560[0][1].field_4 = (void *)GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        self->field_560[0][1].field_8 = &self->field_4A0;
    }
    if (D_01E8D45A.field_0 != 0) {
        ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
    }
    func_0033FCF0(&D_01E8D450, CGtV2d(256.0f, 96.0f), CGtV2d(0.0f, 0.0f), CGtV2d(352.0f, 272.0f), &self->field_4E0, self->field_608, self->field_5F0);
}


