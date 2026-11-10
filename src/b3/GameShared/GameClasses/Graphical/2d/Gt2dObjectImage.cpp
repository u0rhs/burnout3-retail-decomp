// NOT WIRED IN, NOT PROVEN HERE: seeded partial from the earlier research repo (`linked: false` there; docs/known.md N6, N16).
// Gt2dObjectImage.cpp (E map), retail 0x1D5FB0-0x1D6170: the whole file. Local fork unit (docs/conventions.md "Original structure").
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

#pragma auto_inline on

using namespace GtMathPs2;

extern const CGtV2d D_004B8118;   // 8-byte .rodata constant, (0, 0); name not recovered

// 0x1D5FB0: one textured sprite over the object's space, UVs from the data block
void CGt2dObjectImage::_Render(const CGt2dObject::CGt2dObjectSpace& space, const void* data)
{
    const UnkStruct_Gt2dObject_20* d = (const UnkStruct_Gt2dObject_20*)data;
    CGtV2d corners[2];
    corners[0] = space.mTopLeftPos;
    corners[1] = space.mTopLeftPos + space.mSize;
    if (d->field_14)
        Gt2dRenderer::SetTexture(d->field_10, d->field_14);
    else
        Gt2dRenderer::SetTexture(d->field_10);
    Gt2dRenderer::RenderSpritesTex(space.mColour, D_004B8118, 1, corners, &d->field_0);
}

// 0x1D6070
void CGt2dObjectImage::SetTexture(CGtTexture* texture)
{
    unsigned int n;   // never set: retail stores whatever a2 holds (B13, uninitialised local [L])
    Data().field_10 = texture;
    Data().field_14 = n;
}

// 0x1D6080
void CGt2dObjectImage::SetUVs(const CGtV2d& uv0, const CGtV2d& uv1)
{
    Data().field_0 = uv0;
    Data().field_8 = uv1;
}

// 0x1D60B0
void CGt2dObjectImage::Prepare(const CGtV2d& pos, const CGtV2d& anchor, const CGtV2d& size, const CGtV4d colour,
                               CGtTexture* texture, const CGtV2d& uv0, const CGtV2d& uv1)
{
    SetTexture(texture);
    SetUVs(uv0, uv1);
    CGt2dObject::Prepare(pos - size * anchor, size, colour, _Render, 0x40, sizeof(UnkStruct_Gt2dObject_20));
}
