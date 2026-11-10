// CB3ScoreBonus::OnTailgate(CB3RaceCar*,CB3ScoreCategory*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a103: block form if(c!=-1)).

#include "b3/classes/CB3RaceCar.h"
#include "b3/classes/CB3Score.h"
#include "b3/classes/CB3ScoreBonus.h"
#include "b3/classes/CB3ScoreCategory.h"
#include "b3/classes/EScoreBonusAttackType.h"
#include "b3/classes/EScoreBonusCategory.h"
#include "b3/classes/EScoreBonusEvent.h"
extern "C" void OnAttack__13CB3ScoreBonusF21EScoreBonusAttackTypeP10CB3RaceCari19EScoreBonusCategory(void *, EScoreBonusAttackType, void *, int, EScoreBonusCategory);
extern "C" int gmanTailgateBP__8CB3Score[3];
extern unsigned char D_004C7AA6[];
extern "C" int OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(void *, int, int, int, bool);
extern "C" void AddScore__8CB3ScoreFii(void *, int, int, int);
struct UnkStruct_00368D60 {
    unsigned char pad_0[0x148];
    char * field_148;
};
extern "C" void OnTailgate__13CB3ScoreBonusFP10CB3RaceCarP16CB3ScoreCategory(UnkStruct_00368D60 * self, void * car, CB3ScoreCategory * cat)
{
    int c = cat->field_11;
    if (c != -1) {
        int bp = gmanTailgateBP__8CB3Score[c];
        OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(self, D_004C7AA6[c], bp, 1, 0);
        AddScore__8CB3ScoreFii(self->field_148 + 0x10C0, bp, 1, 1);
    }
}
