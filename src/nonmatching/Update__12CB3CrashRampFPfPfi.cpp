// NONMATCHING: Update__12CB3CrashRampFPfPfi -- retail 104 / ours 104 instructions, 30 in changed runs
// ghvu4: logic right; scoped opt_dead_assignments off [G] gives retail's s-registers and keeps the two dead CGtV3d constants' stores (3,1.2,4)/(2.5,3,6), but retail also keeps their dead lq loads and has no zero-trip guard; frame 0x110 vs 0xB0 (pragma keeps extra slots). Without the pragma the constants vanish (91 instrs). Header gap?: retail's CGtV3d(float,float,float) leaves a dead lq
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_003A1D10_m { CGtMatrix3x4 field_0; int field_40; };
class CB3VehiclePhysics {
public:
    void ApplyCrashRamp(CGtMatrix3x4 *, CGtV3d *, bool);
    unsigned char pad_0[0x204];
    CGtMatrix3x4 * field_204;
};
struct UnkStruct_003A1D10_ent { CB3VehiclePhysics * field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x3C98C];
    UnkStruct_003A1D10_ent field_3C98C[4];
    unsigned char pad_3CA4C[0x125F68 - 0x3CA4C];
    int field_125F68[4];
};
extern UnkStruct_D_00522660 D_00522660;
extern float D_004E0E60;
class CB3CrashRamp {
public:
    void Update(float *, float *, int);
    CGtV3d field_0;
    unsigned char pad_10[0x50];
    UnkStruct_003A1D10_m * field_60;
};

// N182: [G] scoped to this function -- keeps the two dead vector constants' stores and loads
#pragma push
#pragma opt_dead_assignments off
// 0x003A1D10
void CB3CrashRamp::Update(float * p0, float * p1, int n)
{
    CGtV3d k0(3.0f, D_004E0E60, 4.0f);
    CGtV3d k1(2.5f, 3.0f, 6.0f);
    int i = 0;
    while (i < n) {
        float * best;
        if (i == 0) {
            best = p0;
        } else {
            best = p1;
        }
        UnkStruct_003A1D10_m * m = field_60;
        CB3VehiclePhysics * car = D_00522660.field_3C98C[i].field_0;
        float d = (car->field_204->mPos - m->field_0.mPos).GetLength();
        if (d < *best) {
            if (m->field_40 == 2) {
                car->ApplyCrashRamp(&m->field_0, &field_0, true);
            } else {
                car->ApplyCrashRamp(&m->field_0, &field_0, false);
            }
            D_00522660.field_125F68[i] = field_60->field_40;
            *best = d;
        }
        i++;
    }
}
#pragma pop
