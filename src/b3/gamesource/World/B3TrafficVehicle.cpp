// B3TrafficVehicle.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> B3TrafficVehicle.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4TrafficVehicle.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

// Auto-inlining with deferred code generation (N151): retail's 0x167D10/0x173D30/0x186850 are
// func_00173D30 recursively auto-inlined into itself to -inline level=8 (2^9-1 bodies); StartCrashing
// (lower address) inlines it, which needs deferred codegen (emits in reverse source order).
#pragma auto_inline on
#pragma defer_codegen on

#include "b3/classes/CB3TrafficAxle.h"
#include "b3/classes/CB3TrafficParam.h"
#include "b3/classes/CB3TrafficSystem.h"
#include "b3/classes/CB3TrafficVehicle.h"  // needs field_110/174/17A: see build/vt/inl/tu/CB3TrafficVehicle.h

extern CB3TrafficSystem D_00527440;

struct UnkStruct_D_0055D7F7 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
extern UnkStruct_D_0055D7F7 D_0055D7F7;  // [L] D_00527440 + 0x363B7 (Nahelam's label: gWorld.mTrafficSystem.mbIsOnline)
extern "C" void func_00163E90(CB3TrafficSystem *, CB3TrafficVehicle *, int);  // [L] E: CB3TrafficSystem::AddToDeadTrafficList(CB3TrafficVehicle*,bool)
extern "C" void func_00173D30(CB3TrafficVehicle * self);

// func_00167D10 -- [L] E map: CB3TrafficVehicle::StartCrashing() (first function of B3TrafficVehicle.cpp in E;
// Nahelam's label too). Its 0x93CC bytes are func_00173D30 auto-inlined 8 levels deep (255 bodies).
// 0x00167D10
extern "C" void func_00167D10(CB3TrafficVehicle * self)
{
    self->field_174 |= 2;
    if (D_0055D7F7.field_0 == 0) {
        func_00173D30(self);
    }
}
extern "C" void Release__14CB3TrafficAxleFv(void *);  // CB3TrafficAxle::Release()
extern "C" void Prepare__14CB3TrafficAxleFv(void *);  // CB3TrafficAxle::Prepare()
extern "C" void Construct__14CB3TrafficAxleFv(void *);  // CB3TrafficAxle::Construct()

// CB3TrafficVehicle::RemoveFromLanes() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficVehicle.cpp.
// 0x00172000
void CB3TrafficVehicle::RemoveFromLanes()
{
    CB3TrafficParam * t0 = field_114;
    if (t0 != 0) {
        t0->RemoveFromTrafficLights();
        field_114->Remove();
        D_00527440.AddToDeadTrafficParamList((CB3TrafficParam*)field_114);
        field_114 = 0;
    }
    if (field_118 != 0) {
        field_118 = 0;
        field_11C = -1.0f;
    }
}

// func_00173D30 -- [L] E map: CB3TrafficVehicle::Remove() (between InitalisePosition and Create, as in E; Nahelam's
// label too). Recursive: field_110 is the next vehicle ([L] Nahelam: mpTrailerVehicle). Auto-inlined into itself to
// -inline level=8: 511 bodies, 512 out-of-line self-calls and 256 RemoveFromLanes calls at the leaves (N151).
// 0x00173D30
extern "C" void func_00173D30(CB3TrafficVehicle * self)
{
    self->field_17A |= 1;
    self->RemoveFromLanes();
    if (D_0055D7F7.field_0 != 0) {
        if (self->field_110 != 0) func_00173D30(self->field_110);
    } else {
        if (self->field_110 != 0 && (self->field_174 & 2) == 0) func_00173D30(self->field_110);
    }
    func_00163E90(&D_00527440, self, 1);
    self->field_174 = 0;
}

// CB3TrafficVehicle::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficVehicle.cpp.
// 0x00186810
void CB3TrafficVehicle::Release()
{
    ResetMemberVariables();
    Release__14CB3TrafficAxleFv(this);
    field_30.Release();
}

// CB3TrafficVehicle::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficVehicle.cpp.
// 0x001996D0
int CB3TrafficVehicle::Prepare()
{
    ResetMemberVariables();
    Prepare__14CB3TrafficAxleFv(this);
    field_30.Prepare();
    return 1;
}

// CB3TrafficVehicle::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficVehicle.cpp.
// 0x00199710
void CB3TrafficVehicle::Construct()
{
    ResetMemberVariables();
    Construct__14CB3TrafficAxleFv(this);
    field_30.Construct();
}
