// NONMATCHING: UpdateTrafficWorldCollisionEffects__17CB3EffectsManagerFP17CB3VehiclePhysics -- retail 1034 / ours 1033 instructions, 330 in changed runs
// draftAJ C-first: lighting (as UpdateBodyPartWorldCollisionEffects), scrape mark with per-frame random jitter, two random-jittered func_0025F0C0 sprays (type 0, then type 4 / 3 by surface strength), head-on impact func_0025D430, crazy sparks, func_00280900; 1033/1034, calls identical; left: height lane op (vsuby.y in place vs our SetY copy), frame 0x310 vs 0x210, sqc2 temps
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid); every random draw in retail order (11 Random() calls), threshold (ELF .lit4), argument (incl. the 12th stack int and the emit-accumulator bytes field_CC4+0x1017..0x1019) and branch sense traced; one operator+(YAxisType, WAxisType) stand-in (queued)

// CB3EffectsManager::UpdateTrafficWorldCollisionEffects(CB3VehiclePhysics*) -- draftAJ (C-first draft; the lifter refused
// it). 0x258490, 0x1028. [C] name: the mangled symbol in retail's tables. Written from the retail asm (Ghidra's draft as a
// reading aid); the lighting and the scrape/impact calls follow the archived sibling UpdateBodyPartWorldCollisionEffects.
// What it does [L]: world-collision effects for a traffic vehicle (the race-car version is UpdateRaceCarWorldCollisionEffects):
//  - ambient lighting (CLighting) from the vehicle instance's two light values;
//  - a scrape mark (func_00375840) when moving faster than 12 per frame step on a near-flat surface (normal.y > 0.866),
//    jittered by a random offset in [0.125, 0.375) on x and z (the random is drawn every frame);
//  - above a crawl (dt * speed > 0.005): two particle sprays (func_0025F0C0) from the contact point, positions and
//    velocities jittered by the manager's random generator, strength from the speed and the surface table
//    _gaSurfaceEffects[surface] (+4: base, +8: scale; the second spray is type 4 above 0.05, else type 3);
//  - an impact effect (func_0025D430) when hitting the surface head-on (dot < 0.707) faster than 3500;
//  - crazy sparks, then func_00280900 on D_01E78510.
// Types and field meanings [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

struct UnkStruct_00258490_inst { unsigned char pad_0[0x30]; CGtV3d field_30; unsigned char pad_40[0x1C]; float field_5C; float field_60; };
struct UnkStruct_00258490_st {
    unsigned char pad_0[0x490];
    CGtV4d field_490;                       // w: [G] ride height
    unsigned char pad_4A0[0xB77];
    unsigned char field_1017[3];            // spray emit accumulators (func_0025F0C0)
};
struct UnkStruct_00258490_se {              // _gaSurfaceEffects entries (16 bytes)
    int field_0;
    float field_4;                          // spray base strength
    float field_8;                          // spray strength per speed
    unsigned char pad_C[0x4];
};
extern UnkStruct_00258490_se _gaSurfaceEffects[];

class CB3VehiclePhysics {
public:
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;                        // velocity, w = speed
    unsigned char pad_C0[0xA0];
    CGtV3d field_160;                       // contact point
    CGtV3d field_170;                       // contact normal
    unsigned char pad_180[0x10];
    unsigned char field_190;                // surface type
    unsigned char pad_191[0x3];
    float field_194;                        // impact speed
    unsigned char pad_198[0xB28];
    UnkStruct_00258490_inst *field_CC0;
    UnkStruct_00258490_st *field_CC4;
    unsigned char pad_CC8[0x4E8];
    unsigned char field_11B0[0x10];         // scrape emitter data
};

struct UnkStruct_00258490_16 { unsigned char pad_0[0x10]; };
extern UnkStruct_00258490_16 _gSparkSpawnParamsBody;
extern UnkStruct_00258490_16 D_01E78510;
extern float D_004E29E8;
extern float D_004E19AC;
extern float D_004E19B0;
extern float D_004E19B4;
extern float D_004E19B8;
extern float D_004E19BC;

class CB3EffectsManager {
public:
    class CLighting {
    public:
        float field_0;
        float field_4;
    };
    void UpdateTrafficWorldCollisionEffects(CB3VehiclePhysics *);
    unsigned char pad_0[0x16C80];
    unsigned char field_16C80[0x8BA8];      // the scrape system
    CGtRandom field_1F828;
    unsigned char pad_1F830[0x1C];
    float field_1F84C;                      // frame time step
};
extern "C" void func_00375840(void *, void *, const CGtV3d *, const CGtV3d *, int, const void *);
extern "C" void func_0025D430(CB3EffectsManager *, const CGtV3d *, const CGtV3d *, const CGtV3d *, const CGtV3d *, const CGtV3d *, int, int, float, float);
// signature as the proven B3EffectsManager_00257C70.cpp (UpdateVehicleFireTrail): the 12th int on the stack
extern "C" void func_0025F0C0(CB3EffectsManager *, const void *, const void *, const void *, int, const void *, unsigned char *, int, float, float, float, int);
extern "C" void DoCrazySparksWithWorld__17CB3EffectsManagerFP16CB3CollidingBodyPC19CB3SparkSpawnParams(CB3EffectsManager *, CB3VehiclePhysics *, void *);
extern "C" void func_00280900(void *, int, CB3VehiclePhysics *);

// unary minus on compiler-chosen registers (as the sibling's func_00257FD0_inl3; retail `vsub.xyz $vf2, $vf0, $vf2`)
static inline CGtV3d func_00258490_inl2(const CGtV3d &a)
{
    u_long128 r;
    asm("vsub.xyz %0, $vf0, %1" : "=j"(r) : "j"(a.mData));
    return CGtV3d(r);
}
static inline float func_00258490_inl3(float x, float hi) { return GtMath::Min(GtMath::Max(x, 0.0f), hi); }
// [G] a random value in [0, 1)
static inline float func_00258490_inl4(CB3EffectsManager *m) { return 2.3283064e-10f * (float)m->field_1F828.Random(); }

// 0x00258490
void CB3EffectsManager::UpdateTrafficWorldCollisionEffects(CB3VehiclePhysics *veh)
{
    UnkStruct_00258490_se *surf = &_gaSurfaceEffects[veh->field_190];
    CGtV3d pos = veh->field_160;
    CGtV3d nrm = veh->field_170;
    float impact = veh->field_194;
    UnkStruct_00258490_inst *inst = veh->field_CC0;
    // [G] the contact height over the ground under the body
    CGtV3d hp = inst->field_30;
    hp.SetY(pos.Y() - hp.Y());
    float height = (hp.Y() + veh->field_CC4->field_490.W());
    float dt = field_1F84C;
    CGtV3d move = *(const CGtV3d *)&veh->field_B0 * dt;
    float step = dt * (float)veh->field_B0.W();
    // lighting (as UpdateBodyPartWorldCollisionEffects)
    float a5C = inst->field_5C;
    float a60 = inst->field_60;
    float m = GtMath::Min(a60, a5C);
    float x1 = func_00258490_inl3(D_004E19AC * (a5C - D_004E29E8), 1.0f);
    float x2 = func_00258490_inl3(D_004E19B4 * (a60 - D_004E19B0), 1.0f);
    float s = x1 + x2;
    s = s * s;
    if (x1 < x2) s = s + x1; else s = s + x2;
    CLighting light;
    light.field_4 = func_00258490_inl3(s * D_004E19BC, 1.0f);
    light.field_0 = func_00258490_inl3(m * D_004E19B8, 1.0f - light.field_4);
    // scrape mark
    float r = 0.125f + 0.25f * func_00258490_inl4(this);
    CGtV3d off;
    off.SetX(r);
    off.SetY(0.0f);
    off.SetZ(r);
    float up = DotProduct(CGtV3d(0.0f, 1.0f, 0.0f), nrm);
    if (!(step <= 12.0f) && !(up <= 0.866f)) {
        CGtV3d q = pos;
        q += off;
        func_00375840(field_16C80, veh->field_11B0, &q, &nrm, 0, 0);
    }
    if (!(step <= 0.005f)) {
        // two particle sprays from the contact point
        CGtV3d p1 = pos;
        CGtV3d v(0.0f, 0.1f, 0.0f);
        CGtV3d p0 = pos;
        move.SetY(0.0f);
        p0.SetX(p0.X() + (func_00258490_inl4(this) - 0.5f) * 4.0f);
        p0.SetZ(p0.Z() + (func_00258490_inl4(this) - 0.5f) * 4.0f);
        v.SetX((func_00258490_inl4(this) - 0.5f) * 8.0f);
        v.SetZ((func_00258490_inl4(this) - 0.5f) * 8.0f);
        float k = GtMath::Min(1.0f, step / 0.1f);
        float a = 0.5f * k * (0.5f * (1.0f + func_00258490_inl4(this)));
        func_0025F0C0(this, &p0, &p1, &v, 0, &light, &veh->field_CC4->field_1017[0], 0, 0.3f, 4.0f * (0.75f + 0.25f * a),
                      GtMath::Min(2.0f * a, 1.0f), 1);
        p0.SetX(p0.X() + (func_00258490_inl4(this) - 0.5f) * 4.0f);
        p0.SetZ(p0.Z() + (func_00258490_inl4(this) - 0.5f) * 4.0f);
        v.SetX((func_00258490_inl4(this) - 0.5f) * 8.0f);
        v.SetZ((func_00258490_inl4(this) - 0.5f) * 8.0f);
        float b = GtMath::Min(1.0f, k * surf->field_8);
        if (!(b <= 0.05f)) {
            float c = b * (0.5f * (1.0f + func_00258490_inl4(this)));
            func_0025F0C0(this, &p0, &p1, &v, 4, &light, &veh->field_CC4->field_1017[2], 0, 0.3f, 4.0f * (0.75f + 0.25f * c), c, 1);
        } else {
            b = GtMath::Min(1.0f, surf->field_4 + 2.0f * k);
            float c = b * (0.5f * (1.0f + func_00258490_inl4(this)));
            func_0025F0C0(this, &p0, &p1, &v, 3, &light, &veh->field_CC4->field_1017[1], 0, 0.3f, 4.0f * (0.75f + 0.25f * c),
                          GtMath::Min(2.0f * c, 1.0f), 1);
        }
    }
    // head-on impact
    CGtV3d n(0.0f, 1.0f, 0.0f);
    CGtV3d vel = *(const CGtV3d *)&veh->field_B0;
    if (DotProduct(move, func_00258490_inl2(nrm)) < 0.707f && !(impact <= 3500)) {
        n = vel * 0.75f;
        func_0025D430(this, &pos, &n, &n, &vel, &nrm, 3, 1, 150.0f, height);
    }
    DoCrazySparksWithWorld__17CB3EffectsManagerFP16CB3CollidingBodyPC19CB3SparkSpawnParams(this, veh, &_gSparkSpawnParamsBody);
    func_00280900(&D_01E78510, 0, veh);
}
