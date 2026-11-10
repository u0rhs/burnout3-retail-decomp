// NONMATCHING: GetCrashingDrivingControls__19CB3PlayerCarPhysicsFv -- retail 1615 / ours 1637 instructions, 783 in changed runs
// draftV: 1615/1637, 783 changed; call sequence identical (acosf/asinf = func_0011E328/0011E340), CFG and branch senses match except the |=4 test (inline in ours, out of line in retail); residue: CreateRotationMatrix3x4 x2 / ConvertToMatrix x2 / SetFromMatrix / operator* scheduling, UncompressRotation z-test block order and Z negate (retail vsub.z), dead matrix copies of operator*= (retail 2 extra), frame 0x1380 vs 0x2020
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm with Revenge STABS locals (B4PlayerCarPhysics.cpp): every call, branch, store and VU op accounted for -- crash-breaker timer, controller reads, CompressRotation of the camera quat into field_1410 when D_00665E53 == 0, slow-mo/pitch, crash-breaker score, then UncompressRotation -> steering axis in XZ -> velocity nudge, yaw toward it clamped by speed (CreateRotationMatrix3x4 about Y), body tilt about field_204->mAt clamped to +-17

// GetCrashingDrivingControls__19CB3PlayerCarPhysicsFv -- draftV (0x1BB6E0, 0x193C) -- CB3PlayerCarPhysics::GetCrashingDrivingControls()
// Written from the retail asm with Revenge STABS (B4PlayerCarPhysics.cpp, CB4PlayerCarPhysics::GetCrashingDrivingControls locals:
// lCameraQuat, lpControls, lAxis, lrLength, lrColAngle/lrRowAngle, luResult, lnCol/lnRow, lrClamped) as [L] structure.
// The E O0PCH map emits after it (reverse first use): CGtMatrix3x4::operator*=(const&), TransformVector(3x4,V3d),
// UncompressRotation, CompressRotation(CGtQuat), CGtV3d::Set(X,Y,Z), Abs(CGtV4d), CGtQuat::SetFromMatrix [C map].
// Field layout from the asm (instruction widths) [G]; CDrivingControls block at +0x13FC (NextFrame's argument) [C].
// [G] header experiment switch: UncompressRotation's w via SetA (vmulx.w, as retail here and at GetMatrix 0x446BA4) -- queued.
#define QX_SETA
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_001BB6E0_vt {
    virtual int vfunc_8();
    virtual int vfunc_C();
    virtual int vfunc_10();
    virtual int vfunc_14();
    virtual int vfunc_18();
    virtual int vfunc_1C();
    virtual int vfunc_20();
    virtual int vfunc_24();
    virtual int vfunc_28();
    virtual int vfunc_2C();
    virtual int vfunc_30();
    virtual int vfunc_34();
    virtual int vfunc_38();
    virtual int vfunc_3C();
    virtual int vfunc_40();
    virtual int vfunc_44();
    virtual int vfunc_48();
    virtual int vfunc_4C();
    virtual int vfunc_50();
    virtual int vfunc_54();
    virtual int vfunc_58();
    virtual int vfunc_5C();
    virtual int vfunc_60();
    virtual int vfunc_64();
    virtual int vfunc_68();
    virtual int vfunc_6C();
    virtual int vfunc_70();
    virtual int vfunc_74();
    virtual int vfunc_78();
    virtual int vfunc_7C();
    virtual int vfunc_80();
    virtual int vfunc_84();
    virtual int vfunc_88();
    virtual int vfunc_8C();
    virtual int vfunc_90();
    virtual int vfunc_94();
    virtual int vfunc_98();
    virtual int vfunc_9C();
    virtual int vfunc_A0();
    virtual int vfunc_A4();
    virtual int vfunc_A8();
    virtual int vfunc_AC();
    virtual int vfunc_B0();
    virtual int vfunc_B4();
    virtual int vfunc_B8();
    virtual int vfunc_BC();
    virtual int vfunc_C0();
    virtual int vfunc_C4();
    virtual int vfunc_C8();
};
struct UnkStruct_001BB6E0_G { unsigned char pad_0[0x1B4]; UnkStruct_001BB6E0_vt * field_1B4; };
struct UnkStruct_D_0051BA88_gcdc { UnkStruct_001BB6E0_G * field_0; int pad[3]; };
extern UnkStruct_D_0051BA88_gcdc D_0051BA88;

struct UnkStruct_001BB6E0_P {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
    unsigned char pad_19AD[0x2460 - 0x19AD];
    void ** field_2460;
    unsigned char pad_2464[0x27C0 - 0x2464];
    int field_27C0;
    unsigned char pad_27C4[4];
    unsigned char field_27C8;
};

struct UnkStruct_001BB6E0_self {
    void * vptr;
    unsigned char pad_4[0xAC];
    CGtV3dPlus field_B0;           // [G] linear velocity, w = speed (as CB3TrafficPhysics, draftN)
    CGtV3d field_C0;
    unsigned char pad_D0[0x204 - 0xD0];
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[0x13FC - 0x208];
    unsigned char field_13FC;      // CDrivingControls flags (NextFrame's argument) [C]
    unsigned char pad_13FD[3];
    float field_1400;
    float field_1404;
    float field_1408;
    float field_140C;
    unsigned int field_1410;
    float field_1414;
    unsigned char pad_1418[0x1530 - 0x1418];
    float field_1530;
    unsigned char pad_1534[0xC];
    unsigned char field_1540;
    unsigned char pad_1541[0x1580 - 0x1541];
    UnkStruct_001BB6E0_P * field_1580;
    unsigned char pad_1584[0x3534 - 0x1584];
    float field_3534;
    float field_3538;
    unsigned char pad_353C[0x4583 - 0x353C];
    unsigned char field_4583;
    unsigned char pad_4584;
    unsigned char field_4585;
    unsigned char field_4586;
    unsigned char field_4587;
    CGtV3d field_B0Vec() { return CGtV3d(field_B0.mData); }
};

// gGame (config: conflict) -- placeholder; per-player camera managers at +0x29000, 0xBB0 each, camera CGtQuatPos at +0x10 [L].
struct UnkStruct_001BB6E0_cam { unsigned char pad_0[0x10]; CGtQuatPos field_10; unsigned char pad_30[0xBB0 - 0x30]; };
struct UnkStruct_001BB6E0_cams { UnkStruct_001BB6E0_cam field_0[2]; };
struct UnkStruct_D_004EE040_gcdc {
    unsigned char pad_0[0x29000];
    UnkStruct_001BB6E0_cams field_29000;
};
extern UnkStruct_D_004EE040_gcdc D_004EE040;

extern signed char D_004F507C[];
extern float D_00522680[];
extern int D_0064D3A0[];
extern unsigned char D_00665E53[];
extern unsigned char D_01E65499[];
struct UnkStruct_001BB6E0_blk { unsigned char pad[0x10]; };
extern UnkStruct_001BB6E0_blk D_00522660;
extern UnkStruct_001BB6E0_blk D_01E75640;
extern UnkStruct_001BB6E0_blk D_0064CE40;
extern UnkStruct_001BB6E0_blk D_0055EEE8;

extern "C" bool func_00131E40(void *);   // E map: CB3Game::IsCrashMode() [high, not a symbol]
extern "C" bool func_00131CA0(void *);   // E map: CB3Game::Is2PlayerSplitScreen() [high, not a symbol]
extern "C" float GetAccelerator__20CB3ControllerMappingFv(void *);
extern "C" float GetBrake__20CB3ControllerMappingFv(void *);
extern "C" float func_0012F850(void *);  // [low] CB3ControllerMapping::GetSteering()
extern "C" float func_0012F720(void *);  // [low] CB3ControllerMapping::GetAftertouch()
extern "C" float func_0012F610(void *);
extern "C" float func_0012F4E0(void *);
extern "C" float func_0012F160(void *);  // [low] CB3ControllerMapping::GetCameraSwitch()
extern "C" void NextFrame__15CB3ReplaySystemFP16CDrivingControlsb(void *, void *, bool);
extern "C" void SetSlowMo__8CGtTimerFi(void *, int);
extern "C" void SetMasterPitchScalar__15CB3SoundManagerFf(void *, float);
extern "C" void AddCrashScore__13CB3CrashScoreF20ECrashModePickupTypei(void *, int, int);

// [G] placeholder for the float GtMath::Clamp (Revenge lrClamped): max.s then min.s. Header gap (queued).
static inline float func_001BB6E0_inl1(float v, float lo, float hi) { return GtMath::Min(GtMath::Max(v, lo), hi); }
// [G] placeholder for GtMathPs2::CompressRotation(CGtQuat) (B3O0PCH map, 1092 bytes): UncompressRotation's inverse. Header gap.
static inline unsigned int func_001BB6E0_inl3(CGtQuat q)
{
    CGtV4d lAbs = Abs(q.mRot);
    unsigned int luResult = (int)(lAbs.W() * (float)1023);
    if (luResult >= 0x400) luResult = 0x3FF;
    if (q.mRot.X() < 0.0f) luResult |= 0x400;
    if (q.mRot.Y() < 0.0f) luResult |= 0x800;
    if (q.mRot.Z() < 0.0f) luResult |= 0x1000;
    if (q.mRot.W() < 0.0f) luResult |= 0x2000;
    CGtV3d lAxis;
    lAxis.Set(lAbs.X(), lAbs.Y(), lAbs.Z());
    float lrLength = lAxis.GetLength();
    float lrRowAngle;
    float lrColAngle;
    if (lrLength < 0.001f) {
        lrRowAngle = 1.5707964f;
        lrColAngle = 0.0f;
    } else {
        lAxis = lAxis * (1.0f / lrLength);
        lAxis.SetX(func_001BB6E0_inl1(lAxis.X(), -1.0f, 1.0f));
        lAxis.SetY(func_001BB6E0_inl1(lAxis.Y(), -1.0f, 1.0f));
        lAxis.SetZ(func_001BB6E0_inl1(lAxis.Z(), -1.0f, 1.0f));
        lrRowAngle = GtMath::ACosRad(lAxis.Y());
        lrColAngle = GtMath::ASinRad(lAxis.X());
    }
    int lnRow = (int)((float)511 * (lrRowAngle / 1.5707964f));
    int lnCol = (int)((float)(lnRow * 2) * (lrColAngle / 1.5707964f));
    return luResult | ((lnRow * lnRow + lnCol) << 14);
}

extern "C" void GetCrashingDrivingControls__19CB3PlayerCarPhysicsFv(UnkStruct_001BB6E0_self * self)
{
    CGtV3d lUp(0.0f, 1.0f, 0.0f);
    bool lCrashMode = func_00131E40(&D_004EE040);
    bool lSlow = false;
    bool lAllow = true;
    bool lSplit = func_00131CA0(&D_004EE040);
    bool lBreaker;
    if (lCrashMode) {
        lBreaker = self->field_1530 < 2.0f && ((self->field_13FC & 4) != 0 || D_004F507C[0] != 0);
        if (self->field_3534 >= 0.0f) {
            if (D_00522680[0] - self->field_3534 < 0.9f) lBreaker = true;
            else { lBreaker = false; self->field_3534 = -1.0f; }
        }
    } else {
        lBreaker = false;
    }
    void * lpControls = *self->field_1580->field_2460;
    if (self->field_1580->field_27C8 != 0) return;
    self->field_1414 = GetAccelerator__20CB3ControllerMappingFv(lpControls);
    self->field_1404 = GetBrake__20CB3ControllerMappingFv(lpControls);
    self->field_1408 = func_0012F850(lpControls);
    self->field_140C = func_0012F720(lpControls);
    self->field_13FC = 0;
    if (D_00665E53[0] == 0) {
        CGtMatrix3x4 lCamMatrix;
        lCamMatrix = D_004EE040.field_29000.field_0[self->field_1580->field_27C0].field_10.ConvertToMatrix();
        CGtQuat lCameraQuat;
        lCameraQuat.SetFromMatrix(lCamMatrix);
        self->field_1410 = func_001BB6E0_inl3(lCameraQuat);
    }
    if (!(func_0012F610(lpControls) <= 0.1f)) self->field_13FC |= 1;
    if (!(func_0012F4E0(lpControls) <= 0.1f)) self->field_13FC |= 2;
    if (func_0012F160(lpControls) != 0.0f) self->field_13FC |= 4;
    NextFrame__15CB3ReplaySystemFP16CDrivingControlsb(&D_0055EEE8, &self->field_13FC, true);
    if (D_01E65499[0] != 0) {
        if (D_0051BA88.field_0->field_1B4->vfunc_9C() != 3) lAllow = false;
    }
    if (lAllow && D_0064D3A0[0] == 1) {
        if (lCrashMode) lSlow = lBreaker;
        else if (self->field_13FC & 4) lSlow = true;
        else lSlow = false;
        if (lSlow) {
            if (!lCrashMode) SetSlowMo__8CGtTimerFi(&D_00522660, 5);
            else if (self->field_3534 < 0.0f) SetSlowMo__8CGtTimerFi(&D_00522660, 3);
            else SetSlowMo__8CGtTimerFi(&D_00522660, 4);
            SetMasterPitchScalar__15CB3SoundManagerFf(&D_01E75640, 0.75f);
            self->field_4587 = 1;
        } else if (self->field_4587) {
            SetSlowMo__8CGtTimerFi(&D_00522660, 1);
            SetMasterPitchScalar__15CB3SoundManagerFf(&D_01E75640, 1.0f);
            self->field_4587 = 0;
        }
    }
    if (self->field_4586 && lCrashMode && (self->field_13FC & 1)) {
        (*(void (**)(void *, int))(*(char **)self + 0x28))(self, 0);
        self->field_3534 = D_00522680[0];
        AddCrashScore__13CB3CrashScoreF20ECrashModePickupTypei(&D_0064CE40, 1, self->field_1580->field_19AC);
        self->field_4586 = 0;
    }
    bool lGo;
    if (lSplit || (D_0051BA88.field_0 && D_0051BA88.field_0->field_1B4 && D_0051BA88.field_0->field_1B4->vfunc_C8()))
        lGo = self->field_4583 != 0 && (self->field_1530 < 5.0f || lBreaker);
    else
        lGo = self->field_4583 != 0 && lSlow && (self->field_1530 < 5.0f || lBreaker);
    if (lGo) {
    if (WAxisType(self->field_B0.mData) > 1.0f)
    if (GtMath::Abs(self->field_1408) + GtMath::Abs(self->field_140C) > 0.5f) {

    CGtQuat lQuat = UncompressRotation(self->field_1410);
    CGtMatrix3x4 lMatrix;
    lMatrix = lQuat.ConvertToMatrix();
    CGtV3d lRight = lMatrix.mRight;
    lRight.SetY(0.0f);
    lRight.Normalise();
    CGtV3d lAt = lMatrix.mAt;
    lAt.SetY(0.0f);
    lAt.Normalise();
    CGtV3d lAxis = lRight * -self->field_1408 + lAt * self->field_140C;
    lAxis.Normalise();
    if (self->field_3534 > 0.0f && lBreaker) {
        if (lSplit) self->field_B0.SetGtV3d(self->field_B0Vec() + lAxis * 0.25f);
        else self->field_B0.SetGtV3d(self->field_B0Vec() + lAxis * 0.15f);
    }
    CGtV3d lSide = CrossProduct(lUp, lAxis);
    float lrSide = DotProduct(self->field_C0, lSide);
    float lrAngle = GtMath::ACosDeg(DotProduct(self->field_C0, lAxis));
    if (lrSide > 0.0f) lrAngle *= -1.0f;
    if (GtMath::Abs(lrAngle) > 8.0f) {
        float lrMax;
        if (lSplit) lrMax = 0.75f / (1.0f + self->field_1530);
        else lrMax = 0.4f / (1.0f + self->field_1530);
        lrAngle = GtMath::Min(GtMath::Max(lrAngle, -lrMax), lrMax);
        CGtMatrix3x4 lRot;
        lRot = CreateRotationMatrix3x4(lUp, 0.017453292f * lrAngle);
        self->field_B0.SetGtV3d(TransformVector(lRot, self->field_B0Vec()));
        self->field_4585 = 1;
    }
    if (self->field_1540) {
        float lrTilt = func_001BB6E0_inl1(-0.5f * lrAngle, -1.2f, 1.2f);
        float lrNew = self->field_3538 + lrTilt;
        if (GtMath::Abs(lrNew) <= 17.0f) {
            CGtMatrix3x4 lTilt;
            lTilt = CreateRotationMatrix3x4(self->field_204->mAt, 0.017453292f * lrTilt);
            CGtV3d lPos = self->field_204->mPos;
            (*self->field_204 *= lTilt);
            self->field_204->mPos = lPos;
            self->field_3538 = lrNew;
        }
    }
}
}
}
