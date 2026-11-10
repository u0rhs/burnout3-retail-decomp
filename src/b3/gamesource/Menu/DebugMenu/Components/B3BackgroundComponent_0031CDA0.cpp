#include "b3/gamesource/Menu/DebugMenu/Components/B3BackgroundComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

extern CGt2dScene D_01E903E0;  // unnamed global, no evidence of its real name yet

// 0x0031CDA0
void CB3BackgroundComponent::ReleaseObjects()
{
    CGt2dScene *scene = &D_01E903E0;
    // One local per layer, declared in this order (+0, +1, +2, +4, +3, +5): retail precomputes each into its own
    // saved register before the first call ($s3/$s2/$s1/$s0/$s6). A single `short layer` reloads/extends instead, and
    // any other declaration order permutes the registers. The flag stores go after them (before: scheduled earlier).
    int layer0 = field_8;
    int layer1 = field_8 + 1;
    int layer2 = field_8 + 2;
    int layer4 = field_8 + 4;
    int layer3 = field_8 + 3;
    int layer5 = field_8 + 5;
    field_65 = false;
    field_67 = true;
    field_66 = true;
    if (field_20 != 0) {
        scene->DestructObject(layer0, field_20);
        field_20 = 0;
    }
    if (field_4C != 0) {
        scene->DestructObject(layer3, field_4C);
        field_4C = 0;
    }
    if (field_58 != 0) {
        scene->DestructObject(layer4, field_58);
        field_58 = 0;
    }
    if (field_50 != 0) {
        scene->DestructObject(layer5, field_50);
        field_50 = 0;
    }
    if (field_54 != 0) {
        scene->DestructObject(layer4, field_54);
        field_54 = 0;
    }
    for (int i = 0; i < 5; i++) {
        if (field_24[i] != 0) {
            scene->DestructObject(layer1, field_24[i]);
            field_24[i] = 0;
        }
        if (field_38[i] != 0) {
            scene->DestructObject(layer2, field_38[i]);
            field_38[i] = 0;
        }
    }
}

// 0x0031CF00
void CB3BackgroundComponent::Release()
{
    CB3MenuComponentBase::Release();
    ReleaseObjects();
}
