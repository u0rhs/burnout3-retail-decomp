// NONMATCHING: Construct__15CB3HUDComponentFv -- retail 84 / ours 82 instructions, 21 in changed runs
// 84/82, 21 changed: logic right (ods colour/outline copied into maOutlineDropShadow[3], drop offsets 3/4/2.2, texture arrays cleared). Left: retail keeps the dead swc1 1.2 stores to the stack ods (sp+0x28/2C) and one lui per element-field store; opt_dead_assignments off grows the frame. Same open shape as N108b.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectText.h"

using namespace GtMathPs2;

class CB3HUDComponent {
public:
    static void Construct();
    static CGt2dObjectText::COutlineDropShadow maOutlineDropShadow[3];
    static void *mapBoostFireCoreTextures[30];
    static void *mapBoostFireEdgeTextures[41];
    static void *mapBoostFireOverTextures[20];
    static void *mapIconTextures[17];
    static void *mpBoostBitsTexture;
    static void *mpBoostBlueFlameTexture;
    static void *mpHUDTexture;
    static void *mpBoostFlareTexture;
    static void *mpHealthBarTexture;
};

// 0x0019FCF0
void CB3HUDComponent::Construct()
{
    CGt2dObjectText::COutlineDropShadow ods;
    ods.mDropShadowColour = CGtV4d(0.0f, 0.0f, 0.0f, 0.25f);
    ods.mOutlineOffset.marValues[0] = 1.2f;
    ods.mOutlineOffset.marValues[1] = 1.2f;
    for (int k = 0; k < 3; k++) {
        maOutlineDropShadow[k].mDropShadowColour = ods.mDropShadowColour;
        maOutlineDropShadow[k].mOutlineOffset.marValues[0] = ods.mOutlineOffset.marValues[0];
        maOutlineDropShadow[k].mOutlineOffset.marValues[1] = ods.mOutlineOffset.marValues[1];
    }
    maOutlineDropShadow[1].mDropShadowOffset.marValues[0] = 3.0f;
    maOutlineDropShadow[1].mDropShadowOffset.marValues[1] = 3.0f;
    maOutlineDropShadow[2].mDropShadowOffset.marValues[0] = 4.0f;
    maOutlineDropShadow[2].mDropShadowOffset.marValues[1] = 4.0f;
    maOutlineDropShadow[0].mDropShadowOffset.marValues[1] = 2.2f;
    maOutlineDropShadow[0].mDropShadowOffset.marValues[0] = 2.2f;
    int i;
    for (i = 0; i < 30; i++) mapBoostFireCoreTextures[i] = 0;
    for (i = 0; i < 41; i++) mapBoostFireEdgeTextures[i] = 0;
    for (i = 0; i < 20; i++) mapBoostFireOverTextures[i] = 0;
    mpBoostBitsTexture = 0;
    mpBoostBlueFlameTexture = 0;
    for (i = 0; i < 17; i++) mapIconTextures[i] = 0;
    mpHUDTexture = 0;
    mpBoostFlareTexture = 0;
    mpHealthBarTexture = 0;
}
