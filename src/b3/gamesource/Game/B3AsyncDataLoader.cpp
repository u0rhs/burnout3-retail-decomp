// B3AsyncDataLoader.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3AsyncDataLoader.cpp.
// Area: src/b3/gamesource/Game, [L] Revenge (SLUS_212.42) GameSource/Game/B4AsyncDataLoader.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CAsyncLoadManager.h"

struct UnkStruct_0013D410_2;

struct UnkStruct_0013D410_2 {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0xC];
    int field_1C;
    int field_20;
    int field_24;
};

// CAsyncLoadManager::Shutdown() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AsyncDataLoader.cpp.
// 0x0013D410
void CAsyncLoadManager::Shutdown()
{
    UnkStruct_0013D410_1 * t0 = field_780;
    if (t0 == 0) {
        return;
    }
    int r0 = t0->vfunc_24();
    if (r0 == 2) {
        field_780->vfunc_20();
        field_780->vfunc_1C(1);
    }
    int r3 = field_780->vfunc_24();
    if (r3 != 0) {
        field_780->vfunc_C();
        field_780 = 0;
    } else {
        field_780 = 0;
    }
}

// CAsyncLoadManager::Init() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AsyncDataLoader.cpp.
// 0x0013D4D0
void CAsyncLoadManager::Init()
{
    field_780 = 0;
    field_788 = 0;
    field_78C = 0;
    field_790 = 1;
    for (int i = 0; (i < 24); i++) {
        field_0[i].field_0 = 0;
        field_0[i].field_40 = 0;
        field_0[i].field_44 = 0;
        field_0[i].field_48 = 0;
        field_0[i].field_4C = 0;
    }
    field_784 = 0;
    field_785 = 0;
}
