// NONMATCHING: func_0027D380 -- retail 658 / ours 659 instructions, 226 in changed runs
// draftAK C-first: [L] a CB3SoundCrashManager crash-impact sound (unnamed; called from B3SoundCrashManager_0027F2A0.cpp): strength gate + cooldown 20 (func_0027BCE0 with the position when field_8DB && !field_8E0), volume/pitch over the strength range, one voice of wave D_004BEDA8 (multiplayer: listener-facing test, range 150, volume*0.85; else range 50), then on the first impact two more voices with random x/z offsets, volume and pitch (field_7B8 / field_7C0); 659/658, 7 hunks, frame equal, calls identical; left: the listener-loop body placement (retail in line, ours out of line; same as PayLoadImpact), two pointer-CSE placements
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid); every voice-param store, random step, call argument (func_0027BCE0 gets the entry copy's address; func_003872C0 is an empty function in retail, call kept) traced; retail's position offset divides RandomReal() by 2^32 again (offset ~ -2) -- kept

// func_0027D380 -- draftAK (C-first draft). 0x27D380, 0xA48. Unnamed in every table, so the asm label with C linkage.
// [C] callers: CB3SoundCrashManager (B3SoundCrashManager_0027F2A0.cpp) with (this, &position, strength) when a car is
// crashing; the position is a by-value CGtV3d (retail copies it in the prologue and passes that copy on to func_0027BCE0).
// Voice-params layout, the random step and the listener test from the archived PayLoadImpact__20CB3SoundCrashManager.
// What it does [L]: a crash impact sound: below field_700 or during the cooldown (field_8C7) nothing; else cooldown 20
// (func_0027BCE0 first when field_8DB is set and field_8E0 clear), volume / pitch interpolated over the strength range
// (field_700..704 -> 708..70C, 710..714), doubled volume when field_8DF, one voice of wave D_004BEDA8 at the position with
// a random pitch; multiplayer: only when a listener faces it (range 150, volume * 0.85), else range 50. On the first such
// impact (field_8C2 clear, then 0xFF) two more voices of the same wave follow, each moved by a random x/z offset, with
// random volume and pitch scaled by field_7B8 / field_7C0.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

struct UnkStruct_0027D380_p {               // CGtSoundVoiceParams (PayLoadImpact draft)
    float field_0; float field_4; float field_8; unsigned char pad_C[0xC];
    int field_18;                           // wave
    float field_1C;                         // volume
    float field_20;
    float field_24;                         // frequency
    unsigned char pad_28[0x10]; float field_38;   // range [G]
    unsigned char pad_3C[8];
    unsigned char field_44; unsigned char pad_45[0xB];
};
struct UnkStruct_0027D380_l { CGtV3d field_0; CGtV3d field_10; unsigned char pad_20[0x20]; };   // [G] a listener: facing, position
class CGtSoundBank;

class CB3SoundCrashManager {
public:
    unsigned char pad_0[0x270];
    UnkStruct_0027D380_l field_270[10];     // [G] count
    unsigned char pad_4F0[0x30];
    CGtRandom field_520;
    unsigned char pad_528[0x1D8];
    float field_700;                        // strength range lo / hi
    float field_704;
    float field_708;                        // volume at lo / hi
    float field_70C;
    float field_710;                        // pitch at lo / hi
    float field_714;
    unsigned char pad_718[0xA0];
    float field_7B8;                        // second / third voice pitch scale
    unsigned char pad_7BC[0x4];
    float field_7C0;
    unsigned char pad_7C4[0xBC];
    CGtSoundBank *field_880;
    unsigned char pad_884[0x3E];
    unsigned char field_8C2;                // [G] first-impact flag
    unsigned char pad_8C3[0x4];
    signed char field_8C7;                  // cooldown
    unsigned char pad_8C8[0x13];
    unsigned char field_8DB;
    unsigned char pad_8DC[0x3];
    unsigned char field_8DF;                // [G] loud
    unsigned char field_8E0;
};

struct UnkStruct_D_01E7569C { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E7569C D_01E7569C;
extern unsigned char D_004EE040[];
extern int D_0064D3A0;                      // [C] listener count
extern const unsigned long D_004BEDA8;      // [C] the wave id
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" int FindWave__12CGtSoundBankCFRCUlb(CGtSoundBank *, const unsigned long *, bool);
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);
extern "C" void *TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(void *, const void *);
extern "C" int func_00131E40(void *);       // [G] a game-mode test on gGame (as its other callers)
extern "C" void func_0027BCE0(CB3SoundCrashManager *, const CGtV3d &);   // [C] reads a1 as a CGtV3d (lq 0(a1)); retail passes the local copy's address
extern "C" void func_003872C0(void *, int, float, float, float, float, float, float);   // [C] an empty function (jr ra) in retail
extern "C" void SetBias__20CGtSoundVirtualVoiceFf(void *, float);
extern "C" void SetPriority__20CGtSoundVirtualVoiceFf(void *, float);

static inline void func_0027D380_inl1(UnkStruct_0027D380_p *p, CGtV3d v) { p->field_0 = ((float *)&v)[0]; p->field_4 = ((float *)&v)[1]; p->field_8 = ((float *)&v)[2]; }
// [L] the voice set-up after every trigger
static inline void func_0027D380_inl2(void *v)
{
    if (v != 0) {
        func_003872C0(v, 1, 0.63f, 0.63f, 0.31f, 0.5f, 0.42f, 0.42f);
        SetBias__20CGtSoundVirtualVoiceFf(v, 1.0f);
        SetPriority__20CGtSoundVirtualVoiceFf(v, 1.0f);
    }
}
// [C] retail's offset: RandomReal() divided by 2^32 again, so the offset is ~ -2 (kept as is)
static inline float func_0027D380_inl3(CGtRandom *r)
{
    float f = r->RandomReal() / 4294967296.0f;
    f = 4.0f * f;
    f -= 2.0f;
    return f;
}

// [G] the listener test as a bool inline, so retail's `lbSeen = lbSeen || ...` shape keeps the loop body in line
static inline bool func_0027D380_inl4(CB3SoundCrashManager *self, const CGtV3d &pos, int i)
{
    CGtV3d d = pos - self->field_270[i].field_10;
    d.NormaliseFast();
    return !((float)CosAngleBetweenNormalisedVectors(self->field_270[i].field_0, d) <= 0.17364818f);
}

extern "C" void func_0027D380(CB3SoundCrashManager *self, const CGtV3d &lpos, float strength)
{
    CGtV3d pos = lpos;                      // [C] copied at entry (lq/sq to sp+0xF0)
    if (strength < self->field_700)
        return;
    if (self->field_8C7 != 0)
        return;
    if (self->field_8DB != 0 && self->field_8E0 == 0)
        func_0027BCE0(self, pos);
    self->field_8C7 = 20;
    float t = GtMath::Min(GtMath::Max((strength - self->field_700) / (self->field_704 - self->field_700), 0.0f), 1.0f);
    float vol = 0.0f + self->field_708 + t * (self->field_70C - self->field_708);
    float pitch = 0.0f + self->field_710 + t * (self->field_714 - self->field_710);
    UnkStruct_0027D380_p p;
    Construct__19CGtSoundVoiceParamsFv(&p);
    p.field_20 = 1.0f;
    func_0027D380_inl1(&p, pos);
    if (self->field_8DF != 0)
        p.field_1C = 2.0f * vol;
    else
        p.field_1C = vol;
    p.field_18 = FindWave__12CGtSoundBankCFRCUlb(self->field_880, &D_004BEDA8, true);
    pitch = pitch * ((0.0f + 1.0f + 0.1f * (2.0f * self->field_520.RandomReal())) - 0.1f);
    p.field_24 = pitch * CalcFrequency__12CGtSoundWaveCFv((void *)(p.field_18));
    p.field_44 = 3;
    if (func_00131E40(D_004EE040)) {
        // only when a listener faces the impact
        bool lbSeen = false;
        for (int i = 0; i < D_0064D3A0; i++) {
            lbSeen = lbSeen || func_0027D380_inl4(self, pos, i);
        }
        if (!lbSeen)
            return;
        p.field_38 = 150.0f;
        p.field_1C = p.field_1C * 0.85f;
    } else {
        p.field_38 = 50.0f;
    }
    func_0027D380_inl2(TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(&D_01E7569C, &p));
    if (self->field_8C2 == 0) {
        float v0 = p.field_1C;
        self->field_8C2 = 0xFF;
        p.field_0 += func_0027D380_inl3(&self->field_520);
        p.field_8 += func_0027D380_inl3(&self->field_520);
        p.field_18 = FindWave__12CGtSoundBankCFRCUlb(self->field_880, &D_004BEDA8, true);
        p.field_1C = v0 * ((0.0f + 1.0f + 0.2f * (2.0f * self->field_520.RandomReal())) - 0.2f);
        unsigned int r = self->field_520.Random();
        float f = CalcFrequency__12CGtSoundWaveCFv((void *)(p.field_18));
        p.field_24 = self->field_7B8 * (f * ((0.0f + 1.0f + 0.2f * (2.0f * (2.3283064e-10f * (float)r))) - 0.2f));
        func_0027D380_inl2(TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(&D_01E7569C, &p));

        p.field_0 += func_0027D380_inl3(&self->field_520);
        p.field_8 += func_0027D380_inl3(&self->field_520);
        p.field_18 = FindWave__12CGtSoundBankCFRCUlb(self->field_880, &D_004BEDA8, true);
        p.field_1C = v0 * ((0.0f + 1.0f + 0.2f * (2.0f * self->field_520.RandomReal())) - 0.2f);
        r = self->field_520.Random();
        f = CalcFrequency__12CGtSoundWaveCFv((void *)(p.field_18));
        p.field_24 = self->field_7C0 * (f * ((0.0f + 1.0f + 0.2f * (2.0f * (2.3283064e-10f * (float)r))) - 0.2f));
        func_0027D380_inl2(TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(&D_01E7569C, &p));
    }
}
