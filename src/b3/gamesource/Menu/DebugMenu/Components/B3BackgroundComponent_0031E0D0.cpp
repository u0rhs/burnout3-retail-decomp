#include "b3/gamesource/Menu/DebugMenu/Components/B3BackgroundComponent.h"

// 0x0031E0D0
void CB3BackgroundComponent::Construct()
{
    CB3MenuComponentBase::Construct(6);
    field_20 = 0;
    field_4C = 0;
    field_50 = 0;
    field_54 = 0;
    field_58 = 0;
    field_65 = false;
    field_67 = true;
    field_66 = true;
    for (int i = 0; i < 5; i++) {
        field_24[i] = 0;
        field_38[i] = 0;
    }
}
