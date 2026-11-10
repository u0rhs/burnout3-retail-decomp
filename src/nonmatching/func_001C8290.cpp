// NONMATCHING: func_001C8290 -- retail 375 / ours 374 instructions, 206 in changed runs
// draftAF C-first: hinged part world collision (part x body matrix + Invert, func_002F2E70; miss: hinge angle relaxes to the limit; hit: func_001D0930 impulse into body space, angular impulse, projected contact direction vs the hinge's zero axis via AngleBetweenVectors, hard-hit timer). 374/375; calls identical (acosf = func_0011E328 by the header's name); VU op counts equal except 2 vmove.xyzw; left: two compare senses, lqc2/lq class, frame 0x1F0 vs 0x360
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block mapped (both arms, three axis cases, both angle-sign arms); per-kind op counts equal except 2 copies; one implicit-operator= row-loop set as retail (copy-init of the product)

// func_001C8290 -- draftAF (0x1C8290, 0x5DC). Unnamed in every table, so the asm label with C linkage. Called by
// CB3RaceCarPhysics::Update / LightweightUpdate and func_001CEE10 with (this, part index). [L] a hinged body part's world
// collision (the hinged-part layout of UpdateHingedPart's archive, Revenge CB4HingedPartPhysics): the part's world matrix
// (its local matrix times the body matrix) and its inverse go to func_002F2E70 (the world-triangle test CB3CollidingBody::
// CollideWithWorld also calls) with the part's hinge record. No hit: the hinge angle field_B0 relaxes toward the part's limit
// (q->field_AFC[i]) and is clamped to it. Hit: the impulse func_001D0930 computes (restitution D_004E06C0) at the contact
// is turned into body space and, when positive, added to the part's angular impulse; the contact direction projected off the
// hinge axis is measured against the hinge's zero-degree axis and the hinge angle opened toward zero by that angle; a hard
// hit (impulse > D_004E16F8) sets the part's timer in field_CC4 to 1000.
// Types and field meanings [G] (instruction widths, use).
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

struct UnkStruct_001C8870_part {    // [L] Revenge CB4HingedPartPhysics (UpdateHingedPart's archive)
    unsigned char pad_0[0x60];
    CGtV3d field_60;
    CGtV3d field_70;
    CGtV3d field_80;                // [L] mTotalImpulseAngular
    CGtV3d field_90;
    CGtV3d field_A0;
    float field_B0;                 // [L] mrMaxHingeAngle (degrees, signed)
    float field_B4;
    CGtMatrix3x4 *field_B8;         // [L] mpMatrix
    unsigned char pad_BC[4];
};
struct UnkStruct_001C8290_hinge { CGtV3d field_0; CGtV3d field_10; };   // [G] the part's two hinge points (local)
struct UnkStruct_001C8290_q {
    unsigned char pad_0[0xADC];
    unsigned char field_ADC[0x20];  // [L] per part: hinge axis 0 = x, 1 = y, 2 = z (lnAxis)
    float field_AFC[0xE9];          // [G] per part: hinge limit (degrees, signed)
    UnkStruct_001C8290_hinge field_EA0[1];
};
struct UnkStruct_001C8290_p { unsigned char pad_0[0x40]; UnkStruct_001C8290_q *field_40; };
struct UnkStruct_001C8290_t { unsigned char pad_0[0xF90]; float field_F90[1]; };
struct UnkStruct_001C8290_cache { int field_0; };
struct UnkStruct_001C8290 {
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;          // [G] world -> body
    CGtV3d field_B0;                // [G] linear velocity
    unsigned char pad_C0[0x10];
    CGtV3d field_D0;                // [G] angular velocity
    unsigned char pad_E0[0x120];
    UnkStruct_001C8290_cache *field_200;   // [G] cached world triangles (count first)
    CGtMatrix3x4 *field_204;        // [G] body matrix
    unsigned char pad_208[0xAB8];
    UnkStruct_001C8290_p *field_CC0;
    UnkStruct_001C8290_t *field_CC4;
    unsigned char pad_CC8[0x18];
    UnkStruct_001C8870_part field_CE0[1];
};
extern float D_004E16F4;            // [G] relax rate
extern float D_004E06C0;            // [G] restitution
extern float D_004E16F8;            // [G] hard-hit impulse
// [G] as CB3CollidingBody::CollideWithWorld's declaration (10 arguments as passed)
extern "C" bool func_002F2E70(void *, CGtMatrix3x4 *, void *, UnkStruct_001C8290_cache *, void *, void *, void *, void *, void *, void *);
extern "C" float func_001D0930(float e, UnkStruct_001C8870_part *body, const CGtV3d &p0, const CGtV3d &v, const CGtV3d &n0, CGtV3d *out);

// 0x001C8290
extern "C" void func_001C8290(UnkStruct_001C8290 *self, int i)
{
    UnkStruct_001C8870_part *lPart = &self->field_CE0[i];
    if (self->field_200->field_0 == 0) return;
    CGtMatrix3x4 lWorld = *lPart->field_B8 * *self->field_204;
    CGtMatrix3x4 lInv = lWorld;
    lInv.Invert();
    ((float *)&lInv.mPos)[3] = ((const float *)&lWorld.mPos)[3]; // [C] 0x1C83FC lq t2, 0x260(sp) (lWorld.mPos), 0x1C8450 qmtc2 t2, vf1;
    // 0x1C8468 vmuly.xyz vf1, vf4, vf1y into it, 0x1C846C/0x1C8470 vadd.xyz and 0x1C8474 vsub.xyz vf1, vf0, vf1 keep its w;
    // 0x1C8480 sqc2 vf1, 0x300(sp) -- the port header's Invert gives the up row's w
    CGtV3d lPos, lNormal, lOther;
    unsigned short lnTri;
    if (func_002F2E70(&self->field_CC0->field_40->field_EA0[i], self->field_204, &lInv, self->field_200, &lPos, &lNormal,
                      &lnTri, 0, 0, &lOther) == 0) {
        float lrLimit = self->field_CC0->field_40->field_AFC[i];
        float lrAbsLimit = GtMath::Abs(lrLimit);
        if (GtMath::Abs(lPart->field_B0) < lrAbsLimit) {
            lPart->field_B0 = 0.0f + lPart->field_B0 + lrLimit * D_004E16F4;
            if (!(GtMath::Abs(lPart->field_B0) <= lrAbsLimit)) lPart->field_B0 = lrLimit;
        }
        return;
    }
    CGtV3d lVel = CrossProduct(self->field_D0, lPos - self->field_204->mPos) + self->field_B0;
    CGtV3d lImpulse;
    float lrImpulse = func_001D0930(D_004E06C0, lPart, lPos, lVel, lNormal, &lImpulse);
    lPos = TransformPoint(self->field_70, lPos);
    lOther = TransformVector(self->field_70, lOther);
    lImpulse = TransformVector(self->field_70, lImpulse);
    if (lrImpulse > 0.0f) lPart->field_80 += CrossProduct(lPos - lPart->field_B8->mPos, lImpulse);
    CGtV3d lZero;
    unsigned char lnAxis = self->field_CC0->field_40->field_ADC[i];
    if (lnAxis == 0) {
        lZero.Set(0.0f, 0.0f, 1.0f);
        lOther.SetX(0.0f);
    } else if (lnAxis == 1) {
        lZero.Set(0.0f, 0.0f, -1.0f);
        lOther.SetY(0.0f);
    } else {
        lZero.Set(1.0f, 0.0f, 0.0f);
        lOther.SetZ(0.0f);
    }
    float lrAngle = AngleBetweenVectors(lZero, lZero + lOther);
    if (lPart->field_B0 < 0.0f) {
        lPart->field_B0 = lPart->field_B0 + lrAngle;
        if (!(lPart->field_B0 <= 0.0f)) lPart->field_B0 = 0.0f;
    } else {
        lPart->field_B0 = lPart->field_B0 - lrAngle;
        if (lPart->field_B0 < 0.0f) lPart->field_B0 = 0.0f;
    }
    if (!(lrImpulse <= D_004E16F8)) self->field_CC4->field_F90[i] = 1000.0f;
}
