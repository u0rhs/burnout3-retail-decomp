// func_003F2920 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E7A800.h"
#include "b3/classes/UnkStruct_D_01E91C3E.h"

struct UnkStruct_003F2920;

struct UnkStruct_003F2920 {
    unsigned char pad_0[0x6C];
    unsigned char field_6C;
};

extern UnkStruct_D_01E91C3E D_01E91C3E;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern "C" void func_00283DA0(void *);

// 0x003F2920
extern "C" void func_003F2920(UnkStruct_003F2920 * self)
{
    func_00283DA0(&D_01E7A800);
    if (self->field_6C == 0) {
        D_01E91C3E.field_0 = 0;
    }
}
