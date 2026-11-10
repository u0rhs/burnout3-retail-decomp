// NONMATCHING: Update__23CB3BehaviourInterpolateFP9CGtCameraf -- retail 360 / ours 358 instructions, 158 in changed runs
// draftAM C-first: camera transition between two key frames: clock by time source (own clock advanced by dt, or the manager's two clocks), ratio = (t - start) / duration, the "to" behaviour refreshes its key frame (vfunc 0x18); finished: spring to the target position (curve 2: krSpringCoeff x distance, krDamping) or snap, FOV set, the finished bit (64-bit) set, DeactivateBehaviour(10), both behaviours released; running: curve (linear / smoothstep / double smoothstep), the "from" behaviour refreshes, position by CatmullRom (curve 2) or Interpolate, orientation by Slerp (the header's, decoded from this function), FOV lerp; 358/360, calls identical (acosf = retail's func_0011E328, as the header's Slerp), non-stack stores identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; the case compares (time source 2/1/0, curve 3/1/2/0, both leaving the value unset otherwise), the finish test (c.lt ratio 1.0 / bc1t to the running path), the spring (as the CatmullRom archive's tail with d = target - camera), the 64-bit or (ld/dsllv/sd), the two field_4 byte clears and the FOV lerp traced
// Retail reads kept: lrTime is unset for a time source outside 0..2 and lrCatMullRomRatio for a curve outside 0..3.

// CB3BehaviourInterpolate::Update(CGtCamera*, float) -- draftAM (C-first draft). 0x3739C0, 0x5A0. [C] name: the mangled symbol;
// local names from the Revenge STABS of CB4BehaviourInterpolate::Update (B4BehaviourInterpolate.cpp: lrTimeStep, lrRatio,
// lrCatMullRomRatio, lpCamera). Layout as the Prepare / CatmullRom archives of the same class; the key-frame and camera layouts
// as Update__18CB3BehaviourEffect (FOV at +4, CGtQuatPos at +0x10). Meanings of the fields [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_003739C0_k {               // [L] a camera key frame (Revenge lapCameraKeyFrames: CB4CameraKeyFrame), 0x40
    unsigned char pad_0[0x4];
    float field_4;                          // [G] field of view
    unsigned char pad_8[0x8];
    CGtQuatPos field_10;                    // orientation (0x10), position (0x20)
    unsigned char pad_30[0x10];
};
struct UnkStruct_003739C0_b {               // [L] a camera behaviour (Revenge lpBehaviour: CB4BehaviourKeyFrame)
    // vptr at +0x0: placeholder virtuals by slot offset [G] (as the CatmullRom / Prepare archives)
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(void *);
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_003739C0_k *, float);   // [G] fills the key frame for this frame
    unsigned char field_4;                  // [G] in use
};
class CB3PlayerCameraManager {
public:
    void DeactivateBehaviour(int);
    unsigned char pad_0[0x240];
    UnkStruct_003739C0_b * field_240[0x250];
    unsigned long field_B80;                // [G] finished-behaviour bits
    float field_B88;                        // [G] clocks (time sources 0 and 1)
    float field_B8C;
};
class CGtCamera {
public:
    unsigned char pad_0[0x4];
    float field_4;                          // [G] field of view
    unsigned char pad_8[0x8];
    CGtQuatPos field_10;                    // [L] the camera's orientation + position
};
class CB3BehaviourInterpolate {
public:
    void CatmullRom(CGtV3d * pos, float lrRatio, float lrTimeStep);
    void Update(CGtCamera * lpCamera, float lrTimeStep);
    unsigned char pad_0[0x10];
    UnkStruct_003739C0_k field_10;          // from
    UnkStruct_003739C0_k field_50;          // to
    UnkStruct_003739C0_k field_90;          // spline neighbours (CatmullRom)
    UnkStruct_003739C0_k field_D0;
    CGtV3d field_110;                       // [G] spring velocity
    CB3PlayerCameraManager * field_120;
    float field_124;                        // [G] start time
    float field_128;                        // [G] duration
    float field_12C;                        // [G] own clock (time source 2)
    int field_130;                          // behaviour index (from)
    int field_134;                          // behaviour index (to)
    int field_138;
    int field_13C;
    int field_140;                          // [G] transition curve: 0/2 linear, 1 double smoothstep, 3 smoothstep; 2 also spline + spring
    int field_144;                          // [G] time source
};
extern float krSpringCoeff;
extern float krDamping;

// 0x003739C0
void CB3BehaviourInterpolate::Update(CGtCamera * lpCamera, float lrTimeStep)
{
    if (field_144 == 2)
        field_12C += lrTimeStep;
    float lrTime;                           // [C] unset for a time source other than 0..2 (retail reads the register as is)
    switch (field_144) {
    case 2:
        lrTime = field_12C;
        break;
    case 1:
        lrTime = field_120->field_B8C;
        break;
    case 0:
        lrTime = field_120->field_B88;
        break;
    }
    float lrRatio = (lrTime - field_124) / field_128;
    field_120->field_240[field_134]->vfunc_18(&field_50, lrTimeStep);
    if (!(lrRatio < 1.0f)) {
        if (field_140 == 2) {
            CGtV3d d = field_50.field_10.mPos - lpCamera->field_10.mPos;
            CGtV3d f(0.0f, 0.0f, 0.0f);
            CGtV3d dk = d * krSpringCoeff;
            f += dk * d.GetLength();
            f += -field_110 * krDamping;
            field_110 += f * lrTimeStep;
            lpCamera->field_10.mPos += field_110 * lrTimeStep;
        } else {
            lpCamera->field_10.mQuat = field_50.field_10.mQuat;
            lpCamera->field_10.mPos = field_50.field_10.mPos;
        }
        lpCamera->field_4 = field_50.field_4;
        field_120->field_B80 |= (unsigned long)1 << field_134;
        field_120->DeactivateBehaviour(10);
        field_120->field_240[field_130]->field_4 = 0;
        field_120->field_240[field_134]->field_4 = 0;
        return;
    }
    float lrCatMullRomRatio;                // [C] unset for a curve type other than 0..3 (retail keeps the caller's f22)
    switch (field_140) {
    case 3:
        lrCatMullRomRatio = (0.0f + 3.0f - 2.0f * lrRatio) * (lrRatio * lrRatio);
        break;
    case 1: {
        float s = (0.0f + 3.0f - 2.0f * lrRatio) * (lrRatio * lrRatio);
        lrCatMullRomRatio = (0.0f + 3.0f - 2.0f * s) * (s * s);
        break;
    }
    case 2:
        lrCatMullRomRatio = lrRatio;
        break;
    case 0:
        lrCatMullRomRatio = lrRatio;
        break;
    }
    field_120->field_240[field_130]->vfunc_18(&field_10, lrTimeStep);
    if (field_140 == 2)
        CatmullRom(&lpCamera->field_10.mPos, lrCatMullRomRatio, lrTimeStep);
    else
        lpCamera->field_10.mPos = Interpolate(field_10.field_10.mPos, field_50.field_10.mPos, lrCatMullRomRatio);
    lpCamera->field_10.mQuat = Slerp(field_10.field_10.mQuat, field_50.field_10.mQuat, lrCatMullRomRatio);
    lpCamera->field_4 = 0.0f + field_10.field_4 + lrCatMullRomRatio * (field_50.field_4 - field_10.field_4);
}
