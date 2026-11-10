// CB3TrafficDataStruct -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TRAFFICDATASTRUCT_H
#define B3_CLASSES_CB3TRAFFICDATASTRUCT_H

class CB3TrafficDataStruct;
struct UnkStruct_00269FA0_e0;
struct UnkStruct_00269FA0_e1;
struct UnkStruct_00269FA0_e10;
struct UnkStruct_00269FA0_e11;
struct UnkStruct_00269FA0_e12;
struct UnkStruct_00269FA0_e13;
struct UnkStruct_00269FA0_e14;
struct UnkStruct_00269FA0_e15;
struct UnkStruct_00269FA0_e16;
struct UnkStruct_00269FA0_e3;
struct UnkStruct_00269FA0_e5;
struct UnkStruct_00269FA0_e6;
struct UnkStruct_00269FA0_e8;
struct UnkStruct_00269FA0_e9;

struct UnkStruct_00269FA0_e0 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269FA0_e1 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269FA0_e10 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269FA0_e11 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269FA0_e12 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269FA0_e13 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269FA0_e14 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269FA0_e15 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269FA0_e16 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269FA0_e3 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269FA0_e5 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269FA0_e6 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269FA0_e8 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269FA0_e9 {
    unsigned char pad_0[0x1];
};

class CB3TrafficDataStruct {
public:
    void Fixup(unsigned int p0);

    unsigned char pad_0[0x2C];
    UnkStruct_00269FA0_e0 * field_2C;
    unsigned char pad_30[0x4];
    UnkStruct_00269FA0_e1 * field_34;
    int field_38;
    UnkStruct_00269FA0_e3 * field_3C;
    int field_40;
    UnkStruct_00269FA0_e5 * field_44;
    unsigned char pad_48[0x4];
    UnkStruct_00269FA0_e6 * field_4C;
    int field_50;
    UnkStruct_00269FA0_e8 * field_54;
    unsigned char pad_58[0x8];
    UnkStruct_00269FA0_e9 * field_60;
    unsigned char pad_64[0x8];
    UnkStruct_00269FA0_e10 * field_6C;
    unsigned char pad_70[0x8];
    UnkStruct_00269FA0_e11 * field_78;
    unsigned char pad_7C[0x8];
    UnkStruct_00269FA0_e12 * field_84;
    unsigned char pad_88[0x8];
    UnkStruct_00269FA0_e13 * field_90;
    unsigned char pad_94[0x8];
    UnkStruct_00269FA0_e15 * field_9C;
    unsigned char pad_A0[0x4];
    UnkStruct_00269FA0_e16 * field_A4;
    int field_A8;
    UnkStruct_00269FA0_e14 * field_AC;
};

#endif
