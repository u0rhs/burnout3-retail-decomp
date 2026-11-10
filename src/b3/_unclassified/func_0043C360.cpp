// func_0043C360 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004F50C0.h"
#include "b3/classes/UnkStruct_D_004F6061.h"
#include "b3/classes/UnkStruct_D_01E90424.h"

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_004F6061 D_004F6061;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern "C" void func_003C1390(void *, void *);

// 0x0043C360
extern "C" void func_0043C360(int n0)
{
    if (D_01E90424.field_0 != 5) return;
    func_003C1390((void *)(n0), ((char *)&D_004F50C0.field_0[D_004F6061.field_0] + 0xD48));
}
