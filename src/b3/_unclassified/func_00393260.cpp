// func_00393260 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/UnkStruct_theMemMgr.h"

struct UnkStruct_00393260;

struct UnkStruct_00393260 {
    unsigned char pad_0[0x60];
    int field_60;
    int field_64;
    int field_68;
    unsigned char pad_6C[0x88];
    int field_F4[1];  // [G] element count unknown
    unsigned char pad_F8[0x1C];
    unsigned char field_114[1];  // [G] element count unknown
    unsigned char pad_115[0x7];
    unsigned char field_11C;
    unsigned char field_11D;
    unsigned char field_11E;
    unsigned char field_11F;
    unsigned char field_120;
    unsigned char field_121;
};

extern UnkStruct_theMemMgr theMemMgr;
extern "C" int AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" int func_003922D0(UnkStruct_00393260 *);

// 0x00393260
extern "C" void func_00393260(UnkStruct_00393260 * self)
{
    self->field_68 = 1;
    if (self->field_60 == 0) {
        int r0 = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 1, 1);
        self->field_60 = r0;
    }
    if (self->field_64 == 0) {
        int r1 = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 1, 2);
        self->field_64 = r1;
    }
    self->field_11C = 0;
    self->field_11D = 0;
    self->field_11E = 0;
    self->field_11F = 0;
    self->field_120 = 0;
    self->field_121 = 0;
    for (int i = 0; (i < 8); i++) {
        self->field_F4[i] = -1;
        self->field_114[i] = 0;
    }
    func_003922D0(self);
}
