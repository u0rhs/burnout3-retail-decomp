// NONMATCHING: PrepareFocus__13CB3ClusterRigFf -- retail 1097 / ours 1107 instructions, 1102 in changed runs
// draftK: 1107/1097, calls identical, every op count equal except VU memory moves (lq/lqc2/sq/sqc2) and 2 vmove; type dispatch [C]: one switch with case 3/2/1 (rotate, return) written first then 0+4/5/6 gives retail's beq order 1,2,3,6,5,4,0 (an || chain becomes a range test); residue in header bodies (CreateRotationMatrix3x4 x3, operator* x3) scheduling, d kept in a GPR where retail goes through the stack (X/Y/Z reads), frame 0xE00 vs 0x1730 | N275 header APIs (gapK)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm on UpdateFocus's pattern; every branch, call and store accounted for; stand-ins (vsub.z negation, V4d*W, sign, dead zone, exponent test, row builder) as in UpdateFocus's archive

// CB3ClusterRig::PrepareFocus(float) -- draftK, written from the retail asm (0x35A700, 0x1124) on the pattern of draftB's
// UpdateFocus archive (same class, same file; shared stand-ins copied with this function's placeholder prefix).
// [C] name: the mangled symbol in retail's tables. Structure [C asm]: field_C8 1/2/3 -> aim the camera matrix field_40 at
// field_84->field_40->field_204's position (world-space angles: atan2f, asinf or +-90 near the pole), FOV update for 1/2,
// vertical dead zone, horizontal safe-zone offset by side (DotProduct with field_0.mRight), three inlined
// CreateRotationMatrix3x4 (up, right, at) applied by operator*, the roll from asinf(mRight.Y); else a focus point
// (0/4 target, 5 mirrored field_A0, 6 a point on the field_90 sphere) and a kAxisY look-at matrix.
// Revenge counterpart (PrepareFocus__13CB4ClusterRigf, 0xD5C) is 28% smaller: STABS used as a hint only.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

struct UnkStruct_0035A700_2 {
    unsigned char pad_0[0x204];
    CGtMatrix3x4 * field_204;
};
struct UnkStruct_0035A700_1 {
    unsigned char pad_0[0x40];
    UnkStruct_0035A700_2 * field_40;
};

class CB3ClusterRig {
public:
    void PrepareFocus(float);

    CGtMatrix3x4 field_0;
    CGtMatrix3x4 field_40;      // camera matrix [G]
    unsigned char pad_80[0x4];
    UnkStruct_0035A700_1 * field_84;
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

// [L] stand-in: CGtV4d * WAxisType -> CGtV3d (as PrepareRotate's archive, func_0035B830_inl3)
static inline CGtV3d func_0035A700_inl1(CGtV4d a, WAxisType w) { u_long128 r; asm("vmulw.xyz %0, %1, %2w" : "=j"(r) : "j"(a.mData), "j"(w.lVector)); return CGtV3d(r); }
// [G] stand-in: ZAxisType negation as retail's vsub.z (header's operator- is vmulx.z by -1)
static inline ZAxisType func_0035A700_inl2(ZAxisType a) { u_long128 r; asm("vsub.z %0, $vf0, %1" : "=j"(r) : "j"(a.lVector)); return ZAxisType(r); }
// [L] sign of a float as +-1.0 through the bits (Revenge STABS: lrReal + USplitBits lSplitBits)
static inline float func_0035A700_inl4(float v) {
    *(unsigned int *)&v = (*(unsigned int *)&v & 0x80000000) | 0x3F800000;
    return v;
}
// [L] dead zone: 0 inside +-lim, else moved towards 0 by lim (Revenge STABS: lrValue, lrAbs, then the sign inline)
static inline float func_0035A700_inl7(float v, float lim) {
    float a = GtMath::Abs(v);
    if (a <= lim)
        return 0.0f;
    return v - lim * GtMath::Sign(v);
}
// [G] float exponent test (retail: (bits & 0x7F800000) < 0x37800001)
static inline bool func_0035A700_inl5(float v) {
    union { float f; unsigned int u; } s;
    s.f = v;
    return (s.u & 0x7F800000) < 0x37800001;
}

// [G] stand-in: a matrix built from its four rows, returned by value (retail copies it through a temporary at 0x1F00)
static inline CGtMatrix3x4 func_0035A700_inl6(CGtV3d right, CGtV3d up, CGtV3d at, CGtV3d pos) {
    CGtMatrix3x4 m;
    m.mRight = right;
    m.mUp = up;
    m.mAt = at;
    m.mPos = pos;
    return m;
}

// 0x0035A700
void CB3ClusterRig::PrepareFocus(float aspect)
{
    switch (field_C8) {
    case 3:
    case 2:
    case 1: {
        CGtMatrix3x4 * target = field_84->field_40->field_204;
        CGtV3d d = target->mPos - field_40.mPos;
        float len = d.GetLength();
        float angleY = D_004E069C * func_0011E358(d.X(), d.Z());
        float s = d.Y() / len;
        float angleX;
        if (func_0035A700_inl5(1.0f - GtMath::Abs(s)))
            angleX = 90.0f * GtMath::Sign(s);
        else
            angleX = GtMath::ASinDeg(s);
        angleX = -angleX;
        if ((unsigned int)(field_C8 - 1) < 2) {
            float width;
            if (field_C8 == 1)
                width = krWidthFOVSoft;
            else
                width = krWidthFOVHard;
            (target->mPos - field_40.mPos).GetLength();
            float fov = GtMath::Min(GtMath::Max(D_004E069C * atanf(width / (float)(target->mPos - field_40.mPos).GetLength()), krMinFOV), krMaxFOV);  // [C] retail FPU form, not a VU lane op: 0x35ABC0..0x35AD54 div.s (the cast keeps the port's PS2 float model)
            field_B8 = field_B8 + krInterpFOV * (fov - field_B8);
        }
        float horiz, vert;
        if (field_C8 == 2) {
            horiz = field_B8 * krSafeFOVHorizHard;
            vert = krSafeFOVVertHard * (field_B8 / aspect);
        } else {
            horiz = field_B8 * krSafeFOVHorizSoft;
            vert = krSafeFOVVertSoft * (field_B8 / aspect);
        }
        angleX = func_0035A700_inl7(angleX, vert);
        if ((unsigned int)(field_C8 - 1) < 2) {
            if (DotProduct(field_0.mRight, d) > 0.0f)
                angleY -= horiz;
            else
                angleY += horiz;
        }
        CGtV3d pos = field_40.mPos;
        field_40.mPos.Zero();
        field_40 = field_40 * CreateRotationMatrix3x4(field_40.mUp, 0.017453292f * angleY);
        field_40 = field_40 * CreateRotationMatrix3x4(field_40.mRight, 0.017453292f * angleX);
        float roll = -(GtMath::ASinDeg(field_40.mRight.Y()));
        field_40 = field_40 * CreateRotationMatrix3x4(field_40.mAt, 0.017453292f * roll);
        field_40.mPos = pos;
        return;
    }
    }
    CGtV3d focus;
    switch (field_C8) {
    case 0:
    case 4:
        focus = field_84->field_40->field_204->mPos;
        break;
    case 5: {
        CGtV3d v = field_A0;
        v.SetX(-v.X());
        v.SetZ(func_0035A700_inl2(v.Z()));
        focus = TransformPoint(field_0, v);
        break;
    }
    case 6: {
        CGtSphere s = field_90;
        s.SetRadius(field_BC);
        CGtV4d sc = SinCosFast(0.017453292f * field_C0);
        CGtV3d r = func_0035A700_inl1(sc, s.Radius());
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
    field_40 = func_0035A700_inl6(r.mRight, r.mUp, r.mAt, field_40.mPos);
}
