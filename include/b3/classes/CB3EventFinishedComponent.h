// CB3EventFinishedComponent -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3EVENTFINISHEDCOMPONENT_H
#define B3_CLASSES_CB3EVENTFINISHEDCOMPONENT_H

class CB3EventFinishedComponent;

class CB3EventFinishedComponent {
public:
    void Construct();

    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
    int field_14;
};

#endif
