// NONMATCHING: func_00445970 -- retail 202 / ours 202 instructions, 32 in changed runs
// a158: logic+layout exact (202/202 instrs, entry-jump goto loop, recomputed cy before loop 2, h1/h2 float locals, padded D_004D2F80); 32 instrs left = register numbering only: retail loop2 has mgr2=s3, &field_38[i]=s1 (ours s1/s3 swapped) and float regs f2=h,f0=const,f1=24.0 (ours f1/f2/f0). Declaration-order sweeps (24 perms) did not move s1/s3.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00445970 -- hand-written (a158): page Prepare (a1 = pos, a2 = size): six scene objects, two strings, background + two columns of text.
#include "b3/GtMathPs2.h"
class CGt2dFrame;
class CGt2dFont;
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];
    CGtV4d field_10;
    unsigned char pad_20[0xF0];
    CGtV4d field_110;
    unsigned char pad_120[0x60];
    CGtV4d field_180;
};
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x14]; void *field_14; };
struct UnkStruct_D_00665ED0 { CGt2dFont *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };
struct UnkStruct_00445970 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[2];
    int field_C[6];
    unsigned char pad_24[4];
    CGtV2d field_28;
    CGtV2d field_30;
    int field_38[2];
};
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_P16 D_0051BA44;
extern UnkStruct_P16 D_01E90438;
extern UnkStruct_P16 D_0051AEC0;
extern UnkStruct_P16 D_004EE040;
extern float D_004D2F78[];
struct UnkStruct_D_004D2F80 { CGtV2d field_0; unsigned char pad_8[8]; };
extern UnkStruct_D_004D2F80 D_004D2F80;
extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, unsigned int);
extern "C" void *func_00271A00(void *, int);
extern "C" void func_003D0710(void *, const CGtV2d &, const CGtV2d &, CGtV4d, int, int, int, CGt2dFont *, float, float, void *, int);
extern "C" int func_0013C930(void *, int);
extern "C" void PrintUInt__10CGtUnicodeFPUsUii(int, int, int);
extern "C" void func_0033D4E0(void *, const CGtV2d &, const CGtV2d &, float, CGtV4d, CGt2dFont *, const unsigned short *, const CGtV2d *, int);

// 0x00445970
extern "C" int func_00445970(UnkStruct_00445970 *self, const CGtV2d *p0, const CGtV2d *p1)
{
    Prepare__20CB3MenuComponentBaseFv(self);
    UnkStruct_D_01E903E0 *const scene = &D_01E903E0;
    void *frame = scene->field_14;
    int layer = self->field_8;
    UnkStruct_D_01E90240 *const mgr = &D_01E90240;
    self->field_28 = *p0;
    self->field_30 = *p1;
    float cy = 0.0f + self->field_28.marValues[1] + 0.5f * self->field_30.marValues[1];
    int i;
    for (i = 0; i < 6; i++)
        self->field_C[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, frame);
    self->field_38[0] = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 16);
    self->field_38[1] = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 16);
    Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi((void *)self->field_C[5], CGtV2d(self->field_28.marValues[0], 1.0f + self->field_28.marValues[1]), CGtV2d(0.0f, 0.0f), self->field_30, mgr->field_110, 3);
    void *text = func_00271A00(&D_0051BA44, 0x9E2);
    float sc = 1.1f * self->field_30.marValues[1];
    func_003D0710((void *)(self->field_C[0]), CGtV2d(self->field_28.marValues[0] + 24.0f, cy), CGtV2d(0.0f, 0.5f), mgr->field_110, 1, 1, 0, D_00665ED0.field_0, sc, 3.402823466e+38f, text, 0);
    cy = 0.0f + self->field_28.marValues[1] + 0.5f * self->field_30.marValues[1];
    UnkStruct_D_01E90240 *const mgr2 = &D_01E90240;
    int j;
    float x;
    int *s;
    j = 0;
    goto test;
body:
    {
        x = 0.0f + self->field_28.marValues[0] + D_004D2F78[j] * self->field_30.marValues[0];
        s = &self->field_38[j];
        PrintUInt__10CGtUnicodeFPUsUii(*s, func_0013C930(&D_0051AEC0, j), 0);
        float h1 = 0.7f * self->field_30.marValues[1];
        func_0033D4E0((void *)(self->field_C[1 + j]), CGtV2d(x, self->field_28.marValues[1] - 2.0f), CGtV2d(0.5f, 1.0f), h1, mgr2->field_10, D_00665ED0.field_0, (const unsigned short *)((char *)&D_004EE040 + j * 36 + 0x28DB4), &D_004D2F80.field_0, 2);
        float h2 = 1.2f * self->field_30.marValues[1];
        func_0033D4E0((void *)(self->field_C[3 + j]), CGtV2d(x, cy), CGtV2d(0.5f, 0.5f), h2, mgr2->field_180, D_00665ED0.field_0, (const unsigned short *)*s, &D_004D2F80.field_0, 2);
    }
    j++;
test:
    if (j < 2) goto body;
    return 1;
}
