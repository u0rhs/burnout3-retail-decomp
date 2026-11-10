// CB3ConvexHullCollide::CollideHulls(CB3HullCollideParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ConvexHullCollide.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near4: header GetSquaredLength (hdr6 noreorder tail) replaces a234 stand-in; .lit4 D_004E1284 as 0.0009f; exact).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct CB3HullCollideParams {
    unsigned char pad_0[0x60];
    CGtV3d field_60;
    unsigned char pad_70[0xE0];
    CGtV3d field_150;
};
class CB3ConvexHullCollide { public:
static int DoCollideHullToHull(CB3HullCollideParams *p);
static int CollideHulls(CB3HullCollideParams *p);
};
// 0x002B9400
int CB3ConvexHullCollide::CollideHulls(CB3HullCollideParams *p)
{
    CGtV3d d = p->field_60 - p->field_150;
    if (d.GetSquaredLength() < 0.0009f) return 0;
    return DoCollideHullToHull(p) & 255;
}
