// Hand-written; the lifter refused it (fam1: clone of func_0027C5A0 (fields -0x20, cooldown 0x8CE=15, D_004BED90)).

// func_0027C8E0 -- hand-matched by fam1: clone of func_0027C5A0 (lst1's listener family source; simfind 0.995) with
// this function's fields (0x640..0x65C), the cooldown byte 0x8CE = 15 and the wave key D_004BED90. Unnamed in every
// table, so a placeholder with C linkage (the asm label); file and Area unknown, so _unclassified/. Structs are declared
// with only the fields touched; every type is [G] (instruction widths); `self` is whatever a0 points to.

typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::XAxisType;

class CGtSoundVoiceParams;

class CGtSoundVoiceManager;
class CGtSoundWave;
struct UnkStruct_0027C8E0;
struct UnkStruct_0027C8E0_2;
struct UnkStruct_0027C8E0_a1;
struct UnkStruct_D_004BEE10;
struct UnkStruct_D_004EE040;

class CGtSoundWave {
public:
    float CalcFrequency() const;
};

class CGtSoundVoiceManager {
public:
    void TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0027C8E0_a1 {
    u_long128 field_0;
};

struct UnkStruct_0027C8E0_2 {
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0xC];
    CGtSoundWave * field_18;
    float field_1C;
    float field_20;
    float field_24;
    unsigned char pad_28[0x10];
    float field_38;
    unsigned char pad_3C[0x8];
    unsigned char field_44;
    unsigned char pad_45[0xB];
};

struct UnkStruct_0027C8E0_v {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};

struct UnkStruct_D_004BEE10 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0027C8E0_pad { int x[4]; UnkStruct_0027C8E0_pad() {} ~UnkStruct_0027C8E0_pad() {} };
struct UnkStruct_0027C8E0_e {
    CGtV3d field_0;
    CGtV3d field_10;
    unsigned char pad_20[0x20];
};
struct UnkStruct_D_0064D3A0 { int field_0; int pad_4[3]; };
extern UnkStruct_D_0064D3A0 D_0064D3A0;

struct UnkStruct_0027C8E0 {
    unsigned char pad_0[0x270];
    UnkStruct_0027C8E0_e field_270[4];  // [G] count
    unsigned char pad_370[0x1B0];
    int field_520;
    int field_524;
    unsigned char pad_528x[0x118];
    float field_640;
    float field_644;
    float field_648;
    float field_64C;
    float field_650;
    float field_654;
    float field_658;
    float field_65C;
    unsigned char pad_660[0x220];
    int field_880;
    unsigned char pad_884[0x4A];
    signed char field_8CE;
    unsigned char pad_8CF[0x10];
    unsigned char field_8DF;
};

extern UnkStruct_D_004BEE10 D_004BED90;
extern UnkStruct_D_004EE040 D_004EE040;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const
extern "C" int func_00131E40(void *);

// [L] N185 local stand-ins for the listener test (no header body reproduces retail's sequence):
// d = a - b on compiler-chosen registers
static inline CGtV3d func_0027C8E0_inl1(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
// [L] N185 stand-in: normalise in place through 1/sqrt, with the inverse length also formed (dead) in the same tail
static inline void func_0027C8E0_inl2(CGtV3d &d)
{
    XAxisType l = d.GetSquaredLength();
    u_long128 v = d.mData, t, p, inv;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2 %0, $vf1" "\n\t" "vwaitq" : "=r"(p));
    asm(".set reorder");
    asm("vmulq.xyz %0, %0, $Q" "\n\t" "qmtc2 %1, $vf1" : "+j"(v) : "r"(p));
    asm(".set noreorder");
    asm("vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2 %0, $vf1" : "=r"(inv));
    asm(".set reorder");
    t = v;
    d.mData = t;
}
static inline bool func_0027C8E0_inl4(float c)
{
    return c > 0.17364818f;
}

static inline bool func_0027C8E0_inl5(UnkStruct_0027C8E0 *self, const UnkStruct_0027C8E0_a1 &pos, int i)
{
    CGtV3d d = func_0027C8E0_inl1(CGtV3d(pos.field_0), self->field_270[i].field_10);
    func_0027C8E0_inl2(d);
    XAxisType x = GtMathPs2::CosAngleBetweenNormalisedVectors(self->field_270[i].field_0, d);
    float f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(x.lVector));
    return func_0027C8E0_inl4(f);
}

// 0x0027C8E0
extern "C" void func_0027C8E0(UnkStruct_0027C8E0 * self, unsigned char sel, const UnkStruct_0027C8E0_a1 * p0, float f0)
{
    UnkStruct_0027C8E0_a1 pos = *p0;
    UnkStruct_0027C8E0_2 params;
    UnkStruct_0027C8E0_v v;
    UnkStruct_0027C8E0_pad pad;  // N140 [G]: one more 16-byte slot below v (retail frame 0xD0)
    if (self->field_8DF != 0) return;
    if (f0 < self->field_640) return;
    if (self->field_8CE != 0) return;
    self->field_8CE = 15;
    float t = GtMath::Min(GtMath::Max((f0 - self->field_640) / (self->field_644 - self->field_640), 0.0f), 1.0f);
    float v0 = self->field_648 + t * (self->field_64C - self->field_648);
    float vol;
    if (sel) vol = v0 * self->field_658; else vol = v0 * self->field_65C;
    float pitch = self->field_650 + t * (self->field_654 - self->field_650);
    if (pitch < 0.1f) return;
    Construct__19CGtSoundVoiceParamsFv(&params);
    *(u_long128 *)&v = pos.field_0;
    float &vr = params.field_1C;
    vr = vol;
    params.field_20 = 1.0f;
    params.field_0 = v.field_0;
    params.field_4 = v.field_4;
    params.field_8 = v.field_8;
    params.field_18 = (CGtSoundWave *)FindWave__12CGtSoundBankCFRCUlb((void *)self->field_880, &D_004BED90, 1);
    self->field_520 = (self->field_520 << 16) + (self->field_520 >> 16);
    self->field_520 += self->field_524;
    self->field_524 += self->field_520;
    pitch *= (1.0f + 0.1f * (2.0f * (2.3283064e-10f * (float)(unsigned int)self->field_520))) - 0.1f;
    params.field_24 = pitch * params.field_18->CalcFrequency();
    if (func_00131E40(&D_004EE040) != 0) {
        bool b = false;
        for (int i = 0; i < D_0064D3A0.field_0; i++) {
            b = b || func_0027C8E0_inl5(self, pos, i);
        }
        if (!b) return;
        params.field_38 = 120.0f;
        vr *= 0.85f;
    } else {
        params.field_38 = 40.0f;
    }
    params.field_44 = 3;
    D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&params);
}
