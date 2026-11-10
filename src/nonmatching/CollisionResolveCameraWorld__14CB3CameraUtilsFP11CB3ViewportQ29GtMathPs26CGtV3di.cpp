// NONMATCHING: CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3ViewportQ29GtMathPs26CGtV3di -- retail 549 / ours 485 instructions, 460 in changed runs
// draftAG: logic complete; retail 549 / ours 488; calls identical (incl. the out-of-line CGtV4d(u_long128) via a camera-matrix accessor inline [G], Revenge's second lResult); VU lane ops agree except SetFromMatrix's positive-branch SetW (header gap, queued); left: retail's six 16-byte lb/sb row-copy loops (ours lq/sq: known open wall), frame 0xD70 vs 0x6F0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm and the Revenge stabs block (same locals); header APIs ConvertToMatrix / DotProduct / TransformPoint / lane negation / SetFromMatrix; every branch, call and store accounted for; call sequence identical (calls.sh)

// CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3ViewportQ29GtMathPs26CGtV3di -- draftAG (C-first draft).
// [C] retail takes FOUR register arguments (a0 viewport: fov 0x6C, near 0x84; a1 the camera: CGtQuatPos at +0x10, written
// back; a2 the focus CGtV3d by address; a3 the stream index) although the mangled name lists three: as Revenge's
// CollisionResolveCameraWorld__14CB4CameraUtilsP11CB4ViewportP9CGtCameraGQ29GtMathPs26CGtV3d15EPlayerCarIndex (stabs: lpViewport,
// lpCamera, lFocus, leStream) -- so the camera pointer is [L] an argument the name source lacks; defined through the link name.
// Locals named after Revenge's stabs block (lCameraMatrix, lLine, lNearOffset, lrDistance, lrDepth, lnCurrentUnit, lnCorner) [L].
// What it does [L]: casts a line from each near-plane corner, pushed out to the focus depth, back to the near plane through the
// streamed track's collision; on a hit, moves the camera forward along its view axis by the blocked part.
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;
extern "C" float tanf(float);

struct UnkStruct_002F66C0_vp {             // CB3Viewport [L]; fields seen here only
    unsigned char pad_0[0x6C];
    float field_6C;                         // [C] field of view, degrees (tanf(rad(fov) / 2))
    float field_70;                         // [C] x scale of the near-plane half-width
    float field_74;                         // [C] aspect: half-height = half-width / field_74
    unsigned char pad_78[0xC];
    float field_84;                         // [C] near-plane distance
};
struct UnkStruct_002F66C0_cam {            // CGtCamera [L] (include/b3/classes/CGtCamera.h has field_30.. only)
    unsigned char pad_0[0x10];
    CGtQuatPos field_10;                    // [C] lqc2 0x10 (quat), lq 0x20 (pos); both written back on a hit
};
struct UnkStruct_002F66C0_line { CGtV3d field_0; CGtV3d field_10; };   // CGtLine [L] (as B3CrashCameraDirector_00356700.cpp)

extern unsigned char D_00522660[];          // [C] the streamed tracks (0x1CC per stream, CB3StreamedTrack at +0x12A348)
extern "C" unsigned int TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(void *, const CGtV3d *);
extern "C" int IntersectLineWithUnit__16CB3StreamedTrackFUiRC7CGtLinePFRC28CGtPolygonIntersectionResultPv_bPv(void *, unsigned int, const UnkStruct_002F66C0_line *, bool (*)(const void *, void *), void *);
extern "C" bool func_002F72A0(const void *, void *);   // [C] the intersection callback; user data = &lrDistance (hit fraction)

// [L] a camera matrix accessor (Revenge's block has a second lResult CGtMatrix3x4 around the quaternion conversion's own, as
// Draw__14CB3CrashPickupFv's); name unknown, placeholder [G]
static inline CGtMatrix3x4 func_002F66C0_inl1(UnkStruct_002F66C0_cam *cam)
{
    CGtMatrix3x4 lResult = cam->field_10.ConvertToMatrix();
    return lResult;
}

// 0x002F66C0
extern "C" bool CollisionResolveCameraWorld__14CB3CameraUtilsFP11CB3ViewportQ29GtMathPs26CGtV3di(
    UnkStruct_002F66C0_vp *lpViewport, UnkStruct_002F66C0_cam *lpCamera, CGtV3d lFocus, int leStream)
{
    CGtMatrix3x4 lCameraMatrix = func_002F66C0_inl1(lpCamera);
    float lrDistance = 1.0f;
    void *trk = (char *)D_00522660 + leStream * 0x1CC + 0x12A348;
    unsigned int lnCurrentUnit = TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(trk, &lFocus);
    float lrNear = lpViewport->field_84;
    float lrDepth = (float)DotProduct(lFocus - lCameraMatrix.mPos, lCameraMatrix.mAt) - lrNear;
    float lrTan = tanf(0.017453292f * (0.5f * lpViewport->field_6C));
    CGtV3d lNearOffset;
    lNearOffset.SetX(lpViewport->field_70 * (lrNear * lrTan));
    lNearOffset.SetY((float)lNearOffset.X() / lpViewport->field_74);
    lNearOffset.SetZ(lrNear);
    for (int lnCorner = 0; lnCorner < 4; lnCorner++) {
        switch (lnCorner) {
        case 1:
            lNearOffset.SetX(-lNearOffset.X());
            break;
        case 2:
            lNearOffset.SetY(-lNearOffset.Y());
            break;
        case 3:
            lNearOffset.SetX(-lNearOffset.X());
            break;
        }
        UnkStruct_002F66C0_line lLine;
        CGtV3d p = TransformPoint(lCameraMatrix, lNearOffset);
        lLine.field_10 = p;
        lLine.field_0 = p + lCameraMatrix.mAt * lrDepth;
        IntersectLineWithUnit__16CB3StreamedTrackFUiRC7CGtLinePFRC28CGtPolygonIntersectionResultPv_bPv(
            trk, lnCurrentUnit, &lLine, func_002F72A0, &lrDistance);
    }
    if (lrDistance == 1.0f)
        return false;
    lCameraMatrix.mPos += lCameraMatrix.mAt * ((1.0f - lrDistance) * lrDepth);
    lpCamera->field_10.SetFromMatrix(lCameraMatrix);
    return true;
}

