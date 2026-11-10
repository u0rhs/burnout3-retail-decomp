// NONMATCHING: Update__14CB3PropPhysicsFf -- retail 90 / ours 90 instructions, 22 in changed runs
// near23: float k = -1.0f; k *= s*s; fixed the f0/f1 swap (25 -> 22); pads now one UnkStruct_001BE250_pad type (16 bytes, 3 in inl2 + 4 in body). Left: pure s-register rotation, retail p=s3 / &m.mUp s2 / &m.mAt s1 / &m.mPos s0, ours p=s0 always (p before/after the copy, reference, m declared first, statement moves all keep p in s0)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: Update__14CB3PropPhysicsFf -- retail 90 / ours 90 instructions, 25 in changed runs
// b2l: logic, VU registers and frame (0x130 via N140 pads) exact; left: f0/f1 swap of s vs -1.0f and s-register rotation (p s0 vs retail s3, matrix-row slot addresses s3/s2/s1 vs s2/s1/s0); sreg run, decl orders, copy forms, inline-returned pointer all inert
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// CB3PropPhysics::Update(float) -- hand-written from the retail asm (the lifter refused it: vmove.w).
// Control flow cross-checked against Burnout 2's CPropPhysics::Update (github.com/b3dllc/burnout2 @
// 61e466e295e34abf3de7816c220e4b09ba95022d, src/gamesource/Physics/CPropPhysics.cpp): unit test, air resistance on the
// force from the squared speed, angular air resistance on the torque from the angular-velocity length, then the base
// CollidingBody update. Burnout 3 drops B2's rest/prop-type branches and restores the matrix rows' w lanes after the
// base update. No Burnout 2 name is used for any Burnout 3 symbol (provenance rule).
// [G] func_001BE250_inl1: copies one row's w lane back (vmove.w); no header API.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3CollidingBody {
public:
    void Update(float t);
};
class CB3PropPhysics : public CB3CollidingBody {
public:
    void Update(float t);
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;
    CGtV3d field_C0;
    CGtV3d field_D0;
    unsigned char pad_E0[0x10];
    CGtV3d field_F0;
    CGtV3d field_100;
    unsigned char pad_110[0xF4];
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[0xE];
    signed char field_216;
};

static inline void func_001BE250_inl1(CGtV3d & d, const CGtV3d & s)
{
    asm("vmove.w %0, %1" : "+j"(d.mData) : "j"(s.mData));
}

// [G] N140 frame pads: retail's 0x130 frame keeps nine unused 16-byte slots, four below the W() lane copy (an
// address-read local of the GetLength call's inline, here func_001BE250_inl2's pad) and five between it and the matrix copy.
struct UnkStruct_001BE250_pad { int x[4]; UnkStruct_001BE250_pad() {} ~UnkStruct_001BE250_pad() {} };
static inline float func_001BE250_inl2(const CGtV3d & v) { UnkStruct_001BE250_pad q0, q1, q2; return v.GetLength(); }

// 0x001BE250
void CB3PropPhysics::Update(float t)
{
    if (field_216 == -1) {
        return;
    }
    CGtMatrix3x4 * p = field_204;
    CGtMatrix3x4 m = *p;
    UnkStruct_001BE250_pad q1;
    UnkStruct_001BE250_pad q2;
    UnkStruct_001BE250_pad q3;
    UnkStruct_001BE250_pad q4;
    float s = field_B0.W();
    float k = -1.0f;
    k *= s * s;
    CGtV3d f = field_C0 * k;
    field_F0 += f;
    float a = -2.0f * func_001BE250_inl2(field_D0);
    CGtV3d g = field_D0 * a;
    field_100 += g;
    CB3CollidingBody::Update(t);
    func_001BE250_inl1(p->mRight, m.mRight);
    func_001BE250_inl1(p->mUp, m.mUp);
    func_001BE250_inl1(p->mAt, m.mAt);
    func_001BE250_inl1(p->mPos, m.mPos);
}


