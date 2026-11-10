// CB3TrailSystem -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TRAILSYSTEM_H
#define B3_CLASSES_CB3TRAILSYSTEM_H

class CB3TrailSystem;

class CB3TrailSystem {
public:
    void Construct();
    void Destruct();
    void Release();

    unsigned char pad_0[0x13A00];
    void * field_13A00;
    unsigned char pad_13A04[0x4];
    int field_13A08;
    unsigned char pad_13A0C[0xC28];
    int field_14634;
    int field_14638;
};

#endif
