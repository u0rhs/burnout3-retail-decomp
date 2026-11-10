// func_0026BCA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/classes/UnkStruct__gpMeshCache.h"

struct UnkStruct_0026BCA0;

struct UnkStruct_0026BCA0 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    unsigned char pad_30[0x5C];
    int field_8C;
    unsigned char pad_90[0x4];
    int field_94;
    unsigned char field_98;
    signed char field_99;
    unsigned char field_9A;
    unsigned char pad_9B[0x1];
    unsigned char field_9C;
    unsigned char pad_9D[0x3];
    unsigned long field_A0;
    unsigned long field_A8;
    unsigned long field_B0;
    unsigned long field_B8;
    unsigned char pad_C0[0x8];
    int field_C8;
};

extern UnkStruct__gpMeshCache _gpMeshCache;

// 0x0026BCA0
extern "C" void func_0026BCA0(UnkStruct_0026BCA0 * self)
{
    self->field_94 = 0;
    self->field_9A = 0;
    self->field_9C = 0;
    _gpMeshCache.field_0 = 0;
    self->field_98 = 0;
    self->field_A0 = 0;
    self->field_A8 = 0;
    self->field_B0 = 0;
    self->field_B8 = 0;
    self->field_99 = -1;
    unsigned long c = 0x10000000;
    u_long128 q1;
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(c), "r"(c));
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(c + 1), "r"(0x6C0103F501000404));
    u_long128 q2;
    asm("pcpyld %0, %2, %1" : "=r"(q2) : "r"(c), "r"(0x17000000));
    self->field_8C = 0;
    self->field_C8 = 0;
    self->field_0 = q1;
    self->field_10 = q0;
    self->field_20 = q2;
}
