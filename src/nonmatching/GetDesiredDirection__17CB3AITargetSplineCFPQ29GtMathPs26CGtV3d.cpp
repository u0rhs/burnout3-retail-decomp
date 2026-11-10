// NONMATCHING: GetDesiredDirection__17CB3AITargetSplineCFPQ29GtMathPs26CGtV3d -- retail 154 / ours 154 instructions, 12 in changed runs
// psweep: scoped #pragma opt_arithtransformation off [G] improves 13 -> 12
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3AITargetSpline::GetDesiredDirection(GtMathPs2::CGtV3d *) const -- hand-written from the Ghidra draft (ghvu9).
// [C] name: config/symbol_addrs_b3names.txt (0x149EC0). Fields are placeholders, types [G] (instruction widths).

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_arithtransformation off

struct UnkStruct_00149EC0_obj {
    unsigned char pad_0[0xB0];
    GtMathPs2::CGtV4d field_B0;
    unsigned char pad_C0[0x1464];
    int field_1524;
};

struct UnkStruct_00149EC0_car {
    unsigned char pad_0[0x30];
    GtMathPs2::CGtV3d field_30;
    unsigned char pad_40[0x1BA8];
    int field_1BE8;
    int field_1BEC;
    unsigned char pad_1BF0[0x40];
    GtMathPs2::CGtV3d field_1C30;
    GtMathPs2::CGtV3d field_1C40;
    unsigned char pad_1C50[0x2];
    unsigned char field_1C52;
    unsigned char pad_1C53[0x7DD];
    UnkStruct_00149EC0_obj * field_2430;
};

class CB3AITargetSpline {
public:
    float GetDesiredDirection(GtMathPs2::CGtV3d * p0) const;

    unsigned char pad_0[0x110];
    GtMathPs2::CGtV3d field_110;
    GtMathPs2::CGtV3d field_120;
    GtMathPs2::CGtV3d field_130;
    GtMathPs2::CGtV3d field_140;
    unsigned char pad_150[0x1];
    unsigned char field_151;
    unsigned char pad_152[0x2];
    UnkStruct_00149EC0_car * field_154;
};

// [L] N185: stands in for a missing GtMathPs2 inline (CGtV3d::operator*=(float), in place: retail 0x14A07C
// `qmtc2.ni s,$vf1; vmulx.xyz $vf3,$vf3,$vf1x`)
static inline void func_00149EC0_inl1(GtMathPs2::CGtV3d * v, float f)
{
    u_long128 s;
    asm("qmtc2 %1, %0" : "=j"(s) : "r"(f));
    asm("vmulx.xyz %0, %0, %1x" : "+j"(v->mData) : "j"(s));
}

static inline float func_00149EC0_inl2(GtMathPs2::CGtV3d * p0, float w, GtMathPs2::CGtV3d d)
{
    float r;
    if (w > 1.0f) {
        r = (float)d.GetLength() / w;
    } else {
        r = d.GetLength();
    }
    func_00149EC0_inl1(p0, 80.0f);
    *p0 += d;
    p0->Normalise();
    return r;
}

// 0x00149EC0
float CB3AITargetSpline::GetDesiredDirection(GtMathPs2::CGtV3d * p0) const
{
    UnkStruct_00149EC0_car * car = field_154;
    if (car->field_1BEC == 0 && car->field_1BE8 == 2 &&
        (car->field_2430->field_1524 == 1 || car->field_2430->field_1524 == 2) && car->field_1C52 != 0xFF) {
        *p0 = car->field_1C40;
        GtMathPs2::CGtV3d d = car->field_1C30 - car->field_30;
        float w = car->field_2430->field_B0.W();
        float r;
        if (w > 1.0f) {
            r = (float)GtMathPs2::DotProduct(*p0, d) / w;
        } else {
            r = GtMathPs2::DotProduct(*p0, d);
        }
        return GtMath::Min(GtMath::Max(0.1f, r), 0.5f);
    }
    GtMathPs2::CGtV3d target;
    if (field_151) {
        target = field_140;
        *p0 = field_130;
    } else {
        target = field_120;
        *p0 = field_110;
    }
    GtMathPs2::CGtV3d d = target - field_154->field_30;
    ((float *)&d)[3] = ((const float *)&field_154->field_30)[3]; // [C] 0x14A008 lqc2 vf1, 0x30(a0) (field_154->field_30);
    // 0x14A010 vsub.xyz vf1, vf2, vf1 keeps its w; 0x14A014 sqc2 vf1, 0x0(sp) -- `a - b` took target's w
    return func_00149EC0_inl2(p0, field_154->field_2430->field_B0.W(), d);
}


#pragma pop
