// Hand-written; the lifter refused it (hdr12: exact with the N224 Interpolate(CGtV4d) + call-site float t).

// DRAFT -- NOT MATCHING, NOT WIRED IN (retail's asm is still linked: game/unit_0031B860.s). Blocked on the same
// GtMathPs2::Interpolate lq+qmtc2 fold as func_0031BD60 (docs/known.md N94).
#include "b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern CB3MenuPageManager D_01E90240;  // unnamed global (the page manager instance)

// Same declarations as B3HelpBarComponent_0031BD60.cpp.
struct UnkStruct_D_0066A4C0 {
    unsigned char pad0[0x30];
    CGtV4d field_30;
    unsigned char pad40[0x20];
    CGtV4d field_60;
    unsigned char pad70[0x100];
};
extern UnkStruct_D_0066A4C0 D_0066A4C0;

// [L] the allocator the two prompt strings come from (16 characters each). Padded for N51.
struct UnkStruct_D_01E90438 {
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E90438 D_01E90438;
extern "C" const unsigned short *AllocUTF16String__19CB3MenuStringBufferFi(UnkStruct_D_01E90438 *pool, int length);

extern "C" void func_003824D0(CGt2dObject *obj, const CGtV2d &a, const CGtV2d &b, float c, CGtV4d d, CGtV4d e,
                              const unsigned short *text, int f, float g, float h);

// 0x0031BF40. Prepares the bar as one or two prompts (left text, and right text when given): two string buffers,
// the objects (the right pair only with a right prompt), the bar's clip frame, both prompt texts, then each side's
// prompt via func_0031BD60; finally resets the per-side state and the slide bounds.
bool func_0031BF40(CB3HelpBarComponent *self, const unsigned short *left, const unsigned short *right)
{
    CGt2dScene *scene = &D_01E90240.field_1A0;
    CGt2dFrame *root = scene->field_14;
    UnkStruct_D_0066A4C0 *colours = &D_0066A4C0;
    self->CB3MenuComponentBase::Prepare();
    self->field_48[0] = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x10);
    self->field_48[1] = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x10);
    bool two = right != 0;
    self->field_14 = scene->ConstructObject(self->field_8, root);
    self->field_18[0] = scene->ConstructObject(self->field_8, root);
    if (two) {
        self->field_20 = scene->ConstructObject(self->field_8, root);
        self->field_18[1] = scene->ConstructObject(self->field_8, root);
    }
    self->field_24 = root->ConstructChild();
    self->field_24->field_0.SetIdentity();
    self->field_24->field_0.field_0 = CGtV2d(16.0f, 386.0f);
    self->field_24->field_0.field_8 = CGtV2d(608.0f, 28.0f);
    scene->field_2c[self->field_8].field_c = self->field_24;
    self->field_C = 0;
    self->field_10 = 0;
    self->field_6D = -1;
    if (two)  // branches with a store each, as retail (a ?: compiles to movz)
        self->field_6E = 2;
    else
        self->field_6E = 1;
    float t = 0.25f;
    CGtV4d blend = GtMathPs2::Interpolate(colours->field_60, colours->field_30, t);
    CGtV4d base;
    base = colours->field_30;  // one copy (lq/sq), passed to both prompt texts
    func_003824D0(self->field_14, CGtV2d(45.0f, 400.0f), CGtV2d(0.0f, 0.5f), 27.0f, blend, base, left, 1,
                  1.25f, 3.402823466e+38f);
    func_0031BD60(self, 0, false);
    if (two) {
        func_003824D0(self->field_20, CGtV2d(490.0f, 400.0f), CGtV2d(0.0f, 0.5f), 27.0f, blend, base,
                      right, 1, 1.25f, 3.402823466e+38f);
        func_0031BD60(self, 0, true);
    }
    for (int i = 0; i < 2; i++) {
        self->field_54[i] = -1.0f;
        self->field_6F[i] = 0;
    }
    self->field_5C = 0.0f;
    self->field_60 = 0.0f;
    self->field_64 = 0.0f;
    self->field_68 = 0.0f;
    self->field_6C = 0;
    return true;
}
