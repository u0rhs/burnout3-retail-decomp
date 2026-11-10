#include "b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent.h"

// 0x003214B0
void CB3VSelectComponent::Construct()
{
    CB3MenuComponentBase::Construct(4);
    for (int i = 0; i < 9; i++) {
        field_14[i] = 0;
        field_38[i] = 0;
    }
    field_C4 = -1.0f;
}
