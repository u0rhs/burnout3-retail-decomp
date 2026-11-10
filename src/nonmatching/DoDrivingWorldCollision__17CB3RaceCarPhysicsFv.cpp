// NONMATCHING: DoDrivingWorldCollision__17CB3RaceCarPhysicsFv -- retail 888 / ours 894 instructions, 676 in changed runs
// draftV: 888/894, 676 changed; calls identical, every FPU/VU op count equal (adda/msub, lane vsubx/vsubz/vaddx via GtMathPs2Quat.h operators), block layout as retail; residue: 2 flag tests retail materialises as bool (xori/sltiu/xori on field_1353&8, sltu on key&0x8000) that ours branches on directly, key zero-extends (andi 10 vs 7), lq+qmtc2 vs lqc2 operand loads in the header CrossProduct/TransformPoint, a dead W-lane read of field_B0 kept by retail, frame 0x7C0 vs 0xD20
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm with Revenge STABS names: callback data as read by the archived callee func_001C6210 (wall set / ground set), ground contact -> mean point, normal, impulse into field_194; wall contact -> horizontal normal, box-edge distance push (field_130), velocity damping (0.707 / player field_13A8 / 0.99), impulse at the contact applied (ApplyNonSpinoutPositionedImpulse or field_110), crash test (crash mode 10x/0.303x, else 27.5x/0.707x of field_1534) -> StartRaceCarCrashing, else score callback vfunc_6C

// DoDrivingWorldCollision__17CB3RaceCarPhysicsFv -- draftV (0x1C5430, 0xDE0) -- CB3RaceCarPhysics::DoDrivingWorldCollision()
// Written from the retail asm; Revenge STABS (B4RaceCarPhysics.cpp, CB4RaceCarPhysics::DoDrivingWorldCollision: lCallbackData,
// lpPlayerCarPhysics, lrAtWallDot, lrVelWallDot, lHorizCollisionNormal, lCSI, lrImpulseOverMass) as [L] structure.
// The contact callback data layout is the one the archived callee func_001C6210 reads (two contact sets: A = walls
// (centroid sum +0x40, normal min/max +0x70/+0x80, count +0xD0), B = ground (centroid sum +0x50, normal sum +0x60, count +0xD4),
// box +0xB0/+0xC0, smallest surface key +0xDC) [L]. Field types from instruction widths [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_001C5430_key { unsigned short lo : 8; unsigned short hi : 8; };
struct UnkStruct_001C5430_cb {
    CGtMatrix3x4 field_0;
    CGtV3d field_40;
    CGtV3d field_50;
    CGtV3d field_60;
    CGtV3d field_70;
    CGtV3d field_80;
    CGtV3d field_90;
    CGtV3d field_A0;
    CGtV3d field_B0;
    CGtV3d field_C0;
    int field_D0;
    int field_D4;
    void * field_D8;
    UnkStruct_001C5430_key field_DC;
};
struct UnkStruct_001C5430_tri { unsigned char pad[0x40]; };
struct UnkStruct_001C5430_soup { int field_0; UnkStruct_001C5430_tri * field_4; short * field_8; };
struct UnkStruct_001C5430_rc {
    unsigned char pad_0[0x10C0];
    unsigned char field_10C0[0x15BC - 0x10C0];
    unsigned char field_15BC;
    unsigned char pad_15BD[0x1914 - 0x15BD];
    int field_1914;
    unsigned char pad_1918[0x19AC - 0x1918];
    signed char field_19AC;
};
struct UnkStruct_001C5430_other {
    unsigned char pad_0[0x1618];
    unsigned char field_1618[6];
    unsigned char field_161E[0x19AC - 0x161E];
    signed char field_19AC;
};
struct UnkStruct_001C5430_self {
    unsigned char pad_0[0x40];
    CGtMatrix3x3 field_40;         // [G] inverse inertia (world)
    CGtMatrix3x4 field_70;
    CGtV3dPlus field_B0;           // [G] linear velocity, w = speed
    CGtV3d field_C0;
    CGtV3d field_D0;               // [G] angular velocity
    CGtV3d field_E0;
    CGtV3d field_F0;
    CGtV3d field_100;
    CGtV3d field_110;
    CGtV3d field_120;
    CGtV3d field_130;
    CGtV3d field_140;
    CGtV3d field_150;
    CGtV3d field_160;
    CGtV3d field_170;
    unsigned char pad_180[0x10];
    UnkStruct_001C5430_key field_190;
    unsigned char pad_192[2];
    float field_194;
    int field_198;
    unsigned char pad_19C[4];
    CGtV3d field_1A0;
    CGtV3d field_1B0;
    CGtV3d field_1C0;
    CGtV3d field_1D0;
    CGtV3d field_1E0;
    float field_1F0;               // [G] mass
    unsigned char pad_1F4[0xC];
    UnkStruct_001C5430_soup * field_200;
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[9];
    unsigned char field_211;
    unsigned char pad_212[0x1353 - 0x212];
    unsigned char field_1353;
    unsigned char pad_1354[0x13A8 - 0x1354];
    float field_13A8;
    unsigned char pad_13AC[0x13F4 - 0x13AC];
    UnkStruct_001C5430_rc * field_13F4;
    unsigned char pad_13F8[0x1404 - 0x13F8];
    float field_1404;
    unsigned char pad_1408[0x1434 - 0x1408];
    float field_1434;
    unsigned char pad_1438[0x14C8 - 0x1438];
    int field_14C8;
    unsigned char pad_14CC[0x1534 - 0x14CC];
    float field_1534;
    unsigned char pad_1538[6];
    unsigned char field_153E;
    unsigned char pad_153F[0x1590 - 0x153F];
    UnkStruct_001C5430_tri field_1590[(0x3510 - 0x1590) / 0x40];
    int field_3510;
    CGtV3d field_B0Vec() { return CGtV3d(field_B0.mData); }
};
struct UnkStruct_001C5430_csi { unsigned char field_0; unsigned char field_1; unsigned char pad_2[2]; int field_4; int field_8; int field_C; };
struct UnkStruct_001C5430_G { unsigned char pad_0[0x1B4]; void * field_1B4; };
struct UnkStruct_D_0051BA88_ddwc { UnkStruct_001C5430_G * field_0; int pad[3]; };
extern UnkStruct_D_0051BA88_ddwc D_0051BA88;
struct UnkStruct_001C5430_row { void * field_0; unsigned char pad_4[0x2C]; };
extern UnkStruct_001C5430_row D_0055EFEC[];
struct UnkStruct_001C5430_blk { unsigned char pad[0x10]; };
extern UnkStruct_001C5430_blk D_004EE040;
extern UnkStruct_001C5430_blk D_0055E948;

extern "C" void func_001C6210(UnkStruct_001C5430_self *, UnkStruct_001C5430_tri *, UnkStruct_001C5430_key, UnkStruct_001C5430_cb *);
extern "C" bool func_00131E40(void *);   // E map: CB3Game::IsCrashMode() [high, not a symbol]
extern "C" UnkStruct_001C5430_other * func_00155360(void *);
extern "C" float fabsf(float);
extern "C" void ApplyNonSpinoutPositionedImpulse__17CB3RaceCarPhysicsFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(UnkStruct_001C5430_self *, CGtV3d, CGtV3d);
extern "C" void StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(void *, void *, int, void *, void *);

// [G] placeholder: CGtV3dPlus scaled by a float, xyz through SetGtV3d and w by vmulx.w + vmove.w (no evidenced name).
static inline void func_001C5430_inl1(CGtV3dPlus& v, float f)
{
    v.SetGtV3d(CGtV3d(v.mData) * f);
    u_long128 s, t;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vmulx.w %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(s));
    asm("vmove.w %0, %1" : "+j"(v.mData) : "j"(t));
}
// [G] flag tests as bool inlines (retail materialises them: xori/sltiu/xori, sltu).
static inline bool func_001C5430_inl3(const UnkStruct_001C5430_self * self) { return (self->field_1353 & 8) == 8; }
static inline bool func_001C5430_inl4(const UnkStruct_001C5430_self * self) { return (*(const unsigned short *)&self->field_190 & 0x8000) != 0; }
// [G] the impulse along n at world point p (velocity at p, effective inverse mass).
static inline float func_001C5430_inl2(UnkStruct_001C5430_self * self, CGtV3d p, CGtV3d n)
{
    CGtV3d lVel = CrossProduct(self->field_D0, p - self->field_204->mPos) + self->field_B0Vec();
    float lrNum = DotProduct(n, lVel) * -1.0f;
    CGtV3d r = p - self->field_204->mPos;
    CGtV3d t = TransformVector(*(CGtMatrix3x4 *)&self->field_40, CrossProduct(r, n));
    XAxisType lrDen = DotProduct(CrossProduct(t, r), n);
    lrDen = lrDen + 1.0f / self->field_1F0;
    return lrNum / lrDen;
}

extern "C" int DoDrivingWorldCollision__17CB3RaceCarPhysicsFv(UnkStruct_001C5430_self * self)
{
    void * lpScore = D_0051BA88.field_0->field_1B4;
    if ((self->field_1353 & 1) == 1 || (self->field_1353 & 4) == 4) {
        self->field_198 = 0;
        return 0;
    }
    UnkStruct_001C5430_self * lpPlayerCarPhysics;
    if (self->field_13F4->field_1914 == 0) lpPlayerCarPhysics = self;
    else lpPlayerCarPhysics = 0;
    UnkStruct_001C5430_cb lCallbackData;
    lCallbackData.field_0 = self->field_70;
    lCallbackData.field_40.Zero();
    lCallbackData.field_50.Zero();
    lCallbackData.field_60.Zero();
    lCallbackData.field_70.Zero();
    lCallbackData.field_80.Zero();
    lCallbackData.field_90.Zero();
    lCallbackData.field_A0.Zero();
    lCallbackData.field_B0 = self->field_1D0;
    lCallbackData.field_C0 = self->field_1E0;
    *(unsigned short *)&lCallbackData.field_DC &= 0xFF00;
    lCallbackData.field_D0 = 0;
    lCallbackData.field_D4 = 0;
    lCallbackData.field_D8 = self;
    int lnIndex;
    for (lnIndex = 0; lnIndex < self->field_200->field_0; lnIndex++)
        func_001C6210(self, &self->field_200->field_4[lnIndex], *(UnkStruct_001C5430_key *)&self->field_200->field_8[lnIndex], &lCallbackData);
    if (lpPlayerCarPhysics && lpPlayerCarPhysics->field_3510 > 0) {
        int lnBefore = lCallbackData.field_D0;
        unsigned short lKey = 0;
        lKey &= 0xFF00;
        lKey |= 0x20;
        for (lnIndex = 0; lnIndex < lpPlayerCarPhysics->field_3510; lnIndex++)
            func_001C6210(self, &lpPlayerCarPhysics->field_1590[lnIndex], *(UnkStruct_001C5430_key *)&lKey, &lCallbackData);
        if (lnBefore < lCallbackData.field_D0)
            self->field_F0 += self->field_C0 * self->field_1F0 * -1000.0f;
    }
    self->field_198 = 0;
    if (lCallbackData.field_D0 == 0) {
        if (lCallbackData.field_D4 != 0) {
            lCallbackData.field_50 = lCallbackData.field_50 * (1.0f / (float)lCallbackData.field_D4);
            self->field_198 = 2;
            self->field_160 = TransformPoint(*self->field_204, lCallbackData.field_50);
            self->field_1A0 = self->field_160;
            self->field_1B0 = self->field_160;
            self->field_170 = lCallbackData.field_60;
            self->field_170.Normalise();
            self->field_190 = lCallbackData.field_DC;
            float lrImpulse = func_001C5430_inl2(self, self->field_160, self->field_170);
            fabsf(lrImpulse);
            self->field_194 = lrImpulse;
        }
        return lCallbackData.field_D0;
    }
    CGtV3d lHorizCollisionNormal = lCallbackData.field_70 + lCallbackData.field_80;
    if (lHorizCollisionNormal.GetSquaredLength() < 2.3283064e-10f) {
        if (DotProduct(self->field_204->mRight, lCallbackData.field_80) < 0.0f) lHorizCollisionNormal = lCallbackData.field_70;
        else lHorizCollisionNormal = lCallbackData.field_80;
    }
    lCallbackData.field_40 = lCallbackData.field_40 * (1.0f / (float)lCallbackData.field_D0);
    lHorizCollisionNormal.SetY(0.0f);
    lHorizCollisionNormal.Normalise();
    self->field_160 = lCallbackData.field_40;
    self->field_160.SetY((self->field_1D0.Y() - self->field_1E0.Y()) * 0.33f + self->field_1E0.Y());
    self->field_160 = TransformPoint(*self->field_204, self->field_160);
    self->field_170 = lHorizCollisionNormal;
    self->field_190 = lCallbackData.field_DC;
    self->field_194 = 0.0f;
    self->field_198 = 1;
    float lrDistance = GtMath::Abs(lCallbackData.field_40.X() - self->field_1D0.X());
    lrDistance = GtMath::Min(lrDistance, GtMath::Abs(lCallbackData.field_40.X() - self->field_1E0.X()));
    lrDistance = GtMath::Min(lrDistance, GtMath::Abs(lCallbackData.field_40.Z() - self->field_1D0.Z()));
    lrDistance = GtMath::Min(lrDistance, GtMath::Abs(lCallbackData.field_40.Z() - self->field_1E0.Z()));
    CGtV3d lProj = self->field_204->mRight * DotProduct(lHorizCollisionNormal, self->field_204->mRight)
                 + self->field_204->mAt * DotProduct(lHorizCollisionNormal, self->field_204->mAt);
    if (lProj.GetSquaredLength() < 2.3283064e-10f) return 0;
    self->field_170 = lProj;
    self->field_170.Normalise();
    self->field_130 += lProj * (1.5f * lrDistance);
    float lrVelWallDot = GtMath::Abs(DotProduct(lHorizCollisionNormal, self->field_C0));
    float lrAtWallDot = GtMath::Abs(DotProduct(lHorizCollisionNormal, self->field_204->mAt));
    if (!(GtMath::Abs(lrAtWallDot) <= 0.707f))
    {
        float lrScale = 1.0f;
        lrScale -= 0.1f * (lrAtWallDot - 0.707f);
        func_001C5430_inl1(self->field_B0, lrScale);
    }
    if (lpPlayerCarPhysics) {
        func_001C5430_inl1(self->field_B0, lpPlayerCarPhysics->field_13A8);
        if (lpPlayerCarPhysics->field_14C8 == -1) self->field_1434 *= -1.0f;
    } else if (!self->field_153E) {
        func_001C5430_inl1(self->field_B0, 0.99f);
    }
    CGtV3d lContact = TransformPoint(*self->field_204, lCallbackData.field_40);
    float lrImpulseOverMass = func_001C5430_inl2(self, lContact, self->field_170);
    fabsf(lrImpulseOverMass);
    lrImpulseOverMass /= self->field_1F0;
    if (!(lrImpulseOverMass <= 0.0f)) {
        float lrSpeed = GtMath::Min(WAxisType(self->field_B0.mData), 89.408f);
        float lrDot = GtMath::Min(0.9f, 1.75f * lrVelWallDot);
        float lrFactor = 1.0f - lrDot;
        lrFactor += 0.9f * (1.0f - lrSpeed / 89.408f);
        self->field_194 = 0.175f * (lrImpulseOverMass * self->field_1F0) * lrFactor;
        CGtV3d lDir = self->field_170 - self->field_204->mUp * DotProduct(self->field_204->mUp, self->field_170);
        lDir.Normalise();
        if (self->field_1404 <= 0.1f)
            ApplyNonSpinoutPositionedImpulse__17CB3RaceCarPhysicsFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(self, lContact, lDir * self->field_194);
        else
            self->field_110 += lDir * self->field_194;
    }
    bool lbCrash;
    if (func_00131E40(&D_004EE040)) {
        lbCrash = false;
        if (lrImpulseOverMass > 10.0f * self->field_1534 && lrAtWallDot > 0.303f * self->field_1534) lbCrash = true;
    } else {
        bool c = false;
        bool b = false;
        bool a = false;
        if (self->field_190.lo != 0x20 && !func_001C5430_inl3(self)) a = true;
        if (a && lrImpulseOverMass > 27.5f * self->field_1534) b = true;
        if (b && lrAtWallDot > 0.707f * self->field_1534) c = true;
        lbCrash = c;
    }
    if (self->field_13F4->field_1914 == 2) lbCrash = false;
    if (lbCrash) {
        UnkStruct_001C5430_csi lCSI;
        lCSI.field_0 = 1;
        lCSI.field_1 = 0;
        lCSI.field_4 = self->field_190.lo;
        lCSI.field_8 = 0;
        lCSI.field_C = 0;
        if (func_001C5430_inl4(self)) self->field_13F4->field_15BC = 1;
        else self->field_13F4->field_15BC = 0;
        StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(&D_0055E948, self, self->field_13F4->field_19AC, 0, &lCSI);
    } else if (self->field_211 == 1) {
        if (!(DotProduct(self->field_170, self->field_150 - lContact) < 0.0f)) {
            int lnCar = self->field_13F4->field_19AC;
            UnkStruct_001C5430_other * o = func_00155360(self->field_13F4->field_10C0);
            if (o) {
                if (!o->field_161E[lnCar] && !o->field_1618[lnCar]) {} else (*(void (**)(void *, int, void *, void *, float))(*(char **)lpScore + 0x6C))(lpScore, 2, D_0055EFEC[o->field_19AC].field_0, self, 1.0f);
            }
        }
    }
    return lCallbackData.field_D0;
}
