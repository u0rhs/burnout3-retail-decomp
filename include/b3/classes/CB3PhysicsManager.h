// CB3PhysicsManager -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3PHYSICSMANAGER_H
#define B3_CLASSES_CB3PHYSICSMANAGER_H

#include "b3/GtMath.h"

class CB3PhysicsManager;
class CB3TrafficVehicle;
struct UnkStruct_001B85F0_e0;
struct UnkStruct_001B85F0_e1;

struct UnkStruct_001B85F0_e0 {
    unsigned char pad_0[0x10];
    unsigned char field_10;
    unsigned char field_11;
    unsigned char field_12;
    unsigned char pad_13[0x1];
    void * field_14;
    int field_18;
    CB3TrafficVehicle * field_1C;
    unsigned char pad_20[0x10];
};

struct UnkStruct_001B85F0_e1 {
    unsigned char pad_0[0x30];
};

class CB3PhysicsManager {
public:
    void AddTrafficVehicle(CB3TrafficVehicle* p0);
    void ClearCrashingBodies(int);
    void PostEffectsUpdate();
    void StopRaceCarBodyPartsCrashing(int);
    void UpdateActiveBodyList();

    UnkStruct_001B85F0_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_30[0x30];
    UnkStruct_001B85F0_e0 field_60[1];  // [G] element count unknown
    unsigned char pad_90[0x1CAE0];
    int field_1CB70;
};

#endif
