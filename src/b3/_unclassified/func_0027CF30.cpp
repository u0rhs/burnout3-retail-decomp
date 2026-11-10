// Hand-written; the lifter refused it (lst1: rewritten as a clone of the func_0027CC20 listener family source (fields 0x610.., 0x8C3=4, D_004BEDA0)).

// func_0027CF30 -- hand-matched by lst1: clone of the func_0027CC20 listener family source (lst1), with this function's
// fields (0x610..0x624), the cooldown byte 0x8C3 = 4 and its sound (D_004BEDA0). Earlier archives: a195 / repair1 (local
// stand-ins). Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction widths); `self` is
// whatever a0 points to.

typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::XAxisType;

class CGtSoundVoiceParams;

class CGtSoundVoiceManager;
class CGtSoundWave;
struct UnkStruct_0027CF30;
struct UnkStruct_0027CF30_2;
struct UnkStruct_0027CF30_a1;
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

struct UnkStruct_0027CF30_a1 {
    u_long128 field_0;
};

struct UnkStruct_0027CF30_2 {
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

struct UnkStruct_0027CF30_v {
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

struct UnkStruct_0027CF30_pad { int x[4]; UnkStruct_0027CF30_pad() {} ~UnkStruct_0027CF30_pad() {} };
struct UnkStruct_0027CF30_e {
    CGtV3d field_0;
    CGtV3d field_10;
    unsigned char pad_20[0x20];
};
struct UnkStruct_D_0064D3A0 { int field_0; int pad_4[3]; };
extern UnkStruct_D_0064D3A0 D_0064D3A0;

struct UnkStruct_0027CF30 {
    unsigned char pad_0[0x270];
    UnkStruct_0027CF30_e field_270[4];  // [G] count
    unsigned char pad_370[0x1B0];
    int field_520;
    int field_524;
    unsigned char pad_528x[0xE8];
    float field_610;
    float field_614;
    float field_618;
    float field_61C;
    float field_620;
    float field_624;
    unsigned char pad_628[0x258];
    int field_880;
    unsigned char pad_884[0x3F];
    signed char field_8C3;
    unsigned char pad_8C4[0x1B];
    unsigned char field_8DF;
};

extern UnkStruct_D_004BEE10 D_004BEDA0;
extern UnkStruct_D_004EE040 D_004EE040;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const
extern "C" int func_00131E40(void *);

// [L] N185 local stand-ins for the listener test (no header body reproduces retail's sequence):
// d = a - b on compiler-chosen registers
static inline CGtV3d func_0027CF30_inl1(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
// [L] N185 stand-in: normalise in place through 1/sqrt, with the inverse length also formed (dead) in the same tail
static inline void func_0027CF30_inl2(CGtV3d &d)
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
static inline bool func_0027CF30_inl4(float c)
{
    return c > 0.17364818f;
}

static inline bool func_0027CF30_inl5(UnkStruct_0027CF30 *self, const UnkStruct_0027CF30_a1 &pos, int i)
{
    CGtV3d d = func_0027CF30_inl1(CGtV3d(pos.field_0), self->field_270[i].field_10);
    func_0027CF30_inl2(d);
    XAxisType x = GtMathPs2::CosAngleBetweenNormalisedVectors(self->field_270[i].field_0, d);
    float f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(x.lVector));
    return func_0027CF30_inl4(f);
}

// 0x0027CF30
extern "C" void func_0027CF30(UnkStruct_0027CF30 * self, const UnkStruct_0027CF30_a1 * p0, float f0)
{
    UnkStruct_0027CF30_a1 pos = *p0;
    UnkStruct_0027CF30_2 params;
    UnkStruct_0027CF30_v v;
    UnkStruct_0027CF30_pad pad;  // N140 [G]: one more 16-byte slot below v (retail frame 0xD0)
    if (self->field_8DF != 0) return;
    if (f0 < self->field_610) return;
    if (self->field_8C3 != 0) return;
    self->field_8C3 = 4;
    float t = GtMath::Min(GtMath::Max((f0 - self->field_610) / (self->field_614 - self->field_610), 0.0f), 1.0f);
    float vol = self->field_618 + t * (self->field_61C - self->field_618);
    float pitch = self->field_620 + t * (self->field_624 - self->field_620);
    Construct__19CGtSoundVoiceParamsFv(&params);
    *(u_long128 *)&v = pos.field_0;
    float &vr = params.field_1C;
    vr = vol;
    params.field_20 = 1.0f;
    params.field_0 = v.field_0;
    params.field_4 = v.field_4;
    params.field_8 = v.field_8;
    params.field_18 = (CGtSoundWave *)FindWave__12CGtSoundBankCFRCUlb((void *)self->field_880, &D_004BEDA0, 1);
    self->field_520 = (self->field_520 << 16) + (self->field_520 >> 16);
    self->field_520 += self->field_524;
    self->field_524 += self->field_520;
    pitch *= (1.0f + 0.1f * (2.0f * (2.3283064e-10f * (float)(unsigned int)self->field_520))) - 0.1f;
    params.field_24 = pitch * params.field_18->CalcFrequency();
    if (func_00131E40(&D_004EE040) != 0) {
        bool b = false;
        for (int i = 0; i < D_0064D3A0.field_0; i++) {
            b = b || func_0027CF30_inl5(self, pos, i);
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
