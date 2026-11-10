// NONMATCHING: BeginInstanceRender__16CB3TrackRendererFPC15CB3InstanceMeshPC17CGtAxisAlignedBoxRC16CB3TrackMaterialff24EB3InstanceDistanceCheckbf -- retail 402 / ours 347 instructions, 251 in changed runs
// draftAH C-first: VU0 code residency (UploadVu0Code inline as func_0026AE30), material state block (as proven func_0026AE30), light dir + alpha by material flags, camera pos + LOD dist^2, z rotation by speed*time (header CreateRotationMatrix3x4), microprogram call (vcallms 0x0, inputs vf1-4/vi15/vi8/vf13-16); 347/402, calls identical, VU op counts equal; left: retail's CreateRotationMatrix3x4 lane products/copies through the stack (lqc2 34/18, sqc2 36/21, N255 shape), frame 0x4F0 vs 0x840; the trailing asm cfc2.i $0,$vi0 is dropped by b119p at the function end (kept when any store follows)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm with Revenge STABS names (same function, 308 instrs); every flag branch, store and the microprogram register hand-off traced; VU op counts equal; microprogram call is PS2-only inline asm (port replaces it)

// CB3TrackRenderer::BeginInstanceRender(const CB3InstanceMesh*, const CGtAxisAlignedBox*, const CB3TrackMaterial&, float, float,
// EB3InstanceDistanceCheck, bool, float) -- draftAH (C-first draft; the lifter refused it). 0x26A7E0, 0x648.
// [C] name: retail symbol table. Revenge counterpart BeginInstanceRender__16CB4TrackRenderer... (STABS,
// TrackRenderer/Ps2/B4TrackRendererRuntimePS2.cpp, 308 instrs): parameter and local names from it (lpInstance, lpInstanceBox,
// lMaterial, lrLodSwitchDist, lrStopDrawDist, leDistanceCheck, lbRotating, lrSpeed; lLightDirAndAlpha, lu128Inf, lu128Sup,
// lu128LightDirAlpha, lu128CamPosDistSq, lRotateMatrix, lu16DynamicLit, lbCodeUploading, lrTime, lrAngle) [L].
// The material set-up block is the proven sibling func_0026AE30's (same fields, same order).
// What it does [L]: make sure the instance VU0 microprogram (vu_game_00479610) is resident; set up the material state;
// the light direction of the current light set with an alpha per material flags; camera position with the LOD switch
// distance squared; for rotating instances a rotation about z by speed * time; then hand box, light, camera, distance-check
// mode, the dynamic-lit flag and the rotation to the microprogram (vcallms 0x0: inline asm, the program reads fixed VF/VI
// registers -- PS2 only; the port replaces the call). Types [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;

extern "C" int sceDmaGetChan(int);
extern "C" int sceDmaSync(int, int, int);
extern char vu_game_00479610[];     // the instance VU0 microprogram
// [C] names: E B3O0PCH map (CGtVu0CodeManager::UploadVu0Code 0x2294A0, WaitForUploadToFinish 0x2293C0, GetCurrentVu0CodePointer
// 0x229520); bodies as the proven func_0026AE30 / IntersectFrustum (N203)
class CGtVu0CodeManager {
public:
    static void *gmpCurrentVu0Code;
    static bool UploadVu0Code(void *code);
    static void WaitForUploadToFinish();
    static void *GetCurrentVu0CodePointer() { return gmpCurrentVu0Code; }
};
inline bool CGtVu0CodeManager::UploadVu0Code(void *code)
{
    if (gmpCurrentVu0Code == code) {
        return false;
    } else {
        gmpCurrentVu0Code = code;
        if (code) {
            *(volatile unsigned int *)0x10008020 = 0;
            *(volatile unsigned int *)0x10008030 = (unsigned int)code;
            *(volatile unsigned int *)0x10008000 = 0x145;
            return true;
        } else {
            return false;
        }
    }
}
inline void CGtVu0CodeManager::WaitForUploadToFinish()
{
    while (sceDmaSync(sceDmaGetChan(0), 1, 0) != 0) {}
}

class CB3InstanceMesh;
struct CGtAxisAlignedBox { CGtV3d mSup; CGtV3d mInf; };   // [L] Revenge layout (mSup, mInf: class_layouts.tsv)
class CB3TrackMaterial {
public:
    int field_0;                            // 5: dynamically lit [G]
    unsigned char pad_4[0x20];
    unsigned short field_24;                // flags: 0x4 / 0x8 alpha, 0x18 alpha test, 0x400
};
enum EB3InstanceDistanceCheck { };
struct UnkStruct_mesh { unsigned char pad_0[4]; int field_4; int field_8; };   // as func_0026AE30
extern UnkStruct_mesh *_gpMeshCache;
struct UnkStruct_D_01E85900_e { CGtV3d field_0; unsigned char pad_10[0x30]; };   // a light set: direction first [G]
struct UnkStruct_D_01E85900 { unsigned char pad_0[0xB0]; UnkStruct_D_01E85900_e field_B0[2]; };
extern UnkStruct_D_01E85900 D_01E85900;
extern int D_01E85A30;                      // the current light set (D_01E85900 + 0x130) [G]
extern CGtV3d D_00666400;                   // the camera position (as other track/sun renderers) [G]
extern float D_00522680;                    // [G] game time
extern float D_004E0F70, D_004E069C, D_004E0F74;

class CB3TrackRenderer {
public:
    void BeginInstanceRender(const CB3InstanceMesh *, const CGtAxisAlignedBox *, const CB3TrackMaterial &, float, float,
                             EB3InstanceDistanceCheck, bool, float);

    unsigned char pad_0[0x70];
    CGtV3dPlus field_70;                    // camera position, LOD switch distance squared in w
    const CB3InstanceMesh *field_80;
    unsigned char field_84;
    unsigned char field_85;
    unsigned char field_86;
    unsigned char pad_87[0x3];
    unsigned char field_8A;                 // rotating
    unsigned char pad_8B[0x5];
    float field_90;                         // stop-draw distance
    const CB3TrackMaterial *field_94;
    unsigned char field_98;
    unsigned char pad_99[2];
    unsigned char field_9B;
    unsigned char field_9C;
    unsigned char pad_9D[3];
    unsigned long field_A0;
    unsigned long pad_A8;
    unsigned long field_B0;
};

// 0x0026A7E0
void CB3TrackRenderer::BeginInstanceRender(const CB3InstanceMesh * lpInstance, const CGtAxisAlignedBox * lpInstanceBox,
                                           const CB3TrackMaterial & lMaterial, float lrLodSwitchDist, float lrStopDrawDist,
                                           EB3InstanceDistanceCheck leDistanceCheck, bool lbRotating, float lrSpeed)
{
    bool lbCodeUploading = false;
    if (CGtVu0CodeManager::GetCurrentVu0CodePointer() != (void *)vu_game_00479610) {
        if (CGtVu0CodeManager::UploadVu0Code((void *)vu_game_00479610))
            lbCodeUploading = true;
    }
    field_9B = 0;
    field_9C = 0;
    field_94 = &lMaterial;
    if ((lMaterial.field_24 & 0x18) != 0)
        field_A0 = (unsigned long)0xFF000000 << 32;
    else
        field_A0 = 0;
    if ((lMaterial.field_24 & 0x400) != 0)
        field_B0 = (unsigned long)1 << 32;
    else
        field_B0 = 0;
    field_98 = 0;
    UnkStruct_mesh *m = _gpMeshCache;
    m->field_8 = (int)m + 0x150;
    m->field_4 = m->field_8;

    unsigned short lu16DynamicLit;
    if (field_94->field_0 == 5)
        lu16DynamicLit = 1;
    else
        lu16DynamicLit = 0;
    CGtV3dPlus lLightDirAndAlpha;
    lLightDirAndAlpha.SetGtV3d(D_01E85900.field_B0[D_01E85A30].field_0);
    if (field_94->field_24 & 0x4)
        lLightDirAndAlpha.SetPlus(255.0f);
    else if (field_94->field_24 & 0x8)
        lLightDirAndAlpha.SetPlus(128.0f);
    else
        lLightDirAndAlpha.SetPlus(4.0f);

    field_80 = lpInstance;
    field_84 = 0;
    field_85 = 0;
    field_86 = 0;
    field_70.SetGtV3d(D_00666400);
    field_70.SetPlus(lrLodSwitchDist * lrLodSwitchDist);
    field_90 = lrStopDrawDist;
    CGtMatrix3x4 lRotateMatrix;
    if (lbRotating) {
        float lrTime = lrSpeed * D_00522680;
        float lrAngle = D_004E0F70 * lrTime;
        lRotateMatrix = CreateRotationMatrix3x4(CGtV3d(0.0f, 0.0f, 1.0f), D_004E0F74 * (lrAngle * D_004E069C));
        field_8A = 1;
    } else {
        field_8A = 0;
    }
    u_long128 lu128Inf = lpInstanceBox->mInf.mData;
    u_long128 lu128Sup = lpInstanceBox->mSup.mData;
    u_long128 lu128LightDirAlpha = lLightDirAndAlpha.mData;
    u_long128 lu128CamPosDistSq = field_70.mData;
    if (lbCodeUploading)
        CGtVu0CodeManager::WaitForUploadToFinish();
    // the microprogram's inputs: box in vf1/vf2, light in vf3, camera in vf4, distance check in vi15, dynamic-lit in vi8, the
    // rotation rows in vf13..vf16; then run it and wait (cfc2.i)
    asm volatile("qmtc2.i %0, $vf1\n\tqmtc2.ni %1, $vf2\n\tqmtc2.ni %2, $vf3\n\tqmtc2.ni %3, $vf4"
                 : : "r"(lu128Inf), "r"(lu128Sup), "r"(lu128LightDirAlpha), "r"(lu128CamPosDistSq));
    asm volatile("ctc2.ni %0, $vi15\n\tctc2.ni %1, $vi8" : : "r"(leDistanceCheck), "r"(lu16DynamicLit));
    asm volatile("lqc2 $vf13, 0x0(%0)\n\tlqc2 $vf14, 0x10(%0)\n\tlqc2 $vf15, 0x20(%0)\n\tlqc2 $vf16, 0x30(%0)" : : "r"(&lRotateMatrix));
    asm("vcallms 0x0");
    asm("cfc2.i $0, $vi0");
}
