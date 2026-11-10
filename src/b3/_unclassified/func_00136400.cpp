// func_00136400 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051BFA0.h"

extern UnkStruct_D_0051BFA0 D_0051BFA0;
extern "C" int func_003E96E0(int);

// 0x00136400
extern "C" int func_00136400()
{
    int m0 = -1;
    for (int i = 0; (i < 73); i++) {
        if (D_0051BFA0.field_57[i] != 0) {
            int r0 = func_003E96E0(i);
            if (m0 < r0) {
                int r1 = func_003E96E0(i);
                m0 = r1;
            }
        }
    }
    return m0;
}
