// NONMATCHING: func_003AE120 -- retail 509 / ours 509 instructions, 80 in changed runs
// big1: logic complete, 509/509 instrs, frame 0x240 equal, 80 changed. Left: stack-slot assignment only -- CGtV4d(1,1,1,1) ctor temps (retail t1 0x130/t2 0x120, ours 0x120/0x110), b2 named colour (retail 0x110, ours 0x170), b1 h/tp temp swap (retail h 0x1E0 tp 0x1E8), and retail schedules the D_004C9FA8 size load ahead of the colour stores. Tried: colour by value/const-ref/local copy in the inline (copy inside the inline gives the frame), named vs temp anchor, one inline with an active flag for both arms (same slots), int d before size. Arms: if/else on idx<lim, if-chain for field_254 offsets (switch is wrong).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_003AE120 -- hand-written from retail (lifter refused). [L] CB3SatNavComponent (same unit as
// func_003AD3E0/func_003ADA10; DNAT pairs the next function func_003AE920 with CB3SatNavComponent::Release).
// Per stage row i < field_8E0: prepare the row's icon object (field_18C[i]) and, for states 2/3, its
// label (field_1C0[i]); rows past the end lose their objects.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CGt2dFrame;
class CGt2dFont;
struct UnkStruct_003AE120_obj {
    unsigned char pad_0[0x20];
    int field_20;
    int field_24;
    int field_28;
    float field_2C;
    float field_30;
    unsigned char field_34;
    unsigned char field_35;
    unsigned char field_36;
};
struct UnkStruct_003AE120 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x182];
    UnkStruct_003AE120_obj * field_18C[13];
    UnkStruct_003AE120_obj * field_1C0[12];
    unsigned char pad_1F0[0x38];
    CGt2dFrame * field_228;
    unsigned char pad_22C[0x28];
    int field_254;
    unsigned char pad_258[0x4C];
    int field_2A4[12];
    unsigned char pad_2D4[0x2A8];
    int field_57C[3][28];
    unsigned char pad_6CC[0x214];
    int field_8E0;
    unsigned char pad_8E4[0xC];
    char field_8F0[0x40];
};
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x110]; CGtV4d field_110; };
struct UnkStruct_D_00665ED0 { CGt2dFont * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_0051BA44 D_0051BA44;
struct UnkStruct_D_004C9FA8 { CGtV2d field_0; unsigned char pad_8[0x8]; };
extern UnkStruct_D_004C9FA8 D_004C9FA8;
extern "C" void func_003B0160(void *, void *);
extern "C" UnkStruct_003AE120_obj * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, CGt2dFrame *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, UnkStruct_003AE120_obj *);
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, unsigned int, unsigned int);
extern "C" int func_003F5D10(int);
extern "C" int func_003EA530(int);
extern "C" CGtV2d func_003F5C70(int, int, int);
extern "C" int func_003F57A0(int, int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003D0960(void *, int, void *, int);
extern "C" void func_003D0710(UnkStruct_003AE120_obj *, const CGtV2d &, const CGtV2d &, CGtV4d, int, int, int, CGt2dFont *, float, float, void *, int);

static inline void func_003AE120_inl1(UnkStruct_003AE120_obj * o, const CGtV2d & pos, const CGtV2d & size, CGtV4d colour, int c0, int c1, int c2, int idx)
{
    CGtV4d col = colour;
    o->field_34 = c0;
    o->field_35 = c1;
    o->field_30 = 0.0f;
    o->field_28 = 0;
    o->field_24 = 0;
    o->field_36 = c2;
    o->field_20 = idx;
    CGtV2d h = size * 0.5f;
    CGtV2d tp = pos - h;
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(o, tp, size, col, (const void *)func_003B0160, 64, 24);
    o->field_2C = 1.0f;
}

// 0x003AE120
extern "C" void func_003AE120(UnkStruct_003AE120 * self)
{
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    CGtV2d pos;
    CGtV2d size;
    int a = self->field_8 + 8;
    int b = self->field_8 + 9;
    self->field_8E0 = func_003F5D10(self->field_254);
    int lim = func_003EA530(self->field_254);
    int off = 1;
    if (self->field_254 == 1) off = 7; else if (self->field_254 == 2) off = 0xF;
    int i;
    for (i = 0; i < self->field_8E0; i++) {
        int idx = self->field_57C[self->field_254][i];
        bool done = false;
        if (idx < lim) {
            int * st = &self->field_2A4[i];
            if (*st != 0) {
                if (self->field_18C[i] == 0) self->field_18C[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, a, self->field_228);
                pos = func_003F5C70(self->field_254, i, 1);
                float dir = (float)func_003F57A0(self->field_254, i);
                size = D_004C9FA8.field_0;
                CGtV4d col;
                col = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
                int c0 = 0x2F;
                int c1 = 0x30;
                switch (*st) {
                case 1:
                    size = D_004C9FA8.field_0 * 0.5f;
                    break;
                case 2:
                    break;
                case 3:
                    c0 = 0x35;
                    c1 = 0x36;
                    break;
                case 4:
                    c0 = 0x31;
                    size = D_004C9FA8.field_0 * 0.5f;
                    break;
                }
                func_003AE120_inl1(self->field_18C[i], pos, size, col, c0, c1, idx + off, idx);
                if (*st == 2 || *st == 3) {
                    if (self->field_1C0[i] == 0) self->field_1C0[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, b, self->field_228);
                    if (dir > 0.0f) {
                        pos -= CGtV2d(35.0f, 15.0f);
                    } else {
                        pos += CGtV2d(35.0f, -15.0f);
                    }
                    func_003D0960(self->field_8F0, 0x20, (void *)(func_00271A00(&D_0051BA44, 0x109)), 0);
                    func_003D0710(self->field_1C0[i], pos, CGtV2d(dir, 1.0f), mgr->field_110, 1, 2, 0, D_00665ED0.field_0, 60.0f, 3.402823466e+38f, self->field_8F0, 0);
                }
                done = true;
            }
        } else {
            int * st = &self->field_2A4[i];
            if (*st != 0) {
                if (self->field_18C[i] == 0) self->field_18C[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, a, self->field_228);
                pos = func_003F5C70(self->field_254, i, 1);
                float dir = (float)func_003F57A0(self->field_254, i);
                size = D_004C9FA8.field_0;
                CGtV4d col;
                col = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
                int c0 = 0x32;
                switch (*st) {
                case 1:
                    size = D_004C9FA8.field_0 * 0.5f;
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    c0 = 0x34;
                    size = D_004C9FA8.field_0 * 0.5f;
                    break;
                }
                func_003AE120_inl1(self->field_18C[i], pos, size, col, c0, 0x33, -1, idx);
                if (*st == 2 || *st == 3) {
                    if (self->field_1C0[i] == 0) self->field_1C0[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, b, self->field_228);
                    if (dir > 0.0f) {
                        pos -= CGtV2d(35.0f, 15.0f);
                    } else {
                        pos += CGtV2d(35.0f, -15.0f);
                    }
                    func_003D0960(self->field_8F0, 0x20, (void *)(func_00271A00(&D_0051BA44, 0x109)), 0);
                    func_003D0710(self->field_1C0[i], pos, CGtV2d(dir, 1.0f), mgr->field_110, 1, 2, 0, D_00665ED0.field_0, 60.0f, 3.402823466e+38f, self->field_8F0, 0);
                }
                done = true;
            }
        }
        if (!done) {
            if (self->field_18C[i] != 0) {
                DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, self->field_18C[i]);
                self->field_18C[i] = 0;
            }
            if (self->field_1C0[i] != 0) {
                DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, b, self->field_1C0[i]);
                self->field_1C0[i] = 0;
            }
        }
    }
    for (int j = self->field_8E0; j < 12; j++) {
        if (self->field_18C[j] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a, self->field_18C[j]);
            self->field_18C[j] = 0;
        }
        if (self->field_1C0[j] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, b, self->field_1C0[j]);
            self->field_1C0[j] = 0;
        }
    }
}
