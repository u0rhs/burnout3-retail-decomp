// func_0038D950 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E32AE0.h"

struct UnkStruct_0038D950;

struct UnkStruct_0038D950 {
    unsigned char pad_0[0x60];
    int field_60;
    int field_64;
};

extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern "C" void func_00392040(UnkStruct_0038D950 *);
extern "C" void func_0026DE80(void *, int);

// 0x0038D950
extern "C" void func_0038D950(UnkStruct_0038D950 * self)
{
    func_00392040(self);
    func_0026DE80(&D_01E32AE0, 0);
    self->field_60 = 6;
    self->field_64 = (self->field_64 + 1);
}
