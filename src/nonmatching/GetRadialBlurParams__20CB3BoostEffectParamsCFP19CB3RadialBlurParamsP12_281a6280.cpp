// NONMATCHING: GetRadialBlurParams__20CB3BoostEffectParamsCFP19CB3RadialBlurParamsP12CB3PlayerCarP22CB3PlayerCameraManager -- retail 344 / ours 362 instructions, 489 in changed runs
// draftAM C-first: boost radial blur: centre (0.5, 0.5), radius lerp(1, 0.45, boost), UV scale lerp(0.995, 0.985, boost), amount lerp(0, 1, boost); with camera-manager bit 0x20 the centre x follows last frame's car velocity . camera right (clamped +-0.49, radius + 2.5 |d|, then the new velocity stored), else -(camera right . car forward) (radius + 4 |d|, the car's forward stored); the car's 0x200/0x2000 state into +0x30; radius / viewport width, +0xC x 0.75 x height / width; 362/344, calls identical (fabsf x2), non-stack stores identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; retail's five-register argument list (viewport in a2, car a3, camera manager t0: set by the caller func_0030A9D0, whose archive now matches exactly with it), the camera matrix through the header's CGtQuat::ConvertToMatrix (decoded from the same product sequence), the clamp senses (c.le 0.49 / bc1t keep, c.lt -0.49 / bc1f keep), unfused |d| x k + radius, the 1/width product order traced

// CB3BoostEffectParams::GetRadialBlurParams(...) const -- draftAM (C-first draft). 0x30ABA0, 0x560. [C] name: the mangled symbol;
// [C] five arguments (see the definition). Local names from the Revenge STABS of CB4BoostEffectParams::GetRadialBlurParams
// (B4BoostEffectParams.cpp: lpParams, lpViewport, lpCar, lpCamera, lrRadialBlurRadiusMax, lrRadialBlurUVScaleMax, lrAmount, lrB,
// lMatrix, lResult). Meanings of the fields [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

class CB3RadialBlurParams {
public:
    float field_0;                          // [G] blur centre x
    float field_4;                          // [G] blur centre y
    float field_8;                          // [G] radius (Revenge lrRadialBlurRadiusMax)
    float field_C;
    float field_10;                         // [G] UV scale (Revenge lrRadialBlurUVScaleMax)
    float field_14;
    float field_18;
    float field_1C;                         // [G] amount
    CGtV3d field_20;                        // [G] last frame's reference direction
    unsigned char field_30;                 // [G] the car's 0x200 / 0x2000 state bit
};
struct UnkStruct_0030ABA0_vp { unsigned char pad_0[0x70]; float field_70; float field_74; };   // [L] Revenge lpViewport
struct UnkStruct_0030ABA0_ph {              // [L] the player's car physics
    unsigned char pad_0[0xC0];
    CGtV3d field_C0;                        // [G] velocity
    unsigned char pad_D0[0x134];
    CGtMatrix3x4 * field_204;               // the car matrix
    unsigned char pad_208[0xF58];
    unsigned short field_1160;              // [G] state bits
};
struct UnkStruct_0030ABA0_pc { UnkStruct_0030ABA0_ph * field_0; unsigned char pad_4[0x2C]; };   // per player, 0x30
extern UnkStruct_0030ABA0_pc D_0055EFEC[];
extern "C" float fabsf(float);
class CB3PlayerCar { public: unsigned char pad_0[0x19AC]; signed char field_19AC; };   // player index
class CB3PlayerCameraManager {
public:
    unsigned char pad_0[0x210];
    CGtQuat field_210;                      // [G] camera orientation
    unsigned char pad_220[0x960];
    unsigned long field_B80;                // finished-behaviour bits
};
class CB3BoostEffectParams { public: unsigned char pad_0[0x4]; float field_4; };   // [G] boost amount 0..1

// [G] a lerp inline (retail's unfolded `0 + a + d * t`: the inline-parameter form; Revenge lrInterpolated / lrB locals)
static inline float func_0030ABA0_inl1(float a, float b, float t) { return a + (b - a) * t; }

// [C] retail's real argument list: a viewport between the params and the car (a2; Revenge's CB4BoostEffectParams::
// GetRadialBlurParams has it in its mangled name), the car in a3 and the camera manager in t0 (the caller func_0030A9D0 sets all
// five); retail's mangled name lists three, so the function is defined through its link name.
// 0x0030ABA0
extern "C" void GetRadialBlurParams__20CB3BoostEffectParamsCFP19CB3RadialBlurParamsP12CB3PlayerCarP22CB3PlayerCameraManager(
    const CB3BoostEffectParams * self, CB3RadialBlurParams * lpParams, UnkStruct_0030ABA0_vp * lpViewport, CB3PlayerCar * lpCar,
    CB3PlayerCameraManager * lpCamera)
{
    float lrAmount = self->field_4;
    lpParams->field_0 = 0.5f;
    lpParams->field_4 = 0.5f;
    float lrRadialBlurRadiusMax = func_0030ABA0_inl1(1.0f, 0.45f, lrAmount);
    lpParams->field_8 = lrRadialBlurRadiusMax;
    lpParams->field_C = lrRadialBlurRadiusMax;
    float lrRadialBlurUVScaleMax = func_0030ABA0_inl1(0.995f, 0.985f, lrAmount);
    lpParams->field_10 = lrRadialBlurUVScaleMax;
    lpParams->field_14 = lrRadialBlurUVScaleMax;
    lpParams->field_18 = 1.0f;
    lpParams->field_1C = func_0030ABA0_inl1(0.0f, 1.0f, lrAmount);
    if (lpCamera->field_B80 & 0x20) {
        CGtMatrix3x4 lMatrix = lpCamera->field_210.ConvertToMatrix();   // mPos never set (as the header's ConvertToMatrix)
        UnkStruct_0030ABA0_ph * ph = D_0055EFEC[lpCar->field_19AC].field_0;
        CGtV3d lVelocity = ph->field_C0;
        CGtMatrix3x4 lResult = lMatrix;
        CGtV3d lRight = lMatrix.mRight;
        unsigned short f = ph->field_1160;
        lpParams->field_30 = (f & 0x200) != 0 || (f & 0x2000) != 0;
        float lrB = (float)DotProduct(lpParams->field_20, lRight);
        if (!(lrB <= 0.49f))
            lrB = 0.49f;
        if (lrB < -0.49f)
            lrB = -0.49f;
        lpParams->field_0 = 0.5f + lrB;
        float a = fabsf(lrB);
        a *= 2.5f;
        lpParams->field_8 = lpParams->field_8 + a;
        lpParams->field_20 = lVelocity;
    } else {
        CGtMatrix3x4 lMatrix = lpCamera->field_210.ConvertToMatrix();
        UnkStruct_0030ABA0_ph * ph = D_0055EFEC[lpCar->field_19AC].field_0;
        CGtV3d lAt = ph->field_204->mAt;
        CGtMatrix3x4 lResult = lMatrix;
        CGtV3d lRight = lMatrix.mRight;
        unsigned short f = ph->field_1160;
        lpParams->field_30 = (f & 0x200) != 0 || (f & 0x2000) != 0;
        float lrB = (float)DotProduct(lRight, lAt) * -1.0f;
        if (!(lrB <= 0.49f))
            lrB = 0.49f;
        if (lrB < -0.49f)
            lrB = -0.49f;
        lpParams->field_0 = 0.5f + lrB;
        float a = fabsf(lrB);
        a *= 4.0f;
        lpParams->field_8 = lpParams->field_8 + a;
        lpParams->field_20 = lAt;
    }
    float lrRecip = 1.0f / lpViewport->field_70;
    lpParams->field_8 = lpParams->field_8 * lrRecip;
    lpParams->field_C = lpParams->field_C * (0.75f * (lrRecip * lpViewport->field_74));
}
