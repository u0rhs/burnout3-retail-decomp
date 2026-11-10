// func_0026C8C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E32B08.h"

struct UnkStruct_0026C8C0_1;
struct UnkStruct_0026C8C0_2;

struct UnkStruct_0026C8C0_1 {
    unsigned char pad_0[0x6DC];
    UnkStruct_0026C8C0_2 * field_6DC;
    unsigned char pad_6E0[0x481C];
    unsigned char field_4EFC;
};

struct UnkStruct_0026C8C0_2 {
    unsigned char pad_0[0x16C8];
    int field_16C8;
};

extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" UnkStruct_0026C8C0_1 * func_002366D0(void *, int);

// 0x0026C8C0
extern "C" int func_0026C8C0(void *a0 /* passed by every caller, not read here */)
{
    for (int i = 0; (i < D_01E32B08.field_0); i++) {
        UnkStruct_0026C8C0_1 * r0 = func_002366D0(&D_01E32AE0, i);
        if (r0 == 0) {
            continue;
        }
        if (((r0->field_4EFC != 0) ^ 1) == 0) {
            continue;
        }
        if (r0->field_6DC->field_16C8 != 0) {
            continue;
        }
        return 0;
    }
    return 1;
}
