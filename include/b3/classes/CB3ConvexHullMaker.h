// CB3ConvexHullMaker -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3CONVEXHULLMAKER_H
#define B3_CLASSES_CB3CONVEXHULLMAKER_H

#include "b3/GtMathPs2.h"

class CB3ConvexHull;
class CB3ConvexHullMaker;
class CB3ConvexHullVertex;

class CB3ConvexHullMaker {
public:
    void GetBasePoints(GtMathPs2::CGtV3d*, float*);
    void MakeConvexHull(CB3ConvexHull* p0, float* p1, CB3ConvexHullVertex* p2);
    void MakeVerticesIntoHull(GtMathPs2::CGtV3d*);

    CB3ConvexHullVertex * field_0;
    CB3ConvexHull * field_4;
};

#endif
