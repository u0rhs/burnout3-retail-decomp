#include "b3/gamesource/Menu/DebugMenu/Components/B3HSelectComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

extern CGt2dScene D_01E903E0;  // unnamed global, no evidence of its real name yet

// 0x0031CC90 (Target #27)
void CB3HSelectComponent::Release()
{
    CB3MenuComponentBase::Release();
    D_01E903E0.DestructObject(field_8, field_14);
}
