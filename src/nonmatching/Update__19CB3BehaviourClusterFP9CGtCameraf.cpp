// NONMATCHING: Update__19CB3BehaviourClusterFP9CGtCameraf -- retail 328 / ours 333 instructions, 9 hunks (11 instructions)
// draftAM C-first: cluster camera update: rig mode 0 runs the spring step (func_003580B0) and clears field_1E1, modes 0/1 re-aim (func_0035A270), UpdateFocus with the viewport's +0x74, FOV, the camera's quat+pos from the rig's camera matrix (the header's CGtQuatPos::SetFromMatrix), CollisionResolveCameraWorld with the camera-to-child distance (result into field_1E0), and in mode 3 a pushed camera drags the rig camera to 0.1 behind it; 333/328, calls identical, non-stack stores identical, behaviour_audit clean; left: SetFromMatrix's positive branch computes 0.5/s before 0.5*s (header scheduling) and two register moves
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; the mode tests (beqz 0, sltiu 2 unsigned, bne 3), CollisionResolveCameraWorld's four arguments and bool result, the 2^-32 squared-length test (c.lt / bc1f) and the normalise (vrsqrt) traced

// CB3BehaviourCluster::Update(CGtCamera*, float) -- draftAM (C-first draft). 0x357B90, 0x520. [C] name: the mangled symbol; parameter
// names from the Revenge STABS (B4BehaviourCluster.cpp: lpCamera, lrTimeStep). Rig layout as func_00355BD0's archive, camera as
// Update__23CB3BehaviourInterpolate's (+0x30 the viewport: CollisionResolveCameraWorld's first argument).
// [C] CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3Viewportfi takes the camera in a1 as well and returns a bool (read here);
// the other archived callers (RaceCarFollow, Rotate, TrackSide) pass the same four arguments and ignore the result (declared void).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_00357B90_b40 { unsigned char pad_0[0x204]; CGtMatrix3x4 * field_204; };
struct UnkStruct_00357B90_child { unsigned char pad_0[0x40]; UnkStruct_00357B90_b40 * field_40; };
class CB3ClusterRig {                       // [L] the rig record (as func_00355BD0's archive), 0xE0
public:
    void UpdateFocus(float);
    CGtMatrix3x4 field_0;                   // the rig matrix
    CGtMatrix3x4 field_40;                  // the camera matrix
    int field_80;
    UnkStruct_00357B90_child * field_84;    // the child body
    CGtV3d field_90;
    CGtV3d field_A0;
    float field_B0;
    float field_B4;
    float field_B8;                         // [G] field of view
    float field_BC;
    float field_C0;
    int field_C4;                           // [G] collision mode (CollisionResolveCameraWorld's int)
    int field_C8;
    int field_CC;                           // [G] rig mode: 0 springs from scratch, < 2 re-aim, 3 collision pushes the rig camera
    unsigned char field_D0;
};
struct UnkStruct_00357B90_vp { unsigned char pad_0[0x74]; float field_74; };
class CGtCamera {
public:
    unsigned char pad_0[0x4];
    float field_4;                          // [G] field of view
    unsigned char pad_8[0x8];
    CGtQuatPos field_10;                    // [L] orientation + position
    UnkStruct_00357B90_vp * field_30;       // [L] the viewport
};
class CB3BehaviourCluster {
public:
    void Update(CGtCamera * lpCamera, float lrTimeStep);
    unsigned char pad_0[0x10];
    CB3ClusterRig field_10;
    unsigned char pad_F0[0xF0];
    bool field_1E0;                         // [G] camera pushed by the world this frame
    bool field_1E1;
};
extern "C" void func_003580B0(CB3BehaviourCluster * self, float dt);
extern "C" void func_0035A270(CB3ClusterRig * self);
// [C] retail passes the camera in a1 and reads the result (sb v0): a bool, four arguments (the mangled name lists three)
extern "C" bool CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3Viewportfi(void *, CGtCamera *, float, int);

// 0x00357B90
void CB3BehaviourCluster::Update(CGtCamera * lpCamera, float lrTimeStep)
{
    if (field_10.field_CC == 0) {
        func_003580B0(this, lrTimeStep);
        field_1E1 = false;
    }
    if ((unsigned int)field_10.field_CC < 2)
        func_0035A270(&field_10);
    field_10.UpdateFocus(lpCamera->field_30->field_74);
    lpCamera->field_4 = field_10.field_B8;
    lpCamera->field_10.SetFromMatrix(field_10.field_40);
    float lrDist = (float)(field_10.field_40.mPos - field_10.field_84->field_40->field_204->mPos).GetLength();
    field_1E0 = CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3Viewportfi(lpCamera->field_30, lpCamera, lrDist, field_10.field_C4);
    if (field_1E0 && field_10.field_CC == 3) {
        CGtV3d cam = lpCamera->field_10.mPos;
        CGtV3d d = cam - field_10.field_40.mPos;
        if ((float)d.GetSquaredLength() < 2.3283064e-10f) {
            field_10.field_40.mPos = cam;
        } else {
            d.Normalise();
            field_10.field_40.mPos = cam + d * 0.1f;
        }
    }
}
