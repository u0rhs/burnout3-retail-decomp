// NONMATCHING: ImpactBody__16CB3VehicleDeformFv -- retail 1709 / ours 1718 instructions, 1800 in changed runs
// draftG: calls identical except layout (loop+UpdateAttachState block placed before the bones block, the two RotateBoneLookAtOppositeBoneInY copies out of line) and the out-of-line XAxisType(u_long128) (= retail func_0023E3D0, reproduced x2 by a scoped inline_depth(6) [G] + a one-level-deeper SetLookAt normalise stand-in); left: that block layout, roof-test andi, vmove copies, lq/lqc2 folding, frame 0x1150 vs 0x1730
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: every call (incl. [L] DeformRoof/GetClampBox/GetVirtualBoneMatrix placeholders), branch, store and VU op accounted for; inlined IsRoofImpact / DistancesAlongLine / SetFinalMatrix / RotateBoneLookAt(+OppositeBoneInY) / Matrix3x4SetLookAt as [G] placeholders

// CB3VehicleDeform::ImpactBody() -- draftG, written from the retail asm (no Revenge counterpart).
// [L] reading: a body impact of size field_17C. Without bones (field_18->field_AC0 == 0) a random share is added to a damage
// accumulator (field_14->field_1010) and two thresholds set a state byte. With bones: a roof impact (the [G] inlined
// IsRoofImpact test) deforms the roof (func_003E5CC0, [L] DeformRoof by the E dnat file order) and the flying bits;
// otherwise the struck virtual bones are found, an IK pass bends the corner bone of the struck side (GetIKAngles, a rotation
// about X of the angle between the side vector and -Z), the side's final matrices are rebuilt, the struck bone and its
// opposite are turned to look at each other in Y, and the corner bones are re-pointed. Then the deformed hull is rebuilt when
// the vehicle asks for it, and the attach state is updated.
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Trig.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;
#pragma push
#pragma inline_depth(6)   // [G] N262/N182: leaves retail's two out-of-line XAxisType(u_long128) (func_0023E3D0)

// [G] layout from the copy loops at 0x3DD9DC..0x3DDB10 (0x600 bytes: 6 words, 3 bytes, 0x78 bytes, two CGtV3d arrays,
// 0x78 bytes, 0x42 words)
class CB3ConvexHull {
public:
    bool DeformHullVerts(CGtV3d *, CGtMatrix3x4 *) const;
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;                     // [G] flags: bit 1 = the deformed hull must be rebuilt
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
    signed char field_1C[0x78] __attribute__((aligned(4)));   // [G] starts at 0x1C: 0x1B is padding (retail copy skips it)
    CGtV3d field_A0[40];
    CGtV3d field_320[22];
    signed char field_480[0x78];
    int field_4F8[0x42];
};
class CB3ConvexHullVehicle : public CB3ConvexHull {
public:
    void Initialise();
};
struct UnkStruct_003DC730_40 {
    unsigned char pad_0[0x1060];
    CB3ConvexHull field_1060;
    unsigned char pad_1660[0x2C];
    CGtV3d *field_168C;
    unsigned char pad_1690[0x26];
    unsigned char field_16B6;
};
struct UnkStruct_003DC730_10 { unsigned char pad_0[0x40]; UnkStruct_003DC730_40 *field_40; };
// [G] field_14: final bone matrices (+0x500), virtual-bone matrices (+0x700), per-bit damage (+0xF90), damage state
struct UnkStruct_003DC730_14 {
    unsigned char pad_0[0x500];
    CGtMatrix3x4 field_500[8];
    CGtMatrix3x4 field_700[8];
    unsigned char pad_900[0x690];
    float field_F90[32];
    float field_1010;
    unsigned char field_1014;
    unsigned char field_1015;
    unsigned char field_1016;
    unsigned char pad_1017[4];
    unsigned char field_101B;
};
// [G] field_18: default bone matrices (+0x70), bind matrices (+0x570), bone count/flag (+0xAC0)
struct UnkStruct_003DC730_18 {
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70[20];
    CGtMatrix3x4 field_570[8];
    unsigned char pad_770[0x350];
    int field_AC0;
};
struct UnkStruct_003DC730_1C { unsigned char pad_0[0x220]; CB3ConvexHullVehicle field_220; };
// [G] func_003E6C20's output (E dnat order: GetClampBox(EVirtualBoneIndex, CGtAxisAlignedBox*))
struct UnkStruct_003DC730_box { CGtV3d field_0; CGtV3d field_10; };

class CB3VehicleDeform {
public:
    void ImpactBody();
    void SidewaysDeformation();
    void UpdateFlyingBits();
    void UpdateFlyingBitsBones(float, float);
    void UpdateAttachState();
    void RotateAndScaleCornerBonesToPointToRestOfCar(bool);
    void GetVirtualBones(CGtV3d, signed char *, signed char *, float *);
    bool GetIKAngles(float, float, float, float *, float *, float *, float *);
    CGtV3d GetWindscreenPos(bool, bool);
    int GetClosestBitToPoint(const CGtV3d *);
    void CreateDeformedHull(CB3ConvexHull *, CGtV3d *);

    CGtRandom field_0;
    unsigned char pad_8[8];
    UnkStruct_003DC730_10 *field_10;
    UnkStruct_003DC730_14 *field_14;
    UnkStruct_003DC730_18 *field_18;
    UnkStruct_003DC730_1C *field_1C;
    unsigned char pad_20[0x18];
    int field_38;                       // [G] flag: lower damage thresholds
    unsigned char pad_3C[9];
    unsigned char field_45;             // [G] set when the deformed hull was rebuilt
    unsigned char field_46;             // [G] flag: run the IK pass
    unsigned char pad_47[0xF9];
    CGtV3d field_140;                   // [G] impact position
    CGtV3d field_150;                   // [G] impact direction
    unsigned char pad_160[0x18];
    float field_178;
    float field_17C;                    // [G] impact size
    float field_180;
    signed char field_184;              // [G] EVirtualBoneIndex of the struck bone
    signed char field_185;
};

extern int kaeOtherMainBone[];
extern int kaeVirtualToNormalBone[];
extern CGtV3d D_01EB5B40[];             // [G] deformed hull vertices
extern "C" float func_0011E328(float);  // [L] acosf (E_B3DEBUG map: LIBM.A wf_acos.o)
extern "C" void func_003E5CC0(CB3VehicleDeform *self, float, float);   // [L] DeformRoof(float, float) (E dnat file order)
extern "C" void func_003E6C20(CB3VehicleDeform *self, int bone, UnkStruct_003DC730_box *box);   // [L] GetClampBox
extern "C" CGtMatrix3x4 func_003E7390(CB3VehicleDeform *self, int bone);   // [L] GetVirtualBoneMatrix
extern "C" void func_003DC1A0(CB3VehicleDeform *self);

// [L] N185 stand-ins: CGtV3d + and - on compiler-chosen registers (header bodies are the fixed $vf1/$vf2 forms)
static inline CGtV3d func_003DC730_inl1(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
static inline CGtV3d func_003DC730_inl2(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vsub.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
// [L] N185 stand-in: ZAxisType negation as `vsub.z d, $vf0, s` (header op- is vmulx.z by -1; queued)
static inline ZAxisType func_003DC730_inl3(const ZAxisType &z) { u_long128 r; asm("vsub.z %0, $vf0, %1" : "=j"(r) : "j"(z.lVector)); return ZAxisType(r); }
// [L] N185 stand-in for CGtV3d::NormaliseFast() (B3O0PCH map name; queued): func_001CB780_inl3's GPR/$vf1 form (proven)
static inline CGtV3d func_003DC730_inl4(const CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 one;
    CGtV3d r;
    asm(".set noreorder");
    asm("qmtc2.i %0, $vf1" : : "r"(l.lVector));
    asm("vrsqrt $Q, $vf0w, $vf1x" "\n\t" "vaddw.x $vf1, $vf0, $vf0w" "\n\t" "qmfc2.i %1, $vf1" "\n\t"
        "vwaitq" "\n\t" "qmtc2.i %2, $vf1" "\n\t" "vmulq.xyz $vf1, $vf1, $Q" "\n\t" "qmfc2.i %0, $vf1" "\n\t"
        "qmtc2.i %1, $vf1" "\n\t" "vmulq.x $vf1, $vf1, $Q" "\n\t" "qmfc2.i %1, $vf1"
        : "=&r"(r.mData), "=&r"(one) : "r"(*(volatile const u_long128 *)&v.mData));
    asm(".set reorder");
    return r;
}
static inline float func_003DC730_inl5(XAxisType x) { float f; asm("mtc1 %1, %0" : "=f"(f) : "r"(x.lVector)); return f; }
// [G] stand-in for GtMathPs2::AngleBetweenVectors(CGtV3d, CGtV3d) (B3O0PCH 0x152F30) with GtMath::ACosDeg: degrees
static inline float func_003DC730_inl6(CGtV3d a, CGtV3d b)
{
    CGtV3d an = func_003DC730_inl4(a);
    CGtV3d bn = func_003DC730_inl4(b);
    return 57.29578f * func_0011E328(func_003DC730_inl5(CosAngleBetweenNormalisedVectors(an, bn)));
}
// [G] inlined; = CB3VehicleDeform::DistancesAlongLine(CGtV3d, CGtV3d, CGtV3d, float*, float*) by the E map's API (0x13C)
static inline void func_003DC730_inl7(CGtV3d p, CGtV3d a, CGtV3d b, float *along, float *rest)
{
    CGtV3d d = func_003DC730_inl2(p, a);
    CGtV3d l = func_003DC730_inl2(b, a);
    d.SetX(0.0f);
    l.SetX(0.0f);
    float len = l.NormaliseGetLength();
    *along = DotProduct(d, l);
    *rest = len - *along;
}

// [G] N262 stand-in: Matrix3x4SetLookAt (header body) with its normalise one inline level deeper, so that a scoped
// inline_depth leaves exactly retail's one out-of-line XAxisType(u_long128) (func_0023E3D0) per call
static inline void func_003DC730_inl10(CGtV3d &v) { func_002EBED0_inl1(v); }
static inline CGtMatrix3x4 func_003DC730_inl11(CGtV3d at, CGtV3d up)
{
    CGtMatrix3x4 lReturnMatrix;
    lReturnMatrix.mAt = at;
    lReturnMatrix.mRight = CrossProduct(up, lReturnMatrix.mAt);
    func_003DC730_inl10(lReturnMatrix.mRight);
    lReturnMatrix.mUp = CrossProduct(lReturnMatrix.mAt, lReturnMatrix.mRight);
    return lReturnMatrix;
}
// [G] inlined CB3VehicleDeform::RotateBoneLookAt(EMainBodyBoneIndex, CGtV3d*) (E map API, 0x214): the bone's at row
// turned to the target, rows rebuilt by cross products, row lengths kept
static inline void func_003DC730_inl8(CB3VehicleDeform *self, int k, CGtV3d *target)
{
    CGtV3d pos = self->field_14->field_700[k].mPos;
    CGtV3d at = func_003DC730_inl2(*target, pos);
    float lr = self->field_14->field_700[k].mRight.GetLength();
    float la = self->field_14->field_700[k].mAt.GetLength();
    CGtV3d up = self->field_14->field_700[k].mUp;
    float lu = up.NormaliseGetLength();
    at.Normalise();
    CGtMatrix3x4 m = func_003DC730_inl11(at, up);
    m.mPos = pos;
    self->field_14->field_700[k] = m;
    self->field_14->field_700[k].mRight = self->field_14->field_700[k].mRight * lr;
    self->field_14->field_700[k].mUp = self->field_14->field_700[k].mUp * lu;
    self->field_14->field_700[k].mAt = self->field_14->field_700[k].mAt * la;
}
// [G] inlined CB3VehicleDeform::RotateBoneLookAtOppositeBoneInY(EMainBodyBoneIndex) (E map API, 0x160): the opposite
// bone's position with the component along this bone's right row removed
static inline void func_003DC730_inl9(CB3VehicleDeform *self, int k)
{
    CGtV3d o = self->field_14->field_700[kaeOtherMainBone[k]].mPos;
    CGtV3d diff = func_003DC730_inl2(o, self->field_14->field_700[k].mPos);
    CGtV3d r = self->field_14->field_700[k].mRight;
    r.Normalise();
    XAxisType dot = DotProduct(diff, r);
    CGtV3d s = r * dot;
    o = func_003DC730_inl2(o, s);
    func_003DC730_inl8(self, k, &o);
}

// [G] inlined CB3VehicleDeform::IsRoofImpact() (E map: emitted right after ImpactBody): the roof bone above its clamp box,
// the impact from above, between 3/4 and 1/4 of the way from bone 1's z to bone 4's
static inline bool func_003DC730_inl12(CB3VehicleDeform *self)
{
    UnkStruct_003DC730_box box;
    func_003E6C20(self, 6, &box);
    CGtV3d pos = func_003E7390(self, 6).mPos;
    CGtV3d top = box.field_10;
    bool below = !(pos.Y() > top.Y());
    if (below) return false;
    CGtV3d dir = self->field_150;
    if (!(dir.Y() < -0.5f)) return false;
    float zf = self->field_18->field_70[4].mPos.Z() * 0.75f + self->field_18->field_70[1].mPos.Z() * 0.25f;
    float zr = self->field_18->field_70[4].mPos.Z() * 0.25f + self->field_18->field_70[1].mPos.Z() * 0.75f;
    if (self->field_140.Z() > zf) return false;
    if (self->field_140.Z() < zr) return false;
    return true;
}
// [L] N185 stand-in: YAxisType negation on compiler-chosen registers (header body is the fixed $vf1 GPR form)
static inline YAxisType func_003DC730_inl13(const YAxisType &y) { u_long128 r; asm("vsub.y %0, $vf0, %1" : "=j"(r) : "j"(y.lVector)); return YAxisType(r); }
// [G] stand-in: retail passes &field_140 itself for the by-value CGtV3d (BRIEF: const void* link-name form)
extern "C" void GetVirtualBones__16CB3VehicleDeformFQ29GtMathPs26CGtV3dPScPScPf(CB3VehicleDeform *, const void *, signed char *, signed char *, float *);

// 0x003DC730
void CB3VehicleDeform::ImpactBody()
{
    if (field_17C < 0.0002f) return;
    if (field_18->field_AC0 != 0) {
        if (field_17C > 0.0f) {
            if (func_003DC730_inl12(this)) {
                func_003E5CC0(this, func_003DC730_inl13(field_150.Y()) * field_17C, func_003DC730_inl13(field_150.Y()) * 80.0f * field_180);
                UpdateFlyingBits();
            } else {
                field_14->field_101B = 1;
                GetVirtualBones__16CB3VehicleDeformFQ29GtMathPs26CGtV3dPScPScPf(this, &field_140, &field_184, &field_185, &field_178);
                int bone = kaeVirtualToNormalBone[field_184];
                int bone2 = kaeVirtualToNormalBone[field_185];
                int a, b, c;
                bool side;
                float along, rest;
                if (bone == 4 || bone == 5) {
                    a = 3; b = 7; c = 6; side = true;
                } else if (bone == 1 || bone == 2) {
                    a = 0; b = 6; c = 7; side = false;
                } else {
                    a = 8; b = a; c = a;
                }
                if (a != 8) {
                    CGtV3d w = GetWindscreenPos(side, true);
                    float al0, re0, al1, re1;
                    func_003DC730_inl7(w, field_18->field_70[bone].mPos, field_18->field_70[a].mPos, &al0, &re0);
                    func_003DC730_inl7(w, field_18->field_70[kaeOtherMainBone[bone]].mPos, field_18->field_70[a].mPos, &al1, &re1);
                    along = 0.5f * (al0 + al1);
                    rest = 0.5f * (re0 + re1);
                }
                SidewaysDeformation();
                if (field_46 && a != 8) {
                    CGtV3d mid = func_003DC730_inl1(field_14->field_700[bone].mPos, field_14->field_700[kaeOtherMainBone[bone]].mPos) * 0.5f;
                    CGtV3d d = func_003DC730_inl2(field_14->field_700[a].mPos, mid);
                    d.SetX(0.0f);
                    float len = d.NormaliseGetLength();
                    CGtV3d down;
                    down.Set(0.0f, 0.0f, -1.0f);
                    if (a == 0) d = -d;
                    CGtV3d axis;
                    axis.Set(1.0f, 0.0f, 0.0f);
                    float ang = func_003DC730_inl6(d, down);
                    if (a == 0) ang = -ang;
                    float t0, t1;
                    if (GetIKAngles(along, rest, len, 0, 0, &t0, &t1)) {
                        CGtV3d perp;
                        perp.Set(0.0f, func_003DC730_inl3(d.Z()), d.Y());
                        CGtV3d mid2 = func_003DC730_inl1(field_14->field_700[bone].mPos, field_14->field_700[kaeOtherMainBone[bone]].mPos) * 0.5f;
                        CGtV3d np = func_003DC730_inl1(mid2, func_003DC730_inl1(d * t0, perp * t1));
                        CGtMatrix3x4 rot = CreateRotationMatrix3x4(axis, 0.017453292f * ang);
                        CGtV3d at = TransformVector(rot, func_003DC730_inl2(np, field_14->field_700[a].mPos));
                        at.Normalise();
                        field_14->field_700[a].mAt = at;
                        if (a == 3) {
                            field_14->field_700[b].mAt = at;
                            float dz = field_14->field_700[b].mPos.Z() - field_14->field_700[a].mPos.Z();
                            if (dz > 0.0f) {
                                field_14->field_700[b].mPos.SetY(field_18->field_70[b].mPos.Y() + at.Y() * dz);
                                field_14->field_700[c].mPos.SetY(field_18->field_70[c].mPos.Y() + at.Y() * dz);
                            }
                        }
                    }
                }
                if (a != 8) {
                    // [G] inlined CB3VehicleDeform::SetFinalMatrix(EMainBodyBoneIndex) (E map API)
                    field_14->field_500[a] = field_18->field_570[a] * field_14->field_700[a];
                    field_14->field_500[b] = field_18->field_570[b] * field_14->field_700[b];
                    field_14->field_500[c] = field_18->field_570[c] * field_14->field_700[c];
                }
                if (!(bone != 4 && bone != 5 && bone != 1 && bone != 2)) {
                    // [G] inlined RotateBoneLookAtOppositeBoneInY(EMainBodyBoneIndex) + RotateBoneLookAt (E map APIs), twice
                    func_003DC730_inl9(this, bone);
                    func_003DC730_inl9(this, kaeOtherMainBone[bone]);
                }
                if (a != 8) RotateAndScaleCornerBonesToPointToRestOfCar(side);
                field_14->field_500[bone] = field_18->field_570[bone] * field_14->field_700[bone];
                field_14->field_500[bone2] = field_18->field_570[bone2] * field_14->field_700[bone2];
                field_14->field_500[kaeOtherMainBone[bone]] = field_18->field_570[kaeOtherMainBone[bone]] * field_14->field_700[kaeOtherMainBone[bone]];
                field_14->field_500[kaeOtherMainBone[bone2]] = field_18->field_570[kaeOtherMainBone[bone2]] * field_14->field_700[kaeOtherMainBone[bone2]];
                UpdateFlyingBits();
                UpdateFlyingBitsBones(field_17C, field_180);
            }
            if (field_10->field_40->field_1060.field_14 & 2) {
                field_45 = 1;
                field_10->field_40->field_1060.DeformHullVerts(D_01EB5B40, field_14->field_500);
                (CB3ConvexHull &)field_1C->field_220 = field_10->field_40->field_1060;
                field_1C->field_220.Initialise();
                CreateDeformedHull(&field_1C->field_220, D_01EB5B40);
            }
        }
        UnkStruct_003DC730_40 *p = field_10->field_40;
        unsigned char n = p->field_16B6;
        CGtV3d *pt = p->field_168C;
        unsigned char bit = 1;
        while (n--) {
            if (!(field_14->field_1016 & bit)) {
                CGtV3d v = *pt;
                if (field_14->field_F90[(unsigned char)GetClosestBitToPoint(&v)] > 0.3f) field_14->field_1016 |= bit;
            }
            bit = bit + bit;
        }
        UpdateAttachState();
        func_003DC1A0(this);
    } else {
        float r = 1.0f + 2.3283064e-10f * field_0.Random();
        r *= field_17C;                     // [C on this site] a separate *= keeps retail's mul.s + add.s (no madd)
        field_14->field_1010 += r;
        float lo = field_38 ? 0.02f : 0.1f;
        float hi = field_38 ? 0.05f : 0.25f;
        if (field_14->field_1010 > hi && field_14->field_1014 != 2) {
            field_14->field_1014 = 2;
            field_14->field_1015 |= 1;
        } else if (field_14->field_1010 > lo && field_14->field_1014 == 0) {
            field_14->field_1014 = 1;
        }
    }
}
