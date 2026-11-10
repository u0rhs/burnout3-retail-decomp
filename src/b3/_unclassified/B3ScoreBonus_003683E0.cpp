// CB3ScoreBonus::OnCrashComboResult(ECrashComboEvaluation) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a103: e += n % m before the n+1 store (fills bnez delay slot)).

#include "b3/classes/CB3RaceCar.h"
#include "b3/classes/CB3Score.h"
#include "b3/classes/CB3ScoreBonus.h"
#include "b3/classes/CB3ScoreCategory.h"
#include "b3/classes/EScoreBonusAttackType.h"
#include "b3/classes/EScoreBonusCategory.h"
#include "b3/classes/EScoreBonusEvent.h"
extern "C" void OnAttack__13CB3ScoreBonusF21EScoreBonusAttackTypeP10CB3RaceCari19EScoreBonusCategory(void *, EScoreBonusAttackType, void *, int, EScoreBonusCategory);
extern "C" int OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(void *, int, int, int, bool);
extern "C" void AddScore__8CB3ScoreFii(void *, int, int, int);
struct UnkStruct_003683E0_ev {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
};
struct UnkStruct_003683E0_tbl {
    unsigned char pad_0[0x20];
    UnkStruct_003683E0_ev field_20[1];
};
extern "C" UnkStruct_003683E0_tbl _kaaeBadSlamTypeEvents;
struct UnkStruct_003683E0 {
    unsigned char pad_0[0x148];
    char * field_148;
    unsigned char pad_14C[0x4];
    int field_150;
};
extern "C" void OnCrashComboResult__13CB3ScoreBonusF21ECrashComboEvaluation(UnkStruct_003683E0 * self, void *ev_)
{
    int ev = (int)ev_;
    if (ev == 31) {
        return;
    }
    int e = _kaaeBadSlamTypeEvents.field_20[ev].field_0;
    int bp = _kaaeBadSlamTypeEvents.field_20[ev].field_1;
    int m = _kaaeBadSlamTypeEvents.field_20[ev].field_2;
    if (m != 0) {
        int n = self->field_150;
        e += n % m;
        self->field_150 = n + 1;
        if (self->field_150 > 1000) {
            self->field_150 = 0;
        }
    }
    OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(self, e, bp, 1, 0);
    AddScore__8CB3ScoreFii(self->field_148 + 0x10C0, bp, 1, 2);
}
