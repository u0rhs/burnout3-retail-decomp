// CB3Burn::GetSegmentSizeInBurn() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Burn.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a163 tiny).

class CB3Burn { public: float GetSegmentSizeInBurn(); unsigned char pad_0[0x30]; int field_30; static float gmarBoostBarSizes[4]; };
// 0x0014DDB0
float CB3Burn::GetSegmentSizeInBurn() { return gmarBoostBarSizes[0] / (float)(field_30 + 1); }
