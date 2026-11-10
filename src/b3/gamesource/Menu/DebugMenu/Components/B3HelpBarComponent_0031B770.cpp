#include "b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

extern CB3MenuPageManager D_01E90240;  // unnamed global (the page manager instance)

// [C] names: E-build DNAT map (B3HelpBarComponent.cpp .sbss); see B3HelpBarComponent_0031C210.cpp.
extern CB3MenuComponentSelectionData _gDefaultSelectionData;
extern CB3ScrollingTextData _gDefaultScrollingTextData;

// 0x0031B770. Replaces the help text: one default entry holding `text`, the text object rebuilt only when
// there is text. The scene is taken as a member address (N63, as in B3HelpBarComponent_0031C210.cpp).
void CB3HelpBarComponent::SetString(const unsigned short *text, bool b1, bool b2, float f)
{
    CGt2dScene *scene = &D_01E90240.field_1A0;
    CGt2dFrame *root = scene->field_14;
    _gDefaultSelectionData.field_2 = 1;
    _gDefaultSelectionData.field_0 = 0;
    _gDefaultScrollingTextData.SetData(text);
    field_C = &_gDefaultSelectionData;
    field_10 = &_gDefaultScrollingTextData;
    field_6D = 0;
    field_50 = f;
    if (field_14 != 0) {
        scene->DestructObject(field_8, field_14);
        field_14 = 0;
    }
    if (text != 0) {
        field_14 = scene->ConstructObject(field_8, root);
        ((CB3ScrollingText2dObject *)field_14)->Prepare(field_10->field_0, b1, b2, field_50);
    }
}
