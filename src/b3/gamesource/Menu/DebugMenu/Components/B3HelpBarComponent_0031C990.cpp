#include "b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using GtMathPs2::CGtV2d;

// [C] name: E-build DNAT map (B3HelpBarComponent.cpp .rodata); retail 0x4C51F0, filled in by the file's static
// initializer.
extern const CGtV2d kHelpBarRecipSize;

// Same declaration and N51 padding as B3HeadingComponent_00319A90.cpp.
struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;

// 0x0031C990 (Target #48). Draws the scrolling text as repeated batches: the start offset is 100 * the scroll position less
// the strip width, wrapped by the text's extent; batches already left of the strip are skipped, then each batch
// is drawn until the cursor passes the right edge.
void CB3ScrollingText2dObject::_Render(const CGt2dObject::CGt2dObjectSpace &space, const void *p)
{
    const CGt2dObjectScrollingTextRenderData *data = (const CGt2dObjectScrollingTextRenderData *)p;
    // Declared first (top slot) but assigned after `end`: its address goes to _BuildBatchData, and MWCC won't hoist
    // the `space` loads above a store to an address-exposed local (N100).
    const unsigned short *text;
    CGtV2d scale = kHelpBarRecipSize * space.mSize;
    CGtV2d cursor;  // declared here: named locals take slots in declaration order (retail: scale, cursor, end)
    CGtV2d end = space.mTopLeftPos + space.mSize;
    text = data->field_0;
    float offset = 100.0f * data->field_4 - 608.0f;
    if (offset > 608.0f)
        offset = offset - data->field_8 * (float)(int)(offset / data->field_8);
    offset *= scale.marValues[0];  // scaled in place: `x - offset * scale.x` would fuse into msub (N100)
    cursor.Set(space.mTopLeftPos.marValues[0] - offset, space.mTopLeftPos.marValues[1]);
    do {
        int n;
        do {
            n = _BuildBatchData(scale, &cursor, &text, space, *data);
        } while (!(cursor.marValues[0] > space.mTopLeftPos.marValues[0]));
        if (n > 0) {
            Gt2dRenderer::SetTexture(D_00665ED0.pFont->field_4);
            Gt2dRenderer::RenderTriStripFlatTex(space.mColour, CGtV2d(0.0f, 0.0f), n,
                                                (const CGtV2d *)CGt2dObject::mgu8RenderBatchData,
                                                (const CGtV2d *)(CGt2dObject::mgu8RenderBatchData + 0xFE0));
        }
    } while (cursor.marValues[0] <= end.marValues[0]);
}
