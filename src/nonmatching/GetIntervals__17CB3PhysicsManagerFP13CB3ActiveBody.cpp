// NONMATCHING: GetIntervals__17CB3PhysicsManagerFP13CB3ActiveBody -- retail 77 / ours 77 instructions, 53 in changed runs
// ghvu2: logic + frame exact (transpose stand-ins, lane-wise vmul, header Min/Max, x+y+z lane-sum stand-in, SetX/Y/Z-from-x-lane stand-ins, 0x2C0 N140 pad); left: VU register numbering only (retail T0/T1/T2 = vf10/vf4/vf7, ours vf7/vf6/vf9) -- needs header APIs for transpose/lane-sum
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3PhysicsManager::GetIntervals(CB3ActiveBody*) -- hand-written from retail (ghvu2; the lifter refused vmini.xyz).
// [C] name: the mangled symbol in retail's tables. Area not evidenced, so _unclassified/ (docs/conventions.md). Structs carry only
// the fields touched; every type is [G]. Reading [G]: an oriented box (matrix rows, two extent vectors) to an axis-aligned
// interval pair: the 3x3 transposed, scaled by both extents, per-axis min/max lane sums, plus the matrix position.

#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

class CB3ActiveBody;

struct UnkStruct_001B4AB0_8 {
    CGtV3d field_0;
    CGtV3d field_10;
};

class CB3ActiveBody {
public:
    unsigned char pad_0[0x4];
    CGtMatrix3x4 * field_4;
    UnkStruct_001B4AB0_8 * field_8;
    unsigned char pad_C[0x4];
    CGtV3d field_10;
    CGtV3d field_20;
};

class CB3PhysicsManager {
public:
    void GetIntervals(CB3ActiveBody * p0);
};

// [L] N185: stand-ins for GtMathPs2 inlines missing from the header (compiler-chosen VU registers): one lane of a
// vector copied into another lane of this one (the transpose), the lane-wise product, the x+y+z lane sum.
static inline void func_001B4AB0_r0(CGtV3d &t0, CGtV3d &t1, CGtV3d &t2, const CGtV3d &r)
{
    asm("vaddx.x %0, $vf0, %1x" : "+j"(t0.mData) : "j"(r.mData));
    asm("vaddy.x %0, $vf0, %1y" : "+j"(t1.mData) : "j"(r.mData));
    asm("vaddz.x %0, $vf0, %1z" : "+j"(t2.mData) : "j"(r.mData));
}
static inline void func_001B4AB0_r1(CGtV3d &t0, CGtV3d &t1, CGtV3d &t2, const CGtV3d &r)
{
    asm("vaddx.y %0, $vf0, %1x" : "+j"(t0.mData) : "j"(r.mData));
    asm("vaddy.y %0, $vf0, %1y" : "+j"(t1.mData) : "j"(r.mData));
    asm("vaddz.y %0, $vf0, %1z" : "+j"(t2.mData) : "j"(r.mData));
}
static inline void func_001B4AB0_r2(CGtV3d &t0, CGtV3d &t1, CGtV3d &t2, const CGtV3d &r)
{
    asm("vaddx.z %0, $vf0, %1x" : "+j"(t0.mData) : "j"(r.mData));
    asm("vaddy.z %0, $vf0, %1y" : "+j"(t1.mData) : "j"(r.mData));
    asm("vaddz.z %0, $vf0, %1z" : "+j"(t2.mData) : "j"(r.mData));
}
static inline CGtV3d func_001B4AB0_mul(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 t;
    asm("vmul.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(t);
}
static inline XAxisType func_001B4AB0_sum(const CGtV3d &a)
{
    u_long128 t;
    asm("vaddy.x %0, %1, %1y" "\n\t" "vaddz.x %0, %0, %1z" : "=j"(t) : "j"(a.mData));
    return XAxisType(t);
}
static inline void func_001B4AB0_setx(CGtV3d &d, XAxisType a) { asm("vaddx.x %0, $vf0, %1x" : "+j"(d.mData) : "j"(a.lVector)); }
static inline void func_001B4AB0_sety(CGtV3d &d, XAxisType a) { asm("vaddx.y %0, $vf0, %1x" : "+j"(d.mData) : "j"(a.lVector)); }
static inline void func_001B4AB0_setz(CGtV3d &d, XAxisType a) { asm("vaddx.z %0, $vf0, %1x" : "+j"(d.mData) : "j"(a.lVector)); }

static inline void func_001B4AB0_tr(CGtV3d &t0, CGtV3d &t1, CGtV3d &t2, const CGtMatrix3x4 &m)
{
    func_001B4AB0_r0(t0, t1, t2, m.mRight);
    func_001B4AB0_r1(t0, t1, t2, m.mUp);
    func_001B4AB0_r2(t0, t1, t2, m.mAt);
}
// [G] N140 pad: retail's frame is 0x310 with 0x2C0 bytes below the five used 16-byte slots never accessed.
struct UnkStruct_001B4AB0_pad { int x[176]; UnkStruct_001B4AB0_pad() {} ~UnkStruct_001B4AB0_pad() {} };
// 0x001B4AB0
void CB3PhysicsManager::GetIntervals(CB3ActiveBody * p0)
{
    CGtMatrix3x4 * m = p0->field_4;
    UnkStruct_001B4AB0_8 e = *p0->field_8;
    CGtV3d t0, t1, t2;
    UnkStruct_001B4AB0_pad pad;
    func_001B4AB0_tr(t0, t1, t2, *m);
    CGtV3d a0 = func_001B4AB0_mul(t0, e.field_0);
    CGtV3d b0 = func_001B4AB0_mul(t0, e.field_10);
    CGtV3d a1 = func_001B4AB0_mul(t1, e.field_0);
    CGtV3d b1 = func_001B4AB0_mul(t1, e.field_10);
    CGtV3d a2 = func_001B4AB0_mul(t2, e.field_0);
    CGtV3d b2 = func_001B4AB0_mul(t2, e.field_10);
    CGtV3d n0 = Min(b0, a0), x0 = Max(b0, a0);
    CGtV3d n1 = Min(b1, a1), x1 = Max(b1, a1);
    CGtV3d n2 = Min(b2, a2), x2 = Max(b2, a2);
    func_001B4AB0_setx(p0->field_10, func_001B4AB0_sum(n0));
    func_001B4AB0_setx(p0->field_20, func_001B4AB0_sum(x0));
    func_001B4AB0_sety(p0->field_10, func_001B4AB0_sum(n1));
    func_001B4AB0_sety(p0->field_20, func_001B4AB0_sum(x1));
    func_001B4AB0_setz(p0->field_10, func_001B4AB0_sum(n2));
    func_001B4AB0_setz(p0->field_20, func_001B4AB0_sum(x2));
    p0->field_10 += m->mPos;
    p0->field_20 += m->mPos;
}
