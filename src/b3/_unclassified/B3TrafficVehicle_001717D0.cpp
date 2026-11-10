// CB3TrafficVehicle::DoTrafficBehaviour(CB3TrafficRaceCarInfo*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficVehicle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near7: header DotProduct (hdr6) replaces both local stand-ins + FAKEMATCH lane pads; two N140 UnkStruct_001717D0_pad slots).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3TrafficRaceCarInfo {                    // [G] 0x70-byte records
public:
    unsigned char pad_0[0x30];
    CGtV3d field_30;
    CGtV3d field_40;
    unsigned char pad_50[0x20];
};
struct UnkStruct_001717D0_114 { unsigned char pad_0[0x28]; int field_28; };
struct UnkStruct_D_00522660 {                    // [G] rows of 0x3F8 bytes from +0x39234
    unsigned char pad_0[0x39234];
    float field_39234[1][0xFE];                  // [G] row count unknown
};
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };   // [G] size: absolute addressing needs > 8 bytes (N50)
extern UnkStruct_D_00522680 D_00522680;

class CB3TrafficVehicle {
public:
    void DoTrafficBehaviour(CB3TrafficRaceCarInfo* pInfo, int n);
    bool ApplyNiceSameWayBehaviour(CB3TrafficRaceCarInfo* pInfo, int i, float f);
    bool ApplyNiceOncomingBehaviour(CB3TrafficRaceCarInfo* pInfo, int i, float f);

    unsigned char pad_0[0x90];
    CGtV3d field_90;
    CGtV3d field_A0;
    unsigned char pad_B0[0x14];
    float field_C4;
    unsigned char pad_C8[0x28];
    float field_F0[8];                           // [G] element count
    unsigned char pad_110[0x4];
    UnkStruct_001717D0_114* field_114;
    unsigned char pad_118[0xC];
    float field_124;
    unsigned char pad_128[0x3C];
    float field_164;
    unsigned char pad_168[0x8];
    signed char field_170;
    unsigned char pad_171;
    signed char field_172;
    unsigned char pad_173[0x4];
    unsigned char field_177;
};

struct UnkStruct_001717D0_pad { int x[4]; UnkStruct_001717D0_pad() {} ~UnkStruct_001717D0_pad() {} };  // [G] N140 frame pad

// 0x001717D0
void CB3TrafficVehicle::DoTrafficBehaviour(CB3TrafficRaceCarInfo* pInfo, int n)
{
    UnkStruct_001717D0_pad pad0;  // [G] N140: retail keeps two more 16-byte slots
    UnkStruct_001717D0_pad pad1;
    bool applied = false;
    float t = D_00522680.field_0;
    for (int i = 0; i < n; i++) {
        field_F0[i] = DotProduct(pInfo[i].field_30 - field_A0, field_90);
    }
    if (field_164 < t) {
        field_114->field_28 = 0;
        field_124 = 1.0f;
        field_164 = t;
        if (!(field_C4 <= 2.0f)) {
            float tSame = 0.4f + t;
            float tOncoming = 0.8f + t;
            for (int j = 0; j < n; j++) {
                float v = D_00522660.field_39234[j][field_177];
                if (!(v < 0.0f) && v < 60.0f) {
                    if (!(DotProduct(field_90, pInfo[j].field_40) <= 0.0f)) {
                        if (ApplyNiceSameWayBehaviour(pInfo, j, v)) {
                            field_164 = tSame;
                            applied = true;
                        }
                    } else {
                        if (ApplyNiceOncomingBehaviour(pInfo, j, v)) {
                            field_164 = tOncoming;
                            applied = true;
                        }
                    }
                }
            }
        }
        if (!applied && field_172 == 1) {
            field_172 = 0;
            field_170 = -1;
        }
    }
}
