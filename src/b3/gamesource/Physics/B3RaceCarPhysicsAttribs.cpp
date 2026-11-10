#include "b3/gamesource/Physics/B3RaceCarPhysicsAttribs.h"

// 0x00254080 (tail call)
void CB3RaceCarPhysicsAttribs::Destruct()
{
    CB3VehiclePhysicsAttribs::Destruct();
}

// 0x00254090 (tail call)
void CB3RaceCarPhysicsAttribs::Release()
{
    Unregister();
}

// 0x002540A0
bool CB3RaceCarPhysicsAttribs::Prepare(CB3VehiclePhysics *physics)
{
    Register(physics);
    CopyToPhysics(physics);
    return true;
}
