// GtMalloc.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> GtMalloc.cpp.
// Area: src/b3/GameShared/GameClasses/Memory, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Memory/GtMalloc.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtMalloc.h"
#include "b3/classes/UnkStruct_lnMallocSema.h"

struct UnkStruct_003BB2A0_2;

struct UnkStruct_003BB2A0_2 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    unsigned char pad_C[0x14];
};

extern UnkStruct_lnMallocSema lnMallocSema;
extern "C" void * memset(void *, int, unsigned int);
extern "C" int CreateSema(UnkStruct_003BB2A0_2 *);

// CGtMalloc::Create(void*,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtMalloc.cpp.
// 0x003BB2A0
void CGtMalloc::Create(void* p0, unsigned int p1)
{
    UnkStruct_003BB2A0_2 local;  // [G] the frame's one local (size: up to the frame top)
    field_0 = 1;
    CGtMalloc::mpBuffer = (void *)p0;
    CGtMalloc::mnPoolSize = p1;
    CGtMalloc::mnPoolOffset = 0;
    memset(&local, 0, 24);
    local.field_8 = 1;
    local.field_4 = 1;
    int r1 = CreateSema(&local);
    lnMallocSema.field_0 = r1;
}
