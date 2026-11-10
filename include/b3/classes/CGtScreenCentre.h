// CGtScreenCentre -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTSCREENCENTRE_H
#define B3_CLASSES_CGTSCREENCENTRE_H

class CGtScreenCentre;

class CGtScreenCentre {
public:
    float GetPositionX();
    float GetPositionY();

    float field_0;
    float field_4;
};

#endif
