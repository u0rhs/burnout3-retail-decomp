// CB3TrafficValve -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3TRAFFICVALVE_H
#define B3_CLASSES_CB3TRAFFICVALVE_H

#include "b3/GtMath.h"

class CB3StartFinishLine;
class CB3TrafficValve;
struct UnkStruct_00266450_1;
struct UnkStruct_002667E0_2;
struct UnkStruct_00267790_e5;

struct UnkStruct_00266450_1 {
    int * field_0;
    int * field_4;
    int field_8;
};

struct UnkStruct_002667E0_2 {
    float field_0;
};

struct UnkStruct_00267790_e5 {
    unsigned char pad_0[0x10];
    int field_10[1];  // [G] element count unknown
    unsigned char pad_14[0x8];
};

class CB3TrafficValve {
public:
    void FillLaneSection(int, int, int, int, CB3StartFinishLine*, int, bool);
    void GenerateInitialTraffic(CB3StartFinishLine* p0, int p1);
    float GetSpeedAfterLaneChange(bool p0, int p1, int p2);
    void Release();
    void ResetCrashmodeData();
    void RolloutCrashTraffic();
    void RolloutCrashTraffic(int);

    UnkStruct_002667E0_2 * field_0[1];  // [G] element count unknown
    unsigned char pad_4[0xC];
    int field_10[1];  // [G] element count unknown
    unsigned char pad_14[0xC];
    int field_20[1];  // [G] element count unknown
    unsigned char pad_24[0xC];
    int field_30[1];  // [G] element count unknown
    unsigned char pad_34[0xC];
    UnkStruct_00266450_1 * field_40;
    unsigned char pad_44[0x48];
    UnkStruct_00267790_e5 field_8C[1];  // [G] element count unknown
    unsigned char pad_A8[0x68];
    unsigned char field_110[1];  // [G] element count unknown
};

#endif
