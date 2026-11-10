// func_001AB010 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

struct UnkStruct_001AB010;

struct UnkStruct_001AB010 {
    unsigned char pad_0[0xF0];
    GtMathPs2::CGtV3d field_F0;
    GtMathPs2::CGtV3d field_100;
    GtMathPs2::CGtV3d field_110;
    GtMathPs2::CGtV3d field_120;
    GtMathPs2::CGtV3d field_130;
};

// 0x001AB010
extern "C" void func_001AB010(UnkStruct_001AB010 * self)
{
    self->field_F0.Zero();
    self->field_100.Zero();
    self->field_110.Zero();
    self->field_120.Zero();
    self->field_130.Zero();
}
