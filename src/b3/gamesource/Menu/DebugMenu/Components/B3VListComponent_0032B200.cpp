#include "b3/gamesource/Menu/DebugMenu/Components/B3VListComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

extern CGt2dScene D_01E903E0;  // unnamed global, no evidence of its real name yet

// 0x0032B200 (Target #22)
void CB3VListComponent::Release()
{
    CB3MenuComponentBase::Release();
    CGt2dScene *scene = &D_01E903E0;
    int type = field_8;
    for (int i = 0; i < field_C; i++) {
        scene->DestructObject(type, elements[i]);
        elements[i] = 0;
    }
}
