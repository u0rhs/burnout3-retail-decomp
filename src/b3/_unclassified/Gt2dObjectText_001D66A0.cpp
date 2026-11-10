// CGt2dObjectText::_RenderPlain(const CGt2dObject::CGt2dObjectSpace&,const void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dObjectText.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a77: sibling of _RenderDropShadow shape: single RenderSpritesTex plain pass).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using namespace GtMathPs2;

struct UnkStruct_Gt2dObjectText_font {
    unsigned char pad_0[4];
    CGtTexture *field_4;       // [G] the font's texture (Gt2dFont.h field_4)
};
struct UnkStruct_Gt2dObjectText_data {
    UnkStruct_Gt2dObjectText_font *field_0;
    unsigned char pad_4[0xC];
    CGtV2d field_10;           // [L] drop shadow offset (COutlineDropShadow::mDropShadowOffset), scaled by the object size
};

extern "C" int _BuildBatchData__15CGt2dObjectTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &, const void *);

// 0x001D66A0
extern "C" void _RenderPlain__15CGt2dObjectTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(const CGt2dObject::CGt2dObjectSpace &space, const void *data)
{
    const UnkStruct_Gt2dObjectText_data *d = (const UnkStruct_Gt2dObjectText_data *)data;
    int n = _BuildBatchData__15CGt2dObjectTextFRCQ211CGt2dObject16CGt2dObjectSpacePCv(space, data);
    if (n > 0) {
        Gt2dRenderer::SetTexture(d->field_0->field_4);
        Gt2dRenderer::RenderSpritesTex(space.mColour, CGtV2d(0.0f, 0.0f), n, (const CGtV2d *)CGt2dObject::mgu8RenderBatchData,
                                       (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
    }
}
