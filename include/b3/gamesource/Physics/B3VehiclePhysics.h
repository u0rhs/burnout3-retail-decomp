// CB3VehiclePhysics layout as far as our units use it (local fork). Retail offsets
// (E -> retail field map: research/retail_fieldmap.csv; most members moved by -0x80, deform data by +0x30).
// [assert] = name occurs in E's assert strings; [assert, class L] = class/offset attribution inferred.
// Upstream's d6/ units use their own struct (vehicle_physics.h, unaudited); this header is ours.
#ifndef B3_VEHICLEPHYSICS_H
#define B3_VEHICLEPHYSICS_H

#include "b3/gamesource/Physics/B3CollidingBody.h"

enum EVehicleFlyingBit {};  // type name from GetFlyingObjectIndex; values unknown

struct CB3VehicleData
{
    char _p[0x40];
    CB3VehicleData *field_40;  // passed as CB3VehicleData* to GetFlyingObjectIndex
};

struct UnkStruct_cc4  // pointed to by CB3VehiclePhysics+0xcc4 (retail; E +0xd44). Offsets: E + 0x30
{
    char _p[0x4ac];
    signed char field_4ac[6];  // per-wheel state (0/1 -> 2 in DetachAll)
    signed char field_4b2[8];  // per-body-part state (meanings inferred)
    char _q[0xf78 - 0x4ba];
    float field_f78[6];  // per-wheel float (set to 2.0f)
    float field_f90[8];  // per-body-part float (set to 1000.0f; E 2.0f)
};

// CB3CollidingBody now lives in its own file (B3CollidingBody.h), split out 2026-10-20 per N35's
// literal alienbrain path evidence (GameSource\Physics\B4CollidingBody.cpp) -- it is not part of
// VehiclePhysics in the real source tree, only a base class of it.

struct CB3VehicleDeform
{
    static int GetFlyingObjectIndex(CB3VehicleData *, EVehicleFlyingBit);
};

struct CB3VehiclePhysics : CB3CollidingBody  // base from the tail-call targets
{
    char _v[0xcc0 - sizeof(CB3CollidingBody)];
    CB3VehicleData *field_cc0;
    UnkStruct_cc4 *field_cc4;
    char _w[0x1169 - 0xcc8];
    signed char mnNumWheels;  // [assert] "lpVehiclePhysics->mnNumWheels"
    void Destruct();
    void Release();
    void DetachAll(bool);
};

#endif
