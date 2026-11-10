// NONMATCHING: OnSlam__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb -- retail 225 / ours 225 instructions, 61 in changed runs
// near35: LOGIC FIX -- retail also stores p3 to s4->field_4CC (sb s0,0x4CC(s4) in the first GetSegmentSizeInBurn delay slot); .lit4 D_004E0D6C -> 2.236936331f. Now 225/225, pure saved-register rotation: retail p3/p1/p0 = s0/s1/s2 and scores s3/s4, ours scores s0/s1 and params s2-s4. Score refs, inline getter, decl/def order, car locals, CSE form tried; the N215 void* lever would need extern-C typed-param change (not done)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: OnSlam__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb -- retail 225 / ours 225 instructions, 66 in changed runs
// a204: lane3 via ((CGtV4d*)&f)->W() fixes frame (0xC0, 0x90 slot); left: saved-reg order (scores s1/s0 vs retail s4/s3) | classic-op fallback | guard: n/a (classic ops) | mwperm: 78 -> 69 ('s4->field_4CC = p3;' -> '')
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// NONMATCHING: OnSlam__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb -- retail 225 / ours 226 instructions, 76 in changed runs
// a137: 226 vs 225 instrs; logic/layout right. Left: saved-reg order (retail p3=s0,p1=s1,p0=s2, scores s3(c1)/s4(c0), type s5, flag s6; ours scores s0/s1 below the params), frame 0xC0 vs ours 0xB0 (retail has an extra 16-byte slot between the two vectors at 0x90/0xB0 and mul.s f1,f1,f2 operand order), the lq/sq of the lane-3 vector via an address register
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CB3RaceCar;
class CB3RaceCarPhysics;
struct UnkStruct_D_01E7A800 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004EE040_row {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(int, void *);
    unsigned char pad_x[0xBAC];
};
struct UnkStruct_D_004EE040_o { unsigned char pad_0[0x28E00]; UnkStruct_D_004EE040_row field_28E00[1]; };
struct UnkStruct_D_004E0D6C { float v; unsigned char pad[12]; };
typedef CGtV3d UnkStruct_V3;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern UnkStruct_D_004EE040_o D_004EE040;
extern UnkStruct_D_004E0D6C D_004E0D6C;
class CB3Score {
public:
    static bool OnSlam(CB3RaceCarPhysics * p0, CB3RaceCarPhysics * p1, float p2, bool p3);
    static int CalculateSlamType(CB3RaceCarPhysics *, CB3RaceCarPhysics *, float);
    static float gmrMaxSlamBurnValue;
    unsigned char pad_0[0xC];
    float field_C;
    unsigned char pad_10[0x94];
    int field_A4;
    unsigned char pad_A8[0x24];
    unsigned char field_CC[0x58];
    unsigned char field_124[0x21C];
    float field_340;
    unsigned char pad_344[0x174];
    float field_4B8;
    float field_4BC;
    int field_4C0;
    float field_4C4;
    float field_4C8;
    bool field_4CC;
    unsigned char pad_4CD[3];
    int field_4D0;
    unsigned char pad_4D4[0x118];
    CB3RaceCar * field_5EC;
    float field_5F0;
};
class CB3RaceCar {
public:
    unsigned char pad_0[0x30];
    u_long128 field_30;
    unsigned char pad_40[0x1080];
    CB3Score field_10C0;
};
class CB3RaceCarPhysics {
public:
    unsigned char pad_0[0xB0];
    u_long128 field_B0;
    unsigned char pad_C0[0x1334];
    CB3RaceCar * field_13F4;
};
extern "C" void Shunt__18CB3HUDSoundManagerFQ29GtMathPs26CGtV3dP17CB3RaceCarPhysicsP17CB3RaceCarPhysics(void *, UnkStruct_V3 *, CB3RaceCarPhysics *, CB3RaceCarPhysics *);
extern "C" void Slam__18CB3HUDSoundManagerFQ29GtMathPs26CGtV3dP17CB3RaceCarPhysicsP17CB3RaceCarPhysics(void *, UnkStruct_V3 *, CB3RaceCarPhysics *, CB3RaceCarPhysics *);
extern "C" void OnSlam__13CB3ScoreBonusFP10CB3RaceCar16EB3ScoreSlamTypeb(void *, CB3RaceCar *, void *, bool);
extern "C" float GetSegmentSizeInBurn__7CB3BurnFv(void *);
extern "C" void AddBurn__7CB3BurnFf(void *, float);
extern "C" void RemoveBurn__7CB3BurnFf(void *, float);
extern "C" void IncreaseAggression__8CB3AICarFf(void *, float);
extern "C" void DoAggressiveHornBlast__24CB3AIAggressionBehaviourF26EAggressiveHornBlashReason(void *, int);
static inline float a137_lane3(u_long128 q) { union { u_long128 q; float f[4]; } v; v.q = q; return v.f[3]; }
#define CAR_I(c, o) (*(int *)((char *)(c) + (o)))
#define CAR_B(c, o) (*(unsigned char *)((char *)(c) + (o)))
bool CB3Score::OnSlam(CB3RaceCarPhysics * p0, CB3RaceCarPhysics * p1, float p2, bool p3)
{
    CB3Score * s4 = &p0->field_13F4->field_10C0;
    CB3Score * s3 = &p1->field_13F4->field_10C0;
    UnkStruct_V3 pos(p0->field_13F4->field_30);
    if (CAR_I(p0->field_13F4, 0x1914) == 0) {
        if (p3) {
            D_004EE040.field_28E00[CAR_I(p0->field_13F4, 0x27C0)].vfunc_14(1, 0);
            Shunt__18CB3HUDSoundManagerFQ29GtMathPs26CGtV3dP17CB3RaceCarPhysicsP17CB3RaceCarPhysics(&D_01E7A800, &pos, p0, p1);
        } else {
            D_004EE040.field_28E00[CAR_I(p0->field_13F4, 0x27C0)].vfunc_14(4, (char *)p0 + 0x153C);
            Slam__18CB3HUDSoundManagerFQ29GtMathPs26CGtV3dP17CB3RaceCarPhysicsP17CB3RaceCarPhysics(&D_01E7A800, &pos, p0, p1);
        }
    }
    if (CAR_I(p1->field_13F4, 0x1914) == 0) {
        if (p3) {
            D_004EE040.field_28E00[CAR_I(p1->field_13F4, 0x27C0)].vfunc_14(2, 0);
            Shunt__18CB3HUDSoundManagerFQ29GtMathPs26CGtV3dP17CB3RaceCarPhysicsP17CB3RaceCarPhysics(&D_01E7A800, &pos, p0, p1);
        } else {
            D_004EE040.field_28E00[CAR_I(p1->field_13F4, 0x27C0)].vfunc_14(3, (char *)p0 + 0x153C);
            Slam__18CB3HUDSoundManagerFQ29GtMathPs26CGtV3dP17CB3RaceCarPhysicsP17CB3RaceCarPhysics(&D_01E7A800, &pos, p0, p1);
        }
    }
    float burn = gmrMaxSlamBurnValue;
    bool flag = false;
    if (CAR_B(p1->field_13F4, 0x18EB) != 0 || s3->field_C < 3.0f + s3->field_340 || 2.236936331f * (float)((CGtV4d*)&p1->field_B0)->W() < 70.0f) {
        flag = true;
    }
    int type = CalculateSlamType(p0, p1, p2);
    OnSlam__13CB3ScoreBonusFP10CB3RaceCar16EB3ScoreSlamTypeb(s4->field_124, p1->field_13F4, (void *)(type), flag);
    s4->field_A4++;
    s4->field_4B8 += burn;
    s4->field_4BC = s4->field_C;
    s4->field_4CC = p3;
    AddBurn__7CB3BurnFf(s4->field_CC, GetSegmentSizeInBurn__7CB3BurnFv(s4->field_CC));
    s4->field_4D0 = type;
    s4->field_5EC = p1->field_13F4;
    s4->field_5F0 = s4->field_C;
    s3->field_4C0++;
    s3->field_4C4 += burn;
    s3->field_4C8 = s3->field_C;
    s3->field_4CC = p3;
    RemoveBurn__7CB3BurnFf(s3->field_CC, GetSegmentSizeInBurn__7CB3BurnFv(s3->field_CC));
    s3->field_4D0 = type;
    s3->field_5EC = p0->field_13F4;
    s3->field_5F0 = s3->field_C;
    CB3RaceCar * c1 = p1->field_13F4;
    if (CAR_I(c1, 0x1914) == 1 && CAR_I(p0->field_13F4, 0x1914) == 0) {
        IncreaseAggression__8CB3AICarFf(c1, p2);
        DoAggressiveHornBlast__24CB3AIAggressionBehaviourF26EAggressiveHornBlashReason((char *)c1 + 0x1B60, 0);
    }
    if (CAR_I(p0->field_13F4, 0x1914) == 0) {
        CAR_B(p0->field_13F4, 0x1B84) = 1;
    }
    return true;
}
