// CB3CrashActionDirector -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CB3CRASHACTIONDIRECTOR_H
#define B3_CLASSES_CB3CRASHACTIONDIRECTOR_H

#include "b3/GtMath.h"

class CB3CollidingPair;
class CB3CrashActionDirector;
class CB3CrashStartInfo;
class CB3RaceCarPhysics;
class CB3VehiclePhysics;
struct UnkStruct_001AE480_e0;
struct UnkStruct_001AE4A0_e0;

struct UnkStruct_001AE480_e0 {
    unsigned char pad_0[0x4];
    float field_4;
    unsigned char pad_8[0x34];
};

struct UnkStruct_001AE4A0_e0 {
    CB3VehiclePhysics * field_0;
    unsigned char pad_4[0x1];
    unsigned char field_5;
    unsigned char field_6;
    unsigned char pad_7[0x5];
};

class CB3CrashActionDirector {
public:
    float GetRaceCarCrashTime(int p0);
    void RenderDebugData();
    void SetSympatheticTraffic(int p0, CB3VehiclePhysics* p1);
    void StartRaceCarCrashing(CB3RaceCarPhysics*, int, CB3CollidingPair*, CB3CrashStartInfo*);
    void StopRaceCarCrashing(int p0);

    unsigned char pad_0[0x12C];
    UnkStruct_001AE480_e0 field_12C[1];  // [G] element count unknown
    unsigned char pad_168[0x114];
    UnkStruct_001AE4A0_e0 field_27C[1];  // [G] element count unknown
};

#endif
