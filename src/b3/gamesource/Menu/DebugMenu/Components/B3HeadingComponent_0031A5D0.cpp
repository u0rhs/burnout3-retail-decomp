#include "b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/_unclassified/B3NetworkManager.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern CB3MenuPageManager D_01E90240;  // unnamed global (the page manager instance)
extern CGt2dScene D_01E903E0;          // the menu's scene (= D_01E90240.field_1A0, N65)

// Same declarations as B3HeadingComponent_00319A90.cpp / _00319E80.cpp. Padded for N51.
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

extern CGtTexture *D_01EA46B0[0x38];

struct UnkStruct_D_01E7A800 {
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E7A800 D_01E7A800;
extern "C" void func_00285560(UnkStruct_D_01E7A800 *p, int type, int n);

// [L] what AllocUTF16String__19CB3MenuStringBufferFi allocates a 0x40-character string from (D_01E90240 + 0x1F8). Padded for N51.
struct UnkStruct_D_01E90438 {
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E90438 D_01E90438;

// [L] a byte flag (lbu, tested for zero) choosing the network player's name over the local profile's
// (online [G]). Padded for N51.
struct UnkStruct_D_01E65499 {
    unsigned char value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E65499 D_01E65499;

// [L] a large object holding an array of 0x27D0-byte entries at +0x12C6C4, indexed by `mode` (0/1);
// each entry starts with a name string (passed to PrintString<PUs>).
struct UnkStruct_D_00522660_Entry {
    unsigned short field_0[0x27D0 / 2];
};
struct UnkStruct_D_00522660 {
    unsigned char pad[0x12C6C4];
    UnkStruct_D_00522660_Entry field_12C6C4[2];
};
extern UnkStruct_D_00522660 D_00522660;

extern CB3NetworkManager D_01E32AE0;  // [L] the network manager instance (GetPlayerRecordByID's this)

// Unnamed callees: placeholder names, register layouts only [L].
extern "C" void *AllocUTF16String__19CB3MenuStringBufferFi(UnkStruct_D_01E90438 *pool, int length);
extern "C" void *func_002366D0(CB3NetworkManager *mgr, int index);
extern "C" int func_0022FBB0(void *player);
// [L] CGtUnicode::PrintString<PUs>(unsigned short*, const unsigned short*, unsigned short* const&):
// research/names_C_retail.csv ([high], no mangled form, so the placeholder stays). func_00310180 is the
// same shape (a sibling instantiation [G]).
extern "C" void func_003180A0(unsigned short *dst, const unsigned short *fmt, unsigned short *const &arg);
extern "C" void func_00310180(unsigned short *dst, const unsigned short *fmt, unsigned short *const &arg);
extern "C" unsigned short *Copy__10CGtUnicodeFPUsPCUs(unsigned short *dst, const unsigned short *src);  // 0x213A00
extern "C" void func_003D0960(void *str, int length, const unsigned short *text, int n);
// [L] a text object's Prepare: obj, pos, anchor, colour (by value: passed by address), three ints, the
// font, two floats (EABI: allocated apart from the ints), then two stack arguments (the string, 0).
extern "C" void func_003D0710(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, CGtV4d colour,
                              int a, int b, int c, CGt2dFont *font, float d, float e, void *str, int f);

// 0x0031A5D0 (Target #35). Called by Prepare(EHeadingType) for types 10/11/12 (mode 2/0/1): builds the
// heading text (a name through string 0x305, or string 0xA1E) and a text object for it in layer field_8+2.
// Source shapes (single-change variants): i and id declared at the top (declared in the loop, the $s
// registers are assigned differently), and the scene as the page manager's member (N63).
void func_0031A5D0(CB3HeadingComponent *self, int mode)
{
    int i, id;
    unsigned short buf[0x40];
    void *str = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x40);
    if (D_01E65499.value) {
        if (mode == 0) {
            func_003180A0(buf, D_0051BA44.strings.GetString(0x305), D_00522660.field_12C6C4[mode].field_0);
        } else if (mode == 1) {
            id = -1;
            for (i = 0; i < D_01E32AE0.field_28; i++) {
                void *player = func_002366D0(&D_01E32AE0, i);
                if (player)
                    id = func_0022FBB0(player);
            }
            func_00310180(buf, D_0051BA44.strings.GetString(0x305), D_01E32AE0.GetPlayerRecordByID(id)->field_4);
        } else {
            Copy__10CGtUnicodeFPUsPCUs(buf, D_0051BA44.strings.GetString(0xA1E));
        }
    } else {
        if (mode < 2)
            func_003180A0(buf, D_0051BA44.strings.GetString(0x305), D_00522660.field_12C6C4[mode].field_0);
        else
            Copy__10CGtUnicodeFPUsPCUs(buf, D_0051BA44.strings.GetString(0xA1E));
    }
    func_003D0960(str, 0x40, buf, 1);
    CGt2dScene *scene = &D_01E90240.field_1A0;
    self->field_14 = scene->ConstructObject(self->field_8 + 2, scene->field_14);
    func_003D0710(self->field_14, CGtV2d(30.0f, 48.0f), CGtV2d(0.0f, 0.5f), D_01E90240.field_110, 1, 1, 0,
                  D_00665ED0.pFont, 44.0f, 3.402823466e+38f, str, 0);
}

// 0x0031A840 (Target #35). Called from game/unit_003C35C0. Only for a prepared (field_A) type-3 heading:
// types 0-2 get the rotating image (as Prepare(EHeadingType) does), and the type and the pending string
// id (field_24, see Update) are stored; any other type is ignored. `(int)(type + 14)`: even on an int,
// the cast keeps 14 out of the table base, as in Prepare(EHeadingType) (an enum in the original? [G]).
void func_0031A840(CB3HeadingComponent *self, int type, int id)
{
    if (!self->field_A || self->field_26 != 3)
        return;
    switch (type) {
    case 0:
    case 1:
    case 2:
        self->field_28 = 1;
        self->field_14 = D_01E903E0.ConstructObject(self->field_8 + 2, D_01E903E0.field_14);
        ((CB3RotatingImage2dObject *)self->field_14)
            ->Prepare(CGtV2d(640.0f, 22.0f), CGtV2d(0.0f, 0.0f), CGtV2d(100.0f, 100.0f), D_01E90240.field_110,
                      D_01EA46B0[(int)(type + 14)]);
        func_00285560(&D_01E7A800, type, 0);
    case 3:
        break;
    default:
        return;
    }
    self->field_26 = type;
    self->field_24 = id;
}
