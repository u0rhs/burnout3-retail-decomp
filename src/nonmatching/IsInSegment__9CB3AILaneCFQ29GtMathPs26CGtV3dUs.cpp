// NONMATCHING: IsInSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs -- retail 148 / ours 151 instructions, 105 in changed runs
// logic believed right (bit 4: l1->r1 edge if l1!=r1, 1: l0->l1, 2: r0->r1, 8: l0->r0 if r0!=l0; side = DotProduct(p - a, +/-Cross(b - a, kYAxis)) > 0); block order via goto + scoped opt_repositioncode off [G] (retail's dead 'ori v0,1' at 0x1484FC is a repositioner tail-dup artifact the pragma form can't give). Left: cross->GPR round trip (a .i cross stand-in gives it: variant g8), p-a scheduled before the cross (VU pressure -> square parked), frame 0x90 vs 0xD0 (3 dead slots per side test)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3AILane::IsInSegment(CGtV3d, unsigned short) const -- hand-matched (ghvu8). Structs as the proven sibling
// GetTotalWidth (B3AILane_00148140.cpp): field_4->field_0[s] holds the segment's left/right vertex indices, the
// vertices are D_0064D354.field_0[]. Returns a bit per edge the point lies outside of [G].
#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

struct UnkStruct_00148440_v { unsigned short field_0; unsigned short field_2; };
struct CB3AILaneStruct {
    UnkStruct_00148440_v *field_0;
};
class CB3AILane {
public:
    int IsInSegment(CGtV3d pos, unsigned short seg) const;
    unsigned char pad_0[4];
    CB3AILaneStruct *field_4;
};
struct UnkStruct_00148440_e9 { CGtV3d field_0; };
struct UnkStruct_D_0064D354 {
    UnkStruct_00148440_e9 *field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_0064D354 D_0064D354;
extern CGtV3d kYAxis;

// [L] N185: CGtV3d - CGtV3d on compiler-chosen registers (the header's goes through $vf1/$vf2 and GPRs)
static inline CGtV3d IsInSegment_inl1(const CGtV3d &a, const CGtV3d &b) {
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
// [L] N185: unary minus on compiler-chosen registers (the header's hard-codes $vf1)
static inline CGtV3d IsInSegment_inl2(const CGtV3d &a) {
    u_long128 r;
    asm("vsub.xyz %0, $vf0, %1" : "=j"(r) : "j"(a.mData));
    return CGtV3d(r);
}

// [G] side test of p against the edge a->b (vertical plane through the edge)
static inline bool IsInSegment_inl3(CGtV3d p, CGtV3d a, CGtV3d b) {
    return DotProduct(IsInSegment_inl1(p, a), CrossProduct(IsInSegment_inl1(b, a), kYAxis)) > 0.0f;
}
static inline bool IsInSegment_inl4(CGtV3d p, CGtV3d a, CGtV3d b) {
    return DotProduct(IsInSegment_inl1(p, a), IsInSegment_inl2(CrossProduct(IsInSegment_inl1(b, a), kYAxis))) > 0.0f;
}

// N182: scoped `opt_repositioncode off` [G] scoped to this function, goto form in retail's block order
#pragma push
#pragma opt_repositioncode off
// 0x00148440
int CB3AILane::IsInSegment(CGtV3d pos, unsigned short seg) const
{
    CGtV3d pc = pos;
    int r = 0;
    unsigned short l0 = field_4->field_0[seg].field_0;
    unsigned short r0 = field_4->field_0[seg].field_2;
    unsigned short l1 = field_4->field_0[seg + 1].field_0;
    unsigned short r1 = field_4->field_0[seg + 1].field_2;
    if (l1 == r1) goto left;
    if (!IsInSegment_inl4(pc, D_0064D354.field_0[l1].field_0, D_0064D354.field_0[r1].field_0)) goto left;
    r |= 4;
    goto left;
right:
    if (IsInSegment_inl3(pc, D_0064D354.field_0[r0].field_0, D_0064D354.field_0[r1].field_0)) r |= 2;
    if (r0 == l0) return r;
    if (IsInSegment_inl3(pc, D_0064D354.field_0[l0].field_0, D_0064D354.field_0[r0].field_0)) r |= 8;
    return r;
left:
    if (!IsInSegment_inl4(pc, D_0064D354.field_0[l0].field_0, D_0064D354.field_0[l1].field_0)) goto right;
    r |= 1;
    goto right;
}
#pragma pop
