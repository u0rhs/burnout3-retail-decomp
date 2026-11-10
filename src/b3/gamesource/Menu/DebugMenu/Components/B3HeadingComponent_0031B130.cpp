// DRAFT -- NOT MATCHING, NOT WIRED IN (retail's asm is still linked: B3HeadingComponent_0031B130.s).
// Status: 321/321 instructions; batch pointers chained off `colours`, the
// quad written through X()/Y() accessors and the fill colour as its own statement all match retail's
// code. What differs is the frame (0x270 here vs retail's 0x1E0): MWCC reserves more 16-byte stack
// slots for the CGtV4d products than retail did, so every stack offset is shifted. No CGtV4d::operator*
// form or colour-statement spelling tried (a 40-way grid) gives 0x1E0.
#include "b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

// [C] names: E-build maps (B3HeadingComponent.cpp .rodata); retail addresses 0x4C5170/0x4C5180
// (config/symbol_addrs_b3names.txt).
extern const CGtV2d krHeadingBarBigCurveEffectiveImageSize;
extern const CGtV4d kHeadingTextBarFillColourScale;

extern CGtTexture *D_01EA46B0[0x38];  // same texture table as Prepare(EHeadingType); [5] is the bar's curve

// 0x0031B130. The data block is the reciprocal of the bar's 640x128 design size (CHeadingBar2dObject::
// Prepare), so `scale` is the object's size in design units. Draws, from mgu8RenderBatchData: a flat
// fill quad, two 6-vertex Gouraud strips (one per end of the quad), the textured curve, then a 3-vertex cap.
void CHeadingBar2dObject::_Render(const CGt2dObject::CGt2dObjectSpace &space, const void *data)
{
    CB3MenuPageManager *const mgr = &D_01E90240;
    CGtV4d *colours = (CGtV4d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *pos = (CGtV2d *)(colours + 6);
    CGtV2d *uv = pos + 6;
    CGtV2d *quad = uv + 4;

    CGtV2d scale = *(const CGtV2d *)data * space.mSize;
    CGtV2d c = scale * CGtV2d(0.0f, 1.0f);
    CGtV2d b = scale * CGtV2d(0.0f, 25.0f);
    CGtV2d a = scale * CGtV2d(640.0f, 46.0f);
    CGtV2d offset(0.0f, 0.0f);
    CGtV2d d = space.mTopLeftPos + b;
    CGtV2d e = d + a;

    quad[0].Set(d.X() + 161.0f * scale.X(), d.Y());
    quad[1].Set(e.X(), d.Y());
    quad[2].Set(d.X() + 76.0f * scale.X(), e.Y());
    quad[3].Set(e.X(), e.Y());
    CGtV4d fill;
    fill = space.mColour * kHeadingTextBarFillColourScale;
    Gt2dRenderer::RenderTriStripFlatUntex(mgr->field_100 * fill, offset, 4, quad);

    CGtV4d outer = mgr->field_130 * space.mColour;
    CGtV4d middle = mgr->field_120 * space.mColour;
    colours[0] = outer;
    colours[1] = outer;
    colours[2] = middle;
    colours[3] = middle;
    colours[4] = outer;
    colours[5] = outer;
    pos[0] = quad[0] - c;
    pos[1] = quad[0] + c;
    pos[2].Set(0.5f * space.mSize.marValues[0], pos[0].marValues[1]);
    pos[3].Set(0.5f * space.mSize.marValues[0], pos[1].marValues[1]);
    pos[4] = quad[1] - c;
    pos[5] = quad[1] + c;
    Gt2dRenderer::RenderTriStripGouraudUntex(offset, 6, pos, colours);

    pos[0] = quad[2] - c;
    pos[1] = quad[2] + c;
    pos[2].Set(0.5f * space.mSize.marValues[0], pos[0].marValues[1]);
    pos[3].Set(0.5f * space.mSize.marValues[0], pos[1].marValues[1]);
    pos[4] = quad[3] - c;
    pos[5] = quad[3] + c;
    Gt2dRenderer::RenderTriStripGouraudUntex(offset, 6, pos, colours);

    uv[0].Set(1.0f, 0.0f);
    uv[1].Set(0.0f, 0.0f);
    uv[2].Set(1.0f, 0.5f);
    uv[3].Set(0.0f, 1.0f);
    for (int i = 0; i < 4; i++)
        pos[i] = uv[i] * krHeadingBarBigCurveEffectiveImageSize * scale;
    Gt2dRenderer::SetTexture(D_01EA46B0[5]);
    Gt2dRenderer::RenderTriStripFlatTex(space.mColour, space.mTopLeftPos, 4, pos, uv);

    uv[0].Set(1.0f, 1.0f);
    uv[1].Set(0.0f, 1.0f);
    uv[2].Set(1.0f, 0.5f);
    pos[1].Set(pos[0].marValues[0] + krHeadingBarBigCurveEffectiveImageSize.marValues[0] * scale.marValues[0], pos[0].marValues[1]);
    Gt2dRenderer::RenderTriStripFlatTex(space.mColour, space.mTopLeftPos, 3, pos, uv);
}
