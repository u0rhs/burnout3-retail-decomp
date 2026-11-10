// CGt2dObjectImage::Prepare(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d,CGtTextu -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dObjectImage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C under the mangled name with the 9th (stack) argument explicit (N68); SetTexture/SetUVs written as direct stores, gt2d N167).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

#pragma auto_inline on

using namespace GtMathPs2;

// 0x1D60B0
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObjectImage * self, const CGtV2d& pos, const CGtV2d& anchor, const CGtV2d& size, const CGtV4d colour,
    CGtTexture* texture, const CGtV2d& uv0, const CGtV2d& uv1, unsigned int n)
{
    self->Data().field_10 = texture;
    self->Data().field_14 = n;
    self->Data().field_0 = uv0;
    self->Data().field_8 = uv1;
// 0x001D60B0
    self->CGt2dObject::Prepare(pos - size * anchor, size, colour, CGt2dObjectImage::_Render, 0x40, sizeof(UnkStruct_Gt2dObject_20));
}
