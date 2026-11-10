// CB3RoundedPanel2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RoundedPanel2dObject.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (mwperm: 'CGtV2d inv = CGtV2d(1.0f, 1.0f) / size; self->field_20 = inv' -> 'self->field_20 = (CGtV2d(1.0f, 1.0f) / size);'; 'CGtV2d tp = pos - size * anchor; Prepare__11CGt2dObjectFRCQ2' -> 'Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CG').

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_D_01E90350 { CGtV4d field_0; };
struct UnkStruct_func_003A2850 { unsigned char pad_0[0x10]; };
struct UnkStruct_003A3190 { unsigned char pad_0[0x20]; CGtV2d field_20; unsigned int field_28; unsigned int field_2C; };
extern UnkStruct_D_01E90350 D_01E90350;
extern UnkStruct_func_003A2850 _Render__23CB3RoundedPanel2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv;
extern "C" bool Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, unsigned int, unsigned int);
extern "C" bool Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(UnkStruct_003A3190 *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, unsigned int p0, unsigned int p1)
{
    self->field_20 = (CGtV2d(1.0f, 1.0f) / size);
    self->field_28 = p0;
    self->field_2C = p1;
    return Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(self, (pos - size * anchor), size, D_01E90350.field_0, (const void *)&_Render__23CB3RoundedPanel2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv, 64, 16);
}
