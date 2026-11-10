// B3Burn.cpp -- translation unit regrouped by tools/tu_merge.py from 5 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 5 function(s) named in research/retail_names.csv -> B3Burn.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4Burn.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3BoostEffectParams.h"
#include "b3/classes/CB3Burn.h"

struct UnkStruct_0014DD80;
struct UnkStruct_0014DD80_a1;

struct UnkStruct_0014DD80_a1 {
    unsigned char pad_0[0x10CC];
    float field_10CC;
};

struct UnkStruct_0014DD80 {
    unsigned char pad_0[0x24];
    float field_24;
    unsigned char pad_28[0x2A];
    unsigned char field_52;
};

extern "C" void Stop__20CB3BoostEffectParamsFv(void *);  // CB3BoostEffectParams::Stop()

// func_0014DD80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0014DD80
extern "C" float func_0014DD80(UnkStruct_0014DD80 * self, UnkStruct_0014DD80_a1 * p0)
{
    float v0;
    if (self->field_52 != 0) {
        v0 = (p0->field_10CC - self->field_24);
    } else {
        v0 = 0.0f;
    }
    return v0;
}

// CB3Burn::StopBurn() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Burn.cpp.
// 0x0014DEB0
void CB3Burn::StopBurn()
{
    if (field_55 == 0) {
        field_53 = 1;
        Stop__20CB3BoostEffectParamsFv(this);
    }
}

// CB3Burn::RemoveBurn(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Burn.cpp.
// 0x0014E250
void CB3Burn::RemoveBurn(float p0)
{
    if (field_50 != 0) return;
    if (field_51 != 0) return;
    float t0 = field_38;
    float t1 = field_48;
    field_38 = (t0 - (p0 * t1));
    if (!((t0 - (p0 * t1)) <= 0.0f)) return;
    field_38 = 0.0f;
    if (field_52 != 0) {
        if (field_55 == 0) {
            field_53 = 1;
            Stop__20CB3BoostEffectParamsFv(this);
        }
    }
}

// CB3Burn::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Burn.cpp.
// 0x0014E390
void CB3Burn::Release()
{
}

// CB3Burn::Construct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Burn.cpp.
// 0x0014E5F0
void CB3Burn::Construct()
{
}
