// func_003F5940 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

#include "b3/classes/UnkStruct_D_004CE2E0.h"
#include "b3/classes/UnkStruct_D_004CE2E2.h"
#include "b3/classes/UnkStruct_D_004CE2E4.h"

struct UnkStruct_003F5940;

struct UnkStruct_003F5940 {
    float field_0;
    float field_4;
};

extern UnkStruct_D_004CE2E4 D_004CE2E4;
extern UnkStruct_D_004CE2E0 D_004CE2E0;
extern UnkStruct_D_004CE2E2 D_004CE2E2;

// 0x003F5940
extern "C" void func_003F5940(UnkStruct_003F5940 * self, int p0, int p1)
{
    int v0;
    switch (p0) {
    case 0:
        v0 = 0;
        break;
    case 1:
        v0 = 9;
        break;
    case 2:
        v0 = 21;
        break;
    default:
        v0 = 0;
        break;
    }
    int i = p1 + v0;
    short s0 = D_004CE2E4.field_0[i].field_0;
    short s1 = D_004CE2E0.field_0[i].field_0;
    short s2 = D_004CE2E2.field_0[i].field_0;
    GtMathPs2::CGtV2d local(s1 + (400.0f * s0) / 416.0f, (float)s2 + (float)s0);
    *(GtMathPs2::CGtV2d *)self = local;
}
