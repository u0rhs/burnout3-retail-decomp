// Hand-written; the lifter refused it (L261: clone of CB3RotatingImage2dObject::_Render (corners in a local CGtV2d c[4] declared before the matrix, transformed into the batch buffer); angle = pi/180 * (field_E >= 0 ? field_C : 0); half assigned (not initialised) reserves retail's top temp slot; SetTexture(tex, flag)/SetTexture(tex) + strip inside if (texture)).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtMatrix2x3;

// [G] the object's data block (render callback's second argument).
struct UnkStruct_004272A0_d {
    unsigned char pad_0[0x8];
    CGtTexture *field_8;
    signed char field_C;
    unsigned char pad_D[0x1];
    signed char field_E;
    unsigned char pad_F[0x2];
    signed char field_11;
};

// 0x004272A0. [L] a CB3ImageReward2dObject render callback (between PrepareCarSelect and Prepare in
// research/proto/new_names.csv); same shape as CB3RotatingImage2dObject::_Render (0x31A300).
extern "C" void func_004272A0(const CGt2dObject::CGt2dObjectSpace &space, const void *data)
{
    const UnkStruct_004272A0_d *d = (const UnkStruct_004272A0_d *)data;
    CGtV2d *pos = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *uv = pos + 4;
    CGtV2d half;
    CGtV2d c[4];
    CGtMatrix2x3 m;
    half = space.mSize * 0.5f;
    m = GtMathPs2::CreateRotationMatrix2x3(0.01745329238f * (d->field_E >= 0 ? (float)d->field_C : 0.0f));
    float y0 = half.Y();
    m.mPos = space.mTopLeftPos + half;
    c[0].Set(-half.X(), y0);
    c[1] = -half;
    c[2].Set(half.marValues[0], half.marValues[1]);
    c[3] = -c[0];
    uv[0].Set(0.0f, 1.0f);
    uv[1].Set(0.0f, 0.0f);
    uv[2].Set(1.0f, 1.0f);
    uv[3].Set(1.0f, 0.0f);
    GtMathPs2::TransformPoints(m, pos, c, 4);
    if (d->field_8 != 0) {
        if (d->field_11 != 0)
            Gt2dRenderer::SetTexture(d->field_8, d->field_11);
        else
            Gt2dRenderer::SetTexture(d->field_8);
        Gt2dRenderer::RenderTriStripFlatTex(space.mColour, CGtV2d(0.0f, 0.0f), 4, pos, uv);
    }
}
