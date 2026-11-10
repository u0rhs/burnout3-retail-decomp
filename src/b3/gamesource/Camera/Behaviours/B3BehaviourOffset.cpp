// B3BehaviourOffset.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 0 function(s) named in research/retail_names.csv -> B3BehaviourOffset.cpp, 2 by a medium-confidence name confirmed by a neighbour, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Camera/Behaviours, [L] Revenge (SLUS_212.42) GameSource/Camera/Behaviours/B4BehaviourOffset.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3BehaviourOffset.h"
#include "b3/classes/CB3CameraBehaviour.h"
#include "b3/classes/UnkStruct_D_0055EFEC.h"

struct UnkStruct_002E32E0;
struct UnkStruct_002E32E0_a1;
struct UnkStruct_00395A00_a1;

struct UnkStruct_002E32E0_a1 {
    unsigned char pad_0[0x4];
    float field_4;
};

struct UnkStruct_002E32E0 {
    unsigned char pad_0[0x28];
    int field_28;
    int field_2C;
    int field_30;
};

extern UnkStruct_D_0055EFEC D_0055EFEC;

// CB3BehaviourOffset::Construct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3BehaviourOffset.cpp.
// 0x002E2700
void CB3BehaviourOffset::Construct()
{
    CB3CameraBehaviour::Construct();
}

// CB3BehaviourOffset::Release(void*) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3BehaviourOffset.cpp.
// 0x002E2720
void CB3BehaviourOffset::Release(void* p0)
{
}

// Prepare__18CB3BehaviourOffsetFPv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002E32E0
extern "C" int Prepare__18CB3BehaviourOffsetFPv(UnkStruct_002E32E0 * self, UnkStruct_002E32E0_a1 * p0)
{
    switch (self->field_2C) {
    case 5:
    case 6:
    case 7:
        p0->field_4 = 60.0f;
        break;
    default:
        p0->field_4 = 90.0f;
        break;
    }
    self->field_30 = D_0055EFEC.field_0[self->field_28].field_0->field_204;
    return 1;
}
