// UpdateWibbleAnimationOut__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (d=f150-f154 in one local; && guard; return !(d>=1.0f) as bool; D_004E09BC.field_0 volatile [G] (retail reloads it with no store between)).

// from build/vt\try_func_003D46A0_best.cpp
// UpdateWibbleAnimationOut__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

class CGt2dObject;

struct UnkStruct_003D46A0;
struct UnkStruct_003D46A0_1;
struct UnkStruct_003D46A0_3;
struct UnkStruct_D_004E09BC;

struct UnkStruct_003D46A0_1 {
    unsigned char pad_0[0x2C];
    float field_2C;
    unsigned char pad_30[0x1];
    unsigned char field_31;
};

struct UnkStruct_D_004E09BC {
     volatile float field_0;  // [G] volatile: retail reloads it for the subtraction with no store in between
};

struct UnkStruct_003D46A0_3 {
    unsigned char pad_0[0x10];
    GtMathPs2::CGtV4d field_10;
};

struct UnkStruct_003D46A0 {
    int field_0;
    unsigned char pad_4[0x4];
    int field_8;
    UnkStruct_003D46A0_1 * field_C;
    UnkStruct_003D46A0_3 * field_10;
    unsigned char pad_14[0x13C];
    float field_150;
    float field_154;
};

extern UnkStruct_D_004E09BC D_004E09BC;

extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);  // CGt2dScene::DestructObject(int,CGt2dObject*)
extern "C" void ModifyEffect__23CB3StylisedText2dObjectFQ223CB3StylisedText2dObject19EStylisedTextEffect(UnkStruct_003D46A0_1 *, void *);

// 0x003D46A0
extern "C" bool UpdateWibbleAnimationOut__27CB3HUDPrimaryMessageHandlerFP27CB3HUDPrimaryMessageHandler(UnkStruct_003D46A0 * self)
{
    UnkStruct_003D46A0_1 * t0 = self->field_C;
    float d = self->field_150 - self->field_154;
    if (t0->field_31 != 3) {
        ModifyEffect__23CB3StylisedText2dObjectFQ223CB3StylisedText2dObject19EStylisedTextEffect(t0, (void *)(3));
    }
    t0->field_2C = 1.0f - d;
    UnkStruct_003D46A0_3 * t3 = self->field_10;
    if (t3 != 0 && !(d <= 0.25f)) {
        if (d < D_004E09BC.field_0) {
            t3->field_10.SetA(2.5f * (D_004E09BC.field_0 - d));
        } else {
            DestructObject__10CGt2dSceneFiP11CGt2dObject((void *)self->field_0, self->field_8, (CGt2dObject*)t3);
            self->field_10 = 0;
        }
    }
    return !(d >= 1.0f);
}
