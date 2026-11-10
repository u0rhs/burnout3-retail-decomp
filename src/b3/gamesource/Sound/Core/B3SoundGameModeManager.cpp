// B3SoundGameModeManager.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3SoundGameModeManager.cpp.
// Area: src/b3/gamesource/Sound/Core, [L] Revenge (SLUS_212.42) GameSource/Sound/Core/B4SoundGameModeManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundGameModeManager.h"
#include "b3/classes/EB3RaceCarType.h"
#include "b3/classes/UnkStruct_D_00522680.h"

struct UnkStruct_00289AF0 {
    unsigned char pad_0[0x8];
    int field_8;
};

extern UnkStruct_D_00522680 D_00522680;
extern "C" void func_003FAA40(void *);

// CB3SoundGameModeManager::TriggerSpotDucker(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundGameModeManager.cpp.
// 0x00289320
void CB3SoundGameModeManager::TriggerSpotDucker(float p0)
{
    field_C = (p0 + D_00522680.field_0);
}

// func_00289AF0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00289AF0
extern "C" void func_00289AF0(UnkStruct_00289AF0 *self, int p0)
{
    self->field_8 = p0;
}

// CB3SoundGameModeManager::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundGameModeManager.cpp.
// 0x00289B00
void CB3SoundGameModeManager::Destruct()
{
    field_10.Destruct();
    func_003FAA40(((char *)this + 0x3348));
}
