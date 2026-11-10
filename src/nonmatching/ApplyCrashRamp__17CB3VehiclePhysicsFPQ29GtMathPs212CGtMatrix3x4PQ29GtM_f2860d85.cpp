// NONMATCHING: ApplyCrashRamp__17CB3VehiclePhysicsFPQ29GtMathPs212CGtMatrix3x4PQ29GtMathPs26CGtV3db -- retail 218 / ours 218 instructions, 30 in changed runs
// ghvu12: six ramp triangles (2 per bool arm from cross of corner differences, 4 from matrix rows, header Normalise in place); VU of the cross blocks exact with a noreorder-wrapped in-place cross stand-in; left: retail CSEs &p[k] into a3 for the second triangle's VU load only (the copy store reads direct), shifting the normal GPR t0<->a3; tail tri2's -mRight product on vf1 in place (ours vf3)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

// [L] N185: compiler-chosen CGtV3d operator- stand-in
static inline CGtV3d func_001CBF30_sub(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
// [L] N185: in-place Normalise on a compiler-chosen register stand-in
static inline void func_001CBF30_norm(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 r = v.mData;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(r));
    asm(".set reorder");
    v.mData = r;
}
// [L] N185: CrossProduct(a, b) with the result on a's register stand-in
static inline CGtV3d func_001CBF30_cross(CGtV3d a, CGtV3d b)
{ asm(".set noreorder"); asm("vopmula.xyz $ACC, %0, %1" "\n\t" "vopmsub.xyz %0, %1, %0" : "+j"(a.mData) : "j"(b.mData)); asm(".set reorder"); return a; }
struct UnkStruct_001CBF30_tri { CGtV3d field_0; CGtV3d field_10; CGtV3d field_20; CGtV3d field_30; };
// [G] a ramp triangle: three corners and the unit normal of (a - b) x (a - c)
static inline void func_001CBF30_inl1(UnkStruct_001CBF30_tri &t, const CGtV3d &a, const CGtV3d &b, const CGtV3d &c)
{
    CGtV3d n = func_001CBF30_cross(func_001CBF30_sub(a, b), func_001CBF30_sub(a, c));
    func_001CBF30_norm(n);
    t.field_0 = a;
    t.field_10 = b;
    t.field_20 = c;
    t.field_30 = n;
}
// [G] a ramp triangle with a given normal, normalised in place
static inline void func_001CBF30_inl2(UnkStruct_001CBF30_tri &t, const CGtV3d &a, const CGtV3d &b, const CGtV3d &c, const CGtV3d &n)
{
    t.field_0 = a;
    t.field_10 = b;
    t.field_20 = c;
    t.field_30 = n;
    t.field_30.Normalise();
}
class CB3VehiclePhysics {
public:
    void ApplyCrashRamp(CGtMatrix3x4 *m, CGtV3d *p, bool b);
    unsigned char pad_0[0x11D0];
    UnkStruct_001CBF30_tri field_11D0[6];
    unsigned char pad_1350;
    bool field_1351;
};

// 0x001CBF30
void CB3VehiclePhysics::ApplyCrashRamp(CGtMatrix3x4 *m, CGtV3d *p, bool b)
{
    if (b) {
        CGtV3d *q = &p[2];
        func_001CBF30_inl1(field_11D0[0], p[5], p[2], p[4]);
        func_001CBF30_inl1(field_11D0[1], p[5], p[3], *q);
    } else {
        CGtV3d *q = &p[3];
        func_001CBF30_inl1(field_11D0[0], p[4], p[5], p[3]);
        func_001CBF30_inl1(field_11D0[1], p[4], *q, p[2]);
    }
    func_001CBF30_inl2(field_11D0[2], p[4], p[2], p[0], m->mRight * -1.0f);
    func_001CBF30_inl2(field_11D0[3], p[5], p[3], p[1], m->mRight);
    func_001CBF30_inl2(field_11D0[4], p[5], p[1], p[0], m->mAt);
    func_001CBF30_inl2(field_11D0[5], p[5], p[0], p[4], m->mAt);
    field_1351 = true;
}




