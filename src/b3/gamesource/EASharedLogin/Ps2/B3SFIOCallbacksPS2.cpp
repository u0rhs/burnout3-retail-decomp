// B3SFIOCallbacksPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 12 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3SFIOCallbacksPS2.cpp, 3 by a medium-confidence name confirmed by a neighbour, 8 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/EASharedLogin/Ps2, [L] Revenge (SLUS_212.42) GameSource/EASharedLogin/Ps2/B4SFIOCallbacksPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3OnlineSelectLoginPage.h"
#include "b3/classes/CB3SFIOCallbacks.h"
#include "b3/classes/CMemoryDevicePS2.h"
#include "b3/classes/EMemDevPollOrWait.h"
#include "b3/classes/SLoginProcessE.h"
#include "b3/classes/UnkStruct_D_004E2E04.h"
#include "b3/classes/UnkStruct_D_01EA3FA0.h"
#include "b3/classes/UnkStruct_D_01EA3FB1.h"

extern UnkStruct_D_004E2E04 D_004E2E04;
extern CMemoryDevicePS2 D_005185A0;
extern UnkStruct_D_01EA3FB1 D_01EA3FB1;
extern UnkStruct_D_01EA3FA0 D_01EA3FA0;
extern "C" int func_00465910();
extern "C" int func_00465430(CB3SFIOCallbacks *, SLoginProcessE*);

// SFIOSetAttrCallback__16CB3SFIOCallbacksFiUi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00361050
extern "C" void SFIOSetAttrCallback__16CB3SFIOCallbacksFiUi()
{
    CB3SFIOCallbacks::gmeLastOperation = 0;
    CB3SFIOCallbacks::gmeError = 0;
    CB3SFIOCallbacks::gmeProcess = 2;
}

// func_00361070 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00361070
extern "C" void func_00361070()
{
    CB3SFIOCallbacks::gmeLastOperation = 0;
    CB3SFIOCallbacks::gmeError = 0;
    CB3SFIOCallbacks::gmeProcess = 2;
}

// SFIOSeekCallback__16CB3SFIOCallbacksFii9SFIOSeekE -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00361090
extern "C" void SFIOSeekCallback__16CB3SFIOCallbacksFii9SFIOSeekE(int n0, int p0, int p1)
{
    CB3SFIOCallbacks::gmnOffset = p0;
    D_004E2E04.field_0 = p1;
    CB3SFIOCallbacks::gmeProcess = 2;
    CB3SFIOCallbacks::gmeLastOperation = 0;
    CB3SFIOCallbacks::gmeError = 0;
}

// CB3SFIOCallbacks::SFIOReadCallback(int,void*,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SFIOCallbacksPS2.cpp.
// 0x003611C0
void CB3SFIOCallbacks::SFIOReadCallback(int p0, void* p1, unsigned int p2)
{
    int r0 = D_005185A0.Read((char*)p0, (unsigned int)p1, CB3SFIOCallbacks::gmnOffset);
    if (r0 == 0) {
        CB3SFIOCallbacks::gmeLastOperation = 0;
        CB3SFIOCallbacks::gmeProcess = 2;
        CB3SFIOCallbacks::gmeError = 4;
    } else {
        CB3SFIOCallbacks::gmeError = 0;
        CB3SFIOCallbacks::gmeLastOperation = 7;
        CB3SFIOCallbacks::gmeProcess = 1;
    }
}

// SFIODestroyCallback__16CB3SFIOCallbacksFPCc11SFIODeviceE -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00361220
extern "C" void SFIODestroyCallback__16CB3SFIOCallbacksFPCc11SFIODeviceE()
{
    CB3SFIOCallbacks::gmeLastOperation = 0;
    CB3SFIOCallbacks::gmeError = 0;
    CB3SFIOCallbacks::gmeProcess = 2;
}

// func_00361240 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00361240
extern "C" void func_00361240()
{
    CB3SFIOCallbacks::gmeLastOperation = 0;
    CB3SFIOCallbacks::gmeError = 0;
    CB3SFIOCallbacks::gmeProcess = 2;
}

// SFIOUnMountCallback__16CB3SFIOCallbacksF11SFIODeviceE -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00361420
extern "C" void SFIOUnMountCallback__16CB3SFIOCallbacksF11SFIODeviceE()
{
    CB3SFIOCallbacks::gmeLastOperation = 0;
    CB3SFIOCallbacks::gmeError = 0;
    CB3SFIOCallbacks::gmeProcess = 2;
}

// func_003614A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003614A0
extern "C" void func_003614A0()
{
    CB3SFIOCallbacks::gmeLastOperation = 0;
    CB3SFIOCallbacks::gmnFreeSpace = 2000;
    CB3SFIOCallbacks::gmeError = 0;
    CB3SFIOCallbacks::gmeProcess = 1;
}

// CB3SFIOCallbacks::GetSharedNetworkLoginPassword() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3SFIOCallbacksPS2.cpp.
// 0x00361590
void * CB3SFIOCallbacks::GetSharedNetworkLoginPassword()
{
    return &D_01EA3FB1;
}

// CB3SFIOCallbacks::GetSharedNetworkLoginName() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3SFIOCallbacksPS2.cpp.
// 0x003615A0
void * CB3SFIOCallbacks::GetSharedNetworkLoginName()
{
    return &D_01EA3FA0;
}

// func_003615B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003615B0
extern "C" int func_003615B0()
{
    if (CB3SFIOCallbacks::gmbOpenedFile == 0) {
        return 0;
    }
    CB3SFIOCallbacks::gmbOpenedFile = 0;
    int r0 = func_00465910();
    return r0;
}

// CB3SFIOCallbacks::SharedNetworkLoginUpdate(SLoginProcessE*) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3SFIOCallbacksPS2.cpp.
// 0x003615E0
// [C] returns func_00465430's result: retail 0x3615E0 is `j func_00465430` (a tail call, so v0 is the callee's), and
// its callers read it: func_0037D1F0 at 0x37D4B0 / 0x37D4F8 (`daddu $s1, $v0, $zero`),
// CB3OnlineSelectLoginPage::UpdateRetrieveLogin at 0x347768 (`bnez $v0`).
int CB3SFIOCallbacks::SharedNetworkLoginUpdate(SLoginProcessE* p0)
{
    return func_00465430(this, p0);
}
