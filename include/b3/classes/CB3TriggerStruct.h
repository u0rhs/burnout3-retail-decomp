// CB3TriggerStruct -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TRIGGERSTRUCT_H
#define B3_CLASSES_CB3TRIGGERSTRUCT_H

class CB3TriggerStruct;
struct UnkStruct_00269D20_e0;
struct UnkStruct_00269D20_e1;
struct UnkStruct_00269D20_e10;
struct UnkStruct_00269D20_e11;
struct UnkStruct_00269D20_e13;
struct UnkStruct_00269D20_e14;
struct UnkStruct_00269D20_e15;
struct UnkStruct_00269D20_e2;
struct UnkStruct_00269D20_e3;
struct UnkStruct_00269D20_e4;
struct UnkStruct_00269D20_e5;
struct UnkStruct_00269D20_e6;
struct UnkStruct_00269D20_e7;
struct UnkStruct_00269D20_e8;
struct UnkStruct_00269D20_e9;

struct UnkStruct_00269D20_e0 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269D20_e1 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269D20_e10 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269D20_e11 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269D20_e13 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269D20_e14 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269D20_e15 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269D20_e2 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269D20_e3 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269D20_e4 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269D20_e5 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269D20_e6 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269D20_e7 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269D20_e8 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269D20_e9 {
    unsigned char pad_0[0x1];
};

class CB3TriggerStruct {
public:
    void Fixup(unsigned int p0);

    UnkStruct_00269D20_e0 * field_0;
    UnkStruct_00269D20_e13 * field_4;
    UnkStruct_00269D20_e6 * field_8;
    UnkStruct_00269D20_e7 * field_C;
    UnkStruct_00269D20_e10 * field_10;
    UnkStruct_00269D20_e2 * field_14;
    UnkStruct_00269D20_e3 * field_18;
    UnkStruct_00269D20_e11 * field_1C;
    UnkStruct_00269D20_e4 * field_20;
    UnkStruct_00269D20_e5 * field_24;
    UnkStruct_00269D20_e14 * field_28;
    UnkStruct_00269D20_e8 * field_2C;
    UnkStruct_00269D20_e9 * field_30;
    UnkStruct_00269D20_e1 * field_34;
    UnkStruct_00269D20_e15 * field_38;
    int field_3C;
    unsigned char pad_40[0x8];
    int field_48;
};

#endif
