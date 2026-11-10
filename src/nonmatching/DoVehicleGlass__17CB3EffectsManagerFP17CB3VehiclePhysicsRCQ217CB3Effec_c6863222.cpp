// NONMATCHING: DoVehicleGlass__17CB3EffectsManagerFP17CB3VehiclePhysicsRCQ217CB3EffectsManager9CLighting -- retail 232 / ours 220 instructions, 123 in changed runs
// beh8: 220/232, 123 changed. Logic decoded: local CLighting {D_004E19C0, D_004E19C4}; m = CC0 matrix copy; loop A over field_16B5 pieces (field_1688, stride 0x30): pos/vel = TransformPoint/Vector, h = CC4->490.W() + pos.Y() - CC0 mPos.Y(), func_0025E410(type 12) + func_0025D430(bvel*1.75 twice, h); loop B over 16B1 then 16B2 pieces (1678/167C) with type 13 and the caller's lighting. Point+vector as ONE stand-in (rows $vf4/$vf3/$vf2 shared; qmtc2.i for mUp/mAt/mPos keeps retail's lq+qmtc2, .ni folds to lqc2). Left: frame 0x1B0 vs 0x260 (dead lane slots, N221), s-register numbering, and retail still computes h in loop B (dead lwc1 f0) which every form here drops
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// CB3EffectsManager::DoVehicleGlass(CB3VehiclePhysics*, const CB3EffectsManager::CLighting&) -- hand-written (beh8).
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/ (docs/conventions.md). Fields placeholders, types [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_0025FE70_pc { CGtV3d field_0; CGtV3d field_10; unsigned char pad_20[0x10]; };
struct UnkStruct_0025FE70_m {
    unsigned char pad_0[0x1678];
    UnkStruct_0025FE70_pc *field_1678;
    UnkStruct_0025FE70_pc *field_167C;
    unsigned char pad_1680[0x8];
    UnkStruct_0025FE70_pc *field_1688;
    unsigned char pad_168C[0x25];
    unsigned char field_16B1;
    unsigned char field_16B2;
    unsigned char pad_16B3[0x2];
    unsigned char field_16B5;
};
struct UnkStruct_0025FE70_inst { CGtMatrix3x4 field_0; UnkStruct_0025FE70_m *field_40; };
struct UnkStruct_0025FE70_st { unsigned char pad_0[0x490]; CGtV4d field_490; };
class CB3VehiclePhysics {
public:
    unsigned char pad_0[0xB0];
    CGtV3d field_B0;
    unsigned char pad_C0[0xC00];
    UnkStruct_0025FE70_inst *field_CC0;
    UnkStruct_0025FE70_st *field_CC4;
};
class CB3EffectsManager {
public:
    class CLighting {
    public:
        float field_0;
        float field_4;
    };
    void DoVehicleGlass(CB3VehiclePhysics *, const CLighting &);
};
extern __declspec(sdata) const float D_004E19C0;
extern __declspec(sdata) const float D_004E19C4;
extern "C" void func_0025E410(CB3EffectsManager *, const CGtV3d *, const CGtV3d *, const CGtV3d *, int, float, float, const CB3EffectsManager::CLighting *, void *, int, bool);
extern "C" void func_0025D430(CB3EffectsManager *, const CGtV3d *, const CGtV3d *, const CGtV3d *, const CGtV3d *, const CGtV3d *, int, int, float, float);
// [L] N185: TransformPoint / TransformVector with every row on a compiler-chosen register (retail keeps the rows in $vf4/$vf3/$vf2
// across both; the header TransformPoint hard-codes rows 1-3 on $vf1)
static inline CGtV3d func_0025FE70_inl1(const CGtMatrix3x4 &m, const CGtV3d &v)
{
    u_long128 t;
    u_long128 r;
    asm("vmulax.xyz $ACC, %1, %2x" "\n\t" "vmadday.xyz $ACC, %3, %2y" "\n\t" "vmaddaz.xyz $ACC, %4, %2z" "\n\t" "vmaddw.xyz %0, %5, $vf0w"
        : "=j"(t) : "j"(m.mRight.mData), "j"(v.mData), "j"(m.mUp.mData), "j"(m.mAt.mData), "j"(m.mPos.mData));
    asm("qmfc2.i %0, %1" : "=r"(r) : "j"(t));
    return CGtV3d(r);
}
static inline CGtV3d func_0025FE70_inl2(const CGtMatrix3x4 &m, const CGtV3d &v)
{
    u_long128 t;
    u_long128 r;
    asm("vmulax.xyz $ACC, %1, %2x" "\n\t" "vmadday.xyz $ACC, %3, %2y" "\n\t" "vmaddz.xyz %0, %4, %2z"
        : "=j"(t) : "j"(m.mRight.mData), "j"(v.mData), "j"(m.mUp.mData), "j"(m.mAt.mData));
    asm("qmfc2.i %0, %1" : "=r"(r) : "j"(t));
    return CGtV3d(r);
}
// [L] N185: lane w + lane y / lane w - lane y, result in lane w (retail `vaddy.w`, `vsuby.w`)
static inline WAxisType func_0025FE70_inl3(WAxisType a, YAxisType b) { u_long128 r; asm("vaddy.w %0, %1, %2y" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return WAxisType(r); }
static inline WAxisType func_0025FE70_inl4(WAxisType a, YAxisType b) { u_long128 r; asm("vsuby.w %0, %1, %2y" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return WAxisType(r); }

// [L] N185: TransformPoint(m, a) then TransformVector(m, b) on the same rows (retail: m.mRight in $vf4, mUp/mAt through GPRs into
// $vf3/$vf2 once, mPos into $vf1; the vector reuses $vf4/$vf3/$vf2)
static inline void func_0025FE70_inl5(const CGtMatrix3x4 &m, const CGtV3d &a, const CGtV3d &b, CGtV3d &p, CGtV3d &v)
{
    asm("qmtc2.ni %1, $vf4" "\n\t" "qmtc2.ni %2, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "qmtc2.i %3, $vf3" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t"
        "qmtc2.i %4, $vf2" "\n\t" "vmaddaz.xyz $ACC, $vf2, $vf1z" "\n\t" "qmtc2.i %5, $vf1" "\n\t" "vmaddw.xyz $vf1, $vf1, $vf0w" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(p.mData) : "r"(m.mRight.mData), "r"(a.mData), "r"(m.mUp.mData), "r"(m.mAt.mData), "r"(m.mPos.mData));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1"
        : "=r"(v.mData) : "r"(b.mData));
}
struct UnkStruct_0025FE70_pad { int x[4]; UnkStruct_0025FE70_pad() {} ~UnkStruct_0025FE70_pad() {} };

// 0x0025FE70
void CB3EffectsManager::DoVehicleGlass(CB3VehiclePhysics *veh, const CLighting &light)
{
    CLighting l;
    l.field_0 = D_004E19C0;
    l.field_4 = D_004E19C4;
    CGtMatrix3x4 m = veh->field_CC0->field_0;
    CGtV3d pos;
    CGtV3d vel;
    CGtV3d bvel = veh->field_B0;
    unsigned char n = veh->field_CC0->field_40->field_16B5;
    if (n != 0) {
        float one = 1.0f;
        float r = one / (float)(int)n;
        float a = GtMath::Min(180.0f * r, 50.0f);
        float b = GtMath::Min(125.0f * r, 40.0f);
        float c = 1.75f;
        UnkStruct_0025FE70_pc *pc = veh->field_CC0->field_40->field_1688;
        do {
            func_0025FE70_inl5(m, pc->field_0, pc->field_10, pos, vel);
            float h = func_0025FE70_inl4(func_0025FE70_inl3(veh->field_CC4->field_490.W(), pos.Y()), veh->field_CC0->field_0.mPos.Y());
            func_0025E410(this, &pos, &vel, &bvel, 12, a, one, &l, 0, 1, true);
            CGtV3d v1 = bvel * c;
            CGtV3d v2 = bvel * c;
            func_0025D430(this, &pos, &vel, &v1, 0, &v2, 2, 1, b, h);
            pc++;
        } while (--n != 0);
    }
    UnkStruct_0025FE70_m *x = veh->field_CC0->field_40;
    int n1 = x->field_16B1;
    int n2 = x->field_16B2;
    int tot = (unsigned char)(n1 + n2);
    if (tot != 0) {
        float one = 1.0f;
        float a = GtMath::Min(100.0f * (one / (float)tot), 25.0f);
        UnkStruct_0025FE70_pc *pc = x->field_1678;
        bool second = false;
        for (;;) {
            int old;
            while (old = n1, n1 = (unsigned char)(n1 - 1), old != 0) {
                func_0025FE70_inl5(m, pc->field_0, pc->field_10, pos, vel);
                float h = func_0025FE70_inl4(func_0025FE70_inl3(veh->field_CC4->field_490.W(), pos.Y()), veh->field_CC0->field_0.mPos.Y());
                func_0025E410(this, &pos, &vel, &bvel, 13, a, one, &light, 0, 1, true);
                pc++;
            }
            if (second) break;
            n1 = n2;
            pc = veh->field_CC0->field_40->field_167C;
            second = true;
        }
    }
}

