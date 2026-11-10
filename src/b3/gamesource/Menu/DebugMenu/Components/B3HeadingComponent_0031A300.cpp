// The rotating image's render callback. Single-change variants found, beyond the inline level (N79/N86: -inline level=8 in tools/mwcc_flags.sh):
// CreateRotationMatrix2x3 sets mDown first; corner 0 through the X()/Y() accessors (N82), with its y
// read into a local before the centre add (that fixes the creation order MWCC numbers the FPRs by, N83);
// TransformPoint as `r = translation; r += ...` (GtMathPs2.h).
#include "b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtMatrix2x3;

// [L] the rotating image's 8-byte data block (CB3RotatingImage2dObject::Prepare writes it).
struct UnkStruct_RotatingImageData {
    CGtTexture *texture;
    float angle;  // [L] degrees (scaled by pi/180 here)
};

// 0x0031A300 (Target #38). The image is drawn as a 4-vertex strip rotated by `angle` about its centre.
void CB3RotatingImage2dObject::_Render(const CGt2dObject::CGt2dObjectSpace &space, const void *data)
{
    const UnkStruct_RotatingImageData *d = (const UnkStruct_RotatingImageData *)data;
    CGtV2d *pos = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *uv = pos + 4;
    CGtV2d half = space.mSize * 0.5f;
    CGtMatrix2x3 m;
    m = GtMathPs2::CreateRotationMatrix2x3(0.01745329238f * d->angle);
    float y0 = half.Y();
    m.mPos = space.mTopLeftPos + half;
    pos[0].Set(-half.X(), y0);
    pos[1] = -half;
    pos[2].Set(half.marValues[0], half.marValues[1]);
    pos[3] = -pos[0];
    uv[0].Set(0.0f, 1.0f);
    uv[1].Set(0.0f, 0.0f);
    uv[2].Set(1.0f, 1.0f);
    uv[3].Set(1.0f, 0.0f);
    GtMathPs2::TransformPoints(m, pos, pos, 4);
    Gt2dRenderer::SetTexture(d->texture);
    Gt2dRenderer::RenderTriStripFlatTex(space.mColour, CGtV2d(0.0f, 0.0f), 4, pos, uv);
}
