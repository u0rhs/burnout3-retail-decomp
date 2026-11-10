// NONMATCHING: UpdateSkidVoices__22CB3SoundCrashedTrafficFv -- retail 166 / ours 156 instructions, 68 in changed runs
// L261: all arithmetic, lerps (adda/madd), max/min clamps and calls in retail order; missing: retail's two empty branches (bltz on the RNG result, c.lt.s field_24<0 + bc1f, both to the next instruction) and two dead 16-byte frame slots (0x60/0x70; frame 0xE0 vs 0xC0). Every dead-if form, empty inline calls, unsigned->float conversions and opt_* pragmas tried: MWCC deletes or keeps the whole body
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMath.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGtSoundVoiceParams;

class CGtSoundWave {
public:
    float CalcFrequency() const;
};

class CGtSoundVirtualVoice {
public:
    void Update(const CGtSoundVoiceParams *);
};

struct UnkStruct_0028FF30_3 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
};

struct UnkStruct_0028FF30_2 {
    unsigned char pad_0[0xB0];
    u_long128 field_B0;
    unsigned char pad_C0[0x144];
    UnkStruct_0028FF30_3 *field_204;
    unsigned char pad_208[0x2218];
    int field_2420;
};

struct UnkStruct_D_01E78E58 {
    int field_0;
    int field_4;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_F16 {
    float field_0;
    unsigned char pad_4[0xC];
};

class CB3SoundCrashedTraffic {
public:
    void UpdateSkidVoices();

    UnkStruct_0028FF30_2 *field_0;
    unsigned char pad_4[0x8];
    CGtSoundWave *field_C;
    CGtSoundWave *field_10;
    CGtSoundWave *field_14;
    CGtSoundVirtualVoice *field_18;
    int field_1C;
    float field_20;
    float field_24;
    int field_28;
    int field_2C;
    float field_30;
    float field_34;
};

extern UnkStruct_D_01E78E58 D_01E78E58;
extern UnkStruct_F16 D_01E78EC8;
extern UnkStruct_F16 D_01E78ECC;
extern UnkStruct_F16 D_01E78ED0;
extern UnkStruct_F16 D_01E78ED4;
extern UnkStruct_F16 D_01E78ED8;
extern UnkStruct_F16 D_01E78EDC;
extern UnkStruct_F16 D_01E78EE0;
extern UnkStruct_F16 D_01E78EE4;
extern UnkStruct_F16 D_01E78EE8;
extern UnkStruct_F16 D_01E78EEC;
extern UnkStruct_F16 D_01E78EF0;
extern UnkStruct_F16 D_01E78EF4;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()

struct UnkStruct_0028FF30_p {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    CGtSoundWave *field_18;
    float field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0x28];
};
struct UnkStruct_0028FF30_v {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};
// [G] inlined random-number step (no name in any table): D_01E78E58 = { x, y } (as StartSkidVoices)
static inline unsigned int func_0028FF30_inl1()
{
    UnkStruct_D_01E78E58 * const r = &D_01E78E58;
    int x = r->field_0;
    x = (x << 16) + (x >> 16);
    x += r->field_4;
    r->field_0 = x;
    r->field_4 += x;
    return x;
}

// 0x0028FF30
void CB3SoundCrashedTraffic::UpdateSkidVoices()
{
    UnkStruct_0028FF30_p params;
    UnkStruct_0028FF30_v v;
    Construct__19CGtSoundVoiceParamsFv(&params);
    *(u_long128 *)&v = field_0->field_204->field_30;
    int r = func_0028FF30_inl1();
    params.field_0 = v.field_0;
    params.field_4 = v.field_4;
    params.field_8 = v.field_8;
    if (r < 0) {
    }
    if (field_24 < 0.0f) {
    }
    if (field_2C != 0) {
        field_34 = field_34 - 0.05f;
    } else {
        field_34 = field_34 + 0.05f;
    }
    field_34 = GtMath::Min(GtMath::Max(field_34, 0.0f), 1.0f);
    field_30 = 1.0f + 0.25f * field_34;
    float vol;
    float pitch;
    if ((unsigned int)(field_0->field_2420 - 3) <= 2) {
        UnkStruct_0028FF30_v w;
        *(u_long128 *)&w = field_0->field_B0;
        float t = GtMath::Min(GtMath::Max((w.field_C - D_01E78EE0.field_0) / (D_01E78EE4.field_0 - D_01E78EE0.field_0), 0.0f), 1.0f);
        vol = D_01E78EE8.field_0 + t * (D_01E78EEC.field_0 - D_01E78EE8.field_0);
        pitch = (D_01E78EF0.field_0 + t * (D_01E78EF4.field_0 - D_01E78EF0.field_0)) * (1.0f + field_24) * field_30;
        params.field_24 = pitch * field_14->CalcFrequency();
    } else {
        UnkStruct_0028FF30_v w;
        *(u_long128 *)&w = field_0->field_B0;
        float t = GtMath::Min(GtMath::Max((w.field_C - D_01E78EC8.field_0) / (D_01E78ECC.field_0 - D_01E78EC8.field_0), 0.0f), 1.0f);
        vol = D_01E78ED0.field_0 + t * (D_01E78ED4.field_0 - D_01E78ED0.field_0);
        pitch = (D_01E78ED8.field_0 + t * (D_01E78EDC.field_0 - D_01E78ED8.field_0)) * (1.0f + field_24) * field_30;
        params.field_24 = pitch * field_C->CalcFrequency();
    }
    params.field_1C = field_34 * (vol * field_20);
    UnkStruct_0028FF30_v u;
    *(u_long128 *)&u = field_0->field_B0;
    params.field_C = u.field_0;
    params.field_10 = u.field_4;
    params.field_14 = u.field_8;
    field_18->Update((const CGtSoundVoiceParams *)&params);
}
