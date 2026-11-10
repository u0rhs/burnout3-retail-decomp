// func_003F3F90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E8980A.h"

struct UnkStruct_003F3F90;

struct UnkStruct_003F3F90 {
    unsigned char pad_0[0x4];
    int field_4;
};

extern UnkStruct_D_01E8980A D_01E8980A;
extern UnkStruct_D_01E89800 D_01E89800;
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x003F3F90
extern "C" void func_003F3F90(UnkStruct_003F3F90 * self, int p0)
{
    if (D_01E8980A.field_0 == 0) {
    } else {
        ((UnkStruct_D_01E89800 *)&D_01E89800)->vfunc_C();
    }
    switch (p0) {
    case 0:
        func_0031ECD0(&D_01E89800, 265, 3);
        break;
    case 1:
        func_0031ECD0(&D_01E89800, 16, 3);
        break;
    case 3:
        func_0031ECD0(&D_01E89800, 261, 3);
        break;
    case 2:
        if (self->field_4 == 18) {
            func_0031ECD0(&D_01E89800, 261, 3);
        } else {
            func_0031ECD0(&D_01E89800, 265, 3);
        }
        break;
    case 4:
        func_0031ECD0(&D_01E89800, 264, 3);
        break;
    }
}
