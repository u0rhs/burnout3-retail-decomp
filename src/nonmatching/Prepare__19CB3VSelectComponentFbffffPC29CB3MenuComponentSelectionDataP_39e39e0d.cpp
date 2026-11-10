// NONMATCHING: Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData -- retail 213 / ours 214 instructions, 84 in changed runs
// draftAO (2026-11-01): scored under its retail-signature symbol (N104 objcopy rename; the archive scored 0 as a symbol mismatch); fixed c (func_00372400's 3rd float): retail computes a + 0*(e - a) before the field_D4 test [C] 0x321348, the draft used the half-width there | Before: lit4fix: .lit4 externs rewritten as literals; was: a147: logic complete (header signature with float f4 + bool b2); 207 vs 213 instrs, ~120 in changed runs, mostly register allocation: retail keeps b2 in fp (highest) and the layer values in s5/s6/s7 with entry in s1, scene in s0; ours spreads them differently (decl-order permutations of scene/l2/l3/
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm (0x3210D0..0x321424): calls identical, every store and float operand checked; retail's (bool, 5 floats, sel, entry, bool) per N104


#include "b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern CGt2dScene D_01E903E0;
extern CB3MenuPageManager D_01E90240;
extern const float D_004C5390;
// 0x00372400, unnamed: prepares the selection bar object (pos, anchor, colour pointer, three floats) [G]
extern "C" void func_00372400(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, const CGtV4d &colour, float a, float b, float c);

// 0x003210D0
bool CB3VSelectComponent::Prepare(bool b, float x, float f1, float f2, float f3, float f4,
                                  const CB3MenuComponentSelectionData *sel, CB3VSelectComponentEntryData *entry, bool b2)
{
    CB3MenuComponentBase::Prepare();
    int layer = field_8;
    CGt2dScene *scene = &D_01E903E0;
    int l2 = layer + 2;
    int l3 = layer + 3;
    int l1 = layer + 1;
    *((unsigned char *)this + 0xD0) = 0;
    *(float *)((char *)this + 0xCC) = 0.4f;
    field_C0 = f4;
    *((unsigned char *)this + 0xD1) = b;
    field_BC = x;
    if (*((unsigned char *)this + 0xD1) != 0)
        field_AC = 320.0f + field_BC;
    else
        field_AC = field_BC - 320.0f;
    field_C = sel;
    field_A4 = -1;
    field_10 = entry;
    *(float *)&field_C8 = -1.0f;
    field_B0 = f2;
    field_B4 = f3;
    field_A8 = scene->field_14->ConstructChild();
    field_A8->field_0.SetIdentity();
    float zero = 0.0f;
    field_B8 = zero + f1 - 0.5f * ((2.0f + field_B0) * ((float)(int)field_C->field_2 - 1.0f));
    for (int i = 0; i < field_C->field_2; i++) {
        field_14[i] = scene->ConstructObject(l2, field_A8);
        if (field_10[i].pad5[0] != 0 && field_38[i] == 0) {
            field_38[i] = scene->ConstructObject(l3, field_A8);
        } else if (field_38[i] != 0) {
            scene->DestructObject(l2, field_38[i]);
        }
        func_00320EB0(this, i, field_AC, false);
    }
    field_5C = scene->ConstructObject(l1, field_A8);
    int idx = field_C->field_0;
    float w = field_14[idx]->mObjectSpace.mSize.marValues[0];
    float e = D_004C5390 + w;
    float a = zero + 640.0f + 2.0f * field_BC;
    float half = 0.0f;
    float d = e - a;
    if (field_D4)
        half = w / 2.0f;
    // retail 0x321348 computes c before the field_D4 test, with the zero register (f6) as the factor: c = a whatever
    // field_D4 holds -- an interpolation at t = 0 [C]; half only moves pos.x below
    float c = zero + a + zero * d;
    float t = c - e;
    CGtV2d pos;
    pos.SetX(-0.5f * t - half);
    pos.SetY(zero + field_B8 + (float)idx * (2.0f + field_B0));
    CGtV2d anchor(0.0f, 0.5f);
    func_00372400(field_5C, pos, anchor, D_01E90240.field_110, 640.0f + t, field_BC, c);
    *((unsigned char *)this + 0xD2) = 1;
    *((unsigned char *)this + 0xD3) = 1;
    field_C4 = -1.0f;
    field_D4 = b2;
    field_60 = 0;
    return true;
}
