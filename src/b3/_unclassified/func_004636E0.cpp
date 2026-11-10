// func_004636E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_D_004D3B70.h"

struct UnkStruct_004636E0;
struct UnkStruct_004636E0_0;

struct UnkStruct_004636E0_0 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

struct UnkStruct_004636E0 {
    char * field_0;
};

extern UnkStruct_D_004D3B70 D_004D3B70;
extern "C" void * memset(void *, int, unsigned int);
extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" void func_004652B0(int, void *, void *);
extern "C" int func_00360AE0(int, int, int);

// 0x004636E0
extern "C" int func_004636E0(UnkStruct_004636E0 * self, int p0, int p1, int p2)
{
    int a0_ = 4;
    int a1_ = 1;
    func_004652B0(p2, &a0_, &a1_);
    int b0 = 4;
    int b1 = 1;
    func_004652B0(p2, &b0, &b1);
    unsigned int n = p1 + 12;
    unsigned int a = b1;
    unsigned int sz = (n < a) ? a : n + (a - n % a) % a;
    if (self == 0) {
        return 4;
    }
    self->field_0 = (char *)func_00360AE0(p0, sz, a0_);
    if (self->field_0 == 0) {
        return 6;
    }
    memset(self->field_0, 0, sz);
    memcpy(self->field_0, &D_004D3B70, 12);
    self->field_0 += 12;
    return 0;
}
