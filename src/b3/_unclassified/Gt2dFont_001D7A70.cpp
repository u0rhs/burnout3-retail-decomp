// CGt2dFont::MakeNumberCharactersFixedWidth() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dFont.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (seeded Gt2dFont.cpp function as is (a95 0 off), installed by gt2d (N167)).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using namespace GtMathPs2;

// 0x1D7A70: give '0'-'9' the widest digit's advance, each centred in it (counters do not jiggle)
// 0x001D7A70
void CGt2dFont::MakeNumberCharactersFixedWidth()
{
    float widest = -3.4028235e+38f;
    for (unsigned short c = '0'; c <= '9'; c++) {
        UnkStruct_Gt2dFont_Glyph* g = UnkInline_FindGlyph(c);
        if (g->field_1c == c && widest < g->field_18)
            widest = g->field_18;
    }
    if (widest < 0.0f)
        return;
    for (unsigned short d = '0'; d <= '9'; d++) {
        UnkStruct_Gt2dFont_Glyph* h = UnkInline_FindGlyph(d);
        if (h->field_1c == d) {
            h->field_10.marValues[0] += (widest - h->field_18) * 0.5f;
            h->field_18 = widest;
        }
    }
}
