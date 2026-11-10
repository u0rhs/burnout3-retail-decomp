// NONMATCHING: UpdateAttachState__16CB3VehicleDeformFv -- retail 574 / ours 558 instructions, 479 in changed runs
// draftAF C-first: logic complete (rate factor k from player/hash/crash-mode, per-bit timer vs thresholds, CGtRandom::RandomReal half-chance for type 4, loosen: 5-degree CreateRotationMatrix3x4 swing about the bit's hinge axis, then the first type-4 bit's clamp-box height test). 558/574; call multiset identical (static order = block placement); VU op counts equal except 1 vmove.xyzw; retail indexes the state/timer after loop 2 with loop 1's counter (kept). Left: copy levels (sqc2 22/17, frame 0x390 vs 0x6E0), compare senses
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] every retail block mapped (k chain, 4 timer arms, RNG = Reset's inline, axis pick, rotate-about-pivot with the held 0.0 offset, loop 2 + both box ratios); per-kind op counts equal except 1 copy

// UpdateAttachState__16CB3VehicleDeformFv -- draftAF (0x3E0FE0, 0x8F8) -- CB3VehicleDeform::UpdateAttachState()
// [C name: config/symbol_addrs_b3names.txt]. Written from the retail asm (no Revenge counterpart; Ghidra as reading aid).
// [L] reading: each flying bit's damage timer (field_14->field_F90[i]) against its thresholds: out of reach of the car's
// reference value (field_160[i] + rate * k) -> 1000; above the detach threshold -> held just past it (unless state >= 2); between
// the loosen and detach thresholds a still-attached bit (state 0) becomes loose (state 1): bits of type 4 only half of the time
// (CGtRandom::RandomReal), the others always; a loosened bit's matrix swings 5 degrees about its hinge axis (field_ADC: 0/1/2
// -> D_004CAD70/80/90) opposite to the hinge limit's sign, about its own position. Then, for the first type-4 bit, the two clamp
// boxes (func_003E6C20 = [L] GetClampBox) decide by the bit's height inside them whether it is pushed past its detach threshold.
// k: 0.5 for crash-able players (field_1C kind 1/2/3 with field_13F4->field_15C6), 0 for the two hashed vehicles, D_004E0AAC
// for traffic in crash mode, else 1. Types/fields [G]; class layout as the UpdateFlyingBits / ImpactBody archives.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/GtMathPs2Trig.h"
using namespace GtMathPs2;

// [C] names: CGtRandom::Random() / RandomReal() (B3O0PCH map); layout [L] Revenge's CGtRandom (two RwInt32, 8 bytes)
struct CGtRandom {
    int field_0;
    int field_4;
    unsigned int Random() { field_0 = (field_0 << 16) + (field_0 >> 16); field_0 += field_4; field_4 += field_0; return field_0; }
    float RandomReal() { return 2.3283064e-10f * (float)Random(); }
};
// [G] the bits' parameters (UpdateFlyingBits' field_18 layout): count, type, hinge axis, hinge limit
struct UnkStruct_003E0FE0_prm {
    unsigned char pad_0[0xC];
    signed char field_C;
    unsigned char pad_D[0xAB7];
    int field_AC4[6];
    unsigned char field_ADC[0x20];
    float field_AFC[6];
};
struct UnkStruct_003E0FE0_10 { unsigned char pad_0[0x40]; UnkStruct_003E0FE0_prm *field_40; };
struct UnkStruct_003E0FE0_14 {
    CGtMatrix3x4 field_0[6];
    CGtMatrix3x4 field_180[11];       // [G] the extra (flying) bits
    unsigned char pad_440[0x72];
    signed char field_4B2[0x4E];      // [G] bit state: 0 attached, 1 loose, 2.. detached
    CGtMatrix3x4 field_500[8];
    CGtMatrix3x4 field_700[0x22];     // [G] the bits' current matrices (only mPos.y read)
    unsigned char pad_F80[0x10];
    float field_F90[6];               // [G] damage timer
    float field_FA8[6];               // [G] loosen threshold
    float field_FC0[6];               // [G] detach threshold
    float field_FD8[6];               // [G] rate
};
struct UnkStruct_003E0FE0_cs { unsigned char pad_0[0x15C6]; unsigned char field_15C6; };
struct UnkStruct_003E0FE0_vp { unsigned char pad_0[0x215]; signed char field_215; unsigned char pad_216[0x11DE]; UnkStruct_003E0FE0_cs *field_13F4; };
struct UnkStruct_003E0FE0 {
    CGtRandom field_0;
    unsigned long field_8;            // [G] the vehicle's 64-bit name hash
    UnkStruct_003E0FE0_10 *field_10;
    UnkStruct_003E0FE0_14 *field_14;
    UnkStruct_003E0FE0_prm *field_18;
    UnkStruct_003E0FE0_vp *field_1C;
    unsigned char pad_20[0x140];
    float field_160[6];
};
struct UnkStruct_003E0FE0_box { CGtV3d field_0; CGtV3d field_10; };   // [L] max, min corners (func_003E6C20's archive)
extern const CGtV3d D_004CAD70, D_004CAD80, D_004CAD90;   // [G] hinge axes
extern float D_004E0D3C;              // [G] degrees -> radians
extern float D_004E0AAC;
extern unsigned char D_004EE040[];
extern "C" int func_00131E40(void *);  // [L] CB3Game::IsCrashMode() (E map, high)
extern "C" void func_003E6C20(UnkStruct_003E0FE0 *, int, UnkStruct_003E0FE0_box *);   // [L] GetClampBox

// [G] the vehicle kinds 1..3 (players; CollideWithWorld's `grounded` test)
static inline bool func_003E0FE0_inl1(signed char k) { return k == 1 || k == 2 || k == 3; }

// 0x003E0FE0
extern "C" void UpdateAttachState__16CB3VehicleDeformFv(UnkStruct_003E0FE0 *self)
{
    bool lbPlayer;
    if (self->field_1C != 0 && func_003E0FE0_inl1(self->field_1C->field_215) && self->field_1C->field_13F4->field_15C6 != 0)
        lbPlayer = true;
    else
        lbPlayer = false;
    float k;
    if (lbPlayer) {
        k = 0.5f;
    } else if (self->field_1C != 0 && (self->field_8 == 0x790798FBA1192600UL || self->field_8 == 0x790798FBA11A2000UL)) {
        k = 0.0f;
    } else if (func_00131E40(D_004EE040) && self->field_1C != 0 && !func_003E0FE0_inl1(self->field_1C->field_215)) {
        k = D_004E0AAC;
    } else {
        k = 1.0f;
    }
    int i;
    for (i = 0; i < self->field_10->field_40->field_C; i++) {
        UnkStruct_003E0FE0_14 *b = self->field_14;
        float t = b->field_F90[i];
        if (!(t - self->field_160[i] <= b->field_FD8[i] * k)) {
            b->field_F90[i] = 1000.0f;
            continue;
        }
        if (!(t <= b->field_FC0[i])) {
            if ((unsigned int)b->field_4B2[i] < 2) b->field_F90[i] = 1.0f + b->field_FC0[i];
            continue;
        }
        if (t <= b->field_FA8[i]) continue;
        if (b->field_4B2[i] != 0) continue;
        if (self->field_10->field_40->field_AC4[i] == 4 && self->field_0.RandomReal() < 0.5f) {
            self->field_14->field_F90[i] = 1.0f + self->field_14->field_FC0[i];
            continue;
        }
        self->field_14->field_4B2[i] = 1;
        UnkStruct_003E0FE0_prm *p = self->field_10->field_40;
        CGtV3d lAxis;
        if (p->field_ADC[i] == 1) lAxis = D_004CAD80;
        else if (p->field_ADC[i] == 0) lAxis = D_004CAD70;
        else lAxis = D_004CAD90;
        CGtMatrix3x4 &m = self->field_14->field_180[i];
        CGtMatrix3x4 lRotate = CreateRotationMatrix3x4(lAxis, D_004E0D3C * (-5.0f * GtMath::Sign(p->field_AFC[i])));
        float lrPivot = 0.0f;   // [G] the pivot's offset along the bit's at axis (retail multiplies by a held 0.0)
        CGtV3d lPivot = m.mPos + m.mAt * lrPivot;
        CGtMatrix3x4 lBit = m;
        lBit.mPos.Zero();
        m = lBit * lRotate;
        m.mPos = lPivot - m.mAt * lrPivot;
    }
    int lnBit;
    for (lnBit = 0; lnBit < self->field_18->field_C; lnBit++) {
        if (self->field_18->field_AC4[lnBit] == 4) goto found;
    }
    lnBit = -1;
found:
    if (lnBit < 0) return;
    // [G] retail indexes the state, and later the timer, with the first loop's counter (s0), not lnBit
    if (self->field_14->field_4B2[i] != 0) return;
    UnkStruct_003E0FE0_box lBox0, lBox1;
    func_003E6C20(self, 0, &lBox0);
    func_003E6C20(self, 1, &lBox1);
    float f0 = 0.0f, f1 = 0.0f;
    float h0 = lBox0.field_0.Y() - lBox0.field_10.Y();
    if (h0 > 0.0f) f0 = (self->field_14->field_700[lnBit].mPos.Y() - lBox0.field_10.Y()) / h0;
    float h1 = lBox1.field_0.Y() - lBox1.field_10.Y();
    if (h1 > 0.0f) f1 = (self->field_14->field_700[lnBit].mPos.Y() - lBox1.field_10.Y()) / h1;
    if (f0 <= D_004E0AAC && f1 <= D_004E0AAC) return;
    self->field_14->field_F90[i] = 1.0f + self->field_14->field_FC0[i];
}
