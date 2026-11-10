// CDrivingControls -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CDRIVINGCONTROLS_H
#define B3_CLASSES_CDRIVINGCONTROLS_H

struct CDrivingControls;

struct CDrivingControls {
    unsigned char field_0;
    unsigned char pad_1[0x7];
    float field_8;
    float field_C;
    float field_10;
    int field_14;
    float field_18;
};

#endif
