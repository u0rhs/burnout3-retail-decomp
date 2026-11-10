// CB3ScoreBonus::OnGrind(CB3RaceCar*,CB3ScoreCategory*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (OnAttack call extern C).

struct UnkStruct_a166_cat { unsigned char pad_0[0x11]; signed char field_11; };
extern "C" int gmanGrindingBP__8CB3Score[8];
extern "C" void OnAttack__13CB3ScoreBonusF21EScoreBonusAttackTypeP10CB3RaceCari19EScoreBonusCategory(void *self, int type, void *car, int bp, int cat);
extern "C" void OnGrind__13CB3ScoreBonusFP10CB3RaceCarP16CB3ScoreCategory(void *self, void *car, UnkStruct_a166_cat *c) {
  int i = c->field_11;
  if (i != -1) OnAttack__13CB3ScoreBonusF21EScoreBonusAttackTypeP10CB3RaceCari19EScoreBonusCategory(self, 1, car, gmanGrindingBP__8CB3Score[i], i);
}
