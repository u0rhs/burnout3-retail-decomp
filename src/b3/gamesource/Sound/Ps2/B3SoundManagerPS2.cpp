// B3SoundManagerPS2.cpp -- translation unit regrouped by tools/tu_merge.py from 2 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3SoundManagerPS2.cpp, 1 by a medium-confidence name confirmed by a neighbour.
// Area: src/b3/gamesource/Sound/Ps2, [L] Revenge (SLUS_212.42) GameSource/Sound/Ps2/B4SoundManagerPS2.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundManager.h"
#include "b3/classes/UnkStruct_D_004E1C0C.h"

struct UnkStruct_00276990_1;

struct UnkStruct_00276990_1 {
    int field_0;
    int field_4;
    int field_8;
    unsigned char pad_C[0x4];
};

extern UnkStruct_D_004E1C0C D_004E1C0C;
extern "C" int _rwaCoreOpen(int, int);
extern "C" void RwaCoreRegisterDefaultObjects();
extern "C" void RwaSPU2RegisterUsingInterface();
extern "C" int RwaSPU2OutputCreate(UnkStruct_00276990_1 *, int, int, int);
extern "C" void RwaSPU2HWResourceDMAChannelLock(int);

// CB3SoundManager::CloseRenderWare() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3SoundManagerPS2.cpp.
// 0x00276980
void CB3SoundManager::CloseRenderWare()
{
    field_1EE0 = 0;
}

// CB3SoundManager::OpenRenderWare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundManagerPS2.cpp.
// 0x00276990
void CB3SoundManager::OpenRenderWare()
{
    UnkStruct_00276990_1 local;  // [G] the frame's one local (size: up to the frame top)
    int r0 = _rwaCoreOpen(0, 1);
    D_004E1C0C.field_0 = r0;
    RwaCoreRegisterDefaultObjects();
    RwaSPU2RegisterUsingInterface();
    local.field_8 = 1;
    local.field_0 = 48;
    local.field_4 = 0;
    int r3 = RwaSPU2OutputCreate(&local, 2, 0, 0);
    field_1ED8 = r3;
    RwaSPU2HWResourceDMAChannelLock(0);
    field_1EE0 = 1;
}
