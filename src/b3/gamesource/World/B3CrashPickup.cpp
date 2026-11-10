// B3CrashPickup.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3CrashPickup.cpp, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4CrashPickup.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3CrashPickup.h"

struct UnkStruct_003A0FF0 {
    int field_0;
    unsigned char pad_4[0x4];
    unsigned char field_8;
    unsigned char field_9;
    signed char field_A;
};

// func_003A0FE0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003A0FE0
extern "C" void func_003A0FE0(void *a0 /* passed by every caller, not read here */)
{
}

// Release__14CB3CrashPickupFv -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003A0FF0
extern "C" void Release__14CB3CrashPickupFv(UnkStruct_003A0FF0 *self)
{
    self->field_0 = 0;
    self->field_8 = 0;
    self->field_9 = 0;
    self->field_A = -1;
}

// CB3CrashPickup::Construct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashPickup.cpp.
// 0x003A17E0
void CB3CrashPickup::Construct()
{
    field_0 = 0;
    field_8 = 0;
    field_9 = 0;
    field_A = -1;
}
