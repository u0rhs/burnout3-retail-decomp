// B3TriggerStruct.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3TriggerStruct.cpp.
// Area: src/b3/SharedClasses/TrafficData, [L] Revenge (SLUS_212.42) SharedClasses/TrafficData/B4TriggerStruct.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3CrashTrafficSequenceStruct.h"
#include "b3/classes/CB3FormationBehaviourStruct.h"
#include "b3/classes/CB3TriggerStruct.h"

struct UnkStruct_00269D20_e12;
struct UnkStruct_00269D20_e16;

struct UnkStruct_00269D20_e12 {
    unsigned char pad_0[0x14];
};

struct UnkStruct_00269D20_e16 {
    unsigned char pad_0[0xC];
};

extern "C" void Fixup__27CB3FormationBehaviourStructFUi(void *, unsigned int);  // CB3FormationBehaviourStruct::Fixup(unsigned int)
extern "C" void Fixup__29CB3CrashTrafficSequenceStructFUi(void *, unsigned int);  // CB3CrashTrafficSequenceStruct::Fixup(unsigned int)

// CB3TriggerStruct::Fixup(unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TriggerStruct.cpp.
// 0x00269D20
void CB3TriggerStruct::Fixup(unsigned int p0)
{
    field_0 = (UnkStruct_00269D20_e0 *)&field_0[p0];
    field_34 = (UnkStruct_00269D20_e1 *)&field_34[p0];
    field_14 = (UnkStruct_00269D20_e2 *)&field_14[p0];
    field_18 = (UnkStruct_00269D20_e3 *)&field_18[p0];
    field_20 = (UnkStruct_00269D20_e4 *)&field_20[p0];
    field_24 = (UnkStruct_00269D20_e5 *)&field_24[p0];
    field_8 = (UnkStruct_00269D20_e6 *)&field_8[p0];
    field_C = (UnkStruct_00269D20_e7 *)&field_C[p0];
    field_2C = (UnkStruct_00269D20_e8 *)&field_2C[p0];
    field_30 = (UnkStruct_00269D20_e9 *)&field_30[p0];
    field_10 = (UnkStruct_00269D20_e10 *)&field_10[p0];
    field_1C = (UnkStruct_00269D20_e11 *)&field_1C[p0];
    for (int i = 0; (i < field_48); i++) {
        Fixup__27CB3FormationBehaviourStructFUi(&((UnkStruct_00269D20_e12 *)field_1C)[i], p0);
    }
    field_4 = (UnkStruct_00269D20_e13 *)&field_4[p0];
    field_28 = (UnkStruct_00269D20_e14 *)&field_28[p0];
    field_38 = (UnkStruct_00269D20_e15 *)&field_38[p0];
    for (int i1 = 0; (i1 < field_3C); i1++) {
        Fixup__29CB3CrashTrafficSequenceStructFUi(&((UnkStruct_00269D20_e16 *)field_38)[i1], p0);
    }
}
