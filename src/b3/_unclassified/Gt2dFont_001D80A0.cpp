// CGt2dFont::GetStringWidthIncludingLRKern(const unsigned short*) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dFont.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (seeded Gt2dFont.cpp function as is, 0 off (gt2d, N167)).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using namespace GtMathPs2;

// 0x1D80A0: the advances added up
// 0x001D80A0
float CGt2dFont::GetStringWidthIncludingLRKern(const unsigned short* s) const
{
    float width = UnkInline_FindGlyph(*s)->field_18;
    while (*++s)
        width += UnkInline_FindGlyph(*s)->field_18;
    return width * field_8.marValues[0];
}
