// NONMATCHING: ApplyDrivingForces__17CB3RaceCarPhysicsFf -- retail 1908 / ours 1907 instructions, 1512 in changed runs
// draftP: logic complete from asm+Ghidra; calls identical (layout order differs), every FPU/VU op count equal; residue = block placement (retail keeps the drag-test chain and the in-loop drift arm inline, ours moves them to the tail; retail moves the friction tail/yaw-torque cases out of line), N255-type frame (0x1540 vs 0xDD0), CreateRotationMatrix/op* row-load order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: every branch, call, store and VU op accounted for (op counts equal, call set identical); ApplyPositionedForce(lPoint, lForce) order from Revenge STABS

// CB3RaceCarPhysics::ApplyDrivingForces(float) -- hand-written by draftP from the retail asm + Ghidra draft.
// [C] name: the mangled symbol in retail's tables. Field names are placeholders and every type is [G] (instruction widths).
// Locals named after Revenge's UpdateCrashSteering STABS (draftN's archive) where the per-wheel friction code is the same [L].
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;


extern "C" float sqrtf(float);
extern "C" float sinf(float);
extern "C" int strcmp(const char *, const char *);
extern "C" void func_0021AB40(unsigned long, char *);   // [L] GtIDConvertToString(unsigned long, char*) (retail_names.csv, high)
extern const CGtV3d kGravity;                            // [C] config name (B3PhysicsConstants.cpp)
struct UnkStruct_D_00522680 { float field_0; float field_4[3]; };   // [G] field_0 = the game clock (seconds); B3RaceCarPhysics.cpp's type
extern UnkStruct_D_00522680 D_00522680;

struct UnkStruct_001C1B20_mode {     // [G] *(gGame+0x2DA48)
    unsigned char pad_0[0x1B4];
    void *field_1B4;                 // [G] current sub-mode, compared with two objects embedded in gGame
};
// [L] D_004EE040 = gGame (config comment: conflict) -- placeholder kept.
struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x2D6D4];
    unsigned char field_2D6D4[0x74];
    unsigned char field_2D748[0x300];
    UnkStruct_001C1B20_mode *field_2DA48;
};
extern UnkStruct_D_004EE040 D_004EE040;
struct UnkStruct_D_01E32AE0 {        // [L] the network manager instance (B3NetworkManager.cpp)
    unsigned char pad_0[0x329B9];
    unsigned char field_329B9;
};
extern UnkStruct_D_01E32AE0 D_01E32AE0;

struct UnkStruct_001C1B20_car {      // [G] field_13F4: the owning CB3RaceCar
    unsigned char pad_0[0x1340];
    float field_1340;                // [G] time of the last ... (compared with D_00522680)
    unsigned char pad_1344[0x1960 - 0x1344];
    unsigned long field_1960;        // [G] vehicle GtID (GtIDConvertToString -> "HEVYCAR9" / "HEVYCAR36")
};
struct UnkStruct_001C1B20_wheel {    // [G] 0xC0 stride, base veh+0x820 (as UpdateCrashSteering's archive)
    unsigned char pad_0[0x50];
    float field_50;                  // [G] wheel radius
    float field_54;                  // [G] drive torque accumulator
    unsigned char pad_58[4];
    float field_5C;                  // [G] wheel spin rate
    unsigned char pad_60[0x14];
    float field_74;
    unsigned char pad_78[0x3B];
    unsigned char field_B3;          // [G] on the ground
    unsigned char pad_B4[0xC];
    void func_001C1B20_inl7(float t) { field_54 += t; }   // [G] inlined torque add (retail mul.s + add.s, not madd)
};

// [G] CGtV3d::operator+(const CGtV3d&) on compiler-chosen registers: retail's 7 sites in this function add in place
// (`vadd.xyz $vfA, $vfA, $vfB`), not the header's fixed $vf1/$vf2 form -> header queue
static inline CGtV3d func_001C1B20_inl10(const CGtV3d& a, const CGtV3d& b)
{
    u_long128 r;
    asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}

// [L] base class: Revenge's inlined CB4CollidingBody methods run on the vehicle's own `this` register (STABS).
class CB3CollidingBody {
public:
    unsigned char pad_0[0xB0];
    CGtV3d field_B0;                  // [G] linear velocity, w = speed
    CGtV3d field_C0;                  // [G] forward direction of travel
    CGtV3d field_D0;                  // [G] angular velocity
    CGtV3d field_E0;                  // [G] angular momentum
    CGtV3d field_F0;                  // [G] force accumulator
    CGtV3d field_100;                 // [G] torque accumulator
    unsigned char pad_110[0xC0];
    CGtV3d field_1D0;                 // [G] box half extents
    CGtV3d field_1E0;
    float field_1F0;                  // [G] mass
    unsigned char pad_1F4[0x10];
    CGtMatrix3x4 *field_204;
    unsigned char pad_208[0x18];

    // [L] E map names (B3O0PCH: CB3CollidingBody::ApplyPositionedForce(CGtV3d, CGtV3d), GetPointVelocity(CGtV3d),
    // LocalPointToWorldPoint(CGtV3d)); bodies [G] from retail's inlined copies (as in UpdateCrashSteering's archive).
    // [G] the speed lane of field_B0 (CGtV4d::W() on the velocity; LightweightUpdate's archive reads it the same way)
    WAxisType func_001C1B20_inl3() const { return ((const CGtV4d *)&field_B0)->W(); }
    void ApplyPositionedForce(CGtV3d lPoint, CGtV3d lForce) {
        field_F0 += lForce;
        field_100 += CrossProduct(lPoint - field_204->mPos, lForce);
    }
    CGtV3d LocalPointToWorldPoint(CGtV3d p) { return TransformPoint(*field_204, p); }
    CGtV3d GetPointVelocity(CGtV3d pos) {
        return func_001C1B20_inl10(CrossProduct(field_D0, pos - field_204->mPos), field_B0);
    }
};

// [L] CB3RaceCarPhysics derives from CB3VehiclePhysics (E map); flattened here so the 0x1168.. bytes keep retail's offsets
class CB3RaceCarPhysics : public CB3CollidingBody {
public:
    void ApplyDrivingForces(float lrTimeStep);
    void ApplyLowSpeedDrivingForces(float lrTimeStep);

    unsigned char pad_220[0x820 - 0x220];
    UnkStruct_001C1B20_wheel field_820[6];
    unsigned char pad_CA0[0xCC8 - 0xCA0];
    CGtMatrix3x4 *field_CC8[4];       // [G] per-wheel local frames (mPos = mount point)
    unsigned char pad_CD8[0x1164 - 0xCD8];
    float field_1164;                 // [G] steering angle, degrees
    unsigned char field_1168;         // [G] airborne
    signed char field_1169;           // [G] wheel count

    unsigned char pad_116A[0x1360 - 0x116A];
    float field_1360;                 // [G] drag coefficient
    float field_1364;
    float field_1368;                 // [G] drive force height
    float field_136C;                 // [G] road force height (longitudinal)
    float field_1370;                 // [G] road force height (lateral)
    float field_1374;                 // [G] road force height (lateral, drifting)
    unsigned char pad_1378[0x138C - 0x1378];
    float field_138C;                 // [G] brake force
    float field_1390;
    unsigned char pad_1394[4];
    float field_1398;                 // [G] max yaw rate at 60 mph
    float field_139C;                 // [G] max yaw rate at 110 mph
    unsigned char pad_13A0[4];
    float field_13A4;                 // [G] drift steering torque scale
    unsigned char pad_13A8[4];
    float field_13AC;                 // [G] low-speed threshold (mph)
    unsigned char pad_13B0[0x13C0 - 0x13B0];
    float field_13C0;                 // [G] steering drag
    unsigned char pad_13C4[0x13CC - 0x13C4];
    float field_13CC;                 // [G] engine force
    float field_13D0;
    float field_13D4;                 // [G] speed (mph)
    float field_13D8;                 // [G] airborne roll damping
    float field_13DC;                 // [G] drift entry lateral threshold
    unsigned char pad_13E0[0x13F4 - 0x13E0];
    UnkStruct_001C1B20_car *field_13F4;
    unsigned char pad_13F8[0x1400 - 0x13F8];
    float field_1400;                 // [G] brake input
    float field_1404;                 // [G] reverse input
    float field_1408;                 // [G] steering input
    unsigned char pad_140C[0x1414 - 0x140C];
    float field_1414;
    unsigned char pad_1418[0x142C - 0x1418];
    float field_142C;                 // [G] drift time
    float field_1430;
    unsigned char pad_1434[0x143C - 0x1434];
    float field_143C;                 // [G] airborne time
    float field_1440;                 // [G] drift amount
    unsigned char field_1444;
    unsigned char field_1445;         // [G] airborne last frame
    unsigned char field_1446;
    unsigned char pad_1447[0x1470 - 0x1447];
    float field_1470;
    unsigned char pad_1474[0x149C - 0x1474];
    float field_149C;                 // [G] engine rad/s
    unsigned char pad_14A0[8];
    int field_14A8;
    unsigned char pad_14AC[0x14C8 - 0x14AC];
    int field_14C8;                   // [G] gear
    int field_14CC;
    unsigned char pad_14D0[0x14E0 - 0x14D0];
    CGtMatrix3x4 field_14E0;          // [G] front-wheel frame (body matrix turned by the steering angle)
    float field_1520;
    int field_1524;                   // [G] drift state: 0 none, 1 left, 2 right
    unsigned char pad_1528[0x153D - 0x1528];
    unsigned char field_153D;
};


// [G] retail keeps the tests of an if whose body is empty (an emptied debug hook)
static inline void func_001C1B20_inl4() {}

struct UnkStruct_001C1B20_spring {   // [G] airborne self-righting probe: local point, local direction, stiffness
    CGtV3d mPos;
    CGtV3d mDir;
    float mK;
};

// 0x001C1B20
void CB3RaceCarPhysics::ApplyDrivingForces(float lrTimeStep)
{
    char lacName[16];                 // [G] GtIDConvertToString buffer (sp+0x1530, the top slot)
    CGtV3d lTotalLatForce(0.0f, 0.0f, 0.0f);
    float lrOne = 1.0f;
    CGtV3d lYAxis(0.0f, lrOne, 0.0f);
    CGtMatrix3x4 lMatrix = *field_204;
    CGtV3d lRight = lMatrix.mRight;
    CGtV3d lUp = lMatrix.mUp;
    CGtV3d lAt = lMatrix.mAt;
    bool lbLeft = field_820[0].field_B3 != 0 || field_820[2].field_B3 != 0;
    bool lbRight = field_820[1].field_B3 != 0 || field_820[3].field_B3 != 0;
    bool lbReversing = DotProduct(lAt, field_B0) < 0.0f;
    float lrSpeedMPH = func_001C1B20_inl3() * 2.2374146f;
    float lrSideSlip = DotProduct(field_C0, lRight);

    field_1445 = field_1168;
    if (field_820[0].field_B3 == 0 && field_820[1].field_B3 == 0 && field_820[2].field_B3 == 0 && field_820[3].field_B3 == 0) {
        if (field_1168 == 0) field_143C = 0.0f;
        field_1168 = 1;
        field_143C += lrTimeStep;
        field_14A8 = 1;
    } else {
        if (field_1168 == 1) {
            field_14A8 = 0;
            if (field_143C > 0.1f) {
                if (lrSideSlip > field_13DC) {
                    if (field_1524 == 0) {
                        field_142C = 0.0f;
                        field_1430 = field_1390;
                    }
                    field_1524 = 2;
                } else if (lrSideSlip < -field_13DC) {
                    if (field_1524 == 0) {
                        field_142C = 0.0f;
                        field_1430 = field_1390;
                    }
                    field_1524 = 1;
                }
            }
        }
        field_1168 = 0;
    }

    float lrSteerDrag;
    if (field_1524 == 0 && field_153D == 0)
        lrSteerDrag = func_001C1B20_inl3() * (field_1408 * field_1408) * field_13C0;
    else
        lrSteerDrag = 0.0f;
    CGtV3d lDrag;
    if ((field_1444 != 0 || field_1446 != 0) && func_001C1B20_inl3() < 0.44704f * field_13D4
        && ((field_14C8 == field_14CC) != 0 || 9.549296379f * field_149C < field_1470))
        lDrag.Zero();
    else
        lDrag = field_B0 * (-func_001C1B20_inl3() * field_1360 - lrSteerDrag);
    field_F0 += lDrag;

    if (field_1168 == 0) {
        if (field_1446 != 0 || (lrSpeedMPH >= field_13AC && field_14C8 != -1)) {
            // [G] retail evaluates (w0 || w2) && w1 and discards it (a debug macro remnant?); an expression statement keeps it
            (void)((field_820[0].field_B3 != 0 || field_820[2].field_B3 != 0) && field_820[1].field_B3 != 0);
            field_820[2].func_001C1B20_inl7(0.5f * field_1520);
            field_820[3].func_001C1B20_inl7(0.5f * field_1520);
            CGtV3d lPoint = func_001C1B20_inl10(lUp * field_1368, field_204->mPos);
            float lrThrottle;
            if (field_1524 == 2 || field_1524 == 1 || field_1400 > 0.1f)
                lrThrottle = 0.0f;
            else
                lrThrottle = lrOne;
            float lrDrive = (func_001C1B20_inl3() + 1.0f) * (-20000 * (field_138C * field_1404) + lrThrottle * field_13CC);
            lrDrive /= 70.0f;
            if (field_1524 == 1 || field_1524 == 2) {
                if (field_142C < 0.3f) lrDrive = 0.0f;
                lPoint = field_204->mPos;
            }
            ApplyPositionedForce(lPoint, field_C0 * lrDrive);

            field_14E0 = lMatrix;
            CGtMatrix3x4 lRotationMatrix;
            lRotationMatrix = CreateRotationMatrix3x4(lYAxis, 0.017453292f * field_1164);
            field_14E0 = lRotationMatrix * field_14E0;

            CGtV3d lOldTorque = field_100;
            for (int lnWheel = 0; lnWheel < 4; lnWheel++) {
                float lrWeightPerWheel = 0.25f * (20.0f * field_1F0);
                CGtV3d p = field_CC8[lnWheel]->mPos;
                p.SetY(field_820[lnWheel].field_74);
                CGtV3d lContact = LocalPointToWorldPoint(p);
                CGtV3d lPointVel = GetPointVelocity(lContact);
                CGtV3d lWheelAt;
                CGtV3d lWheelRight;
                if (lnWheel < 2) {
                    lWheelAt = field_14E0.mAt;
                    lWheelRight = field_14E0.mRight;
                } else {
                    lWheelAt = lAt;
                    lWheelRight = lRight;
                }
                float lrWheelLatSpeed = DotProduct(lWheelRight, lPointVel);
                float lrWheelFwdSpeed = DotProduct(lWheelAt, lPointVel);
                float lrTreadSpeed = field_820[lnWheel].field_5C * field_820[lnWheel].field_50;
                if (lnWheel < 2)
                    field_820[lnWheel].field_5C = lrWheelFwdSpeed / field_820[lnWheel].field_50;
                float lrSlipSpeedLong = lrWheelFwdSpeed - lrTreadSpeed;
                float lrSlipSpeed = sqrtf(lrWheelLatSpeed * lrWheelLatSpeed + lrSlipSpeedLong * lrSlipSpeedLong);
                if (lrTreadSpeed == 0.0f) lrTreadSpeed = 1e-06f;
                if (lrSlipSpeed == 0.0f) lrSlipSpeed = 1e-07f;
                float lrK;
                float lrDynamicCoeff;
                float lrStaticCoeff;
                if (lnWheel < 2) {
                    lrK = 60.0f;
                    lrStaticCoeff = 150000;
                    lrDynamicCoeff = 2.3f + 2.5f * (lrOne - field_1400);
                } else {
                    lrK = 12.0f;
                    float s = func_001C1B20_inl3() * 0.025f;
                    if (s < 0.5f) s = 0.5f;
                    if (s > lrOne) s = lrOne;
                    lrStaticCoeff = 500000 * s;
                    lrDynamicCoeff = (6.0f + 7.0f * (lrOne - field_1400)) * s;
                }
                float lrClamped = GtMath::Abs(lrStaticCoeff * lrSlipSpeed / (lrTreadSpeed * (lrWeightPerWheel * lrK)));
                if (lrClamped > lrOne) lrClamped = lrOne;
                float lrAngle = 0.4f - 0.8f * lrClamped;
                float lrSin = sinf(lrAngle);
                float lrCurve = (0.38941833f - lrSin) + 0.92106098f * (lrAngle - 0.4f);
                float lrTotalForce = -(lrCurve * (lrDynamicCoeff * (23.816387f * lrWeightPerWheel))
                                       + 0.5f * (lrStaticCoeff * (lrSlipSpeed * ((lrAngle - -0.4f) / lrTreadSpeed))));
                float lrLatForceFromRoad = lrTotalForce * lrWheelLatSpeed / lrSlipSpeed;
                float lrLongForceFromRoad = lrTotalForce * lrSlipSpeedLong / lrSlipSpeed;
                if (field_1446 != 0 && lrLongForceFromRoad > 0.0f) {
                    bool lb = false;
                    if (D_01E32AE0.field_329B9 != 0) {
                        void *m = D_004EE040.field_2DA48->field_1B4;
                        if (m != 0 && (m == D_004EE040.field_2D6D4 || m == D_004EE040.field_2D748)) lb = true;
                    }
                    if (lb)
                        lrLongForceFromRoad *= 4.0f;
                    else
                        lrLongForceFromRoad *= 8.0f;
                    func_0021AB40(field_13F4->field_1960, lacName);
                    if (strcmp(lacName, "HEVYCAR9") == 0 || strcmp(lacName, "HEVYCAR36") == 0) {
                        if (D_00522680.field_0 - field_13F4->field_1340 < 0.2f)
                            field_E0 -= field_204->mUp * DotProduct(field_204->mUp, field_E0);
                    }
                }
                field_820[lnWheel].field_54 += -lrLongForceFromRoad * field_820[lnWheel].field_50;
                field_820[lnWheel].field_5C += lrTimeStep * (field_820[lnWheel].field_54 / 25.0f);
                field_820[lnWheel].field_54 = 0.0f;
                if ((unsigned)(field_1524 - 1) < 2) {
                    CGtV3d lLatForce = lWheelRight * lrLatForceFromRoad;
                    float lrDot = DotProduct(field_C0, lAt);
                    float lrDrift = (4200 + 6400.0f * lrDot) * (lrOne - field_1440 / 1.5f);
                    if (lrLatForceFromRoad > 0.0f) {
                    } else
                        lrDrift = -lrDrift;
                    if (field_142C < lrOne) lrDrift *= field_142C;
                    CGtV3d lForce = func_001C1B20_inl10(lWheelRight * (lrDrift * field_1440), lLatForce * (lrOne - field_1440));
                    CGtV3d lOffset;
                    lOffset.SetX(0.0f);
                    lOffset.SetY(0.0f);
                    lOffset.SetZ(0.0f);
                    if (lnWheel < 2) {
                        if ((field_820[0].field_B3 != 0 || field_820[1].field_B3 != 0) && lbLeft && lbRight)
                            lOffset = lUp * field_1374;
                    } else if (field_820[lnWheel].field_B3 != 0 && lbLeft && lbRight) {
                        lOffset = lUp * field_1374;
                    }
                    ApplyPositionedForce(func_001C1B20_inl10(lOffset, lContact), lForce);
                    lTotalLatForce += lForce;
                } else {
                    CGtV3d lForce = lWheelRight * lrLatForceFromRoad;
                    CGtV3d lOffset;
                    lOffset.SetX(0.0f);
                    lOffset.SetY(0.0f);
                    lOffset.SetZ(0.0f);
                    if (lnWheel < 2) {
                        if (field_820[0].field_B3 != 0 || field_820[1].field_B3 != 0)
                            lOffset = lUp * field_1370;
                    } else if (field_820[lnWheel].field_B3 != 0) {
                        lOffset = lUp * field_1370;
                    }
                    ApplyPositionedForce(func_001C1B20_inl10(lOffset, lContact), lForce);
                    lTotalLatForce += lForce;
                }
                CGtV3d lLongForce = lWheelAt * lrLongForceFromRoad;
                lPoint = func_001C1B20_inl10(field_204->mPos, lUp * field_136C);
                if (field_1446 == 0)
                    ApplyPositionedForce(lPoint, lLongForce);
                else
                    field_F0 += lLongForce;
            }
            if (field_1169 > 4) {
                field_820[4].field_5C = field_820[2].field_5C;
                field_820[5].field_5C = field_820[3].field_5C;
            }

            float lrSlip = DotProduct(field_C0, lRight);
            if ((field_1524 == 1 || field_1524 == 2) && field_142C > 0.5f) {
                if (field_1524 == 1) {
                    if (lrSlip >= -0.01f && field_1408 >= -0.005f) field_1524 = 0;
                } else if (lrSlip <= 0.01f && field_1408 <= 0.005f) {
                    field_1524 = 0;
                }
            }
            if ((field_1524 == 1 || field_1524 == 2) && field_1400 < 0.5f && field_1404 < 0.5f && field_1408 == 0.0f
                && lrSpeedMPH < 40.0f)
                field_1524 = 0;

            CGtV3d lTorque = field_100 - lOldTorque;
            XAxisType lYawTorque = DotProduct(lTorque, lUp);
            float lrYawTorque = lYawTorque;
            CGtV3d lOtherTorque = lTorque - lUp * lYawTorque;
            float lrYawRate = DotProduct(field_E0, lUp);
            if (field_1524 == 2) {
                if (field_1408 < -0.05f)
                    lrYawTorque = (lrOne - 0.75f * field_1440) * (field_13A4 * (10000 * (-field_1408 * GtMath::Abs(field_1408))));
                else if (lrSlip < field_13D0) {
                    if (field_1408 > 0.05f)
                        lrYawTorque = (lrOne - 0.75f * field_1440) * (field_13A4 * (5000 * (-field_1408 * GtMath::Abs(field_1408))));
                    else
                        lrYawTorque = 1000.0f * field_1414;
                } else
                    lrYawTorque = 1000.0f;
            } else if (field_1524 == 1) {
                if (field_1408 > 0.05f)
                    lrYawTorque = (lrOne - 0.75f * field_1440) * (field_13A4 * (10000 * (-field_1408 * GtMath::Abs(field_1408))));
                else if (lrSlip > -field_13D0) {
                    if (field_1408 < -0.05f)
                        lrYawTorque = (lrOne - 0.75f * field_1440) * (field_13A4 * (5000 * (-field_1408 * GtMath::Abs(field_1408))));
                    else
                        lrYawTorque = -1000.0f * field_1414;
                } else
                    lrYawTorque = -1000.0f;
            }
            float lrMaxYawRate;
            if (lrSpeedMPH < 60.0f)
                lrMaxYawRate = 800.0f;
            else if (lrSpeedMPH < 110.0f) {
                float t = (lrSpeedMPH - 60.0f) / 50.0f;
                lrMaxYawRate = field_139C * (lrOne - t) + field_1398 * t;
            } else
                lrMaxYawRate = field_139C;
            if (field_142C < 0.25f) lrMaxYawRate *= 0.75f + field_142C;
            if (lrSlip > 0.0f) {
                if (lrYawTorque > 0.0f && lrYawRate > lrMaxYawRate) lrYawTorque *= 0.1f;
                if (lrYawTorque < 0.0f && lrYawRate < -lrMaxYawRate) lrYawTorque *= 0.1f;
            } else {
                if (lrYawTorque > 0.0f && lrYawRate > lrMaxYawRate) lrYawTorque *= 0.1f;
                if (lrYawTorque < 0.0f && lrYawRate < -lrMaxYawRate) lrYawTorque *= 0.1f;
            }
            field_100 = func_001C1B20_inl10(lOldTorque, func_001C1B20_inl10(lOtherTorque, lUp * lrYawTorque));

            CGtV3d lSide = CrossProduct(lUp, field_C0);
            float lrLat = DotProduct(lTotalLatForce, field_C0);
            if (lrLat < 0.0f && (field_1524 == 1 || field_1524 == 2) && field_1400 > 0.1f) {
                CGtV3d lCounter = lSide * lrLat;
                field_F0 += field_C0 * -lrLat;
                if (DotProduct(field_C0, lRight) < 0.0f) lCounter = lCounter * -1.0f;
                field_F0 += lCounter;
            }
        } else {
            ApplyLowSpeedDrivingForces(lrTimeStep);
        }
        if (func_001C1B20_inl3() > lrOne && field_204->mAt.Y() > 0.0f) {
            field_F0 -= kGravity * field_1F0;
            field_F0 += lUp * (-20.0f * field_1F0);
        }
    } else {
        UnkStruct_001C1B20_spring laSprings[4];
        laSprings[0].mPos.SetX(0.0f);
        laSprings[0].mPos.SetY(0.0f);
        laSprings[0].mPos.SetZ((float)field_1D0.Z() / 2.0f);
        laSprings[0].mDir.SetX(0.0f);
        laSprings[0].mDir.SetY(1.0f);
        laSprings[0].mDir.SetZ(0.0f);
        laSprings[0].mK = 1000.0f;
        laSprings[1].mPos.SetX(0.0f);
        laSprings[1].mPos.SetY(0.0f);
        laSprings[1].mPos.SetZ((float)field_1D0.Z() / 2.0f);
        laSprings[1].mDir.SetX(1.0f);
        laSprings[1].mDir.SetY(0.0f);
        laSprings[1].mDir.SetZ(0.0f);
        laSprings[1].mK = 10.0f;
        laSprings[2].mPos.SetX(0.0f);
        laSprings[2].mPos.SetY(0.0f);
        laSprings[2].mPos.SetZ(2.0f * (float)field_1E0.Z());
        laSprings[2].mDir.SetX(0.0f);
        laSprings[2].mDir.SetY(1.0f);
        laSprings[2].mDir.SetZ(0.0f);
        laSprings[2].mK = 1000.0f;
        laSprings[3].mPos.SetX(0.0f);
        laSprings[3].mPos.SetY(0.0f);
        laSprings[3].mPos.SetZ(2.0f * (float)field_1E0.Z());
        laSprings[3].mDir.SetX(1.0f);
        laSprings[3].mDir.SetY(0.0f);
        laSprings[3].mDir.SetZ(0.0f);
        laSprings[3].mK = 10.0f;
        int i = 0;
        do {
            CGtV3d lWorld;
            if (lbReversing) {
                CGtV3d p = laSprings[i].mPos;
                p.SetZ(p.Z() * -1.0f);
                lWorld = LocalPointToWorldPoint(p);
            } else {
                lWorld = LocalPointToWorldPoint(laSprings[i].mPos);
            }
            CGtV3d lDir = TransformVector(*field_204, laSprings[i].mDir);
            float lrSpeed = DotProduct(lDir, GetPointVelocity(lWorld));
            CGtV3d lForce = lDir * (-lrSpeed * laSprings[i].mK);
            ApplyPositionedForce(lWorld, lForce);
            i++;
        } while (i < 4);
        field_E0 -= field_204->mAt * DotProduct(field_204->mAt, field_E0) * field_13D8;
        CGtV3d lLift;
        lLift.SetX(0.0f);
        lLift.SetY(field_1F0 * -(10.0f + lrSpeedMPH * (10.0f * field_1364) / 100.0f));
        lLift.SetZ(0.0f);
        field_F0 += lLift;
        field_820[2].field_54 += 0.5f * field_1520;
        field_820[3].field_54 += 0.5f * field_1520;
        for (int n = 0; n < field_1169; n++) {
            field_820[n].field_5C += lrTimeStep * (field_820[n].field_54 / 25.0f);
            field_820[n].field_54 = 0.0f;
        }
    }
}
