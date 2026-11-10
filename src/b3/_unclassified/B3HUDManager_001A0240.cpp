// CB3HUD::GetHandlePosition(const GtMathPs2::CGtV2d&) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (lerp inline returning CGtV2d into a named local r then return r).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
class CB3HUD {
public:
    CGtV2d GetHandlePosition(const CGtV2d &);
    unsigned char pad_0[0x48];
    CGtV2d field_48;
    CGtV2d field_50;
};
static inline CGtV2d func_001A0240_inl1(const CGtV2d &a, const CGtV2d &b, const CGtV2d &t) { return a + (b - a) * t; }
// 0x001A0240
// [G] a + (b - a) * t lerp inlined from a function with no known name; no DNAT row in new_names.csv
CGtV2d CB3HUD::GetHandlePosition(const CGtV2d &p0)
{
    CGtV2d r = func_001A0240_inl1(field_48, field_50, p0);
    return r;
}
