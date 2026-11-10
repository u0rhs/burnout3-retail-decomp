// Hand-written; the lifter refused it (cases 2-4 as header CGtV2d: r = *s; r -= CGtV2d(0, 32*v); *field_C = r (pass3a)).

// func_0038ABE0 -- [L] DNAT: CB3PromptBarComponent::Update(float) (research/proto/new_names.csv, medium); a0 only, the float is unused/unreadable here
#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;

// [L] the debug-menu state and its 0..1 transition amount (same declarations as B3HelpBarComponent_0031B860.cpp). Padded for N51.
struct UnkStruct_D_01E90424 {
    int value;
    unsigned char pad[0x100];
};
struct UnkStruct_D_01E90420 {
    float value;
    unsigned char pad[0x100];
};
struct UnkStruct_D_01E89792 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

// [G] a 2d object's 0x40-byte object space; the top-left position leads.
typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_0038ABE0_space {
    u_long128 field_0[2];
    int field_20[6];
    int field_38;
    int field_3C;
};

struct UnkStruct_0038ABE0 {
    unsigned char pad_0[0xC];
    UnkStruct_0038ABE0_space * field_C;
    UnkStruct_0038ABE0_space * field_10;
    UnkStruct_0038ABE0_space * field_14;
    UnkStruct_0038ABE0_space * field_18;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E90420 D_01E90420;
extern UnkStruct_D_01E89792 D_01E89792;

// 0x0038ABE0
extern "C" void func_0038ABE0(UnkStruct_0038ABE0 * self)
{
    switch (D_01E90424.value) {
    case 2:
    case 3:
    case 4:
        if (D_01E89792.field_0 != 0) {
            CGtV2d * s = (CGtV2d *)self->field_14;
            CGtV2d r = *s;
            r -= CGtV2d(0.0f, 32.0f * D_01E90420.value);
            *(CGtV2d *)self->field_C = r;
        }
        break;
    case 5:
        if (D_01E89792.field_0 != 0) {
            CGtV2d * d = (CGtV2d *)self->field_C;
            CGtV2d * s = (CGtV2d *)self->field_14;
            *d = CGtV2d(d->marValues[0], s->marValues[1] - 32.0f);
        } else {
            CGtV2d * s = (CGtV2d *)self->field_14;
            float sy = s->marValues[1];
            CGtV2d * d = (CGtV2d *)self->field_C;
            if (d->marValues[1] != sy) {
                *d = CGtV2d(d->marValues[0], sy);
            }
        }
    case 0:
    case 1: {
        float z = 0.0f;
        CGtV2d r(0.0f, z + 96.0f + -96.0f * D_01E90420.value);
        *(CGtV2d *)self->field_18 = r;
        break;
    }
    }
    if (self->field_10 != 0) {
        *self->field_10 = *self->field_C;
    }
}
