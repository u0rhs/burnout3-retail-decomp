#include "b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

extern CB3MenuPageManager D_01E90240;   // unnamed global, no evidence of its real name yet

// 0x00319390 (Target #21)
void CB3MenuComponentBase::Release()
{
    field_A = false;
}

// 0x003193A0 (Target #21)
bool CB3MenuComponentBase::Prepare()
{
    field_A = true;
    field_B = false;
    return true;
}

// 0x003193B0 (Target #21)
void CB3MenuComponentBase::Construct(int type)
{
    field_A = false;
    field_B = false;
    D_01E90240.AddComponent(this, type);
}
