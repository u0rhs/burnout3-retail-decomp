// B3PlayerCarPhysics.cpp (E map). Local fork unit.
#include "b3/gamesource/Physics/B3PlayerCarPhysics.h"

// 0x1BDF10
void CB3PlayerCarPhysics::Construct()
{
    CB3AICarPhysics::Construct();
    field_215 = true;
    mWrongWayWall.Construct();
    field_4583 = true;
    field_4582 = false;
    field_4584 = false;
}
