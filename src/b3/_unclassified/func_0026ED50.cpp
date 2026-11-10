// AllNATDataIsFinalised__17CB3NetworkManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E32AE0.h"
#include "b3/classes/UnkStruct_D_01E32B08.h"

struct UnkStruct_0026ED50_1;

struct UnkStruct_0026ED50_1 {
    unsigned char pad_0[0x4F0];
    int field_4F0;
};

extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" UnkStruct_0026ED50_1 * func_002366D0(void *, int);

// 0x0026ED50
extern "C" int AllNATDataIsFinalised__17CB3NetworkManagerFv(void *a0 /* passed by every caller, not read here */)
{
    for (int i = 0; (i < D_01E32B08.field_0); i++) {
        UnkStruct_0026ED50_1 * r0 = func_002366D0(&D_01E32AE0, i);
        if (r0 == 0) {
            continue;
        }
        if (r0->field_4F0 == 2) {
            continue;
        }
        return 0;
    }
    return 1;
}
