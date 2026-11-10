// CB3ConvexHull::MakeFromBoundingBox(GtMathPs2::CGtV3d,GtMathPs2::CGtV3d,EB3HullShape) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ConvexHull.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (locals a,b + hoisted pa/pb const void* args to extern C by-value callees).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
enum EB3HullShape { EB3HullShape_Box, EB3HullShape_Cone, EB3HullShape_Boat };
class CB3ConvexHull {
public:
    void MakeFromBoundingBox(CGtV3d, CGtV3d, EB3HullShape);
};
extern "C" void MakeBoxFromBoundingBox__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(CB3ConvexHull *, const void *, const void *);
extern "C" void MakeConeFromBoundingBox__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(CB3ConvexHull *, const void *, const void *);
extern "C" void MakeBoatFromBoundingBox__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(CB3ConvexHull *, const void *, const void *);
// 0x002BA3A0
// [G] callees take by-value CGtV3d: retail copies both once into locals and passes their addresses (const void * extern "C" link names); pa/pb hoisted before the switch
void CB3ConvexHull::MakeFromBoundingBox(CGtV3d p0, CGtV3d p1, EB3HullShape p2)
{
    CGtV3d a;
    CGtV3d b;
    const void *pa = &a;
    const void *pb = &b;
    a = p0;
    b = p1;
    switch (p2) {
    case 0: MakeBoxFromBoundingBox__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(this, pa, pb); break;
    case 1: MakeConeFromBoundingBox__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(this, pa, pb); break;
    case 2: MakeBoatFromBoundingBox__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(this, pa, pb); break;
    }
}
