// B3PropPhysics.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3PropPhysics.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Physics, [L] Revenge (SLUS_212.42) GameSource/Physics/B4PropPhysics.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3CollidingBody.h"
#include "b3/classes/CB3PropPhysics.h"

extern "C" void Destruct__16CB3CollidingBodyFv(CB3PropPhysics *);  // CB3CollidingBody::Destruct()
extern "C" void Release__16CB3CollidingBodyFv(void *);  // CB3CollidingBody::Release()

// CB3PropPhysics::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PropPhysics.cpp.
// 0x001BE210
void CB3PropPhysics::Destruct()
{
    Destruct__16CB3CollidingBodyFv(this);
}

// CB3PropPhysics::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3PropPhysics.cpp.
// 0x001BE220
void CB3PropPhysics::Release()
{
    Release__16CB3CollidingBodyFv(this);
    field_220 = 0;
    field_224 = -1.0f;
}
