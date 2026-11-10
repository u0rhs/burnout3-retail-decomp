// func_00464790 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2FBC.h"

extern UnkStruct_D_004E2FBC D_004E2FBC;
extern "C" int func_004678E0(const char *, int, int);

// 0x00464790
// pass1: a0..a2 (func_004665D0 etc. pass &D_004D3CB8, -1, 0) go to func_004678E0(name, slot, mode) untouched
extern "C" int func_00464790(const char * name, int slot, int mode)
{
    D_004E2FBC.field_0->field_74 = 1;
    D_004E2FBC.field_0->field_78 = 1;
    int r0 = func_004678E0(name, slot, mode);
    int v0;
    if (r0 == 0) {
        v0 = 0;
    } else {
        v0 = (r0 + 100);
    }
    return v0;
}
