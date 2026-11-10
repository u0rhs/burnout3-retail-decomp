// CB3Score::WasResetWithinTime(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a163 tiny).

struct UnkStruct_a163_w { unsigned char pad_0[0x10CC]; float field_10CC; unsigned char pad_10D0[0x330]; float field_1400; };
static inline bool func_00156080_inl1(float a, float b) { return a > b; }
class CB3Score { public: bool WasResetWithinTime(float); unsigned char pad_0[0xC8]; UnkStruct_a163_w *field_C8; };
// 0x00156080
bool CB3Score::WasResetWithinTime(float t) { UnkStruct_a163_w *w = field_C8; if (w->field_1400 >= 0.0f) { return !func_00156080_inl1(w->field_10CC, w->field_1400 + t); } return false; }
