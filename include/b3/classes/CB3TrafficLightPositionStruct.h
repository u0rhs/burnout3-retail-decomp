// CB3TrafficLightPositionStruct -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TRAFFICLIGHTPOSITIONSTRUCT_H
#define B3_CLASSES_CB3TRAFFICLIGHTPOSITIONSTRUCT_H

class CB3TrafficLightPositionStruct;
struct UnkStruct_00269E80_e0;
struct UnkStruct_00269E80_e1;
struct UnkStruct_00269E80_e2;
struct UnkStruct_00269E80_e3;

struct UnkStruct_00269E80_e0 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269E80_e1 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269E80_e2 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269E80_e3 {
    unsigned char pad_0[0x1];
};

class CB3TrafficLightPositionStruct {
public:
    void Fixup(unsigned int p0);

    UnkStruct_00269E80_e2 * field_0;
    UnkStruct_00269E80_e3 * field_4;
    UnkStruct_00269E80_e0 * field_8;
    UnkStruct_00269E80_e1 * field_C;
};

#endif
