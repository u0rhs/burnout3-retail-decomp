// func_00445CA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004D2F88.h"
#include "b3/classes/UnkStruct_D_004D2F90.h"

extern UnkStruct_D_004D2F88 D_004D2F88;
extern UnkStruct_D_004D2F90 D_004D2F90;
extern "C" int func_00445970(void *, void *, void *);

// Returns the tail call's value (retail `j func_00445970`: v0 passes through to the caller).
// 0x00445CA0
extern "C" int func_00445CA0(void *n0_)
{
    int n0 = (int)n0_;
    return func_00445970((void *)(n0), &D_004D2F88, &D_004D2F90);
}
