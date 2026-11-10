// NONMATCHING: UpdateFlyingBits__16CB3VehicleDeformFv -- retail 633 / ours 633 instructions, 525 in changed runs
// draftS: 633/633, branch sequence identical except the first continue (retail beq to the shared i++ block, ours bne over a duplicated b; 6 loop forms negative); residue: VU register numbering of the hoisted identity/zero/1.0 invariants, case-block matrix copy levels (retail 2 full stack copies + rows-only temp per case, frame 0x700 vs 0x4A0: N254/N263 family)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: every load/store offset, branch, VU op and lane accounted for (blend of <=2 bone matrices + identity*(1-sum) per bit, mirrored blend via kaeOtherMainBone for types 2/3/6 with rest x > 0.1, re-aim by d x up (mode 0) / Matrix3x4SetLookAt (mode 2), main-bit height kept and its change added to field_1C)

// UpdateFlyingBits__16CB3VehicleDeformFv -- draftS (0x3E1F80, 0x9E4) -- CB3VehicleDeform::UpdateFlyingBits()
// Written from the retail asm (no Revenge counterpart). [L] reading: each flying bit's matrix is a weighted blend of up to two
// bone matrices (weights 0 = end of list) plus identity * (1 - sum); its position = blend * rest position. Bits of types 2/3/6
// whose rest x > 0.1 also blend the mirrored bones (kaeOtherMainBone) and re-aim the bit along the left/right difference
// (type 6 with mode 0: rows (d, a x d, a = |d x up|); mode 2: Matrix3x4SetLookAt(|d x up|, up)). Then (unless field_47) the
// six main bits get their blended positions with the old height kept, and the height change is added to field_1C's per-bit
// value. Types/fields [G] (instruction widths); class layout as the ImpactBody archive (UnkStruct_003DC730_*).
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

class CB3VehicleDeform;
struct UnkStruct_003E1F80_40 { unsigned char pad_0[0xC]; signed char field_C; };
struct UnkStruct_003E1F80_10 { unsigned char pad_0[0x40]; UnkStruct_003E1F80_40 *field_40; };
// [G] field_14: flying-bit matrices (+0x0, bits 0-5 then 6..), bit state (+0x4AC, 3 = detached?), bone matrices (+0x500)
struct UnkStruct_003E1F80_14 {
    CGtMatrix3x4 field_0[6];          // [G] the six main flying bits (loop 2)
    CGtMatrix3x4 field_180[11];       // [G] the extra bits (loop 1, count field_10->field_40->field_C)
    unsigned char pad_440[0x6C];
    signed char field_4AC[6];
    signed char field_4B2[0x4E];
    CGtMatrix3x4 field_500[8];
};
// [G] field_18: bit type (+0xAC4), mode (+0xADC), bone indices (+0xAE2), bone weights (+0xB14), rest matrices (+0xB80)
struct UnkStruct_003E1F80_18 {
    unsigned char pad_0[0xAC0];
    int field_AC0;
    int field_AC4[6];
    unsigned char field_ADC[6];
    unsigned char field_AE2[6][2];
    unsigned char field_AEE[6][2];
    unsigned char pad_AFA[0x1A];
    float field_B14[6][2];
    float field_B44[6][2];
    unsigned char pad_B74[0xC];
    CGtMatrix3x4 field_B80[6];
    CGtMatrix3x4 field_D00[6];
};
struct UnkStruct_003E1F80_1C_e { unsigned char pad_0[0x14]; float field_14; unsigned char pad_18[0xA8]; };
struct UnkStruct_003E1F80_1C {
    unsigned char pad_0[0x880];
    UnkStruct_003E1F80_1C_e field_880[4];
    unsigned char pad_B80[0x120];
    float field_CA0;
    unsigned char pad_CA4[0xC];
    float field_CB0;
};
struct UnkStruct_003E1F80 {
    unsigned char pad_0[0x10];
    UnkStruct_003E1F80_10 *field_10;
    UnkStruct_003E1F80_14 *field_14;
    UnkStruct_003E1F80_18 *field_18;
    UnkStruct_003E1F80_1C *field_1C;
    unsigned char pad_20[0x27];
    unsigned char field_47;
};
extern int kaeOtherMainBone[];

// 0x003E1F80
extern "C" void UpdateFlyingBits__16CB3VehicleDeformFv(UnkStruct_003E1F80 *self)
{
    if (self->field_18 == 0 || self->field_18->field_AC0 == 0)
        return;
    CGtMatrix3x4 lIdentity;
    lIdentity.SetIdentity();
    for (int i = 0; ; i++) {
        if (i >= self->field_10->field_40->field_C)
            break;
        UnkStruct_003E1F80_14 *b = self->field_14;
        if (b->field_4B2[i] == 3)
            continue;
        CGtMatrix3x4 lA;
        CGtMatrix3x4 lB;
        lA.mRight.Zero(); lA.mUp.Zero(); lA.mAt.Zero(); lA.mPos.Zero();
        bool lMirror = false;
        UnkStruct_003E1F80_18 *e = self->field_18;
        int type = e->field_AC4[i];
        if ((type == 2 || type == 3 || type == 6) && e->field_D00[i].mPos.X() > 0.1f) {
            lB.mRight.Zero(); lB.mUp.Zero(); lB.mAt.Zero(); lB.mPos.Zero();
            lMirror = true;
        }
        float lSum = 0.0f;
        for (int j = 0; j < 2; j++) {
            float w = self->field_18->field_B14[i][j];
            if (w == 0.0f)
                break;
            unsigned char bone = self->field_18->field_AE2[i][j];
            lSum += w;
            {
                CGtMatrix3x4 m = b->field_500[bone];
                lA.mRight += m.mRight * w;
                lA.mUp += m.mUp * w;
                lA.mAt += m.mAt * w;
                lA.mPos += m.mPos * w;
            }
            if (lMirror) {
                CGtMatrix3x4 m = b->field_500[kaeOtherMainBone[bone]];
                lB.mRight += m.mRight * w;
                lB.mUp += m.mUp * w;
                lB.mAt += m.mAt * w;
                lB.mPos += m.mPos * w;
            }
        }
        float s = 1.0f - lSum;
        lA.mRight += lIdentity.mRight * s;
        lA.mUp += lIdentity.mUp * s;
        lA.mAt += lIdentity.mAt * s;
        lA.mPos += lIdentity.mPos * s;
        if (lMirror) {
            lB.mRight += lIdentity.mRight * s;
            lB.mUp += lIdentity.mUp * s;
            lB.mAt += lIdentity.mAt * s;
            lB.mPos += lIdentity.mPos * s;
        }
        b->field_180[i].mPos = TransformPoint(lA, e->field_D00[i].mPos);
        if (lMirror) {
            UnkStruct_003E1F80_18 *e2 = self->field_18;
            UnkStruct_003E1F80_14 *b2 = self->field_14;
            CGtV3d p = e2->field_D00[i].mPos;
            p.SetX(-p.X());
            CGtV3d q = TransformPoint(lB, p);
            CGtV3d d = b2->field_180[i].mPos;
            d -= q;
            if (d.GetSquaredLength() < 2.3283064e-10f) {
                d.SetX(1.0f);
                d.SetY(0.0f);
                d.SetZ(0.0f);
            }
            d.Normalise();
            if (e2->field_AC4[i] == 6) {
                if (e2->field_ADC[i] == 0) {
                    CGtMatrix3x4 r;
                    r = b2->field_180[i];
                    CGtMatrix3x4 n;
                    n.mRight = d;
                    n.mAt = CrossProduct(d, b2->field_180[i].mUp);
                    func_002EBED0_inl1(n.mAt);
                    n.mUp = CrossProduct(n.mAt, n.mRight);
                    r.mRight = n.mRight;
                    r.mUp = n.mUp;
                    r.mAt = n.mAt;
                    b2->field_180[i] = r;
                }
            } else if (e2->field_ADC[i] == 2) {
                CGtV3d at = CrossProduct(d, b2->field_180[i].mUp);
                func_002EBED0_inl1(at);
                CGtMatrix3x4 r;
                r = b2->field_180[i];
                CGtMatrix3x4 n = Matrix3x4SetLookAt(at, b2->field_180[i].mUp);
                r.mRight = n.mRight;
                r.mUp = n.mUp;
                r.mAt = n.mAt;
                b2->field_180[i] = r;
            }
        }
    }
    if (self->field_47 == 0) {
        for (int k = 0; ; k++) {
            if (k >= 6)
                break;
            UnkStruct_003E1F80_14 *b = self->field_14;
            if (b->field_4AC[k] == 3)
                continue;
            CGtMatrix3x4 lA;
            lA.mRight.Zero(); lA.mUp.Zero(); lA.mAt.Zero(); lA.mPos.Zero();
            float lSum = 0.0f;
            for (int j = 0; j < 2; j++) {
                float w = self->field_18->field_B44[k][j];
                if (w == 0.0f)
                    break;
                CGtMatrix3x4 m = b->field_500[self->field_18->field_AEE[k][j]];
                lSum += w;
                lA.mRight += m.mRight * w;
                lA.mUp += m.mUp * w;
                lA.mAt += m.mAt * w;
                lA.mPos += m.mPos * w;
            }
            float s = 1.0f - lSum;
            float lOldY = b->field_0[k].mPos.Y();
            lA.mRight += lIdentity.mRight * s;
            lA.mUp += lIdentity.mUp * s;
            lA.mAt += lIdentity.mAt * s;
            lA.mPos += lIdentity.mPos * s;
            CGtV3d lRest = self->field_18->field_B80[k].mPos;
            self->field_14->field_0[k].mPos = TransformPoint(lA, lRest);
            float dy = self->field_14->field_0[k].mPos.Y() - lRest.Y();
            self->field_14->field_0[k].mPos.SetY(lOldY);
            if (self->field_1C != 0) {
                float f;
                if (k < 2)
                    f = self->field_1C->field_CA0;
                else
                    f = self->field_1C->field_CB0;
                self->field_1C->field_880[k].field_14 = f + dy;
            }
        }
    }
}




