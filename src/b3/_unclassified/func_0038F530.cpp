// OnPlayerCarDeath__26CB3OnlineRoadRageRaceLogicFP12CB3PlayerCar -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3ScoreBonus.h"
#include "b3/classes/EB3ScoreMedalType.h"
#include "b3/classes/EScoreBonusEvent.h"

struct UnkStruct_0038F530_a1;

struct UnkStruct_0038F530_a1 {
    unsigned char pad_0[0x1161];
    unsigned char field_1161;
    unsigned char pad_1162[0x82];
    CB3ScoreBonus field_11E4;
};

// 0x0038F530
extern "C" void OnPlayerCarDeath__26CB3OnlineRoadRageRaceLogicFP12CB3PlayerCar(int n0, UnkStruct_0038F530_a1 * p0)
{
    if (p0->field_1161 != 0) return;
    p0->field_1161 = 1;
    p0->field_11E4.OnEvent((EScoreBonusEvent)134, 0, -1, 1);
}
