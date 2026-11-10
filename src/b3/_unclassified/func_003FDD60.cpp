// func_003FDD60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_01EA5470.h"

struct UnkStruct_func_003FDD00;

struct UnkStruct_func_003FDD00 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01EA5470 D_01EA5470;
extern UnkStruct_func_003FDD00 func_003FDD00;
extern "C" void func_003C1C40(int, const void *);
extern "C" void qsort(void *, int, int, void *);
extern "C" void func_003FCED0(void *);

// 0x003FDD60
// pass1: a1 (the page's data record, read only by func_003C1C40) is forwarded untouched
extern "C" void func_003FDD60(int n0, const void * rec)
{
    func_003C1C40(n0, rec);
    qsort(&D_01EA5470, 8, 56, &func_003FDD00);
    func_003FCED0((void *)(n0));
}
