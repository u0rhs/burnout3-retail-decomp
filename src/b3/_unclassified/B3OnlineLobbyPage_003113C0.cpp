// CB3OnlineLobbyPage::_GetImageSize(GtMathPs2::CGtV2d*,const CGt2dFrame&,const void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a77: stack CGt2dObjectImage prepared via link-name Prepare (colour by ptr, n=0 on stack), size*2+2).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);

struct UnkStruct_003113C0_d {
    CGtV4d field_0;
    CGtV2d field_10;
    CGtV2d field_18;
    CGtV2d field_20;
    CGtV2d field_28;
    CGtTexture *field_30;
};

// 0x003113C0
extern "C" void _GetImageSize__18CB3OnlineLobbyPageFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *result, const void *frame, const UnkStruct_003113C0_d *d)
{
    CGt2dObjectImage obj;
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
        &obj, CGtV2d(0.0f, 0.0f), d->field_18, d->field_10, d->field_0, d->field_30, d->field_20, d->field_28, 0);
    *result = obj.mObjectSpace.mSize;
    result->marValues[0] = 2.0f * result->marValues[0] + 2.0f;
}
