// NONMATCHING: HandleBattleSmoke__17CB3EffectsManagerFP17CB3RaceCarPhysicsf -- retail 354 / ours 372 instructions, 310 in changed runs
// draftAM C-first: unless field_13F4->field_18EA, smoke trails (func_0025F0C0, spawn type 0x12 in battle mode, else 0x13, lighting (0, 0.5)): outside battle mode one per body effects point (field_168C, count field_16B6, each with its own accumulator field_1F858[i], scale 0.75), in battle mode three from fixed points between the body box corners (x/y lerps, z 0.8 max / 0.9 min) sharing accumulator 0, the velocity replaced by the matrix's mAt below 0.01 m/s; each line runs back by velocity x dt; 372/354, calls identical, non-stack stores identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; the type select (lb field_215 bne 1), the u8 count loop (decrement then index the accumulator with the new count), every call's 12 arguments (f14 0.75 vs 1.0, t3 0, stack 0), the three box points' lane weights (each x/y lane kept as two products and an add, retail's vmulx/vaddx order), the low-speed velocity swap (c.lt 0.01; audit: arm placement only, bc1f vs bc1t, same condition) traced; lrHealth is never read (as retail)

// CB3EffectsManager::HandleBattleSmoke(CB3RaceCarPhysics*, float) -- draftAM (C-first draft). 0x261870, 0x588. [C] name: the
// mangled symbol; local names from the Revenge STABS of CB4EffectsManager::HandleBattleSmoke (B4EffectsManager.cpp: leSpawnType,
// lLighting, lCarMatrix, lLineStart, lLineEnd, lDelta, lVelocity, lSpawnPoint, lrLength, lu8Count, lpEffectsPoint).
// func_0025F0C0's declaration as the archived callers. The box-point lerp is one local inline (the weights 1/0, 0/1, 0.5/0.5 are
// real products in retail's VU code, kept). Meanings of the fields [G].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_00261870_tag { CGtV3d field_0; unsigned char pad_10[0x20]; };   // [L] Revenge lpEffectsPoint (CB4VehicleTag), 0x30
struct UnkStruct_00261870_body {            // [L] the car's colliding body
    unsigned char pad_0[0xE80];
    CGtV3d field_E80;                       // [G] collision box corner (max)
    CGtV3d field_E90;                       // [G] collision box corner (min)
    unsigned char pad_EA0[0x7EC];
    UnkStruct_00261870_tag * field_168C;    // [L] effects points
    unsigned char pad_1690[0x26];
    unsigned char field_16B6;               // [L] effects point count (Revenge lu8Count)
};
struct UnkStruct_00261870_inst {            // [L] the car's world instance: its matrix, then the body
    CGtMatrix3x4 field_0;
    UnkStruct_00261870_body * field_40;
};
struct UnkStruct_00261870_dm { unsigned char pad_0[0x18EA]; unsigned char field_18EA; };
class CB3RaceCarPhysics {
public:
    unsigned char pad_0[0xB0];
    CGtV4d field_B0;                        // [L] velocity
    unsigned char pad_C0[0x155];
    signed char field_215;                  // [G] 1: battle (damage) mode
    unsigned char pad_216[0xAAA];
    UnkStruct_00261870_inst * field_CC0;
    unsigned char pad_CC4[0x730];
    UnkStruct_00261870_dm * field_13F4;
};
class CB3EffectsManager {
public:
    class CLighting {
    public:
        float field_0;
        float field_4;
    };
    void HandleBattleSmoke(CB3RaceCarPhysics * lpRaceCarPhysics, float lrHealth);
    unsigned char pad_0[0x1F84C];
    float field_1F84C;                      // frame time step
    unsigned char pad_1F850[0x8];
    unsigned char field_1F858[8];           // [G] emit-count accumulators (func_0025F0C0)
};
// signature as the archived callers (UpdateWheelEffects, UpdateRaceCarWorldCollisionEffects); the 12th (stack) argument here 0
extern "C" void func_0025F0C0(CB3EffectsManager *, const void *, const void *, const void *, int, const void *, unsigned char *, int, float, float, float, bool);

// a point between the box corners: x/y lerped (min x (1 - t) + max x t, both products kept), z one corner scaled
static inline CGtV3d func_00261870_inl1(const CGtV3d &lo, const CGtV3d &hi, float sx, float tx, float sy, float ty, ZAxisType z)
{
    CGtV3d p;
    p.SetX(lo.X() * sx + hi.X() * tx);
    p.SetY(lo.Y() * sy + hi.Y() * ty);
    p.SetZ(z);
    return p;
}

// 0x00261870
void CB3EffectsManager::HandleBattleSmoke(CB3RaceCarPhysics * lpRaceCarPhysics, float lrHealth)
{
    // lrHealth: never read in retail [C 0x261870..0x261DF4: no f12 read]
    if (lpRaceCarPhysics->field_13F4->field_18EA != 0)
        return;
    int leSpawnType;
    if (lpRaceCarPhysics->field_215 == 1)
        leSpawnType = 0x12;
    else
        leSpawnType = 0x13;
    CLighting lLighting;
    lLighting.field_0 = 0.0f;
    lLighting.field_4 = 0.5f;
    CGtMatrix3x4 lCarMatrix = lpRaceCarPhysics->field_CC0->field_0;
    CGtV3d lLineStart, lLineEnd, lVelocity;
    if (lpRaceCarPhysics->field_215 != 1) {
        UnkStruct_00261870_body * body = lpRaceCarPhysics->field_CC0->field_40;
        unsigned char lu8Count = body->field_16B6;
        UnkStruct_00261870_tag * lpEffectsPoint = body->field_168C;
        while (lu8Count-- != 0) {
            lLineStart = TransformPoint(lCarMatrix, lpEffectsPoint->field_0);
            lVelocity = CGtV3d(lpRaceCarPhysics->field_B0.mData);
            CGtV3d lDelta = lVelocity * field_1F84C;
            lLineEnd = lLineStart - lDelta;
            float lrLength = (float)lDelta.GetLength();
            func_0025F0C0(this, &lLineStart, &lLineEnd, &lVelocity, leSpawnType, &lLighting, &field_1F858[lu8Count], 0, lrLength, 1.0f,
                          0.75f, false);
            lpEffectsPoint++;
        }
        return;
    }
    UnkStruct_00261870_body * body = lpRaceCarPhysics->field_CC0->field_40;
    lVelocity = CGtV3d(lpRaceCarPhysics->field_B0.mData);
    if ((float)lVelocity.GetLength() < 0.01f)
        lVelocity = lCarMatrix.mAt;
    CGtV3d lDelta = lVelocity * field_1F84C;
    float lrLength = (float)lDelta.GetLength();
    CGtV3d lSpawnPoint;
    lSpawnPoint = func_00261870_inl1(body->field_E90, body->field_E80, 1.0f, 0.0f, 0.9f, 0.1f, body->field_E80.Z() * 0.8f);
    lLineStart = TransformPoint(lCarMatrix, lSpawnPoint);
    lLineEnd = lLineStart - lDelta;
    func_0025F0C0(this, &lLineStart, &lLineEnd, &lVelocity, leSpawnType, &lLighting, &field_1F858[0], 0, lrLength, 1.0f, 1.0f, false);
    lSpawnPoint = func_00261870_inl1(body->field_E90, body->field_E80, 0.0f, 1.0f, 0.9f, 0.1f, body->field_E80.Z() * 0.8f);
    lLineStart = TransformPoint(lCarMatrix, lSpawnPoint);
    lLineEnd = lLineStart - lDelta;
    func_0025F0C0(this, &lLineStart, &lLineEnd, &lVelocity, leSpawnType, &lLighting, &field_1F858[0], 0, lrLength, 1.0f, 1.0f, false);
    lSpawnPoint = func_00261870_inl1(body->field_E90, body->field_E80, 0.5f, 0.5f, 0.8f, 0.2f, body->field_E90.Z() * 0.9f);
    lLineStart = TransformPoint(lCarMatrix, lSpawnPoint);
    lLineEnd = lLineStart - lDelta;
    func_0025F0C0(this, &lLineStart, &lLineEnd, &lVelocity, leSpawnType, &lLighting, &field_1F858[0], 0, lrLength, 1.0f, 1.0f, false);
}
