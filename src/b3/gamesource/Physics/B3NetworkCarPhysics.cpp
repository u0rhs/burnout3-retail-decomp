// B3NetworkCarPhysics.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3NetworkCarPhysics.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Physics, [L] Revenge (SLUS_212.42) GameSource/Physics/B4NetworkCarPhysics.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3NetworkCarPhysics.h"
#include "b3/classes/CB3RaceCarPhysics.h"

extern "C" void func_001C0E80(CB3NetworkCarPhysics *);

// CB3NetworkCarPhysics::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkCarPhysics.cpp.
// 0x00268950
void CB3NetworkCarPhysics::Destruct()
{
    CB3RaceCarPhysics::Destruct();
}

// CB3NetworkCarPhysics::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3NetworkCarPhysics.cpp.
// 0x00268960
void CB3NetworkCarPhysics::Release()
{
    func_001C0E80(this);
}
