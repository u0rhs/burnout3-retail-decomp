// Gt2dObjectBox.cpp (E map), retail 0x1D5EA0-0x1D5FB0: the whole file. Local fork unit (docs/conventions.md "Original structure").
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using namespace GtMathPs2;

// 0x1D5EA0: one untextured sprite over the object's space
void CGt2dObjectBox::_Render(const CGt2dObject::CGt2dObjectSpace& space, const void*)
{
    CGtV2d corners[2];
    corners[0] = space.mTopLeftPos;
    corners[1] = space.mTopLeftPos + space.mSize;
    Gt2dRenderer::RenderSpritesUntex(space.mColour, CGtV2d(0.0f, 0.0f), 1, corners);
}

// 0x1D5F20
void CGt2dObjectBox::Prepare(const CGtV2d& pos, const CGtV2d& anchor, const CGtV2d& size, const CGtV4d colour)
{
    CGt2dObject::Prepare(pos - size * anchor, size, colour, _Render, 0x40, 0);
}
