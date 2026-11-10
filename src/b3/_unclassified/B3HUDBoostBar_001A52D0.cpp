// CB3HUDBoostBar::Prepare(int,EHUDAlign,int,bool,const CB3HUDHeading*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDBoostBar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near31: colour by value into the first-Prepare inline (drops the N140 pad), float[2] frame copies, byte-offset row address, bool return).

// CB3HUDBoostBar::Prepare(int, EHUDAlign, int, bool, const CB3HUDHeading*) -- hand-matched (near31): the white colour passed
// by value into the first-Prepare inline (retail's copy slot), the frame copies as float[2] structs, the row address as a byte
// offset, and a bool return (retail's li v0,1 for the last store [L], v275 rule).
#include "b3/GtMathPs2.h"

enum EHUDAlign {};
class CGt2dFrame;
class CB3HUDHeading;
struct UnkStruct_001A52D0_msg;
struct UnkStruct_001A52D0_obj;
struct UnkStruct_001A52D0_row;
struct UnkStruct_001A52D0_frm;
struct UnkStruct_001A52D0_car;

struct UnkStruct_001A52D0_row {
    unsigned char pad_0[0x28];
    void * field_28;
    unsigned char pad_2C[0x44];
};

struct UnkStruct_001A52D0_frm {
    float field_0[2];
};
struct UnkStruct_001A52D0_f2 { float field_0; float field_4; };

struct UnkStruct_001A52D0_car {
    unsigned char pad_0[0xFC];
    int field_FC;
};

struct UnkStruct_001A52D0_obj {
    float field_0;
    float field_4;
    unsigned char pad_8[0x4];
    float field_C;
    unsigned char pad_10[0x10];
    void * field_20;
};

struct UnkStruct_001A52D0_msg {
    void * field_0;
    int field_4;
    float field_8;
    float field_C;
    float field_10;
    void * field_14;
    signed char field_18;
    unsigned char pad_19[0x3];
    float field_1C;
    int field_20;
    int field_24;
};

struct UnkStruct_D_00522660 { unsigned char pad_0[0x27D0]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_V2_16 { GtMathPs2::CGtV2d field_0; unsigned char pad_8[0x8]; };

extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_V2_16 D_004B77F8;

extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);
extern "C" void AdjustScalingForSplitScreen__15CB3HUDComponentFv(void *);
extern "C" void func_0019F350(void *);
extern "C" int func_00271A00(void *, int);
extern "C" void * func_001D5CE0(void *, void *, void *, GtMathPs2::CGtV4d);
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const GtMathPs2::CGtV2d &, const GtMathPs2::CGtV2d &, GtMathPs2::CGtV4d, const void *, unsigned int, unsigned int);
extern "C" void Prepare__Q214CB3HUDBoostBar19CBoostBarObjectDataFv(void *);
extern "C" void _Render__17C2dObjectBoostBarFRCQ211CGt2dObject16CGt2dObjectSpacePCv(void *, void *);

class CB3HUDBoostBar {
public:
// 0x001A52D0
    void Prepare(int p0, EHUDAlign p1, int p2, bool p3, const CB3HUDHeading * p4);

    unsigned char pad_0[0x4];
    UnkStruct_001A52D0_row * field_4;
    UnkStruct_001A52D0_frm * field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    unsigned char field_20[0x504];
    float field_524;
    unsigned char pad_528[0x13];
    unsigned char field_53B;
    unsigned char pad_53C[0x14];
    int field_550;
    int field_554;
    UnkStruct_001A52D0_frm field_558;
    UnkStruct_001A52D0_obj * field_560;
    unsigned char field_564;
    unsigned char field_565;
    unsigned char field_566;
    unsigned char field_567;
    unsigned char field_568;
    unsigned char field_569;
    unsigned char field_56A;
    unsigned char field_56B;
    float field_56C;
    UnkStruct_001A52D0_msg field_570[7];
    void * field_688;
    UnkStruct_001A52D0_car * field_68C;
    void * field_690;
    float field_694;
    int field_698;
    void * field_69C;
    UnkStruct_001A52D0_frm field_6A0;
    unsigned char field_6A8;
};

static inline void func_001A52D0_inl2(UnkStruct_001A52D0_obj * o, GtMathPs2::CGtV4d c)
{
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(o, GtMathPs2::CGtV2d(0.0f, 0.0f) - D_004B77F8.field_0 * GtMathPs2::CGtV2d(0.0f, 1.0f), D_004B77F8.field_0, c, (const void *)&_Render__17C2dObjectBoostBarFRCQ211CGt2dObject16CGt2dObjectSpacePCv, 64, 24);
}

extern "C" bool Prepare__14CB3HUDBoostBarFi9EHUDAlignibPC13CB3HUDHeading(CB3HUDBoostBar * self, int p0, EHUDAlign p1, int p2, bool p3, unsigned char p4, void * p5)
{
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(self, 2, 9, 1, p0, p1, p2);
    AdjustScalingForSplitScreen__15CB3HUDComponentFv(self);
    func_0019F350(self);
    UnkStruct_001A52D0_row * r = &self->field_4[self->field_1C];
    self->field_68C = (UnkStruct_001A52D0_car *)((char *)&D_00522660 + p0 * 0x27D0 + 0x12BE10);
    self->field_56A = p3;
    self->field_698 = self->field_10 + 1;
    self->field_560 = (UnkStruct_001A52D0_obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame((char *)r + 0x14, self->field_698, self->field_8);
    UnkStruct_001A52D0_obj * o = self->field_560;
    func_001A52D0_inl2(o, GtMathPs2::CGtV4d(1.0f, 1.0f, 1.0f, 1.0f));
    o->field_20 = self->field_20;
    Prepare__Q214CB3HUDBoostBar19CBoostBarObjectDataFv(self->field_20);
    self->field_524 = 0.25f * (1.0f + (float)self->field_68C->field_FC);
    self->field_53B = p4;
    self->field_554 = 0x2B9D6F8;
    self->field_550 = 0xFD462907;
    self->field_558 = *(UnkStruct_001A52D0_frm *)self->field_560;
    self->field_564 = 0;
    self->field_565 = 0;
    self->field_566 = 0;
    self->field_567 = 0;
    self->field_568 = 0;
    self->field_569 = 0;
    self->field_56B = 0;
    self->field_56C = 0.0f + self->field_560->field_4 + 0.5f * self->field_560->field_C;
    int r0 = func_00271A00(&D_0051BA44, 0x851);
    self->field_570[0].field_0 = 0; self->field_570[0].field_4 = r0; self->field_570[0].field_14 = 0; self->field_570[0].field_18 = -1; self->field_570[0].field_1C = 1.0f; self->field_570[0].field_20 = 0; self->field_570[0].field_24 = 0;
    int r1 = func_00271A00(&D_0051BA44, 0x852);
    self->field_570[1].field_0 = 0; self->field_570[1].field_4 = r1; self->field_570[1].field_14 = 0; self->field_570[1].field_18 = -1; self->field_570[1].field_1C = 1.0f; self->field_570[1].field_20 = 0; self->field_570[1].field_24 = 0;
    int r2 = func_00271A00(&D_0051BA44, 0x853);
    self->field_570[2].field_0 = 0; self->field_570[2].field_4 = r2; self->field_570[2].field_14 = 0; self->field_570[2].field_18 = -1; self->field_570[2].field_1C = 1.0f; self->field_570[2].field_20 = 0; self->field_570[2].field_24 = 0;
    int r3 = func_00271A00(&D_0051BA44, 0x850);
    self->field_570[3].field_0 = 0; self->field_570[3].field_4 = r3; self->field_570[3].field_14 = 0; self->field_570[3].field_18 = -1; self->field_570[3].field_1C = 1.0f; self->field_570[3].field_20 = 0; self->field_570[3].field_24 = 0;
    int r4 = func_00271A00(&D_0051BA44, 0x854);
    self->field_570[4].field_0 = 0; self->field_570[4].field_4 = r4; self->field_570[4].field_14 = 0; self->field_570[4].field_18 = -1; self->field_570[4].field_1C = 1.0f; self->field_570[4].field_20 = 0; self->field_570[4].field_24 = 0;
    int r5 = func_00271A00(&D_0051BA44, 0x855);
    self->field_570[5].field_0 = 0; self->field_570[5].field_4 = r5; self->field_570[5].field_14 = 0; self->field_570[5].field_18 = -1; self->field_570[5].field_1C = 1.0f; self->field_570[5].field_20 = 0; self->field_570[5].field_24 = 0;
    int r6 = func_00271A00(&D_0051BA44, 0x856);
    self->field_570[6].field_0 = 0; self->field_570[6].field_4 = r6; self->field_570[6].field_14 = 0; self->field_570[6].field_18 = -1; self->field_570[6].field_1C = 1.0f; self->field_570[6].field_20 = 0; self->field_570[6].field_24 = 0;
    self->field_688 = 0;
    self->field_690 = p5;
    self->field_6A0 = *self->field_8;
    self->field_69C = func_001D5CE0(((UnkStruct_001A52D0_row *)((char *)self->field_4 + self->field_1C * 0x70))->field_28, &self->field_6A0, (char *)self->field_8 + 8, GtMathPs2::CGtV4d(1.0f, 1.0f, 1.0f, 1.0f));
    self->field_694 = -1.0f;
    self->field_6A8 = 1;
    return true;
}
