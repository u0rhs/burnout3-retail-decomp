// B3HUDBoostBar.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3HUDBoostBar.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Hud, [L] Revenge (SLUS_212.42) GameSource/Hud/B4HUDBoostBar.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3HUDBoostBar.h"

struct UnkStruct_001A4150;

struct UnkStruct_001A4150 {
    unsigned char pad_0[0x56A];
    unsigned char field_56A;
};

extern "C" void BarUpdate__14CB3HUDBoostBarFf(void *, float);  // CB3HUDBoostBar::BarUpdate(float)
extern "C" void MessagesUpdate__14CB3HUDBoostBarFf(UnkStruct_001A4150 *, float);

// func_001A4150 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001A4150
extern "C" void func_001A4150(UnkStruct_001A4150 * self, float f0)
{
    BarUpdate__14CB3HUDBoostBarFf(self, f0);
    if (self->field_56A != 0) {
        MessagesUpdate__14CB3HUDBoostBarFf(self, f0);
    }
}

// CB3HUDBoostBar::StaticConstruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDBoostBar.cpp.
// 0x001A8490
void CB3HUDBoostBar::StaticConstruct()
{
}
