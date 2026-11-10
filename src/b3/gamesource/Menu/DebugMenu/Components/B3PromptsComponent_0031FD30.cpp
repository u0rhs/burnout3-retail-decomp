#include "b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent.h"

// 0x0031FD30
void CB3PromptsComponent::Construct()
{
    CB3MenuComponentBase::Construct(1);
    // unsigned long (64-bit; int/unsigned int give a 32-bit counter): retail daddiu + sltiu, index sign-extended.
    for (unsigned long i = 0; i < 11; i++) {
        field_1C[i] = 0;
        field_48[i] = 0;
    }
    for (unsigned long i = 0; i < 4; i++) {
        field_74[i] = 0;
        field_84[i] = 0;
    }
    field_94 = 0;
    field_98 = 0;
}
