#include "b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

using GtMathPs2::CGtV2d;

extern CB3MenuPageManager D_01E90240;  // unnamed global (the page manager instance)

// Same declaration and N51 padding as B3HeadingComponent_00319A90.cpp.
struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;

// 0x0031CB20. The help text: a 608x28 strip centred at (320, 432); the scroll start is either 0 or, centred,
// half a string past the right edge, in hundredths.
void CB3ScrollingText2dObject::Prepare(const unsigned short *text, bool scroll, bool centred, float extra)
{
    // Set through the API's SetY/SetX, y first: the (x, y) constructor or SetX-then-SetY swaps the two constants'
    // registers (retail: 608 in $v0). The bar height is read through Y(), which keeps &size.y out of a saved register.
    CGtV2d size;
    size.SetY(28.0f);
    size.SetX(608.0f);
    CB3MenuPageManager *mgr = &D_01E90240;
    CGt2dObjectScrollingTextRenderData *data = (CGt2dObjectScrollingTextRenderData *)mauDataBlock;
    float width = D_00665ED0.pFont->GetStringWidthIncludingLRKern(text);
    data->field_0 = text;
    data->field_8 = extra + width * size.Y();
    data->field_C = extra;
    if (scroll) {
        if (centred)
            data->field_4 = (608.0f + 0.5f * width) / 100.0f;
        else
            data->field_4 = 0.0f;
    }
    CGt2dObject::Prepare(CGtV2d(320.0f, 432.0f) - size * 0.5f, size, mgr->field_30, _Render, 0x40, 0x10);
}
