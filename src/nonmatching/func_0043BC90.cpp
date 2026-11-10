// NONMATCHING: func_0043BC90 -- retail 432 / ours 408 instructions, 499 in changed runs
// fix2 (2026-11-01): the D_01E8D450 table's slot-0xC call made virtual through a cast pointer, as retail and the matched func_0037B770 (the direct call was devirtualised to vfunc_C__20UnkStruct_D_01E8D450Fv, a symbol retail does not have) | Before: tcopy: 405/432 (was 468), 483 changed (was 602), frame 0x90 = retail. Retail writes the TEMPLATE's own fields first (D_01EA6AF0.field_48 = str; .field_20 = mgr colour; loop 2 also .field_30 = CGtV2d(0.5,0.5)) then copies it whole (D_01EA5A80[s2].field_X = D_01EA6AF0) -- the lifter had forwarded those into a memberwise copy; loop 1 stores half into the row's field_30 after the copy. Retail has NO GetItalicTextSize stores in this function (lifter's were spurious; removed). Left: out-of-line CopyN__10CGtUnicodeFPUsiPCUs/func_003B8750 fallbacks (b back) and block order -- not the copy.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)



#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;

union UnkStruct_3C0430_u30 { unsigned long u; CGtV2d v; };  // [G] retail copies it as one ld/sd, stores it as a CGtV2d
struct UnkStruct_3C0430_sub {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    UnkStruct_3C0430_u30 field_30;
    unsigned long field_38;
    float field_40;
    int field_44;
    void * field_48;
    int field_4C;
};
struct UnkStruct_3C0430_row {
    UnkStruct_3C0430_sub field_0;
    UnkStruct_3C0430_sub field_50;
    UnkStruct_3C0430_sub field_A0;
    UnkStruct_3C0430_sub field_F0;
    UnkStruct_3C0430_sub field_140;
    unsigned char pad_190[0x0];
};
struct UnkStruct_3C0430_desc {
    void * field_0; void * field_4; void * field_8;
    void * field_C; void * field_10; void * field_14;
    void * field_18; void * field_1C; void * field_20;
    void * field_24; void * field_28; void * field_2C;
    void * field_30; void * field_34; void * field_38;
};
struct UnkStruct_3C0430_rec {
    unsigned char field_0;
    unsigned char pad_1[0x7];
    float field_8;
    float field_C;
    int field_10;
    unsigned char pad_14[0x20];
    int field_34;
};
struct UnkStruct_3C0430_str {
    unsigned char pad_0[0x8C];
    unsigned short field_8C[0x37];
};
struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
    unsigned char pad_20[0x160];
    u_long128 field_180;
};
struct UnkStruct_D_01E8D450 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_PT { void * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_B D_01E8D45A;
extern UnkStruct_I D_01EA5638;
extern UnkStruct_3C0430_rec D_01EA5470[];
extern UnkStruct_3C0430_row D_01EA5A80[];
extern UnkStruct_3C0430_desc D_01EA6890[];
extern UnkStruct_3C0430_str D_01EA6B70;

extern UnkStruct_3C0430_sub D_01EA6AF0;

extern UnkStruct_PT D_01EA6B38;
extern UnkStruct_P D_0051BA44;
extern char D_004D1D08[];
extern float D_004E0BFC;
extern CGtV2d D_01EA6B20;
extern unsigned long D_01EA6B28;
extern float D_01EA6B30;
extern int D_01EA6B34;
extern int D_01EA6B3C;
extern "C" void func_003B8750(void *, float);
extern "C" void func_0043B770(void *);
extern "C" void PrintInt__10CGtUnicodeFPUsii(unsigned short *, int, int, int);
extern "C" int func_0043BC30(const void *, const void *);
extern "C" void func_003C1E00(int, const void *);
extern "C" void qsort(void *, int, int, void *);
extern "C" void RecalculateSize__17CB3TableComponentFv(void *);
extern "C" int snprintf(char *, int, const char *, ...);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, unsigned short *, int);
extern "C" unsigned short * ustrFromInt(unsigned short *, int, int, int);
extern "C" unsigned short * CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, void *);
extern "C" void *func_00271A00(void *, int);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);
extern "C" void RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetItalicTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);


// pass1: a0 and a1 (the page's data record) reach func_003C1E00 untouched (retail live-in; the func_003BA4E0 pattern)
extern "C" void func_0043BC90(int arg, const void *rec)
{
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    char buf[0x23];
    int s0;
    int s2;
    int s3;
    func_003C1E00(arg, rec);
    qsort(&D_01EA5470, 8, 0x38, (void *)&func_0043BC30);
    if (D_01E8D45A.field_0 != 0) {
        ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();   // fix2: a virtual call, as retail (vtable at +0, slot 0xC) and the matched func_0037B770; the direct form is devirtualised to a symbol retail does not have
        func_0043B770((void *)(arg));
        s0 = 0;
    } else {
        s0 = 1;
    }
    if (D_01EA5638.field_0 >= 2) goto loop1;
loop2:
    for (s2 = 1; s2 < D_01EA5638.field_0; s2++) {
        if (D_01EA5470[s2 - 1].field_0 != 0) {
            unsigned short * str = (unsigned short *)((char *)&D_01EA6B70 + (s2 - 1) * 0x15E + 0x46);
            if (D_004E0BFC == D_01EA5470[s2 - 1].field_C) {
                CopyN__10CGtUnicodeFPUsiPCUs(str, 0x23, func_00271A00(&D_0051BA44, 0x26C));
            } else {
                func_003B8750(str, D_01EA5470[s2 - 1].field_C);
            }
            D_01EA6AF0.field_48 = str;
            D_01EA6AF0.field_20 = mgr->field_180;
            D_01EA6AF0.field_30.v = CGtV2d(0.5f, 0.5f);
            D_01EA5A80[s2].field_A0 = D_01EA6AF0;
            D_01EA6890[s2].field_18 = (void *)&RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
            D_01EA6890[s2].field_20 = &D_01EA5A80[s2].field_A0;
        }
    }
    for (s2 = 1; s2 < D_01EA5638.field_0; s2++) {
        if (D_01EA5470[s2 - 1].field_0 != 0) {
            unsigned short * str = (unsigned short *)((char *)&D_01EA6B70 + (s2 - 1) * 0x15E + 0x8C);
            if (D_004E0BFC == D_01EA5470[s2 - 1].field_8) {
                CopyN__10CGtUnicodeFPUsiPCUs(str, 0x23, func_00271A00(&D_0051BA44, 0x26C));
            } else {
                func_003B8750(str, D_01EA5470[s2 - 1].field_8);
            }
            D_01EA6AF0.field_48 = str;
            D_01EA6AF0.field_20 = mgr->field_180;
            D_01EA5A80[s2].field_F0 = D_01EA6AF0;
            D_01EA6890[s2].field_24 = (void *)&RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
            D_01EA6890[s2].field_2C = &D_01EA5A80[s2].field_F0;
        }
    }
    for (s2 = 1; s2 < D_01EA5638.field_0; s2++) {
        if (D_01EA5470[s2 - 1].field_0 != 0) {
            unsigned short * str = (unsigned short *)((char *)&D_01EA6B70 + (s2 - 1) * 0x15E + 0xD2);
            PrintInt__10CGtUnicodeFPUsii(str, D_01EA5470[s2 - 1].field_10, 1, 0);
            D_01EA6AF0.field_48 = str;
            D_01EA6AF0.field_20 = mgr->field_180;
            D_01EA5A80[s2].field_140 = D_01EA6AF0;
            D_01EA6890[s2].field_30 = (void *)&RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
            D_01EA6890[s2].field_38 = &D_01EA5A80[s2].field_140;
        }
    }
    if (s0 == 0) {
        RecalculateSize__17CB3TableComponentFv(&D_01E8D450);
    }
    return;
loop1:
    {
        CGtV2d half(0.0f, 0.5f);
        for (s3 = 1; s3 < D_01EA5638.field_0; s3++) {
            unsigned short * str = (unsigned short *)((char *)&D_01EA6B70 + (s3 - 1) * 0x15E);
            if (D_01EA5470[s3 - 1].field_0 != 0) {
                snprintf(buf, 0x23, D_004D1D08, D_01EA5470[s3 - 1].field_34);
                ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, str, 0x23);
            } else {
                CopyN__10CGtUnicodeFPUsiPCUs(str, 0x23, func_00271A00(&D_0051BA44, 0x26B));
            }
            D_01EA6AF0.field_48 = str;
            D_01EA6AF0.field_20 = mgr->field_10;
            D_01EA5A80[s3].field_50 = D_01EA6AF0;
            D_01EA5A80[s3].field_50.field_30.v = half;
            D_01EA6890[s3].field_C = (void *)&RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
            D_01EA6890[s3].field_14 = &D_01EA5A80[s3].field_50;
        }
    }
    goto loop2;
}

