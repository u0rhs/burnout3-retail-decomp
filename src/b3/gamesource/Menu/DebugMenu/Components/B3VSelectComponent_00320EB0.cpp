#include "b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/_unclassified/B3Strings.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern CB3MenuPageManager D_01E90240;  // unnamed global (the page manager instance)

// Same declarations as B3HeadingComponent_00319490.cpp (N51 padding).
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
extern const CGtV2d D_004C5388;  // [L] krVSelectOutlineOffset (B3VSelectComponent_004D81A0.cpp)

// [C] class and method name: retail's tables (the mangled name, 7 parameters, as this call); only declared here.
class CB3FlashText2dObject : public CGt2dObject {
public:
    void Prepare(const CGtV2d &pos, const CGtV2d &anchor, float size, CGtV4d colour, const CGt2dFont *font,
                 const unsigned short *text, const CGtV2d &outline);
};

// 0x003D0960, unnamed, not yet decompiled: copies `src` into `dst` (at most `max` characters, breaking at spaces;
// '\' handled) [L by its loops]; flag [G].
extern "C" void func_003D0960(unsigned short *dst, int max, const unsigned short *src, int flag);
// 0x003D0710, unnamed, not yet decompiled: a text object's prepare -- pos, anchor, colour (by value), three small
// settings stored as bytes / an index into the float table D_004CA4D0, the font, a size and a width limit, the text
// and a flag [C by its stores; G for the meanings].
extern "C" void func_003D0710(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, CGtV4d colour, int a, int b,
                              int c, const CGt2dFont *font, float size, float maxWidth, const unsigned short *text,
                              bool flag);

// 0x00320EB0
void func_00320EB0(CB3VSelectComponent *self, int item, float x, bool selected)
{
    // Declared anchor, mgr, y, state, size: retail's order (120 orders tried).
    CGtV2d anchor(0.0f, 0.5f);
    CB3MenuPageManager *mgr = &D_01E90240;
    float y = self->UnkInline_ItemY(item);
    int state;
    if (self->field_10[item].field_4)
        state = 2;
    else if (selected)
        state = 1;
    else
        state = 0;
    float size;
    if (selected) {
        size = self->field_B4;
        self->field_C8 = 0;
    } else {
        size = self->field_B0;
    }
    float w = D_00665ED0.pFont->GetStringWidth(self->field_10[item].field_0);
    if (w * size > self->field_C0)
        size = self->field_C0 / w;
    if (self->field_D4)
        anchor.marValues[0] = 0.5f;
    ((CB3FlashText2dObject *)self->field_14[item])->Prepare(CGtV2d(x, y), anchor, size, mgr->field_0[state],
                                                            D_00665ED0.pFont, self->field_10[item].field_0, D_004C5388);
    if (self->field_38[item] != 0) {
        func_003D0960(self->field_64, 0x20, D_0051BA44.strings.GetString(0x109), 0);
        func_003D0710(self->field_38[item], CGtV2d(x, y), CGtV2d(0.5f, 1.15f), mgr->field_110, 1, 2, 0,
                      D_00665ED0.pFont, 0.75f * self->field_B0, 3.402823466e+38f, self->field_64, false);
    }
}
