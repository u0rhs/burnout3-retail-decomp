// NONMATCHING: IntersectSphere__14GtIntersectionFQ29GtMathPs29CGtSphereQ29GtMathPs29CGtSphere -- retail 45 / ours 45 instructions, 2 in changed runs
// pass3b: a pad inside SubW (deepest inline) lifts the SubW copy to 0x10 (frame 0x160 with an extra function pad) but the AddW copy then sits at 0x30 (2 off); two SubW pads give AddW 0x40 but SubW 0x20; pads at near20_subw level, an AddW wrapper with a pad, a block-scoped pad all miss. Need one dead slot between the SubW copy's temp and the AddW copy.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// near20: 7 -> 2, code identical and frame 0x160 exact (named CGtV3d d + header GetSquaredLength; 10 function-level N140 pads + 2 in a SubW wrapper put the AddW lane copy at retail's 0x40). Left: the SubW lane copy sits at sp+0x0, retail sp+0x10 (one more dead slot below it in retail; extra (float) lane reads of a WAxisType local are not CSE'd).


#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
static inline WAxisType AddW(const CGtSphere& a, const CGtSphere& b)
{ u_long128 t; asm("vaddw.w %0, %1, %2w" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return WAxisType(t); }
static inline WAxisType SubW(const CGtSphere& a, const CGtSphere& b)
{ u_long128 t; asm("vsubw.w %0, %1, %2w" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return WAxisType(t); }
// N140 pads [G]: retail frame 0x160 keeps 17 dead 16-byte slots above the radius-sum lane copy (0x40) and two
// between it and the radius-difference copy; ten function-level pads + two inside the SubW wrapper stand in for them.
struct UnkStruct_002BF530_pad { int x[4]; UnkStruct_002BF530_pad() {} ~UnkStruct_002BF530_pad() {} };
static inline float near20_subw(const CGtSphere& a, const CGtSphere& b)
{ UnkStruct_002BF530_pad p0; UnkStruct_002BF530_pad p1; WAxisType w = SubW(b, a); float r = w; return r; }
class GtIntersection { public: static int IntersectSphere(CGtSphere a, CGtSphere b); };
// 0x002BF530
int GtIntersection::IntersectSphere(CGtSphere a, CGtSphere b)
{
    UnkStruct_002BF530_pad q0;
    UnkStruct_002BF530_pad q1;
    UnkStruct_002BF530_pad q2;
    UnkStruct_002BF530_pad q3;
    UnkStruct_002BF530_pad q4;
    UnkStruct_002BF530_pad q5;
    UnkStruct_002BF530_pad q6;
    UnkStruct_002BF530_pad q7;
    UnkStruct_002BF530_pad q8;
    UnkStruct_002BF530_pad q9;
    CGtV3d d = a.Position() - b.Position();
    float d2 = d.GetSquaredLength();
    float rs = AddW(a, b);
    if (!(d2 <= rs * rs)) return 0;
    float rd = near20_subw(a, b);
    if (rd < 0) return 1;
    return d2 < rd * rd ? 2 : 1;
}



