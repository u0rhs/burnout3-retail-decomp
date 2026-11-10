// NONMATCHING: Prepare__21CB3BehaviourFlyAroundFPv -- retail 626 / ours 664 instructions, 862 in changed runs
// draftAD C-first: target matrix copy, pad from GetLockedPlayersPort, inlined set-mode helper x2 (orbit: ConvertToMatrix, look-at, Invert, * , distance/ASinDeg pitch/atan2 yaw; FOV 90); residue = retail's out-of-line GtMathPs2 copies (CGtV4d*float, CGtQuat ctors, XAxisType ctor, GetSquaredLength) + retail DCE of the 3 unused rows of l*ti; -Z via header vmulx.z (retail vsub.z)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block decoded; the orbit block = the archived Update's (same calls and VU shape); calls equal up to the out-of-line inline copies; VU op counts equal except the dead matrix rows ours keeps and the inlined copies

// CB3BehaviourFlyAround::Prepare(void*) -- hand-written C-first draft (draftAD, 2026-10-31); the lifter refused it.
// [C] name: retail symbol table. [L] Revenge STABS Prepare__21CB4BehaviourFlyAroundPv: bool return, lpData, lpCamera (a CGtCamera*).
// [L] reading: the target car's matrix is copied, the pad controller picked from the locked player's port, then the mode set
// through an inlined helper (twice): with field_70 == 0 the orbit mode (3, auto-spin off) -- which derives the orbit distance /
// pitch / yaw of the camera seen from the target -- and a 90-degree field of view; otherwise the free mode (0).
// The orbit set-up is the archived CB3BehaviourFlyAround::Update's "entering orbit mode" block (look-at stand-in from there);
// retail keeps CGtV4d::operator*(float), the CGtQuat copies, XAxisType(u_long128) (func_0023E3C0) and GetSquaredLength out of line.
#include "b3/GtMath.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;
#pragma push
#pragma inline_depth(7)   // [G] N262: as the Update archive

class CGtCamera;
struct UnkStruct_002EC8F0_cam {
    unsigned char pad_0[0x4];
    float field_4;              // [G] field of view, degrees
    unsigned char pad_8[0x8];
    CGtQuatPos field_10;        // [L] the camera's orientation + position
};
struct UnkStruct_002EC8F0_car { unsigned char pad_0[0x204]; CGtMatrix3x4 * field_204; };
struct UnkStruct_002EC8F0_slot { UnkStruct_002EC8F0_car * field_0; unsigned char pad_4[0x2C]; };
extern UnkStruct_002EC8F0_slot D_0055EFEC[];
struct UnkStruct_D_004F50C0 { unsigned char pad_0[0x10]; };   // [L] CB3InputManager (GetLockedPlayersPort's this)
extern UnkStruct_D_004F50C0 D_004F50C0;
extern CGtV3d kAxisY;
extern "C" signed char GetLockedPlayersPort__15CB3InputManagerFSc(void *, signed char);
extern "C" float func_0011E358(float, float);   // [L] libm atan2f (E_B3DEBUG wf_atan2.o)

class CB3BehaviourFlyAround {
public:
    bool Prepare(void * lpData);

    unsigned char pad_0[0x10];
    CGtMatrix3x4 field_10;      // [G] the target's matrix last frame
    float field_50;             // [G] orbit distance
    float field_54;             // [G] orbit yaw, degrees
    float field_58;
    float field_5C;             // [G] orbit pitch, degrees
    int field_60;               // [G] controller index
    signed char field_64;       // [G] player
    unsigned char pad_65[0x3];
    int field_68;               // [G] target car slot
    int field_6C;               // [G] target slot last frame
    int field_70;
    int field_74;               // [G] mode 0..3
    unsigned char pad_78[0x11];
    unsigned char field_89;     // [G] auto-spin in orbit mode
};

// [L] look-at (as the Update archive's func_002E90F0_inl3): right = Y x at normalised, up = at x right
static inline CGtMatrix3x4 func_002EC8F0_inl1(CGtV3d at, CGtV3d pos)
{
    CGtMatrix3x4 m;
    at.Normalise();
    CGtV3d right = CrossProduct(kAxisY, at);
    right.Normalise();
    m.mRight = right;
    m.mUp = CrossProduct(at, right);
    m.mAt = at;
    m.mPos = pos;
    return m;
}

// [G] set the mode (inlined twice); orbit mode derives distance / pitch / yaw from the camera's current place
static inline void func_002EC8F0_inl2(CB3BehaviourFlyAround * self, UnkStruct_002EC8F0_cam * cam, int mode)
{
    self->field_74 = mode;
    self->field_89 = 0;
    if (self->field_74 == 3) {
        CGtMatrix3x4 * t = D_0055EFEC[self->field_68].field_0->field_204;
        CGtMatrix3x4 cm = cam->field_10.ConvertToMatrix();
        CGtMatrix3x4 l = func_002EC8F0_inl1(t->mPos - cm.mPos, cm.mPos);
        CGtMatrix3x4 ti = *t;
        ti.Invert();
        CGtMatrix3x4 r = l * ti;
        self->field_50 = r.mPos.GetLength();
        self->field_5C = GtMath::ASinDeg((float)r.mPos.Y() / self->field_50);
        self->field_54 = 57.29578f * func_0011E358(-r.mPos.X(), -r.mPos.Z());
    }
}

// 0x002EC8F0
bool CB3BehaviourFlyAround::Prepare(void * lpData)
{
    UnkStruct_002EC8F0_cam * lpCamera = (UnkStruct_002EC8F0_cam *)lpData;
    signed char port = GetLockedPlayersPort__15CB3InputManagerFSc(&D_004F50C0, field_64);
    field_10 = *D_0055EFEC[field_68].field_0->field_204;
    field_6C = field_68;
    if (port == 1) field_60 = 0;
    else field_60 = 1;
    if (field_70 == 0) {
        func_002EC8F0_inl2(this, lpCamera, 3);
        lpCamera->field_4 = 90.0f;
    } else {
        func_002EC8F0_inl2(this, lpCamera, 0);
    }
    return true;
}
#pragma pop
