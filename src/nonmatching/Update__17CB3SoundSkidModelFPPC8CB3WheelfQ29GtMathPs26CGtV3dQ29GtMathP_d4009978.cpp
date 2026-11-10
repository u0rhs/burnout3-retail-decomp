// NONMATCHING: Update__17CB3SoundSkidModelFPPC8CB3WheelfQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPP20CGtSoundVirtualVoiceQ29GtMathPs26CGtV3dbPfPfbbb -- retail 458 / ours 459 instructions, 14 in changed runs
// L286: 458/459, 14 changed. Logic complete. Left: retail copies params.pos (3 lwc1/swc1 from the sq'd CGtV3d temp at 0xB0) in its own block ending in a nop, with the IsEffectivelyZero-style bits test (and 0x7F800000 < 0x37800001) in the next block; the int load of vol is hoisted into the copy block. Plain struct copy (28 off) lets MWCC interleave the test; a 3-iteration loop (this file) gives the block split but MWCC does not unroll it (opt_unroll_loops no effect). Solved: pitch-curve inline = clamp/loop via e->mode[m].pitch[k], interpolation via ((E*)((char*)e + k*16))->mode[m].pitch[0] (retail recomputes s4+k*16); wheel pointer-to-element local; vm = v; vm *= m.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3SoundSkidModel::Update(const CB3Wheel**, float, CGtV3d, CGtV3d, CGtSoundVirtualVoice**, CGtV3d, bool, float*, float*, bool, bool, bool)
#include "b3/GtMathPs2.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

class CB3Wheel {
public:
    unsigned char pad_0[0x50];
    float field_50;
    unsigned char pad_54[0x8];
    float field_5C;
    unsigned char pad_60[0x18];
    int field_78;
    unsigned char pad_7C[0x34];
    unsigned char field_B0;
    unsigned char pad_B1[0x2];
    unsigned char field_B3;
};
class CGtSoundVirtualVoice;
class CGtSoundWave;

struct UnkStruct_0028E2E0_v3 { float x; float y; float z; };
struct UnkStruct_0028E2E0_params {
    UnkStruct_0028E2E0_v3 field_0;
    unsigned char pad_C[0xC];
    CGtSoundWave * field_18;
    float field_1C;
    float field_20;
    float field_24;
    unsigned char pad_28[0x18];
    unsigned int field_40;
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0xA];
};

// [C] class name CB3SoundSkidModelGraph (CalcVolumeOutput__22CB3SoundSkidModelGraphCFfRf); [G] pitch lookup inline
struct UnkStruct_0028E2E0_pt { float field_0; float field_4; };
class CB3SoundSkidModelGraph {
public:
    void CalcVolumeOutput(float p0, float & p1) const;
    UnkStruct_0028E2E0_pt field_0[2];
};
struct UnkStruct__gaSkidGraphs_m {
    CB3SoundSkidModelGraph field_0;
    CB3SoundSkidModelGraph field_10[1];  // [G] count
};
struct UnkStruct__gaSkidGraphs {
    unsigned long field_0;
    UnkStruct__gaSkidGraphs_m field_8[2];
};
struct UnkStruct_0028E2E0_sel { signed char field_0; unsigned char pad_1[3]; };

class CGtSoundUtils {
public:
    static float Clamp(float v, float lo, float hi)
    {
        return (v < lo) ? lo : ((v > hi) ? hi : v);
    }
};

static inline float func_0028E2E0_inl1(const UnkStruct__gaSkidGraphs *e, int m, int k, float p0)
{
    float t = CGtSoundUtils::Clamp(p0, ((const UnkStruct__gaSkidGraphs *)((char *)e + k * 16))->field_8[m].field_10[0].field_0[0].field_0, ((const UnkStruct__gaSkidGraphs *)((char *)e + k * 16))->field_8[m].field_10[0].field_0[1].field_0);
    unsigned int i;
    for (i = 0; i < 1; i++) {
        if (t >= ((const UnkStruct__gaSkidGraphs *)((char *)e + k * 16))->field_8[m].field_10[0].field_0[i].field_0 && t < ((const UnkStruct__gaSkidGraphs *)((char *)e + k * 16))->field_8[m].field_10[0].field_0[i + 1].field_0) {
            break;
        }
    }
    float d = e->field_8[m].field_10[k].field_0[i + 1].field_0 - e->field_8[m].field_10[k].field_0[i].field_0;
    if (0.0f == d) {
        return e->field_8[m].field_10[k].field_0[i].field_4;
    }
    return 0.0f + e->field_8[m].field_10[k].field_0[i].field_4 + (t - e->field_8[m].field_10[k].field_0[i].field_0) / d * (e->field_8[m].field_10[k].field_0[i + 1].field_4 - e->field_8[m].field_10[k].field_0[i].field_4);
}

class CB3SoundSkidModel {
public:
    void Update(const CB3Wheel**, float, CGtV3d, CGtV3d, CGtSoundVirtualVoice**, CGtV3d, bool, float*, float*, bool, bool, bool);

    CGtSoundWave * field_0[3];
    unsigned char pad_C[0x28];
    UnkStruct_0028E2E0_sel field_34[4];
    unsigned char pad_44[0xC];
    CGtRandom field_50;
};

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" float CalcFrequency__12CGtSoundWaveCFv(const CGtSoundWave *);
extern "C" unsigned int GetLength__12CGtSoundWaveCFv(const CGtSoundWave *);
extern "C" int IsPlaying__20CGtSoundVirtualVoiceFv(CGtSoundVirtualVoice *);
extern "C" void Stop__20CGtSoundVirtualVoiceFv(CGtSoundVirtualVoice *);
extern "C" void Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(CGtSoundVirtualVoice *, const void *);
extern "C" void Start__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(CGtSoundVirtualVoice *, const void *);

extern float _garWheelModeMultiplers[];
extern UnkStruct__gaSkidGraphs _gaSkidGraphs[];
extern float _grSlipSpeedMultipler;
extern float _grSlipSpinLagMin;
extern float _grSlipSpinLagMax;
extern float _grMaxSlip;
extern float _grMaxSpin;
extern float _grLeftPitchOffset;
extern float _grRightPitchOffset;
extern float _grCrashVolumeMultipler;

// 0x0028E2E0
void CB3SoundSkidModel::Update(const CB3Wheel** wheels, float speed, CGtV3d p2, CGtV3d p3, CGtSoundVirtualVoice** voices, CGtV3d pos, bool left, float* lags, float* p8, bool crash, bool p10, bool negate)
{
    float freq;
    CGtV3d pc = pos;
    float total = 0.0f;
    if (negate) {
        speed = -speed;
    }
    unsigned int i = 0;
    do {
        const CB3Wheel *const *wp = &wheels[i];
        float slip;
        if ((*wp)->field_B3 != 0) {
            const CB3Wheel *w = *wp;
            slip = (0.0f + speed - (w->field_5C / 6.2831855f) * (6.2831855f * w->field_50)) * _garWheelModeMultiplers[w->field_78];
            if (slip > 0.0f) {
                slip *= speed * _grSlipSpeedMultipler;
            }
        } else {
            slip = 0.0f;
        }
        float *lag = &lags[i];
        float l = *lag;
        float nl = l + CGtSoundUtils::Clamp(slip - l, _grSlipSpinLagMin, _grSlipSpinLagMax);
        float v;
        if (nl > 0.0f) {
            v = CGtSoundUtils::Clamp(nl, 0.0f, _grMaxSlip);
        } else {
            v = -CGtSoundUtils::Clamp(-nl, 0.0f, _grMaxSpin);
        }
        *lag = v;
        float m;
        switch ((*wp)->field_B0) {
        case 0x14: case 8: case 9: case 6: case 1: case 2: case 3: case 0xC: case 0xD: case 0x11:
            m = 1.0f;
            break;
        case 7: case 0xA: case 0xB: case 0x13:
            m = 0.5f;
            break;
        default:
            m = 0.0f;
            break;
        }
        float vm = v;
        vm *= m;
        total += vm;
        i++;
    } while (i < 2);
    float s;
    if (total > 0.0f) {
        s = CGtSoundUtils::Clamp(total, 0.0f, _grMaxSlip);
    } else {
        s = -CGtSoundUtils::Clamp(-total, 0.0f, _grMaxSpin);
    }
    UnkStruct_0028E2E0_params params;
    unsigned int j = 0;
    do {
        Construct__19CGtSoundVoiceParamsFv(&params);
        if (p10) {
            params.field_44 = 5;
        } else {
            params.field_44 = 7;
        }
        float vol = 1.0f;
        freq = CalcFrequency__12CGtSoundWaveCFv(field_0[j]);
        int k = (j + left) ? 0 : 3;
        if (s >= 0.0f) {
            UnkStruct__gaSkidGraphs *e = &_gaSkidGraphs[j];
            e->field_8[0].field_0.CalcVolumeOutput(s, vol);
            freq += func_0028E2E0_inl1(e, 0, field_34[k].field_0, s);
        } else {
            s = -s;
            UnkStruct__gaSkidGraphs *e = &_gaSkidGraphs[j];
            e->field_8[1].field_0.CalcVolumeOutput(s, vol);
            freq += func_0028E2E0_inl1(e, 1, field_34[k].field_0, s);
        }
        if (left) {
            freq += _grLeftPitchOffset;
        } else {
            freq += _grRightPitchOffset;
        }
        if (crash) {
            vol *= _grCrashVolumeMultipler;
        }
        params.field_24 = freq;
        CGtV3d t = pc;
        params.field_1C = vol;
        for (int c = 0; c < 3; c++) {
            ((float *)&params.field_0)[c] = ((float *)&t)[c];
        }
        if ((*(unsigned int *)&vol & 0x7F800000) < 0x37800001) {
            if (IsPlaying__20CGtSoundVirtualVoiceFv(voices[j]) != 0) {
                Stop__20CGtSoundVirtualVoiceFv(voices[j]);
            }
        } else if (IsPlaying__20CGtSoundVirtualVoiceFv(voices[j]) != 0) {
            Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(voices[j], &params);
        } else {
            params.field_45 = 1;
            params.field_18 = field_0[j];
            params.field_40 = field_50.Random() % GetLength__12CGtSoundWaveCFv(params.field_18);
            Start__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(voices[j], &params);
        }
        j++;
    } while (j < 3);
}





