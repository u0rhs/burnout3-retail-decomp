#include "b3/gamesource/Menu/DebugMenu/Pages/B3MenuPageBase.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

extern CB3MenuPageManager D_01E90240;  // unnamed global (the page manager instance)

// 0x00318530
bool CB3MenuPageBase::Prepare(bool b)
{
    D_01E90240.SetMenuPage(this, b);
    return true;
}
