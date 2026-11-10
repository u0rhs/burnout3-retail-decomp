// func_003BA4E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01E8D450.h"
#include "b3/classes/UnkStruct_D_01E8D45A.h"
#include "b3/classes/UnkStruct_D_01EA5470.h"

struct UnkStruct_func_003BA300;

struct UnkStruct_func_003BA300 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01E8D45A D_01E8D45A;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_D_01EA5470 D_01EA5470;
extern UnkStruct_func_003BA300 func_003BA300;
extern "C" void func_003C1E00(int, const void *);
extern "C" void qsort(void *, int, int, void *);
extern "C" void func_003B9880(void *);
extern "C" void func_003B90E0(void *, bool);

// 0x003BA4E0
// pass1: a1 (the page's data record, read only by func_003C1E00) is forwarded untouched
extern "C" void func_003BA4E0(int n0, const void * rec)
{
    func_003C1E00(n0, rec);
    qsort(&D_01EA5470, 8, 56, &func_003BA300);
    bool v0;
    if (D_01E8D45A.field_0 != 0) {
        ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
        func_003B9880((void *)(n0));
        v0 = 1;
    } else {
        v0 = 0;
    }
    func_003B90E0((void *)(n0), v0);
}
