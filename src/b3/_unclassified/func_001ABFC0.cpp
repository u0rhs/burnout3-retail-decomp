// func_001ABFC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/classes/UnkStruct_D_004E2704.h"

struct UnkStruct_001ABFC0;
struct UnkStruct_001ABFC0_1;
struct UnkStruct_001ABFC0_4;
struct UnkStruct_001ABFC0_a1;
struct UnkStruct_001ABFC0_e0;

struct UnkStruct_001ABFC0_1 {
    unsigned char pad_0[0x4];
    unsigned char field_4;
};

struct UnkStruct_001ABFC0_a1 {
    unsigned char pad_0[0x200];
    UnkStruct_001ABFC0_4 * field_200;
};

struct UnkStruct_001ABFC0_4 {
    int field_0;
    UnkStruct_001ABFC0_e0 * field_4;
    short * field_8;
};

struct UnkStruct_001ABFC0_e0 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    u_long128 field_30;
};

struct UnkStruct_001ABFC0 {
    unsigned char pad_0[0x10];
    u_long128 field_10;
    u_long128 field_20;
    u_long128 field_30;
    u_long128 field_40;
    unsigned char pad_50[0x10];
    UnkStruct_001ABFC0_1 * field_60;
};

extern UnkStruct_D_004E2704 D_004E2704;

// 0x001ABFC0
extern "C" bool func_001ABFC0(const UnkStruct_001ABFC0 * self, UnkStruct_001ABFC0_a1 * p0)
{
    UnkStruct_001ABFC0_1 * t0 = self->field_60;
    switch (t0->field_4) {
    case 32: case 36: case 35: case 34:
        return 1;
    default:
        break;
    }
    bool ok;
    if (D_004E2704.field_0 != 0) goto full;
    {
        UnkStruct_001ABFC0_4 * t1 = p0->field_200;
        int t2 = t1->field_0;
        if (t2 >= 96) goto full;
        UnkStruct_001ABFC0_e0 * t3 = t1->field_4;
        UnkStruct_001ABFC0_e0 *e = &t3[t2];
        e->field_0 = self->field_20;
        e->field_10 = self->field_30;
        e->field_20 = self->field_40;
        e->field_30 = self->field_10;
        p0->field_200->field_8[t2] = *(unsigned short *)&t0->field_4;
        p0->field_200->field_0 = t2 + 1;
        ok = true;
        goto done;
    }
full:
    D_004E2704.field_0 = 1;
    ok = false;
done:
    return ok;
}
