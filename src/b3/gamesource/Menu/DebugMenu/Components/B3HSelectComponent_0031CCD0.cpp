#include "b3/gamesource/Menu/DebugMenu/Components/B3HSelectComponent.h"

// [L] true size/type unknown; padded well past CodeWarrior's small-data threshold for the N51
// GPREL16 idiom -- retail's own instructions use the 2-instruction absolute addressing form.
struct UnkStruct_D_01E90424 {
    int value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E90424 D_01E90424;

extern GtMathPs2::CGtV4d D_01E903C0;  // unnamed global CGtV4d constant, no evidence of its real name yet

// [L] a field within gGraphicsManager (config/symbol_addrs_b3names.txt tags 0x00665EC0-0x00666330 as
// one contiguous "gGraphicsManager" region; this is the field at +0x10), read here as a default font
// pointer. Padded well past CodeWarrior's small-data threshold for the N51 GPREL16 idiom.
struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;

// 0x0031CCD0 (Target #28)
void CB3HSelectComponent::Update(float)
{
    if (D_01E90424.value != 5)
        return;

    unsigned short cur = *field_C;
    if (field_18 != cur) {
        field_18 = cur;
        field_14->Prepare(GtMathPs2::CGtV2d(320.0f, 120.0f), GtMathPs2::CGtV2d(0.5f, 0.5f), 40.0f,
                           D_01E903C0, D_00665ED0.pFont, field_10[field_18].text,
                           GtMathPs2::CGtV2d(2.0f, 2.0f), (CGt2dObjectItalicText::ETextType)1);
    }
}
