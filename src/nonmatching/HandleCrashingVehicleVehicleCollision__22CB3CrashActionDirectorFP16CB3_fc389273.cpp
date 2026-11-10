// NONMATCHING: HandleCrashingVehicleVehicleCollision__22CB3CrashActionDirectorFP16CB3CollidingPair -- retail 443 / ours 456 instructions, 509 in changed runs
// draftAO (2026-11-01): rewritten complete from retail: the one-race-car branch had the race car and the other vehicle swapped (0x930 mask, tanker id, speed, DoTankerExplosion's tanker and the crash applied to the wrong body; retail s0 = the type<3 body [C] 0x1ADD54); the VU0 stand-in replaced by the real tanker test (velocity dir dot tanker At, TransformPoint into tanker space through its +0x70 matrix, box centre / 0.475 depth, Min(t,1)) and DoTankerExplosion gets z and the whole box (was 0 and a 4-float copy); 20000 branch constant D_004E0EEC (was D_004E12A8); crash point via CGtV3dPlus SetGtV3d/SetPlus; FPU/VU op counts equal, calls identical, behaviour_audit quiet | Before: son7 first archive: control flow, thresholds, RNG rolls, field offsets and the func_001ADA00 call (retail helper at 0x1ADA00: self, body, f12, vec*, 0) decoded; the player-vs-traffic alignment maths (VU0) is a scalar stand-in [G]; retail 443 vs ours 422 instrs, frame 0x230 vs 0x70
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm (0x1ADC70..0x1AE358): every branch, call argument and non-stack store traced; FPU/VU op census equal; behaviour_audit quiet

// CB3CrashActionDirector::HandleCrashingVehicleVehicleCollision -- son7 first archive, rewritten complete by draftAO fork C
// from retail 0x1ADC70..0x1AE358. A collision pair (contact point +0, impulse +0x20, the two colliding objects +0x24 / +0x28,
// each with a type byte at +0 and its vehicle body at +0xC). Types 0..2 ("small" below; the signed byte compared unsigned,
// sltiu 3) are the race cars [G]. Steps [C]:
//  1. impulse > 5000: each body that is a race car or whose state (+0x2420) has bit 1 rolls twice (state +0x370 - 0.5, then
//     4e-5 * (impulse - 5000)) and on both passes sets the crash flags +0x1016 |= 0xF0.
//  2. both race cars: done. One race car (`car`) against another vehicle (`veh`): veh's state must be in mask 0x930; if veh is
//     the tanker (vehicle id 0x77042838671E0800) and the car is faster than 31.286 (+0xB0 w) and impulse > 2400, a chance
//     0.25 * ((1 - 2 |dot(car velocity dir, tanker At)|) + ((1 - |z| / (0.475 * box depth)) + 2 min(5.68e-5 (impulse - 2400), 1)))
//     (z = the car's position in tanker space minus the box centre; x8 when func_00131E40(&D_004EE040)) triggers
//     DoTankerExplosion(veh, z, &box, false) [func_001ADA00, L] and, in that mode, car +0x3534 = the race time; else
//     the car's crash chance terms 2e-5 (impulse - 10000) and 1.667 (car +0x370 - 0.4). Neither a race car: the vehicle whose
//     state is in 0x930 against one with bit 1 (B checked first) takes 2.5e-5 (impulse - 20000) and 2 (+0x370 - 0.5).
//  3. unless already crashing (+0x1015 bit 4): if a roll <= 0.5 a + 0.5 b, start the crash: +0x1000 = (contact point, time),
//     +0x1015 |= 0x18, +0x1016 |= 0xF0, +0x1015 &= ~6, state +0x1014 := 2 with +0x1015 bit 0 when it was not 2.
// The son7 draft had the race car / other vehicle swapped in step 2 (every test, the explosion and the crash on the wrong body).
// Field names are placeholders and every type is [G] unless tagged.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_Crash_state {
    unsigned char pad_0[0x370];
    float field_370;             // [G] crash propensity (compared with rolls around 0.5)
    unsigned char pad_374[0xC8C];
    CGtV3dPlus field_1000;       // [C] crash point xyz + start time w (vadd.xyz / vsubw.w + vaddx.w into the loaded quad)
    unsigned char pad_1010[4];
    unsigned char field_1014;
    unsigned char field_1015;
    unsigned char field_1016;
};
// [L] CGtAxisAlignedBox (DoTankerExplosion's lpBBox, Revenge stabs): two corners; [C] the first is the larger (depth = first.z - second.z)
struct UnkStruct_Crash_box { CGtV3d field_0; CGtV3d field_10; };
struct UnkStruct_Crash_body {
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;       // [C] world -> body space (TransformPoint of the other car's position)
    CGtV4d field_B0;             // [C] velocity xyz, speed w
    unsigned char pad_C0[0x110];
    UnkStruct_Crash_box field_1D0;   // [C] the body's box (copied whole to the stack, DoTankerExplosion's box)
    unsigned char pad_1F0[0x14];
    CGtMatrix3x4 *field_204;     // the body's matrix
    unsigned char pad_208[0xCC4 - 0x208];
    UnkStruct_Crash_state *field_CC4;
    unsigned char pad_CC8[0x2420 - 0xCC8];
    int field_2420;              // state index (bit masks 0x930 / 2)
    unsigned char pad_2424[6];
    unsigned char field_242A;    // vehicle id index into D_0055B7D0
    unsigned char pad_242B[0x3534 - 0x242B];
    float field_3534;
};
struct UnkStruct_Crash_obj { signed char field_0; unsigned char pad_1[0xB]; UnkStruct_Crash_body *field_C; };
struct UnkStruct_Crash_pair {
    CGtV3d field_0;              // [C] contact point (xyz copied into the crash state)
    unsigned char pad_10[0x10];
    float field_20;              // [C] impulse
    UnkStruct_Crash_obj *field_24;
    UnkStruct_Crash_obj *field_28;
};
class CB3CrashActionDirector {
public:
    void HandleCrashingVehicleVehicleCollision(class CB3CollidingPair *);
    unsigned int field_0;        // LCG state
    unsigned int field_4;
};
extern unsigned long D_0055B7D0[];      // [C] 64-bit vehicle ids (ld, index * 8)
extern float D_004E129C, D_004E12A0, D_004E12A4, D_004E12A8, D_004E12AC, D_004E12B0, D_004E0C50, D_004E0EEC;
extern float D_00522680;                // [G] race time
extern unsigned char D_004EE040[];
extern unsigned char D_01E65499;
extern "C" int func_00131E40(void *);
// [L] CB3CrashActionDirector::DoTankerExplosion(CB3TrafficPhysics *, float, CGtAxisAlignedBox *, bool) (func_001ADA00's archive)
extern "C" void func_001ADA00(CB3CrashActionDirector *, UnkStruct_Crash_body *, float, UnkStruct_Crash_box *, int);

// [G] the director's LCG roll in [0,1): x = (x << 16) + (x >> 16 arithmetic); x += y; y += x; (unsigned) x * 2^-32
static inline float func_001ADC70_inl1(CB3CrashActionDirector *self)
{
    self->field_0 = self->field_0 * 0x10000 + ((int)self->field_0 >> 16);
    self->field_0 = self->field_0 + self->field_4;
    self->field_4 = self->field_4 + self->field_0;
    return 2.3283064e-10f * (float)self->field_0;
}
// [G] lane scale z * s on the VU (retail `qmtc2.ni s; vmulx.z`); no header API for ZAxisType * float
static inline ZAxisType func_001ADC70_inl2(ZAxisType z, float s)
{
    u_long128 sv, r;
    asm("qmtc2.ni %1, %0" : "=j"(sv) : "r"(s));
    asm("vmulx.z %0, %1, %2x" : "=j"(r) : "j"(z.lVector), "j"(sv));
    return ZAxisType(r);
}
static inline float func_001ADC70_inl3(float x) { float r; asm("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
// sllv semantics: the shift count is taken mod 32 (C's 1 << n is undefined past 31)
static inline unsigned int func_001ADC70_inl4(int n) { return 1u << (n & 0x1F); }

// 0x001ADC70
void CB3CrashActionDirector::HandleCrashingVehicleVehicleCollision(CB3CollidingPair *cp)
{
    UnkStruct_Crash_pair *pair = (UnkStruct_Crash_pair *)cp;
    UnkStruct_Crash_obj *ob = pair->field_28;
    float impulse = pair->field_20;
    UnkStruct_Crash_obj *oa = pair->field_24;
    UnkStruct_Crash_body *ba = oa->field_C;
    UnkStruct_Crash_body *bb = ob->field_C;
    bool smallA = (unsigned int)oa->field_0 < 3;
    bool smallB = (unsigned int)ob->field_0 < 3;
    if (!(impulse <= 5000.0f)) {
        float lrChance = D_004E129C * (impulse - 5000.0f);
        for (int i = 0; i < 2; i++) {
            UnkStruct_Crash_body *b;
            bool small;
            if (i == 0) { b = ba; small = smallA; } else { b = bb; small = smallB; }
            if (small || (func_001ADC70_inl4(b->field_2420) & 2) != 0) {
                float v = b->field_CC4->field_370;
                if (!(v - 0.5f <= func_001ADC70_inl1(this))) {
                    if (!(lrChance <= func_001ADC70_inl1(this))) {
                        b->field_CC4->field_1016 |= 0xF0;
                    }
                }
            }
        }
    }
    if (smallA && smallB) return;
    UnkStruct_Crash_body *car;
    float lrA, lrB;
    if (smallA || smallB) {
        UnkStruct_Crash_body *veh;
        if (smallA) { car = ba; veh = bb; } else { car = bb; veh = ba; }
        if ((func_001ADC70_inl4(veh->field_2420) & 0x930) == 0) return;
        if (D_0055B7D0[veh->field_242A] == 0x77042838671E0800UL) {   // [C] the tanker's id
            CGtV4d lVel = car->field_B0;
            float lrSpeed = ((float *)&lVel)[3];
            if (!(lrSpeed <= D_004E12A0) && !(pair->field_20 <= 2400.0f)) {
                float t = D_004E12A4 * (pair->field_20 - 2400.0f);
                CGtV3d lDir = CGtV3d(lVel.mData) * (1.0f / lrSpeed);
                float lrAlign = 1.0f - 2.0f * func_001ADC70_inl3(DotProduct(lDir, veh->field_204->mAt));
                UnkStruct_Crash_box lBox = veh->field_1D0;
                CGtV3d lPos = TransformPoint(veh->field_70, car->field_204->mPos);
                CGtV3d lOff = lPos - (lBox.field_0 + lBox.field_10) * 0.5f;
                float z = lOff.Z();
                float hz = func_001ADC70_inl2(lBox.field_0.Z() - lBox.field_10.Z(), D_004E12A8);
                float m = GtMath::Min(t, 1.0f);
                float lrChance = 0.25f * (lrAlign + ((1.0f - func_001ADC70_inl3(z) * (1.0f / hz)) + (m + m)));
                if (func_00131E40(D_004EE040) != 0) lrChance = lrChance * 8.0f;
                if (!(lrChance <= func_001ADC70_inl1(this))) {
                    func_001ADA00(this, veh, z, &lBox, 0);
                    if (func_00131E40(D_004EE040) == 0) return;
                    if (D_01E65499 != 0) return;
                    car->field_3534 = D_00522680;
                    return;
                }
            }
        }
        lrB = D_004E12AC * (pair->field_20 - 10000.0f);
        lrA = D_004E12B0 * (car->field_CC4->field_370 - D_004E0C50);
    } else {
        unsigned int ka = func_001ADC70_inl4(ba->field_2420);
        if ((ka & 0x930) != 0 && (func_001ADC70_inl4(bb->field_2420) & 2) != 0) {
            car = bb;
        } else {
            if ((func_001ADC70_inl4(bb->field_2420) & 0x930) == 0) return;
            if ((ka & 2) == 0) return;
            car = ba;
        }
        lrB = D_004E0EEC * (pair->field_20 - 20000.0f);
        lrA = 2.0f * (car->field_CC4->field_370 - 0.5f);
    }
    UnkStruct_Crash_state *st = car->field_CC4;
    if ((st->field_1015 & 0x10) != 0) return;
    float lrRoll = func_001ADC70_inl1(this);
    if (0.5f * lrA + 0.5f * lrB < lrRoll) return;
    st = car->field_CC4;
    st->field_1000.SetGtV3d(pair->field_0);
    st->field_1000.SetPlus(D_00522680);
    st->field_1015 |= 0x18;
    car->field_CC4->field_1016 |= 0xF0;
    st->field_1015 &= 0xF9;
    if (st->field_1014 != 2) {
        st->field_1014 = 2;
        st->field_1015 |= 1;
    }
}
