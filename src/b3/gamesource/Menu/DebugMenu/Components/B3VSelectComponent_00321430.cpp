#include "b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent.h"

// 0x00321430
bool CB3VSelectComponent::Prepare(float f, float f4, const CB3MenuComponentSelectionData *sel,
                                  CB3VSelectComponentEntryData *entry)
{
    return Prepare(false, 84.0f, f, 30.0f, 40.0f, f4, sel, entry, false);
}

// 0x00321470
bool CB3VSelectComponent::Prepare(float f4, const CB3MenuComponentSelectionData *sel, CB3VSelectComponentEntryData *entry)
{
    return Prepare(false, 84.0f, 240.0f, 30.0f, 40.0f, f4, sel, entry, false);
}
