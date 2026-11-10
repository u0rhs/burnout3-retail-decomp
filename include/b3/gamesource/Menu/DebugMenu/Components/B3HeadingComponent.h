#ifndef B3_B3HEADINGCOMPONENT_H
#define B3_B3HEADINGCOMPONENT_H

#include "b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"
#include "b3/_unclassified/B3Strings.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

extern CB3MenuPageManager D_01E90240;  // unnamed global (the page manager instance)

class CB3HeadingComponent;

// Unnamed in retail and in every table in research/ (none is in the E maps' B3HeadingComponent.cpp
// function list, which retail's four don't fit either), so placeholder names with C linkage; `self`
// is the component (a0). Friends below, since they use its fields. [C] register layouts; [L] members.
extern "C" void func_0031A5D0(CB3HeadingComponent *self, int mode);           // award heading text
extern "C" void func_0031A840(CB3HeadingComponent *self, int type, int id);   // change type 3 -> 0-3
extern "C" void func_0031A9C0(CB3HeadingComponent *self, int type);            // change type 13 -> 10-12
extern "C" int func_0031ABC0(CB3HeadingComponent *self);                     // heading id for the page

// [C] class and method names: E-build maps (B3HeadingComponent.cpp; B3O0PCH lists Prepare out of line,
// inlined in retail). Body reconstructed from retail's inlined copies [L]: an 8-byte data block at +0x20
// (texture, then +0x24 probably the angle: SetAngle(float) exists [G]); position = pos - size * anchor as
// in CGt2dObjectBox/Image. E map signature: (const CGtV2d&, const CGtV2d&, const CGtV2d&, CGtV4d, ...),
// truncated there; the texture is the one more argument these calls need. Stores in retail's order.
class CB3RotatingImage2dObject : public CGt2dObject {
public:
    static void _Render(const CGt2dObject::CGt2dObjectSpace &, const void *);  // 0x31A300
    void Prepare(const GtMathPs2::CGtV2d &pos, const GtMathPs2::CGtV2d &anchor, const GtMathPs2::CGtV2d &size,
                 GtMathPs2::CGtV4d colour, CGtTexture *texture)
    {
        *(float *)&mauDataBlock[1] = 0.0f;
        *(CGtTexture **)mauDataBlock = texture;
        CGt2dObject::Prepare(pos - size * anchor, size, colour, _Render, 0x40, 8);
    }
};

// [C] class and method names: E-build maps (B3HeadingComponent.cpp; B3O0PCH lists Prepare
// out of line). Inlined in retail, so the body is reconstructed from Prepare(EHeadingType)'s code
// [L]: an 8-byte data block at +0x20 (the last CGt2dObject::Prepare argument is its size, as for
// CGt2dObjectImage's 0x18), position = pos - size * anchor as in CGt2dObjectBox/Image.
class CHeadingBar2dObject : public CGt2dObject {
public:
    static void _Render(const CGt2dObject::CGt2dObjectSpace &, const void *);  // 0x31B130
    // The E map's two references are taken as (pos, anchor) and the 640x128 size as a local: with size as
    // a parameter instead, the temporaries land in different stack slots and 640 isn't kept in $a3.
    void Prepare(const GtMathPs2::CGtV2d &pos, const GtMathPs2::CGtV2d &anchor)
    {
        GtMathPs2::CGtV2d size(640.0f, 128.0f);
        *(GtMathPs2::CGtV2d *)mauDataBlock = GtMathPs2::CGtV2d(1.0f, 1.0f) / size;  // reciprocal through a by-value temporary [C]
        CGt2dObject::Prepare(pos - size * anchor, size, D_01E90240.field_110, _Render, 0x40, 8);
    }
};

// [L] folder: same Menu/DebugMenu/Components/ area as CB3VListComponent/CB3HSelectComponent (its
// Construct() calls CB3MenuComponentBase::Construct(3)); no literal alienbrain path of its own found yet.
class CB3HeadingComponent : public CB3MenuComponentBase {
    friend void func_0031A5D0(CB3HeadingComponent *self, int mode);
    friend void func_0031A840(CB3HeadingComponent *self, int type, int id);
    friend void func_0031A9C0(CB3HeadingComponent *self, int type);
    friend int func_0031ABC0(CB3HeadingComponent *self);

public:
    // [C] type name from the mangled names; enumerators unknown. Stored in field_26 as a signed byte;
    // Prepare(EHeadingType) dispatches on it through a 15-entry jump table (values 0-14).
    enum EHeadingType {};

    void Construct();      // 0x0031B0F0 [C]: decompiled and wire-in verified (Target #29)
    void Release();        // 0x003193D0 [C]: decompiled and wire-in verified (Target #30)
    void Update(float);    // 0x00319490, not yet decompiled: 0x5F4 bytes, a 6-way jump-table state
                           // switch with FPU/VU0 math (see docs/progress.md)
    // 0x00319A90 [C]: decompiled and wire-in verified (Target #31). Returns bool [C] (v0 = 1 on exit).
    bool Prepare(const unsigned short *text, EHeadingType type);
    // 0x00319C80 [C] identity: E-build maps (research/E_dnat_symbols.csv) list this exact signature in
    // B3HeadingComponent.cpp, between the other two Prepares, as here. Decompiled and wire-in verified
    // (Target #32); returns bool [C] (v0 = 1).
    bool Prepare(EGlobalStrings id, EHeadingType type);
    // 0x00319E80 [C]: decompiled and wire-in verified (Target #33, N67); returns bool [C] (v0 = 1).
    bool Prepare(EHeadingType type);
    // [L] name: E-build B3O0PCH map. No out-of-line copy in retail: inlined twice into Update (defined
    // in B3HeadingComponent_00319490.cpp).
    void SetHeadingString(const unsigned short *text);

private:
    // [L] three CGt2dObject*-family sub-objects plus one CGt2dFrame*, all zeroed by Construct() and torn
    // down by Release() via CGt2dScene::DestructObject() at consecutive layer numbers (field_8,
    // field_8+1, field_8+2). field_18 is the clip frame of layer field_8+1: Prepare(text, type)
    // creates it as a child of the scene's root frame and installs it as that layer's clip frame,
    // and Release() clears that slot before destroying it.
    CGt2dObject *field_C;  // [C] layer field_8+1's object (a text object: func_003824D0 prepares it)
    CGt2dObject *field_10; // [C] layer field_8's object: a CHeadingBar2dObject (Prepare(EHeadingType))
    // [C] layer field_8+2's object, per type (Prepare(EHeadingType)): a CB3RotatingImage2dObject (0-2), a
    // CGt2dObjectImage (4, 6-9) or a text object (14). Its mTopLeftPos.x + mSize.x shrink the text width.
    CGt2dObject *field_14;
    CGt2dFrame *field_18;
    // [C] all initialized by Prepare(EHeadingType) (0x319E80): -1.0f, 0, 0xFA5, type, 0, 0.
    float field_1C;
    int field_20;
    short field_24;
    signed char field_26;  // [C] the EHeadingType (sb on store, lb on load)
    unsigned char field_27;
    unsigned char field_28;
};

#endif
