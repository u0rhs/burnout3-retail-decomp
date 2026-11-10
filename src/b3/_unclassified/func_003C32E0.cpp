// func_003C32E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_theMemMgr.h"

struct UnkStruct_003C32E0;
struct UnkStruct_003C32E0_3;

struct UnkStruct_003C32E0_3 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual int vfunc_24();
};

struct UnkStruct_003C32E0 {
    UnkStruct_003C32E0_3 * field_0;
    unsigned char field_4;
    unsigned char pad_5[0xB];
    int field_10[1];  // [G] element count unknown
    unsigned char pad_14[0x48];
    int field_5C[1];  // [G] element count unknown
    unsigned char pad_60[0x88];
    int field_E8;
    int field_EC;
    int field_F0;
};

extern UnkStruct_theMemMgr theMemMgr;
extern "C" void * memset(void *, int, unsigned int);
extern "C" void ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);

// 0x003C32E0
extern "C" void func_003C32E0(UnkStruct_003C32E0 * self)
{
    for (int i = 0; (i < self->field_E8); i++) {
        if (self->field_10[i] != 0) {
            ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 6, i);
            self->field_10[i] = 0;
        }
    }
    for (int i1 = 0; (i1 < self->field_EC); i1++) {
        if (self->field_5C[i1] != 0) {
            ReleaseBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 7, i1);
            self->field_5C[i1] = 0;
        }
    }
    memset(((char *)self + 0x10), 0, 76);
    memset(((char *)self + 0x5C), 0, 140);
    self->field_4 = 1;
    if (self->field_0 != 0) {
        int m0 = 2;
        while (m0 != 1) {
            int r4 = self->field_0->vfunc_24();
            m0 = r4;
        }
        self->field_0->vfunc_C();
    }
    self->field_0 = 0;
    self->field_F0 = 24;
}
