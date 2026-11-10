// CB3HUDTimer::Prepare(int,EHUDAlign,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HUDTimer.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a131: extern C + extra int p3; short layer + int i decl order; sibling B3HUDTakedowns).

#include "b3/GtMathPs2.h"

enum EHUDAlign {};
class CGt2dFrame;

struct UnkStruct_003C26F0_o { float field_0; unsigned char pad_4[0x4]; float field_8; };
struct UnkStruct_003C26F0_e0 { unsigned char pad_0[0x27D0]; };
struct UnkStruct_D_00522660 { UnkStruct_003C26F0_e0 field_0[1]; };
struct UnkStruct_003C26F0_e1 { unsigned char pad_0[0x70]; };
struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x10];
    GtMathPs2::CGtV4d field_10;
    unsigned char pad_20[0x20];
    GtMathPs2::CGtV4d field_40;
};
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_003C26F0 {
    unsigned char pad_0[0x4];
    UnkStruct_003C26F0_e1 * field_4;
    int field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    int field_20;
    UnkStruct_003C26F0_o * field_24;
    int field_28;
    void * field_2C;
    unsigned char pad_30[0x4];
    unsigned char field_34;
};
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern float D_004E0C14;

extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, GtMathPs2::CGtV4d, unsigned int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003824D0(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, float, GtMathPs2::CGtV4d, GtMathPs2::CGtV4d, void *, int, float, float);
extern "C" void PrepareTimerObject__11CB3HUDTimerFv(void *);

// 0x003C26F0
extern "C" int Prepare__11CB3HUDTimerFi9EHUDAligni(UnkStruct_003C26F0 * self, int p0, EHUDAlign p1, int p2, int p3)
{
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(self, 1, 3, 1, p0, p1, p2);
    UnkStruct_D_0066A4C0 * const mgr = &D_0066A4C0;
    void * scene = (char *)&self->field_4[self->field_1C] + 0x14;
    short layer = self->field_10;
    int i;
    self->field_2C = ((char *)&D_00522660.field_0[p0] + 0x12BE10);
    self->field_34 = p3;
    for (i = 0; i < 3; i++) {
        (&self->field_20)[i] = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, (CGt2dFrame *)self->field_8);
    }
    int text = func_00271A00(&D_0051BA44, 0x7F2);
    func_003824D0((void *)((int)self->field_24), GtMathPs2::CGtV2d(0.0f, 14.0f), GtMathPs2::CGtV2d(1.0f, 0.5f), 27.0f, mgr->field_40, mgr->field_40, (void *)(text), 9, 1.0f, D_004E0C14);
    Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi((void *)self->field_28, GtMathPs2::CGtV2d(30.0f + (self->field_24->field_0 + self->field_24->field_8), 14.0f), GtMathPs2::CGtV2d(1.0f, 0.5f), GtMathPs2::CGtV2d(174.0f, 27.0f), mgr->field_10, 1);
    PrepareTimerObject__11CB3HUDTimerFv(self);
    return 1;
}
