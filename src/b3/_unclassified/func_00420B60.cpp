// func_00420B60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CMemoryDevicePS2.h"
#include "b3/classes/EMemDevPollOrWait.h"

extern CMemoryDevicePS2 D_005185A0;

// 0x00420B60
extern "C" void func_00420B60(void *a0 /* passed by every caller, not read here */)
{
    int r0 = D_005185A0.GetError();
    if (r0 != 0) {
        if (r0 != 13) {
            D_005185A0.Sync((EMemDevPollOrWait)1, 0);
        }
    }
}
