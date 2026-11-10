// func_003C55D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E898E8.h"
#include "b3/classes/UnkStruct_D_01ECDA04.h"

struct UnkStruct_003C55D0;

struct UnkStruct_003C55D0 {
    unsigned char pad_0[0x38];
    int field_38;
};

extern UnkStruct_D_01ECDA04 D_01ECDA04;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern "C" void func_003C58A0(UnkStruct_003C55D0 *, int, int, void *);
extern "C" void func_0032D080(void *, int, int, int, int);

// 0x003C55D0
extern "C" int func_003C55D0(UnkStruct_003C55D0 * self)
{
    func_003C58A0(self, D_01ECDA04.field_0, 0, (void *)(0));
    self->field_38 = 1;
    func_0032D080(&D_01E898E8, 7, 312, 4, 0);
    return 1;
}
