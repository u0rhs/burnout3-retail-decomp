// Gt2dObject.cpp (E map), retail 0x1D5E00-0x1D5EA0: the whole file. Local fork unit (docs/conventions.md "Original structure").
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using namespace GtMathPs2;

// 0x1D5E00
void CGt2dObject::SetPos(const CGtV2d& pos, const CGtV2d& anchor)
{
    mObjectSpace.mTopLeftPos = pos - mObjectSpace.mSize * anchor;
}

// 0x1D5E70
void CGt2dObject::Prepare(const CGtV2d& pos, const CGtV2d& size, const CGtV4d colour, UnkFn_RenderCallback render,
                          unsigned int, unsigned int)
{
    mObjectSpace.mTopLeftPos = pos;
    mObjectSpace.mSize = size;
    mObjectSpace.mColour = colour;
    mpfRender = render;
}
