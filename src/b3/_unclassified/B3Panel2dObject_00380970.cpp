// CB3Panel2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,bool,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Panel2dObject.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (clone of proven sibling CB3RoundedPanel2dObject::Prepare (header CGtV2d operators, extern C mangled def)).

// CB3Panel2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,bool,bool)
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Panel2dObject.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders, every type is [G].
// Hand-written from the proven sibling CB3RoundedPanel2dObject::Prepare (B3RoundedPanel2dObject_003A3190.cpp,
// simfind 0.50): reciprocal size at +0x20, flags at +0x28, 1.0f at +0x2C, base Prepare at pos - size*anchor.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_D_01E90350 { CGtV4d field_0; };
struct UnkStruct_func_00380250 { unsigned char pad_0[0x10]; };
struct UnkStruct_00380970 { unsigned char pad_0[0x20]; CGtV2d field_20; int field_28; float field_2C; };
extern UnkStruct_D_01E90350 D_01E90350;
extern UnkStruct_func_00380250 _Render__16CB3Panel2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv;
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, unsigned int, unsigned int);
extern "C" void Prepare__16CB3Panel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dbb(UnkStruct_00380970 *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, bool p3, bool p4)
{
    int f = 0;
    if (p3) f |= 1;
    if (p4) f |= 4;
    self->field_20 = (CGtV2d(1.0f, 1.0f) / size);
    self->field_28 = f;
    self->field_2C = 1.0f;
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(self, (pos - size * anchor), size, D_01E90350.field_0, (const void *)&_Render__16CB3Panel2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv, 64, 16);
}
