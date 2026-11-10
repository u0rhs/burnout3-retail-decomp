// NONMATCHING: Update__22CB3SoundTrafficVehicleFbf -- retail 982 / ours 970 instructions, 669 in changed runs
// draftAD C-first: all 34 calls, every branch/store/constant; per-kind op counts agree except bool materialisation (daddiu) and 2 signed-char reloads; 669 changed = block order (horn arm placed before StartHorn arm), frame 0x560 vs 0x5A0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block decoded to a statement (asm read end to end); call sequence identical as a multiset (StartHorn/UpdateHorn arms swapped in layout only); per-mnemonic counts equal for FPU/VU/arith ops

// CB3SoundTrafficVehicle::Update(bool,float) -- hand-written C-first draft (draftAD, 2026-10-31); the lifter refused it.
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3SoundTrafficVehicle.cpp.
// Parameter names [L]: Revenge STABS Update__22CB4SoundTrafficVehiclebf (lbBoostMode, lrBoostLevel; tools/stabs_lookup.py).
// Classes and structs are declared here with only what this function touches; field names are placeholders and every
// type is [G] (instruction widths). VU math through the GtMathPs2 header (GetLength, NormaliseFast, IsEffectivelyZero,
// DotProduct, operator-).

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

class CGtSoundWave {
public:
    float CalcFrequency() const;
};

// [G] 0x50 bytes (retail's frame: Construct() targets 0x50 apart); offsets from the stores below
class CGtSoundVoiceParams {
public:
    void Construct();
    float field_0;     // position x, y, z [L] (this->field_B0)
    float field_4;
    float field_8;
    float field_C;     // velocity x, y, z [L] (GetVelocity)
    float field_10;
    float field_14;
    const CGtSoundWave * field_18;
    float field_1C;    // volume [L]
    float field_20;
    float field_24;    // frequency [L] (pitch * CalcFrequency())
    unsigned char pad_28[0x10];
    float field_38;    // 500.0f, or the L-train max audible distance [L]
    float field_3C;    // the L-train min audible distance [L]
    int field_40;
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0xA];
};

class CGtSoundVirtualVoice {
public:
    void Update(const CGtSoundVoiceParams *);
    void Stop();
    unsigned char pad_0[0xC];
    int field_C;
};

class CGtSoundVoiceManager {
public:
    CGtSoundVirtualVoice * TriggerVoice(const CGtSoundVoiceParams *);
    unsigned char pad_0[0x10];   // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtSoundListenerManager {
public:
    unsigned char pad_0[0x10];   // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundTrafficPass {
public:
    void Update(float, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *, float);
    unsigned char pad_0[0xA0];
};

// [L] the traffic vehicle this sound follows (CB3SoundTrafficVehicle::Activate stores a CB3TrafficVehicle* at +0)
struct UnkStruct_002795F0_tv {
    unsigned char pad_0[0x90];
    CGtV3d field_90;   // velocity [L] (normalised, dotted with the player's heading)
    CGtV3d field_A0;   // position [L]
    unsigned char pad_B0[0x14];
    float field_C4;    // speed [G] (/ 10, clamped to 0..1)
};

// [L] the listening player's race car: velocity (w = speed in m/s: * 2.2369363 = mph) and its matrix
struct UnkStruct_002795F0_car {
    unsigned char pad_0[0xB0];
    CGtV3d field_B0;
    unsigned char pad_C0[0x144];
    CGtMatrix3x4 * field_204;
};

struct UnkStruct_002795F0_pl {   // [G] 0x30-byte per-player record, the car first
    UnkStruct_002795F0_car * field_0;
    unsigned char pad_4[0x2C];
};

struct UnkStruct_002795F0_rnd {   // [G] CGtRandom padded: retail addresses it with lui/addiu (> 8 bytes, N50)
    CGtRandom field_0;
    unsigned char pad_8[0x8];
};

struct UnkStruct_002795F0_b {
    unsigned char field_0;
    unsigned char pad_1[0xF];   // [G] size: absolute addressing needs > 8 bytes (N50)
};

union UnkStruct_002795F0_uv { u_long128 q; float f[4]; };

class CB3SoundTrafficVehicle {
public:
    void Update(bool lbBoostMode, float lrBoostLevel);
    void UpdateDoppler(float *, float *, float);
    void StartHorn();
    void UpdateHorn(float, float, bool);
    void StartSpecialVehicle(float, float, float, float, CGtSoundVirtualVoice **, const CGtSoundWave *);

    UnkStruct_002795F0_tv * field_0;
    unsigned char pad_4[0xC];
    CB3SoundTrafficPass field_10;
    CGtV3d field_B0;                  // position, copied from field_0->field_A0
    CGtSoundVirtualVoice * field_C0;  // engine voice / L-train squeak voice
    CGtSoundVirtualVoice * field_C4;  // type 4/5 voice / L-train rails voice
    CGtSoundVirtualVoice * field_C8;  // horn voice (IsHorning)
    const CGtSoundWave * field_CC;
    const CGtSoundWave * field_D0;
    unsigned char pad_D4[0x4];
    float field_D8;                   // horn volume [G]
    unsigned char pad_DC[0x4];
    float field_E0;                   // UpdateDoppler outputs [L]: pitch, volume
    float field_E4;
    unsigned char pad_E8[0xC];
    float field_F4;
    float field_F8;
    float field_FC;
    float field_100;
    float field_104;
    float field_108;
    unsigned char pad_10C[0x4];
    int field_110;
    unsigned int field_114;           // flags: 1 pitch rising, 4 squeaks, 8, 0x10 no horn blips, 0x20 horn pattern
    int field_118;
    int field_11C;
    int field_120;                    // vehicle category (Activate's switch; 7 = L-train)
    unsigned char field_124;          // active
    unsigned char pad_125[0x1];
    unsigned char field_126;          // horn volume rising [G]
    signed char field_127;            // horn pattern position (mod 16)
    signed char field_128;            // horn pattern row
    signed char field_129;            // L-train squeak countdown
    signed char field_12A;
    signed char field_12B;
    signed char field_12C;            // player index
};

extern UnkStruct_002795F0_pl D_0055EFEC[];
extern UnkStruct_002795F0_rnd D_01E78E58;
extern UnkStruct_002795F0_b D_00665EA0;
extern UnkStruct_002795F0_b D_004EE040;
extern CGtSoundVoiceManager D_01E7569C;
extern CGtSoundListenerManager D_01E75688;
extern float D_01E78F0C[];   // [G] horn volume floor factor
extern int D_01E78F10[];     // [G] horn blip on-time min / max (F10/F18), off-time min / max (F14/F1C)
extern int D_01E78F14[];
extern int D_01E78F18[];
extern int D_01E78F1C[];
extern float D_004E0D6C;     // 2.2369363 (m/s -> mph)
extern float D_004E0E00;     // 0.2
extern float D_004E12D0;     // 0.05
extern float D_004E1394;     // -0.55
extern float D_004E1398;     // -0.998
extern unsigned char _gau8HornPatterns[];
extern float _grTrainPitchVariationMax, _grTrainPitchVariationMin, _grTrainPitchVariationStep;
extern int _gnUpdatesDuringSqueak, _gnUpdatesBetweenSqueaks, _gnSqueakDurationVariation, _gnTimeBetweenSqueaksVariation;
extern float _grLTrainSqueakVolumeBase, _grLTrainSqueakVolumeRange, _grLTrainRailsVolume;
extern float _grLTrainMaxAudibleDistance, _grLTrainMinAudibleDistance;
extern float _grLTrainSqueakPitchBase, _grLTrainSqueakPitchRange;

extern "C" int func_00131E40(void *);
// [L] CGtSoundListenerManager::GetNearestListener(GtMathPs2::CGtV3d) const -- retail passes &field_B0 (hidden reference)
extern "C" void * GetNearestListener__23CGtSoundListenerManagerCFQ29GtMathPs26CGtV3d(const void *, const void *);
extern "C" void GetVelocity__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(void *, CGtV3d *);

// [G] a vector's x, y, z into three floats (retail: one 16-byte stack copy, three lwc1/swc1)
static inline void func_002795F0_inl1(float * d, const CGtV3d & v)
{
    UnkStruct_002795F0_uv t;
    t.q = v.mData;
    d[0] = t.f[0];
    d[1] = t.f[1];
    d[2] = t.f[2];
}

// [G] the shared CGtRandom through a pointer (retail takes its address once per use, as Activate's proven copy)
static inline unsigned int func_002795F0_inl6()
{
    CGtRandom * const r = &D_01E78E58.field_0;
    return r->Random();
}

// [G] CGtRandom::RandomReal()-style 0..1 value (retail: unsigned -> float, * 2^-32)
static inline float func_002795F0_inl2()
{
    return (float)func_002795F0_inl6() * 2.3283064e-10f;
}

// [G] inlined twice (L-train rails and squeak voices): a positioned voice update with the nearest listener's velocity
static inline void func_002795F0_inl3(CB3SoundTrafficVehicle * self, float vol, float pitch, CGtSoundVirtualVoice * v, const CGtSoundWave * w)
{
    CGtSoundVoiceParams prm;
    CGtV3d vel;
    prm.Construct();
    func_002795F0_inl1(&prm.field_0, self->field_B0);
    void * l = GetNearestListener__23CGtSoundListenerManagerCFQ29GtMathPs26CGtV3d(&D_01E75688, &self->field_B0);
    GetVelocity__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(l, &vel);
    prm.field_18 = w;
    prm.field_1C = vol;
    func_002795F0_inl1(&prm.field_C, vel);
    prm.field_24 = pitch * w->CalcFrequency();
    if (func_00131E40(&D_004EE040)) {
        prm.field_38 = 500.0f;
    }
    v->Update(&prm);
}

// [G] next horn on/off countdown: min + Random() % (max - min)
static inline signed char func_002795F0_inl4(int * lo, int * hi)
{
    int a = lo[0];
    return a + func_002795F0_inl6() % (hi[0] - a);
}

// [G] the next horn pattern entry, the position wrapping at 16
static inline unsigned char func_002795F0_inl5(CB3SoundTrafficVehicle * self)
{
    unsigned char r = _gau8HornPatterns[self->field_128 * 16 + self->field_127];
    self->field_127++;
    self->field_127 = self->field_127 % 16;
    return r;
}

// 0x002795F0
void CB3SoundTrafficVehicle::Update(bool lbBoostMode, float lrBoostLevel)
{
    if (field_0 == 0) return;
    if (field_124 == 0) return;

    field_B0 = field_0->field_A0;
    UpdateDoppler(&field_E0, &field_E4, lrBoostLevel);

    if (field_120 == 4 || field_120 == 5) {
        if (field_C4 == 0) {
            CGtSoundVoiceParams prm;
            prm.Construct();
            prm.field_18 = field_D0;
            prm.field_44 = 8;
            prm.field_45 = 1;
            if (D_00665EA0.field_0 != 0) {
                prm.field_38 = 500.0f;
            }
            prm.field_40 = (field_110 * 100) % 3950;
            field_C4 = D_01E7569C.TriggerVoice(&prm);
            if (field_C4 != 0) {
                field_11C = field_C4->field_C;
            }
        } else {
            float vol = field_E4;
            CGtSoundVoiceParams prm;
            prm.Construct();
            func_002795F0_inl1(&prm.field_0, field_B0);
            float s = GtMath::Min(GtMath::Max(field_0->field_C4 / 10.0f, 0.0f), 1.0f);
            prm.field_1C = field_F8 * vol;
            if (prm.field_1C < D_004E0E00) prm.field_1C = D_004E0E00;
            prm.field_24 = field_108 * s;
            if (prm.field_24 < 0.5f) prm.field_24 = 0.5f;
            prm.field_24 *= field_D0->CalcFrequency();
            if (func_00131E40(&D_004EE040)) {
                prm.field_38 = 500.0f;
            }
            field_C4->Update(&prm);
        }
    }

    // the listening player's car against this vehicle
    UnkStruct_002795F0_car * car = D_0055EFEC[field_12C].field_0;
    CGtV3d lVel = field_0->field_90;
    CGtV3d lCarVel = car->field_B0;
    CGtV3d lCarDir;
    if (lCarVel.GetLength() < 1.0f) {
        lCarDir = car->field_204->mAt;
    } else {
        lCarDir = lCarVel;
        lCarDir.NormaliseFast();
    }
    CGtV3d lToVehicle = field_B0 - car->field_204->mPos;
    if (!lToVehicle.IsEffectivelyZero()) lToVehicle.NormaliseFast();
    if (!lVel.IsEffectivelyZero()) lVel.NormaliseFast();
    float lrHeadingDot = DotProduct(lVel, lCarDir);
    float lrOffsetDot = DotProduct(lToVehicle, lVel);
    float lrDistance = (car->field_204->mPos - field_B0).GetLength();

    bool lbOncoming = true;
    if (lrHeadingDot > 0.0f) lbOncoming = false;
    if (lbOncoming) {
        if (field_C8 == 0) {
            if (lrOffsetDot < D_004E1394) {
                if (lrDistance < 15.0f && lrOffsetDot < D_004E1398 && (field_114 & 8) == 0
                    && (unsigned int)(field_120 - 1) < 5) {
                    field_114 |= 8;
                }
                if (lrDistance < 50.0f) {
                    StartHorn();
                    field_126 = 1;
                    field_12A = 0;
                    field_12B = func_002795F0_inl4(D_01E78F14, D_01E78F1C);
                }
            }
        } else {
            // horning: volume from distance, blipped by the on/off countdowns
            float v;
            if (D_0055EFEC[field_12C].field_0->field_B0.GetLength() <= 15.0f) {
                v = 0.0f;
            } else {
                float t = GtMath::Min(GtMath::Max((100.0f - lrDistance) / 100.0f, 0.0f), 1.0f);
                float sq = t * t;
                if (lrBoostLevel > 0.5f) sq = sq * sq;
                v = t * D_01E78F0C[0];
                if (!(sq <= v)) v = sq;
            }
            if ((field_114 & 0x10) == 0 && lrDistance > 5.0f) {
                if (field_12B != 0) {
                    field_12B--;
                    if (field_D8 > 0.0f) {
                        field_D8 = field_D8 - 0.25f;
                        if (field_D8 < 0.0f) field_D8 = 0.0f;
                    }
                    v = field_D8;
                    if (field_12B <= 0) {
                        if (field_114 & 0x20) {
                            field_12A = func_002795F0_inl5(this);
                        } else {
                            field_12A = func_002795F0_inl4(D_01E78F10, D_01E78F18);
                        }
                    }
                } else {
                    field_12A--;
                    if (field_126) {
                        float top = 1.25f * v;
                        if (field_D8 <= top) {
                            field_D8 = field_D8 + 0.25f;
                            if (!(field_D8 <= top)) {
                                field_D8 = top;
                                field_126 = 0;
                            }
                        }
                    } else {
                        if (!(field_D8 < v)) {
                            field_D8 = field_D8 - D_004E12D0;
                            if (field_D8 < v) field_D8 = v;
                        }
                    }
                    v = field_D8;
                    if (field_12A <= 0) {
                        if (field_114 & 0x20) {
                            field_12B = func_002795F0_inl5(this);
                        } else {
                            field_12B = func_002795F0_inl4(D_01E78F14, D_01E78F1C);
                        }
                    }
                }
            }
            float lrBoost = lrBoostLevel * 0.75f;
            lrBoost += 0.25f;
            UpdateHorn(field_E0, v * lrBoost, lrOffsetDot > 0.0f);
        }
    }

    if (field_120 == 7) {
        // L-train: rails loop, random squeaks, pitch wobble
        CGtSoundVoiceParams lParams;
        lParams.Construct();
        lParams.field_38 = _grLTrainMaxAudibleDistance;
        lParams.field_3C = _grLTrainMinAudibleDistance;
        CGtSoundVirtualVoice * v = field_C4;
        if (v == 0) {
            StartSpecialVehicle(_grLTrainRailsVolume, _grLTrainMaxAudibleDistance, _grLTrainMinAudibleDistance,
                                field_108, &field_C4, field_D0);
            field_11C = field_C4->field_C;
        } else {
            func_002795F0_inl3(this, _grLTrainRailsVolume, field_108, v, field_D0);
        }
        v = field_C0;
        if (v == 0) {
            if (field_129 == 0 && (field_114 & 4) != 0) {
                field_100 = (0.0f + _grLTrainSqueakPitchBase) + _grLTrainSqueakPitchRange * func_002795F0_inl2();
                field_104 = (0.0f + _grLTrainSqueakVolumeBase) + _grLTrainSqueakVolumeRange * func_002795F0_inl2();
                StartSpecialVehicle(field_104, _grLTrainMaxAudibleDistance, _grLTrainMinAudibleDistance,
                                    field_100, &field_C0, field_CC);
                field_118 = field_C0->field_C;
                field_129 = _gnUpdatesDuringSqueak + func_002795F0_inl6() % _gnSqueakDurationVariation;
            }
        } else if (field_129 == 0) {
            v->Stop();
            field_C0 = 0;
            field_129 = _gnUpdatesBetweenSqueaks + func_002795F0_inl6() % _gnTimeBetweenSqueaksVariation;
        } else {
            func_002795F0_inl3(this, field_104, field_100, v, field_CC);
        }
        field_129--;
        if (field_114 & 1) {
            field_108 += _grTrainPitchVariationStep;
            if (field_108 >= _grTrainPitchVariationMax) field_114 &= ~1;
        } else {
            field_108 -= _grTrainPitchVariationStep;
            if (field_108 <= _grTrainPitchVariationMin) field_114 |= 1;
        }
    } else if (field_C0 == 0) {
        CGtSoundVoiceParams prm;
        prm.Construct();
        prm.field_18 = field_CC;
        prm.field_45 = 1;
        prm.field_44 = 8;
        if (D_00665EA0.field_0 != 0) {
            prm.field_38 = 500.0f;
        }
        prm.field_40 = (field_110 * 100) % 4050;
        field_C0 = D_01E7569C.TriggerVoice(&prm);
        if (field_C0 != 0) {
            field_118 = field_C0->field_C;
        }
    } else {
        float pitch = field_E0;
        float vol = field_E4;
        if (field_CC != 0) {
            CGtSoundVoiceParams prm;
            prm.Construct();
            func_002795F0_inl1(&prm.field_0, field_B0);
            prm.field_1C = field_F4 * vol;
            prm.field_24 = field_100 * pitch * field_CC->CalcFrequency();
            if (D_00665EA0.field_0 != 0) {
                prm.field_38 = 500.0f;
            }
            field_C0->Update(&prm);
        }
    }

    // the pass-by sound: the player's position and heading (its matrix's at-row when nearly stopped)
    UnkStruct_002795F0_car * pc = D_0055EFEC[field_12C].field_0;
    CGtV3d lPos = pc->field_204->mPos;
    CGtV3d lDir;
    float w = ((CGtV4d *)&pc->field_B0)->W();
    if (D_004E0D6C * w < 1.0f) {
        lDir = pc->field_204->mAt;
    } else {
        lDir = pc->field_B0;
    }
    field_10.Update(lrBoostLevel, &lPos, &lDir, &field_B0, &field_0->field_90, field_FC);
}

