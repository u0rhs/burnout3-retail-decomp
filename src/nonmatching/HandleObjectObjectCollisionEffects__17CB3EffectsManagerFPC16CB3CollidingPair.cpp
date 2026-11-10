// NONMATCHING: HandleObjectObjectCollisionEffects__17CB3EffectsManagerFPC16CB3CollidingPair -- retail 420 / ours 400 instructions, 446 in changed runs
// fix2 (2026-11-01): type 6 - type 7 sound impacts pass the pair's impulse (pair+0x20) where the draft passed the body part's field_194 [C] retail 0x25C954/0x25C97C/0x25CA20; spark depth = (pos.y - CC0+0x30.y) + CC4+0x490.w (the draft dropped pos.y) [C] 0x25C5C0/0x25C764; type 0 tests a byte at +0x1550 (lbu), not the type-1 pointer [C] 0x25C430/0x25C4A0; HandleRaceCarTrafficCollisionEffects declared with its real parameter classes (the draft's placeholder types mangled to a symbol that does not exist) | Before: son6 first archive (388 vs 420): type-ordered pair (lo/hi by type byte), switch lo 0/1/2 fallthrough checks (+0x1550, +0x1A90, +0x13F4/0x18EB) -> func_0025BBC0 / HandleRaceCarTrafficCollisionEffects / prop+bodypart spark (func_0025DF30 with point-velocity via CrossProduct, energy = sqrt(Max(|v1|^2,|v2|^2)), _gSparkSpawnParamsBody lerp * this+0x1F84C) / sound impacts (+0x2BA kind 0/2/other), final DealWithObjectObjectCollision; left: retail frame 0x570 (several 16-byte stack copies of pair pos / velocities per case, case 6 and 7 not shared as one inline), VU register choices
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

struct UnkStruct_25C3C0_mat { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_25C3C0_ctl { unsigned char pad_0[0x490]; CGtV4d field_490; };
struct UnkStruct_25C3C0_hud { unsigned char pad_0[0x18EB]; unsigned char field_18EB; unsigned char pad_18EC[0x28]; int field_1914; unsigned char pad_1918[0x178]; };
struct UnkStruct_25C3C0_sub { unsigned char pad_0[0x1A90]; unsigned char field_1A90; };
struct UnkStruct_25C3C0_info { unsigned char pad_0[2]; unsigned char field_2; };
struct UnkStruct_25C3C0_car {   // [G] CB3RaceCarPhysics / CB3BodyPartPhysics view
    unsigned char pad_0[0xB0];
    CGtV3d field_B0;
    unsigned char pad_C0[0x10];
    CGtV3d field_D0;
    unsigned char pad_E0[0x80];
    float field_160x;
    unsigned char pad_164[0x30];
    float field_194;
    unsigned char pad_198[0x6C];
    UnkStruct_25C3C0_mat *field_204;
    unsigned char pad_208[8];
    unsigned char field_210;
    unsigned char pad_211[0xF];
    UnkStruct_25C3C0_info *field_220;
    unsigned char pad_224[0x94];
    unsigned short field_2B8;
    unsigned char field_2BA;
    unsigned char pad_2BB[0xA05];
    UnkStruct_25C3C0_mat *field_CC0;
    UnkStruct_25C3C0_ctl *field_CC4;
    unsigned char pad_CC8[0x72C];
    UnkStruct_25C3C0_hud *field_13F4;
    unsigned char pad_13F8[0x158];
    UnkStruct_25C3C0_sub *field_1550;
};
struct UnkStruct_25C3C0_o {   // [G] CB3ActiveBody view: type byte + body pointer
    signed char field_0;
    unsigned char pad_1[0xB];
    UnkStruct_25C3C0_car *field_C;
};
class CB3CollidingPair {
public:
    CGtV3d field_0;
    unsigned char pad_10[0x10];
    float field_20;
    UnkStruct_25C3C0_o *field_24;
    UnkStruct_25C3C0_o *field_28;
};
struct UnkStruct_D_0064A85C { unsigned char *field_0; unsigned char pad_4[12]; };
struct UnkStruct_gSpark { float field_0; float field_4; float field_8; float field_C; };
extern UnkStruct_D_0064A85C D_0064A85C;
extern UnkStruct_gSpark _gSparkSpawnParamsBody;
extern unsigned char D_004C9CF0[];
class CB3SoundCrashManager {
public:
    void DealWithObjectObjectCollision(const CB3CollidingPair *);
};
extern CB3SoundCrashManager D_01E78510;
extern "C" float sqrtf(float);
extern "C" void WheelImpact__20CB3SoundCrashManagerFbQ29GtMathPs26CGtV3df(CB3SoundCrashManager *, bool, const void *, float);
extern "C" void BodyPartImpact__20CB3SoundCrashManagerFb17EVehicleFlyingBitQ29GtMathPs26CGtV3df(CB3SoundCrashManager *, bool, unsigned short, const void *, float);
extern "C" void PayLoadImpact__20CB3SoundCrashManagerFbP18CB3BodyPartPhysicsf(CB3SoundCrashManager *, bool, void *, float);
extern "C" void func_0025DF30(float, float, class CB3EffectsManager *, const CGtV3d *, const CGtV3d *, const CGtV3d *, const void *, int);
extern "C" void func_0025BBC0(class CB3EffectsManager *, UnkStruct_25C3C0_car *, UnkStruct_25C3C0_car *, const CB3CollidingPair *);

class CB3RaceCarPhysics;
class CB3ActiveBody;
class CB3EffectsManager {
public:
    void HandleObjectObjectCollisionEffects(const CB3CollidingPair *);
    // [C] retail calls HandleRaceCarTrafficCollisionEffects__17CB3EffectsManagerFP17CB3RaceCarPhysicsP13CB3ActiveBodyPC16CB3CollidingPair
    void HandleRaceCarTrafficCollisionEffects(CB3RaceCarPhysics *, CB3ActiveBody *, const CB3CollidingPair *);
    unsigned char pad_0[0x1F84C];
    float field_1F84C;
};

// [G] inlined helper (name unknown): spark/bump effect for a prop or body part hit by a race car
static inline void func_0025C3C0_inl1(CB3EffectsManager *self, UnkStruct_25C3C0_car *car, UnkStruct_25C3C0_car *other, const CB3CollidingPair *pair, int flag, float scale)
{
    CGtV3d pos = pair->field_0;
    CGtV3d v1 = CrossProduct(car->field_D0, pos - car->field_204->field_30) + car->field_B0;
    CGtV3d v2 = CrossProduct(other->field_D0, pos - other->field_204->field_30) + other->field_B0;
    float py = car->field_CC0->field_30.Y();
    float depth = (float)(pos.Y() - py) + car->field_CC4->field_490.f[3];   // [C] retail 0x25C5C0 vsuby.y (pair pos - CC0+0x30).y, vaddw.y
    float l1 = v1.GetSquaredLength();
    float l2 = v2.GetSquaredLength();
    float e = sqrtf(GtMath::Max(l1, l2));
    float f;
    if (_gSparkSpawnParamsBody.field_0 < e) {
        f = _gSparkSpawnParamsBody.field_C;
        if (e < _gSparkSpawnParamsBody.field_4) {
            f = (_gSparkSpawnParamsBody.field_C - _gSparkSpawnParamsBody.field_8) * ((e - _gSparkSpawnParamsBody.field_0) / (_gSparkSpawnParamsBody.field_4 - _gSparkSpawnParamsBody.field_0)) + _gSparkSpawnParamsBody.field_8 + 0.0f;
        }
        f = f * self->field_1F84C;
    } else {
        f = 0.0f;
    }
    func_0025DF30(scale * f, depth, self, &pos, &v1, &v2, D_004C9CF0, flag);
}

// [C] the sound impact of a body part: the strength is the body part's field_194 after a race-car hit (retail 0x25C8CC..),
// the pair's impulse (pair+0x20) for a type 6 - type 7 pair (retail 0x25C954, 0x25C97C, 0x25CA20)
static inline void func_0025C3C0_inl2(UnkStruct_25C3C0_o *o, float k)
{
    UnkStruct_25C3C0_car *c = o->field_C;
    if (c->field_2BA == 0) {
        WheelImpact__20CB3SoundCrashManagerFbQ29GtMathPs26CGtV3df(&D_01E78510, false, &c->field_204->field_30, k);
    } else if (c->field_2BA == 2) {
        PayLoadImpact__20CB3SoundCrashManagerFbP18CB3BodyPartPhysicsf(&D_01E78510, false, c, k);
    } else {
        BodyPartImpact__20CB3SoundCrashManagerFb17EVehicleFlyingBitQ29GtMathPs26CGtV3df(&D_01E78510, false, c->field_2B8, &c->field_204->field_30, k);
    }
}

// 0x0025C3C0
void CB3EffectsManager::HandleObjectObjectCollisionEffects(const CB3CollidingPair *pair)
{
    UnkStruct_25C3C0_o *lo = pair->field_24;
    UnkStruct_25C3C0_o *hi = pair->field_28;
    if (lo->field_0 < hi->field_0) {
    } else {
        lo = pair->field_28;
        hi = pair->field_24;
    }
    switch (lo->field_0) {
    case 0:
        if (((unsigned char *)lo->field_C)[0x1550] == 0) return;   // [C] retail 0x25C430: a byte (lbu) for type 0, a pointer for type 1
    case 1:
        if (lo->field_0 == 1 && lo->field_C->field_1550->field_1A90 == 0) return;
    case 2: {
        UnkStruct_25C3C0_car *car = lo->field_C;
        UnkStruct_25C3C0_hud *hud = car->field_13F4;
        if (hud->field_18EB != 0) return;
        switch (hi->field_0) {
        case 0:
            if (((unsigned char *)hi->field_C)[0x1550] == 0) return;   // [C] retail 0x25C4A0 lbu
        case 1:
            if (hi->field_0 == 1 && hi->field_C->field_1550->field_1A90 == 0) return;
        case 2:
            if (hi->field_C->field_13F4->field_18EB != 0) return;
            func_0025BBC0(this, car, hi->field_C, pair);
            break;
        case 3:
        case 4:
            HandleRaceCarTrafficCollisionEffects((CB3RaceCarPhysics *)car, (CB3ActiveBody *)hi, pair);
            break;
        case 6: {
            UnkStruct_25C3C0_car *oc = hi->field_C;
            int flag = 1;
            int kind = D_0064A85C.field_0[oc->field_220->field_2];
            if (car->field_210 == 0 && kind != 8) {
                flag = 0;
            }
            if (kind == 8 || kind == 6 || kind == 5 || kind == 3) {
                func_0025C3C0_inl1(this, car, oc, pair, flag, hud->field_1914 == 0 ? 1.5f : 1.0f);
            }
            break;
        }
        case 7:
            func_0025C3C0_inl1(this, car, hi->field_C, pair, 1, hud->field_1914 == 0 ? 1.5f : 1.0f);
            func_0025C3C0_inl2(hi, hi->field_C->field_194);
            break;
        }
        break;
    }
    case 6:
        if (hi->field_0 == 7) {
            func_0025C3C0_inl2(hi, pair->field_20);
        }
        break;
    }
    D_01E78510.DealWithObjectObjectCollision(pair);
}
