// B3BodyPartPhysics.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3BodyPartPhysics.cpp, 2 by a medium-confidence name confirmed by a neighbour.
// Area: src/b3/gamesource/Physics, [L] Revenge (SLUS_212.42) GameSource/Physics/B4BodyPartPhysics.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3BodyPartPhysics.h"
#include "b3/classes/CB3CollidingBody.h"

extern "C" void StopCrashing__16CB3CollidingBodyFv(void *);  // CB3CollidingBody::StopCrashing()
extern "C" void Destruct__16CB3CollidingBodyFv(CB3BodyPartPhysics *);  // CB3CollidingBody::Destruct()
extern "C" void Release__16CB3CollidingBodyFv(void *);  // CB3CollidingBody::Release()

// CB3BodyPartPhysics::StopCrashing() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3BodyPartPhysics.cpp.
// 0x00333140
void CB3BodyPartPhysics::StopCrashing()
{
    field_4D0 = 1;
    StopCrashing__16CB3CollidingBodyFv(this);
}

// CB3BodyPartPhysics::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BodyPartPhysics.cpp.
// 0x00333FC0
void CB3BodyPartPhysics::Destruct()
{
    Destruct__16CB3CollidingBodyFv(this);
}

// CB3BodyPartPhysics::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3BodyPartPhysics.cpp.
// 0x00333FD0
void CB3BodyPartPhysics::Release()
{
    Release__16CB3CollidingBodyFv(this);
    field_2B0 = 0;
    field_2BA = 3;
    field_2B4 = 0;
    field_2BB = 0;
}
