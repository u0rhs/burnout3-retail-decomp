// NONMATCHING: UpdateRaceCar__22CB3CrashActionDirectorFiP17CB3RaceCarPhysicsf -- retail 420 / ours 422 instructions, 340 in changed runs
// fix3 (2026-11-01): UpdateFlyingBits on the deform object at vehicle+0x380, not on the vehicle pointer [C] retail 0x1B2118 | Before: son6 first pass (422 vs 420 instrs; first 0x110 bytes identical): UpdateFlyingBits, wheel count (0x8D3 stride 0xC0), timer at this+idx*0x3C+0x148, angle test (acosf) + speed-scaled func_001CC520 calls (flags +0x140/+0x144), LCG member; left: retail frame 0x2A0 (locals kept in 0x280/0x290/0x150 quads), Normalise/dot VU form (retail normalises into vf3 and keeps abs.s+cop1 dead code),  read uninitialised (retail reads it unset: a lifter/ABI oddity)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

class CB3VehicleDeform {
public:
    void UpdateFlyingBits();
};
struct UnkStruct_1B20D0_wheel {   // [G] 0xC0 stride at car+0x8D3-ish
    unsigned char pad_0[0xC0];
};
struct UnkStruct_1B20D0_orient {   // [G] rows at +0x00 / +0x20
    CGtV3d field_0;
    unsigned char pad_10[0x10];
    CGtV3d field_20;
};
struct UnkStruct_1B20D0_car {   // [G] CB3RaceCarPhysics
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
    CGtV4d field_C0;
    CGtV3d field_D0;
    unsigned char pad_E0[0x124];
    UnkStruct_1B20D0_orient *field_204;
};
class CB3RaceCarPhysics;
struct UnkStruct_1B20D0_slot {   // [G] D_0055EFEC entries, stride 0x30
    UnkStruct_1B20D0_car *field_0;
    unsigned char pad_4[0x2C];
};
struct UnkStruct_1B20D0_stat {   // [G] per-car record of the director, stride 0x3C
    unsigned char pad_0[0x140];
};
extern UnkStruct_1B20D0_slot D_0055EFEC[];
// fix3: D_0064D388[] holds the vehicles; the CB3VehicleDeform is embedded at +0x380 [C] retail 0x1B2118 addiu a0, v0, 0x380
struct UnkStruct_1B20D0_veh { unsigned char pad_0[0x380]; CB3VehicleDeform field_380; };
extern UnkStruct_1B20D0_veh *D_0064D388[];
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_Pad16 D_004EE040;
extern float D_004E0E60, D_004E0E94, D_004E1210, D_004E1278, D_004E1298, D_004E12B4, D_004E12B8;
extern "C" int func_00131E40(void *);
extern "C" float func_0011E328(float);
extern "C" void func_001CC520(UnkStruct_1B20D0_car *, int, int, float);

class CB3CrashActionDirector {
public:
    void UpdateRaceCar(int, CB3RaceCarPhysics *, float);
    int field_0;
    int field_4;
    unsigned char pad_8[0x138];
    // per-car blocks of 0x3C bytes start at +0x0 (idx*0x3C): +0x140 / +0x144 flags, +0x148 timer [G]
};

static inline float func_001B20D0_rnd(CB3CrashActionDirector *self)
{
    self->field_0 = (self->field_0 << 16) + (self->field_0 >> 16);
    self->field_0 = self->field_0 + self->field_4;
    self->field_4 = self->field_4 + self->field_0;
    return (float)(unsigned int)self->field_0 * 2.3283064e-10f;
}

// 0x001B20D0
void CB3CrashActionDirector::UpdateRaceCar(int idx, CB3RaceCarPhysics *, float dt)
{
    float spd;   // [G] retail reads $f21 here without ever setting it
    D_0064D388[idx]->field_380.UpdateFlyingBits();
    UnkStruct_1B20D0_car *car = D_0055EFEC[idx].field_0;
    UnkStruct_1B20D0_orient *o = car->field_204;
    int cnt = 0;
    for (int i = 0; i < *((signed char *)car + 0x1169); i++) {
        if (*((unsigned char *)car + i * 0xC0 + 0x8D3) == 0) {
            cnt++;
        }
    }
    float *timer = (float *)((char *)this + idx * 0x3C + 0x148);
    if (cnt < 3) {
        *timer = *timer + dt;
    } else {
        *timer = 0.0f;
    }
    CGtV4d lv = car->field_C0;
    CGtV4d pos = car->field_B0;
    float lim = D_004E1278;
    if (*timer <= lim) {
        return;
    }
    if (func_00131E40(&D_004EE040) != 0) {
        return;
    }
    CGtV3d p3(pos.mData);
    float unusedAbs = DotProduct(o->field_0, p3);
    CGtV3d n0 = o->field_20;
    n0.Normalise();
    CGtV3d v3(lv.mData);
    v3.Normalise();
    float c = DotProduct(n0, v3);
    if (c < -1.0f) c = -1.0f;
    if (c > 1.0f) c = 1.0f;
    float ang = D_004E1298 * func_0011E328(c);
    int *flag140 = (int *)((char *)this + idx * 0x3C + 0x140);
    int *flag144 = (int *)((char *)this + idx * 0x3C + 0x144);
    if (ang < 20.0f) {
        float len = car->field_D0.GetLength();
        if (len < 1.0f && *flag140 == 0) {
            CGtV4d a = car->field_B0;
            if (a.f[3] > 25.0f) {
                CGtV4d b = car->field_B0;
                if (b.f[3] <= 50.0f) {
                    int k = (float)DotProduct(o->field_20, v3) < 0.0f ? 1 : 2;
                    func_001CC520(car, k, 0, GtMath::Min(GtMath::Max(3.0f * func_001B20D0_rnd(this), D_004E1210), 3.0f));
                    *flag140 = 1;
                    return;
                }
                CGtV4d d = *(CGtV4d *)&car->field_D0;
                int k = d.f[1] < 0.0f ? 0x20 : 0x40;
                func_001CC520(car, k, 0, GtMath::Min(GtMath::Max(D_004E0E60 * func_001B20D0_rnd(this), D_004E0E94), D_004E0E60));
                *flag140 = 1;
                return;
            }
        }
    }
    if (spd <= 15.0f) {
        return;
    }
    if (*flag144 != 0) {
        return;
    }
    float d = DotProduct(o->field_0, v3);
    float inv = 1.0f / (lim * (spd - 14.0f));
    float f = inv * (1.0f + D_004E12B4 * func_001B20D0_rnd(this));
    f = GtMath::Min(GtMath::Max(f, D_004E12B8), D_004E12B4);
    if (d > 0.5f) {
        func_001CC520(car, 8, 0, f);
        *flag144 = 1;
        return;
    }
    if (d < -0.5f) {
        func_001CC520(car, 4, 0, f);
        *flag144 = 1;
    }
}
