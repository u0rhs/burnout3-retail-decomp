// func_003EFE70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E8E5D8.h"
#include "b3/classes/UnkStruct_D_01E8E5E2.h"

extern UnkStruct_D_01E8E5E2 D_01E8E5E2;
extern UnkStruct_D_01E8E5D8 D_01E8E5D8;

// 0x003EFE70
extern "C" void func_003EFE70()
{
    if (D_01E8E5E2.field_0 != 0) {
        ((UnkStruct_D_01E8E5D8 *)&D_01E8E5D8)->vfunc_C();
    }
}
