#include "b3/gamesource/Menu/DebugMenu/Components/B3HeadingComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

extern CGt2dScene D_01E903E0;  // unnamed global, no evidence of its real name yet

// 0x003193D0 (Target #30)
void CB3HeadingComponent::Release()
{
    CB3MenuComponentBase::Release();
    // A local, assigned after the base call: caches the address in $s0 across every later call, matching
    // retail (otherwise it's rematerialized per call, and computed before the base call if hoisted).
    CGt2dScene *scene = &D_01E903E0;
    scene->DestructObject(field_8, field_10);
    field_10 = 0;
    // "!= 0", not a bare "if (field_C)": the bare form makes -O4 move this block out of line (N60).
    if (field_C != 0) {
        int layer1 = field_8 + 1;
        scene->field_2c[layer1].field_c = 0;  // clears the layer's clip frame before destroying it
        field_18->Destruct();
        field_18 = 0;
        scene->DestructObject(layer1, field_C);
        field_C = 0;
    }
    if (field_14 != 0) {
        scene->DestructObject(field_8 + 2, field_14);
        field_14 = 0;
    }
}
