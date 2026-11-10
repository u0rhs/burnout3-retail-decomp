// func_003CA6B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (inlined Release/destroy helpers, if/else on AreLockedPlayersConnected, scene const pointer, lost = !a && !b, controller lookup in an int-parameter inline).

// func_003CA6B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_003CA6B0_e3 {
    unsigned char pad_0[0x12C];
};

class CB3InputManager {
public:
    int AreLockedPlayersConnected();
    int GetLockedPlayersPort(signed char);

    unsigned char pad_0[0xD48];
    UnkStruct_003CA6B0_e3 field_D48[4];  // [G] element count unknown
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x8021];
    signed char field_8021[2];
};

struct UnkStruct_003CA6B0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject * field_C;
    CGt2dObject * field_10[2];
    CGt2dObject * field_18[2];
    unsigned char pad_20[0x230];
    unsigned char field_250;
};

extern CGt2dScene D_01E903E0;
extern UnkStruct_D_004EE040 D_004EE040;
extern CB3InputManager D_004F50C0;

extern "C" void Release__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Release()
extern "C" void Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour);
extern "C" int PadIsValid__20CB3ControllerMappingFv(void *);  // CB3ControllerMapping::PadIsValid()
extern "C" int func_0012EF20(void *);
extern "C" void func_003CA2F0(UnkStruct_003CA6B0 *, unsigned char, signed char);

// [G] inlined helpers (no names known)
static inline void func_003CA6B0_inl1(UnkStruct_003CA6B0 * self, unsigned char i)
{
    CGt2dScene * const scene = &D_01E903E0;
    int layer = self->field_8 + 1;
    if (self->field_18[i] != 0) {
        scene->DestructObject(layer, self->field_18[i]);
        self->field_18[i] = 0;
        scene->DestructObject(layer, self->field_10[i]);
        self->field_10[i] = 0;
    }
}

static inline void func_003CA6B0_inl2(UnkStruct_003CA6B0 * self)
{
    Release__20CB3MenuComponentBaseFv(self);
    CGt2dObject * o = self->field_C;
    int layer = self->field_8;
    if (o != 0) {
        CGt2dScene * scene = &D_01E903E0;
        if (o != 0) {
            scene->DestructObject(layer, o);
            self->field_C = 0;
        }
    }
    for (signed char i = 0; i < 2; i++) {
        func_003CA6B0_inl1(self, i);
    }
}

// [G] an int parameter: retail re-extends the signed char index at each later use (a signed char one is CSE'd)
static inline void * func_003CA6B0_inl5(int i)
{
    return &D_004F50C0.field_D48[D_004EE040.field_8021[i]];
}

// 0x003CA6B0
extern "C" void func_003CA6B0(UnkStruct_003CA6B0 * self)
{
    if (self->field_250 != 0) {
        func_003CA6B0_inl2(self);
        return;
    }
    if (!D_004F50C0.AreLockedPlayersConnected()) {
        if (self->field_C == 0) {
            CGt2dScene * const scene = &D_01E903E0;
            self->field_C = scene->ConstructObject(self->field_8, scene->field_14);
            Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(
                self->field_C, CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 480.0f), CGtV4d(0.0f, 0.0f, 0.0f, 0.5f));
        }
        for (signed char i = 0; i < 2; i++) {
            void * m = func_003CA6B0_inl5(i);
            signed char port = D_004F50C0.GetLockedPlayersPort(i);
            if (port != -1) {
                bool lost = !PadIsValid__20CB3ControllerMappingFv(m) && !func_0012EF20(m);
                if (!self->field_18[i]) {
                    if (lost) {
                        func_003CA2F0(self, i, port);
                    }
                } else if (!lost) {
                    func_003CA6B0_inl1(self, i);
                }
            }
        }
    } else {
        func_003CA6B0_inl2(self);
    }
}
