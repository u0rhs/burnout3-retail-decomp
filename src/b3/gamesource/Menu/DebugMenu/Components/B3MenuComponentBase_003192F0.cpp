#include "b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase.h"

// Same declaration as B3HeadingComponent_00319490.cpp (N51 padding).
struct UnkStruct_D_0051BA44 {
    CB3Strings strings;
    unsigned char pad[0x100];
};
extern UnkStruct_D_0051BA44 D_0051BA44;

// 0x003192F0
void CB3ScrollingTextData::SetData(const unsigned short *text)
{
    field_0 = text;
}

// 0x00319300
void CB3ScrollingTextData::SetData(EGlobalStrings id)
{
    field_0 = D_0051BA44.strings.GetString(id);
}

// 0x00319330
bool func_00319330(CB3MenuComponentSelectionData *self)
{
    int next = self->field_0 + 1;
    if (next < self->field_2) {
        self->field_0 = next;
        return true;
    }
    return false;
}

// 0x00319360
bool func_00319360(CB3MenuComponentSelectionData *self)
{
    if (self->field_0 != 0) {
        self->field_0 = self->field_0 - 1;
        return true;
    }
    return false;
}
