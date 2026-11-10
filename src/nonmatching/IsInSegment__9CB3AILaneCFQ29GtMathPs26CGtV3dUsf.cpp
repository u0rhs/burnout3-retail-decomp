// NONMATCHING: IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUsf -- retail 250 / ours 249 instructions, 235 in changed runs
// draftAN fork C C-first: the float overload of the archived IsInSegment(CGtV3d, unsigned short): four edge tests with normalised horizontal normals Cross(edge, kYAxis) and the signed distance against lrTolerance (bit when NOT <=, retail c.le/bc1t): 4 far edge (unless degenerate), 1 left, 2 right, 8 near edge (unless degenerate); retail's unused degenerate-edge normals and the (seg+1)&0xFFFF vs seg+1 entry pair kept; 249/250, no calls, no non-stack stores
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: every vertex index (entry, lane), subtraction order, cross operand order (vopmula/vopmsub with kYAxis second), base point and compare sense traced edge by edge

// IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUsf -- draftAN fork C (C-first draft). 0x148690, 0x3E8. [C] name: the mangled
// symbol in retail's tables. The float overload of IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs (archived, 0x148440; its
// structs reused): the same four edge tests, but each edge's horizontal normal Cross(edge, kYAxis) is normalised and the point's
// signed distance compared with lrTolerance (a bit is set when the distance is NOT <= the tolerance: retail c.le.s / bc1t,
// so a NaN sets it). Bits [G as the sibling]: 4 = far edge (segment seg+1, unless degenerate), 1 = left side, 2 = right side,
// 8 = near edge (unless degenerate). [C] retail quirks kept: the far edge's normal comes from entry (unsigned short)(seg + 1) and
// its point from entry seg + 1 unmasked (the same entry unless seg == 0xFFFF); for a degenerate end edge retail still computes a
// normal from the next entry (seg + 2 / seg + 1) and never uses it (no side effect; kept to mirror the reads).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00148690_v { unsigned short field_0; unsigned short field_2; };   // left / right vertex index
struct CB3AILaneStruct {
    UnkStruct_00148690_v *field_0;
};
class CB3AILane {
public:
    int IsInSegment(CGtV3d pos, unsigned short seg, float lrTolerance) const;
    unsigned char pad_0[4];
    CB3AILaneStruct *field_4;
};
struct UnkStruct_00148690_e9 { CGtV3d field_0; };
struct UnkStruct_D_0064D354 {
    UnkStruct_00148690_e9 *field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_0064D354 D_0064D354;
extern CGtV3d kYAxis;

// 0x00148690
int CB3AILane::IsInSegment(CGtV3d pos, unsigned short seg, float lrTolerance) const
{
    UnkStruct_00148690_v *e = field_4->field_0;
    UnkStruct_00148690_e9 *p = D_0064D354.field_0;
    unsigned short next = (unsigned short)(seg + 1);
    unsigned short l0 = e[seg].field_0;
    unsigned short r0 = e[seg].field_2;
    unsigned short l1 = e[seg + 1].field_0;
    int flags = 0;
    CGtV3d n;
    bool ok;

    if (e[next].field_0 == e[next].field_2) {
        n = CrossProduct(p[e[next + 1].field_0].field_0 - p[e[next + 1].field_2].field_0, kYAxis);   // [C] unused
        ok = false;
    } else {
        n = CrossProduct(p[e[next].field_0].field_0 - p[e[next].field_2].field_0, kYAxis);
        ok = true;
    }
    if (ok) {
        n.Normalise();
        if (!(DotProduct(pos - p[l1].field_0, n) <= lrTolerance)) flags |= 4;
    }

    n = CrossProduct(p[l0].field_0 - p[l1].field_0, kYAxis);
    n.Normalise();
    if (!(DotProduct(pos - p[l1].field_0, n) <= lrTolerance)) flags |= 1;

    n = CrossProduct(p[e[seg + 1].field_2].field_0 - p[r0].field_0, kYAxis);
    n.Normalise();
    if (!(DotProduct(pos - p[r0].field_0, n) <= lrTolerance)) flags |= 2;

    if (l0 == r0) {
        n = CrossProduct(p[e[seg + 1].field_2].field_0 - p[l1].field_0, kYAxis);   // [C] unused
        ok = false;
    } else {
        n = CrossProduct(p[r0].field_0 - p[l0].field_0, kYAxis);
        ok = true;
    }
    if (ok) {
        n.Normalise();
        if (!(DotProduct(pos - p[r0].field_0, n) <= lrTolerance)) flags |= 8;
    }
    return flags;
}
