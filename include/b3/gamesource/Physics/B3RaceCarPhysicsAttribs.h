#ifndef B3_B3RACECARPHYSICSATTRIBS_H
#define B3_B3RACECARPHYSICSATTRIBS_H

#include "b3/gamesource/Physics/B3VehiclePhysicsAttribs.h"

class CB3VehiclePhysics;

// [L] folder: Physics/, same domain as CB3VehiclePhysicsAttribs; no literal alienbrain path found
// yet. [L] class relationship: Destruct() tail-calls CB3VehiclePhysicsAttribs::Destruct() directly
// (a `j`, not `jal`), confirming inheritance.
struct CB3RaceCarPhysicsAttribs : CB3VehiclePhysicsAttribs
{
    void CopyToPhysics(CB3VehiclePhysics *physics);  // 0x00252530, not yet decompiled
    void Unregister();                                // 0x00252800, not yet decompiled
    void Register(CB3VehiclePhysics *physics);         // 0x00252C20, not yet decompiled
    void Destruct();   // 0x00254080 [C]: decompiled and objdiff-verified (tail call, Target #18)
    void Release();    // 0x00254090 [C]: decompiled and objdiff-verified (tail call, Target #18)
    bool Prepare(CB3VehiclePhysics *physics);  // 0x002540A0 [C]: decompiled and objdiff-verified (Target #18)
    void Construct();  // 0x002540E0, not yet decompiled
};

#endif
