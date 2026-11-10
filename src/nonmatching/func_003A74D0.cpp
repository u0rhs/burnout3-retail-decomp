// NONMATCHING: func_003A74D0 -- retail 502 / ours 480 instructions, 459 in changed runs
// fix2 (2026-11-01): the cross-hair offsets go to +0/+4 of the field_30/field_34 objects (the draft wrote them into the +0x10 colour) [C] retail 0x3A7AF4..0x3A7B14; case 6 end of countdown: func_003A7F20 gets 0.0f (retail keeps the compare's zero in f12, 0x3A7778/0x3A7BD8), not the negative field_704 | Before: son9 first archive: logic/control flow/calls/field offsets right (5-state SatNav update; fade loops via vsubx.w). Frame 0x4E0 reached via dead pad; remaining: fade-temp stack slot layout (retail 0x30-strided slots + loop slot regs), sum locals in s1/stack, qmtc2.ni scheduling
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)



#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"

using namespace GtMathPs2;

struct UnkStruct_003A74D0_o {
    float field_0;                          // [C] retail 0x3A7AF4..0x3A7B14: the cross-hair offsets go to +0/+4
    float field_4;
    unsigned char pad_8[0x8];
    CGtV4d field_10;                        // the colour (0x3A7C00)
};

struct UnkStruct_003A74D0_s {
    UnkStruct_003A74D0_o * field_0[4];
};

struct UnkStruct_003A74D0 {
    unsigned char pad_0[0x28];
    float field_28;
    float field_2C;
    UnkStruct_003A74D0_o * field_30;
    UnkStruct_003A74D0_o * field_34;
    unsigned char pad_38[0x8];
    UnkStruct_003A74D0_s field_40[4];
    UnkStruct_003A74D0_o * field_80;
    UnkStruct_003A74D0_o * field_84;
    UnkStruct_003A74D0_o * field_88;
    UnkStruct_003A74D0_o * field_8C;
    unsigned char pad_90[0x1C4];
    int field_254;
    unsigned char pad_258[0x20];
    int field_278;
    int field_27C;
    unsigned char pad_280[0x10];
    unsigned char field_290;
    unsigned char pad_291[0x473];
    float field_704;
    float field_708;
    unsigned char pad_70C[0x4];
    float field_710;
    unsigned char pad_714[0x1C8];
    int field_8DC;
    int field_8E0;
    signed char field_8E4;
    unsigned char pad_8E5;
    unsigned char field_8E6;
    unsigned char pad_8E7[0xC9];
    float field_9B0;
    int field_9B4;
};

extern float D_004E07D0;
extern float D_004E07F4;
extern float D_004E2EA8;
extern int D_004E07A8;
extern int D_004E0784;
extern CGtV4d kSatNavXHairColour;

extern "C" void func_003A7F20(UnkStruct_003A74D0 *, float, int);
extern "C" void func_003AD3E0(float);
extern "C" void func_003ADA10();
extern "C" void func_003A9040(UnkStruct_003A74D0 *, float);
extern "C" void func_003A7CB0(UnkStruct_003A74D0 *, float);
extern "C" void func_003AC170();
extern "C" void func_003A8EB0(UnkStruct_003A74D0 *, float);
extern "C" void func_003AB2E0(UnkStruct_003A74D0 *, float);
extern "C" void func_003AB0A0(UnkStruct_003A74D0 *);
extern "C" void func_003ADD80(UnkStruct_003A74D0 *, float);
extern "C" CGtV2d func_003F5C70(int, int, int);

struct UnkStruct_003A74D0_padb {
    int x[0xA0];
    UnkStruct_003A74D0_padb() {}
    ~UnkStruct_003A74D0_padb() {}
};

struct UnkStruct_003A74D0_pad {
    int x[8];
    UnkStruct_003A74D0_pad() {}
    ~UnkStruct_003A74D0_pad() {}
};

static inline void func_003A74D0_inl1(UnkStruct_003A74D0_o * o, u_long128 s)
{
    u_long128 c = o->field_10.mData;
    u_long128 r;
    asm("vsubx.w %0, %1, %2x" : "=j"(r) : "j"(c), "j"(s));
    CGtV4d t(r);
    float a = t.f[3];
    CGtV4d n(c);
    n.SetA(GtMath::Max(a, 0.0f));
    o->field_10 = n;
}

static inline void func_003A74D0_inl1p(UnkStruct_003A74D0_o * o, u_long128 s)
{
    UnkStruct_003A74D0_pad pad;
    u_long128 c = o->field_10.mData;
    u_long128 r;
    asm("vsubx.w %0, %1, %2x" : "=j"(r) : "j"(c), "j"(s));
    CGtV4d t(r);
    float a = t.f[3];
    CGtV4d n(c);
    n.SetA(GtMath::Max(a, 0.0f));
    o->field_10 = n;
}

static inline void func_003A74D0_inl2(UnkStruct_003A74D0 * self, float dt)
{
    u_long128 s0, s1, s2;
    asm("qmtc2.ni %1, %0" : "=j"(s0) : "r"(dt));
    asm("qmtc2.ni %1, %0" : "=j"(s1) : "r"(dt));
    asm("qmtc2.ni %1, %0" : "=j"(s2) : "r"(dt));
    for (int i = 0; i < 4; i++) {
        if (self->field_40[i].field_0[0]) func_003A74D0_inl1(self->field_40[i].field_0[0], s0);
        if (self->field_40[i].field_0[1]) func_003A74D0_inl1(self->field_40[i].field_0[1], s1);
        if (self->field_40[i].field_0[2]) func_003A74D0_inl1(self->field_40[i].field_0[2], s2);
    }
    u_long128 s;
    if (self->field_84) { asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(dt)); func_003A74D0_inl1p(self->field_84, s); }
    if (self->field_88) { asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(dt)); func_003A74D0_inl1p(self->field_88, s); }
    if (self->field_8C) { asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(dt)); func_003A74D0_inl1p(self->field_8C, s); }
    if (self->field_80) { asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(dt)); func_003A74D0_inl1p(self->field_80, s); }
    self->field_290 = 1;
}

// 0x003A74D0
extern "C" void func_003A74D0(UnkStruct_003A74D0 * self, float dt)
{
    UnkStruct_003A74D0_padb padb;
    switch (self->field_8E4) {
    default:
        return;
    case 5: {
        float t = self->field_704 + dt;
        self->field_704 = t;
        if (t < D_004E07D0) {
            func_003A7F20(self, self->field_704, 1);
        } else {
            func_003AD3E0(D_004E07D0);
            func_003A7F20(self, D_004E07D0, 1);
            self->field_704 = 0.0f;
            self->field_708 = 0.0f;
            self->field_8E4 = 3;
        }
        func_003A74D0_inl2(self, 2.5f * dt);
        func_003A7CB0(self, 1.0f);
        break;
    }
    case 6:
        self->field_704 = self->field_704 - dt;
        self->field_9B4 = 0;
        if (self->field_704 > 0.0f) {
            func_003A7F20(self, self->field_704, 0);
        } else {
            func_003A7F20(self, 0.0f, 0);       // [C] retail 0x3A7BD8: f12 is still the 0.0f of the compare (0x3A7778)
            self->field_30->field_10 = kSatNavXHairColour;
            self->field_30->field_10.SetA(*(float *)&D_004E07A8);
            self->field_34->field_10.SetA(*(float *)&D_004E0784);
            self->field_704 = 0.0f;
            self->field_708 = 0.0f;
            self->field_8E4 = 2;
            self->field_8DC = 0;
            self->field_8E0 = 0;
            func_003AB0A0(self);
        }
        func_003A74D0_inl2(self, 2.5f * dt);
        break;
    case 1: {
        float t = self->field_710 + dt;
        self->field_710 = t;
        if (t < D_004E07F4) {
            dt = 2.5f * t;
        } else {
            self->field_710 = 0.0f;
            self->field_708 = 0.0f;
            dt = 1.0f;
            self->field_8E4 = 2;
            self->field_278 = self->field_27C;
            self->field_290 = 1;
            CGtV2d p = func_003F5C70(self->field_254, self->field_27C, self->field_8E6 == 0);
            self->field_28 = p.marValues[0];
            self->field_2C = p.marValues[1];
        }
        CGtV2d sum(0.0f, 0.0f);
        if (self->field_8E6 == 0) {
            sum += func_003F5C70(self->field_254, self->field_27C, 1);
        } else {
            sum += func_003F5C70(self->field_254, self->field_27C, 0);
        }
        CGtV2d cur(self->field_28, self->field_2C);
        CGtV2d np = cur + (sum - cur) * dt;
        self->field_30->field_0 = np.X() - 6.0f;
        self->field_30->field_4 = 0.0f;
        self->field_34->field_0 = 0.0f;
        self->field_34->field_4 = np.Y() - 3.0f;
        func_003ADD80(self, dt);
        break;
    }
    case 2:
        self->field_704 = self->field_704 + dt;
        self->field_9B0 = self->field_9B0 + dt;
        func_003ADA10();
        func_003A9040(self, dt);
        func_003A7CB0(self, dt);
        break;
    case 3:
        self->field_704 = self->field_704 + dt;
        D_004E2EA8 = D_004E2EA8 + dt;
        func_003AC170();
        if (self->field_8E6 == 0) func_003A8EB0(self, dt);
        func_003AB2E0(self, dt);
        break;
    }
}
