// NONMATCHING: ApplyRamp__17CB3VehiclePhysicsFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d -- retail 105 / ours 103 instructions, 71 in changed runs
// ghvu5: logic complete (cross x2, six fan points, 4 tris, normals). Left: retail keeps lq+qmtc2.ni for pos/dir/size/kY (ours folds to lqc2; .i-move stand-ins in ghvu5_x4.txt keep them but number pos/size above A: retail A=vf8,pos=vf7,size=vf6 -> they are created later/deeper, e.g. inside operator inlines); frame 0x1C0 vs 0x60 (pts[6] at sp+0x130..0x180 plus ~22 dead slots); retail CrossProduct writes the result over its first operand (vopmula ACC,a,b; vopmsub a,b,a), not the header's b-register form.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3VehiclePhysics::ApplyRamp(CGtV3d, CGtV3d, CGtV3d) -- hand-written (ghvu5, Ghidra draft).
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/ (docs/conventions.md).
// [G] builds a six-point ramp outline (pos, dir, size) and a four-triangle fan from point 0 into field_11D0
// (0x40-byte records: three corners and a normal), then the normals.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
extern u_long128 kYAxis;
struct UnkStruct_001CC200_t { CGtV3d field_0; CGtV3d field_10; CGtV3d field_20; CGtV3d field_30; };
class CB3VehiclePhysics {
public:
    void ApplyRamp(CGtV3d, CGtV3d, CGtV3d);
    unsigned char pad_0[0x11D0];
    UnkStruct_001CC200_t field_11D0[6];
    unsigned char field_1350;
};
// [L] N185: stands in for missing GtMathPs2 inlines -- CGtV3d::operator*(XAxisType/YAxisType/ZAxisType) (B3O0PCH map, 68 bytes)
static inline CGtV3d func_001CC200_inl1(const CGtV3d &v, XAxisType s) { u_long128 t; asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(v.mData), "j"(s.lVector)); return CGtV3d(t); }
static inline CGtV3d func_001CC200_inl2(const CGtV3d &v, YAxisType s) { u_long128 t; asm("vmuly.xyz %0, %1, %2y" : "=j"(t) : "j"(v.mData), "j"(s.lVector)); return CGtV3d(t); }
static inline CGtV3d func_001CC200_inl3(const CGtV3d &v, ZAxisType s) { u_long128 t; asm("vmulz.xyz %0, %1, %2z" : "=j"(t) : "j"(v.mData), "j"(s.lVector)); return CGtV3d(t); }
// [L] N185: CrossProduct with the result on its own compiler-chosen register, moved out .i (vu0_ni_fixup -> .ni)
static inline CGtV3d func_001CC200_inl4(CGtV3d a, CGtV3d b)
{
    u_long128 t, r;
    asm("vopmula.xyz $ACC, %1, %2" "\n\t" "vopmsub.xyz %0, %2, %1" : "=j"(t) : "j"(a.mData), "j"(b.mData));
    asm("qmfc2.i %0, %1" : "=r"(r) : "j"(t));
    return CGtV3d(r);
}
// [L] N185: CGtV3d + / - on compiler-chosen registers (retail vadd.xyz/vsub.xyz here use no hard-coded $vf1/$vf2)
static inline CGtV3d func_001CC200_inl5(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vadd.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
static inline CGtV3d func_001CC200_inl6(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData)); return CGtV3d(t); }
// 0x001CC200
void CB3VehiclePhysics::ApplyRamp(CGtV3d pos, CGtV3d dir, CGtV3d size)
{
    CGtV3d pts[6];
    u_long128 p = pos.mData;
    u_long128 s = size.mData;
    u_long128 y = kYAxis;
    u_long128 d = dir.mData;
    CGtV3d side = func_001CC200_inl4(CGtV3d(y), CGtV3d(d));
    CGtV3d up = func_001CC200_inl4(CGtV3d(d), side);
    pts[0] = func_001CC200_inl5(CGtV3d(p), func_001CC200_inl2(up, CGtV3d(s).Y()));
    pts[1] = func_001CC200_inl6(CGtV3d(p), func_001CC200_inl1(side, CGtV3d(s).X()));
    pts[2] = func_001CC200_inl5(func_001CC200_inl6(CGtV3d(p), func_001CC200_inl1(side, CGtV3d(s).X()) * 0.707f), func_001CC200_inl3(CGtV3d(d), CGtV3d(s).Z()) * 0.707f);
    pts[3] = func_001CC200_inl5(CGtV3d(p), func_001CC200_inl3(CGtV3d(d), CGtV3d(s).Z()));
    pts[4] = func_001CC200_inl5(func_001CC200_inl5(CGtV3d(p), func_001CC200_inl1(side, CGtV3d(s).X()) * 0.707f), func_001CC200_inl3(CGtV3d(d), CGtV3d(s).Z()) * 0.707f);
    pts[5] = func_001CC200_inl5(CGtV3d(p), func_001CC200_inl1(side, CGtV3d(s).X()));
    field_11D0[0].field_0 = pts[0];
    field_11D0[0].field_10 = pts[1];
    field_11D0[0].field_20 = pts[2];
    field_11D0[1].field_0 = pts[0];
    field_11D0[1].field_10 = pts[2];
    field_11D0[1].field_20 = pts[3];
    field_11D0[2].field_0 = pts[0];
    field_11D0[2].field_10 = pts[3];
    field_11D0[2].field_20 = pts[4];
    field_11D0[3].field_0 = pts[0];
    field_11D0[3].field_10 = pts[4];
    field_11D0[3].field_20 = pts[5];
    for (int j = 0; j < 4; j++) {
        CGtV3d e0 = func_001CC200_inl6(field_11D0[j].field_0, field_11D0[0].field_10);
        CGtV3d e1 = func_001CC200_inl6(field_11D0[j].field_20, field_11D0[0].field_10);
        field_11D0[j].field_30 = func_001CC200_inl4(e1, e0);
        field_11D0[j].field_30.Normalise();
    }
    field_1350 = 1;
}


