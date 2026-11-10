// NONMATCHING: AddRaceTime__21CB3CrashStandingsPageFPC14CB3ResultsData -- retail 274 / ours 265 instructions, 152 in changed runs
// fix2 (2026-11-01): the D_01E8D450 table's slot-0xC call made virtual through a cast pointer, as retail and the matched func_0037B770 (the direct call was devirtualised to a symbol retail does not have) | Before: tcopy: 262/274, 155 changed (was 266, 322). The template's text field is written as D_01EA6AF0.field_48 = str (the template object itself), not through the separate extern D_01EA6B38: MWCC then forwards str into the whole-struct copy as retail does (with a separate extern it re-loads T+0x48). Left: the s2 flag / delay-slot shape and str address arithmetic order (a152 note), not the copy.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)



#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;

class CB3ResultsData;
class CB3CrashStandingsPage {
public:
    void AddRaceTime(const CB3ResultsData *);
    unsigned char pad_0[0x4];
};
struct UnkStruct_3C0430_sub {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    unsigned long field_30;
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
    unsigned char pad_F0[0xA0];
};
struct UnkStruct_3C0430_desc {
    void * field_0;
    void * field_4;
    void * field_8;
    unsigned char pad_C[0xC];
    void * field_18;
    void * field_1C;
    void * field_20;
    unsigned char pad_24[0x18];
};
struct UnkStruct_3C0430_rec {
    unsigned char field_0;
    unsigned char pad_1[0x2F];
    int field_30;
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
extern char D_004CA320[], D_004CA328[];
extern "C" void func_003C1E00();
extern "C" void qsort(void *, int, int, void *);
extern "C" int func_003C03D0(void *, void *);
extern "C" void func_003BFEE0(void *);
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

void CB3CrashStandingsPage::AddRaceTime(const CB3ResultsData * p0)
{
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    char buf[0x23];
    func_003C1E00();
    qsort(&D_01EA5470, 8, 0x38, (void *)&func_003C03D0);
    if (D_01E8D45A.field_0 != 0) {
        ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();   // fix2: a virtual call, as retail (vtable at +0, slot 0xC) and the matched func_0037B770; the direct form is devirtualised to a symbol retail does not have
        func_003BFEE0(this);
    }
    int s2 = 1;
    int s1;
    if (D_01EA5638.field_0 >= 2) goto loopB;
loopA:
    for (s1 = 1; s1 < D_01EA5638.field_0; s1++) {
        if (D_01EA5470[s1 - 1].field_0 == 0) {
            s2 = 0;
        } else {
            s2 = 1;
            if (D_01EA5470[s1 - 1].field_30 < 0) {
                CopyN__10CGtUnicodeFPUsiPCUs(((UnkStruct_3C0430_str *)((char *)&D_01EA6B70 + s1 * 0x15E))->field_8C, 0x23, func_00271A00(&D_0051BA44, 0x301));
            } else {
                ustrFromInt(((UnkStruct_3C0430_str *)((char *)&D_01EA6B70 + s1 * 0x15E))->field_8C, D_01EA5470[s1 - 1].field_30, 0, 0);
            }
        }
        if (s2 != 0) {
            UnkStruct_3C0430_row * row = &D_01EA5A80[s1];
            D_01EA6AF0.field_48 = ((UnkStruct_3C0430_str *)((char *)&D_01EA6B70 + s1 * 0x15E))->field_8C;
            row->field_A0 = D_01EA6AF0;
            CGtV2d one(1.0f, 0.5f);
            row->field_A0.field_20 = mgr->field_180;
            *(CGtV2d *)&row->field_A0.field_30 = one;
            D_01EA6890[s1].field_18 = (void *)&RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
            D_01EA6890[s1].field_1C = (void *)&GetItalicTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
            D_01EA6890[s1].field_20 = &row->field_A0;
        } else {
            D_01EA6890[s1].field_18 = 0;
            D_01EA6890[s1].field_1C = 0;
            D_01EA6890[s1].field_20 = 0;
        }
    }
    RecalculateSize__17CB3TableComponentFv(&D_01E8D450);
    return;
loopB:
    {
        CGtV2d half(0.0f, 0.5f);
        for (s2 = 1; s2 < D_01EA5638.field_0; s2++) {
            UnkStruct_3C0430_str * str = (UnkStruct_3C0430_str *)((char *)&D_01EA6B70 + s2 * 0x15E);
            if (D_01EA5470[s2 - 1].field_0 == 0) {
                snprintf(buf, 0x23, D_004CA320, D_004CA328);
            } else {
                snprintf(buf, 0x23, D_004CA320, D_01EA5470[s2 - 1].field_34);
            }
            ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, (unsigned short *)str, 0x23);
            D_01EA6AF0.field_48 = str;
            UnkStruct_3C0430_row * row = &D_01EA5A80[s2];
            row->field_0 = *(UnkStruct_3C0430_sub *)&D_01EA6AF0;
            row->field_0.field_20 = mgr->field_10;
            *(CGtV2d *)&row->field_0.field_30 = half;
            D_01EA6890[s2].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
            D_01EA6890[s2].field_4 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
            D_01EA6890[s2].field_8 = &row->field_0;
        }
    }
    goto loopA;
}

