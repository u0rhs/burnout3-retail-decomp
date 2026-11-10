// NONMATCHING: func_0031D340 -- retail 200 / ours 200 instructions, 2 in changed runs
// sreg: PrepareBorders twin fix -- mgr kept by a live 2nd def derived from scene, colour = (&(mgr = (CB3MenuPageManager *)((char *)scene - 0x1A0))->field_D0)[2], and int i declared last (after layer): every register right, 200/200; left: that def is one addiu s3,s2,-416 in a delay slot (retail nop) and the lqc2 reads -176(s2). [G] scene-relative def is a shape lever. v277: logic exact | near5: PrepareBorders clone (layer, scene, mgr, root order; for-scope i) and a 0xF0 member view struct: 16 off -- the sreg scene-relative def stays best.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/gamesource/Menu/DebugMenu/Components/B3BackgroundComponent.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern CB3MenuPageManager D_01E90240;  // unnamed global (the page manager instance)
extern CGtTexture *D_01EA46B0[0x38];   // unnamed texture table (B3HeadingComponent_00319E80.cpp)

// CGt2dObjectImage::Prepare, called by its link name with retail's 9th argument (N68; as PrepareBorders).
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
#define CGt2dObjectImage_Prepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d

// 0x003A6E80 (see PrepareBorders): pos/anchor/size, two end alphas [L], a UV pair, a mode.
extern "C" void func_003A6E80(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size,
                              float a0, float a1, const CGtV2d &uv0, const CGtV2d &uv1, int mode);

// [C] a view of CB3BackgroundComponent (B3BackgroundComponent.h: field_8 the layer base, field_38[5] the objects
// ReleaseObjects destroys at layer +2); the class members are private, this placeholder is not a declared member.
struct UnkStruct_0031D340_view {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x38 - 0xA];
    CGt2dObject *field_38[5];
};

// 0x0031D340 [G] a CB3BackgroundComponent method like PrepareBorders (same unit, same shape); unnamed in every table.
extern "C" void func_0031D340(UnkStruct_0031D340_view *self, float alpha)
{
    CB3MenuPageManager *mgr = &D_01E90240;
    CGt2dScene *scene = &D_01E90240.field_1A0;
    CGt2dFrame *root = scene->field_14;
    int layer = self->field_8 + 2;
    int i;
    if (self->field_38[0] == 0) {
        for (i = 0; i < 4; i++)
            self->field_38[i] = scene->ConstructObject(layer, root);
    }

    if (alpha < 0.0f) {
        alpha = 0.0f;
    } else {
        CGtV4d colour;
        colour = (&(mgr = (CB3MenuPageManager *)((char *)scene - 0x1A0))->field_D0)[2];
        colour.SetA(alpha);
        if (self->field_38[4] == 0)
            self->field_38[4] = scene->ConstructObject(layer, root);
        CGt2dObjectImage_Prepare(self->field_38[4], CGtV2d(0.0f, 96.0f), CGtV2d(0.0f, 0.0f), CGtV2d(656.0f, 288.0f), colour,
                                 D_01EA46B0[3], CGtV2d(0.0625f, 0.0625f), CGtV2d(40.9375f, 18.9375f), 0);
    }
    CGt2dObjectImage_Prepare(self->field_38[0], CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 0.0f), CGtV2d(656.0f, 65.0f),
                             (&mgr->field_D0)[2],
                             D_01EA46B0[3], CGtV2d(0.0625f, 0.0625f), CGtV2d(40.9375f, 3.9375f), 0);
    CGt2dObjectImage_Prepare(self->field_38[3], CGtV2d(0.0f, 416.0f), CGtV2d(0.0f, 0.0f), CGtV2d(656.0f, 64.0f),
                             (&mgr->field_D0)[2],
                             D_01EA46B0[3], CGtV2d(0.0625f, 0.0625f), CGtV2d(40.9375f, 3.9375f), 0);
    func_003A6E80(self->field_38[1], CGtV2d(0.0f, 65.0f), CGtV2d(0.0f, 0.0f), CGtV2d(656.0f, 32.0f),
                  1.0f, alpha, CGtV2d(0.0625f, 0.0625f), CGtV2d(40.9375f, 1.9375f), 1);
    func_003A6E80(self->field_38[2], CGtV2d(0.0f, 384.0f), CGtV2d(0.0f, 0.0f), CGtV2d(656.0f, 32.0f),
                  alpha, 1.0f, CGtV2d(0.0625f, 0.0625f), CGtV2d(40.9375f, 1.9375f), 1);
}


