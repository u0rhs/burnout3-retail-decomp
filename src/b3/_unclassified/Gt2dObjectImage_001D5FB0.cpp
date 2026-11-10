// CGt2dObjectImage::_Render(const CGt2dObject::CGt2dObjectSpace&,const void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dObjectImage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (seeded whole-file function as is, 0 off as its own unit (gt2d, N167)).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

#pragma auto_inline on

using namespace GtMathPs2;

extern const CGtV2d D_004B8118;   // 8-byte .rodata constant, (0, 0); name not recovered

// 0x1D5FB0: one textured sprite over the object's space, UVs from the data block
// 0x001D5FB0
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
