#ifndef B3_B3MENUPAGEMANAGER_H
#define B3_B3MENUPAGEMANAGER_H

#include "b3/GtMathPs2.h"
#include "b3/B3Ptr.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

class CB3MenuComponentBase;
class CB3MenuPageBase;

// [C] type name: the mangled names of CB3MenuPageManager::StartLeadOut*/CB3MenuFlowFSM methods; enumerators unknown.
enum EB3MenuFlowFSMEvents {};

// [L] folder: Menu/DebugMenu/, same area as CB3MenuComponentBase (N35/N49); no literal path of
// its own found yet. Instance: D_01E90240 [C] (CB3MenuComponentBase::Construct calls AddComponent on it).
//
// The 0x0-0x177 layout this header used to carry came from Prepare__14CB3MenuChoicesFv, which initializes a
// different object (D_01E900B0) -- retracted, see docs/known.md N62.
class CB3MenuPageManager {
public:
    void AddComponent(CB3MenuComponentBase *component, int type);  // 0x0030D6B0 [C]: decompiled and
                                                                     // objdiff-verified (Target #24)
    // 0x0030D5C0, not yet decompiled. [C] name/signature: E maps and retail's tables (high).
    void SetMenuPage(CB3MenuPageBase *page, bool b);
    // 0x0030D500, not yet decompiled. [C] name/signature: E maps (StartLeadOutFore(EB3MenuFlowFSMEvents, bool)).
    void StartLeadOutFore(EB3MenuFlowFSMEvents e, bool b);
    // 0x0030D560, not yet decompiled. [C] name: E maps, whose signature is (EB3MenuFlowFSMEvents) only; retail's stores
    // a second argument (sb a2, 0x19FF(a0)) and its callers pass false, as for StartLeadOutBack/Fore [C]. Declared with
    // the bool; aliased to the table label in config/undefined_syms_manual.txt (N112).
    void StartLeadOut(EB3MenuFlowFSMEvents e, bool b);

    // [C] 16-byte values passed by address as the 4th/5th arguments of func_003824D0 (a text object's
    // Prepare) by CB3HeadingComponent::Prepare (Target #31) and Update; meaning not known (two
    // colours? [G]).
    // [C] three colours, indexed by an item's state (func_00320EB0: 0 normal, 1 selected, 2 disabled).
    GtMathPs2::CGtV4d field_0[3];
    // [C] the colour CB3ScrollingText2dObject::Prepare (0x31CB20) passes to CGt2dObject::Prepare (&D_01E90240 + 0x30).
    GtMathPs2::CGtV4d field_30;
    GtMathPs2::CGtV4d field_40;
    GtMathPs2::CGtV4d field_50;
    unsigned char pad1[0xD0 - 0x60];  // [L] layout unknown
    // [C] the colour func_0031F5E0 (CB3PromptsComponent) passes to CGt2dObjectText::Prepare (&D_01E90240 + 0xD0).
    GtMathPs2::CGtV4d field_D0;
    unsigned char pad1b[0x100 - 0xE0];  // [L] layout unknown
    // [C] multiplied into the heading bar's fill colour by CHeadingBar2dObject::_Render (0x31B130).
    GtMathPs2::CGtV4d field_100;
    // [C] a 16-byte value CB3HeadingComponent::Prepare(EHeadingType) (Target #33) passes as the CGtV4d
    // (colour [L]) argument of every 2D object it prepares (lq 0x110(&D_01E90240) / &D_01E90350).
    GtMathPs2::CGtV4d field_110;
    // [C] CHeadingBar2dObject::_Render's two Gouraud strip colours (x the object's colour): field_120 the
    // middle pair of vertices, field_130 the outer four.
    GtMathPs2::CGtV4d field_120;
    GtMathPs2::CGtV4d field_130;
    unsigned char pad2[0x1A0 - 0x140];  // [L] layout unknown
    // [L] the menu's CGt2dScene, embedded here: D_01E903E0 (the scene every component destroys and
    // constructs its 2D objects in) is exactly D_01E90240 + 0x1A0, and 0x1A0 + sizeof(CGt2dScene)
    // (0x34) lands exactly on field_1D4. Taking its address as a member (not as the bare D_01E903E0
    // global) is also what reproduces retail's register caching in CB3HeadingComponent::Prepare (N63).
    CGt2dScene field_1A0;

private:
    // The class stays padded well past CodeWarrior's small-data threshold so an extern reference to
    // D_01E90240 compiles to the 2-instruction absolute lui/addiu form retail uses (N51) -- confirmed
    // by disassembly, the object sits outside the $gp window.
    int field_1D4;                     // [C] bumped by `type` on each AddComponent() call -- looks
                                        // like an accumulating offset/count, e.g. a layout cursor
    CB3MenuComponentBase *field_1D8;   // [C] head of an intrusive singly-linked list of components,
                                        // linked via CB3MenuComponentBase::field_4
    unsigned char pad3[0x100];

    friend struct B3MenuPageManagerLayoutCheck;
};

struct B3MenuPageManagerLayoutCheck {
    B3_CHECK_OFFSET(CB3MenuPageManager, field_40, 0x40);
    B3_CHECK_OFFSET(CB3MenuPageManager, field_D0, 0xD0);
    B3_CHECK_OFFSET(CB3MenuPageManager, field_100, 0x100);
    B3_CHECK_OFFSET(CB3MenuPageManager, field_110, 0x110);
    B3_CHECK_OFFSET(CB3MenuPageManager, field_130, 0x130);
    B3_CHECK_OFFSET(CB3MenuPageManager, field_1A0, 0x1A0);
    B3_CHECK_OFFSET(CB3MenuPageManager, field_1D4, 0x1D4);
    B3_CHECK_OFFSET(CB3MenuPageManager, field_1D8, 0x1D8);
};

#endif
