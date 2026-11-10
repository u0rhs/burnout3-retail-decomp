// NONMATCHING: func_003AB850 -- retail 584 / ours 584 instructions, 126 in changed runs
// prag1: scoped opt_lifetimes off [G] alone: 224 -> 126, length now 584/584. Left: s-register rotation (fp/s7, s0/s1) and the order of four spilled v1+K address slots (sp+272/336/352); second-pragma sweep no gain; source shape not re-tuned under the pragma yet
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// big1: logic complete, 579/584 instrs, 224 changed, block layout matches (out-of-line &&-chains, construct blocks, guarded count-down loop with R5900 nops). Left: register allocation -- retail l13 in s5 and list/search-i in s1 (ours swapped), keeps n in s7 and spills the &field_A4[i].field_C CSE pointer (sq 0x100/0xF0/0xD0/0xB0, plus the row base in branch 2) where ours spills n and keeps the pointer in s8; frame 0x250 vs 0x220 follows. 20+ declaration orders, named ref/ptr id locals change nothing. Found: text = func_00271A00(...) must be a local before func_003824D0 (temps after the call); 'found > 5' / '> 6' for slti at; field_252 store before field_250.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_003AB850 -- hand-written from retail (lifter refused). [L] CB3SatNavComponent (same unit as
// func_003AB640/func_003AD3E0; DNAT pairs func_003AE920 with CB3SatNavComponent::Release). Builds the stage
// list panel: frame, rows, the first unlocked row, scroll arrows and the fixed backdrop/title objects.

#include "b3/GtMathPs2.h"
// N182: `#pragma opt_lifetimes off` [G] scoped to this function (N236: pragmas are per-function).
#pragma push
#pragma opt_lifetimes off
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
class CGt2dFrame;
class CGtTexture;
struct UnkStruct_003AB850_row { void * field_0; void * field_4; void * field_8; int field_C; };
struct UnkStruct_003AB850_lay { unsigned int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003AB850_frm { CGtV2d field_0; };
struct UnkStruct_003AB850 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x9A];
    UnkStruct_003AB850_row field_A4[12];
    unsigned char pad_164[0xBC];
    void * field_220;
    void * field_224;
    unsigned char pad_228[0x8];
    void * field_230;
    void * field_234;
    void * field_238;
    void * field_23C;
    void * field_240;
    void * field_244;
    void * field_248;
    UnkStruct_003AB850_frm * field_24C;
    unsigned short field_250;
    unsigned short field_252;
    unsigned char pad_254[0x28];
    int field_27C;
    unsigned char pad_280[0x50C];
    int field_78C[3];
    unsigned char pad_798[0x144];
    int field_8DC;
    unsigned char pad_8E0[0x5];
    signed char field_8E5;
    unsigned char field_8E6;
    unsigned char field_8E7;
    unsigned char pad_8E8[0xD0];
    int field_9B8;
    int field_9BC;
};
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x14]; CGt2dFrame * field_14; unsigned char pad_18[0x14]; UnkStruct_003AB850_lay * field_2C; };
extern UnkStruct_D_01E903E0 D_01E903E0;
struct UnkStruct_D_01E90240 { CGtV4d field_0[0x13]; };
extern UnkStruct_D_01E90240 D_01E90240;
struct UnkStruct_D_Pad16 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_Pad16 D_0051BF9C, D_01EA46B4, D_01EA46BC, D_01E95928, D_0051BA44;
struct UnkStruct_D_0051A868 { void * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051A868 D_0051A868;
extern unsigned char D_004E2E98;
struct UnkStruct_D_V2 { CGtV2d field_0; unsigned char pad_8[0x8]; };
extern UnkStruct_D_V2 D_004CA020, D_004CA028, D_004CA030, D_004CA038, D_004CA040, D_004CA048, D_004CA050, D_004CA058;
extern const CGtV4d D_004CA010, D_004CA060, D_004CA070;
struct UnkStruct_D_004CA0C8 { char field_0[0x10]; };
extern UnkStruct_D_004CA0C8 D_004CA0C8;

struct UnkStruct_003AB850_e0 { unsigned char pad_0[0x8]; int field_8; unsigned char pad_C[0x4]; };
struct UnkStruct_003AB850_2 { unsigned char pad_0[0x8]; int field_8; UnkStruct_003AB850_e0 * field_C; };
// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113, B3HUDImpactTime_003D6AB0).
struct UnkStruct_003AB850_blk { unsigned char pad_0[0x18]; char field_18[8]; };

extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
extern "C" UnkStruct_003AB850_frm * ConstructChild__10CGt2dFrameFv(void *);
extern "C" void SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(void *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const void *, const void *, const void *, CGtV4d, CGtTexture *, const void *, const void *, unsigned int);
extern "C" void Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d);
extern "C" bool Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, unsigned int, int);
extern "C" void func_003824D0(void *, const CGtV2d &, const CGtV2d &, float, CGtV4d, CGtV4d, const unsigned short *, int, float, float);
extern "C" void func_003B0870(void *, float, int);
extern "C" void func_003AB540(UnkStruct_003AB850 *, float);
extern "C" int func_003A8570(UnkStruct_003AB850 *);
extern "C" int func_003F5B30(int, int);
extern "C" unsigned short * func_00271A00(void *, int);
extern "C" int func_0013AD30(void *, int, int);
extern "C" int func_0013AD70(void *, int, int);
extern "C" int strcasecmp(const char *, const void *);

static inline int big1_pminw(int a, int b)
{
    int r;
    asm("pminw %0,%1,%2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline int big1_pextlw0(int a)
{
    int r;
    asm("pextlw %0,$0,%1" : "=r"(r) : "r"(a));
    return r;
}

// 0x003AB850
extern "C" void func_003AB850(UnkStruct_003AB850 * self)
{
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    CGtTexture * tex;
    int n;
    int prof = D_0051BF9C.field_0;
    UnkStruct_003AB850_2 * list = (UnkStruct_003AB850_2 *)D_0051A868.field_0;
    int l13 = self->field_8 + 0x13;
    int sel;
    int found;
    int i;
    CGt2dFrame * root = scene->field_14;
    int l15 = self->field_8 + 0xF;
    int l16 = self->field_8 + 0x10;
    int l10 = self->field_8 + 0xA;
    int l17 = self->field_8 + 0x11;
    int l18 = self->field_8 + 0x12;
    int l20 = self->field_8 + 0x14;
    for (i = 0; i < list->field_8; i++) {
        int t2 = list->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_003AB850_blk *)(t2 + 0x90))->field_18, &D_004CA0C8) == 0) {
            tex = (CGtTexture *)t2;
            goto found_tex;
        }
    }
    tex = 0;
found_tex:
    self->field_252 = self->field_78C[self->field_27C];
    self->field_250 = 0;
    self->field_8E5 = -1;
    self->field_8DC = 0;
    self->field_24C = ConstructChild__10CGt2dFrameFv(root);
    SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(self->field_24C);
    self->field_24C->field_0 = CGtV2d(656.0f, 0.0f);
    scene->field_2C[l15].field_0 = 8;
    scene->field_2C[l16].field_0 = 0x10;
    for (i = 0; i < self->field_252; i++) {
        UnkStruct_003AB850_row * r = &self->field_A4[i];
        if (r->field_0 == 0) r->field_0 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l13, self->field_24C);
        if (r->field_4 == 0) r->field_4 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l13, self->field_24C);
        func_003B0870(r, 0.0f, 0);
    }
    self->field_8E7 = 1;
    D_004E2E98 = 1;
    found = -1;
    if (self->field_8E6 == 0) {
        n = self->field_78C[self->field_27C];
        for (i = 0; i < n; i++) {
            if (func_0013AD30((void *)(prof), self->field_A4[i].field_C, 1) <= 0 && func_0013AD70((void *)(prof), self->field_A4[i].field_C, 1) == 0 && self->field_A4[i].field_0 != 0)
                found = i;
        }
        if (found == -1) {
            found = 0;
            for (i = 0; i < n; i++) {
                if (func_0013AD30((void *)(prof), self->field_A4[i].field_C, 1) < 3 && func_0013AD70((void *)(prof), self->field_A4[i].field_C, 1) == 0 && self->field_A4[i].field_0 != 0)
                    found = i;
            }
        }
        sel = found;
    } else {
        n = big1_pextlw0(big1_pminw(self->field_78C[self->field_27C], 6));
        for (i = 0; i < self->field_78C[self->field_27C]; i++) {
            if (func_0013AD30((void *)(prof), self->field_A4[i].field_C, 0) <= 0 && func_0013AD70((void *)(prof), self->field_A4[i].field_C, 0) == 0 && self->field_A4[i].field_0 != 0)
                found = i;
        }
        if (found == -1) {
            found = 0;
            for (i = 0; i < self->field_78C[self->field_27C]; i++) {
                if (func_0013AD30((void *)(prof), self->field_A4[i].field_C, 0) < 3 && func_0013AD70((void *)(prof), self->field_A4[i].field_C, 0) == 0 && self->field_A4[i].field_0 != 0)
                    found = i;
            }
        }
        sel = found;
        if (found > 5) {
            if (found > 0) {
                sel = 5;
                for (; found > 0; found--) func_003A8570(self);
            }
        } else {
            self->field_9B8 = found;
        }
        if (self->field_78C[self->field_27C] > 6) {
            if (self->field_220 == 0) self->field_220 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l13, self->field_24C);
            if (self->field_224 == 0) self->field_224 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l13, self->field_24C);
            CGtV4d c1;
            CGtV4d c2;
            if (self->field_9B8 > 0) c1 = D_004CA060; else c1 = D_004CA070;
            if (self->field_9B8 < self->field_9BC) c2 = D_004CA060; else c2 = D_004CA070;
            Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_220, &D_004CA028, &D_004CA020, &D_004CA038, c1, tex, &D_004CA040, &D_004CA058, 0);
            Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_224, &D_004CA030, &D_004CA020, &D_004CA038, c2, tex, &D_004CA050, &D_004CA048, 0);
        }
    }
    sel = big1_pextlw0(big1_pminw(sel, 5));
    for (i = 6; i < self->field_252; i++) {
        UnkStruct_003AB850_row * r = &self->field_A4[i];
        if (r->field_0 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, l13, r->field_0);
            r->field_0 = 0;
        }
        if (r->field_4 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, l13, r->field_4);
            r->field_4 = 0;
        }
        if (r->field_8 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, l20, r->field_8);
            r->field_8 = 0;
        }
    }
    self->field_250 = sel;
    self->field_252 = n;
    self->field_230 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l10, self->field_24C);
    self->field_234 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l15, self->field_24C);
    self->field_238 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l15, self->field_24C);
    self->field_23C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l16, self->field_24C);
    self->field_240 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l17, self->field_24C);
    self->field_244 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l18, self->field_24C);
    self->field_248 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, l13, root);
    Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(self->field_230, CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 0.0f), CGtV2d(16.0f, 416.0f), D_004CA010);
    Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(self->field_234, CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 0.0f), CGtV2d(2.0f, 416.0f), mgr->field_0[0x12]);
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_238, &CGtV2d(0.0f, 0.0f), &CGtV2d(0.0f, 0.0f), &CGtV2d(240.0f, 416.0f), mgr->field_0[0x11], (CGtTexture *)D_01EA46B4.field_0, &CGtV2d(0.390625f, 0.0f), &CGtV2d(0.625f, 0.8125f), 0);
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_23C, &CGtV2d(0.0f, 0.0f), &CGtV2d(0.0f, 0.0f), &CGtV2d(240.0f, 416.0f), mgr->field_0[0xF], (CGtTexture *)D_01EA46BC.field_0, &CGtV2d(0.0625f, 0.0625f), &CGtV2d(14.9375f, 25.9375f), 0);
    const unsigned short * text = func_00271A00(&D_0051BA44, func_003F5B30(D_01E95928.field_0, self->field_27C));
    func_003824D0(self->field_244, CGtV2d(120.0f, 78.0f), CGtV2d(0.5f, 0.0f), 24.0f, mgr->field_0[4], mgr->field_0[5], text, 0x12, 1.0f, 3.402823466e+38f);
    Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(self->field_240, CGtV2d(240.0f, 75.0f), CGtV2d(1.0f, 0.0f), CGtV2d(230.0f, 30.0f), 0x48, 0);
    func_003AB540(self, 1.0f);
}

#pragma pop
