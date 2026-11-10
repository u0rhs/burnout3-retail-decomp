// func_00438F30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (void (Render returns nothing); early return on 0.0f == field_30; CGtV2d stack temporary assigned to field_14->field_8 (GtMathPs2.h)).

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;

struct UnkStruct_00438F30;
struct UnkStruct_00438F30_1;
struct UnkStruct_00438F30_6;

struct UnkStruct_00438F30_1 {
    unsigned char pad_0[0x30];
    float field_30;
};

struct UnkStruct_D_00665EC0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665EC4 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E105C {
    float field_0;
};

struct UnkStruct_D_004E13A8 {
    float field_0;
};

struct UnkStruct_00438F30_6 {
    unsigned char pad_0[0x8];
    CGtV2d field_8;
};

struct UnkStruct_00438F30 {
    unsigned char pad_0[0x14];
    UnkStruct_00438F30_6 * field_14;
    unsigned char pad_18[0x1C];
    UnkStruct_00438F30_1 * field_34;
};

extern UnkStruct_D_00665EC0 D_00665EC0;
extern UnkStruct_D_00665EC4 D_00665EC4;
extern UnkStruct_D_004E105C D_004E105C;
extern UnkStruct_D_004E13A8 D_004E13A8;

extern "C" void Render__10CGt2dSceneFv(void *);  // CGt2dScene::Render()
extern "C" void func_00438FB0(UnkStruct_00438F30 *);

// 0x00438F30
extern "C" void func_00438F30(UnkStruct_00438F30 * self)
{
    func_00438FB0(self);
    if (0.0f == self->field_34->field_30) {
        return;
    }
    CGtV2d v(D_004E105C.field_0 * (float)D_00665EC0.field_0, D_004E13A8.field_0 * (float)D_00665EC4.field_0);
    self->field_14->field_8 = v;
    Render__10CGt2dSceneFv(self);
}
