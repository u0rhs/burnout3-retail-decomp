// NONMATCHING: func_001A3C70 -- retail 177 / ours 177 instructions, 44 in changed runs
// ghvu10: [L] DNAT CB3HUDSpeedo::Prepare. 177/177, frame exact, 44 changed: &D_0066A4C0 (retail s1) and the layer/text value (retail s2) are swapped, which shifts the argument temporaries around the two func_003824D0 calls (Interpolate(field_60, field_30, 0.25/0.75) via header). Logic and shapes from ActualPrepare__20CB3HUDEscapeDistance / func_001A22A0; sreg 2 rounds took 58 -> 46, declaration orders -> 44.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_001A3C70 -- hand-written (ghvu10, Ghidra draft; shapes from ActualPrepare__20CB3HUDEscapeDistance and func_001A22A0).
// [L] DNAT: CB3HUDSpeedo::Prepare(int, EHUDAlign, int) (research/proto/new_names.csv, low). Area not evidenced, so
// _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G].

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

enum EHUDAlign {};
class CGt2dFrame;
struct UnkStruct_001A3C70_e1 { unsigned char pad_0[0x70]; };
struct UnkStruct_001A3C70_obj { float field_0; float field_4; };
struct UnkStruct_001A3C70_font { unsigned char pad_0[0x10]; float field_10; };
struct UnkStruct_001A3C70 {
    unsigned char pad_0[0x4];
    UnkStruct_001A3C70_e1 *field_4;
    void *field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    UnkStruct_001A3C70_obj *field_20[3];
    unsigned char *field_2C;
    unsigned short field_30[8];
    CGtV2d field_40;
    int field_48;
};
struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x10];
    CGtV4d field_10;
    unsigned char pad_20[0x10];
    CGtV4d field_30;
    unsigned char pad_40[0x20];
    CGtV4d field_60;
};
struct UnkStruct_D_00665ED0 { UnkStruct_001A3C70_font *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_00645170 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_00645170 D_00645170;
extern unsigned char D_0055EF70[];
extern unsigned int D_004E2918;
extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);
extern "C" void AdjustScalingForSplitScreen__15CB3HUDComponentFv(void *);
extern "C" UnkStruct_001A3C70_obj *ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, unsigned int);
extern "C" const unsigned short *func_00271A00(void *, int);
extern "C" void func_003824D0(UnkStruct_001A3C70_obj *, const CGtV2d &, const CGtV2d &, float, CGtV4d, CGtV4d, const unsigned short *, int, float, float);

// 0x001A3C70
extern "C" int func_001A3C70(UnkStruct_001A3C70 *self, int p0, EHUDAlign p1, int p2)
{
    int i;
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(self, 1, 3, 1, p0, p1, p2);
    AdjustScalingForSplitScreen__15CB3HUDComponentFv(self);
    void *scene = (char *)&self->field_4[self->field_1C] + 0x14;
    int layer = self->field_10;
    UnkStruct_D_0066A4C0 * const mgr = &D_0066A4C0;
    self->field_2C = p0 < D_00645170.field_0 ? D_0055EF70 + p0 * 0x4590 + 0x1CB80 : 0;
    for (i = 0; i < 3; i++) {
        self->field_20[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, self->field_8);
    }
    const unsigned short *text;
    if (D_004E2918 > 1) text = func_00271A00(&D_0051BA44, 0x7D7);
    else text = func_00271A00(&D_0051BA44, 0x7D8);
    Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(self->field_20[2], CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 1.0f), CGtV2d(168.0f, 27.0f), mgr->field_10, 3);
    func_003824D0(self->field_20[1], CGtV2d(-18.0f, -8.100000381f), CGtV2d(1.0f, D_00665ED0.field_0->field_10), 27.0f,
                  Interpolate(mgr->field_60, mgr->field_30, 0.25f), mgr->field_30, text, 0x11, 1.25f, 3.402823466e+38f);
    self->field_30[0] = 0x30;
    self->field_30[1] = 0;
    self->field_40.Set(self->field_20[1]->field_0 - 6.0f, 0.0f + self->field_20[1]->field_4 + 27.0f * D_00665ED0.field_0->field_10);
    func_003824D0(self->field_20[0], self->field_40, CGtV2d(1.0f, D_00665ED0.field_0->field_10), 48.0f,
                  mgr->field_60, Interpolate(mgr->field_60, mgr->field_30, 0.75f), self->field_30, 0x31, 1.5f, 3.402823466e+38f);
    self->field_48 = 0;
    return 1;
}

