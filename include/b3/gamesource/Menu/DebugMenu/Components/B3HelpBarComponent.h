#ifndef B3_B3HELPBARCOMPONENT_H
#define B3_B3HELPBARCOMPONENT_H

#include "b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"

class CB3HelpBarComponent;

// [L] CB3HelpBarComponent methods missing from the E-build maps (retail-only, between functions the DNAT map lists
// in B3HelpBarComponent.cpp), so placeholder names with C linkage; `self` is the component (a0). Class: their
// callers pass D_01E89788, the instance other call sites pass to CB3HelpBarComponent::Prepare/AwardPrepare, and
// they use this class's fields.
extern "C" void func_0031B640(CB3HelpBarComponent *self);            // side-prompt slide bounds
extern "C" void func_0031BD60(CB3HelpBarComponent *self, int unused, bool right);  // show one side prompt
extern "C" bool func_0031BF40(CB3HelpBarComponent *self, const unsigned short *left,
                              const unsigned short *right);            // two-prompt Prepare

// [C] class and method names: E-build maps (B3HelpBarComponent.cpp). The help bar's text object (field_14).
class CB3ScrollingText2dObject : public CGt2dObject {
public:
    // [C] name: _BuildBatchData's mangled parameter list. The object's data block (Prepare passes its size, 0x10).
    struct CGt2dObjectScrollingTextRenderData {
        const unsigned short *field_0;  // [C] the text
        float field_4;                  // [C] scroll offset: Prepare's start value, CB3HelpBarComponent::Update adds dt
        float field_8;                  // [C] Prepare: extent = `extra` + string width * the bar height
        float field_C;                  // [C] Prepare: `extra` (its float argument)
    };

    // 0x0031C5D0, not yet decompiled: fills mgu8RenderBatchData from `*text` at `*cursor`, advancing both; returns
    // the vertex count (v0).
    static int _BuildBatchData(const GtMathPs2::CGtV2d &scale, GtMathPs2::CGtV2d *cursor, const unsigned short **text,
                               const CGt2dObject::CGt2dObjectSpace &space,
                               const CGt2dObjectScrollingTextRenderData &data);
    static void _Render(const CGt2dObject::CGt2dObjectSpace &, const void *);  // 0x0031C990
    // 0x0031CB20. [L] parameter meanings: scroll (sets the start offset), centred (start half a string in),
    // extra (added to the extent).
    void Prepare(const unsigned short *text, bool scroll, bool centred, float extra);
};

// [C] class and method names: E-build maps (B3HelpBarComponent.cpp). [L] folder: same Menu/DebugMenu/Components/
// area as CB3HSelectComponent/CB3HeadingComponent (Construct() calls CB3MenuComponentBase::Construct(1)); no
// literal alienbrain path of its own found yet.
class CB3HelpBarComponent : public CB3MenuComponentBase {
    friend void func_0031B640(CB3HelpBarComponent *self);
    friend void func_0031BD60(CB3HelpBarComponent *self, int unused, bool right);
    friend bool func_0031BF40(CB3HelpBarComponent *self, const unsigned short *left, const unsigned short *right);

public:
    void Construct();                  // 0x0031C590 [C]: decompiled and wire-in verified (Target #41)
    void Release();                    // 0x0031B6A0 [C]: decompiled and wire-in verified (Target #40)
    // 0x0031B860 [C] identity: vtable slot 0 (0x4DE418), the slot every sibling component's Update(float) has.
    void Update(float dt);         // draft, not wired in (N95)
    void SetString(const unsigned short *text, bool, bool, float);   // 0x0031B770 [C]: wire-in verified (Target #42)
    bool AwardPrepare(const unsigned short *text);                   // 0x0031C210 [C]: wire-in verified (Target #43)
    bool Prepare(const CB3MenuComponentSelectionData *selection, const CB3ScrollingTextData *texts, bool,
                 float);                                             // 0x0031C350 [C]: wire-in verified (Target #44)
    bool Prepare();                                                  // 0x0031C470 [C]: wire-in verified (Target #45)
    bool Prepare(const unsigned short *text, bool, float);           // 0x0031C520 [C]: wire-in verified (Target #46)

private:
    // [C] layout from Release() (0x31B6A0) and Construct(): four CGt2dObject* torn down by
    // CGt2dScene::DestructObject(field_8, ...) in the order 14, 18, 20, 1C, then the frame at +0x24.
    // Prepare(selection, texts, ...) stores its first two arguments here; AwardPrepare/func_0031BF40 zero them.
    const CB3MenuComponentSelectionData *field_C;
    const CB3ScrollingTextData *field_10;   // [C] indexed by the current item (Update: field_10[field_6D])
    CGt2dObject *field_14;     // [C] the main text: a CB3ScrollingText2dObject (SetString, Prepare); left prompt
                               //     text in func_0031BF40
    CGt2dObject *field_18[2];  // [C] per side (0 left, 1 right): the prompt object func_0031BD60 prepares
    CGt2dObject *field_20;     // [C] right prompt text (func_0031BF40)
    CGt2dFrame *field_24;      // [C] Release(): Destruct()ed after clearing the layer's clip-frame slot
    GtMathPs2::CGtV2d field_28[2];  // [C] per side: field_18[i]'s size as prepared (func_0031BD60)
    GtMathPs2::CGtV2d field_38[2];  // [C] per side: field_18[i]'s position as prepared (func_0031BD60)
    const unsigned short *field_48[2];  // [C] per side: prompt strings (func_0031BF40 allocates both)
    float field_50;            // [C] last argument of SetString/Prepare, passed on to the text's Prepare
    float field_54[2];         // [C] per side: D_004F50A0 when the prompt was shown (a timestamp [L])
    // [C] written by func_0031B640 from the objects' x positions and widths (slide bounds [L]: Update clamps to them)
    float field_5C;
    float field_60;
    float field_64;
    float field_68;
    unsigned char field_6C;    // [C] func_0031B640 sets 1; Update clears it once both clamps are reached
    signed char field_6D;      // [C] the current item last shown (-1: none; lb)
    signed char field_6E;      // [C] mode: 0 text, 1 one prompt, 2 two prompts, 3 award (lb)
    unsigned char field_6F[2]; // [C] per side: prompt animating (lbu)
};

#endif
