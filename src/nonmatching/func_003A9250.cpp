// NONMATCHING: func_003A9250 -- retail 482 / ours 482 instructions, 161 in changed runs
// audit1 (2026-11-01): func_003B10A0's last parameter is a float (f12 = 0 in retail); the int prototype left f12 unset [C] retail 0x3A96A0 (behaviour_audit) | Before: a175: logic-complete, 482/482 instrs, 157 in changed runs. Left: (1) else-branch (ret!=0x2F) chain [71C==1 / 2A4==4 / 102] lays out inline here but retail keeps f(0xB37) inline and the chain out of line (B37..B41), tried if/else-if, flipped arms, gotos, static inline; the ret==0x2F chain is out of line via 'if (1C0==0) goto chain1;' after the final call. (2) stack slots: retail has locals at 0x108..0x164 in a different order (temps CGtV2d 0x118/0x120/0x128, 0x130/0x138/0x140 for the Prepare args; ours shifted by 0x10-0x20). (3) mtc1 18.0f/D_00665ED0 load scheduling before func_001D6C40 second call. sq/lq of i*4 spill (0xC0) was int-spill pattern and appears without effort. | classic-op fallback | guard: n/a (classic ops) | mwperm: 157 -> 156 (+'short t0 = self->field_8;'; 'short t0 = self->field_8;' -> ''; 'join:' -> 'join:'; 'tail:' -> 'tail:'; 'chain1: if (self->field_71C[self->field_2
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
class CGt2dObject;
class CGt2dFrame;
class CGtTexture;
class CB3HardCodedRaceStageList {
public:
    unsigned long GetStageGtID(int, int);
    int GetChallengeType(int);
};
struct UnkStruct_003A9250_f { unsigned char pad_0[8]; float field_8; };
struct UnkStruct_003A9250_s40 { CGt2dObject * field_0; CGt2dObject * field_4; CGt2dObject * field_8; unsigned char field_C; unsigned char pad_D[0x33]; };
struct UnkStruct_003A9250_s80 { CGt2dObject * field_0; CGt2dObject * field_4; CGt2dObject * field_8; CGt2dObject * field_C; unsigned char field_10[8]; unsigned char field_18[8]; unsigned char pad_20[2]; unsigned char field_22; unsigned char pad_23[1]; };
struct UnkStruct_003A9250 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x36];
    UnkStruct_003A9250_s40 field_40;
    UnkStruct_003A9250_s80 field_80;
    unsigned char pad_A4[0x11C];
    int field_1C0[1];
    unsigned char pad_1C4[0x64];
    UnkStruct_003A9250_f * field_228;
    unsigned char pad_22C[0x28];
    int field_254;
    unsigned char pad_258[0x24];
    int field_27C;
    unsigned char pad_280[0x24];
    int field_2A4[1];
    unsigned char pad_2A8[0x5C];
    int field_304[1];
    unsigned char pad_308[0x414];
    int field_71C[1];
    unsigned char pad_720[0x6C];
    int field_78C[1];
    unsigned char pad_790[0x6C];
    int field_7FC[1];
    unsigned char pad_800[0x6C];
    int field_86C[1];
    unsigned char pad_870[0x76];
    unsigned char field_8E6;
    unsigned char pad_8E7[0x2];
    unsigned char field_8E9;
    unsigned char pad_8EA[0x2];
    int field_8EC;
    unsigned char pad_8F0[0x40];
    unsigned char field_930[8];
};
struct UnkStruct_D_01E88D40 { unsigned short field_0; unsigned char pad_2[0xE]; };
struct UnkStruct_D_0051BF9C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x14]; CGt2dFrame * field_14; };
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x110]; CGtV4d field_110; };
struct UnkStruct_pad { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01EA { CGtTexture * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00665ED0 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_pad D_01E7A800;
extern UnkStruct_pad D_0051BA44;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_01EA D_01EA455C;
extern UnkStruct_D_01EA D_01EA456C;
extern UnkStruct_pad D_004CA080;
extern UnkStruct_pad D_004CA088;
extern float D_004E06DC;
extern "C" CGt2dObject * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, CGt2dFrame *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, CGtTexture *, const CGtV2d &, const CGtV2d &, unsigned int);
extern "C" void Update__Q218CB3SatNavComponent9CPopupBoxFfRCQ29GtMathPs26CGtV2d(UnkStruct_003A9250_s40 *, const CGtV2d &, float);
extern "C" int func_0013AD30(int, int, int);
extern "C" int func_0013AD70(int, int, int);
extern "C" void func_001A3AA0(void *, int, void *);
extern "C" void func_001D6AD0(CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV4d &, int, const void *, const CGtV2d &, int, float);
extern "C" void func_001D6C40(CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV4d &, int, int, float);
extern "C" int func_00271A00(void *, int);
extern "C" void func_00285150(void *);
extern "C" void func_003B10A0(void *, const CGtV2d &, int, float);   // audit1: 4th parameter is a float (f12), as func_003B10A0's own archive [C] retail 0x3A96A0
extern "C" unsigned char func_003F57A0(int, int);
extern "C" int func_003F5B30(int, int);
extern "C" int func_003F5C00(int, int);
extern "C" CGtV2d func_003F5C70(int, int, int);
extern "C" int func_003F5E40(unsigned long);
extern "C" int sprintf(char *, const void *, ...);
extern "C" void ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(const char *, void *, int);

// 0x003A9250
extern "C" void func_003A9250(UnkStruct_003A9250 * self)
{
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    short t0 = self->field_8;
    UnkStruct_003A9250_s40 * a = &self->field_40;
    UnkStruct_003A9250_s80 * bb = &self->field_80;
    CGt2dFrame * root = scene->field_14;
    int x = D_0051BF9C.field_0;
    CGtV2d zero(0.0f, 0.0f);
    int c1 = t0 + 11;
    int fp = t0 + 13;
    int c0 = t0 + 12;
    char buf[4];
    self->field_8E9 = 0;
    a->field_0 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, t0 + 10, root);
    a->field_4 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, fp, root);
    a->field_8 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, fp, root);
    a->field_C = func_003F57A0(self->field_254, self->field_27C);
    func_00285150(&D_01E7A800);
    func_001D6C40(a->field_4, zero, zero, mgr->field_110, D_00665ED0.field_0, func_00271A00(&D_0051BA44, func_003F5B30(self->field_254, self->field_27C)), 18.0f);
    if (func_003F5C00(self->field_254, self->field_27C) == 0x2F) {
        if (self->field_1C0[self->field_27C] == 0) goto chain1;
        {
            for (int i = 0; i < self->field_78C[self->field_27C]; i++) {
                if (func_0013AD70(x, *(int *)((char *)self + self->field_27C * 0x30 + i * 4 + 0x304), 1) == 0) {
                    if (func_0013AD30(x, *(int *)((char *)self + self->field_27C * 0x30 + i * 4 + 0x304), 1) <= 0) {
                        int ct = ((CB3HardCodedRaceStageList *)*(int *)((char *)self + self->field_27C * 0x30 + i * 4 + 0x304))->GetChallengeType(0);
                        if (func_003F5E40(((CB3HardCodedRaceStageList *)*(int *)((char *)self + self->field_27C * 0x30 + i * 4 + 0x304))->GetStageGtID(0, 0)) != 0) {
                            self->field_8EC = func_00271A00(&D_0051BA44, 0x9BD);
                        } else {
                            switch (ct) {
                            case 1: self->field_8EC = func_00271A00(&D_0051BA44, 0x106); break;
                            case 6: self->field_8EC = func_00271A00(&D_0051BA44, 0x104); break;
                            case 7: self->field_8EC = func_00271A00(&D_0051BA44, 0x9BB); break;
                            case 8: self->field_8EC = func_00271A00(&D_0051BA44, 0x107); break;
                            case 9: self->field_8EC = func_00271A00(&D_0051BA44, 0x108); break;
                            case 2: self->field_8EC = func_00271A00(&D_0051BA44, 0x105); break;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (self->field_1C0[self->field_27C] == 0) goto chain2;
        {
            self->field_8EC = func_00271A00(&D_0051BA44, 0xB37);
        }
    }
join:
    func_001D6C40(a->field_8, zero, zero, mgr->field_110, D_00665ED0.field_0, self->field_8E9 ? (int)(self->field_930) : self->field_8EC, 18.0f);
    CGtV2d pos = func_003F5C70(self->field_254, self->field_27C, (self->field_8E6 != 0) ^ 1);
    Update__Q218CB3SatNavComponent9CPopupBoxFfRCQ29GtMathPs26CGtV2d(a, pos, 0.0f);
    bb->field_4 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, c1, root);
    bb->field_0 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, c0, root);
    bb->field_22 = func_003F57A0(self->field_254, self->field_27C);
    if (self->field_86C[self->field_27C] != 0) goto big;
    {
        bb->field_8 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, fp, root);
        bb->field_C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, fp, root);
        sprintf(buf, &D_004CA080, self->field_7FC[self->field_27C]);
        ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(buf, bb->field_10, 4);
        func_001D6AD0(bb->field_8, zero, zero, mgr->field_110, D_00665ED0.field_0, bb->field_10, CGtV2d(D_004E06DC, D_004E06DC), 2, 30.0f);
        sprintf(buf, &D_004CA088, self->field_71C[self->field_27C]);
        ConvertUTF8toUTF16__10CGtUnicodeFPCUcPUsi(buf, bb->field_18, 4);
        func_001D6AD0(bb->field_C, zero, zero, mgr->field_110, D_00665ED0.field_0, bb->field_18, CGtV2d(D_004E06DC, D_004E06DC), 2, 17.0f);
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(bb->field_0, zero, zero, CGtV2d(30.0f, 30.0f), mgr->field_110, D_01EA455C.field_0, CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 1.0f), 0);
    }
tail:
    CGt2dObject * o = a->field_0;
    float n = *(float *)((char *)o + 8);
    float d = self->field_228->field_8;
    CGtV2d q = func_003F5C70(self->field_254, self->field_27C, (self->field_8E6 != 0) ^ 1);
    CGtV2d r(q.marValues[0] + n / d, q.marValues[1] + 0.0f);
    func_003B10A0(bb, r, 0, 0.0f);   // audit1 [C] retail 0x3A96A0: f12 = 0.0
    return;
chain1:
    if (self->field_71C[self->field_27C] == 1) {
        self->field_8EC = func_00271A00(&D_0051BA44, 0x12D);
    } else if (self->field_2A4[self->field_27C] == 4) {
        self->field_8EC = func_00271A00(&D_0051BA44, 0x103);
    } else {
        self->field_8E9 = 1;
        func_001A3AA0(self->field_930, func_00271A00(&D_0051BA44, 0x102), &self->field_71C[self->field_27C]);
    }
    goto join;
chain2:
    if (self->field_71C[self->field_27C] == 1) {
        self->field_8EC = func_00271A00(&D_0051BA44, 0x12D);
    } else if (self->field_2A4[self->field_27C] == 4) {
        self->field_8EC = func_00271A00(&D_0051BA44, 0x103);
    } else {
        self->field_8E9 = 1;
        func_001A3AA0(self->field_930, func_00271A00(&D_0051BA44, 0x102), &self->field_71C[self->field_27C]);
    }
    goto join;
big:
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(bb->field_0, zero, zero, CGtV2d(47.0f, 23.5f), mgr->field_110, D_01EA456C.field_0, CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 1.0f), 0);

    goto tail;
}
