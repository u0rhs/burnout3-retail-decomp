// NONMATCHING: RenderAmbientShadow__12CB3ShadowMgrFP25CB3VehicleEssentialParamsQ29GtMathPs26CGtV3dff -- retail 160 / ours 151 instructions, 135 in changed runs
// draftAN C-first: opacity 1 - min((distance - wheel radius) / 1.25, 1), nothing when <= 0; darkness min(1, krShadowDarkness x essential+0x60); shadow frame on the ground normal (right = normalise(normal x forward), up = normal, at = right x normal; returned by value from an inline, mPos copied unset then set to the car position lowered by the distance), the car's box (+0xE80 / +0xE90) and wheel base (z from wheels 1 and n-2) with y 0, scaled by 1 + 0.4 x height offset; RenderAmbientVehicleShadow(matrix, box, wheel base, opacity, darkness, height); 151/160, calls identical, VU/FPU op counts equal
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; register list from the mangled name (this unread), both min.s operand orders, the c.le/bc1f exit, the two cross products' operand order, each box lane source and the call's three floats traced; audit: only the opacity test's arm placement / return-path count

// RenderAmbientShadow__12CB3ShadowMgrFP25CB3VehicleEssentialParamsQ29GtMathPs26CGtV3dff -- draftAN (C-first draft). 0x303170,
// 0x280. [C] name: the mangled symbol (a member; this unread). Parameter / local names from Revenge STABS
// RenderAmbientShadow__12CB4ShadowMgr (B4Shadows.cpp: lpEssential, lWorldNormal, lrDistanceToWorld, lrHeightAboveGround,
// lrAmbientShadowDarkness, lrWheelRadius, krShadowDarkness, lrHeightAboveOffset, lrOpacity, lAmbientShadowTransform, lShadowBox,
// lWheelBase, lReturnMatrix) [L]; field names placeholders, meanings [G].
// What it does [L]: opacity = 1 - min((distance - wheel radius) / 1.25, 1); nothing when <= 0; else a shadow frame on the ground
// normal (right = normalise(normal x forward), at = right x normal, position = the car's lowered by the distance), the car's box
// and wheel base flattened (y 0) and scaled by 1 + 0.4 x the height offset, then CB3ShadowRenderer::RenderAmbientVehicleShadow.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct CGtAxisAlignedBox { CGtV3d mSup; CGtV3d mInf; };   // [L] Revenge layout (as Render__16CB3VehicleDeform's archive)
struct UnkStruct_00303170_ph {              // [G] the vehicle's physics / params (lpEssential + 0x40)
    unsigned char pad_0[0xD];
    signed char field_D;                    // [C] lb: wheel count [G]; wheel n-2's z is read
    unsigned char pad_E[0xA];
    float field_18;                         // [C] lrWheelRadius
    unsigned char pad_1C[0xB94];
    CGtV3d field_BB0[4];                    // [C] wheel positions (0x40 stride: CGtV3d + pad) [G]
};
class CB3VehicleEssentialParams {
public:
    unsigned char pad_0[0x20];
    CGtV3d field_20;                        // [G] forward axis
    CGtV3d field_30;                        // [G] position
    UnkStruct_00303170_ph *field_40;
    unsigned char pad_44[0x1C];
    float field_60;                         // [G] scaled by krShadowDarkness
};
class CB3ShadowMgr {
public:
    void RenderAmbientShadow(CB3VehicleEssentialParams *, CGtV3d, float, float);
};
extern float D_004E0FC0;                    // [L] Revenge `static RwReal krShadowDarkness` (3.3333333)
extern "C" void RenderAmbientVehicleShadow__17CB3ShadowRendererFRCQ29GtMathPs212CGtMatrix3x4RC17CGtAxisAlignedBoxRC17CGtAxisAlignedBoxfff(
    const CGtMatrix3x4 *, const CGtAxisAlignedBox *, const CGtAxisAlignedBox *, float, float, float);

static inline const CGtV3d &func_00303170_wheel(const UnkStruct_00303170_ph *p, int i)
{
    return *(const CGtV3d *)((const char *)p + 0xBB0 + i * 0x40);
}
// [G] Revenge lReturnMatrix: a frame from an up and a forward vector, returned by value (retail copies rows 1-3 with byte loops,
// the CGtMatrix3x4 copy); mPos is left unset [C] (copied as stack bytes, then overwritten by the caller)
static inline CGtMatrix3x4 func_00303170_inl1(CGtV3d up, CGtV3d fwd)
{
    CGtMatrix3x4 lReturnMatrix;
    lReturnMatrix.mUp = up;
    CGtV3d r = CrossProduct(up, fwd);
    r.Normalise();
    lReturnMatrix.mRight = r;
    lReturnMatrix.mAt = CrossProduct(r, up);
    return lReturnMatrix;
}

// 0x00303170
void CB3ShadowMgr::RenderAmbientShadow(CB3VehicleEssentialParams *lpEssential, CGtV3d lWorldNormal, float lrDistanceToWorld,
                                       float lrHeightAboveGround)
{
    float lrAmbientShadowDarkness = GtMath::Min(1.0f, D_004E0FC0 * lpEssential->field_60);
    float lrWheelRadius = lpEssential->field_40->field_18;
    float lrHeightAboveOffset = lrDistanceToWorld - lrWheelRadius;
    float lrOpacity = 1.0f - GtMath::Min(lrHeightAboveOffset / 1.25f, 1.0f);
    if (lrOpacity <= 0.0f)
        return;
    CGtMatrix3x4 lAmbientShadowTransform;
    lAmbientShadowTransform = func_00303170_inl1(lWorldNormal, lpEssential->field_20);
    CGtV3d lPos = lpEssential->field_30;
    lPos.SetY(lPos.Y() - lrDistanceToWorld);
    lAmbientShadowTransform.mPos = lPos;
    float lrScale = 1.0f + 0.4f * lrHeightAboveOffset;
    CGtAxisAlignedBox lShadowBox;
    lShadowBox.mInf = *(CGtV3d *)((char *)lpEssential->field_40 + 0xE90);
    lShadowBox.mInf.SetY(0.0f);
    CGtAxisAlignedBox lWheelBase;
    lWheelBase.mInf = lShadowBox.mInf;
    lShadowBox.mInf = lShadowBox.mInf * lrScale;
    lShadowBox.mSup = *(CGtV3d *)((char *)lpEssential->field_40 + 0xE80);
    lShadowBox.mSup.SetY(0.0f);
    lWheelBase.mSup = lShadowBox.mSup;
    lShadowBox.mSup = lShadowBox.mSup * lrScale;
    lWheelBase.mInf.SetZ(func_00303170_wheel(lpEssential->field_40, lpEssential->field_40->field_D - 2).Z());
    lWheelBase.mInf = lWheelBase.mInf * lrScale;
    lWheelBase.mSup.SetZ(func_00303170_wheel(lpEssential->field_40, 1).Z());
    lWheelBase.mSup = lWheelBase.mSup * lrScale;
    RenderAmbientVehicleShadow__17CB3ShadowRendererFRCQ29GtMathPs212CGtMatrix3x4RC17CGtAxisAlignedBoxRC17CGtAxisAlignedBoxfff(
        &lAmbientShadowTransform, &lShadowBox, &lWheelBase, lrOpacity, lrAmbientShadowDarkness, lrHeightAboveGround);
}
