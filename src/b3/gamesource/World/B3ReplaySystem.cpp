// B3ReplaySystem.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> B3ReplaySystem.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4ReplaySystem.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3ReplaySystem.h"
#include "b3/classes/UnkStruct_theMemMgr.h"

extern UnkStruct_theMemMgr theMemMgr;
extern "C" int AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" int GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(void *, int);
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);

// CB3ReplaySystem::UnpackHeader() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ReplaySystem.cpp.
// 0x00154DC0
int CB3ReplaySystem::UnpackHeader()
{
    if (field_4 != 1) {
        return 0;
    }
    field_80 = field_8;
    if (field_78 == 0) {
        int r0 = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 8, 0);
        field_78 = r0;
        int r1 = GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(&theMemMgr, 8);
        field_60.Create((void*)field_78, r1, 0);
    }
    return 1;
}

// CB3ReplaySystem::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ReplaySystem.cpp.
// 0x00155000
void CB3ReplaySystem::Destruct()
{
    ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 8, 0);
}

// CB3ReplaySystem::Prepare(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ReplaySystem.cpp.
// 0x001551B0
int CB3ReplaySystem::Prepare(bool p0)
{
    field_7C = 0;
    field_60.SetPosition(0);
    if (!p0) {
        field_6C = field_64;
        field_80 = 0;
    }
    field_84 = p0;
    return 1;
}

// CB3ReplaySystem::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ReplaySystem.cpp.
// 0x00155210
void CB3ReplaySystem::Construct()
{
    int r0 = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 8, 0);
    field_78 = r0;
    int r1 = GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(&theMemMgr, 8);
    field_60.Create((void*)field_78, r1, 0);
    field_7C = 0;
    field_80 = 0;
    field_84 = 0;
}
