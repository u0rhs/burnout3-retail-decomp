// CB3TrafficHullStruct -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TRAFFICHULLSTRUCT_H
#define B3_CLASSES_CB3TRAFFICHULLSTRUCT_H

class CB3TrafficHullStruct;
struct UnkStruct_0032EDD0_e0;
struct UnkStruct_0032EDD0_e1;
struct UnkStruct_0032EDD0_e2;

struct UnkStruct_0032EDD0_e0 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_0032EDD0_e1 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_0032EDD0_e2 {
    unsigned char pad_0[0x1];
};

class CB3TrafficHullStruct {
public:
    void Fixup(unsigned int p0);

    UnkStruct_0032EDD0_e0 * field_0;
    unsigned char pad_4[0x8];
    UnkStruct_0032EDD0_e1 * field_C;
    UnkStruct_0032EDD0_e2 * field_10;
};

#endif
