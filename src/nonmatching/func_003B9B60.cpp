// NONMATCHING: func_003B9B60 -- retail 485 / ours 491 instructions, 187 in changed runs
// tcopy: 491/485, frame 0xB0 = retail (was 439, 508 changed). Template copies written as array-indexed lvalues (D_01EA5A80[s3].field_0[k] = D_01EA6AF0; ...field_48 = ...; no reference locals) -> retail's per-field (&D+off)+idx addresses shared by copy and later stores; field_0/field_10 one 32-byte member, field_30 a union {unsigned long; CGtV2d} [G]; pm=&D_01E90240 declared after s3 (N183 -> s2). Left: block layout of the two 5-case switches + tails (retail inline after the loop tests), copy load order (retail loads T+0x38 before T+0x30).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA5638 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003B9B60_pg { unsigned char pad_0[0x1160]; unsigned char field_1160; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x12AD28]; UnkStruct_003B9B60_pg * field_12AD28[1]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x180]; u_long128 field_180; };
struct UnkStruct_D_004CA260 { int field_0[1]; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA5650 { float field_0; unsigned char pad_4[0x8]; };
struct UnkStruct_003B9880_el_0 { u_long128 field_0; u_long128 field_10; };  // [G] a 32-byte member: retail stores +0/+0x10 off one base
union UnkStruct_003B9880_u30 { unsigned long u; CGtV2d v; };
struct UnkStruct_003B9880_el {
    UnkStruct_003B9880_el_0 field_0;
    u_long128 field_20;
    UnkStruct_003B9880_u30 field_30;
    unsigned long field_38;
    float field_40;
    int field_44;
    int field_48;
    int field_4C;
};
struct UnkStruct_003B9880_e0 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    float field_30;
    float field_34;
    unsigned long field_38;
    float field_40;
    int field_44;
    int field_48;
    int field_4C;
};


struct UnkStruct_003B9B60_row { UnkStruct_003B9880_el field_0[5]; };
struct UnkStruct_D_01EA6B00 { u_long128 field_0; };
struct UnkStruct_D_01EA6B10 { u_long128 field_0; };
struct UnkStruct_003B9B60_t { void * field_0; void * field_4; void * field_8; };
struct UnkStruct_003B9B60_trow { UnkStruct_003B9B60_t field_0[5]; };
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_01EA5638 D_01EA5638;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_004CA260 D_004CA260;
extern UnkStruct_D_01EA5650 D_01EA5650[];
extern UnkStruct_003B9880_el D_01EA6AF0;
extern UnkStruct_003B9B60_row D_01EA5A80[];
extern UnkStruct_003B9B60_trow D_01EA6890[];
extern "C" void RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short*, const void *, const void*);
extern "C" void GetItalicTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void*);
extern "C" int func_00271A00(void *, int);

extern "C" void func_003B9B60()
{
    int n5 = 0;
    int n4 = 0;
    for (int i = 0; i < D_0064D37C.field_0; i++) {
        if (D_00522660.field_12AD28[i]->field_1160 != 0) n4++;
        else n5++;
    }
    D_01EA5650[0].field_0 = 0.0f;
    D_01EA5650[1].field_0 = 8.0f;
    for (int i = 2; i < n5 + 1; i++) D_01EA5650[i].field_0 = 6.5f;
    D_01EA5650[n5 + 1].field_0 = 32.5f;
    for (int i = n5 + 2; i < n5 + n4 + 1; i++) D_01EA5650[i].field_0 = 6.5f;
    int s3 = 1;
    UnkStruct_D_01E90240 *const pm = &D_01E90240;
    if (n5 + 1 >= 2) goto loop1;
  cont1:
    if (s3 < D_01EA5638.field_0) goto loop2;
  cont2:
    switch (n5) {
    case 1: s3 = 0; break;
    case 2: s3 = 0; break;
    case 3: s3 = 1; break;
    case 4: s3 = 1; break;
    case 5: s3 = 2; break;
    }
    s3 = s3 + 1;
    {
        D_01EA5A80[s3].field_0[0] = D_01EA6AF0;
        D_01EA5A80[s3].field_0[0].field_48 = func_00271A00(&D_0051BA44, 0x2FD);
        D_01EA5A80[s3].field_0[0].field_30.v = CGtV2d(0.0f, 0.5f);
        D_01EA6890[s3].field_0[0].field_0 = (void *)&RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        D_01EA6890[s3].field_0[0].field_8 = &D_01EA5A80[s3].field_0[0];
        D_01EA5A80[s3].field_0[0].field_20 = pm->field_180;
        D_01EA6890[s3].field_0[0].field_4 = (void *)&GetItalicTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
    }
    switch (n4) {
    case 1: s3 = 0; break;
    case 2: s3 = 0; break;
    case 3: s3 = 1; break;
    case 4: s3 = 1; break;
    case 5: s3 = 2; break;
    }
    int r = s3 + (n5 + 1);
    {
        D_01EA5A80[r].field_0[0] = D_01EA6AF0;
        D_01EA5A80[r].field_0[0].field_48 = func_00271A00(&D_0051BA44, 0x2FE);
        D_01EA5A80[r].field_0[0].field_30.v = CGtV2d(0.0f, 0.5f);
        D_01EA6890[r].field_0[0].field_0 = (void *)&RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        D_01EA6890[r].field_0[0].field_8 = &D_01EA5A80[r].field_0[0];
        D_01EA5A80[r].field_0[0].field_20 = pm->field_180;
        D_01EA6890[r].field_0[0].field_4 = (void *)&GetItalicTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
    }
    return;
  loop1:
        for (; s3 < n5 + 1; s3++) {
            D_01EA5A80[s3].field_0[1] = D_01EA6AF0;
            D_01EA5A80[s3].field_0[1].field_48 = func_00271A00(&D_0051BA44, D_004CA260.field_0[s3 - 1]);
            D_01EA5A80[s3].field_0[1].field_30.v = CGtV2d(0.0f, 0.5f);
            D_01EA6890[s3].field_0[1].field_0 = (void *)&RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
            D_01EA6890[s3].field_0[1].field_8 = &D_01EA5A80[s3].field_0[1];
            D_01EA6890[s3].field_0[1].field_4 = (void *)&GetItalicTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
            D_01EA5A80[s3].field_0[1].field_20 = pm->field_180;
        }
    
    goto cont1;
  loop2:
        for (; s3 < D_01EA5638.field_0; s3++) {
            D_01EA5A80[s3].field_0[1] = D_01EA6AF0;
            D_01EA5A80[s3].field_0[1].field_48 = func_00271A00(&D_0051BA44, D_004CA260.field_0[s3 - n5 - 1]);
            D_01EA5A80[s3].field_0[1].field_30.v = CGtV2d(0.0f, 0.5f);
            D_01EA6890[s3].field_0[1].field_0 = (void *)&RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
            D_01EA6890[s3].field_0[1].field_8 = &D_01EA5A80[s3].field_0[1];
            D_01EA6890[s3].field_0[1].field_4 = (void *)&GetItalicTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
            D_01EA5A80[s3].field_0[1].field_20 = pm->field_180;
        }
    
    goto cont2;
}




