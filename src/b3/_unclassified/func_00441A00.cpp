// Hand-written; the lifter refused it (v291: hand-written component Prepare (func_003D2AA0 sibling shape), compiler-chosen SetA stand-in [L] N185).

// func_00441A00 -- hand-written (v291; the lifter refused it: vmove.xyzw). A menu component's Prepare: base Prepare, a
// frame + six 2D objects (two gradients, a panel, a text object, two mirrored images), sibling shape of
// func_003D2AA0 / CB3HeadingComponent::Prepare. Unnamed in every table: placeholder with C linkage; Area unknown.
// Every field type is [G] (instruction widths). Prepare arguments as unnamed CGtV2d temporaries (slots in argument
// order); colours as two named CGtV4d locals, c0 reused for the images.
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern CB3MenuPageManager D_01E90240;  // unnamed global (the page manager instance)

struct UnkStruct_00441A00 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject * field_C;
    void * field_10;
    void * field_14;
    void * field_18;
    void * field_1C;
    void * field_20;
    CGt2dFrame * field_24;
    int field_28;
    float field_2C;
    unsigned char field_30;
    unsigned char field_31;
};

struct UnkStruct_D_01EA4718 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing (N51)
};
struct UnkStruct_D_01EA4790 {
    CGtV2d uv;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing (N51)
};
extern UnkStruct_D_01EA4718 D_01EA4718;
extern UnkStruct_D_01EA4790 D_01EA4790;
extern UnkStruct_D_01EA4790 D_01EA4798;
extern const CGtV2d D_004D2308;
extern char D_0051BA44[];

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" const unsigned short * func_00271A00(void *, int);  // [L] DNAT: CB3Strings::GetString(int) (research/proto/new_names.csv, medium)
extern "C" void Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, CGtV4d, float);
extern "C" void Prepare__16CB3Panel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dbb(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, bool, bool);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, void *, const CGtV2d &, const CGtV2d &, unsigned int);  // plus retail's stack argument (N68)
extern "C" void func_003824D0(CGt2dObject *obj, const CGtV2d &a, const CGtV2d &b, float c, CGtV4d d, CGtV4d e, const unsigned short *text, int f, float g, float h);

// [L] N185: CGtV4d::SetA(float) on a compiler-chosen scalar register stand-in (header's form pins $vf2)
static inline void func_00441A00_inl1(CGtV4d &v, float a) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(a)); asm("vmulx.w %0, $vf0, %1x" : "+j"(v.mData) : "j"(s)); }

// 0x00441A00
extern "C" bool func_00441A00(UnkStruct_00441A00 * self, int p1)
{
    CB3MenuPageManager * const mgr = &D_01E90240;
    CGt2dScene * const scene = &D_01E90240.field_1A0;
    int layer = self->field_8;
    int layer1 = layer + 1;
    CGtV4d c0;
    CGtV4d c1;
    Prepare__20CB3MenuComponentBaseFv(self);
    self->field_28 = 0;
    self->field_2C = 0.4f;
    self->field_31 = 3;
    self->field_30 = 0;
    self->field_24 = scene->field_14->ConstructChild();
    self->field_18 = scene->ConstructObject(layer, self->field_24);
    self->field_1C = scene->ConstructObject(layer, self->field_24);
    self->field_20 = scene->ConstructObject(layer, self->field_24);
    Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(self->field_18, CGtV2d(0.0f, 388.0f), CGtV2d(0.0f, 1.0f), CGtV2d(640.0f, 2.0f), mgr->field_0[0], mgr->field_100, 0.0f);
    Prepare__19CB32dObjectGradientFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV4df(self->field_1C, CGtV2d(0.0f, 438.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 2.0f), mgr->field_0[0], mgr->field_100, 0.0f);
    Prepare__16CB3Panel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dbb(self->field_20, CGtV2d(0.0f, 438.0f), CGtV2d(0.0f, 1.0f), CGtV2d(640.0f, 50.0f), p1 == 1, false);
    self->field_10 = scene->ConstructObject(layer1, self->field_24);
    self->field_14 = scene->ConstructObject(layer1, self->field_24);
    self->field_C = scene->ConstructObject(layer1, self->field_24);
    c0 = mgr->field_40;
    func_00441A00_inl1(c0, 0.0f);
    c1 = mgr->field_50;
    func_00441A00_inl1(c1, 0.0f);
    const unsigned short * str = func_00271A00(D_0051BA44, 0xD6);
    func_003824D0(self->field_C, CGtV2d(320.0f, 413), D_004D2308, 22.0f, c0, c1, str, 0, 1.0f, 3.402823466e+38f);
    c0 = mgr->field_110;
    func_00441A00_inl1(c0, 0.0f);
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_10, CGtV2d(90.0f, 413), D_004D2308, CGtV2d(80.0f, 40.0f), c0, D_01EA4718.field_0, D_01EA4790.uv, D_01EA4798.uv, 0);
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_14, CGtV2d(550, 413), D_004D2308, CGtV2d(80.0f, 40.0f), c0, D_01EA4718.field_0, CGtV2d(D_01EA4798.uv.marValues[0], D_01EA4790.uv.marValues[1]), CGtV2d(D_01EA4790.uv.marValues[0], D_01EA4798.uv.marValues[1]), 0);
    return true;
}
