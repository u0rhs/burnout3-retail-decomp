// CB3ConvexHullProp -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3CONVEXHULLPROP_H
#define B3_CLASSES_CB3CONVEXHULLPROP_H

class CB3ConvexHullProp;

class CB3ConvexHullProp {
public:
    void Initialise();

    void * field_0;
    void * field_4;
    void * field_8;
    void * field_C;
    void * field_10;
};

#endif
