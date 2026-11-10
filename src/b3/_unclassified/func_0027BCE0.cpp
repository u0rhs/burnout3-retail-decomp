// Hand-written; the lifter refused it (Ghidra draft + CalculateDoppler's VU stand-ins (b-first vsub, Normalise+1*Q, mtc1 lane read), header GetLength compare, one N140 pad).

// func_0027BCE0 -- hand-written (ghvu7) from the Ghidra draft; same VU shapes as CalculateDoppler (B3SoundESM_00287970.cpp).
// Field names are placeholders and every type is [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_0027BCE0_s { unsigned char pad_0[0x1EC]; unsigned char field_1EC; };
struct UnkStruct_0027BCE0 {
    unsigned char pad_0[0x270];
    CGtV3d field_270;
    CGtV3d field_280;
    unsigned char pad_290[0x5F4];
    UnkStruct_0027BCE0_s *field_884;
    unsigned char pad_888[0x1C];
    float field_8A4;
    unsigned char pad_8A8[0x34];
    unsigned char field_8DC;
    unsigned char field_8DD;
    unsigned char pad_8DE[2];
    unsigned char field_8E0;
};
// N140 pad: one dead 16-byte frame slot retail keeps [G] (the header operator float in the cosine compare would reserve
// it, but that form moves the cosine block out of line).
struct UnkStruct_0027BCE0_pad { int x[4]; UnkStruct_0027BCE0_pad() {} ~UnkStruct_0027BCE0_pad() {} };
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0027BCE0_id { unsigned long field_0; };
struct UnkStruct_D_00516E44 { UnkStruct_0027BCE0_id *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_int D_0064D3A0;
extern UnkStruct_D_00516E44 D_00516E44;
extern unsigned char D_004EE040[];
extern "C" int func_00131E40(void *);
extern "C" void func_00385EA0(void *, int, float, float, float, float);
extern "C" void func_00385EB0(void *);
extern "C" void Play__14CGtSoundStreamFb(void *, bool);

// [L] N185: stands in for a missing GtMathPs2 inline (a Normalise on a compiler-chosen register that also forms 1.0*Q,
// result unused; as in CalculateDoppler__15CB3SoundESMHigh).
static inline void func_0027BCE0_inl1(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 one;
    CGtV3d r;
    asm(".set noreorder");
    asm("qmtc2.i %2, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %1, $vf1" "\n\t"
        "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(v.mData), "=&r"(one) : "r"(l.lVector));
    asm("qmtc2.i %1, $vf1" "\n\t" "qmfc2.i %0, %2" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %1, $vf1" : "=r"(r.mData), "+r"(one) : "j"(v.mData));
    asm(".set reorder");
    v = r;
}
// [L] N185: XAxisType -> float without the address-taken read (operator float's N129 slot).
static inline float func_0027BCE0_inl2(u_long128 x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x)); return f; }
// [L] N185: CGtV3d::operator-(const CGtV3d&) on compiler-chosen registers stand-in.
static inline CGtV3d func_0027BCE0_inl3(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %2, %1" : "=j"(r) : "j"(b.mData), "j"(a.mData)); return CGtV3d(r); }

// 0x0027BCE0
extern "C" void func_0027BCE0(UnkStruct_0027BCE0 *self, CGtV3d pos)
{
    CGtV3d pc = pos;
    UnkStruct_0027BCE0_pad pad;
    if (D_0064D3A0.field_0 > 1) return;
    if (func_00131E40(D_004EE040) != 0) {
        CGtV3d d = func_0027BCE0_inl3(pc, self->field_280);
        func_0027BCE0_inl1(d);
        if (func_0027BCE0_inl2(CosAngleBetweenNormalisedVectors(self->field_270, d).lVector) <= 0.8660254f) return;
    } else {
        unsigned long key;
        if (D_00516E44.field_0 != 0) {
            key = D_00516E44.field_0->field_0;
        } else {
            key = 0x6D6123044330FCCFUL;
        }
        if (key == 0xBA38E7C8878337FFUL) return;
    }
    if (func_0027BCE0_inl3(pc, self->field_280).GetLength() < 50.0f) {
        func_00385EA0(self->field_884, -1, 0.71f, 0.6f, 0.0f, 0.35f);
        Play__14CGtSoundStreamFb(self->field_884, false);
        self->field_884->field_1EC = 3;
        func_00385EB0(self->field_884);
        self->field_8DD = 0;
        self->field_8E0 = 1;
        self->field_8DC = 1;
        self->field_8A4 = 2.0f;
    }
}
