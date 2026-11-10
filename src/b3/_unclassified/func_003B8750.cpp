// func_003B8750 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051BA44.h"

struct UnkStruct_003B8750_0 {
    unsigned char pad_0[0x30];
};

extern UnkStruct_D_0051BA44 D_0051BA44;
extern "C" int func_00271A00(void *, int);
extern "C" void PrintInt__10CGtUnicodeFPUsii(void *, int, int, int);
extern "C" void func_003B8930(void *, int, void *, void *, void *);

// 0x003B8750
extern "C" void func_003B8750(void *n0_, float f0)
{
    int n0 = (int)n0_;
    unsigned short a[8];
    unsigned short b[8];
    unsigned short c[8];
    int m = (int)(f0 / 60.0f);
    float rem = f0 - 60.0f * m;
    int sec = (int)rem;
    int id = func_00271A00(&D_0051BA44, 2461);
    PrintInt__10CGtUnicodeFPUsii(a, m, 1, 0);
    PrintInt__10CGtUnicodeFPUsii(b, sec, 2, 0);
    PrintInt__10CGtUnicodeFPUsii(c, (int)(100.0f * (rem - sec)), 2, 0);
    func_003B8930((void *)(n0), id, a, b, c);
}
