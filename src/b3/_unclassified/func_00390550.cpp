// func_00390550 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E32B08.h"

extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" char *func_002366D0(void *, int);
extern "C" void func_003CC280(void *, int);

// 0x00390550
extern "C" void func_00390550()
{
    for (int i = 0; (i < D_01E32B08.field_0); i++) {
        char *r0 = func_002366D0(&D_01E32AE0, i);
        if (r0 != 0) {
            func_003CC280((r0 + 5680), 2);
        }
    }
}
