// B3GraphicsManagerPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3GraphicsManagerPS2.cpp, 1 by a medium-confidence name confirmed by a neighbour, 3 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Graphics/Ps2, [L] Revenge (SLUS_212.42) GameSource/Graphics/Ps2/B4GraphicsManagerPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3GraphicsManager.h"
#include "b3/classes/CGtTextureCache.h"
#include "b3/classes/RwSkyVideoMode.h"
#include "b3/classes/UnkStruct_D_0051A6A8.h"
#include "b3/classes/UnkStruct_D_0051BA88.h"
#include "b3/classes/UnkStruct__gnIntcHandler.h"
#include "b3/classes/UnkStruct_guFrameCount.h"
#include "b3/classes/UnkStruct_theMemMgr.h"

struct UnkStruct_00227ED0_0;
struct UnkStruct_func_00228040;
struct UnkStruct_func_0022B830;
struct UnkStruct_00228380;
struct UnkStruct_00228400;

struct UnkStruct_00227ED0_0 {
    int field_0;
};

struct UnkStruct_func_00228040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_0022B830 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00228380 {
    unsigned char pad_0[0x1198];
    int field_1198;
    int field_119C;
    int field_11A0[1];  // [G] element count unknown
    unsigned char pad_11A4[0x10];
    int field_11B4[1];  // [G] element count unknown
    unsigned char pad_11B8[0x10];
    int field_11C8[1];  // [G] element count unknown
};

struct UnkStruct_00228400 {
    unsigned char pad_0[0x1198];
    int field_1198;
    int field_119C;
};

extern UnkStruct_guFrameCount guFrameCount;
extern UnkStruct__gnIntcHandler _gnIntcHandler;
extern UnkStruct_theMemMgr theMemMgr;
extern UnkStruct_func_00228040 func_00228040;
extern CGtTextureCache gTextureCache;
extern UnkStruct_func_0022B830 func_0022B830;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern "C" int RwEngineInit(int, int, int);
extern "C" int RwFrameSetStaticPluginsSize(int);
extern "C" int AttachPlugins__10CGtTextureFv();
extern "C" int RwEngineOpen(UnkStruct_00227ED0_0 *);
extern "C" void RwEngineTerm();
extern "C" void RpSkySelectTrueTSClipper(int);
extern "C" void RpSkySelectDeepZBuffer(int);
extern "C" int RpSkyGetModeStructurePtr();
extern "C" void RwEngineSetVideoMode(int);
extern "C" int AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" int GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(void *, int);
extern "C" void _rwDMAPreAlloc(int, int, int);
extern "C" void _rwDMAYieldCallbackSet(void *);
extern "C" void RpSkyTexCacheDisable(int);
extern "C" int RwEngineStart();
extern "C" int RpSkyTexCacheGetStartAddress();
extern "C" int AddIntcHandler(int, void *, int);
extern "C" void RwEngineClose();
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" void PreBuildSpheremapWarpData__18CB3GraphicsManagerFv(void *);  // CB3GraphicsManager::PreBuildSpheremapWarpData()
extern "C" void func_002284B0(UnkStruct_00228400 *);
extern "C" void SyncDCache(int, int);

// func_00222C90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00222C90
extern "C" int func_00222C90(void *a0 /* passed by every caller, not read here */)
{
    return guFrameCount.field_0;
}

// CB3GraphicsManager::OpenRenderWare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3GraphicsManagerPS2.cpp.
// 0x00227ED0
void CB3GraphicsManager::OpenRenderWare()
{
    UnkStruct_00227ED0_0 local;  // [G] the frame's one local (size: up to the frame top)
    int r0 = RwEngineInit(0, 1, 256);
    if (r0 == 0) {
        return;
    }
    int r1 = RwFrameSetStaticPluginsSize(0);
    if (r1 == 0) {
        return;
    }
    int r2 = AttachPlugins__10CGtTextureFv();
    if (r2 == 0) {
        return;
    }
    local.field_0 = 0;
    int r3 = RwEngineOpen(&local);
    if (r3 == 0) {
        RwEngineTerm();
        return;
    }
    RpSkySelectTrueTSClipper(1);
    RpSkySelectDeepZBuffer(1);
    int r7 = RpSkyGetModeStructurePtr();
    SetVideoModeParams((RwSkyVideoMode*)r7);
    RwEngineSetVideoMode(-1);
    int r10 = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 25, 0);
    field_42C = r10;
    int r11 = GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(&theMemMgr, 25);
    _rwDMAPreAlloc(r11, 384, field_42C);
    _rwDMAYieldCallbackSet(&func_00228040);
    int r14 = GetBlockSize__19CB3MemoryManagerPS2CF14EB3MemoryBlock(&theMemMgr, 25);
    field_420 = r14;
    RpSkyTexCacheDisable(1);
    int r16 = RwEngineStart();
    if (r16 != 0) {
        int r17 = RpSkyTexCacheGetStartAddress();
        gTextureCache.Construct(r17, 30, 384);
        int r19 = AddIntcHandler(2, &func_0022B830, 0);
        _gnIntcHandler.field_0 = r19;
        return;
    }
    RwEngineClose();
    RwEngineTerm();
}

// func_00228380 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00228380
extern "C" void func_00228380(UnkStruct_00228380 * self)
{
    for (int i = 1; i < 6; i++) {
        int j = i - 1;
        if (self->field_11A0[j] != 0) {
            self->field_11A0[j] = 0;
            self->field_11B4[j] = 0;
            self->field_11C8[j] = 0;
        }
    }
    ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 26, 0);
    self->field_1198 = 0;
    self->field_119C = 0;
}

// func_00228400 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00228400
extern "C" int func_00228400(UnkStruct_00228400 * self)
{
    if (self->field_1198 == 0) {
        self->field_1198 = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 26, 0);
        if (self->field_1198 == 0) {
            return 0;
        }
        self->field_119C = 0;
        if ((void *)D_0051BA88.field_0 == (void *)&D_0051A6A8) {
            func_002284B0(self);
        } else {
            PreBuildSpheremapWarpData__18CB3GraphicsManagerFv(self);
        }
        SyncDCache(self->field_1198, self->field_1198 + self->field_119C - 1);
    }
    return 1;
}
