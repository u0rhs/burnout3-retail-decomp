// NONMATCHING: func_0028CF00 -- retail 165 / ours 165 instructions, 26 in changed runs
// near26: 26 off (was 32): .lit4 externs written as literals (0.4/0.05/0.7/0.3/2.666/0.85), pos/vel as 3-float struct copies (vel through a field pointer), (curve) * fq operand order. Left: head load order (retail lq e->B0, lwc1 field_11C4, lq car->30, lwc1 boost; pv in a0 -- statement order inert), FP numbering in the volume curve (0.75 in f3 shared by compare+multiply, 0.25 loaded before the sub; operand orders/inline forms inert), add.s order of the out-of-line field_8C += 0.05 block
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


typedef unsigned int u_long128 __attribute__((mode(TI)));
class CB3Burn { public: static float gmarBoostBarSizes[4]; };
struct UnkStruct_0028CF00_v { float x; float y; float z; };
struct UnkStruct_0028CF00_p {
    UnkStruct_0028CF00_v field_0; UnkStruct_0028CF00_v field_C;
    unsigned char pad_18[4];
    float field_1C; unsigned char pad_20[4]; float field_24; unsigned char pad_28[0x24];
};
struct UnkStruct_0028CF00_e { unsigned char pad_0[0xB0]; u_long128 field_B0; };
struct UnkStruct_0028CF00_ent { UnkStruct_0028CF00_e *field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_0028CF00_car {
    unsigned char pad_0[0x30]; u_long128 field_30;
    unsigned char pad_40[0x1184]; float field_11C4;
    unsigned char pad_11C8[0x7E4]; signed char field_19AC;
};
struct UnkStruct_0028CF00_self {
    unsigned char pad_0[0x6C];
    void *field_6C; void *field_70;
    unsigned char pad_74[0x18];
    float field_8C;
    unsigned char pad_90[0xC];
    int field_9C;
};
extern UnkStruct_0028CF00_ent D_0055EFEC[];
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);
extern "C" void Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(void *, const void *);
extern "C" void func_0028CF00(UnkStruct_0028CF00_self *self, UnkStruct_0028CF00_car *car)
{
    if (self->field_6C == 0) return;
    float s = self->field_8C;
    if (s < 1.0f) self->field_8C = s + 0.05f;
    UnkStruct_0028CF00_e *e = D_0055EFEC[car->field_19AC].field_0;
    UnkStruct_0028CF00_p p;
    u_long128 b;
    u_long128 a;
    Construct__19CGtSoundVoiceParamsFv(&p);
    b = e->field_B0;
    a = car->field_30;
    float f20 = car->field_11C4 / CB3Burn::gmarBoostBarSizes[3];
    UnkStruct_0028CF00_v *pv = &p.field_C;
    *pv = *(UnkStruct_0028CF00_v *)&b;
    p.field_0 = *(UnkStruct_0028CF00_v *)&a;
    float fq = CalcFrequency__12CGtSoundWaveCFv((void *)(self->field_9C));
    p.field_24 = (0.7f + 0.4f * (1.0f - f20)) * fq;
    float v;
    if (f20 < 0.125f) {
        v = 0.0f;
    } else if (f20 < 0.5f) {
        v = 0.75f * (2.666f * (f20 - 0.125f));
    } else if (f20 < 0.75f) {
        v = 0.75f * (2.0f * (f20 - 0.25f));
    } else {
        v = 0.75f + 0.25f * (4.0f * (f20 - 0.75f));
    }
    p.field_1C = v * self->field_8C;
    Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(self->field_6C, &p);
    float w;
    if (f20 < 0.375f) {
        w = 0.85f * (2.666f * f20);
        if (w < 0.3f) w = 0.3f;
    } else if (f20 < 0.75f) {
        w = 0.85f - 0.85f * (2.666f * (f20 - 0.375f));
    } else {
        w = 0.85f * (4.0f * (f20 - 0.75f));
    }
    p.field_1C = w * self->field_8C;
    Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(self->field_70, &p);
}
