// NONMATCHING: InitalisePosition__17CB3TrafficVehicleFv -- retail 248 / ours 252 instructions, 22 in changed runs
// ghvu14: logic + frame right (pragma opt_pulloutconstants off [G], N140 0x90 pad, .i CrossProduct stand-in); 22 off: head 1.5/f120 VU numbering, mPos = field_0 - mAt*f150 rotated (vf3/vf1/vf2 vs vf1/vf2/vf3), GetSquaredLength after each CrossProduct squares into vf1 then moves to vf2 via GPR (retail vf2 directly)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3TrafficVehicle::InitalisePosition() -- hand-written (ghvu14, Ghidra draft + retail asm).
// [C] name: the mangled symbol in retail's tables; Area not evidenced, so _unclassified/ (docs/conventions.md).
// Layout as the proven CB3TrafficVehicle sources (B3TrafficVehicle_00171E90.cpp: CGtV3d rows at 0x60..0xA0) and
// CB3TrafficAxle::InitalisePosition (B3TrafficAxle_0015F940.cpp: axles at +0x0 / +0x30, position CGtV4d at +0);
// field names are placeholders and every type is [G]. ghvu14: the matrix at 0x70 is copied from the per-type
// record (D_00522660 + 0x34210, 0x50 stride [C asm]), the axles placed along mAt, then mAt/mUp/mRight rebuilt
// (IsZero / NormaliseGetLength fallbacks, CrossProduct).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3TrafficVehicle;
class CB3TrafficAxle {
public:
    void InitalisePosition(CB3TrafficVehicle *);
    CGtV3dPlus field_0;
    CGtV3d field_10;
    unsigned char pad_20[0x10];
};
struct UnkStruct_00173950_rec { CGtMatrix3x4 field_0; unsigned char pad_40[0x10]; };
struct UnkStruct_00173950_d { unsigned char pad_0[0x49]; unsigned char field_49; };
struct UnkStruct_D_00522660 { UnkStruct_00173950_rec field_0[1]; };  // [G] element count unknown
extern UnkStruct_D_00522660 D_00522660;

class CB3TrafficVehicle {
public:
    void InitalisePosition();
    void InitaliseTrailerPosition();

    CB3TrafficAxle field_0;
    CB3TrafficAxle field_30;
    CGtV3d field_60;
    CGtMatrix3x4 field_70;
    float field_B0;
    float field_B4;
    float field_B8;
    float field_BC;
    float field_C0;
    unsigned char pad_C4[0x4C];
    CB3TrafficVehicle * field_110;
    UnkStruct_00173950_d * field_114;
    unsigned char pad_118[0x8];
    float field_120;
    unsigned char pad_124[0xC];
    int field_130;
    unsigned char pad_134[0x18];
    float field_14C;
    float field_150;
};

// [L] N185: a - b and a + b on compiler-chosen registers (the header operators hard-code $vf1/$vf2).
static inline CGtV3d func_00173950_inl1(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
static inline CGtV3d func_00173950_inl2(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}
#pragma push
#pragma opt_pulloutconstants off
// N182 [G] scoped to this function: retail rematerialises 1.0f in each out-of-line SetX/SetY block.
// [L] N185: b-first operand lists (VU numbering by creation order, ghvu7).
static inline CGtV3d func_00173950_inl3(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vsub.xyz %0, %2, %1" : "=j"(r) : "j"(b.mData), "j"(a.mData));
    return CGtV3d(r);
}
static inline CGtV3d func_00173950_inl4(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vadd.xyz %0, %2, %1" : "=j"(r) : "j"(b.mData), "j"(a.mData));
    return CGtV3d(r);
}
// [L] N185: CrossProduct (header body) with the result moved out `.i` (retail keeps qmfc2 + sq and reloads, v241).
static inline CGtV3d func_00173950_inl5(CGtV3d a, CGtV3d b)
{
    u_long128 t;
    asm("vopmula.xyz $ACC, %2, %1" "\n\t" "vopmsub.xyz %1, %1, %2" "\n\t" "qmfc2.i %0, %1" : "=r"(t), "+j"(b.mData) : "j"(a.mData));
    return CGtV3d(t);
}
struct UnkStruct_00173950_pad { int x[36]; UnkStruct_00173950_pad() {} ~UnkStruct_00173950_pad() {} };

// 0x00173950
void CB3TrafficVehicle::InitalisePosition()
{
    UnkStruct_00173950_pad pad;  // N140 [G]: nine dead 16-byte slots (retail frame 0x100)
    field_B4 = 0.0f;
    field_B8 = 1.0f;
    field_BC = 0.0f;
    field_C0 = 1.0f;
    field_130 = 0;
    UnkStruct_00173950_rec *rec = (UnkStruct_00173950_rec *)((char *)&D_00522660.field_0[field_114->field_49] + 0x34210);
    field_70 = rec->field_0;
    CGtV3d up = field_70.mUp * field_120;
    CGtV3d off = field_70.mAt * 1.5f;
    CGtV3d pos = field_70.mPos;
    pos += up;
    field_70.mPos = pos;
    field_60 = pos;
    field_0.field_0.SetGtV3d(func_00173950_inl1(pos, off));
    field_70.mPos = func_00173950_inl1(CGtV3d(field_0.field_0.mData), field_70.mAt * field_150);
    field_30.field_0.SetGtV3d(func_00173950_inl2(field_70.mPos, field_70.mAt * field_14C));
    field_0.InitalisePosition(this);
    field_30.InitalisePosition(this);
    field_70.mAt = CGtV3d(field_0.field_0.mData) - CGtV3d(field_30.field_0.mData);
    if (field_70.mAt.IsZero()) {
        field_70.mAt = rec->field_0.mAt;
    } else if (field_70.mAt.NormaliseGetLength() == 0.0f) {
        field_70.mAt = rec->field_0.mAt;
    }
    CGtV3d p2 = CGtV3d(field_0.field_0.mData);
    p2 -= field_70.mAt * field_150;
    field_70.mPos = p2;
    field_70.mUp = func_00173950_inl4(field_0.field_10, field_30.field_10);
    if (field_70.mUp.NormaliseGetLength() == 0.0f) field_70.mUp.SetY(1.0f);
    field_70.mRight = func_00173950_inl5(field_70.mUp, field_70.mAt);
    if (field_70.mRight.NormaliseGetLength() == 0.0f) field_70.mRight.SetX(1.0f);
    field_70.mUp = func_00173950_inl5(field_70.mAt, field_70.mRight);
    if (field_70.mUp.NormaliseGetLength() == 0.0f) field_70.mUp.SetY(1.0f);
    if (field_110) field_110->InitaliseTrailerPosition();
}
#pragma pop
