// NONMATCHING: UpdateRaceCarWorldCollisionEffects__17CB3EffectsManagerFP17CB3RaceCarPhysicsb -- retail 1500 / ours 1497 instructions, 1020 in changed runs
// hard1 C-first (twin: UpdateTrafficWorldCollisionEffects): contact-point velocity (cross + linear), debris count (surface +0xE, local player, 700..20000), lighting, scrape mark within D_004E19E4 of the last (car+0x11B0), up to 4 sprays (type 2 for the bool; type 3 when the bool or surface +8 == 0; type 4 for +8 > 0 above 0.05; the surface type unless 0x1A), head-on impact for local players, crazy sparks, debris, func_00280D00, rumble (func_0022C2F0) above 20 mph; 1497/1500, calls identical, 52/52 non-stack stores identical (16 Random draws in retail order), every compare/branch sense traced; left: frame 0x430 vs 0x650 (stack temps), the dead move = B0*dt retail stores at 0x600, lui/ori address builds
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm region by region (Ghidra as a reading aid); every call with retail's argument registers (incl. the stack bool and func_0022C2F0's real a0..a3/f12..f15 list), every branch sense, all 16 Random() draws and the 52 non-stack stores checked against retail; retail's discarded range test kept as a dead local; one operator+(YAxisType, WAxisType) stand-in (queued)

// CB3EffectsManager::UpdateRaceCarWorldCollisionEffects(CB3RaceCarPhysics*, bool) -- hard1 (C-first draft; deferred-hard by
// draftAH). 0x2594C0, 0x1770. [C] name: the mangled symbol in retail's tables. Written from the retail asm region by region
// (Ghidra's draft as a reading aid); the lighting, the scrape mark and the spray calls follow the archived traffic twin
// UpdateTrafficWorldCollisionEffects (draftAJ).
// What it does [L]:
//  - contact-point velocity = angular velocity x (contact - body centre) + linear velocity, and its length;
//  - a debris count for func_0025CD60 (surface flag +0xE, local-player cars only, impact speed above 700; 24 at 20000+);
//  - ambient lighting (CLighting) from the instance's two light values (as the twin);
//  - a scrape mark (func_00375840) above 12 on a near-flat surface, only when the jittered contact point is within
//    D_004E19E4 of the previous mark (car+0x11B0, always updated);
//  - when moving (dt * speed > 0.005) and the car flag +0x210 is set: up to four particle sprays (func_0025F0C0): type 2 for
//    the bool parameter (the player? [G]), type 3 for the bool or a surface without a scale (+8 == 0), type 4 for a positive surface
//    scale above 0.05, and the surface's own type (+0xC) unless 0x1A; each from the jittered contact point;
//  - for local-player cars a head-on impact effect (func_0025D430) when hitting the surface head-on faster than 3500;
//  - crazy sparks, debris, func_00280D00 on D_01E78510; for the bool parameter a rumble pulse (func_0022C2F0) above 20 mph
//    (2.236936 = m/s -> mph), its strength from the velocity along the normal, its balance from the normal along the body's
//    right axis [G].
// Types and field meanings [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

extern "C" float fabsf(float);

struct UnkStruct_002594C0_inst { unsigned char pad_0[0x30]; CGtV3d field_30; unsigned char pad_40[0x1C]; float field_5C; float field_60; };
struct UnkStruct_002594C0_st {
    unsigned char pad_0[0x490];
    CGtV4d field_490;                       // w: [G] ride height
    unsigned char pad_4A0[0xB77];
    unsigned char field_1017[4];            // spray emit accumulators (func_0025F0C0)
};
struct UnkStruct_002594C0_mat {             // [G] the body transform: right row at +0, position at +0x30
    CGtV3d field_0;
    unsigned char pad_10[0x20];
    CGtV3d field_30;
};
struct UnkStruct_002594C0_hud {
    unsigned char pad_0[0x18EA];
    unsigned char field_18EA;               // [G] local player
    unsigned char pad_18EB[0xED5];
    signed char field_27C0;                 // [G] controller port
};
struct UnkStruct_002594C0_se {              // _gaSurfaceEffects entries (16 bytes)
    int field_0;
    float field_4;                          // spray base strength
    float field_8;                          // spray strength per speed
    signed char field_C;                    // the surface's own spray type (0x1A: none)
    unsigned char pad_D;
    unsigned char field_E;                  // debris on impact
    unsigned char pad_F;
};
extern UnkStruct_002594C0_se _gaSurfaceEffects[];
struct UnkStruct_002594C0_sp { float field_0; float field_4; unsigned char pad_8[0x8]; };   // [G] CB3SparkSpawnParams
extern UnkStruct_002594C0_sp D_004BC620;

class CB3RaceCarPhysics {
public:
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;                        // velocity, w = speed
    unsigned char pad_C0[0x10];
    CGtV3d field_D0;                        // angular velocity
    unsigned char pad_E0[0x80];
    CGtV3d field_160;                       // contact point
    CGtV3d field_170;                       // contact normal
    unsigned char pad_180[0x10];
    unsigned char field_190;                // surface type
    unsigned char pad_191[0x3];
    float field_194;                        // impact speed
    unsigned char pad_198[0x6C];
    UnkStruct_002594C0_mat *field_204;
    unsigned char pad_208[0x8];
    bool field_210;                         // [G] sprays enabled (lbu, used unmasked: a bool)
    unsigned char pad_211[0xAAF];
    UnkStruct_002594C0_inst *field_CC0;
    UnkStruct_002594C0_st *field_CC4;
    unsigned char pad_CC8[0x4E8];
    CGtV3d field_11B0;                      // last scrape mark position
    unsigned char pad_11C0[0x234];
    UnkStruct_002594C0_hud *field_13F4;
};

struct UnkStruct_002594C0_16 { unsigned char pad_0[0x10]; };
extern UnkStruct_002594C0_16 D_01E78510;
extern unsigned char D_004F50C0[];
extern float D_004E29E8;
extern float D_004E19AC;
extern float D_004E19B0;
extern float D_004E19B4;
extern float D_004E19B8;
extern float D_004E19BC;
extern float D_004E19E4;                    // 1.0 (a variable: low half zero): the scrape mark spacing
extern float D_004E19E8;                    // 20.0 (a variable): the rumble's full-strength normal speed
extern float D_004E1DD0;                    // rumble pulse parameters (local-player / other) [G]
extern float D_004E1DD4;
extern int D_004E1DD8;
extern float D_004E1DDC;
extern float D_004E1DE0;
extern int D_004E2DDC;
extern float D_004E2DE0;
extern float D_004E2DE4;

class CB3EffectsManager {
public:
    class CLighting {
    public:
        float field_0;
        float field_4;
    };
    void UpdateRaceCarWorldCollisionEffects(CB3RaceCarPhysics *, bool);
    unsigned char pad_0[0x16C80];
    unsigned char field_16C80[0x8BA8];      // the scrape system
    CGtRandom field_1F828;
    unsigned char pad_1F830[0x1C];
    float field_1F84C;                      // frame time step
};
extern "C" void func_00375840(void *, CGtV3d *, const CGtV3d *, const CGtV3d *, int, const void *);
extern "C" void func_0025D430(CB3EffectsManager *, const CGtV3d *, const CGtV3d *, const CGtV3d *, const CGtV3d *, const CGtV3d *, int, int, float, float);
extern "C" void func_0025F0C0(CB3EffectsManager *, const void *, const void *, const void *, int, const void *, unsigned char *, int, float, float, float, bool);  // last: bool here (retail passes the lbu flag unmasked)
extern "C" void func_0025CD60(float, float, CB3EffectsManager *, const CGtV3d *, const CGtV3d *, const CGtV3d *, const CGtV3d *, const void *, bool);
extern "C" void DoCrazySparksWithWorld__17CB3EffectsManagerFP16CB3CollidingBodyPC19CB3SparkSpawnParams(CB3EffectsManager *, CB3RaceCarPhysics *, void *);
extern "C" void func_00280D00(void *, int, CB3RaceCarPhysics *, float);
// [L] real list from the matched B3InputManager func_0022C2F0 (a0, mode a1 switch, a2, a3 passed on; f12-f15 untouched)
extern "C" void func_0022C2F0(void *, int, int, int, float, float, float, float);

static inline float func_002594C0_inl3(float x, float hi) { return GtMath::Min(GtMath::Max(x, 0.0f), hi); }

// 0x002594C0
void CB3EffectsManager::UpdateRaceCarWorldCollisionEffects(CB3RaceCarPhysics *car, bool b)
{
    UnkStruct_002594C0_se *surf = &_gaSurfaceEffects[car->field_190];
    CGtV3d pos = car->field_160;
    CGtV3d nrm = car->field_170;
    float impact = car->field_194;
    UnkStruct_002594C0_inst *inst = car->field_CC0;
    // [G] the contact height over the ground under the body
    float height = (pos.Y() - inst->field_30.Y() + car->field_CC4->field_490.W());
    // the contact point's velocity
    CGtV3d vel = CrossProduct(car->field_D0, pos - car->field_204->field_30) + *(const CGtV3d *)&car->field_B0;
    ((float *)&vel)[3] = ((const float *)&car->field_204->field_30)[3]; // [C] 0x259558 lqc2 vf1, 0x30(v1); 0x259560 vsub.xyz vf1, vf2, vf1
    // keeps field_30's w; 0x259574 vopmsub.xyz vf1, vf1, vf2 keeps it; 0x259578/0x259580 qmfc2/qmtc2 to vf3; 0x259584 vadd.xyz vf3, vf3,
    // vf2; 0x259590 sqc2 vf3, 0x610(sp) -- the port's `a - b` / `a + b` took pos's, then field_B0's w
    float speed = vel.GetLength();
    bool on = car->field_210;
    int debris = 0;
    if (surf->field_E && car->field_13F4->field_18EA && !(impact <= 700.0f)) {
        if (impact < 20000)
            debris = (int)(0.00075129536f * (impact - 700.0f));
        else
            debris = 24;
    }
    float dt = field_1F84C;
    CGtV3d move = *(const CGtV3d *)&car->field_B0 * dt;    // [C] computed, never read (as the twin's)
    float step = dt * (float)car->field_B0.W();
    // lighting (as UpdateBodyPartWorldCollisionEffects)
    float a5C = inst->field_5C;
    float a60 = inst->field_60;
    float m = GtMath::Min(a60, a5C);
    float x1 = func_002594C0_inl3(D_004E19AC * (a5C - D_004E29E8), 1.0f);
    float x2 = func_002594C0_inl3(D_004E19B4 * (a60 - D_004E19B0), 1.0f);
    float s = x1 + x2;
    s = s * s;
    if (x1 < x2) s = s + x1; else s = s + x2;
    CLighting light;
    light.field_4 = func_002594C0_inl3(s * D_004E19BC, 1.0f);
    light.field_0 = func_002594C0_inl3(m * D_004E19B8, 1.0f - light.field_4);
    // scrape mark
    CGtV3d half;                            // [C] retail builds (0.5, 0, 0.5) in a stack slot and never reads it
    half.SetX(0.5f);
    half.SetY(0.0f);
    half.SetZ(0.5f);
    float r = 0.125f + 0.25f * field_1F828.RandomReal();
    CGtV3d off;
    off.SetX(r);
    off.SetY(0.0f);
    off.SetZ(r);
    float up = DotProduct(CGtV3d(0.0f, 1.0f, 0.0f), nrm);
    CGtV3d q = pos;
    q += off; // [C] w = pos.w: 0x25986C lqc2 vf1, 0x630(sp); 0x259874 vadd.xyz vf1, vf1, vf5; 0x259878 sqc2 vf1, 0x5C0(sp) (`a + b` took off's unset w)
    if (!(speed <= 12.0f) && !(up <= 0.866f)) {
        CGtV3d d = q - car->field_11B0;
        if ((float)d.GetSquaredLength() < D_004E19E4 * D_004E19E4)
            func_00375840(field_16C80, &car->field_11B0, &q, &nrm, 0, 0);
        car->field_11B0 = q;
    }
    if (!(step <= 0.005f) && on) {
        // particle sprays from the jittered contact point
        CGtV3d v(0.0f, 0.1f, 0.0f);
        CGtV3d p1 = pos;
        CGtV3d p0 = pos;
        float k;
        if (b) {
            p0.SetX(p0.X() + (field_1F828.RandomReal() - 0.5f) * 4.0f);
            p0.SetZ(p0.Z() + (field_1F828.RandomReal() - 0.5f) * 4.0f);
            v.SetX((field_1F828.RandomReal() - 0.5f) * 20.0f);
            v.SetZ((field_1F828.RandomReal() - 0.5f) * 20.0f);
            k = GtMath::Min(1.0f, step / 0.1f);
            float a = 0.5f * k * (0.5f * (1.0f + field_1F828.RandomReal()));
            func_0025F0C0(this, &p0, &p1, &v, 2, &light, &car->field_CC4->field_1017[0], 0, 0.3f, (0.75f + 0.25f * a) * 5.0f,
                          GtMath::Min(2.0f * a, 1.0f), on);
        } else {
            k = GtMath::Min(0.35f, step / 0.1f);
        }
        if (b || surf->field_8 == 0.0f) {
            p0.SetX(p0.X() + (field_1F828.RandomReal() - 0.5f) * 4.0f);
            p0.SetZ(p0.Z() + (field_1F828.RandomReal() - 0.5f) * 4.0f);
            v.SetX((field_1F828.RandomReal() - 0.5f) * 20.0f);
            v.SetZ((field_1F828.RandomReal() - 0.5f) * 20.0f);
            float c = GtMath::Min(1.0f, surf->field_4 + 7.0f * k);
            c = c * (0.5f * (1.0f + field_1F828.RandomReal()));
            func_0025F0C0(this, &p0, &p1, &v, 3, &light, &car->field_CC4->field_1017[1], 0, 0.3f, (0.75f + 0.25f * c) * 5.0f,
                          GtMath::Min(2.0f * c, 1.0f), on);
        }
        if (!(surf->field_8 <= 0.0f)) {
            p0.SetX(p0.X() + (field_1F828.RandomReal() - 0.5f) * 4.0f);
            p0.SetZ(p0.Z() + (field_1F828.RandomReal() - 0.5f) * 4.0f);
            v.SetX((field_1F828.RandomReal() - 0.5f) * 20.0f);
            v.SetZ((field_1F828.RandomReal() - 0.5f) * 20.0f);
            float c = GtMath::Min(1.0f, k * surf->field_8);
            if (!(c <= 0.05f)) {
                c = c * (0.5f * (1.0f + field_1F828.RandomReal()));
                func_0025F0C0(this, &p0, &p1, &v, 4, &light, &car->field_CC4->field_1017[2], 0, 0.3f, (0.75f + 0.25f * c) * 5.0f,
                              c, on);
            }
        }
        int type = surf->field_C;
        if (type != 0x1A)
            func_0025F0C0(this, &p0, &p1, &v, type, &light, &car->field_CC4->field_1017[3], 0, 0.3f, 5.0f, 1.0f, on);
    }
    // head-on impact (local-player cars)
    if (car->field_13F4->field_18EA) {
        CGtV3d n(0.0f, 1.0f, 0.0f);
        CGtV3d vb = *(const CGtV3d *)&car->field_B0;
        if (DotProduct(vel, -nrm) < 0.707f && !(impact <= 3500)) {
            n = vb * 0.75f;
            // [C] retail evaluates this range test and discards the result: a dead local set in the body keeps the
            // compares (an empty body drops them)
            float sc = 0.0f;
            if (!(step <= D_004BC620.field_0) && step < D_004BC620.field_4) {
                sc = 1.0f;
            }
            func_0025D430(this, &pos, &n, &n, &vb, &nrm, 3, 1, 200.0f, height);
        }
    }
    DoCrazySparksWithWorld__17CB3EffectsManagerFP16CB3CollidingBodyPC19CB3SparkSpawnParams(this, car, &D_004BC620);
    if (debris)
        func_0025CD60((float)debris, height, this, &pos, &vel, &vel, &nrm, &light, on);
    func_00280D00(&D_01E78510, 0, car, impact);
    if (b) {
        CGtV4d v4 = car->field_B0;
        if (!(2.2369363f * (float)v4.W() <= 20.0f)) {
            UnkStruct_002594C0_hud *h = car->field_13F4;
            float side = -DotProduct(car->field_170, car->field_204->field_0);
            float f = GtMath::Min(fabsf(DotProduct(*(const CGtV3d *)&v4, car->field_170)) / D_004E19E8, 1.0f);
            f = func_002594C0_inl3(f * f, 1.0f);
            float bal = GtMath::Min(GtMath::Max(side, -1.0f), 1.0f);
            if (h->field_18EA)
                func_0022C2F0(D_004F50C0, D_004E1DD8, h->field_27C0, 0xFFFF, D_004E1DE0, bal, D_004E1DDC * f, D_004E2DE4);
            else
                func_0022C2F0(D_004F50C0, D_004E2DDC, h->field_27C0, 0xFFFF, D_004E1DD4, bal, D_004E1DD0 * f, D_004E2DE0);
        }
    }
}
