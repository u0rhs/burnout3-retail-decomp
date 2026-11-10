// Hand-written; the lifter refused it (by-value CGtV4d colour declared const [G] (top-level const, not mangled): its lq leaves the store order and schedules first (sdra rule 1)).


// [L] DNAT: CGt2dObjectParagraph::Prepare(const CGtV2d&,float,const CGtV2d&,CGtV4d,const unsigned short*,c...) (research/proto/new_names.csv, high)
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

// [G] the text style the object keeps at +0x2C: two line-metric floats and the font at +0x10
struct UnkStruct_002F9690_style {
    unsigned char pad_0[0x8];
    float field_8;
    float field_C;
    const CGt2dFont * field_10;
};

struct UnkStruct_002F9690_data {
    CGtV2d field_0;
    const unsigned short * field_8;
    const UnkStruct_002F9690_style * field_C;
    unsigned int field_10;
    float field_14;
};
class CGt2dObjectParagraph : public CGt2dObject {
public:
    UnkStruct_002F9690_data * Data() { return (UnkStruct_002F9690_data *)mauDataBlock; }
};

extern "C" const CGt2dObject::UnkFn_RenderCallback mgapfRenderFunctions__20CGt2dObjectParagraph[];

// 0x002F9690
extern "C" void func_002F9690(CGt2dObjectParagraph * self, const CGtV2d & pos, float scale, const CGtV2d & anchor,
                              const CGtV4d colour, const unsigned short * text, const UnkStruct_002F9690_style * style,
                              unsigned int flags, int type)
{
    UnkStruct_002F9690_data * const d = self->Data();
    const unsigned short * start = text;
    const unsigned short * end;
    float inv = scale / style->field_8;
    float h = -style->field_C;
    unsigned int mask = flags & 0x64;
    do {
        style->field_10->GetStringStartAndEnd(start, inv, &start, &end, mask == 0x64);
        if (start == end) break;
        start = end;
        h += style->field_8 + style->field_C;
    } while (*end != 0);
    CGtV2d size(scale, h);
    d->field_0 = CGtV2d(1.0f, 1.0f) / size;
    d->field_8 = text;
    d->field_C = style;
    d->field_10 = flags;
    d->field_14 = inv;
    self->CGt2dObject::Prepare(pos - size * anchor, size, colour, mgapfRenderFunctions__20CGt2dObjectParagraph[type], 0x40, 0x18);
}
