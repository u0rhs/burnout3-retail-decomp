// NONMATCHING: CanStickySpeedMatch__24CB3AIAggressionBehaviourCFv -- retail 157 / ours 157 instructions, 39 in changed runs
// psweep: scoped #pragma opt_pulloutconstants off [G] improves 41 -> 39
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3AIAggressionBehaviour::CanStickySpeedMatch() const -- hand-written from the lifted draft (fresh2).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAggressionBehaviour.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G].
// Speeds as 2.236936331f * field_B0.W() (m/s -> mph [L], BRIEF near18; ConfirmGrinding's form).

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_pulloutconstants off

struct UnkStruct_0032F0D0_phys {
    unsigned char pad_0[0xB0];
    GtMathPs2::CGtV4d field_B0;
};

struct UnkStruct_D_0055EFEC {
    UnkStruct_0032F0D0_phys * field_0;
    unsigned char pad_4[0x2C];
};

struct UnkStruct_0032F0D0_e1 {
    unsigned char pad_0[0x2C];
    UnkStruct_0032F0D0_phys * field_2C;
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x3C960];
    UnkStruct_0032F0D0_e1 field_3C960[1];  // [G] element count unknown
};

struct UnkStruct_D_01E7559C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3Score {
public:
    bool WasSlammedWithinTime(float);
    float GetTotalRaceDistFromAILaneStart();
    unsigned char pad_0[0x1];
};

struct UnkStruct_0032F0D0_car {
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
    unsigned char pad_10C1[0x11D];
    unsigned char field_11DE;
    unsigned char pad_11DF[0x7CD];
    signed char field_19AC;
    unsigned char pad_19AD[0xA23];
    float field_23D0;
    unsigned char pad_23D4[0x4D];
    unsigned char field_2421;
    unsigned char pad_2422[0x12];
    float field_2434;
    unsigned char pad_2438[0x8];
    int field_2440;
};

class CB3AIAggressionBehaviour {
public:
    bool CanStickySpeedMatch() const;

    unsigned char pad_0[0x22];
    unsigned char field_22;
    unsigned char pad_23[0x15];
    float field_38;
    unsigned char pad_3C[0x8];
    UnkStruct_0032F0D0_car * field_44;
    UnkStruct_0032F0D0_car * field_48;
};

extern UnkStruct_D_0055EFEC D_0055EFEC[];
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_01E7559C D_01E7559C;
extern UnkStruct_D_01E7559C D_01E755A0;

// 0x0032F0D0
bool CB3AIAggressionBehaviour::CanStickySpeedMatch() const
{
    if (field_48 == 0) {
        return false;
    }
    if (field_44->field_2421 != 0) {
        return false;
    }
    if (field_44->field_10C0.WasSlammedWithinTime(3.0f)) {
        return false;
    }
    float m;
    if (field_44->field_2440 == 1) {
        m = 40.0f;
    } else {
        m = D_01E7559C.field_0;
    }
    float d0 = field_44->field_10C0.GetTotalRaceDistFromAILaneStart();
    float d1 = field_48->field_10C0.GetTotalRaceDistFromAILaneStart();
    if (!(GtMath::Abs(d0 - d1) <= 3.0f + field_44->field_23D0 * (m - 3.0f))) {
        return false;
    }
    if (field_22 == 0 && field_44->field_2440 != 1) {
        float a = D_0055EFEC[field_44->field_19AC].field_0->field_B0.W();
        float b = ((UnkStruct_0032F0D0_e1 *)((char *)&D_00522660 + 0x3C960))[field_48->field_19AC].field_2C->field_B0.W();
        if (!(GtMath::Abs(2.236936331f * a - 2.236936331f * b) <= D_01E755A0.field_0)) {
            return false;
        }
    }
    float lim = 100.0f;
    if (field_44->field_2440 == 1) {
        lim = 60.0f;
    }
    if (2.236936331f * (float)D_0055EFEC[field_48->field_19AC].field_0->field_B0.W() < lim) {  // [C] retail FPU form, not a VU lane op: 0x32F208 lwc1 / 0x32F20C mul.s (the cast keeps the port's PS2 float model)
        return false;
    }
    if (field_44->field_2440 == 0 && field_48->field_11DE != 0) {
        return false;
    }
    if (field_38 < 1.1f * field_44->field_2434) {
        return false;
    }
    return true;
}


#pragma pop
