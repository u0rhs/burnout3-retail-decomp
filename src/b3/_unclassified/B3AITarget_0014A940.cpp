// CB3AITarget::GetCurrentFwdFrac() const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AITarget.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a163 tiny).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_a163_s { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_a163_r { unsigned char pad_0[0x204]; UnkStruct_a163_s *field_204; };
struct UnkStruct_a163_o { unsigned char pad_0[0x2430]; UnkStruct_a163_r *field_2430; };
extern "C" float GetLeftFrac__9CB3AILaneCFUsQ29GtMathPs26CGtV3df(void *, unsigned short, CGtV3d, float);
class CB3AITarget { public: float GetCurrentFwdFrac() const; unsigned char pad_0[4]; UnkStruct_a163_o *field_4; unsigned char pad_8[0x1CC]; void *field_1D4; unsigned short field_1D8; };
// 0x0014A940
float CB3AITarget::GetCurrentFwdFrac() const { return GetLeftFrac__9CB3AILaneCFUsQ29GtMathPs26CGtV3df(field_1D4, field_1D8, field_4->field_2430->field_204->field_30, 0.0f); }
