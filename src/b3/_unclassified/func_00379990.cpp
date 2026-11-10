// Release__21CB3OnlineNewsMenuPageFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E3CD44.h"

struct UnkStruct_00379990;

struct UnkStruct_00379990 {
    unsigned char pad_0[0x20];
    int field_20;
};

extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern "C" void func_00335F60(void *);
extern "C" void func_00335DB0(void *, void *);

// 0x00379990
extern "C" void Release__21CB3OnlineNewsMenuPageFv(UnkStruct_00379990 * self)
{
    func_00335F60(&D_01E3CD44);
    int t0 = self->field_20;
    if (t0 == 0) return;
    func_00335DB0(&D_01E3CD44, (void *)(t0));
    self->field_20 = 0;
}
