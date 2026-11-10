// NONMATCHING: _SubdivideCurveSection__16CGt2dBezierCurveFP16CGtBezierSectionP16CGtBezierSectionP16CGtBezierSection -- retail 136 / ours 135 instructions, 100 in changed runs
// sm9: logic, lane-read order and the hard-coded VU registers right (rows qmtc2.i, vectors .ni, results qmfc2.i; second call reuses vf7/vf6 like retail). Left: frame 0x290 vs 0x2D0 (retail has 4 more dead 16-byte slots; lane copies sit 0x20 higher), retail interleaves qmtc2 with the vmula ops and folds only R0 into lqc2.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GtMath.h"

using namespace GtMathPs2;

struct CGtBezierSection {
    CGtV2d pt[4];
    CGtV2d field_20;
};

// [C] names: config/symbol_addrs_b3names.txt (0x4D12E0 / 0x4D1320, .rodata, 0x40 each). Type [G]: four 16-byte rows.
extern const CGtV4d _kTransposedLeftSubCurveMatrix[4];
extern const CGtV4d _kTransposedRightSubCurveMatrix[4];

// [L] N185: stands in for a 4x4 matrix * vector inline (rows on $vf5/$vf4/$vf3/$vf1, as retail)
static inline void func_0041DD70_inl1(const CGtV4d *m, const CGtV4d xs, const CGtV4d ys, CGtV4d &rx, CGtV4d &ry)
{
    asm("qmtc2.i %0, $vf5" : : "r"(m[0].mData));
    asm("qmtc2.i %0, $vf4" : : "r"(m[1].mData));
    asm("qmtc2.i %0, $vf3" : : "r"(m[2].mData));
    asm("qmtc2.i %0, $vf1" : : "r"(m[3].mData));
    asm("qmtc2.ni %0, $vf7" : : "r"(xs.mData));
    asm("vmulax.xyzw $ACC, $vf5, $vf7x" "\n\t" "vmadday.xyzw $ACC, $vf4, $vf7y" "\n\t"
        "vmaddaz.xyzw $ACC, $vf3, $vf7z" "\n\t" "vmaddw.xyzw $vf2, $vf1, $vf7w");
    asm("qmfc2.i %0, $vf2" : "=r"(rx.mData));
    asm("qmtc2.ni %0, $vf6" : : "r"(ys.mData));
    asm("vmulax.xyzw $ACC, $vf5, $vf6x" "\n\t" "vmadday.xyzw $ACC, $vf4, $vf6y" "\n\t"
        "vmaddaz.xyzw $ACC, $vf3, $vf6z" "\n\t" "vmaddw.xyzw $vf1, $vf1, $vf6w");
    asm("qmfc2.i %0, $vf1" : "=r"(ry.mData));
}
// [L] GtMath::Interpolate(float,float,float) (E map 0x14CCF0), the body as func_001D1130_inl7
static inline float func_0041DD70_inl2(float a, float b, float t) { float d = b - a; return a + t * d; }

extern "C" void _SubdivideCurveSection__16CGt2dBezierCurveFP16CGtBezierSectionP16CGtBezierSectionP16CGtBezierSection(
    CGtBezierSection * sec, CGtBezierSection * left, CGtBezierSection * right)
{
    CGtV4d xs(sec->pt[0].X(), sec->pt[1].X(), sec->pt[2].X(), sec->pt[3].X());
    CGtV4d ys(sec->pt[0].Y(), sec->pt[1].Y(), sec->pt[2].Y(), sec->pt[3].Y());
    CGtV4d rx;
    CGtV4d ry;
    func_0041DD70_inl1(_kTransposedLeftSubCurveMatrix, xs, ys, rx, ry);
    left->pt[0].SetX(rx.X());
    left->pt[0].SetY(ry.X());
    left->pt[1].SetX(rx.Y());
    left->pt[1].SetY(ry.Y());
    left->pt[2].SetX(rx.Z());
    left->pt[2].SetY(ry.Z());
    left->pt[3].SetX(rx.W());
    left->pt[3].SetY(ry.W());
    left->field_20 = CGtV2d(sec->field_20.X(), func_0041DD70_inl2(sec->field_20.X(), sec->field_20.Y(), 0.5f));
    func_0041DD70_inl1(_kTransposedRightSubCurveMatrix, xs, ys, rx, ry);
    right->pt[0].SetX(rx.X());
    right->pt[0].SetY(ry.X());
    right->pt[1].SetX(rx.Y());
    right->pt[1].SetY(ry.Y());
    right->pt[2].SetX(rx.Z());
    right->pt[2].SetY(ry.Z());
    right->pt[3].SetX(rx.W());
    right->pt[3].SetY(ry.W());
    right->field_20 = CGtV2d(left->field_20.Y(), sec->field_20.Y());
}




