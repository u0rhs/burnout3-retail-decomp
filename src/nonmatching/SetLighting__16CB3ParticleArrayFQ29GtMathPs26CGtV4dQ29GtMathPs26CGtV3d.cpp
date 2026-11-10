// NONMATCHING: SetLighting__16CB3ParticleArrayFQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV3d -- retail 112 / ours 112 instructions, 12 in changed runs
// retune1 (N239): 0x28-int N140 pad after v (v declared bare, then v = d) restores frame 0x100 and v at 0xC0; 35 -> 12 (old archive 21)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: SetLighting__16CB3ParticleArrayFQ29GtMathPs26CGtV4dQ29GtMathPs26CGtV3d -- retail 112 / ours 112 instructions, 21 in changed runs
// ghvu5: logic complete; head/if-else/Min/normalise exact. Left (21): v = d is forwarded as vmove (retail reloads lqc2 vf3,0xE0(sp)); retail makes GetLength's 1.0 before the Set and parks it; v's slot (retail 0xC0 under m, ours sp+0) and frame 0x100 vs 0x80 (8 dead slots between v and the if/else temps, 2 below). Stand-ins: CGtV4d*float and SetA with compiler-chosen scalar (header hard-codes $vf2), Min with const& operands, Y*float on hard $vf1.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// CB3ParticleArray::SetLighting(GtMathPs2::CGtV4d, GtMathPs2::CGtV3d) -- hand-written (ghvu5, Ghidra draft).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3ParticleRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders, types [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_00254D50_cfg { unsigned char pad_0[0x50]; float field_50; float field_54; float field_58; unsigned char field_5C; };
class CB3ParticleArray {
public:
    void SetLighting(CGtV4d colour, CGtV3d dir);
    unsigned char pad_0[0x30];
    CGtV4d field_30;
    CGtV4d field_40;
    CGtV3dPlus field_50;
    unsigned char pad_60[0x84];
    UnkStruct_00254D50_cfg *field_E4;
};
// [L] N185: stand in for header bodies that hard-code $vf2 for the scalar (retail: compiler-chosen)
static inline CGtV4d func_00254D50_inl1(const CGtV4d &c, float s)
{
    u_long128 sv, t;
    asm("qmtc2.ni %1, %0" : "=j"(sv) : "r"(s));
    asm("vmulx.xyzw %0, %1, %2x" : "=j"(t) : "j"(c.mData), "j"(sv));
    return CGtV4d(t);
}
static inline void func_00254D50_inl2(CGtV4d &c, float a)
{
    u_long128 sv;
    asm("qmtc2.ni %1, %0" : "=j"(sv) : "r"(a));
    asm("vmulx.w %0, $vf0, %1x" : "+j"(c.mData) : "j"(sv));
}
// [L] N185: Min(CGtV4d, CGtV4d) with the first operand by const& (v279)
static inline CGtV4d func_00254D50_inl3(const CGtV4d &a, const CGtV4d &b) { u_long128 r; asm("vmini.xyzw %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV4d(r); }
// [L] N185: operator*(YAxisType, float) with the scalar and the product on a hard-coded $vf1 (retail
// `qmtc2.ni a1,$vf1; vmulx.y $vf1,$vf2,$vf1x`; the header's is compiler-chosen)
static inline YAxisType func_00254D50_inl4(YAxisType a, float f)
{
    u_long128 r;
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulx.y $vf1, %2, $vf1x" "\n\t" "qmfc2 %0, $vf1" : "=r"(r) : "r"(f), "j"(a.lVector));
    return YAxisType(r);
}
struct UnkStruct_00254D50_pad { int x[40]; UnkStruct_00254D50_pad() {} ~UnkStruct_00254D50_pad() {} };
// 0x00254D50
void CB3ParticleArray::SetLighting(CGtV4d colour, CGtV3d dir)
{
    CGtV3d d = dir;
    field_30 = func_00254D50_inl1(colour, field_E4->field_50);
    field_40 = func_00254D50_inl1(colour, field_E4->field_54);
    func_00254D50_inl2(field_30, 1.0f);
    func_00254D50_inl2(field_40, 1.0f);
    CGtV4d m;
    if (field_E4->field_5C) m = CGtV4d(1.99f, 1.99f, 1.99f, 1.0f);
    else m = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
    field_30 = func_00254D50_inl3(field_30, m);
    field_40 = func_00254D50_inl3(field_40, m);
CGtV3d v;
    UnkStruct_00254D50_pad pq;
    v = d;
    v.Set(d.X(), func_00254D50_inl4(d.Y(), field_E4->field_58), d.Z());
    XAxisType len = v.GetLength();
    if (((unsigned long)len.lVector & 0x7F800000) <= 0x37800000) v.Set(0.0f, -1.0f, 0.0f);
    v.Normalise();
    field_50.SetGtV3d(v);
}


