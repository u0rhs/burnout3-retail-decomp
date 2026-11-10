// NONMATCHING: HandleBattleSparks__17CB3EffectsManagerFP17CB3RaceCarPhysicsf -- retail 371 / ours 379 instructions, ~41 in changed runs (22 hunks)
// draftAM C-first: battle-mode (field_215 == 1, not field_13F4->field_18EA) sparks scraping along the car's side above 8.94 m/s: count 120..210 by speed (x the density field_1F84C), spawn line from the body box corner (z x 0.95) in world space, 0.8 of the box width along mRight starting 0.1 in, dropped by half the body height; height above ground = ground w + matrix y - spawn y; per spark a random velocity ((r-0.5), 1.5 + r + 0.025 speed, (r-0.5)) + car velocity x (0.8 + 0.19 r), SpawnBouncySpark(.., false); 379/371, calls identical, non-stack stores identical, behaviour_audit clean
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; branch senses (field_215 bne 1, c.lt/bc1t min speed, c.lt/bc1f 62.57 -> 210), the lane ops (SetX/SetY of the box corner, SetZ(z x 0.95), the y drop, the W+Y-Y height), RandomReal draw order z, y, x, then the velocity factor (the source must keep this order: argument evaluation order differs between compilers), the 1/count step (float count, not the int) and the random start offset traced; lrHealth is never read (as retail)

// CB3EffectsManager::HandleBattleSparks(CB3RaceCarPhysics*, float) -- draftAM (C-first draft). 0x2612A0, 0x5CC. [C] name: the
// mangled symbol; local names from the Revenge STABS of CB4EffectsManager::HandleBattleSparks (B4EffectsManager.cpp: lCarMatrix,
// lSpawnPos, lVelocity, lrNumSparks, lnNumSparks, lrHeightAboveGround, lrHealth). Called from UpdateRaceCarEffects (0x261264).
// Constants are the ELF's gp literals with exact bits (0.01864512 = 1 / (62.572224 - 8.938889), 0.099999994 folded).
// Meanings of the fields [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/_unclassified/GtRandom.h"
using namespace GtMathPs2;

struct UnkStruct_002612A0_body {            // [L] the car's colliding body
    unsigned char pad_0[0x18];
    float field_18;                         // [G] body height
    unsigned char pad_1C[0xE64];
    CGtV3d field_E80;                       // [G] collision box corner (max)
    CGtV3d field_E90;                       // [G] collision box corner (min)
};
struct UnkStruct_002612A0_inst {            // [L] the car's world instance: its matrix, then the body
    CGtMatrix3x4 field_0;
    UnkStruct_002612A0_body * field_40;
};
struct UnkStruct_002612A0_st { unsigned char pad_0[0x490]; CGtV4d field_490; };   // [G] w: ground height
struct UnkStruct_002612A0_dm { unsigned char pad_0[0x18EA]; unsigned char field_18EA; };
class CB3RaceCarPhysics {
public:
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;                        // [L] velocity, w: speed
    unsigned char pad_C0[0x155];
    signed char field_215;                  // [G] 1: battle (damage) mode
    unsigned char pad_216[0xAAA];
    UnkStruct_002612A0_inst * field_CC0;
    UnkStruct_002612A0_st * field_CC4;
    unsigned char pad_CC8[0x72C];
    UnkStruct_002612A0_dm * field_13F4;
};
class CB3EffectsManager {
public:
    void HandleBattleSparks(CB3RaceCarPhysics * lpRaceCarPhysics, float lrHealth);
    unsigned char pad_0[0x21F0];
    unsigned char field_21F0[0x1D638];      // [L] a CB3SparkArray (SpawnBouncySpark's this)
    CGtRandom field_1F828;
    unsigned char pad_1F830[0x18];
    float field_1F848;                      // [G] spark lifetime, SpawnBouncySpark's first float
    float field_1F84C;                      // [G] effects density scale
};
extern "C" void SpawnBouncySpark__13CB3SparkArrayFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dffb(void *, const CGtV3d *, const CGtV3d *, float, float, bool);

// (W + Y) in the w lane: no header API yet (operator+(YAxisType, WAxisType) is queued; retail `vaddy.w d, w, yy`)
static inline WAxisType func_002612A0_inl1(WAxisType w, YAxisType y)
{
    u_long128 r;
    asm("vaddy.w %0, %1, %2y" : "=j"(r) : "j"(w.lVector), "j"(y.lVector));
    return WAxisType(r);
}

// 0x002612A0
void CB3EffectsManager::HandleBattleSparks(CB3RaceCarPhysics * lpRaceCarPhysics, float lrHealth)
{
    // lrHealth: never read in retail [C 0x2612A0..0x261868: no f12 read]
    if (lpRaceCarPhysics->field_215 != 1)
        return;
    if (lpRaceCarPhysics->field_13F4->field_18EA != 0)
        return;
    float lrSpeed = (float)lpRaceCarPhysics->field_B0.W();
    if (lrSpeed < 8.938889f)
        return;
    float lrNumSparks;
    if (lrSpeed < 62.572224f)
        lrNumSparks = 0.0f + 120.0f + 90.0f * (0.01864512f * (lrSpeed - 8.938889f));
    else
        lrNumSparks = 210.0f;
    UnkStruct_002612A0_inst * inst = lpRaceCarPhysics->field_CC0;
    lrNumSparks = lrNumSparks * field_1F84C;
    CGtMatrix3x4 lCarMatrix = inst->field_0;
    UnkStruct_002612A0_body * body = inst->field_40;
    CGtV3d lSpawnPos;
    lSpawnPos.SetX(body->field_E90.X());
    lSpawnPos.SetY(body->field_E90.Y());
    lSpawnPos.SetZ(body->field_E90.Z() * 0.95f);
    lSpawnPos = TransformPoint(lCarMatrix, lSpawnPos);
    CGtV3d lSide = lCarMatrix.mRight * (body->field_E80.X() - body->field_E90.X());
    int lnNumSparks = (int)lrNumSparks;
    lSpawnPos += lSide * 0.099999994f; // [C] w = lSpawnPos.w: 0x261410 lqc2 vf3, 0x390(sp); 0x261428 vadd.xyz vf3, vf3, vf1; 0x261430 sqc2 vf3 (`a + b` took b's w)
    CGtV3d lSpan = lSide * 0.8f;
    lSpawnPos.SetY(lSpawnPos.Y() - 0.5f * lpRaceCarPhysics->field_CC0->field_40->field_18);
    float lrHeightAboveGround = (float)(func_002612A0_inl1(lpRaceCarPhysics->field_CC4->field_490.W(), lCarMatrix.mPos.Y()) - lSpawnPos.Y());
    CGtV4d lCarVelocity(lpRaceCarPhysics->field_B0.mData);
    if (lnNumSparks <= 0)
        return;
    CGtV3d lStep = lSpan * (1.0f / lrNumSparks);
    lSpawnPos += lStep * field_1F828.RandomReal(); // [C] w = lSpawnPos.w: 0x2615A8 lqc2 vf3, 0x390(sp); 0x2615C4 vadd.xyz vf3, vf3, vf1; 0x2615C8 sqc2 vf3
    do {
        CGtV3d lVelocity;
        float z = field_1F828.RandomReal() - 0.5f;
        float y = 0.0f + 1.5f + field_1F828.RandomReal() + 0.025f * lrSpeed;
        float x = field_1F828.RandomReal() - 0.5f;
        lVelocity.SetX(x);
        lVelocity.SetY(y);
        lVelocity.SetZ(z);
        lVelocity += CGtV3d(lCarVelocity.mData) * (0.0f + 0.8f + 0.19f * field_1F828.RandomReal()); // [C] w = lVelocity.w: 0x2617CC lqc2 vf3,
        // 0x370(sp); 0x2617F0 vadd.xyz vf3, vf3, vf1; 0x2617F4 sqc2 vf3, 0x370(sp) (`a + b` took the car velocity's w)
        SpawnBouncySpark__13CB3SparkArrayFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dffb(field_21F0, &lSpawnPos, &lVelocity, field_1F848,
                                                                                 lrHeightAboveGround, false);
        lSpawnPos += lStep; // [C] w = lSpawnPos.w: 0x261810 lqc2 vf2, 0x390(sp); 0x26181C vadd.xyz vf2, vf2, vf1; 0x261820 sqc2 vf2 (`a + b` took lStep's w)
        lrHeightAboveGround += (float)lStep.Y();
    } while (--lnNumSparks != 0);
}
