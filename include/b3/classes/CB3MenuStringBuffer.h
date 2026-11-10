// CB3MenuStringBuffer -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3MENUSTRINGBUFFER_H
#define B3_CLASSES_CB3MENUSTRINGBUFFER_H

class CB3MenuStringBuffer;

class CB3MenuStringBuffer {
public:
    int Prepare();

    unsigned char pad_0[0x1800];
    void * field_1800;
};

#endif
