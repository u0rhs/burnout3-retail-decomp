#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase.h"

// 0x0030D6B0 (Target #24)
void CB3MenuPageManager::AddComponent(CB3MenuComponentBase *component, int type)
{
    component->field_8 = field_1D4;
    field_1D4 += type;
    component->field_4 = field_1D8;
    field_1D8 = component;
}
