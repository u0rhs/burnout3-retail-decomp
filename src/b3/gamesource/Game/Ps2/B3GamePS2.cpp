// B3GamePS2.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 0 function(s) named in research/retail_names.csv -> B3GamePS2.cpp, 1 by a medium-confidence name confirmed by a neighbour, 2 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Game/Ps2, [L] Revenge (SLUS_212.42) GameSource/Game/Ps2/B4GamePS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3Game.h"

struct UnkStruct_001D3FA0;
struct UnkStruct_001D3FA0_1;
struct UnkStruct_func_001D4010;

struct UnkStruct_001D3FA0_1 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual int vfunc_C();
};

struct UnkStruct_001D3FA0 {
    unsigned char pad_0[0x8080];
    UnkStruct_001D3FA0_1 * field_8080;
};

struct UnkStruct_func_001D4010 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_func_001D4010 func_001D4010;
extern "C" void sceCdPOffCallback(void *, void *);

// func_001D3FA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x001D3FA0
extern "C" int func_001D3FA0(UnkStruct_001D3FA0 * self)
{
    if ((self->field_8080 == 0) || (self->field_8080->vfunc_C() != 6)) {
        return 0;
    }
    return 1;
}

// CB3Game::PreparePowerOff() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3GamePS2.cpp.
// 0x001D3FF0
void CB3Game::PreparePowerOff()
{
    sceCdPOffCallback(&func_001D4010, ((char *)this + 0x2DA80));
}
