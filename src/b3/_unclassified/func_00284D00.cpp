// OnRaceCarCollision__18CB3HUDSoundManagerF21ERaceCarCollisionTypeP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsf -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

#include "b3/classes/CB3HUDSoundManager.h"
#include "b3/classes/CB3RaceCarPhysics.h"

struct UnkStruct_00284D00_1;
struct UnkStruct_00284D00_a2;

struct UnkStruct_00284D00_a2 {
    unsigned char pad_0[0x204];
    UnkStruct_00284D00_1 * field_204;
};

struct UnkStruct_00284D00_1 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
};

// 0x00284D00
extern "C" void OnRaceCarCollision__18CB3HUDSoundManagerF21ERaceCarCollisionTypeP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsf(CB3HUDSoundManager * self, int p0, UnkStruct_00284D00_a2 * p1, int p2)
{
    GtMathPs2::CGtV3d vt10;
    vt10.mData = p1->field_204->field_30;
    self->Shunt(vt10, (CB3RaceCarPhysics*)p1, (CB3RaceCarPhysics*)p2);
}
