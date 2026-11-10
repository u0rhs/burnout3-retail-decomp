// CB3AIAvoidanceMap -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3AIAVOIDANCEMAP_H
#define B3_CLASSES_CB3AIAVOIDANCEMAP_H

class CB3AIAvoidanceMap;

class CB3AIAvoidanceMap {
public:
    int GetSafestChannel();

    unsigned char pad_0[0x13D];
    unsigned char field_13D[1];  // [G] element count unknown
    unsigned char pad_13E[0x1];
    unsigned char field_13F[1];  // [G] element count unknown
    unsigned char field_140[1];  // [G] element count unknown
    unsigned char field_141[1];  // [G] element count unknown
    unsigned char pad_142[0x1];
    unsigned char field_143[1];  // [G] element count unknown
    unsigned char pad_144[0x300];
    float field_444;
    unsigned char pad_448[0x4];
    float field_44C;
};

#endif
