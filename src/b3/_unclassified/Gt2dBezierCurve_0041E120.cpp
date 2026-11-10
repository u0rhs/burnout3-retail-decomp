// CGt2dBezierCurve::_Render(const CGt2dObject::CGt2dObjectSpace&,const void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dBezierCurve.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (Bezier _Render; section ptr byte-offset 0x28 stride).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

#pragma auto_inline on

using namespace GtMathPs2;

struct CGtBezierSection;
struct CGtTexture;
struct UnkStruct_D_01EBE360 { unsigned char pad_0[0x40]; };
extern UnkStruct_D_01EBE360 D_01EBE360;
extern "C" void Update__8CGtTimerFv(UnkStruct_D_01EBE360 *);

struct UnkStruct_0041E120_rd {
    CGtBezierSection * field_0;
    int field_4;
    float field_8;
    float field_C;
};
struct UnkStruct_0041E120_data {
    unsigned char pad_0[8];
    CGtTexture * field_8;
    UnkStruct_0041E120_rd * field_C;
};

extern "C" void _DrawBezierSpline__16CGt2dBezierCurveFRCQ211CGt2dObject16CGt2dObjectSpacePCvP16CGtBezierSectionP10CGtTextureQ29GtMathPs26CGtV4dff(
    const CGt2dObject::CGt2dObjectSpace &, const void *, CGtBezierSection *, CGtTexture *, CGtV4d, float, float);

extern "C" void _Render__16CGt2dBezierCurveFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace & space, const void * data)
{
    const UnkStruct_0041E120_data * d = (const UnkStruct_0041E120_data *)data;
    Update__8CGtTimerFv(&D_01EBE360);
    for (int i = 0; i < d->field_C->field_4; i++) {
        UnkStruct_0041E120_rd * rd = d->field_C;
        _DrawBezierSpline__16CGt2dBezierCurveFRCQ211CGt2dObject16CGt2dObjectSpacePCvP16CGtBezierSectionP10CGtTextureQ29GtMathPs26CGtV4dff(
            space, data, (CGtBezierSection *)((char *)rd->field_0 + i * 0x28), d->field_8, space.mColour, rd->field_C, rd->field_8);
    }
}
