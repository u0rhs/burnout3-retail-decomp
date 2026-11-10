// CB3ConvexHull -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3CONVEXHULL_H
#define B3_CLASSES_CB3CONVEXHULL_H

class CB3ConvexHull;

class CB3ConvexHull {
public:
    void Fixup();

    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
};

#endif
