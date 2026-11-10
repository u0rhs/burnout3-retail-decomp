// func_001D0A90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

struct UnkStruct_001D0A90;
struct UnkStruct_001D0A90_0;

struct UnkStruct_001D0A90_0 {
    int field_0;
    float field_4;
    int field_8;
    unsigned char pad_C[0x14];
};

struct UnkStruct_001D0A90 {
    GtMathPs2::CGtV3d field_0;
    GtMathPs2::CGtV3d field_10;
    u_long128 field_20;
    GtMathPs2::CGtV3d field_30;
    GtMathPs2::CGtV3d field_40;
    unsigned char pad_50[0x4];
    int field_54;
    int field_58;
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    unsigned char pad_6C[0x8];
    int field_74;
    int field_78;
    unsigned char pad_7C[0x14];
    int field_90;
    float field_94;
    unsigned char pad_98[0x8];
    unsigned char field_A0;
    unsigned char field_A1;
    unsigned char field_A2;
    unsigned char pad_A3[0x1];
    unsigned char field_A4;
    unsigned char field_A5;
    unsigned char field_A6;
    unsigned char field_A7;
    unsigned char pad_A8[0x8];
    short field_B0;
    unsigned char field_B2;
    unsigned char field_B3;
    unsigned char field_B4;
};

extern "C" void * memset(void *, int, unsigned int);

// 0x001D0A90
extern "C" void func_001D0A90(UnkStruct_001D0A90 * self)
{
    UnkStruct_001D0A90_0 local;  // [G] the frame's one local (size: up to the frame top)
    // [C] retail copies the 16-byte local with `lq a0, 32(sp)` (0x1D0ACC) after writing only +0/+4/+8 (0x1D0AB4..0x1D0AC0):
    // self->field_20's w (+0x2C) is the stale stack word at sp+0x2C. Retail's own read, not a decomp error; on a host it
    // is an uninitialized local (native3: the Prepare family's 4 words via CB3VehiclePhysics::Prepare's 4 calls, 0x1CF324).
    memset(self, 0, 192);
    local.field_4 = 1.0f;
    local.field_0 = 0;
    local.field_8 = 0;
    self->field_0.Zero();
    self->field_10.Zero();
    u_long128 t0 = *(u_long128 *)&local.field_0;
    self->field_20 = t0;
    self->field_30.Zero();
    self->field_40.Zero();
    self->field_54 = 0;
    self->field_58 = 0;
    self->field_5C = 0;
    self->field_60 = 0;
    self->field_64 = 0;
    self->field_68 = 0;
    self->field_78 = 0;
    self->field_A0 = 0;
    self->field_A1 = 0;
    self->field_A2 = 0;
    self->field_A4 = 0;
    self->field_A5 = 0;
    self->field_A6 = 0;
    self->field_A7 = 0;
    self->field_90 = 0;
    self->field_94 = -1.0f;
    self->field_B0 = 0;
    self->field_B2 = 0;
    self->field_B3 = 0;
    self->field_B4 = 0;
    self->field_74 = 0;
}
