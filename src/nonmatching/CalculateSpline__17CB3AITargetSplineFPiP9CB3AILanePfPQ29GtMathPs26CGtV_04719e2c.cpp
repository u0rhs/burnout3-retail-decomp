// NONMATCHING: CalculateSpline__17CB3AITargetSplineFPiP9CB3AILanePfPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3dPQ29GtMathPs26CGtV3d -- retail 270 / ours 270 instructions, 37 in changed runs
// v299 first pass: logic complete, 270/270, 37 in changed runs. Left: frame 0x390 vs 0x100 (retail keeps ~40 dead 16-byte slots: by-value/temp CGtV4d of the inlined spline-matrix transforms, not modelled); load/mul scheduling inside the kSplinePosMatrix transform; the scalar qmtc2 of the scale stand-in. Same lane-position inline as FillInTargetPosition (see that archive for the 1-2 off shape: read indices straight through lane->field_4->field_0[seg]). Stand-ins [L] N185: per-lane vmul/vadd 4x4 transform, SetA/SetZ/lane-product chain for (t^3,t^2,t,1).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

struct UnkStruct_00149180_p { unsigned short field_0[2]; };
struct CB3AILaneStruct { UnkStruct_00149180_p *field_0; unsigned char pad_4[8]; unsigned short field_C; unsigned char field_E; };
class CB3AILane { public: unsigned char pad_0[4]; CB3AILaneStruct *field_4; };
struct UnkStruct_D_0064D354 { CGtV3d *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064D354 D_0064D354;
struct UnkStruct_00149180_m { CGtV4d field_0[4]; };
extern const UnkStruct_00149180_m kSplinePosMatrix;
extern const UnkStruct_00149180_m kSplineDirMatrix;
struct UnkStruct_00149180_c { unsigned char pad_0[0x1BD0]; float field_1BD0; };
extern "C" {
float GetWidth__9CB3AILaneCFUs(CB3AILane *, unsigned short);
void ClampToWithinDesiredLanes__17CB3AITargetSplineCFQ29GtMathPs26CGtV3dPC9CB3AILaneUsPQ29GtMathPs26CGtV3d(const void *, const void *, const CB3AILane *, unsigned short, CGtV3d *);
}
class CB3AITargetSpline {
public:
    void CalculateSpline(int *, CB3AILane *, float *, CGtV3d *, CGtV3d *, CGtV3d *, CGtV3d *);
    CGtV3d field_0[6];
    CGtV3d field_60[6];
    unsigned char pad_C0[0x90];
    unsigned char field_150;
    unsigned char pad_151[3];
    UnkStruct_00149180_c *field_154;
};
// [L] N185: stands in for an in-place Normalise on a compiler-chosen register (retail `vmulq.xyz $vf4,$vf4,$Q`)
static inline void func_00149180_inl2(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    u_long128 o;
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "vmulq.xyz %1, %1, $Q" "\n\t" "qmfc2 %0, %1" : "=r"(o), "+j"(v.mData));
    asm(".set reorder");
    v.mData = o;
}
// [L] N185: stands in for the hard-coded CGtV3d::operator*(float) body (v288)
static inline CGtV3d func_00149180_inl3(CGtV3d v, float s)
{
    u_long128 t;
    asm("qmtc2.ni %0, $vf2" : : "r"(s));
    asm("qmtc2 %1, $vf1" "\n\t" "vmulx.xyz $vf1, $vf1, $vf2x" "\n\t" "qmfc2 %0, $vf1" : "=r"(t) : "r"(v.mData));
    return CGtV3d(t);
}
// [L] N185: compiler-chosen vsub (retail `vsub.xyz $vf4, $vf1, $vf3`)
static inline CGtV3d func_00149180_inl4(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vsub.xyz %0, %1, %2" : "=j"(t) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(t);
}
// [L] N185: lane setters / lane products on compiler-chosen registers
static inline void func_00149180_inl8(CGtV4d &v, float a)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(a));
    asm("vmulx.w %0, $vf0, %1x" : "+j"(v.mData) : "j"(s));
}
static inline void func_00149180_inl5(CGtV4d &v, float z)
{
    u_long128 sz, t;
    asm("qmtc2.ni %1, %0" : "=j"(sz) : "r"(z));
    asm("vaddx.z %0, $vf0, %1x" : "+j"(v.mData) : "j"(sz));
    asm("vmulz.z %0, %1, %1z" : "=j"(t) : "j"(v.mData));
    asm("vaddz.y %0, $vf0, %1z" : "+j"(v.mData) : "j"(t));
    asm("vmulz.y %0, %1, %1z" : "=j"(t) : "j"(v.mData));
    asm("vaddy.x %0, $vf0, %1y" : "+j"(v.mData) : "j"(t));
}
// [L] N185: 4-row transform x*r0 + y*r1 + z*r2 + w*r3 (vmul per lane, vadd chain)
static inline CGtV4d func_00149180_inl6(const CGtV4d *m, const CGtV4d &v)
{
    u_long128 a, b, c, d, r1, r2, r;
    asm("vmulw.xyzw %0, %1, %2w" : "=j"(d) : "j"(m[3].mData), "j"(v.mData));
    asm("vmulx.xyzw %0, %1, %2x" : "=j"(a) : "j"(m[0].mData), "j"(v.mData));
    asm("vmulz.xyzw %0, %1, %2z" : "=j"(c) : "j"(m[2].mData), "j"(v.mData));
    asm("vmuly.xyzw %0, %1, %2y" : "=j"(b) : "j"(m[1].mData), "j"(v.mData));
    asm("vadd.xyzw %0, %1, %2" : "=j"(r1) : "j"(a), "j"(b));
    asm("vadd.xyzw %0, %1, %2" : "=j"(r2) : "j"(r1), "j"(c));
    asm("vadd.xyzw %0, %1, %2" : "=j"(r) : "j"(r2), "j"(d));
    return CGtV4d(r);
}
static inline CGtV3d func_00149180_inl7(const CGtV3d *m, const CGtV4d &v)
{
    u_long128 a, b, c, d, r1, r2, r;
    asm("vmulw.xyz %0, %1, %2w" : "=j"(d) : "j"(m[3].mData), "j"(v.mData));
    asm("vmulx.xyz %0, %1, %2x" : "=j"(a) : "j"(m[0].mData), "j"(v.mData));
    asm("vmuly.xyz %0, %1, %2y" : "=j"(b) : "j"(m[1].mData), "j"(v.mData));
    asm("vadd.xyz %0, %1, %2" : "=j"(r1) : "j"(a), "j"(b));
    asm("vmulz.xyz %0, %1, %2z" : "=j"(c) : "j"(m[2].mData), "j"(v.mData));
    asm("vadd.xyz %0, %1, %2" : "=j"(r2) : "j"(r1), "j"(c));
    asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(r2), "j"(d));
    return CGtV3d(r);
}
// 0x00149180
void CB3AITargetSpline::CalculateSpline(int *segs, CB3AILane *lane, float *fracs, CGtV3d *d0, CGtV3d *d1, CGtV3d *d2, CGtV3d *pos)
{
    int i;
    CGtV3d *buf;
    if (field_150) buf = field_60; else buf = field_0;
    for (i = 0; i < 6; i++) {
        float f = fracs[i];
        unsigned short seg = segs[i];
        float s = f * GetWidth__9CB3AILaneCFUs(lane, seg);
        unsigned short l = lane->field_4->field_0[seg].field_0[0];
        unsigned short r = lane->field_4->field_0[seg].field_0[1];
        if (l != r) {
            CGtV3d a = D_0064D354.field_0[l];
            CGtV3d b = D_0064D354.field_0[r];
            CGtV3d d;
            d = func_00149180_inl4(b, a);
            func_00149180_inl2(d);
            CGtV3d p = func_00149180_inl3(d, s);
            p += a;
            buf[i] = p;
        } else {
            buf[i] = D_0064D354.field_0[l];
        }
        ClampToWithinDesiredLanes__17CB3AITargetSplineCFQ29GtMathPs26CGtV3dPC9CB3AILaneUsPQ29GtMathPs26CGtV3d(this, &buf[i], lane, seg, &buf[i]);
    }
    CGtV4d tv;
    func_00149180_inl8(tv, 1.0f);
    func_00149180_inl5(tv, GtMath::Min(GtMath::Max(field_154->field_1BD0, 0.0f), 1.0f));
    if (pos) {
        CGtV4d pm = func_00149180_inl6(kSplinePosMatrix.field_0, tv);
        *pos = func_00149180_inl7(&buf[1], pm);
    }
    CGtV4d dm = func_00149180_inl6(kSplineDirMatrix.field_0, tv);
    if (d0) *d0 = func_00149180_inl7(&buf[0], dm);
    if (d1) *d1 = func_00149180_inl7(&buf[1], dm);
    if (d2) *d2 = func_00149180_inl7(&buf[2], dm);
    if (lane->field_4->field_E == 0) {
        int n = lane->field_4->field_C;
        if (segs[1] == n - 3) {
            if (d2) {
                if (d1) *d2 = *d1;
                else if (d0) *d2 = *d0;
            }
        } else if (segs[1] == n - 2) {
            if (d2 && d0) *d2 = *d0;
            if (d1 && d0) *d1 = *d0;
        } else if (segs[1] == n - 1) {
            if (d2 && d0) *d2 = *d0;
            if (d1 && d0) *d1 = *d0;
        }
    }
}
