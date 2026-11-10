// NONMATCHING: CollisionIsCameraInVehicle__14CB3CameraUtilsFQ29GtMathPs26CGtV3di -- retail 550 / ours 571 instructions, 763 in changed runs
// draftAL C-first: crash-list traffic (player crashing, same crash index), all traffic, the player's race cars: sphere (+1.5) pre-test, then the E-map 4-argument overload inlined (camera in local space within the box grown by 1.5); 571/550, no calls (as retail); left: b119p threads the materialized bool chain into branches (&&, b = b && c and if (b) b = c forms compile identically), frame 0x5E0 vs 0x670
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; each list's base/stride/count offset, the crash-index compare, the six box comparisons (>= lower - 1.5 via c.lt/bc1f, <= upper + 1.5 via c.le/bc1t), the race-car Invert and radius 1.5 + field_14 traced; Revenge STABS names

// CB3CameraUtils::CollisionIsCameraInVehicle(CGtV3d, int) -- draftAL (C-first draft). 0x2F7390, 0x898.
// [C] name: the mangled symbol in retail's tables. Written from the retail asm (no calls: everything inlined). Parameter and
// local names from the Revenge STABS of CB4CameraUtils::CollisionIsCameraInVehicle(CGtV3d, EPlayerCarIndex) (lCamera,
// lBBox, lInverseMatrix, lpPhysics, lu8PlayerCrashIndex, lpBody, lnIndex) and of its 4-argument overload (lCamera, lBBox,
// lMatrix, lInverseMatrix, lrAdjust). [C] the 4-argument overload exists in B3 too: E map (research tables, 0x321520,
// "CollisionIsCameraInVehicle(CGtV3d, const CGtAxisAlignedBox&, const CGtMatrix3x4&, const GtMa..." -- the 4th type truncated;
// [L] const CGtMatrix3x4& by Revenge's `T3`); retail inlines it three times.
// What it does [L]: is the camera inside (within 1.5 of) any vehicle's box? Tested, each first against the bounding sphere
// grown by 1.5, then in the vehicle's local space against its box grown by 1.5:
//  1. while the player car is crashing (+0x210), the traffic in the crash list (D_00522660 +0x122A10, count +0x122B1C) with the
//     player's crash index (+0x218);
//  2. all traffic (D_00522660 +0x3C98C, 0x30 per entry, count +0x12AD1C);
//  3. the race cars in the player's list (D_00527440: counts +0x36350[player], car indices +0x35C24[player][254], cars
//     +0x127D0 x 0x180), whose inverse matrix is computed here.
// Types and field meanings [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

class CGtAxisAlignedBox {                   // [C] name: the overload's parameter type (E map, Revenge)
public:
    CGtV3d field_0;                         // upper corner
    CGtV3d field_10;                        // lower corner
};
struct UnkStruct_002F7390_body {            // [L] CB3CollidingBody (traffic physics / the player car physics)
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;                  // inverse world matrix
    unsigned char pad_B0[0x110];
    CGtV4d field_1C0;                       // bounding sphere (w = radius)
    CGtAxisAlignedBox field_1D0;            // local box
    unsigned char pad_1F0[0x14];
    CGtMatrix3x4 * field_204;               // world matrix
    unsigned char pad_208[0x8];
    unsigned char field_210;                // crashing
    unsigned char pad_211[0x7];
    signed char field_218;                  // crash index
};
struct UnkStruct_002F7390_pc { UnkStruct_002F7390_body * field_0; unsigned char pad_4[0x2C]; };   // per player, 0x30
extern UnkStruct_002F7390_pc D_0055EFEC[];
struct UnkStruct_002F7390_rcp { unsigned char pad_0[0x14]; float field_14; unsigned char pad_18[0xE68]; CGtAxisAlignedBox field_E80; };
struct UnkStruct_002F7390_rc {              // race car, 0x180
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;                  // world matrix
    UnkStruct_002F7390_rcp * field_B0;      // radius +0x14, local box +0xE80
    unsigned char pad_B4[0xCC];
};
extern unsigned char D_00522660[];          // [G] the traffic system
extern unsigned char D_00527440[];          // [G] the race car manager

class CB3CameraUtils {
public:
    static bool CollisionIsCameraInVehicle(CGtV3d, int);
    static bool CollisionIsCameraInVehicle(CGtV3d, const CGtAxisAlignedBox &, const CGtMatrix3x4 &, const CGtMatrix3x4 &);
};

// [L] body: the camera in the vehicle's space within the box grown by lrAdjust; lMatrix is not read (retail's inlined copies)
inline bool CB3CameraUtils::CollisionIsCameraInVehicle(CGtV3d lCamera, const CGtAxisAlignedBox & lBBox, const CGtMatrix3x4 & lMatrix,
                                                       const CGtMatrix3x4 & lInverseMatrix)
{
    float lrAdjust = 1.5f;
    CGtV3d p = TransformPoint(lInverseMatrix, lCamera);
    return p.X() >= lBBox.field_10.X() - lrAdjust && p.Y() >= lBBox.field_10.Y() - lrAdjust && p.Z() >= lBBox.field_10.Z() - lrAdjust &&
           p.X() <= lBBox.field_0.X() + lrAdjust && p.Y() <= lBBox.field_0.Y() + lrAdjust && p.Z() <= lBBox.field_0.Z() + lrAdjust;
}
// [G] the bounding-sphere pre-test (radius + 1.5 on the w lane)
static inline bool func_002F7390_inl1(const UnkStruct_002F7390_body * lpBody, CGtV3d lCamera)
{
    float r = lpBody->field_1C0.W() + 1.5f;
    return (lpBody->field_204->mPos - lCamera).GetSquaredLength() <= r * r;
}

// 0x002F7390
bool CB3CameraUtils::CollisionIsCameraInVehicle(CGtV3d lCamera, int lePlayerCarIndex)
{
    CGtAxisAlignedBox lBBox;
    CGtMatrix3x4 lInverseMatrix;
    UnkStruct_002F7390_body * lpPhysics = D_0055EFEC[lePlayerCarIndex].field_0;
    if (lpPhysics->field_210) {
        signed char lu8PlayerCrashIndex = lpPhysics->field_218;
        int lnCrashTraffic = *(int *)(D_00522660 + 0x122B1C);
        for (int lnIndex = 0; lnIndex < lnCrashTraffic; lnIndex++) {
            UnkStruct_002F7390_body * lpBody = ((UnkStruct_002F7390_body **)(D_00522660 + 0x122A10))[lnIndex];
            if (lpBody->field_218 == lu8PlayerCrashIndex && func_002F7390_inl1(lpBody, lCamera)) {
                lBBox = lpBody->field_1D0;
                lInverseMatrix = lpBody->field_70;
                if (CollisionIsCameraInVehicle(lCamera, lBBox, *lpBody->field_204, lInverseMatrix))
                    return true;
            }
        }
    }
    int lnTraffic = *(int *)(D_00522660 + 0x12AD1C);
    for (int lnIndex = 0; lnIndex < lnTraffic; lnIndex++) {
        UnkStruct_002F7390_body * lpBody = *(UnkStruct_002F7390_body **)(D_00522660 + 0x3C98C + lnIndex * 0x30);
        if (func_002F7390_inl1(lpBody, lCamera)) {
            lBBox = lpBody->field_1D0;
            lInverseMatrix = lpBody->field_70;
            if (CollisionIsCameraInVehicle(lCamera, lBBox, *lpBody->field_204, lInverseMatrix))
                return true;
        }
    }
    int leRaceCarCount = D_00527440[0x36350 + lePlayerCarIndex];
    for (int lnIndex = 0; lnIndex < leRaceCarCount; lnIndex++) {
        int n = D_00527440[0x35C24 + lePlayerCarIndex * 254 + lnIndex];
        UnkStruct_002F7390_rc * lpCar = (UnkStruct_002F7390_rc *)(D_00527440 + n * 0x180 + 0x127D0);
        float r = 1.5f + lpCar->field_B0->field_14;
        if ((lpCar->field_70.mPos - lCamera).GetSquaredLength() <= r * r) {
            lBBox = lpCar->field_B0->field_E80;
            lInverseMatrix = lpCar->field_70;
            lInverseMatrix.Invert();
            ((float *)&lInverseMatrix.mPos)[3] = ((const float *)&lpCar->field_70.mPos)[3]; // [C] 0x2F7A40 lqc2 vf3, 0xA0(a1) (mPos);
            // 0x2F7A6C vmuly.xyz vf3, vf12, vf3y into it, 0x2F7A70 / 0x2F7A74 vadd.xyz and 0x2F7A78 vsub.xyz vf3, vf0, vf3 keep its w;
            // 0x2F7A88 sqc2 vf3, 0(s5) -- the port header's Invert gives the up row's w (right for other call sites, not this one)
            if (CollisionIsCameraInVehicle(lCamera, lBBox, lpCar->field_70, lInverseMatrix))
                return true;
        }
    }
    return false;
}
