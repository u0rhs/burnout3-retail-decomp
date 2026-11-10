// Free__9CGtMallocFPv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_lnMallocSema.h"

extern UnkStruct_lnMallocSema lnMallocSema;
extern "C" void WaitSema(int);
extern "C" void func_003BB610(void *);
extern "C" void SignalSema(int);

// 0x003BB1D0
extern "C" void Free__9CGtMallocFPv(void *n0_, void *p0_)
{
    int n0 = (int)n0_;
    int p0 = (int)p0_;
    WaitSema(lnMallocSema.field_0);
    func_003BB610((void *)(p0));
    SignalSema(lnMallocSema.field_0);
}
