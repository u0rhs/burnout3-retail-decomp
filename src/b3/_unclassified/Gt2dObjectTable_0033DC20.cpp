// CGt2dObjectTable::GetImageSize(GtMathPs2::CGtV2d*,const CGt2dFrame&,const void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dObjectTable.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (local CGt2dObjectImage, Image::Prepare via link name with stack n=0, colour = data ptr).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"

using namespace GtMathPs2;

struct UnkStruct_Gt2dObjectTable_img {
    CGtV4d field_0;
    CGtV2d field_10;
    CGtV2d field_18;
    CGtV2d field_20;
    CGtV2d field_28;
    CGtTexture *field_30;
};

extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, const CGtV4d &colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);

extern "C" void GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *out, const CGt2dFrame &frame, const void *data)
{
    const UnkStruct_Gt2dObjectTable_img *d = (const UnkStruct_Gt2dObjectTable_img *)data;
    CGt2dObjectImage img;
    CGtV2d zero(0.0f, 0.0f);
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
        &img, zero, d->field_18, d->field_10, d->field_0, d->field_30, d->field_20, d->field_28, 0);
    *out = img.mObjectSpace.mSize;
}
