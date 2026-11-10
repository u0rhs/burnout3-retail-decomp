// B3TrafficValve.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 5 function(s) named in research/retail_names.csv -> B3TrafficValve.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4TrafficValve.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3StartFinishLine.h"
#include "b3/classes/CB3TrafficLane.h"
#include "b3/classes/CB3TrafficValve.h"
#include "b3/classes/UnkStruct_D_00522660.h"

struct UnkStruct_00267520_3;
struct UnkStruct_00267520_5;
struct UnkStruct_00267520_6;

struct UnkStruct_00267520_3 {
    int field_0;
    unsigned char pad_4[0x4];
};

struct UnkStruct_00267520_5 {
    UnkStruct_00267520_6 * field_0;
};

struct UnkStruct_00267520_6 {
    unsigned char pad_0[0x10];
    int field_10;
};

extern UnkStruct_D_00522660 D_00522660;
extern "C" int FindNextValve__14CB3TrafficLaneFiPiPi(void *, int, int*, int*);  // CB3TrafficLane::FindNextValve(int,int*,int*)

// CB3TrafficValve::ResetCrashmodeData() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficValve.cpp.
// 0x002662B0
void CB3TrafficValve::ResetCrashmodeData()
{
    for (int i = 0; (i < 4); i++) {
        field_110[i] = 0;
        field_30[i] = 0;
    }
}

// CB3TrafficValve::RolloutCrashTraffic() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficValve.cpp.
// 0x00266450
void CB3TrafficValve::RolloutCrashTraffic()
{
    for (int i = 0; (i < field_40->field_8); i++) {
        RolloutCrashTraffic(i);
    }
}

// CB3TrafficValve::GetSpeedAfterLaneChange(bool,int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficValve.cpp.
// 0x002667E0
float CB3TrafficValve::GetSpeedAfterLaneChange(bool p0, int p1, int p2)
{
    int v0;
    if (p0) {
        v0 = (p2 - p1);
    } else {
        v0 = (p2 + p1);
    }
    return field_0[v0]->field_0;
}

// CB3TrafficValve::GenerateInitialTraffic(CB3StartFinishLine*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficValve.cpp.
// 0x00267520
void CB3TrafficValve::GenerateInitialTraffic(CB3StartFinishLine* p0, int p1)
{
    UnkStruct_00267520_3 local;  // [G] the frame's one local (size: up to the frame top)
    int m0 = 0;
    for (;;) {
        UnkStruct_00266450_1 * t0 = field_40;
        if (m0 >= t0->field_8) {
            break;
        }
        int * t1 = t0->field_0;
        int t2 = t1[m0];
        UnkStruct_00267520_5 * v0;
        if (t2 == 255) {
            v0 = 0;
        } else {
            v0 = (UnkStruct_00267520_5 *)((char *)&D_00522660.field_0[t2] + 0x22C);
        }
        int r0 = FindNextValve__14CB3TrafficLaneFiPiPi(v0, t0->field_4[m0], (int*)((char *)&local + 0x4), (int*)&local);
        if (r0 == 0) {
            local.field_0 = (v0->field_0->field_10 + -1);
        }
        FillLaneSection(m0, field_40->field_4[m0], local.field_0, 0, p0, p1, 0);
        m0 = (m0 + 1);
    }
}

// CB3TrafficValve::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficValve.cpp.
// 0x00267790
void CB3TrafficValve::Release()
{
    for (int i = 0; (i < 4); i++) {
        field_0[i] = 0;
        field_10[i] = 0;
        field_20[i] = 0;
        field_110[i] = 0;
        field_30[i] = 0;
        for (int i1 = 0; (i1 < 7); i1++) {
            field_8C[i].field_10[i1] = 0;
        }
    }
    field_40 = 0;
}
