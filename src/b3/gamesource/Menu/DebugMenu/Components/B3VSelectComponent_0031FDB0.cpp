#include "b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent.h"

// 0x0031FDB0
void CB3VSelectComponent::ForceLead(bool a, bool b)
{
    if (field_C4 < 0.0f)
        field_C4 = 0.0f;
    field_D2 = a;
    field_D3 = b;
    if (!field_D2) {
        for (int i = 0; i < field_C->field_2; i++)
            func_00320EB0(this, i, field_AC, false);
    }
}

// 0x0031FE40
void CB3VSelectComponent::SetItemEnabled(int item, bool enabled)
{
    field_10[item].field_4 = !enabled;
    func_00320EB0(this, item, field_BC, field_A4 == item);
}
