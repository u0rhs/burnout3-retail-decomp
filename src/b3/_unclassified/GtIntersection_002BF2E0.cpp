// GtIntersection::IntersectSphere(GtMathPs2::CGtSphere,const CGtOrientedBox&) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtIntersection.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (DotProduct/operator-(XAxisType,WAxisType) helpers [G]; 4 dead lane reads as frame pad, FAKEMATCH [G]).
// The 1.0 is DotProduct's own partial-lane statement; the build compiler b119p hoists it out of the loop as retail's did
// (N184; was an explicit pinned-$vf2 hoist under b119, N163).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
namespace GtMathPs2 {
// CGtSphere / CGtPlane now come from include/b3/GtMathPs2.h (header-API task, N185).
// GtMathPs2::DotProduct(CGtV3d, CGtV3d) now comes from include/b3/GtMathPs2.h (hdr6). The four dead lane reads are a frame
// pad: retail's frame keeps four more 16-byte slots below the sphere copy (inline-local temporaries of the real bodies, N129
// mechanism); dead converted locals in an inline wrapped around the call reproduce them. [G] placeholder for the pad wrapper.
static inline XAxisType func_002BF2E0_inl1(CGtV3d a, CGtV3d b)
{
    XAxisType d = DotProduct(a, b);
    XAxisType t0(d); float f0 = t0;   // FAKEMATCH [G]: frame pad (see above)
    XAxisType t1(d); float f1 = t1;
    XAxisType t2(d); float f2 = t2;
    XAxisType t3(d); float f3 = t3;
    return d;
}
// [C] API: B3O0PCH map (GtMathPs2::operator -(XAxisType,WAxisType), 80 bytes out of line). [G] body.
static inline XAxisType operator-(XAxisType a, WAxisType b)
{
    u_long128 e;
    asm("qmtc2.i %1, $vf1" "\n\t" "vsubw.x $vf1, $vf1, %2w" "\n\t" "qmfc2 %0, $vf1" : "=r"(e) : "r"(a.lVector), "j"(b.lVector));
    return XAxisType(e);
}
}
struct CGtOrientedBox { unsigned char pad_0[0x80]; CGtPlane maPlanes[6]; };   // [C] maPlanes at 0x80 (Revenge types.h)
class GtIntersection { public: static int IntersectSphere(CGtSphere s, const CGtOrientedBox& box); };

// 0x002BF2E0
int GtIntersection::IntersectSphere(CGtSphere s, const CGtOrientedBox& box)
{
    int r = 2;
    float rad = s.Radius();
    for (int i = 0; i < 6; i++) {
        float d = func_002BF2E0_inl1(s.Position(), box.maPlanes[i].Normal()) - box.maPlanes[i].Distance();
        if (!(d <= rad)) return 0;
        if (!(d <= -rad)) r = 1;
    }
    return r;
}
