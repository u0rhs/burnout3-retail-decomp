// CB3TrafficAxle::AdjustAxleHeight(CB3TrafficLane*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficAxle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (b2src: hand-written from asm, shape cross-checked vs Burnout 2 CTrafficAxle::AdjustAxleHeight (b3dllc/burnout2@61e466e); returns int (sibling InitalisePosition declares it void)).

// Hand-written from the retail asm (the lifter refused it: label in an if body reached from outside).
// Shape cross-checked against Burnout 2's CTrafficAxle::AdjustAxleHeight (github.com/b3dllc/burnout2 @
// 61e466e295e34abf3de7816c220e4b09ba95022d, src/gamesource/Race/CTrafficAxle.cpp): current segment, next segment, then a
// backwards search of up to 10 segments from the vehicle's cab/param position. Burnout 3 drops B2's merge-lane tries
// (both parameters unused) and IntersectLineSegment reads node indices stored in the axle. No Burnout 2 name is used for
// any Burnout 3 symbol or field (provenance rule). [C] returns int (v0 = 1/0); [C] `found` is bool (daddiu s2,zero,1).
#include "b3/GtMathPs2.h"

class CB3TrafficLane;
struct UnkStruct_0015F650_seg { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_0015F650_blk {
    UnkStruct_0015F650_seg * field_0;
    unsigned char pad_4[0xC];
    int field_10;
};
struct UnkStruct_0015F650_lane {
    UnkStruct_0015F650_blk * field_0;
    unsigned char pad_4[0x43];
    unsigned char field_47;
    unsigned char pad_48[0x4];
};
struct UnkStruct_0015F650_cab {
    unsigned char pad_0[0x5C];
    short field_5C;
    unsigned char field_5E;
};
struct UnkStruct_0015F650_prm {
    unsigned char pad_0[0x30];
    float field_30;
    unsigned char pad_34[0xD];
    unsigned char field_41;
};
struct UnkStruct_0015F650_veh {
    unsigned char pad_0[0x80];
    GtMathPs2::CGtV4d field_80;
    unsigned char pad_90[0x7C];
    UnkStruct_0015F650_cab * field_10C;
    unsigned char pad_110[0x4];
    UnkStruct_0015F650_prm * field_114;
    unsigned char pad_118[0x68];
};
struct UnkStruct_D_00522660_aah { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00522660_aah D_00522660;

class CB3TrafficAxle {
public:
    int AdjustAxleHeight(CB3TrafficLane *, int);
    int IntersectLineSegment();
    GtMathPs2::CGtV4d field_0;
    GtMathPs2::CGtV4d field_10;
    unsigned short field_20;
    unsigned short field_22;
    unsigned short field_24;
    unsigned short field_26;
    int field_28;
    short field_2C;
    unsigned char field_2E;
    unsigned char field_2F;
};

// [G] inlined lane lookup by index (0xFF = none); no name in our tables
static inline UnkStruct_0015F650_lane * func_0015F650_inl1(unsigned char i)
{
    if (i == 0xFF) {
        return 0;
    }
    return (UnkStruct_0015F650_lane *)((char *)&D_00522660 + i * 76 + 0x22C);
}
// [G] inlined vehicle lookup by index (0xFF = none); no name in our tables
static inline UnkStruct_0015F650_veh * func_0015F650_inl2(unsigned char i)
{
    if (i == 0xFF) {
        return 0;
    }
    return (UnkStruct_0015F650_veh *)((char *)&D_00522660 + i * 384 + 0x175B0);
}

// 0x0015F650
int CB3TrafficAxle::AdjustAxleHeight(CB3TrafficLane * p0, int p1)
{
    if (field_2E != 0xFF) {
        UnkStruct_0015F650_lane * lane = func_0015F650_inl1(field_2E);
        if (field_2C >= 0) {
            if (IntersectLineSegment()) {
                return 1;
            }
            if (field_2C < lane->field_0->field_10 - 2) {
                field_2C = field_2C + 1;
                field_20 = field_24;
                field_22 = field_26;
                field_24 = lane->field_0->field_0[field_2C + 1].field_0;
                field_26 = lane->field_0->field_0[field_2C + 1].field_2;
                if (IntersectLineSegment()) {
                    return 1;
                }
            }
            field_2C = -1;
        } else {
            UnkStruct_0015F650_veh * veh = func_0015F650_inl2(field_2F);
            UnkStruct_0015F650_lane * l2;
            int seg;
            UnkStruct_0015F650_cab * cab = veh->field_10C;
            if (cab != 0) {
                seg = cab->field_5C;
                l2 = func_0015F650_inl1(cab->field_5E);
            } else {
                seg = (int)veh->field_114->field_30;
                l2 = func_0015F650_inl1(veh->field_114->field_41);
            }
            field_10 = veh->field_80;
            int min = seg - 10;
            bool found = false;
            field_20 = l2->field_0->field_0[seg + 1].field_0;
            field_22 = l2->field_0->field_0[seg + 1].field_2;
            while (seg >= 0 && seg >= min) {
                field_24 = field_20;
                field_26 = field_22;
                field_20 = l2->field_0->field_0[seg].field_0;
                field_22 = l2->field_0->field_0[seg].field_2;
                if (IntersectLineSegment()) {
                    found = true;
                    break;
                }
                seg--;
            }
            if (found) {
                field_2E = l2->field_47;
                field_2C = seg;
                return 1;
            }
            field_2C = -1;
        }
    }
    return 0;
}
