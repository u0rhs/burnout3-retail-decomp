// SetAIOutOfRange__8CB3AICarFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

struct UnkStruct_001419D0;

struct UnkStruct_001419D0 {
    unsigned char pad_0[0x19B0];
    GtMathPs2::CGtV3d field_19B0;
    GtMathPs2::CGtV3d field_19C0;
};

// 0x001419D0
extern "C" void SetAIOutOfRange__8CB3AICarFv(UnkStruct_001419D0 * self)
{
    self->field_19B0.Zero();
    self->field_19C0.Zero();
}
