// CGt2dBezierCurve::_ComputeSize(CGtBezierCurveRenderData*,GtMathPs2::CGtV2d*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dBezierCurve.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (min/max loop over 0x28-stride sections via element pointer).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GtMath.h"

using namespace GtMathPs2;

struct UnkStruct_CGtBezierSection_pts { CGtV2d pt[4]; unsigned char pad_20[8]; };
struct CGtBezierCurveRenderData {
    UnkStruct_CGtBezierSection_pts * field_0;
    int field_4;
};
extern float D_004E073C;

extern "C" void _ComputeSize__16CGt2dBezierCurveFP24CGtBezierCurveRenderDataPQ29GtMathPs26CGtV2d(CGtBezierCurveRenderData * rd, CGtV2d * out)
{
    float maxx = 0.0f;
    float maxy = 0.0f;
    float minx = D_004E073C;
    float miny = D_004E073C;
    for (int i = 0; i < rd->field_4; i++) {
        UnkStruct_CGtBezierSection_pts * sec = &rd->field_0[i];
        for (int j = 0; j < 4; j++) {
            CGtV2d p = sec->pt[j];
            maxx = GtMath::Max(maxx, p.X());
            maxy = GtMath::Max(maxy, p.Y());
            minx = GtMath::Min(minx, p.X());
            miny = GtMath::Min(miny, p.Y());
        }
    }
    CGtV2d r(maxx - minx, maxy - miny);
    *out = r;
}
