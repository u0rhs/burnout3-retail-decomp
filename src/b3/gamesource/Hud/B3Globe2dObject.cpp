// B3Globe2dObject.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3Globe2dObject.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Hud, same unit as the hand-placed file there (its docs/layout.md row).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3Globe2dObject.h"
#include "b3/classes/UnkStruct_theMemMgr.h"

extern UnkStruct_theMemMgr theMemMgr;
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);

// Release__16CB3Globe2dObjectFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003B5420
extern "C" void Release__16CB3Globe2dObjectFv(void *a0 /* passed by every caller, not read here */)
{
    if (CB3Globe2dObject::gmpStaticGlobeData == 0) return;
    ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 19, 0);
    CB3Globe2dObject::gmpStaticGlobeData = 0;
}

// CB3Globe2dObject::SetShape(float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Globe2dObject.cpp.
// 0x003B5460
void CB3Globe2dObject::SetShape(float p0, float p1)
{
    field_30 = ((int)(((float)65535) * p0));
    field_32 = ((int)(((float)65535) * p1));
}

// CB3Globe2dObject::SetHighlight(signed char,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Globe2dObject.cpp.
// 0x003B54A0
void CB3Globe2dObject::SetHighlight(signed char p0, float p1)
{
    field_37 = p0;
    field_36 = ((int)(255.0f * p1));
}

// CB3Globe2dObject::SetGlobeLocation(float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Globe2dObject.cpp.
// 0x003B5510
void CB3Globe2dObject::SetGlobeLocation(float p0, float p1)
{
    field_2C = ((int)(((float)65535) * (p0 / 180.0f)));
    field_2E = ((int)(((float)65535) * (p1 / 360.0f)));
}
