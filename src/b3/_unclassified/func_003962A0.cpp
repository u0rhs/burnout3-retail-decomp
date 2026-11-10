// func_003962A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E89800.h"
#include "b3/classes/UnkStruct_D_01E898E8.h"

struct UnkStruct_003962A0_1;

struct UnkStruct_003962A0_1 {
    unsigned char pad_0[0xC];
    int field_C;
};

extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E89800 D_01E89800;
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x003962A0
extern "C" void func_003962A0(int n0)
{
    if (n0 != 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        func_0032D080(&D_01E898E8, 2, 56, 0, 0);
    } else {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        func_0032D080(&D_01E898E8, 2, 57, 0, 0);
    }
    func_0031ECD0(&D_01E89800, 4, 3);
}
