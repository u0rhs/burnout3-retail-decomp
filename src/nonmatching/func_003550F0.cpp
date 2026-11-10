// NONMATCHING: func_003550F0 -- retail 614 / ours 612 instructions, 182 in changed runs
// fix2 (2026-11-01): decomp1 2026-11-06: rigs[i].field_80 written 0 (retail copies a never-written stack word into out->field_80, 0x3553EC; host determinism) | Before: draftAL C-first: 16 PrepareRotate candidate rigs (22.5 deg steps, or 360/17 from the current rig), lane-kind-5 block test per camera position, func_00354FD0 scoring (x2 near head-on), up/down half scan with best and best-before-blocked, rig struct copy out; 611/614, calls identical; func_00354FD0 returns float (retail reads f0)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid; shapes from the proven UpdateCrashMode); every call's argument list (PrepareRotate's 16 incl. the unlisted 8(sp) bool, func_00354FD0's bool p4 passed as lbu), the three return values and each arm's score store, the scan order (0..7 then 15..8) and branch sense traced


// func_003550F0 -- draftAL (C-first draft). 0x3550F0, 0x998. Unnamed in every table: placeholder with C linkage. [L] file
// B3CrashCameraDirector.cpp (between proven B3CrashCameraDirector functions; its only caller is the proven func_00355A90).
// Written from the retail asm (Ghidra's draft as a reading aid); declarations and the PrepareRotate / lane-walk shapes from the
// proven sibling B3CrashCameraDirector_00356700.cpp (UpdateCrashMode).
// What it does [L]: picks a crash-camera rotate rig around a child body. It builds 16 candidate rigs around the body (angle
// steps of 22.5 from 0, or 360/17 from the current rig's angle + one step when `useCurrent`), marks each one whose camera
// position lies on an AI-lane segment of kind 5 as blocked, scores the free ones with func_00354FD0 (doubled when the
// director's flag +0x1048 is set and the rig looks within 25 degrees of head-on), scanning 0..7 upwards then 15..8 downwards
// and keeping both the overall best and the best before the first blocked rig of each half. The chosen rig is copied to *out
// and its score to *outScore. Returns 0 (all blocked), 1 or 2 [G: which pick].
// Types and field meanings [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

struct UnkStruct_003550F0_rig {             // [L] CB3ClusterRig (PrepareRotate's this), 0xE0 bytes
    CGtMatrix3x4 field_0;
    CGtMatrix3x4 field_40;                  // camera matrix (mPos = camera position)
    int field_80;                           // never written on this path: see the note in func_003550F0
    void * field_84;
    CGtV3d field_90;
    CGtV3d field_A0;
    float field_B0;                         // rig angle (degrees)
    float field_B4;
    float field_B8;
    float field_BC;
    float field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    unsigned char field_D0;                 // (CGtV3d alignment pads 0x88 and the tail to 0xE0: no pad members, so the copy skips them as retail's)
};
struct UnkStruct_003550F0_e { unsigned char pad_0[3]; unsigned char field_3; unsigned char pad_4[6]; };   // lane segment, 10 bytes
struct UnkStruct_003550F0_ls { unsigned char pad_0[8]; UnkStruct_003550F0_e * field_8; };
struct UnkStruct_003550F0_lane { unsigned char pad_0[4]; UnkStruct_003550F0_ls * field_4; };
struct UnkStruct_003550F0_ai { unsigned char pad_0[0x18B4]; void * field_18B4; unsigned short field_18B8; };
struct UnkStruct_003550F0_b40 { unsigned char pad_0[0x13F4]; UnkStruct_003550F0_ai * field_13F4; };
struct UnkStruct_003550F0_car { unsigned char pad_0[0x40]; UnkStruct_003550F0_b40 * field_40; };
struct UnkStruct_003550F0_child { CGtV3d field_0; unsigned char pad_10[0x30]; void * field_40; };
struct UnkStruct_003550F0_f30 { unsigned char pad_0[0x74]; float field_74; };
struct UnkStruct_003550F0_f14 { unsigned char pad_0[0x30]; UnkStruct_003550F0_f30 * field_30; };
struct UnkStruct_003550F0_an { unsigned char pad_0[0x1048]; unsigned char field_1048; };
struct UnkStruct_003550F0 {
    CGtRandom field_0;
    UnkStruct_003550F0_an * field_8;
    unsigned char pad_C[0x8];
    UnkStruct_003550F0_f14 * field_14;
    unsigned char pad_18[0x10];
    int field_28;
};
struct UnkStruct_003550F0_D { unsigned char pad_0[0x10]; };
extern UnkStruct_003550F0_D D_004EE040;

extern "C" int func_00131E40(void *);
extern "C" UnkStruct_003550F0_car * func_00353960(void *);
// [C] returns a float: its two tail calls (func_00353C00 / func_00353E10) return f0, read here
extern "C" float func_00354FD0(UnkStruct_003550F0 *, UnkStruct_003550F0_rig *, int, bool);
extern "C" void GetRigMatrix__14CB3CameraUtilsFPQ29GtMathPs212CGtMatrix3x4P16CB3CollidingBody(CGtMatrix3x4 * m, void * body);
extern "C" UnkStruct_003550F0_lane * WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(void *, unsigned short *, const CGtV3d &);
// [L] retail passes a 10th argument at 8(sp) that the mangled name doesn't list (as the proven func_00356FB0 / UpdateCrashMode)
extern "C" void PrepareRotate__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyffQ29GtMathPs26CGtV3dfffRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs212CGtMatrix3x4fib(
    UnkStruct_003550F0_rig *, int, int, void *, float, float, const CGtV3d &, float, float, float, const CGtMatrix3x4 &, const CGtMatrix3x4 &, float, int, bool, bool);

// 0x003550F0
extern "C" int func_003550F0(UnkStruct_003550F0 * self, UnkStruct_003550F0_rig * out, float * outScore, UnkStruct_003550F0_child * child,
                             bool useCurrent, bool p4, float a, float b, float c)
{
    UnkStruct_003550F0_rig rigs[16];
    CGtMatrix3x4 inv;
    CGtMatrix3x4 mat;
    bool ok[16];
    float step;
    float angle;
    if (useCurrent) {
        mat = out->field_0;
        step = 360.0f / 17.0f;
        angle = out->field_B0 + step;
    } else {
        GetRigMatrix__14CB3CameraUtilsFPQ29GtMathPs212CGtMatrix3x4P16CB3CollidingBody(&mat, child->field_40);
        angle = 0.0f;
        step = 22.5f;
    }
    bool allBlocked = true;
    bool allOk = true;
    inv = mat;
    inv.Invert();
    for (int i = 0; i < 16; i++) {
        // [C] retail's *out = rigs[k] copies rigs[k]+0x80 word by word (lw 0x360(a2) / sw 0x80(s1), 0x3553EC..0x3553FC, rigs at
        // sp+0x2E0) but nothing on this path writes it (PrepareRotate 0x35B830 stores 0x0-0x70, 0x84, 0x90, 0xA0-0xD0; PrepareFocus
        // 0x35A700 has no 0x80 store off its `this` s0 [L]): out->field_80 gets a stale word of retail's own frame (0xBE30134C in the native3 capture). Not reproducible;
        // [L] nothing reads it (retail overwrites the caller's rig +0x80 with that garbage). The draft writes 0 so a host build is
        // deterministic (decomp1 2026-11-06).
        rigs[i].field_80 = 0;
        CGtV3d pos = child->field_0;
        PrepareRotate__13CB3ClusterRigF10EB3RigType12EB3FocusTypeP12CB3ChildBodyffQ29GtMathPs26CGtV3dfffRCQ29GtMathPs212CGtMatrix3x4RCQ29GtMathPs212CGtMatrix3x4fib(
            &rigs[i], 0, 4, child, angle, a, pos, b, c, 0.0f, mat, inv, self->field_14->field_30->field_74, self->field_28, true, true);
        CGtV3d cam = rigs[i].field_40.mPos;
        UnkStruct_003550F0_ai * ai = func_00353960(self->field_8)->field_40->field_13F4;
        unsigned short seg = ai->field_18B8;
        UnkStruct_003550F0_ls * ls = WalkLanesToFindPosition__9CB3AILaneFPUsQ29GtMathPs26CGtV3d(ai->field_18B4, &seg, cam)->field_4;
        ok[i] = (ls->field_8[seg].field_3 & 7) != 5;
        if (ok[i])
            allBlocked = false;
        else
            allOk = false;
        angle += step;
    }
    float best = 0.0f;
    int bestIdx = 0;
    int bestRunIdx = 0;
    int idx = 0;
    float bestRun = best;
    bool blocked = false;
    for (int j = 0; j < 16; j++) {
        if (ok[idx]) {
            UnkStruct_003550F0_rig * r = &rigs[idx];
            float s = func_00354FD0(self, r, 1, p4);
            if (self->field_8->field_1048) {
                float d = 180.0f - r->field_B0;
                bool ahead = d <= 25.0f && d >= -25.0f;
                if (ahead)
                    s *= 2.0f;
            }
            if (!(s <= best)) {
                bestIdx = idx;
                best = s;
            }
            if (!blocked && !(s <= bestRun)) {
                bestRun = s;
                bestRunIdx = idx;
            }
        } else {
            blocked = true;
        }
        if (j == 8) {
            blocked = false;
            idx = 16;
        }
        if (j >= 8)
            idx--;
        else
            idx++;
    }
    if (allBlocked) {
        *out = rigs[bestIdx];
        *outScore = best;
        return 0;
    }
    if (useCurrent) {
        if (!(best <= bestRun)) {
            *out = rigs[bestIdx];
            *outScore = best;
            return 2;
        }
        *out = rigs[bestRunIdx];
        *outScore = bestRun;
        return 1;
    }
    if (allOk) {
        if (func_00131E40(&D_004EE040) == 0 && self->field_8->field_1048 == 0) {
            *out = rigs[self->field_0.Random() & 15];
            *outScore = best;
        } else {
            *out = rigs[bestIdx];
            *outScore = best;
        }
        return 1;
    }
    *out = rigs[bestIdx];
    *outScore = best;
    return 2;
}
