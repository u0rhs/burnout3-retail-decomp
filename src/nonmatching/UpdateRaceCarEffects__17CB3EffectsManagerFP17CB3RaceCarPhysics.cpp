// NONMATCHING: UpdateRaceCarEffects__17CB3EffectsManagerFP17CB3RaceCarPhysics -- retail 220 / ours 218 instructions, 31 in changed runs
// beh8: 218/220, 31 changed. Lighting = UpdateCrashingTrafficEffects' proven code; decl order pm, i, crashing fixes s0-s2; matrix staging t = a*b (byte loops), m = t, m declared before t (slots exact). Left: (1) CGtMatrix3x4::operator* stand-in: retail keeps a0=&a, a1=&m bases for rows 1-3 / m.mPos and row-0 result in v1 (same body gap as func_002F0440); m.U/m.A need qmtc2.i (lq+qmtc2), outputs qmfc2.i; (2) team = (field_215==1) ? field_1580->field_27C0 : -1 -- retail puts the else (li -1) out of line; if/else, ternary, inline early returns, goto: all inline
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// CB3EffectsManager::UpdateRaceCarEffects(CB3RaceCarPhysics*) -- hand-written (beh8).
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/ (docs/conventions.md). Fields placeholders, types [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CB3VehiclePhysics;
class CB3RaceCarPhysics;
extern __declspec(sdata) const float D_004E19AC;
extern __declspec(sdata) const float D_004E19B0;
extern __declspec(sdata) const float D_004E19B4;
extern __declspec(sdata) const float D_004E19B8;
extern __declspec(sdata) const float D_004E19BC;
extern __declspec(sdata) const float D_004E29E8;
struct UnkStruct_00260F30_X { unsigned char pad_0[0x5C]; float field_5C; float field_60; };
struct UnkStruct_00260F30_Y { unsigned char pad_0[0x4AC]; signed char field_4AC[1]; };
struct UnkStruct_00260F30_Z { unsigned char pad_0[0x27C0]; signed char field_27C0; };
class CB3RaceCar {
public:
    unsigned char pad_0[0x16B4];
    float field_16B4;
    unsigned char pad_16B8[0x268];
    CGtMatrix3x4 field_1920;
    unsigned char pad_1960[0x3B];
    unsigned char field_199B;
};
struct UnkStruct_00260F30_phys {
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;
    unsigned char pad_B0[0x160];
    bool field_210;
    unsigned char pad_211[4];
    signed char field_215;
    unsigned char pad_216[0xAAA];
    UnkStruct_00260F30_X *field_CC0;
    UnkStruct_00260F30_Y *field_CC4;
    unsigned char pad_CC8[0x4A1];
    signed char field_1169;
    unsigned char pad_116A[0x28A];
    CB3RaceCar *field_13F4;
    unsigned char pad_13F8[0x188];
    UnkStruct_00260F30_Z *field_1580;
};
class CB3EffectsManager {
public:
    class CLighting {
    public:
        float field_0;
        float field_4;
        unsigned char pad_8[8];
    };
    void UpdateRaceCarEffects(CB3RaceCarPhysics *);
    void UpdateCrashingVehicleEffectsPoints(CB3VehiclePhysics *, const CLighting &);
    void UpdateExhaustSmoke(CB3RaceCar *, const CLighting &);
    void HandleBattleSmoke(CB3RaceCarPhysics *, float);
    void HandleBattleSparks(CB3RaceCarPhysics *, float);
    unsigned char pad_0[0x1F854];
    int field_1F854;
};
extern "C" void UpdateWheelEffects__17CB3EffectsManagerFP17CB3VehiclePhysicsUiPCQ29GtMathPs212CGtMatrix3x4RCQ217CB3EffectsManager9CLightingb(CB3EffectsManager *, CB3VehiclePhysics *, unsigned int, const CGtMatrix3x4 *, const CB3EffectsManager::CLighting &, bool, int);

#pragma opt_classresults on
static inline CGtMatrix3x4 func_00260F30_inl1(const CGtMatrix3x4& a, const CGtMatrix3x4& m)
{
    CGtMatrix3x4 r;
    asm("qmtc2.ni %1, $vf4" "\n\t" "qmtc2.ni %2, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "qmtc2.i %3, $vf3" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "qmtc2.i %4, $vf2" "\n\t" "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mRight.mData) : "r"(m.mRight.mData), "r"(a.mRight.mData), "r"(m.mUp.mData), "r"(m.mAt.mData));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mUp.mData) : "r"(a.mUp.mData));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mAt.mData) : "r"(a.mAt.mData));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddaz.xyz $ACC, $vf2, $vf1z" "\n\t"
        "qmtc2.ni %2, $vf1" "\n\t" "vmaddw.xyz $vf1, $vf1, $vf0w" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mPos.mData) : "r"(a.mPos.mData), "r"(m.mPos.mData));
    return r;
}
#pragma opt_classresults reset

// 0x00260F30
void CB3EffectsManager::UpdateRaceCarEffects(CB3RaceCarPhysics * p0)
{
    const CGtMatrix3x4 *pm = 0;
    int i;

    UnkStruct_00260F30_phys * ph = (UnkStruct_00260F30_phys *)p0;
    UnkStruct_00260F30_X * x = ph->field_CC0;
    bool crashing = ph->field_210;
    UnkStruct_00260F30_Y * y = ph->field_CC4;
    float f4 = x->field_5C;
    float f3 = x->field_60;
    float f6 = GtMath::Min(f3, f4);
    float t0 = GtMath::Max(D_004E19AC * (f4 - D_004E29E8), 0.0f);
    float one = 1.0f;
    float a = GtMath::Min(t0, one);
    float b = GtMath::Min(GtMath::Max(D_004E19B4 * (f3 - D_004E19B0), 0.0f), one);
    float sq = (a + b) * (a + b);
    float r;
    if (a < b) {
        r = sq + a;
    } else {
        r = sq + b;
    }
    CLighting lighting;
    float c = GtMath::Min(GtMath::Max(r * D_004E19BC, 0.0f), one);
    float &r4 = lighting.field_4;
    r4 = c;
    float d = 1.0f - r4;
    lighting.field_0 = GtMath::Min(GtMath::Max(f6 * D_004E19B8, 0.0f), d);

    int team;
    if (ph->field_215 == 1) team = ph->field_1580->field_27C0; else team = -1;
    CB3RaceCar *car = ph->field_13F4;
    int s0 = field_1F854 & 1;
    CGtMatrix3x4 m;
    if (car->field_199B != 0) {
        CGtMatrix3x4 t;
        t = func_00260F30_inl1(ph->field_70, car->field_1920);
        m = t;
        pm = &m;
    }
    for (i = 0; i < ph->field_1169; i++) {
        int w = i ^ s0;
        if (y->field_4AC[w] != 3) {
            UpdateWheelEffects__17CB3EffectsManagerFP17CB3VehiclePhysicsUiPCQ29GtMathPs212CGtMatrix3x4RCQ217CB3EffectsManager9CLightingb(this, (CB3VehiclePhysics *)p0, w, pm, lighting, crashing, team);
        }
    }
    if (crashing) UpdateCrashingVehicleEffectsPoints((CB3VehiclePhysics *)p0, lighting);
    else UpdateExhaustSmoke(ph->field_13F4, lighting);
    float bat = ph->field_13F4->field_16B4;
    if (bat < 0.1f) HandleBattleSmoke(p0, bat);
    if (bat < 0.1f) HandleBattleSparks(p0, bat);
}

