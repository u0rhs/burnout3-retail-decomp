// CGt2dObjectItalicText::_RenderPlain(const CGt2dObject::CGt2dObjectSpace&,const void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dObjectItalicText.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (sibling of Text::_RenderPlain).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using namespace GtMathPs2;

struct UnkStruct_Gt2dObjectItalicText_font {
    unsigned char pad_0[4];
    CGtTexture *field_4;
};
struct UnkStruct_Gt2dObjectItalicText_data {
    UnkStruct_Gt2dObjectItalicText_font *field_0;
};

extern "C" int _BuildBatchData__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &, const void *);

extern "C" void _RenderPlain__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &space, const void *data)
{
    const UnkStruct_Gt2dObjectItalicText_data *d = (const UnkStruct_Gt2dObjectItalicText_data *)data;
    int n = _BuildBatchData__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(space, data);
    if (n > 0) {
        Gt2dRenderer::SetTexture(d->field_0->field_4);
        Gt2dRenderer::RenderTriStripFlatTex(space.mColour, CGtV2d(0.0f, 0.0f), n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData,
                                       (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
    }
}
