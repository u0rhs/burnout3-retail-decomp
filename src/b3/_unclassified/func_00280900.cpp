// Hand-written; the lifter refused it (fam1: listener clone of func_0027E570 + body a2, two-way wave pick, SetBias/SetPriority).

// func_00280900 -- hand-matched by fam1: clone of the proven listener sibling func_0027E570 (lst1 family source), with
// this function's fields (0x6B8..0x6CC, cooldown 0x8C9, early exit on 0x8DF), the speed and position read from the
// body in a2 (field_194, field_204->field_30; a1 is unused, the caller passes 0), the wave picked by a second random
// step (D_004BEDE0 / D_004BEDB0), the D_004E1AD8 threshold (as func_0027E170) and SetBias/SetPriority on the
// TriggerVoice result. `pw` assigned in each arm with `vr` declared after it gives retail's s0/s1; two N140 pads give
// the 0xE0 frame. Unnamed in every table: placeholder with C linkage; _unclassified/. Every type is [G].

typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::XAxisType;

class CGtSoundVoiceParams;

class CGtSoundVoiceManager;
class CGtSoundWave;
class CGtSoundVirtualVoice {
public:
    void SetBias(float);
    void SetPriority(float);
};
struct UnkStruct_00280900;
struct UnkStruct_00280900_2;
struct UnkStruct_00280900_a1;
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

struct UnkStruct_00280900_a1 {
    u_long128 field_0;
};

struct UnkStruct_00280900_2 {
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

struct UnkStruct_00280900_v {
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

struct UnkStruct_00280900_pad { int x[4]; UnkStruct_00280900_pad() {} ~UnkStruct_00280900_pad() {} };
struct UnkStruct_00280900_e {
    CGtV3d field_0;
    CGtV3d field_10;
    unsigned char pad_20[0x20];
};
struct UnkStruct_D_0064D3A0 { int field_0; int pad_4[3]; };
extern UnkStruct_D_0064D3A0 D_0064D3A0;

struct UnkStruct_00280900 {
    unsigned char pad_0[0x270];
    UnkStruct_00280900_e field_270[4];  // [G] count
    unsigned char pad_370[0x1B0];
    int field_520;
    int field_524;
    unsigned char pad_528[0x190];
    float field_6B8;
    float field_6BC;
    float field_6C0;
    float field_6C4;
    float field_6C8;
    float field_6CC;
    unsigned char pad_6D0[0x1B0];
    int field_880;
    unsigned char pad_884[0x45];
    signed char field_8C9;
    unsigned char pad_8CA[0x15];
    unsigned char field_8DF;
};

struct UnkStruct_00280900_p1b {
    unsigned char pad_0[0x30];
    UnkStruct_00280900_a1 field_30;
};

struct UnkStruct_00280900_p1 {
    unsigned char pad_0[0x194];
    float field_194;
    unsigned char pad_198[0x6C];
    UnkStruct_00280900_p1b * field_204;
};


extern UnkStruct_D_004BEE10 D_004BEDE0;
extern UnkStruct_D_004BEE10 D_004BEDB0;
extern float D_004E1AD8;
extern UnkStruct_D_004EE040 D_004EE040;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const
extern "C" int func_00131E40(void *);

// [L] N185 local stand-ins for the listener test (no header body reproduces retail's sequence):
// d = a - b on compiler-chosen registers
static inline CGtV3d func_00280900_inl1(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
// [L] N185 stand-in: normalise in place through 1/sqrt, with the inverse length also formed (dead) in the same tail
static inline void func_00280900_inl2(CGtV3d &d)
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
static inline bool func_00280900_inl4(float c)
{
    return c > D_004E1AD8;
}

static inline bool func_00280900_inl5(UnkStruct_00280900 *self, const UnkStruct_00280900_a1 &pos, int i)
{
    CGtV3d d = func_00280900_inl1(CGtV3d(pos.field_0), self->field_270[i].field_10);
    func_00280900_inl2(d);
    XAxisType x = GtMathPs2::CosAngleBetweenNormalisedVectors(self->field_270[i].field_0, d);
    float f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(x.lVector));
    return func_00280900_inl4(f);
}

// 0x00280900
extern "C" void func_00280900(UnkStruct_00280900 * self, int p0, UnkStruct_00280900_p1 * p1)
{
    UnkStruct_00280900_pad pad0;  // N140 [G]: unused 16-byte slot at the top of the frame (retail 0xE0)
    UnkStruct_00280900_a1 pos;
    UnkStruct_00280900_2 params;
    UnkStruct_00280900_v v;
    UnkStruct_00280900_pad pad;  // N140 [G]: one more 16-byte slot below v (as func_0027E570)
    if (self->field_8DF != 0) return;
    if (self->field_8C9 != 0) return;
    float f0 = p1->field_194;
    if (f0 < self->field_6B8) return;
    pos = p1->field_204->field_30;
    self->field_520 = (self->field_520 << 16) + (self->field_520 >> 16);
    self->field_520 += self->field_524;
    self->field_524 += self->field_520;
    self->field_8C9 = (unsigned int)self->field_520 % 20 + 20;
    float t = GtMath::Min(GtMath::Max((f0 - self->field_6B8) / (self->field_6BC - self->field_6B8), 0.0f), 1.0f);
    float vol = self->field_6C0 + t * (self->field_6C4 - self->field_6C0);
    float pitch = self->field_6C8 + t * (self->field_6CC - self->field_6C8);
    Construct__19CGtSoundVoiceParamsFv(&params);
    *(u_long128 *)&v = pos.field_0;
    CGtSoundWave **pw;
    params.field_20 = 1.0f;
    float &vr = params.field_1C;
    vr = vol;
    params.field_0 = v.field_0;
    params.field_4 = v.field_4;
    params.field_8 = v.field_8;
    self->field_520 = (self->field_520 << 16) + (self->field_520 >> 16);
    self->field_520 += self->field_524;
    self->field_524 += self->field_520;
    if ((unsigned int)self->field_520 % 10 < 5) {
        pw = &params.field_18;
        *pw = (CGtSoundWave *)FindWave__12CGtSoundBankCFRCUlb((void *)self->field_880, &D_004BEDE0, 1);
    } else {
        pw = &params.field_18;
        *pw = (CGtSoundWave *)FindWave__12CGtSoundBankCFRCUlb((void *)self->field_880, &D_004BEDB0, 1);
    }
    self->field_520 = (self->field_520 << 16) + (self->field_520 >> 16);
    self->field_520 += self->field_524;
    self->field_524 += self->field_520;
    pitch *= (1.0f + (2.0f * (2.3283064e-10f * (float)(unsigned int)self->field_520)) * 0.1f) - 0.1f;
    params.field_24 = pitch * (*pw)->CalcFrequency();
    params.field_44 = 3;
    if (func_00131E40(&D_004EE040) != 0) {
        bool b = false;
        for (int i = 0; i < D_0064D3A0.field_0; i++) {
            b = b || func_00280900_inl5(self, pos, i);
        }
        if (!b) return;
        params.field_38 = 120.0f;
        vr *= 0.85f;
    } else {
        params.field_38 = 40.0f;
    }
    CGtSoundVirtualVoice *vv = D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&params);
    if (vv != 0) {
        vv->SetBias(1.0f);
        vv->SetPriority(1.0f);
    }
}
