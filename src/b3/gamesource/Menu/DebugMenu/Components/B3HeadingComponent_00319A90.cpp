#include "b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

extern CB3MenuPageManager D_01E90240;  // unnamed global (the page manager instance)

// [L] a field within gGraphicsManager, same reading and N51 padding as B3HSelectComponent_0031CCD0.cpp.
struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;

// [L] a byte flag (lbu, tested for zero); type and owner unknown. Padded for N51.
struct UnkStruct_D_01E91C3D {
    bool value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E91C3D D_01E91C3D;

// Unknown object passed to func_00285190 (also to func_00285560 by Prepare(EHeadingType)). Padded for N51.
struct UnkStruct_D_01E7A800 {
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E7A800 D_01E7A800;

// Both callees are unnamed in retail and in every table in research/, so they keep their placeholder
// names, with C linkage so the symbol is exactly func_XXXXXXXX (no alias needed). func_003824D0 is a
// CGt2dObject-derived text object's Prepare (it calls CGt2dObject::Prepare with a render callback).
// Its parameter list is reconstructed only as far as the call's register layout shows (EABI: integer
// and float arguments are allocated independently): a0 object, a1/a2 two CGtV2d by reference,
// a3/t0 two 16-byte values passed by address (CGtV4d by value, same convention as Target #28's
// CGt2dObjectItalicText::Prepare), t1 the string, t2 an int (0x12 here), f12-f14 three floats. [L]
extern "C" void func_003824D0(CGt2dObject *obj, const GtMathPs2::CGtV2d &a, const GtMathPs2::CGtV2d &b,
                              float c, GtMathPs2::CGtV4d d, GtMathPs2::CGtV4d e, const unsigned short *text,
                              int f, float g, float h);
extern "C" void func_00285190(UnkStruct_D_01E7A800 *p);

// 0x00319A90 (Target #31). Three source shapes matter here (N63), each isolated by single-change variants:
// - the scene is taken as a member address (&D_01E90240.field_1A0). Through the bare D_01E903E0 global, -O4
//   constant-propagates the address and rebuilds it with lui per use instead of keeping it in $s4;
// - mgr is a local declared after the frame setup (not at the top: that gives it its own $s-register for
//   the whole function instead of reusing root's $s2);
// - the fit test multiplies by `scale` (still the constant 42 there), not a literal 42.0f: the literal
//   form swaps mul.s's operands.
bool CB3HeadingComponent::Prepare(const unsigned short *text, EHeadingType type)
{
    Prepare(type);
    CGt2dScene *scene = &D_01E90240.field_1A0;
    CGt2dFrame *root = scene->field_14;
    int layer1 = field_8 + 1;
    field_18 = root->ConstructChild();
    field_18->field_0.SetIdentity();
    field_18->field_0.field_0 = GtMathPs2::CGtV2d(610, 0);
    field_18->field_0.field_8 = GtMathPs2::CGtV2d(640.0f, 480.0f);
    scene->field_2c[layer1].field_c = field_18;
    field_C = scene->ConstructObject(layer1, root);

    CB3MenuPageManager *mgr = &D_01E90240;
    float scale = 42.0f;
    float width = D_00665ED0.pFont->GetStringWidth(text);
    // Retail's two constants are 1 ULP above 421.4f/437.4f (0x43D2B334/0x43DAB334): exactly what folding
    // 597.4f - 176.0f / 597.4f - 160.0f in single precision gives, so they're written that way.
    float avail;
    if (field_26 < 3)
        avail = 597.4f - 176.0f;
    else if (field_14 == 0)
        avail = 597.4f - 160.0f;
    else
        avail = 597.4f - (field_14->mObjectSpace.mTopLeftPos.marValues[0] + field_14->mObjectSpace.mSize.marValues[0]) - 12.0f;
    if (width * scale > avail)
        scale = avail / width;

    func_003824D0(field_C, GtMathPs2::CGtV2d(597.4f, 48.0f), GtMathPs2::CGtV2d(1.0f, 0.5f), scale,
                  mgr->field_40, mgr->field_50, text, 0x12, 1.0f, 3.402823466e+38f);
    if (!D_01E91C3D.value)
        func_00285190(&D_01E7A800);
    return true;
}
