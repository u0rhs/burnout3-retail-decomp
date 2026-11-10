// func_003CCA70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (find loop with goto exit, CGtRandom member, const float local for the reloaded 0.1f clamp literal).

#include "b3/_unclassified/GtRandom.h"

struct UnkStruct_003CCA70_3 {
    unsigned char pad_0[0x370];
    float field_370;
};

struct UnkStruct_003CCA70_a1 {
    unsigned char pad_0[0xCC4];
    UnkStruct_003CCA70_3 * field_CC4;
};

struct UnkStruct_003CCA70 {
    unsigned char pad_0[0x10];
    CGtRandom field_10;
    UnkStruct_003CCA70_a1 * field_18[0x41];  // [G] element count unknown
    int field_11C;
    int field_120[1];  // [G] element count unknown
    unsigned char pad_124[0x38B];
    unsigned char field_4AF;
};

// 0x003CCA70
extern "C" int func_003CCA70(UnkStruct_003CCA70 * self, UnkStruct_003CCA70_a1 * p0)
{
    // [G] find loop (goto exit), CGtRandom at +0x10 (inlined Random(), unsigned -> float)
    int i;
    for (i = 0; i < self->field_4AF; i++) {
        if (self->field_18[i] == p0) {
            goto found;
        }
    }
    i = -1;
found:
    if (i == -1) {
        return 0;
    }
    float v = p0->field_CC4->field_370;
    const float k = 0.1f;  // [G] a const local: retail reloads the literal in the then-block (a plain 0.1f is CSE'd)
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
