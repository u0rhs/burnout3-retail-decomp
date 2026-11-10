// CGt2dObjectImage::SetTexture(CGtTexture*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dObjectImage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C under the mangled name with retail's extra a2 argument explicit (B13/N68), gt2d N167).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

#pragma auto_inline on

using namespace GtMathPs2;

// 0x1D6070: retail stores a2 into +0x34 although the mangled name has one parameter (B13/N68): defined under its
// mangled symbol with C linkage and the extra argument made explicit.
extern "C" void SetTexture__16CGt2dObjectImageFP10CGtTexture(CGt2dObjectImage * self, CGtTexture * texture, unsigned int n)
{
    self->Data().field_10 = texture;
    self->Data().field_14 = n;
}
