// CGt2dObjectItalicText::_RenderOutline(const CGt2dObject::CGt2dObjectSpace&,const void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dObjectItalicText.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (slot: as CGt2dObjectText::_RenderOutline (shadow w from space.mColour.W(), N152 slot; -off temporaries)).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using namespace GtMathPs2;

struct UnkStruct_Gt2dObjectItalicText_font {
    unsigned char pad_0[4];
    CGtTexture *field_4;
};
struct UnkStruct_Gt2dObjectItalicText_data {
    UnkStruct_Gt2dObjectItalicText_font *field_0;
    unsigned char pad_4[0xC];
    CGtV2d field_10;
};

extern "C" int _BuildBatchData__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &, const void *);

// 0x0033CCD0
extern "C" void _RenderOutline__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &space, const void *data)
{
    const UnkStruct_Gt2dObjectItalicText_data *d = (const UnkStruct_Gt2dObjectItalicText_data *)data;
    int n = _BuildBatchData__21CGt2dObjectItalicTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(space, data);
    if (n > 0) {
        CGtV4d shadow(0.0f, 0.0f, 0.0f, space.mColour.W());   // W(): the pointer-form copy + lane read and its forwarded 16-byte source slot (N152)
        CGtV2d off = d->field_10 * space.mSize;
        Gt2dRenderer::SetTexture(d->field_0->field_4);
        Gt2dRenderer::RenderTriStripFlatTex(shadow, off, n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData,
                                       (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
        Gt2dRenderer::RenderTriStripFlatTex(shadow, -off, n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData,
                                       (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
        off.marValues[0] = -off.marValues[0];
        Gt2dRenderer::RenderTriStripFlatTex(shadow, off, n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData,
                                       (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
        Gt2dRenderer::RenderTriStripFlatTex(shadow, -off, n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData,
                                       (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
        Gt2dRenderer::RenderTriStripFlatTex(space.mColour, CGtV2d(0.0f, 0.0f), n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData,
                                       (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
    }
}
