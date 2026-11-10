#ifndef B3_B3VSELECTCOMPONENT_H
#define B3_B3VSELECTCOMPONENT_H

#include "b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"

class CB3VSelectComponent;

// [C] class name: the mangled Prepare names. Layout from retail code: 8-byte entries (SetItemEnabled scales the
// index by 8) with a flag at +4 that SetItemEnabled sets to !enabled.
class CB3VSelectComponentEntryData {
public:
    const unsigned short *field_0;  // [C] the item's text (func_00320EB0 measures and prepares it)
    bool field_4;  // [C] SetItemEnabled stores !enabled ([L] "disabled")
    unsigned char pad5[0x3];
};

// Not in retail's name tables, so a placeholder with C linkage; `self` is the component. [L] identity: the
// E-build maps' CB3VSelectComponent::PrepareItem(int, float, bool) -- every call passes (this, int, float, bool),
// and it sits where the E map puts PrepareItem (after Update, before the Prepare overloads).
extern "C" void func_00320EB0(CB3VSelectComponent *self, int item, float x, bool selected);
// Placeholder with C linkage: retail-only [C] (no E function of this shape; callers at 0x3160BC, 0x316464, 0x45AD90).
// Prepares the field_60 rounded panel (constructed on first use in the field_A8 frame) from three vectors.
extern "C" void func_00320E20(CB3VSelectComponent *self, const GtMathPs2::CGtV2d &a, const GtMathPs2::CGtV2d &b,
                              const GtMathPs2::CGtV2d &c);

// [C] class and method names: E-build maps (B3VSelectComponent.cpp, research/E_classified.csv) and retail's own
// tables. [L] folder: same Menu/DebugMenu/Components/ area as the other components (Construct() calls
// CB3MenuComponentBase::Construct(4)); no literal alienbrain path of its own. Vtable (__vt__19CB3VSelectComponent,
// 0x4DE450: Update, Release) stays in asm.
//
// The three Prepare overloads have one more float each than in the E build, and the main one one more bool (N104):
// E's own wrappers (DNAT_200.45, 0x2D20C0/0x2D20F0) pass (false, 84, f | 240, 30, 40, sel, entry), retail's the same
// plus their new float as main's 5th float (f16) and false as its 5th GPR argument (t0). [C] counts and types by
// register use (main stores the float to field_C0, the bool as a byte to field_D4); [G] the new parameters'
// positions (appended after their kind's existing ones), which only the mangled names would show. Our symbol
// names therefore can't be retail's real ones: tools/compile_vselectcomponent_00321430.sh renames them to the
// table's (E-signature) labels the rest of the build uses.
class CB3VSelectComponent : public CB3MenuComponentBase {
    friend void func_00320EB0(CB3VSelectComponent *self, int item, float x, bool selected);
    friend void func_00320E20(CB3VSelectComponent *self, const GtMathPs2::CGtV2d &a, const GtMathPs2::CGtV2d &b,
                              const GtMathPs2::CGtV2d &c);

public:
    void ForceLead(bool a, bool b);           // 0x0031FDB0 [C]
    void SetItemEnabled(int item, bool enabled);  // 0x0031FE40 [C]
    void Release();                           // 0x0031FE70 [C]
    void Update(float);                       // 0x0031FF80, not yet decompiled (0xE98)
    void Construct();                         // 0x003214B0 [C]
    // [L] an inline (name unknown): an item's row y. As an inline its loads aren't shared with the caller -- retail's
    // func_00320EB0 reads field_B0 again for the item size (N116); written in line, ours reuses it.
    float UnkInline_ItemY(int item) const { return field_B8 + (float)item * (field_B0 + 2.0f); }
    // 0x003210D0, not yet decompiled (0x354). [L] returns bool (v0 = 1 at the end, as the other components' Prepare).
    bool Prepare(bool b, float x, float f1, float f2, float f3, float f4, const CB3MenuComponentSelectionData *sel,
                 CB3VSelectComponentEntryData *entry, bool b2);
    bool Prepare(float f, float f4, const CB3MenuComponentSelectionData *sel,
                 CB3VSelectComponentEntryData *entry);  // 0x00321430 [C]
    bool Prepare(float f4, const CB3MenuComponentSelectionData *sel,
                 CB3VSelectComponentEntryData *entry);  // 0x00321470 [C]

private:
    const CB3MenuComponentSelectionData *field_C;  // [C] Prepare's selection argument
    CB3VSelectComponentEntryData *field_10;         // [C] Prepare's entry-data argument
    // [C] zeroed by Construct(); Release() destroys them through CGt2dScene::DestructObject() at layer field_8 + 2
    // (field_14[i]) and + 3 (field_38[i]), stopping at the first null field_14[i].
    CGt2dObject *field_14[9];
    CGt2dObject *field_38[9];
    CGt2dObject *field_5C;  // [C] Release(): destroyed unconditionally, layer field_8 + 1
    CGt2dObject *field_60;  // [C] Release(): destroyed if set, layer field_8; func_00320E20's rounded panel
    unsigned short field_64[0x20];  // [C] func_00320EB0 copies a string into it (func_003D0960, max 0x20)
    int field_A4;     // [C] SetItemEnabled passes (field_A4 == item) on to func_00320EB0 [L: the current item]
    CGt2dFrame *field_A8;  // [C] Release(): Destruct()ed, then cleared (no null check)
    float field_AC;   // [C] ForceLead passes it to func_00320EB0 for every item
    float field_B0;   // [C] func_00320EB0: the item text size (and the row step, + 2)
    float field_B4;   // [C] func_00320EB0: the selected item's text size
    float field_B8;   // [C] func_00320EB0: the first row's y
    float field_BC;   // [C] Prepare's first float; SetItemEnabled passes it to func_00320EB0
    float field_C0;   // [C] main Prepare's 5th float; func_00320EB0's maximum text width
    float field_C4;   // [C] Construct sets -1.0f; ForceLead clamps it to >= 0
    int field_C8;     // [C] func_00320EB0 clears it when preparing the selected item
    unsigned char pad_CC[0x6];
    bool field_D2;    // [C] ForceLead's first argument; when false, every item is re-prepared
    bool field_D3;    // [C] ForceLead's second argument
    bool field_D4;    // [C] main Prepare's last argument
};

#endif
