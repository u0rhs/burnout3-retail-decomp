// func_00463800 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2FBC.h"

extern UnkStruct_D_004E2FBC D_004E2FBC;
extern "C" int func_00467020(int);

// 0x00463800
// pass1: a0 (func_00461F40 passes a stack buffer) goes to func_00467020 untouched
extern "C" int func_00463800(void *n0_)
{
    int n0 = (int)n0_;
    if ((D_004E2FBC.field_0 != 0) == false) {
        return 2;
    }
    int r0 = func_00467020(n0);
    int v0;
    if (r0 == 0) {
        v0 = 0;
    } else {
        v0 = (r0 + 100);
    }
    return v0;
}
