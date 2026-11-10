// B3VehiclePhysics.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3VehiclePhysics.cpp.
// Area: src/b3/gamesource/Physics, same unit as the hand-placed file there (its docs/layout.md row).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/classes/UnkStruct_D_0055EF70.h"

struct UnkStruct_001CBCE0;
struct UnkStruct_001CBCE0_1;
struct UnkStruct_001CBCE0_2;
struct UnkStruct_001CBCE0_3;

struct UnkStruct_001CBCE0_1 {
    unsigned char pad_0[0x1023];
    unsigned char field_1023;
    UnkStruct_001CBCE0_2 * field_1024;
};

struct UnkStruct_001CBCE0_2 {
    signed char field_0;
};

struct UnkStruct_001CBCE0_3 {
    signed char field_0;
};

struct UnkStruct_001CBCE0 {
    unsigned char pad_0[0xCC4];
    UnkStruct_001CBCE0_1 * field_CC4;
};

extern UnkStruct_D_0055EF70 D_0055EF70;
extern u_long128 D_004B7DA0;
extern u_long128 D_004B7DB0;
extern "C" int func_001B86A0(void *, UnkStruct_001CBCE0 *, int, int);
extern "C" void func_00333990(int);
extern "C" void FireAirRamWithDirection__17CB3VehiclePhysicsFUifQ29GtMathPs26CGtV3db(void *, unsigned int, float, void *, bool);

// func_001CBCE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001CBCE0
extern "C" void func_001CBCE0(UnkStruct_001CBCE0 * self)
{
    if (self->field_CC4->field_1023 != 0) {
        return;
    }
    if (self->field_CC4->field_1024 == 0) {
        return;
    }
    self->field_CC4->field_1023 = 1;
    for (int i = 0; (i < ((UnkStruct_001CBCE0_3 *)self->field_CC4->field_1024)->field_0); i++) {
        int r0 = func_001B86A0(&D_0055EF70, self, i, 2);
        if (r0 == 0) {
            break;
        }
        func_00333990(r0);
    }
}

// func_001CC4C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001CC4C0
extern "C" void func_001CC4C0(void * self, unsigned int flags, bool b, float f)
{
    u_long128 dir;
    if ((flags & 0x40) != 0 || (flags & 0x20) != 0) {
        dir = D_004B7DA0;
    } else {
        dir = D_004B7DB0;
    }
    FireAirRamWithDirection__17CB3VehiclePhysicsFUifQ29GtMathPs26CGtV3db(self, flags, f, &dir, b);
}
