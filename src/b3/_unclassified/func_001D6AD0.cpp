// Hand-written; the lifter refused it (text set-up as an inline helper (sz below the caller's scale/size temp); const render-function table lets its load hoist).

// func_001D6AD0 -- hand-written from the retail structure (lifter refused).
// [L] DNAT: CGt2dObjectText::Prepare(const CGtV2d&, const CGtV2d&, float, CGtV4d, const CGt2dFont*,
//     const unsigned short*, const CGtV2d&, ETextType) (research/proto/new_names.csv, high)
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectText.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

#pragma auto_inline on

using namespace GtMathPs2;

// [G] data block at +0x20 (cf. Gt2dObjectImage): font, text, reciprocal width
struct UnkStruct_001D6AD0_s30 {
    unsigned char pad_0[0x30];
    CGtV2d field_30;
};
struct UnkStruct_001D6AD0_data {
    const CGt2dFont * field_0;
    const unsigned short * field_4;
    float field_8;
};

extern "C" CGt2dObject::UnkFn_RenderCallback const mgapfRenderFunctions__15CGt2dObjectText[];

// [G] stack investigator: the text set-up as an inline helper (cf. CGt2dObjectItalicText::PrepareCommonData, out of
// line in retail). Its local `sz` and its call temporaries then sit below the caller's scale/size temporary, as in
// retail's frame; a function-level `sz` would take the top slot.
static inline void func_001D6AD0_inl1(CGt2dObjectText * self, const CGtV2d & pos, const CGtV2d & anchor, float size,
                                      const CGtV4d & colour, const CGt2dFont * font, const unsigned short * text,
                                      int type)
{
    UnkStruct_001D6AD0_data * d = (UnkStruct_001D6AD0_data *)self->mauDataBlock;
    float width = font->GetStringWidth(text);
    CGtV2d sz(width * size, size);
    d->field_0 = font;
    d->field_4 = text;
    d->field_8 = 1.0f / width;
    self->CGt2dObject::Prepare(pos - sz * anchor, sz, colour, mgapfRenderFunctions__15CGt2dObjectText[type], 0x40, 0xC);
}

// 0x001D6AD0
extern "C" void func_001D6AD0(CGt2dObjectText * self, const CGtV2d & pos, const CGtV2d & anchor, float size,
                              const CGtV4d colour, const CGt2dFont * font, const unsigned short * text,
                              const CGtV2d & scale, int type)
{
    CGtV4d c2 = colour;
    func_001D6AD0_inl1(self, pos, anchor, size, c2, font, text, type);
    ((UnkStruct_001D6AD0_s30 *)self)->field_30 = scale / self->mObjectSpace.mSize;
}
