#include "b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectText.h"
#include "b3/_unclassified/B3Strings.h"

using GtMathPs2::CGtV2d;

extern CB3MenuPageManager D_01E90240;  // unnamed global (the page manager instance)

// Same declarations as B3HeadingComponent_00319490.cpp (N51 padding).
struct UnkStruct_D_01E90424 {
    int value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E90424 D_01E90424;
struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_D_0051BA44 {
    CB3Strings strings;
    unsigned char pad[0x100];
};
extern UnkStruct_D_0051BA44 D_0051BA44;

// 0x00380F10, unnamed, not yet decompiled: prepares a button object at pos/anchor; bit-tests `flags` (1, 2, 4, 8). [G]
// parameter types beyond the register use.
extern "C" void Prepare__15CB3DPad2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, unsigned int flags);

// 0x0031F5E0
void func_0031F5E0(CB3PromptsComponent *self, int id, bool b)
{
    // The scene as the page manager's member (N63): with the bare D_01E903E0 global, scene->field_14 is folded into
    // an absolute load instead of retail's lw 0x14($s2). Declared scene, mgr, root, layer: retail's registers.
    CGt2dScene *scene = &D_01E90240.field_1A0;
    CB3MenuPageManager *mgr = &D_01E90240;
    CGt2dFrame *root = scene->field_14;
    int layer = self->field_8;
    float y = 504.0f;
    float x;
    if (b)
        x = 386.75f;
    else
        x = 320.0f;
    if (D_01E90424.value == 5)
        y = 447.5f;
    if (self->field_94 == 0)
        self->field_94 = scene->ConstructObject(layer, root);
    // A (non-const) local: with the literal in the expression, MWCC puts the constant first (add.s f0, f0, f20);
    // retail has x first.
    float off = 21.0f;
    const unsigned short *text = D_0051BA44.strings.GetString(id);
    ((CGt2dObjectText *)self->field_94)->Prepare(CGtV2d(x + off, y), CGtV2d(0.0f, 0.5f), 24.0f, mgr->field_D0,
                                                 D_00665ED0.pFont, text);
    if (self->field_98 == 0)
        self->field_98 = scene->ConstructObject(layer, root);
    Prepare__15CB3DPad2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(self->field_98, CGtV2d(x, y), CGtV2d(0.5f, 0.5f), self->field_18);
}
