#include "b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern CB3MenuPageManager D_01E90240;  // unnamed global (the page manager instance)

// [L] the debug-menu state, switched on here (0-5) and tested by every component's Update. Padded for N51.
struct UnkStruct_D_01E90424 {
    int value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E90424 D_01E90424;

// [L] a 0..1 transition amount for the current state (lwc1, absolute), right before D_01E90424. Padded for N51.
struct UnkStruct_D_01E90420 {
    float value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E90420 D_01E90420;

// Same declarations as B3HeadingComponent_00319A90.cpp / _00319E80.cpp.
struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;

struct UnkStruct_D_0051BA44 {
    CB3Strings strings;
    unsigned char pad[0x100];
};
extern UnkStruct_D_0051BA44 D_0051BA44;

extern CGtTexture *D_01EA46B0[0x38];
struct UnkStruct_D_01EA4790 {
    CGtV2d uv;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01EA4790 D_01EA4790;
extern UnkStruct_D_01EA4790 D_01EA4798;

extern "C" void func_003824D0(CGt2dObject *obj, const CGtV2d &a, const CGtV2d &b, float c, CGtV4d d, CGtV4d e,
                              const unsigned short *text, int f, float g, float h);

// CGt2dObjectImage::Prepare by its link name, with retail's 8th stack argument (N68).
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
#define CGt2dObjectImage_Prepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d

// [L] identity: the E-build B3O0PCH map has CB3HeadingComponent::SetHeadingString(const unsigned short*)
// out of line (0x110 bytes); DNAT and retail have no copy, and retail's Update holds two inlined copies of
// exactly Prepare(text, type)'s text-fit code (Target #31), whose temporaries are allocated after all of
// Update's own -- the signature of an inlined callee.
inline void CB3HeadingComponent::SetHeadingString(const unsigned short *text)
{
    CB3MenuPageManager *mgr = &D_01E90240;
    float scale = 42.0f;
    float width = D_00665ED0.pFont->GetStringWidth(text);
    float avail;
    if (field_26 < 3)
        avail = 597.4f - 176.0f;
    else if (field_14 == 0)
        avail = 597.4f - 160.0f;
    else
        avail = 597.4f - (field_14->mObjectSpace.mTopLeftPos.marValues[0] + field_14->mObjectSpace.mSize.marValues[0]) - 12.0f;
    if (width * scale > avail)
        scale = avail / width;
    func_003824D0(field_C, CGtV2d(597.4f, 48.0f), CGtV2d(1.0f, 0.5f), scale, mgr->field_40, mgr->field_50, text,
                  0x12, 1.0f, 3.402823466e+38f);
}

// 0x00319490 (Target #34). Per menu state (D_01E90424): slide the heading in/out (0-1), fade (2-4), or in
// state 5 run the heading-text change: field_24 (a string id, 0xFA5 = none) or field_20 (a text pointer)
// is a pending heading; field_1C counts 0.4 s out, the text is replaced, then 0.4 s back in (scale =
// 2.5 * field_1C). Afterwards the rotating image (types 0-2) rolls in by `alpha` and the clip frame
// (field_18) narrows the text by `scale`. Source shapes that matter, each found by single-change variants:
//  - SetHeadingString inlined (it puts its temporaries after Update's, as retail's stack layout shows);
//  - case 5's texture index as an int local; the cases in retail's code order (2, 3-4, 5, 0-1);
//  - `if (field_18 != 0) { ... }` at the end: an early `return` fills the last branch's delay slot,
//    retail leaves it empty;
//  - CGtV4d::SetA's definition (GtMathPs2.h: one asm statement, defined out of class).
// 1.145915627 = 360 / (100 pi): degrees of roll per unit of travel for a 100-wide image [G].
void CB3HeadingComponent::Update(float dt)
{
    float scale = 1.0f;
    float alpha = -1.0f;

    switch (D_01E90424.value) {
    case 2:
        if (field_26 < 3)
            alpha = D_01E90420.value;
        scale = D_01E90420.value;
        break;
    case 3:
    case 4:
        scale = D_01E90420.value;
        if (field_26 < 3)
            field_14->mObjectSpace.mColour.SetA(scale);
        break;
    case 5:
        if (field_27) {
            int icon = field_26 + 14;
            CGt2dObjectImage_Prepare(field_14, CGtV2d(30.0f, 22.0f), CGtV2d(0.0f, 0.0f), CGtV2d(100.0f, 100.0f),
                                     D_01E90240.field_110, D_01EA46B0[icon],
                                     D_01EA4790.uv, D_01EA4798.uv, 0);
            field_27 = 0;
        }
        if (field_18 == 0)
            return;
        if (field_1C < 0.0f) {
            if (field_24 < 0xFA5 || field_20 != 0)
                field_1C = 0.4f;
        }
        if (field_1C < 0.0f)
            break;
        if (field_24 >= 0xFA5 && field_20 == 0) {
            field_1C += dt;
            if (field_28)
                alpha = 2.5f * field_1C;
            if (field_1C > 0.4f) {
                field_1C = -1.0f;
                field_28 = 0;
                if (field_28)
                    alpha = 1.0f;
                break;
            }
        } else {
            field_1C -= dt;
            if (field_1C < 0.0f) {
                if (field_24 < 0xFA5)
                    SetHeadingString(D_0051BA44.strings.GetString(field_24));
                else
                    SetHeadingString((const unsigned short *)field_20);
                field_24 = 0xFA5;
                field_20 = 0;
                field_1C = 0.0f;
            }
        }
        scale = 2.5f * field_1C;
        break;
    case 0:
    case 1: {
        float y = 176.0f * D_01E90420.value;
        field_10->mObjectSpace.mTopLeftPos = CGtV2d(0.0f, -176.0f + y);
        if (field_26 == 4)
            field_14->mObjectSpace.mTopLeftPos = CGtV2d(30.0f, -152.0f + y);
        return;
    }
    default:
        return;
    }

    if (alpha >= 0.0f) {
        float d = -480.0f * alpha;
        *(float *)&field_14->mauDataBlock[1] = 1.145915627f * (-480.0f - d);
        field_14->mObjectSpace.mTopLeftPos = CGtV2d(510.0f + d, 22.0f);
        field_14->mObjectSpace.mColour.SetA(alpha);
    }
    if (field_18 != 0) {
        float x = 610;
        if (field_14 == 0 || field_28)
            x = x - 450.0f * scale;
        else
            x = x - scale * (x - (field_14->mObjectSpace.mTopLeftPos.marValues[0] + field_14->mObjectSpace.mSize.marValues[0]));
        field_18->field_0.field_0 = CGtV2d(x, 0.0f);
    }
}
