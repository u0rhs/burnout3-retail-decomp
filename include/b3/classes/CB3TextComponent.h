// CB3TextComponent -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TEXTCOMPONENT_H
#define B3_CLASSES_CB3TEXTCOMPONENT_H

class CB3TextComponent;
class CGt2dObject;

class CB3TextComponent {
public:
    void Release();

    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x26];
    CGt2dObject * field_30;
    CGt2dObject * field_34;
};

#endif
