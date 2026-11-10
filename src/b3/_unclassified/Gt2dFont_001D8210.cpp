// CGt2dFont::Prepare(CGtTexture*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dFont.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (seeded Gt2dFont.cpp function as is, 0 off (gt2d, N167)).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using namespace GtMathPs2;

// 0x1D8210
// 0x001D8210
void CGt2dFont::Prepare(CGtTexture* texture)
{
    field_4 = texture;
    if (!field_18) {
        FixupPointers((unsigned int)this);
        field_18 = 1;
    }
}
