// GtMathPs2::CGtV4d::operator *(float) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BehaviourFlyAround.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (out-of-line CGtV4d::operator*(float) via extern C wrapper calling header inline).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
// 0x002EC8D0
extern "C" void __ml__Q29GtMathPs26CGtV4dCFf(CGtV4d * r, const CGtV4d * self, float s)
{
    *r = self->operator*(s);
}
