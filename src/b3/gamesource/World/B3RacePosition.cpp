// B3RacePosition.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 5 function(s) named in research/retail_names.csv -> B3RacePosition.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4RacePosition.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3RacePosition.h"
#include "b3/classes/UnkStruct_D_0051BA88.h"
#include "b3/classes/UnkStruct_D_0064ED5C.h"

extern UnkStruct_D_0064ED5C D_0064ED5C;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern "C" bool IsAheadOf__8CB3ScoreFP8CB3Score(void *, void *);

// CB3RacePosition::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RacePosition.cpp.
// 0x00154750
void CB3RacePosition::Destruct()
{
}

// CB3RacePosition::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RacePosition.cpp.
// 0x00154760
void CB3RacePosition::Release()
{
}

// Hand-written; the lifter refused it (qsort-style comparator (const void*, const void*): const-pointee loads schedule above sd ra (sdra rule 1)).
// 0x001549F0
extern "C" int func_001549F0(const void *a, const void *b) { bool r = IsAheadOf__8CB3ScoreFP8CB3Score(*(char **)a + 0x10C0, *(char **)b + 0x10C0); return r ? -1 : 1; }

// CB3RacePosition::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RacePosition.cpp.
// 0x00154A30
int CB3RacePosition::Prepare()
{
    field_18 = 0;
    field_1C = D_0064ED5C.field_0;
    for (int i = 0; (i < 6); i++) {
        field_0[i] = 1;
    }
    int r0 = D_0051BA88.field_0->field_1B4->vfunc_34();
    field_20 = r0;
    return 1;
}

// CB3RacePosition::Construct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RacePosition.cpp.
// 0x00154AB0
void CB3RacePosition::Construct()
{
}
