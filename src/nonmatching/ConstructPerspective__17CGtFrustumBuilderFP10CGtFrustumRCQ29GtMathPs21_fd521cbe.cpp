// NONMATCHING: ConstructPerspective__17CGtFrustumBuilderFP10CGtFrustumRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dff -- retail 282 / ours 299 instructions, 291 in changed runs
// draftAE C-first: 299/282; no calls; op counts agree except the header operator+/- shapes (5 vmove.xyzw from the hard-coded $vf1/$vf2 operator+, 2 vsub.xyz retail CSEs (v1-v5, v3-v7), mPos by-value copies sq x2) and 9 fewer lqc2 (retail reloads corners). Left: frame 0x90 vs 0x450 (dead slots), compiler-chosen three-operand vadd/vsub in retail's loop
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm lane by lane (corner construction, near/far push-out, 2 end planes + 4 SoA side planes with their cross-product operand orders and distance points); Revenge STABS locals; CGtFrustum layout Revenge types.h; header APIs SetNormal/DotProduct/CrossProduct/Normalise/lane setters, stand-ins for 6 CGtV4d setters + register SetDistance (gaps queued)

// ConstructPerspective__17CGtFrustumBuilder... -- draftAE (0x349980, 0x468) -- CGtFrustumBuilder::ConstructPerspective(CGtFrustum*,
// const CGtMatrix3x4&, const CGtV2d&, const CGtV2d&, float, float), a static member (no this: a0 = the frustum).
// Written from the retail asm. Names: parameters and locals lTmp / i / laFrustumVerts[8] / lPlane after Revenge's STABS of the
// same function (GameShared/GameClasses/Geometric/GtFrustumBuilder.cpp) [L]; CGtFrustum layout [C] Revenge types.h (size 0x60);
// CGtFrustum::SetPlane(EGtFrustumPlane, CGtPlane) [C] B3O0PCH map (0x36B110, 0x3EC; inlined six times here), body [G].
// [L] the eight corners: the view window at distance 1 along mAt (rows scaled by the window half-size), shifted by the view
// offset (lTmp, the eye offset in the camera plane), then pushed out to the near / far distances along the rays from the
// offset eye; planes: far (+mAt through a far corner), near (-mAt through a near corner), then four side planes from cross
// products of corner differences, normalised, stored lane-wise (SoA) by SetPlane.
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;


// [G] CGtPlane::SetDistance(XAxisType) (B3O0PCH map, 56 bytes) on the plane's register: retail keeps lPlane in a VU register
// between the setters (0x349AC8 `vmulx.w $vf4,$vf0,$vf1x`); the header body goes through memory (hdrrd) -- gap queued.
static inline void func_00349980_sd(CGtPlane &p, XAxisType d) { asm("vmulx.w %0, $vf0, %1x" : "+j"(p.mData) : "j"(d.lVector)); }

enum EGtFrustumPlane {};   // [C] name: B3O0PCH map (SetPlane's parameter); enumerators unknown -- values 0..5 below [G]

struct CGtFrustum {
    CGtPlane maEndPlanes[2];
    CGtV4d mSidePlanesX;
    CGtV4d mSidePlanesY;
    CGtV4d mSidePlanesZ;
    CGtV4d mSidePlanesD;

    // [G] body: 0/1 the end planes (one 128-bit store); 2..5 the side planes, one lane of each SoA row (retail x, y, z, w lanes)
    void SetPlane(EGtFrustumPlane e, CGtPlane p) {
        switch ((int)e) {
        case 0:
        case 1:
            maEndPlanes[e] = p;
            break;
        case 2:
            mSidePlanesX.SetX(p.Normal().X());
            mSidePlanesY.SetX(p.Normal().Y());
            mSidePlanesZ.SetX(p.Normal().Z());
            mSidePlanesD.SetX(p.Distance());
            break;
        case 3:
            mSidePlanesX.SetY(p.Normal().X());
            mSidePlanesY.SetY(p.Normal().Y());
            mSidePlanesZ.SetY(p.Normal().Z());
            mSidePlanesD.SetY(p.Distance());
            break;
        case 4:
            mSidePlanesX.SetZ(p.Normal().X());
            mSidePlanesY.SetZ(p.Normal().Y());
            mSidePlanesZ.SetZ(p.Normal().Z());
            mSidePlanesD.SetZ(p.Distance());
            break;
        case 5:
            mSidePlanesX.SetW(p.Normal().X());
            mSidePlanesY.SetW(p.Normal().Y());
            mSidePlanesZ.SetW(p.Normal().Z());
            mSidePlanesD.SetW(p.Distance());
            break;
        }
    }
};

class CGtFrustumBuilder {
public:
    static void ConstructPerspective(CGtFrustum * lpFrustum, const CGtMatrix3x4 & lCameraMatrix, const CGtV2d & lViewWindow,
                                     const CGtV2d & lViewOffset, float lrNearClipPlane, float lrFarClipPlane);
};

void CGtFrustumBuilder::ConstructPerspective(CGtFrustum * lpFrustum, const CGtMatrix3x4 & lCameraMatrix, const CGtV2d & lViewWindow,
                                             const CGtV2d & lViewOffset, float lrNearClipPlane, float lrFarClipPlane)
{
    CGtV3d lTmp;
    int i;
    CGtV3d laFrustumVerts[8];
    CGtPlane lPlane;

    CGtV3d lOffset = lCameraMatrix.mRight * -lViewOffset.marValues[0];
    lOffset += lCameraMatrix.mUp * lViewOffset.marValues[1];
    CGtV3d lRight = lCameraMatrix.mRight * lViewWindow.marValues[0];
    CGtV3d lUp = lCameraMatrix.mUp * lViewWindow.marValues[1];
    lTmp = lCameraMatrix.mAt;
    lTmp += lRight;
    lTmp += lUp;
    laFrustumVerts[0] = lTmp;
    lRight = lRight * 2.0f;
    lUp = lUp * 2.0f;
    lTmp -= lRight;
    laFrustumVerts[1] = lTmp;
    lTmp -= lUp;
    laFrustumVerts[2] = lTmp;
    lTmp += lRight;
    laFrustumVerts[3] = lTmp;
    for (i = 0; i < 4; i++) {
        CGtV3d lRay = laFrustumVerts[i] - lOffset;
        laFrustumVerts[i] = lOffset + lCameraMatrix.mPos + lRay * lrNearClipPlane;
        laFrustumVerts[i + 4] = lOffset + lCameraMatrix.mPos + lRay * lrFarClipPlane;
    }

    lPlane.SetNormal(lCameraMatrix.mAt);
    func_00349980_sd(lPlane, DotProduct(laFrustumVerts[4], lCameraMatrix.mAt));
    lpFrustum->SetPlane((EGtFrustumPlane)0, lPlane);
    lPlane.SetNormal(-lCameraMatrix.mAt);
    func_00349980_sd(lPlane, DotProduct(laFrustumVerts[0], -lCameraMatrix.mAt));
    lpFrustum->SetPlane((EGtFrustumPlane)1, lPlane);

    lTmp = CrossProduct(laFrustumVerts[1] - laFrustumVerts[5], laFrustumVerts[6] - laFrustumVerts[5]);
    lTmp.Normalise();
    lPlane.SetNormal(lTmp);
    func_00349980_sd(lPlane, DotProduct(laFrustumVerts[1], lTmp));
    lpFrustum->SetPlane((EGtFrustumPlane)2, lPlane);

    lTmp = CrossProduct(laFrustumVerts[4] - laFrustumVerts[5], laFrustumVerts[1] - laFrustumVerts[5]);
    lTmp.Normalise();
    lPlane.SetNormal(lTmp);
    func_00349980_sd(lPlane, DotProduct(laFrustumVerts[1], lTmp));
    lpFrustum->SetPlane((EGtFrustumPlane)3, lPlane);

    lTmp = CrossProduct(laFrustumVerts[3] - laFrustumVerts[7], laFrustumVerts[4] - laFrustumVerts[7]);
    lTmp.Normalise();
    lPlane.SetNormal(lTmp);
    func_00349980_sd(lPlane, DotProduct(laFrustumVerts[3], lTmp));
    lpFrustum->SetPlane((EGtFrustumPlane)4, lPlane);

    lTmp = CrossProduct(laFrustumVerts[6] - laFrustumVerts[7], laFrustumVerts[3] - laFrustumVerts[7]);
    lTmp.Normalise();
    lPlane.SetNormal(lTmp);
    func_00349980_sd(lPlane, DotProduct(laFrustumVerts[3], lTmp));
    lpFrustum->SetPlane((EGtFrustumPlane)5, lPlane);
}
