// CB3PromptsComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PromptsComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3PromptsComponent has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].
// Hand-finished from the lifted source (parkfix: tool-bug park fixed (N213)).

// CB3PromptsComponent::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PromptsComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// CB3PromptsComponent has a header in include/ (pads and a few proven fields only): declared locally instead, as the
// hand-matched units of such classes do (B3AITarget_00149140.cpp) [lift3].
// Hand-finished from the lifted source (a260: second destroy nested inside the first if (field_48/84/98 inside the guard)).

// DRAFT -- NOT MATCHING, NOT WIRED IN (retail's asm is still linked: game/unit_0031E1A0.s). 83/85 instructions,
// registers and frame right; the unconditional destroys load their object before setting a0 (retail: after), and
// both loops' branch delay slots get the final store (retail: nop) -- docs/known.md N103.
#include "b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

extern CGt2dScene D_01E903E0;  // unnamed global, no evidence of its real name yet

// 0x0031E1A0
void CB3PromptsComponent::Release()
{
    CGt2dScene *scene = &D_01E903E0;
    int layer = field_8;
    CB3MenuComponentBase::Release();
    for (unsigned long i = 0; i < 11; i++) {
        if (field_1C[i] != 0) {
            scene->DestructObject(layer, field_1C[i]);
            field_1C[i] = 0;
            CGt2dObject *&p = field_48[i];
            scene->DestructObject(layer, p);
            p = 0;
        }
    }
    for (unsigned long i = 0; i < 4; i++) {
        if (field_74[i] != 0) {
            scene->DestructObject(layer, field_74[i]);
            field_74[i] = 0;
            CGt2dObject *&p = field_84[i];
            scene->DestructObject(layer, p);
            p = 0;
        }
    }
    if (field_94 != 0) {
        scene->DestructObject(layer, field_94);
        field_94 = 0;
        scene->DestructObject(layer, field_98);
        field_98 = 0;
    }
    if (field_9C != 0) {
        scene->DestructObject(layer, field_9C);
        field_9C = 0;
    }
}
