// NONMATCHING: UpdateBodyPartWorldCollisionEffects__17CB3EffectsManagerFP19CB3TrailEmitterDataP16CB3CollidingBody -- retail 301 / ours 307 instructions, 114 in changed runs
// ghvu17 (Ghidra draft): logic and block layout right (random-spark block out of line, field_2BA==2 arm, clamps, 4 calls); scoped opt_pulloutconstants off [G] stops the 1.0 being CSEd into f20 across the random block (146 -> 129); cross product stand-in with a .i move out keeps retail's qmfc2/qmtc2 round trip (-> 114). Left: 307 vs 301 -- the vmul product of GetLength() and of the second DotProduct is parked through a GPR in ours (retail keeps it in vf2/vf4; the product lands on vf1, which the GetLength tail hard-codes), a/c on vf4/vf3 vs retail vf3/vf4, f4/f5 zero/one swapped, frame 0x170 vs 0x240 (13 dead slots; p/up/n temps placement), a3 = &info.field_10 held from the prologue in retail
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3EffectsManager::UpdateBodyPartWorldCollisionEffects(CB3TrailEmitterData*,CB3CollidingBody*) -- hand-written (ghvu17).
// [C] name: the mangled symbol in retail's tables. Classes and structs declared here with only what this function
// touches; field names are placeholders and every type is [G] (instruction widths).
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/_unclassified/GtRandom.h"
#pragma push
#pragma opt_pulloutconstants off
using namespace GtMathPs2;

class CB3TrailEmitterData;
struct UnkStruct_00257FD0_info {
    CGtV3d field_0;
    CGtV3d field_10;
    CGtV3d field_20;
    short field_30;
    float field_34;
    int field_38;
    CGtV3d field_40;
    CGtV3d field_50;
};
struct UnkStruct_00257FD0_204 { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_00257FD0_car { unsigned char pad_0[0x5C]; float field_5C; float field_60; };
struct UnkStruct_00257FD0_2B0 { unsigned char pad_0[0xCC0]; UnkStruct_00257FD0_car * field_CC0; };
struct UnkStruct_00257FD0_290 { unsigned char pad_0[0x10]; };
class CB3CollidingBody {
public:
    unsigned char pad_0[0xB0];
    CGtV3d field_B0;
    unsigned char pad_C0[0x10];
    CGtV3d field_D0;
    unsigned char pad_E0[0x80];
    UnkStruct_00257FD0_info field_160;
    unsigned char pad_1C0[0x44];
    UnkStruct_00257FD0_204 * field_204;
    unsigned char pad_208[0x88];
    UnkStruct_00257FD0_290 field_290;
    unsigned char pad_2A0[0x10];
    UnkStruct_00257FD0_2B0 * field_2B0;
    unsigned char pad_2B4[6];
    unsigned char field_2BA;
};
struct UnkStruct_00257FD0_16 { unsigned char pad_0[0x10]; };
extern UnkStruct_00257FD0_16 _gSparkSpawnParamsBody;
extern float D_004E29E8;
extern float D_004E19AC;
extern float D_004E19B0;
extern float D_004E19B4;
extern float D_004E19B8;
extern float D_004E19BC;
extern float D_004E19EC;
class CB3EffectsManager {
public:
    class CLighting {
    public:
        float field_0;
        float field_4;
    };
    void UpdateBodyPartWorldCollisionEffects(CB3TrailEmitterData *, CB3CollidingBody *);
    unsigned char pad_0[0x16C80];
    unsigned char field_16C80[0x8BA8];
    CGtRandom field_1F828;
};
extern "C" void func_00375840(void *, void *, const CGtV3d *, const CGtV3d *, int, const void *);
extern "C" void func_0025D430(CB3EffectsManager *, const CGtV3d *, const CGtV3d *, const CGtV3d *, const CGtV3d *, const CGtV3d *, int, int, float, float);
extern "C" void func_0025EA70(CB3EffectsManager *, const CGtV3d *, const CGtV3d *, const CGtV3d *, int, const CB3EffectsManager::CLighting *, void *, int, unsigned long, float, float);
extern "C" void DoCrazySparksWithWorld__17CB3EffectsManagerFP16CB3CollidingBodyPC19CB3SparkSpawnParams(CB3EffectsManager *, CB3CollidingBody *, void *);

// [L] N185: CGtV3d subtract on compiler-chosen VU registers (result on the second operand's register, as retail)
static inline CGtV3d func_00257FD0_inl1(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %2, %1" : "=j"(r) : "j"(b.mData), "j"(a.mData)); return CGtV3d(r); }
// [L] N185: CrossProduct with the result on the first operand's register (retail `vopmula ACC,a,b; vopmsub a,b,a`), out .ni
static inline CGtV3d func_00257FD0_inl2(CGtV3d a, CGtV3d b) { u_long128 t; asm("vopmula.xyz $ACC, %1, %2" "\n\t" "vopmsub.xyz %1, %2, %1" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(a.mData) : "j"(b.mData)); return CGtV3d(t); }
// [L] N185: unary minus on compiler-chosen registers (retail `vsub.xyz $vf1, $vf0, $vf4`)
static inline CGtV3d func_00257FD0_inl3(const CGtV3d &a) { u_long128 r; asm("vsub.xyz %0, $vf0, %1" : "=j"(r) : "j"(a.mData)); return CGtV3d(r); }
static inline float func_00257FD0_inl4(float x, float hi) { return GtMath::Min(GtMath::Max(x, 0.0f), hi); }

static inline CGtV3d func_00257FD0_inl5(CGtV3d a, const CGtV3d &b) { a += b; return a; }
// 0x00257FD0
void CB3EffectsManager::UpdateBodyPartWorldCollisionEffects(CB3TrailEmitterData * trail, CB3CollidingBody * body)
{
    UnkStruct_00257FD0_info info = body->field_160;
    CGtV3d p = body->field_204->field_30;
    p.SetY(info.field_0.Y());
    if (!(DotProduct(CGtV3d(0.0f, 1.0f, 0.0f), info.field_10) <= 0.8659999967f)) {
        float k = D_004E19EC;
        float r = k * 0.5f + k * (2.3283064e-10f * field_1F828.Random());
        CGtV3d off;
        off.SetX(r);
        off.SetY(0.0f);
        off.SetZ(r);
        CGtV3d q = p;
        q += off;
        func_00375840(field_16C80, &body->field_290, &q, &info.field_10, 0, 0);
    }
    CGtV3d n(0.0f, 1.0f, 0.0f);
    CGtV3d a = body->field_160.field_0;
    CGtV3d b = body->field_160.field_10;
    float f194 = body->field_160.field_34;
    const CGtV3d &w = body->field_D0;
    CGtV3d d = func_00257FD0_inl1(a, body->field_204->field_30);
    CGtV3d c = func_00257FD0_inl5(func_00257FD0_inl2(w, d), body->field_B0);
    c.GetLength();
    if (body->field_2BA == 2) {
        d = func_00257FD0_inl1(a, body->field_204->field_30);
        c = func_00257FD0_inl5(func_00257FD0_inl2(w, d), body->field_B0);
        if (DotProduct(c, func_00257FD0_inl3(b)) < 0.7070000172f && f194 > 1750) {
            n = c * 0.75f;
            UnkStruct_00257FD0_car * car = body->field_2B0->field_CC0;
            float a5C = car->field_5C;
            float a60 = car->field_60;
            float m = GtMath::Min(a60, a5C);
            float x1 = func_00257FD0_inl4(D_004E19AC * (a5C - D_004E29E8), 1.0f);
            float x2 = func_00257FD0_inl4(D_004E19B4 * (a60 - D_004E19B0), 1.0f);
            float s = x1 + x2;
            s = s * s;
            if (x1 < x2) s = s + x1; else s = s + x2;
            CLighting light;
            light.field_4 = func_00257FD0_inl4(s * D_004E19BC, 1.0f);
            light.field_0 = func_00257FD0_inl4(m * D_004E19B8, 1.0f - light.field_4);
            func_0025D430(this, &a, &n, &n, &c, &b, 3, 1, 75.0f, 0.0f);
            func_0025D430(this, &a, &n, &n, 0, &b, 1, 1, 75.0f, 0.0f);
            func_0025EA70(this, &a, &n, &n, 2, &light, 0, 0, 0, 8.0f, 1.0f);
            DoCrazySparksWithWorld__17CB3EffectsManagerFP16CB3CollidingBodyPC19CB3SparkSpawnParams(this, body, &_gSparkSpawnParamsBody);
        }
    } else {
        DoCrazySparksWithWorld__17CB3EffectsManagerFP16CB3CollidingBodyPC19CB3SparkSpawnParams(this, body, &_gSparkSpawnParamsBody);
    }
}


#pragma pop

