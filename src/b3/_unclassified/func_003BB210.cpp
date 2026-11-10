// Malloc__9CGtMallocFUi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_lnMallocSema.h"

struct UnkStruct_003BB210_1;

struct UnkStruct_003BB210_1 {
    unsigned char pad_0[0x30];
};

extern UnkStruct_lnMallocSema lnMallocSema;
extern "C" void WaitSema(int);
extern "C" int func_003BB7A0(int);
extern "C" void SignalSema(int);
extern "C" void func_003BB2F0(UnkStruct_003BB210_1 *);

// 0x003BB210
extern "C" int Malloc__9CGtMallocFUi(void *n0_, int p0)
{
    int n0 = (int)n0_;
    UnkStruct_003BB210_1 local;  // [G] the frame's one local (size: up to the frame top)
    WaitSema(lnMallocSema.field_0);
    int r = func_003BB7A0(p0);
    SignalSema(lnMallocSema.field_0);
    WaitSema(lnMallocSema.field_0);
    func_003BB2F0(&local);
    SignalSema(lnMallocSema.field_0);
    return r;
}
