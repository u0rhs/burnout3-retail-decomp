// B3PhysicsManager.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3PhysicsManager.cpp, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Physics, [L] Revenge (SLUS_212.42) GameSource/Physics/B4PhysicsManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3ActiveBody.h"
#include "b3/classes/CB3BodyPartPhysics.h"
#include "b3/classes/CB3NetworkCarPhysics.h"
#include "b3/classes/CB3PhysicsManager.h"
#include "b3/classes/CB3PropPhysics.h"
#include "b3/classes/CB3TrafficPhysics.h"
#include "b3/classes/CB3TrafficVehicle.h"
#include "b3/classes/UnkStruct_D_01D9C350.h"

struct UnkStruct_001B8B70;
struct UnkStruct_001B8B70_e2;
struct UnkStruct_001B8B70_e3;
struct UnkStruct_001B8B70_e4;
struct UnkStruct_001B8B70_e5;
struct UnkStruct_001B8B70_e6;
struct UnkStruct_001B8B70_e7;
struct UnkStruct_001B9820;
struct UnkStruct_001B9820_a1;

struct UnkStruct_001B8B70_e2 {
    unsigned char pad_0[0x4590];
};

struct UnkStruct_001B8B70_e3 {
    unsigned char pad_0[0x1580];
};

struct UnkStruct_001B8B70_e4 {
    unsigned char pad_0[0x1560];
};

struct UnkStruct_001B8B70_e5 {
    unsigned char pad_0[0x2430];
};

struct UnkStruct_001B8B70_e6 {
    unsigned char pad_0[0x780];
};

struct UnkStruct_001B8B70_e7 {
    unsigned char pad_0[0x4E0];
};

struct UnkStruct_001B8B70 {
    UnkStruct_001B8B70_e2 field_0[1];  // [G] element count unknown
};

struct UnkStruct_001B9820_a1 {
    float field_0;
};

struct UnkStruct_001B9820 {
    float field_0;
};

extern UnkStruct_D_01D9C350 D_01D9C350;
extern "C" void GetIntervals__17CB3PhysicsManagerFP13CB3ActiveBody(void *, void *, void *, void *, void *);  // CB3PhysicsManager::GetIntervals(CB3ActiveBody*), passed 3 more argument(s) [G]
extern "C" void func_001B7E10(CB3PhysicsManager *, int);
extern "C" void Destruct__19CB3PlayerCarPhysicsFv(void *);  // CB3PlayerCarPhysics::Destruct()
extern "C" void Destruct__15CB3AICarPhysicsFv(void *);  // CB3AICarPhysics::Destruct()
extern "C" void Destruct__20CB3NetworkCarPhysicsFv(void *);  // CB3NetworkCarPhysics::Destruct()
extern "C" void Destruct__17CB3TrafficPhysicsFv(void *);  // CB3TrafficPhysics::Destruct()
extern "C" void Destruct__14CB3PropPhysicsFv(void *);  // CB3PropPhysics::Destruct()
extern "C" void Destruct__18CB3BodyPartPhysicsFv(void *);  // CB3BodyPartPhysics::Destruct()
extern "C" void Destruct__24CB3RaceCarPhysicsAttribsFv(void *);  // CB3RaceCarPhysicsAttribs::Destruct()

// CB3PhysicsManager::AddTrafficVehicle(CB3TrafficVehicle*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManager.cpp.
// 0x001B85F0
void CB3PhysicsManager::AddTrafficVehicle(CB3TrafficVehicle* p0)
{
    int t0 = field_1CB70;
    UnkStruct_001B85F0_e1 *ea0 = &field_0[t0];
    field_60[t0].field_1C = p0;
    field_60[t0].field_14 = ((char *)p0 + 0x70);
    field_60[t0].field_10 = 3;
    field_60[t0].field_18 = (p0->field_B0 + 3712);
    field_60[t0].field_11 = 0;
    field_60[t0].field_12 = 0;
    p0->field_16C = ((char *)ea0 + 0x70);
    GetIntervals__17CB3PhysicsManagerFP13CB3ActiveBody(this, (CB3ActiveBody*)((char *)ea0 + 0x70), ((char *)p0 + 0x70), ((char *)ea0 + 0x70), ea0);
    func_001B7E10(this, field_1CB70);
    field_1CB70 = (field_1CB70 + 1);
}

// func_001B8B70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001B8B70
extern "C" void func_001B8B70(UnkStruct_001B8B70 * self)
{
    for (int i = 0; (i < 2); i++) {
        Destruct__19CB3PlayerCarPhysicsFv(((char *)&self->field_0[i] + 0x1CB80));
    }
    for (int i1 = 0; (i1 < 5); i1++) {
        Destruct__15CB3AICarPhysicsFv(((char *)((char *)self + (i1 * 5504)) + 0x256A0));
    }
    for (int i2 = 0; (i2 < 5); i2++) {
        Destruct__20CB3NetworkCarPhysicsFv(((char *)((char *)self + (i2 * 5472)) + 0x2C220));
    }
    for (int i3 = 0; (i3 < 64); i3++) {
        Destruct__17CB3TrafficPhysicsFv(((char *)((char *)self + (i3 * 9264)) + 0x32D00));
    }
    for (int i4 = 0; (i4 < 32); i4++) {
        Destruct__14CB3PropPhysicsFv(((char *)((char *)self + ((i4 * 15) << 7)) + 0xC3900));
    }
    for (int i5 = 0; (i5 < 64); i5++) {
        Destruct__18CB3BodyPartPhysicsFv(((char *)((char *)self + ((i5 * 39) << 5)) + 0xD2900));
    }
    for (int i6 = 0; (i6 < 6); i6++) {
        Destruct__24CB3RaceCarPhysicsAttribsFv(&D_01D9C350.field_0[i6]);
        D_01D9C350.field_AE0[i6] = 0;
        D_01D9C350.field_AF8[i6] = 0;
    }
}

// CB3PhysicsManager::PostEffectsUpdate() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManager.cpp.
// 0x001B8EF0
void CB3PhysicsManager::PostEffectsUpdate()
{
    UpdateActiveBodyList();
}

// func_001B9820 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001B9820
extern "C" int func_001B9820(UnkStruct_001B9820 * self, UnkStruct_001B9820_a1 * p0)
{
    int v0;
    if (self->field_0 < p0->field_0) {
        v0 = -1;
    } else {
        v0 = 1;
    }
    return v0;
}
