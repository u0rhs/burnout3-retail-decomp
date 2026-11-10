// NONMATCHING: func_00446300 -- retail 410 / ours 376 instructions, 279 in changed runs
// draftAF C-first: logic complete (path rebuilt from the camera buffer or the keyframes, start/end parameters, look-at from the path point 40 ahead and 4 lower, CGtQuatPos::SetFromMatrix, fov 60). 376/410; calls identical (8); VU op counts equal except the quaternion w lane (header SetW(float) = vsubw.w+vaddx.w, retail vmulx.w SetA form, 1 site) ; left: retail's implicit-operator= row loops (3x lb/sb, a returned look-at temporary copied twice; 4 forms tried incl. scoped opt_classresults off), frame 0x410 vs 0x890
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block mapped (path loops, both parameter arms, look-at, Shoemake 4 branches via the header body); calls.sh identical; constants 25/40/4/16/60 + D_004E2638

// func_00446300 -- draftAF (0x446300, 0x668). Unnamed in every table, so the asm label with C linkage; its unit
// (0x445D10..) holds func_00445D10, the same shape. [L] a camera state's set-up from a path: the path (self->field_8,
// func_002F5770's segment list) is rebuilt from the camera buffer's points (or, when field_49 is set, from the camera
// keyframes), the start/end parameters along it are chosen, then the camera is placed at the start point looking at a point
// 40 units further along (4 units lower), and written as a CGtQuatPos (out + 0x10) with a 60-degree field of view [G].
// Field names are placeholders and every type is [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

// [L] func_002F4F90 / func_002F5770's segment list (0x32 entries of 0x30, length at +0x960, count at +0x964)
struct UnkStruct_002F5770_e { CGtV3d field_0; unsigned char pad_10[0x10]; float field_20; unsigned char pad_24[0xC]; };
struct UnkStruct_002F5770 { UnkStruct_002F5770_e field_0[0x32]; float field_960; int field_964; };
struct UnkStruct_00446300_kf { unsigned char pad_0[0x20]; };   // [L] CB3CameraKeyFrame (GetIsSetup's this), 0x20 apart
// [G] CB3PlayerCameraManager::mgpCameraBuffer's target: a point count, the points, then the keyframes
struct UnkStruct_00446300_buf {
    int field_0;
    unsigned char pad_4[0xC];
    CGtV3d field_10[0x98];
    UnkStruct_00446300_kf field_990[1];
};
class CB3PlayerCameraManager { public: static UnkStruct_00446300_buf *mgpCameraBuffer; };
struct UnkStruct_00446300 {
    unsigned char pad_0[8];
    UnkStruct_002F5770 *field_8;   // the path
    unsigned char pad_C[4];
    CGtV3d field_10;
    CGtV3d field_20;               // look-at point
    void *field_30;
    float field_34;                // start parameter
    float field_38;
    float field_3C;
    float field_40;
    float field_44;                // end parameter
    unsigned char field_48;
    unsigned char field_49;        // [G] path from the keyframes
};
struct UnkStruct_00446300_out { unsigned char pad_0[4]; float field_4; unsigned char pad_8[8]; CGtQuatPos field_10; };
extern const CGtV3d kAxisY;
extern float D_004E2638;
extern "C" void func_002F5770(UnkStruct_002F5770 *, const CGtV3d *);   // [G] append a path point
extern "C" void func_002F5060(UnkStruct_002F5770 *);                   // [G] finish the path (segment lengths)
extern "C" CGtV3d func_002F4F90(UnkStruct_002F5770 *, float);          // [L] point at distance t * length (hidden return pointer)
extern "C" CGtV3d func_00446A40(UnkStruct_00446300_kf *);              // [L] the keyframe's position (proven)
extern "C" int GetIsSetup__17CB3CameraKeyFrameFv(UnkStruct_00446300_kf *);
extern "C" void func_00353780(void *, float *, float *, UnkStruct_002F5770 *);

// 0x00446300
extern "C" int func_00446300(UnkStruct_00446300 *self, UnkStruct_00446300_out *out)
{
    self->field_10.Zero();
    self->field_8->field_964 = 0;
    self->field_8->field_960 = 0.0f;
    if (self->field_49 != 0) {
        for (UnkStruct_00446300_kf *kf = CB3PlayerCameraManager::mgpCameraBuffer->field_990; GetIsSetup__17CB3CameraKeyFrameFv(kf); kf++) {
            CGtV3d p = func_00446A40(kf);
            func_002F5770(self->field_8, &p);
        }
    } else {
        for (int i = 0; i < CB3PlayerCameraManager::mgpCameraBuffer->field_0; i++)
            func_002F5770(self->field_8, &CB3PlayerCameraManager::mgpCameraBuffer->field_10[i]);
    }
    func_002F5060(self->field_8);
    if (self->field_49 != 0) {
        self->field_38 = 25.0f;
        self->field_34 = 0.0f;
        self->field_44 = 1.0f;
    } else {
        func_00353780(self->field_30, &self->field_3C, &self->field_40, self->field_8);
        self->field_3C = self->field_3C - 40.0f;
        self->field_38 = D_004E2638;
        self->field_34 = self->field_3C / self->field_8->field_960;
        self->field_44 = (16.0f + self->field_40) / self->field_8->field_960;
        self->field_34 = GtMath::Max(0.0f, self->field_34);
        self->field_44 = GtMath::Min(1.0f, self->field_44);
    }
    self->field_48 = 0;
    CGtMatrix3x4 lCamera;
    lCamera.mPos = func_002F4F90(self->field_8, self->field_34);
    CGtV3d lTarget = func_002F4F90(self->field_8, self->field_34 + 40.0f / self->field_8->field_960);
    self->field_20 = lTarget;
    self->field_20.SetY(lTarget.Y() - 4.0f);
    CGtV3d lAt = self->field_20 - lCamera.mPos;
    lAt.Normalise();
    CGtMatrix3x4 lLook = Matrix3x4SetLookAt(lAt, kAxisY);
    lLook.mPos = lCamera.mPos;
    lCamera = lLook;
    out->field_10.SetFromMatrix(lCamera);
    out->field_4 = 60.0f;
    return 1;
}
