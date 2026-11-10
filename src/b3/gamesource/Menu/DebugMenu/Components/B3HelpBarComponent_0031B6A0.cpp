#include "b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

extern CGt2dScene D_01E903E0;  // unnamed global, no evidence of its real name yet (as B3HeadingComponent_003193D0.cpp)

// 0x0031B6A0 (Target #40). Same shape as CB3HeadingComponent::Release (Target #30): the scene address held in
// a local assigned after the base call, and `!= 0` tests.
void CB3HelpBarComponent::Release()
{
    CB3MenuComponentBase::Release();
    CGt2dScene *scene = &D_01E903E0;
    if (field_14 != 0) {
        scene->DestructObject(field_8, field_14);
        field_14 = 0;
    }
    if (field_18[0] != 0) {
        scene->DestructObject(field_8, field_18[0]);
        field_18[0] = 0;
    }
    if (field_20 != 0) {
        scene->DestructObject(field_8, field_20);
        field_20 = 0;
    }
    if (field_18[1] != 0) {
        scene->DestructObject(field_8, field_18[1]);
        field_18[1] = 0;
    }
    scene->field_2c[field_8].field_c = 0;  // clears the layer's clip frame before destroying it
    if (field_24 != 0) {
        field_24->Destruct();
        field_24 = 0;
    }
}
