// func_00150280 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (bool p0, early return on p0 == field, then if/else (not early return) with pointer-to-field inner test).

// lifter variant 0
// func_00150280 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

struct UnkStruct_00150280;
struct UnkStruct_00150280_1;

struct UnkStruct_00150280_1 {
    unsigned char pad_0[0x1524];
    int field_1524;
    unsigned char pad_1528[0xC];
    float field_1534;
};

struct UnkStruct_00150280 {
    unsigned char pad_0[0x19C0];
    GtMathPs2::CGtV3d field_19C0;
    unsigned char pad_19D0[0xA60];
    UnkStruct_00150280_1 * field_2430;
    unsigned char pad_2434[0x394];
    unsigned char field_27C8;
};

extern "C" void ResetTarget__11CB3AITargetFv(void *);  // CB3AITarget::ResetTarget()

// 0x00150280
extern "C" void func_00150280(UnkStruct_00150280 * self, bool p0)
{
    if (p0 == self->field_27C8) return;
    self->field_27C8 = p0;
    if (self->field_27C8 != 0) {
        self->field_19C0.Zero();
        ResetTarget__11CB3AITargetFv(((char *)self + 0x19F0));
    } else {
        self->field_2430->field_1534 = 1.0f;
        int * pp = &self->field_2430->field_1524;
        if (*pp == 4) {
            *pp = 0;
        }
    }
}
