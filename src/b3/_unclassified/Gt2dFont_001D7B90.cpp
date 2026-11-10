// CGt2dFont::RenderString(const unsigned short*,float,float,float,GtMathPs2::CGtV4d) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dFont.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (RenderString: CGtV2d(field_8) temp, px/py locals).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using namespace GtMathPs2;
// [C] matched by hand (a101): CGtV2d(field_8) copy temp, float px/py locals, origin declared after px.
// 0x001D7B90
void CGt2dFont::RenderString(const unsigned short* s, float x, float y, float size, const CGtV4d colour) const
{
    UnkStruct_Gt2dFont_Glyph* g = UnkInline_FindGlyph(*s);
    CGtV2d scale = CGtV2d(field_8) * size;
    float px = x - g->field_10.marValues[0] * scale.marValues[0];
    const CGtV2d origin(0.0f, 0.0f);
    float py = y;
    for (;;) {
        if (g->field_0.marValues[0] >= 0.0f) {
            CGtV2d corners[2];
            CGtV2d uvs[2];
            corners[0] = CGtV2d(px, py) + g->field_10 * scale;
            uvs[0] = g->field_0;
            corners[1] = corners[0] + scale * g->field_8;
            uvs[1] = g->field_0 + g->field_8;
            Gt2dRenderer::SetTexture(field_4);
            Gt2dRenderer::RenderSpritesTex(colour, origin, 1, corners, uvs);
        }
        unsigned short c = *++s;
        if (c == 0)
            return;
        px += g->field_18 * scale.marValues[0];
        g = UnkInline_FindGlyph(*s);
    }
}
