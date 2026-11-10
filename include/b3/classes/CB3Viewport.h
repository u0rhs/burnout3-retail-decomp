// CB3Viewport -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3VIEWPORT_H
#define B3_CLASSES_CB3VIEWPORT_H

class CB3Viewport;

class CB3Viewport {
public:
    void Construct(int p0, int p1, int p2);
    void Update();

    unsigned char pad_0[0x48];
    float field_48;
    unsigned char pad_4C[0x44];
    float field_90;
};

#endif
