// NONMATCHING: IntersectSphere__14GtIntersectionFQ29GtMathPs29CGtSphereRC10CGtFrustum -- retail 104 / ours 107 instructions, 36 in changed runs
// repair1: was not broken (the compscan log is shared with the P21CGtIntersectionResult overload: both names truncate to the same 60 chars); local operator stand-ins renamed func_002BF390_inl1-5 so future header operators can't clash, same 36. Left (near29): frame 0x1D0 vs 0x270, lane reads via a separate address register, position on vf5 vs vf4
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
namespace GtMathPs2 {
// [C] layout and API: Revenge stabs (types.h CGtSphere/CGtPlane: u_long128 mData; Position/Radius, Normal/Distance);
// B3O0PCH map (CGtSphere::Radius(), CGtSphere::Position(), CGtPlane::Normal(), CGtPlane::Distance()). [G] bodies.
// [C] API: B3O0PCH map (GtMathPs2::operator -(XAxisType,WAxisType), 80 bytes out of line); not in the header yet. [G] body.
static inline XAxisType func_002BF390_inl1(XAxisType a, WAxisType b)
{
    u_long128 e;
    asm("qmtc2.i %1, $vf1" "\n\t" "vsubw.x $vf1, $vf1, %2w" "\n\t" "qmfc2 %0, $vf1" : "=r"(e) : "r"(a.lVector), "j"(b.lVector));
    return XAxisType(e);
}
}
// [C] layout: Revenge stabs (CGtFrustum, size 0x60): two end planes, then the four side planes as lane vectors.
struct CGtFrustum {
    CGtPlane maEndPlanes[2];
    CGtV4d mSidePlanesX;
    CGtV4d mSidePlanesY;
    CGtV4d mSidePlanesZ;
    CGtV4d mSidePlanesD;
};
// [G] lane-broadcast products and the 4-lane sum (compiler-chosen VU registers)
static inline CGtV4d func_002BF390_inl2(const CGtV4d& a, XAxisType x)
{ u_long128 t; asm("vmulx.xyzw %0, %1, %2x" : "=j"(t) : "j"(a.mData), "j"(x.lVector)); return CGtV4d(t); }
static inline CGtV4d func_002BF390_inl3(const CGtV4d& a, YAxisType y)
{ u_long128 t; asm("vmuly.xyzw %0, %1, %2y" : "=j"(t) : "j"(a.mData), "j"(y.lVector)); return CGtV4d(t); }
static inline CGtV4d func_002BF390_inl4(const CGtV4d& a, ZAxisType z)
{ u_long128 t; asm("vmulz.xyzw %0, %1, %2z" : "=j"(t) : "j"(a.mData), "j"(z.lVector)); return CGtV4d(t); }
class GtIntersection { public: static int IntersectSphere(CGtSphere s, const CGtFrustum& f); };

// 0x002BF390
int GtIntersection::IntersectSphere(CGtSphere s, const CGtFrustum& f)
{
    int r = 2;
    float rad = s.Radius();
    float nrad = -rad;
    for (int i = 0; i < 2; i++) {
        float d = func_002BF390_inl1(DotProduct(s.Position(), f.maEndPlanes[i].Normal()), f.maEndPlanes[i].Distance());
        if (!(d <= rad)) return 0;
        if (!(d <= nrad)) r = 1;
    }
    CGtV3d p = s.Position();
    CGtV4d d = ((func_002BF390_inl2(f.mSidePlanesX, p.X()) + func_002BF390_inl3(f.mSidePlanesY, p.Y())) + func_002BF390_inl4(f.mSidePlanesZ, p.Z())) - f.mSidePlanesD;
    if (!(d.X() <= rad) || !(d.Y() <= rad) || !(d.Z() <= rad) || !(d.W() <= rad)) return 0;
    if (!(d.X() <= nrad) || !(d.Y() <= nrad) || !(d.Z() <= nrad) || !(d.W() <= nrad)) return 1;
    return r;
}
