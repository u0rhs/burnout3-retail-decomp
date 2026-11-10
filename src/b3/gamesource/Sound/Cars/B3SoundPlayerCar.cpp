// B3SoundPlayerCar.cpp -- translation unit regrouped by tools/tu_merge.py from 1 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3SoundPlayerCar.cpp.
// Area: src/b3/gamesource/Sound/Cars, [L] Revenge (SLUS_212.42) GameSource/Sound/Cars/B4SoundPlayerCar.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundPlayerCar.h"
#include "b3/classes/CB3SoundRaceCar.h"
#include "b3/classes/UnkStruct_gVdbDatabase.h"

extern UnkStruct_gVdbDatabase mpToolBase__Q27GtComms16CGtCommsToolBase;
extern "C" void Unregister__15CB3SoundRaceCarFv(void *);  // CB3SoundRaceCar::Unregister()
extern "C" void RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(int, int);

// CB3SoundPlayerCar::Unregister() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundPlayerCar.cpp.
// 0x0028C670
void CB3SoundPlayerCar::Unregister()
{
    if (field_BF != 0) {
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 36));
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), field_68);
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 4));
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 8));
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 20));
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 24));
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 12));
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 16));
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 28));
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 32));
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 40));
    }
    Unregister__15CB3SoundRaceCarFv(this);
}
