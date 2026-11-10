// func_00137D50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051BFA0.h"

extern UnkStruct_D_0051BFA0 D_0051BFA0;
extern "C" int func_003F5FF0(int);

// 0x00137D50
extern "C" int func_00137D50(void *a0 /* passed by every caller, not read here */)
{
    int m0 = 0;
    for (int i = 0; (i < 4); i++) {
        int i1;
        int m1 = 0;
        for (i1 = 0; (i1 < 20); i1++) {
            if (i == func_003F5FF0(i1)) {
                if (D_0051BFA0.field_43[i1] != 0) {
                    m1++;
                }
            }
        }
        if (m1 >= 5) {
            m0++;
        }
    }
    return m0;
}
