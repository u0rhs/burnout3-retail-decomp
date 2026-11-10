// NONMATCHING: Prepare__17CB3VehiclePhysicsFP25CB3VehicleEssentialParamsP16CB3VehicleParams -- retail 593 / ours 584 instructions, 558 in changed runs
// draftAH C-first: body reset, wheel set-up, deform prepare, sphere/box, hull copy (proven func_001CBA30 layout) + Initialise, hinged-part inverse inertia (box half extents, R^T I R), state resets; 584/593, calls identical, every VU op count equal; left lq/lqc2 class (21/26, 29/23), sqc2 36/32, frame 0x5B0 vs 0x560
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm with Revenge STABS (bool return, param/local names); body part layout = archived func_001CFE40's CB3HingedPart; tensor stand-ins from it; per-kind op counts equal for every VU op and lw/lb

// CB3VehiclePhysics::Prepare(CB3VehicleEssentialParams*, CB3VehicleParams*) -- draftAH (C-first draft; the lifter refused it).
// 0x1CF2B0, 0x944. [C] name: retail symbol table. Revenge counterpart Prepare__17CB4VehiclePhysicsP25CB4VehicleEssentialParams
// P16CB4VehicleParams (STABS, B4VehiclePhysics.cpp, 279 instrs: bool return; lpEssentialParams, lpVehicleParams, lnWheel,
// lnBodyPartIndex, lrRadius) [L]. Written from the retail asm.
// What it does [L]: the colliding-body reset (func_001AD380, draftAG's archive), then keep the two parameter blocks, take the
// wheel count and per-wheel set-up (func_001D0A90 on each wheel, its params row, radius), clear the unused wheel slots up to 6,
// prepare the deform object, set the bounding sphere / box, copy the convex hull record (as the proven func_001CBA30) and
// initialise it, then each hinged body part: reset (inverse-inertia world tensor from the identity, zero state, mass 260),
// mass from the vehicle data, its matrix from the params, inverse inertia of a box with the part's half extents
// (I = 0.5 m (b^2 + c^2) per axis, inverted per lane), world tensor = R^T I R; then the per-car state resets. Returns true.
// Layouts: hull and body part as the proven func_001CBA30 / the archived func_001CFE40 (CB3HingedPart [L]). Types [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;
extern "C" void *memset(void *, int, unsigned int);

// [L] GtMathPs2::CGtMatrix3x3 with the B3O0PCH map's ctors (as func_001CFE40's UnkStruct_001AC470_m33)
struct UnkStruct_001CF2B0_m33 {
    CGtV3d mRight, mUp, mAt;
    UnkStruct_001CF2B0_m33() {}
    UnkStruct_001CF2B0_m33(const UnkStruct_001CF2B0_m33& m) { UnkStruct_001CF2B0_m33& r = (*this = m); }
};
// [G] stand-ins (queued with func_001CFE40's): CGtMatrix3x3::operator* row product, operator*, CGtV3d::Set(X,X,X) family,
// CB3Tensor::GetTranspose() -- copied from func_001CFE40's archive
static inline CGtV3d func_001CF2B0_inl12(const UnkStruct_001CF2B0_m33& m, CGtV3d v) {
    u_long128 t;
    asm("vmulax.xyz $ACC, %0, %1x" : : "j"(m.mRight.mData), "j"(v.mData));
    asm("vmadday.xyz $ACC, %0, %1y" : : "j"(m.mUp.mData), "j"(v.mData));
    asm("vmaddz.xyz $vf1, %1, %2z" "\n\t" "qmfc2.i %0, $vf1" : "=r"(t) : "j"(m.mAt.mData), "j"(v.mData));
    return CGtV3d(t);
}
static inline UnkStruct_001CF2B0_m33 func_001CF2B0_inl2(const UnkStruct_001CF2B0_m33& a, const UnkStruct_001CF2B0_m33& b) {
    UnkStruct_001CF2B0_m33 r;
    r.mRight = func_001CF2B0_inl12(b, a.mRight);
    r.mUp = func_001CF2B0_inl12(b, a.mUp);
    r.mAt = func_001CF2B0_inl12(b, a.mAt);
    return r;
}
static inline void func_001CF2B0_inl3(CGtV3d& d, XAxisType a, XAxisType b, XAxisType c) {
    asm("vaddx.x %0, $vf0, %1x" "\n\t" "vaddx.y %0, $vf0, %2x" "\n\t" "vaddx.z %0, $vf0, %3x" : "+j"(d.mData) : "j"(a.lVector), "j"(b.lVector), "j"(c.lVector));
}
static inline void func_001CF2B0_inl4(CGtV3d& d, YAxisType a, YAxisType b, YAxisType c) {
    asm("vaddy.x %0, $vf0, %1y" "\n\t" "vaddy.y %0, $vf0, %2y" "\n\t" "vaddy.z %0, $vf0, %3y" : "+j"(d.mData) : "j"(a.lVector), "j"(b.lVector), "j"(c.lVector));
}
static inline void func_001CF2B0_inl5(CGtV3d& d, ZAxisType a, ZAxisType b, ZAxisType c) {
    asm("vaddz.x %0, $vf0, %1z" "\n\t" "vaddz.y %0, $vf0, %2z" "\n\t" "vaddz.z %0, $vf0, %3z" : "+j"(d.mData) : "j"(a.lVector), "j"(b.lVector), "j"(c.lVector));
}
static inline UnkStruct_001CF2B0_m33 func_001CF2B0_inl6(const UnkStruct_001CF2B0_m33& m) {
    UnkStruct_001CF2B0_m33 t;
    func_001CF2B0_inl3(t.mRight, m.mRight.X(), m.mUp.X(), m.mAt.X());
    func_001CF2B0_inl4(t.mUp, m.mRight.Y(), m.mUp.Y(), m.mAt.Y());
    func_001CF2B0_inl5(t.mAt, m.mRight.Z(), m.mUp.Z(), m.mAt.Z());
    return t;
}

// [G] 0x600-byte convex hull record (as the proven func_001CBA30's UnkStruct_001CBA30_hull)
struct UnkStruct_001CF2B0_hull {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
    signed char field_1C[0x78] __attribute__((aligned(4)));  // [G] array starts 4-aligned (0x1B not copied)
    u_long128 field_A0[0x28];
    u_long128 field_320[0x16];
    signed char field_480[0x78];
    int field_4F8[0x42];
};
struct UnkStruct_001CF2B0_box { CGtV3d field_0; CGtV3d field_10; };   // [L] CGtAxisAlignedBox (mSup, mInf)
struct UnkStruct_001CF2B0_40 {              // the vehicle data block (essential params +0x40)
    unsigned char pad_0[0xC];
    signed char field_C;                    // hinged body part count
    signed char field_D;                    // wheel count
    unsigned char pad_E[0x6];
    float field_14;                         // bounding sphere radius
    unsigned char pad_18[0xAE4];
    float field_AFC[6];                     // body part masses [G]
    unsigned char pad_B14[0x36C];
    UnkStruct_001CF2B0_box field_E80;       // bounding box
    UnkStruct_001CF2B0_box field_EA0[6];    // body part boxes [G]
    unsigned char pad_F60[0x100];
    UnkStruct_001CF2B0_hull field_1060;
};
class CB3VehicleEssentialParams {
public:
    unsigned char pad_0[0x40];
    UnkStruct_001CF2B0_40 * field_40;
};
struct UnkStruct_001CF2B0_wp { CGtV3d field_0; CGtV3d field_10; unsigned char pad_20[0x20]; };   // per-wheel params row
class CB3VehicleParams {
public:
    UnkStruct_001CF2B0_wp field_0[6];
    CGtMatrix3x4 field_180[6];              // body part matrices
    unsigned char field_300[0x190];         // the deform object
    CGtV3dPlus field_490;
    unsigned char pad_4A0[0x30];
    float field_4D0[6];                     // wheel radii [G]
    unsigned char pad_4E8[0xB08];
    CGtV4d field_FF0;
    CGtV4d field_1000;
    unsigned char pad_1010[0x4];
    unsigned char field_1014;
    unsigned char field_1015;
    unsigned char field_1016;
    unsigned char field_1017;
    unsigned char field_1018;
    unsigned char field_1019;
    unsigned char field_101A;
    unsigned char pad_101B[0x8];
    unsigned char field_1023;
    int field_1024;
};
struct UnkStruct_001CF2B0_w {               // wheel, stride 0xC0 (at +0x820)
    unsigned char pad_0[0x50];
    float field_50;                         // radius (ResetOnTrack's field_870[i].field_0)
    unsigned char pad_54[0x18];
    float field_6C;
    float field_70;
    int field_74;
    unsigned char pad_78[0x48];
};
struct UnkStruct_001CF2B0_bp {              // [L] CB3HingedPart (Revenge CB4HingedPartPhysics), as func_001CFE40's
    UnkStruct_001CF2B0_m33 field_0;         // [L] inverse inertia tensor, local
    UnkStruct_001CF2B0_m33 field_30;        // [L] inverse inertia tensor, world
    CGtV3d field_60;
    CGtV3d field_70;
    CGtV3d field_80;
    CGtV3d field_90;
    CGtV3d field_A0;
    float field_B0;
    float field_B4;                         // mass [G]
    CGtMatrix3x4 *field_B8;                 // [L] matrix
    int field_BC;
};

class CB3VehiclePhysics {
public:
    bool Prepare(CB3VehicleEssentialParams *, CB3VehicleParams *);

    unsigned char pad_0[0x1C0];
    CGtSphere field_1C0;                    // [L] mBoundingSphere
    UnkStruct_001CF2B0_box field_1D0;       // [L] mBoundingBox
    unsigned char pad_1F0[0x8];
    int field_1F8;
    unsigned char pad_1FC[0x8];
    CGtMatrix3x4 *field_204;
    UnkStruct_001CF2B0_hull *field_208;
    unsigned char field_20C;
    unsigned char pad_20D[0x13];
    UnkStruct_001CF2B0_hull field_220;
    UnkStruct_001CF2B0_w field_820[6];
    unsigned char pad_CA0[0x20];
    CB3VehicleEssentialParams *field_CC0;
    CB3VehicleParams *field_CC4;
    UnkStruct_001CF2B0_wp *field_CC8[6];
    UnkStruct_001CF2B0_bp field_CE0[6];
    unsigned short field_1160;
    unsigned char pad_1162[0x2];
    int field_1164;
    unsigned char field_1168;
    signed char field_1169;                 // wheel count
    signed char field_116A;
    unsigned char field_116B;
    unsigned char pad_116C[0x44];
    unsigned char field_11B0[0x20];
    unsigned char field_11D0[0x180];
    unsigned char field_1350;
    unsigned char field_1351;
    unsigned char pad_1352[0x1];
    unsigned char field_1353;
    unsigned char field_1354;
};

extern "C" bool func_001AD380(CB3VehiclePhysics *);           // [L] CB3CollidingBody reset (draftAG archive)
extern "C" void func_001D0A90(UnkStruct_001CF2B0_w *);        // wheel set-up (proven, placeholder)
extern "C" void Prepare__16CB3VehicleDeformFP25CB3VehicleEssentialParamsP16CB3VehicleParams(void *, CB3VehicleEssentialParams *, CB3VehicleParams *);
extern "C" void Initialise__20CB3ConvexHullVehicleFv(void *);

// [G] header gap (queued with DrawGlobeHalo's): -ZAxisType as retail's `vsub.z D, $vf0, S` (the header's operator-() multiplies by -1)
static inline ZAxisType func_001CF2B0_inl8(ZAxisType a) { u_long128 r; asm("vsub.z %0, $vf0, %1" : "=j"(r) : "j"(a.lVector)); return ZAxisType(r); }
// [G] the transpose of a rotation as copies of the rows with the off-diagonal lanes swapped in (CGtMatrix3x4::Invert's
// transposition; retail's second transpose here, while the identity's is GetTranspose's full-lane form)
static inline UnkStruct_001CF2B0_m33 func_001CF2B0_inl9(const UnkStruct_001CF2B0_m33& m) {
    UnkStruct_001CF2B0_m33 t = m;
    t.mRight.SetY(m.mUp.X());
    t.mRight.SetZ(m.mAt.X());
    t.mUp.SetX(m.mRight.Y());
    t.mUp.SetZ(m.mAt.Y());
    t.mAt.SetX(m.mRight.Z());
    t.mAt.SetY(m.mUp.Z());
    return t;
}

// [G] the body part reset: the world tensor from the identity orientation, zero state, mass 260, no matrix
static inline void func_001CF2B0_inl7(UnkStruct_001CF2B0_bp &bp)
{
    UnkStruct_001CF2B0_m33 lRot;
    lRot.mRight.SetX(1.0f);
    lRot.mRight.SetY(0.0f);
    lRot.mRight.SetZ(0.0f);
    lRot.mUp.SetX(0.0f);
    lRot.mUp.SetY(1.0f);
    lRot.mUp.SetZ(0.0f);
    lRot.mAt.SetX(0.0f);
    lRot.mAt.SetY(0.0f);
    lRot.mAt.SetZ(1.0f);
    bp.field_30 = func_001CF2B0_inl2(func_001CF2B0_inl6(lRot), bp.field_0);
    bp.field_30 = func_001CF2B0_inl2(bp.field_30, lRot);
    bp.field_60.Zero();
    bp.field_70.Zero();
    bp.field_80.Zero();
    bp.field_90.Zero();
    bp.field_A0.Zero();
    bp.field_B0 = 0.0f;
    bp.field_B4 = 260.0f;
    bp.field_B8 = 0;
    bp.field_BC = 0;
}

// 0x001CF2B0
bool CB3VehiclePhysics::Prepare(CB3VehicleEssentialParams * lpEssentialParams, CB3VehicleParams * lpVehicleParams)
{
    func_001AD380(this);
    field_CC4 = lpVehicleParams;
    field_CC0 = lpEssentialParams;
    field_204 = (CGtMatrix3x4 *)field_CC0;
    field_1169 = field_CC0->field_40->field_D;
    int lnWheel;
    for (lnWheel = 0; lnWheel < field_1169; lnWheel++) {
        func_001D0A90(&field_820[lnWheel]);
        field_CC8[lnWheel] = &lpVehicleParams->field_0[lnWheel];
        field_820[lnWheel].field_70 = field_CC8[lnWheel]->field_0.X();
        field_820[lnWheel].field_6C = field_CC8[lnWheel]->field_10.Y();
        field_820[lnWheel].field_50 = lpVehicleParams->field_4D0[lnWheel];
    }
    for (; lnWheel < 6; lnWheel++)
        field_820[lnWheel].field_74 = 0;
    Prepare__16CB3VehicleDeformFP25CB3VehicleEssentialParamsP16CB3VehicleParams(field_CC4->field_300, field_CC0, field_CC4);
    field_20C = 2;
    field_1C0.SetPosition(CGtV3d(0.0f, 0.0f, 0.0f));
    field_1C0.SetRadius(lpEssentialParams->field_40->field_14);
    field_1D0 = lpEssentialParams->field_40->field_E80;
    field_220 = lpEssentialParams->field_40->field_1060;
    Initialise__20CB3ConvexHullVehicleFv(&field_220);
    field_20C = 2;
    field_208 = &field_220;
    memset(field_CE0, 0, sizeof(field_CE0));
    for (int lnBodyPartIndex = 0; lnBodyPartIndex < field_CC0->field_40->field_C; lnBodyPartIndex++) {
        UnkStruct_001CF2B0_bp &bp = field_CE0[lnBodyPartIndex];
        func_001CF2B0_inl7(bp);
        bp.field_B0 = lpEssentialParams->field_40->field_AFC[lnBodyPartIndex];
        bp.field_B8 = &lpVehicleParams->field_180[lnBodyPartIndex];
        bp.field_BC = 0;
        const UnkStruct_001CF2B0_box &b = field_CC0->field_40->field_EA0[lnBodyPartIndex];
        float x = GtMath::Max(b.field_0.X(), -b.field_10.X());
        float y = GtMath::Max(b.field_0.Y(), -b.field_10.Y());
        float z = GtMath::Max(b.field_0.Z(), func_001CF2B0_inl8(b.field_10.Z()));
        float x2 = x * x;
        float y2 = y * y;
        float z2 = z * z;
        CGtV3d lInertia;
        lInertia.SetX(0.5f * (bp.field_B4 * (y2 + z2)));
        lInertia.SetX(1.0f / (float)lInertia.X());  // [C] retail FPU form, not a VU lane op: 0x1CF878 / 0x1CF8A0 / 0x1CF8C4 div.s (the cast keeps the port's PS2 float model)
        lInertia.SetY(0.5f * (bp.field_B4 * (x2 + z2)));
        lInertia.SetY(1.0f / (float)lInertia.Y());  // [C] retail FPU form, not a VU lane op: 0x1CF878 / 0x1CF8A0 / 0x1CF8C4 div.s (the cast keeps the port's PS2 float model)
        lInertia.SetZ(0.5f * (bp.field_B4 * (x2 + y2)));
        lInertia.SetZ(1.0f / (float)lInertia.Z());  // [C] retail FPU form, not a VU lane op: 0x1CF878 / 0x1CF8A0 / 0x1CF8C4 div.s (the cast keeps the port's PS2 float model)
        bp.field_0.mRight.SetX(lInertia.X());
        bp.field_0.mRight.SetY(0.0f);
        bp.field_0.mRight.SetZ(0.0f);
        bp.field_0.mUp.SetX(0.0f);
        bp.field_0.mUp.SetY((float)lInertia.Y());
        bp.field_0.mUp.SetZ(0.0f);
        bp.field_0.mAt.SetX(0.0f);
        bp.field_0.mAt.SetY(0.0f);
        bp.field_0.mAt.SetZ((float)lInertia.Z());
        UnkStruct_001CF2B0_m33 lRot;
        lRot.mRight = bp.field_B8->mRight;
        lRot.mUp = bp.field_B8->mUp;
        lRot.mAt = bp.field_B8->mAt;
        bp.field_30 = func_001CF2B0_inl2(func_001CF2B0_inl9(lRot), bp.field_0);
        bp.field_30 = func_001CF2B0_inl2(bp.field_30, lRot);
    }
    field_116A = field_1169;
    field_CC4->field_1014 = 0;
    field_1164 = 0;
    field_1160 &= 0xFF00;
    field_1168 = 0;
    field_1F8 = 0;
    field_CC4->field_490.SetGtV3d(CGtV3d(0.0f, 0.0f, 0.0f));
    field_CC4->field_490.SetPlus(9999);
    memset(field_11D0, 0, sizeof(field_11D0));
    field_1350 = 0;
    field_1351 = 0;
    field_CC4->field_1016 = 0;
    field_CC4->field_1024 = 0;
    field_CC4->field_1023 = 0;
    field_CC4->field_1015 = 0;
    field_CC4->field_1017 = 0;
    field_CC4->field_1019 = 0;
    field_CC4->field_1018 = 0;
    field_CC4->field_101A = 0;
    field_CC4->field_FF0.Zero();
    field_CC4->field_1000.Zero();
    field_116B = 0;
    memset(field_11B0, 0, sizeof(field_11B0));
    field_1353 = 0;
    field_1354 = 0;
    return true;
}
