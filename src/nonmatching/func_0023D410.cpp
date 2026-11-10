// NONMATCHING: func_0023D410 -- retail 1001 / ours 951 instructions, 1128 in changed runs
// draftAE C-first: 951/1001; calls identical except retail's 7 out-of-line lane/vector ctors (func_0023E3C0 x4 in QueryRotate's Invert, func_0023E3D0 x3 in the normalises: inline-depth effect; scoped inline_depth(10) [G] here, depth 4-8 give 27-200 spurious calls) and the lookup's tail-duplicated VehicleIsValid; VU op counts agree except header operator+/- vmoves (12 vs 7); memory traffic lower (lqc2 34/58, sq 74/88: retail's out-of-line ctor results and temporaries). Left: frame 0x140 vs 0x1F90, three compare senses
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm lane by lane (record unpack/copy, lookup + CrashTrafficBody, inverse(current)*target, per-step delta, GtMathPs2::Slerp/QueryRotate/QueryRotateDegenerateUnitAxis inlined: stand-ins checked against RW 3.1 bamatrix.c and retail 0x23D7B0..0x23E364, range test); header Invert/SetIdentity/CreateRotationMatrix3x4/GetLength/Normalise/lane ops

// func_0023D410 -- draftAE (0x23D410, 0xFA4). Unnamed in every table, so the asm label with C linkage. [G] (draftD, func_0023C520's
// archive) the E-build CB3NetworkPlayer::ApplyTrafficCarData (dnat 0xFAC) -- name in comments only.
// Written from the retail asm (Ghidra as reading aid). [L] receives one crashing-traffic record from the network: unpacks it
// (func_001A8800), looks the traffic vehicle up, crashes its body locally (unless it is crashed already), and when the record's
// owner is the vehicle's controlling player appends it to the record list (+0x3CE0, 0xC0 each): the target matrix, its offset
// from the body's current matrix (inverse(current) * target), the per-step position delta, and the per-step rotation
// interpolated from the identity over field_6D6 steps (GtMathPs2::Slerp, inlined); field_3D91 marks a record to be blended
// (small position steps only), field_4EE4 = steps left.
// Local stand-ins for map-named GtMathPs2 functions the header lacks (header gap queued), bodies [L] from retail's inlined copy
// (0x23D7E8..0x23E364) and the RenderWare 3.1 MatrixQueryRotate / MatrixQueryRotateDegenerateUnitAxis they mirror:
//   func_0023D410_qrd  = GtMathPs2::QueryRotateDegenerateUnitAxis(const CGtMatrix3x4&, CGtV3d*)        (B3O0PCH 0x24DDD0, 0x5CC)
//   func_0023D410_qr   = GtMathPs2::QueryRotate(const CGtMatrix3x4&, CGtV3d*, float*, CGtV3d*)        (B3O0PCH 0x24D9D0, 0x3F8)
//   func_0023D410_slrp = GtMathPs2::Slerp(const CGtMatrix3x4&, const CGtMatrix3x4&, float, float*)   (B3O0PCH 0x24D530, 0x494)
// Types and field meanings [G] (instruction widths, use).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;
#pragma inline_depth(10)   // [G] N262/N182

extern "C" float func_0011E358(float, float);
// [G] GtMathPs2::operator -(XAxisType, float) (B3O0PCH 0x131C90, 0x50; header gap already queued, ApplyDrivingForces): the scalar
// moved into a VU register, `vsubx.x D, a, Sx` (retail 0x23D908)
static inline XAxisType func_0023D410_subxf(XAxisType a, float f) { u_long128 s, r; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s)); return XAxisType(r); }   // [L] libm atan2f (E_B3DEBUG wf_atan2.o at the same address)

static inline void func_0023D410_qrd(const CGtMatrix3x4 & m, CGtV3d * lpUnitAxis)
{
    CGtV3d lTwoSinThetaAxis;
    if (m.mRight.X() > m.mUp.Y()) {
        if (m.mRight.X() > m.mAt.Z()) {
            lTwoSinThetaAxis.SetX(m.mRight.X() + 1.0f);
            lTwoSinThetaAxis.SetX(lTwoSinThetaAxis.X() + lTwoSinThetaAxis.X());
            lTwoSinThetaAxis.SetY(m.mRight.Y() + m.mUp.X());
            lTwoSinThetaAxis.SetZ(m.mRight.Z() + m.mAt.X());
        } else {
            lTwoSinThetaAxis.SetZ(m.mAt.Z() + 1.0f);
            lTwoSinThetaAxis.SetZ(lTwoSinThetaAxis.Z() + lTwoSinThetaAxis.Z());
            lTwoSinThetaAxis.SetX(m.mAt.X() + m.mRight.Z());
            lTwoSinThetaAxis.SetY(m.mAt.Y() + m.mUp.Z());
        }
    } else {
        if (m.mUp.Y() > m.mAt.Z()) {
            lTwoSinThetaAxis.SetY(m.mUp.Y() + 1.0f);
            lTwoSinThetaAxis.SetY(lTwoSinThetaAxis.Y() + lTwoSinThetaAxis.Y());
            lTwoSinThetaAxis.SetZ(m.mUp.Z() + m.mAt.Y());
            lTwoSinThetaAxis.SetX(m.mUp.X() + m.mRight.Y());
        } else {
            lTwoSinThetaAxis.SetZ(m.mAt.Z() + 1.0f);
            lTwoSinThetaAxis.SetZ(lTwoSinThetaAxis.Z() + lTwoSinThetaAxis.Z());
            lTwoSinThetaAxis.SetX(m.mAt.X() + m.mRight.Z());
            lTwoSinThetaAxis.SetY(m.mAt.Y() + m.mUp.Z());
        }
    }
    lTwoSinThetaAxis.Normalise();
    *lpUnitAxis = lTwoSinThetaAxis;
}

static inline void func_0023D410_qr(const CGtMatrix3x4 & m, CGtV3d * lpUnitAxis, float * lpAngle, CGtV3d * lpCentre)
{
    float lrTwoCosTheta = func_0023D410_subxf(m.mRight.X() + m.mUp.Y() + m.mAt.Z(), 1.0f);
    CGtV3d lTwoSinThetaAxis;
    lTwoSinThetaAxis.SetX(m.mUp.Z() - m.mAt.Y());
    lTwoSinThetaAxis.SetY(m.mAt.X() - m.mRight.Z());
    lTwoSinThetaAxis.SetZ(m.mRight.Y() - m.mUp.X());
    float lrTwoSinTheta = lTwoSinThetaAxis.GetLength();
    if (lrTwoSinTheta > 0.0f) {
        *lpUnitAxis = lTwoSinThetaAxis * (1.0f / lrTwoSinTheta);
    } else {
        lpUnitAxis->Zero();
    }
    *lpAngle = 57.29578f * func_0011E358(lrTwoSinTheta, lrTwoCosTheta);
    if (lrTwoSinTheta <= 0.01f && lrTwoCosTheta <= 0.0f) {
        func_0023D410_qrd(m, lpUnitAxis);
    }
    CGtMatrix3x4 lISubMat;
    lISubMat.SetIdentity();
    lISubMat.mRight -= m.mRight;
    lISubMat.mUp -= m.mUp;
    lISubMat.mAt -= m.mAt;
    CGtMatrix3x4 lISubMatInverse = lISubMat;
    lISubMatInverse.Invert();
    *lpCentre = lISubMatInverse.mPos;
    *lpCentre += lISubMatInverse.mRight * m.mPos.X();
    *lpCentre += lISubMatInverse.mUp * m.mPos.Y();
    *lpCentre += lISubMatInverse.mAt * m.mPos.Z();
}

static inline CGtMatrix3x4 func_0023D410_slrp(const CGtMatrix3x4 & a, const CGtMatrix3x4 & b, float t, float * lpAngle)
{
    CGtMatrix3x4 lResult;
    if (t <= 0.0f) {
        lResult = a;
    } else if (t >= 1.0f) {
        lResult = b;
    } else {
        CGtMatrix3x4 lInv = a;
        lInv.Invert();
        CGtMatrix3x4 lDelta;
        lDelta = lInv * b;
        CGtV3d lAxis;
        CGtV3d lCentre;
        func_0023D410_qr(lDelta, &lAxis, lpAngle, &lCentre);
        if (*lpAngle < 2.0f) {
            lResult.mRight = a.mRight + (b.mRight - a.mRight) * t;
            lResult.mUp = a.mUp + (b.mUp - a.mUp) * t;
            lResult.mAt = a.mAt + (b.mAt - a.mAt) * t;
            lResult.mPos = a.mPos + (b.mPos - a.mPos) * t;
            lResult.mRight.Normalise();
            lResult.mUp.Normalise();
            lResult.mAt.Normalise();
        } else {
            lResult = a;
            lResult.mPos.Set(0.0f, 0.0f, 0.0f);
            lResult = lResult * CreateRotationMatrix3x4(lAxis, 0.017453292f * (*lpAngle * t));
            lResult.mPos = (b.mPos - a.mPos) * t + a.mPos;
        }
    }
    return lResult;
}

// [G] -5 <= v <= 5 (each lane of the per-step position delta)
static inline bool func_0023D410_inl1(float v) { return v <= 5.0f && v >= -5.0f; }

class CB3ActiveBody;
struct UnkStruct_0023D410_cb { unsigned char pad_0[0x204]; CGtMatrix3x4 * field_204; unsigned char pad_208[0x2223]; signed char field_242B; };
struct UnkStruct_0023D410_body { unsigned char pad_0[0xC]; UnkStruct_0023D410_cb * field_C; };   // [L] CB3ActiveBody (CrashTrafficBody's parameter)
// [C] layout: the record (as func_0023C520's archive): two matrices, three vectors, id, blend flag
struct UnkStruct_0023D410_ent {
    CGtMatrix3x4 field_0;           // [G] target matrix
    CGtMatrix3x4 field_40;          // [G] inverse(current) * target, then the per-step rotation
    CGtV3d field_80;                // [G] velocity
    CGtV3d field_90;                // [G] angular velocity
    CGtV3d field_A0;                // [G] per-step position delta
    unsigned char field_B0;         // [G] traffic vehicle id
    unsigned char field_B1;         // [G] blend
};   // 0xC0 with the 16-byte alignment
struct UnkStruct_0023D410_13F4 { unsigned char pad_0[0x19AC]; signed char field_19AC; };
struct UnkStruct_0023D410_6E0 { unsigned char pad_0[0x13F4]; UnkStruct_0023D410_13F4 * field_13F4; };
struct UnkStruct_0023D410 {
    unsigned char pad_0[0x6D6];
    short field_6D6;                // [G] blend steps
    unsigned char pad_6D8[0x8];
    UnkStruct_0023D410_6E0 * field_6E0;
    unsigned char pad_6E4[0x3CE0 - 0x6E4];
    UnkStruct_0023D410_ent field_3CE0[24];
    int field_4EE0;                 // [G] record count
    int field_4EE4;                 // [G] blend steps left
    unsigned char field_4EE8;       // [G] new records
};
struct UnkStruct_0023D410_tv { UnkStruct_0023D410_body * field_0; unsigned char pad_4[0x4]; unsigned char field_8; unsigned char pad_9[0x177]; };   // 0x180 per vehicle
struct UnkStruct_D_00522660 { unsigned char pad_0[0x1771C]; UnkStruct_0023D410_tv field_1771C[1]; };
class CB3TrafficSystem { public: bool VehicleIsValid(unsigned char p0); };
class CB3PhysicsManager { public: void CrashTrafficBody(CB3ActiveBody *, int, int, bool, bool, bool); };
class CGtNetworkPlayerManager { public: int GetPlayerIndexByID(int); };
struct UnkStruct_D_00527440 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00527440 D_00527440;
extern UnkStruct_D_00522660 D_00522660;
extern CB3PhysicsManager D_0055EF70;
extern CGtNetworkPlayerManager D_01E32AE0;
// [G] signatures from the call sites: the packet, then the record's id/flag bytes, matrix, two vectors, and the caller's a2
extern "C" void func_001A8800(void *, unsigned char *, CGtMatrix3x4 *, CGtV3d *, CGtV3d *, void *);
extern "C" int func_0022FBB0(UnkStruct_0023D410 *);   // [G] this machine's network player id

// as func_0023C520_inl1 / func_0023D0F0_inl1 (proven lookup shape)
static inline UnkStruct_0023D410_body * func_0023D410_inl2(unsigned char id)
{
    if (((CB3TrafficSystem *)&D_00527440)->VehicleIsValid(id)) {
        return D_00522660.field_1771C[id].field_0;
    }
    return 0;
}

extern "C" void func_0023D410(UnkStruct_0023D410 * self, void * lpPacket, void * p2)
{
    UnkStruct_0023D410_ent lEntry;
    self->field_4EE8 = 1;
    func_001A8800(lpPacket, &lEntry.field_B0, &lEntry.field_0, &lEntry.field_80, &lEntry.field_90, p2);
    unsigned char id = lEntry.field_B0;
    bool lbCrashed = (D_00522660.field_1771C[id].field_8 & 2) != 0;
    UnkStruct_0023D410_body * lpBody = func_0023D410_inl2(id);
    if (lpBody == 0)
        return;
    if (!lbCrashed) {
        D_0055EF70.CrashTrafficBody((CB3ActiveBody *)lpBody, D_01E32AE0.GetPlayerIndexByID(func_0022FBB0(self)),
                                    self->field_6E0->field_13F4->field_19AC, true, true, true);
    }
    UnkStruct_0023D410_cb * cb = lpBody->field_C;
    if (cb->field_242B != D_01E32AE0.GetPlayerIndexByID(func_0022FBB0(self)))
        return;

    self->field_3CE0[self->field_4EE0] = lEntry;
    UnkStruct_0023D410_ent * e = &self->field_3CE0[self->field_4EE0++];
    CGtMatrix3x4 * lpCurrent = cb->field_204;
    CGtMatrix3x4 lInv = *lpCurrent;
    lInv.Invert();
    e->field_40 = lInv * e->field_0;
    float lrStep = 1.0f / (float)self->field_6D6;
    CGtMatrix3x4 lIdentity;
    lIdentity.SetIdentity();
    e->field_A0 = (e->field_0.mPos - lpCurrent->mPos) * lrStep;
    float lrAngle;
    e->field_40 = func_0023D410_slrp(lIdentity, e->field_40, lrStep, &lrAngle);
    e->field_B1 = 1;
    CGtV3d d = e->field_A0;
    if (!(func_0023D410_inl1(d.X()) && func_0023D410_inl1(d.Y()) && func_0023D410_inl1(d.Z()))) {
        e->field_B1 = 0;
    }
    self->field_4EE4 = self->field_6D6;
}
