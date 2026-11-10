// NONMATCHING: InitaliseTrailerPosition__17CB3TrafficVehicleFv -- retail 373 / ours 372 instructions, 13 in changed runs
// ghvu20: 13 off, all in the race-car distance loop: retail's guard compares a materialised i (daddu a1,0; slt at,a1,a0; nop) where ours folds 0 (slt at,zero,a0; move in delay slot) -- no loop form/pragma reproduces it; loop VU numbering 1.0 vf2/mPos vf3/zero vf4 vs ours 1.0 vf3/mPos vf2. Rest exact: fused p+v*s stand-in (inl7), 3-statement form at the second mPos site (inl8), noreorder cross product, N140 0x70 pad
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3TrafficVehicle::InitaliseTrailerPosition() -- hand-written (ghvu20, Ghidra draft + retail asm).
// [C] name: the mangled symbol in retail's tables; Area not evidenced, so _unclassified/ (docs/conventions.md).
// Layout as the archived sibling CB3TrafficVehicle::InitalisePosition (src/nonmatching, ghvu14: axles at +0x0 / +0x30,
// CGtMatrix3x4 at +0x70) and the proven DoTrafficBehaviour (B3TrafficVehicle_001717D0.cpp: D_00522660 rows of 0x3F8
// bytes from +0x39234, field_177). Field names are placeholders and every type is [G]. Reading [G]: the trailer copies
// its tractor's matrix, hangs at the hitch point (tractor mPos + mAt * field_134), places its axles, rebuilds
// mAt/mUp/mRight (NormaliseGetLength fallbacks, CrossProduct), records its distance to every race car and recurses
// into its own trailer.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3TrafficVehicle;
class CB3TrafficAxle {
public:
    void InitalisePosition(CB3TrafficVehicle *);
    CGtV3dPlus field_0;
    CGtV3d field_10;
    unsigned char pad_20[0x10];
};
struct UnkStruct_00172860_car { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_D_00522660 {                    // [G] six rows (race cars) per table
    unsigned char pad_0[0x39234];
    float field_39234[6][0xFE];
    unsigned char field_3AA04[6][0xFE];
    unsigned char field_3AFF8[6][0x19];
    unsigned char field_3B08E[6][0x8];
    unsigned char pad_3B0BE[0x72];
    unsigned char field_3B130[6];
    unsigned char field_3B136[6];
    unsigned char field_3B13C[6];
    unsigned char pad_3B142[0xEFBE6];
    UnkStruct_00172860_car * field_12AD28[6];
};
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064D37C D_0064D37C;

class CB3TrafficVehicle {
public:
    void InitaliseTrailerPosition();

    CB3TrafficAxle field_0;
    CB3TrafficAxle field_30;
    CGtV3d field_60;
    CGtMatrix3x4 field_70;
    unsigned char pad_B0[0x14];
    float field_C4;
    unsigned char pad_C8[0x44];
    CB3TrafficVehicle * field_10C;
    CB3TrafficVehicle * field_110;
    unsigned char pad_114[0x20];
    float field_134;
    float field_138;
    unsigned char pad_13C[0x10];
    float field_14C;
    float field_150;
    unsigned char pad_154[0x1F];
    signed char field_173;
    unsigned char field_174;
    unsigned char field_175;
    unsigned char pad_176;
    unsigned char field_177;
    unsigned char pad_178[0x2];
    unsigned char field_17A;
    unsigned char field_17B;
};

// [L] N185: CrossProduct (header body) with the result moved out `.i` (retail keeps qmfc2 + sq and reloads, v241;
// as the archived sibling's func_00173950_inl5).
static inline CGtV3d func_00172860_inl1(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm(".set noreorder");
    asm("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b.mData) : "j"(a.mData));
    asm(".set reorder");
    return CGtV3d(t);
}
// [L] N185: a + b on compiler-chosen registers (the header operator+ hard-codes $vf1/$vf2).
static inline CGtV3d func_00172860_inl3(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
// [G] p + d * s with the sum written directly in the inline (its operands are numbered before the product's, pass2b).
static inline CGtV3d func_00172860_inl4(const CGtV3d &p, CGtV3d d, float s)
{
    u_long128 r;
    asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(p.mData), "j"((d * s).mData));
    return CGtV3d(r);
}
// [L] N185: a - b on compiler-chosen registers (the header operator- takes its inputs on $vf1/$vf2).
static inline CGtV3d func_00172860_inl5(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vsub.xyz %0, %2, %1" : "=j"(r) : "j"(b.mData), "j"(a.mData));
    return CGtV3d(r);
}
static inline CGtV3d func_00172860_inl6(const CGtV3d &p, CGtV3d v, float s)
{
    CGtV3d r = p;
    r += v * s;
    return r;
}
static inline CGtV3d func_00172860_inl7(const CGtV3d &p, CGtV3d v, float s)
{
    u_long128 r, sv;
    asm("qmtc2 %1, %0" : "=j"(sv) : "r"(s));
    asm("vmulx.xyz %1, %1, %3x" "\n\t" "vadd.xyz %0, %2, %1" : "=j"(r), "+j"(v.mData) : "j"(p.mData), "j"(sv));
    return CGtV3d(r);
}
struct UnkStruct_00172860_pad { int x[28]; UnkStruct_00172860_pad() {} ~UnkStruct_00172860_pad() {} };
static inline CGtV3d func_00172860_inl8(const CGtV3d &p, CGtV3d v, float s)
{
    u_long128 r, sv;
    asm("qmtc2 %1, %0" : "=j"(sv) : "r"(s));
    asm("vmulx.xyz %0, %0, %1x" : "+j"(v.mData) : "j"(sv));
    asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(p.mData), "j"(v.mData));
    return CGtV3d(r);
}
static inline CGtV3d func_00172860_inl9(const CGtV3d &p, CGtV3d v, float s)
{
    u_long128 r, sv;
    asm("qmtc2 %1, %0" : "=j"(sv) : "r"(s));
    asm("vmulx.xyz %1, %1, %3x" "\n\t" "vadd.xyz %0, %1, %2" : "=j"(r), "+j"(v.mData) : "j"(p.mData), "j"(sv));
    return CGtV3d(r);
}
static inline CGtV3d func_00172860_inl10(const CGtV3d &p, CGtV3d v, float s)
{
    CGtV3d m = v * s;
    u_long128 r;
    asm("vadd.xyz %0, %2, %1" : "=j"(r) : "j"(m.mData), "j"(p.mData));
    return CGtV3d(r);
}
static inline bool func_00172860_inl2(CB3TrafficVehicle *v)
{
    if (!(v->field_174 & 4)) return false;
    if (v->field_10C == 0) return false;
    if ((unsigned)(v->field_173 - 8) < 2) return true;
    return false;
}

// 0x00172860
void CB3TrafficVehicle::InitaliseTrailerPosition()
{
    CGtMatrix3x4 *pm = &field_10C->field_70;
    if (field_10C) {
        field_17A = field_10C->field_17A;
        field_175 = field_10C->field_175;
        field_17B = field_10C->field_17B;
        field_C4 = field_10C->field_C4;
        field_70 = *pm;
        CGtV3d hitch = func_00172860_inl7(pm->mPos, pm->mAt, field_10C->field_134);
        field_70.mAt = pm->mAt;
        UnkStruct_00172860_pad pad;  // N140 [G]: seven dead 16-byte slots below the hitch (retail frame 0x100)
        field_70.mPos = func_00172860_inl3(hitch, field_70.mAt * field_138);
        if (func_00172860_inl2(this)) {
            field_0.field_0.SetGtV3d(func_00172860_inl7(field_70.mPos, field_70.mAt, field_150));
            field_0.InitalisePosition(this);
        }
        field_30.field_0.SetGtV3d(func_00172860_inl7(field_70.mPos, field_70.mAt, field_14C));
        field_30.InitalisePosition(this);
        field_70.mAt = func_00172860_inl5(hitch, CGtV3d(field_30.field_0.mData));
        if (field_70.mAt.NormaliseGetLength() == 0.0f) field_70.mAt.SetZ(1.0f);
        field_70.mPos = func_00172860_inl8(hitch, field_70.mAt, field_138);
        field_70.mUp = func_00172860_inl3(pm->mUp, field_30.field_10);
        if (field_70.mUp.NormaliseGetLength() == 0.0f) field_70.mUp.SetY(1.0f);
        field_70.mRight = func_00172860_inl1(field_70.mUp, field_70.mAt);
        if (field_70.mRight.NormaliseGetLength() == 0.0f) field_70.mRight.SetX(1.0f);
        field_70.mUp = func_00172860_inl1(field_70.mAt, field_70.mRight);
        if (field_70.mUp.NormaliseGetLength() == 0.0f) field_70.mUp.SetY(1.0f);
        int n = D_0064D37C.field_0;
        for (int i = 0; i < n; i++) {
            CGtV3d d = field_70.mPos - D_00522660.field_12AD28[i]->field_30;
            d.SetY(0.0f);
            float dist = d.GetLength();
            D_00522660.field_39234[i][field_177] = dist;
            if (dist < 16.0f) {
                D_00522660.field_3B08E[i][D_00522660.field_3B13C[i]] = field_177;
                D_00522660.field_3B13C[i]++;
            }
            if (dist < 100.0f) {
                D_00522660.field_3AFF8[i][D_00522660.field_3B136[i]] = field_177;
                D_00522660.field_3B136[i]++;
            }
            D_00522660.field_3AA04[i][D_00522660.field_3B130[i]] = field_177;
            D_00522660.field_3B130[i]++;
        }
        if (field_110) field_110->InitaliseTrailerPosition();
    }
}
