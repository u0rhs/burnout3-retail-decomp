// func_004660B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2FC4.h"

extern UnkStruct_D_004E2FC4 D_004E2FC4;
extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" int func_00463600(void *, int, int, int);
extern "C" int func_00465320(int);

// 0x004660B0
extern "C" void func_004660B0()
{
    memcpy((void *)(D_004E2FC4.field_0->field_D0 + 17), (const void *)D_004E2FC4.field_0->field_148, 17);
    int r1 = func_00463600((void *)(D_004E2FC4.field_0->field_148), D_004E2FC4.field_0->field_144, 17, 0);
    func_00465320(r1);
}
