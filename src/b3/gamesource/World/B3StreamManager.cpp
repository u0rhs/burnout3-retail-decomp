// B3StreamManager.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> B3StreamManager.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4StreamManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3StreamManager.h"
#include "b3/classes/CB3StreamedTrackHighData.h"
#include "b3/classes/CB3StreamedTrackLODAndCollisionData.h"
#include "b3/classes/UnkStruct_theMemMgr.h"

extern UnkStruct_theMemMgr theMemMgr;
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int, int);
extern "C" void * memset(void *, int, unsigned int);

// CB3StreamManager::ReleaseLODUnit(CB3StreamedTrackLODAndCollisionData*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamManager.cpp.
// 0x003C30E0
void CB3StreamManager::ReleaseLODUnit(CB3StreamedTrackLODAndCollisionData* p0)
{
    int t0 = field_EC;
    for (int i = 0; (i < t0); i++) {
        if ((int)p0 == field_5C[i]) {
            ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 7, i, t0);
            field_5C[i] = 0;
            return;
        }
    }
}

// CB3StreamManager::ReleaseHighDetailUnit(CB3StreamedTrackHighData*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamManager.cpp.
// 0x003C31E0
void CB3StreamManager::ReleaseHighDetailUnit(CB3StreamedTrackHighData* p0)
{
    int t0 = field_E8;
    for (int i = 0; (i < t0); i++) {
        if ((int)p0 == field_10[i]) {
            ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 6, i, t0);
            field_10[i] = 0;
            return;
        }
    }
}

// CB3StreamManager::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamManager.cpp.
// 0x003C3560
void CB3StreamManager::Destruct()
{
    field_F0 = 25;
}

// CB3StreamManager::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamManager.cpp.
// 0x003C3570
void CB3StreamManager::Construct()
{
    memset(((char *)this + 0x10), 0, 76);
    memset(((char *)this + 0x5C), 0, 140);
    field_4 = 1;
    field_F0 = 1;
}
