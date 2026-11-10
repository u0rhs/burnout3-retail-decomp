// NONMATCHING: _Render__24C2dObjectBoostBarMessageFRCQ211CGt2dObject16CGt2dObjectSpacePCv -- retail 559 / ours 595 instructions, 553 in changed runs
// draftAG: logic complete; retail 559 / ours 595; call multiset identical (calls.sh order differs only by retail's block placement of the small-star render); every VU op count identical (header SinCosFast / Interpolate / CGtV4d*CGtV4d / SetW; one in-place alpha-squared stand-in); left: float copy temporaries of the quad / UV / corner CGtV2d builds (swc1 84 vs 66, sw 25 vs 17), frame 0x450 vs 0x360
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm with Revenge's STABS locals (same function, 526 instrs); every branch, call, store and VU op accounted for

// C2dObjectBoostBarMessage::_Render(const CGt2dObject::CGt2dObjectSpace&, const void*) -- draftAG (C-first draft).
// [C] name: retail symbol table. Written from the retail asm; local names after Revenge's own _Render (STABS,
// B4HUDBoostBar.cpp: lpBoostMessage, lColour, lScale, lnSpriteCount, lOutlineOffset, lOutlineColour, lStarCentre, lStarRadius,
// lRadius, lCornerA, lCornerB, lrStarStepX, ln8Count, lrTextRight) [L]. What it draws [L]: the message text (glyph quads from
// _BuildBatchData) with a drop shadow ringed by its outline offsets, the outline itself, then the text again with a left-to-
// right colour gradient; then a row of small stars after the text (the last one scaled by field_1C) and a spinning big star
// (SinCosFast of field_20, alpha field_24).
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectText.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

class CGtTexture;
struct UnkStruct_D_00665ED0 { CGt2dFont *pFont; unsigned char pad[0x100]; };
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_D_0066A4C0 {               // the HUD colour set [G]
    unsigned char pad_0[0x20];
    CGtV4d field_20;                         // [C] gradient colour (left end)
    unsigned char pad_30[0x30];
    CGtV4d field_60;                         // [C] gradient colour (right end)
};
extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern const CGtV2d D_004B7948;             // [C] the text scale (times the object's size); static-initialised [G]
class CB3HUDComponent {
public:
    static CGt2dObjectText::COutlineDropShadow maOutlineDropShadow[3];   // [C] mangled name
    static CGtTexture *mpBoostStarsTexture;                              // [C] mangled name
};
struct UnkStruct_001A5740_msg {             // [L] Revenge's CBoostMessage
    unsigned char pad_0[0x18];
    signed char field_18;                    // [C] small star count
    unsigned char pad_19[3];
    float field_1C;                          // [C] the last small star's scale
    float field_20;                          // [C] big star angle (radians)
    float field_24;                          // [C] big star alpha, <= 0 hidden
};
struct UnkStruct_001A5740_quad { CGtV2d field_0; CGtV2d field_8; };   // a sprite: top-left, bottom-right
class C2dObjectBoostBarMessage {
public:
    struct C2dObjectBoostBarMessageData { UnkStruct_001A5740_msg *field_0; };
    static int _BuildBatchData(const CGt2dObject::CGt2dObjectSpace &space, const CGtV2d &scale,
                               const C2dObjectBoostBarMessageData *data);
    static void _Render(const CGt2dObject::CGt2dObjectSpace &lObjectSpace, const void *lpData);
};
extern "C" void RenderTriStripGouraudTex__12Gt2dRendererFRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV4d(
    const CGtV2d &, int, const CGtV2d *, const CGtV2d *, const CGtV4d *);

// [L] N185 stand-in: the colour's alpha squared in place (retail one `vmulw.w v, v, vw`; no header form)
static inline void func_001A5740_inl1(CGtV4d &c) { asm("vmulw.w %0, %0, %0w" : "+j"(c.mData)); }

// 0x001A5740
void C2dObjectBoostBarMessage::_Render(const CGt2dObject::CGt2dObjectSpace &lObjectSpace, const void *lpData)
{
    const C2dObjectBoostBarMessageData *d = (const C2dObjectBoostBarMessageData *)lpData;
    UnkStruct_001A5740_msg *lpBoostMessage = d->field_0;
    UnkStruct_001A5740_quad *lpXY = (UnkStruct_001A5740_quad *)CGt2dObject::mgu8RenderBatchData;
    UnkStruct_001A5740_quad *lpUV = (UnkStruct_001A5740_quad *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    CGtV4d lColour = lObjectSpace.mColour;
    func_001A5740_inl1(lColour);
    CGtV4d lOutlineColour(0.0f, 0.0f, 0.0f, ((const float *)&lColour)[3]);
    CGtV2d lZero(0.0f, 0.0f);
    CGtV2d lScale = D_004B7948 * lObjectSpace.mSize;
    const CGt2dObjectText::COutlineDropShadow &ods = CB3HUDComponent::maOutlineDropShadow[0];
    CGtV4d lShadowColour = ods.mDropShadowColour;
    lShadowColour.SetW(lShadowColour.W() * lOutlineColour.W());
    CGtV2d lShadowOffset = ods.mDropShadowOffset * lScale;
    CGtV2d lOutlineOffset = ods.mOutlineOffset * lScale;
    Gt2dRenderer::SetTexture(D_00665ED0.pFont->field_4);
    int lnSpriteCount = _BuildBatchData(lObjectSpace, lScale, d);
    // the drop shadow, ringed by the outline offsets
    for (int i = 0; i < 2; i++) {
        Gt2dRenderer::RenderSpritesTex(lShadowColour, lShadowOffset + lOutlineOffset, lnSpriteCount, &lpXY->field_0, &lpUV->field_0);
        Gt2dRenderer::RenderSpritesTex(lShadowColour, lShadowOffset - lOutlineOffset, lnSpriteCount, &lpXY->field_0, &lpUV->field_0);
        lOutlineOffset.marValues[0] = -lOutlineOffset.marValues[0];
    }
    // the outline
    for (int i = 0; i < 2; i++) {
        Gt2dRenderer::RenderSpritesTex(lOutlineColour, lOutlineOffset, lnSpriteCount, &lpXY->field_0, &lpUV->field_0);
        Gt2dRenderer::RenderSpritesTex(lOutlineColour, -lOutlineOffset, lnSpriteCount, &lpXY->field_0, &lpUV->field_0);
        lOutlineOffset.marValues[0] = -lOutlineOffset.marValues[0];
    }
    // the text, coloured left to right
    float lrTextLeft = lpXY[0].field_0.marValues[0];
    float lrTextRight = lpXY[lnSpriteCount - 1].field_8.marValues[0];
    float lrWidth = lrTextRight - lrTextLeft;
    float lrInv = 1.0f / (lrWidth + 0.002f);
    float lrStart = 0.0f + lrTextLeft - 0.001f * lrWidth;
    CGtV4d lRight = lObjectSpace.mColour * D_0066A4C0.field_60;
    CGtV4d lLeft = lObjectSpace.mColour * D_0066A4C0.field_20;
    UnkStruct_001A5740_quad *xy = lpXY;
    UnkStruct_001A5740_quad *uv = lpUV;
    for (int i = 0; i < lnSpriteCount; i++) {
        CGtV2d lPos[4];
        CGtV2d lUV[4];
        CGtV4d lCol[4];
        lPos[0] = xy->field_0;
        lPos[1] = CGtV2d(xy->field_8.marValues[0], xy->field_0.marValues[1]);
        lPos[2] = CGtV2d(xy->field_0.marValues[0], xy->field_8.marValues[1]);
        lPos[3] = xy->field_8;
        lUV[0] = uv->field_0;
        lUV[1] = CGtV2d(uv->field_8.marValues[0], uv->field_0.marValues[1]);
        lUV[2] = CGtV2d(uv->field_0.marValues[0], uv->field_8.marValues[1]);
        lUV[3] = uv->field_8;
        lCol[0] = lCol[2] = Interpolate(lLeft, lRight, lrInv * (xy->field_0.marValues[0] - lrStart));
        lCol[3] = lCol[1] = Interpolate(lLeft, lRight, lrInv * (xy->field_8.marValues[0] - lrStart));
        xy++;
        uv++;
        RenderTriStripGouraudTex__12Gt2dRendererFRCQ29GtMathPs26CGtV2diPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV2dPCQ29GtMathPs26CGtV4d(
            lZero, 4, lPos, lUV, lCol);
    }
    // the stars after the text
    if (!(lpBoostMessage->field_18 > 0) && lpBoostMessage->field_24 <= 0.0f)
        return;
    lrTextRight = lpXY[lnSpriteCount - 1].field_8.marValues[0];
    CGtV2d lStarCentre(lrTextRight - lObjectSpace.mTopLeftPos.marValues[0] + 23.7f * lScale.marValues[0], 11.7f * lScale.marValues[1]);
    CGtV2d lStarRadius(11.7f * lScale.marValues[0], 11.7f * lScale.marValues[1]);
    float lrStarStepX = 17.4f * lScale.marValues[0];
    CGtV4d lStarColour = lObjectSpace.mColour;
    Gt2dRenderer::SetTexture(CB3HUDComponent::mpBoostStarsTexture);
    signed char ln8Count = lpBoostMessage->field_18;
    if (ln8Count > 0) {
        CGtV2d lRadius = lStarRadius;
        xy = lpXY + 2;
        uv = lpUV + 2;
        do {
            if (--ln8Count == 0)
                lRadius *= lpBoostMessage->field_1C;
            uv->field_0 = CGtV2d(0.0078125f, 0.015625f);
            CGtV2d lCornerA = lStarCentre - lRadius;
            CGtV2d lCornerB = lStarCentre + lRadius;
            lStarCentre.marValues[0] = lrStarStepX + lStarCentre.marValues[0];
            xy->field_0 = lCornerA;
            uv->field_8 = CGtV2d(0.4921875f, 0.984375f);
            xy->field_8 = lCornerB;
            uv++;
            xy++;
        } while (ln8Count != 0);
    }
    if (!(lpBoostMessage->field_24 <= 0.0f)) {
        // the big star, spinning: corners (s rx, c ry), (c rx, -s ry) and their negations
        CGtV4d lSinCos = SinCosFast(lpBoostMessage->field_20);
        const float *sc = (const float *)&lSinCos;
        CGtV2d lCornerA(sc[0] * lStarRadius.marValues[0], sc[1] * lStarRadius.marValues[1]);
        CGtV2d lCornerB(sc[1] * lStarRadius.marValues[0], (float)-lSinCos.X() * lStarRadius.marValues[1]);
        lpUV[0].field_0 = CGtV2d(0.5078125f, 0.015625f);
        lpUV[0].field_8 = CGtV2d(0.9921875f, 0.015625f);
        lpUV[1].field_0 = CGtV2d(0.5078125f, 0.984375f);
        lpUV[1].field_8 = CGtV2d(0.9921875f, 0.984375f);
        lpXY[0].field_0 = lCornerA;
        lpXY[0].field_8 = lCornerB;
        lpXY[1].field_0 = -lCornerB;
        lpXY[1].field_8 = -lCornerA;
        lStarColour.SetW(lObjectSpace.mColour.W() * lpBoostMessage->field_24);
        Gt2dRenderer::RenderTriStripFlatTex(lStarColour, lObjectSpace.mTopLeftPos + lStarCentre, 4, &lpXY->field_0, &lpUV->field_0);
    }
    if (lpBoostMessage->field_18 > 0) {
        lStarColour.SetW(lObjectSpace.mColour.W());
        Gt2dRenderer::RenderSpritesTex(lStarColour, lObjectSpace.mTopLeftPos, lpBoostMessage->field_18, &lpXY[2].field_0, &lpUV[2].field_0);
    }
}
