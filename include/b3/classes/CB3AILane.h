// CB3AILane -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3AILANE_H
#define B3_CLASSES_CB3AILANE_H

class CB3AILane;
struct CB3AILaneStruct;
struct UnkStruct_00146180_1;
struct UnkStruct_00146180_e0;
struct UnkStruct_00148D60_seg;

struct UnkStruct_00146180_1 {
    unsigned char pad_0[0x4];
    UnkStruct_00146180_e0 * field_4;
    UnkStruct_00148D60_seg * field_8;
    unsigned short field_C;
    unsigned char field_E;
};

struct UnkStruct_00146180_e0 {
    float field_0;
    unsigned char pad_4[0x4];
};

struct UnkStruct_00148D60_seg {
    unsigned char pad_0[0x3];
    unsigned char field_3;
    unsigned char pad_4[0x6];
};

class CB3AILane {
public:
    float GetSegmentLengthFast(unsigned short p0) const;
    bool LaneIsDriveable(unsigned short, unsigned short);
    int SegmentAIsInfrontOfSegmentB(unsigned short p0, unsigned short p1) const;
    static bool LaneIsDriveable(const CB3AILaneStruct *, unsigned short, unsigned short);
    static bool LaneIsDriveable(unsigned char p0, unsigned short p1, unsigned short p2);

    unsigned char pad_0[0x4];
    UnkStruct_00146180_1 * field_4;
};

#endif
