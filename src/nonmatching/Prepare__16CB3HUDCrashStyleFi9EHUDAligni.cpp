// NONMATCHING: Prepare__16CB3HUDCrashStyleFi9EHUDAligni -- retail 296 / ours 296 instructions, 13 in changed runs
// 13 off: text1 temp registers rotated (t=0.75 a1/obj a0/colour copy v1 in retail) + retail's li v0,1 sits before ld ra; logic, frame, s-registers exact; 15-pragma sweep, decl/statement permutations, bool/int return, goto done don't move them
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// CB3HUDCrashStyle::Prepare(int,EHUDAlign,int)
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/.
// Hand-written (ghvu16) from the Ghidra draft and retail; shapes from the proven HUD siblings (B3HUDEscapeDistance_003D8BC0:
// func_003824D0 / Prepare calls with CGtV2d temporaries, mgr = &D_0066A4C0; B3HUDImpactTime_003D6AB0: the find-by-name
// inline). Field names are placeholders and every type is [G] (instruction widths).
// [G] shape: the two text/image blocks in a static inline (their CGtV2d temporaries sit below the background call's, as
// in retail's frame); named CGtV4d colour locals (c1, i1, i2, c2: retail's 16-byte slot order); the find loops written
// out with function-level i/found pairs (declaration order picks retail's s1/s2); scene before layer (s3/s0).
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

enum EHUDAlign {};
class CGt2dFrame;
class CGtTexture;

struct UnkStruct_003A3880_o {
    CGtV2d field_0;
    CGtV2d field_8;
};
struct UnkStruct_003A3880_e1 { unsigned char pad_0[0x70]; };
struct UnkStruct_003A3880_car { unsigned char pad_0[0x19AC]; signed char field_19AC; };
struct UnkStruct_003A3880_rc { unsigned char pad_0[0xC8]; UnkStruct_003A3880_car *field_C8; };
struct UnkStruct_003A3880_e0 { unsigned char pad_0[0x8]; int field_8; unsigned char pad_C[0x4]; };
struct UnkStruct_003A3880_2 { unsigned char pad_0[0x8]; int field_8; UnkStruct_003A3880_e0 *field_C; };
struct UnkStruct_D_00518688 { UnkStruct_003A3880_2 *field_0; unsigned char pad_4[0xC]; };
// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113, B3SunRendererPS2_0024D390).
struct UnkStruct_003A3880_blk { unsigned char pad_0[0x18]; char field_18[8]; };
struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x10];
    CGtV4d field_10;
    unsigned char pad_20[0x10];
    CGtV4d field_30;
    unsigned char pad_40[0x20];
    CGtV4d field_60;
};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0064CE40 { unsigned char pad_0[0x10]; };

class CB3HUDCrashStyle {
public:
    int Prepare(int p0, EHUDAlign p1, int p2);

    unsigned char pad_0[0x4];
    UnkStruct_003A3880_e1 *field_4;
    int field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    UnkStruct_003A3880_o *field_20;
    UnkStruct_003A3880_o *field_24;
    UnkStruct_003A3880_o *field_28;
    UnkStruct_003A3880_o *field_2C;
    UnkStruct_003A3880_rc *field_30;
    int field_34;
    int field_38;
    unsigned short field_3C[4];
    int field_44;
    int field_48;
    unsigned char pad_4C[0x4];
    CGtV2d field_50;
    CGtV2d field_58;
};

extern UnkStruct_D_00518688 D_00518688;
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_0064CE40 D_0064CE40;
extern const CGtV4d D_004C9DB0;
extern char D_004C9DC0[];
extern char D_004C9DD0[];

extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);  // CB3HUDComponent::Prepare(int,int,int,int,EHUDAlign,int)
extern "C" void AdjustScalingForSplitScreen__15CB3HUDComponentFv(void *);  // CB3HUDComponent::AdjustScalingForSplitScreen()
extern "C" int strcasecmp(const char *, const void *);
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" const unsigned short *func_00271A00(void *, int);
extern "C" void func_003824D0(void *, const CGtV2d &, const CGtV2d &, float, CGtV4d, CGtV4d, const unsigned short *, int, float, float);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, void *, const CGtV2d &, const CGtV2d &, unsigned int);  // CGt2dObjectImage::Prepare(...), plus retail's stack argument (N68)
extern "C" int func_003CC910(void *, int);
extern "C" void PrintInt__10CGtUnicodeFPUsii(void *, int, int, int);
extern "C" void Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, unsigned int);  // CB3HUDBackground2dObject::Prepare(...)

static inline int func_003A3880_inl1(const char *name)  // [G] placeholder: an inlined find-by-name (as B3HUDImpactTime_003D6AB0)
{
    UnkStruct_003A3880_2 * t0 = D_00518688.field_0;
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_003A3880_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return t2;
        }
    }
    return 0;
}

static inline void func_003A3880_inl2(CB3HUDCrashStyle *self)  // [G] placeholder
{
    UnkStruct_D_0066A4C0 * const m1 = &D_0066A4C0;
    float x = self->field_28->field_0.marValues[0] + self->field_28->field_8.marValues[0];
    CGtV4d c1;
    c1 = m1->field_60;
    float t1 = 0.75f;
    CGtV4d i1 = GtMathPs2::Interpolate(m1->field_60, m1->field_30, t1);
    const unsigned short *t = func_00271A00(&D_0051BA44, 0x8B9);
    func_003824D0(self->field_20, CGtV2d(5.0f + x, -10.0f), CGtV2d(0.0f, 0.6f), 27.0f, c1, i1, t, 1, 1.25f, 3.402823466e+38f);
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
        self->field_28, CGtV2d(-8.0f, -10.0f), CGtV2d(0.0f, 0.6f), CGtV2d(65.0f, 65.0f), D_004C9DB0, (void *)self->field_38, CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 1.0f), 0);
    UnkStruct_D_0066A4C0 * const m2 = &D_0066A4C0;
    x = self->field_20->field_0.marValues[0] + self->field_20->field_8.marValues[0];
    PrintInt__10CGtUnicodeFPUsii(self->field_3C, func_003CC910(&D_0064CE40, self->field_30->field_C8->field_19AC), 1, 0);
    float t2 = 0.25f;
    CGtV4d i2 = GtMathPs2::Interpolate(m2->field_60, m2->field_30, t2);
    CGtV4d c2;
    c2 = m2->field_30;
    func_003824D0(self->field_24, CGtV2d(5.0f + x, -10.0f), CGtV2d(0.0f, 0.6f), 45.0f, i2,
                  c2, (const unsigned short *)self->field_3C, 0x21, 1.25f, 3.402823466e+38f);
    self->field_50 = self->field_24->field_8;
    self->field_58 = self->field_24->field_0 + self->field_50 * 0.5f;
}

// 0x003A3880
int CB3HUDCrashStyle::Prepare(int p0, EHUDAlign p1, int p2)
{
    int layer1;
    void *scene;
    int found2;
    int found;
    int i2;
    int i;
    int layer;
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(this, 2, 4, 0, p0, p1, p2);
    AdjustScalingForSplitScreen__15CB3HUDComponentFv(this);
    scene = (char *)&field_4[field_1C] + 0x14;
    layer = field_10;
    field_30 = (UnkStruct_003A3880_rc *)((char *)&D_00522660 + p0 * 0x27D0 + 0x12BE10);
    UnkStruct_D_0066A4C0 * const mgr = &D_0066A4C0;
    field_48 = p0;
    layer1 = layer + 1;
    {
        UnkStruct_003A3880_2 * t0 = D_00518688.field_0;
        for (i = 0; i < t0->field_8; i++) {
            found = t0->field_C[i].field_8;
            if (strcasecmp(((UnkStruct_003A3880_blk *)(found + 0x90))->field_18, D_004C9DC0) == 0) goto f1;
        }
        found = 0;
    f1:
        field_34 = found;
    }
    {
        UnkStruct_003A3880_2 * t0 = D_00518688.field_0;
        for (i2 = 0; i2 < t0->field_8; i2++) {
            found2 = t0->field_C[i2].field_8;
            if (strcasecmp(((UnkStruct_003A3880_blk *)(found2 + 0x90))->field_18, D_004C9DD0) == 0) goto f2;
        }
        found2 = 0;
    f2:
        field_38 = found2;
    }
    field_44 = 0;
    field_20 = (UnkStruct_003A3880_o *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, (CGt2dFrame *)field_8);
    field_24 = (UnkStruct_003A3880_o *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer1, (CGt2dFrame *)field_8);
    field_2C = (UnkStruct_003A3880_o *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, (CGt2dFrame *)field_8);
    field_28 = (UnkStruct_003A3880_o *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer1, (CGt2dFrame *)field_8);
    func_003A3880_inl2(this);
    Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(
        field_2C, CGtV2d(-30.0f, -10.0f), CGtV2d(0.0f, 0.6f), CGtV2d(30.0f + (field_24->field_0.marValues[0] + field_24->field_8.marValues[0]), 27.0f), mgr->field_10, 2);
    return 1;
}

