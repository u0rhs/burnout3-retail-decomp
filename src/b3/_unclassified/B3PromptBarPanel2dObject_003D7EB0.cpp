// CPromptBarPanel2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PromptBarPanel2dObject.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (s313: clone of CB3RoundedPanel2dObject::Prepare (simfind 0.55), no flag stores, flags 8).

// CPromptBarPanel2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&)
// [C] name: the mangled symbol in retail's tables. Hand-matched by s313: clone of CB3RoundedPanel2dObject::Prepare
// (B3RoundedPanel2dObject_003A3190.cpp, simfind 0.55) without the two stored flags, flags argument 8.
// Classes and structs are declared here with only what this function touches; field names are placeholders, types [G].

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_D_01E90350 { CGtV4d field_0; };
struct UnkStruct_func_003D7B40 { unsigned char pad_0[0x10]; };
struct UnkStruct_003D7EB0 { unsigned char pad_0[0x20]; CGtV2d field_20; };
extern UnkStruct_D_01E90350 D_01E90350;
extern UnkStruct_func_003D7B40 _Render__23CPromptBarPanel2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv;
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, unsigned int, unsigned int);
// 0x003D7EB0
extern "C" void Prepare__23CPromptBarPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(UnkStruct_003D7EB0 *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size)
{
    self->field_20 = (CGtV2d(1.0f, 1.0f) / size);
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(self, (pos - size * anchor), size, D_01E90350.field_0, (const void *)&_Render__23CPromptBarPanel2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv, 64, 8);
}
