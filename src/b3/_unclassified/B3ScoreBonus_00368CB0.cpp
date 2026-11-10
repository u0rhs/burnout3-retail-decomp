// CB3ScoreBonus::OnSlam(CB3RaceCar*,EB3ScoreSlamType,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a103: extern C self-struct, fields 0/4/5, tail OnAttack).

#include "b3/classes/CB3RaceCar.h"
#include "b3/classes/CB3Score.h"
#include "b3/classes/CB3ScoreBonus.h"
#include "b3/classes/CB3ScoreCategory.h"
#include "b3/classes/EScoreBonusAttackType.h"
#include "b3/classes/EScoreBonusCategory.h"
#include "b3/classes/EScoreBonusEvent.h"
extern "C" void OnAttack__13CB3ScoreBonusF21EScoreBonusAttackTypeP10CB3RaceCari19EScoreBonusCategory(void *, EScoreBonusAttackType, void *, int, EScoreBonusCategory);
extern "C" int gmanSlamBP__8CB3Score[4];
extern "C" int gmanSuperSlamBP__8CB3Score[4];
struct UnkStruct_00368CB0_2 {
    unsigned char pad_0[0x11DE];
    unsigned char field_11DE;
};
struct UnkStruct_00368CB0 {
    int field_0;
    unsigned char field_4;
    unsigned char field_5;
    unsigned char pad_6[0x142];
    UnkStruct_00368CB0_2 * field_148;
};
extern "C" void OnSlam__13CB3ScoreBonusFP10CB3RaceCar16EB3ScoreSlamTypeb(UnkStruct_00368CB0 * self, void * car, void *type_, bool b)
{
    int type = (int)type_;
    self->field_0 = type;
    self->field_4 = b;
    self->field_5 = self->field_148->field_11DE;
    int bp;
    if (self->field_4 != 0) {
        bp = gmanSuperSlamBP__8CB3Score[type];
    } else {
        bp = gmanSlamBP__8CB3Score[type];
    }
    if (self->field_5 != 0) {
        bp += CB3Score::gmnBurningSlamExtraBP;
    }
    OnAttack__13CB3ScoreBonusF21EScoreBonusAttackTypeP10CB3RaceCari19EScoreBonusCategory(self, (EScoreBonusAttackType)5, car, bp, (EScoreBonusCategory)-1);
}
