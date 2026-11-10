// func_00469920 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004B13C0_crc.h"

extern UnkStruct_D_004B13C0_crc D_004B13C0;

// 0x00469920
extern "C" int func_00469920()
{
    if (D_004B13C0.field_0 == 0) {
        return 6;
    }
    D_004B13C0.field_C = 0xFFFFFFFF;
    return 0;
}
