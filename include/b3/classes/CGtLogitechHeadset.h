// CGtLogitechHeadset -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTLOGITECHHEADSET_H
#define B3_CLASSES_CGTLOGITECHHEADSET_H

class CGtLogitechHeadset;

class CGtLogitechHeadset {
public:
    void BeginDecodeFrame();
    void Destruct();
    int GetNumCodecs();
    int GetStatus();

    unsigned char pad_0[0x10];
    int field_10;
};

#endif
