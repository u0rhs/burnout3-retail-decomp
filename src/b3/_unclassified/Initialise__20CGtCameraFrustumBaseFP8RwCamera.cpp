// Hand-written; the lifter refused it (ghvu6: six RW frustum planes as CGtPlane SetNormal/SetDistance stand-ins; planes 2-5 lane-copied into four rows; N129 address-read by-value params reproduce 38 dead slots, one 0x60 N140 pad the last six).

// CGtCameraFrustumBase::Initialise(RwCamera*) -- hand-written (ghvu6): Ghidra draft + the proven sibling
// CGtCameraFrustum::Initialise (ghvu4). [L] the six 0x14-byte records at RwCamera+0x94 = RwCamera::frustumPlanes (RW 3.5
// SDK rwcore.h: RwPlane normal + distance, then closestX/Y/Z); planes 0/1 stored as CGtPlanes, planes 2-5 transposed
// into the four rows at +0x20 [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00334750_pl { float field_0[3]; float field_C; unsigned char field_10[4]; };
struct RwCamera { unsigned char pad_0[0x94]; UnkStruct_00334750_pl field_94[6]; };
class CGtCameraFrustumBase {
public:
    void Initialise(RwCamera *);
    CGtPlane field_0;
    CGtPlane field_10;
    CGtV4d field_20[4];
};
// [L] N185: CGtPlane::SetDistance(float) with the scalar on a compiler-chosen register (as the header's SetRadius)
static inline void func_00334750_inl0(CGtPlane &p, const float &f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.w %0, $vf0, %1x" : "+j"(p.mData) : "j"(s)); }
// [L] N185: one lane of the plane into one lane of a row (no header API of this shape; retail vaddY.X / vmulY.w)
static inline void func_00334750_inl1(CGtV4d &r, XAxisType p) { asm("vaddx.x %0, $vf0, %1x" : "+j"(r.mData) : "j"(*(const u_long128 *)&p.lVector)); }
static inline void func_00334750_inl2(CGtV4d &r, XAxisType p) { asm("vaddy.x %0, $vf0, %1y" : "+j"(r.mData) : "j"(*(const u_long128 *)&p.lVector)); }
static inline void func_00334750_inl3(CGtV4d &r, XAxisType p) { asm("vaddz.x %0, $vf0, %1z" : "+j"(r.mData) : "j"(*(const u_long128 *)&p.lVector)); }
static inline void func_00334750_inl4(CGtV4d &r, XAxisType p) { asm("vaddw.x %0, $vf0, %1w" : "+j"(r.mData) : "j"(*(const u_long128 *)&p.lVector)); }
static inline void func_00334750_inl5(CGtV4d &r, XAxisType p) { asm("vaddx.y %0, $vf0, %1x" : "+j"(r.mData) : "j"(*(const u_long128 *)&p.lVector)); }
static inline void func_00334750_inl6(CGtV4d &r, XAxisType p) { asm("vaddy.y %0, $vf0, %1y" : "+j"(r.mData) : "j"(*(const u_long128 *)&p.lVector)); }
static inline void func_00334750_inl7(CGtV4d &r, XAxisType p) { asm("vaddz.y %0, $vf0, %1z" : "+j"(r.mData) : "j"(*(const u_long128 *)&p.lVector)); }
static inline void func_00334750_inl8(CGtV4d &r, XAxisType p) { asm("vaddw.y %0, $vf0, %1w" : "+j"(r.mData) : "j"(*(const u_long128 *)&p.lVector)); }
static inline void func_00334750_inl9(CGtV4d &r, XAxisType p) { asm("vaddx.z %0, $vf0, %1x" : "+j"(r.mData) : "j"(*(const u_long128 *)&p.lVector)); }
static inline void func_00334750_inl10(CGtV4d &r, XAxisType p) { asm("vaddy.z %0, $vf0, %1y" : "+j"(r.mData) : "j"(*(const u_long128 *)&p.lVector)); }
static inline void func_00334750_inl11(CGtV4d &r, XAxisType p) { asm("vaddz.z %0, $vf0, %1z" : "+j"(r.mData) : "j"(*(const u_long128 *)&p.lVector)); }
static inline void func_00334750_inl12(CGtV4d &r, XAxisType p) { asm("vaddw.z %0, $vf0, %1w" : "+j"(r.mData) : "j"(*(const u_long128 *)&p.lVector)); }
static inline void func_00334750_inl13(CGtV4d &r, XAxisType p) { asm("vmulx.w %0, $vf0, %1x" : "+j"(r.mData) : "j"(*(const u_long128 *)&p.lVector)); }
static inline void func_00334750_inl14(CGtV4d &r, XAxisType p) { asm("vmuly.w %0, $vf0, %1y" : "+j"(r.mData) : "j"(*(const u_long128 *)&p.lVector)); }
static inline void func_00334750_inl15(CGtV4d &r, XAxisType p) { asm("vmulz.w %0, $vf0, %1z" : "+j"(r.mData) : "j"(*(const u_long128 *)&p.lVector)); }
static inline void func_00334750_inl16(CGtV4d &r, XAxisType p) { asm("vmulw.w %0, $vf0, %1w" : "+j"(r.mData) : "j"(*(const u_long128 *)&p.lVector)); }

// [L] N185/N129: CGtPlane::SetNormal(CGtV3d) with its by-value argument read through its address (the dead slot stays)
static inline void func_00334750_inl17(CGtPlane &p, CGtV3d v) { asm("vadd.xyz %0, $vf0, %1" : "+j"(p.mData) : "j"(*(const u_long128 *)&v.mData)); }
static inline XAxisType func_00334750_inl18(CGtPlane p) { return XAxisType(*(const u_long128 *)&p.mData); }
// N140: one unused 0x60-byte frame pad standing in for six dead 16-byte slots (one per plane; retail frame 0x330 --
// probably by-value SetDistance arguments, not reproduced) [G]
struct UnkStruct_00334750_pad { int x[24]; UnkStruct_00334750_pad() {} ~UnkStruct_00334750_pad() {} };
// 0x00334750
void CGtCameraFrustumBase::Initialise(RwCamera *cam)
{
    CGtPlane p;
    UnkStruct_00334750_pad pad;
    func_00334750_inl17(p, CGtV3d(cam->field_94[0].field_0[0], cam->field_94[0].field_0[1], cam->field_94[0].field_0[2]));
    func_00334750_inl0(p, cam->field_94[0].field_C);
    field_0 = p;
    func_00334750_inl17(p, CGtV3d(cam->field_94[1].field_0[0], cam->field_94[1].field_0[1], cam->field_94[1].field_0[2]));
    func_00334750_inl0(p, cam->field_94[1].field_C);
    field_10 = p;
    func_00334750_inl17(p, CGtV3d(cam->field_94[2].field_0[0], cam->field_94[2].field_0[1], cam->field_94[2].field_0[2]));
    func_00334750_inl0(p, cam->field_94[2].field_C);
    func_00334750_inl1(field_20[0], func_00334750_inl18(p));
    func_00334750_inl2(field_20[1], func_00334750_inl18(p));
    func_00334750_inl3(field_20[2], func_00334750_inl18(p));
    func_00334750_inl4(field_20[3], func_00334750_inl18(p));
    func_00334750_inl17(p, CGtV3d(cam->field_94[3].field_0[0], cam->field_94[3].field_0[1], cam->field_94[3].field_0[2]));
    func_00334750_inl0(p, cam->field_94[3].field_C);
    func_00334750_inl5(field_20[0], func_00334750_inl18(p));
    func_00334750_inl6(field_20[1], func_00334750_inl18(p));
    func_00334750_inl7(field_20[2], func_00334750_inl18(p));
    func_00334750_inl8(field_20[3], func_00334750_inl18(p));
    func_00334750_inl17(p, CGtV3d(cam->field_94[4].field_0[0], cam->field_94[4].field_0[1], cam->field_94[4].field_0[2]));
    func_00334750_inl0(p, cam->field_94[4].field_C);
    func_00334750_inl9(field_20[0], func_00334750_inl18(p));
    func_00334750_inl10(field_20[1], func_00334750_inl18(p));
    func_00334750_inl11(field_20[2], func_00334750_inl18(p));
    func_00334750_inl12(field_20[3], func_00334750_inl18(p));
    func_00334750_inl17(p, CGtV3d(cam->field_94[5].field_0[0], cam->field_94[5].field_0[1], cam->field_94[5].field_0[2]));
    func_00334750_inl0(p, cam->field_94[5].field_C);
    func_00334750_inl13(field_20[0], func_00334750_inl18(p));
    func_00334750_inl14(field_20[1], func_00334750_inl18(p));
    func_00334750_inl15(field_20[2], func_00334750_inl18(p));
    func_00334750_inl16(field_20[3], func_00334750_inl18(p));
}
