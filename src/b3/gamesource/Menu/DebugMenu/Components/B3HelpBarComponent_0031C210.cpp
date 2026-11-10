#include "b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

// The scene (D_01E903E0) is taken as a member address, as in B3HeadingComponent_00319A90.cpp (N63): through the
// bare global, -O4 rebuilds the address with lui per use instead of keeping it in a saved register.
extern CB3MenuPageManager D_01E90240;  // unnamed global (the page manager instance)

// Same declaration and N51 padding as B3HeadingComponent_00319A90.cpp.
struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;

// [C] names: E-build DNAT map (B3HelpBarComponent.cpp .sbss). Retail's selection data is 4 bytes (it writes +2),
// though DNAT lists 2.
extern CB3MenuComponentSelectionData _gDefaultSelectionData;
extern CB3ScrollingTextData _gDefaultScrollingTextData;

// [L] an unnamed text-object Prepare (retail 0x3D0710); parameter list read off the registers at this call.
extern "C" void func_003D0710(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, CGtV4d colour, int a, int b,
                              int c, CGt2dFont *font, float size, float d, const unsigned short *text, int e);

// 0x0031C210
bool CB3HelpBarComponent::AwardPrepare(const unsigned short *text)
{
    CB3MenuComponentBase::Prepare();
    CGt2dScene *scene = &D_01E90240.field_1A0;
    CGt2dFrame *root = scene->field_14;
    field_14 = scene->ConstructObject(field_8, root);
    field_24 = root->ConstructChild();
    field_24->field_0.SetIdentity();
    field_24->field_0.field_0 = CGtV2d(16.0f, 386.0f);
    field_24->field_0.field_8 = CGtV2d(608.0f, 28.0f);
    scene->field_2c[field_8].field_c = field_24;
    field_C = 0;
    field_10 = 0;
    field_6D = -1;
    field_6E = 3;
    func_003D0710(field_14, CGtV2d(320.0f, 400.0f), CGtV2d(0.5f, 0.5f), D_01E90240.field_110, 1, 1, 0,
                  D_00665ED0.pFont, 28.0f, 3.402823466e+38f, text, 0);  // FLT_MAX: a shared .lit4 entry (D_004E0C14)
    return true;
}

// 0x0031C350
bool CB3HelpBarComponent::Prepare(const CB3MenuComponentSelectionData *selection, const CB3ScrollingTextData *texts,
                                  bool b, float f)
{
    CB3MenuComponentBase::Prepare();
    CGt2dScene *scene = &D_01E90240.field_1A0;
    CGt2dFrame *root = scene->field_14;
    field_50 = f;
    field_14 = scene->ConstructObject(field_8, root);
    field_24 = root->ConstructChild();
    field_24->field_0.SetIdentity();
    field_24->field_0.field_0 = CGtV2d(16.0f, 386.0f);
    field_24->field_0.field_8 = CGtV2d(608.0f, 28.0f);
    scene->field_2c[field_8].field_c = field_24;
    field_C = selection;
    field_10 = texts;
    field_6D = -1;
    field_6E = 0;
    ((CB3ScrollingText2dObject *)field_14)->Prepare(field_10->field_0, true, b, field_50);
    return true;
}

// 0x0031C470
bool CB3HelpBarComponent::Prepare()
{
    CB3MenuComponentBase::Prepare();
    CGt2dScene *scene = &D_01E90240.field_1A0;
    CGt2dFrame *root = scene->field_14;  // read before the field_14 store, as retail orders them
    field_14 = 0;
    field_6E = 0;
    field_24 = root->ConstructChild();
    field_24->field_0.SetIdentity();
    field_24->field_0.field_0 = CGtV2d(16.0f, 386.0f);
    field_24->field_0.field_8 = CGtV2d(608.0f, 28.0f);
    scene->field_2c[field_8].field_c = field_24;
    return true;
}

// 0x0031C520
bool CB3HelpBarComponent::Prepare(const unsigned short *text, bool b, float f)
{
    _gDefaultSelectionData.field_2 = 1;
    _gDefaultSelectionData.field_0 = 0;
    _gDefaultScrollingTextData.SetData(text);
    return Prepare(&_gDefaultSelectionData, &_gDefaultScrollingTextData, b, f);
}
