// CB3TrafficVehicle::ApplyNiceSameWayBehaviour(CB3TrafficRaceCarInfo*,int,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficVehicle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (v277: hand-written from the asm; header DotProduct/operator-; scoped opt_repositioncode off [G] (N182) keeps retail's source-order blocks).

// CB3TrafficVehicle::ApplyNiceSameWayBehaviour(CB3TrafficRaceCarInfo*,int,float).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficVehicle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Fields are placeholders, types [G] (instruction widths).

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"

using GtMathPs2::CGtV3d;

class CB3TrafficRaceCarInfo {                    // [G] 0x70-byte records (as DoTrafficBehaviour)
public:
    unsigned char pad_0[0x30];
    CGtV3d field_30;
    unsigned char pad_40[0x29];
    unsigned char field_69;
    unsigned char pad_6A[0x6];
};

struct UnkStruct_001714A0_2 {
    unsigned char pad_0[0x28];
    float field_28;
    unsigned char pad_2C[0x1D];
    unsigned char field_49;
};

// [C] 0x50-byte lane records at D_00522660+0x34210: a direction at +0, a position at +0x30.
struct UnkStruct_001714A0_e1 {
    CGtV3d field_0;
    unsigned char pad_10[0x20];
    CGtV3d field_30;
    unsigned char pad_40[0x10];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x34210];
    UnkStruct_001714A0_e1 field_34210[1];  // [G] element count unknown
};

class CB3TrafficVehicle {
public:
    int ApplyNiceSameWayBehaviour(CB3TrafficRaceCarInfo *p0, int p1, float p2);

    unsigned char pad_0[0xF0];
    float field_F0[1];  // [G] element count unknown
    unsigned char pad_F4[0x20];
    UnkStruct_001714A0_2 *field_114;
    unsigned char pad_118[0xC];
    float field_124;
    unsigned char pad_128[0x1C];
    int field_144;
    unsigned char pad_148[0x28];
    unsigned char field_170;
    unsigned char pad_171[0x1];
    signed char field_172;
    unsigned char pad_173[0x5];
    unsigned char field_178;
    unsigned char field_179;
};

extern UnkStruct_D_00522660 D_00522660;
extern unsigned char _gu8NextFlashPattern;

// N182: [G] scoped to this function -- retail keeps the blocks in source order.
#pragma push
#pragma opt_repositioncode off
// 0x001714A0
int CB3TrafficVehicle::ApplyNiceSameWayBehaviour(CB3TrafficRaceCarInfo *p0, int p1, float p2)
{
    UnkStruct_001714A0_e1 *lane = &D_00522660.field_34210[field_114->field_49];
    if (p0[p1].field_69 != 0) {
        if (p2 < 40.0f) {
            if (field_F0[p1] > 0.0f && !(p2 < 25.0f))
                return 0;
            float d = GtMathPs2::DotProduct(p0[p1].field_30 - lane->field_30, lane->field_0);
            if (d > -10.0f && d < 10.0f) {
                field_124 = GtMath::Max(3.0f, field_124);
                if (d > 0.0f)
                    field_114->field_28 = field_114->field_28 + 1.5f;
                else
                    field_114->field_28 = field_114->field_28 - 1.5f;
                return 1;
            }
        }
    } else {
        if (p2 < 25.0f && field_F0[p1] < 0.0f && !(p2 < 10.0f))
            return 0;
        float d = GtMathPs2::DotProduct(p0[p1].field_30 - lane->field_30, lane->field_0);
        if ((d > -6.0f && d < -1.0f) || (d > 1.0f && d < 6.0f)) {
            field_124 = GtMath::Max(2.0f, field_124);
            if (d > 0.0f)
                field_114->field_28 = field_114->field_28 + 1.0f;
            else
                field_114->field_28 = field_114->field_28 - 1.0f;
            if (field_F0[p1] > 10.0f) {
                if (field_172 == 0) {
                    field_172 = 2;
                    field_178 = _gu8NextFlashPattern;
                    _gu8NextFlashPattern = (_gu8NextFlashPattern + 1) % 5;
                    field_144 = 0;
                    field_179 = 0;
                }
                field_170 = p1;
            }
            return 1;
        }
    }
    return 0;
}

#pragma pop
