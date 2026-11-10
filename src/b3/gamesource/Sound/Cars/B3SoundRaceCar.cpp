// B3SoundRaceCar.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> B3SoundRaceCar.cpp.
// Area: src/b3/gamesource/Sound/Cars, [L] Revenge (SLUS_212.42) GameSource/Sound/Cars/B4SoundRaceCar.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundESM.h"
#include "b3/classes/CB3SoundESMManager.h"
#include "b3/classes/CB3SoundRaceCar.h"
#include "b3/classes/UnkStruct__guNumDifferentCars.h"

extern CB3SoundESMManager D_01E78170;
extern UnkStruct__guNumDifferentCars _guNumDifferentCars;

// CB3SoundRaceCar::Destruct() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundRaceCar.cpp.
// 0x0028D7B0
void CB3SoundRaceCar::Destruct()
{
    field_8.Destruct();
}

// CB3SoundRaceCar::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundRaceCar.cpp.
// 0x0028D7C0
void CB3SoundRaceCar::Release()
{
    vfunc_18();
    field_8.Release();
    UnkStruct_0028D7C0_1 * t0 = field_4;
    if (t0 == 0) return;
    t0->vfunc_10();
    D_01E78170.RelinquishESM((CB3SoundESM*)field_4);
    field_4 = 0;
}

// CB3SoundRaceCar::Unregister() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundRaceCar.cpp.
// 0x0028DA00
void CB3SoundRaceCar::Unregister()
{
    if (field_BF != 0) {
        field_68->field_2C = 0;
        field_68 = 0;
        _guNumDifferentCars.field_0 = (_guNumDifferentCars.field_0 + -1);
        field_BF = 0;
    }
}
