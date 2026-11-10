// Hand-written; the lifter refused it (ghvu13: clone of proven func_0027E570 (listener loop) with this function's fields/constants).

// func_0027DDD0 -- hand-matched by ghvu13: clone of the proven sibling func_0027E570 (same listener loop and
// normalise/CosAngleBetweenNormalisedVectors stand-ins) with this function's fields (0x6D0..0x6E4, cooldown 0x8C7),
// D_004E1AD8 threshold (sdata global, as func_00280580), field_38 120/40, field_44 = 12 and the TriggerVoice result
// passed to func_003872C0 (as func_0028BF90). Unnamed in every table: placeholder with C linkage; _unclassified/.
// Structs declare only the fields touched; every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::XAxisType;

class CGtSoundVoiceParams;

class CGtSoundVoiceManager;
class CGtSoundVirtualVoice;
class CGtSoundWave;
struct UnkStruct_0027DDD0;
struct UnkStruct_0027DDD0_2;
struct UnkStruct_0027DDD0_a1;
struct UnkStruct_D_004BEE10;
struct UnkStruct_D_004EE040;

class CGtSoundWave {
public:
    float CalcFrequency() const;
};

class CGtSoundVoiceManager {
public:
    CGtSoundVirtualVoice * TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0027DDD0_a1 {
    u_long128 field_0;
};

struct UnkStruct_0027DDD0_2 {
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

struct UnkStruct_0027DDD0_v {
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

struct UnkStruct_0027DDD0_pad { int x[4]; UnkStruct_0027DDD0_pad() {} ~UnkStruct_0027DDD0_pad() {} };
struct UnkStruct_0027DDD0_e {
    CGtV3d field_0;
    CGtV3d field_10;
    unsigned char pad_20[0x20];
};
struct UnkStruct_D_0064D3A0 { int field_0; int pad_4[3]; };
extern UnkStruct_D_0064D3A0 D_0064D3A0;

struct UnkStruct_0027DDD0 {
    unsigned char pad_0[0x270];
    UnkStruct_0027DDD0_e field_270[4];  // [G] count
    unsigned char pad_370[0x1B0];
    int field_520;
    int field_524;
    unsigned char pad_528[0x1A8];
    float field_6D0;
    float field_6D4;
    float field_6D8;
    float field_6DC;
    float field_6E0;
    float field_6E4;
    unsigned char pad_6E8[0x198];
    int field_880;
    unsigned char pad_884[0x43];
    signed char field_8C7;
    unsigned char pad_8C8[0x17];
    unsigned char field_8DF;
};

extern UnkStruct_D_004BEE10 D_004BEDB0;
extern UnkStruct_D_004EE040 D_004EE040;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const
extern "C" int func_00131E40(void *);
extern "C" void func_003872C0(CGtSoundVirtualVoice *, int, float, float, float, float, float, float);
extern float D_004E1AD8;

// [L] N185 local stand-ins for the listener test (no header body reproduces retail's sequence):
// d = a - b on compiler-chosen registers
static inline CGtV3d func_0027DDD0_inl1(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
// [L] N185 stand-in: normalise in place through 1/sqrt, with the inverse length also formed (dead) in the same tail
static inline void func_0027DDD0_inl2(CGtV3d &d)
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
static inline bool func_0027DDD0_inl4(float c)
{
    return c > D_004E1AD8;
}

static inline bool func_0027DDD0_inl5(UnkStruct_0027DDD0 *self, const UnkStruct_0027DDD0_a1 &pos, int i)
{
    CGtV3d d = func_0027DDD0_inl1(CGtV3d(pos.field_0), self->field_270[i].field_10);
    func_0027DDD0_inl2(d);
    XAxisType x = GtMathPs2::CosAngleBetweenNormalisedVectors(self->field_270[i].field_0, d);
    float f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(x.lVector));
    return func_0027DDD0_inl4(f);
}

// 0x0027DDD0
extern "C" void func_0027DDD0(UnkStruct_0027DDD0 * self, const UnkStruct_0027DDD0_a1 * p0, float f0)
{
    UnkStruct_0027DDD0_a1 pos = *p0;
    UnkStruct_0027DDD0_2 params;
    UnkStruct_0027DDD0_v v;
    UnkStruct_0027DDD0_pad pad;  // N140 [G]: one more 16-byte slot below v (retail frame 0xD0)
    if (f0 < self->field_6D0) return;
    if (self->field_8C7 != 0) return;
    self->field_520 = (self->field_520 << 16) + (self->field_520 >> 16);
    self->field_520 += self->field_524;
    self->field_524 += self->field_520;
    self->field_8C7 = (unsigned int)self->field_520 % 20 + 20;
    float t = GtMath::Min(GtMath::Max((f0 - self->field_6D0) / (self->field_6D4 - self->field_6D0), 0.0f), 1.0f);
    float vol = self->field_6D8 + t * (self->field_6DC - self->field_6D8);
    float pitch = self->field_6E0 + t * (self->field_6E4 - self->field_6E0);
    Construct__19CGtSoundVoiceParamsFv(&params);
    *(u_long128 *)&v = pos.field_0;
    params.field_20 = 1.0f;
    params.field_0 = v.field_0;
    params.field_4 = v.field_4;
    params.field_8 = v.field_8;
    if (self->field_8DF != 0) {
        params.field_1C = 2.0f * vol;
    } else {
        params.field_1C = vol;
    }
    float &vr = params.field_1C;
    params.field_18 = (CGtSoundWave *)FindWave__12CGtSoundBankCFRCUlb((void *)self->field_880, &D_004BEDB0, 1);
    self->field_520 = (self->field_520 << 16) + (self->field_520 >> 16);
    self->field_520 += self->field_524;
    self->field_524 += self->field_520;
    pitch *= (1.0f + (2.0f * (2.3283064e-10f * (float)(unsigned int)self->field_520)) * 0.1f) - 0.1f;
    params.field_24 = pitch * params.field_18->CalcFrequency();
    if (func_00131E40(&D_004EE040) != 0) {
        bool b = false;
        for (int i = 0; i < D_0064D3A0.field_0; i++) {
            b = b || func_0027DDD0_inl5(self, pos, i);
        }
        if (!b) return;
        params.field_38 = 120.0f;
        vr *= 0.85f;
    } else {
        params.field_38 = 40.0f;
    }
    params.field_44 = 12;
    CGtSoundVirtualVoice *vv = D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&params);
    if (vv != 0) {
        func_003872C0(vv, 1, 0.63f, 0.63f, 0.31f, 0.5f, 0.42f, 0.42f);
    }
}
