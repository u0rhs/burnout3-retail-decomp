// CB3PlayerCarPhysics layout as far as our units use it (local fork). Retail offsets.
// Hierarchy from resolved call targets: CB3PlayerCarPhysics : CB3AICarPhysics; member +0x1590 is a CB3WrongWayWall.
#ifndef B3_PLAYERCARPHYSICS_H
#define B3_PLAYERCARPHYSICS_H

#include "b3/_unclassified/B3WrongWayWall.h"

struct CB3AICarPhysics
{
    void Destruct();
    void Release();
    void Construct();
};

struct CB3PlayerCarPhysics : CB3AICarPhysics
{
    char _a[0x215];
    bool field_215;
    char _b[0x1590 - 0x216];
    CB3WrongWayWall mWrongWayWall;  // name: B2 DWARF CPlayerCarPhysics::mWrongWayWall (type CWrongWayWall)
    char _c[0x4582 - 0x1590 - sizeof(CB3WrongWayWall)];
    bool field_4582, field_4583, field_4584;
    void Destruct();
    void Release();
    void Construct();
};

#endif
