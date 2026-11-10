// NONMATCHING: Update__22CB3SoundRaceCarManagerFv -- retail 165 / ours 164 instructions, 45 in changed runs
// psweep: scoped #pragma opt_lifetimes off [G] improves 53 -> 49
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_lifetimes off
using GtMathPs2::CGtV4d;

struct UnkStruct_002ED3E0_burn {
    unsigned char pad_0[0x11C4];
    float field_11C4;
    unsigned char pad_11C8[0x16];
    unsigned char field_11DE;
    unsigned char pad_11DF[0x27C0 - 0x11DF];
    int field_27C0;
};
struct UnkStruct_002ED3E0_phys {
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
    unsigned char pad_C0[0x13D4 - 0xC0];
    float field_13D4;
    unsigned char pad_13D8[0x1C];
    UnkStruct_002ED3E0_burn *field_13F4;
};
struct UnkStruct_002ED3E0_rcp {
    UnkStruct_002ED3E0_phys *field_0;
    unsigned char pad_4[0x2C];
};
struct UnkStruct_002ED3E0_eng { unsigned char pad_0[0x24]; float field_24; };
struct UnkStruct_002ED3E0_out {
    virtual void vfunc_8();
    virtual void vfunc_C(void *, float, float, float);
};
struct UnkStruct_002ED3E0_car;
struct UnkStruct_002ED3E0_snd {
    virtual void vfunc_8();
    virtual void vfunc_C(UnkStruct_002ED3E0_car *); // a1 = the car [C retail 0x2ED430 lw a1 field_12AD28[i], live at the jalr; target CB3SoundPlayerCar::Update (this, const CB3RaceCar *) 0x28CB00]
    UnkStruct_002ED3E0_out *field_4;
    unsigned char pad_8[0x60];
    UnkStruct_002ED3E0_eng *field_68;
    unsigned char pad_6C[0x52];
    unsigned char field_BE;
    unsigned char pad_BF[0x91];
    float field_150;
};
struct UnkStruct_002ED3E0_car {
    unsigned char pad_0[0x1918];
    UnkStruct_002ED3E0_snd *field_1918;
    unsigned char pad_191C[0x90];
    signed char field_19AC;
};
struct UnkStruct_002ED3E0_cd {
    unsigned char pad_0[0x3C98C];
    UnkStruct_002ED3E0_rcp field_3C98C[6];
    unsigned char pad_3CAAC[0x12AD1C - 0x3CAAC];
    int field_12AD1C;
    unsigned char pad_12AD20[8];
    UnkStruct_002ED3E0_car *field_12AD28[6];
};
struct UnkStruct_002ED3E0 {
    unsigned char pad_0[0x1E0];
    float field_1E0[2];
};
struct UnkStruct_002ED3E0_i { int field_0; unsigned char pad_4[0xC]; };
struct CB3Burn { static float gmarBoostBarSizes[4]; };
extern UnkStruct_002ED3E0_cd D_00522660;
extern UnkStruct_002ED3E0_i D_0064D37C;
extern float _grVolumeTailoffStartSpeedPercent;
extern float _grVolumeTailoffEndSpeedPercent;
extern float D_004E1CE8;
extern float D_004E1CDC;

// 0x002ED3E0
extern "C" void Update__22CB3SoundRaceCarManagerFv(UnkStruct_002ED3E0 *self)
{
    UnkStruct_002ED3E0_out *outs[6];
    int i;
    for (i = 0; i < D_0064D37C.field_0; i++) {
        UnkStruct_002ED3E0_car *car = D_00522660.field_12AD28[i];
        // [C] retail 0x2ED430..0x2ED438: `lw a1, field_12AD28[i]; lw s1, 0x1918(a1); beqz s1` -- no test of the car
        // pointer. With car == 0 (a slot this loop's count, D_0064D37C, reaches but field_12AD28 leaves empty) retail
        // loads the word at absolute address 0x1918 (EE kernel RAM; the game runs in kernel mode, so no fault) and
        // treats it as the sound object. Written out so a host build reads guest RAM there instead of faulting (port8:
        // host crash at data address 0x1914).
        UnkStruct_002ED3E0_snd *s = car != 0 ? car->field_1918 : *(UnkStruct_002ED3E0_snd *const *)0x1918;
        if (s != 0) {
            s->vfunc_C(car);
            outs[i] = s->field_4;
        } else {
            outs[i] = 0;
        }
    }
    i = 0;
    for (;;) {
        if (!(i < D_00522660.field_12AD1C)) break;
        if (outs[i] != 0) {
            UnkStruct_002ED3E0_car *car = D_00522660.field_12AD28[i];
            UnkStruct_002ED3E0_snd *s = car->field_1918;
            float a = s->field_68->field_24 * D_004E1CDC;
            float b = 0.0f;
            float c = 1.0f;
            if (s->field_BE != 0) {
                b = s->field_150;
                UnkStruct_002ED3E0_phys *p = D_00522660.field_3C98C[car->field_19AC].field_0;
                float k = p->field_13D4;
                float v = 2.236936331f * (float)*(const GtMathPs2::WAxisType *)&p->field_B0;
                float lo = _grVolumeTailoffStartSpeedPercent * k;
                float hi = _grVolumeTailoffEndSpeedPercent * k;
                if (v < lo) v = lo;
                else if (!(v <= hi)) v = hi;
                float range = hi - lo;
                unsigned int rbits;
                asm("mfc1 %0, %1" : "=r"(rbits) : "f"(range));
                if ((rbits & 0x7F800000) > 0x37800000) {
                    float t = (v - lo) / range;
                    self->field_1E0[p->field_13F4->field_27C0] = t;
                    c = 1.0f + t * (D_004E1CE8 - 1.0f);
                }
                UnkStruct_002ED3E0_burn *bn = p->field_13F4;
                if (bn->field_11DE != 0) {
                    float m = 1.0f - bn->field_11C4 / CB3Burn::gmarBoostBarSizes[3];
                    m *= 0.5f;
                    m += 0.5f;
                    c *= m;
                }
            }
            outs[i]->vfunc_C(D_00522660.field_12AD28[i], a, b, c);
        }
        i++;
    }
}

#pragma pop
