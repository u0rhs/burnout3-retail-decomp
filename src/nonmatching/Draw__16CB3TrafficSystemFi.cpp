// NONMATCHING: Draw__16CB3TrafficSystemFi -- retail 1465 / ours 1394 instructions, 1832 in changed runs
// fix2 (2026-11-01): CB3TrafficSystem layout: the vehicles start at 0x127D0 (alignment put them at 0x127B0: every vehicle access 0x20 low), 0xFE of them (the matched constructor's memset), field_343F0 at 0x343F0 (was 0x337D0); the params block's field_180 holds 0xC matrices + 0x20 (field_4A0.. were 0x160 high) [C] retail 0x307A80, 0x3082D4, 0x3082E0, 0x373E3 | Before: draftY: complete, call multiset identical (25 calls); Revenge STABS local names; [C] map names CDrawnTrafficCache::IsUnitVisibleToMainCamera (inlined), CSortedTrafficVehicle, CGtAxisAlignedBox; camera-inside test = inverse matrix + 6 compares (>= lower, <= upper); left: block placement (ours puts the first loop's active-vehicle body and one corona tail out of line, so call order differs), large this-offset constants not kept in s-registers (ori 12 vs 26), wheel matrices in GPRs (retail keeps the 3 rotation matrices in VU regs across the wheel loop), stand-ins for the no-copy CGtV3d arguments of GetIrradiance / func_003090A0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm + Ghidra draft: every call (same multiset), branch sense, store and VU op accounted for; field layout from offsets, roles [G]


// CB3TrafficSystem::Draw(int) -- draftY, written from the retail asm + Ghidra draft; local names after Revenge's
// CB4TrafficSystem::Draw(EPlayerCarIndex) STABS (B4TrafficSystemLoadAndRender.cpp) [L], placeholders otherwise.
// [L] reading: collect the visible traffic of the player's race-car lists into the scratchpad CDrawnTrafficCache (LOD by
// squared camera distance; a vehicle the camera sits inside is flagged, not drawn), add the crashing ("checked") traffic,
// sort, compute irradiance, render (wheel matrices from two spin rotations and a steer rotation), render the immediate
// effects, then add the traffic-light and the unassigned coronas.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

extern "C" void *memset(void *, int, unsigned int);
extern "C" void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
extern "C" int func_00309070(const void *, const void *);   // [L] _CompareVehicleDistanceQSortCallback (B3O0PCH order)
extern "C" int func_00309040(const void *, const void *);   // [L] _CompareCrashingVehicleDistanceQSortCallback
extern "C" int func_00309010(const void *, const void *);   // [L] _CompareVehicleTypesQSortCallback
extern "C" int func_00308FE0(const void *, const void *);   // [L] _CompareCrashingVehicleTypesQSortCallback

struct CB3StreamedTrackLODAndCollisionData;
class CB3StreamedTrack {
public:
    void ForEveryUnitInSafeArea(void (*)(CB3StreamedTrackLODAndCollisionData *, int, void *), void *);
    bool IsUnitVisibleToMainCamera(int);
};
extern "C" void func_00309390(CB3StreamedTrackLODAndCollisionData *, int, void *);   // [L] _safeUnitCallback
struct CGtIrradianceMap;
// [G] stand-in: retail passes the CGtV3d argument's address with no copy (b119p copies a by-value class argument)
extern "C" void GetIrradiance__16CB3StreamedTrackFiQ29GtMathPs26CGtV3dP16CGtIrradianceMapf(CB3StreamedTrack *, int, const CGtV3d &, CGtIrradianceMap *, float);
// [L] CreateRotationMatrixOnPrincipalAxis(CGtV3d, float) (DNAT); [G] stand-in as above
extern "C" CGtMatrix3x4 func_003090A0(const CGtV3d &, float);
extern CGtV3d kXAxisVector;
extern CGtV3d kYAxisVector;

struct CB3VehicleEssentialParams;
enum EVehicleLOD { };                            // [C] name (RenderVehicle's mangled parameter)
struct CB3VehicleParams;
class CB3VehicleRenderer {
public:
    void FrustumTestUndamagedVehicle(CB3VehicleEssentialParams *);
    void FrustumTestDamagedVehicle(CB3VehicleEssentialParams *, CB3VehicleParams *);
    void BeginVehicleRendering();
    void EndVehicleRendering();
    void RenderVehicle(const CB3VehicleEssentialParams *, const CB3VehicleParams *, EVehicleLOD);
};
extern CB3VehicleRenderer gVehicleRenderer;
class CB3TrafficVehicle;
class CB3EffectsManager {
public:
    void RenderTrafficImmediateEffects(CB3TrafficVehicle *);
    void AddTrafficCorona(CGtV3d, CGtV3d, CGtV3d, CGtV3d, float);
    unsigned char pad_0[0x100];
};
extern CB3EffectsManager D_01D9D200;

struct CGtAxisAlignedBox { CGtV3d field_0; CGtV3d field_10; };   // [C] name (E map); [L] upper / lower corner (compare senses)
struct UnkStruct_003078F0_vd {                    // [G] traffic vehicle data (vehicle-type table entry)
    unsigned char pad_0[0xC];
    signed char field_C;                          // body matrix count
    signed char field_D;                          // wheel count
    unsigned char pad_E[0x6];
    float field_14;                               // bounding radius
    float field_18;                               // wheel radius
    unsigned char pad_1C[0xB80 - 0x1C];
    CGtMatrix3x4 field_B80[6];                    // wheel matrices
    CGtMatrix3x4 field_D00[0x1C];                 // body matrices
    unsigned char pad_1400[0x16C0 - 0x1400];
    unsigned char *field_16C0;
    unsigned char pad_16C4[4];
    signed char field_16C8;
};
struct UnkStruct_003078F0_vd2 {                   // [G] same object seen through the source-data pointer
    unsigned char pad_0[0x14];
    float field_14;
    unsigned char pad_18[0xE80 - 0x18];
    CGtAxisAlignedBox field_E80;
};
class CB3TrafficVehicle {                         // [C] name (RenderTrafficImmediateEffects' parameter); stride 0x180
public:
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;                        // start of the CB3VehicleEssentialParams (+0x70)
    UnkStruct_003078F0_vd2 *field_B0;
    unsigned char pad_B4[0x10];
    float field_C4;                               // [G] wheel spin speed
    unsigned char pad_C8[2];
    signed char field_CA;                         // streamed-track unit
    signed char field_CB;                         // frustum result
    unsigned char field_CC[0x5C];                 // irradiance map
    float field_128;                              // [G] wheel spin angle
    unsigned char pad_12C[4];
    float field_130;                              // [G] steer angle
    unsigned char pad_134[0x3D];
    unsigned char field_171;
    unsigned char pad_172[2];
    unsigned char field_174;                      // flags: bit 0 active, bit 2 crashing
    unsigned char pad_175;
    unsigned char field_176;                      // vehicle type
    unsigned char pad_177[3];
    unsigned char field_17A;                      // flags: bit 1 camera inside
    unsigned char pad_17B[5];
};
struct UnkStruct_003078F0_cm { unsigned long field_0; };   // [L] CB3PlayerCameraManager (Revenge `this` of the inline)
struct UnkStruct_003078F0_ph {                    // [G] crashing traffic physics
    unsigned char pad_0[0x204];
    CGtMatrix3x4 *field_204;
    unsigned char pad_208[0x1360 - 0x208];
    unsigned char field_1360[0x30];               // CB3VehicleEssentialParams
    CGtV3d field_1390;
    unsigned char pad_13A0[0x1A];
    signed char field_13BA;
    signed char field_13BB;
    unsigned char pad_13BC[0x24];
    unsigned char field_13E0[0x4A0];              // CB3VehicleParams
    int field_1880;
    unsigned char pad_1884[0x2402 - 0x1884];
    unsigned char field_2402;
};
class CSortedTrafficVehicle {                     // [C] name (B3O0PCH operator=); 12 bytes
public:
    CB3TrafficVehicle *field_0;
    float field_4;                                // squared distance
    signed char field_8;                          // LOD
    signed char field_9;                          // vehicle type
};
struct UnkStruct_003078F0_cr { UnkStruct_003078F0_ph *field_0; float field_4; int field_8; int field_C; };
class CDrawnTrafficCache {                        // [C] name; lives in the scratchpad (0x70002000)
public:
    unsigned char TestPosition(CGtV3d);
    // [C] name/size: B3O0PCH 0x3373C0 (0x78); inlined
    bool IsUnitVisibleToMainCamera(int lnUnit)
    {
        for (int i = 0; i < field_9B0; i++) {
            if (field_980[i] == lnUnit) return field_9A4[i];
        }
        return false;
    }
    CSortedTrafficVehicle field_0[64];
    int field_300;
    CSortedTrafficVehicle field_304[16];
    int field_3C4;
    UnkStruct_003078F0_cr field_3C8[64];
    int field_7C8;
    unsigned char pad_7CC[0x980 - 0x7CC];
    int field_980[9];
    bool field_9A4[12];
    int field_9B0;
};
struct UnkStruct_003078F0_lt { unsigned char pad_0[0x10]; unsigned char field_10[4]; unsigned char field_14; };
struct UnkStruct_003078F0_tl { UnkStruct_003078F0_lt *field_0; unsigned char pad_4[0x10]; unsigned char field_14; unsigned char pad_15[3]; };
struct UnkStruct_003078F0_co { CGtV3d field_0; CGtV3d field_10; };
struct UnkStruct_003078F0_td {
    unsigned char pad_0[0x38];
    int field_38;
    unsigned char pad_3C[0xAC - 0x3C];
    UnkStruct_003078F0_co *field_AC;
    int field_B0;
};
struct UnkStruct_003078F0_cam { unsigned char pad_0[0x20]; CGtV3d field_20; };
struct UnkStruct_003078F0_g { unsigned char pad_0[0x68]; UnkStruct_003078F0_cam *field_68; unsigned char pad_6C[0x24]; float field_90; };
extern UnkStruct_003078F0_g *D_00666270;
extern unsigned char D_00665F25;
extern float D_00665F3C;
extern float D_00665F40;
extern int D_0064517C;
extern unsigned char D_00522660[];                // [L] gWorld (E map, medium)
extern unsigned char D_004EE040[];                // gGame (conflict)
extern CGtV3d D_004C4980, D_004C4990, D_004C49A0, D_004C49B0, D_004C49C0;

struct UnkStruct_003078F0_rp {                    // [G] CB3VehicleParams block at this+0x363C0 (0x1040 bytes)
    CGtMatrix3x4 field_0[6];
    CGtMatrix3x4 field_180[0xC];                  // fix2: [0x12] put field_4A0.. at 0x600.. (0x160 high); retail 0x3082E0 stores
    unsigned char pad_480[0x20];                  // field_4A0 at +0x4A0 (0x36860), field_1023/1024 at 0x373E3/4 [C]
    void *field_4A0;
    unsigned char pad_4A4[0x2C];
    float field_4D0[6];
    float field_4E8[6];
    unsigned char pad_500[0x1023 - 0x500];
    unsigned char field_1023;
    void *field_1024;
    unsigned char pad_1028[0x18];
};

class CB3TrafficSystem {
public:
    void Draw(int);
    UnkStruct_003078F0_td *field_0;
    unsigned char pad_4[0x117CC - 4];
    UnkStruct_003078F0_tl field_117CC[0xA9];
    unsigned char pad_127A4[0x2C];                // fix2: the lights table ends at 0x127A4; the vehicles start at 0x127D0 (the
                                                  // draft let alignment put them at 0x127B0: every vehicle access 0x20 low)
    CB3TrafficVehicle field_127D0[0xFE];          // fix2: 254 x 0x180 = 0x17D00 [C] the matched constructor (B3TrafficSystem.cpp memset)
    unsigned char pad_2A4D0[0x343F0 - 0x2A4D0];   // fix2: [0x160] put field_343F0 at 0x337D0 (retail 0x3082D4 reads 0x343F0)
    UnkStruct_003078F0_vd *field_343F0[0x20];
    unsigned char pad_34470[0x35C24 - 0x34470];
    unsigned char field_35C24[8][0xFE];
    unsigned char pad_36414[0];
};

#define TS_U8(o) (*(unsigned char *)((char *)this + (o)))
#define TS_U32(o) (*(unsigned int *)((char *)this + (o)))

void CB3TrafficSystem::Draw(int lePlayer)
{
    CGtV3d lTLAt(0.0f, 1.0f, 0.0f);
    UnkStruct_003078F0_cam *lpCamera = D_00666270->field_68;
    CGtV3d lCamPos = lpCamera->field_20;
    if (field_0 == 0 || D_00665F25 == 0) return;
    float larLodDistances[2];
    larLodDistances[1] = D_00665F40 * D_00666270->field_90;
    larLodDistances[0] = D_00665F3C * D_00666270->field_90;
    int lePlayerRaceCarIndex = *(signed char *)(D_00522660 + lePlayer * 0x27D0 + 0x12AD50 + 0x19AC);
    larLodDistances[0] = larLodDistances[0] * larLodDistances[0];
    larLodDistances[1] = larLodDistances[1] * larLodDistances[1];
    CDrawnTrafficCache *lpCache = (CDrawnTrafficCache *)0x70002000;
    CB3StreamedTrack *lpTrack = (CB3StreamedTrack *)(D_00522660 + lePlayer * 0x1CC + 0x12A348);
    lpCache->field_9B0 = 0;
    lpCache->field_300 = 0;
    lpCache->field_3C4 = 0;
    lpCache->field_7C8 = 0;
    lpTrack->ForEveryUnitInSafeArea(func_00309390, lpCache);
    int lnIndex;
    for (lnIndex = 0; lnIndex < lpCache->field_9B0; lnIndex++)
        lpCache->field_9A4[lnIndex] = lpTrack->IsUnitVisibleToMainCamera(lpCache->field_980[lnIndex]);
    float lrMaxDistanceSq = (float)75625;
    for (lnIndex = 0; lnIndex < TS_U8(0x36350 + lePlayerRaceCarIndex); lnIndex++) {
        CB3TrafficVehicle *lpTrafficVehicle = &field_127D0[field_35C24[lePlayerRaceCarIndex][lnIndex]];
        if (!(lpTrafficVehicle->field_174 & 1)) continue;
        float lrDistanceSq = (lpTrafficVehicle->field_70.mPos - lCamPos).GetSquaredLength();
        if (!(lrDistanceSq <= lrMaxDistanceSq) && !(lpTrafficVehicle->field_174 & 4)) continue;
        signed char leVehicleLOD;
        if (lrDistanceSq <= larLodDistances[1]) {
            if (lrDistanceSq <= larLodDistances[0]) leVehicleLOD = 2;
            else leVehicleLOD = 1;
        } else {
            leVehicleLOD = 0;
        }
        if (!(lpTrafficVehicle->field_174 & 4)) {
            lpTrafficVehicle->field_CA = lpCache->TestPosition(lpTrafficVehicle->field_70.mPos);
            if (!lpCache->IsUnitVisibleToMainCamera(lpTrafficVehicle->field_CA)) continue;
        } else {
            lpTrafficVehicle->field_CA = lpCache->TestPosition(lpTrafficVehicle->field_70.mPos);
        }
        gVehicleRenderer.FrustumTestUndamagedVehicle((CB3VehicleEssentialParams *)&lpTrafficVehicle->field_70);
        if (lpTrafficVehicle->field_CB == 0) continue;
        bool lbCameraInside = false;
        UnkStruct_003078F0_cm *lpCameraManager = (UnkStruct_003078F0_cm *)(D_004EE040 + lePlayer * 0xBB0 + 0x29980);
        if ((lpCameraManager->field_0 & 4) && lpTrafficVehicle->field_CB == 1) {
            UnkStruct_003078F0_vd2 *lpData = lpTrafficVehicle->field_B0;
            float lrRadiusSquared = lpData->field_14 * lpData->field_14;
            if (lrDistanceSq < lrRadiusSquared) {
                CGtAxisAlignedBox lBBox = lpData->field_E80;
                CGtMatrix3x4 lInverseMatrix = lpTrafficVehicle->field_70;
                lInverseMatrix.Invert();
                CGtV3d lTransformedPoint = TransformPoint(lInverseMatrix, lCamPos);
                lbCameraInside = lTransformedPoint.X() >= lBBox.field_10.X() && lTransformedPoint.Y() >= lBBox.field_10.Y() &&
                    lTransformedPoint.Z() >= lBBox.field_10.Z() && lTransformedPoint.X() <= lBBox.field_0.X() &&
                    lTransformedPoint.Y() <= lBBox.field_0.Y() && lTransformedPoint.Z() <= lBBox.field_0.Z();
            }
        }
        if (lbCameraInside) {
            lpTrafficVehicle->field_17A |= 2;
        } else {
            if (lpTrafficVehicle->field_174 & 4) {
                if (lpCache->field_3C4 < 16) {
                    lpCache->field_304[lpCache->field_3C4].field_8 = leVehicleLOD;
                    lpCache->field_304[lpCache->field_3C4].field_0 = lpTrafficVehicle;
                    lpCache->field_304[lpCache->field_3C4].field_4 = lrDistanceSq;
                    lpCache->field_304[lpCache->field_3C4].field_9 = lpTrafficVehicle->field_176;
                    lpCache->field_3C4++;
                }
            } else if (lpCache->field_300 < 64) {
                lpCache->field_0[lpCache->field_300].field_8 = leVehicleLOD;
                lpCache->field_0[lpCache->field_300].field_0 = lpTrafficVehicle;
                lpCache->field_0[lpCache->field_300].field_4 = lrDistanceSq;
                lpCache->field_0[lpCache->field_300].field_9 = lpTrafficVehicle->field_176;
                lpCache->field_300++;
            }
            lpTrafficVehicle->field_17A &= ~2;
        }
    }
    float lrFarDistanceSq = larLodDistances[1];
    for (lnIndex = 0; lnIndex < D_0064517C; lnIndex++) {
        UnkStruct_003078F0_ph *lpPhysics = ((UnkStruct_003078F0_ph **)(D_00522660 + 0x122A10))[lnIndex];
        float lrDistanceSq = (lpPhysics->field_204->mPos - lCamPos).GetSquaredLength();
        if (!(lrDistanceSq <= lrMaxDistanceSq)) continue;
        int leVehicleLOD;
        if (lrDistanceSq <= lrFarDistanceSq) {
            if (lrDistanceSq <= larLodDistances[0]) leVehicleLOD = 2;
            else leVehicleLOD = 1;
        } else {
            leVehicleLOD = 0;
        }
        lpPhysics->field_13BA = lpCache->TestPosition(lpPhysics->field_1390);
        if (!lpCache->IsUnitVisibleToMainCamera(lpPhysics->field_13BA)) continue;
        gVehicleRenderer.FrustumTestDamagedVehicle((CB3VehicleEssentialParams *)lpPhysics->field_1360, (CB3VehicleParams *)lpPhysics->field_13E0);
        if (lpPhysics->field_13BB == 0 && lpPhysics->field_2402 == 0) continue;
        if (lpCache->field_7C8 < 64) {
            lpCache->field_3C8[lpCache->field_7C8].field_8 = leVehicleLOD;
            lpCache->field_3C8[lpCache->field_7C8].field_0 = lpPhysics;
            lpCache->field_3C8[lpCache->field_7C8].field_4 = lrDistanceSq;
            lpCache->field_3C8[lpCache->field_7C8].field_C = lpPhysics->field_1880;
            lpCache->field_7C8++;
        }
    }
    qsort(lpCache->field_304, lpCache->field_3C4, 0xC, func_00309070);
    qsort(lpCache->field_0, lpCache->field_300, 0xC, func_00309070);
    qsort(lpCache->field_3C8, lpCache->field_7C8, 0x10, func_00309040);
    if (lpCache->field_3C4 > 8) lpCache->field_3C4 = 8;
    if (lpCache->field_300 > 32 - lpCache->field_3C4) lpCache->field_300 = 32 - lpCache->field_3C4;
    if (lpCache->field_7C8 > 32) lpCache->field_7C8 = 32;
    for (lnIndex = 0; lnIndex < lpCache->field_3C4; lnIndex++)
        lpCache->field_0[lnIndex + lpCache->field_300] = lpCache->field_304[lnIndex];
    lpCache->field_300 += lpCache->field_3C4;
    qsort(lpCache->field_0, lpCache->field_300, 0xC, func_00309010);
    qsort(lpCache->field_3C8, lpCache->field_7C8, 0x10, func_00308FE0);
    CB3TrafficVehicle *lapDrawnNonCrashing[32];
    signed char laeDrawnNonCrashingLODs[32];
    UnkStruct_003078F0_ph *lapDrawnCrashing[32];
    signed char laeDrawnCrashingLODs[32];
    int lnNumNonCrashingDrawnVehicles = lpCache->field_300;
    for (lnIndex = 0; lnIndex < lnNumNonCrashingDrawnVehicles; lnIndex++) {
        CB3TrafficVehicle *lpTrafficVehicle = lpCache->field_0[lnIndex].field_0;
        lapDrawnNonCrashing[lnIndex] = lpTrafficVehicle;
        laeDrawnNonCrashingLODs[lnIndex] = lpCache->field_0[lnIndex].field_8;
        GetIrradiance__16CB3StreamedTrackFiQ29GtMathPs26CGtV3dP16CGtIrradianceMapf(lpTrack, lpTrafficVehicle->field_CA,
            lpTrafficVehicle->field_70.mPos, (CGtIrradianceMap *)lpTrafficVehicle->field_CC, lpTrafficVehicle->field_B0->field_14);
    }
    int lnNumCrashingDrawnVehicles = lpCache->field_7C8;
    for (lnIndex = 0; lnIndex < lnNumCrashingDrawnVehicles; lnIndex++) {
        lapDrawnCrashing[lnIndex] = lpCache->field_3C8[lnIndex].field_0;
        laeDrawnCrashingLODs[lnIndex] = lpCache->field_3C8[lnIndex].field_8;
    }
    gVehicleRenderer.BeginVehicleRendering();
    UnkStruct_003078F0_rp *lpParams = (UnkStruct_003078F0_rp *)((char *)this + 0x363C0);
    memset(lpParams, 0, 0x1040);
    for (lnIndex = lnNumNonCrashingDrawnVehicles - 1; lnIndex >= 0; lnIndex--) {
        CB3TrafficVehicle *lpTrafficVehicle = lapDrawnNonCrashing[lnIndex];
        UnkStruct_003078F0_vd *lpSourceData = field_343F0[lpTrafficVehicle->field_176];
        float lrInvRadius = 1.0f / lpSourceData->field_18;
        lpParams->field_4A0 = (char *)this + 0x37400;
        int i;
        for (i = 0; i < lpSourceData->field_D; i++) lpParams->field_4D0[i] = lpSourceData->field_18;
        for (i = 0; i < lpSourceData->field_C; i++) lpParams->field_180[i] = lpSourceData->field_D00[i];
        CGtMatrix3x4 lWheelSpinMatrix = func_003090A0(kXAxisVector, lpTrafficVehicle->field_128);
        CGtMatrix3x4 lWheelRevSpinMatrix = func_003090A0(kXAxisVector, -lpTrafficVehicle->field_128);
        CGtMatrix3x4 lSteerMatrix = func_003090A0(kYAxisVector, -lpTrafficVehicle->field_130);
        // [C] w lanes of field_0[i]'s first three rows: every product row is written xyz-only into vf4 (0x308520..0x308550,
        // 0x3085A4..0x3085E8 and the other paths' twins), so rows 0..2 keep the w vf4 carries into the iteration; mPos.w =
        // field_B80[i].mPos.w (0x3085F4 lq a2, 0xBB0(a1), a1 = lpSourceData + i * 0x40; 0x30860C qmtc2 a2, vf4; 0x308610
        // vmaddw.xyz vf4, vf4, vf0w). vf4 entering wheel 0 = lSteerMatrix.mPos (func_003090A0 ends 0x3092E0 vadd.xyz vf4 /
        // 0x3092EC sqc2 vf4, 0x30(a0); no vf4 write from 0x308438 to 0x3084F8), entering wheel i >= 1 = wheel i-1's mPos row.
        // Stored at 0x30892C / 0x308930 / 0x308934 (sq from sp+0x7A0 / 0x7B0 / 0x7C0). The port's matrix product gives
        // each row the left factor's row w instead (the spin matrix's: 1.0 / 0.53 natively, retail 0).
        float lrRowW = ((const float *)&lSteerMatrix.mPos)[3];
        for (i = 0; i < lpSourceData->field_D; i++) {
            lpParams->field_4E8[i] = lpTrafficVehicle->field_C4 * lrInvRadius;
            if (i == 1) {
                lpParams->field_0[i] = (lWheelRevSpinMatrix * lSteerMatrix) * lpSourceData->field_B80[i];
            } else if (i == 0) {
                lpParams->field_0[i] = (lWheelSpinMatrix * lSteerMatrix) * lpSourceData->field_B80[i];
            } else if (i % 2 == 0) {
                lpParams->field_0[i] = lWheelSpinMatrix * lpSourceData->field_B80[i];
            } else {
                lpParams->field_0[i] = lWheelRevSpinMatrix * lpSourceData->field_B80[i];
            }
            ((float *)&lpParams->field_0[i].mRight)[3] = lrRowW;   // [C] see above: vf4.w entering the iteration
            ((float *)&lpParams->field_0[i].mUp)[3] = lrRowW;
            ((float *)&lpParams->field_0[i].mAt)[3] = lrRowW;
            lrRowW = ((const float *)&lpSourceData->field_B80[i].mPos)[3];   // [C] 0x308610 / 0x308744 / 0x308818 / 0x3088CC
        }
        lpParams->field_1023 = 0;
        if (lpSourceData->field_16C8 > 0)
            lpParams->field_1024 = lpSourceData->field_16C0 + lpTrafficVehicle->field_171 * 0xC;
        else
            lpParams->field_1024 = 0;
        gVehicleRenderer.RenderVehicle((CB3VehicleEssentialParams *)&lpTrafficVehicle->field_70, (CB3VehicleParams *)lpParams, (EVehicleLOD)laeDrawnNonCrashingLODs[lnIndex]);
    }
    for (lnIndex = lnNumCrashingDrawnVehicles - 1; lnIndex >= 0; lnIndex--)
        gVehicleRenderer.RenderVehicle((CB3VehicleEssentialParams *)lapDrawnCrashing[lnIndex]->field_1360, (CB3VehicleParams *)lapDrawnCrashing[lnIndex]->field_13E0, (EVehicleLOD)laeDrawnCrashingLODs[lnIndex]);
    gVehicleRenderer.EndVehicleRendering();
    for (lnIndex = 0; lnIndex < lnNumNonCrashingDrawnVehicles; lnIndex++)
        D_01D9D200.RenderTrafficImmediateEffects((CB3TrafficVehicle *)&lapDrawnNonCrashing[lnIndex]->field_70);
    for (lnIndex = lnNumCrashingDrawnVehicles - 1; lnIndex >= 0; lnIndex--)
        D_01D9D200.RenderTrafficImmediateEffects((CB3TrafficVehicle *)lapDrawnCrashing[lnIndex]->field_1360);
    int lnTLIndex;
    for (lnTLIndex = 0; lnTLIndex < field_0->field_38; lnTLIndex++) {
        UnkStruct_003078F0_tl *lpTrafficLight = &field_117CC[lnTLIndex];
        CGtV3d lTLColour;
        CGtV3d lTLPosOffset;
        switch (lpTrafficLight->field_14) {
        case 0:
            lTLColour = D_004C49A0;
            lTLPosOffset = D_004C49C0;
            break;
        case 2:
            lTLColour = D_004C4980;
            lTLPosOffset = D_004C49B0;
            break;
        default:
        case 1:
            lTLColour = D_004C4990;
            lTLPosOffset.Zero();
            break;
        }
        for (int lnTLCoronaIndex = 0; lnTLCoronaIndex < lpTrafficLight->field_0->field_14; lnTLCoronaIndex++) {
            int lnCoronaIndex = lpTrafficLight->field_0->field_10[lnTLCoronaIndex];
            if (TS_U8(0x363BA) == 0) {
                CGtV3d lCross = CrossProduct(lTLAt, field_0->field_AC[lnCoronaIndex].field_10 * -1.0f);
                if (lpTrafficLight->field_14 == 2) lTLPosOffset = lCross * -0.5f;
                else if (lpTrafficLight->field_14 == 0) lTLPosOffset = lCross * 0.5f;
            }
            CGtV3d lColour = lTLColour;
            CGtV3d lDir = field_0->field_AC[lnCoronaIndex].field_10 * -1.0f;
            CGtV3d lPos = field_0->field_AC[lnCoronaIndex].field_0 + lTLPosOffset;
            CGtV3d lToCamera = lPos - lpCamera->field_20;
            float lrDistance = lToCamera.NormaliseGetLength();
            D_01D9D200.AddTrafficCorona(lToCamera, lDir, lPos, lColour, 1.5f + 0.004f * lrDistance);
        }
    }
    unsigned int lx32Flag = 1;
    int w = 0;
    CGtV3d lUColour = D_004C49A0;
    CGtV3d lUPosOffset = D_004C49C0;
    unsigned int lx32UnassignedCorona = TS_U32(0x36320);
    for (int lnCoronaIndex = 0; lnCoronaIndex < field_0->field_B0; lnCoronaIndex++) {
        if (~lx32UnassignedCorona & lx32Flag) {
            if (TS_U8(0x363BA) == 0)
                lUPosOffset = CrossProduct(lTLAt, field_0->field_AC[lnCoronaIndex].field_10 * -1.0f) * 0.5f;
            CGtV3d lColour = lUColour;
            CGtV3d lDir = field_0->field_AC[lnCoronaIndex].field_10 * -1.0f;
            CGtV3d lPos = field_0->field_AC[lnCoronaIndex].field_0 + lUPosOffset;
            CGtV3d lToCamera = lPos - lpCamera->field_20;
            float lrDistance = lToCamera.NormaliseGetLength();
            D_01D9D200.AddTrafficCorona(lToCamera, lDir, lPos, lColour, 1.5f + 0.004f * lrDistance);
        }
        if (lx32Flag < 0x7F000000) {
            lx32Flag <<= 1;
        } else {
            w++;
            lx32UnassignedCorona = TS_U32(0x36320 + w * 4);
            lx32Flag = 1;
        }
    }
}
