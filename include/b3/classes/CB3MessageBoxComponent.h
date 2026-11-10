// CB3MessageBoxComponent -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3MESSAGEBOXCOMPONENT_H
#define B3_CLASSES_CB3MESSAGEBOXCOMPONENT_H

class CB3MessageBoxComponent;

class CB3MessageBoxComponent {
public:
    void Construct();

    unsigned char pad_0[0x80];
    int field_80;
    int field_84;
};

#endif
