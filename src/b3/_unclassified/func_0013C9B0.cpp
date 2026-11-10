// func_0013C9B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_00516DF0.h"
#include "b3/classes/UnkStruct_D_00516E10.h"
#include "b3/classes/UnkStruct_D_00516E14.h"
#include "b3/classes/UnkStruct_D_00516E34.h"
#include "b3/classes/UnkStruct_theMemMgr.h"

extern UnkStruct_D_00516E10 D_00516E10;
extern UnkStruct_D_00516E34 D_00516E34;
extern UnkStruct_D_00516DF0 D_00516DF0;
extern UnkStruct_D_00516E14 D_00516E14;
extern UnkStruct_theMemMgr theMemMgr;
extern "C" void func_00134600(int);
extern "C" void func_00135A90(void *);
extern "C" void func_003E8750(void *);

// 0x0013C9B0
extern "C" void func_0013C9B0(int n0)
{
    func_00134600(n0);
    D_00516E10.field_0 = 1;
    func_00135A90(&D_00516DF0);
    D_00516E34.field_0 = 1;
    func_00135A90(&D_00516E14);
    func_003E8750(&theMemMgr);
}
