// B3PlayerCameraManager.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3PlayerCameraManager.cpp, 2 by a medium-confidence name confirmed by a neighbour, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Camera, [L] Revenge (SLUS_212.42) GameSource/Camera/B4PlayerCameraManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3PlayerCameraManager.h"
#include "b3/classes/CGtFSM.h"
#include "b3/classes/CGtStateOffset.h"
#include "b3/classes/CGtTimer.h"
#include "b3/classes/UnkStruct_D_00517970.h"
#include "b3/classes/UnkStruct_D_005179C0.h"
#include "b3/classes/UnkStruct_D_005179E7.h"
#include "b3/classes/UnkStruct_D_00518520.h"
#include "b3/classes/UnkStruct_D_00518570.h"
#include "b3/classes/UnkStruct_D_00518597.h"
#include "b3/classes/UnkStruct_theMemMgr.h"

extern UnkStruct_D_005179E7 D_005179E7;
extern UnkStruct_D_00518597 D_00518597;
extern UnkStruct_theMemMgr theMemMgr;
extern UnkStruct_D_005179C0 D_005179C0;
extern UnkStruct_D_00518570 D_00518570;
extern UnkStruct_D_00517970 D_00517970;
extern UnkStruct_D_00518520 D_00518520;
extern "C" void func_002F7C30(int);
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" int func_00445D00(void *);

// CB3PlayerCameraManager::Construct(void*,const CGtStateOffset*,CGtTimer*) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3PlayerCameraManager.cpp.
// 0x002E6F40
void CB3PlayerCameraManager::Construct(void* p0, const CGtStateOffset* p1, CGtTimer* p2)
{
    CGtFSM::Construct(p0, p1, p2);
}

// CB3PlayerCameraManager::Update() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3PlayerCameraManager.cpp.
// 0x002E6F50
void CB3PlayerCameraManager::Update()
{
    CGtFSM::Update();
}

// CB3PlayerCameraManager::HasIntroFinished() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCameraManager.cpp.
// 0x002E70B0
bool CB3PlayerCameraManager::HasIntroFinished()
{
    bool v0 = ((D_005179E7.field_0 != 0) || (D_00518597.field_0 != 0));
    return (!v0);
}

// func_002E70E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002E70E0
extern "C" int func_002E70E0()
{
    if ((D_005179C0.field_0 & 8192) != 0) {
        return func_00445D00(&D_00517970);
    }
    if ((D_00518570.field_0 & 8192) != 0) {
        return func_00445D00(&D_00518520);
    }
    return 1;
}

// CB3PlayerCameraManager::ReleaseBuffer() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCameraManager.cpp.
// 0x002E7CD0
void CB3PlayerCameraManager::ReleaseBuffer()
{
    int t0 = CB3PlayerCameraManager::mgpCameraBuffer;
    if (t0 == 0) return;
    func_002F7C30((t0 + 11312));
    ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 0, 0);
    CB3PlayerCameraManager::meLoadState = 0;
    CB3PlayerCameraManager::mgpCameraBuffer = 0;
}
