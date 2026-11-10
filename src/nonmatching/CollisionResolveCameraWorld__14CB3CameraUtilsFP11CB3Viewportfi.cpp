// NONMATCHING: CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3Viewportfi -- retail 205 / ours 211 instructions, 99 in changed runs
// draftAN fork C C-first: camera matrix from the camera's CGtQuatPos (header ConvertToMatrix, the 0x2F66C0 overload's accessor inline), focus = mPos + mAt * lrDistance, then the 0x2F66C0 overload (retail four-register list: viewport, camera, &focus copy, stream); bool result returned; 211/205, calls identical (incl. the out-of-line CGtV4d ctor), non-stack stores identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: quat * sqrt2 conversion, the 0x20 position copy, vmulx.xyz/vadd.xyz focus and the four call arguments traced; Revenge's same-named overload has the same list

// CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3Viewportfi -- draftAN fork C (C-first draft). 0x2F6F60, 0x334.
// [C] name: the mangled symbol in retail's tables. [C] retail's register list is (a0 viewport, a1 the camera, f12 distance,
// a2 stream) although the mangled name lists three (draftAM: CB3BehaviourCluster::Update passes lpCamera in a1 and reads the
// bool result); Revenge's CollisionResolveCameraWorld__14CB4CameraUtilsP11CB4ViewportP9CGtCameraf15EPlayerCarIndex (0x1F8,
// B4CameraUtils.cpp; stabs lpViewport, lpCamera, lrDistance, leStream, lCameraMatrix, two lResult) has the camera too.
// Defined through the link name with retail's list. What it does [L]: the camera matrix from its quaternion + position
// (header CGtQuatPos::ConvertToMatrix, through the same accessor inline as the 0x2F66C0 overload's archive), the focus point
// lrDistance along its view axis (mPos + mAt * lrDistance), then the 0x2F66C0 overload with it; its bool is returned.
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_002F6F60_cam {            // CGtCamera [L] (include/b3/classes/CGtCamera.h has field_30.. only)
    unsigned char pad_0[0x10];
    CGtQuatPos field_10;                    // [C] lqc2 0x10 (quat), lq 0x20 (pos)
};

extern "C" bool CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3ViewportQ29GtMathPs26CGtV3di(
    void *lpViewport, UnkStruct_002F6F60_cam *lpCamera, CGtV3d lFocus, int leStream);

// [L] a camera matrix accessor (Revenge's block has a second lResult CGtMatrix3x4 around the quaternion conversion's own);
// name unknown, placeholder (as func_002F66C0_inl1)
static inline CGtMatrix3x4 func_002F6F60_inl1(UnkStruct_002F6F60_cam *cam)
{
    CGtMatrix3x4 lResult = cam->field_10.ConvertToMatrix();
    return lResult;
}

// 0x002F6F60
extern "C" bool CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3Viewportfi(void *lpViewport, UnkStruct_002F6F60_cam *lpCamera,
                                                                              float lrDistance, int leStream)
{
    CGtMatrix3x4 lCameraMatrix = func_002F6F60_inl1(lpCamera);
    return CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3ViewportQ29GtMathPs26CGtV3di(
        lpViewport, lpCamera, lCameraMatrix.mPos + lCameraMatrix.mAt * lrDistance, leStream);
}
