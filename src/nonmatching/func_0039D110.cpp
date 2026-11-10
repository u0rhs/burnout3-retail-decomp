// NONMATCHING: func_0039D110 -- retail 217 / ours 217 instructions, 63 in changed runs
// near36: 63 changed (was 77). Scene as the page manager's member (&D_01E90240.field_1A0) with real CGt2dScene::ConstructObject calls, FLT_MAX .lit4 as a literal, o1/o2 read inside the argument expressions (retail builds the anchor temp first). Left: s0/s1 swap (retail s0=row, s1=&D_01E90240; ours reversed -- decl/definition order, mgr-from-scene (sreg PrepareBorders trick), no-mgr-local all inert or worse) and the Image::Prepare texture-index lb that retail schedules before the CGtV2d temp stores (tex/index locals inert).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.



// func_0039D110 -- hand-written from retail (lifter refused); builds one popup/option row of 5 2d objects (background, image, 3 texts)
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_D_00665ED0 { CGt2dFont * pFont; unsigned char pad[0x100]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_3C { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_039D110_row {
    CGt2dObject * field_0[5];
};
struct UnkStruct_039D110 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    UnkStruct_039D110_row field_C[1];
    unsigned char pad_20[0x40];
    CGt2dFrame * field_60;
};
extern UnkStruct_D_00665ED0 D_00665ED0;
extern CB3MenuPageManager D_01E90240;
extern UnkStruct_P D_0051BA44, D_004C9A58, D_01EA4790, D_01EA4798;
extern signed char D_004C9A60[], D_004C9A70[];
extern int D_004C9A78[];
extern CGtTexture * D_01EA46B0[];
extern "C" void func_0033D4E0(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const CGt2dFont *, const unsigned short *, const CGtV2d *, int);
extern "C" void Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, unsigned int);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, CGtTexture *, const CGtV2d &, const CGtV2d &, unsigned int);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" void func_003D0710(CGt2dObject *, const CGtV2d &, const CGtV2d &, CGtV4d, int, int, int, const CGt2dFont *, float, float, const unsigned short *, bool);

// 0x0039D110
extern "C" void func_0039D110(UnkStruct_039D110 * self, int idx, const unsigned short * textA, const unsigned short * textB, bool flag)
{
    CB3MenuPageManager * const mgr = &D_01E90240;
    CGt2dScene * scene = &D_01E90240.field_1A0;
    int base = self->field_8;
    int hi = base + 2;
    UnkStruct_039D110_row * row = &self->field_C[idx];
    float y = 0.0f + 210.0f + 60.0f * (float)idx;
    row->field_0[4] = scene->ConstructObject(base, self->field_60);
    row->field_0[3] = scene->ConstructObject(base + 1, self->field_60);
    for (int i = 0; i < 2; i++) {
        row->field_0[1 + i] = scene->ConstructObject(hi, self->field_60);
    }
    row->field_0[0] = scene->ConstructObject(hi, self->field_60);
    func_0033D4E0(row->field_0[1], CGtV2d(300.0f, y), CGtV2d(0.0f, 0.5f), 40.0f, *(CGtV4d *)((char *)mgr + 0x180), D_00665ED0.pFont, textA, (const CGtV2d *)&D_004C9A58, 2);
    float ex = flag ? 8.0f : 0.0f;
    func_0033D4E0(row->field_0[2], CGtV2d(ex + (5.0f + (row->field_0[1]->mObjectSpace.mTopLeftPos.marValues[0] + row->field_0[1]->mObjectSpace.mSize.marValues[0])), y), CGtV2d(0.0f, 0.5f), 28.0f, *(CGtV4d *)((char *)mgr + 0x10), D_00665ED0.pFont, textB, (const CGtV2d *)&D_004C9A58, 2);
    Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(row->field_0[4], CGtV2d(220.0f, y), CGtV2d(0.0f, 0.5f), CGtV2d(60.0f + ((row->field_0[2]->mObjectSpace.mTopLeftPos.marValues[0] + row->field_0[2]->mObjectSpace.mSize.marValues[0]) - 220.0f), 30.0f), mgr->field_110, 3);
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(row->field_0[3], CGtV2d(220.0f, y), CGtV2d(0.5f, 0.5f), CGtV2d(50.0f, 50.0f), mgr->field_110, D_01EA46B0[D_004C9A60[idx]], *(const CGtV2d *)&D_01EA4790, *(const CGtV2d *)&D_01EA4798, 0);
    const unsigned short * text = func_00271A00(&D_0051BA44, D_004C9A78[idx]);
    func_003D0710(row->field_0[0], CGtV2d(220.0f, y), CGtV2d(1.0f, 0.5f), mgr->field_110, D_004C9A70[idx], 2, 0, D_00665ED0.pFont, 32.0f, 3.402823466e+38f, text, false);
}


