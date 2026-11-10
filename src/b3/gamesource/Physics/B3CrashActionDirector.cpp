// B3CrashActionDirector.cpp -- translation unit regrouped by tools/tu_merge.py from 8 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> B3CrashActionDirector.cpp, 4 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Physics, [L] Revenge (SLUS_212.42) GameSource/Physics/B4CrashActionDirector.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/classes/CB3CrashActionDirector.h"
#include "b3/classes/CB3PhysicsManager.h"
#include "b3/classes/CB3VehiclePhysics.h"

struct UnkStruct_001AE4A0_4;
struct UnkStruct_001AE630;
struct UnkStruct_001AE630_e0;
struct UnkStruct_001AF410;
struct UnkStruct_001AF3C0;
struct UnkStruct_001AF3C0_a1;
struct UnkStruct_001AF420;
struct UnkStruct_001AF420_a1;

struct UnkStruct_001AE4A0_4 {
    unsigned char pad_0[0x116B];
    unsigned char field_116B;
    unsigned char pad_116C[0x12BC];
    unsigned char field_2428;
};

struct UnkStruct_001AE630_e0 {
    unsigned char pad_0[0x4];
    float field_4;
    unsigned char pad_8[0x34];
};

struct UnkStruct_001AE630 {
    unsigned char pad_0[0x12C];
    UnkStruct_001AE630_e0 field_12C[1];  // [G] element count unknown
};

struct UnkStruct_001AF3C0_a1 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    short field_30;
    unsigned char pad_32[0x2];
    float field_34;
    int field_38;
    unsigned char pad_3C[0x4];
    u_long128 field_40;
    u_long128 field_50;
};

struct UnkStruct_001AF3C0 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    short field_30;
    unsigned char pad_32[0x2];
    float field_34;
    int field_38;
    unsigned char pad_3C[0x4];
    u_long128 field_40;
    u_long128 field_50;
};

struct UnkStruct_001AF420_a1 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    u_long128 field_30;
};

struct UnkStruct_001AF420 {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    u_long128 field_30;
};

extern UnkStruct_001AE4A0_4 * D_00645070[];  // [G] element count unknown
extern CB3PhysicsManager D_0055EF70;

// CB3CrashActionDirector::GetRaceCarCrashTime(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashActionDirector.cpp.
// 0x001AE480
float CB3CrashActionDirector::GetRaceCarCrashTime(int p0)
{
    return field_12C[p0].field_4;
}

// CB3CrashActionDirector::SetSympatheticTraffic(int,CB3VehiclePhysics*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashActionDirector.cpp.
// 0x001AE4A0
void CB3CrashActionDirector::SetSympatheticTraffic(int p0, CB3VehiclePhysics* p1)
{
    field_27C[p0].field_6 = 0;
    UnkStruct_001AE4A0_4 * t0 = D_00645070[p0];
    if (t0->field_2428 == 0) {
        t0->field_116B = 1;
        field_27C[p0].field_5 = 0;
        field_27C[p0].field_0 = (CB3VehiclePhysics *)p1;
    }
}

// func_001AE630 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001AE630
extern "C" void func_001AE630(UnkStruct_001AE630 * self, int p0)
{
    self->field_12C[p0].field_4 = -1.0f;
    D_0055EF70.ClearCrashingBodies(p0);
}

// CB3CrashActionDirector::StopRaceCarCrashing(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashActionDirector.cpp.
// 0x001AE660
void CB3CrashActionDirector::StopRaceCarCrashing(int p0)
{
    field_12C[p0].field_4 = -1.0f;
    D_0055EF70.ClearCrashingBodies(p0);
}

// func_001AF3C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001AF3C0
extern "C" UnkStruct_001AF3C0 * func_001AF3C0(UnkStruct_001AF3C0 * self, const UnkStruct_001AF3C0_a1 * p0)
{
    self->field_0 = p0->field_0;
    self->field_10 = p0->field_10;
    self->field_20 = p0->field_20;
    self->field_30 = p0->field_30;
    self->field_34 = p0->field_34;
    self->field_38 = p0->field_38;
    self->field_40 = p0->field_40;
    self->field_50 = p0->field_50;
    return self;
}

// func_001AF410 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001AF410
extern "C" UnkStruct_001AF410 * func_001AF410(UnkStruct_001AF410 *self)
{
    return self;
}

// func_001AF420 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001AF420
extern "C" UnkStruct_001AF420 * func_001AF420(UnkStruct_001AF420 * self, const UnkStruct_001AF420_a1 * p0)
{
    self->field_0 = p0->field_0;
    self->field_10 = p0->field_10;
    self->field_20 = p0->field_20;
    self->field_30 = p0->field_30;
    return self;
}

// CB3CrashActionDirector::RenderDebugData() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashActionDirector.cpp.
// 0x001B20C0
void CB3CrashActionDirector::RenderDebugData()
{
}
