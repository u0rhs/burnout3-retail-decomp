// B3RaceCarPhysics.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3RaceCarPhysics.cpp, 1 by a medium-confidence name confirmed by a neighbour, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Physics, [L] Revenge (SLUS_212.42) GameSource/Physics/B4RaceCarPhysics.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3RaceCarPhysics.h"
#include "b3/classes/CB3VehiclePhysics.h"
#include "b3/classes/UnkStruct_D_00522660.h"
#include "b3/classes/UnkStruct_D_0052267C.h"
#include "b3/classes/UnkStruct_D_00522680.h"

struct UnkStruct_001C5040;

struct UnkStruct_001C5040 {
    unsigned char pad_0[0x210];
    unsigned char field_210;
};

extern UnkStruct_D_00522680 D_00522680;
extern UnkStruct_D_0052267C D_0052267C;
extern UnkStruct_D_00522660 D_00522660;
extern "C" void CollideWheels__17CB3VehiclePhysicsFv(void *);  // CB3VehiclePhysics::CollideWheels()
extern "C" void UpdateSuspension__17CB3VehiclePhysicsFf(void *, float);  // CB3VehiclePhysics::UpdateSuspension(float)
extern "C" int TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(void *, int, signed char);
extern "C" void func_001CEE10(UnkStruct_001C5040 *);

// CB3RaceCarPhysics::SetUpCollisionBools() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3RaceCarPhysics.cpp.
// 0x001BEA60
void CB3RaceCarPhysics::SetUpCollisionBools()
{
}

// CB3RaceCarPhysics::SetTempTrafficInvulnerable() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCarPhysics.cpp.
// 0x001BEA70
void CB3RaceCarPhysics::SetTempTrafficInvulnerable()
{
    field_153F = 1;
    field_1353 = (field_1353 | 2);
    field_1538 = D_00522680.field_0;
}

// CB3RaceCarPhysics::ResetOnTrackWhileCrashing() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCarPhysics.cpp.
// 0x001BFE00
void CB3RaceCarPhysics::ResetOnTrackWhileCrashing()
{
    int r0 = TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(((char *)((char *)&D_00522660 + (field_217 * 460)) + 0x12A348), (field_204 + 48), field_217);
    field_216 = r0;
    CacheWorldTriangles(0);
    CollideWheels__17CB3VehiclePhysicsFv(this);
    UpdateSuspension__17CB3VehiclePhysicsFf(this, D_0052267C.field_0);
}

// CB3RaceCarPhysics::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RaceCarPhysics.cpp.
// 0x001C0E70
void CB3RaceCarPhysics::Destruct()
{
}

// func_001C5040 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001C5040
extern "C" void func_001C5040(UnkStruct_001C5040 * self)
{
    if (self->field_210 != 0) {
        func_001CEE10(self);
    }
}
