// NONMATCHING: func_003BFEE0 -- retail 314 / ours 319 instructions, 166 in changed runs
// a152: structure right (vcalls A0/A8/100/20, count loop, 7.0f/200.0f global init block, then table Prepare via func_0033FF10 + RecalculateSize); 319 vs 314 instrs, 166 changed: the two global-copy blocks (D_01EA5780.. / D_01EA5B20..) differ in load/store interleave and lui sharing, retail frame 0xB0 (dead CGtV2d(1.0,0.5) temps at sp+0xA0/0x98 and arg temps 0x68..0x94) vs ours 0xA0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003BFEE0 -- hand-written from retail (lifter refused); [L] CB3CrashStandingsPage-family table Prepare (results/standings table data set up in globals)
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_003BFEE0_b {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual int vfunc_A0();
    virtual void vfunc_A4();
    virtual int vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual void vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
    virtual void vfunc_E8();
    virtual void vfunc_EC();
    virtual void vfunc_F0();
    virtual void vfunc_F4();
    virtual void vfunc_F8();
    virtual void vfunc_FC();
    virtual int vfunc_100();
};
struct UnkStruct_003BFEE0_a {
    unsigned char pad_0[0x1B0];
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual int vfunc_20();
    UnkStruct_003BFEE0_b * field_1B4;
};
struct UnkStruct_D_0051BA88 { UnkStruct_003BFEE0_a * field_0; unsigned char pad_4[0xC]; };
struct F16 { float v; unsigned char pad_4[0xC]; };
struct I16 { int v; unsigned char pad_4[0xC]; };
struct B16 { unsigned char v; unsigned char pad_1[0xF]; };
struct Q16 { u_long128 v; };
struct P16 { unsigned char pad_0[0x10]; };
struct V2_16 { float x; float y; unsigned char pad_8[0x8]; };
struct V4_16 { float x; float y; float z; float w; };
struct UnkStruct_003BFEE0 {
    unsigned char pad_0[0x8];
    CGtV2d field_8;
    CGtV2d field_10;
    CGtV2d field_18;
};
extern UnkStruct_D_0051BA88 D_0051BA88;
extern P16 D_01E90240, D_01E32AE0, D_0051BA44, D_01E8D450, D_01EA5630, D_01EA6B40, D_01EA6BFC, D_01EA54A4;
extern I16 D_0064D3A0, D_01E32B08, D_01EA5638, D_01EA5650, D_01EA6AD4, D_01EA6ADC, D_01EA6AE0, D_01EA57A4, D_01EA57AC, D_01EA57B0, D_01EA6B34, D_01EA6B3C, D_01EA5B64, D_01EA5B6C;
extern B16 D_01E65499, D_0051BA3B, D_01EA5470;
extern F16 D_01EA565C, D_01EA5668, D_01EA5674, D_01EA5680, D_01EA568C, D_01EA5698, D_01EA56A4, D_01EA56B0, D_01EA56C4, D_01EA56C0, D_01EA56D0, D_01EA56CC, D_01EA56DC, D_01EA56D8, D_01EA6B30;
extern F16 D_01EA6AC8, D_01EA6ACC, D_01EA6AD0, D_01EA5798, D_01EA579C, D_01EA57A0, D_01EA5790, D_01EA5794, D_01EA5B50, D_01EA5B54, D_01EA5B60;
extern Q16 D_01EA6AB0, D_01EA5780, D_01EA6AF0, D_01EA5B20, D_01EA5B40;
extern V4_16 D_01EA6B00, D_01EA5B30;
extern V2_16 D_01EA6B28, D_01EA5B58;
struct PT { void * v; unsigned char pad_4[0xC]; };
extern PT D_01EA57A8, D_01EA6B38, D_01EA5B68;
extern "C" void func_003C1FC0();
extern "C" void *func_00271A00(void *, int);
extern "C" void func_00310180(void *, void *, void *);
extern "C" void *func_001A3AA0(void *, void *, int *);
extern "C" int func_0033FF10(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, int, void *, void *, int);
extern "C" void RecalculateSize__17CB3TableComponentFv(void *);
extern "C" void func_003C1990(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetStylisedTextSize__14CB3ResultsPageFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, void *, void *);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern void *D_01EA68A8, *D_01EA68AC, *D_01EA68B0;

// 0x003BFEE0
extern "C" void func_003BFEE0(UnkStruct_003BFEE0 * self)
{
    P16 * const mgr = &D_01E90240;
    int count;
    func_003C1FC0();
    UnkStruct_003BFEE0_b * const s1 = D_0051BA88.field_0->field_1B4;
    if (s1->vfunc_A0() != 0 && s1->vfunc_A8() == 0 && D_01E65499.v == 0) {
        D_01EA5638.v = D_0051BA3B.v + 1;
    } else {
        int a1 = D_0064D3A0.v;
        int a3 = 0;
        int a2 = 0;
        int a0 = D_01E32B08.v;
        for (; a3 < a0; a3++) {
            if (*(int *)((char *)&D_01E32AE0 + a3 * 4 + 8) != 0) {
                a2++;
            }
        }
        D_01EA5638.v = a2 + a1 + 1;
    }
    D_01EA5650.v = 0;
    D_01EA565C.v = 7.0f;
    D_01EA5668.v = 7.0f;
    D_01EA5674.v = 7.0f;
    D_01EA5680.v = 7.0f;
    D_01EA568C.v = 7.0f;
    D_01EA5698.v = 7.0f;
    D_01EA56A4.v = 7.0f;
    D_01EA56B0.v = 7.0f;
    D_01EA56C4.v = 200.0f;
    D_01EA56C0.v = 40.0f;
    D_01EA56D0.v = 50.0f;
    D_01EA56CC.v = 5.0f;
    D_01EA56DC.v = 200.0f;
    D_01EA56D8.v = 5.0f;
    D_01EA6B30.v = 22.0f;
    UnkStruct_003BFEE0_a * const s4 = D_0051BA88.field_0;
    int h = s1->vfunc_100();
    int local;
    bool ok;
    if (h < s4->vfunc_20()) {
        ok = false;
        local = s1->vfunc_100();
    } else {
        ok = true;
    }
    if (ok && D_01EA5470.v != 0) {
        func_00310180(&D_01EA6BFC, func_00271A00(&D_0051BA44, 0x305), &D_01EA54A4);
        D_01EA5780 = D_01EA6AB0;
        D_01EA57A4.v = D_01EA6AD4.v;
        D_01EA57A8.v = &D_01EA6BFC;
        CGtV2d t1(1.0f, 0.5f);
        D_01EA5794.v = t1.marValues[1];
        D_01EA5798.v = D_01EA6AC8.v;
        D_01EA5790.v = t1.marValues[0];
        D_01EA579C.v = D_01EA6ACC.v;
        D_01EA57A0.v = D_01EA6AD0.v;
        D_01EA57AC.v = D_01EA6ADC.v;
        D_01EA57B0.v = D_01EA6AE0.v;
        D_01EA68A8 = (void *)&func_003C1990;
        D_01EA68B0 = &D_01EA5780;
        D_01EA68AC = (void *)&GetStylisedTextSize__14CB3ResultsPageFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
    } else {
        func_001A3AA0(&D_01EA6BFC, func_00271A00(&D_0051BA44, 0x26A), &local);
        D_01EA5B20 = D_01EA6AF0;
        D_01EA6B38.v = &D_01EA6BFC;
        D_01EA5B40 = *(Q16 *)((char *)mgr + 0x10);
        D_01EA5B30 = D_01EA6B00;
        D_01EA5B58 = D_01EA6B28;
        D_01EA5B60.v = D_01EA6B30.v;
        D_01EA5B64.v = D_01EA6B34.v;
        CGtV2d t2(1.0f, 0.5f);
        D_01EA5B68.v = &D_01EA6BFC;
        D_01EA5B6C.v = D_01EA6B3C.v;
        D_01EA5B50.v = t2.marValues[0];
        D_01EA5B54.v = t2.marValues[1];
        D_01EA68A8 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        D_01EA68AC = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        D_01EA68B0 = &D_01EA5B20;
    }
    self->field_8 = CGtV2d(60.0f, 95.0f);
    self->field_10 = CGtV2d(0.0f, 0.0f);
    self->field_18 = CGtV2d(520.0f, (float)305);
    func_0033FF10(&D_01E8D450, CGtV2d(60.0f, 95.0f), CGtV2d(0.0f, 0.0f), CGtV2d(520.0f, (float)305), 0, &D_01EA5630, &D_01EA6B40, 0);
    RecalculateSize__17CB3TableComponentFv(&D_01E8D450);
}
