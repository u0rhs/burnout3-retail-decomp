#include "b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent.h"

using GtMathPs2::CGtV2d;

// 0x0031A9C0 (Target #36). Called from game/unit_003C35C0; the type-13 counterpart of func_0031A840: for a
// prepared type-13 heading, switches to award type 10/11/12 (func_0031A5D0 builds its text), then shrinks
// the heading text (field_C) to fit left of field_14, keeping its right-middle point in place.
// Needs CGtV2d::operator*(float) as a member (vector by reference): the free by-value form GtMathPs2.h
// had before stores and reloads `size` (tested).
void func_0031A9C0(CB3HeadingComponent *self, int type)
{
    if (!self->field_A || self->field_26 != 13)
        return;
    switch (type) {
    case 10:
        func_0031A5D0(self, 2);
        break;
    case 11:
        func_0031A5D0(self, 0);
        break;
    case 12:
        func_0031A5D0(self, 1);
        break;
    case 13:
        return;
    default:
        return;
    }
    self->field_26 = type;
    CGt2dObject *text = self->field_C;
    if (text == 0)
        return;
    CGtV2d size = text->mObjectSpace.mSize;
    float avail = 597.4f - (self->field_14->mObjectSpace.mTopLeftPos.marValues[0] + self->field_14->mObjectSpace.mSize.marValues[0]) - 12.0f;
    if (size.marValues[0] > avail) {
        CGtV2d anchor(1.0f, 0.5f);
        CGtV2d pos = text->mObjectSpace.mTopLeftPos + anchor * size;
        CGtV2d newSize = size * avail / size.marValues[0];
        text->mObjectSpace.mSize = newSize;
        self->field_C->mObjectSpace.mTopLeftPos = pos - newSize * anchor;
    }
}

// [L] menu page instances (all .bss, all compared by address only; their classes aren't identified).
// Padded for N51: retail addresses each with the 2-instruction absolute lui/addiu form.
struct UnkStruct_MenuPage {
    unsigned char pad[0x100];
};
extern UnkStruct_MenuPage D_01E94F30;
extern UnkStruct_MenuPage D_01E95B54;
extern UnkStruct_MenuPage D_01E95C38;
extern UnkStruct_MenuPage D_01E97EC8;
extern UnkStruct_MenuPage D_01E95C44;
extern UnkStruct_MenuPage D_01E95C70;
extern UnkStruct_MenuPage D_01E95CA8;
extern UnkStruct_MenuPage D_01E95CB8;
extern UnkStruct_MenuPage D_01E95CD0;
extern UnkStruct_MenuPage D_01E95CE0;
extern UnkStruct_MenuPage D_01E96410;
extern UnkStruct_MenuPage D_01E96418;
extern UnkStruct_MenuPage D_01E96424;
extern UnkStruct_MenuPage D_01E9644C;
extern UnkStruct_MenuPage D_01E96450;
extern UnkStruct_MenuPage D_01E96474;
extern UnkStruct_MenuPage D_01E9842C;
extern UnkStruct_MenuPage D_01E964A4;
extern UnkStruct_MenuPage D_01E96514;
extern UnkStruct_MenuPage D_01E96550;
extern UnkStruct_MenuPage D_01E96F20;
extern UnkStruct_MenuPage D_01E96F58;
extern UnkStruct_MenuPage D_01E96F5C;
extern UnkStruct_MenuPage D_01E98490;
extern UnkStruct_MenuPage D_01E99840;
extern UnkStruct_MenuPage D_01E9987C;
extern UnkStruct_MenuPage D_01E9996C;
extern UnkStruct_MenuPage D_01E999A0;
extern UnkStruct_MenuPage D_01E9B4C0;
extern UnkStruct_MenuPage D_01E9B4CC;
extern UnkStruct_MenuPage D_01E9B634;
extern UnkStruct_MenuPage D_01E9B690;
extern UnkStruct_MenuPage D_01E9B698;
extern UnkStruct_MenuPage D_01E9B6B4;
extern UnkStruct_MenuPage D_01E9B740;
extern UnkStruct_MenuPage D_01E9B794;
extern UnkStruct_MenuPage D_01E9B8C0;
extern UnkStruct_MenuPage D_01E9B8F8;
extern UnkStruct_MenuPage D_01E9B924;
extern UnkStruct_MenuPage D_01E9B940;
extern UnkStruct_MenuPage D_01E9C870;
extern UnkStruct_MenuPage D_01E9E000;
extern UnkStruct_MenuPage D_01E9E018;
extern UnkStruct_MenuPage D_01E9E050;
extern UnkStruct_MenuPage D_01E9F9A0;
extern UnkStruct_MenuPage D_01E9F9F4;
extern UnkStruct_MenuPage D_01E9FBA8;
extern UnkStruct_MenuPage D_01E9FC00;
extern UnkStruct_MenuPage D_01EA0070;
extern UnkStruct_MenuPage D_01EA0778;
extern UnkStruct_MenuPage D_01EA077C;
extern UnkStruct_MenuPage D_01EA0780;
extern UnkStruct_MenuPage D_01EA07D0;
extern UnkStruct_MenuPage D_01EA08A0;
extern UnkStruct_MenuPage D_01EA14C0;
extern UnkStruct_MenuPage D_01EA1B20;
extern UnkStruct_MenuPage D_01EA2870;
extern UnkStruct_MenuPage D_01EA2960;
extern UnkStruct_MenuPage D_01E96F78;
extern UnkStruct_MenuPage D_01E94E4C;
extern UnkStruct_MenuPage D_01E94EF0;
extern UnkStruct_MenuPage D_01E97F38;
extern UnkStruct_MenuPage D_01E95920;
extern UnkStruct_MenuPage D_01E97640;
extern UnkStruct_MenuPage D_01E97D08;
extern UnkStruct_MenuPage D_01E97DCC;
extern UnkStruct_MenuPage D_01E95780;

// [L] the current menu page (lw, absolute). Padded for N51.
struct UnkStruct_D_01E90430 {
    UnkStruct_MenuPage *value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E90430 D_01E90430;

// [L] two ints of the object Prepare__14CB3MenuChoicesFv initializes (D_01E900B0, N62): +0x4 and +0x8. Padded for N51.
struct UnkStruct_D_01E900B4 {
    int value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E900B4 D_01E900B4;
extern UnkStruct_D_01E900B4 D_01E900B8;

// 0x0031ABC0 (Target #36). Called by Prepare(EHeadingType) for type 14: the heading string for the current
// menu page, as an index into the D_0051BA48 string table; 10 = none. `self` is unused (leaf, a0 ignored).
// The chains are retail's compare order, generated from its code. `id` declared before `page` (the
// other order swaps $v0/$v1 in the first lui).
int func_0031ABC0(CB3HeadingComponent *self)
{
    int id = 10;
    UnkStruct_MenuPage *page = D_01E90430.value;
    if (page == &D_01E94F30 ||
        page == &D_01E95B54 ||
        page == &D_01E95C38 ||
        page == &D_01E97EC8 ||
        page == &D_01E95C44 ||
        page == &D_01E95C70 ||
        page == &D_01E95CA8 ||
        page == &D_01E95CB8 ||
        page == &D_01E95CD0 ||
        page == &D_01E95CE0 ||
        page == &D_01E96410 ||
        page == &D_01E96418 ||
        page == &D_01E96424 ||
        page == &D_01E9644C ||
        page == &D_01E96450 ||
        page == &D_01E96474 ||
        page == &D_01E9842C ||
        page == &D_01E964A4 ||
        page == &D_01E96514 ||
        page == &D_01E96550 ||
        page == &D_01E96F20 ||
        page == &D_01E96F58 ||
        page == &D_01E96F5C)
        id = 3;
    else if (page == &D_01E98490 ||
        page == &D_01E99840 ||
        page == &D_01E9987C ||
        page == &D_01E9996C ||
        page == &D_01E999A0 ||
        page == &D_01E9B4C0 ||
        page == &D_01E9B4CC ||
        page == &D_01E9B634 ||
        page == &D_01E9B690 ||
        page == &D_01E9B698 ||
        page == &D_01E9B6B4 ||
        page == &D_01E9B740 ||
        page == &D_01E9B794 ||
        page == &D_01E9B8C0 ||
        page == &D_01E9B8F8 ||
        page == &D_01E9B924 ||
        page == &D_01E9B940 ||
        page == &D_01E9C870 ||
        page == &D_01E9E000 ||
        page == &D_01E9E018 ||
        page == &D_01E9E050 ||
        page == &D_01E9F9A0 ||
        page == &D_01E9F9F4 ||
        page == &D_01E9FBA8 ||
        page == &D_01E9FC00 ||
        page == &D_01EA0070 ||
        page == &D_01EA0778 ||
        page == &D_01EA077C ||
        page == &D_01EA0780 ||
        page == &D_01EA07D0 ||
        page == &D_01EA08A0 ||
        page == &D_01EA14C0 ||
        page == &D_01EA1B20 ||
        page == &D_01EA2870 ||
        page == &D_01EA2960)
        id = 0;
    else if (page == &D_01E96F78 ||
        page == &D_01E94E4C ||
        page == &D_01E94EF0 ||
        page == &D_01E97F38) {
        switch (D_01E900B4.value) {
        case 0:
            id = 2;
            break;
        case 1:
            if (page == &D_01E94E4C) {
                id = 8;
                break;
            }
            switch (D_01E900B8.value) {
            case 0:
                id = 5;
                break;
            case 1:
                id = 9;
                break;
            case 2:
                id = 6;
                break;
            case 3:
                id = 1;
                break;
            }
            break;
        case 2:
            id = 4;
            break;
        case 3:
            id = 0;
            break;
        case 4:
            id = 8;
            break;
        }
    } else if (page == &D_01E95920)
        id = 2;
    else if (page == &D_01E97640 ||
        page == &D_01E97D08 ||
        page == &D_01E97DCC ||
        page == &D_01E95780)
        id = 4;
    return id;
}
