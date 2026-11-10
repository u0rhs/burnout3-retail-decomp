// CB3AITargetSpline::GetTargetPosition() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AITarget.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a163 tiny).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
class CB3AITargetSpline { public: CGtV3d GetTargetPosition(); unsigned char pad_0[0x10]; CGtV3d field_10; unsigned char pad_20[0x50]; CGtV3d field_70; unsigned char pad_80[0xD1]; unsigned char field_151; };
// 0x00149E80
CGtV3d CB3AITargetSpline::GetTargetPosition() { if (field_151 != 0) return field_70; return field_10; }
