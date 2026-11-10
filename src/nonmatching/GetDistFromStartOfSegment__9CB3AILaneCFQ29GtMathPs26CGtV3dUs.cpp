// NONMATCHING: GetDistFromStartOfSegment__9CB3AILaneCFQ29GtMathPs26CGtV3dUs -- retail 102 / ours 102 instructions, 35 in changed runs
// ghvu4: GetFwdFrac shape + [G] inline (cross of the segment vs kYAxis, false when degenerate -> GetAvgForwardsVector); frame, VU numbering of branch 1 right; left: GPR naming (s ext in a3 / field_4 in a1 swapped), bool flag in v1 vs v0, branch-2 load order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

struct UnkStruct_00147670_e0 { float field_0; unsigned char pad_4[0x4]; };
struct UnkStruct_00147670_e2 { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_00147670_3 { UnkStruct_00147670_e2 * field_0; UnkStruct_00147670_e0 * field_4; };
struct UnkStruct_00147670_e3 { CGtV3d field_0; };
struct UnkStruct_D_0064D354 { UnkStruct_00147670_e3 * field_0; unsigned char pad_4[0xC]; };
class CB3AILane {
public:
    float GetDistFromStartOfSegment(CGtV3d, unsigned short) const;
    void GetAvgForwardsVector(unsigned short, CGtV3d *) const;
    unsigned char pad_0[0x4];
    UnkStruct_00147670_3 * field_4;
};
extern UnkStruct_D_0064D354 D_0064D354;
extern u_long128 kYAxis;

// [L] N185: the cross product with its result moved out `.i` (keeps retail's qmfc2 + sq), as GetAvgRightwardsVector's
static inline void func_00147670_inl1(CGtV3d *o, const CGtV3d &a, u_long128 b)
{
    u_long128 t;
    asm volatile("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b) : "j"(a.mData));
    o->mData = t;
}
// [L] N185: compiler-chosen vsub.xyz
static inline CGtV3d func_00147670_inl2(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
// [G] placeholder inline: the segment's sideways direction, false when the segment is degenerate
static inline bool func_00147670_inl3(const CB3AILane * l, unsigned short s, CGtV3d * out)
{
    UnkStruct_00147670_e2 * seg = &l->field_4->field_0[s];
    UnkStruct_00147670_e3 * p = D_0064D354.field_0;
    if (seg[0].field_0 != seg[0].field_2) {
        { CGtV3d d = func_00147670_inl2(p[seg[0].field_0].field_0, p[seg[0].field_2].field_0); func_00147670_inl1(out, d, kYAxis); }
        return true;
    }
    { CGtV3d d = func_00147670_inl2(p[seg[1].field_0].field_0, p[seg[1].field_2].field_0); func_00147670_inl1(out, d, kYAxis); }
    return false;
}

// [G] N140 frame pads: retail's frame keeps two more unused 16-byte slots
struct UnkStruct_00147670_pad { int x[4]; UnkStruct_00147670_pad() {} ~UnkStruct_00147670_pad() {} };

// 0x00147670
float CB3AILane::GetDistFromStartOfSegment(CGtV3d p1, unsigned short p0) const
{
    CGtV3d pos = p1;
    float len;
    if (p0 <= 0) {
        len = field_4->field_4[p0].field_0;
    } else {
        len = field_4->field_4[p0].field_0 - field_4->field_4[p0 - 1].field_0;
    }
    CGtV3d fwd;
    CGtV3d d = pos - D_0064D354.field_0[field_4->field_0[p0].field_0].field_0;
    ((float *)&d)[3] = ((const float *)&D_0064D354.field_0[field_4->field_0[p0].field_0].field_0)[3]; // [C] 0x1476D0 lqc2 vf1
    // (the vertex); 0x1476D4 vsub.xyz vf1, vf2, vf1 keeps its w; 0x1476DC sqc2 vf1, 0x50(sp) -- `a - b` took pos's w
    UnkStruct_00147670_pad q0;
    UnkStruct_00147670_pad q1;
    if (!func_00147670_inl3(this, p0, &fwd)) {
        GetAvgForwardsVector(p0, &fwd);
    }
    fwd.Normalise();
    return GtMath::Min(DotProduct(d, fwd), len);
}
