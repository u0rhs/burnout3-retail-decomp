// NONMATCHING: func_003E7640 -- retail 130 / ours 131 instructions, 5 in changed runs
// v278: 5 off. Fixed: both matrices at function scope (v272), DotProduct stand-in with vadday as its own non-region statement and only vmaddz in a noreorder region (retail: vmul; vaddw.x one; qmfc2 park; vadday), Normalise stand-in's rsqrt/scale statement in a noreorder region (keeps qmfc2 right after vmulq). Left: (1) case 2 schedules addiu a1/a2 (&m.mUp/&m.mAt) before the dot result's qmfc2/qmtc2 round trip (case 3 identical code is right); (2) a dead copy of the default's lw v1,0x18(a1) stays after the b delay-slot fill (retail moves it); every variant with a .set noreorder region keeps it, the region-free dot (c0) drops it but reshuffles everything
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// [L] DNAT: CB3VehicleDeform::GetDefaultVirtualBoneMatrix(EVirtualBoneIndex) (research/proto/new_names.csv, medium)
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_003E7640_1 {
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70[6];   // [G] count
};
struct UnkStruct_003E7640_self {
    unsigned char pad_0[0x18];
    UnkStruct_003E7640_1 * field_18;
};
extern int kaeVirtualToNormalBone[7];

#define V256_ZERO(f) { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); f.mData = r; }
#define V256_IDX(f) { u_long128 r = f.mData; asm("vaddw.x %0, $vf0, $vf0w" : "+j"(r)); f.mData = r; }
#define V256_IDY(f) { u_long128 r = f.mData; asm("vaddw.y %0, $vf0, $vf0w" : "+j"(r)); f.mData = r; }
#define V256_IDZ(f) { u_long128 r = f.mData; asm("vaddw.z %0, $vf0, $vf0w" : "+j"(r)); f.mData = r; }
static inline u_long128 v256_one() { u_long128 o, one; asm("vaddw.x %0, $vf0, $vf0w" : "=j"(o)); asm("qmfc2.i %0, %1" : "=r"(one) : "j"(o)); return one; }
// [L] N185: v278_dot(CGtV3d, CGtV3d) (B3O0PCH map, 116 bytes) stand-in: the 1.0 parked in a GPR (N191 round trip)
static inline XAxisType v256_dot(CGtV3d a, CGtV3d b)
{
    u_long128 one, r;
    asm("qmtc2 %0, $vf1" "\n\t" "qmtc2 %1, $vf2" "\n\t" "vmul.xyz $vf3, $vf1, $vf2" : : "r"(a.mData), "r"(b.mData));
    asm("vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %0, $vf1" : "=r"(one));
    asm("vadday.x $ACC, $vf3, $vf3y" "\n\t" "qmtc2.i %1, $vf1" "\n\t" "vmaddz.x $vf1, $vf1, $vf3z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(r) : "r"(one));
    return XAxisType(r);
}
// [L] N185: CGtV3d::Normalise() stand-in, vector on a compiler-chosen register, 1.0 parked in a GPR
static inline void v256_normalise(CGtV3d &v)
{
    u_long128 one = v256_one();
    u_long128 x = v.mData;
    u_long128 m, d, w, t;
    asm("vmul.xyz %0, %1, %1" "\n\t" "vadday.x $ACC, %0, %0y" : "=j"(m) : "j"(x));
    asm("qmtc2.i %2, %1" "\n\t" "vmaddz.x %1, %1, %3z" "\n\t" "qmfc2.i %0, %1" : "=r"(d), "=&j"(w) : "r"(one), "j"(m));
    asm(".set noreorder");
    asm("qmtc2.i %1, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %2, %2, $Q" "\n\t" "qmfc2.i %0, %2" : "=r"(t) : "r"(d), "j"(x));
    asm(".set reorder");
    v.mData = t;
}
// [L] N185: CGtV3d * XAxisType stand-in (scalar through a GPR onto a compiler-chosen register)
static inline CGtV3d v256_mulx(const CGtV3d &v, XAxisType s)
{
    u_long128 t;
    asm("qmtc2.i %1, $vf1" "\n\t" "qmtc2 %2, $vf2" "\n\t" "vmulx.xyz $vf1, $vf2, $vf1x" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(s.lVector), "r"(v.mData));
    return CGtV3d(t);
}
static inline CGtV3d v256_sub(const CGtV3d &a, const CGtV3d &b) { u_long128 t; asm("vsub.xyz %0, %2, %1" : "=j"(t) : "j"(b.mData), "j"(a.mData)); return CGtV3d(t); }
// [L] N185: CGtV3d::operator+ stand-in with this read through its address (retail: lqc2 $vf2, 0(a3))
static inline CGtV3d v256_add(const CGtV3d &a, CGtV3d b) { u_long128 t; asm("lqc2 $vf2, 0(%1)" "\n\t" "qmtc2 %2, $vf1" "\n\t" "vadd.xyz $vf1, $vf2, $vf1" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(&a), "r"(b.mData)); return CGtV3d(t); }
// [L] N185: v278_dot(CGtV3d, CGtV3d) (B3O0PCH map, 116 bytes) stand-in: hdr8's v3 body (vmul + vadday in one statement)
static inline XAxisType v278_dot(CGtV3d a, CGtV3d b)
{
    u_long128 m, one, d, t;
    asm("vmul.xyz %0, %1, %2" : "=j"(m) : "j"(a.mData), "j"(b.mData));
    asm("vaddw.x %0, $vf0, $vf0w" : "=j"(one));
    asm("vadday.x $ACC, %0, %0y" : : "j"(m));
    asm(".set noreorder");
    asm("vmaddz.x %0, %1, %2z" : "=j"(t) : "j"(one), "j"(m));
    asm(".set reorder");
    asm("qmfc2 %0, %1" : "=r"(d) : "j"(t));
    return XAxisType(d);
}
// 0x003E7640
extern "C" CGtMatrix3x4 func_003E7640(UnkStruct_003E7640_self * self, int idx)
{
    CGtMatrix3x4 m;
    CGtMatrix3x4 m3;
    switch (idx) {
    case 2: {
        UnkStruct_003E7640_1 * d = self->field_18;
        const CGtV3d *pb = &d->field_70[4].mPos;
        CGtV3d dir = v256_sub(d->field_70[1].mPos, d->field_70[4].mPos);
        v256_normalise(dir);
        CGtV3d p = v256_add(*pb, v256_mulx(dir, v278_dot(v256_sub(d->field_70[3].mPos, d->field_70[4].mPos), dir)));
        m.SetIdentity();
        m.mPos = p;
        return m;
    }
    case 3: {
        UnkStruct_003E7640_1 * d = self->field_18;
#define m m3
        const CGtV3d *pb = &d->field_70[5].mPos;
        CGtV3d dir = v256_sub(d->field_70[2].mPos, d->field_70[5].mPos);
        v256_normalise(dir);
        CGtV3d p = v256_add(*pb, v256_mulx(dir, v278_dot(v256_sub(d->field_70[3].mPos, d->field_70[5].mPos), dir)));
        m.SetIdentity();
        m.mPos = p;
        return m;
#undef m
    }
    default:
        return self->field_18->field_70[kaeVirtualToNormalBone[idx]];
    }
}
