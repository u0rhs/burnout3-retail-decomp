#ifndef B3_B3MYBURNOUTPAGE_H
#define B3_B3MYBURNOUTPAGE_H

#include "b3/gamesource/Menu/DebugMenu/Pages/B3MenuPageBase.h"
#include "b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase.h"

class CB3MyBurnoutPage;

// Placeholder with C linkage: retail-only, not yet decompiled (0x1D4). Called by Update with the new current item
// [C] -- [L] re-prepares the page for it (E has PrepareStats(), no argument).
extern "C" void func_00321870(CB3MyBurnoutPage *self, int item);

// [C] class and method names: E-build maps (B3MyBurnoutPage.cpp: PrepareStats, Release, Update, Prepare, Construct) and
// retail's vtable __vt__16CB3MyBurnoutPage. [L] base: CB3MenuPageBase (vtable shape). [L] folder: as B3MenuPageBase.h.
class CB3MyBurnoutPage : public CB3MenuPageBase {
public:
    void Update();     // 0x00322320 [C]; draft (N112b)
    void Release();    // 0x00322310 [C]: empty
    void Construct();  // 0x00322610 [C]

private:
    // [C] Construct() zeroes it; Update() sets it to the current item. [L] it may belong to CB3MenuPageBase (only the
    // vptr there is evidenced).
    int field_4;
    unsigned char pad_8[0x804];
    CB3MenuComponentSelectionData field_80C;  // [C] Update() steps it with func_00319330/func_00319360
};

#endif
