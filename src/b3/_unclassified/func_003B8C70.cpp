// Hand-written; the lifter refused it (a85: EventFinishedComponent::Prepare; buf declared before n, second text anchor is (0.5,0.0)).

// [L] DNAT: CB3EventFinishedComponent::Prepare() (research/proto/new_names.csv, high); shape of CB3HelpBarComponent::AwardPrepare
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_003B8C70 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject * field_C;
    CGt2dObject * field_10;
    CGt2dFrame * field_14;
    int field_18;
};
struct UnkStruct_D_00665ED0 {
    CGt2dFont * pFont;
    unsigned char pad[0x100];
};
struct UnkStruct_D_01ECD9F4 {
    const unsigned short * value;
    unsigned char pad[0x100];
};
struct UnkStruct_D_01ECD9FC {
    int value;
    unsigned char pad[0x100];
};
struct UnkStruct_D_01E90438 { unsigned char pad_0[0x10]; };

extern CB3MenuPageManager D_01E90240;
extern CGt2dScene D_01E903E0;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_01ECD9F4 D_01ECD9F4;
extern UnkStruct_D_01ECD9F4 D_01ECD9F8;
extern UnkStruct_D_01ECD9FC D_01ECD9FC;
extern UnkStruct_D_01E90438 D_01E90438;
extern CGtV4d D_004CA250;

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" int Length__10CGtUnicodeFPCUs(const unsigned short *);
extern "C" unsigned short * AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_003D0960(unsigned short *, int, const unsigned short *, bool);
extern "C" void func_003D0710(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, CGtV4d colour, int a, int b,
                              int c, CGt2dFont *font, float size, float d, const unsigned short *text, int e);

// 0x003B8C70
extern "C" bool Prepare__25CB3EventFinishedComponentFv(UnkStruct_003B8C70 * self)
{
    Prepare__20CB3MenuComponentBaseFv(self);
    CGt2dScene * const scene = &D_01E903E0;
    CB3MenuPageManager * const mgr = &D_01E90240;
    int layer = self->field_8;
    CGt2dFrame * root = scene->field_14;
    self->field_18 = 0;
    self->field_14 = root->ConstructChild();
    self->field_14->field_0.SetIdentity();
    self->field_14->field_0.field_0 = CGtV2d(320.0f, 120.0f);
    self->field_14->field_0.field_10 = D_004CA250;
    const unsigned short * t1 = D_01ECD9F4.value;
    if (t1 != 0) {
        unsigned short * buf;
        int n = Length__10CGtUnicodeFPCUs(t1) * 4;
        buf = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, n);
        func_003D0960(buf, n, t1, false);
        self->field_C = scene->ConstructObject(layer, self->field_14);
        func_003D0710(self->field_C, CGtV2d(0.0f, 0.0f), CGtV2d(0.5f, 0.5f), mgr->field_110, D_01ECD9FC.value, 1, 0,
                      D_00665ED0.pFont, 42.0f, 3.402823466e+38f, buf, 0);
    }
    const unsigned short * t2 = D_01ECD9F8.value;
    if (t2 != 0) {
        unsigned short * buf;
        int n = Length__10CGtUnicodeFPCUs(t2) * 4;
        buf = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, n);
        func_003D0960(buf, n, t2, false);
        self->field_10 = scene->ConstructObject(layer, self->field_14);
        func_003D0710(self->field_10, CGtV2d(0.0f, 22.0f), CGtV2d(0.5f, 0.0f), D_004CA250, D_01ECD9FC.value, 1, 0,
                      D_00665ED0.pFont, 28.0f, 3.402823466e+38f, buf, 0);
    }
    return true;
}
