// func_004662D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2FC4.h"

extern UnkStruct_D_004E2FC4 D_004E2FC4;
extern "C" int func_004645F0(void *);
extern "C" int func_00465320(int);

// 0x004662D0
extern "C" void func_004662D0()
{
    D_004E2FC4.field_0->field_100 = 0;
    D_004E2FC4.field_0->field_104 = 0;
    int r0 = func_004645F0(((char *)D_004E2FC4.field_0 + 0x48));
    func_00465320(r0);
}
