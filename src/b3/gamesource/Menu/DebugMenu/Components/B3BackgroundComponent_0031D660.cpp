// DRAFT -- NOT MATCHING, NOT WIRED IN (retail's asm is still linked: game/unit_0031CF30.s). 175/175 instructions, 19 in
// changed runs, mostly relocation addends: the page manager pointer and the layer have each other's saved registers
// ($s4/$s0) (docs/known.md N115).
#include "b3/gamesource/Menu/DebugMenu/Components/B3BackgroundComponent.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern CB3MenuPageManager D_01E90240;  // unnamed global (the page manager instance)
extern CGtTexture *D_01EA46B0[0x38];   // unnamed texture table (B3HeadingComponent_00319E80.cpp)

// The UV sets B3BackgroundComponent_004D7EC0.cpp builds (16-byte CGtV4d values; their two halves are passed as the
// top-left / bottom-right CGtV2d [C: every caller passes &x and &x + 8, and asm references both halves' labels]).
extern CGtV4d D_01EA3190;
extern CGtV4d D_01EA31A0;
extern CGtV4d D_01EA31B0;
extern const CGtV4d D_004C5210;
extern const CGtV4d D_004C5220;
// [G] how the source named the halves: a 16-byte UV type with two CGtV2d views is the likeliest (the objects stay
// 16-aligned, which retail's layout needs); expressed here as views of the CGtV4d.
inline const CGtV2d &UnkInline_UV0(const CGtV4d &uv) { return *(const CGtV2d *)&uv.f[0]; }
inline const CGtV2d &UnkInline_UV1(const CGtV4d &uv) { return *(const CGtV2d *)&uv.f[2]; }

// CGt2dObjectImage::Prepare, called by its link name with retail's 8th argument (N68; as B3HeadingComponent_00319E80.cpp).
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
#define CGt2dObjectImage_Prepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d

// 0x003A6E80, unnamed, not yet decompiled: prepares a 2D object of another kind from pos/anchor/size, two floats
// (stored at +0x30/+0x34: [L] the alphas of its two ends -- PrepareBorders passes 1/alpha and alpha/1), a UV pair
// and a mode (0 or 1 selects the render function) [C by its stores and branches]. [G] parameter order: the floats
// before the UVs is the order whose evaluation schedules retail's call (f13 before the jal, t2 in its delay slot).
extern "C" void func_003A6E80(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size,
                              float a0, float a1, const CGtV2d &uv0, const CGtV2d &uv1, int mode);

// 0x0031D660
void CB3BackgroundComponent::PrepareBorders(float alpha)
{
    // Declared layer, scene, mgr, root: the closest order (130+ orders and forms tried, N115).
    int layer = field_8 + 1;
    CGt2dScene *scene = &D_01E90240.field_1A0;
    CB3MenuPageManager *mgr = &D_01E90240;
    CGt2dFrame *root = scene->field_14;
    if (field_24[0] == 0) {
        for (int i = 0; i < 4; i++)
            field_24[i] = scene->ConstructObject(layer, root);
    }
    if (alpha < 0.0f) {
        alpha = 0.0f;
    } else {
        // N114: a default-constructed copy assigned whole, then SetA -- retail's lqc2 / vmulx.w / sqc2.
        CGtV4d colour;
        colour = mgr->field_110;
        colour.SetA(alpha);
        if (field_24[4] == 0)
            field_24[4] = scene->ConstructObject(layer, root);
        CGt2dObjectImage_Prepare(field_24[4], CGtV2d(0.0f, 96.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 288.0f), colour,
                                 D_01EA46B0[1], UnkInline_UV0(D_004C5220), UnkInline_UV1(D_004C5220), 0);
    }
    CGt2dObjectImage_Prepare(field_24[0], CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 64.0f), mgr->field_110,
                             D_01EA46B0[1], UnkInline_UV0(D_01EA3190), UnkInline_UV1(D_01EA3190), 0);
    CGt2dObjectImage_Prepare(field_24[3], CGtV2d(0.0f, 416.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 64.0f), mgr->field_110,
                             D_01EA46B0[1], UnkInline_UV0(D_01EA31A0), UnkInline_UV1(D_01EA31A0), 0);
    func_003A6E80(field_24[1], CGtV2d(0.0f, 64.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 32.0f),
                  1.0f, alpha, UnkInline_UV0(D_004C5210), UnkInline_UV1(D_004C5210), 0);
    func_003A6E80(field_24[2], CGtV2d(0.0f, 384.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 32.0f),
                  alpha, 1.0f, UnkInline_UV0(D_01EA31B0), UnkInline_UV1(D_01EA31B0), 0);
}
