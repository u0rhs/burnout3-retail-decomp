// CGtSoundListener -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTSOUNDLISTENER_H
#define B3_CLASSES_CGTSOUNDLISTENER_H

class CGtSoundListener;

class CGtSoundListener {
public:
    void Construct();
    void Destruct();
    int GetRWAListener();
    void Release();

    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
};

#endif
