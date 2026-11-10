// func_003FFD80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01ECD950.h"

extern UnkStruct_D_01ECD950 D_01ECD950;
extern "C" void ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(int, void *);

// 0x003FFD80
extern "C" void func_003FFD80(int n0, int p0, int p1, int p2)
{
    switch (p0) {
    case 3:
        break;
    case 4:
        ((UnkStruct_D_01ECD950 *)&D_01ECD950)->vfunc_10();
        break;
    case 5:
        switch (p2) {
        case 0:
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(48, (void *)(0));
            break;
        case 1:
            ApplyEvent__29CB3MemCardFSMFlowCommunicatorFUiPv(49, (void *)(0));
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        }
        break;
    case 2:
        break;
    }
}
