// CB3CrashTrafficSequenceStruct -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3CRASHTRAFFICSEQUENCESTRUCT_H
#define B3_CLASSES_CB3CRASHTRAFFICSEQUENCESTRUCT_H

class CB3CrashTrafficSequenceStruct;
struct UnkStruct_0035EF20_e0;

struct UnkStruct_0035EF20_e0 {
    unsigned char pad_0[0x1];
};

class CB3CrashTrafficSequenceStruct {
public:
    void Fixup(unsigned int p0);

    UnkStruct_0035EF20_e0 * field_0;
};

#endif
