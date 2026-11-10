// NONMATCHING: ActualPrepare__15CB3HUDScoreListFv -- retail 220 / ours 220 instructions, 33 in changed runs
// psweep: scoped #pragma opt_lifetimes off [G] improves 36 -> 33
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// ActualPrepare__15CB3HUDScoreListFv -- hand-matched (a153).
#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_lifetimes off

enum EHUDAlign {};
class CGt2dFrame;
struct UnkStruct_003CB090_pad {
    unsigned char pad_0[0x10];
    UnkStruct_003CB090_pad() {}
    ~UnkStruct_003CB090_pad() {}
};
struct UnkStruct_003CB090_car { unsigned char pad_0[0x1160]; unsigned char field_1160; };
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12AD28];
    UnkStruct_003CB090_car * field_12AD28[10];
};
struct UnkStruct_003CB090_e1 { unsigned char pad_0[0x70]; };
struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x10];
    GtMathPs2::CGtV4d field_10;
    GtMathPs2::CGtV4d field_20;
    GtMathPs2::CGtV4d field_30;
    GtMathPs2::CGtV4d field_40;
    GtMathPs2::CGtV4d field_50;
};
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064E510 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_003CB090 {
    unsigned char pad_0[0x4];
    UnkStruct_003CB090_e1 * field_4;
    int field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    int field_20[12];
    int field_50[5];
    int field_64[0x7F];
    unsigned char field_260;
    unsigned char pad_261[0x3];
    EHUDAlign field_264;
    int field_268;
    int field_26C;
    int field_270;
};
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_0064E510 D_0064E510;

extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, GtMathPs2::CGtV4d, unsigned int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003824D0(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, float, GtMathPs2::CGtV4d, GtMathPs2::CGtV4d, void *, int, float, float);
extern "C" void func_003CAAB0(void *);

extern "C" void ActualPrepare__15CB3HUDScoreListFv(UnkStruct_003CB090 * self)
{
    int s3;
    void * scene;
    int k;
    int * slot;
    int * slot2;
    int text;
    s3 = 1;
    int i;
    int j;
    self->field_260 = 1;
    scene = (char *)&self->field_4[self->field_1C] + 0x14;
    for (i = 0; i < D_0064D37C.field_0; i++) {
        if (D_00522660.field_12AD28[i]->field_1160 == 0) {
            s3 += 2;
        }
    }
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(self, 2, s3, 1, 0, self->field_264, self->field_268);
    UnkStruct_D_0066A4C0 * const mgr = &D_0066A4C0;
    self->field_26C = self->field_10 + 1;
    self->field_270 = self->field_10;
    for (j = 0; j < s3; j++) {
        self->field_20[j] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_26C, (CGt2dFrame *)self->field_8);
    }
    for (; j < 12; j++) {
        self->field_20[j] = 0;
    }
    for (i = 0; i < 5; i++) {
        self->field_50[i] = 0;
    }
    k = 0;
    for (j = 0; j < D_0064D37C.field_0; j++) {
        if (D_00522660.field_12AD28[j]->field_1160 == 0) {
            slot = &self->field_64[k];
            *slot = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_270, (CGt2dFrame *)self->field_8);
            Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi((void *)*slot, GtMathPs2::CGtV2d(-30.0f, 0.0f + 120.0f + 27.0f * (float)k), GtMathPs2::CGtV2d(0.0f, 0.0f), GtMathPs2::CGtV2d(210.0f, 24.0f), mgr->field_10, 2);
            k++;
        }
    }
    slot2 = &self->field_64[j];
    *slot2 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_270, (CGt2dFrame *)self->field_8);
    Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi((void *)*slot2, GtMathPs2::CGtV2d(-30.0f, 0.0f), GtMathPs2::CGtV2d(0.0f, 0.0f), GtMathPs2::CGtV2d(210.0f, 27.0f), mgr->field_10, 2);
    GtMathPs2::CGtV4d cb;
    GtMathPs2::CGtV4d ca;
    UnkStruct_003CB090_pad padslot; // [G] N140 frame pad
    int msg;
    if (D_0064E510.field_0 != 0) {
        cb = mgr->field_30;
        ca = mgr->field_50;
        msg = 0x8B1;
    } else {
        cb = mgr->field_40;
        ca = GtMathPs2::CGtV4d(0.2f, 0.4f, 0.6f, 1.0f);
        msg = 0x8B0;
    }
    text = func_00271A00(&D_0051BA44, msg);
    func_003824D0((void *)(self->field_20[s3 - 1]), GtMathPs2::CGtV2d(0.0f, 0.0f), GtMathPs2::CGtV2d(0.0f, 0.0f), 40.0f, cb, ca, (void *)(text), 0x21, 1.0f, 3.4028235e+38f);
    func_003CAAB0(self);
}




#pragma pop
