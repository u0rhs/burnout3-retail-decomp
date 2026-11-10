// CB3RaceCarPhysics -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3RACECARPHYSICS_H
#define B3_CLASSES_CB3RACECARPHYSICS_H

#include "b3/GtMath.h"

#include "b3/classes/CB3Burn.h"

class CB3RaceCarPhysics;
struct UnkStruct_0038F3E0_1;

struct UnkStruct_0038F3E0_1 {
    unsigned char pad_0[0x1160];
    unsigned char field_1160;
    unsigned char pad_1161[0x2B];
    CB3Burn field_118C;
};

class CB3RaceCarPhysics {
public:
    void CacheWorldTriangles(int);
    void Destruct();
    void ResetOnTrackWhileCrashing();
    void SetTempTrafficInvulnerable();
    void SetUpCollisionBools();

    unsigned char pad_0[0x204];
    int field_204;
    unsigned char pad_208[0xE];
    unsigned char field_216;
    signed char field_217;
    unsigned char pad_218[0x113B];
    unsigned char field_1353;
    unsigned char pad_1354[0xA0];
    UnkStruct_0038F3E0_1 * field_13F4;
    unsigned char pad_13F8[0x140];
    float field_1538;
    unsigned char pad_153C[0x3];
    unsigned char field_153F;
};

#endif
