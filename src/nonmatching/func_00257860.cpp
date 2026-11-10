// NONMATCHING: func_00257860 -- retail 260 / ours 230 instructions, 206 in changed runs
// draftAN C-first: [G] a 100-spark burst for a pending collision entry (UpdateCollisionEffects' D_006481A0 list): spark kind from the entry object's type byte (jump table: 0/3/5 -> 3, 1/7 -> 2, 2 -> 5, 4 -> 1, 6 -> 4, 8 -> none; > 8 leaves the kind unset as retail), retail's dead |v|^2 <= 2500 compare, VU0 R seeded from CGtRandom; each spark at position + (+-0.5), velocity = car velocity (D_0055EFEC[player]+0xB0) x (0.55..1.15, one t) + (+-10, 0..15, +-10), func_00263E80 into this + 0x21F0 + kind x 0xA8 with the manager's time; 252/260, calls identical, FPU/VU op counts equal
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; the jump table (jtbl_004BC940, 9 entries read from the ELF), the entry/object/car offsets, each randomiser's pair (0x270/0x280, 0x250/0x260, one-t 0x230/0x240), draw order and the 100 count traced; audit: only the loop's constant top test (folded by b119p; same 100 iterations)

// func_00257860 -- draftAN (C-first draft). 0x257860, 0x410. Unnamed in every table: placeholder with C linkage; parameter list
// as the caller's archive (UpdateCollisionEffects__17CB3EffectsManagerFv: this, one of the 20 pending entries of D_006481A0 whose
// flag +9 is set). Meanings [G].
// What it does [L]: a burst of 100 sparks at an entry's position: the spark kind from the entry object's type byte (+0x10; 8 =
// none), velocities from the player's car (D_0055EFEC[entry+0xA], +0xB0): each spark at position + (+-0.5 box), velocity =
// car velocity x (0.55..1.15, one t) + (+-10, 0..15, +-10) box; func_00263E80 spawns it into spark array kind (this + 0x21F0 +
// kind x 0xA8) with the manager's time.
// The random draws keep retail's VU0 R sequence (b3/_unclassified/CV3dRandomiser.h; this file's state = retail D_01D9D190 /
// D_004BBFB0, as func_0025D930).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
#include "b3/_unclassified/GtRandom.h"
#include "b3/_unclassified/CV3dRandomiser.h"
using namespace GtMathPs2;

struct UnkStruct_00257860_obj {             // [G] the entry's object
    CGtV3d field_0;                         // [C] the burst position (lq +0)
    unsigned char field_10;                 // [C] the type byte (switch 0..8)
};
struct UnkStruct_00257860_q {               // D_006481A0 entries (0x10), as the caller's UnkStruct_UCE_e9
    UnkStruct_00257860_obj *field_0;
    unsigned char pad_4[5];
    unsigned char field_9;                  // [C] pending flag (the caller clears it)
    signed char field_A;                    // [C] player index (lb)
    unsigned char pad_B[5];
};
struct UnkStruct_00257860_car { unsigned char pad_0[0xB0]; CGtV3d field_B0; };   // [G] the car physics (velocity at +0xB0)
struct UnkStruct_00257860_pl { UnkStruct_00257860_car *field_0; unsigned char pad_4[0x2C]; };   // D_0055EFEC entries (0x30) [C]
extern UnkStruct_00257860_pl D_0055EFEC[];
struct UnkStruct_00257860_mgr {             // [L] CB3EffectsManager (fields as func_0025D930)
    unsigned char pad_0[0x21F0];
    unsigned char field_21F0[6][0xA8];      // [G] spark arrays by kind (func_00263E80's this), kinds 1..5 used here
    unsigned char pad_25E0[0x1D248];
    CGtRandom field_1F828;
    unsigned char pad_1F830[0x18];
    float field_1F848;                      // [G] spawn time, as func_0025D930
};
extern "C" float sqrtf(float);
extern "C" void func_00263E80(void *, const CGtV3d *, const CGtV3d *, int, float);

// the VU0 random generator seeded (vrinit), as func_0025D930_inl1
static inline void func_00257860_inl1(float seed)
{
    u_long128 s;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(seed));
    asm volatile("vrinit $R, %0x" : : "j"(s));
}

// 0x00257860
extern "C" void func_00257860(UnkStruct_00257860_mgr *self, UnkStruct_00257860_q *q)
{
    CGtV3d lPos = q->field_0->field_0;
    CGtV3d lVel = D_0055EFEC[q->field_A].field_0->field_B0;
    int kind;                               // [C] unset for a type byte > 8 (retail reads whatever v1 holds)
    switch (q->field_0->field_10) {
    case 0: case 3: case 5: kind = 3; break;
    case 1: case 7: kind = 2; break;
    case 2: kind = 5; break;
    case 4: kind = 1; break;
    case 6: kind = 4; break;
    case 8: return;
    }
    float lrLengthSq = lVel.GetSquaredLength();
    float lrUnused;                         // [C] 0x257944: retail compares |v|^2 <= 2500 and uses neither result (dead scale)
    if (lrLengthSq <= (float)2500)
        lrUnused = 0.02f * sqrtf(lrLengthSq);
    else
        lrUnused = 1.0f;
    func_00257860_inl1(self->field_1F828.RandomReal());
    CV3dRandomiser lPosRandomiser;
    lPosRandomiser.mVecA = CGtV3d(0.5f, 0.5f, 0.5f);
    lPosRandomiser.mVecB = lPosRandomiser.mVecA - CGtV3d(-0.5f, -0.5f, -0.5f);
    CV3dRandomiser lVelRandomiser;
    lVelRandomiser.mVecA = CGtV3d(10.0f, 15.0f, 10.0f);
    lVelRandomiser.mVecB = lVelRandomiser.mVecA - CGtV3d(-10.0f, 0.0f, -10.0f);
    CV3dRandomiser lVelInheritanceRandomiser;
    lVelInheritanceRandomiser.mVecA = lVel * 1.15f;
    lVelInheritanceRandomiser.mVecB = lVelInheritanceRandomiser.mVecA - lVel * 0.55f;
    for (int n = 100; n-- != 0;) {
        CGtV3d lSpawnPos = lPos + lPosRandomiser.RandomiseXYZ();
        CGtV3d lInherit = lVelInheritanceRandomiser.RandomInterpolate();
        CGtV3d lSpawnVel = lVelRandomiser.RandomiseXYZ() + lInherit;
        func_00263E80(self->field_21F0[kind], &lSpawnPos, &lSpawnVel, 0, self->field_1F848);
    }
}
