// Hand-written; the lifter refused it (CGt2dBezierCurve::Prepare: pass the CGtV4d by-value param straight to Prepare (no c2 copy local)).

// func_0041E260 -- hand-written from the retail structure (lifter refused).
// [L] DNAT: CGt2dBezierCurve::Prepare(const CGtV2d&, const CGtV2d&, CGtV4d, CGtBezierCurveRenderData*, float, C...)
//     (research/proto/new_names.csv, high; signature truncated there, 6th parameter's type unknown)
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

#pragma auto_inline on

using namespace GtMathPs2;

struct CGtBezierCurveRenderData;
struct UnkStruct_D_01EBE360 { unsigned char pad_0[0x40]; };
extern UnkStruct_D_01EBE360 D_01EBE360;

// [E map] CGtTimer::Construct / Prepare / Start at these addresses (config/symbol_addrs_b3names.txt)
extern "C" void Construct__8CGtTimerFv(UnkStruct_D_01EBE360 *);
extern "C" bool Prepare__8CGtTimerFv(UnkStruct_D_01EBE360 *);
extern "C" void Start__8CGtTimerFv(UnkStruct_D_01EBE360 *);
extern "C" void _ComputeSize__16CGt2dBezierCurveFP24CGtBezierCurveRenderDataPQ29GtMathPs26CGtV2d(CGtBezierCurveRenderData *, CGtV2d *);
extern "C" void _Render__16CGt2dBezierCurveFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &, const void *);

// [G] data block at +0x20
struct UnkStruct_0041E260_data {
    CGtV2d field_0;
    const void * field_8;
    CGtBezierCurveRenderData * field_C;
    float field_10;
};

// 0x0041E260
extern "C" void func_0041E260(CGt2dObject * self, const CGtV2d & pos, const CGtV2d & anchor, const CGtV4d colour,
                              CGtBezierCurveRenderData * rd, float scale, const void * arg6)
{
    UnkStruct_0041E260_data * d = (UnkStruct_0041E260_data *)self->mauDataBlock;
    CGtV2d size;
    _ComputeSize__16CGt2dBezierCurveFP24CGtBezierCurveRenderDataPQ29GtMathPs26CGtV2d(rd, &size);
    Construct__8CGtTimerFv(&D_01EBE360);
    Prepare__8CGtTimerFv(&D_01EBE360);
    Start__8CGtTimerFv(&D_01EBE360);
    d->field_C = rd;
    d->field_8 = arg6;
    CGtV2d one(1.0f, 1.0f);
    d->field_0 = one / size;
    d->field_10 = scale;
    self->CGt2dObject::Prepare(pos - size * anchor, size, colour, _Render__16CGt2dBezierCurveFRCQ211CGt2dObject16CGt2dObjectSpacePCv, 0x40, 0x18);
}
