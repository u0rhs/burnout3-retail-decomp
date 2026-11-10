// CB3SoundListener -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3SOUNDLISTENER_H
#define B3_CLASSES_CB3SOUNDLISTENER_H

class CB3SoundListener;

class CB3SoundListener {
public:
    void Construct();

    unsigned char pad_0[0x10];
    int field_10;
};

#endif
