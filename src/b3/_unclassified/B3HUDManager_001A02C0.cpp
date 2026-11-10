// CB3HUD::GetAlignPos(EHUDAlign) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (named result local r = a + (b - a) * t; return r; gives retail's temp slot order and 0x30 frame).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
enum EHUDAlign { EHUDAlign_Unk0 };
extern CGtV2d D_004B7650[9];
class CB3HUD {
public:
    CGtV2d GetAlignPos(EHUDAlign);
    unsigned char pad_0[0x48];
    CGtV2d field_48;
    CGtV2d field_50;
};

// 0x001A02C0
CGtV2d CB3HUD::GetAlignPos(EHUDAlign p0)
{
    if (p0 == 8) {
        return CGtV2d(0.0f, 0.0f);
    }
    const CGtV2d * t = &D_004B7650[p0];
    // [C] stack investigator: a named result local `r` gives retail's slot order and frame; the plain
    // `return expr;` and by-value inline helpers order the temporaries differently.
    CGtV2d r = field_48 + (field_50 - field_48) * *t;
    return r;
}
