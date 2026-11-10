#ifndef B3_B3LOADINGSCREENPAGE_H
#define B3_B3LOADINGSCREENPAGE_H

#include "b3/gamesource/Menu/DebugMenu/Pages/B3MenuPageBase.h"

class CB3LoadingScreenPage;

// Placeholder with C linkage (0x174). [L] identity: E's CB3LoadingScreenPage::Prepare() -- the
// file's third function (E order Release, Update, Prepare; retail puts it first) and called by Update with `this`.
extern "C" void func_00321500(CB3LoadingScreenPage *self);

// [C] class and method names: E-build maps (B3LoadingScreenPage.cpp) and retail's vtable __vt__20CB3LoadingScreenPage.
// [L] base: CB3MenuPageBase (vtable shape). [L] folder: as B3MenuPageBase.h.
class CB3LoadingScreenPage : public CB3MenuPageBase {
public:
    void Update();   // 0x00321690 [C]; draft (N112b)
    void Release();  // 0x00321680 [C]: empty
};

#endif
