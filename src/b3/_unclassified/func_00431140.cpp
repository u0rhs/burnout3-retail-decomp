// func_00431140 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E7A888.h"

struct UnkStruct_00431140;

struct UnkStruct_00431140 {
    unsigned char pad_0[0x9B8];
    int field_9B8;
};

extern UnkStruct_D_01E7A888 D_01E7A888;
extern "C" void func_003FA600(void *, int);

// 0x00431140
extern "C" void func_00431140(UnkStruct_00431140 * self)
{
    self->field_9B8 = 0;
    func_003FA600(&D_01E7A888, 1);
}
