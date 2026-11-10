// Hand-written; the lifter refused it (a117: FlashText Prepare item; enum state diamond, 0.0f + t; y += 32*item, size declared first).

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
extern const CGtV2d D_004D30C8;
enum UnkEnum_00449050 { UnkEnum_00449050_0 = 0, UnkEnum_00449050_1 = 1, UnkEnum_00449050_2 = 2 };

class CB3FlashText2dObject : public CGt2dObject {
public:
    void Prepare(const CGtV2d &pos, const CGtV2d &anchor, float size, CGtV4d colour, const CGt2dFont *font,
                 const unsigned short *text, const CGtV2d &outline);
};
struct UnkStruct_00449050_ent {
    const unsigned short *field_0;
    unsigned char field_4;
    unsigned char pad_5[3];
};
struct UnkStruct_00449050_b { unsigned char pad_0[4]; float field_4; };
struct UnkStruct_00449050 {
    unsigned char pad_0[0x10];
    UnkStruct_00449050_ent field_10[3];
    unsigned char pad_28[0x10];
    CGt2dObject *field_38[3];
    unsigned char pad_44[0x28];
    unsigned char field_6C;
    unsigned char pad_6D[0x1B];
    UnkStruct_00449050_b *field_88;
    unsigned char pad_8C[0x68];
    float field_F4;
};

// 0x00449050
extern "C" void func_00449050(UnkStruct_00449050 *self, int item, int selected, float x)
{
    float size;
    CB3MenuPageManager *const mgr = &D_01E90240;
    float t = self->field_F4 + self->field_88->field_4;
    t = t + 15.0f;
    float y = 0.0f + t;
    y += 32.0f * (float)item;
    UnkEnum_00449050 state;
    if (selected != 0) state = UnkEnum_00449050_1; else state = UnkEnum_00449050_0;
    if (self->field_6C != 0 && self->field_10[item].field_4 != 0) state = UnkEnum_00449050_2;
    if (selected == 0) {
        size = 30.0f;
    } else {
        size = 40.0f;
        *(int *)((char *)self + 0x64) = 0;
    }
    ((CB3FlashText2dObject *)self->field_38[item])->Prepare(CGtV2d(x, y), CGtV2d(0.5f, 0.5f), size, mgr->field_0[state], D_00665ED0.pFont, self->field_10[item].field_0, D_004D30C8);
}
