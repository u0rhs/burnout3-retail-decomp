// B3OnlineTurnBasedCrashLogic.cpp -- translation unit regrouped by tools/tu_merge.py from 9 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3OnlineTurnBasedCrashLogic.cpp, 8 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Game/Logic, [G] domain word `Logic` in the name: 19 of Revenge's 19 files with it are in GameSource/Game/Logic/.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3OnlineStageLogic.h"
#include "b3/classes/CB3OnlineTurnBasedCrashLogic.h"
#include "b3/classes/UnkStruct_D_004F50C0.h"
#include "b3/classes/UnkStruct_D_004F6061.h"
#include "b3/classes/UnkStruct_D_00516E40.h"
#include "b3/classes/UnkStruct_D_00665E53.h"
#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E91C3E.h"
#include "b3/classes/UnkStruct_theMemMgr.h"

struct UnkStruct_00392980;
struct UnkStruct_003929D0;
struct UnkStruct_00392A30;
struct UnkStruct_00392A30_5;

struct UnkStruct_00392970 {
    unsigned char pad_0[0x4];
    unsigned char field_4;
};

struct UnkStruct_00392980 {
    unsigned char pad_0[0x68];
    int field_68;
};

struct UnkStruct_003929C0 {
    unsigned char pad_0[0x68];
    int field_68;
};

struct UnkStruct_003929D0 {
    unsigned char pad_0[0x60];
    int field_60;
    int field_64;
    int field_68;
};

struct UnkStruct_00392A30_5 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_00392A30 {
    unsigned char pad_0[0x68];
    int field_68;
};

extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_theMemMgr theMemMgr;
extern UnkStruct_D_01E91C3E D_01E91C3E;
extern UnkStruct_D_00665E53 D_00665E53;
extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_00516E40 D_00516E40;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern "C" void StartReplay__19CB3OnlineStageLogicFv(void *);  // CB3OnlineStageLogic::StartReplay()
extern "C" void func_00392040(UnkStruct_00392980 *);
extern "C" void func_0026DE80(void *, int);
extern "C" void func_00392240(UnkStruct_003929C0 *);
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" void func_00392250(UnkStruct_003929D0 *);
extern "C" float func_0012F240(void *);
extern "C" float func_0012F330(void *);

// CB3OnlineTurnBasedCrashLogic::StartReplay() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineTurnBasedCrashLogic.cpp.
// 0x00392740
void CB3OnlineTurnBasedCrashLogic::StartReplay()
{
    field_68 = 6;
    StartReplay__19CB3OnlineStageLogicFv(this);
}

// func_00392940 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00392940
extern "C" int func_00392940()
{
    return 0;
}

// func_00392950 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00392950
extern "C" int func_00392950()
{
    return 1;
}

// func_00392960 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00392960
extern "C" int func_00392960()
{
    return 11;
}

// func_00392970 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00392970
extern "C" unsigned char func_00392970(UnkStruct_00392970 *self)
{
    return self->field_4;
}

// func_00392980 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00392980
extern "C" void func_00392980(UnkStruct_00392980 * self)
{
    func_00392040(self);
    func_0026DE80(&D_01E32AE0, 0);
    self->field_68 = 6;
}

// func_003929C0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003929C0
extern "C" void func_003929C0(UnkStruct_003929C0 *self)
{
    self->field_68 = 0;
    func_00392240(self);
}

// Release__28CB3OnlineTurnBasedCrashLogicFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003929D0
extern "C" void Release__28CB3OnlineTurnBasedCrashLogicFv(UnkStruct_003929D0 * self)
{
    ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 1, 1);
    ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 1, 2);
    self->field_60 = 0;
    self->field_64 = 0;
    self->field_68 = 0;
    func_00392250(self);
}

// func_00392A30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00392A30
extern "C" void func_00392A30(UnkStruct_00392A30 * self)
{
    if (D_01E91C3E.field_0 != 0) {
        return;
    }
    switch (self->field_68) {
    case 6:
        if (D_00665E53.field_0 != 0) {
            break;
        }
        void * p = (char *)&D_004F50C0.field_0[D_004F6061.field_0] + 0xD48;
        if (!func_0012F240(p)) {
            if (func_0012F330(p)) {
                ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(7, 0);
            }
        } else {
            ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(8, 0);
        }
        break;
    }
}
