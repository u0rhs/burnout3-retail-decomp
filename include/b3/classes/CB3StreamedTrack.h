// CB3StreamedTrack -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3STREAMEDTRACK_H
#define B3_CLASSES_CB3STREAMEDTRACK_H

class CB3StreamedTrack;
struct UnkStruct_00302610_u;

struct UnkStruct_00302610_u {
    unsigned char pad_0[0x4];
    int field_4;
};

class CB3StreamedTrack {
public:
    int GetUnitOriginalID(int p0);

    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x14];
    int field_24;
    unsigned char pad_28[0x4];
    int field_2C;
    unsigned char pad_30[0x14C];
    UnkStruct_00302610_u * field_17C[1];
};

#endif
