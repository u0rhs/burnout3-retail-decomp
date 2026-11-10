// func_00468ED0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2FC8.h"

extern UnkStruct_D_004E2FC8 D_004E2FC8;

// 0x00468ED0
extern "C" int func_00468ED0(int n0)
{
    switch (D_004E2FC8.field_0->field_4) {
    case 10:
    case 14:
    case 6:
    case 22:
        switch (n0) {
        case 17:
        case 13:
        case 9:
        case 4:
        case 3:
        case 0:
            break;
        default:
            return 16;
        }
        return n0;
    default:
        return 18;
    }
}
