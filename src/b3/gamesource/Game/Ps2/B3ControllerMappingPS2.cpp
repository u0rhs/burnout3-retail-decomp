// B3ControllerMappingPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 2 function(s) named in research/retail_names.csv -> B3ControllerMappingPS2.cpp, 1 placed between two of them by address contiguity (N2).
// Area: src/b3/gamesource/Game/Ps2, [L] Revenge (SLUS_212.42) GameSource/Game/Ps2/B4ControllerMappingPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3ControllerMapping.h"
#include "b3/classes/CB3MenuInput.h"
#include "b3/classes/UnkStruct_D_004EE040.h"
#include "b3/classes/UnkStruct_D_004F50A0.h"

struct UnkStruct_0012FFB0_e1;

struct UnkStruct_0012FFB0_e1 {
    unsigned char pad_0[0x208];
};

extern UnkStruct_D_004F50A0 D_004F50A0;
extern UnkStruct_D_004EE040 D_004EE040;
extern "C" void Construct__12CB3MenuInputFv(void *, unsigned int, void *);  // CB3MenuInput::Construct(), passed 2 more argument(s) [G]
extern "C" float func_0012FC30(void *, int, int);

// func_0012FB10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x0012FB10
extern "C" int func_0012FB10(void *n0_, int p0)
{
    int n0 = (int)n0_;
    float r0 = func_0012FC30((void *)(n0), 8, p0);
    int v0 = 1;
    if (r0 <= 0.0f) {
        v0 = 0;
    }
    return v0;
}

// CB3ControllerMapping::Prepare() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ControllerMappingPS2.cpp.
// 0x0012FFA0
void CB3ControllerMapping::Prepare()
{
    field_C.Prepare();
}

// CB3ControllerMapping::Construct(unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ControllerMappingPS2.cpp.
// 0x0012FFB0
void CB3ControllerMapping::Construct(unsigned int p0)
{
    field_0 = p0;
    field_4 = ((char *)&D_004EE040.field_0[p0] + 0x7300);
    field_8 = ((char *)((char *)&D_004EE040 + ((p0 * 65) << 3)) + 0x79B8);
    Construct__12CB3MenuInputFv(((char *)this + 0xC), p0, &D_004EE040);
    field_128 = D_004F50A0.field_0;
}
