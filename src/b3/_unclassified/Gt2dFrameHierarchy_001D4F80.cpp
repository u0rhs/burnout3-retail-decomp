// GtMathPs2::CGtV2d::CGtV2d(float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dFrameHierarchy.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (CGtV2d(float,float) out-of-line).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// 0x001D4F80
extern "C" CGtV2d * __ct__Q29GtMathPs26CGtV2dFff(CGtV2d * self, float x, float y)
{
    self->marValues[0] = x;
    self->marValues[1] = y;
    return self;
}
