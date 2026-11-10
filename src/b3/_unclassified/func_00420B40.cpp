// ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3MenuFlowFSM.h"

extern CB3MenuFlowFSM D_01EA2970;

// 0x00420B40
extern "C" void ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(int n0, void *p0_)
{
    int p0 = (int)p0_;
    D_01EA2970.ApplyEvent(n0, (void*)p0);
}
