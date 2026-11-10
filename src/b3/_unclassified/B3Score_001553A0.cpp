// CB3Score::GetLastContactCar(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a163 tiny).

class CB3RaceCar;
class CB3Score { public: CB3RaceCar *GetLastContactCar(float); unsigned char pad_0[0xC]; float field_C; unsigned char pad_10[0x5DC]; CB3RaceCar *field_5EC; float field_5F0; };
// 0x001553A0
CB3RaceCar *CB3Score::GetLastContactCar(float t) { if (field_5F0 == -1.0f) return 0; if (field_5F0 + t < field_C) return 0; return field_5EC; }
