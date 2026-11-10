#ifndef B3_B3PROMPTSCOMPONENT_H
#define B3_B3PROMPTSCOMPONENT_H

#include "b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

class CB3PromptsComponent;

// Not in retail's name tables, so a placeholder with C linkage; `self` is the component. [L] identity: the E-build
// maps' CB3PromptsComponent::Prepare(unsigned int, unsigned int) -- same (this, uint, uint) arguments, and the
// same place in the file's function order (after Release and Update, before the prompt creators).
extern "C" void func_0031ECD0(CB3PromptsComponent *self, unsigned long a, unsigned int b);  // w64: a is 64-bit [C retail 0x31ED08 sd a1 unconverted]
// w64 (2026-11-02): SetCurrentPrompts is defined by its link name so its first argument can be 64-bit: retail hands a1 to
// func_0031ECD0 unconverted [C 0x31E158/0x31E17C], and callers pass 64-bit flags (CB3MessageBoxComponent::Release: ld)
// [C]; the C++ declaration below keeps the mangled (unsigned int, unsigned int) for member-call callers.
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(CB3PromptsComponent *self, unsigned long a, unsigned int b);
// Placeholder with C linkage: retail-only (E has no 0x174-byte CB3PromptsComponent function with these arguments:
// its CreateTalkPrompt takes one bool, this takes a string id and a bool [C]). Prepares the field_94 text / field_98
// button pair at a fixed spot (x 320, or 386.75 when b; y 504, or 447.5 in menu state 5).
extern "C" void func_0031F5E0(CB3PromptsComponent *self, int id, bool b);
// Placeholder with C linkage: retail-only, no arguments [C]. Prepares prompt slot 3 (field_1C[3] text, string 0xC0F;
// field_48[3] button 3) at D_004C5360 -- the same layout as func_0031FB10's for button 3 [L]. Draft (N105).
// Placeholder with C linkage: retail-only [C] (bool argument). Prepares prompt slot 1 of the second pair (field_74[1]
// text, string 0x84; field_84[1] button 5) at D_004C5358 (text to the right) or D_004C5340 (text to the left).
extern "C" void func_0031F760(CB3PromptsComponent *self, bool b);
extern "C" void func_0031F970(CB3PromptsComponent *self);
// Placeholder with C linkage. [L] identity: the E map's CB3PromptsComponent::CreatePrompt(CB3Button2dObject::EButton,
// EGlobalStrings) (retail_names.csv "low": order + similarity), grown by a float x handle (negative: the button's
// default from D_004C52E0). Draft (N105).
extern "C" void func_0031FB10(CB3PromptsComponent *self, int button, int str, float handle);

// [C] class and method names: E-build maps (B3PromptsComponent.cpp, research/E_classified.csv) and retail's own
// tables (research/retail_names.csv). [L] folder: same Menu/DebugMenu/Components/ area as the other components
// (CB3MenuComponentBase-derived); no literal alienbrain path of its own. Vtable (__vt__19CB3PromptsComponent,
// 0x4DE440: Update__19CB3PromptsComponentFf, Release) stays in asm.
class CB3PromptsComponent : public CB3MenuComponentBase {
    friend void func_0031F5E0(CB3PromptsComponent *self, int id, bool b);
    friend void func_0031F760(CB3PromptsComponent *self, bool b);
    friend void func_0031F970(CB3PromptsComponent *self);
    friend void func_0031FB10(CB3PromptsComponent *self, int button, int str, float handle);
    friend void SetCurrentPrompts__19CB3PromptsComponentFUiUi(CB3PromptsComponent *self, unsigned long a, unsigned int b);

public:
    void SetCurrentPrompts(unsigned int a, unsigned int b);  // 0x0031E140 [C]
    void Release();                                          // 0x0031E1A0 [C]; draft 83/85 (N103)
    void Construct();                                        // 0x0031FD30 [C]

private:
    unsigned char pad_C[0xC];
    unsigned int field_18;  // [C] func_0031F5E0 passes it to Prepare__15CB3DPad2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi (bit-tested there: 1, 2, 4, 8)
    // [C] all destroyed by Release() through CGt2dScene::DestructObject() at layer field_8; all but field_9C
    // zeroed by Construct(). Release() null-checks field_1C[i] and field_74[i] but not their partners
    // field_48[i]/field_84[i] [L: each pair is one prompt's two objects, e.g. button image and text].
    CGt2dObject *field_1C[11];
    CGt2dObject *field_48[11];
    CGt2dObject *field_74[4];
    CGt2dObject *field_84[4];
    CGt2dObject *field_94;
    CGt2dObject *field_98;
    CGt2dObject *field_9C;
};

#endif
