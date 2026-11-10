// NONMATCHING: func_003B90E0 -- retail 486 / ours 461 instructions, 613 in changed runs
// a175: logic-complete draft (461 vs 486 instrs, 613 changed); first-pass shape only, not iterated. Same blocker as func_003B9B60 (0x50 template copy via separate field symbols + 4 live pointer regs; BRIEF a100 open item). Structure: n = D_0064D37C - pages with field_1160 - D_01EA5470 records (byte0&&!byte1); loop A columns 2 (ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi / CopyN__10CGtUnicodeFPUsiPCUs 0x26B into D_01EA6B70[i-1]+0x46, callbacks RenderItalicText); loop B column 3 (record byte1 -> 28x28 icon D_01EA4E70[k-1] with func_003B8EC0 callback and pminw(5,rec+0x10)+pextlw count; byte3 -> func_003B8750 + RenderText; byte2 -> 0xB2D/0x2FF italic text with mgr+0x190/0x180 colour) into +0x8C buffers; loop C column 4 (PrintInt__10CGtUnicodeFPUsii rec+0x2C into +0xD2, RenderText); then if (p1) D_01E8D450.RecalculateSize(). Unverified/approximate: icon struct layout (offsets from m2c negative offsets), the pminw/pextlw MMI helper written as one asm (BRIEF wants separate pminw and pextlw helpers), loop B/C page-skip bookkeeping, order of D_01EA6890 stores, CGtV2d p30 constants (loopA 0,0.5; loopB 0.5,0).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
class CB3TableComponent { public: void RecalculateSize(); unsigned char pad_0[0x10]; };
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01EA5638 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003B90E0_pg { unsigned char pad_0[0x1160]; unsigned char field_1160; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x12AD28]; UnkStruct_003B90E0_pg * field_12AD28[1]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x10]; u_long128 field_10; unsigned char pad_20[0x160]; u_long128 field_180; u_long128 field_190; };
struct UnkStruct_003B90E0_rec { unsigned char field_0; unsigned char field_1; unsigned char field_2; unsigned char field_3; unsigned char pad_4[4]; float field_8; unsigned char pad_C[4]; int field_10; unsigned char pad_14[0x18]; int field_2C; unsigned char pad_30[4]; unsigned short * field_34; unsigned char pad_38[0]; };
struct UnkStruct_003B90E0_rec2 { unsigned char field_0; unsigned char field_1; unsigned char field_2; unsigned char field_3; unsigned char pad_4[4]; float field_8; unsigned char pad_C[4]; int field_10; unsigned char pad_14[0x18]; int field_2C; unsigned char pad_30[4]; unsigned short * field_34; };
struct UnkStruct_D_01EA5470 { unsigned char pad_0[0x38]; };
struct UnkStruct_003B90E0_txt { unsigned char pad_0[0x46]; unsigned short field_46[35]; unsigned short field_8C[35]; unsigned short field_D2[35]; unsigned char pad_118[0x46]; };
struct UnkStruct_003B90E0_icon { u_long128 field_0; float field_10; float field_14; float field_18; float field_1C; int field_20; int field_24; float field_28; float field_2C; int field_30; unsigned char pad_34[0xC]; unsigned long field_40; unsigned char pad_48[8]; };
struct UnkStruct_D_00522660_dummy { int field_0; };
struct UnkStruct_003B9880_el {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    unsigned long field_30;  // [G] a CGtV2d copied as one doubleword
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


struct UnkStruct_003B90E0_row { UnkStruct_003B9880_el field_0[5]; };
struct UnkStruct_003B90E0_t { void * field_0; void * field_4; void * field_8; };
struct UnkStruct_003B90E0_trow { UnkStruct_003B90E0_t field_0[5]; };
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_01EA5638 D_01EA5638;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_003B90E0_rec2 D_01EA5470[];
extern UnkStruct_003B90E0_icon D_01EA4E70[];
extern UnkStruct_003B90E0_txt D_01EA6B70[];
extern UnkStruct_003B9880_el D_01EA6AF0;
extern UnkStruct_003B90E0_row D_01EA5A80[];
extern UnkStruct_003B90E0_trow D_01EA6890[];
extern CB3TableComponent D_01E8D450;
extern int mapIconTextures__15CB3HUDComponent[];
extern "C" void RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short*, const void *, const void*);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short*, const void *, const void*);
extern "C" void func_003B8EC0(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003B8750(unsigned short *, float);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(unsigned short *, unsigned short *, int);
extern "C" void PrintInt__10CGtUnicodeFPUsii(unsigned short *, int, int, int);
static inline unsigned long func_003B90E0_inl0(int v) { unsigned long r; asm("pminw %0,%1,%2" : "=r"(r) : "r"(5), "r"(v)); return r; }

// 0x003B90E0
extern "C" void func_003B90E0(void * self, int p1)
{
    int n = D_0064D37C.field_0;
    for (int i = 0; i < D_0064D37C.field_0; i++) {
        if (D_00522660.field_12AD28[i]->field_1160 != 0) n--;
    }
    for (int i = 0; i < D_01EA5638.field_0; i++) {
        if (D_01EA5470[i].field_0 != 0 && D_01EA5470[i].field_1 == 0) n--;
    }
    int s0 = 1;
    int s3 = 0;
    if (D_01EA5638.field_0 >= 2) {
        for (; s0 < D_01EA5638.field_0; s0++) {
            unsigned short * txt;
            if (n < s0) {
                UnkStruct_003B90E0_rec2 * r = &D_01EA5470[s3];
                if (r->field_0 != 0) {
                    txt = D_01EA6B70[s0 - 1].field_46;
                    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(r->field_34, txt, 0x23);
                    s3++;
                } else {
                    txt = D_01EA6B70[s0 - 1].field_46;
                    CopyN__10CGtUnicodeFPUsiPCUs(txt, 0x23, func_00271A00(&D_0051BA44, 0x26B));
                }
            } else {
                txt = D_01EA6B70[s0 - 1].field_46;
                CopyN__10CGtUnicodeFPUsiPCUs(txt, 0x23, func_00271A00(&D_0051BA44, 0x26B));
            }
            UnkStruct_003B9880_el &e = D_01EA5A80[s0].field_0[2];
            e = D_01EA6AF0;
            e.field_48 = (int)txt;
            e.field_20 = D_01E90240.field_10;
            *(CGtV2d *)&e.field_30 = CGtV2d(0.0f, 0.5f);
            D_01EA6890[s0].field_0[2].field_0 = (void *)&RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
            D_01EA6890[s0].field_0[2].field_8 = &e;
        }
    }
    s0 = 1;
    s3 = 0;
    {
    }
    int s2 = 0;
    for (int k = 1; k < D_01EA5638.field_0; k++) {
        if (n < k) {
            UnkStruct_003B90E0_rec2 * r = &D_01EA5470[s2];
            if (r->field_0 != 0) {
                if (r->field_1 == 0) {
                    UnkStruct_003B9880_el &e = D_01EA5A80[k].field_0[3];
                    unsigned short * txt;
                    e = D_01EA6AF0;
                    *(CGtV2d *)&e.field_30 = CGtV2d(0.5f, 0.0f);
                    if (r->field_3 == 0) {
                        if (r->field_2 != 0) {
                            txt = D_01EA6B70[k - 1].field_8C;
                            CopyN__10CGtUnicodeFPUsiPCUs(txt, 0x23, func_00271A00(&D_0051BA44, 0xB2D));
                            e.field_20 = D_01E90240.field_190;
                        } else {
                            txt = D_01EA6B70[k - 1].field_8C;
                            CopyN__10CGtUnicodeFPUsiPCUs(txt, 0x23, func_00271A00(&D_0051BA44, 0x2FF));
                            e.field_20 = D_01E90240.field_180;
                        }
                        D_01EA6890[k].field_0[3].field_0 = (void *)&RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                    } else {
                        txt = D_01EA6B70[k - 1].field_8C;
                        func_003B8750(txt, r->field_8);
                        e.field_20 = D_01E90240.field_10;
                        D_01EA6890[k].field_0[3].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                    }
                    e.field_48 = (int)txt;
                    D_01EA6890[k].field_0[3].field_8 = &e;
                } else {
                    UnkStruct_003B90E0_icon * ic = &D_01EA4E70[k - 1];
                    D_01EA6890[k].field_0[3].field_0 = (void *)&func_003B8EC0;
                    ic->field_0 = D_01E90240.field_10;
                    ic->field_10 = 28.0f;
                    ic->field_14 = 28.0f;
                    ic->field_18 = 0.0f;
                    ic->field_1C = 0.5f;
                    ic->field_20 = 0;
                    ic->field_24 = 0;
                    ic->field_28 = 1.0f;
                    ic->field_2C = 1.0f;
                    ic->field_30 = mapIconTextures__15CB3HUDComponent[1];
                    ic->field_40 = func_003B90E0_inl0(r->field_10);
                    D_01EA6890[k].field_0[3].field_8 = ic;
                }
                s2++;
            }
        }
    }
    s2 = 0;
    for (int k = 1; k < D_01EA5638.field_0; k++) {
        if (n < k) {
            UnkStruct_003B90E0_rec2 * r = &D_01EA5470[s2];
            if (r->field_0 != 0) {
                unsigned short * txt = D_01EA6B70[k - 1].field_D2;
                PrintInt__10CGtUnicodeFPUsii(txt, r->field_2C, 1, 0);
                s2++;
                UnkStruct_003B9880_el &e = D_01EA5A80[k].field_0[4];
                e = D_01EA6AF0;
                e.field_48 = (int)txt;
                D_01EA6890[k].field_0[4].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                D_01EA6890[k].field_0[4].field_8 = &e;
                e.field_20 = D_01E90240.field_180;
            }
        }
    }
    if (p1 != 0) D_01E8D450.RecalculateSize();
}
