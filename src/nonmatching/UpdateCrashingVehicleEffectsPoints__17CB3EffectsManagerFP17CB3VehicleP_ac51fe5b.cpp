// NONMATCHING: UpdateCrashingVehicleEffectsPoints__17CB3EffectsManagerFP17CB3VehiclePhysicsRCQ217CB3EffectsManager9CLighting -- retail 130 / ours 130 instructions, 9 in changed runs
// 130/130, 9 changed, frame exact: three u8-parameter inline helpers (retail's andi 0xFF copies), member-wise q copy, CGtV3d::SetY(0.0f), W() + one N140 pad. Left: retail forms &D_01EA4BB0 last (lui late, addiu in the jal delay slot) so the SetY zero lands in a0; ours computes it early (zero in v0). Tried arg locals, typed first param, opt_lifetimes/propagation/pulloutconstants.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3EffectsManager::UpdateCrashingVehicleEffectsPoints(CB3VehiclePhysics*, const CB3EffectsManager::CLighting&) -- hand-written (fresh1).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_0025F950_X { unsigned char pad_0[0x54]; float field_54; };
struct UnkStruct_0025F950_Y {
    unsigned char pad_0[0x490];
    CGtV4d field_490;
    unsigned char pad_4A0[0xB75];
    unsigned char field_1015;
    unsigned char field_1016;
};
struct UnkStruct_0025F950_q2 { u_long128 field_0; u_long128 field_10; };
class CB3VehiclePhysics {
public:
    unsigned char pad_0[0xB0];
    CGtV3d field_B0;
    unsigned char pad_C0[0x110];
    UnkStruct_0025F950_q2 field_1D0;
    unsigned char pad_1F0[0x14];
    void * field_204;
    unsigned char pad_208[0xAB8];
    UnkStruct_0025F950_X * field_CC0;
    UnkStruct_0025F950_Y * field_CC4;
};
struct UnkStruct_0025F950_l8 { float field_0; float field_4; };

class CB3EffectsManager {
public:
    class CLighting {
    public:
        float field_0;
        float field_4;
        unsigned char pad_8[8];
    };
    void UpdateCrashingVehicleEffectsPoints(CB3VehiclePhysics *, const CLighting &);
    void func_0025F950_inl1(CB3VehiclePhysics *, const CLighting &, unsigned char);
    void func_0025F950_inl2(CB3VehiclePhysics *, const CLighting &, unsigned char);
    void func_0025F950_inl3(CB3VehiclePhysics *, const CLighting &, unsigned char);
    void DoVehicleSteam(CB3VehiclePhysics *, float, const CLighting &);
    void DoVehicleFire(CB3VehiclePhysics *, float, const CLighting &);
    void DoVehicleGlass(CB3VehiclePhysics *, const CLighting &);
    void UpdateVehicleFireTrail(CB3VehiclePhysics *, const CLighting &);
};

class CB3SoundCrashManager {
public:
    void GenericGlassSmash(CB3VehiclePhysics *);
    unsigned char pad_0[0x10];
};

extern CB3SoundCrashManager D_01E78510;
struct UnkStruct_D_01EA4BB0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01EA4BB0 D_01EA4BB0;

extern "C" void func_0025AC30(CB3EffectsManager *, CB3VehiclePhysics *, UnkStruct_0025F950_l8);
extern "C" void func_0039A360(void *, void *, const UnkStruct_0025F950_q2 *, const CGtV3d *, float);

struct UnkStruct_0025F950_pad { int x[4]; UnkStruct_0025F950_pad() {} ~UnkStruct_0025F950_pad() {} };
// [G] unnamed inlined helpers (each takes the flag byte as an unsigned char: retail re-masks it with andi 0xFF per helper).
inline void CB3EffectsManager::func_0025F950_inl1(CB3VehiclePhysics * v, const CLighting & l, unsigned char f)
{
    if (f & 0xF) {
        float d = 14.0f - v->field_CC0->field_54;
        if (!(d <= 0.01f)) {
            float k = 0.07142857462f;
            float t = d * k;
            float s = 1.0f - t;
            s = s * s;
            DoVehicleSteam(v, 1.0f - s, l);
        }
    }
    if (f & 0xF0) {
        if (v->field_CC0->field_54 < 8.0f) DoVehicleFire(v, 1.0f, l);
    }
}
inline void CB3EffectsManager::func_0025F950_inl2(CB3VehiclePhysics * v, const CLighting & l, unsigned char g)
{
    if (g & 6) func_0025AC30(this, v, *(const UnkStruct_0025F950_l8 *)&l);
    if (g & 8) {
        UnkStruct_0025F950_q2 q;
        q.field_0 = v->field_1D0.field_0;
        q.field_10 = v->field_1D0.field_10;
        CGtV3d p = v->field_B0;
        UnkStruct_0025F950_pad pad;  // N140 frame pad [G]: one dead 16-byte slot below p in retail's frame
        p.SetY(0.0f);
        func_0039A360(&D_01EA4BB0, v->field_204, &q, &p, v->field_CC4->field_490.W());
        v->field_CC4->field_1015 &= ~8;
    }
}
inline void CB3EffectsManager::func_0025F950_inl3(CB3VehiclePhysics * v, const CLighting & l, unsigned char g)
{
    if (g & 0x10) UpdateVehicleFireTrail(v, l);
    if (g & 1) {
        v->field_CC4->field_1015 &= ~1;
        DoVehicleGlass(v, l);
        D_01E78510.GenericGlassSmash(v);
    }
}

// 0x0025F950
void CB3EffectsManager::UpdateCrashingVehicleEffectsPoints(CB3VehiclePhysics * v, const CLighting & l)
{
    int f = v->field_CC4->field_1016;
    if (f != 0) func_0025F950_inl1(v, l, f);
    int g = v->field_CC4->field_1015;
    if (g != 0) {
        func_0025F950_inl2(v, l, g);
        func_0025F950_inl3(v, l, g);
    }
}
