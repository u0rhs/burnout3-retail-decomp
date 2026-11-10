#include "b3/gamesource/Menu/DebugMenu/Components/B3VSelectComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

extern CGt2dScene D_01E903E0;  // unnamed global, no evidence of its real name yet

// 0x0031FE70
void CB3VSelectComponent::Release()
{
    CB3MenuComponentBase::Release();
    // Read after the base call (retail's lh follows the jal). One local per layer and a function-scope counter, in
    // this order (+2, i, +3, +1, +0): retail's saved-register assignment (120 orders tried; `i` in the for loop or
    // declared elsewhere swaps it with layer0's register).
    CGt2dScene *scene = &D_01E903E0;
    int layer2 = field_8 + 2;
    int i;
    int layer3 = field_8 + 3;
    int layer1 = field_8 + 1;
    int layer0 = field_8;
    for (i = 0; i < 9; i++) {
        if (field_38[i] != 0) {
            scene->DestructObject(layer3, field_38[i]);
            field_38[i] = 0;
        }
        if (field_14[i] == 0)
            break;  // [C] the first empty item ends the teardown (beqz to after the loop)
        scene->DestructObject(layer2, field_14[i]);
        field_14[i] = 0;
    }
    if (field_60 != 0) {
        scene->DestructObject(layer0, field_60);
        field_60 = 0;
    }
    scene->DestructObject(layer1, field_5C);
    field_5C = 0;
    field_A8->Destruct();
    field_A8 = 0;
}
