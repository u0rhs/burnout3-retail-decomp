// CB3AITargetSpline -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3AITARGETSPLINE_H
#define B3_CLASSES_CB3AITARGETSPLINE_H

class CB3AITargetSpline;

class CB3AITargetSpline {
public:
    unsigned char IsSquareCorner();

    unsigned char pad_0[0x151];
    unsigned char field_151;
};

#endif
