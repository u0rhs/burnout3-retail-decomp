// NONMATCHING: PayLoadImpact__20CB3SoundCrashManagerFbP18CB3BodyPartPhysicsf -- retail 455 / ours 458 instructions, 79 in changed runs
// draftAG: logic complete; retail 455 / ours 458, 79 in changed runs; calls identical; VU ops identical (header NormaliseFast / CosAngleBetweenNormalisedVectors); left: stack slots 16 bytes low (retail has one more dead slot under the position copy; a 0x48-byte voice-params struct shrinks the frame instead), the FindWave null test as bnez+b (as the PropImpact draft), the listener-loop bool materialisation, D_004E1358 load order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; voice-params layout / random step / pitch jitter from the archived PropImpact draft; all 8 hash cases, branches, calls and stores accounted for; call sequence identical (calls.sh)

// CB3SoundCrashManager::PayLoadImpact(bool, CB3BodyPartPhysics*, float) -- draftAG (C-first draft; no Revenge counterpart).
// [C] name: retail symbol table. Written from the retail asm; voice-params layout, the random step and the frequency jitter from
// the archived sibling PropImpact__20CB3SoundCrashManagerFb11EB3PropTypeQ29GtMathPs26CGtV3df.
// [L] reading: a payload (body part shed by a vehicle) hits something with strength f. Below 3 or while the cooldown byte is
// set nothing plays; otherwise the body part's type id (64-bit hash) picks one of eight sound sets: a wave id from that set's
// table (indexed by field_8C1) and a volume interpolated from the set's strength range. The voice plays at the part's position
// with a random pitch; in [L] multiplayer it only plays when some listener faces it (cos > D_004E1AD8 ~ cos 80 deg), louder
// range 150 and volume * 0.85. [C] The bool argument is never read (a1 is overwritten first).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_0027F8D0_p {               // CGtSoundVoiceParams (PropImpact draft)
    float field_0; float field_4; float field_8; unsigned char pad_C[0xC];
    int field_18;                            // wave
    float field_1C;                          // volume
    float field_20;
    float field_24;                          // frequency
    unsigned char pad_28[0x10]; float field_38;   // range [G]
    unsigned char pad_3C[8];
    unsigned char field_44; unsigned char pad_45[0xB];
};
struct UnkStruct_0027F8D0_set { float field_0; float field_4; float field_8; float field_C; };   // [C] strength hi/lo, volume hi/lo
struct UnkStruct_0027F8D0_l { CGtV3d field_0; CGtV3d field_10; unsigned char pad_20[0x20]; };   // [G] a listener: facing, position
struct UnkStruct_0027F8D0_type { unsigned long field_0; unsigned char pad_8[0x48]; };          // [C] 0x50 per body-part type: id hash
struct UnkStruct_0027F8D0_1024 { unsigned char pad_0[8]; UnkStruct_0027F8D0_type *field_8; };
struct UnkStruct_0027F8D0_CC4 { unsigned char pad_0[0x1024]; UnkStruct_0027F8D0_1024 *field_1024; };
struct UnkStruct_0027F8D0_2B0 { unsigned char pad_0[0xCC4]; UnkStruct_0027F8D0_CC4 *field_CC4; };
class CB3BodyPartPhysics {
public:
    unsigned char pad_0[0x204];
    CGtMatrix3x4 *field_204;
    unsigned char pad_208[0xA8];
    UnkStruct_0027F8D0_2B0 *field_2B0;       // [G] the owning vehicle's physics
    unsigned char pad_2B4[4];
    short field_2B8;                         // [C] body-part type index
};
struct UnkStruct_D_01E75648 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E7569C { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E75648 D_01E75648;
extern UnkStruct_D_01E7569C D_01E7569C;
extern unsigned char D_004EE040[];
extern int D_0064D3A0;                       // [C] listener count
extern float D_004E1358;                     // 0.1 (pitch jitter)
// [C] eight wave-id tables (17 64-bit entries each, indexed by field_8C1)
extern const unsigned long D_004BE8C0[], D_004BE948[], D_004BE9D0[], D_004BEA58[], D_004BEAE0[], D_004BEB68[], D_004BEBF0[], D_004BEC78[];
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" int FindWave__19CGtSoundBankManagerCFRCUlb(void *, const unsigned long *, bool);
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);
extern "C" void *TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(void *, const void *);
extern "C" int func_00131E40(void *);       // [G] a game-mode test on gGame (as its other callers)
static inline void func_0027F8D0_inl1(UnkStruct_0027F8D0_p *p, CGtV3d v) { p->field_0 = ((float *)&v)[0]; p->field_4 = ((float *)&v)[1]; p->field_8 = ((float *)&v)[2]; }

class CB3SoundCrashManager {
public:
    void PayLoadImpact(bool, CB3BodyPartPhysics *, float);
    unsigned char pad_0[0x270];
    UnkStruct_0027F8D0_l field_270[10];      // [G] count
    unsigned char pad_4F0[0x30];
    int field_520;                           // CGtRandom-style state (PropImpact draft)
    int field_524;
    unsigned char pad_528[0x208];
    UnkStruct_0027F8D0_set field_730[8];     // [C] per sound set
    unsigned char pad_7B0[0x111];
    signed char field_8C1;                   // [C] wave-table index
    unsigned char pad_8C2[8];
    signed char field_8CA;                   // [C] cooldown (set to 4 per impact)
};

// [G] inlined per sound set: the wave id and the volume over the set's strength range
static inline void func_0027F8D0_inl2(const UnkStruct_0027F8D0_set *s, float f, float *vol)
{
    float t = GtMath::Min(GtMath::Max((f - s->field_4) / (s->field_0 - s->field_4), 0.0f), 1.0f);
    *vol = 0.0f + s->field_C + t * (s->field_8 - s->field_C);
}

// 0x0027F8D0
void CB3SoundCrashManager::PayLoadImpact(bool, CB3BodyPartPhysics *bp, float f)
{
    unsigned long id;
    unsigned long type = bp->field_2B0->field_CC4->field_1024->field_8[bp->field_2B8].field_0;
    if (f < 3.0f)
        return;
    if (field_8CA != 0)
        return;
    field_8CA = 4;
    UnkStruct_0027F8D0_p p;
    Construct__19CGtSoundVoiceParamsFv(&p);
    func_0027F8D0_inl1(&p, bp->field_204->mPos);
    switch (type) {
    case 0x5BBA30EB90C68000UL:
        id = D_004BE8C0[field_8C1];
        func_0027F8D0_inl2(&field_730[1], f, &p.field_1C);
        break;
    case 0x537E8FD3B1000000UL:
        id = D_004BE948[field_8C1];
        func_0027F8D0_inl2(&field_730[0], f, &p.field_1C);
        break;
    case 0x55784E69E8000000UL:
        id = D_004BE9D0[field_8C1];
        func_0027F8D0_inl2(&field_730[2], f, &p.field_1C);
        break;
    case 0x8FB24F74B8000000UL:
        {
            id = D_004BEA58[field_8C1];
            float lo = field_730[7].field_4;
            if (f <= lo)
                return;
            float t = GtMath::Min(GtMath::Max((f - lo) / (field_730[7].field_0 - lo), 0.0f), 1.0f);
            p.field_1C = 0.0f + field_730[7].field_C + t * (field_730[7].field_8 - field_730[7].field_C);
        }
        break;
    case 0x76716724D92C4000UL:
        id = D_004BEAE0[field_8C1];
        func_0027F8D0_inl2(&field_730[3], f, &p.field_1C);
        break;
    case 0x76716724D9535000UL:
        id = D_004BEB68[field_8C1];
        func_0027F8D0_inl2(&field_730[4], f, &p.field_1C);
        break;
    case 0x5970064FC9FA8000UL:
        id = D_004BEBF0[field_8C1];
        func_0027F8D0_inl2(&field_730[5], f, &p.field_1C);
        break;
    case 0x5B568999817A5C00UL:
        id = D_004BEC78[field_8C1];
        func_0027F8D0_inl2(&field_730[6], f, &p.field_1C);
        break;
    }
    p.field_20 = 1.0f;
    int *pw = &p.field_18;
    *pw = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &id, true);
    int w = *pw;
    if (w == 0)
        return;
    float *pf = &p.field_24;
    *pf = CalcFrequency__12CGtSoundWaveCFv((void *)(w));
    field_520 = (field_520 << 16) + (field_520 >> 16);
    field_520 += field_524;
    field_524 += field_520;
    *pf *= (0.0f + 1.0f + D_004E1358 * (2.0f * (2.3283064e-10f * (float)(unsigned int)field_520))) - D_004E1358;
    p.field_44 = 3;
    if (func_00131E40(D_004EE040)) {
        // only when a listener faces the impact
        bool lbSeen = false;
        for (int i = 0; i < D_0064D3A0; i++) {
            if (!lbSeen) {
                CGtV3d d = bp->field_204->mPos - field_270[i].field_10;
                d.NormaliseFast();
                lbSeen = !((float)CosAngleBetweenNormalisedVectors(field_270[i].field_0, d) <= 0.17364818f);
            }
        }
        if (!lbSeen)
            return;
        p.field_38 = 150.0f;
        p.field_1C *= 0.85f;
    } else {
        p.field_38 = 50.0f;
    }
    TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(&D_01E7569C, &p);
}

