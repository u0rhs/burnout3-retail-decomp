// GtHiResSystemTimerPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> GtHiResSystemTimerPS2.cpp, 3 placed between two of them by address contiguity (N2).
// Area: src/b3/GameShared/GameClasses/System/Timer/Ps2, [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Timer/Ps2/GtHiResSystemTimerPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtHiResSystemTimer.h"

extern unsigned char gmbVsyncAt60Hz__19CGtHiResSystemTimer;
extern int gmnLastVsyncCount__19CGtHiResSystemTimer;
extern int gmnTimeMSP__19CGtHiResSystemTimer;

// func_003752E0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003752E0
extern "C" void func_003752E0()
{
}

// func_003752F0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003752F0
extern "C" void func_003752F0()
{
}

// Hand-written; the lifter refused it (a89: static member Update(int) as extern C with mangled static externs; float literals exact).
// 0x00375300
extern "C" void Update__19CGtHiResSystemTimerFi(int count)
{
    if (gmbVsyncAt60Hz__19CGtHiResSystemTimer != 0) {
        float ms = 0.0011444091796875f * (float)(count - gmnLastVsyncCount__19CGtHiResSystemTimer);
        if (ms >= 1.0f) {
            gmnTimeMSP__19CGtHiResSystemTimer += (int)ms;
        }
    } else {
        float ms = 0.001373291015625f * (float)(count - gmnLastVsyncCount__19CGtHiResSystemTimer);
        if (ms >= 1.0f) {
            gmnTimeMSP__19CGtHiResSystemTimer += (int)ms;
        }
    }
    gmnLastVsyncCount__19CGtHiResSystemTimer = count;
}

// Prepare__19CGtHiResSystemTimerFbi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003753B0
extern "C" int Prepare__19CGtHiResSystemTimerFbi(int n0, int p0)
{
    CGtHiResSystemTimer::gmnLastVsyncCount = p0;
    CGtHiResSystemTimer::gmbVsyncAt60Hz = n0;
    CGtHiResSystemTimer::gmuTimeLSP = 0;
    CGtHiResSystemTimer::gmnTimeMSP = 0;
    return 1;
}

// Construct__19CGtHiResSystemTimerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003753D0
extern "C" void Construct__19CGtHiResSystemTimerFv()
{
    CGtHiResSystemTimer::gmuTimeLSP = 0;
    CGtHiResSystemTimer::gmnTimeMSP = 0;
    CGtHiResSystemTimer::gmbVsyncAt60Hz = 1;
    CGtHiResSystemTimer::gmnLastVsyncCount = 0;
}
