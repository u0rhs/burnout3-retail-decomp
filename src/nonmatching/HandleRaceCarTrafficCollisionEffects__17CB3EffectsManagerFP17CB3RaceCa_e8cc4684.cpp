// NONMATCHING: HandleRaceCarTrafficCollisionEffects__17CB3EffectsManagerFP17CB3RaceCarPhysicsP13CB3ActiveBodyPC16CB3CollidingPair -- retail 476 / ours 488 instructions, 456 in changed runs
// fix2 (2026-11-01): func_0025EA70 call gets the 11th (stack) flag 1 (retail 0x25B798) through the definition's prototype; rumble func_0022C2F0 args fixed to the matched prototype (a0 &D_004F50C0, a1 [D_004E2DCC/2DD4], a2 (s8)hud+0x27C0, f13 0); car pad_211 0xAB3 -> 0xAAF (field_CC0.. were 4 high); every gp global was named 0x7990 high; cols[0]/[1] swapped [C] retail 0x25B760/0x25B778, 0x25BAB0..0x25BB0C | Before: son7 first archive: contact-point velocities, spark/debris strengths, calls func_0025CD60/EA70/DF30 and func_0022C2F0 (rumble) decoded with real offsets; GtMathPs2 operator form of the VU0 code (frame 0x480 vs 0x120); callee prototypes (float,float,this,ptrs..) from the ABI of the call sites; retail 476 vs ours 481 instrs
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)



// CB3EffectsManager::HandleRaceCarTrafficCollisionEffects -- hand-written (son7) first archive. For a race car hitting a
// traffic/other body: works out the contact point velocity of each body, an impact "sparks" strength (from the pair's impulse,
// +0x20) and a "debris" count, then spawns sparks (func_0025CD60), scrape smoke (func_0025EA70), a bump effect (func_0025DF30) and,
// for the local player's car, a rumble pulse (func_0022C2F0). The VU0 vector arithmetic is written with GtMathPs2 operators [G].
// Field names are placeholders and every type is [G]; callee signatures follow the sibling archives (pointers for CGtV3d).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_Fx_mat { CGtV3d field_0; unsigned char pad_10[0x10]; CGtV3d field_20; CGtV3d field_30; };
struct UnkStruct_Fx_phys { unsigned char pad_0[0x30]; CGtV4d field_30; unsigned char pad_40[0x1C]; float field_5C; float field_60; };
struct UnkStruct_Fx_state { unsigned char pad_0[0x490]; CGtV4d field_490; };
struct UnkStruct_Fx_hit { unsigned char pad_0[0xA0]; CGtV3d field_A0; unsigned char pad_B0[0x14]; float field_C4; unsigned char pad_C8[8]; CGtV3d field_D0; unsigned char pad_E0[0x20]; };
struct UnkStruct_Fx_other {
    unsigned char field_0;
    unsigned char pad_1[3];
    UnkStruct_Fx_mat *field_4;
    unsigned char pad_8[4];
    UnkStruct_Fx_hit *field_C;
};
struct UnkStruct_Fx_pair { CGtV3d field_0; unsigned char pad_10[0x10]; float field_20; };
struct UnkStruct_Fx_hud { unsigned char pad_0[0x18EA]; unsigned char field_18EA; unsigned char pad_18EB[0x1C]; unsigned char pad_1907[0xD]; int field_1914; unsigned char pad_1918[0xEA8]; signed char field_27C0; };
class CB3RaceCarPhysics { public: unsigned char pad_0[4]; };
struct UnkStruct_Fx_car {
    unsigned char pad_0[0x70];
    CGtV4d field_70;   // fix3: the car's matrix rows (z column read) [C] retail 0x25B800
    CGtV4d field_80;
    CGtV4d field_90;
    CGtV4d field_A0;
    CGtV3d field_B0;
    unsigned char pad_C0[0x10];
    CGtV3d field_D0;
    unsigned char pad_E0[0x124];
    UnkStruct_Fx_mat *field_204;
    unsigned char pad_208[8];
    unsigned char field_210;
    unsigned char pad_211[0xAAF];
    UnkStruct_Fx_phys *field_CC0;
    UnkStruct_Fx_state *field_CC4;
    unsigned char pad_CC8[0x72C];
    UnkStruct_Fx_hud *field_13F4;
    unsigned char pad_13F8[0x188];
    UnkStruct_Fx_hud *field_1580;
};
class CB3ActiveBody;
class CB3CollidingPair;
class CB3EffectsManager {
public:
    void HandleRaceCarTrafficCollisionEffects(CB3RaceCarPhysics *, CB3ActiveBody *, const CB3CollidingPair *);
};
extern float D_004E1320, D_004E1324, D_004E19AC, D_004E19B0, D_004E19B4, D_004E19B8, D_004E19BC, D_004E29E8;
extern float D_004E1DC0, D_004E1DC4, D_004E1DC8, D_004E1DCC, D_004E2DD0, D_004E2DD8; // [C] gp_rel loads 0x25BAB8..0x25BAF8 (the draft had all gp globals 0x7990 high)
extern int D_004E2DCC, D_004E2DD4;
extern unsigned char D_004C9CF0[];
extern unsigned char D_004F50C0[];
extern unsigned long D_005179C0[];
extern float D_004BC630, D_004BC634, D_004BC638, D_004BC63C;
extern "C" void func_0025CD60(float, float, CB3EffectsManager *, const CGtV3d *, const CGtV3d *, const CGtV3d *, const void *, const float *, int);
// [C] the 11th argument is on the stack (retail sd v0, 0(sp) before each call); float order as the definition
extern "C" void func_0025EA70(CB3EffectsManager *, const CGtV3d *, const CGtV3d *, const CGtV3d *, int, float, float, const float *, unsigned char *, bool, bool);
extern "C" void func_0025DF30(float, float, CB3EffectsManager *, const CGtV3d *, const CGtV3d *, const CGtV3d *, const void *, int);
extern "C" void func_0022C2F0(void *, int, int, int, float, float, float, float); // [C] matched callers B3Score_00157FA0, B3RaceCarPhysics_001BFC70
extern "C" float sqrtf(float);

// fix4 (2026-11-09): [C] the w lane retail's VU code leaves in a velocity it builds (vsub.xyz / vopmsub.xyz / vadd.xyz
// write xyz only): the callees copy whole quads into the particles
static inline void func_0025B450_keep_w(CGtV3d &v, const CGtV3d &from)
{
    asm("vmove.w %0, %1" : "+j"(v.mData) : "j"(from.mData));
}

static inline float func_0025B450_sat(float x) { x = x > 0.0f ? x : 0.0f; return x < 1.0f ? x : 1.0f; }

// 0x0025B450
void CB3EffectsManager::HandleRaceCarTrafficCollisionEffects(CB3RaceCarPhysics *carp, CB3ActiveBody *bodyp, const CB3CollidingPair *pairp)
{
    UnkStruct_Fx_car *car = (UnkStruct_Fx_car *)carp;
    UnkStruct_Fx_other *other = (UnkStruct_Fx_other *)bodyp;
    const UnkStruct_Fx_pair *pair = (const UnkStruct_Fx_pair *)pairp;
    CGtV3d pos = pair->field_0;
    CGtV3d vel = CrossProduct(car->field_D0, pos - car->field_204->field_30) + car->field_B0;
    func_0025B450_keep_w(vel, car->field_204->field_30);   // fix4: [C] 0x25B494..0x25B4BC
    CGtV3d vel2 = CGtV3d(0.0f, 0.0f, 0.0f);
    if (other->field_0 == 3) {
        vel2 = other->field_4->field_20 * other->field_C->field_C4;
        func_0025B450_keep_w(vel2, other->field_4->field_20);   // fix4: [C] 0x25B4FC vmulx.xyz
    } else {
        bool ok = true;
        if (other->field_0 > 2) {
            unsigned int u = (int)(signed char)other->field_0 - 4;
            bool in = u < 4 && ((1 << (u & 0x1F)) & 0xD) != 0;
            if (!in) ok = false;
        }
        if (ok) {
            UnkStruct_Fx_hit *h = other->field_C;
            vel2 = CrossProduct(h->field_D0, pos - ((UnkStruct_Fx_car *)h)->field_204->field_30) + ((UnkStruct_Fx_car *)h)->field_B0;
            func_0025B450_keep_w(vel2, h->field_D0);   // fix4: [C] 0x25B570 vopmsub.xyz into the +0xD0 register
        }
    }
    signed char cVar2 = (signed char)car->field_210;
    bool local = car->field_13F4->field_1914 == 0;
    float sparks;
    if (cVar2 == 0) {
        sparks = 0.0f;
    } else {
        float imp = pair->field_20;
        if (imp > 1500.0f) {
            if (imp < 20000.0f) sparks = D_004E1320 * (imp - 1500.0f);
            else sparks = 25.0f;
        } else {
            sparks = 0.0f;
        }
    }
    int debris;
    if (other->field_0 == 3) {
        debris = 0;
    } else {
        float imp = pair->field_20;
        if (imp > 700.0f) {
            if (imp < 20000.0f) debris = (int)(D_004E1324 * (imp - 700.0f));
            else debris = 0x18;
        } else {
            debris = 0;
        }
    }
    // fix3 (2026-11-09): the contact's height (f21, passed as the callees' second float) [C] retail 0x25B65C..0x25B6AC:
    // over the other body's +0xA0 for type 3, else over the car's ground (state +0x490 w + y - phys +0x30 y)
    float height;
    if (other->field_0 == 3) height = pos.Y() - other->field_C->field_A0.Y();
    else height = car->field_CC4->field_490.f[3] + pos.Y() - car->field_CC0->field_30.f[1];
    if (debris != 0 || sparks >= 1.0f) {
        float f12 = car->field_CC0->field_5C;
        float f9 = car->field_CC0->field_60;
        float a = func_0025B450_sat(D_004E19AC * (f12 - D_004E29E8));
        float b = func_0025B450_sat(D_004E19B4 * (f9 - D_004E19B0));
        float sum = a + b;
        float mn = a < b ? a : b;
        float c = func_0025B450_sat((sum * sum + mn) * D_004E19BC);
        float cc = 1.0f - c;
        float m2 = (f9 < f12 ? f9 : f12) * D_004E19B8;
        float d = m2 > 0.0f ? m2 : 0.0f;
        d = d < cc ? d : cc;
        float cols[2] = { d, c }; // [C] retail 0x25B760/0x25B778: c at sp+0x47C, d at sp+0x478 = the array passed (t1)
        if (debris != 0) func_0025CD60((float)debris, height, this, &pos, &vel, &vel2, D_004C9CF0, cols, cVar2);
        if (sparks > 0.0f) func_0025EA70(this, &pos, &vel, &vel2, 2, sparks, 1.0f, cols, 0, false, true); // [C] flag 1: retail 0x25B798
    }
    if (local) {
        UnkStruct_Fx_hud *p = car->field_1580;
        if ((D_005179C0[p->field_27C0 * 0xBB0 / 8] & 0x20) != 0) {
            // fix3: [C] retail 0x25B800..0x25B86C: only when the contact is ahead in the car's frame (z > 0), as 0x25BBC0
            float z = pos.X() * car->field_70.f[2] + pos.Y() * car->field_80.f[2] + pos.Z() * car->field_90.f[2] + car->field_A0.f[2];
            if (z > 0.0f) pos = pos + car->field_204->field_20 * -1.0f;
        }
    }
    float vlen = sqrtf(DotProduct(vel, vel) < DotProduct(vel2, vel2) ? DotProduct(vel2, vel2) : DotProduct(vel, vel));
    float bump;
    if (D_004BC630 < vlen) {
        bump = D_004BC63C;
        if (vlen < D_004BC634) bump = (D_004BC63C - D_004BC638) * ((vlen - D_004BC630) / (D_004BC634 - D_004BC630)) + D_004BC638 + 0.0f;
        bump = bump * *(float *)((char *)this + 0x1F84C);
    } else {
        bump = 0.0f;
    }
    func_0025DF30(bump * 1.0f, height, this, &pos, &vel, &vel2, D_004C9CF0, cVar2);
    if (local) {
        CGtV3d dv = vel - vel2;
        float l2 = DotProduct(dv, dv);
        if (l2 >= 2.3283064e-10f) {
            float dotx = DotProduct(car->field_204->field_20, dv);
            float k = sqrtf(l2) / 20.0f;
            k = func_0025B450_sat(k * k);
            (void)dotx;
            UnkStruct_Fx_hud *h = car->field_13F4;
            // [C] retail 0x25BAB8..0x25BB0C: a0 = &D_004F50C0, a1 = int global, a2 = (s8)field_27C0, a3 = 0xFFFF, f13 = 0
            // (the clamped dot is computed and dropped)
            if (h->field_18EA == 0) func_0022C2F0(D_004F50C0, D_004E2DCC, h->field_27C0, 0xFFFF, D_004E1DC4, 0.0f, D_004E1DC0 * k, D_004E2DD0);
            else func_0022C2F0(D_004F50C0, D_004E2DD4, h->field_27C0, 0xFFFF, D_004E1DCC, 0.0f, D_004E1DC8 * k, D_004E2DD8);
        }
    }
}
