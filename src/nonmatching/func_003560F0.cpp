// NONMATCHING: func_003560F0 -- retail 354 / ours 357 instructions, 403 in changed runs (12 hunks)
// draftAM C-first: [L] the crash camera director's per-frame update (config/symbol_addrs_b3names.txt low: CB3CrashCameraDirector::UpdateCrash(float)): first frame (field_18 == 0) picks a rotate rig (func_00355A90, PrepareRotate with the inverted rig matrix, 4.5 / 1.5 by camera-in-car, lane check), scores it, activates the cluster (behaviour 6); later frames re-search when the timer runs out (func_00355BD0, the archived FindInterpRig); camera-in-car latch; a lane-kind-5 segment under the camera (or the cluster's field_1E0) switches to behaviour 5 for 1.5 s; off a driveable lane in mode 5 the cluster rig moves to the second cluster, the camera is raised to 5 above the rig's A0 height and an interpolation 7 -> 6 over 1 s starts; timers advance by dt; 357/354, call multiset identical (static order differs by block layout only), non-stack stores identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; the first-frame block is func_00355BD0's archive shape (PrepareRotate's 16 arguments incl. the 8(sp) bool), every compare (c.eq field_18 0, c.le field_1C 0, the lane-5 and 0x400 bit tests, the u8 masks of func_00355BD0's result and LaneIsDriveable's), the rig copy (memberwise, the +0x88 gap and the tail skipped), the camera raise (5 - A0.y added to the camera y as lane ops) and the 64-bit store 0x80 traced; behaviour_audit: only shape (the lane-5 bool materialised, return-path count, layout)

// func_003560F0 -- draftAM (C-first draft). 0x3560F0, 0x588. Unnamed in every table: placeholder with C linkage. Its only caller
// is the proven func_00356FB0 (0x357228). File [L] B3CrashCameraDirector.cpp (between the director's functions). Declarations and
// the rig record as func_00355BD0's archive; the orthonormal invert is the header's CGtMatrix3x4::Invert() (gapH, decoded from
// the same family). Meanings of the fields [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

// [L] the rig record (CB3ClusterRig), as func_00355BD0's archive: the gap at +0x88 and the tail are not copied
struct UnkStruct_003560F0_rig {
    u_long128 field_0[4];                   // the rig matrix
    u_long128 field_40[4];                  // the camera matrix
    int field_80;
    void * field_84;                        // the child body
    CGtSphere field_90;
    u_long128 field_A0;
    float field_B0;                         // rig angle
    float field_B4;
    float field_B8;
    float field_BC;
    float field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    unsigned char field_D0;
};
struct UnkStruct_003560F0_e { unsigned char pad_0[3]; unsigned char field_3; unsigned char field_4; unsigned char field_5; unsigned char pad_6[4]; };
struct UnkStruct_003560F0_ls { unsigned char pad_0[8]; UnkStruct_003560F0_e * field_8; };
struct UnkStruct_003560F0_lane { unsigned char pad_0[4]; UnkStruct_003560F0_ls * field_4; };
struct UnkStruct_003560F0_ai { unsigned char pad_0[0x18B4]; void * field_18B4; unsigned short field_18B8; unsigned char pad_18BA[0xF2]; signed char field_19AC; };
struct UnkStruct_003560F0_c40 { unsigned char pad_0[0x13F4]; UnkStruct_003560F0_ai * field_13F4; };
struct UnkStruct_003560F0_car { unsigned char pad_0[0x40]; UnkStruct_003560F0_c40 * field_40; };
struct UnkStruct_003560F0_b40 { unsigned char pad_0[0x204]; CGtMatrix3x4 * field_204; };
struct UnkStruct_003560F0_child { unsigned char pad_0[0x40]; UnkStruct_003560F0_b40 * field_40; };
struct UnkStruct_003560F0_f30 { unsigned char pad_0[0x74]; float field_74; };
struct UnkStruct_003560F0_f14 { unsigned char pad_0[0x20]; CGtV3d field_20; UnkStruct_003560F0_f30 * field_30; };
struct UnkStruct_003560F0_bc {              // [L] a CB3BehaviourCluster (SetRig's this)
    unsigned char pad_0[0x10];
    UnkStruct_003560F0_rig field_10;
    unsigned char pad_F0[0xF0];
    unsigned char field_1E0;
};
struct UnkStruct_003560F0_cm {              // [L] the CB3PlayerCameraManager
    unsigned char pad_0[0x6D0];
    unsigned char field_6D0[0x1F0];         // [L] a CB3BehaviourCluster
    unsigned char field_8C0[0x2C0];         // [L] the CB3BehaviourInterpolate
    unsigned long field_B80;                // finished-behaviour bits
};
struct UnkStruct_003560F0 {                 // [L] CB3CrashCameraDirector
    unsigned char pad_0[0x8];
    void * field_8;
    UnkStruct_003560F0_cm * field_C;
    UnkStruct_003560F0_bc * field_10;
    UnkStruct_003560F0_f14 * field_14;
    float field_18;                         // [G] time since the crash started
    float field_1C;                         // [G] time to the next rig search
    unsigned char pad_20[0x8];
    int field_28;
    int field_2C;                           // [G] active camera behaviour
    unsigned char field_30;                 // [G] camera has been inside the car
    unsigned char pad_31;
    unsigned char field_32;
};

extern "C" float func_00354FD0(UnkStruct_003560F0 *, UnkStruct_003560F0_rig *, int, int);
extern "C" int func_00355A90(UnkStruct_003560F0 *, UnkStruct_003560F0_rig *, float *, void *, int, int);
extern "C" int func_00355BD0(UnkStruct_003560F0 *, UnkStruct_003560F0_bc *);
extern "C" UnkStruct_003560F0_car * func_00353960(void *);
extern "C" bool CollisionIsCameraInVehicle__14CB3CameraUtilsFQ29GtMathPs26CGtV3di(CGtV3d, int);
extern "C" UnkStruct_003560F0_lane * WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(void *, unsigned short *, const CGtV3d &);
extern "C" CGtV3d GetPositionAtParam__14CB3CameraUtilsFP15CB3AILaneStructUsf18EAISegmentLinkType(UnkStruct_003560F0_ls *, unsigned short, float, int);
extern "C" bool LaneIsDriveable__9CB3AILaneFUsUs(void *, unsigned short, unsigned short);
extern "C" void PrepareRotate__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyffQ29GtMathPs26CGtV3dfffRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs212CGtMatrix3x4fib(
    UnkStruct_003560F0_rig *, int, int, void *, float, float, CGtV3d, float, float, float, const CGtMatrix3x4 &, const CGtMatrix3x4 &, float, int, bool, bool);
extern "C" void SetRig__19CB3BehaviourClusterFP13CB3ClusterRig(void *, UnkStruct_003560F0_rig *);
extern "C" void SetActiveBehaviour__22CB3PlayerCameraManagerFi(void *, int);
extern "C" void SetParameters__23CB3BehaviourInterpolateF24EB3PlayerCameraBehaviour24EB3PlayerCameraBehaviourf20EB3InterpolationType24EB3InterpolationTimeMode(void *, int, int, float, int, int);

// [L] CB3CrashCameraDirector::IsPointInsideVehicle(CGtV3d) (B3O0PCH map, 0x74): inlined (as func_00355BD0_inl7)
static inline bool func_003560F0_inl1(UnkStruct_003560F0 * self, CGtV3d p)
{
    return CollisionIsCameraInVehicle__14CB3CameraUtilsFQ29GtMathPs26CGtV3di(p, func_00353960(self->field_8)->field_40->field_13F4->field_19AC);
}
// [G] the child's lane segment linked both ways and its start not more than 3 below the child (as func_00355BD0_inl6)
static inline bool func_003560F0_inl2(UnkStruct_003560F0 * self, UnkStruct_003560F0_child * child)
{
    CGtV3d pos = child->field_40->field_204->mPos;
    UnkStruct_003560F0_ai * ai = func_00353960(self->field_8)->field_40->field_13F4;
    unsigned short seg = ai->field_18B8;
    UnkStruct_003560F0_ls * ls = WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(ai->field_18B4, &seg, pos)->field_4;
    UnkStruct_003560F0_e * e = &ls->field_8[seg];
    bool ok = e->field_4 != 0xFF && e->field_5 != 0xFF;
    if (ok) {
        CGtV3d p = GetPositionAtParam__14CB3CameraUtilsFP15CB3AILaneStructUsf18EAISegmentLinkType(ls, seg, 0.0f, 1);
        if ((float)(pos.Y() - p.Y()) < -3.0f)
            ok = false;
    }
    return ok;
}

// 0x003560F0
extern "C" void func_003560F0(UnkStruct_003560F0 * self, float dt)
{
    if (self->field_18 == 0.0f) {
        // first frame of the crash: pick a rotate rig around the car and make the cluster behaviour active
        UnkStruct_003560F0_rig rig;
        float score;
        func_00355A90(self, &rig, &score, func_00353960(self->field_8), 0, 0);
        CGtMatrix3x4 inv = *(CGtMatrix3x4 *)rig.field_0;
        inv.Invert();
        float k;
        if (self->field_30 != 0 || func_003560F0_inl1(self, CGtV3d(rig.field_40[3]))) {
            k = 4.5f;
            self->field_30 = 1;
        } else {
            k = 1.5f;
        }
        bool ok = func_003560F0_inl2(self, (UnkStruct_003560F0_child *)rig.field_84);
        PrepareRotate__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyffQ29GtMathPs26CGtV3dfffRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs212CGtMatrix3x4fib(
            &rig, 0, 3, rig.field_84, rig.field_B0, k, rig.field_90.Position(), (float)rig.field_90.Radius(), rig.field_B8, rig.field_BC,
            *(CGtMatrix3x4 *)rig.field_0, inv, self->field_14->field_30->field_74, self->field_28, ok, false);
        score = func_00354FD0(self, &rig, 1, 0);
        self->field_2C = 6;
        self->field_1C = 0.0f;
        SetRig__19CB3BehaviourClusterFP13CB3ClusterRig(self->field_10, &rig);
        SetActiveBehaviour__22CB3PlayerCameraManagerFi(self->field_C, 6);
    } else if (self->field_1C <= 0.0f) {
        if ((unsigned char)func_00355BD0(self, self->field_10) != 0)
            self->field_2C = 6;
    }
    if (func_003560F0_inl1(self, self->field_14->field_20))
        self->field_30 = 1;
    if (self->field_2C != 5 && (self->field_C->field_B80 & 0x400) == 0) {
        bool lane5;
        if (self->field_10->field_1E0 != 0) {
            lane5 = true;
        } else {
            CGtV3d pos = self->field_14->field_20;
            UnkStruct_003560F0_ai * ai = func_00353960(self->field_8)->field_40->field_13F4;
            unsigned short seg = ai->field_18B8;
            UnkStruct_003560F0_ls * ls = WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(ai->field_18B4, &seg, pos)->field_4;
            lane5 = (ls->field_8[seg].field_3 & 7) == 5;
        }
        if (lane5) {
            self->field_10->field_10.field_CC = 3;
            self->field_10->field_10.field_C8 = 1;
            self->field_2C = 5;
            self->field_1C = 1.5f;
            self->field_32 = 0;
        }
    }
    if (self->field_2C == 5 && self->field_32 == 0) {
        UnkStruct_003560F0_ai * ai = func_00353960(self->field_8)->field_40->field_13F4;
        if (!LaneIsDriveable__9CB3AILaneFUsUs(ai->field_18B4, ai->field_18B8, 1)) {
            // off the road: hand the cluster's rig to the second cluster, raise the camera to 5 above the rig's A0 height,
            // and interpolate from behaviour 7 to 6 over a second
            UnkStruct_003560F0_rig rig = self->field_10->field_10;
            CGtV3d cam(rig.field_40[3]);
            cam.SetY(cam.Y() + (5.0f - CGtV3d(self->field_10->field_10.field_A0).Y()));
            rig.field_40[3] = cam.mData;
            SetRig__19CB3BehaviourClusterFP13CB3ClusterRig(self->field_C->field_6D0, &self->field_10->field_10);
            SetRig__19CB3BehaviourClusterFP13CB3ClusterRig(self->field_10, &rig);
            self->field_C->field_B80 = 0x80;
            SetParameters__23CB3BehaviourInterpolateF24EB3PlayerCameraBehaviour24EB3PlayerCameraBehaviourf20EB3InterpolationType24EB3InterpolationTimeMode(
                self->field_C->field_8C0, 7, 6, 1.0f, 0, 1);
            self->field_1C = 1.5f;
            self->field_32 = 1;
        }
    }
    self->field_1C -= dt;
    self->field_18 += dt;
}
