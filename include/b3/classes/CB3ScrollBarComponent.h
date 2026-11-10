// CB3ScrollBarComponent -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SCROLLBARCOMPONENT_H
#define B3_CLASSES_CB3SCROLLBARCOMPONENT_H

class CB3ScrollBarComponent;

class CB3ScrollBarComponent {
public:
    void Release();

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x6];
    int field_10;
    int field_14;
    int field_18;
};

#endif
