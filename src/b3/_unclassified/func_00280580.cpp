// Hand-written; the lifter refused it (Ghidra draft; AirRam-style sound trigger; Normalise+1*Q / dot-clamp stand-ins on u_long128 (no dead slots), nested GetSquaredLength helper for VU numbering; bool r = c > K).

// func_00280580 -- hand-written from the Ghidra draft (ghvu11). Unnamed in every table: placeholder, C linkage.
// Callers: CB3SoundCrashManager::DeformBoot etc. (`func_00280580(this, f, &pos, 0)`). Field names are placeholders,
// every type is [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

// N182: as the file's proven AirRam (file-wide consistent opt_dead_assignments off) [G]
#pragma push
#pragma opt_dead_assignments off

struct UnkStruct_00280580_a1 { u_long128 field_0; };
struct UnkStruct_00280580_v3 { float x; float y; float z; };
struct UnkStruct_00280580_params {
    UnkStruct_00280580_v3 field_0;
    unsigned char pad_C[0xC];
    int field_18;
    float field_1C;
    float field_20;
    float field_24;
    unsigned char pad_28[0x10];
    float field_38;
    unsigned char pad_3C[0x8];
    unsigned char field_44;
    unsigned char pad_45[0xB];
};
struct UnkStruct_00280580_v { float field_0; float field_4; float field_8; float field_C; };
struct UnkStruct_00280580_row { CGtV3d field_0; CGtV3d field_10; unsigned char pad_20[0x20]; };
struct UnkStruct_00280580 {
    unsigned char pad_0[0x270];
    UnkStruct_00280580_row field_270[8];
    unsigned char pad_470[0x128];
    float field_598;
    unsigned char pad_59C[8];
    float field_5A4;
    unsigned char pad_5A8[8];
    float field_5B0;
    unsigned char pad_5B4[8];
    float field_5BC;
    unsigned char pad_5C0[8];
    float field_5C8;
    unsigned char pad_5CC[8];
    float field_5D4;
    unsigned char pad_5D8[0x2A8];
    void *field_880;
    unsigned char pad_884[0x47];
    signed char field_8CB;
    unsigned char pad_8CC[0x13];
    unsigned char field_8DF;
};
struct UnkStruct_D_004BEE90 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004BEE90 D_004BEE90;
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004EE040 D_004EE040;
struct UnkStruct_D_01E7569C { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E7569C D_01E7569C;
struct UnkStruct_D_0064D3A0 { int field_0; unsigned char pad_4[12]; };
extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern unsigned char D_00522660[];
extern float D_004E1AD8;
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, const void *, bool);
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);
extern "C" void *TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(void *, const void *);
extern "C" int func_00131E40(void *);

// [L] N185: CGtV3d::operator-(const CGtV3d&) on compiler-chosen registers (N198's second vsub form) stand-in
static inline u_long128 func_00280580_inl3(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return r; }
// [L] N185: GetSquaredLength on a u_long128 (header body, no CGtV3d copy)
static inline u_long128 func_00280580_inl7(u_long128 v)
{
    u_long128 sq, one, t;
    asm("vmul.xyz %0, %1, %1" : "=j"(sq) : "j"(v));
    asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));
    asm(".set noreorder");
    asm("vadday.x $ACC, %1, %1y" "\n\t" "vmaddz.x %0, %2, %1z" : "=j"(t) : "j"(sq), "j"(one));
    asm(".set reorder");
    return t;
}
// [L] N185: stands in for a missing GtMathPs2 inline (a Normalise on a compiler-chosen register that also forms 1.0*Q,
// result unused; as proven func_00287970_inl1), by value
static inline u_long128 func_00280580_inl1(u_long128 v)
{
    u_long128 t = func_00280580_inl7(v);
    u_long128 l;
    asm("qmfc2 %0, %1" : "=r"(l) : "j"(t));
    u_long128 one, r;
    asm(".set noreorder");
    asm("qmtc2.i %2, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %1, $vf1" "\n\t"
        "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(v), "=&r"(one) : "r"(l));
    asm("qmtc2.i %1, $vf1" "\n\t" "qmfc2.i %0, %2" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %1, $vf1" : "=r"(r), "+r"(one) : "j"(v));
    asm(".set reorder");
    return r;
}
// [L] N185: DotProduct / CosAngleBetweenNormalisedVectors with const& operands stand-ins (two levels, as the header)
static inline u_long128 func_00280580_inl6(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 d, m, one, t;
    asm("vmul.xyz %0, %1, %2" : "=j"(m) : "j"(a.mData), "j"(b.mData));
    asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));
    asm(".set noreorder");
    asm("vadday.x $ACC, %1, %1y" "\n\t" "vmaddz.x %0, %2, %1z" : "=j"(t) : "j"(m), "j"(one));
    asm(".set reorder");
    asm("qmfc2 %0, %1" : "=r"(d) : "j"(t));
    return d;
}
static inline u_long128 func_00280580_inl4(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 d = func_00280580_inl6(a, b);
    u_long128 m;
    asm("vsubw.x %0, $vf0, $vf0w" : "=j"(m));
    asm("vmax.x %0, %0, %1" "\n\t" "vminiw.x %0, %0, $vf0w" : "+j"(d) : "j"(m));
    return d;
}
static inline float func_00280580_inl5(u_long128 x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x)); return f; }
static inline bool func_00280580_inl2(UnkStruct_00280580 *self, const CGtV3d &pos, int i)
{
    CGtV3d d = func_00280580_inl1(func_00280580_inl3(pos, self->field_270[i].field_10));
    float c = func_00280580_inl5(func_00280580_inl4(self->field_270[i].field_0, d));
    bool r = c > D_004E1AD8;
    return r;
}

// 0x00280580
extern "C" void func_00280580(UnkStruct_00280580 *self, float f, const UnkStruct_00280580_a1 *p0, int b)
{
    UnkStruct_00280580_a1 pos = *p0;
    UnkStruct_00280580_params params;
    UnkStruct_00280580_v v;
    if (self->field_8DF != 0) return;
    bool a = false;
    for (int i = 0; i < D_0064D3A0.field_0; i++) {
        bool t = true;
        if (!a) {
            if (*((unsigned char *)&D_00522660 + i * 0x27D0 + 0x12C63A) == 0) t = false;
        }
        a = t;
    }
    if (!a) return;
    if (self->field_8CB != 0) return;
    self->field_8CB = 30;
    Construct__19CGtSoundVoiceParamsFv(&params);
    *(u_long128 *)&v = pos.field_0;
    UnkStruct_00280580_v3 t3;
    params.field_0 = t3 = *(UnkStruct_00280580_v3 *)&v;
    float t = GtMath::Min(GtMath::Max((f - self->field_598) / (self->field_5A4 - self->field_598), 0.0f), 1.0f);
    float vol = 0.0f + self->field_5B0 + t * (self->field_5BC - self->field_5B0);
    float pitch = 0.0f + self->field_5C8 + t * (self->field_5D4 - self->field_5C8);
    if (func_00131E40(&D_004EE040) != 0) {
        bool hit = false;
        for (int i = 0; i < D_0064D3A0.field_0; i++) {
            bool h = hit;
            if (!hit) h = func_00280580_inl2(self, *(const CGtV3d *)&pos, i);
            hit = h;
        }
        if (!hit) return;
        params.field_38 = 45.0f;
        vol *= 0.85f;
    } else {
        params.field_38 = 15.0f;
    }
    params.field_1C = vol;
    params.field_20 = 1.0f;
    int *w = &params.field_18;
    *w = FindWave__12CGtSoundBankCFRCUlb(self->field_880, &D_004BEE90, 1);
    params.field_24 = pitch * CalcFrequency__12CGtSoundWaveCFv((void *)(*w));
    if (b != 0) params.field_44 = 1; else params.field_44 = 3;
    TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(&D_01E7569C, &params);
}

#pragma pop
