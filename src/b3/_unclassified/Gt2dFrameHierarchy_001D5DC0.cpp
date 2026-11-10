// CGt2dFrame::CGt2dFrameSpace::SetIdentity() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dFrameHierarchy.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (SetIdentity out-of-line).

#include "b3/GtMathPs2.h"
struct UnkStruct_Gt2dSpace {
    GtMathPs2::CGtV2d field_0;
    GtMathPs2::CGtV2d field_8;
    GtMathPs2::CGtV4d field_10;
};
extern "C" void SetIdentity__Q210CGt2dFrame15CGt2dFrameSpaceFv(UnkStruct_Gt2dSpace * self)
{
    self->field_0.Set(0.0f, 0.0f);
    self->field_8.Set(1.0f, 1.0f);
    self->field_10 = GtMathPs2::CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
}
