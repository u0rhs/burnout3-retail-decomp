// GtThreadMgrPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> GtThreadMgrPS2.cpp, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/GameShared/GameClasses/System/Threads/ps2, [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Threads/ps2/GtThreadMgrPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/UnkStruct_D_004E8670.h"

struct UnkStruct_func_00237090;
struct UnkStruct_00237270_0;

struct UnkStruct_func_00237090 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00237270_0 {
    int field_0;
    void * field_4;
    void * field_8;
    int field_C;
    void * field_10;
    int field_14;
    unsigned char pad_18[0x18];
};

extern UnkStruct_func_00237090 func_00237090;
extern unsigned char _gaThreadsToWakeSignals[8];  // [G] element count: gp-relative
extern int D_01D80700[];  // [G] element count unknown
extern UnkStruct_D_004E8670 D_004E8670;
extern "C" int GetThreadId(int);
extern "C" void SetAlarm(int, void *, int);
extern "C" void SleepThread();
extern "C" void iWakeupThread(int);
extern "C" void * malloc(int);
extern "C" int CreateThread(UnkStruct_00237270_0 *);
extern "C" int _StartThread(int, void *);

// SleepThread__12CGtThreadMgrFi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00237050
extern "C" void SleepThread__12CGtThreadMgrFi(int n0)
{
    int r0 = GetThreadId(n0);
    SetAlarm((n0 & 65535), &func_00237090, r0);
    SleepThread();
}

// Hand-written; the lifter refused it (a77: VBlank handler; pointer local, reread via const pun, sync + ei as asm).
// 0x002370A0
extern "C" int func_002370A0(int p0)
{
    for (int i = 0; i < 4; i++) {
        int *p = &D_01D80700[i];
        if (*p != -1) {
            iWakeupThread(*(const int *)&*p);
            _gaThreadsToWakeSignals[i] = 1;
        }
    }
    asm("sync");
    asm(".word 0x42000038");
    return 0;
}

// CreateThread__12CGtThreadMgrFPFPv_iPviQ212CGtThreadMgr17EThreadPriorities -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00237270
extern "C" int CreateThread__12CGtThreadMgrFPFPv_iPviQ212CGtThreadMgr17EThreadPriorities(void * n0, void * p0, int p1, void *p2_)
{
    int p2 = (int)p2_;
    UnkStruct_00237270_0 local;  // [G] the frame's one local (size: up to the frame top)
    local.field_4 = n0;
    local.field_8 = malloc(p1);
    local.field_C = p1;
    local.field_10 = &D_004E8670;
    local.field_14 = (p2 + 1);
    int r1 = CreateThread(&local);
    _StartThread(r1, p0);
    return r1;
}
