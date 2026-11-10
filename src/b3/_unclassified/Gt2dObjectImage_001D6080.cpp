// CGt2dObjectImage::SetUVs(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dObjectImage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (seeded whole-file function as is, 0 off as its own unit (gt2d, N167)).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

#pragma auto_inline on

using namespace GtMathPs2;

extern const CGtV2d D_004B8118;   // 8-byte .rodata constant, (0, 0); name not recovered

// 0x1D6080
// 0x001D6080
void CGt2dObjectImage::SetUVs(const CGtV2d& uv0, const CGtV2d& uv1)
{
    Data().field_0 = uv0;
    Data().field_8 = uv1;
}
