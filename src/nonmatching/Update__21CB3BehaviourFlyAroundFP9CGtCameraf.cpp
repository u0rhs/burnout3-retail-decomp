// NONMATCHING: Update__21CB3BehaviourFlyAroundFP9CGtCameraf -- retail 3570 / ours 3622 instructions, 4318 in changed runs
// draft1 first full draft: 3658/3570, frame 0x2F40 vs 0x6CE0. Counts agree (27 vrsqrt, 16 cross products, 88 trig ctc2, 26 FP compares, 7 GetPadControl + asinf/atan2f); missing retail's out-of-line CGtV4d __ml__/copy-ctor/XAxisType ctor calls (7: ConvertToMatrix call shape), one vsqrt (field_50 length), block layout and matrix copy loops. Stand-ins: CreateRotationMatrix3x4, orthonormal inverse, look-at, OrthoNormalise (local inlines) | N259: CreateRotationMatrix3x4 + lane ops via the header | N262: scoped #pragma inline_depth [G] (gapF) | N266-N268 header APIs (gapH) | N275 header APIs (gapK)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra as reading aid), every branch, call and store accounted for; rotation/ortho stand-ins decoded lane by lane

// draft1: CB3BehaviourFlyAround::Update(CGtCamera*, float) (0x2E90F0), written from the retail asm and the Ghidra draft.
// [L] a free-fly / orbit debug camera on the pad of controller field_60: field_74 is the mode (0 free, 1 attached rigidly to
// the target car, 2 following the target's position, 3 orbiting it), toggled by pad controls 0xE / 0xF.
// Types and field meanings [G] (instruction widths, use). Local stand-ins for GtMathPs2 inlines the headers lack:
//   inl1 = [L] the E map's GtMathPs2::CreateRotationMatrix3x4(CGtV3d, float) (1372 bytes): axis normalised, SinCosFast,
//          rows R = (xx k + c, xy k + z s, zx k - y s), U = (xy k - z s, yy k + c, yz k + x s), A = (zx k + y s, yz k - x s,
//          zz k + c), k = 1 - c, mPos zero (decoded at 0x2E9760.., same as func_00429BE0's archive);
//   inl2 = the orthonormal inverse (transposed rows, -(p . rows)) (0x2EAF2C..);
//   inl3 = a look-at (the E map's Matrix3x4SetLookAt(CGtV3d) would fit): right = Y x at normalised, up = at x right;
//   inl4 = [L] the E map's CGtMatrix3x4::OrthoNormalise() (1552 bytes): rows normalised keeping their lengths; if one is 0,
//          rebuilt from the other two; else the pair with the smallest |dot| is kept and the third and one of the pair
//          rebuilt by cross products (0x2EBED0..0x2EC438).
#include "b3/GtMath.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;
#pragma inline_depth(7)

class CGtCamera;
struct UnkStruct_002E90F0_cam {
    unsigned char pad_0[0x4];
    float field_4;              // [G] field of view, degrees (clamped 2..120)
    unsigned char pad_8[0x8];
    CGtQuatPos field_10;        // [L] the camera's orientation + position (0x10 quat, 0x20 pos)
};
struct UnkStruct_002E90F0_car {
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;      // [G] read as a matrix when the target changes (an inverse/world-to-local matrix?)
    unsigned char pad_B0[0x154];
    CGtMatrix3x4 * field_204;   // [G] the car's world matrix
};
struct UnkStruct_002E90F0_slot { UnkStruct_002E90F0_car * field_0; unsigned char pad_4[0x2C]; };
extern UnkStruct_002E90F0_slot D_0055EFEC[];
struct UnkStruct_002E90F0_pad { unsigned char pad_0[0x12C]; };      // [L] CB3ControllerMapping (GetPadControl's this)
struct UnkStruct_D_004F50C0 { unsigned char pad_0[0xD48]; UnkStruct_002E90F0_pad field_D48[1]; };
extern UnkStruct_D_004F50C0 D_004F50C0;
extern CGtV3d kAxisY;
// [L] CB3ControllerMapping::GetPadControl(EGtPS2DualShockDeviceControl, bool) (nahelam_check.csv, rejected there: placeholder)
extern "C" float func_0012FC30(void *, int, int);
extern "C" float func_0011E340(float);          // [L] libm asinf (E_B3DEBUG wf_asin.o at the same address)
extern "C" float func_0011E358(float, float);   // [L] libm atan2f (E_B3DEBUG wf_atan2.o)

class CB3BehaviourFlyAround {
public:
    void Update(CGtCamera * cam, float dt);

    unsigned char pad_0[0x10];
    CGtMatrix3x4 field_10;      // [G] the target's matrix last frame
    float field_50;             // [G] orbit distance
    float field_54;             // [G] orbit yaw, degrees
    float field_58;             // [G] auto-spin angle, degrees
    float field_5C;             // [G] orbit pitch, degrees
    signed char field_60;       // [G] controller index
    unsigned char pad_61[0x7];
    int field_68;               // [G] target car slot
    int field_6C;               // [G] target slot last frame
    unsigned char pad_70[0x4];
    int field_74;               // [G] mode 0..3
    unsigned char pad_78[0x10];
    unsigned char field_88;     // [G] 0: pitch inverted
    unsigned char field_89;     // [G] auto-spin in orbit mode
};

static inline CGtMatrix3x4 func_002E90F0_inl1_unused(CGtV3d axis, float angle)
{
    axis.Normalise();
    CGtV4d sc = SinCosFast(angle);
    float s = sc.f[0];
    float c = sc.f[1];
    float k = 1.0f - c;
    float x = axis.X(), y = axis.Y(), z = axis.Z();
    CGtMatrix3x4 m;
    m.mRight = CGtV3d(1.0f - (1.0f - x * x) * k, x * y * k + z * s, z * x * k - y * s);
    m.mUp = CGtV3d(x * y * k - z * s, 1.0f - (1.0f - y * y) * k, y * z * k + x * s);
    m.mAt = CGtV3d(z * x * k + y * s, y * z * k - x * s, 1.0f - (1.0f - z * z) * k);
    m.mPos.Zero();
    return m;
}

static inline CGtMatrix3x4 func_002E90F0_inl2(const CGtMatrix3x4 & m)
{
    CGtMatrix3x4 r;
    r.mRight = CGtV3d(m.mRight.X(), m.mUp.X(), m.mAt.X());
    r.mUp = CGtV3d(m.mRight.Y(), m.mUp.Y(), m.mAt.Y());
    r.mAt = CGtV3d(m.mRight.Z(), m.mUp.Z(), m.mAt.Z());
    float px = m.mPos.X(), py = m.mPos.Y(), pz = m.mPos.Z();
    r.mPos = -(r.mRight * px + r.mUp * py + r.mAt * pz);
    return r;
}

static inline CGtMatrix3x4 func_002E90F0_inl3(CGtV3d at, CGtV3d pos)
{
    CGtMatrix3x4 m;
    at.Normalise();
    CGtV3d right = CrossProduct(kAxisY, at);
    right.Normalise();
    m.mRight = right;
    m.mUp = CrossProduct(at, right);
    m.mAt = at;
    m.mPos = pos;
    return m;
}

static inline void func_002E90F0_inl4(CGtMatrix3x4 & m)
{
    float lr = m.mRight.NormaliseGetLength();
    float lu = m.mUp.NormaliseGetLength();
    float la = m.mAt.NormaliseGetLength();
    if (lr > 0.0f) {
        if (lu > 0.0f) {
            if (la > 0.0f) {
                float dx = GtMath::Abs(DotProduct(m.mUp, m.mAt));
                float dy = GtMath::Abs(DotProduct(m.mAt, m.mRight));
                float dz = GtMath::Abs(DotProduct(m.mRight, m.mUp));
                if (dx < dy) {
                    if (dx < dz) {
                        m.mRight = CrossProduct(m.mUp, m.mAt); m.mRight.Normalise();
                        m.mAt = CrossProduct(m.mRight, m.mUp); m.mAt.Normalise();
                    } else {
                        m.mAt = CrossProduct(m.mRight, m.mUp); m.mAt.Normalise();
                        m.mUp = CrossProduct(m.mAt, m.mRight); m.mUp.Normalise();
                    }
                } else if (dy < dz) {
                    m.mUp = CrossProduct(m.mAt, m.mRight); m.mUp.Normalise();
                    m.mRight = CrossProduct(m.mUp, m.mAt); m.mRight.Normalise();
                } else {
                    m.mAt = CrossProduct(m.mRight, m.mUp); m.mAt.Normalise();
                    m.mUp = CrossProduct(m.mAt, m.mRight); m.mUp.Normalise();
                }
            } else {
                m.mAt = CrossProduct(m.mRight, m.mUp); m.mAt.Normalise();
                m.mUp = CrossProduct(m.mAt, m.mRight); m.mUp.Normalise();
            }
        } else {
            m.mUp = CrossProduct(m.mAt, m.mRight); m.mUp.Normalise();
            m.mRight = CrossProduct(m.mUp, m.mAt); m.mRight.Normalise();
        }
    } else {
        m.mRight = CrossProduct(m.mUp, m.mAt); m.mRight.Normalise();
        m.mAt = CrossProduct(m.mRight, m.mUp); m.mAt.Normalise();
    }
}

// [L] +-1.0 with x's sign, through memory as retail (and 0x80000000, or 0x3F800000)
static inline float func_002E90F0_inl5(float x)
{
    union { float f; unsigned int u; } t;
    t.f = x;
    t.u = (t.u & 0x80000000) | 0x3F800000;
    return t.f;
}

// 0x002E90F0
void CB3BehaviourFlyAround::Update(CGtCamera * pcam, float dt)
{
    UnkStruct_002E90F0_cam * cam = (UnkStruct_002E90F0_cam *)pcam;
    float move = 0.0f, strafe = 0.0f, yaw = 0.0f, pitch = 0.0f;     // f26 f25 f24 f23
    float rise = 0.0f, fov = 0.0f, roll = 0.0f;                     // f22 f21 f20

    if (field_6C != field_68) {
        // the target changed: re-express the camera relative to the new target (0x2EA7EC..0x2EADCC)
        field_68 = field_68;
        CGtMatrix3x4 m = cam->field_10.ConvertToMatrix();
        m = m * D_0055EFEC[field_6C].field_0->field_70;
        m = m * *D_0055EFEC[field_68].field_0->field_204;
        field_6C = field_68;
        cam->field_10.SetFromMatrix(m);
    }

    UnkStruct_002E90F0_pad * pad = &D_004F50C0.field_D48[field_60];
    float p19 = func_0012FC30(pad, 0x19, 0);
    float p18 = func_0012FC30(pad, 0x18, 0);
    float p1B = func_0012FC30(pad, 0x1B, 0);
    float p1A = func_0012FC30(pad, 0x1A, 0);
    if (func_0012FC30(pad, 0xC, 0) == 0.0f) {
        move = p19; strafe = p18; pitch = p1B; yaw = p1A;
    } else {
        rise = p19; roll = p18; fov = p1B;
    }

    if (func_0012FC30(pad, 0xE, 1) != 0.0f) {
        if (field_74 == 3) {
            field_74 = 0;
        } else {
            field_74 = 3;
            // entering orbit mode: distance / pitch / yaw of the camera seen from the target (0x2EAE28..0x2EB27C)
            CGtMatrix3x4 * t = D_0055EFEC[field_68].field_0->field_204;
            CGtMatrix3x4 cm = cam->field_10.ConvertToMatrix();
            CGtMatrix3x4 l = func_002E90F0_inl3(t->mPos - cm.mPos, cm.mPos);
            CGtMatrix3x4 ti = *t;
            ti.Invert();
            CGtMatrix3x4 r = l * ti;
            field_50 = r.mPos.GetLength();
            field_5C = GtMath::ASinDeg((float)r.mPos.Y() / field_50);
            CGtV3d n = -r.mPos;
            field_54 = 57.29578f * func_0011E358(n.X(), n.Z());
        }
    }
    if (func_0012FC30(pad, 0xF, 1) != 0.0f) {
        if (field_74 == 2)
            field_74 = 1;
        else
            field_74 = 2;
    }

    CGtMatrix3x4 * t = D_0055EFEC[field_68].field_0->field_204;
    CGtMatrix3x4 m = cam->field_10.ConvertToMatrix();
    int mode = field_74;
    if (mode == 2) {
        m.mPos = m.mPos - field_10.mPos + t->mPos;
    } else if (mode == 1) {
        CGtMatrix3x4 fi = field_10;
        fi.Invert();
        m = m * fi;
        m = m * *t;
    } else if (mode == 3) {
        m = *t;
    }
    field_10 = *t;

    if (field_88 == 0)
        pitch = -pitch;

    if (field_74 == 3) {
        if (field_89 == 0) {
            field_50 = field_50 + 0.3f * -move;
            field_54 += yaw;
            field_5C += pitch;
            m.mPos = m.mAt * -field_50;
            m = m * CreateRotationMatrix3x4(t->mUp, 0.017453292f * field_54);
            m = m * CreateRotationMatrix3x4(m.mRight, 0.017453292f * field_5C);
            m.mPos = m.mPos + t->mPos;
        } else {
            field_58 += 3.0f;
            m.mPos = m.mAt * -field_50;
            m = m * CreateRotationMatrix3x4(t->mUp, 0.017453292f * field_54);
            m = m * CreateRotationMatrix3x4(m.mRight, 0.017453292f * field_5C);
            m = m * CreateRotationMatrix3x4(kAxisY, 0.017453292f * field_58);
            m.mPos = m.mPos + t->mPos;
        }
    } else {
        // free flight (0x2EB284..0x2EBECC); turn rates are signed squares of the stick
        float nstrafe = -strafe;
        float nyaw = -yaw;
        if (move != 0.0f)
            m.mPos += m.mAt * (50.0f * move * dt) * 0.3f;
        if (nstrafe != 0.0f)
            m.mPos += m.mRight * (50.0f * nstrafe * dt) * 0.6f;
        if (nyaw != 0.0f) {
            CGtV3d p = m.mPos;
            m.mPos.Zero();
            m = m * CreateRotationMatrix3x4(CGtV3d(0.0f, 1.0f, 0.0f),
                                       0.017453292f * (dt * (90.0f * (nyaw * nyaw * GtMath::Sign(nyaw)))));
            m.mPos = p;
        }
        if (pitch != 0.0f) {
            CGtV3d p = m.mPos;
            m.mPos.Zero();
            m = m * CreateRotationMatrix3x4(m.mRight,
                                       0.017453292f * (dt * (90.0f * (pitch * pitch * GtMath::Sign(pitch)))));
            m.mPos = p;
        }
        if (roll != 0.0f) {
            CGtV3d p = m.mPos;
            m.mPos.Zero();
            m = m * CreateRotationMatrix3x4(CGtV3d(0.0f, 0.0f, 1.0f),
                                       0.017453292f * (dt * (90.0f * (roll * roll * GtMath::Sign(roll)))));
            m.mPos = p;
        } else if (rise != 0.0f) {
            m.mPos += m.mUp * rise * dt * 20.0f;
        }
    }

    if (fov != 0.0f) {
        float f = cam->field_4 - fov;
        cam->field_4 = f;
        if (f < 2.0f)
            cam->field_4 = 2.0f;
        else if (f > 120.0f)
            cam->field_4 = 120.0f;
    }

    func_002E90F0_inl4(m);
    cam->field_10.SetFromMatrix(m);
}
