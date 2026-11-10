// NONMATCHING: StopCrashing__17CB3RaceCarPhysicsFv -- retail 442 / ours 400 instructions, 458 in changed runs
// draftAO (2026-11-01): complete: the three inverse-inertia blocks written (diag lanes set into the existing rows, w kept; world tensor transpose(R)*D*R via SetRealisticMomentsOfInertia's helpers); HEVYCAR5/6 diagonal fixed to (0.00075, 0.0008, 0.0011) [C] 0x1BF830 (the skeleton had (0, 0.00075, 0)); Revenge local lbCanReset [L]; calls identical, behaviour_audit quiet | Before: audit1 (2026-11-01): layout: pad_216 was 0x60 too long (field_13F4 read at 0x1454) and pad_1914 8 short (field_1960/field_19AC at 0x1958/0x19A4) [C] retail 0x1BF5A8, 0x1BF810 (behaviour_audit) | Before: psweep: scoped #pragma inline_depth(3) [G] improves 1452 -> 1424
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm (0x1BF580..0x1BFC64): every call, branch and non-stack store traced (store census equal); behaviour_audit quiet

// StopCrashing__17CB3RaceCarPhysicsFv -- draftAO fork C (complete draft). 0x1BF580, 0x6E8.
// [C] name: the mangled symbol. Revenge StopCrashing__17CB4RaceCarPhysics (B4RaceCarPhysics.cpp, 0xDC; STABS local lbCanReset) [L].
// What it does [L]: stops the car's body parts crashing; if the car was crashing (field_210) and its race car is set up (+0x19AE):
// leaves the crash state (func_001CBA30, the race car's vfunc_18), resets onto the track unless the reset mode (+0x215) is 3, or 2
// and func_001419B0(race car) is 0; HEVY* vehicles (func_00131E40(&D_004EE040) mode) take their mass from field_13F8+0xB8; then the
// body's inverse inertia: diag(0.0008, 0.0011, 0.0013), HEVYCAR5 / HEVYCAR6 diag(0.00075, 0.0008, 0.0011), other HEVY* diag(0.0004,
// 0.0006, 0.0007) -- each time the world tensor field_40 = transpose(R) * field_10 * R is rebuilt from the rotation rows of *field_204
// (the CB3CollidingBody tail of SetRealisticMomentsOfInertia's archive, reused) [C retail 0x1BF63C..0x1BF7F8, 0x1BF830..0x1BF9EC,
// 0x1BFA78..0x1BFC38]. The diagonal rows are written lane by lane (x, y, z) into the existing rows: their w lanes are kept [C].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

// [L] GtMathPs2::CGtMatrix3x3 with the map's copy ctor (as SetRealisticMomentsOfInertia's archive) [G body]
struct UnkStruct_001BF580_m33 {
    CGtV3d mRight, mUp, mAt;
    UnkStruct_001BF580_m33() {}
    UnkStruct_001BF580_m33(const UnkStruct_001BF580_m33& m) { UnkStruct_001BF580_m33& r = (*this = m); }
};
// [G] the row product inside CGtMatrix3x3::operator* (B3O0PCH 0x1A50B0), result w = w's w
static inline CGtV3d func_001BF580_inl1(const UnkStruct_001BF580_m33& m, CGtV3d v, u_long128 w) {
    u_long128 t = w;
    asm("vmulax.xyz $ACC, %0, %1x" : : "j"(m.mRight.mData), "j"(v.mData));
    asm("vmadday.xyz $ACC, %0, %1y" : : "j"(m.mUp.mData), "j"(v.mData));
    asm("vmaddz.xyz %0, %1, %2z" : "+j"(t) : "j"(m.mAt.mData), "j"(v.mData));
    return CGtV3d(t);
}
// [G] stand-in for CGtMatrix3x3::operator*(const CGtMatrix3x3&): each row of a through b, keeping a's row w [C retail 0x1BF724..0x1BF7E4]
static inline UnkStruct_001BF580_m33 func_001BF580_inl2(const UnkStruct_001BF580_m33& a, const UnkStruct_001BF580_m33& b) {
    UnkStruct_001BF580_m33 r;
    r.mRight = func_001BF580_inl1(b, a.mRight, a.mRight.mData);
    r.mUp = func_001BF580_inl1(b, a.mUp, a.mUp.mData);
    r.mAt = func_001BF580_inl1(b, a.mAt, a.mAt.mData);
    return r;
}
// [G] stand-in for CB3Tensor::GetTranspose() (B3O0PCH 0x1A5230): copies of the rows with the off-diagonal lanes swapped, each row
// keeping its own w [C retail 0x1BF6F4..0x1BF708]
static inline UnkStruct_001BF580_m33 func_001BF580_inl3(const UnkStruct_001BF580_m33& m) {
    UnkStruct_001BF580_m33 t = m;
    asm("vaddx.y %0, $vf0, %1x" "\n\t" "vaddx.z %0, $vf0, %2x" : "+j"(t.mRight.mData) : "j"(m.mUp.mData), "j"(m.mAt.mData));
    asm("vaddy.x %0, $vf0, %1y" "\n\t" "vaddy.z %0, $vf0, %2y" : "+j"(t.mUp.mData) : "j"(m.mRight.mData), "j"(m.mAt.mData));
    asm("vaddz.x %0, $vf0, %1z" "\n\t" "vaddz.y %0, $vf0, %2z" : "+j"(t.mAt.mData) : "j"(m.mRight.mData), "j"(m.mUp.mData));
    return t;
}

struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_Pad16 D_0055EF70;           // [C] the physics manager (StopRaceCarBodyPartsCrashing's this)
extern UnkStruct_D_004EE040 D_004EE040;
extern char D_004B7D28[];                      // [C] "HEVYCAR5"
extern char D_004B7D38[];                      // [C] "HEVYCAR6"
extern char D_004B7D48[];                      // [C] "HEVY" (compared over 4 characters)
extern float D_004E0DD0, D_004E0DD4, D_004E0DD8, D_004E0DDC, D_004E16D0, D_004E16D4, D_004E16D8;
class CB3PhysicsManager {
public:
    void StopRaceCarBodyPartsCrashing(int);
};
// [L] the race car (field_13F4): vptr at +0x1910 (retail `lw t9, 0x1910(a0); lw t9, 0x18(t9)` with a0 = the object)
class UnkStruct_StopCrashing_x {
public:
    unsigned char pad_0[0x1910];
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(void *);
    virtual void vfunc_18();
    unsigned char pad_1914[0x4C];
    unsigned long field_1960;     // [C] ld: the vehicle id func_0021AB40 names
    unsigned char pad_1968[0x44];
    signed char field_19AC;       // [C] lb: StopRaceCarBodyPartsCrashing's index
    unsigned char pad_19AD;
    unsigned char field_19AE;
};
struct UnkStruct_StopCrashing_b { unsigned char pad_0[0xB8]; float field_B8; };
extern "C" void func_001CBA30(void *);
extern "C" int func_001419B0(void *);
extern "C" int func_00131E40(void *);
extern "C" void func_0021AB40(unsigned long, char *);
extern "C" int strcmp(const char *, const char *);
extern "C" int strncmp(const char *, const char *, unsigned int);

class CB3RaceCarPhysics {
public:
    void StopCrashing();
    void ResetOnTrack(bool, CB3RaceCarPhysics *);
    unsigned char pad_0[0x10];
    UnkStruct_001BF580_m33 field_10;   // [L] CB3Tensor: local inverse inertia (CB3CollidingBody)
    UnkStruct_001BF580_m33 field_40;   // [L] CB3Tensor: world inverse inertia
    unsigned char pad_70[0x1F0 - 0x70];
    float field_1F0;                   // [L] mass (SetRealisticMomentsOfInertia reads it as such)
    unsigned char pad_1F4[0x10];
    CGtMatrix3x4 *field_204;           // the body's matrix
    unsigned char pad_208[8];
    unsigned char field_210;           // crashing
    unsigned char pad_211[4];
    signed char field_215;             // reset mode
    unsigned char pad_216[0x1350 - 0x216];
    unsigned char field_1350;
    unsigned char field_1351;
    unsigned char pad_1352[0x13F4 - 0x1352];
    UnkStruct_StopCrashing_x *field_13F4;   // the race car
    UnkStruct_StopCrashing_b *field_13F8;
    unsigned char pad_13FC[0x152C - 0x13FC];
    float field_152C;
};

// [G] inlined (name unknown; Revenge's CB4CollidingBody calls in StopCrashing): field_10 := diag(x, y, z) lane by lane (w kept),
// field_40 := transpose(R) * field_10 * R with R = the rows of *field_204
static inline void func_001BF580_inl4(CB3RaceCarPhysics *self, float x, float y, float z)
{
    self->field_10.mRight.SetX(x);
    self->field_10.mRight.SetY(0.0f);
    self->field_10.mRight.SetZ(0.0f);
    self->field_10.mUp.SetX(0.0f);
    self->field_10.mUp.SetY(y);
    self->field_10.mUp.SetZ(0.0f);
    self->field_10.mAt.SetX(0.0f);
    self->field_10.mAt.SetY(0.0f);
    self->field_10.mAt.SetZ(z);
    UnkStruct_001BF580_m33 lRot;
    lRot.mRight = self->field_204->mRight;
    lRot.mUp = self->field_204->mUp;
    lRot.mAt = self->field_204->mAt;
    self->field_40 = func_001BF580_inl2(func_001BF580_inl3(lRot), self->field_10);
    self->field_40 = func_001BF580_inl2(self->field_40, lRot);
}

// 0x001BF580
void CB3RaceCarPhysics::StopCrashing()
{
    ((CB3PhysicsManager *)&D_0055EF70)->StopRaceCarBodyPartsCrashing(field_13F4->field_19AC);
    if (field_210 == 0) return;
    if (field_13F4->field_19AE == 0) return;
    func_001CBA30(this);
    field_13F4->vfunc_18();
    bool lbCanReset = field_215 != 3;
    if (field_215 == 2 && func_001419B0(field_13F4) == 0) {
        lbCanReset = false;
    }
    if (lbCanReset) {
        ResetOnTrack(true, 0);
    }
    if (func_00131E40(&D_004EE040) != 0) {
        char buf[16];
        func_0021AB40(field_13F4->field_1960, buf);
        if (strncmp(buf, D_004B7D48, 4) == 0) {
            field_1F0 = field_13F8->field_B8;
        }
    }
    float x = D_004E0DD0;
    float y = D_004E0DD4;
    func_001BF580_inl4(this, x, y, D_004E0DD8);
    if (field_13F4 != 0) {
        char buf2[16];
        func_0021AB40(field_13F4->field_1960, buf2);
        if (strcmp(buf2, D_004B7D28) == 0 || strcmp(buf2, D_004B7D38) == 0) {
            func_001BF580_inl4(this, D_004E0DDC, x, y);   // [C] 0x1BF830: (DDC, f21 = DD0, f20 = DD4)
        } else if (strncmp(buf2, D_004B7D48, 4) == 0) {
            func_001BF580_inl4(this, D_004E16D0, D_004E16D4, D_004E16D8);
        }
    }
    field_152C = 1.0f;
    field_1350 = 0;
    field_1351 = 0;
}
