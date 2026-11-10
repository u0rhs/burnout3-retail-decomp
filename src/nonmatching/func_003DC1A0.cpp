// NONMATCHING: func_003DC1A0 -- retail 355 / ours 367 instructions, 170 in changed runs
// draftAH C-first: clamp-box penetration fractions (5 boxes, z/y depth), weighted total capped at 1 (field_70), deform state thresholds, per-wheel flags from depth > 0.5 or sideways offset outside the (crash-dependent) range; 367/355, calls identical, VU and FPU op counts equal; left: branch polarity of the range tests (beq 23/19, bne 3/6), mov.s 6/2, frame 0x3A0 vs 0x480
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; every compare, threshold constant (values read from the ELF), store and wheel-count guard traced; header lane subtractions (vsubz.z / vsuby.y / vsubx.x) and GtMath::Abs/Min

// func_003DC1A0 -- draftAH (C-first draft; the lifter refused it). 0x3DC1A0, 0x58C. Unnamed in every table, so the asm label
// with C linkage. Called by CB3VehicleDeform::ImpactBody (archive) after the body deformation. Written from the retail asm.
// What it does [L]: how far the deform bones have pushed into their clamp boxes (func_003E6C20 = [L] GetClampBox, ImpactBody's
// archive): per box the bone position's depth through the box along z (boxes 0, 1 from the top corner, 4, 5 from the bottom
// one) or y (box 6), as a fraction of the box size (0 for an empty box); a weighted total (0.35 per side box + 0.5 * the roof)
// capped at 1 into field_70; the deform state (params +0x1014) goes to 2 (and bit 0 of +0x1015) past a threshold, or 1 past a
// lower one (thresholds per field_38); then each wheel slot (params +0xF78, one float per wheel, up to the wheel count) is set to
// 1 when its corner is pushed in more than half way or its bone's sideways offset leaves the allowed range (wider, and
// asymmetric, while the car is crashing: field_1C->field_215 1..3). Types [G]; layouts as Prepare / Render.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct CGtAxisAlignedBox { CGtV3d mSup; CGtV3d mInf; };   // [L] Revenge layout (GetClampBox's output)
struct UnkStruct_003DC1A0_40 {              // the vehicle data block (essential params +0x40)
    unsigned char pad_0[0xD];
    signed char field_D;                    // wheel count
    unsigned char pad_E[0xD2];
    CGtV3d field_E0;                        // [G] rest positions of the corner bones (x used)
    unsigned char pad_F0[0x30];
    CGtV3d field_120;
    unsigned char pad_130[0x70];
    CGtV3d field_1A0;
    unsigned char pad_1B0[0x30];
    CGtV3d field_1E0;
};
class CB3VehicleEssentialParams {
public:
    unsigned char pad_0[0x40];
    UnkStruct_003DC1A0_40 *field_40;
};
class CB3VehicleParams {
public:
    unsigned char pad_0[0x700];
    CGtMatrix3x4 field_700[8];              // deform bone matrices (as Render's)
    unsigned char pad_900[0x678];
    float field_F78[6];                     // per-wheel flags [G]
    unsigned char pad_F90[0x84];
    unsigned char field_1014;               // deform state
    unsigned char field_1015;
};
struct UnkStruct_003DC1A0_1C { unsigned char pad_0[0x215]; signed char field_215; };   // [G] the owner (crash state at +0x215)
class CB3VehicleDeform {
public:
    unsigned char pad_0[0x10];
    CB3VehicleEssentialParams *field_10;
    CB3VehicleParams *field_14;
    UnkStruct_003DC1A0_40 *field_18;
    UnkStruct_003DC1A0_1C *field_1C;
    unsigned char pad_20[0x18];
    int field_38;
    unsigned char pad_3C[0x34];
    float field_70;                         // total deformation, 0..1
};
extern "C" void func_003E6C20(CB3VehicleDeform *self, int bone, CGtAxisAlignedBox *box);   // [L] GetClampBox
extern float D_004E07A8;                    // 0.35
extern float D_004E0CD0, D_004E0D4C, D_004E0C18;                // state thresholds
extern float D_004E0D48, D_004E0C14;                            // -FLT_MAX, FLT_MAX
extern float D_004E09F4, D_004E0D50, D_004E0D40, D_004E0D54;    // crashing ranges

// 0x003DC1A0
extern "C" void func_003DC1A0(CB3VehicleDeform *self)
{
    CGtAxisAlignedBox b0, b1, b4, b5, b6;
    func_003E6C20(self, 0, &b0);
    func_003E6C20(self, 1, &b1);
    func_003E6C20(self, 4, &b4);
    func_003E6C20(self, 5, &b5);
    func_003E6C20(self, 6, &b6);
    float d, r0 = 0.0f, r1 = 0.0f, r4 = 0.0f, r5 = 0.0f, r6 = 0.0f;
    d = b0.mSup.Z() - b0.mInf.Z();
    if (!(d <= 0.0f))
        r0 = GtMath::Abs(b0.mSup.Z() - self->field_14->field_700[4].mPos.Z()) / d;
    d = b1.mSup.Z() - b1.mInf.Z();
    if (!(d <= 0.0f))
        r1 = GtMath::Abs(b1.mSup.Z() - self->field_14->field_700[5].mPos.Z()) / d;
    d = b4.mInf.Z() - b4.mSup.Z();
    if (!(d <= 0.0f))
        r4 = GtMath::Abs(b4.mInf.Z() - self->field_14->field_700[1].mPos.Z()) / d;
    d = b5.mInf.Z() - b5.mSup.Z();
    if (!(d <= 0.0f))
        r5 = GtMath::Abs(b5.mInf.Z() - self->field_14->field_700[2].mPos.Z()) / d;
    d = b6.mSup.Y() - b6.mInf.Y();
    if (!(d <= 0.0f))
        r6 = GtMath::Abs(b6.mSup.Y() - self->field_14->field_700[7].mPos.Y()) / d;

    UnkStruct_003DC1A0_40 *dat = self->field_18;
    CB3VehicleParams *par = self->field_14;
    float w = GtMath::Abs(dat->field_1A0.X() - dat->field_1E0.X());
    float x12 = (par->field_700[4].mPos.X() - dat->field_1A0.X()) / w;
    float x11 = (par->field_700[5].mPos.X() - dat->field_1E0.X()) / w;
    w = GtMath::Abs(dat->field_1A0.X() - dat->field_1E0.X());   // [C asm] computed again
    float x10 = (par->field_700[1].mPos.X() - dat->field_E0.X()) / w;
    float x9 = (par->field_700[2].mPos.X() - dat->field_120.X()) / w;
    float k = D_004E07A8;
    self->field_70 = GtMath::Min(k * r1 + k * r0 + k * r4 + k * r5 + 0.5f * r6, 1.0f);

    if (self->field_14->field_1014 != 2) {
        float s = 0.0f + (r0 + r1) + 3.0f * r6;
        if (!(s <= (self->field_38 ? D_004E0CD0 : 0.25f))) {
            self->field_14->field_1014 = 2;
            self->field_14->field_1015 |= 1;
        } else if (!(s <= (self->field_38 ? D_004E0D4C : D_004E0C18))) {
            self->field_14->field_1014 = 1;
        }
    }

    float lo1 = D_004E0D48, hi1 = D_004E0C14;
    float lo2 = lo1, hi2 = hi1;
    if (self->field_1C) {
        switch (self->field_1C->field_215) {
        case 1:
        case 2:
        case 3:
            hi1 = D_004E09F4;
            lo2 = D_004E0D50;
            hi2 = D_004E0D40;
            lo1 = D_004E0D54;
            break;
        }
    }
    if (!(r1 <= 0.5f) || !(x11 <= hi1) || x11 < lo1) {
        if (self->field_10->field_40->field_D > 0)
            self->field_14->field_F78[0] = 1.0f;
    }
    if (!(r0 <= 0.5f) || !(x12 <= hi1) || x12 < lo1) {
        if (self->field_10->field_40->field_D >= 2)
            self->field_14->field_F78[1] = 1.0f;
    }
    if (!(r5 <= 0.5f) || !(x9 <= hi2) || x9 < lo2) {
        if (self->field_10->field_40->field_D >= 3)
            self->field_14->field_F78[2] = 1.0f;
        if (self->field_10->field_40->field_D >= 5)
            self->field_14->field_F78[4] = 1.0f;
    }
    if (!(r4 <= 0.5f) || !(x10 <= hi2) || x10 < lo2) {
        if (self->field_10->field_40->field_D >= 4)
            self->field_14->field_F78[3] = 1.0f;
        if (self->field_10->field_40->field_D >= 6)
            self->field_14->field_F78[5] = 1.0f;
    }
}
