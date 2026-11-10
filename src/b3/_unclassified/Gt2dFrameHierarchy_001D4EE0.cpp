// GtMathPs2::CGtV2d::operator +(const GtMathPs2::CGtV2d&) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dFrameHierarchy.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (CGtV2d::operator+ out-of-line copy).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// 0x001D4EE0
extern "C" CGtV2d __pl__Q29GtMathPs26CGtV2dCFRCQ29GtMathPs26CGtV2d(const CGtV2d * self, const CGtV2d * o)
{
    return self->operator+(*o);
}
