// NONMATCHING: UpdateFocus__13CB3ClusterRigFf -- retail 1671 / ours 1690 instructions, 1619 in changed runs
// draftB: written from the asm; 1694 vs 1671 instrs, calls and float-branch senses identical, frame 0x1530 vs 0x22E0; residue in header bodies (CreateRotationMatrix3x4 x3, operator* x3, OrthoNormalise) and look-at row stack homes | N266-N268 header APIs (gapH) | N275 header APIs (gapK)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm, every branch, call and store accounted for; local inlines (Invert, sign, dead zone, vsub.z negation, V4d*W) are behaviour-equivalent asm for header gaps

// CB3ClusterRig::UpdateFocus(float) -- draftB, written from the retail asm (0x358850, 0x1A1C).
// [C] name: the mangled symbol in retail's tables. Area not evidenced (B3BehaviourCluster.cpp per the sibling SetRig).
// Structure [C asm]: field_C8 (focus type, [L] EB3FocusType) 0 -> return; 1/2/3 -> rotate the camera matrix field_40
// towards field_84->field_40->field_204's position (local angles via the inverted camera matrix, atan2f/asinf), with an
// FOV update for 1/2 (atanf, krMin/Max/InterpFOV) and safe-zone dead zones (Soft/Hard by type), three inlined
// CreateRotationMatrix3x4 (up, right, at) and OrthoNormalise; 4/5/6 -> a focus point (target position / field_0 *
// mirrored field_A0 / a point on the field_90 sphere at angle field_C0, as PrepareRotate) and a kAxisY look-at matrix.
// Calls identical to retail [C calls.sh]; float branch senses identical; residue = scheduling/VU-GPR moves inside
// the header bodies (CreateRotationMatrix3x4, operator*, OrthoNormalise) and the look-at rows' stack homes.
// Revenge counterpart (UpdateFocus__13CB4ClusterRigf, 0x132C) is 27% smaller: STABS used as a hint only (the dead-zone
// and sign inlines, lCameraMatrixInverse).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

struct UnkStruct_00358850_2 {
    unsigned char pad_0[0x204];
    CGtMatrix3x4 * field_204;
};
struct UnkStruct_00358850_1 {
    unsigned char pad_0[0x40];
    UnkStruct_00358850_2 * field_40;
};

class CB3ClusterRig {
public:
    void UpdateFocus(float);

    CGtMatrix3x4 field_0;
    CGtMatrix3x4 field_40;      // camera matrix [G]
    unsigned char pad_80[0x4];
    UnkStruct_00358850_1 * field_84;
    unsigned char pad_88[0x8];
    CGtSphere field_90;
    CGtV3d field_A0;
    float field_B0;
    float field_B4;
    float field_B8;             // FOV [G]
    float field_BC;
    float field_C0;
    int field_C4;
    int field_C8;               // EB3FocusType [L] (PrepareRotate's parameter)
    int field_CC;
    unsigned char field_D0;
};

extern CGtV3d kAxisY;
extern float D_004E069C;        // 57.29578 (180/pi)
extern float krSafeFOVHorizSoft;
extern float krSafeFOVVertSoft;
extern float krWidthFOVSoft;
extern float krSafeFOVHorizHard;
extern float krSafeFOVVertHard;
extern float krWidthFOVHard;
extern float krMinFOV;
extern float krMaxFOV;
extern float krInterpFOV;
extern "C" float atanf(float);
extern "C" float func_0011E340(float);          // [L] asinf (E map, LIBM.A wf_asin.o)
extern "C" float func_0011E358(float, float);   // [L] atan2f (E map, LIBM.A wf_atan2.o)

// [G] stand-in for CGtMatrix3x4::Invert() (B3O0PCH map name, 524 bytes): orthonormal inverse = transposed rotation,
// position -(R^T p). Retail 0x359DF8..0x359E80.
static inline CGtMatrix3x4 func_00358850_inl3(const CGtMatrix3x4& m) {
    CGtMatrix3x4 r;
    u_long128 a = m.mRight.mData, b = m.mUp.mData, c = m.mAt.mData, p;
    u_long128 r0 = a, r1 = b, r2 = c;
    asm("vaddx.y %0, $vf0, %1x" : "+j"(r0) : "j"(b));
    asm("vaddy.x %0, $vf0, %1y" : "+j"(r1) : "j"(a));
    asm("vaddx.z %0, $vf0, %1x" : "+j"(r0) : "j"(c));
    asm("vaddy.z %0, $vf0, %1y" : "+j"(r1) : "j"(c));
    asm("vaddz.x %0, $vf0, %1z" : "+j"(r2) : "j"(a));
    asm("vaddz.y %0, $vf0, %1z" : "+j"(r2) : "j"(b));
    r.mRight.mData = r0; r.mUp.mData = r1; r.mAt.mData = r2;
    {
        u_long128 t0, t1, t2, pos = m.mPos.mData;
        asm("vmulz.xyz %0, %1, %2z" : "=j"(t2) : "j"(r2), "j"(pos));
        asm("vmuly.xyz %0, %1, %2y" : "=j"(t1) : "j"(r1), "j"(pos));
        asm("vmulx.xyz %0, %1, %2x" : "=j"(t0) : "j"(r0), "j"(pos));
        asm("vadd.xyz %0, %1, %2" : "=j"(t1) : "j"(t0), "j"(t1));
        asm("vadd.xyz %0, %1, %2" : "=j"(t1) : "j"(t1), "j"(t2));
        asm("vsub.xyz %0, $vf0, %1" : "=j"(p) : "j"(t1));
    }
    r.mPos.mData = p;
    return r;
}
// [L] sign of a float as +-1.0 through the bits (Revenge STABS: lrReal + USplitBits lSplitBits)
static inline float func_00358850_inl4(float v) {
    *(unsigned int *)&v = (*(unsigned int *)&v & 0x80000000) | 0x3F800000;
    return v;
}
// [L] dead zone: 0 inside +-lim, else moved towards 0 by lim (Revenge STABS: lrValue, lrAbs, then the sign inline)
static inline float func_00358850_inl7(float v, float lim) {
    float a = GtMath::Abs(v);
    if (a <= lim)
        return 0.0f;
    return v - lim * GtMath::Sign(v);
}
// [G] float exponent test (retail: (bits & 0x7F800000) < 0x37800001)
static inline bool func_00358850_inl5(float v) {
    union { float f; unsigned int u; } s;
    s.f = v;
    return (s.u & 0x7F800000) < 0x37800001;
}

// [G] stand-in: a matrix built from its four rows, returned by value (retail copies it through a temporary at 0x1F00)
static inline CGtMatrix3x4 func_00358850_inl6(CGtV3d right, CGtV3d up, CGtV3d at, CGtV3d pos) {
    CGtMatrix3x4 m;
    m.mRight = right;
    m.mUp = up;
    m.mAt = at;
    m.mPos = pos;
    return m;
}

// 0x00358850
void CB3ClusterRig::UpdateFocus(float aspect)
{
    if (field_C8 == 0)
        return;
    if (field_C8 == 1 || field_C8 == 2 || field_C8 == 3) {
        CGtMatrix3x4 inv = field_40;
        inv.Invert();
        ((float *)&inv.mPos)[3] = ((const float *)&field_40.mRight)[3]; // [C] 0x359DF8 lq a1, 0x40(s0) (mRight), 0x359E14 vmove.xyzw
        // vf1, vf6; 0x359E6C vmuly.xyz vf1, vf4, vf2y into it; 0x359E74/0x359E78 vadd.xyz and 0x359E7C vsub.xyz vf1, vf0, vf1 keep its w;
        // 0x359E80 sqc2 vf1, 0x22C0(sp) -- the port header's Invert gives the up row's w
        CGtV3d angles(0.0f, 0.0f, 0.0f);
        CGtMatrix3x4 * target = field_84->field_40->field_204;
        CGtV3d local = TransformPoint(inv, target->mPos);
        float len = local.GetLength();
        float angleY = D_004E069C * func_0011E358(local.X(), local.Z());
        float angleX = -(GtMath::ASinDeg(local.Y() / len));
        float horiz, vert;
        if (field_C8 == 2) {
            horiz = field_B8 * krSafeFOVHorizHard;
            vert = krSafeFOVVertHard * (field_B8 / aspect);
        } else {
            horiz = field_B8 * krSafeFOVHorizSoft;
            vert = krSafeFOVVertSoft * (field_B8 / aspect);
        }
        if (field_C8 == 1 || field_C8 == 2) {
            float width;
            if (field_C8 == 1)
                width = krWidthFOVSoft;
            else
                width = krWidthFOVHard;
            (target->mPos - field_40.mPos).GetLength();
            float fov = GtMath::Min(GtMath::Max(D_004E069C * atanf(width / (float)(target->mPos - field_40.mPos).GetLength()), krMinFOV), krMaxFOV);  // [C] retail FPU form, not a VU lane op: 0x358C78..0x359F28 div.s (the cast keeps the port's PS2 float model)
            field_B8 = field_B8 + krInterpFOV * (fov - field_B8);
            angleY = func_00358850_inl7(angleY, horiz);
        }
        if (GtMath::Abs(angleX) <= vert) {
            float cur = GtMath::ASinDeg(field_40.mAt.Y());
            float lim = angleX + vert * GtMath::Sign(cur);
            if (GtMath::Abs(cur) > GtMath::Abs(lim))
                angleX = lim;
            else
                angleX = cur;
        } else {
            angleX = angleX - vert * GtMath::Sign(angleX);
        }
        (target->mPos - field_40.mPos).GetLength();
        angles.SetX(angleX);
        angles.SetY(angleY);
        angles.SetZ(0.0f);
        CGtV3d pos = field_40.mPos;
        field_40.mPos.Zero();
        field_40 = field_40 * CreateRotationMatrix3x4(field_40.mUp, 0.017453292f * (float)angles.Y());
        field_40 = field_40 * CreateRotationMatrix3x4(field_40.mRight, 0.017453292f * (float)angles.X());
        float roll;
        if (func_00358850_inl5(field_40.mRight.Y())) {
            roll = 0.0f;
            if (DotProduct(field_40.mUp, kAxisY) < roll)
                roll = 180.0f;
        } else {
            roll = -(GtMath::ASinDeg(field_40.mRight.Y()));
        }
        field_40 = field_40 * CreateRotationMatrix3x4(field_40.mAt, 0.017453292f * roll);
        field_40.mPos = pos;
        field_40.OrthoNormalise();
        return;
    }
    CGtV3d focus;
    switch (field_C8) {
    case 4:
        focus = field_84->field_40->field_204->mPos;
        break;
    case 5: {
        CGtV3d v = field_A0;
        v.SetX(-v.X());
        v.SetZ(-v.Z());
        focus = TransformPoint(field_0, v);
        break;
    }
    case 6: {
        CGtSphere s = field_90;
        s.SetRadius(field_BC);
        CGtV4d sc = SinCosFast(0.017453292f * field_C0);
        CGtV3d r = CGtV3d(sc.mData) * s.Radius();
        CGtV3d p;
        p.SetX(r.X());
        p.SetY(0.0f);
        p.SetZ(r.Y());
        CGtMatrix3x4 m = field_0;
        m.mPos = s.Position();
        focus = TransformPoint(m, p);
        break;
    }
    }
    CGtMatrix3x3 r;
    r.mAt = focus - field_40.mPos;
    r.mAt.Normalise();
    r.mRight = CrossProduct(kAxisY, r.mAt);
    r.mRight.Normalise();
    r.mUp = CrossProduct(r.mAt, r.mRight);
    field_40 = func_00358850_inl6(r.mRight, r.mUp, r.mAt, field_40.mPos);
}
