// Hand-written; the lifter refused it (a126: HUD Prepare on B3HUDTakedowns model, field_20[4] array loop, int i declared before layer).

#include "b3/GtMathPs2.h"
#include "b3/classes/UnkStruct_D_0051BA88.h"
enum EHUDAlign {};
class CGt2dFrame;
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
struct UnkStruct_D_00522660 { unsigned char pad_0[0x27D0]; };
struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x10];
    CGtV4d field_10;
    unsigned char pad_20[0x20];
    CGtV4d field_40;
};
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_00335450_e1 { unsigned char pad_0[0x70]; };
struct UnkStruct_00335450_pos { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00335450 {
    unsigned char pad_0[0x4];
    UnkStruct_00335450_e1 *field_4;
    int field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    int field_20[4];
    int field_30;
    unsigned char pad_34[4];
    int field_38;
    int field_3C;
    unsigned char pad_40[8];
    short field_48;
    short field_4A;
    short field_4C;
    unsigned char pad_4E[2];
    short field_50;
    unsigned char field_52;
};
extern UnkStruct_D_00522660 D_00522660[];
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);
extern "C" void AdjustScalingForSplitScreen__15CB3HUDComponentFv(void *);
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, unsigned int);
extern "C" void SetPos__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const CGtV2d &, const CGtV2d &);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003824D0(void *, const CGtV2d &, const CGtV2d &, float, CGtV4d, CGtV4d, void *, int, float, float);
extern "C" void func_003350F0(void *);

// 0x00335450
extern "C" int func_00335450(UnkStruct_00335450 *self, int p0, EHUDAlign p1, int p2, bool p3)
{
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(self, 1, 4, 1, p0, p1, p2);
    AdjustScalingForSplitScreen__15CB3HUDComponentFv(self);
    UnkStruct_D_0066A4C0 * const mgr = &D_0066A4C0;
    void * scene = (char *)&self->field_4[self->field_1C] + 0x14;
    int i;
    int layer = self->field_10;
    self->field_3C = 0;
    self->field_30 = (int)((char *)&D_00522660[p0] + 0x12BE10);
    self->field_52 = p3;
    for (i = 3; i >= 0; i--)
        self->field_20[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, (CGt2dFrame *)self->field_8);
    int r = D_0051BA88.field_0->vfunc_20();
    self->field_48 = 0x2F;
    self->field_4A = r + 0x30;
    self->field_4C = 0;
    self->field_50 = 0;
    int text = func_00271A00(&D_0051BA44, 0x7E8);
    func_003824D0((void *)(self->field_20[1]), CGtV2d(0.0f, 14.0f), CGtV2d(1.0f, 0.5f), 27.0f, mgr->field_40, mgr->field_40, (void *)(text), 9, 1.0f, 3.402823466e+38f);
    func_003350F0(self);
    if (self->field_52 != 0)
        SetPos__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d((void *)self->field_20[1], CGtV2d(((UnkStruct_00335450_pos *)self->field_20[3])->field_0 - 2.0f, 14.0f), CGtV2d(1.0f, 0.5f));
    float w;
    if (self->field_52 != 0)
        w = 148.0f;
    else
        w = 125.0f;
    Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi((void *)self->field_20[0], CGtV2d(30.0f, 14.0f), CGtV2d(1.0f, 0.5f), CGtV2d(w, 27.0f), mgr->field_10, 1);
    return 1;
}
