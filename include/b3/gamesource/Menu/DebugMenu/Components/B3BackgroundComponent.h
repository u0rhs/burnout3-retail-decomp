#ifndef B3_B3BACKGROUNDCOMPONENT_H
#define B3_B3BACKGROUNDCOMPONENT_H

#include "b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

class CB3BackgroundComponent;

// [C] type name and namespace scope: the mangled Prepare__22CB3BackgroundComponentF17EB3BackgroundType (not nested in the
// class); enumerators unknown.
enum EB3BackgroundType {};

// [C] a CB3BackgroundComponent member taking a float: all three callers (0x424580, 0x453F90, 0x461BF8) pass the
// background component instance D_01E88A80 in a0, two of them straight after its Prepare(EB3BackgroundType). Not in
// any name table (retail-only), so a placeholder with C linkage; `self` is the component. Stores the float in
// field_60.
extern "C" void func_0031D920(CB3BackgroundComponent *self, float f);

// [C] class and method names: E-build maps (B3BackgroundComponent.cpp, research/E_classified.csv) and retail's
// own tables (research/retail_names.csv, "direct+chain agree"). [L] folder: same Menu/DebugMenu/Components/
// area as CB3VListComponent/CB3HeadingComponent (Construct() calls CB3MenuComponentBase::Construct(6)); no
// literal alienbrain path of its own. Its vtable (__vt__22CB3BackgroundComponent, 0x4DE430: Update, Release)
// stays in asm, as for the other components.
class CB3BackgroundComponent : public CB3MenuComponentBase {
    friend void func_0031D920(CB3BackgroundComponent *self, float f);

public:
    void ReleaseObjects();               // 0x0031CDA0 [C]
    void Release();                      // 0x0031CF00 [C]
    void Update(float);                  // 0x0031CF30, not yet decompiled (0x410)
    void PrepareBorders(float);          // 0x0031D660 [C]; draft 175/175 (N115)
    void Prepare(EB3BackgroundType);     // 0x0031D930, not yet decompiled (0x79C); return type not yet known
    void Construct();                    // 0x0031E0D0 [C]

private:
    unsigned char pad_C[0x14];
    // [C] ReleaseObjects() destroys each through CGt2dScene::DestructObject() at a layer relative to field_8:
    // field_20 at +0, field_24[i] at +1, field_38[i] at +2, field_4C at +3, field_58 and field_54 at +4,
    // field_50 at +5. Construct() zeroes all of them.
    CGt2dObject *field_20;
    CGt2dObject *field_24[5];
    CGt2dObject *field_38[5];
    CGt2dObject *field_4C;
    CGt2dObject *field_50;
    CGt2dObject *field_54;
    CGt2dObject *field_58;
    unsigned char pad_5C[0x4];
    float field_60;   // [C] set by func_0031D920
    unsigned char pad_64[0x1];
    // [L] flags: ReleaseObjects() and Construct() both set field_65 false, field_66/field_67 true
    bool field_65;
    bool field_66;
    bool field_67;
};

#endif
