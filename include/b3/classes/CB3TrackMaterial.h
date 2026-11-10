// CB3TrackMaterial -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TRACKMATERIAL_H
#define B3_CLASSES_CB3TRACKMATERIAL_H

class CB3TrackMaterial;
struct UnkStruct_0026A170_e1;

struct UnkStruct_0026A170_e1 {
    unsigned char pad_0[0x1];
};

class CB3TrackMaterial {
public:
    void FixUp();
    int Prepare();

    UnkStruct_0026A170_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_1[0xB];
    void * * field_C;
    unsigned char field_10;
    signed char field_11;
    unsigned char pad_12[0xA];
    int field_1C;
};

#endif
