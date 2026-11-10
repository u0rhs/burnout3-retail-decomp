// Hand-written; the lifter refused it (a88: Text::Prepare plain overload, sibling of func_0033D650).

// Hand-written (a88: CGt2dObjectText::Prepare(pos,anchor,size,colour,font,text) plain overload).
// [L] DNAT: CGt2dObjectText::Prepare (research/proto/new_names.csv, high)
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectText.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

#pragma auto_inline on

using namespace GtMathPs2;

struct UnkStruct_001D6C40_data {
    const CGt2dFont * field_0;
    const unsigned short * field_4;
    float field_8;
};

extern "C" void _RenderPlain__15CGt2dObjectTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(void *, const void *);

// 0x001D6C40
extern "C" void func_001D6C40(CGt2dObjectText * self, const CGtV2d & pos, const CGtV2d & anchor, float size,
                              const CGtV4d colour, const CGt2dFont * font, const unsigned short * text)
{
    UnkStruct_001D6C40_data * d = (UnkStruct_001D6C40_data *)self->mauDataBlock;
    CGtV4d c2 = colour;
    float width = font->GetStringWidth(text);
    CGtV2d sz(width * size, size);
    d->field_0 = font;
    d->field_4 = text;
    d->field_8 = 1.0f / width;
    self->CGt2dObject::Prepare(pos - sz * anchor, sz, c2, (CGt2dObject::UnkFn_RenderCallback)_RenderPlain__15CGt2dObjectTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv, 0x40, 0xC);
}
