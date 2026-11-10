// CB3TitleScreenComponent -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TITLESCREENCOMPONENT_H
#define B3_CLASSES_CB3TITLESCREENCOMPONENT_H

class CB3TitleScreenComponent;

class CB3TitleScreenComponent {
public:
    void Construct();

    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
};

#endif
