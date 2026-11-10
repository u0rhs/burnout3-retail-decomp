#include "b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectText.h"
#include "b3/_unclassified/B3Strings.h"

using GtMathPs2::CGtV2d;

extern CB3MenuPageManager D_01E90240;
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
extern const CGtV2d D_004C5340;
extern const CGtV2d D_004C5358;
extern "C" float func_00382BE0(int button);
extern "C" void func_00382C00(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, int button);

// 0x0031F760
void func_0031F760(CB3PromptsComponent *self, bool b)
{
    // Declared mgr, scene, root, layer: retail's registers and load order (24 orders tried). The scene as the page
    // manager's member, as in func_0031F5E0 (N63).
    CB3MenuPageManager *mgr = &D_01E90240;
    CGt2dScene *scene = &D_01E90240.field_1A0;
    CGt2dFrame *root = scene->field_14;
    int layer = self->field_8;
    if (self->field_74[1] == 0)
        self->field_74[1] = scene->ConstructObject(layer, root);
    float w = func_00382BE0(5);
    float off = 5.0f + 0.5f * w;
    // x and the string fetched into locals before each Prepare: retail keeps x in a saved register across GetString
    // and builds the position temporary after it (frame 0xB0).
    if (b) {
        float tx = off + D_004C5358.marValues[0];
        const unsigned short *text = D_0051BA44.strings.GetString(0x84);
        ((CGt2dObjectText *)self->field_74[1])->Prepare(CGtV2d(tx, D_004C5358.marValues[1]), CGtV2d(0.0f, 0.5f), 24.0f,
                                                       mgr->field_D0, D_00665ED0.pFont, text);
    } else {
        float tx = D_004C5340.marValues[0] - off;
        const unsigned short *text = D_0051BA44.strings.GetString(0x84);
        ((CGt2dObjectText *)self->field_74[1])->Prepare(CGtV2d(tx, D_004C5340.marValues[1]), CGtV2d(1.0f, 0.5f), 24.0f,
                                                       mgr->field_D0, D_00665ED0.pFont, text);
    }
    if (self->field_84[1] == 0)
        self->field_84[1] = scene->ConstructObject(layer, root);
    if (b)
        func_00382C00(self->field_84[1], D_004C5358, CGtV2d(0.5f, 0.5f), 5);
    else
        func_00382C00(self->field_84[1], D_004C5340, CGtV2d(0.5f, 0.5f), 5);
}
