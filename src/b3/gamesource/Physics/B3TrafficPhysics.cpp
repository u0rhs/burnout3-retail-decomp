// B3TrafficPhysics.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3TrafficPhysics.cpp, 1 by a medium-confidence name confirmed by a neighbour.
// Area: src/b3/gamesource/Physics, [L] Revenge (SLUS_212.42) GameSource/Physics/B4TrafficPhysics.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3TrafficPhysics.h"
#include "b3/classes/CB3VehiclePhysics.h"

extern "C" void func_001CBA30(CB3TrafficPhysics *);
extern "C" void Destruct__17CB3VehiclePhysicsFv(CB3TrafficPhysics *);  // CB3VehiclePhysics::Destruct()
extern "C" void Release__17CB3VehiclePhysicsFv(void *);  // CB3VehiclePhysics::Release()
extern "C" void func_001CFD20(CB3TrafficPhysics *);

// CB3TrafficPhysics::StopCrashing() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficPhysics.cpp.
// 0x002502D0
void CB3TrafficPhysics::StopCrashing()
{
    if (field_210 == 0) return;
    func_001CBA30(this);
}

// CB3TrafficPhysics::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficPhysics.cpp.
// 0x00250300
void CB3TrafficPhysics::Destruct()
{
    Destruct__17CB3VehiclePhysicsFv(this);
}

// CB3TrafficPhysics::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficPhysics.cpp.
// 0x00250310
void CB3TrafficPhysics::Release()
{
    vfunc_14();
    Release__17CB3VehiclePhysicsFv(this);
}

// CB3TrafficPhysics::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3TrafficPhysics.cpp.
// 0x00251460
void CB3TrafficPhysics::Construct()
{
    func_001CFD20(this);
    field_215 = 4;
}
