// NONMATCHING: GetAvgForwardsVector__9CB3AILaneCFUsPQ29GtMathPs26CGtV3d -- retail 98 / ours 97 instructions, 51 in changed runs
// ghvu4: logic right (4-point sums, closed/open lane ends); left: retail reloads l->field_0 in every branch arm (ours CSEs it), branch load order, compiler-chosen VU numbering of the 7 vadds (vf1..vf4)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00147D00_e0 {
    unsigned short field_0;
    unsigned short field_2;
};
struct UnkStruct_00147D00_2 {
    UnkStruct_00147D00_e0 * field_0;
    unsigned char pad_4[0x8];
    unsigned short field_C;
    unsigned char field_E;
};
struct UnkStruct_D_0064D354 {
    CGtV3d * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
class CB3AILane;
class CB3AILane {
public:
    void GetAvgForwardsVector(unsigned short, CGtV3d *) const;
    unsigned char pad_0[0x4];
    UnkStruct_00147D00_2 * field_4;
};
extern UnkStruct_D_0064D354 D_0064D354;
// [L] N185: compiler-chosen vadd/vsub on full vectors (retail registers, no $vf1/$vf2 pinning)
static inline CGtV3d func_00147D00_inl1(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vadd.xyz %0, %2, %1" : "=j"(r) : "j"(b.mData), "j"(a.mData)); return CGtV3d(r); }
static inline CGtV3d func_00147D00_inl2(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline CGtV3d func_00147D00_inl3(const UnkStruct_00147D00_2 * l, unsigned short s)
{
    CGtV3d * p = D_0064D354.field_0;
    return func_00147D00_inl1(func_00147D00_inl1(func_00147D00_inl1(p[l->field_0[s].field_0], p[l->field_0[s].field_2]), p[l->field_0[s + 1].field_0]), p[l->field_0[s + 1].field_2]);
}
static inline CGtV3d func_00147D00_inl4(int c0, int c1, int d0, int d1)
{
    CGtV3d * p = D_0064D354.field_0;
    return func_00147D00_inl1(func_00147D00_inl1(func_00147D00_inl1(p[c0], p[c1]), p[d0]), p[d1]);
}

// 0x00147D00
void CB3AILane::GetAvgForwardsVector(unsigned short s, CGtV3d * out) const
{
    UnkStruct_00147D00_2 * l = field_4;
    int c0, c1, d0, d1;
    if (s == l->field_C - 2) {
        if (l->field_E) {
            d1 = l->field_0[1].field_2;
            d0 = l->field_0[1].field_0;
        } else {
            d0 = l->field_0[l->field_C].field_0;
            d1 = l->field_0[l->field_C].field_2;
        }
        c1 = l->field_0[s + 2].field_2;
        c0 = l->field_0[s + 2].field_0;
    } else if (s == l->field_C - 1) {
        if (l->field_E) {
            c1 = l->field_0[1].field_2;
            d0 = l->field_0[2].field_0;
            d1 = l->field_0[2].field_2;
            c0 = l->field_0[1].field_0;
        } else {
            c0 = l->field_0[l->field_C].field_0;
            c1 = l->field_0[l->field_C].field_2;
            d0 = c0;
            d1 = c1;
        }
    } else {
        c1 = l->field_0[s + 2].field_2;
        d0 = l->field_0[s + 3].field_0;
        d1 = l->field_0[s + 3].field_2;
        c0 = l->field_0[s + 2].field_0;
    }
    *out = func_00147D00_inl2(func_00147D00_inl4(c0, c1, d0, d1), func_00147D00_inl3(l, s));
}
