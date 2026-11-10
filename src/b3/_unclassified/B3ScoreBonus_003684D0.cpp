// CB3ScoreBonus::OnBoostLocked() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (wirefix: OnEvent takes EScoreBonusEvent, per its mangled name).

enum EScoreBonusEvent { EScoreBonusEvent_0 };
class CB3ScoreBonus { public: void OnEvent(EScoreBonusEvent, int, int, bool); void OnBoostLocked(); };
// 0x003684D0
void CB3ScoreBonus::OnBoostLocked() { OnEvent((EScoreBonusEvent)0xC3, 0, -1, false); }
