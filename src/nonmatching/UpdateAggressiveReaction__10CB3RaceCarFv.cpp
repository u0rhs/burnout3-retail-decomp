// NONMATCHING: UpdateAggressiveReaction__10CB3RaceCarFv -- retail 617 / ours 620 instructions, 215 in changed runs
// draftR: calls/CFG/stores identical; residue = CreateRotationMatrix3x4 internals (up ctor's 1.0f CSE'd into a saved FPR, by-value axis lq+qmtc2 vs lqc2), operator* stand-in, frame 0x2D0 vs 0x700 (dead slots)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] same call sequence, branch senses and stores; per-op counts equal except header-internal moves

// CB3RaceCar::UpdateAggressiveReaction() -- draftR (2026-10-31), hand-written from retail asm + Ghidra draft.
// [C] name: retail tables (B3RaceCar.cpp). Fields are placeholders, types [G] (instruction widths) unless noted.
// [L] field_0 / field_1920 / field_199B / field_44..50: the matched CB3RaceCar::Draw (B3RaceCar_00151A40.cpp) swaps
// field_0 for field_1920 when field_199B is set and resets 44/48/4C/50 to sin/cos 0 -> roll (44 sin, 48 cos) and
// pitch (4C sin, 50 cos) of the aggressive reaction. field_10C0 is the car's CB3Score (WasSlammedWithinTime this ptr).
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;
extern "C" float sinf(float);
extern "C" float cosf(float);

class CB3Score {
public:
    bool WasSlammedWithinTime(float);
    bool SlammedSomeoneWithinTime(float);
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0x4AC];
    float field_4BC;
    unsigned char pad_4C0[0x8];
    float field_4C8;
    unsigned char field_4CC;
};
struct UnkStruct_00151DC0_40 { unsigned char pad_0[0xE80]; CGtV3d field_E80; };
extern float krFishTailTime;
extern float krFishTailAngle;
extern float krAIFishTailAngle;
extern float krRollAngle;
extern float krFishTailDegMulti;
extern float krShuntTime;
extern float krShuntPitchAngle;
extern float krShuntDegMulti;

class CB3RaceCar {
public:
    void UpdateAggressiveReaction();
    CGtMatrix3x4 field_0;
    UnkStruct_00151DC0_40 *field_40;
    float field_44;
    float field_48;
    float field_4C;
    float field_50;
    unsigned char pad_54[0x106C];
    CB3Score field_10C0;
    unsigned char pad_1590[0x384];
    int field_1914;
    unsigned char pad_1918[0x8];
    CGtMatrix3x4 field_1920;
    unsigned char pad_1960[0x3B];
    unsigned char field_199B;
};

// [G] local stand-in for CGtMatrix3x4::operator* (header body with retail's .ni input moves at this site; header gap queued).
static inline CGtMatrix3x4 func_00151DC0_inl1(const CGtMatrix3x4& a, const CGtMatrix3x4& m)
{
    CGtMatrix3x4 r;
    asm("qmtc2.ni %0, $vf4" "\n\t" "qmtc2.ni %3, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "qmtc2.i %1, $vf3" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "qmtc2.i %2, $vf2" : : "r"(m.mRight.GetRawData()), "r"(m.mUp.GetRawData()), "r"(m.mAt.GetRawData()), "r"(a.mRight.GetRawData()));
    asm("vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mRight.mData));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mUp.mData) : "r"(a.mUp.GetRawData()));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddz.xyz $vf1, $vf2, $vf1z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mAt.mData) : "r"(a.mAt.GetRawData()));
    asm("qmtc2.ni %1, $vf1" "\n\t" "vmulax.xyz $ACC, $vf4, $vf1x" "\n\t" "vmadday.xyz $ACC, $vf3, $vf1y" "\n\t" "vmaddaz.xyz $ACC, $vf2, $vf1z" "\n\t" "qmtc2.i %2, $vf1" "\n\t" "vmaddw.xyz $vf1, $vf1, $vf0w" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r.mPos.mData) : "r"(a.mPos.GetRawData()), "r"(m.mPos.GetRawData()));
    return r;
}
// 0x00151DC0
void CB3RaceCar::UpdateAggressiveReaction()
{
    CGtV3d up(0.0f, 1.0f, 0.0f);
    CGtV3d zero(0.0f, 0.0f, 0.0f);
    if (field_10C0.field_4CC == 0 && field_10C0.WasSlammedWithinTime(krFishTailTime)) {
        CGtV3d off = zero;
        off.SetZ(field_40->field_E80.Z());
        field_1920 = field_0;
        float t = field_10C0.field_C - field_10C0.field_4C8;
        float k = 1.0f - t / krFishTailTime;
        CGtMatrix3x4 rot;
        if (field_1914 == 0) {
            rot = CreateRotationMatrix3x4(up, 0.017453292f * (k * krFishTailAngle * sinf(0.017453292f * (t * krFishTailDegMulti))));
        } else {
            rot = CreateRotationMatrix3x4(up, 0.017453292f * (k * krAIFishTailAngle * sinf(0.017453292f * (t * krFishTailDegMulti))));
        }
        field_1920.mPos -= off;
        field_1920 = func_00151DC0_inl1(rot, field_1920);
        field_1920.mPos += off;
        float r = k * krRollAngle * sinf(0.017453292f * (t * krFishTailDegMulti));
        field_44 = sinf(r);
        field_48 = cosf(r);
        field_199B = 1;
    }
    if (field_10C0.field_4CC == 1 && field_10C0.SlammedSomeoneWithinTime(krShuntTime)) {
        float t = field_10C0.field_C - field_10C0.field_4BC;
        float k = 1.0f - t / krShuntTime;
        float p = k * krShuntPitchAngle * sinf(0.017453292f * (t * krShuntDegMulti));
        field_4C = sinf(p);
        field_50 = cosf(p);
    }
}
