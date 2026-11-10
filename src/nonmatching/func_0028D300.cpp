// NONMATCHING: func_0028D300 -- retail 215 / ours 213 instructions, 49 in changed runs
// psweep: scoped #pragma opt_arithtransformation off [G] improves 59 -> 57
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_arithtransformation off
// NONMATCHING: func_0028D300 -- retail 215 / ours 213 instructions, 53 in changed runs
// a142: logic complete (CB3SoundRaceCar boost/ducker voice trigger; sibling of StartBoost). 213/215 instrs, ~53 differ: float scratch numbering in the 0.25/0.5/0.75 piecewise block (retail constants in f1/f2, ours f0/f1; operand order of mul), the f21 TriggerRealVoice block laid out inline vs out-of-line, c.eq.s operand order for 'x != 0.0f', and 1-slot addiu s0 scheduling. Needed: 'D > f90' form (not D<=f90) for the first diamond; madd avoided via compound assigns
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

typedef unsigned int u_long128 __attribute__((mode(TI)));
class CGtSoundVoiceParams;
class CGtSoundVoiceManager {
public:
    int TriggerVoice(const CGtSoundVoiceParams*);
    int TriggerRealVoice(const CGtSoundVoiceParams*);
    unsigned char pad_0[0x10];
};
class CB3Burn { public: static float gmarBoostBarSizes[4]; };
struct UnkStruct_0028D300_a1 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
    unsigned char pad_40[0x1184];
    float field_11C4;
    unsigned char pad_11C8[0x74C];
    int field_1914;
};
struct UnkStruct_0028D300_P {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0xC];
    int field_18;
    float field_1C;
    unsigned char pad_20[0x24];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0xA];
};
struct UnkStruct_0028D300_S {
    unsigned char pad_0[0x90];
    float field_90;
    float field_94;
    unsigned char pad_98[0xC];
    int field_A4;
    unsigned char pad_A8[0x14];
    unsigned char field_BC;
};
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E77540 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E75648 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00522680 D_00522680;
extern UnkStruct_D_01E77540 D_01E77540;
extern UnkStruct_D_01E75648 D_01E75648;
extern CGtSoundVoiceManager D_01E7569C;
extern float D_004E06A8;
extern float D_004E06B4;
extern float D_004E06C0;
extern float D_004E0768;
extern float D_004E076C;
extern float D_004E0770;
extern float D_004E0774;
extern float D_004E0778;
extern float _grAIBoostInVol;
extern char D_004BFB88[];
extern char D_004BFB98[];
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" void TriggerSpotDucker__23CB3SoundGameModeManagerFf(void *, float);
extern "C" unsigned long GtIDCompress__FPCc(const char *);
extern "C" int FindWave__19CGtSoundBankManagerCFRCUlb(void *, const void *, bool);
extern "C" void func_0028D300(UnkStruct_0028D300_S *self, const UnkStruct_0028D300_a1 *car)
{
    UnkStruct_0028D300_P params;
    u_long128 v;
    float t, m;
    float f22, f21, f20;
    unsigned long nmA;
    unsigned long nmB;
    Construct__19CGtSoundVoiceParamsFv(&params);
    v = car->field_30;
    params.field_0 = ((float *)&v)[0];
    params.field_4 = ((float *)&v)[1];
    params.field_8 = ((float *)&v)[2];
    if (D_00522680.field_0 > self->field_90) { f22 = car->field_11C4 / CB3Burn::gmarBoostBarSizes[3]; } else { f22 = D_004E06A8; }
    int g = car->field_1914;
    params.field_45 = 0;
    int *pid = &params.field_18;
    *pid = self->field_A4;
    if (g != 0) {
        if (g == 2 && self->field_BC != 0) {
            params.field_44 = 1;
            params.field_1C = _grAIBoostInVol;
            D_01E7569C.TriggerVoice((const CGtSoundVoiceParams *)&params);
            self->field_BC = 0;
        }
        return;
    }
    if (f22 > self->field_94) f22 = self->field_94;
    TriggerSpotDucker__23CB3SoundGameModeManagerFf(&D_01E77540, D_004E06C0);
    params.field_44 = 1;
    if (f22 < 0.25f) {
        f21 = 0.0f;
        f20 = 0.0f;
        m = D_004E0768 * f22;
        m *= D_004E076C;
        f22 = m;
        f22 += D_004E0770;
    } else {
        f21 = 0.5f;
        if (f22 < 0.5f) {
            t = 4.0f * (f22 - 0.25f);
            f21 = t * f21;
            f20 = 0.0f;
            m = t * D_004E0774;
            f22 = m;
            f22 += D_004E0778;
        } else if (f22 < 0.75f) {
            f20 = 0.0f;
            m = 4.0f * (f22 - f21);
            m *= D_004E06B4;
            f22 = D_004E06B4 - m;
        } else {
            t = 4.0f * (f22 - 0.75f);
            m = t * -0.25f;
            f21 = m + f21;
            f22 = 0.0f;
            f20 = t * D_004E06A8;
        }
    }
    if (0.0f != f22) {
        nmA = GtIDCompress__FPCc(D_004BFB88);
        params.field_18 = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &nmA, false);
        if (params.field_18 != 0) {
            params.field_1C = f22;
            D_01E7569C.TriggerRealVoice((const CGtSoundVoiceParams *)&params);
            D_01E7569C.TriggerRealVoice((const CGtSoundVoiceParams *)&params);
        }
    }
    if (0.0f != f21) {
        params.field_18 = self->field_A4;
        if (params.field_18 != 0) {
            params.field_1C = f21;
            D_01E7569C.TriggerRealVoice((const CGtSoundVoiceParams *)&params);
            D_01E7569C.TriggerRealVoice((const CGtSoundVoiceParams *)&params);
        }
    }
    if (0.0f != f20) {
        nmB = GtIDCompress__FPCc(D_004BFB98);
        params.field_18 = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &nmB, false);
        if (params.field_18 != 0) {
            params.field_1C = f20;
            D_01E7569C.TriggerRealVoice((const CGtSoundVoiceParams *)&params);
            D_01E7569C.TriggerRealVoice((const CGtSoundVoiceParams *)&params);
        }
    }
    self->field_94 = 0.0f;
}


#pragma pop
