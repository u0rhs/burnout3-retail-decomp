// B3TrafficDataStruct.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3TrafficDataStruct.cpp.
// Area: src/b3/SharedClasses/TrafficData, [L] Revenge (SLUS_212.42) SharedClasses/TrafficData/B4TrafficDataStruct.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3TrafficDataStruct.h"
#include "b3/classes/CB3TrafficHullStruct.h"
#include "b3/classes/CB3TrafficLightPositionStruct.h"
#include "b3/classes/CB3TrafficValvePositionStruct.h"
#include "b3/classes/CB3TriggerStruct.h"

struct UnkStruct_00269FA0_e17;
struct UnkStruct_00269FA0_e2;
struct UnkStruct_00269FA0_e4;
struct UnkStruct_00269FA0_e7;

struct UnkStruct_00269FA0_e2 {
    unsigned char pad_0[0x18];
};

struct UnkStruct_00269FA0_e4 {
    unsigned char pad_0[0x10];
};

struct UnkStruct_00269FA0_e7 {
    unsigned char pad_0[0x58];
};

struct UnkStruct_00269FA0_e17 {
    unsigned char pad_0[0x18];
};

extern "C" void Fixup__29CB3TrafficLightPositionStructFUi(void *, unsigned int);  // CB3TrafficLightPositionStruct::Fixup(unsigned int)
extern "C" void Fixup__29CB3TrafficValvePositionStructFUi(void *, unsigned int);  // CB3TrafficValvePositionStruct::Fixup(unsigned int)
extern "C" void Fixup__16CB3TriggerStructFUi(void *, unsigned int);  // CB3TriggerStruct::Fixup(unsigned int)
extern "C" void Fixup__20CB3TrafficHullStructFUi(void *, unsigned int);  // CB3TrafficHullStruct::Fixup(unsigned int)

// CB3TrafficDataStruct::Fixup(unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficDataStruct.cpp.
// 0x00269FA0
void CB3TrafficDataStruct::Fixup(unsigned int p0)
{
    field_2C = (UnkStruct_00269FA0_e0 *)&field_2C[p0];
    field_34 = (UnkStruct_00269FA0_e1 *)&field_34[p0];
    for (int i = 0; (i < field_38); i++) {
        Fixup__29CB3TrafficLightPositionStructFUi(&((UnkStruct_00269FA0_e2 *)field_34)[i], p0);
    }
    field_3C = (UnkStruct_00269FA0_e3 *)&field_3C[p0];
    for (int i1 = 0; (i1 < field_40); i1++) {
        Fixup__29CB3TrafficValvePositionStructFUi(&((UnkStruct_00269FA0_e4 *)field_3C)[i1], p0);
    }
    field_44 = (UnkStruct_00269FA0_e5 *)&field_44[p0];
    field_4C = (UnkStruct_00269FA0_e6 *)&field_4C[p0];
    for (int i2 = 0; (i2 < field_50); i2++) {
        Fixup__16CB3TriggerStructFUi(&((UnkStruct_00269FA0_e7 *)field_4C)[i2], p0);
    }
    field_54 = (UnkStruct_00269FA0_e8 *)&field_54[p0];
    field_60 = (UnkStruct_00269FA0_e9 *)&field_60[p0];
    field_6C = (UnkStruct_00269FA0_e10 *)&field_6C[p0];
    field_78 = (UnkStruct_00269FA0_e11 *)&field_78[p0];
    field_84 = (UnkStruct_00269FA0_e12 *)&field_84[p0];
    field_90 = (UnkStruct_00269FA0_e13 *)&field_90[p0];
    field_AC = (UnkStruct_00269FA0_e14 *)&field_AC[p0];
    field_9C = (UnkStruct_00269FA0_e15 *)&field_9C[p0];
    field_A4 = (UnkStruct_00269FA0_e16 *)&field_A4[p0];
    for (int i3 = 0; (i3 < field_A8); i3++) {
        Fixup__20CB3TrafficHullStructFUi(&((UnkStruct_00269FA0_e17 *)field_A4)[i3], p0);
    }
}
