// CGt2dFont::GetStringWidth(const unsigned short*) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dFont.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (seeded Gt2dFont.cpp function as is, 0 off (gt2d, N167)).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using namespace GtMathPs2;

// 0x1D8150: from the first glyph's left edge to the last glyph's right edge
// 0x001D8150
float CGt2dFont::GetStringWidth(const unsigned short* s) const
{
    UnkStruct_Gt2dFont_Glyph* g = UnkInline_FindGlyph(*s);
    float width = -g->field_10.marValues[0];
    while (*++s) {
        width += g->field_18;
        g = UnkInline_FindGlyph(*s);
    }
    width += g->field_10.marValues[0] + g->field_8.marValues[0];
    return width * field_8.marValues[0];
}
