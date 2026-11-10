// Hand-written; the lifter refused it (lst1: listener family loop + c = inl7(c, i) crash-flag loop sharing one int i, flags at the top, D_004E1AD8 extern).

// func_0027B1D0 -- hand-matched by lst1: the func_0027CC20 listener-family loop (lst1) as an early-out guard, then a
// crash-flag loop over the cars (byte 0x12C63A of each 0x27D0 record), the spot ducker and one or two voices.
// Earlier archives: a192 / a204 / sdra (local stand-ins). Unnamed in every table, so a placeholder with C linkage (the asm
// label); file and Area unknown, so _unclassified/. Structs are declared with only the fields touched; every type is [G]
// (instruction widths); `self` is whatever a0 points to.
// lst1: the second loop as `c = inl7(c, i)` (bool r = true; if (!c) {byte test}) with ONE `int i` shared by both loops
// (fixes t0/t1), both flags declared at the top (c lives in s0 from entry), the threshold through the D_004E1AD8 extern
// (the literal schedules its lwc1 too early here), D_01E75644 padded to 0x10 (absolute addressing).

typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::XAxisType;

class CGtSoundVoiceParams;

class CGtSoundVoiceManager;
class CGtSoundVirtualVoice;
class CGtSoundWave;
struct UnkStruct_0027B1D0;
struct UnkStruct_0027B1D0_2;
struct UnkStruct_0027B1D0_a1;
struct UnkStruct_D_004BEE10;

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

struct UnkStruct_0027B1D0_a1 {
    u_long128 field_0;
};

struct UnkStruct_0027B1D0_2 {
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

struct UnkStruct_0027B1D0_v {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};

struct UnkStruct_D_004BEE10 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0027B1D0_pad { int x[4]; UnkStruct_0027B1D0_pad() {} ~UnkStruct_0027B1D0_pad() {} };
struct UnkStruct_0027B1D0_e {
    CGtV3d field_0;
    CGtV3d field_10;
    unsigned char pad_20[0x20];
};
struct UnkStruct_D_0064D3A0 { int field_0; int pad_4[3]; };
extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern float D_004E1AD8;

struct UnkStruct_0027B1D0 {
    unsigned char pad_0[0x270];
    UnkStruct_0027B1D0_e field_270[4];  // [G] count
    unsigned char pad_370[0x510];
    int field_880;
};

struct UnkStruct_D_00522660 { unsigned char pad_0[0x27D0]; };
extern UnkStruct_D_00522660 D_00522660[];
struct UnkStruct_D_01E75644 { unsigned char field_0; unsigned char pad_1[0xF]; };  // [G] size: absolute addressing (N50)
extern UnkStruct_D_01E75644 D_01E75644;
class CB3SoundGameModeManager { public: void TriggerSpotDucker(float); unsigned char pad_0[0x10]; };
extern CB3SoundGameModeManager D_01E77540;
extern "C" void func_00280580(void *, float, const void *, int);
extern "C" void func_0027E170(void *, float, const void *, int);

extern UnkStruct_D_004BEE10 D_004BED10;
extern UnkStruct_D_004BEE10 D_004BED18;
extern CGtSoundVoiceManager D_01E7569C;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);  // CGtSoundBank::FindWave(const unsigned long&,bool) const

// [L] N185 local stand-ins for the listener test (no header body reproduces retail's sequence):
// d = a - b on compiler-chosen registers
static inline CGtV3d func_0027B1D0_inl1(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
// [L] N185 stand-in: normalise in place through 1/sqrt, with the inverse length also formed (dead) in the same tail
static inline void func_0027B1D0_inl2(CGtV3d &d)
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
static inline bool func_0027B1D0_inl4(float c)
{
    return c > D_004E1AD8;
}

static inline bool func_0027B1D0_inl5(UnkStruct_0027B1D0 *self, const UnkStruct_0027B1D0_a1 &pos, int i)
{
    CGtV3d d = func_0027B1D0_inl1(CGtV3d(pos.field_0), self->field_270[i].field_10);
    func_0027B1D0_inl2(d);
    XAxisType x = GtMathPs2::CosAngleBetweenNormalisedVectors(self->field_270[i].field_0, d);
    float f;
    asm("mtc1 %1, %0" : "=f"(f) : "r"(x.lVector));
    return func_0027B1D0_inl4(f);
}

static inline bool func_0027B1D0_inl7(bool c, int i)
{
    bool r = true;
    if (!c) {
        if (*((unsigned char *)&D_00522660[i] + 0x12C63A) == 0) r = false;
    }
    return r;
}

// 0x0027B1D0
extern "C" void func_0027B1D0(UnkStruct_0027B1D0 * self, const UnkStruct_0027B1D0_a1 * p0)
{
    UnkStruct_0027B1D0_a1 pos = *p0;
    UnkStruct_0027B1D0_2 params;
    UnkStruct_0027B1D0_v v;
    UnkStruct_0027B1D0_pad pad;  // N140 [G]: one more 16-byte slot below v (retail frame 0xC0)
    bool b = false;
    bool c = false;
    int i;
    for (i = 0; i < D_0064D3A0.field_0; i++) {
        b = b || func_0027B1D0_inl5(self, pos, i);
    }
    if (!b) return;
    Construct__19CGtSoundVoiceParamsFv(&params);
    *(u_long128 *)&v = pos.field_0;
    params.field_20 = 1.0f;
    params.field_0 = v.field_0;
    params.field_4 = v.field_4;
    params.field_8 = v.field_8;
    for (i = 0; i < D_0064D3A0.field_0; i++) {
        c = func_0027B1D0_inl7(c, i);
    }
    if (c) {
        D_01E77540.TriggerSpotDucker(0.75f);
        params.field_18 = (CGtSoundWave *)FindWave__12CGtSoundBankCFRCUlb((void *)self->field_880, &D_004BED10, 1);
        params.field_1C = 1.0f;
    } else {
        params.field_18 = (CGtSoundWave *)FindWave__12CGtSoundBankCFRCUlb((void *)self->field_880, &D_004BED18, 1);
        params.field_1C = 0.5f;
    }
    float &vr = params.field_1C;
    params.field_38 = 450.0f;
    params.field_3C = 100.0f;
    params.field_24 = params.field_18->CalcFrequency();
    params.field_44 = 2;
    CGtSoundVirtualVoice *vv = D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&params);
    if (vv != 0) {
        vv->IgnoreGlobalPitch();
        vv->Update((const CGtSoundVoiceParams*)&params);
    }
    if (D_01E75644.field_0 == 0) {
        vv = D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&params);
        if (vv != 0) {
            vr = 0.5f;
            vv->IgnoreGlobalPitch();
            vv->Update((const CGtSoundVoiceParams*)&params);
        }
    }
    func_00280580(self, 100000, &pos, 1);
    func_0027E170(self, 100000, &pos, 1);
}
