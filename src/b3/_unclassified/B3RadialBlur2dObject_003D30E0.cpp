// CB3RadialBlur2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RadialBlur2dObject.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (locals before data stores, bool return).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_D_01E90350 { CGtV4d field_0; };
struct UnkStruct_003D30E0 { unsigned char pad_0[0x20]; CGtV2d field_20; CGtV2d field_28; float field_30; float field_34; };
extern UnkStruct_D_01E90350 D_01E90350;
extern "C" void _Render__21CB3RadialBlur2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const void *, const void *);
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, unsigned int, unsigned int);
extern "C" bool Prepare__21CB3RadialBlur2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dff(UnkStruct_003D30E0 *self, const CGtV2d &p0, const CGtV2d &p1, float f0, float f1)
{
    CGtV2d pos(0.0f, 0.0f);
    CGtV2d size(640.0f, 640.0f);
    self->field_20 = p0;
    self->field_28 = p1;
    self->field_30 = f0;
    self->field_34 = f1;
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(self, pos, size, D_01E90350.field_0, (const void *)_Render__21CB3RadialBlur2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv, 64, 24);
    return true;
}
