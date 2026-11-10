// CB3CrashCameraDirector::UpdateCrashMode(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCameraDirector.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ghvu21: clone of func_00356FB0; named per-block CGtV3d by const&, lane check split in two inlines with N140 pads (64 slots), field_28/field_C read into locals before the line stores).

// UpdateCrashMode__22CB3CrashCameraDirectorFf -- hand-written (ghvu21) from the Ghidra draft and the proven unit
// sibling func_00356FB0 (same orthonormal-invert / lane-check / PrepareRotate blocks) [L]. Types/fields [G].
// Shapes: each block's PrepareRotate vector is a named block local passed by const& [G] (retail keeps its slot under
// the block's matrices, no second copy); the lane check is written twice (inl6/inl7) because retail's dead frame slots
// differ per expansion -- the N140 pads (64 slots, 0x400 bytes in all) stand in for them [G]; the tail reads
// field_28/field_C into locals before the line stores (retail's register order).
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/classes/UnkStruct_D_0051BA88.h"
using namespace GtMathPs2;

struct UnkStruct_00356700_rig {
    CGtMatrix3x4 field_0;
    CGtMatrix3x4 field_40;
    unsigned char pad_80[0x4];
    void * field_84;
    unsigned char pad_88[0x8];
    CGtV3d field_90;
    unsigned char pad_A0[0x10];
    float field_B0;
    unsigned char pad_B4[0x14];
    int field_C8;
    unsigned char pad_CC[0x14];
};
struct UnkStruct_00356700_e { unsigned char pad_0[4]; unsigned char field_4; unsigned char field_5; unsigned char pad_6[4]; };
struct UnkStruct_00356700_ls { unsigned char pad_0[8]; UnkStruct_00356700_e * field_8; };
struct UnkStruct_00356700_lane { unsigned char pad_0[4]; UnkStruct_00356700_ls * field_4; };
struct UnkStruct_00356700_ai { unsigned char pad_0[0x18B4]; void * field_18B4; unsigned short field_18B8; };
struct UnkStruct_00356700_b40 {
    unsigned char pad_0[0x204];
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[0x13F4 - 0x208];
    UnkStruct_00356700_ai * field_13F4;
    unsigned char pad_13F8[0x3534 - 0x13F8];
    float field_3534;
    unsigned char pad_3538[0x4586 - 0x3538];
    unsigned char field_4586;
};
struct UnkStruct_00356700_child { CGtV3d field_0; unsigned char pad_10[0x30]; UnkStruct_00356700_b40 * field_40; unsigned char pad_44[0x10]; float field_54; };
struct UnkStruct_00356700_f30 { unsigned char pad_0[0x74]; float field_74; };
struct UnkStruct_00356700_f14 { unsigned char pad_0[0x30]; UnkStruct_00356700_f30 * field_30; };
struct UnkStruct_00356700_cam {
    unsigned char pad_0[0x220];
    CGtV3d field_220;
    unsigned char pad_230[0x6D0 - 0x230];
    unsigned char field_6D0[0x8C0 - 0x6D0];
    unsigned char field_8C0[0xB80 - 0x8C0];
    unsigned long field_B80;
    unsigned char pad_B88[0x18];
    int field_BA0;
    unsigned char pad_BA4[0x2];
    unsigned char field_BA6;
};
struct UnkStruct_00356700_cl { unsigned char pad_0[0x10]; unsigned char field_10[0x10]; };
struct UnkStruct_00356700 {
    unsigned char pad_0[0x8];
    void * field_8;
    UnkStruct_00356700_cam * field_C;
    UnkStruct_00356700_cl * field_10;
    UnkStruct_00356700_f14 * field_14;
    float field_18;
    float field_1C;
    int field_20;
    unsigned char pad_24[0x4];
    int field_28;
    int field_2C;
};
struct UnkStruct_00356700_line { CGtV3d field_0; CGtV3d field_10; };
struct UnkStruct_00356700_pad { int x[4]; UnkStruct_00356700_pad() {} ~UnkStruct_00356700_pad() {} };  // [G] N140 frame pad
struct UnkStruct_00356700_D { unsigned char pad_0[0x10]; };
struct UnkStruct_00356700_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_00356700_F { unsigned char field_0; unsigned char pad_1[0x100]; };
extern UnkStruct_00356700_D D_004EE040;
extern UnkStruct_00356700_D D_0051AEC0;
extern UnkStruct_00356700_F D_01E65499;
extern UnkStruct_00356700_B D_0051BAD5;
extern UnkStruct_00356700_B D_0051BAD6;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern unsigned char D_00522660[];
extern const float D_004C71D4[];
extern const float D_004C71D8[];
extern const float D_004C71E4[];
extern const float D_004C71F4[];
extern const float D_004C7204[];
extern const float D_004C7208[];

extern "C" int func_00131F60(void *);
extern "C" float GetTimeScale__23CB3BehaviourInterpolateFv(void *);
extern "C" UnkStruct_00356700_child * func_00353960(void *);
extern "C" UnkStruct_00356700_child * GetVehicleBeforeImpact__16CB3CrashAnalyserFv(void *);
extern "C" void * GetMostInterestingCluster__16CB3CrashAnalyserFv(void *);
extern "C" UnkStruct_00356700_child * GetMostInterestingChild__16CB3CrashAnalyserFP19CGtSphereTreeSphere(void *, void *);
extern "C" void GetRigImpact__22CB3CrashCameraDirectorFP13CB3ClusterRigP12CB3ChildBody(UnkStruct_00356700 *, UnkStruct_00356700_rig *, UnkStruct_00356700_child *);
extern "C" void GetRigMatrix__14CB3CameraUtilsFPQ29GtMathPs212CGtMatrix3x4P16CB3CollidingBody(CGtMatrix3x4 * m, void * body);
extern "C" int func_00355A90(UnkStruct_00356700 *, UnkStruct_00356700_rig *, float *, UnkStruct_00356700_child *, int, int);
extern "C" UnkStruct_00356700_lane * WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(void *, unsigned short *, const CGtV3d &);
extern "C" CGtV3d GetPositionAtParam__14CB3CameraUtilsFP15CB3AILaneStructUsf18EAISegmentLinkType(UnkStruct_00356700_ls *, unsigned short, float, int);
// [L] retail passes a 10th argument at 8(sp) that the mangled name doesn't list (as in func_00356FB0)
extern "C" void PrepareRotate__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyffQ29GtMathPs26CGtV3dfffRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs212CGtMatrix3x4fib(
    UnkStruct_00356700_rig *, int, int, void *, float, float, const CGtV3d &, float, float, float, const CGtMatrix3x4 &, const CGtMatrix3x4 &, float, int, bool, bool);
extern "C" void SetRig__19CB3BehaviourClusterFP13CB3ClusterRig(void *, void *);
extern "C" void SetParameters__23CB3BehaviourInterpolateF24EB3PlayerCameraBehaviour24EB3PlayerCameraBehaviourf20EB3InterpolationType24EB3InterpolationTimeMode(void *, int, int, float, int, int);
extern "C" unsigned int TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(void *, const CGtV3d *);
extern "C" int IntersectLineWithUnit__16CB3StreamedTrackFUiRC7CGtLinePFRC28CGtPolygonIntersectionResultPv_bPv(void *, unsigned int, const UnkStruct_00356700_line *, bool (*)(const void *, void *), void *);
extern "C" bool func_00356680(const void *, void *);

// [L] N185 stand-ins (copied from func_00356FB0): orthonormal invert of a 3x4 matrix in place.
static inline void func_00356700_inl1(CGtV3d &d, const CGtV3d &s) { asm("vadd.xyz %0, %0, %1" : "+j"(d.mData) : "j"(s.mData)); }
static inline CGtV3d func_00356700_inl3(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulx.xyz %0, %1, %2x" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_00356700_inl4(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmuly.xyz %0, %1, %2y" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline CGtV3d func_00356700_inl5(const CGtV3d &a, const CGtV3d &s) { u_long128 t; asm("vmulz.xyz %0, %1, %2z" : "=j"(t) : "j"(a.mData), "j"(s.mData)); return CGtV3d(t); }
static inline void func_00356700_r0(CGtV3d &d, const CGtV3d &b, const CGtV3d &c) { asm("vaddx.y %0, $vf0, %1x" "\n\t" "vaddx.z %0, $vf0, %2x" : "+j"(d.mData) : "j"(b.mData), "j"(c.mData)); }
static inline void func_00356700_r1(CGtV3d &d, const CGtV3d &a, const CGtV3d &c) { asm("vaddy.x %0, $vf0, %1y" "\n\t" "vaddy.z %0, $vf0, %2y" : "+j"(d.mData) : "j"(a.mData), "j"(c.mData)); }
static inline void func_00356700_r2(CGtV3d &d, const CGtV3d &a, const CGtV3d &b) { asm("vaddz.x %0, $vf0, %1z" "\n\t" "vaddz.y %0, $vf0, %2z" : "+j"(d.mData) : "j"(a.mData), "j"(b.mData)); }
static inline void func_00356700_inl0(CGtMatrix3x4 &r)
{
    CGtV3d a = r.mRight, b = r.mUp, c = r.mAt;
    func_00356700_r0(r.mRight, b, c);
    func_00356700_r1(r.mUp, a, c);
    func_00356700_r2(r.mAt, a, b);
    CGtV3d p = r.mPos;
    CGtV3d z = func_00356700_inl5(r.mAt, p);
    CGtV3d x = func_00356700_inl3(r.mRight, p);
    CGtV3d t = x + func_00356700_inl4(r.mUp, p);
    func_00356700_inl1(t, z);
    r.mPos = -t;
}
// [L] N185 stand-in (as func_00356FB0): Y-lane subtract with the subtrahend loaded first.
static inline YAxisType func_00356700_ysub(YAxisType b, YAxisType a) { UnkStruct_00356700_pad py2_0, py2_1, py2_2, py2_3, py2_4, py2_5, py2_6, py2_7; u_long128 r; asm("vsuby.y %0, %1, %2y" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return YAxisType(r); }
// [G] placeholder inline (as func_00356FB0's): is the lane segment linked both ways, and the child not more than 3
// below the lane point.
static inline bool func_00356700_inl6(UnkStruct_00356700 * self, UnkStruct_00356700_child * child, unsigned short & seg)
{
    UnkStruct_00356700_pad pa2_0, pa2_1, pa2_2, pa2_3, pa2_4, pa2_5, pa2_6, pa2_7, pa2_8, pa2_9, pa2_10, pa2_11, pa2_12, pa2_13, pa2_14, pa2_15, pa2_16;
    CGtV3d pos = child->field_40->field_204->mPos;
    UnkStruct_00356700_ai * ai = func_00353960(self->field_8)->field_40->field_13F4;
    seg = ai->field_18B8;
    UnkStruct_00356700_ls * ls = WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(ai->field_18B4, &seg, pos)->field_4;
    UnkStruct_00356700_e * e = &ls->field_8[seg];
    bool ok = e->field_4 != 0xFF && e->field_5 != 0xFF;
    if (ok) {
        UnkStruct_00356700_pad pb2_0;
        CGtV3d p = GetPositionAtParam__14CB3CameraUtilsFP15CB3AILaneStructUsf18EAISegmentLinkType(ls, seg, 0.0f, 1);
        UnkStruct_00356700_pad pc2_0, pc2_1, pc2_2, pc2_3, pc2_4, pc2_5, pc2_6, pc2_7;
        if (func_00356700_ysub(p.Y(), pos.Y()) < -3.0f)
            ok = false;
    }
    return ok;
}

// [G] copy of ysub/inl6 for the second expansion: retail's dead slots differ per expansion (N140 pads).
static inline YAxisType func_00356700_ysub3(YAxisType b, YAxisType a) { UnkStruct_00356700_pad py3_0, py3_1, py3_2, py3_3, py3_4, py3_5, py3_6, py3_7, py3_8, py3_9, py3_10, py3_11; u_long128 r; asm("vsuby.y %0, %1, %2y" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return YAxisType(r); }
// [G] (copy): is the lane segment linked both ways, and the child not more than 3
// below the lane point.
static inline bool func_00356700_inl7(UnkStruct_00356700 * self, UnkStruct_00356700_child * child, unsigned short & seg)
{
    UnkStruct_00356700_pad pa3_0, pa3_1;
    CGtV3d pos = child->field_40->field_204->mPos;
    UnkStruct_00356700_ai * ai = func_00353960(self->field_8)->field_40->field_13F4;
    seg = ai->field_18B8;
    UnkStruct_00356700_ls * ls = WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(ai->field_18B4, &seg, pos)->field_4;
    UnkStruct_00356700_e * e = &ls->field_8[seg];
    bool ok = e->field_4 != 0xFF && e->field_5 != 0xFF;
    if (ok) {
        UnkStruct_00356700_pad pb3_0;
        CGtV3d p = GetPositionAtParam__14CB3CameraUtilsFP15CB3AILaneStructUsf18EAISegmentLinkType(ls, seg, 0.0f, 1);
        UnkStruct_00356700_pad pc3_0, pc3_1, pc3_2, pc3_3, pc3_4, pc3_5, pc3_6, pc3_7, pc3_8, pc3_9, pc3_10, pc3_11, pc3_12, pc3_13;
        if (func_00356700_ysub3(p.Y(), pos.Y()) < -3.0f)
            ok = false;
    }
    return ok;
}

// 0x00356700
extern "C" void UpdateCrashMode__22CB3CrashCameraDirectorFf(UnkStruct_00356700 * self, float dt)
{
    bool changed;
    UnkStruct_00154A30_4 * m = D_0051BA88.field_0;
    UnkStruct_00154A30_5 * o = m->field_1B4;
    bool on = true;
    if (D_01E65499.field_0 == 0) {
        if (m == (void *)&D_0051AEC0)
            on = false;
    } else {
        if (o->vfunc_9C() != 3)
            on = false;
    }
    if (on && (unsigned)(self->field_2C - 2) <= 1 && (self->field_C->field_B80 & 0x400) != 0) {
        float s = GetTimeScale__23CB3BehaviourInterpolateFv(self->field_C->field_8C0);
        if (s <= 0.2f || s >= 0.8f)
            D_0051BAD6.field_0 = 1;
        else
            D_0051BAD5.field_0 = 1;
    }
    if (func_00131F60(&D_004EE040) != 0 && (self->field_C->field_B80 & 0x400) == 0)
        D_0051BAD6.field_0 = 1;
    UnkStruct_00356700_b40 * b = func_00353960(self->field_8)->field_40;
    float interp = 0.0f;
    self->field_1C -= dt;
    changed = false;
    UnkStruct_00356700_rig rig;
    UnkStruct_00356700_line line;
    if (self->field_18 == 0.0f) {
        CGtMatrix3x4 inv;
        CGtMatrix3x4 mat;
        CGtV3d v;
        UnkStruct_00356700_pad pb1_0;
        UnkStruct_00356700_child * car = func_00353960(self->field_8);
        GetRigMatrix__14CB3CameraUtilsFPQ29GtMathPs212CGtMatrix3x4P16CB3CollidingBody(&mat, car->field_40);
        inv = mat;
        func_00356700_inl0(inv);
        float k = self->field_14->field_30->field_74;
        v = car->field_0;
        PrepareRotate__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyffQ29GtMathPs26CGtV3dfffRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs212CGtMatrix3x4fib(
            &rig, 1, 6, car, 180.0f, D_004C71E4[0], v, D_004C71D4[0], D_004C71F4[0], D_004C7204[0], mat, inv,
            k, self->field_28, true, true);
        self->field_2C = 1;
        self->field_1C = 2.5f;
        changed = true;
        interp = 0.5f;
    } else if (b->field_4586 != 0 || !(b->field_3534 <= 0.0f)) {
        if (self->field_2C != 2) {
            if (self->field_2C != 1) {
                CGtMatrix3x4 inv;
                CGtMatrix3x4 mat;
                CGtV3d v;
                unsigned short seg;
                float f;
                UnkStruct_00356700_child * car = func_00353960(self->field_8);
                GetRigMatrix__14CB3CameraUtilsFPQ29GtMathPs212CGtMatrix3x4P16CB3CollidingBody(&mat, car->field_40);
                inv = mat;
                func_00356700_inl0(inv);
                func_00355A90(self, &rig, &f, car, 0, 0);
                bool ok = func_00356700_inl6(self, car, seg);
                float k = self->field_14->field_30->field_74;
                v = rig.field_90;
                PrepareRotate__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyffQ29GtMathPs26CGtV3dfffRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs212CGtMatrix3x4fib(
                    &rig, 0, 4, rig.field_84, rig.field_B0, 5.5f, v, D_004C71D8[0], 75.0f, D_004C7208[0], mat, inv,
                    k, self->field_28, ok, false);
                rig.field_C8 = 2;
                changed = true;
                interp = 0.5f;
            }
            self->field_1C = 0.5f;
            self->field_2C = 2;
        }
        self->field_1C = 0.5f;
    } else if (self->field_1C <= 0.0f) {
        UnkStruct_00356700_child * v = GetVehicleBeforeImpact__16CB3CrashAnalyserFv(self->field_8);
        if (v != 0) {
            GetRigImpact__22CB3CrashCameraDirectorFP13CB3ClusterRigP12CB3ChildBody(self, &rig, v);
            float k = 1.5f;
            self->field_1C = GtMath::Min(GtMath::Max(k * v->field_54, 0.75f), k);
            changed = true;
            self->field_2C = 3;
            if (on)
                interp = 1.0f;
            else
                interp = 0.3f;
            self->field_1C += interp;
        } else if (!(self->field_18 <= 10.0f) && self->field_2C != 4) {
            void * cluster = GetMostInterestingCluster__16CB3CrashAnalyserFv(self->field_8);
            if (cluster != 0) {
                CGtMatrix3x4 inv;
                CGtMatrix3x4 mat;
                CGtV3d v;
                unsigned short seg;
                float f;
                UnkStruct_00356700_child * child = GetMostInterestingChild__16CB3CrashAnalyserFP19CGtSphereTreeSphere(self->field_8, cluster);
                GetRigMatrix__14CB3CameraUtilsFPQ29GtMathPs212CGtMatrix3x4P16CB3CollidingBody(&mat, child->field_40);
                inv = mat;
                func_00356700_inl0(inv);
                func_00355A90(self, &rig, &f, child, 0, 1);
                bool ok = func_00356700_inl7(self, child, seg);
                float k = self->field_14->field_30->field_74;
                v = rig.field_90;
                PrepareRotate__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyffQ29GtMathPs26CGtV3dfffRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs212CGtMatrix3x4fib(
                    &rig, 2, 4, rig.field_84, rig.field_B0, 5.5f, v, D_004C71D8[0], 75.0f, D_004C7208[0], mat, inv,
                    k, self->field_28, ok, false);
                changed = true;
                self->field_1C = 5.0f;
                interp = 1.0f;
                self->field_2C = 4;
            }
        }
    }
    if (changed) {
        int n = self->field_28;
        UnkStruct_00356700_cam * c = self->field_C;
        line.field_0 = c->field_220;
        line.field_10 = rig.field_40.mPos;
        void * trk = (char *)((char *)D_00522660 + n * 0x1CC) + 0x12A348;
        unsigned int u = TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(trk, &line.field_0);
        bool hit = false;
        IntersectLineWithUnit__16CB3StreamedTrackFUiRC7CGtLinePFRC28CGtPolygonIntersectionResultPv_bPv(trk, u, &line, func_00356680, &hit);
        if (hit) {
            self->field_C->field_BA6 = 1;
            SetRig__19CB3BehaviourClusterFP13CB3ClusterRig(self->field_10, &rig);
        } else if (self->field_20 == 0) {
            SetRig__19CB3BehaviourClusterFP13CB3ClusterRig(self->field_10, &rig);
            SetParameters__23CB3BehaviourInterpolateF24EB3PlayerCameraBehaviour24EB3PlayerCameraBehaviourf20EB3InterpolationType24EB3InterpolationTimeMode(
                self->field_C->field_8C0, self->field_C->field_BA0, 6, interp, 0, 1);
        } else {
            SetRig__19CB3BehaviourClusterFP13CB3ClusterRig(self->field_C->field_6D0, self->field_10->field_10);
            self->field_C->field_B80 = 0x80;
            SetRig__19CB3BehaviourClusterFP13CB3ClusterRig(self->field_10, &rig);
            SetParameters__23CB3BehaviourInterpolateF24EB3PlayerCameraBehaviour24EB3PlayerCameraBehaviourf20EB3InterpolationType24EB3InterpolationTimeMode(
                self->field_C->field_8C0, 7, 6, interp, 1, 1);
        }
        self->field_20++;
    }
    self->field_18 += dt;
}
