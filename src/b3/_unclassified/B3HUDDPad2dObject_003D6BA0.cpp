// CB3HUDDPad2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDDPad2dObject.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (const by-value CGtV4d, sub inline).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_func_003D6C30 { unsigned char pad_0[0x10]; };
extern UnkStruct_func_003D6C30 func_003D6C30;
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, unsigned int, unsigned int);
static inline CGtV2d inl1(const CGtV2d &a, const CGtV2d &b) { return a - b; }
extern "C" void Prepare__18CB3HUDDPad2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(void *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, const CGtV4d colour)
{
    const CGtV2d tp = inl1(pos, size * anchor);
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(self, tp, size, colour, (const void *)&func_003D6C30, 64, 1);
}
