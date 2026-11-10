// CB3PopcornArray -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3POPCORNARRAY_H
#define B3_CLASSES_CB3POPCORNARRAY_H

class CB3PopcornArray;

class CB3PopcornArray {
public:
    void Destruct();
    void Release();
    void Render();

    unsigned char pad_0[0x2C];
    int field_2C;
};

#endif
