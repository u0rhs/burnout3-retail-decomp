// NONMATCHING: func_00355BD0 -- retail 325 / ours 327 instructions, 31 in changed runs
// ghvu18: DNAT CB3CrashCameraDirector::FindInterpRig; logic complete, cloned from proven sibling func_00356FB0 (rig record copy via a const& local = retail's held source base, orthonormal invert, lane-check inline, ysub, PrepareRotate 10th arg); 327 vs 325 instrs, 31 in changed runs. Left: frame-slot placement (Position copy/p/IPIV2/IPIV1/W temps; retail top-down: Position 0x370, p 0x350, IPIV2 0x340, IPIV1 0x200, pos 0x1F0, GPA 0x1D0, W 0x190, ysub 0x100 -- 37 dead slots, pads copied from the sibling), PrepareRotate argument scheduling (retail stores the Radius() W copy + reads f14 first), the first IsPointInsideVehicle copy lq via addiu (retail lq 0x430(sp)), ysub lane read addiu v1/sp+4 form. Signature clash: func_00355A90/func_00354FD0 are declared void in their own sources but return int/float here.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00355BD0 -- hand-written (ghvu18): Ghidra draft + retail asm + the proven sibling func_00356FB0 (same rig record,
// orthonormal-invert and lane-check inlines, PrepareRotate's 10th argument).
// [L] DNAT: CB3CrashCameraDirector::FindInterpRig(CB3BehaviourCluster*) (research/proto/new_names.csv, exact/verified).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

// [L] the rig record (CB3ClusterRig: its operator= is out of line in the B3O0PCH map, 0x14C): two 4-quad blocks copied by
// loops, then the fields; the gap at +0x88 is not copied (alignment before the quad at +0x90). Field types [G].
struct UnkStruct_00355BD0_rig {
    u_long128 field_0[4];
    u_long128 field_40[4];
    int field_80;
    void * field_84;
    CGtSphere field_90;
    u_long128 field_A0;
    float field_B0;
    float field_B4;
    float field_B8;
    float field_BC;
    float field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    unsigned char field_D0;
};
struct UnkStruct_00355BD0_e { unsigned char pad_0[3]; unsigned char field_3; unsigned char field_4; unsigned char field_5; unsigned char pad_6[4]; };
struct UnkStruct_00355BD0_ls { unsigned char pad_0[8]; UnkStruct_00355BD0_e * field_8; };
struct UnkStruct_00355BD0_lane { unsigned char pad_0[4]; UnkStruct_00355BD0_ls * field_4; };
struct UnkStruct_00355BD0_ai { unsigned char pad_0[0x18B4]; void * field_18B4; unsigned short field_18B8; unsigned char pad_18BA[0xF2]; signed char field_19AC; };
struct UnkStruct_00355BD0_c40 { unsigned char pad_0[0x13F4]; UnkStruct_00355BD0_ai * field_13F4; };
struct UnkStruct_00355BD0_car { unsigned char pad_0[0x40]; UnkStruct_00355BD0_c40 * field_40; };
struct UnkStruct_00355BD0_b40 { unsigned char pad_0[0x204]; CGtMatrix3x4 * field_204; };
struct UnkStruct_00355BD0_child { unsigned char pad_0[0x40]; UnkStruct_00355BD0_b40 * field_40; };
struct UnkStruct_00355BD0_f30 { unsigned char pad_0[0x74]; float field_74; };
struct UnkStruct_00355BD0_f14 { unsigned char pad_0[0x20]; CGtV3d field_20; UnkStruct_00355BD0_f30 * field_30; };
struct UnkStruct_00355BD0 {
    unsigned char pad_0[0x8];
    void * field_8;
    unsigned char * field_C;
    void * field_10;
    UnkStruct_00355BD0_f14 * field_14;
    float field_18;
    float field_1C;
    unsigned char pad_20[0x8];
    int field_28;
    int field_2C;
    unsigned char field_30;
};
struct UnkStruct_00355BD0_bc {
    unsigned char pad_0[0x10];
    UnkStruct_00355BD0_rig field_10;
    unsigned char pad_F0[0xF0];
    unsigned char field_1E0;
};
struct UnkStruct_00355BD0_pad { int x[4]; UnkStruct_00355BD0_pad() {} ~UnkStruct_00355BD0_pad() {} };  // [G] N140 frame pad

extern "C" float func_00354FD0(UnkStruct_00355BD0 *, UnkStruct_00355BD0_rig *, int, int);
extern "C" int func_00355A90(UnkStruct_00355BD0 *, UnkStruct_00355BD0_rig *, float *, void *, int, int);
extern "C" UnkStruct_00355BD0_car * func_00353960(void *);
extern "C" bool CollisionIsCameraInVehicle__14CB3CameraUtilsFQ29GtMathPs26CGtV3di(CGtV3d, int);
extern "C" UnkStruct_00355BD0_lane * WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(void *, unsigned short *, const CGtV3d &);
extern "C" CGtV3d GetPositionAtParam__14CB3CameraUtilsFP15CB3AILaneStructUsf18EAISegmentLinkType(UnkStruct_00355BD0_ls *, unsigned short, float, int);
extern "C" void PrepareRotate__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyffQ29GtMathPs26CGtV3dfffRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs212CGtMatrix3x4fib(
    UnkStruct_00355BD0_rig *, int, int, void *, float, float, CGtV3d, float, float, float, const CGtMatrix3x4 &, const CGtMatrix3x4 &, float, int, bool, bool);
extern "C" void SetRig__19CB3BehaviourClusterFP13CB3ClusterRig(void *, UnkStruct_00355BD0_rig *);
extern "C" void SetInterpRig__19CB3BehaviourClusterFP13CB3ClusterRig(void *, UnkStruct_00355BD0_rig *);
extern "C" void SetParameters__23CB3BehaviourInterpolateF24EB3PlayerCameraBehaviour24EB3PlayerCameraBehaviourf20EB3InterpolationType24EB3InterpolationTimeMode(void *, int, int, float, int, int);

// [L] N185 stand-ins (as func_00356FB0 / func_00333740): orthonormal invert of a 3x4 matrix in place.
static inline void func_00355BD0_inl1(CGtV3d &d, const CGtV3d &s) { asm("vadd.xyz %0, %0, %1" : "+j"(d.mData) : "j"(s.mData)); }
static inline CGtV3d func_00355BD0_inl3(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_00355BD0_inl4(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmuly.xyz %0, %1, %2y" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_00355BD0_inl5(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulz.xyz %0, %1, %2z" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline void func_00355BD0_r0(CGtV3d &d, const CGtV3d &b, const CGtV3d &c) { asm("vaddx.y %0, $vf0, %1x" "\n\t" "vaddx.z %0, $vf0, %2x" : "+j"(d.mData) : "j"(b.mData), "j"(c.mData)); }
static inline void func_00355BD0_r1(CGtV3d &d, const CGtV3d &a, const CGtV3d &c) { asm("vaddy.x %0, $vf0, %1y" "\n\t" "vaddy.z %0, $vf0, %2y" : "+j"(d.mData) : "j"(a.mData), "j"(c.mData)); }
static inline void func_00355BD0_r2(CGtV3d &d, const CGtV3d &a, const CGtV3d &b) { asm("vaddz.x %0, $vf0, %1z" "\n\t" "vaddz.y %0, $vf0, %2z" : "+j"(d.mData) : "j"(a.mData), "j"(b.mData)); }
static inline void func_00355BD0_inl0(CGtMatrix3x4 &r)
{
    CGtV3d a = r.mRight, b = r.mUp, c = r.mAt;
    func_00355BD0_r0(r.mRight, b, c);
    func_00355BD0_r1(r.mUp, a, c);
    func_00355BD0_r2(r.mAt, a, b);
    CGtV3d p = r.mPos;
    CGtV3d z = func_00355BD0_inl5(r.mAt, p);
    CGtV3d x = func_00355BD0_inl3(r.mRight, p);
    CGtV3d t = x + func_00355BD0_inl4(r.mUp, p);
    func_00355BD0_inl1(t, z);
    r.mPos = -t;
}
// [L] N185 stand-in for operator-(YAxisType, YAxisType) with a "=j" result (as func_00356FB0)
static inline YAxisType func_00355BD0_ysub(YAxisType b, YAxisType a) { UnkStruct_00355BD0_pad q0, q1, q2, q3, q4; u_long128 r; asm("vsuby.y %0, %1, %2y" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return YAxisType(r); }
// [G] placeholder inline (as func_00356FB0_inl6): the rig child's lane segment linked both ways and not more than 3 below
static inline bool func_00355BD0_inl6(UnkStruct_00355BD0 * self, UnkStruct_00355BD0_child * child, unsigned short & seg)
{
    UnkStruct_00355BD0_pad pa0, pa1, pa2, pa3, pa4, pa5, pa6, pa7, pa8;
    CGtV3d pos = child->field_40->field_204->mPos;
    UnkStruct_00355BD0_ai * ai = func_00353960(self->field_8)->field_40->field_13F4;
    seg = ai->field_18B8;
    UnkStruct_00355BD0_ls * ls = WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(ai->field_18B4, &seg, pos)->field_4;
    UnkStruct_00355BD0_e * e = &ls->field_8[seg];
    bool ok = e->field_4 != 0xFF && e->field_5 != 0xFF;
    if (ok) {
        UnkStruct_00355BD0_pad pb0;
        CGtV3d p = GetPositionAtParam__14CB3CameraUtilsFP15CB3AILaneStructUsf18EAISegmentLinkType(ls, seg, 0.0f, 1);
        UnkStruct_00355BD0_pad pc0, pc1, pc2, pc3, pc4, pc5, pc6, pc7;
        if (func_00355BD0_ysub(p.Y(), pos.Y()) < -3.0f)
            ok = false;
    }
    return ok;
}
// [L] CB3CrashCameraDirector::IsPointInsideVehicle(CGtV3d) (B3O0PCH map, 0x74): inlined
static inline bool func_00355BD0_inl7(UnkStruct_00355BD0 * self, CGtV3d p)
{
    return CollisionIsCameraInVehicle__14CB3CameraUtilsFQ29GtMathPs26CGtV3di(p, func_00353960(self->field_8)->field_40->field_13F4->field_19AC);
}

// 0x00355BD0
extern "C" int func_00355BD0(UnkStruct_00355BD0 * self, UnkStruct_00355BD0_bc * cl)
{
    float d0 = func_00354FD0(self, &cl->field_10, 0, 0);
    const UnkStruct_00355BD0_rig &o = cl->field_10;
    UnkStruct_00355BD0_rig rig = o;
    unsigned short seg2;
    unsigned short seg;
    float f;
    int r = func_00355A90(self, &rig, &f, cl->field_10.field_84, 1, 0);
    if (r == 0)
        return 0;
    CGtMatrix3x4 inv = *(CGtMatrix3x4 *)rig.field_0;
    func_00355BD0_inl0(inv);
    float k;
    if (self->field_30 != 0 || func_00355BD0_inl7(self, CGtV3d(rig.field_40[3]))) {
        k = 4.5f;
        self->field_30 = 1;
    } else {
        k = 1.5f;
    }
    bool ok = func_00355BD0_inl6(self, (UnkStruct_00355BD0_child *)rig.field_84, seg);
    PrepareRotate__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyffQ29GtMathPs26CGtV3dfffRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs212CGtMatrix3x4fib(
        &rig, 0, 3, rig.field_84, rig.field_B0, k, rig.field_90.Position(), rig.field_90.Radius(), rig.field_B8, rig.field_BC,
        *(CGtMatrix3x4 *)rig.field_0, inv, self->field_14->field_30->field_74, self->field_28, ok, false);
    f = func_00354FD0(self, &rig, 1, 0);
    bool b = true;
    if (cl->field_1E0 == 0) {
        bool c = false;
        if (self->field_2C == 6) {
            CGtV3d p = self->field_14->field_20;
            bool t = true;
            UnkStruct_00355BD0_ai * ai = func_00353960(self->field_8)->field_40->field_13F4;
            seg2 = ai->field_18B8;
            UnkStruct_00355BD0_ls * ls = WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(ai->field_18B4, &seg2, p)->field_4;
            UnkStruct_00355BD0_e * e = &ls->field_8[seg2];
            bool is5 = !((e->field_3 & 7) != 5);
            if (!is5) {
                bool in = CollisionIsCameraInVehicle__14CB3CameraUtilsFQ29GtMathPs26CGtV3di(CGtV3d(cl->field_10.field_40[3]), func_00353960(self->field_8)->field_40->field_13F4->field_19AC);
                if (!in)
                    t = false;
            }
            if (t)
                c = true;
        }
        if (!c)
            b = false;
    }
    if (f > 1.25f * d0 || b) {
        if (r == 1 && cl->field_10.field_CC == 0) {
            SetInterpRig__19CB3BehaviourClusterFP13CB3ClusterRig(cl, &rig);
            self->field_1C = 0.0f;
        } else {
            self->field_1C = 1.5f;
            SetRig__19CB3BehaviourClusterFP13CB3ClusterRig(self->field_C + 0x6D0, &cl->field_10);
            SetRig__19CB3BehaviourClusterFP13CB3ClusterRig(cl, &rig);
            SetParameters__23CB3BehaviourInterpolateF24EB3PlayerCameraBehaviour24EB3PlayerCameraBehaviourf20EB3InterpolationType24EB3InterpolationTimeMode(self->field_C + 0x8C0, 7, 6, 0.75f, 1, 1);
        }
        return 1;
    }
    return 0;
}
