// NONMATCHING: SidewaysDeformation__16CB3VehicleDeformFv -- retail 2280 / ours 2229 instructions, 3354 in changed runs
// d5b3 (draft5): written from the asm; call sequence identical (31), VU/FPU op counts identical (6 CreateRotationMatrix3x4 via func_00429BE0's lane-op stand-in); left: lq/sq vs lqc2/sqc2 matrix traffic, 9 vmove extra, 4 branch shapes, frame 0x15E0 vs 0x24B0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (every call, branch and store accounted for: switch, bone push + CGtRandom, two rotate-about-pivot passes, the +0x700 / flying-bit / part loops); call sequence and math op counts identical

// CB3VehicleDeform::SidewaysDeformation() -- draft5, written from the retail asm (no Revenge counterpart).
// [L] reading: a side impact. The struck corner bone (field_184; its partner on the same side lnOther, two placeholder
// int indices into field_14's +0x700 matrices, and a front/rear flag from the switch) is pushed along field_150 by
// field_178 * field_17C * 1.2, clamped to its box; field_150.y is randomised; the diagonal bone field_185 is pushed by the
// rest when it is the partner. Then twice: the axis/angle between the bone's old and new pivot direction rotates both
// bones about the first pivot (full angle; position by the half angle; clamped); the second pass takes the smaller of
// the two bones' angles and restarts from the matrices read before the first pass. Finally the side's extra matrices
// (field_14 +0x700 [two indices], the flying bit 4 or 5, parts 0..1 or 2..n, flying bits 0 and 1) are rotated about
// their own positions.
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

enum EVirtualBoneIndex { EVirtualBoneIndex_0 };   // placeholder enumerators [G]
enum EVehicleFlyingBit { EVehicleFlyingBit_0 };   // placeholder enumerators [G]

// [G] field_14: matrices per part (flying bits from index 6, +0x180), per-part flag bytes (+0x4AC; the flying-bit
// state bytes at +0x4B2 = index 6 on), virtual-bone matrices at +0x700 (as func_003E7390 / SetVirtualBoneMatrix)
struct UnkStruct_003DE1F0_14 {
    CGtMatrix3x4 field_0[18];        // [G] count
    unsigned char pad_480[0x2C];
    signed char field_4AC[0x54];     // [G] count; [6 + i] is func_003E19C0's field_4B2[i]
    CGtMatrix3x4 field_700[8];       // [G] count
};
// [C] layout as GetFlyingObjectIndex reads it (B3VehicleDeform_003E7600.cpp)
class CB3VehicleData {
public:
    unsigned char pad_0[0xC];
    signed char field_C;
    unsigned char pad_D[0xAC4 - 0xD];
    int field_AC4[1];
};
struct UnkStruct_003DE1F0_1C { unsigned char pad_0[0x1169]; signed char field_1169; };
// [G] func_003E6C20's output: the clamp box of one bone (max corner, min corner)
struct UnkStruct_003DE1F0_box { CGtV3d field_0; CGtV3d field_10; };

class CB3VehicleDeform {
public:
    void SidewaysDeformation();
    CGtV3d GetPivotPos(EVirtualBoneIndex);
    CGtV3d GetAxisAngleBetweenAtVectors(CGtV3d, CGtV3d, float *);
    void SetVirtualBoneMatrix(EVirtualBoneIndex, CGtMatrix3x4 *);
    // [C] proven out of line at 0x3E7600 (B3VehicleDeform_003E7600.cpp); inlined here
    static int GetFlyingObjectIndex(CB3VehicleData *d, EVehicleFlyingBit bit)
    {
        int i;
        for (i = 0; i < d->field_C; i++) {
            if (bit == d->field_AC4[i]) return i;
        }
        return -1;
    }

    CGtRandom field_0;
    unsigned char pad_8[0xC];
    UnkStruct_003DE1F0_14 *field_14;
    CB3VehicleData *field_18;           // [L] GetFlyingObjectIndex's argument
    UnkStruct_003DE1F0_1C *field_1C;
    unsigned char pad_20[0x18];
    int field_38;                       // [G] flag: halve-ish (x0.75) the vertical part of the pivot directions
    unsigned char pad_3C[0x114];
    CGtV3d field_150;                   // [G] impact direction
    unsigned char pad_160[0x18];
    float field_178;                    // [G] share of the push on field_184 (the rest goes to field_185)
    float field_17C;                    // [G] push size
    unsigned char pad_180[4];
    signed char field_184;              // [G] EVirtualBoneIndex of the struck bone
    signed char field_185;              // [G] EVirtualBoneIndex of the diagonal bone
};

extern "C" void func_003E6C20(CB3VehicleDeform *self, int bone, UnkStruct_003DE1F0_box *box);
extern "C" CGtMatrix3x4 func_003E7390(CB3VehicleDeform *self, int bone);   // [G] the bone's current matrix

// [L] lane-op CreateRotationMatrix3x4 stand-in copied from src/nonmatching/func_00429BE0.cpp (ghvu22 decode)
// [L] N185 stand-in for GtMathPs2::SinCosFast(float) (GtMathPs2Trig.h body; the trig I-constants as int locals where retail's
// scheduler lets them rise, as the archived BarUpdate__14CB3HUDBoostBarFf's copy, pass3c).
static inline u_long128 func_003DE1F0_sc(float a)
{
    int k0 = 0x3FC90FDB;
    CGtV4d v;
    u_long128 w;
    u_long128 x, one, f, y, t, t2, t4, t8, c1, c3, ca, cb, cc, r;
    asm("qmtc2.ni %1, $vf1\n\tvaddx.x %0, $vf0, $vf1x" : "+j"(v.mData) : "r"(a));
    asm("vaddx.y %0, $vf0, %0x" : "+j"(v.mData));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(k0));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vsubi.xz %0, %1, $I" : "=j"(w) : "j"(v.mData));
    asm(".set reorder");
    int k3 = 0x3F000000;
    int k1 = 0xBE22F983;
    asm("vabs.xyzw %0, %1" : "=j"(x) : "j"(w));
    int k2 = 0x4B400000;
    asm(".set noreorder");
    asm("vmaxw.xyzw %0, $vf0, $vf0w" : "=j"(one));
    asm(".set reorder");
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(k1));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmulai.xyzw $ACC, %0, $I" : : "j"(x));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(k2));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmsubai.xyzw $ACC, %0, $I\n\tvmaddai.xyzw $ACC, %0, $I" : : "j"(one));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(k1));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmsubai.xyzw $ACC, %0, $I" : : "j"(x));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(k3));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmsubi.xyzw %0, %1, $I" : "=j"(f) : "j"(one));
    asm(".set reorder");
    asm("vabs.xyzw %0, %1" : "=j"(y) : "j"(f));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0x3E800000));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vsubi.xyzw %0, %1, $I" : "=j"(t) : "j"(y));
    asm(".set reorder");
    asm("vmul.xyzw %0, %1, %1" : "=j"(t2) : "j"(t));
    asm("vmul.xyzw %0, %1, %1" : "=j"(t4) : "j"(t2));
    asm("vmul.xyzw %0, %1, %1" : "=j"(t8) : "j"(t4));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0xC2992661));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(c1) : "j"(t));
    asm(".set reorder");
    asm("vmul.xyzw %0, %1, %2" : "=j"(c3) : "j"(c1), "j"(t2));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21\n\tvnop" : : "r"(0xC2255DE0));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(ca) : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(0x42A33457));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(cb) : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("nop\n\tctc2 %0, $vi21\n\tvnop" : : "r"(0x421ED7B7));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmuli.xyzw %0, %1, $I" : "=j"(cc) : "j"(t));
    asm(".set reorder");
    int k4 = 0x40C90FDA;
    asm("vmula.xyzw $ACC, %0, %1" : : "j"(ca), "j"(t2));
    asm("vmadda.xyzw $ACC, %0, %1" : : "j"(c3), "j"(t4));
    asm(".set noreorder");
    asm("ctc2 %0, $vi21" : : "r"(k4));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmadda.xyzw $ACC, %0, %1" : : "j"(cb), "j"(t4));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmaddai.xyzw $ACC, %0, $I" : : "j"(t));
    asm(".set reorder");
    asm(".set noreorder");
    asm("vmadd.xyzw %0, %1, %2" : "=j"(r) : "j"(cc), "j"(t8));
    asm(".set reorder");
    return r;
}

// [L] look-at basis (the E map's GtMathPs2::Matrix3x4SetLookAt(CGtV3d, CGtV3d) would fit; body [G]); mPos unwritten
// [L] N185 lane-op stand-ins (compiler-chosen registers) for the rotation-matrix inline below.
#define OPN(name, text) static inline u_long128 name(u_long128 a, u_long128 b) { u_long128 r; asm(text : "=j"(r) : "j"(a), "j"(b)); return r; }
#define OPI(name, text) static inline void name(u_long128 &d, u_long128 a) { asm(text : "+j"(d) : "j"(a)); }
OPN(func_003DE1F0_subyx, "vsuby.x %0, %1, %2y")
OPN(func_003DE1F0_subxx, "vsubx.x %0, %1, %2x")
OPN(func_003DE1F0_subyy, "vsuby.y %0, %1, %2y")
OPN(func_003DE1F0_subzz, "vsubz.z %0, %1, %2z")
OPN(func_003DE1F0_subzx, "vsubz.x %0, %1, %2z")
OPN(func_003DE1F0_addzz, "vaddz.z %0, %1, %2z")
OPN(func_003DE1F0_addxx, "vaddx.x %0, %1, %2x")
OPN(func_003DE1F0_addyy, "vaddy.y %0, %1, %2y")
OPN(func_003DE1F0_mul, "vmul.xyz %0, %1, %2")
OPN(func_003DE1F0_mulzy, "vmulz.y %0, %1, %2z")
OPN(func_003DE1F0_mulxz, "vmulx.z %0, %1, %2x")
OPN(func_003DE1F0_mulyx, "vmuly.x %0, %1, %2y")
OPN(func_003DE1F0_mulx, "vmulx.xyz %0, %1, %2x")
OPI(func_003DE1F0_setzx, "vaddx.z %0, $vf0, %1x")
OPI(func_003DE1F0_setxy, "vaddy.x %0, $vf0, %1y")
OPI(func_003DE1F0_setyz, "vaddz.y %0, $vf0, %1z")
OPI(func_003DE1F0_setxx, "vaddx.x %0, $vf0, %1x")
OPI(func_003DE1F0_setyy, "vaddy.y %0, $vf0, %1y")
OPI(func_003DE1F0_setxz, "vaddz.x %0, $vf0, %1z")
OPI(func_003DE1F0_setyx, "vaddx.y %0, $vf0, %1x")
OPI(func_003DE1F0_setzy, "vaddy.z %0, $vf0, %1y")
OPI(func_003DE1F0_addbx, "vaddx.xyz %0, %0, %1x")
OPI(func_003DE1F0_mulbz, "vmulz.xyz %0, %0, %1z")
static inline u_long128 func_003DE1F0_neg(u_long128 a) { u_long128 r; asm("vsub.xyz %0, $vf0, %1" : "=j"(r) : "j"(a)); return r; }
static inline u_long128 func_003DE1F0_zero() { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); return r; }

// [L] N185: the header Normalise's body as a value-returning helper reading its operand in place (retail loads the
// constant axis twice, lqc2 for the square and lq for the scale: the [G] volatile re-read pun of the proven
// B3VehiclePhysics_001CB780.cpp inl3)
static inline CGtV3d func_003DE1F0_nrmd(const CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    CGtV3d r;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vwaitq" "\n\t" "qmtc2 %1, $vf1" "\n\t" "vmulq.xyz $vf1, $vf1, $Q" "\n\t" "qmfc2 %0, $vf1" : "=r"(r.mData) : "r"(*(volatile const u_long128 *)&v.mData));
    asm(".set reorder");
    return r;
}
// [L] a rotation matrix about a unit axis (the E map's GtMathPs2::CreateRotationMatrix3x4(CGtV3d, float), 1372 bytes, would fit;
// body [G] decoded from retail 0x429E70..0x429EE8): s/c from SinCosFast, k = 1 - c,
// rows R = (1 - (1-xx)k, xy k + z s, zx k - y s), U = (xy k - z s, 1 - (1-yy)k, yz k + x s), A = (zx k + y s, yz k - x s, 1 - (1-zz)k).
static inline void func_003DE1F0_rot(CGtMatrix3x4 &m, const CGtV3d &ax, float angle)
{
    CGtV3d one;
    one.SetX(1.0f);
    CGtV3d axis = func_003DE1F0_nrmd(ax);
    u_long128 sc = func_003DE1F0_sc(angle);
    func_003DE1F0_setzx(sc, func_003DE1F0_subyx(one.mData, sc));
    u_long128 n = func_003DE1F0_neg(func_003DE1F0_mul(axis.mData, axis.mData));
    CGtV3d t;
    func_003DE1F0_setxy(t.mData, func_003DE1F0_mulzy(axis.mData, axis.mData));
    func_003DE1F0_setyz(t.mData, func_003DE1F0_mulxz(axis.mData, axis.mData));
    func_003DE1F0_addbx(n, one.mData);
    func_003DE1F0_setzx(t.mData, func_003DE1F0_mulyx(axis.mData, axis.mData));
    func_003DE1F0_mulbz(n, sc);
    u_long128 as = func_003DE1F0_mulx(axis.mData, sc);
    func_003DE1F0_mulbz(t.mData, sc);
    func_003DE1F0_setxx(m.mRight.mData, func_003DE1F0_subxx(one.mData, n));
    func_003DE1F0_setyz(m.mRight.mData, func_003DE1F0_addzz(t.mData, as));
    func_003DE1F0_setzy(m.mRight.mData, func_003DE1F0_subyy(t.mData, as));
    func_003DE1F0_setxz(m.mUp.mData, func_003DE1F0_subzz(t.mData, as));
    func_003DE1F0_setyx(m.mUp.mData, func_003DE1F0_subyx(one.mData, n));
    func_003DE1F0_setzx(m.mUp.mData, func_003DE1F0_addxx(t.mData, as));
    func_003DE1F0_setxy(m.mAt.mData, func_003DE1F0_addyy(t.mData, as));
    func_003DE1F0_setyx(m.mAt.mData, func_003DE1F0_subxx(t.mData, as));
    m.mPos.mData = func_003DE1F0_zero();
    func_003DE1F0_setzx(m.mAt.mData, func_003DE1F0_subzx(one.mData, n));
}
// [L] GtMathPs2::CreateRotationMatrix3x4(CGtV3d, float) (E map; header candidate, gapE): the lane-op stand-in above
static inline CGtMatrix3x4 func_003DE1F0_inl1(CGtV3d axis, float angle)
{
    CGtMatrix3x4 m;
    func_003DE1F0_rot(m, axis, angle);
    return m;
}

// [G] m rotated by r about the point p: (m - p) * r + p
static inline CGtMatrix3x4 func_003DE1F0_inl2(const CGtMatrix3x4 &m, const CGtMatrix3x4 &r, CGtV3d p)
{
    CGtMatrix3x4 t = m;
    t.mPos -= p;
    t = t * r;
    t.mPos += p;
    return t;
}

// [G] one pass: rotate both bones about lPivot by lrAngle degrees around lAxis, position by the half angle, clamped
static inline void func_003DE1F0_inl3(CB3VehicleDeform *self, int lnBoneA, int lnBoneB, const CGtMatrix3x4 &lMatA,
    const CGtMatrix3x4 &lMatB, CGtV3d lPivot, CGtV3d lAxis, float lrAngle, CGtMatrix3x4 &lRotate,
    CGtMatrix3x4 &lHalfRotate, CGtMatrix3x4 &lHalfRotate2)
{
    UnkStruct_003DE1F0_box lBox;
    CGtMatrix3x4 lMatrix;
    lRotate = func_003DE1F0_inl1(lAxis, 0.01745329238f * lrAngle);
    lHalfRotate = func_003DE1F0_inl1(lAxis, 0.01745329238f * (0.5f * lrAngle));
    lHalfRotate2 = func_003DE1F0_inl1(lAxis, 0.01745329238f * (0.5f * lrAngle));

    lMatrix = func_003DE1F0_inl2(lMatA, lRotate, lPivot);
    lMatrix.mPos = TransformVector(lHalfRotate, lMatrix.mPos);
    func_003E6C20(self, lnBoneA, &lBox);
    lMatrix.mPos = Min(lBox.field_0, Max(lBox.field_10, lMatrix.mPos));
    self->SetVirtualBoneMatrix((EVirtualBoneIndex)lnBoneA, &lMatrix);

    lMatrix = func_003DE1F0_inl2(lMatB, lRotate, lPivot);
    lMatrix.mPos = TransformVector(lHalfRotate, lMatrix.mPos);
    func_003E6C20(self, lnBoneB, &lBox);
    lMatrix.mPos = Min(lBox.field_0, Max(lBox.field_10, lMatrix.mPos));
    self->SetVirtualBoneMatrix((EVirtualBoneIndex)lnBoneB, &lMatrix);
}

// 0x003DE1F0
void CB3VehicleDeform::SidewaysDeformation()
{
    bool lbInvalid = false;
    signed char lnOther;        // [G] the other bone on the struck side
    bool lbFront;               // [G] meaning of the 0/1 cases
    int lnExtraA;               // [G] field_14->field_700 indices rotated with the side
    int lnExtraB;
    CGtV3d lPosA;               // the struck bone's position before the pass
    CGtV3d lPosB;
    CGtMatrix3x4 lMatA;
    CGtMatrix3x4 lMatB;
    CGtMatrix3x4 lRotate;
    CGtMatrix3x4 lHalfRotate;
    CGtMatrix3x4 lHalfRotate2;
    UnkStruct_003DE1F0_box lBoxA;
    UnkStruct_003DE1F0_box lBoxB;
    float lrAngle;

    switch (field_184) {
    case 5: lnOther = 4; lbFront = false; lnExtraA = 0; lnExtraB = 6; break;
    case 1: lnOther = 0; lbFront = true;  lnExtraA = 3; lnExtraB = 7; break;
    case 4: lnOther = 5; lbFront = false; lnExtraA = 0; lnExtraB = 6; break;
    case 0: lnOther = 1; lbFront = true;  lnExtraA = 3; lnExtraB = 7; break;
    default: lbInvalid = true; break;
    }
    if (!lbInvalid) {
        lPosA = func_003E7390(this, field_184).mPos;
        func_003E7390(this, lnOther);           // [C] result unused
        lMatA = func_003E7390(this, field_184);
        lMatB = func_003E7390(this, lnOther);
    }

    // the struck bone pushed along field_150
    func_003E6C20(this, field_184, &lBoxA);
    {
        float lrScale = 1.2f * (field_17C * field_178);
        CGtV3d lDir = field_150;
        CGtMatrix3x4 lMatrix = func_003E7390(this, field_184);
        lMatrix.mPos = Min(lBoxA.field_0, Max(lBoxA.field_10, lMatrix.mPos + lDir * lrScale));
        SetVirtualBoneMatrix((EVirtualBoneIndex)field_184, &lMatrix);
    }
    {
        CGtV3d lDir = field_150;
        float lrRand = 2.3283064e-10f * field_0.Random();
        field_150.SetY(lDir.Y() * 0.3f * lrRand);
    }
    func_003E6C20(this, field_185, &lBoxB);
    float lrRand2 = 2.3283064e-10f * field_0.Random();
    float lrScale2 = 1.2f * (field_17C * (1.0f - field_178)) * lrRand2;
    if (lbInvalid) return;

    if (field_185 == lnOther) {
        CGtV3d lDir = field_150;
        CGtMatrix3x4 lMatrix = func_003E7390(this, field_185);
        lMatrix.mPos = Min(lBoxB.field_0, Max(lBoxB.field_10, lMatrix.mPos + lDir * lrScale2));
        SetVirtualBoneMatrix((EVirtualBoneIndex)field_185, &lMatrix);
    }

    // first pass: the struck bone's turn about its pivot
    CGtV3d lPivot = GetPivotPos((EVirtualBoneIndex)field_184);
    CGtV3d lPivotB = GetPivotPos((EVirtualBoneIndex)lnOther);
    {
        CGtV3d lNewPos = func_003E7390(this, field_184).mPos;
        func_003E7390(this, lnOther);           // [C] result unused
        CGtV3d lFrom = lPosA - lPivot;
        CGtV3d lTo = lNewPos - lPivot;
        if (field_38 != 0) {
            lFrom.SetY(lFrom.Y() * 0.75f);
            lTo.SetY(lTo.Y() * 0.75f);
        }
        CGtV3d lAxis = GetAxisAngleBetweenAtVectors(lFrom, lTo, &lrAngle);
        lPosA = func_003E7390(this, field_184).mPos;
        lPosB = func_003E7390(this, lnOther).mPos;
        lMatA = func_003E7390(this, field_184);
        lMatB = func_003E7390(this, lnOther);
        func_003DE1F0_inl3(this, field_184, lnOther, lMatA, lMatB, lPivot, lAxis, lrAngle, lRotate, lHalfRotate, lHalfRotate2);
    }

    // second pass: the smaller of the two bones' turns, from the matrices read before the first pass
    {
        CGtV3d lNewPosA = func_003E7390(this, field_184).mPos;
        CGtV3d lNewPosB = func_003E7390(this, lnOther).mPos;
        float lrAngleA, lrAngleB;
        CGtV3d lFrom = lPosA - lPivot;
        CGtV3d lTo = lNewPosA - lPivot;
        if (field_38 != 0) {
            lFrom.SetY(lFrom.Y() * 0.75f);
            lTo.SetY(lTo.Y() * 0.75f);
        }
        CGtV3d lAxisA = GetAxisAngleBetweenAtVectors(lFrom, lTo, &lrAngleA);
        lFrom = lPosB - lPivotB;
        lTo = lNewPosB - lPivotB;
        if (field_38 != 0) {
            lFrom.SetY(lFrom.Y() * 0.75f);
            lTo.SetY(lTo.Y() * 0.75f);
        }
        CGtV3d lAxisB = GetAxisAngleBetweenAtVectors(lFrom, lTo, &lrAngleB);
        CGtV3d lAxis;
        if (lrAngleB < lrAngleA) {
            lAxis = lAxisB;
            lrAngle = lrAngleB;
        } else {
            lAxis = lAxisA;
            lrAngle = lrAngleA;
        }
        func_003DE1F0_inl3(this, field_184, lnOther, lMatA, lMatB, lPivot, lAxis, lrAngle, lRotate, lHalfRotate, lHalfRotate2);
    }

    // the side's other matrices about their own positions
    field_14->field_700[lnExtraA] = func_003DE1F0_inl2(field_14->field_700[lnExtraA], lHalfRotate, field_14->field_700[lnExtraA].mPos);
    field_14->field_700[lnExtraB] = func_003DE1F0_inl2(field_14->field_700[lnExtraB], lHalfRotate, field_14->field_700[lnExtraB].mPos);
    {
        int i = GetFlyingObjectIndex(field_18, (EVehicleFlyingBit)(lbFront ? 4 : 5));
        if (i >= 0 && field_14->field_4AC[6 + i] != 3 && field_14->field_4AC[6 + i] != 4) {
            CGtMatrix3x4 &m = field_14->field_0[6 + i];
            m = func_003DE1F0_inl2(m, lHalfRotate, m.mPos);
            m.mPos = TransformVector(lHalfRotate, m.mPos);
        }
    }
    {
        int lnStart, lnCount;
        if (lbFront) {
            lnStart = 0;
            lnCount = 2;
        } else {
            lnStart = 2;
            lnCount = 2;
            if (field_1C) lnCount = field_1C->field_1169 - 2;
        }
        for (int n = 0; n < lnCount; n++, lnStart++) {
            if (field_14->field_4AC[lnStart] == 0) {
                CGtMatrix3x4 &m = field_14->field_0[lnStart];
                m = func_003DE1F0_inl2(m, lRotate, m.mPos);
            }
        }
    }
    if (!lbFront) return;
    int laBits[2] = { 0, 1 };       // [C] .sdata D_004E1EA0/4 (EVehicleFlyingBit values)
    for (int j = 0; j < 2; j++) {
        int i = GetFlyingObjectIndex(field_18, (EVehicleFlyingBit)laBits[j]);
        if (i >= 0 && field_14->field_4AC[6 + i] != 3 && field_14->field_4AC[6 + i] != 4) {
            CGtMatrix3x4 &m = field_14->field_0[6 + i];
            m = func_003DE1F0_inl2(m, lHalfRotate2, m.mPos);
        }
    }
}
