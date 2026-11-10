// NONMATCHING: func_0023C520 -- retail 754 / ours 763 instructions, 703 in changed runs
// retail 754 / ours 763; own code exact in both loop heads and loop 1's velocity/matrix part (slices 0 diff); residue: inlined CGtMatrix3x4::operator* operand shape (retail m rows vf5/vf4/vf2, this.mPos reused in vf3), OrthoNormalise rebuild blocks deferred to the function end in retail + lane compares sqc2 vs sq, loop-1 lookup's cb=0 blocks placed before the velocity code (retail: after the loop's continue block; the continue-form puts the velocity head out of line instead); local stand-ins: gapH's Invert + operator*(Y/ZAxisType), j-operand operator+
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: every call, branch, store and VU op accounted for; calls identical

// func_0023C520 -- drafted by draftD (2026-10-31) from retail asm + Ghidra. Unnamed at this address in every table, so the
// asm label with C linkage. [G] it is the E-build (dnat map) CB3NetworkPlayer::StickValuesIntoCrashingTrafficPhysics()
// (0xCE8 there vs 0xBC8 here; the retail unit's next function func_0023D410 0xFA4 ~ ApplyTrafficCarData 0xFAC, which calls
// func_001A8800 ~ RetrieveCrashingTraffic) -- name in comments only. Per crashing-traffic entry (0xC0 bytes from +0x3CE0): look
// the traffic car up (func_0023D0F0's proven lookup shape), then push the received matrix / velocities into its physics body.
// Every struct below is a placeholder; types [G] from instruction widths.
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;
using GtMathPs2::CGtV3dPlus;
using GtMathPs2::CGtMatrix3x4;

struct UnkStruct_0023C520_cb;
struct UnkStruct_0023C520_pt { unsigned char pad_0[0x2429]; unsigned char field_2429; };
struct UnkStruct_0023C520_cb {
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;            // inverse of *field_204
    CGtV3dPlus field_B0;              // xyz velocity, w speed
    CGtV3d field_C0;                  // unit velocity direction
    CGtV3d field_D0;                  // second vector (angular velocity?)
    unsigned char pad_E0[0x124];
    CGtMatrix3x4 *field_204;          // world matrix
    unsigned char pad_208[0x221C];
    UnkStruct_0023C520_pt *field_2424;
};
struct UnkStruct_0023C520_car { signed char field_0; unsigned char pad_1[0xB]; UnkStruct_0023C520_cb *field_C; };
struct UnkStruct_0023C520_ent {
    unsigned char pad_0[0x3CE0];
    CGtMatrix3x4 field_3CE0;          // absolute matrix
    CGtMatrix3x4 field_3D20;          // relative matrix (applied to the current one)
    CGtV3d field_3D60;                // velocity
    CGtV3d field_3D70;
    CGtV3d field_3D80;                // position offset
    unsigned char field_3D90;         // traffic vehicle id
    unsigned char field_3D91;         // 0: absolute, else relative
};
struct UnkStruct_0023C520 {
    unsigned char pad_0[0x4EE0];
    int field_4EE0;                   // entry count
    int field_4EE4;
    unsigned char field_4EE8;
};
struct UnkStruct_D_00527440 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
class CB3TrafficSystem { public: bool VehicleIsValid(unsigned char p0); };
extern UnkStruct_D_00527440 D_00527440;
extern UnkStruct_D_00522660 D_00522660;

// as func_0023D0F0_inl1 (proven)
static inline UnkStruct_0023C520_car *func_0023C520_inl1(unsigned char id)
{
    if (((CB3TrafficSystem *)&D_00527440)->VehicleIsValid(id)) {
        return *(UnkStruct_0023C520_car **)((char *)&D_00522660 + (id & 0xFF) * 0x180 + 0x1771C);
    }
    return 0;
}
// [L] gapH's proposed CGtV3d::operator*(YAxisType) / operator*(ZAxisType) (B3O0PCH map names), local until they land
static inline CGtV3d func_0023C520_inl6(const CGtV3d &v, GtMathPs2::YAxisType a) { u_long128 r; asm("vmuly.xyz %0, %1, %2y" : "=j"(r) : "j"(v.mData), "j"(a.lVector)); return CGtV3d(r); }
static inline CGtV3d func_0023C520_inl7(const CGtV3d &v, GtMathPs2::ZAxisType a) { u_long128 r; asm("vmulz.xyz %0, %1, %2z" : "=j"(r) : "j"(v.mData), "j"(a.lVector)); return CGtV3d(r); }
// [L] gapH's proposed CGtMatrix3x4::Invert() body (build/vt/gapH/inc_IG), local until it lands in the header
static inline void func_0023C520_inl2(CGtMatrix3x4 &M)
{
    CGtV3d lRight = M.mRight;
    CGtV3d lUp = M.mUp;
    CGtV3d lAt = M.mAt;
    M.mRight.SetY(lUp.X());
    M.mRight.SetZ(lAt.X());
    M.mUp.SetX(lRight.Y());
    M.mUp.SetZ(lAt.Y());
    M.mAt.SetX(lRight.Z());
    M.mAt.SetY(lUp.Z());
    CGtV3d lPos = M.mPos;
    CGtV3d lZ = func_0023C520_inl7(M.mAt, lPos.Z());
    CGtV3d lX = M.mRight * lPos.X();
    CGtV3d lResult;
    lResult = lX + func_0023C520_inl6(M.mUp, lPos.Y());
    lResult += lZ;
    M.mPos = -lResult;
}
// [L] N185 stand-in: CGtV3d + CGtV3d on compiler-chosen registers (retail `vadd.xyz $vf2, $vf3, $vf2`; header operator+ is
// the fixed $vf1/$vf2 body)
static inline CGtV3d func_0023C520_inl3(const CGtV3d &a, const CGtV3d &b)
{
    u_long128 r;
    asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData));
    return CGtV3d(r);
}

#define ENT(i) ((UnkStruct_0023C520_ent *)((char *)self + (i) * 0xC0))

static inline bool func_0023C520_inl4(UnkStruct_0023C520 *self, UnkStruct_0023C520_cb *cb)
{
    int j;
    for (j = 0; j < self->field_4EE0; j++) {
        if (ENT(j)->field_3D90 == cb->field_2424->field_2429) break;
    }
    return j < self->field_4EE0;
}

// 0x0023C520
extern "C" void func_0023C520(UnkStruct_0023C520 *self)
{
    int i;
    int j;
    UnkStruct_0023C520_ent *e;
    UnkStruct_0023C520_cb *cb;
    unsigned char id;
    if (self->field_4EE8) {
        self->field_4EE8 = 0;
        for (i = 0; i < self->field_4EE0; i++) {
            e = ENT(i);
            id = e->field_3D90;
            UnkStruct_0023C520_car *c = func_0023C520_inl1(id);
            if (c != 0) {
                if (c->field_0 == 4) cb = c->field_C; else cb = 0;
            } else cb = 0;
            if (cb == 0) continue;
            if (cb->field_2424 == 0 || func_0023C520_inl4(self, cb)) {
            CGtV3d v = e->field_3D60;
            cb->field_B0.SetGtV3d(v);
            if (v.GetSquaredLength() < 2.3283064e-10f) {
                cb->field_B0.SetPlus(0.0f);
                cb->field_C0 = cb->field_204->mAt;
            } else {
                cb->field_C0 = v;
                cb->field_B0.SetPlus(cb->field_C0.NormaliseGetLength());
            }
            cb->field_D0 = e->field_3D70;
            if (e->field_3D91 == 0) {
                *cb->field_204 = e->field_3CE0;
                cb->field_70 = *cb->field_204;
                func_0023C520_inl2(cb->field_70);
            }
            }
        }
    }
    if (self->field_4EE4 > 0) {
        for (i = 0; i < self->field_4EE0; i++) {
            e = ENT(i);
            if (e->field_3D91 == 0) continue;
            id = e->field_3D90;
            UnkStruct_0023C520_car *c = func_0023C520_inl1(id);
            if (c != 0) {
                if (c->field_0 == 4) cb = c->field_C; else cb = 0;
            } else cb = 0;
            if (cb == 0) continue;
            CGtMatrix3x4 *p = cb->field_204;
            CGtMatrix3x4 L;
            L = *p * e->field_3D20;
            L.mPos = func_0023C520_inl3(p->mPos, e->field_3D80);
            L.OrthoNormalise();
            *cb->field_204 = L;
            cb->field_70 = *cb->field_204;
            func_0023C520_inl2(cb->field_70);
        }
        self->field_4EE4--;
    }
}
