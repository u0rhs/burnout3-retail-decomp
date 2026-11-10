// Hand-written; the lifter refused it (L266: BoostBarMessage-style text builder; CGtV2d* pos/uv post-increments, scalar sx + CGtV2d(sx,size.y) temps, cursor assigned after size, glyph-ptr local, scoped opt_arithtransformation off [G]).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using GtMathPs2::CGtV2d;

struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;
extern float D_004E0864;

// Text-quad builder like C2dObjectBoostBarMessage::_BuildBatchData (0x1A6000); DNAT row for this address is low-tier
// (research/proto/new_names.csv), so the placeholder name stays. a1 = the object's data block [G].
struct UnkStruct_00382200_data {
    const unsigned short *field_0;
    float field_4;
    unsigned char pad_8[0xB];
    unsigned char field_13;
};

// 0x00382200
// N182: opt_arithtransformation off [G] scoped to this function -- keeps `extra + cursor.x` unreassociated
// (retail add.s f4,f3,f4); without it MWCC folds extra into the madd accumulator.
#pragma push
#pragma opt_arithtransformation off
extern "C" int func_00382200(const CGt2dObject::CGt2dObjectSpace &space, const UnkStruct_00382200_data *data)
{
    float extra;  // declared first: retail's FPR numbering (f3)
    const unsigned short *s = data->field_0;
    CGt2dFont *font = D_00665ED0.pFont;
    UnkStruct_Gt2dFont_Glyph *g = font->UnkInline_FindGlyph(*s);
    CGtV2d *pos = (CGtV2d *)CGt2dObject::mgu8RenderBatchData;
    CGtV2d *uv = (CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0);
    int n = 0;
    unsigned char flags = data->field_13;
    CGtV2d cursor;
    CGtV2d size;
    CGtV2d p;
    size = CGtV2d(font->field_8) * space.mSize;
    cursor = space.mTopLeftPos;
    float sx = data->field_4 * size.marValues[0];
    if (!(flags & 0x40)) {
        cursor.marValues[0] = cursor.marValues[0] - g->field_10.marValues[0] * sx;
    }
    extra = 0.0f;
    if (flags & 0x20) {
        UnkStruct_Gt2dFont_Glyph *sp = font->UnkInline_FindGlyph(0x20);
        extra = D_004E0864 * (sp->field_18 * sx);
    }
    for (;;) {
        bool skip = !(g->field_0.marValues[0] >= 0.0f);
        if (!skip) {
            n++;
            p = cursor + g->field_10 * CGtV2d(sx, size.marValues[1]);
            *pos++ = p;
            *uv++ = g->field_0;
            *pos++ = p + CGtV2d(sx, size.marValues[1]) * g->field_8;
            *uv++ = g->field_0 + g->field_8;
        }
        unsigned short c = *++s;
        if (c == 0)
            break;
        cursor.marValues[0] += g->field_18 * sx;
        cursor.marValues[0] = extra + cursor.marValues[0];
        g = font->UnkInline_FindGlyph(c);
    }
    return n;
}
#pragma pop
