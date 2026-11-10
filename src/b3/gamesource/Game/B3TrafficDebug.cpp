// B3TrafficDebug.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 5 function(s) named in research/retail_names.csv -> B3TrafficDebug.cpp.
// Area: src/b3/gamesource/Game, [L] Revenge (SLUS_212.42) GameSource/Game/B4TrafficDebug.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3TrafficDebug.h"
#include "b3/classes/UnkStruct_D_00527440.h"
#include "b3/classes/UnkStruct_D_0055D7FB.h"

extern UnkStruct_D_00527440 D_00527440;
extern UnkStruct_D_0055D7FB D_0055D7FB;

// CB3TrafficDebug::RenderWorld() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficDebug.cpp.
// 0x002F02C0
void CB3TrafficDebug::RenderWorld()
{
    if (D_00527440.field_0 == 0) {
        return;
    }
    if (field_0 != 0) {
        RenderNearMissData();
    }
    if (field_1 != 0) {
        RenderSpatialTriggers();
    }
}

// CB3TrafficDebug::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficDebug.cpp.
// 0x002F0330
void CB3TrafficDebug::Update()
{
    if (field_4 == 0) {
        D_0055D7FB.field_0 = 0;
    }
}

// CB3TrafficDebug::Prepare() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficDebug.cpp.
// 0x002F0360
void CB3TrafficDebug::Prepare()
{
}

// CB3TrafficDebug::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficDebug.cpp.
// 0x002F0370
void CB3TrafficDebug::Destruct()
{
}

// CB3TrafficDebug::Construct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficDebug.cpp.
// 0x002F0380
void CB3TrafficDebug::Construct()
{
    field_0 = 0;
    field_1 = 0;
    field_2 = 0;
    field_3 = 0;
    field_4 = 1;
}
