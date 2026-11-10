#ifndef B3_B3MENUPAGEBASE_H
#define B3_B3MENUPAGEBASE_H

// [C] class/file: E-build maps (B3MenuPageBase.cpp: Prepare(bool)) and retail's tables (0x318530, high); the page
// manager's SetMenuPage takes a CB3MenuPageBase*. [L] folder: Revenge keeps the same base as
// GameSource\Menu\DebugMenu\Pages\B4DebugMenuPageBase.cpp (research/R_jul14), as it keeps CB3MenuComponentBase as
// ...\DebugMenu\Components\B4DebugMenuComponentBase.cpp (N35).
class CB3MenuPageBase {
public:
    // [C] virtual, slots 0 and 1: every page vtable seen so far is {0, 0, Update, Release} (__vt__20CB3LoadingScreenPage
    // 0x4DE460, __vt__16CB3MyBurnoutPage 0x4DE470). [L] Update pure (no base Update in any map).
    virtual void Update() = 0;
    virtual void Release();
    bool Prepare(bool b);  // 0x00318530 [C]: SetMenuPage(this, b) on the page manager, returns true
};

#endif
