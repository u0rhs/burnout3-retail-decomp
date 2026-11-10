#include "b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent.h"

// 0x0031C590 (Target #41). Stores in retail's order.
void CB3HelpBarComponent::Construct()
{
    CB3MenuComponentBase::Construct(1);
    field_14 = 0;
    field_20 = 0;
    field_18[0] = 0;
    field_18[1] = 0;
    field_C = 0;
    field_10 = 0;
}
