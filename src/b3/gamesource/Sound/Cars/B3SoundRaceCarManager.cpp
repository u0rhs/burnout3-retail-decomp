// B3SoundRaceCarManager.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> B3SoundRaceCarManager.cpp.
// Area: src/b3/gamesource/Sound/Cars, [L] Revenge (SLUS_212.42) GameSource/Sound/Cars/B4SoundRaceCarManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundRaceCar.h"
#include "b3/classes/CB3SoundRaceCarManager.h"
#include "b3/classes/EB3RaceCarType.h"

// CB3SoundRaceCarManager::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundRaceCarManager.cpp.
// 0x002ED3C0
void CB3SoundRaceCarManager::Destruct()
{
}

// CB3SoundRaceCarManager::Release() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundRaceCarManager.cpp.
// 0x002ED3D0
void CB3SoundRaceCarManager::Release()
{
}

// CB3SoundRaceCarManager::Prepare() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundRaceCarManager.cpp.
// 0x002ED680
int CB3SoundRaceCarManager::Prepare()
{
    return 1;
}

// CB3SoundRaceCarManager::RelinquishRaceCar(CB3SoundRaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundRaceCarManager.cpp.
// 0x002EEFC0
void CB3SoundRaceCarManager::RelinquishRaceCar(CB3SoundRaceCar* p0)
{
    if (p0 == 0) return;
    p0->field_BD = 0;
}
