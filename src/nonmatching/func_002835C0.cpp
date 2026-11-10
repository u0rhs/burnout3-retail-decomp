// NONMATCHING: UpdateScrape__14CB3SoundScrapeFi -- retail 144 / ours 145 instructions, 32 in changed runs
// near29: literal 1.0f in t1's Min, 'float one = 1.0f;' declared after t1 -> retail's lui/mtc1 f20 after the first max (39 -> 32). Left: ForgetMe arm ends b+sw in delay slot (retail sw; b; ld ra -- return/goto/nesting forms all same), .xC8 store order, tail schedule (retail m2*f38 product before *p24*m1, 1-f28 sub before max)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: UpdateScrape__14CB3SoundScrapeFi -- retail 144 / ours 144 instructions, 39 in changed runs
// a226: f38 computed after m1 (before m2) gives retail's f21/f22/f23 regs; 39 left: exit block b/ld ra order, 1.0f hoist (retail lui/mtc1 after first max), tail schedule
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// NONMATCHING: UpdateScrape__14CB3SoundScrapeFi -- retail 144 / ours 144 instructions, 52 in changed runs
// a84: logic right (params struct on stack, clamp01 via GtMath::Min/Max, self->field_2C reloaded after call, p24 set in each arm). Left: kill-block exit has sw in delay slot vs retail 'sw; b; ld ra' (ld ra in delay), 1.0f hoist (retail lui/mtc1 f20 right before first min, ours earlier), f38 cvt/div scheduled before m1/m2 madds (retail after: f21 m1,f22 m2,f23 f38), a*S570+b*S568 order, vec copy lq reg.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// UpdateScrape__14CB3SoundScrapeFi -- CB3SoundScrape::UpdateScrape(int) [L] DNAT (research/proto/new_names.csv, high)
#include "b3/GtMath.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));
class CGtSoundVoiceParams;
class CGtSoundWave {
public:
    float CalcFrequency() const;
};
class CGtSoundVirtualVoice {
public:
    void ForgetMe(float);
    void Update(const CGtSoundVoiceParams *);
};
struct UnkStruct_002835C0 {
    u_long128 field_0;
    CGtSoundVirtualVoice * field_10[2];
    unsigned char pad_18[0x8];
    CGtSoundWave * field_20;
    CGtSoundWave * field_24;
    float field_28;
    float field_2C;
    float field_30;
    unsigned char pad_34[0x4];
    int field_38;
};
struct UnkStruct_002835C0_p {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0x10];
    float field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0x28];
    float field_50;
    float field_54;
    float field_58;
    unsigned char pad_5C[0x4];
};
struct UnkStruct_002835C0_v { float field_0; float field_4; float field_8; float field_C; };
struct UnkStruct_D_01E78510 {
    unsigned char pad_0[0x528];
    float field_528[2];
    float field_530[2];
    float field_538[2];
    float field_540[2];
    float field_548[2];
    float field_550[2];
    float field_558[2];
    float field_560[2];
    float field_568[2];
    float field_570[2];
};
struct UnkStruct_D_004E1358 { float field_0; };
extern UnkStruct_D_01E78510 D_01E78510;
extern float D_01E78A40[];
extern float D_01E78A50[];
extern UnkStruct_D_004E1358 D_004E1358;
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);

// [L] DNAT: CB3SoundScrape::UpdateScrape(int) (research/proto/new_names.csv, high)
// 0x002835C0
extern "C" void UpdateScrape__14CB3SoundScrapeFi(UnkStruct_002835C0 * self, int idx)
{
    UnkStruct_D_01E78510 * const S = &D_01E78510;
    if (self->field_2C < D_01E78A40[idx] || self->field_2C < D_01E78A50[idx] || self->field_38 <= 0) {
        if (self->field_10[idx] != 0) {
            self->field_10[idx]->ForgetMe(D_004E1358.field_0);
            self->field_10[idx] = 0;
            self->field_28 = 0;
        }
    } else {
        UnkStruct_002835C0_p params;
        UnkStruct_002835C0_v v;
        Construct__19CGtSoundVoiceParamsFv(&params);
        *(u_long128 *)&v = self->field_0;
        params.field_0 = v.field_0;
        params.field_50 = v.field_0;
        params.field_54 = v.field_4;
        params.field_4 = v.field_4;
        params.field_8 = v.field_8;
        params.field_58 = v.field_8;
        float t1 = GtMath::Min(GtMath::Max((self->field_2C - S->field_530[idx]) / (S->field_528[idx] - S->field_530[idx]), 0.0f), 1.0f);
        float one = 1.0f;
        float t2 = GtMath::Min(GtMath::Max((self->field_2C - S->field_540[idx]) / (S->field_538[idx] - S->field_540[idx]), 0.0f), one);
        float m1 = S->field_550[idx] + t1 * (S->field_548[idx] - S->field_550[idx]);
        float f38 = (float)self->field_38 / 25.0f;
        float m2 = S->field_560[idx] + t2 * (S->field_558[idx] - S->field_560[idx]);
        float * p24;
        if (idx == 0) {
            p24 = &params.field_24; *p24 = self->field_20->CalcFrequency();
        } else {
            p24 = &params.field_24; *p24 = self->field_24->CalcFrequency();
        }
        *p24 = *p24 * m1;
        float * p1C = &params.field_1C;
        *p1C = self->field_30 * (m2 * f38);
        float a = GtMath::Min(GtMath::Max(self->field_28, 0.0f), one);
        float b = GtMath::Min(GtMath::Max(1.0f - self->field_28, 0.0f), one);
        *p1C = *p1C * (a * S->field_570[idx] + b * S->field_568[idx]);
        self->field_10[idx]->Update((const CGtSoundVoiceParams *)&params);
    }
}

