// func_00434CF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (CGtV2d local per arm copied to *field_34 (GtMathPs2.h); func_00434FF0 takes the float too).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
// lifter variant 0
// func_00434CF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00434CF0;
struct UnkStruct_00434CF0_5;
struct UnkStruct_00434CF0_6;
struct UnkStruct_D_004D1AA8;
struct UnkStruct_D_004D1AB4;
struct UnkStruct_D_01E90420;
struct UnkStruct_D_01E90424;

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D1AA8 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90420 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D1AB4 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00434CF0_5 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};

struct UnkStruct_00434CF0_6 {
    float field_0;
    float field_4;
};

struct UnkStruct_00434CF0 {
    unsigned char pad_0[0x34];
    CGtV2d * field_34;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_004D1AA8 D_004D1AA8;
extern UnkStruct_D_01E90420 D_01E90420;
extern UnkStruct_D_004D1AB4 D_004D1AB4;

extern "C" void func_00434FF0(UnkStruct_00434CF0 *, float);
extern "C" void func_00434DD0(UnkStruct_00434CF0 *, float);

// 0x00434CF0
extern "C" void func_00434CF0(UnkStruct_00434CF0 * self, float f0)
{
    int t0 = D_01E90424.field_0;
    if (t0 == 2) {
        CGtV2d v(D_004D1AA8.field_0, (1.0f - D_01E90420.field_0) * D_004D1AB4.field_0);
        *self->field_34 = v;
    } else if (t0 == 3) {
        CGtV2d v(D_004D1AA8.field_0, (1.0f - D_01E90420.field_0) * D_004D1AB4.field_0);
        *self->field_34 = v;
    }
    func_00434FF0(self, f0);
    func_00434DD0(self, f0);
}
