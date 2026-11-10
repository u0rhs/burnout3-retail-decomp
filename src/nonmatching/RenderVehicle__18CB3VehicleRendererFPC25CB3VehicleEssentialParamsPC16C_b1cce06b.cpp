// NONMATCHING: RenderVehicle__18CB3VehicleRendererFPC25CB3VehicleEssentialParamsPC16CB3VehicleParams11EVehicleLOD -- retail 1061 / ours 1050 instructions, 504 in changed runs
// retail 1061 / ours 1050, 504 changed; calls identical; every block, call, store and VU op from the asm. Inlines named from the B3O0PCH map (CreateRotationMatrixOnPrincipleAxisWithoutSinCos, SetGlassState as a switch, GetBodyPartPhysics/GetPartIndex/GetBodyPartType/GetHostVehicle). Left: VU register allocation and scheduling in the two rotations, frame 0x830 vs 0xAB0 (retail keeps more matrix temporaries), the bit loop's hoisted lqc2 operator* form (draftU dU13b/14 stand-in tried, not kept)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] logic decoded op by op from retail; asm helpers are exact VU equivalents (explosion-time single asm keeps the block inline)

// CB3VehicleRenderer::RenderVehicle(const CB3VehicleEssentialParams*, const CB3VehicleParams*, EVehicleLOD) -- draftU.
// Structure from the retail asm (0x21E6F0, 1061 instrs) [C]; locals named after Revenge's counterpart
// (B4VehicleRendererRuntimePS2.cpp RenderVehicle STABS: lMainMatrix, lFakeMatrix, lnIndex, lpVehicleData, lpLODData,
// lnVehicleLOD, lx16LitBits, laBitMatrices[8], lan8BodyPartIndices[8], larBodyPartDistances[8], lBitRes, lSphere,
// lWheelMatrix, lWheelRes, lBlurState, lPayloadRes, lOutMatrix) [L]. Callee identities: research/nahelam_check.csv
// (0x21F790 RenderDeformedObject, 0x21FBB0 RenderObject, 0x220040 BeginRenderingSingleVehicle) [L]; inline helpers:
// the B3O0PCH map emits after RenderVehicle CB3BodyPartPhysics::GetPartIndex/GetBodyPartType/GetHostVehicle,
// CB3PhysicsManager::GetBodyPartPhysics(int), CreateRotationMatrixOnPrincipleAxisWithoutSinCos(CGtV3d,float,float),
// CGtV3d::SetZ(WAxisType), operator-(WAxisType, X/Y/ZAxisType), CGtV3d::operator+=(WAxisType),
// CB3VehicleObject::SetGlassState(EVehicleGlassState) [C names]; bodies [L] from the retail ops. Field names placeholders.
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/GtMathPs2Quat.h"

using namespace GtMathPs2;

struct UnkStruct_0021E6F0_mesh {        // [G] CB3VehicleMesh (0x10 bytes)
    unsigned char pad_0[0xB];
    unsigned char field_B;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char pad_E[2];
};

class CB3VehicleObject {
public:
    unsigned char field_0;
    signed char field_1;                 // [G] glass mesh index
    unsigned char pad_2[2];
    UnkStruct_0021E6F0_mesh *field_4;
    // [C] name: B3O0PCH map (0x22BA80, 0x188 at -O0). [L] body: retail 0x21E8CC..0x21E984 / 0x21F004..0x21F0C8.
    void SetGlassState(int leState) {
        if (field_1 >= 0) {
            switch (leState) {
            case 1:
                field_4[field_1].field_B = 3;
                field_4[field_1].field_D = 0x48;
                break;
            case 2:
                field_4[field_1].field_B = 4;
                field_4[field_1].field_D = 0x80;
                break;
            default:
                field_4[field_1].field_B = 2;
                field_4[field_1].field_D = field_4[field_1].field_C;
                break;
            }
        }
    }
};

struct CB3VehicleLODData {
    CB3VehicleObject *field_0;           // [L] body
    CB3VehicleObject *field_4[6];        // [L] bits
    CB3VehicleObject *field_1C[3];       // [L] wheels by blur state
    CB3VehicleObject *field_28[1];       // [L] payload objects, count unknown
};

struct CGtTexture;

struct CB3VehicleData {
    unsigned char pad_0[0xC];
    signed char field_C;                 // [L] bit count
    signed char field_D;                 // [L] wheel count
    unsigned char pad_E[0xA];
    float field_18;
    float field_1C[6];
    float field_34[6];
    CB3VehicleLODData *field_4C[5];
    CGtTexture *field_60;
    unsigned char pad_64[0x16C0 - 0x64];
    int field_16C0;
};

class CB3VehicleEssentialParams {
public:
    CGtMatrix3x4 field_0;
    CB3VehicleData *field_40;
    float field_44;
    float field_48;
    float field_4C;
    float field_50;
    unsigned char pad_54[4];
    unsigned char field_58;
    signed char field_59;
    unsigned char pad_5A;
    signed char field_5B;                // [L] EGtIntersectionResult of the whole vehicle
};

struct UnkStruct_0021E6F0_pl {          // [G] payload entry (0x50 bytes)
    unsigned char pad_0[0xC];
    signed char field_C;
    unsigned char pad_D[3];
    CGtMatrix3x4 field_10;
};
struct UnkStruct_0021E6F0_p {
    signed char field_0;
    unsigned char pad_1[7];
    UnkStruct_0021E6F0_pl *field_8;
};

class CB3VehicleParams {
public:
    CGtMatrix3x4 field_0[6];
    CGtMatrix3x4 field_180[7];
    unsigned char pad_340[0x30];
    float field_370;
    unsigned char pad_374[0x4A0 - 0x374];
    int field_4A0;
    unsigned char pad_4A4[8];
    signed char field_4AC[6];
    signed char field_4B2[6];
    unsigned char pad_4B8[0x4E8 - 0x4B8];
    float field_4E8[6];
    CGtMatrix3x4 field_500[16];
    CGtMatrix3x4 field_900[7][2];
    unsigned char pad_C80[0x1000 - 0xC80];
    CGtV4d field_1000;
    unsigned char pad_1010[4];
    unsigned char field_1014;
    unsigned char field_1015;
    unsigned char pad_1016[5];
    unsigned char field_101B;
    unsigned char field_101C[6];
    unsigned char field_1022;
    unsigned char field_1023;
    UnkStruct_0021E6F0_p *field_1024;
};

struct UnkStruct_0021E6F0_hv {          // [G] host vehicle
    unsigned char pad_0[0xCC4];
    const CB3VehicleParams *field_CC4;
};

class CB3BodyPartPhysics {
public:
    unsigned char pad_0[0x204];
    CGtMatrix3x4 *field_204;
    unsigned char pad_208[0x2B0 - 0x208];
    UnkStruct_0021E6F0_hv *field_2B0;
    unsigned char pad_2B4[4];
    short field_2B8;
    unsigned char field_2BA;
    unsigned char pad_2BB[0x4E0 - 0x2BB];
    // [C] names: B3O0PCH map (0x22B4C0 0x24, 0x22B4F0 0x20, 0x22B510 0x1C). [L] bodies: one field read each.
    int GetPartIndex() { return field_2B8; }
    int GetBodyPartType() { return field_2BA; }
    UnkStruct_0021E6F0_hv *GetHostVehicle() { return field_2B0; }
};

extern unsigned long D_00648188[];      // [L] CB3PhysicsManager active body-part mask (D_0055EF70 + 0xE9218)
class CB3PhysicsManager {
public:
    unsigned char pad_0[0xD2900];
    CB3BodyPartPhysics field_D2900[64];
    // [C] name: B3O0PCH map (0x22B530, 0x7C). [L] body: retail 0x21F64C..0x21F6A4.
    CB3BodyPartPhysics *GetBodyPartPhysics(int i) {
        if (D_00648188[0] & ((unsigned long)1 << (long)i)) return &field_D2900[i];
        return 0;
    }
};
extern CB3PhysicsManager D_0055EF70;

struct UnkStruct_0021E6F0_cam2 { unsigned char pad_0[0x20]; CGtV3d field_20; };
struct UnkStruct_0021E6F0_cam { unsigned char pad_0[0x68]; UnkStruct_0021E6F0_cam2 *field_68; };
extern UnkStruct_0021E6F0_cam *D_00666270[];   // [L] lui/lw: not small data

extern float D_00522680[];   // [L] lui/lw: not a small-data symbol
extern float D_004E0C50;
extern float D_004E0E24;
extern float D_004E0E94;
extern CGtV3d D_004B9D90;
extern CGtV3d kRightAxis;

enum EVehicleLOD {};

class CB3VehicleRenderer {
public:
    void SetTexture(CGtTexture *, int);
    void RenderVehicle(const CB3VehicleEssentialParams *lpEssentialParams, const CB3VehicleParams *lpVehicleParams, EVehicleLOD leVehicleLOD);
    unsigned char pad_0[0xF8];
    int field_F8;
    signed char field_FC;
};

// [L] research/nahelam_check.csv: BeginRenderingSingleVehicle(const CB3VehicleEssentialParams*, CB3VehicleLODData*, float, float)
extern "C" void func_00220040(CB3VehicleRenderer *, const CB3VehicleEssentialParams *, CB3VehicleLODData *, float, float);
// [L] RenderDeformedObject(EB3VehicleRenderType, const CGtMatrix3x4&, CB3VehicleObject*, float, ushort, ushort, const CGtMatrix3x4*, int, bool)
extern "C" void func_0021F790(CB3VehicleRenderer *, int, const CGtMatrix3x4 &, CB3VehicleObject *, float, unsigned short, unsigned short, const CGtMatrix3x4 *, int, bool);
// [L] RenderObject(EB3VehicleRenderType, const CGtMatrix3x4&, CB3VehicleObject*, float, ushort, ushort, bool)
extern "C" void func_0021FBB0(CB3VehicleRenderer *, int, const CGtMatrix3x4 &, CB3VehicleObject *, float, unsigned short, unsigned short, bool);
// [L] the frustum sphere test (archived func_002202D0): 0 outside, 1 inside, else intersecting
extern "C" int func_002202D0(CGtSphere s);

// ---- header gaps (build/vt/header_queue.txt): lane ops CreateRotationMatrixOnPrincipleAxisWithoutSinCos inlines ----
// [C] API: B3O0PCH map 0x22BA30 CGtV3d::operator+=(WAxisType) (0x4C). [L] body: retail `vaddw.xyz $vf5,$vf5,$vf6w`.
static inline void func_0021E6F0_inl1(CGtV3d &v, WAxisType a) { asm("vaddw.xyz %0, %0, %1w" : "+j"(v.mData) : "j"(a.lVector)); }
// [C] API: B3O0PCH map 0x22B9E0/0x22B990/0x22B940 operator-(WAxisType, X/Y/ZAxisType) (0x50 each). [L] result in lane w.
static inline WAxisType func_0021E6F0_inl2(WAxisType a, XAxisType b) { u_long128 r; asm("vsubx.w %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return WAxisType(r); }
static inline WAxisType func_0021E6F0_inl3(WAxisType a, YAxisType b) { u_long128 r; asm("vsuby.w %0, %1, %2y" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return WAxisType(r); }
static inline WAxisType func_0021E6F0_inl4(WAxisType a, ZAxisType b) { u_long128 r; asm("vsubz.w %0, %1, %2z" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return WAxisType(r); }
// [C] API: B3O0PCH map 0x22B900 CGtV3d::SetZ(WAxisType) (0x38); SetX/SetY(WAxisType) [G] as it. [L] vaddw.<lane> from $vf0.
static inline void func_0021E6F0_inl5(CGtV3d &v, WAxisType a) { asm("vaddw.x %0, $vf0, %1w" : "+j"(v.mData) : "j"(a.lVector)); }
static inline void func_0021E6F0_inl6(CGtV3d &v, WAxisType a) { asm("vaddw.y %0, $vf0, %1w" : "+j"(v.mData) : "j"(a.lVector)); }
static inline void func_0021E6F0_inl7(CGtV3d &v, WAxisType a) { asm("vaddw.z %0, $vf0, %1w" : "+j"(v.mData) : "j"(a.lVector)); }
// [L] ZAxisType unary minus as retail here: `vsub.z D,$vf0,S` (the header's form is vmulx.z by -1.0)
static inline ZAxisType func_0021E6F0_inl8(ZAxisType a) { u_long128 r; asm("vsub.z %0, $vf0, %1" : "=j"(r) : "j"(a.lVector)); return ZAxisType(r); }

// [G] `float(x - v.W())` as one asm statement: the header's two-statement operator-(float, WAxisType) + XAxisType::operator
// float put the enclosing if-block out of line at the function end (dU6/dU8 probes); this keeps it inline as retail.
static inline float func_0021E6F0_inl9(float x, const CGtV4d &v) {
    float r;
    asm("qmtc2.ni %1, $vf2\n\tvsubw.x $vf1, $vf2, %2w\n\tqmfc2.ni $2, $vf1\n\tmtc1 $2, %0" : "=f"(r) : "r"(x), "j"(v.mData) : "$2");
    return r;
}

// [C] name/signature: B3O0PCH map (0x22B5C0, 0x338). [L] body: retail 0x21E984.. (axis-aligned: no cross terms; 1 - (1-a)k
// on the diagonal, the axis*sin terms off it). lSinCosOneMinusCosOne / lRotateMatrix: Revenge STABS [L].
static inline CGtMatrix3x4 CreateRotationMatrixOnPrincipleAxisWithoutSinCos(CGtV3d axis, float lrSin, float lrCos)
{
    CGtMatrix3x4 lRotateMatrix;
    CGtV4d lSinCosOneMinusCosOne;
    lSinCosOneMinusCosOne.SetX(lrSin);
    lSinCosOneMinusCosOne.SetY(lrCos);
    lSinCosOneMinusCosOne.SetZ(1.0f - lrCos);
    lSinCosOneMinusCosOne.SetA(1.0f);
    CGtV3d lTemp = -axis;
    func_0021E6F0_inl1(lTemp, lSinCosOneMinusCosOne.W());
    lTemp *= lSinCosOneMinusCosOne.Z();
    CGtV3d lAxisSin = axis * lSinCosOneMinusCosOne.X();
    func_0021E6F0_inl5(lRotateMatrix.mRight, func_0021E6F0_inl2(lSinCosOneMinusCosOne.W(), lTemp.X()));
    lRotateMatrix.mRight.SetY(lAxisSin.Z());
    lRotateMatrix.mRight.SetZ(-lAxisSin.Y());
    lRotateMatrix.mUp.SetX(func_0021E6F0_inl8(lAxisSin.Z()));
    func_0021E6F0_inl6(lRotateMatrix.mUp, func_0021E6F0_inl3(lSinCosOneMinusCosOne.W(), lTemp.Y()));
    lRotateMatrix.mUp.SetZ(lAxisSin.X());
    lRotateMatrix.mAt.SetX(lAxisSin.Y());
    lRotateMatrix.mAt.SetY(-lAxisSin.X());
    func_0021E6F0_inl7(lRotateMatrix.mAt, func_0021E6F0_inl4(lSinCosOneMinusCosOne.W(), lTemp.Z()));
    lRotateMatrix.mPos.Zero();
    return lRotateMatrix;
}

// [G] EB3VehicleRenderType from an EGtIntersectionResult: fully inside (1) -> 2 (no clipping), else 0
void CB3VehicleRenderer::RenderVehicle(const CB3VehicleEssentialParams *lpEssentialParams, const CB3VehicleParams *lpVehicleParams, EVehicleLOD leVehicleLOD)
{
    unsigned short lx16LitBits;
    CB3VehicleData *lpVehicleData;
    CGtMatrix3x4 lMainMatrix;
    CGtMatrix3x4 lFakeMatrix;
    CGtMatrix3x4 laBitMatrices[8];
    signed char lan8BodyPartIndices[8];
    float larBodyPartDistances[8];
    CB3VehicleLODData *lpLODData;
    int lnVehicleLOD;
    int lnIndex;

    lx16LitBits = lpEssentialParams->field_58 & 0xFC;
    field_F8 = lpVehicleParams->field_4A0;
    lpVehicleData = lpEssentialParams->field_40;
    field_FC = lpEssentialParams->field_59;
    lMainMatrix = lpEssentialParams->field_0;
    if (lpEssentialParams->field_5B == 0 && lpVehicleParams->field_1022 == 0) return;

    lnVehicleLOD = leVehicleLOD;
    lpLODData = lpVehicleData->field_4C[lnVehicleLOD];
    while (lpLODData == 0 && lnVehicleLOD < 4) {
        lnVehicleLOD++;
        lpLODData = lpVehicleData->field_4C[lnVehicleLOD];
    }
    while (lpLODData == 0 && lnVehicleLOD > 0) {
        lnVehicleLOD--;
        lpLODData = lpVehicleData->field_4C[lnVehicleLOD];
    }

    float lrShininessScale = 1.0f;       // [G] which Revenge scale is which
    float lrLightingScale = lrShininessScale;
    if (lpVehicleParams->field_101B) lrShininessScale = 1.0f - D_004E0E94 * lpVehicleParams->field_370;
    if (lpVehicleParams->field_1015 & 0x10) {
        float lrTimeSinceExplosion = func_0021E6F0_inl9(D_00522680[0], lpVehicleParams->field_1000);
        if (lrTimeSinceExplosion <= D_004E0C50) {
            lrLightingScale *= 1.0f - 1.875f * lrTimeSinceExplosion;
            lrShininessScale *= 1.0f - 2.25f * lrTimeSinceExplosion;
        } else {
            lrLightingScale *= 0.25f;
            lrShininessScale *= D_004E0E24;
        }
    }
    func_00220040(this, lpEssentialParams, lpLODData, lrShininessScale, lrLightingScale);
    SetTexture(lpVehicleData->field_60, lpEssentialParams->field_59);
    lpLODData->field_0->SetGlassState(lpVehicleParams->field_1014);

    lFakeMatrix = CreateRotationMatrixOnPrincipleAxisWithoutSinCos(D_004B9D90, lpEssentialParams->field_44, lpEssentialParams->field_48) * lMainMatrix;
    CGtMatrix3x4 lRotationMatrix = CreateRotationMatrixOnPrincipleAxisWithoutSinCos(kRightAxis, lpEssentialParams->field_4C, lpEssentialParams->field_50);
    lFakeMatrix = lRotationMatrix * lFakeMatrix;
    lMainMatrix = lFakeMatrix;

    int lRes = lpEssentialParams->field_5B;
    if (lRes) {
        if (lpVehicleParams->field_101B)
            func_0021F790(this, lRes == 1 ? 2 : 0, lMainMatrix, lpLODData->field_0, 1.0f, 0xFF, lx16LitBits, lpVehicleParams->field_500, 8, true);
        else
            func_0021FBB0(this, lRes == 1 ? 2 : 0, lMainMatrix, lpLODData->field_0, 1.0f, 0xFF, lx16LitBits, true);
    }

    CGtV3d lCameraPos = D_00666270[0]->field_68->field_20;
    for (lnIndex = 0; lnIndex < lpVehicleData->field_C; lnIndex++) {
        if (lpVehicleParams->field_4B2[lnIndex] >= 3) {
            laBitMatrices[lnIndex] = lpVehicleParams->field_180[lnIndex];
        } else {
            laBitMatrices[lnIndex] = lpVehicleParams->field_180[lnIndex] * lMainMatrix;
        }
    }
    for (lnIndex = 0; lnIndex < lpVehicleData->field_C; lnIndex++) {
        lan8BodyPartIndices[lnIndex] = lnIndex;
        larBodyPartDistances[lnIndex] = (laBitMatrices[lnIndex].mPos - lCameraPos).GetSquaredLength();
    }
    for (lnIndex = 0; lnIndex < lpVehicleData->field_C; lnIndex++) {
        for (int lnIndex2 = lnIndex + 1; lnIndex2 < lpVehicleData->field_C; lnIndex2++) {
            if (larBodyPartDistances[lnIndex] < larBodyPartDistances[lnIndex2]) {
                float lrTemp = larBodyPartDistances[lnIndex];
                larBodyPartDistances[lnIndex] = larBodyPartDistances[lnIndex2];
                larBodyPartDistances[lnIndex2] = lrTemp;
                signed char ln8Temp = lan8BodyPartIndices[lnIndex];
                lan8BodyPartIndices[lnIndex] = lan8BodyPartIndices[lnIndex2];
                lan8BodyPartIndices[lnIndex2] = ln8Temp;
            }
        }
    }

    for (int lnBit = 0; lnBit < lpVehicleData->field_C; lnBit++) {
        int lnPart = lan8BodyPartIndices[lnBit];
        int lBitRes;
        switch (lpVehicleParams->field_4B2[lnPart]) {
        case 3: {
            CGtSphere lSphere;
            lSphere.SetPosition(laBitMatrices[lnPart].mPos);
            lSphere.SetRadius(lpVehicleData->field_34[lnPart]);
            lBitRes = func_002202D0(lSphere);
            if (lBitRes == 0) continue;
            break;
        }
        case 4:
            continue;
        default:
            lBitRes = lpEssentialParams->field_5B;
            break;
        }
        lpLODData->field_4[lnPart]->SetGlassState(lpVehicleParams->field_1014);
        if (lBitRes) {
            if (lpVehicleParams->field_101C[lnPart])
                func_0021F790(this, lBitRes == 1 ? 2 : 0, laBitMatrices[lnPart], lpLODData->field_4[lnPart], 1.0f, 0x3FF, lx16LitBits, lpVehicleParams->field_900[lnPart], 2, false);
            else
                func_0021FBB0(this, lBitRes == 1 ? 2 : 0, laBitMatrices[lnPart], lpLODData->field_4[lnPart], 1.0f, 0x3FF, lx16LitBits, false);
        }
    }

    lRes = lpEssentialParams->field_5B;
    if (lRes) {
        lMainMatrix = lFakeMatrix;
        if (lpVehicleParams->field_101B)
            func_0021F790(this, lRes == 1 ? 2 : 0, lMainMatrix, lpLODData->field_0, 1.0f, 0x300, lx16LitBits, lpVehicleParams->field_500, 8, true);
        else
            func_0021FBB0(this, lRes == 1 ? 2 : 0, lMainMatrix, lpLODData->field_0, 1.0f, 0x300, lx16LitBits, true);
    }
    lMainMatrix = lpEssentialParams->field_0;

    for (lnIndex = 0; lnIndex < lpVehicleData->field_D; lnIndex++) {
        CGtMatrix3x4 lWheelMatrix = lpVehicleParams->field_0[lnIndex];
        int lWheelRes = lpEssentialParams->field_5B;
        int lBlurState = 0;
        if (lpVehicleParams->field_4AC[lnIndex] == 3) {
            CGtSphere lSphere;
            lSphere.SetPosition(lWheelMatrix.mPos);
            lSphere.SetRadius(lpVehicleData->field_18 * lpVehicleData->field_1C[lnIndex]);
            lWheelRes = func_002202D0(lSphere);
            if (lWheelRes == 0) continue;
        } else {
            lWheelMatrix = lWheelMatrix * lMainMatrix;
        }
        if (GtMath::Abs(lpVehicleParams->field_4E8[lnIndex]) > 50.0f && lpLODData->field_1C[2]) {
            lBlurState = 2;
        } else if (GtMath::Abs(lpVehicleParams->field_4E8[lnIndex]) > 25.0f && lpLODData->field_1C[1]) {
            lBlurState = 1;
        }
        if (lWheelRes)
            func_0021FBB0(this, lWheelRes == 1 ? 2 : 0, lWheelMatrix, lpLODData->field_1C[lBlurState], 1.0f, 0x3FF, lx16LitBits, true);
    }

    if (lpVehicleData->field_16C0 == 0) return;
    int lPayloadRes = lpEssentialParams->field_5B;
    if (lpVehicleParams->field_1023 == 1 || lpVehicleParams->field_1022) {
        for (int lnBodyPart = 0; lnBodyPart < 64; lnBodyPart++) {
            CB3BodyPartPhysics *lpPart = D_0055EF70.GetBodyPartPhysics(lnBodyPart);
            if (lpPart && lpPart->GetHostVehicle()->field_CC4 == lpVehicleParams && lpPart->GetBodyPartType() == 2) {
                CGtMatrix3x4 lOutMatrix = *lpPart->field_204;
                func_0021FBB0(this, 2, lOutMatrix,
                              lpLODData->field_28[lpVehicleParams->field_1024->field_8[lpPart->GetPartIndex()].field_C],
                              1.0f, 0x3FF, lx16LitBits, true);
            }
        }
    } else if (lPayloadRes) {
        for (int lnItem = 0; lnItem < lpVehicleParams->field_1024->field_0; lnItem++) {
            CGtMatrix3x4 lOutMatrix = lpVehicleParams->field_1024->field_8[lnItem].field_10 * lMainMatrix;
            func_0021FBB0(this, lPayloadRes == 1 ? 2 : 0, lOutMatrix,
                          lpLODData->field_28[lpVehicleParams->field_1024->field_8[lnItem].field_C],
                          1.0f, 0x3FF, lx16LitBits, true);
        }
    }
}
