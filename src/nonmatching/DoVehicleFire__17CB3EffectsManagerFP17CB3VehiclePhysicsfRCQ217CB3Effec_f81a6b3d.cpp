// NONMATCHING: DoVehicleFire__17CB3EffectsManagerFP17CB3VehiclePhysicsfRCQ217CB3EffectsManager9CLighting -- retail 99 / ours 99 instructions, 2 in changed runs
// grind1: 4 -> 2. The psweep opt_lifetimes pragma was not needed (4 without it; dropped). TransformPoint operand-order stand-in (point loaded before row 0, as retail) fixes the lqc2 pair. Left: the Y()-w vector temp at sp+0xA0 vs retail 0xB0 (N255 slot order; pads before/after/inside inl1 don't move it)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] logic and calls exact; 2 off = one stack slot (N255 class)

#include "b3/GtMathPs2.h"
// grind1 [G]: TransformPoint stand-in (inl2) = the header body with the point as the first "j" operand: retail loads the point (lqc2 vf2) before row 0 (lqc2 vf1) here; header lead.
using namespace GtMathPs2;

struct UnkStruct_0025FB60_pt { CGtV3d field_0; unsigned char pad_10[0x20]; };
struct UnkStruct_0025FB60_ai { unsigned char pad_0[0x1690]; UnkStruct_0025FB60_pt * field_1690; unsigned char pad_1694[0x23]; unsigned char field_16B7; };
struct UnkStruct_0025FB60_inst { CGtMatrix3x4 field_0; UnkStruct_0025FB60_ai * field_40; };
struct UnkStruct_0025FB60_st { unsigned char pad_0[0x490]; CGtV4d field_490; unsigned char pad_4A0[0xB76]; unsigned char field_1016; };
class CB3VehiclePhysics {
public:
    unsigned char pad_0[0xCC0];
    UnkStruct_0025FB60_inst * field_CC0;
    UnkStruct_0025FB60_st * field_CC4;
};
struct UnkStruct_D_01EA4BB0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01EA4BB0 D_01EA4BB0;
extern "C" void func_0039AD90(UnkStruct_D_01EA4BB0 *, CGtV3d *, float, float, float);
class CB3EffectsManager {
public:
    class CLighting;
    void DoVehicleFire(CB3VehiclePhysics *, float, const CLighting &);
    unsigned char pad_0[0x1F84C];
    float field_1F84C;
};

// [G] N140 frame pad
struct UnkStruct_0025FB60_pad { int x[4]; UnkStruct_0025FB60_pad() {} ~UnkStruct_0025FB60_pad() {} };
static inline float func_0025FB60_inl1(const CGtV3d &v, float w) { return v.Y() - w; }

static inline CGtV3d func_0025FB60_inl2(const CGtMatrix3x4& m, CGtV3d v) {
    u_long128 t;
    asm(".set noreorder" "\n\t" "vmulax.xyz $ACC, %2, %1x" "\n\t" "qmtc2.i %3, $vf1" "\n\t" "vmadday.xyz $ACC, $vf1, %1y" "\n\t" "qmtc2.i %4, $vf1" "\n\t"
        "vmaddaz.xyz $ACC, $vf1, %1z" "\n\t" "qmtc2.i %5, $vf1" "\n\t" "vmaddw.xyz $vf1, $vf1, $vf0w" "\n\t" "qmfc2.i %0, $vf1" "\n\t" ".set reorder"
        : "=r"(t) : "j"(v.mData), "j"(m.mRight.mData), "r"(m.mUp.mData), "r"(m.mAt.mData), "r"(m.mPos.mData));
    return CGtV3d(t);
}

// 0x0025FB60
void CB3EffectsManager::DoVehicleFire(CB3VehiclePhysics * veh, float size, const CLighting &)
{
    float w = veh->field_CC4->field_490.W();
    if (w < 1.8f) {
        unsigned char flags = veh->field_CC4->field_1016;
        UnkStruct_0025FB60_pt * pt;
        unsigned char n;
        unsigned char bit = 0x10;
        CGtMatrix3x4 m = veh->field_CC0->field_0;
        float y = func_0025FB60_inl1(m.mPos, w);
        pt = veh->field_CC0->field_40->field_1690;
        n = veh->field_CC0->field_40->field_16B7;
        while (n--) {
            if (flags & bit) {
                CGtV3d p = func_0025FB60_inl2(m, pt->field_0);
                UnkStruct_0025FB60_pad q0;
                UnkStruct_0025FB60_pad q1;
                UnkStruct_0025FB60_pad q2;
                p.SetY(y);
                func_0039AD90(&D_01EA4BB0, &p, size, size, field_1F84C);
            }
            bit += bit;
            pt++;
        }
    }
}



