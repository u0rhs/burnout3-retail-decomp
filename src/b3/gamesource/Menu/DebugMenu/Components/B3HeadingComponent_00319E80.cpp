#include "b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern CB3MenuPageManager D_01E90240;  // unnamed global (the page manager instance)

// [L] an int flag tested against zero (lw, absolute); same global as B3HSelectComponent_0031CCD0.cpp. Padded for N51.
struct UnkStruct_D_01E90424 {
    int value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E90424 D_01E90424;

// [C] a CGtTexture* table: [2] is the type-4 image, [14 + type] the type 0-2 rotating image, and
// [kan8HeadingAwardIconImages[type - 6]] the type 6-9 icon. Owner and length unknown.
extern CGtTexture *D_01EA46B0[0x38];
// [C] the two UV corners passed with those textures; owner unknown. Padded for N51.
struct UnkStruct_D_01EA4790 {
    CGtV2d uv;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01EA4790 D_01EA4790;
extern UnkStruct_D_01EA4790 D_01EA4798;

// Same object as in B3HeadingComponent_00319A90.cpp. Padded for N51.
struct UnkStruct_D_01E7A800 {
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E7A800 D_01E7A800;

// [L] a second CB3Strings instance, 4 bytes after the one Prepare(EGlobalStrings, type) uses (D_0051BA44).
struct UnkStruct_D_0051BA48 {
    CB3Strings strings;
    unsigned char pad[0x100];
};
extern UnkStruct_D_0051BA48 D_0051BA48;

// [L] name: the E-build maps list kan8HeadingAwardIconImages in B3HeadingComponent.cpp's .sdata (3 bytes
// there). Retail reads a signed byte table gp-relative at 0x4E1D20 (+type-6), cases 6-9, so 4 entries here.
extern signed char kan8HeadingAwardIconImages[4];

// Unnamed in retail and in every table in research/; placeholder names, C linkage. Register layouts only. [L]
extern "C" void func_0031A5D0(CB3HeadingComponent *self, int n);
extern "C" int func_0031ABC0(CB3HeadingComponent *self);
extern "C" void func_00447E50(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor,
                              const unsigned short *text, float a, float b);
extern "C" void func_00285560(UnkStruct_D_01E7A800 *p, int type, int n);

// CGt2dObjectImage::Prepare, called by its link name: retail's callee also reads a stack-passed 8th
// argument (lw 0x40($sp) -> +0x34, the data block's second SetTexture word), which every retail caller
// passes (sd $zero, 0($sp)), although the E-map signature (Gt2dObject.h) has 7 parameters. [C] layout
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
#define CGt2dObjectImage_Prepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d

// CHeadingBar2dObject: B3HeadingComponent.h (its _Render is B3HeadingComponent_0031B130.cpp).
// CB3RotatingImage2dObject: B3HeadingComponent.h (also used by func_0031A840).

// 0x00319E80 (Target #33). Sets up the heading bar for every type, then one extra object (field_14) or
// helper call per type through a 15-entry jump table (retail's jtbl_004C51B0; tools/jtbl_retarget.py).
// Source shapes that matter, each found by single-change variants:
//  - the scene as the page manager's member (as in N63); the bare D_01E903E0 global constant-folds
//    the root-frame load instead of going through $s2;
//  - the cases written in retail's code order (10, 11, 12, 4, 0-2, 14, 6-9): blocks follow source order;
//  - (int)(field_26 + 14): without the cast, 14 is folded into the table base (an enum value in the
//    original, probably [G]);
//  - case 14's string and case 6-9's icon index fetched into locals before ConstructObject, as retail
//    orders them.
bool CB3HeadingComponent::Prepare(EHeadingType type)
{
    CB3MenuComponentBase::Prepare();
    CGt2dScene *scene = &D_01E90240.field_1A0;
    CGt2dFrame *root = scene->field_14;
    CB3MenuPageManager *mgr = &D_01E90240;
    field_26 = type;
    field_24 = 0xFA5;
    field_20 = 0;
    field_1C = -1.0f;
    field_27 = 0;
    field_28 = 0;
    field_C = 0;
    field_10 = scene->ConstructObject(field_8, root);

    float yoff = D_01E90424.value == 0 ? 0.0f : 176.0f;  // (!= 0 ? 176 : 0 inverts the branch)
    ((CHeadingBar2dObject *)field_10)->Prepare(CGtV2d(0.0f, -176.0f + yoff), CGtV2d(0.0f, 0.0f));

    switch (type) {
    case 10:
        func_0031A5D0(this, 2);
        break;
    case 11:
        func_0031A5D0(this, 0);
        break;
    case 12:
        func_0031A5D0(this, 1);
        break;
    case 4:
        field_14 = scene->ConstructObject(field_8 + 2, root);
        CGt2dObjectImage_Prepare(field_14, CGtV2d(0.0f, -152.0f + yoff), CGtV2d(0.0f, 0.0f), CGtV2d(320.0f, 80.0f),
                                 mgr->field_110, D_01EA46B0[2], D_01EA4790.uv, D_01EA4798.uv, 0);
        break;
    case 0:
    case 1:
    case 2:
        field_14 = scene->ConstructObject(field_8 + 2, root);
        ((CB3RotatingImage2dObject *)field_14)
            ->Prepare(CGtV2d(640.0f, 22.0f), CGtV2d(0.0f, 0.0f), CGtV2d(100.0f, 100.0f), mgr->field_110,
                      D_01EA46B0[(int)(field_26 + 14)]);
        field_27 = 1;
        func_00285560(&D_01E7A800, field_26, 0);
        break;
    case 14: {
        int id = func_0031ABC0(this);
        if (id != 10) {
            field_14 = scene->ConstructObject(field_8 + 2, root);
            const unsigned short *text = D_0051BA48.strings.GetString(id);
            func_00447E50(field_14, CGtV2d(30.0f, -158.0f + yoff), CGtV2d(0.0f, 0.0f), text, 60.0f, 384.0f);
        }
        break;
    }
    case 6:
    case 7:
    case 8:
    case 9: {
        int icon = kan8HeadingAwardIconImages[type - 6];
        field_14 = scene->ConstructObject(field_8 + 2, root);
        CGt2dObjectImage_Prepare(field_14, CGtV2d(30.0f, 22.0f), CGtV2d(0.0f, 0.0f), CGtV2d(100.0f, 100.0f),
                                 mgr->field_110, D_01EA46B0[icon],
                                 D_01EA4790.uv, D_01EA4798.uv, 0);
        break;
    }
    }
    return true;
}
