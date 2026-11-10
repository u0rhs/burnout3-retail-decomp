// B3SoundAICar.cpp -- translation unit regrouped by tools/tu_merge.py from 4 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 4 function(s) named in research/retail_names.csv -> B3SoundAICar.cpp.
// Area: src/b3/gamesource/Sound/Cars, [L] Revenge (SLUS_212.42) GameSource/Sound/Cars/B4SoundAICar.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3SoundAICar.h"
#include "b3/classes/CB3SoundRaceCar.h"
#include "b3/classes/CGtSoundBank.h"
#include "b3/classes/CGtSoundBankManager.h"
#include "b3/classes/CGtSoundVirtualVoice.h"
#include "b3/classes/UnkStruct_D_004E1BA0.h"
#include "b3/classes/UnkStruct_gVdbDatabase.h"

extern UnkStruct_gVdbDatabase mpToolBase__Q27GtComms16CGtCommsToolBase;
extern CGtSoundBankManager D_01E75648;
extern UnkStruct_D_004E1BA0 D_004E1BA0;
extern "C" void Unregister__15CB3SoundRaceCarFv(void *);  // CB3SoundRaceCar::Unregister()
extern "C" void RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv(int, int);
extern "C" void Release__15CB3SoundRaceCarFv(void *);  // CB3SoundRaceCar::Release()
extern "C" void Construct__15CB3SoundRaceCarFv(void *);  // CB3SoundRaceCar::Construct()

// CB3SoundAICar::Unregister() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundAICar.cpp.
// 0x0028B9D0
void CB3SoundAICar::Unregister()
{
    if (field_BF != 0) {
        RemoveEntry__Q27GtComms16CGtCommsDatabaseFPv((mpToolBase__Q27GtComms16CGtCommsToolBase.field_0 + 16), (field_68 + 36));
    }
    Unregister__15CB3SoundRaceCarFv(this);
}

// CB3SoundAICar::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundAICar.cpp.
// 0x0028BAC0
void CB3SoundAICar::Destruct()
{
    CGtSoundVirtualVoice * t0 = field_150;
    if (t0 != 0) {
        t0->ForgetMe(0.5f);
        field_150 = 0;
        field_158 = 0;
    }
    CGtSoundVirtualVoice * t1 = field_154;
    if (t1 != 0) {
        t1->ForgetMe(0.5f);
        field_154 = 0;
        field_15C = 0;
    }
    field_140 = 0;
}

// CB3SoundAICar::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundAICar.cpp.
// 0x0028BB30
void CB3SoundAICar::Release()
{
    Release__15CB3SoundRaceCarFv(this);
    CGtSoundVirtualVoice * t0 = field_150;
    if (t0 != 0) {
        t0->ForgetMe(0.5f);
        field_150 = 0;
        field_158 = 0;
    }
    CGtSoundVirtualVoice * t1 = field_154;
    if (t1 != 0) {
        t1->ForgetMe(0.5f);
        field_154 = 0;
        field_15C = 0;
    }
    field_140 = 0;
    D_01E75648.UnloadBank((CGtSoundBank*)field_144);
    field_144 = 0;
}

// CB3SoundAICar::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundAICar.cpp.
// 0x0028BF40
void CB3SoundAICar::Construct()
{
    Construct__15CB3SoundRaceCarFv(this);
    if (D_004E1BA0.field_0 == -1) {
        D_004E1BA0.field_0 = 0;
    }
    field_144 = 0;
    field_150 = 0;
    field_154 = 0;
}
