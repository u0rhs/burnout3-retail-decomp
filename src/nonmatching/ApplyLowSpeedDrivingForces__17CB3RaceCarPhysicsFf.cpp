// NONMATCHING: ApplyLowSpeedDrivingForces__17CB3RaceCarPhysicsFf -- retail 764 / ours 778 instructions, 465 in changed runs
// hard1 C-first: 4 sub-steps of a local x/z tyre model (SinCosFast2 heading/front-wheel axes, rear slip force 16 x min(mass,2000) x min(slip deg,3)/3 with drive/brake on wheel 3's spin, front lateral force 12 x .. /8 against the lateral velocity, velocity/yaw-rate/yaw integration), the slip flag +0x14A8, the change applied back as force +0xF0 and torque +0x100 (+ self-aligning term), two wheel spins from contact velocities, low-speed damping by 0.9; 778/764, calls identical, every FPU and VU arithmetic op count equal, non-stack stores as retail; left: frame 0x4E0 vs 0x670 (retail spills ~20 loop constants), the brake test laid out of line (one bc1t/bc1f swap), CGtV2d temporaries
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm region by region (Ghidra as a reading aid): every call with its float arguments (atan2f x2, cosf), every branch sense, every FPU/VU op count and the non-stack stores checked against retail; the wheel fields beyond the declared array are reached by offset

// CB3RaceCarPhysics::ApplyLowSpeedDrivingForces(float) -- hard1 (C-first draft; deferred-hard by draftAF). 0x1C38F0, 0xBF0.
// [C] name: the mangled symbol in retail's tables. Written from the retail asm region by region (Ghidra's draft as a reading
// aid). Field names are placeholders and every type is [G] (instruction widths).
// What it does [L] (meanings [G]): a low-speed driving model in the car's local x/z plane, integrated in 4 sub-steps of dt/4:
//  - the local velocity (car+0x70 rows x velocity) and the yaw rate (angular velocity . up); the steering angle
//    +0x1164 = -(+0x13B0 * +0x1408) (degrees: x 0.017453292 = pi/180);
//  - per sub-step: heading / front-wheel direction from SinCosFast2(yaw, yaw + steer), the rear and front contact velocities
//    (v -/+ yaw rate x side axis), a drive/brake torque on the rear wheel spin +0xABC (wheel 3; copied to wheel 2 and, with more
//    than 4 wheels, 4 and 5), the rear tyre force from the slip vector (longitudinal: along the heading minus wheel speed x
//    radius; lateral: along the side axis) scaled 16 x min(mass, 2000) x min(slip angle, 3 deg) / 3, the front tyre's lateral
//    force 12 x min(mass, 2000) x min(slip angle, 8 deg) / 8 (sign against the lateral velocity), then velocity, yaw rate and
//    yaw integrated;
//  - +0x14A8 = 1 when the last rear slip is more than half the local z velocity (the latter not effectively zero);
//  - the velocity / yaw-rate change applied back as force (+0xF0) and torque (+0x100, incl. a self-aligning term) about a
//    point 0.5 x +0x1370 below the body centre along up;
//  - the two wheels' spin speeds (+0x87C) from their contact point velocities (negated when moving backwards);
//  - below 0.2 speed with +0x211 and +0x14C8 clear: wheel spins zeroed, velocity and angular velocity damped by 0.9.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;

extern "C" float sqrtf(float);
extern "C" float cosf(float);
extern "C" float func_0011E358(float, float);   // [L] atan2f (as B3VehicleDeform_003E4AA0)
extern float D_004E069C;                        // 57.29578 (rad -> deg), a gp variable as in the proven units

struct UnkStruct_001C38F0_w {                   // per-wheel data (0xC0)
    float field_0;                              // radius
    unsigned char pad_4[0x8];
    float field_C;                              // spin speed
    unsigned char pad_10[0x14];
    float field_24;                             // contact height (local y)
    unsigned char pad_28[0x98];
};
struct UnkStruct_001C38F0_wp { unsigned char pad_0[0x30]; CGtV3d field_30; };   // wheel position (local)
class CB3RaceCarPhysics {
public:
    void ApplyLowSpeedDrivingForces(float);
    unsigned char pad_0[0x20];
    CGtV3d field_20;                            // y: inverse yaw inertia [G]
    unsigned char pad_30[0x40];
    CGtMatrix3x3 field_70;                      // world -> local rows
    unsigned char pad_A0[0x10];
    CGtV4d field_B0;                            // velocity, w = speed
    unsigned char pad_C0[0x10];
    CGtV3d field_D0;                            // angular velocity
    unsigned char pad_E0[0x10];
    CGtV3d field_F0;                            // force accumulator
    CGtV3d field_100;                           // torque accumulator
    unsigned char pad_110[0xE0];
    float field_1F0;                            // mass
    unsigned char pad_1F4[0x10];
    CGtMatrix3x4 *field_204;
    unsigned char pad_208[0x9];
    bool field_211;
    unsigned char pad_212[0x65E];
    UnkStruct_001C38F0_w field_870[6];
    unsigned char pad_CF0_dummy[0];
};
// the fields past the wheel array, by offset (the class above stops at the array; 0xCC8.. overlaps nothing it declares)
#define F_CC8(c, i) (((UnkStruct_001C38F0_wp **)((char *)(c) + 0xCC8))[i])
#define FF(c, o) (*(float *)((char *)(c) + (o)))
#define FI(c, o) (*(int *)((char *)(c) + (o)))
#define FS8(c, o) (*(signed char *)((char *)(c) + (o)))

// 0x001C38F0
void CB3RaceCarPhysics::ApplyLowSpeedDrivingForces(float dt)
{
    CGtMatrix3x4 *mat = field_204;
    CGtV3d right = mat->mRight;
    CGtV3d at = mat->mAt;
    CGtV3d up = mat->mUp;
    bool reversing = (float)DotProduct(at, *(const CGtV3d *)&field_B0) < 0.0f;
    float invI = (float)field_20.Y();
    float dt4 = dt / 4.0f;
    FI(this, 0x1524) = 0;
    float invMass = 1.0f / field_1F0;
    float yaw = 0.0f;
    FF(this, 0x1164) = -FF(this, 0x13B0) * FF(this, 0x1408);
    float r = (float)DotProduct(field_D0, up);
    float r0 = r;
    CGtV3d lv = TransformVector(field_70, *(const CGtV3d *)&field_B0);
    float v[2];                                 // local x / z velocity
    v[0] = (float)lv.X();
    v[1] = (float)lv.Z();
    float v0[2];
    v0[0] = v[0];
    v0[1] = v[1];
    float slip;
    for (int i = 0; i < 4; i++) {
        float f[2];
        f[0] = 0.0f;
        f[1] = 0.0f;
        float tq = 0.0f;
        CGtV4d s = SinCosFast2(yaw, yaw + 0.017453292f * FF(this, 0x1164));
        float sx = (float)s.X();
        float sy = (float)s.Y();
        float sz = (float)s.Z();
        float sw = (float)s.W();
        float nx = -sx;
        float rear[2], front[2], fside[2], side[2], fwd[2];
        rear[0] = v[0] - r * sy;
        front[0] = v[0] + r * sy;
        rear[1] = v[1] - r * nx;
        front[1] = v[1] + r * nx;
        fside[0] = sw;
        fside[1] = -sz;
        side[0] = sy;
        side[1] = nx;
        fwd[0] = sx;
        fwd[1] = sy;
        // drive / brake on the rear wheel spin
        float drive = FF(this, 0x1400) * FF(this, 0x1520);
        float brake = 0.0f;
        if (FF(this, 0x1400) < 0.1f && !((float)field_B0.W() <= 1.0f))
            brake = 0.5f * FF(this, 0x13CC) * (9.5492964f * FF(this, 0x149C)) / FF(this, 0x1480);
        if (FF(this, 0xABC) < 0.0f)
            drive = drive + 6000 * FF(this, 0x1404) * FF(this, 0x138C) - brake;
        else
            drive = drive - 5000 * FF(this, 0x1404) * FF(this, 0x138C) + brake;
        field_870[3].field_C = field_870[3].field_C + dt4 * (drive / 25.0f);
        // rear tyre
        float lat = side[1] * rear[1] + side[0] * rear[0];
        float lon = fwd[1] * rear[1] + fwd[0] * rear[0] - field_870[3].field_C * field_870[3].field_0;
        slip = sqrtf(lon * lon + lat * lat);
        if (slip == 0.0f) slip = 1e-12f;
        float m = GtMath::Min(field_1F0, 2000.0f);
        float k = 16.0f * m * (GtMath::Min(GtMath::Abs(D_004E069C * func_0011E358(slip, field_870[3].field_C * field_870[3].field_0)), 3.0f) / 3.0f);
        float flat = k * -lat / slip;
        float flon = k * -lon / slip;
        float fx = f[0] + flat * side[0] + flon * fwd[0];
        float fz = f[1] + flat * side[1] + flon * fwd[1];
        field_870[3].field_C = field_870[3].field_C - dt4 * (flon * field_870[3].field_0 / 25.0f);
        field_870[2].field_C = field_870[3].field_C;
        if (FS8(this, 0x1169) >= 5) {
            field_870[4].field_C = field_870[3].field_C;
            field_870[5].field_C = field_870[3].field_C;
        }
        tq = tq - flat;
        // front tyre (lateral only)
        float lat2 = fside[1] * front[1] + fside[0] * front[0];
        float m2 = GtMath::Min(field_1F0, 2000.0f);
        float k2 = 12.0f * m2 * (GtMath::Min(GtMath::Abs(D_004E069C * func_0011E358(lat2, sw * front[1] + sz * front[0])), 8.0f) / 8.0f);
        if (!(lat2 <= 0.0f)) k2 = k2 * -1.0f;
        f[0] = fx + k2 * fside[0];
        f[1] = fz + k2 * fside[1];
        tq = tq + k2 * cosf(0.017453292f * FF(this, 0x1164));
        v[0] = v[0] + dt4 * (invMass * f[0]);
        v[1] = v[1] + dt4 * (invMass * f[1]);
        r = r + dt4 * (tq * invI);
        yaw = yaw + r * dt4;
    }
    if (!GtMath::IsEffectivelyZero(v[1]) && !(GtMath::Abs(slip / v[1]) <= 0.5f))
        FI(this, 0x14A8) = 1;
    // the change applied back as a force and a torque
    float dr = r - r0;
    CGtV2d dv;
    dv.SetX(v[0] - v0[0]);
    dv.SetY(v[1] - v0[1]);
    float km = field_1F0 / dt;
    CGtV2d dvm = dv;
    dvm.SetX(dvm.X() * km);
    dvm.SetY(dvm.Y() * km);
    CGtV3d force = right * dvm.X() + at * dvm.Y();
    CGtV3d lever = up * (0.5f * -FF(this, 0x1370));
    field_F0 += force;
    CGtV3d p = field_204->mPos - lever;
    float ki = invI * dt;
    // fix1 (2026-11-09): [C] 0x1C4248..0x1C4270 / 0x1C42B0 lqc2 +0x100, vadd.xyz x3, sqc2: the torque's w lane stays as it
    // was (the port's per-call check: a full assignment wrote up's w products into +0x10C, 285 calls a race)
    field_100 += CrossProduct(p - field_204->mPos, force);
    field_100 += up * (dr / ki);
    field_100 += up * (FF(this, 0x13B8) * (-r * (FF(this, 0x13B4) - GtMath::Abs(FF(this, 0x1408)))) / ki);
    // wheel spins from the contact point velocities
    for (int j = 0; j < 2; j++) {
        CGtV3d wp = F_CC8(this, j)->field_30;
        wp.SetY(field_870[j].field_24);
        CGtMatrix3x4 *mm = field_204;
        CGtV3d rel = TransformPoint(*mm, wp) - mm->mPos;
        float sp = (float)(CrossProduct(field_D0, rel) + *(const CGtV3d *)&field_B0).GetLength();
        if (reversing)
            field_870[j].field_C = -sp / field_870[j].field_0;
        else
            field_870[j].field_C = sp / field_870[j].field_0;
    }
    if ((float)field_B0.W() < 0.2f && !field_211 && FI(this, 0x14C8) == 0) {
        for (int n = 0; n < FS8(this, 0x1169); n++)
            field_870[n].field_C = 0.0f;
        CGtV3dPlus &vp = *(CGtV3dPlus *)&field_B0;   // velocity and speed scaled lane-group-wise, as retail
        CGtV3dPlus nv = vp;
        nv.SetGtV3d(vp.GtV3d() * 0.9f);
        nv.SetPlus(nv.Plus() * 0.9f);
        vp = nv;
        field_D0 = field_D0 * 0.9f;
    }
}
