// NONMATCHING: GetDefaultCornerHeights__16CB3VehicleDeformFP13CB3ConvexHullPf -- retail 116 / ours 116 instructions, 22 in changed runs
// near29: h[i] = inl(CGtV3d a, CGtV3d b){return a.Y()-b.Y();} by value -> frame 0x240 exact, 116/116, 22 off. Left: VU numbering (retail a->vf2, b->vf1, result vf1; ours a->vf1, result vf2) and lane-copy slots (retail 0xD0/0xA0/0x70/0x40 stride 0x30 interleaved with the arg copies; ours grouped at 0x40-0x70)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: GetDefaultCornerHeights__16CB3VehicleDeformFP13CB3ConvexHullPf -- retail 116 / ours 119 instructions, 39 in changed runs
// v242: logic complete (116 vs 119, 39 changed, frame 0x1C0 vs 0x240). 8 FindPointNearestTo(this, &D_004D39E0+16k, hull, hull->field_8, 8, &pk); h[i] = pj.Y() - pk.Y() (header operator-(Y,Y)); then h[i] = Max(h[0], 0.05f) (retail reads h[0] every iteration). Left: VU numbering swapped (retail a-operand vf2, b vf1), our YAxisType lane reads hoist sp+K+4 addresses into registers (retail lwc1 K+4(sp) direct), retail keeps 3 slots per lane subtraction + 14 more temps.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

class CB3ConvexHull { public: unsigned char pad_0[0x8]; CGtV3d *field_8; };
extern const CGtV3d D_004D39E0;
extern const CGtV3d D_004D39F0;
extern const CGtV3d D_004D3A00;
extern const CGtV3d D_004D3A10;
extern const CGtV3d D_004D3A20;
extern const CGtV3d D_004D3A30;
extern const CGtV3d D_004D3A40;
extern const CGtV3d D_004D3A50;
// [L] the mangled name's three floats are not register arguments (a235's FindPointNearestTo archive): a1 is the point
extern "C" void FindPointNearestTo__16CB3VehicleDeformFfffP13CB3ConvexHullPQ29GtMathPs26CGtV3d18EMainBodyBoneIndexPQ29GtMathPs26CGtV3d(void *self, const CGtV3d *v, CB3ConvexHull *hull, CGtV3d *pts, int bone, CGtV3d *out);
static inline float func_00461270_inl1(CGtV3d a, CGtV3d b)
{
    return a.Y() - b.Y();
}
class CB3VehicleDeform {
public:
    void GetDefaultCornerHeights(CB3ConvexHull *hull, float *h);
};

// 0x00461270
void CB3VehicleDeform::GetDefaultCornerHeights(CB3ConvexHull *hull, float *h)
{
    CGtV3d p0, p1, p2, p3, p4, p5, p6, p7;
    FindPointNearestTo__16CB3VehicleDeformFfffP13CB3ConvexHullPQ29GtMathPs26CGtV3d18EMainBodyBoneIndexPQ29GtMathPs26CGtV3d(this, &D_004D39E0, hull, hull->field_8, 8, &p0);
    FindPointNearestTo__16CB3VehicleDeformFfffP13CB3ConvexHullPQ29GtMathPs26CGtV3d18EMainBodyBoneIndexPQ29GtMathPs26CGtV3d(this, &D_004D39F0, hull, hull->field_8, 8, &p1);
    FindPointNearestTo__16CB3VehicleDeformFfffP13CB3ConvexHullPQ29GtMathPs26CGtV3d18EMainBodyBoneIndexPQ29GtMathPs26CGtV3d(this, &D_004D3A00, hull, hull->field_8, 8, &p2);
    FindPointNearestTo__16CB3VehicleDeformFfffP13CB3ConvexHullPQ29GtMathPs26CGtV3d18EMainBodyBoneIndexPQ29GtMathPs26CGtV3d(this, &D_004D3A10, hull, hull->field_8, 8, &p3);
    FindPointNearestTo__16CB3VehicleDeformFfffP13CB3ConvexHullPQ29GtMathPs26CGtV3d18EMainBodyBoneIndexPQ29GtMathPs26CGtV3d(this, &D_004D3A20, hull, hull->field_8, 8, &p4);
    FindPointNearestTo__16CB3VehicleDeformFfffP13CB3ConvexHullPQ29GtMathPs26CGtV3d18EMainBodyBoneIndexPQ29GtMathPs26CGtV3d(this, &D_004D3A30, hull, hull->field_8, 8, &p5);
    FindPointNearestTo__16CB3VehicleDeformFfffP13CB3ConvexHullPQ29GtMathPs26CGtV3d18EMainBodyBoneIndexPQ29GtMathPs26CGtV3d(this, &D_004D3A40, hull, hull->field_8, 8, &p6);
    FindPointNearestTo__16CB3VehicleDeformFfffP13CB3ConvexHullPQ29GtMathPs26CGtV3d18EMainBodyBoneIndexPQ29GtMathPs26CGtV3d(this, &D_004D3A50, hull, hull->field_8, 8, &p7);
    h[0] = func_00461270_inl1(p1, p0);
    h[1] = func_00461270_inl1(p5, p4);
    h[2] = func_00461270_inl1(p3, p2);
    h[3] = func_00461270_inl1(p7, p6);
    for (int i = 0; i < 4; i++) {
        h[i] = GtMath::Max(h[0], 0.05f);
    }
}

