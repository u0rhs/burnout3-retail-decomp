// B3EffectsManager.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3EffectsManager.cpp.
// Area: src/b3/gamesource/World, [L] Revenge (SLUS_212.42) GameSource/World/B4EffectsManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3DebrisArray.h"
#include "b3/classes/CB3EffectsManager.h"
#include "b3/classes/CB3ParticleArray.h"
#include "b3/classes/CB3PopcornArray.h"
#include "b3/classes/CB3SparkArray.h"
#include "b3/classes/UnkStruct_D_01EA4BB0.h"

struct UnkStruct_00262660_e1;
struct UnkStruct_00262660_e2;
struct UnkStruct_00262660_e3;

struct UnkStruct_00262660_e1 {
    unsigned char pad_0[0x150];
};

struct UnkStruct_00262660_e2 {
    unsigned char pad_0[0x40];
};

struct UnkStruct_00262660_e3 {
    unsigned char pad_0[0xA8];
};

extern UnkStruct_D_01EA4BB0 D_01EA4BB0;
extern "C" void Release__14CB3DebrisArrayFv(void *);  // CB3DebrisArray::Release()
extern "C" void Release__16CB3ParticleArrayFv(void *);  // CB3ParticleArray::Release()
extern "C" void Release__15CB3PopcornArrayFv(void *);  // CB3PopcornArray::Release()
extern "C" void Release__13CB3SparkArrayFv(void *);  // CB3SparkArray::Release()
extern "C" void func_0039AD40(void *);
extern "C" void func_00375D80(void *);

// CB3EffectsManager::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EffectsManager.cpp.
// 0x00262660
void CB3EffectsManager::Release()
{
    func_0039AD40(&D_01EA4BB0);
    for (int i = 0; (i < 4); i++) {
        Release__14CB3DebrisArrayFv(((char *)&field_0[i] + 0xB0));
    }
    for (int i1 = 0; (i1 < 24); i1++) {
        Release__16CB3ParticleArrayFv(((char *)((char *)this + (((((i1 << 3) - i1) << 2) - ((i1 << 3) - i1)) << 4)) + 0x170));
    }
    for (int i2 = 0; (i2 < 4); i2++) {
        Release__15CB3PopcornArrayFv(((char *)((char *)this + (i2 << 6)) + 0x20F0));
    }
    for (int i3 = 0; (i3 < 6); i3++) {
        Release__13CB3SparkArrayFv(((char *)((char *)this + (((((i3 << 3) - i3) << 2) - ((i3 << 3) - i3)) << 3)) + 0x21F0));
    }
    field_2600.Release();
    func_00375D80(((char *)this + 0x16C80));
}
