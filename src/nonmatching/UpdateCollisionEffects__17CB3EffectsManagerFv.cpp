// NONMATCHING: UpdateCollisionEffects__17CB3EffectsManagerFv -- retail 195 / ours 195 instructions, 10 in changed runs
// near31: 10 off: type-test inline as 'bool ok = true; if ((unsigned)st > 2) { bool r = st == 4 || st == 6 || st == 7; if (!r) ok = false; } return ok;' (retail's sllv/andi 0xD bit test, r = ok reuse), body pointer declared at its use inside the loop (fixes the e/b/m s-regs); pad renamed UnkStruct_0025CA30_pad. Left: type in a1 / constant 1 in a0 (retail reverse), one addiu a3 (vec address) scheduled 2 later
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: UpdateCollisionEffects__17CB3EffectsManagerFv -- retail 195 / ours 193 instructions, 45 in changed runs
// a226: inline type test as 'bool ok = true; if (st>=3) { bool r=false; ...; if (!r) ok=false; } return ok;' (a3 holds ok as retail) 54->45; left: e/m/b s-reg allocation (e=s3,m=s4,b=s2), sltu vs beqz on mask 0xD test
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// NONMATCHING: UpdateCollisionEffects__17CB3EffectsManagerFv -- retail 195 / ours 190 instructions, 54 in changed runs
// a202: frame 0x80 now matches via 16-byte N140 pad (UnkStruct_0025CA30_pad, ctor+dtor) declared before vec; left: register allocation (e/m/b s-regs), the mask-0xD test li hoist
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// NONMATCHING: UpdateCollisionEffects__17CB3EffectsManagerFv -- retail 195 / ours 190 instructions, 56 in changed runs
// a143: logic complete (pairs loop, body loop with jtbl switch 0-7 and nested prop-type switch 0-8, 20-slot flag loop); 189 vs 195 instrs, ~75 in changed runs: frame 0x70 vs 0x80 (retail has one more 16-byte slot below the PropImpact vec copy), body type kept in a0 with 'li a1,1' hoisted (the open a94 mask-0xD test: ours rebuilds 1 in v1), e/m take s1/s2 and b s3 where retail has e=s3,m=s4,b=s2 (b shares the loop-1 count register)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_UCE_pairobj { unsigned char pad_0[1]; unsigned char field_1; };
struct UnkStruct_UCE_pair {
    unsigned char pad_0[0x24];
    UnkStruct_UCE_pairobj * field_24;
    UnkStruct_UCE_pairobj * field_28;
    unsigned char field_2C;
    unsigned char pad_2D[3];
};
struct UnkStruct_UCE_v3 { u_long128 q; };
struct UnkStruct_UCE_o204 { unsigned char pad_0[0x30]; unsigned long long q[2]; };
struct UnkStruct_UCE_o220 { unsigned char pad_0[2]; unsigned char field_2; };
struct UnkStruct_UCE_body {
    unsigned char pad_0[0x194];
    float field_194;
    int field_198;
    unsigned char pad_19C[0x68];
    UnkStruct_UCE_o204 * field_204;
    unsigned char pad_208[0x18];
    UnkStruct_UCE_o220 * field_220;
    unsigned char pad_224[0x94];
    short field_2B8;
    unsigned char field_2BA;
};
struct UnkStruct_UCE_ent {
    signed char field_0;
    unsigned char field_1;
    unsigned char pad_2[0xA];
    UnkStruct_UCE_body * field_C;
    unsigned char pad_10[0x20];
};
struct UnkStruct_UCE_cnt { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_UCE_ptr { unsigned char * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_UCE_e9 { unsigned char pad_0[9]; unsigned char field_9; unsigned char pad_A[6]; };
struct UnkStruct_UCE_arr { UnkStruct_UCE_pair f[1]; };
struct UnkStruct_UCE_arr2 { UnkStruct_UCE_ent f[1]; };
struct UnkStruct_UCE_arr3 { UnkStruct_UCE_e9 f[20]; };
struct UnkStruct_UCE_16 { unsigned char pad_0[0x10]; };
extern UnkStruct_UCE_cnt D_00648180;
extern UnkStruct_UCE_cnt D_0057BAE0;
extern UnkStruct_UCE_arr D_00645180;
extern UnkStruct_UCE_arr2 D_0055EFE0;
extern UnkStruct_UCE_arr3 D_006481A0;
extern UnkStruct_UCE_ptr D_0064A85C;
extern UnkStruct_UCE_16 D_01E78510;
extern UnkStruct_UCE_16 _gSparkSpawnParamsBody;
struct UnkStruct_0025CA30_pad { unsigned char field_0[0x10]; UnkStruct_0025CA30_pad() {} ~UnkStruct_0025CA30_pad() {} };
class CB3EffectsManager {
public:
    void UpdateCollisionEffects();
};
extern "C" void HandleObjectObjectCollisionEffects__17CB3EffectsManagerFPC16CB3CollidingPair(CB3EffectsManager *, UnkStruct_UCE_pair *);
extern "C" void UpdateRaceCarWorldCollisionEffects__17CB3EffectsManagerFP17CB3RaceCarPhysicsb(CB3EffectsManager *, UnkStruct_UCE_body *, bool);
extern "C" void UpdateTrafficWorldCollisionEffects__17CB3EffectsManagerFP17CB3VehiclePhysics(CB3EffectsManager *, UnkStruct_UCE_body *);
extern "C" void PropImpact__20CB3SoundCrashManagerFb11EB3PropTypeQ29GtMathPs26CGtV3df(void *, bool, unsigned int, const void *, float);
extern "C" void DoCrazySparksWithWorld__17CB3EffectsManagerFP16CB3CollidingBodyPC19CB3SparkSpawnParams(CB3EffectsManager *, UnkStruct_UCE_body *, void *);
extern "C" void PayLoadImpact__20CB3SoundCrashManagerFbP18CB3BodyPartPhysicsf(void *, bool, UnkStruct_UCE_body *, float);
extern "C" void BodyPartImpact__20CB3SoundCrashManagerFb17EVehicleFlyingBitQ29GtMathPs26CGtV3df(void *, bool, int, const void *, float);
extern "C" void WheelImpact__20CB3SoundCrashManagerFbQ29GtMathPs26CGtV3df(void *, bool, const void *, float);
extern "C" void UpdateBodyPartWorldCollisionEffects__17CB3EffectsManagerFP19CB3TrailEmitterDataP16CB3CollidingBody(CB3EffectsManager *, void *, UnkStruct_UCE_body *);
extern "C" void UpdateBodyPartDustTrail__17CB3EffectsManagerFP18CB3BodyPartPhysics(CB3EffectsManager *, void *);
extern "C" void func_00257860(CB3EffectsManager *, void *);

static inline bool func_UCE_inl1(int st)
{
    bool ok = true;
    if ((unsigned)st > 2) {
        bool r = st == 4 || st == 6 || st == 7;
        if (!r) ok = false;
    }
    return ok;
}

void CB3EffectsManager::UpdateCollisionEffects()
{
    int i;
    int n = D_00648180.field_0;
    UnkStruct_UCE_pair * p = D_00645180.f;
    while (n--) {
        if (p->field_2C != 0) {
            if (p->field_24->field_1 == 0 && p->field_28->field_1 == 0) {
                HandleObjectObjectCollisionEffects__17CB3EffectsManagerFPC16CB3CollidingPair(this, p);
            }
        }
        p++;
    }
    int m = D_0057BAE0.field_0;
    UnkStruct_UCE_ent * e = D_0055EFE0.f;
    while (m--) {
        int type = e->field_0;
        if (func_UCE_inl1(type)) {
            if (e->field_1 == 0) {
                UnkStruct_UCE_body * b = e->field_C;
                if (b->field_198 != 0) {
                    switch (type) {
                    case 2:
                        UpdateRaceCarWorldCollisionEffects__17CB3EffectsManagerFP17CB3RaceCarPhysicsb(this, b, true);
                        break;
                    case 0:
                    case 1:
                        UpdateRaceCarWorldCollisionEffects__17CB3EffectsManagerFP17CB3RaceCarPhysicsb(this, b, false);
                        break;
                    case 4:
                        UpdateTrafficWorldCollisionEffects__17CB3EffectsManagerFP17CB3VehiclePhysics(this, b);
                        break;
                    case 6: {
                        unsigned int pt = D_0064A85C.field_0[b->field_220->field_2];
                        UnkStruct_0025CA30_pad pad;
UnkStruct_UCE_v3 vec = *(UnkStruct_UCE_v3 *)((char *)b->field_204 + 0x30);
                        PropImpact__20CB3SoundCrashManagerFb11EB3PropTypeQ29GtMathPs26CGtV3df(&D_01E78510, true, pt, &vec, b->field_194);
                        switch (pt) {
                        case 0:
                        case 1:
                        case 2:
                        case 4:
                        case 7:
                        case 8:
                            break;
                        case 3:
                        case 5:
                        case 6:
                            DoCrazySparksWithWorld__17CB3EffectsManagerFP16CB3CollidingBodyPC19CB3SparkSpawnParams(this, b, &_gSparkSpawnParamsBody);
                            break;
                        }
                        break;
                    }
                    case 7:
                        if (b->field_2BA == 0) {
                            WheelImpact__20CB3SoundCrashManagerFbQ29GtMathPs26CGtV3df(&D_01E78510, true, (char *)b->field_204 + 0x30, b->field_194);
                        } else {
                            if (b->field_2BA == 2) {
                                PayLoadImpact__20CB3SoundCrashManagerFbP18CB3BodyPartPhysicsf(&D_01E78510, true, b, b->field_194);
                            } else {
                                BodyPartImpact__20CB3SoundCrashManagerFb17EVehicleFlyingBitQ29GtMathPs26CGtV3df(&D_01E78510, true, b->field_2B8, (char *)b->field_204 + 0x30, b->field_194);
                            }
                            UpdateBodyPartWorldCollisionEffects__17CB3EffectsManagerFP19CB3TrailEmitterDataP16CB3CollidingBody(this, (char *)b + 0x270, b);
                        }
                        break;
                    }
                    if (e->field_0 == 7) {
                        UpdateBodyPartDustTrail__17CB3EffectsManagerFP18CB3BodyPartPhysics(this, *(void **)((char *)e + 0xC));
                    }
                }
            }
        }
        e++;
    }
    UnkStruct_UCE_e9 * q = D_006481A0.f;
    for (i = 0; i < 20; i++, q++) {
        if (q->field_9 != 0) {
            func_00257860(this, q);
            q->field_9 = 0;
        }
    }
}


