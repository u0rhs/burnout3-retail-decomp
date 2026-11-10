// B3PlayerCarPhysics.cpp (E map). Local fork unit.
#include "b3/gamesource/Physics/B3PlayerCarPhysics.h"

// 0x1BD640
void CB3PlayerCarPhysics::Destruct()
{
    CB3AICarPhysics::Destruct();
    mWrongWayWall.Destruct();
}

// 0x1BD670
void CB3PlayerCarPhysics::Release()
{
    CB3AICarPhysics::Release();
    mWrongWayWall.Release();
}
