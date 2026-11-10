// CB3DebugMipMaps -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3DEBUGMIPMAPS_H
#define B3_CLASSES_CB3DEBUGMIPMAPS_H

class CB3DebugMipMaps;

class CB3DebugMipMaps {
public:
    void Construct();
    static void Destruct();

    unsigned char pad_0[0x1];
};

#endif
