// func_00452630 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (int return 1; CGtV2d local copied to *field_14; the 60.0f spacing as one float local s (mul.s operand order)).

// func_00452630 -- tiny-function batch (tools/tiny_batch.py, lifted; hand-matched).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths). [G] lays out field_138 items in a column at x 640, 60 apart, centred on 294.

#include "b3/GtMathPs2.h"

struct UnkStruct_00452630_e0 {
    unsigned char pad_0[0x14];
    GtMathPs2::CGtV2d * field_14;
    unsigned char pad_18[0xC];
};

struct UnkStruct_00452630 {
    UnkStruct_00452630_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_24[0x110];
    int field_134;
    int field_138;
};

extern "C" void func_00453560(UnkStruct_00452630 *);
extern "C" void func_004526F0(UnkStruct_00452630 *);

// 0x00452630
extern "C" int func_00452630(UnkStruct_00452630 * self)
{
    func_00453560(self);
    self->field_134 = 0;
    func_004526F0(self);
    int n = self->field_138;
    if (n != 0) {
        float s = 60.0f;
        float y = 294.0f - 0.5f * ((float)(n - 1) * s);
        for (int i = 0; i < n; i++) {
            GtMathPs2::CGtV2d p(640.0f, y);
            *self->field_0[i].field_14 = p;
            y += s;
        }
    }
    return 1;
}
