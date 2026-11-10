// B3TrafficLaneStruct.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3TrafficLaneStruct.cpp.
// Area: src/b3/SharedClasses/TrafficData, [L] Revenge (SLUS_212.42) SharedClasses/TrafficData/B4TrafficLaneStruct.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3TrafficLanesStruct.h"

struct UnkStruct_00269F10_e0;
struct UnkStruct_00269F10_e3;
struct UnkStruct_00269F10_e4;
struct UnkStruct_00269F10_e5;

struct UnkStruct_00269F10_e0 {
    UnkStruct_00269F10_e3 * field_0;
    UnkStruct_00269F10_e4 * field_4;
    UnkStruct_00269F10_e5 * field_8;
    int field_C;
    unsigned char pad_10[0x4];
};

struct UnkStruct_00269F10_e3 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269F10_e4 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_00269F10_e5 {
    unsigned char pad_0[0x1];
};

// CB3TrafficLanesStruct::Fixup(unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficLaneStruct.cpp.
// 0x00269F10
void CB3TrafficLanesStruct::Fixup(unsigned int p0)
{
    field_0 = (UnkStruct_00269F10_e1 *)&field_0[p0];
    field_4 = (UnkStruct_00269F10_e2 *)&field_4[p0];
    for (int i = 0; (i < field_8); i++) {
        UnkStruct_00269F10_e0 * t0 = (UnkStruct_00269F10_e0 *)field_0;
        t0[i].field_0 = (UnkStruct_00269F10_e3 *)&t0[i].field_0[p0];
        t0[i].field_4 = (UnkStruct_00269F10_e4 *)&t0[i].field_4[p0];
        t0[i].field_8 = (UnkStruct_00269F10_e5 *)&t0[i].field_8[p0];
        ((UnkStruct_00269F10_e0 *)field_0)[i].field_C = (int)field_4;
    }
}
