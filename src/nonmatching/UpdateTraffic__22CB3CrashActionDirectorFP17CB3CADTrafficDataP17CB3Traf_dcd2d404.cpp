// NONMATCHING: UpdateTraffic__22CB3CrashActionDirectorFP17CB3CADTrafficDataP17CB3TrafficPhysicsf -- retail 669 / ours 688 instructions, 262 in changed runs
// draftAE C-first: 688/669, call sequence identical (acosf x2, FireAirRam x4 = func_001CC520); FPU/VU arithmetic counts agree (ratio as mul then add; one vmove from the header operator+); left: block layout (retail keeps the angle wrap / random blocks inline and moves the speed-up and ram blocks out of line: 33 mnemonic hunks), constant rematerialisation (lui/mtc1 +4), two compare senses, frame 0x2F0 vs 0x330
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm with Revenge STABS names (same algorithm, 632 vs 669 instrs): ram steering toward the target 1 s ahead (close/far rates, decay), speed-up toward krTargetSpeed with the velocity setter, linked-vehicle or own air ram, the on-ground timer and the sideways skid ram at 60..120 degrees; header NormaliseFast/CosAngleBetweenNormalisedVectors/CrossProduct/DotProduct/NormaliseGetLength/SetGtV3d/SetPlus, GtMath Abs/Min/Max

// UpdateTraffic__22CB3CrashActionDirectorFP17CB3CADTrafficDataP17CB3TrafficPhysicsf -- draftAE (0x1B1240, 0xA74) --
// CB3CrashActionDirector::UpdateTraffic(CB3CADTrafficData*, CB3TrafficPhysics*, float)
// Written from the retail asm; names after Revenge's STABS of the same function (B4CrashActionDirector.cpp, 632 instrs:
// lnWheel, lpMatrix, lbAllWheelsOnGround, lVelocity, lrSpeed, lrSpeedDiff, lrDist, lrAngle, lrRatio, lrRamMag, lrRamDirection,
// lbSteeringChanged, lrSidewaysSpeed, lrMagnitude and the function statics krMaxSteer / krSteerRate / krCloseSteerRate /
// krTargetSpeed, here retail's .sdata D_004E15AC.. [L]). [L] crash-mode traffic AI: a traffic car told to ram (field_4) steers
// toward the target's position one second ahead (steering eased by krSteerRate / krCloseSteerRate, decaying otherwise), speeds up
// toward krTargetSpeed and, once close or past it, fires an air ram (CB3VehiclePhysics::FireAirRam) on itself or on its linked
// vehicle; otherwise, after half a second on its wheels while sliding sideways, it may fire a sideways ram toward its skid.
// Types and field meanings [G] (instruction widths, use).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

extern "C" float func_0011E328(float);   // [L] acosf (LIBM wf_acos.o wrapper next to __ieee754_acosf 0x119C20)
extern float D_004E15AC;   // [L] krMaxSteer (10)
extern float D_004E15B0;   // [L] krSteerRate (0.5)
extern float D_004E15B4;   // [L] krCloseSteerRate (1)
extern float D_004E15B8;   // [L] krTargetSpeed (40)
extern float D_004E0C50;   // [G] 0.4

struct UnkStruct_001B1240_wheel { unsigned char pad_0[0xB3]; unsigned char field_B3; unsigned char pad_B4[0xC]; };   // [G] 0xC0 at +0x820
class CB3TrafficPhysics {
public:
    // [C] names: B3O0PCH map (CB3TrafficPhysics::GetLinkedVehicle() 0x1C, IsTrailer() 0x1C); bodies [G] (one field read each)
    CB3TrafficPhysics * GetLinkedVehicle() { return field_2424; }
    bool IsTrailer() { return field_2428; }

    unsigned char pad_0[0xB0];
    CGtV3dPlus field_B0;            // [G] velocity, w = speed
    CGtV3d field_C0;                // [G] unit velocity direction
    unsigned char pad_D0[0x134];
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[0x618];
    UnkStruct_001B1240_wheel field_820[4];
    unsigned char pad_B20[0x644];
    float field_1164;               // [G] steering
    unsigned char pad_1168;
    signed char field_1169;         // [G] wheel count
    unsigned char pad_116A;
    unsigned char field_116B;       // [G] driven by the AI (1)
    unsigned char pad_116C[0x12B8];
    CB3TrafficPhysics * field_2424;
    unsigned char field_2428;
};
// [C] name: research/retail_names.csv 0x1CC520 CB3VehiclePhysics::FireAirRam(unsigned int, float, bool)
extern "C" void func_001CC520(CB3TrafficPhysics *, unsigned int, float, bool);
struct CB3CADTrafficData {
    float field_0;                  // [G] time with all wheels on the ground
    CB3TrafficPhysics * field_4;    // [G] ram target
    unsigned char field_8;          // [G] skid ram fired
    unsigned char field_9;          // [G] air ram fired
};

class CB3CrashActionDirector {
public:
    void UpdateTraffic(CB3CADTrafficData * lpCADData, CB3TrafficPhysics * lpPhysics, float lrTimeStep);
    int field_0;                    // [G] random seeds (as UpdateRaceCar's archive)
    int field_4;
};

// [G] CGtV3dPlus::Plus() as a float (the speed; header gap queued with Update__17CB3VehiclePhysicsFf)
static inline float func_001B1240_plus(CB3TrafficPhysics * p) { return WAxisType(p->field_B0.mData); }
// [G] the director's random number (as UpdateRaceCar's func_001B20D0_rnd)
static inline float func_001B1240_rnd(CB3CrashActionDirector * self)
{
    self->field_0 = (self->field_0 << 16) + (self->field_0 >> 16);
    self->field_0 = self->field_0 + self->field_4;
    self->field_4 = self->field_4 + self->field_0;
    return (float)(unsigned int)self->field_0 * 2.3283064e-10f;
}
// [G] the signed angle (degrees, -180..180) from a to b about up
static inline float func_001B1240_inl1(CGtV3d a, CGtV3d b, CGtV3d up)
{
    a.NormaliseFast();
    b.NormaliseFast();
    float lrAngle = 57.29578f * func_0011E328(CosAngleBetweenNormalisedVectors(a, b));
    if (DotProduct(CrossProduct(a, b), up) < 0.0f)
        lrAngle = 360.0f - lrAngle;
    if (lrAngle > 180.0f)
        lrAngle -= 360.0f;
    return lrAngle;
}
// [G] set the body's velocity (as func_0023C520's archive): xyz, then the speed and unit direction (the matrix At when zero)
static inline void func_001B1240_inl2(CB3TrafficPhysics * p, CGtV3d v)
{
    p->field_B0.SetGtV3d(v);
    if (v.GetSquaredLength() < 2.3283064e-10f) {
        p->field_B0.SetPlus(0.0f);
        p->field_C0 = p->field_204->mAt;
    } else {
        p->field_C0 = v;
        p->field_B0.SetPlus(p->field_C0.NormaliseGetLength());
    }
}

void CB3CrashActionDirector::UpdateTraffic(CB3CADTrafficData * lpCADData, CB3TrafficPhysics * lpPhysics, float lrTimeStep)
{
    if (lpPhysics->IsTrailer())
        return;
    CGtMatrix3x4 * lpMatrix = lpPhysics->field_204;
    if (lpCADData->field_4 != 0 && lpPhysics->field_116B == 1) {
        CB3TrafficPhysics * lpTarget = lpCADData->field_4;
        CGtV3d lDiff = lpTarget->field_204->mPos + CGtV3d(lpTarget->field_B0.mData) * 1.0f - lpMatrix->mPos;
        float lrDist = DotProduct(lpMatrix->mAt, lDiff);
        float lrAngle = func_001B1240_inl1(lDiff, lpMatrix->mAt, lpMatrix->mUp);
        lrAngle = 0.0f + lrAngle + 10.0f * (func_001B1240_rnd(this) - 0.5f);
        bool lbSteeringChanged = false;
        if (lrDist < 15.0f) {
            if (lrAngle > 0.0f && lpPhysics->field_1164 < D_004E15AC) {
                lbSteeringChanged = true;
                lpPhysics->field_1164 = lpPhysics->field_1164 + D_004E15B4;
            } else if (lrAngle < 0.0f && !(lpPhysics->field_1164 <= -D_004E15AC)) {
                lbSteeringChanged = true;
                lpPhysics->field_1164 = lpPhysics->field_1164 - D_004E15B4;
            }
        } else if (!(GtMath::Abs(lrAngle) <= 10.0f)) {
            if (lrAngle > 0.0f && !(lpPhysics->field_1164 <= -D_004E15AC)) {
                lbSteeringChanged = true;
                lpPhysics->field_1164 = lpPhysics->field_1164 - D_004E15B0;
            } else if (lrAngle < 0.0f && lpPhysics->field_1164 < D_004E15AC) {
                lbSteeringChanged = true;
                lpPhysics->field_1164 = lpPhysics->field_1164 + D_004E15B0;
            }
        }
        if (!lbSteeringChanged)
            lpPhysics->field_1164 = lpPhysics->field_1164 * 0.95f;
        float lrRatio = (D_004E15AC - GtMath::Abs(lpPhysics->field_1164)) / D_004E15AC;
        lrRatio *= 0.5f;
        lrRatio += 0.5f;
        float lrSpeed = func_001B1240_plus(lpPhysics);
        if (lrSpeed < D_004E15B8) {
            float lrSpeedDiff = D_004E15B8 - lrSpeed;
            if (lrSpeedDiff > 0.5f * lrRatio)
                lrSpeedDiff = 0.5f * lrRatio;
            CGtV3d lVelocity = lpPhysics->field_C0 * (lrSpeed + lrSpeedDiff);
            func_001B1240_inl2(lpPhysics, lVelocity);
        }
        if (lpCADData->field_9)
            return;
        if (lpPhysics->GetLinkedVehicle() != 0) {
            if (!(lrDist < 15.0f))
                return;
            lpPhysics->field_116B = 0;
            lpCADData->field_4 = 0;
            float lrRamDirection = func_001B1240_rnd(this);
            float lrRamMag = D_004E0C50 * func_001B1240_rnd(this);
            if (lrRamDirection - 0.5f < 0.0f)
                lrRamMag *= -1.0f;
            func_001CC520(lpPhysics->GetLinkedVehicle(), 0x40, lrRamMag, false);
        } else {
            bool lbRam;
            if (!(GtMath::Abs(lrAngle) <= 75.0f))
                lbRam = true;
            else
                lbRam = lrDist < 15.0f;
            if (!lbRam)
                return;
            lpPhysics->field_116B = 0;
            lpCADData->field_4 = 0;
            float lrRamMag = func_001B1240_rnd(this) * 0.25f;
            if (!(lpPhysics->field_1164 <= 0.0f))
                lrRamMag *= -1.0f;
            func_001CC520(lpPhysics, 0x40, lrRamMag, false);
        }
        lpCADData->field_9 = 1;
        lpCADData->field_8 = 1;
        return;
    }

    bool lbAllWheelsOnGround = true;
    for (int lnWheel = 0; lnWheel < lpPhysics->field_1169; lnWheel++) {
        if (lpPhysics->field_820[lnWheel].field_B3 == 0)
            lbAllWheelsOnGround = false;
    }
    if (lbAllWheelsOnGround == true)
        lpCADData->field_0 = lpCADData->field_0 + lrTimeStep;
    else
        lpCADData->field_0 = 0.0f;
    if (lpCADData->field_8)
        return;
    if (!(lpCADData->field_0 > 0.5f))
        return;
    float lrSidewaysSpeed = GtMath::Abs(DotProduct(lpMatrix->mRight, CGtV3d(lpPhysics->field_B0.mData)));
    if (lrSidewaysSpeed <= 5.0f)
        return;
    float lrAngle = func_001B1240_inl1(CGtV3d(lpPhysics->field_B0.mData), lpMatrix->mAt, lpMatrix->mUp);
    float lrMagnitude = GtMath::Min(GtMath::Max(lrSidewaysSpeed / 20.0f, D_004E0C50), 1.0f);
    if (lrAngle > 60.0f && lrAngle < 120.0f) {
        func_001CC520(lpPhysics, 4, lrMagnitude, false);
        lpCADData->field_8 = 1;
        return;
    }
    if (lrAngle < -60.0f && lrAngle > -120.0f) {
        func_001CC520(lpPhysics, 8, lrMagnitude, false);
        lpCADData->field_8 = 1;
    }
}
