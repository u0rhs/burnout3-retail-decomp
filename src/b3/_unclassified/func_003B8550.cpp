// func_003B8550 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_0051BA44.h"

struct UnkStruct_003B8550;
struct UnkStruct_003B8550_e0;

struct UnkStruct_003B8550_e0 {
    unsigned char pad_0[0x2];
};

struct UnkStruct_003B8550 {
    unsigned char pad_0[0x1800];
    UnkStruct_003B8550_e0 * field_1800;
};

extern UnkStruct_D_0051BA44 D_0051BA44;
extern "C" int func_00271A00(void *, int);
extern "C" void PrintInt__10CGtUnicodeFPUsii(void *, int, int, int);
extern "C" void func_003B8930(UnkStruct_003B8550_e0 *, int, void *, void *, void *);
extern "C" int Length__10CGtUnicodeFPCUs(UnkStruct_003B8550_e0 *);

// 0x003B8550
extern "C" UnkStruct_003B8550_e0 * func_003B8550(UnkStruct_003B8550 * self, float f0)
{
    UnkStruct_003B8550_e0 * t0 = self->field_1800;
    int mins = (int)(f0 / 60.0f);
    float secsF = f0 - 60.0f * (float)mins;
    int secs = (int)secsF;
    int r0 = func_00271A00(&D_0051BA44, 2461);
    unsigned char bm[16];
    unsigned char bs[16];
    unsigned char bh[16];
    PrintInt__10CGtUnicodeFPUsii(bm, mins, 1, 0);
    PrintInt__10CGtUnicodeFPUsii(bs, secs, 2, 0);
    PrintInt__10CGtUnicodeFPUsii(bh, (int)(100.0f * (secsF - (float)secs)), 2, 0);
    func_003B8930(t0, r0, bm, bs, bh);
    self->field_1800 = &self->field_1800[Length__10CGtUnicodeFPCUs(t0) + 1];
    return t0;
}
