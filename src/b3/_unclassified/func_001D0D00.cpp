// func_001D0D00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (field_B0 as CGtV4d read via W() (WAxisType copy ctor sq-through-pointer) + segment-type inline with element-pointer local).

// func_001D0D00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished (near19).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3RaceCarPhysics;

struct UnkStruct_001D0D00;
struct UnkStruct_001D0D00_1;
struct UnkStruct_001D0D00_2;
struct UnkStruct_001D0D00_4;
struct UnkStruct_001D0D00_5;
struct UnkStruct_001D0D00_e0;
struct UnkStruct_D_0064D37A;

struct UnkStruct_001D0D00_1 {
    unsigned char pad_0[0x18B4];
    UnkStruct_001D0D00_4 * field_18B4;
    unsigned short field_18B8;
};

struct UnkStruct_001D0D00_2 {
    unsigned char pad_0[0x1BE8];
    int field_1BE8;
    int field_1BEC;
    unsigned char pad_1BF0[0x7D0];
    float field_23C0;
};

struct UnkStruct_001D0D00_4 {
    unsigned char pad_0[0x4];
    UnkStruct_001D0D00_5 * field_4;
};

struct UnkStruct_001D0D00_5 {
    unsigned char pad_0[0x8];
    UnkStruct_001D0D00_e0 * field_8;
};

struct UnkStruct_001D0D00_e0 {
    unsigned char pad_0[0x3];
    unsigned char field_3;
    unsigned char pad_4[0x6];
};

struct UnkStruct_D_0064D37A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_001D0D00 {
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
    unsigned char pad_C0[0x144];
    int field_204;
    unsigned char pad_208[0x11EC];
    UnkStruct_001D0D00_1 * field_13F4;
    unsigned char pad_13F8[0x158];
    unsigned char field_1550;
    unsigned char pad_1551[0x17];
    UnkStruct_001D0D00_2 * field_1568;
};

extern UnkStruct_D_0064D37A D_0064D37A;

extern "C" int ResetOnTrack__17CB3RaceCarPhysicsFbP17CB3RaceCarPhysics(void *, bool, void *);  // CB3RaceCarPhysics::ResetOnTrack(bool,CB3RaceCarPhysics*)
extern "C" void func_00143860(UnkStruct_001D0D00_2 *, unsigned char);
extern "C" void func_001AB610(UnkStruct_001D0D00 *, int);
extern "C" void func_001AB010(UnkStruct_001D0D00 *);
extern "C" void func_001BED00(UnkStruct_001D0D00 *, float);

// [G] inlined segment-type read (callee name unknown)
static inline int func_001D0D00_inl1(const UnkStruct_001D0D00_4 * t1, unsigned short seg)
{
    const UnkStruct_001D0D00_e0 * e = &t1->field_4->field_8[seg];
    return e->field_3 & 7;
}
// near19: field_B0 is a CGtV4d read with W() (the WAxisType copy ctor gives retail's addiu/sq-through-pointer
// and the 0x3C lane load); the segment-type test is a static inline helper (name unknown: placeholder, [G]) taking
// an element-pointer local.
// 0x001D0D00
extern "C" void func_001D0D00(UnkStruct_001D0D00 * self)
{
    UnkStruct_001D0D00_1 * t0 = self->field_13F4;
    if (t0->field_18B4 != 0 && func_001D0D00_inl1(t0->field_18B4, t0->field_18B8) == 5) {
        func_00143860(self->field_1568, D_0064D37A.field_0);
        return;
    }

    UnkStruct_001D0D00_2 * t2 = self->field_1568;
    float v;
    if (t2->field_1BEC == 0 && t2->field_1BE8 == 1) {
        v = t2->field_23C0;
    } else {
        v = self->field_B0.W();
    }
    func_001AB610(self, self->field_204);
    func_001AB010(self);
    if (ResetOnTrack__17CB3RaceCarPhysicsFbP17CB3RaceCarPhysics(self, 0, 0) == 0) {
        return;
    }
    func_001BED00(self, v);
    self->field_1550 = 1;
}
