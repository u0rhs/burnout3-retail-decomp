// func_00465910 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2FC0.h"
#include "b3/classes/UnkStruct_D_004E2FC4.h"

extern UnkStruct_D_004E2FC4 D_004E2FC4;
extern UnkStruct_D_004E2FC0 D_004E2FC0;
extern "C" int func_004647D0();
extern "C" int func_00465320(int);
extern "C" void func_00360AC0(int, UnkStruct_00465910_1 *, int, int);

// 0x00465910
extern "C" int func_00465910()
{
    int r0 = func_004647D0();
    func_00465320(r0);
    func_00360AC0(D_004E2FC4.field_0->field_144, D_004E2FC4.field_0, 336, 4);
    D_004E2FC4.field_0 = 0;
    D_004E2FC0.field_0 = 0;
    return 0;
}
