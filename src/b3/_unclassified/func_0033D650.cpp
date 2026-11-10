// Hand-written; the lifter refused it (a88: ItalicText::Prepare plain overload, a87 sibling shape without scale).

// Hand-written (a88: CGt2dObjectItalicText::Prepare(pos,anchor,size,colour,font,text) plain overload).
// [L] DNAT: CGt2dObjectItalicText::Prepare (research/proto/new_names.csv, high)
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectItalicText.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

#pragma auto_inline on

using namespace GtMathPs2;

struct UnkStruct_0033D650_data {
    const CGt2dFont * field_0;
    const unsigned short * field_4;
    float field_8;
};

extern "C" void _RenderPlain__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(void *, const void *);

// 0x0033D650
extern "C" void func_0033D650(CGt2dObjectItalicText * self, const CGtV2d & pos, const CGtV2d & anchor, float size,
                              const CGtV4d colour, const CGt2dFont * font, const unsigned short * text)
{
    UnkStruct_0033D650_data * d = (UnkStruct_0033D650_data *)self->mauDataBlock;
    CGtV4d c2 = colour;
    float width = font->GetStringWidth(text);
    CGtV2d sz(width * size, size);
    d->field_0 = font;
    d->field_4 = text;
    d->field_8 = 1.0f / width;
    self->CGt2dObject::Prepare(pos - sz * anchor, sz, c2, (CGt2dObject::UnkFn_RenderCallback)_RenderPlain__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv, 0x40, 0xC);
}
