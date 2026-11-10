// CB3SoundTrafficVehicle::UpdateHorn(float,float,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficVehicle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ghvu12: Ghidra draft; three dead unit-axis CGtV4d via volatile-read ctor stand-in [L] N185, union copies in [G] inlines (slot order), compiler-chosen vsub/in-place Normalise stand-ins).

// CB3SoundTrafficVehicle::UpdateHorn(float,float,bool) -- hand-written (ghvu12) from the Ghidra draft.
// [C] name: the mangled symbol in retail's tables. Field names are placeholders and every type is [G].
// [G] meaning: when the horn flag (field_114 bit 3) is set, fill a CGtSoundVoiceParams with the vehicle position and,
// if a wave is set, a Doppler-shifted frequency (speed of sound field_F0) from the nearest listener's position and
// velocity, then update the horn voice. Shapes: StartSpecialVehicle's params/union copies, CalculateDoppler's VU stand-ins.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CGtSoundVirtualVoice;
class CGtSoundWave;
struct UnkStruct_00278B20_prm {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    const CGtSoundWave * field_18;
    float field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0x10];
    float field_38;
    unsigned char pad_3C[0x14];
};
union UnkStruct_00278B20_uv { u_long128 q; float f[4]; };
struct UnkStruct_00278B20_0 { unsigned char pad_0[0x90]; CGtV3d field_90; unsigned char pad_A0[0x24]; float field_C4; };
class CB3SoundTrafficVehicle {
public:
    void UpdateHorn(float p0, float p1, bool p2);
    UnkStruct_00278B20_0 *field_0;
    unsigned char pad_4[0xAC];
    CGtV3d field_B0;
    unsigned char pad_C0[0x8];
    CGtSoundVirtualVoice *field_C8;
    unsigned char pad_CC[0x8];
    const CGtSoundWave *field_D4;
    unsigned char pad_D8[0x10];
    float field_E8;
    float field_EC;
    float field_F0;
    unsigned char pad_F4[0x20];
    int field_114;
};
extern float D_01E78EFC[];
extern unsigned char D_01E75688[];
extern "C" void * GetNearestListener__23CGtSoundListenerManagerCFQ29GtMathPs26CGtV3d(const void *, const void *);
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" void GetPos__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(const void *, CGtV3d *);
extern "C" void GetVelocity__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(const void *, CGtV3d *);
extern "C" float CalcFrequency__12CGtSoundWaveCFv(const void *);
extern "C" void Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(CGtSoundVirtualVoice *, const void *);

// [L] N185: compiler-chosen CGtV3d operator- stand-in
static inline CGtV3d func_00278B20_inl1(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
// [L] N185: in-place Normalise on a compiler-chosen register stand-in
static inline void func_00278B20_inl3(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 r = v.mData;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(r));
    asm(".set reorder");
    v.mData = r;
}
// [L] N185: XAxisType -> float without the address-taken read
static inline float func_00278B20_inl4(u_long128 x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x)); return f; }

// [L] N185: CGtV4d(float,float,float,float) stand-in with the 128-bit load written as asm (retail builds three unit-axis
// vectors (1,0,0,1) (0,1,0,1) (0,0,1,1) at entry and keeps their stack stores and dead lq; a C load is removed)
struct UnkStruct_00278B20_v4 {
    u_long128 mData;
    UnkStruct_00278B20_v4(float x, float y, float z, float w) {
        union { float f[4]; u_long128 q; } t;
        t.f[0] = x; t.f[1] = y; t.f[2] = z; t.f[3] = w;
        mData = *(volatile u_long128 *)&t.q;
    }
};
// [G] a vector's xyz copied into three floats through a 16-byte union temporary
static inline void func_00278B20_inl6(float *vp, const CGtV3d &v)
{
    UnkStruct_00278B20_uv t;
    t.q = v.mData;
    vp[0] = t.f[0];
    vp[1] = t.f[1];
    vp[2] = t.f[2];
}
// [G] the listener velocity copied into the params' second vector through a 16-byte union temporary
static inline void func_00278B20_inl7(UnkStruct_00278B20_prm &p, const CGtV3d &v)
{
    UnkStruct_00278B20_uv t;
    t.q = v.mData;
    float *vp = &p.field_C;
    vp[0] = t.f[0];
    vp[1] = t.f[1];
    vp[2] = t.f[2];
}
// 0x00278B20
void CB3SoundTrafficVehicle::UpdateHorn(float p0, float p1, bool p2)
{
    UnkStruct_00278B20_v4 k0(1.0f, 0.0f, 0.0f, 1.0f);
    UnkStruct_00278B20_v4 k1(0.0f, 1.0f, 0.0f, 1.0f);
    UnkStruct_00278B20_v4 k2(0.0f, 0.0f, 1.0f, 1.0f);
    if (!(field_114 & 8)) return;
    {
        UnkStruct_00278B20_prm prm;
        CGtV3d lv;
        CGtV3d lp;
        Construct__19CGtSoundVoiceParamsFv(&prm);
        func_00278B20_inl6(&prm.field_0, field_B0);
        prm.field_38 = D_01E78EFC[0];
        if (field_D4 == 0) return;
        {
            CGtV3d vv = field_0->field_90 * field_0->field_C4;
            void *l = GetNearestListener__23CGtSoundListenerManagerCFQ29GtMathPs26CGtV3d(D_01E75688, &field_B0);
            GetPos__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(l, &lp);
            GetVelocity__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(l, &lv);
            CGtV3d d = func_00278B20_inl1(field_B0, lp);
            CGtV3d rv = func_00278B20_inl1(lv, vv);
            func_00278B20_inl3(d);
            float dot = func_00278B20_inl4(DotProduct(d, rv).lVector);
            float c = field_F0;
            float f = c / (c - dot) * CalcFrequency__12CGtSoundWaveCFv(field_D4);
            prm.field_24 = field_EC * f;
            func_00278B20_inl7(prm, lv);
            prm.field_1C = p1 * field_E8;
            Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(field_C8, &prm);
        }
    }
}
