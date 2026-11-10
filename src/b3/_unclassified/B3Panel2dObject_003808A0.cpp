// CB3Panel2dObject::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,unsigned int,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Panel2dObject.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near29: clone of CB3RoundedPanel2dObject::Prepare (CGtV2d field_20 = CGtV2d(1,1)/size, pos - size*anchor), field_2C = 1.0f + p4).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_D_01E90350 { CGtV4d field_0; };
struct UnkStruct_func_00380250 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E90350 D_01E90350;
extern UnkStruct_func_00380250 _Render__16CB3Panel2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv;
extern "C" void Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(void *, const CGtV2d &, const CGtV2d &, CGtV4d, const void *, unsigned int, unsigned int);
class CB3Panel2dObject {
public:
    void Prepare(const CGtV2d& pos, const CGtV2d& anchor, const CGtV2d& size, unsigned int p3, float p4);
    unsigned char pad_0[0x20];
    CGtV2d field_20;
    unsigned int field_28;
    float field_2C;
};

// 0x003808A0
void CB3Panel2dObject::Prepare(const CGtV2d& pos, const CGtV2d& anchor, const CGtV2d& size, unsigned int p3, float p4)
{
    field_20 = (CGtV2d(1.0f, 1.0f) / size);
    field_28 = p3;
    field_2C = 1.0f + p4;
    Prepare__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_vUiUi(this, (pos - size * anchor), size, D_01E90350.field_0, (const void *)&_Render__16CB3Panel2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv, 64, 16);
}
