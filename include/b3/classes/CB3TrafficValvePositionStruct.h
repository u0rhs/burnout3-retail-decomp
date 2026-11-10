// CB3TrafficValvePositionStruct -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TRAFFICVALVEPOSITIONSTRUCT_H
#define B3_CLASSES_CB3TRAFFICVALVEPOSITIONSTRUCT_H

class CB3TrafficValvePositionStruct;
struct UnkStruct_00269EF0_e0;
struct UnkStruct_00269EF0_e1;

struct UnkStruct_00269EF0_e0 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269EF0_e1 {
    unsigned char pad_0[0x1];
};

class CB3TrafficValvePositionStruct {
public:
    void Fixup(unsigned int p0);

    UnkStruct_00269EF0_e0 * field_0;
    UnkStruct_00269EF0_e1 * field_4;
};

#endif
