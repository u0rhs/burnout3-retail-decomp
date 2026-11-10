// NONMATCHING: UpdateRoadNoise__17CB3SoundPlayerCarFPC10CB3RaceCar -- retail 350 / ours 349 instructions, 207 in changed runs
// v312 first pass: logic complete (349/350). Left: trigger arm (voice==0) laid out at the end and the sprintf block inline (retail: trigger inline, sprintf out of line) -- every if/else/continue/goto order gives the same layout; pos[] vector ops scheduled/CSE'd differently (retail 4 separate vmulx, ours vmove); frame 0x1E0 vs 0x210 (retail has ~0xD0 of dead slots between 0xD0 and 0x1A0); clamp is the ternary chain (exact).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3SoundPlayerCar::UpdateRoadNoise(const CB3RaceCar*) -- hand-written (v312; the lifter refused it).
// [C] name: retail symbol table. Field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/classes/UnkStruct_D_0055EFEC.h"
using namespace GtMathPs2;

class CB3RaceCar;
class CGtSoundVoiceParams;

struct UnkStruct_0028C0F0_n { unsigned char pad_0[4]; char *field_4; };
class CGtSoundWave {
public:
    float CalcFrequency() const;
    unsigned char pad_0[8];
    UnkStruct_0028C0F0_n *field_8;
};
class CGtSoundBank {
public:
    CGtSoundWave *FindWave(const unsigned long &, bool) const;
};
class CGtSoundVirtualVoice {
public:
    void ForgetMe(float);
    void Update(const CGtSoundVoiceParams *);
};
class CGtSoundVoiceManager {
public:
    CGtSoundVirtualVoice *TriggerVoice(const CGtSoundVoiceParams *);
    unsigned char pad_0[0x10];
};
class CB3SoundCrashManager {
public:
    void PlayerCarHasBeenOnRamp();
    void SetPlayerCarSpeed(float);
    unsigned char pad_0[0x10];
};

// [G] the sound manager's road-noise tables: [front/rear][6 curves][10 surfaces], then the surface map
struct UnkStruct_D_01E75640 {
    unsigned char pad_0[0x1F10];
    float field_1F10[2][6][10];
    unsigned char pad_20F0[8];
    signed char field_20F8[16];
};

// [G] wheel: position first, surface bytes at +0xB0/+0xB3
struct UnkStruct_0028C0F0_w {
    CGtV3d field_0;
    unsigned char pad_10[0xA0];
    unsigned char field_B0;
    unsigned char pad_B1[2];
    unsigned char field_B3;
    unsigned char pad_B4[0xC];
};

struct UnkStruct_0028C0F0_p {
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
    unsigned char pad_C0[0x760];
    UnkStruct_0028C0F0_w field_820[2];
    unsigned char pad_9A0[0xBA0];
    unsigned char field_1540;
};

struct UnkStruct_0028C0F0_c {
    CGtV3d field_0;
    unsigned char pad_10[0x10];
    CGtV3d field_20;
    unsigned char pad_30[0x197C];
    signed char field_19AC;
};

struct UnkStruct_0028C0F0_vp {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0xC];
    CGtSoundWave *field_18;
    float field_1C;
    float field_20;
    float field_24;
    unsigned char pad_28[0x1C];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[2];
};

struct UnkStruct_0028C0F0_v3 { float field_0; float field_4; float field_8; float field_C; };

struct UnkStruct_0028C0F0_s;

class CB3SoundPlayerCar {
public:
    void UpdateRoadNoise(const CB3RaceCar *);
    unsigned char pad_0[8];
    UnkStruct_0028C0F0_s *field_8;  // [G] sub-object at +8 (func_0028DFB0's self); never read here
    unsigned char pad_C[0x150];
    CGtSoundVirtualVoice *field_15C[4];
    int field_16C[4];
    float field_17C[2];
};

extern UnkStruct_D_0055EFEC D_0055EFEC;
extern CB3SoundCrashManager D_01E78510;
extern CGtSoundVoiceManager D_01E7569C;
extern UnkStruct_D_01E75640 D_01E75640;
struct UnkStruct_D_01E7C7F8 { CGtSoundBank *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E7C7F8 D_01E7C7F8;
extern const unsigned long D_004BF850[];
extern const unsigned long D_004BF858;
extern char D_004BF988[];
extern char D_01E7C8C0[4][64];
extern float D_01E7C9C0[4];
extern float D_01E7C9D0[4];
extern float D_004E1BA4;
extern float D_004E1BA8;
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" int func_0028E0A0(void *);
extern "C" float func_0028DFB0(void *, int);
extern "C" int sprintf(char *, const char *, ...);

// [L] GtMath::Interpolate(float,float,float) (map 0x14CCF0; v283's adda/madd shape)
static inline float func_0028C0F0_inl1(float a, float b, float t) { return 0.0f + a + t * (b - a); }

// 0x0028C0F0
void CB3SoundPlayerCar::UpdateRoadNoise(const CB3RaceCar *rc)
{
    const UnkStruct_0028C0F0_c *car = (const UnkStruct_0028C0F0_c *)rc;
    float volScale = 1.0f;
    float pitchScale = volScale;
    UnkStruct_0028C0F0_p *p = (UnkStruct_0028C0F0_p *)D_0055EFEC.field_0[car->field_19AC].field_0;
    if (p->field_1540 != 0) {
        D_01E78510.PlayerCarHasBeenOnRamp();
    }
    UnkStruct_0028C0F0_w *wheel[2];
    wheel[0] = &p->field_820[0];
    wheel[1] = &p->field_820[1];
    CGtV3d pos[2];
    pos[0] = p->field_820[0].field_0 - car->field_0 * D_004E1BA8 - car->field_20 * D_004E1BA4;
    pos[1] = p->field_820[1].field_0 + car->field_0 * D_004E1BA8 - car->field_20 * D_004E1BA4;
    UnkStruct_0028C0F0_vp params;
    Construct__19CGtSoundVoiceParamsFv(&params);
    float speed = p->field_B0.W();
    D_01E78510.SetPlayerCarSpeed(speed);
    for (int i = 0; i < 4; i++) {
        int k = i % 2;
        UnkStruct_0028C0F0_w *w = wheel[k];
        int surf = w->field_B0;
        if (w->field_B3 == 0) {
            surf = 0;
        }
        if (func_0028E0A0(&w->field_B0) != 0) {
            field_17C[k] = 0.0f;
        } else {
            float cur = field_17C[k];
            float d = func_0028DFB0(&field_8, k) - cur;
            field_17C[k] = cur + (d < -0.4f ? -0.4f : (d > 0.15f ? 0.15f : d));
            float a = GtMath::Min(GtMath::Abs(func_0028DFB0(&field_8, k)), 8.0f) / 8.0f;
            volScale = func_0028C0F0_inl1(1.0f, 5.0f, a);
            pitchScale = func_0028C0F0_inl1(1.0f, 0.85f, a);
        }
        int s = D_01E75640.field_20F8[surf];
        float vol, pitch;
        if (i < 2) {
            float (*t)[10] = D_01E75640.field_1F10[0];
            float f = GtMath::Min(GtMath::Max((speed - t[0][s]) / (t[1][s] - t[0][s]), 0.0f), 1.0f);
            vol = func_0028C0F0_inl1(t[2][s], t[3][s], f);
            pitch = func_0028C0F0_inl1(t[4][s], t[5][s], f);
        } else {
            float (*t)[10] = D_01E75640.field_1F10[1];
            float f = GtMath::Min(GtMath::Max((speed - t[0][s]) / (t[1][s] - t[0][s]), 0.0f), 1.0f);
            vol = func_0028C0F0_inl1(t[2][s], t[3][s], f);
            pitch = func_0028C0F0_inl1(t[4][s], t[5][s], f);
        }
        if (i == 0 || i == 3) {
            pitch += 0.24f;
        }
        if (s != field_16C[i] || surf == 0) {
            if (field_15C[i] != 0) {
                field_15C[i]->ForgetMe(0.5f);
                field_15C[i] = 0;
            }
            if (surf == 0) {
                continue;
            }
        }
        field_16C[i] = s;
        float &pv = params.field_1C;
        UnkStruct_0028C0F0_v3 v;
        *(u_long128 *)&v = pos[k].mData;
        params.field_0 = v.field_0;
        params.field_4 = v.field_4;
        params.field_8 = v.field_8;
        pv = vol * volScale;
        pitch *= pitchScale;
        if (field_15C[i] == 0) {
            CGtSoundWave **pw = &params.field_18;
            if (i < 2) {
                *pw = D_01E7C7F8.field_0->FindWave(D_004BF858, true);
            } else {
                *pw = D_01E7C7F8.field_0->FindWave(D_004BF850[surf], true);
            }
            if (*pw != 0) {
                params.field_45 = 1;
                params.field_24 = pitch * (*pw)->CalcFrequency();
                params.field_44 = 0;
                field_15C[i] = D_01E7569C.TriggerVoice((const CGtSoundVoiceParams *)&params);
            }
        } else {
            CGtSoundWave **pw = &params.field_18;
            if (i < 2) {
                *pw = D_01E7C7F8.field_0->FindWave(D_004BF858, true);
            } else {
                *pw = D_01E7C7F8.field_0->FindWave(D_004BF850[surf], true);
            }
            if (*pw != 0) {
                params.field_45 = 1;
                params.field_24 = pitch * (*pw)->CalcFrequency();
                sprintf(D_01E7C8C0[i], D_004BF988, (*pw)->field_8->field_4);
            }
            field_15C[i]->Update((const CGtSoundVoiceParams *)&params);
            D_01E7C9D0[i] = pv;
            D_01E7C9C0[i] = params.field_24;
        }
    }
}
