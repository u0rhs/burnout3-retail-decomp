// CB3HUDBackground2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDBackground2dObject.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (const by-value CGtV4d, data ptr local, sub inline).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_func_003CD920 { unsigned char pad_0[0x10]; };
struct UnkStruct_003CD820_d { float field_0; float field_4; };
struct UnkStruct_003CD820 { unsigned char pad_0[0x20]; UnkStruct_003CD820_d field_20; };
static inline CGtV2d inl1(const CGtV2d &a, const CGtV2d &b) { return a - b; }
extern float D_004E0948;
extern float D_004E094C;
extern UnkStruct_func_003CD920 func_003CD920;
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, unsigned int, unsigned int);
extern "C" void Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(UnkStruct_003CD820 *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, const CGtV4d colour, unsigned int flags)
{
    UnkStruct_003CD820_d *d = &self->field_20;
    d->field_0 = 0.0f;
    d->field_4 = 0.0f;
    if (flags & 1) d->field_0 = D_004E0948 * size.marValues[1] / size.marValues[0];
    if (flags & 2) d->field_4 = D_004E094C * size.marValues[1] / size.marValues[0];
    CGtV2d tp = inl1(pos, size * anchor);
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(self, tp, size, colour, (const void *)&func_003CD920, 64, 8);
}
