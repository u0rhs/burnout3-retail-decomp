// EnableVBlankWait__12CGtThreadMgrFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct__gVBlankWakeInterruptHandler.h"

struct UnkStruct_func_002370A0;

struct UnkStruct_func_002370A0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern unsigned char _gaThreadsToWakeSignals[8];  // [G] element count: gp-relative, so at most 8 bytes
extern int D_01D80700[];  // [G] element count unknown
extern UnkStruct__gVBlankWakeInterruptHandler _gVBlankWakeInterruptHandler;
extern UnkStruct_func_002370A0 func_002370A0;
extern "C" int AddIntcHandler(int, void *, int);
extern "C" void EnableIntc(int);

// 0x00237200
extern "C" void EnableVBlankWait__12CGtThreadMgrFv()
{
    for (int i = 0; (i < 4); i++) {
        D_01D80700[i] = -1;
        _gaThreadsToWakeSignals[i] = 0;
    }
    _gVBlankWakeInterruptHandler.field_0 = AddIntcHandler(2, &func_002370A0, 0);
    EnableIntc(2);
}
