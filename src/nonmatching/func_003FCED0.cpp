// NONMATCHING: func_003FCED0 -- retail 197 / ours 197 instructions, 29 in changed runs
// near36: 29 changed (was 70). Fixed a TYPE BUG: D_01EA6B30 is a float (retail lwc1/swc1; the archive's int gave a cvt.s.w). Text Prepare takes const CGtV2d& and gets CGtV2d temporaries (retail's slot order: table's (0,0.5) temp at 0x48 top, pos 0x40, anchor 0x38); template float runs copied as structs (field_10 = D_01EA6B00 as float[4] struct, field_38 = D_01EA6B28 as float[2] struct). Left: lui/lwc1/swc1 interleaving and FPR numbering in the table block, a2 move at 0x3C. A whole 0x50 template copy (D_01EA6480 = D_01EA6AF0 + overrides) is worse (210 instrs: overwritten members not dropped).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// func_003FCED0 -- CB3OnlineCrashResultsPage::AddRaceTime(const CB3ResultsData*) [L] DNAT (research/proto/new_names.csv, low 0.838)
#include "b3/GtMathPs2.h"
#include "b3/classes/UnkStruct_D_01E8D450.h"
#include "b3/classes/UnkStruct_D_01E8D45A.h"

struct UnkStruct_FCED0_row {
    unsigned char field_0;
    unsigned char pad_1[0x2B];
    int field_2C;
    unsigned char pad_30[0x4];
    void * field_34;
};
struct UnkStruct_FCED0 {
    unsigned char pad_0[0x48];
    unsigned char field_48;
    unsigned char field_49;
};
struct UnkStruct_FCED0_f { float field_0[4]; };
struct UnkStruct_FCED0_v2 { float field_0[2]; };
struct UnkStruct_FCED0_tab {
    u_long128 field_0;
    UnkStruct_FCED0_f field_10;
    u_long128 field_20;
    GtMathPs2::CGtV2d field_30;
    UnkStruct_FCED0_v2 field_38;
    float field_40;
    int field_44;
    void * field_48;
    int field_4C;
};
struct UnkStruct_FCED0_vt { void * field_0; void * field_4; void * field_8; };
struct UnkStruct_FCED0_g { unsigned char pad_0[0x180]; u_long128 field_180; };
struct UnkStruct_FCED0_o { unsigned char pad_0[0x10]; };
struct UnkStruct_FCED0_i { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_FCED0_fl { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_FCED0_f2 { float field_0[2]; unsigned char pad_8[8]; };

extern UnkStruct_FCED0_row D_01EA5470[];
extern UnkStruct_FCED0_g D_01E90240;
extern UnkStruct_D_01E8D45A D_01E8D45A;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_FCED0_o D_01E8D4B0;
extern UnkStruct_FCED0_tab D_01EA6480;
extern UnkStruct_FCED0_vt D_01EA6A10;
extern u_long128 D_01EA6AF0;
extern UnkStruct_FCED0_f D_01EA6B00;
extern UnkStruct_FCED0_f2 D_01EA6B28;
extern UnkStruct_FCED0_fl D_01EA6B30;
extern UnkStruct_FCED0_i D_01EA6B34;
extern UnkStruct_FCED0_i D_01EA6B3C;
extern unsigned short D_01EA7430[];
extern UnkStruct_FCED0_o D_01E3D558;
extern UnkStruct_FCED0_o D_01E90438;
extern UnkStruct_FCED0_o D_0051BA44;
extern "C" void func_003FD1F0(void *, int, int);
extern "C" void func_003FD850(void *);
extern "C" unsigned short * ustrFromInt(unsigned short *, int, int, int);
extern "C" void * AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_00310180(void *, void *, void *);
extern "C" bool Prepare__16CB3TextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPCUsfbfUib(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, const unsigned short*, float, bool, float, unsigned int, bool);
extern "C" void RecalculateSize__17CB3TableComponentFv(void *);
extern "C" void RenderItalicTextNoTruncation__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv();
extern "C" void GetItalicTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv();

// 0x003FCED0
extern "C" void func_003FCED0(UnkStruct_FCED0 * self)
{
    UnkStruct_FCED0_g * const g = &D_01E90240;
    if (D_01E8D45A.field_0 != 0) {
        ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
        func_003FD850(self);
    }
    int a1;
    if (self->field_49 != 0) {
        a1 = 0;
    } else {
        int i = 0;
        a1 = 0;
        for (; i < 8; i++) {
            if (D_01EA5470[i].field_34 == (void *)&D_01E3D558) {
                a1 = i;
                break;
            }
        }
    }
    func_003FD1F0(self, a1, 1);
    if (self->field_49 == 0) goto end;
    func_003FD1F0(self, 1, 3);
    if (self->field_48 == 0) goto text;
    {
        int total = 0;
        for (int j = 0; j < 2; j++) {
            if (D_01EA5470[j].field_0 != 0) total += D_01EA5470[j].field_2C;
        }
        ustrFromInt(D_01EA7430, total, 0, 0);
    }
    {
    D_01EA6480.field_0 = D_01EA6AF0;
    D_01EA6480.field_10 = D_01EA6B00;
    D_01EA6480.field_38 = *(UnkStruct_FCED0_v2 *)&D_01EA6B28;
    D_01EA6480.field_40 = D_01EA6B30.field_0;
    D_01EA6480.field_44 = D_01EA6B34.field_0;
    D_01EA6480.field_4C = D_01EA6B3C.field_0;
    D_01EA6480.field_48 = D_01EA7430;
    D_01EA6480.field_30 = GtMathPs2::CGtV2d(0.0f, 0.5f);
    D_01EA6480.field_20 = g->field_180;
    D_01EA6A10.field_0 = (void *)RenderItalicTextNoTruncation__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
    D_01EA6A10.field_8 = &D_01EA6480;
    D_01EA6A10.field_4 = (void *)GetItalicTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
    }
    goto end;
text:
    if (D_01EA5470[0].field_0 != 0 && D_01EA5470[1].field_0 != 0) {
        void * s0 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x40);
        func_00310180(s0, (void *)(func_00271A00(&D_0051BA44, 0x305)), &D_01EA5470[0].field_34);
        Prepare__16CB3TextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPCUsfbfUib(&D_01E8D4B0, GtMathPs2::CGtV2d(320.0f, 340.0f), GtMathPs2::CGtV2d(0.5f, 0.5f), (const unsigned short *)s0, 35.0f, false, 400.0f, 3, true);
    }
end:
    RecalculateSize__17CB3TableComponentFv(&D_01E8D450);
}

