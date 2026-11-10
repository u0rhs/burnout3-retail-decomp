// NONMATCHING: Update__20CB3NetworkCarPhysicsFf -- retail 1151 / ours 1142 instructions, 447 in changed runs
// draftAH C-first: record-driven blend/snap state machine (inline SetMatrix+Invert, blend step, light update, physics on/off); 1142/1151, calls identical, every VU op and sq count equal; left addiu/sw/lw (pointer temps), frame 0xDB0 vs 0x12D0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: all 38 calls in retail order, per-kind VU op counts equal (header operator* / Invert), every branch/store accounted (4-way crash reconcile, two blend tails, on/off switch)

// CB3NetworkCarPhysics::Update(float) -- draftAH (C-first draft; the lifter refused it). 0x268970, 0x11FC.
// [C] name: retail symbol table (Update__20CB3NetworkCarPhysicsFf). [L] file B3NetworkCarPhysics.cpp (Revenge's
// B4NetworkCarPhysics.cpp holds Update__20CB4NetworkCarPhysicsf, 0x3A8: retail inlines much more). Written from the retail asm.
// What it does [L]: the remote car's physics follows the network record at field_1550 (UnkStruct_00268970_net):
//  - a new record (field_1A84) or a new non-crash record (field_1A13): take its velocity / angular velocity / gear
//    (inl2), then start a blend from the car's matrix to the record's matrix field_19B0 over 10 steps (func_0023FA70 ->
//    per-step rotation field_1A40 and position delta field_1A20; func_0023F960 checks the delta is in [-5, 5] per lane).
//    With field_1A84 the crash state is reconciled first: crash state ending (record field_1A14 clear, ours field_210 set)
//    or starting (record set, ours clear) calls into the crash action director D_0055E948 (func_001AE630 / func_001AE690).
//    In two of the four cases the car is first snapped to the record, lightly simulated, and the blend runs from the
//    pre-snap matrix (inl6).
//  - otherwise, while steps remain (field_1A80 > 0), apply one blend step (inl4).
//  - then physics on/off: WeWantToDoPhysics() decides; switching off clears the drive state and stops the body,
//    switching on snaps to the record, resets on the track (or ResetOnTrackWhileCrashing) and rolling-starts at the old speed.
//  - while physics is on, CB3RaceCarPhysics::Update(dt).
// Field names are placeholders; [L] Revenge names in comments (research/names/class_layouts.tsv). Types [G] from widths.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_00268970_n { unsigned char pad_0[0x4EFC]; unsigned char field_4EFC; };   // as WeWantToDoPhysics' UnkStruct_00269B70_n
struct UnkStruct_00268970_net {             // the network record (WeWantToDoPhysics reads field_1A85 / field_1A88 / field_1A90)
    unsigned char pad_0[0x19B0];
    CGtMatrix3x4 field_19B0;                // target matrix
    CGtV3d field_19F0;                      // linear velocity (passed to func_001BEEE0)
    CGtV3d field_1A00;                      // angular velocity (-> CB3CollidingBody +0xD0, [L] mAngularVelocity)
    unsigned char pad_1A10[0x2];
    unsigned char field_1A12;               // low 3 bits: gear (7 = reverse -> -1) [G]
    unsigned char field_1A13;
    unsigned char field_1A14;               // remote car crashing [G]
    unsigned char field_1A15;
    unsigned char field_1A16;
    unsigned char pad_1A17[0x1];
    int field_1A18;
    unsigned char pad_1A1C[0x4];
    CGtV4d field_1A20;                      // per-step position delta (func_0023F960 takes a CGtV4d*)
    unsigned char field_1A30;               // delta in range
    unsigned char pad_1A31[0xF];
    CGtMatrix3x4 field_1A40;                // per-step rotation
    int field_1A80;                         // blend steps left
    unsigned char field_1A84;
    bool field_1A85;
    unsigned short field_1A86;
    UnkStruct_00268970_n * field_1A88;
    unsigned char pad_1A8C[0x4];
    unsigned char field_1A90;               // physics running
};
struct UnkStruct_00268970_1 {
    unsigned char pad_0[0x1998];
    unsigned char field_1998;
    unsigned char pad_1999[0x13];
    signed char field_19AC;
};
struct UnkStruct_00268970_e {               // per-wheel block, stride 0xC0 (as ResetOnTrack's UnkStruct_001BFE80_e)
    float field_0;
    unsigned char pad_4[0x8];
    float field_C;                          // wheel spin (speed / radius, func_001BEEE0)
    float field_10;
    float field_14;
    unsigned char pad_18[0x10];
    int field_28;
    unsigned char pad_2C[0x34];
    short field_60;
    unsigned char pad_62[0x1];
    unsigned char field_63;
    unsigned char pad_64[0x5C];
};

class CB3NetworkCarPhysics {
public:
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();

    void Update(float);
    bool WeWantToDoPhysics();

    unsigned char pad_4[0x6C];
    CGtMatrix3x4 field_70;                  // inverse matrix ([L] CB3CollidingBody::GetInverseMatrix, B3O0PCH map)
    CGtV3dPlus field_B0;                    // [L] mLinearVelocityAndSpeed
    unsigned char pad_C0[0x10];
    CGtV3d field_D0;                        // [L] mAngularVelocity
    unsigned char pad_E0[0xB8];
    int field_198;
    unsigned char pad_19C[0x68];
    CGtMatrix3x4 * field_204;               // the body's matrix
    unsigned char pad_208[0x6];
    unsigned char field_20E;
    unsigned char pad_20F[0x1];
    unsigned char field_210;                // crashing [G]
    unsigned char field_211;
    unsigned char field_212;
    unsigned char pad_213[0x65D];
    UnkStruct_00268970_e field_870[4];      // [G] four wheels (0x9FC / 0xABC = wheels 2 / 3)
    unsigned char pad_B70[0x5F0];
    short field_1160;
    unsigned char pad_1162[0x7];
    signed char field_1169;                 // wheel count
    unsigned char pad_116A[0x28A];
    UnkStruct_00268970_1 * field_13F4;
    unsigned char pad_13F8[0x4E];
    unsigned char field_1446;
    unsigned char pad_1447[0x1];
    float field_1448[8];                    // per-gear table indexed gear + 1 [G]
    float field_1468;
    unsigned char pad_146C[0x30];
    float field_149C;
    unsigned char pad_14A0[0x28];
    int field_14C8;                         // gear
    unsigned char pad_14CC[0x58];
    int field_1524;
    unsigned char field_1528;
    unsigned char pad_1529[0x27];
    UnkStruct_00268970_net * field_1550;
    unsigned char field_1554;
};

extern unsigned char D_0055E948[];          // [L] the crash action director (func_001AE630's self, B3CrashActionDirector.cpp)
extern "C" void func_001AE630(void *, int);
extern "C" void func_001AE690(void *, CB3NetworkCarPhysics *, int, void *, void *);   // [G] two zero arguments (a3, t0)
extern "C" void func_001AB010(void *);      // [L] CB3CollidingBody::ClearAccumulatedValues() (E map, high)
extern "C" void func_001BEEE0(void *, const CGtV3d *);   // [L] DNAT CB3RaceCarPhysics::SetLinearVelocity(CGtV3d) (low)
extern "C" void func_001BED00(void *, float);            // [L] DNAT CB3RaceCarPhysics::RollingStart(float) (low)
extern "C" void func_0023FA70(int n, const CGtMatrix3x4 * lpCurrent, const CGtMatrix3x4 * lpTarget, CGtMatrix3x4 * lpRot, CGtV4d * lpDelta);
extern "C" void func_0023F960(const CGtV4d *, bool *);
extern "C" bool ResetOnTrack__17CB3RaceCarPhysicsFbP17CB3RaceCarPhysics(void *, bool, void *);
extern "C" void ResetOnTrackWhileCrashing__17CB3RaceCarPhysicsFv(void *);
extern "C" void LightweightUpdate__17CB3RaceCarPhysicsFfi(void *, float, int);
extern "C" void Update__17CB3RaceCarPhysicsFf(void *, float);
extern "C" void StopImmediately__16CB3CollidingBodyFv(void *);

// [G] set the body's matrix and its inverse ([L] CB3CollidingBody::SetMatrix(const CGtMatrix3x4&), B3O0PCH map 0x5C: matrix + the
// inverse at +0x70), then settle the wheels (field_10 = field_14, as ResetOnTrack) and clear the accumulators
static inline void func_00268970_inl1(CB3NetworkCarPhysics * self, CGtMatrix3x4 m)
{
    *self->field_204 = m;
    self->field_70 = *self->field_204;
    self->field_70.Invert();
    for (int i = 0; i < self->field_1169; i++)
        self->field_870[i].field_10 = self->field_870[i].field_14;
    func_001AB010(self);
}
// [G] take the record's velocity, angular velocity and gear; drive factor = field_1468 * max(rear wheel spin) * table[gear]
static inline void func_00268970_inl2(CB3NetworkCarPhysics * self)
{
    func_001BEEE0(self, &self->field_1550->field_19F0);
    self->field_D0 = self->field_1550->field_1A00;
    int g = self->field_1550->field_1A12 & 7;
    if (g == 7) g = -1;
    self->field_14C8 = g;
    self->field_149C = self->field_1468 * (GtMath::Max(self->field_870[2].field_C, self->field_870[3].field_C) * self->field_1448[self->field_14C8 + 1]);
    if (self->field_1550->field_1A16 && self->field_14C8 == 1)
        self->field_149C = self->field_149C / 4.0f;
}
// [G] start a 10-step blend from the body's matrix to the record's; lTarget = the record's matrix
static inline void func_00268970_inl3(CB3NetworkCarPhysics * self, CGtMatrix3x4 & lTarget)
{
    self->field_1550->field_1A80 = 10;
    func_0023FA70(self->field_1550->field_1A80, self->field_204, &self->field_1550->field_19B0, &self->field_1550->field_1A40,
                  &self->field_1550->field_1A20);
    bool lbOk;
    func_0023F960(&self->field_1550->field_1A20, &lbOk);
    lTarget = self->field_1550->field_19B0;
    self->field_1550->field_1A30 = lbOk;
}
// [G] one blend step: rotate the body's matrix by the step rotation, move it by the step delta; one step fewer
static inline void func_00268970_inl4(CB3NetworkCarPhysics * self)
{
    UnkStruct_00268970_net * o = self->field_1550;
    if (o->field_1A90) {
        CGtMatrix3x4 lNew = *self->field_204 * o->field_1A40;
        CGtMatrix3x4 lStep = lNew;
        lStep.mPos = self->field_204->mPos + *(CGtV3d *)&o->field_1A20;
        *self->field_204 = lStep;
    }
    self->field_1550->field_1A80--;
}
// [G] after a blend start: step at once if the delta is sane and physics runs; otherwise jump to the target (unless field_1554)
static inline void func_00268970_inl5(CB3NetworkCarPhysics * self, const CGtMatrix3x4 & lTarget)
{
    UnkStruct_00268970_net * o = self->field_1550;
    if (o->field_1A30 && o->field_1A90) {
        func_00268970_inl4(self);
    } else if (!self->field_1554) {
        o->field_1A80 = 0;
        func_00268970_inl1(self, lTarget);
    }
}
// [G] snap to the record, run a light update while physics is wanted, then blend from the pre-snap matrix to where it got
// (back to the pre-snap matrix if the delta is out of range)
static inline void func_00268970_inl6(CB3NetworkCarPhysics * self, CGtMatrix3x4 & lTarget, float dt)
{
    CGtMatrix3x4 lSaved = *self->field_204;
    func_00268970_inl1(self, self->field_1550->field_19B0);
    if (self->WeWantToDoPhysics())
        LightweightUpdate__17CB3RaceCarPhysicsFfi(self, dt, GtMath::Min(self->field_1550->field_1A86 - 1, 8));
    lTarget = *self->field_204;
    self->field_1550->field_1A80 = 10;
    func_0023FA70(self->field_1550->field_1A80, &lSaved, self->field_204, &self->field_1550->field_1A40, &self->field_1550->field_1A20);
    bool lbOk;
    func_0023F960(&self->field_1550->field_1A20, &lbOk);
    if (lbOk)
        func_00268970_inl1(self, lSaved);
    self->field_1550->field_1A30 = lbOk;
}

// 0x00268970
void CB3NetworkCarPhysics::Update(float dt)
{
    vfunc_24();
    if (field_13F4->field_1998 == 0)
        return;
    if (field_1550->field_1A88->field_4EFC)
        field_20E = 1;
    else
        field_20E = 0;
    CGtMatrix3x4 lTarget;
    UnkStruct_00268970_net * o = field_1550;
    if (o->field_1A84) {
        o->field_1A84 = 0;
        func_00268970_inl2(this);
        if (field_1550->field_1A15)
            field_1528 = 1;
        if (field_1550->field_1A16)
            field_1446 = 1;
        else
            field_1446 = 0;
        field_1524 = field_1550->field_1A18;
        unsigned char lbCrashing = field_1550->field_1A14;
        if (!lbCrashing && field_210) {
            func_001AE630(D_0055E948, field_13F4->field_19AC);
            vfunc_14();
            field_1554 = 0;
            func_00268970_inl2(this);
            func_00268970_inl6(this, lTarget, dt);
            field_1550->field_1A30 = 0;
        } else if (lbCrashing && !field_210) {
            func_001AE690(D_0055E948, this, field_13F4->field_19AC, (void *)(0), (void *)(0));
            func_00268970_inl3(this, lTarget);
            field_1550->field_1A30 = 0;
        } else if (field_210 && lbCrashing) {
            func_00268970_inl3(this, lTarget);
        } else {
            func_00268970_inl6(this, lTarget, dt);
        }
        func_00268970_inl5(this, lTarget);
    } else if (o->field_1A13) {
        o->field_1A13 = 0;
        func_00268970_inl2(this);
        if (field_1550->field_1A15)
            field_1528 = 1;
        if (field_1550->field_1A16)
            field_1446 = 1;
        else
            field_1446 = 0;
        field_1524 = field_1550->field_1A18;
        func_00268970_inl3(this, lTarget);
        func_00268970_inl5(this, lTarget);
    } else if (o->field_1A80 > 0) {
        func_00268970_inl4(this);
    }

    bool lbWant = WeWantToDoPhysics();
    o = field_1550;
    if (o->field_1A90 && !lbWant) {
        {
            o->field_1A90 = 0;
            field_1160 = 0;
            field_198 = 0;
            field_212 = 0;
            field_211 = 0;
            for (int i = 0; i < field_1169; i++) {
                field_870[i].field_63 = 0;
                field_870[i].field_60 = 0;
                field_870[i].field_28 = 0;
            }
            field_1524 = 0;
            StopImmediately__16CB3CollidingBodyFv(this);
            vfunc_24();
        }
    } else if (!o->field_1A90 && lbWant) {
        func_00268970_inl1(this, o->field_19B0);
        field_1550->field_1A90 = 1;
        func_001AB010(this);
        vfunc_24();
        if (field_210 || field_1550->field_1A14) {
            ResetOnTrackWhileCrashing__17CB3RaceCarPhysicsFv(this);
        } else {
            float lrSpeed = CGtV4d(field_B0.mData).W();
            ResetOnTrack__17CB3RaceCarPhysicsFbP17CB3RaceCarPhysics(this, false, 0);
            func_001BED00(this, lrSpeed);
        }
    }
    if (field_1550->field_1A90)
        Update__17CB3RaceCarPhysicsFf(this, dt);
}
