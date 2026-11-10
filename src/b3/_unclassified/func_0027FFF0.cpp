// Hand-written; the lifter refused it (lst1: crash-flag loop (B1D0 form) + listener family loop; vol declared before pitch; field_18 read back via params).

// func_0027FFF0 -- hand-matched by lst1: the crash-flag loop of func_0027B1D0 (lst1) as a guard, the cooldown byte 0x8CD
// (30, skipped when p2 is set), then the func_0027CC20 listener-family loop (lst1) choosing 45/15 and the 0.85 volume
// scale. Earlier archives: a193 / hdr14 reroute (local stand-ins). Unnamed in every table, so a placeholder with C linkage
// (the asm label); file and Area unknown, so _unclassified/. Structs are declared with only the fields touched; every
// type is [G] (instruction widths); `self` is whatever a0 points to. lst1: `float vol;` declared before pitch (f21/f20), and
// field_18 stored then read back as params.field_18->CalcFrequency() (address kept in s1, load forwarded from v0).

typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::XAxisType;

class CGtSoundVoiceParams;

class CGtSoundVoiceManager;
class CGtSoundVirtualVoice;
class CGtSoundWave;
struct UnkStruct_0027FFF0;
struct UnkStruct_0027FFF0_2;
struct UnkStruct_0027FFF0_a1;
struct UnkStruct_D_004BEE10;
struct UnkStruct_D_004EE040;

class CGtSoundWave {
public:
    float CalcFrequency() const;
};

class CGtSoundVirtualVoice {
public:
    void IgnoreGlobalPitch();
    void Update(const CGtSoundVoiceParams*);
};

class CGtSoundVoiceManager {
public:
    CGtSoundVirtualVoice * TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0027FFF0_a1 {
    u_long128 field_0;
};

struct UnkStruct_0027FFF0_2 {
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
    float field_3C;
    unsigned char pad_40[0x4];
    unsigned char field_44;
    unsigned char pad_45[0xB];
};

struct UnkStruct_0027FFF0_v {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004BEE10 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0027FFF0_pad { int x[4]; UnkStruct_0027FFF0_pad() {} ~UnkStruct_0027FFF0_pad() {} };
struct UnkStruct_0027FFF0_e {
    CGtV3d field_0;
    CGtV3d field_10;
    unsigned char pad_20[0x20];
};
struct UnkStruct_D_0064D3A0 { int field_0; int pad_4[3]; };
extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern float D_004E1AD8;

struct UnkStruct_0027FFF0 {
    unsigned char pad_0[0x270];
    UnkStruct_0027FFF0_e field_270[4];  // [G] count
    unsigned char pad_370[0x22C];
    float field_59C;
    unsigned char pad_5A0[0x8];
    float field_5A8;
    unsigned char pad_5AC[0x8];
    float field_5B4;
    unsigned char pad_5B8[0x8];
    float field_5C0;
    unsigned char pad_5C4[0x8];
    float field_5CC;
    unsigned char pad_5D0[0x8];
    float field_5D8;
    unsigned char pad_5DC[0x2A4];
    int field_880;
    unsigned char pad_884[0x49];
    signed char field_8CD;
    unsigned char pad_8CE[0x11];
    unsigned char field_8DF;
};

extern UnkStruct_D_004EE040 D_004EE040;
extern "C" int func_00131E40(void *);
struct UnkStruct_D_00522660 { unsigned char pad_0[0x27D0]; };
extern UnkStruct_D_00522660 D_00522660[];

extern UnkStruct_D_004BEE10 D_004BEE80;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const

// [L] N185 local stand-ins for the listener test (no header body reproduces retail's sequence):
// d = a - b on compiler-chosen registers
static inline CGtV3d func_0027FFF0_inl1(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
// [L] N185 stand-in: normalise in place through 1/sqrt, with the inverse length also formed (dead) in the same tail
static inline void func_0027FFF0_inl2(CGtV3d &d)
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
static inline bool func_0027FFF0_inl4(float c)
{
    return c > D_004E1AD8;
}

static inline bool func_0027FFF0_inl5(UnkStruct_0027FFF0 *self, const UnkStruct_0027FFF0_a1 &pos, int i)
{
    CGtV3d d = func_0027FFF0_inl1(CGtV3d(pos.field_0), self->field_270[i].field_10);
    func_0027FFF0_inl2(d);
    XAxisType x = GtMathPs2::CosAngleBetweenNormalisedVectors(self->field_270[i].field_0, d);
    float f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(x.lVector));
    return func_0027FFF0_inl4(f);
}

static inline bool func_0027FFF0_inl7(bool c, int i)
{
    bool r = true;
    if (!c) {
        if (*((unsigned char *)&D_00522660[i] + 0x12C63A) == 0) r = false;
    }
    return r;
}

// 0x0027FFF0
extern "C" void func_0027FFF0(UnkStruct_0027FFF0 * self, const UnkStruct_0027FFF0_a1 * p0, bool p2, float f0)
{
    UnkStruct_0027FFF0_a1 pos = *p0;
    UnkStruct_0027FFF0_2 params;
    UnkStruct_0027FFF0_v v;
    UnkStruct_0027FFF0_pad pad;  // N140 [G]: one more 16-byte slot below v (retail frame 0xC0)
    if (self->field_8DF != 0) return;
    bool c = false;
    int i;
    for (i = 0; i < D_0064D3A0.field_0; i++) {
        c = func_0027FFF0_inl7(c, i);
    }
    if (!c) return;
    if (self->field_8CD != 0 && !p2) return;
    self->field_8CD = 30;
    Construct__19CGtSoundVoiceParamsFv(&params);
    *(u_long128 *)&v = pos.field_0;
    params.field_0 = v.field_0;
    params.field_4 = v.field_4;
    params.field_8 = v.field_8;
    float t = GtMath::Min(GtMath::Max((f0 - self->field_59C) / (self->field_5A8 - self->field_59C), 0.0f), 1.0f);
    float vol;
    float pitch = self->field_5CC + t * (self->field_5D8 - self->field_5CC);
    vol = self->field_5B4 + t * (self->field_5C0 - self->field_5B4);
    if (func_00131E40(&D_004EE040) != 0) {
        bool b = false;
        for (int k = 0; k < D_0064D3A0.field_0; k++) {
            b = b || func_0027FFF0_inl5(self, pos, k);
        }
        if (!b) return;
        params.field_38 = 45.0f;
        vol *= 0.85f;
    } else {
        params.field_38 = 15.0f;
    }
    params.field_1C = vol;
    params.field_20 = 1.0f;
    params.field_18 = (CGtSoundWave *)FindWave__12CGtSoundBankCFRCUlb((void *)self->field_880, &D_004BEE80, 1);
    params.field_24 = pitch * params.field_18->CalcFrequency();
    params.field_44 = 3;
    D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&params);
}
