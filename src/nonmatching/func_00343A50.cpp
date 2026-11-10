// NONMATCHING: func_00343A50 -- retail 341 / ours 341 instructions, 5 in changed runs
// 5 off: only FP regs swapped in the centred-x calc (retail 580.0f in f3, sum in f2; ours reversed). Tried locals/order/casts/pragmas/inline helpers/sreg (146 variants): no change. Likely CB3TitleScreenComponent::Prepare [G].
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (fresh7): a CB3TitleScreenComponent method between Update (0x343800) and Construct (0x343FB0)
// that calls CB3MenuComponentBase::Prepare first -- the component's Prepare [G]; kept as func_00343A50.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern CB3MenuPageManager D_01E90240;

struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;

struct UnkStruct_D_0051BA44 {
    unsigned char pad[0x100];
};
extern UnkStruct_D_0051BA44 D_0051BA44;

struct UnkStruct_D_004C5D60 {
    CGtV2d v;
    unsigned char pad[0x8];
};
extern UnkStruct_D_004C5D60 D_004C5D60;
extern UnkStruct_D_004C5D60 D_004C5D68;
extern UnkStruct_D_004C5D60 D_01EA4840;
extern UnkStruct_D_004C5D60 D_01EA4848;

struct UnkStruct_D_01EA4628 {
    CGtTexture *p;
    unsigned char pad[0xC];
};
extern UnkStruct_D_01EA4628 D_01EA4628;

struct UnkStruct_D_004F50A0 {
    float field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_004F50A0 D_004F50A0;

struct UnkStruct_00343A50 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dFrame *field_C;
    CGt2dFrame *field_10;
    CGt2dObject *field_14;
    CGt2dObject *field_18;
    CGt2dObject *field_1C;
    CGt2dObject *field_20;
    CGt2dObject *field_24;
    CGt2dObject *field_28;
    float field_2C;
};

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" const unsigned short *func_00271A00(void *, int);
extern "C" void func_0033D650(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const CGt2dFont *, const unsigned short *);
extern "C" void func_001D6C40(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const CGt2dFont *, const unsigned short *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);

// 0x00343A50
extern "C" int func_00343A50(UnkStruct_00343A50 *self)
{
    Prepare__20CB3MenuComponentBaseFv(self);
    CGtV4d c;
    CGtV4d c0;
    c = D_01E90240.field_110;
    c0 = D_01E90240.field_0[0];
    CGt2dScene *scene = &D_01E90240.field_1A0;
    self->field_C = scene->field_14->ConstructChild();
    c.SetA(0.0f);
    self->field_C->field_0.field_10 = c;
    self->field_10 = self->field_C->ConstructChild();
    self->field_10->field_0.SetIdentity();
    self->field_10->field_0.field_0 = D_004C5D60.v;
    self->field_10->field_0.field_8 = D_004C5D68.v;
    int layer1 = self->field_8 + 1;
    scene->field_2c[layer1].field_c = self->field_10;
    self->field_14 = scene->ConstructObject(self->field_8, self->field_C);
    self->field_18 = scene->ConstructObject(self->field_8, self->field_C);
    self->field_1C = scene->ConstructObject(self->field_8 + 1, self->field_C);
    self->field_20 = scene->ConstructObject(self->field_8, self->field_C);
    self->field_24 = scene->ConstructObject(self->field_8, self->field_C);
    self->field_28 = scene->ConstructObject(self->field_8, self->field_C);
    if (self->field_14 != 0) {
        {
            const unsigned short *txt = func_00271A00(&D_0051BA44, 0xD1);
            func_0033D650(self->field_14, CGtV2d(320.0f, 26.0f), CGtV2d(0.5f, 0.0f), 26.0f, CGtV4d(0.9f, 0.9f, 0.9f, 1.0f),
                      D_00665ED0.pFont, txt);
        }
    }
    if (self->field_18 != 0) {
        {
            const unsigned short *txt = func_00271A00(&D_0051BA44, 0xD58);
            func_0033D650(self->field_18, CGtV2d(320.0f, 46.0f), CGtV2d(0.5f, 0.0f), 21.0f, c0,
                      D_00665ED0.pFont, txt);
        }
    }
    {
        const unsigned short *txt = func_00271A00(&D_0051BA44, 0);
        func_001D6C40(self->field_1C, CGtV2d(320.0f, 414.0f), CGtV2d(0.5f, 1.0f), 27.0f, c,
                  D_00665ED0.pFont, txt);
    }
    {
        const unsigned short *txt = func_00271A00(&D_0051BA44, 0xD2);
        func_0033D650(self->field_20, CGtV2d(320.0f, 446.5f), CGtV2d(0.5f, 0.5f), 23.0f, CGtV4d(0.75f, 0.75f, 0.75f, 1.0f),
                  D_00665ED0.pFont, txt);
    }
    {
        const unsigned short *txt = func_00271A00(&D_0051BA44, 0xD3);
        func_0033D650(self->field_24, CGtV2d(320.0f, 446.5f), CGtV2d(0.5f, 0.5f), 23.0f, CGtV4d(0.75f, 0.75f, 0.75f, 1.0f),
                  D_00665ED0.pFont, txt);
    }
    CGtV2d s20 = self->field_20->Size();
    CGtV2d s24 = self->field_24->Size();
    float x = 30.0f + (580.0f - (s20.marValues[0] + s24.marValues[0])) / 2.0f;
    {
        const unsigned short *txt = func_00271A00(&D_0051BA44, 0xD2);
        func_0033D650(self->field_20, CGtV2d(x, 446.5f), CGtV2d(0.0f, 0.5f), 23.0f, CGtV4d(0.75f, 0.75f, 0.75f, 1.0f),
                  D_00665ED0.pFont, txt);
    }
    {
        const unsigned short *txt = func_00271A00(&D_0051BA44, 0xD3);
        func_0033D650(self->field_24, CGtV2d(x + s20.marValues[0], 446.5f), CGtV2d(0.0f, 0.5f), 23.0f, CGtV4d(0.75f, 0.75f, 0.75f, 1.0f),
                  D_00665ED0.pFont, txt);
    }
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
        self->field_28, CGtV2d(320.0f, 240.0f), CGtV2d(0.5f, 0.5f), CGtV2d(455, 146.0f), CGtV4d(1.0f, 1.0f, 1.0f, 1.0f),
        D_01EA4628.p, D_01EA4840.v, D_01EA4848.v, 0);
    self->field_2C = D_004F50A0.field_0;
    return 1;
}
