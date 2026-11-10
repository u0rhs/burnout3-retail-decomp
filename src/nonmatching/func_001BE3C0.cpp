// NONMATCHING: func_001BE3C0 -- retail 330 / ours 331 instructions, 19 in changed runs
// near37: header CGtRandom (D_0055E948 = the director's CGtRandom at +0) + scoped opt_scalarize off [G] (keeps every RNG D_0055E948 store as retail) + scoped opt_pulloutconstants off [G] (0.5 rematerialised) + 3-operand vsuby.y stand-in for the field_1F4 tail (header operator-(Y,Y) numbers a/b the other way, as in CheckRaceCar): 79 -> 19. Left: p3->field_0's GetLength square reuses the GPR copy of the 1D0 store (retail lqc2 0(s2) itself; const pun / local copy don't help), SetRadius vmulx.w vf1/vf2 swap, 10.0f + D_00522680 FP numbering (D in f0 vs f1) and the 2^-32 lui placement
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// v310: logic complete, frame exact (0x390 via a 0x140 N140 pad), bool return (retail's dead li v0,1). Left 327 vs 330, 84 changed: (1) RNG step x4 (CB3CrashActionDirector D_0055E948/D_0055E94C): retail stores D_0055E948 right after computing it, before the D_0055E94C store and the unsigned-convert branch; every inline form tried (local x, struct pair, compound) sinks it; (2) header NormaliseGetLength gives nop; sqrt.s; nop where retail has mtc1; sqrt.s; mfc1 back to back (header gap?); (3) VU numbering at the vmove.w w-restore block (retail lqc2s p3->field_0 for GetLength, ours reuses the GPR copy) and the box-centre Y (vf2/vf3 swapped); (4) the lane temp sits at sp+0xA0, retail sp+0xE0 (4 dead slots below it). Stand-ins [L] N185: vmove.w w copy, X-X / Z-Z / X*Z lane ops, operator*=(float).

// func_001BE3C0 -- hand-written (v310); the lifter refused it (vmove.w). Unnamed in every table: a placeholder with C
// linkage (the asm label). [G] a CB3CollidingBody-derived Prepare (layout as CB3TrafficPhysics::Prepare's, 0x2510F0:
// field_B0 CGtV3dPlus, field_C0, field_1D0/1E0 box, field_1F4, field_204 matrix): copies the matrix, calls the base set-up,
// restores the matrix rows' w lanes, builds the hull from the box, a random spin axis/rate from the CB3CrashActionDirector
// RNG (D_0055E948/D_0055E94C, the StartTrafficCrashing step). Types are [G].

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
#include "b3/_unclassified/GtRandom.h"
#pragma push
#pragma opt_pulloutconstants off
#pragma push
#pragma opt_scalarize off

using namespace GtMathPs2;

struct UnkStruct_001BE3C0_box {
    CGtV3d field_0;
    CGtV3d field_10;
};
struct UnkStruct_001BE3C0_g { int field_0; int pad_4[3]; };
struct UnkStruct_001BE3C0_t { float field_0; int pad_4[3]; };

struct UnkStruct_001BE3C0 {
    unsigned char pad_0[0xB0];
    CGtV3dPlus field_B0;
    CGtV3d field_C0;
    unsigned char pad_D0[0xF0];
    CGtSphere field_1C0;
    CGtV3d field_1D0;
    CGtV3d field_1E0;
    float field_1F0;
    float field_1F4;
    unsigned char pad_1F8[0x8];
    int * field_200;
    CGtMatrix3x4 * field_204;
    void * field_208;
    unsigned char field_20C;
    unsigned char pad_20D[0x13];
    void * field_220;
    float field_224;
    unsigned char pad_228[0x8];
    int field_230;
    void * field_234;
    void * field_238;
    unsigned char pad_23C[0x4];
    unsigned char field_240[0x300];
    unsigned char field_540[0x30];
    unsigned char field_570[0x10];
};

// [L] the CB3CrashActionDirector (D_0055E948) starts with its CGtRandom (StartTrafficCrashing 0x1AE500 steps it)
struct UnkStruct_D_0055E948 { CGtRandom field_0; unsigned char pad_8[8]; };
extern UnkStruct_D_0055E948 D_0055E948;
extern UnkStruct_001BE3C0_t D_00522680;

extern "C" bool func_001AD380(UnkStruct_001BE3C0 *);
extern "C" void func_001AB610(UnkStruct_001BE3C0 *, CGtMatrix3x4 *);
extern "C" void Initialise__17CB3ConvexHullPropFv(void *);
extern "C" void MakeFromBoundingBox__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d12EB3HullShape(void *, const void *, const void *, int);
extern "C" void SetRealisticMomentsOfInertia__16CB3CollidingBodyFv(void *);

// [L] N185: stand-ins for missing GtMathPs2 inlines: CGtV4d-style w copy (`vmove.w`), lane differences and the X*Z lane
// product on compiler-chosen registers, CGtV3d::operator*=(float)
static inline void func_001BE3C0_inl2(CGtV3d & d, const CGtV3d & s) { asm("vmove.w %0, %1" : "+j"(d.mData) : "j"(s.mData)); }
static inline XAxisType func_001BE3C0_inl3(XAxisType a, XAxisType b) { u_long128 r; asm("vsubx.x %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return XAxisType(r); }
static inline ZAxisType func_001BE3C0_inl4(ZAxisType a, ZAxisType b) { asm("vsubz.z %0, %1, %0z" : "+j"(b.lVector) : "j"(a.lVector)); return ZAxisType(b.lVector); }
static inline XAxisType func_001BE3C0_inl5(XAxisType a, ZAxisType b) { asm("vmulz.x %0, %1, %0z" : "+j"(b.lVector) : "j"(a.lVector)); return XAxisType(b.lVector); }
static inline void func_001BE3C0_inl6(CGtV3d & v, float f) { u_long128 s; asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f)); asm("vmulx.xyz %0, %0, %1x" : "+j"(v.mData) : "j"(s)); }
// [L] N185 stand-in for operator-(YAxisType, YAxisType): the three-operand compiler-chosen form numbers the operands as retail
static inline YAxisType func_001BE3C0_inl7(YAxisType a, YAxisType b) { u_long128 r; asm("vsuby.y %0, %1, %2y" : "=j"(r) : "j"(a.lVector), "j"(b.lVector)); return YAxisType(r); }
// N140 frame pad: retail's frame keeps 0x180 more bytes of dead 16-byte slots (the inlined by-value vector/lane
// temporaries b119 drops); an unused local with an empty ctor/dtor reserves them and emits no code
struct UnkStruct_001BE3C0_pad { int x[80]; UnkStruct_001BE3C0_pad() {} ~UnkStruct_001BE3C0_pad() {} };

// 0x001BE3C0
extern "C" bool func_001BE3C0(UnkStruct_001BE3C0 * self, void * p1, CGtMatrix3x4 * p2, const UnkStruct_001BE3C0_box * p3)
{
    func_001AD380(self);
    CGtMatrix3x4 m = *p2;
    self->field_220 = p1;
    self->field_204 = p2;
    func_001AB610(self, self->field_204);
    func_001BE3C0_inl2(p2->mRight, m.mRight);
    func_001BE3C0_inl2(p2->mUp, m.mUp);
    func_001BE3C0_inl2(p2->mAt, m.mAt);
    func_001BE3C0_inl2(p2->mPos, m.mPos);
    self->field_208 = self->field_570;
    self->field_1D0 = p3->field_0;
    self->field_1E0 = p3->field_10;
    self->field_1C0.SetRadius(p3->field_0.GetLength());
    Initialise__17CB3ConvexHullPropFv(self->field_570);
    self->field_20C = 1;
    MakeFromBoundingBox__13CB3ConvexHullFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d12EB3HullShape(self->field_570, &p3->field_10, &p3->field_0, 0);
    self->field_1F0 = GtMath::Max(200.0f * (float)func_001BE3C0_inl5(func_001BE3C0_inl3(self->field_1D0.X(), self->field_1E0.X()), func_001BE3C0_inl4(self->field_1D0.Z(), self->field_1E0.Z())), 100.0f);
    SetRealisticMomentsOfInertia__16CB3CollidingBodyFv(self);
    self->field_224 = 10.0f + D_00522680.field_0;
    self->field_230 = -1;
    self->field_200 = &self->field_230;
    self->field_230 = 0;
    self->field_234 = self->field_240;
    self->field_238 = self->field_540;
    CGtV3d r;
    UnkStruct_001BE3C0_pad pad;
    r.SetX(2.3283064e-10f * (float)D_0055E948.field_0.Random() - 0.5f);
    r.SetY(0.5f * (2.3283064e-10f * (float)D_0055E948.field_0.Random()));
    r.SetZ(2.3283064e-10f * (float)D_0055E948.field_0.Random() - 0.5f);
    func_001BE3C0_inl6(r, 5.0f + 5.0f * (2.3283064e-10f * (float)D_0055E948.field_0.Random()));
    self->field_B0.SetGtV3d(r);
    if (r.GetSquaredLength() < 2.3283064e-10f) {
        self->field_B0.SetPlus(0.0f);
        self->field_C0 = self->field_204->mAt;
    } else {
        self->field_C0 = r;
        self->field_B0.SetPlus(self->field_C0.NormaliseGetLength());
    }
    self->field_1F4 = self->field_1D0.Y() - func_001BE3C0_inl7(self->field_1D0.Y(), self->field_1E0.Y()) * 0.5f;
    return true;
}


#pragma pop

#pragma pop
