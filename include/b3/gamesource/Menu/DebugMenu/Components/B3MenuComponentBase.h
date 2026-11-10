#ifndef B3_B3MENUCOMPONENTBASE_H
#define B3_B3MENUCOMPONENTBASE_H

#include "b3/_unclassified/B3Strings.h"

// [C] folder: literal alienbrain path GameSource\Menu\DebugMenu\Components\B4DebugMenuComponentBase.cpp
// (research/R_jul14/symtab.csv, N35) -- Revenge keeps the same class renamed
// CB4DebugMenuComponentBase.
class CB3MenuComponentBase {
    friend class CB3MenuPageManager;  // [C] AddComponent() (Target #24) reads/writes field_4/field_8 directly

public:
    // [C] virtual, slots 0 and 1: every component's vtable (0x4DE3D0-0x4DE4xx) is {0, 0, Update, Release}, and
    // CB3PromptsComponent::SetCurrentPrompts calls Release() through slot 1 (0xC). Declaring them puts the vptr at
    // offset 0, where the former pad0[0x4] blanket was (MWCC: vptr first, members from +4 -- tested).
    // [L] Update pure: no CB3MenuComponentBase::Update in any map.
    virtual void Update(float) = 0;
    virtual void Release();         // 0x00319390 [C]: decompiled and objdiff-verified (Target #21)
    void Construct(int);  // 0x003193B0 [C]: decompiled and objdiff-verified (Target #21)
    bool Prepare();         // 0x003193A0 [C]: decompiled and objdiff-verified (Target #21)

protected:
    CB3MenuComponentBase *field_4;  // [C] carved out of the former pad0[0xA] blanket (Target #24): next
                                     // pointer for CB3MenuPageManager's intrusive singly-linked list
    short field_8;  // [C] carved out of the former pad0[0xA] blanket (Target #22): read by
                    // CB3VListComponent::Release() and passed as DestructObject's int "layer" param

    // (protected, not private: func_0031A840 tests field_A through a CB3HeadingComponent)
    bool field_A;   // [L] Prepare sets true, Release/Construct set false
    bool field_B;   // [L] Prepare/Construct set false
};

// [C] class names: E-build maps (B3MenuComponentBase.cpp holds SelectNext/SelectPrev and SetData). Layout from
// retail code: SelectNext (0x319330) increments field_0 while it stays below field_2, SelectPrev (0x319360)
// decrements it down to 0.
class CB3MenuComponentSelectionData;

// Placeholders with C linkage (132 asm call sites use these labels). [L] identity: retail_names.csv
// CB3MenuComponentSelectionData::SelectNext() / SelectPrev() ("low": E-map order + similarity), and the bodies fit
// (step the current item up while below the count / down while above 0; return whether it moved).
extern "C" bool func_00319330(CB3MenuComponentSelectionData *self);
extern "C" bool func_00319360(CB3MenuComponentSelectionData *self);

class CB3MenuComponentSelectionData {
public:
    unsigned short field_0;  // [C] current item (B3O0PCH: GetCurrentItem)
    unsigned short field_2;  // [C] item count (B3O0PCH: GetNumItems)
};

class CB3ScrollingTextData {
public:
    void SetData(const unsigned short *text);  // 0x003192F0 [C]: stores text in field_0
    void SetData(EGlobalStrings id);           // 0x00319300 [C]: stores the string for `id`
    const unsigned short *field_0;             // [C] the text
};

#endif
