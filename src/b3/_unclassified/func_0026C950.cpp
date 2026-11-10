// func_0026C950 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004E2A24.h"
#include "b3/classes/UnkStruct_D_004E2A28.h"
#include "b3/classes/UnkStruct_D_01E3CD44.h"

struct UnkStruct_func_0026C9C0;

struct UnkStruct_func_0026C9C0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_004E2A24 D_004E2A24;
extern UnkStruct_D_004E2A28 D_004E2A28;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_func_0026C9C0 func_0026C9C0;

// 0x0026C950
extern "C" bool func_0026C950(void *n0_, int p0)
{
    int n0 = (int)n0_;
    D_004E2A24.field_0 = 0;
    D_004E2A28.field_0 = 0;
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_54(0, p0, 0, 100, &func_0026C9C0, n0);
    int t0 = D_004E2A28.field_0;
    int v1 = (t0 / 2);
    return (D_004E2A24.field_0 < v1);
}
