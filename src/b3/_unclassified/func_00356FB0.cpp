// Hand-written; the lifter refused it (v273: inline orthonormal invert, lane-check inline, =j Y subtract stand-in, N140 pads, 10th PrepareRotate arg).

// Hand-written (v273); the lifter refused it (inlined orthonormal invert as func_00333740, lane check in a static inline
// helper, "=j" Y-lane subtract stand-in, N140 pads, 10th PrepareRotate argument).
// func_00356FB0 -- a CB3CrashCameraDirector update (callees UpdateCrashMode__22CB3CrashCameraDirectorFf, PrepareRotate,
// SetRig; it follows UpdateCrashMode in unit 0x356700) [L]. Types/fields placeholders [G].
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00356FB0_rig {
    CGtMatrix3x4 field_0;
    CGtMatrix3x4 field_40;
    unsigned char pad_80[0x4];
    void * field_84;
    unsigned char pad_88[0x8];
    CGtV3d field_90;
    unsigned char pad_A0[0x10];
    float field_B0;
    unsigned char pad_B4[0x2C];
};
struct UnkStruct_00356FB0_e { unsigned char pad_0[4]; unsigned char field_4; unsigned char field_5; unsigned char pad_6[4]; };
struct UnkStruct_00356FB0_ls { unsigned char pad_0[8]; UnkStruct_00356FB0_e * field_8; };
struct UnkStruct_00356FB0_lane { unsigned char pad_0[4]; UnkStruct_00356FB0_ls * field_4; };
struct UnkStruct_00356FB0_ai { unsigned char pad_0[0x18B4]; void * field_18B4; unsigned short field_18B8; };
struct UnkStruct_00356FB0_c40 { unsigned char pad_0[0x13F4]; UnkStruct_00356FB0_ai * field_13F4; };
struct UnkStruct_00356FB0_car { unsigned char pad_0[0x40]; UnkStruct_00356FB0_c40 * field_40; };
struct UnkStruct_00356FB0_b40 { unsigned char pad_0[0x204]; CGtMatrix3x4 * field_204; };
struct UnkStruct_00356FB0_child { unsigned char pad_0[0x40]; UnkStruct_00356FB0_b40 * field_40; };
struct UnkStruct_00356FB0_f30 { unsigned char pad_0[0x74]; float field_74; };
struct UnkStruct_00356FB0_f14 { unsigned char pad_0[0x30]; UnkStruct_00356FB0_f30 * field_30; };
struct UnkStruct_00356FB0 {
    unsigned char pad_0[0x8];
    void * field_8;
    void * field_C;
    void * field_10;
    UnkStruct_00356FB0_f14 * field_14;
    float field_18;
    unsigned char pad_1C[0xC];
    int field_28;
    unsigned char pad_2C[0x5];
    unsigned char field_31;
};
struct UnkStruct_00356FB0_pad { int x[4]; UnkStruct_00356FB0_pad() {} ~UnkStruct_00356FB0_pad() {} };  // [G] N140 frame pad
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004EE040 D_004EE040;
extern const float D_004C71D8[];
extern const float D_004C7208[];

extern "C" int func_00131E40(void *);
extern "C" void func_003560F0(UnkStruct_00356FB0 *, float);
extern "C" void UpdateCrashMode__22CB3CrashCameraDirectorFf(UnkStruct_00356FB0 *, float);
extern "C" void * GetMostInterestingCluster__16CB3CrashAnalyserFv(void *);
extern "C" UnkStruct_00356FB0_child * GetMostInterestingChild__16CB3CrashAnalyserFP19CGtSphereTreeSphere(void *, void *);
extern "C" void GetRigMatrix__14CB3CameraUtilsFPQ29GtMathPs212CGtMatrix3x4P16CB3CollidingBody(CGtMatrix3x4 * m, void * body);
extern "C" int func_00355A90(UnkStruct_00356FB0 *, UnkStruct_00356FB0_rig *, float *, UnkStruct_00356FB0_child *, int, int);
extern "C" UnkStruct_00356FB0_car * func_00353960(void *);
extern "C" UnkStruct_00356FB0_lane * WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(void *, unsigned short *, const CGtV3d &);
extern "C" CGtV3d GetPositionAtParam__14CB3CameraUtilsFP15CB3AILaneStructUsf18EAISegmentLinkType(UnkStruct_00356FB0_ls *, unsigned short, float, int);
// [L] retail passes a 10th argument (0 at 8(sp)) that the mangled name doesn't list (also the other callers, e.g. 0x355260)
extern "C" void PrepareRotate__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyffQ29GtMathPs26CGtV3dfffRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs212CGtMatrix3x4fib(
    UnkStruct_00356FB0_rig *, int, int, void *, float, float, CGtV3d, float, float, float, const CGtMatrix3x4 &, const CGtMatrix3x4 &, float, int, bool, bool);
extern "C" void SetRig__19CB3BehaviourClusterFP13CB3ClusterRig(void *, UnkStruct_00356FB0_rig *);
extern "C" void SetActiveBehaviour__22CB3PlayerCameraManagerFi(void *, int);

// [L] N185 stand-ins (as func_00333740): orthonormal invert of a 3x4 matrix in place (per-lane transpose copies, then
// pos = -(r0*p.x + r1*p.y + r2*p.z)); the API name is not in our tables.
static inline void func_00356FB0_inl1(CGtV3d &d, const CGtV3d &s) { asm("vadd.xyz %0, %0, %1" : "+j"(d.mData) : "j"(s.mData)); }
static inline CGtV3d func_00356FB0_inl3(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_00356FB0_inl4(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmuly.xyz %0, %1, %2y" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_00356FB0_inl5(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulz.xyz %0, %1, %2z" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline void func_00356FB0_r0(CGtV3d &d, const CGtV3d &b, const CGtV3d &c) { asm("vaddx.y %0, $vf0, %1x" "\n\t" "vaddx.z %0, $vf0, %2x" : "+j"(d.mData) : "j"(b.mData), "j"(c.mData)); }
static inline void func_00356FB0_r1(CGtV3d &d, const CGtV3d &a, const CGtV3d &c) { asm("vaddy.x %0, $vf0, %1y" "\n\t" "vaddy.z %0, $vf0, %2y" : "+j"(d.mData) : "j"(a.mData), "j"(c.mData)); }
static inline void func_00356FB0_r2(CGtV3d &d, const CGtV3d &a, const CGtV3d &b) { asm("vaddz.x %0, $vf0, %1z" "\n\t" "vaddz.y %0, $vf0, %2z" : "+j"(d.mData) : "j"(a.mData), "j"(b.mData)); }
static inline void func_00356FB0_inl0(CGtMatrix3x4 &r)
{
    CGtV3d a = r.mRight, b = r.mUp, c = r.mAt;
    func_00356FB0_r0(r.mRight, b, c);
    func_00356FB0_r1(r.mUp, a, c);
    func_00356FB0_r2(r.mAt, a, b);
    CGtV3d p = r.mPos;
    CGtV3d z = func_00356FB0_inl5(r.mAt, p);
    CGtV3d x = func_00356FB0_inl3(r.mRight, p);
    CGtV3d t = x + func_00356FB0_inl4(r.mUp, p);
    func_00356FB0_inl1(t, z);
    r.mPos = -t;
}

// [L] N185 stand-in for operator-(YAxisType, YAxisType) with a "=j" result: retail loads the subtrahend first
// (`lqc2 $vf1, p; lqc2 $vf2, pos; vsuby.y $vf1, $vf2, $vf1y`); the header body gives the registers swapped here.
// Called as ysub(subtrahend, minuend). The five pads give retail's dead slots below the lane-read temporary [G] N140.
static inline YAxisType func_00356FB0_ysub(YAxisType b, YAxisType a) { UnkStruct_00356FB0_pad q0, q1, q2, q3, q4; u_long128 r; asm("vsuby.y %0, %1, %2y" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return YAxisType(r); }
// [G] placeholder inline: is the car's lane segment linked both ways (bytes +4/+5 != 0xFF), and the rig child not more
// than 3 below the lane point; its locals sit below the caller's temporaries as retail's do (N186). Pads: N140 [G].
static inline bool func_00356FB0_inl6(UnkStruct_00356FB0 * self, UnkStruct_00356FB0_child * child, unsigned short & seg)
{
    UnkStruct_00356FB0_pad pa0, pa1, pa2, pa3, pa4, pa5, pa6, pa7, pa8, pa9;
    CGtV3d pos = child->field_40->field_204->mPos;
    UnkStruct_00356FB0_ai * ai = func_00353960(self->field_8)->field_40->field_13F4;
    seg = ai->field_18B8;
    UnkStruct_00356FB0_ls * ls = WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(ai->field_18B4, &seg, pos)->field_4;
    UnkStruct_00356FB0_e * e = &ls->field_8[seg];
    bool ok = e->field_4 != 0xFF && e->field_5 != 0xFF;
    if (ok) {
        UnkStruct_00356FB0_pad pb0;
        CGtV3d p = GetPositionAtParam__14CB3CameraUtilsFP15CB3AILaneStructUsf18EAISegmentLinkType(ls, seg, 0.0f, 1);
        UnkStruct_00356FB0_pad pc0, pc1, pc2, pc3, pc4, pc5, pc6, pc7;
        if (func_00356FB0_ysub(p.Y(), pos.Y()) < -3.0f)
            ok = false;
    }
    return ok;
}
// 0x00356FB0
extern "C" void func_00356FB0(UnkStruct_00356FB0 * self, float dt)
{
    if (func_00131E40(&D_004EE040) != 0) {
        if (self->field_31 != 0) {
            if (self->field_18 == 0.0f) {
                void * cluster = GetMostInterestingCluster__16CB3CrashAnalyserFv(self->field_8);
                if (cluster != 0) {
                    UnkStruct_00356FB0_rig rig;
                    CGtMatrix3x4 inv;
                    CGtMatrix3x4 mat;
                    unsigned short seg;
                    float f;
                    UnkStruct_00356FB0_child * child = GetMostInterestingChild__16CB3CrashAnalyserFP19CGtSphereTreeSphere(self->field_8, cluster);
                    GetRigMatrix__14CB3CameraUtilsFPQ29GtMathPs212CGtMatrix3x4P16CB3CollidingBody(&mat, child->field_40);
                    inv = mat;
                    func_00356FB0_inl0(inv);
                    func_00355A90(self, &rig, &f, child, 0, 1);
                    bool ok = func_00356FB0_inl6(self, child, seg);
                    float k = self->field_14->field_30->field_74;
                    PrepareRotate__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyffQ29GtMathPs26CGtV3dfffRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs212CGtMatrix3x4fib(
                        &rig, 2, 4, rig.field_84, rig.field_B0, 5.5f, rig.field_90, D_004C71D8[0], 75.0f, D_004C7208[0], mat, inv,
                        k, self->field_28, ok, false);
                    SetRig__19CB3BehaviourClusterFP13CB3ClusterRig(self->field_10, &rig);
                    SetActiveBehaviour__22CB3PlayerCameraManagerFi(self->field_C, 6);
                }
            }
            self->field_18 += dt;
        } else {
            UpdateCrashMode__22CB3CrashCameraDirectorFf(self, dt);
        }
    } else {
        func_003560F0(self, dt);
    }
}
