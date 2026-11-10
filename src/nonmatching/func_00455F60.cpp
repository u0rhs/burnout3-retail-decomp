// NONMATCHING: func_00455F60 -- retail 321 / ours 321 instructions, 12 in changed runs
// 12 changed, 321/321: float-pair copies (+0x28/+0x38) -- retail x->f1 loaded+stored first; ours gets registers or store order, not both
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00455F60 -- v306 hand draft (no lifter draft). Menu component Prepare tail called by func_00456550: picks up to
// three string ids from field_7C/field_78 (jump table, case bodies in retail's block order), builds the 2..5 text
// objects (layers field_8 + D_004D34E8[k], as func_00456470's Release loop), caches the second/third object's pos/size
// at +0x28/+0x38 (4-byte float pairs, lwc1/swc1 [C]), marks the two layers and zeroes every object's alpha.
// Prototypes of func_003D0710 / func_003824D0 as the proven B3HelpBar/B3Heading units. Types/fields [G].
// Open (12 changed): retail loads x then y of each cached pair and stores x then y with x in $f1; every source order
// gives either the registers or the store order, not both (sreg run: no lever).
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern CB3MenuPageManager D_01E90240;
extern CGt2dScene D_01E903E0;
struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_D_Pad16 { unsigned char pad[0x10]; };
extern UnkStruct_D_Pad16 D_0051BA44;
extern unsigned char D_004D34E8[];  // [G] element count unknown (as func_00456470)
extern unsigned char D_004D34E9[];
extern unsigned char D_004D34EA[];
extern unsigned char D_004D34EB[];
extern unsigned char D_004D34EC[];
extern int D_004D34F0[][2];         // [G] pairs of string ids
extern int D_004D3508[];            // [G] string ids
extern const CGtV2d D_004D3418;
extern const CGtV2d D_004D3420;
extern const CGtV2d D_004D3428;
extern const CGtV2d D_004D3430;
extern const CGtV2d D_004D3438;
extern "C" unsigned short *func_00271A00(void *, int);
extern "C" int func_003EAE40(int p0, int p1);
extern "C" void func_003D0710(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, CGtV4d colour, int a, int b,
                              int c, CGt2dFont *font, float size, float d, const unsigned short *text, int e);
extern "C" void func_003824D0(CGt2dObject *obj, const CGtV2d &a, const CGtV2d &b,
                              float c, CGtV4d d, CGtV4d e, const unsigned short *text,
                              int f, float g, float h);
struct UnkStruct_00455F60_v2 { float x; float y; };
struct UnkStruct_00455F60 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject *field_C[5];
    unsigned char field_20[5];
    unsigned char pad_25[3];
    UnkStruct_00455F60_v2 field_28[2];
    UnkStruct_00455F60_v2 field_38[2];
    unsigned char pad_48[0x30];
    int field_78;
    int field_7C;
};
// 0x00455F60
extern "C" void func_00455F60(UnkStruct_00455F60 *self)
{
    int c = 0xFA5;
    CGt2dScene *scene = &D_01E90240.field_1A0;
    CB3MenuPageManager *mgr = &D_01E90240;
    int a = c;
    int b = c;
    CGt2dFrame *root = scene->field_14;
    switch (self->field_7C) {
    case 1:
        a = 0xB47;
        break;
    case 2:
        a = 0xB48;
        b = 0xB49;
        break;
    case 3:
        a = D_004D34F0[self->field_78][0];
        b = D_004D34F0[self->field_78][1];
        break;
    case 4:
        a = 0xB44;
        b = 0xB45;
        break;
    case 5:
        a = 0xB46;
        break;
    case 8:
        a = D_004D3508[self->field_78];
        break;
    case 7:
        c = func_003EAE40(self->field_78, 1);
        a = 0xB4A;
        b = 0xB4B;
        break;
    case 11:
        if (self->field_78 == 3)
            a = 0xCB4;
        else
            a = self->field_78 * 2 + 0xC45;
        b = a + 1;
        break;
    case 9:
    case 10:
        a = 0xCB6;
        b = 0xCB7;
        break;
    }
    unsigned short *t;
    self->field_C[0] = scene->ConstructObject(self->field_8 + D_004D34E8[0], root);
    self->field_C[1] = scene->ConstructObject(self->field_8 + D_004D34E9[0], root);
    t = func_00271A00(&D_0051BA44, 0x39E);
    func_003D0710(self->field_C[0], D_004D3418, CGtV2d(0.5f, 0.5f), mgr->field_110, 1, 1, 1,
                  D_00665ED0.pFont, 40.0f, 3.402823466e+38f, t, 0);
    t = func_00271A00(&D_0051BA44, a);
    func_003D0710(self->field_C[1], D_004D3420, CGtV2d(0.5f, 0.5f), mgr->field_110, 1, 1, 0,
                  D_00665ED0.pFont, 24.0f, 3.402823466e+38f, t, 0);
    { float x = self->field_C[1]->Pos().X(); float y = self->field_C[1]->Pos().Y(); self->field_28[0].y = y; self->field_28[0].x = x; }
    { float x = self->field_C[1]->Size().X(); float y = self->field_C[1]->Size().Y(); self->field_38[0].y = y; self->field_38[0].x = x; }
    if (b != 0xFA5) {
        self->field_C[2] = scene->ConstructObject(self->field_8 + D_004D34EA[0], root);
        t = func_00271A00(&D_0051BA44, b);
        func_003D0710(self->field_C[2], D_004D3420 + D_004D3428, CGtV2d(0.5f, 0.5f), mgr->field_110, 1, 1, 0,
                      D_00665ED0.pFont, 24.0f, 3.402823466e+38f, t, 0);
        { float x = self->field_C[2]->Pos().X(); float y = self->field_C[2]->Pos().Y(); self->field_28[1].y = y; self->field_28[1].x = x; }
        { float x = self->field_C[2]->Size().X(); float y = self->field_C[2]->Size().Y(); self->field_38[1].y = y; self->field_38[1].x = x; }
    }
    if (c != 0xFA5) {
        self->field_C[4] = scene->ConstructObject(self->field_8 + D_004D34EC[0], root);
        self->field_C[3] = scene->ConstructObject(self->field_8 + D_004D34EB[0], root);
        t = func_00271A00(&D_0051BA44, c);
        func_003824D0(self->field_C[4], D_004D3438, CGtV2d(1.0f, 1.0f), 26.0f, mgr->field_40, mgr->field_50,
                      t, 0x21, 1.5f, 3.402823466e+38f);
        t = func_00271A00(&D_0051BA44, 0xB3B);
        func_003D0710(self->field_C[3], D_004D3430, CGtV2d(0.5f, 0.5f), mgr->field_110, 1, 1, 1,
                      D_00665ED0.pFont, 26.0f, 3.402823466e+38f, t, 0);
        CGt2dObject *o = self->field_C[3];
        CGtV2d p = D_004D3430;
        p.marValues[0] -= (o->mObjectSpace.mTopLeftPos.marValues[0] + o->mObjectSpace.mSize.marValues[0]) - o->mObjectSpace.mTopLeftPos.marValues[0];
        o->mObjectSpace.mTopLeftPos = p;
    }
    scene->field_2c[self->field_8].field_0 = 1;
    int k = self->field_8 + 1;
    scene->field_2c[k].field_0 = 1;
    for (int i = 0; i < 5; i++) {
        if (self->field_C[i] != 0)
            self->field_C[i]->mObjectSpace.mColour.SetA(0.0f);
    }
}
