// NONMATCHING: func_00445D10 -- retail 377 / ours 348 instructions, 265 in changed runs
// draftAF C-first: per-frame update of func_00446300's path camera (speed eased to one of three targets by func_00353640's count, parameter advance, end flag, look-at + CGtQuatPos::SetFromMatrix). 348/377; calls identical (3); VU op counts equal except the quaternion w lane (header SetW vs retail vmulx.w, queued); left: the implicit-operator= row loops (3x lb/sb) as func_00446300, frame
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block mapped (both speed arms incl. the 3-way pick, 0.0f+x+k*(t-x) madd form, two early-out tests, look-at, Shoemake via the header body); calls.sh identical

// func_00445D10 -- draftAF (0x445D10, 0x5E4). Unnamed in every table, so the asm label with C linkage. [L] the per-frame
// update of the path camera func_00446300 sets up (same unit, same self/out layout): unless the path came from the keyframes
// (field_49), the speed field_38 eases toward one of three speeds picked by func_00353640's count of whatever lies 40 units
// around the current distance; the parameter field_34 advances by speed * dt over the path length; field_48 flags the end
// parameter field_44 reached; while 40 units of path remain, the camera is placed and written as in func_00446300.
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
extern float D_004E2634, D_004E2638, D_004E263C, D_004E0ED8;
extern "C" CGtV3d func_002F4F90(UnkStruct_002F5770 *, float);          // [L] point at distance t * length (hidden return pointer)
extern "C" int func_00353640(void *, float, float);

// 0x00445D10
extern "C" void func_00445D10(UnkStruct_00446300 *self, UnkStruct_00446300_out *out, float dt)
{
    float d = self->field_34 * self->field_8->field_960;
    if (self->field_49 == 0) {
        int n = func_00353640(self->field_30, d, 40.0f);
        float lrTarget;
        if (n == 0) lrTarget = D_004E2634;
        else if (n < 8) lrTarget = D_004E2638;
        else lrTarget = D_004E263C;
        self->field_38 = 0.0f + self->field_38 + D_004E0ED8 * (lrTarget - self->field_38);
    }
    self->field_34 = self->field_34 + self->field_38 * dt / self->field_8->field_960;
    float lrAhead = 40.0f / self->field_8->field_960;
    if (!(self->field_34 + lrAhead <= self->field_44)) self->field_48 = 1;
    if (!(self->field_34 + lrAhead < 1.0f)) return;
    CGtMatrix3x4 lCamera;
    lCamera.mPos = func_002F4F90(self->field_8, self->field_34);
    CGtV3d lTarget = func_002F4F90(self->field_8, self->field_34 + lrAhead);
    self->field_20 = lTarget;
    self->field_20.SetY(lTarget.Y() - 4.0f);
    CGtV3d lAt = self->field_20 - lCamera.mPos;
    lAt.Normalise();
    CGtMatrix3x4 lLook = Matrix3x4SetLookAt(lAt, kAxisY);
    lLook.mPos = lCamera.mPos;
    lCamera = lLook;
    out->field_10.SetFromMatrix(lCamera);
}
