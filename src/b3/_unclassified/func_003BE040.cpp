// Hand-written; the lifter refused it (a84: CB3VOptionsSelectComponent::PrepareItem [L] DNAT; modeled on func_00320EB0; CGtV2d temps at the call, state/font/size declared before y for s1/s2 and f22/f23).

// func_003BE040 -- CB3VOptionsSelectComponent::PrepareItem(int,float,bool) [L] DNAT (research/proto/new_names.csv, medium)
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern CB3MenuPageManager D_01E90240;
struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_D_00665ED8 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED8 D_00665ED8;
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_F D_004CA2A4, D_004CA2D0;
extern float D_004CA2A0[];
extern const CGtV2d D_004CA290;

class CB3FlashText2dObject : public CGt2dObject {
public:
    void Prepare(const CGtV2d &pos, const CGtV2d &anchor, float size, CGtV4d colour, const CGt2dFont *font,
                 const unsigned short *text, const CGtV2d &outline);
};
struct UnkStruct_003BE040_ent {
    const unsigned short *field_0;
    unsigned char pad_4[0x9];
    unsigned char field_D;
    unsigned char field_E;
    unsigned char pad_F[0x5];
};
struct UnkStruct_003BE040 {
    unsigned char pad_0[0x10];
    UnkStruct_003BE040_ent *field_10;
    CGt2dObject *field_14[9];
    unsigned char pad_38[0xE0 - 0x38];
    int field_E0;
    float field_E4;
};

// [L] DNAT: CB3VOptionsSelectComponent::PrepareItem(int,float,bool) (research/proto/new_names.csv, medium)
// 0x003BE040
extern "C" void func_003BE040(UnkStruct_003BE040 *self, int item, float x, bool selected)
{
    CB3MenuPageManager *mgr = &D_01E90240;
    int state;
    CGt2dFont *font = D_00665ED0.pFont;
    float size;
    float y = self->field_E4 + (float)item * 32.0f;
    if (self->field_10[item].field_E)
        state = 2;
    else if (selected)
        state = 1;
    else
        state = 0;
    float maxw;
    if (self->field_10[item].field_D == 0)
        maxw = (D_004CA2A4.field_0 + D_004CA2D0.field_0) - 68.0f;
    else
        maxw = (D_004CA2A0[self->field_10[item].field_D] - 68.0f) - 40.0f;
    if (selected) {
        size = 40.0f;
        self->field_E0 = 0;
    } else {
        size = 30.0f;
    }
    float w = font->GetStringWidth(self->field_10[item].field_0);
    if (w * size > maxw)
        size = maxw / w;
    if (size < 18.0f) {
        font = D_00665ED8.pFont;
        if (selected) {
            size = 40.0f;
            self->field_E0 = 0;
        } else {
            size = 30.0f;
        }
        w = font->GetStringWidth(self->field_10[item].field_0);
        if (w * size > maxw)
            size = maxw / w;
    }
    ((CB3FlashText2dObject *)self->field_14[item])->Prepare(CGtV2d(x, y), CGtV2d(0.0f, 0.5f), size, mgr->field_0[state], font, self->field_10[item].field_0, D_004CA290);
}
