// Hand-written; the lifter refused it (text set-up as an inline helper (sz below the caller's 1/size temp); callback symbol __21 fixed).

// func_0033D380 -- hand-written from the retail structure (lifter refused).
// [L] DNAT: CGt2dObjectItalicText::Prepare(const CGtV2d&, const CGtV2d&, float, CGtV4d, const CGt2dFont*,
//     const unsigned short*, const CGtV2d&, ETextType) (research/proto/new_names.csv, high)
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectItalicText.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

#pragma auto_inline on

using namespace GtMathPs2;

// [G] data block at +0x20 (cf. Gt2dObjectImage): font, text, reciprocal width
struct UnkStruct_0033D380_s30 {
    unsigned char pad_0[0x30];
    CGtV2d field_30;
};
struct UnkStruct_0033D380_data {
    const CGt2dFont * field_0;
    const unsigned short * field_4;
    float field_8;
    int field_C;
};

extern "C" void _RenderOutlineDropShadow__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &, const void *);

// [G] stack investigator: the text set-up as an inline helper (cf. CGt2dObjectItalicText::PrepareCommonData, out of
// line in retail). Its local `sz` and its call temporaries then sit below the caller's 1/size temporary, as in
// retail's frame; a function-level `sz` would take the top slot.
static inline void func_0033D380_inl1(CGt2dObjectItalicText * self, const CGtV2d & pos, const CGtV2d & anchor, float size,
                                      const CGtV4d & colour, const CGt2dFont * font, const unsigned short * text)
{
    UnkStruct_0033D380_data * d = (UnkStruct_0033D380_data *)self->mauDataBlock;
    float width = font->GetStringWidth(text);
    CGtV2d sz(width * size, size);
    d->field_0 = font;
    d->field_4 = text;
    d->field_8 = 1.0f / width;
    self->CGt2dObject::Prepare(pos - sz * anchor, sz, colour, _RenderOutlineDropShadow__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv, 0x40, 0xC);
}

// 0x0033D380
extern "C" void func_0033D380(CGt2dObjectItalicText * self, const CGtV2d & pos, const CGtV2d & anchor, float size,
                              const CGtV4d colour, const CGt2dFont * font, const unsigned short * text,
                              void *arg_)
{
    int arg = (int)arg_;
    CGtV4d c2 = colour;
    func_0033D380_inl1(self, pos, anchor, size, c2, font, text);
    UnkStruct_0033D380_data * d = (UnkStruct_0033D380_data *)self->mauDataBlock;
    ((UnkStruct_0033D380_s30 *)self)->field_30 = CGtV2d(1.0f, 1.0f) / self->mObjectSpace.mSize;
    d->field_C = arg;
}
