// CB3TrafficAxle::InitalisePosition(CB3TrafficVehicle*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficAxle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3TrafficVehicle;
class CB3TrafficLane;

class CB3TrafficAxle;
struct CB3TrafficVehicle;
struct UnkStruct_0015F940_1;
struct UnkStruct_0015F940_3;
struct UnkStruct_0015F940_4;
struct UnkStruct_0015F940_5;
struct UnkStruct_0015F940_e0;
struct UnkStruct_D_00522660;

struct CB3TrafficVehicle {
    unsigned char pad_0[0x10C];
    UnkStruct_0015F940_3 * field_10C;
    unsigned char pad_110[0x4];
    UnkStruct_0015F940_1 * field_114;
    unsigned char pad_118[0x8];
    float field_120;
    unsigned char pad_124[0x53];
    unsigned char field_177;
};

struct UnkStruct_0015F940_1 {
    unsigned char pad_0[0x41];
    unsigned char field_41;
};

struct UnkStruct_0015F940_3 {
    unsigned char pad_0[0x5E];
    unsigned char field_5E;
};

struct UnkStruct_0015F940_4 {
    UnkStruct_0015F940_5 * field_0;
};

struct UnkStruct_0015F940_5 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_0015F940_e0 {
    unsigned char pad_0[0x4C];
};

struct UnkStruct_D_00522660 {
    UnkStruct_0015F940_e0 field_0[1];  // [G] element count unknown
};

class CB3TrafficAxle {
public:
    void InitalisePosition(CB3TrafficVehicle* p0);
    void AdjustAxleHeight(CB3TrafficLane*, int);

    GtMathPs2::CGtV4d field_0;
    unsigned char pad_10[0x18];
    int field_28;
    short field_2C;
    unsigned char field_2E;
    unsigned char field_2F;
};

extern UnkStruct_D_00522660 D_00522660;

// 0x0015F940
void CB3TrafficAxle::InitalisePosition(CB3TrafficVehicle* p0)
{
    UnkStruct_0015F940_3 * t0 = p0->field_10C;
    if (t0 != 0) {
        field_2E = t0->field_5E;
    } else {
        field_2E = p0->field_114->field_41;
    }
    field_2F = p0->field_177;
    field_0.SetW(p0->field_120);
    unsigned char t1 = field_2E;
    UnkStruct_0015F940_4 * v1;
    if (t1 == 255) {
        v1 = 0;
    } else {
        v1 = (UnkStruct_0015F940_4 *)((char *)&D_00522660.field_0[t1] + 0x22C);
    }
    field_28 = v1->field_0->field_C;
    field_2C = -1;
    AdjustAxleHeight(0, -1);
}
