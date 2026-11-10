// func_003CC770 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (near15: slot search as a static inline with early returns (goto form filled the jr delay slot)).

// func_003CC770 -- hand-written (s321): for every slot with a car, field_120[i] = the body of the proven sibling
// func_003CCA70 (find the car's slot, scale its value by a clamped car factor, add a random term), inlined [L]
// (retail's loop body is func_003CCA70's code with its constants hoisted). near15: the slot search is its own static
// inline with early returns (func_003CC770_inl0, placeholder [G]); with the goto form retail's trailing `sb; jr ra; nop`
// came out as `jr ra; sb`. Types placeholders [G].

#include "b3/_unclassified/GtRandom.h"

struct UnkStruct_003CC770_3 {
    unsigned char pad_0[0x370];
    float field_370;
};

struct UnkStruct_003CC770_a1 {
    unsigned char pad_0[0xCC4];
    UnkStruct_003CC770_3 * field_CC4;
};

struct UnkStruct_003CC770 {
    unsigned char pad_0[0x10];
    CGtRandom field_10;
    UnkStruct_003CC770_a1 * field_18[0x42];
    int field_120[0x42];
    unsigned char pad_228[0x280];
    unsigned char field_4A8;
    unsigned char pad_4A9[6];
    unsigned char field_4AF;
};

static inline int func_003CC770_inl0(UnkStruct_003CC770 * self, UnkStruct_003CC770_a1 * p0)
{
    for (int i = 0; i < self->field_4AF; i++) {
        if (self->field_18[i] == p0) {
            return i;
        }
    }
    return -1;
}

static inline int func_003CC770_inl1(UnkStruct_003CC770 * self, UnkStruct_003CC770_a1 * p0)
{
    int i = func_003CC770_inl0(self, p0);
    if (i == -1) {
        return 0;
    }
    float v = p0->field_CC4->field_370;
    const float k = 0.1f;
    if (v < k) {
        v = k;
    }
    v = v * 1.69f;
    if (!(v <= 1.0f)) {
        v = 1.0f;
    }
    int r = (int)((float)self->field_120[i] * v);
    if (r > 100000) {
        r = 100000;
    }
    return r + (int)(25.0f * (-1.0f * (2.3283064e-10f * (float)self->field_10.Random())));
}

// 0x003CC770
extern "C" void func_003CC770(UnkStruct_003CC770 * self)
{
    for (int i = 0; i < 0x42; i++) {
        if (self->field_18[i] != 0) {
            self->field_120[i] = func_003CC770_inl1(self, self->field_18[i]);
        }
    }
    self->field_4A8 = 0;
}
