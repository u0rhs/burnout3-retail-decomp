// Hand-written; the lifter refused it (sticky flag written vis = vis || cond).


#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;
extern float D_004E0864;
// 0x003827B0
extern "C" float func_003827B0(const unsigned short *s, unsigned char flags)
{
    CGt2dFont *font = D_00665ED0.pFont;
    float pad = 0.0f;
    if (flags & 0x20) {
        pad = D_004E0864 * font->UnkInline_FindGlyph(0x20)->field_18;
    }
    UnkStruct_Gt2dFont_Glyph *g = font->UnkInline_FindGlyph(*s);
    bool vis = g->field_0.marValues[0] >= 0.0f;
    float width = 0.0f;
    if (!(flags & 0x40)) {
        width = -g->field_10.marValues[0];
    }
    while (*++s) {
        width += g->field_18 + pad;
        g = font->UnkInline_FindGlyph(*s);
        vis = vis || g->field_0.marValues[0] >= 0.0f;
    }
    if (vis) {
        if (!(flags & 0x40)) {
            width += g->field_10.marValues[0] + g->field_8.marValues[0];
        } else {
            width += g->field_18;
        }
        GtMathPs2::CGtV2d sc = font->field_8;
        return width * sc.marValues[0];
    }
    return 0.0f;
}
