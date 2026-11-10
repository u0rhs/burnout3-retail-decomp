// NONMATCHING: func_0030B190 -- retail 230 / ours 230 instructions, 12 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: a221: per-arm 2.0f*dt (no shared step) 25->12; remaining: t in f1 vs f5, retail reloads field_4 in Min arm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
class CB3Burn {
public:
    static float gmarBoostBarSizes[4];
};
struct UnkStruct_0030B190_burn {
    unsigned char pad_0[0x38];
    float field_38;
    unsigned char pad_3C[0x16];
    unsigned char field_52;
};
struct UnkStruct_0030B190_self {
    UnkStruct_0030B190_burn *field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
};
struct UnkStruct_0030B190_sub;
struct UnkStruct_0030B190_sub { unsigned char pad_0[0x1033]; unsigned char field_1033; };
struct UnkStruct_0030B190_plr {
    unsigned char pad_0[0xB0];
    GtMathPs2::CGtV4d field_B0;
    unsigned char pad_C0[0xC04];
    UnkStruct_0030B190_sub *field_CC4;
    unsigned char pad_CC8[0x70C];
    float field_13D4;
};
struct UnkStruct_0030B190_car { unsigned char pad_0[0x19AC]; signed char field_19AC; };
struct UnkStruct_0030B190_ent { UnkStruct_0030B190_plr *field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_D_0055EFEC_B190 { UnkStruct_0030B190_ent field_0[1]; };
struct UnkStruct_D_004F509C_B190 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0055EFEC_B190 D_0055EFEC;
extern UnkStruct_D_004F509C_B190 D_004F509C;

static inline float func_0030B190_inl1(float x, float lo, float hi)
{
    if (x <= lo) return lo;
    if (x < hi) return (x - lo) / (hi - lo);
    return 1.0f;
}
static inline float func_0030B190_inl2(float x)
{
    if (x <= 100.0f) return 0.0f;
    if (x < 165.0f) return (x - 100.0f) / 65.0f;
    return 1.0f;
}
extern "C" void func_0030B190(UnkStruct_0030B190_self *self, UnkStruct_0030B190_car *car)
{
    float dt = D_004F509C.field_0;
    float k1 = 0.3f;
    float k2 = 2.2369363f;
    signed char pi = car->field_19AC;
    UnkStruct_D_0055EFEC_B190 *g = &D_0055EFEC;
    UnkStruct_0030B190_plr *p = g->field_0[pi].field_0;
    float f1 = k1 * p->field_13D4;
    float f0 = k2 * (float)p->field_B0.W(); // [C] retail's FPU multiply: 0x30B1DC lwc1 f0, 0xC(sp) (W), 0x30B1E8 mul.s f0, f3, f0 -- the cast keeps the PS2 float model (port lane vu0: without it the host's IEEE multiply ran, 1 ULP off)
    UnkStruct_0030B190_sub *sub = p->field_CC4;
    unsigned char b = sub->field_1033;
    if (b != 0 && self->field_14 == 0.0f) {
        self->field_14 = 2.0f;
        self->field_1C = GtMath::Min(self->field_18 / 2.5f, self->field_0->field_38 / CB3Burn::gmarBoostBarSizes[3]);
        self->field_18 = 0.0f;
    }
    if (b == 0 && self->field_0->field_52 == 0) {
        self->field_14 = GtMath::Max(0.0f + self->field_14 - 2.0f * dt, 0.0f);
    } else {
        self->field_14 = GtMath::Max(0.0f + self->field_14 - 2.5f * dt, 1.0f);
    }
    float bar = self->field_0->field_38 / CB3Burn::gmarBoostBarSizes[3];
    if (self->field_0->field_52 != 0 && !(bar <= 0.1f)) {
        self->field_10 = GtMath::Min(0.0f + self->field_10 + 0.5714286f * dt, 1.0f);
        if (self->field_10 > 0.5f) {
            self->field_C = GtMath::Min(0.0f + self->field_C + 0.5f * dt, 1.0f);
        }
        if (self->field_10 > 0.5f) {
            self->field_20 = GtMath::Max(0.0f + self->field_20 - 2.0f * dt, 0.0f);
        } else {
            self->field_20 = GtMath::Min(0.0f + self->field_20 + 10.0f * dt, 1.0f);
        }
    } else {
        self->field_10 = GtMath::Max(self->field_10 - dt, 0.0f);
        self->field_C = GtMath::Max(0.0f + self->field_C - 0.5f * dt, 0.0f);
        self->field_20 = GtMath::Max(0.0f + self->field_20 - 2.0f * dt, 0.0f);
        self->field_18 = self->field_18 + dt;
    }
    float t = func_0030B190_inl1(f0, 0.0f, f1);
    if (self->field_4 > t) {
        self->field_4 = GtMath::Min(self->field_4 + 2.0f * dt, t);
    } else {
        self->field_4 = GtMath::Max(self->field_4 - 2.0f * dt, t);
    }
    float t2 = func_0030B190_inl2(f0);
    if (self->field_4 > t2) {
        self->field_8 = GtMath::Min(self->field_8 + 2.0f * dt, t2);
    } else {
        self->field_8 = GtMath::Max(self->field_8 - 2.0f * dt, t2);
    }
}

