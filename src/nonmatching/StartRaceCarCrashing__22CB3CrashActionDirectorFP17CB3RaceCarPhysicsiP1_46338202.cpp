// NONMATCHING: StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo -- retail 1648 / ours 1697 instructions, 1252 in changed runs
// hard1 C-first: the crash start body inlined twice (retail has two copies): for the car's own player id when D_0051BA88->field_1B4->vfunc_A8() or gGame func_00131D20, else for the given id; the body is func_001AE690's (archived the same day) with the CGtMatrix3x4 and collision-info copies inline (func_001AE690 calls them out of line); 1697/1648, call multiset identical (ours lays copy 1's pair path after copy 2), vtable slots 0xA8/0x50/0x10/0x14 as retail, 144 non-stack stores as retail (+6 stack sqc2 of the inverted matrix); left: frame 0xCD0 vs 0x1090, block layout, the info copy's short via lh/sh
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] the body decoded region by region from func_001AE690 (every call, branch sense, Random() draw and store checked there) and confirmed on this function's two copies (call multiset, vtable slots, non-stack stores); the top-level choice of copy from the asm

// func_001AE690 -- hard1 (C-first draft; deferred-hard by draftAH). 0x1AE690, 0xD2C. Unnamed in every table, so a placeholder
// with C linkage and an explicit director pointer. [L] B3CrashActionDirector.cpp (tu_map: between StopRaceCarCrashing and
// StartRaceCarCrashing). Called from CB3NetworkCarPhysics::Update (0x268DA4) as (D_0055E948, car, hud+0x19AC, 0, 0): the same
// argument list as StartRaceCarCrashing(CB3RaceCarPhysics*, int, CB3CollidingPair*, CB3CrashStartInfo*) [C asm].
// What it does [L] (meanings [G]): starts a race car's crash and picks the crash kind.
//  - nothing for a car whose +0x210 flag is set or id -1; two notifications (D_0051BA88->field_1B4 vfunc_50, car vfunc_10);
//  - another player's id: only for a local hud, record state 0xC and a message (vfunc_14(0x13, rec)) to the player object;
//  - our id and the record's timer run out: with a colliding pair, the contact point in both bodies' local frames, the
//    crash zones/corners of both (GetCrashZoneAndCorner), a "side" angle flag (rows 2 between 45 and 135 degrees), a fast flag
//    (over 130 mph), the other body's kind (+0x1C; 3/4/5/8/11 = heavy, +0x19), the quadrant (+0x0) from the two local z,
//    then one impulse kind (func_001CC520 pairs) by these, with Random() draws deciding some; without a pair, a fixed kind
//    0xB (an impulse when the contact normal opposes the body's forward axis by more than 45 degrees);
//  - then the record's crash time (+0x20: 3/7/15/17 by the hud's mode and two gGame queries) and constants, and for a local
//    hud the message as above.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

class CGtAxisAlignedBox;
enum EB3CADZone { EB3CADZone_0 };       // [C] type names: GetCrashZoneAndCorner's mangled parameters
enum EB3CADCorner { EB3CADCorner_0 };
class CB3CrashStartInfo;

struct UnkStruct_001AE690_hud {
    unsigned char pad_0[0x1914];
    int field_1914;                         // [G] 0 = local, 2 = network mode
    unsigned char pad_1918[0x94];
    signed char field_19AC;                 // [G] the player's car id
    unsigned char pad_19AD[0xE13];
    int field_27C0;                         // [G] player index
};
struct UnkStruct_001AE690_info {            // car+0x160, 0x60 bytes (the copy as func_001AF3C0's fields)
    CGtV3d field_0;                         // contact point
    CGtV3d field_10;                        // contact normal
    u_long128 field_20;
    short field_30;
    float field_34;
    int field_38;
    u_long128 field_40;
    u_long128 field_50;
};
class CB3RaceCarPhysics {
public:
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10(int, CB3CrashStartInfo *);
    unsigned char pad_4[0xAC];
    CGtV4d field_B0;                        // velocity, w = speed
    CGtV3d field_C0;
    unsigned char pad_D0[0x90];
    UnkStruct_001AE690_info field_160;      // the collision info
    unsigned char pad_1C0[0x44];
    CGtMatrix3x4 *field_204;                // the body transform
    unsigned char pad_208[0x8];
    bool field_210;                         // [G] already crashed / no crash
    unsigned char pad_211[0x11E3];
    UnkStruct_001AE690_hud *field_13F4;
};
struct UnkStruct_001AE690_body {
    signed char field_0;                    // body kind (3, 4: owners with a vehicle kind)
    unsigned char pad_1[0x3];
    CGtMatrix3x4 *field_4;
    CGtAxisAlignedBox *field_8;
    char *field_C;                          // the owner: +0x173 (s8, kind 3) / +0x2420 (int, kind 4)
};
struct CB3CollidingPair {
    CGtV3d field_0;                         // contact point
    unsigned char pad_10[0x14];
    UnkStruct_001AE690_body *field_24;
    UnkStruct_001AE690_body *field_28;
};
struct UnkStruct_001AE690_rec {             // per-car crash record (0x3C)
    int field_0;                            // quadrant 0..3 from the two local z
    int field_4;                            // crash kind / state
    EB3CADZone field_8;                            // EB3CADZone (ours)
    EB3CADCorner field_C;                            // EB3CADCorner (ours)
    EB3CADZone field_10;                           // EB3CADZone (other)
    EB3CADCorner field_14;                           // EB3CADCorner (other)
    unsigned char field_18;                 // side angle
    unsigned char field_19;                 // heavy other vehicle
    unsigned char field_1A;                 // fast (> 130 mph)
    unsigned char pad_1B;
    int field_1C;                           // the other body's vehicle kind
    float field_20;                         // crash time
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
    float field_38;
};
class CB3CrashActionDirector {
public:
    CGtRandom field_0;
    unsigned char pad_8[0x5];
    unsigned char field_D;
    unsigned char pad_E[0x102];
    UnkStruct_001AE690_rec field_110[8];    // [G] element count
    unsigned char pad_2F0[0x28C];
    float field_57C;                        // impulse strengths [G]
    float field_580;
    float field_584;
    unsigned char pad_588[0x8];
    float field_590;
    float field_594;                        // slow-crash scale (under 100 mph)
    void GetCrashZoneAndCorner(CGtV3d *, CGtAxisAlignedBox *, EB3CADZone *, EB3CADCorner *);  // [C] void, as its archive defines it; retail callers overwrite v0 right after (0x1AE974 / 0x1AF708)
    bool DebugCrashEffect(CB3RaceCarPhysics *, CGtAxisAlignedBox *, CGtMatrix3x4 *, unsigned int);
    void StartRaceCarCrashing(CB3RaceCarPhysics *, int, CB3CollidingPair *, CB3CrashStartInfo *);
};
struct UnkStruct_001AE690_msg {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, void *);
};
struct UnkStruct_001AE690_n {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18();
    virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C();
    virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40();
    virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C();
    virtual void vfunc_50(CB3RaceCarPhysics *, CB3CrashStartInfo *);
    virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64();
    virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78();
    virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C();
    virtual void vfunc_90(); virtual void vfunc_94(); virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual bool vfunc_A8();
};
struct UnkStruct_D_0051BA88 { unsigned char pad_0[0x1B4]; UnkStruct_001AE690_n *field_1B4; };
extern UnkStruct_D_0051BA88 *D_0051BA88;
extern unsigned char D_004EE040[];          // gGame [G]
extern "C" bool func_00131E40(void *);
extern "C" int func_00131CA0(void *);
extern "C" bool func_00131D20(void *);
extern "C" float func_0011E328(float);      // [L] acosf (E_B3DEBUG map: LIBM.A wf_acos.o)
extern "C" void func_001CC520(CB3RaceCarPhysics *, int, int, float);
// [L] the CGtMatrix3x4 copy constructor and the collision info's default / copy constructors, emitted out of line
extern "C" CGtMatrix3x4 *func_001AF420(CGtMatrix3x4 *, const CGtMatrix3x4 *);
extern "C" UnkStruct_001AE690_info *func_001AF410(UnkStruct_001AE690_info *);
extern "C" UnkStruct_001AE690_info *func_001AF3C0(UnkStruct_001AE690_info *, const UnkStruct_001AE690_info *);
// by-value CGtV3d parameters passed as the originals' addresses (draftAF rule)
extern "C" void ApplyRamp__17CB3VehiclePhysicsFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(CB3RaceCarPhysics *, const CGtV3d *, const CGtV3d *, const CGtV3d *);

// [L] N185: Normalise on a compiler-chosen register that also forms 1.0*Q (as B3CrashCombo_003634B0's inl1)
static inline void func_001AE690_inl1(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 one;
    CGtV3d r;
    asm(".set noreorder");
    asm("qmtc2.i %2, $vf1" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %1, $vf1" "\n\t"
        "vwaitq" "\n\t" "vmulq.xyz %0, %0, $Q" : "+j"(v.mData), "=&r"(one) : "r"(l.lVector));
    asm("qmtc2.i %1, $vf1" "\n\t" "qmfc2.i %0, %2" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %1, $vf1" : "=r"(r.mData), "+r"(one) : "j"(v.mData));
    asm(".set reorder");
    v = r;
}
// the crash message to the player object (twice)
static inline void func_001AE690_inl2(UnkStruct_001AE690_hud *hud, UnkStruct_001AE690_rec *rec)
{
    ((UnkStruct_001AE690_msg *)(D_004EE040 + hud->field_27C0 * 0xBB0 + 0x28E00))->vfunc_14(0x13, rec);
}
// a point in a body's local frame
static inline CGtV3d func_001AE690_inl3(const CGtMatrix3x4 *m, const CGtV3d &p)
{
    CGtMatrix3x4 inv = *m;
    inv.Invert();
    return TransformPoint(inv, p);
}

// [L] the crash start proper, inlined twice below; func_001AE690 is a separately compiled copy of it (its CGtMatrix3x4 and
// collision-info copies are out-of-line calls there, inline here)
static inline void func_001AF450_inl0(CB3CrashActionDirector *self, CB3RaceCarPhysics *car, int id, CB3CollidingPair *pair,
                                      CB3CrashStartInfo *info)
{
    if (car->field_210) return;
    if (id == -1) return;
    bool b = func_00131E40(D_004EE040);
    UnkStruct_001AE690_hud *hud = car->field_13F4;
    D_0051BA88->field_1B4->vfunc_50(car, info);
    car->vfunc_10(id, info);
    UnkStruct_001AE690_rec *rec = &self->field_110[id];
    rec->field_4 = 0;
    if (id != hud->field_19AC) {
        if (hud->field_1914 != 0) return;
        rec->field_4 = 0xC;
        func_001AE690_inl2(hud, rec);
        return;
    }
    if (!(rec->field_20 <= 0.0f)) return;
    self->field_D = 0;
    bool local = false;
    if (car->field_13F4 && car->field_13F4->field_1914 == 0) local = true;
    if (pair) {
        CGtMatrix3x4 *matA = car->field_204;
        CGtV3d la = func_001AE690_inl3(matA, pair->field_0);
        CGtMatrix3x4 *matB = pair->field_28->field_4;
        CGtV3d lb = func_001AE690_inl3(matB, pair->field_0);
        self->GetCrashZoneAndCorner(&la, pair->field_24->field_8, &rec->field_8, &rec->field_C);
        CGtAxisAlignedBox *boxB = pair->field_28->field_8;
        self->GetCrashZoneAndCorner(&lb, boxB, &rec->field_10, &rec->field_14);
        rec->field_18 = 0;
        if (!((float)la.Z() <= 0.0f)) {
            CGtV3d a = matA->mAt;
            func_001AE690_inl1(a);
            CGtV3d c = matB->mAt;
            func_001AE690_inl1(c);
            float deg = 57.29578f * func_0011E328((float)CosAngleBetweenNormalisedVectors(a, c));
            if (!(deg <= 45.0f) && deg < 135.0f) rec->field_18 = 1;
        }
        if (!(2.2369363f * (float)car->field_B0.W() <= 130.0f))
            rec->field_1A = 1;
        else
            rec->field_1A = 0;
        unsigned int flags;
        if (!((float)la.X() <= 0.0f))
            flags = 4;
        else
            flags = 8;
        UnkStruct_001AE690_body *other = pair->field_28;
        if (other->field_0 == 4)
            rec->field_1C = *(int *)(other->field_C + 0x2420);
        else if (other->field_0 == 3)
            rec->field_1C = *(signed char *)(other->field_C + 0x173);
        else
            rec->field_1C = 1;
        switch (rec->field_1C) {            // case labels in reverse: MWCC tests them last-first (retail 3, 4, 5, 8, 11)
        default:
            rec->field_19 = 0;
            break;
        case 0xB: case 8: case 5: case 4: case 3:
            rec->field_19 = 1;
            break;
        }
        if (!((float)la.Z() <= 0.0f)) {
            if (!((float)lb.Z() <= 0.0f)) rec->field_0 = 0; else rec->field_0 = 1;
        } else {
            if (!((float)lb.Z() <= 0.0f)) rec->field_0 = 2; else rec->field_0 = 3;
        }
        if (!self->DebugCrashEffect(car, boxB, matB, flags)) {
            // [L] a slow local crash: no impulse one time in four
            if (!(local && 2.2369363f * (float)car->field_B0.W() < 120.0f && (self->field_0.Random() & 3) == 0)) {
                CGtV3d w = car->field_C0;
                bool heavySide = rec->field_19 && rec->field_18;
                if (heavySide) {
                    float f = self->field_580;
                    func_001CC520(car, flags | 2, 0, f);
                    func_001CC520(car, 0x10, 0, f);
                    rec->field_4 = 1;
                } else {
                            if ((float)car->field_B0.W() < 50.0f && self->field_0.Random() % 5 == 0 &&
                        !((float)DotProduct(matA->mAt, w) <= 0.9f)) {
                        int dir;
                        if ((float)DotProduct(matA->mAt, w) < 0.0f) dir = 1; else dir = 2;
                        func_001CC520(car, dir, 0, GtMath::Min(GtMath::Max(2.0f * self->field_0.RandomReal(), 1.0f), 2.0f));
                    } else if (rec->field_1A && self->field_0.Random() % 5 == 0) {
                        CGtAxisAlignedBox *box = boxB;
                        const CGtV3d *bx = (const CGtV3d *)box;
                        CGtV3d ext;
                        ext.SetX(bx[0].X() - bx[1].X());
                        ext.SetY(bx[0].Y() - bx[1].Y());
                        ext.SetZ(ext.X());
                        CGtV3d at;
                        at.SetX(0.0f);
                        at.SetY(0.0f);
                        at.SetZ(bx[0].X());
                        at = TransformPoint(*matB, at);
                        ApplyRamp__17CB3VehiclePhysicsFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(car, &at, &matB->mAt, &ext);
                        rec->field_4 = 2;
                    } else {
                        bool corners = rec->field_C && rec->field_14;
                        if (corners) {
                            float f = self->field_584;
                            func_001CC520(car, flags, 0, f);
                            func_001CC520(car, 0x10, 0, f);
                            rec->field_4 = 3;
                        } else {
                            float f;            // [C] unset for a quadrant outside 0..3 (unreachable: set above)
                            switch (rec->field_0) {
                            case 0: case 3:
                                if (!rec->field_19 && (self->field_0.Random() & 1)) {
                                    f = self->field_584; rec->field_4 = 4;
                                } else if (rec->field_1A) {
                                    f = self->field_57C; rec->field_4 = 5; flags |= 2;
                                } else {
                                    f = self->field_57C; rec->field_4 = 6; flags = 1;
                                }
                                break;
                            case 1:
                                if (!rec->field_19 && (self->field_0.Random() & 1)) {
                                    f = self->field_57C; rec->field_4 = 7; flags |= 1;
                                } else if (rec->field_1A) {
                                    f = self->field_57C; rec->field_4 = 8; flags |= 1;
                                } else {
                                    f = self->field_580; rec->field_4 = 9; flags |= 2;
                                }
                                break;
                            case 2:
                                f = self->field_580; rec->field_4 = 0xA; flags |= 2;
                                break;
                            }
                                            if (2.2369363f * (float)car->field_B0.W() < 100.0f) f = f * self->field_594;
                            func_001CC520(car, flags, 0, f);
                            func_001CC520(car, 0x10, 0, f);
                        }
                    }
                }
            }
        }
    } else {
        UnkStruct_001AE690_info ci = car->field_160;
        if ((float)DotProduct(ci.field_10, car->field_204->mAt) < -0.70710677f) {
            float f = self->field_590;
            func_001CC520(car, 2, 0, f);
            func_001CC520(car, 0x10, 0, f);
        }
        rec->field_4 = 0xB;
    }
    if (hud->field_1914 == 2) {
        if (b) rec->field_20 = 15.0f; else rec->field_20 = 7.0f;
        rec->field_2C = 0.25f;
        rec->field_30 = 0.0f;
        rec->field_34 = 0.0f;
        rec->field_38 = 0.0f;
        rec->field_24 = 2.0f;
    } else {
        if (b) {
            if (func_00131CA0(D_004EE040)) rec->field_20 = 17.0f; else rec->field_20 = 15.0f;
        } else {
            rec->field_20 = 3.0f;
        }
        rec->field_2C = 0.25f;
        rec->field_30 = 0.0f;
        rec->field_34 = 0.0f;
        rec->field_38 = 0.0f;
        rec->field_24 = 0.0f;
    }
    if (hud->field_1914 != 0) return;
    func_001AE690_inl2(hud, rec);
}

// 0x001AF450
void CB3CrashActionDirector::StartRaceCarCrashing(CB3RaceCarPhysics *car, int id, CB3CollidingPair *pair, CB3CrashStartInfo *info)
{
    // [L] when D_0051BA88's object says so (vfunc_A8) or gGame's func_00131D20, the crash is for the car's own player id
    if (D_0051BA88->field_1B4->vfunc_A8() || func_00131D20(D_004EE040)) {
        func_001AF450_inl0(this, car, car->field_13F4->field_19AC, pair, info);
        return;
    }
    func_001AF450_inl0(this, car, id, pair, info);
}
