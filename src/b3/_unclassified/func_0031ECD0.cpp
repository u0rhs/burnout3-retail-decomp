// Hand-written; the lifter refused it (L276: CB3PromptsComponent Prepare-like flag dispatcher; [G] inline button-offset helper fixes sub.s operand order; local class like Update__19CB3PromptsComponentFf; jtbl).

#include "b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectText.h"
#include "b3/_unclassified/B3Strings.h"

using GtMathPs2::CGtV2d;

class CB3PromptsComponent;
extern "C" bool func_0031ECD0(CB3PromptsComponent *self, unsigned long flags, int b);

// Layout as in Update__19CB3PromptsComponentFf.cpp (local class: the shared header keeps these fields private).
class CB3PromptsComponent : public CB3MenuComponentBase {
    friend bool func_0031ECD0(CB3PromptsComponent *self, unsigned long flags, int b);
public:
    unsigned char pad_C[4];
    unsigned long field_10;
    int field_18;
    CGt2dObject *field_1C[11];
    CGt2dObject *field_48[11];
    CGt2dObject *field_74[4];
    CGt2dObject *field_84[4];
    CGt2dObject *field_94;
    CGt2dObject *field_98;
    CGt2dObject *field_9C;
    float field_A0;
    unsigned char field_A4;
    unsigned char pad_A5[3];
    unsigned char field_A8;
    unsigned char field_A9;
    unsigned char field_AA;
};

extern CB3MenuPageManager D_01E90240;
struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_D_0051BA44 {
    CB3Strings strings;
    unsigned char pad[0x100];
};
extern UnkStruct_D_0051BA44 D_0051BA44;
struct UnkStruct_D_01E90424 {
    int value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E90424 D_01E90424;
struct UnkStruct_D_01E90420 {
    float value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E90420 D_01E90420;
struct UnkStruct_D_gen { unsigned char pad_0[0x10]; };
extern UnkStruct_D_gen D_01E3D390;
extern float D_004E08B0;
extern float D_004E0A18;
extern const CGtV2d D_004C5348;
extern const CGtV2d D_004C5350;
extern "C" float func_00382BE0(int button);
// CB3Strings::GetString(int) and CGt2dObjectText::Prepare(..) under retail's labels (the asm calls these names);
// the by-value CGtV4d colour goes by address, as retail passes &D_01E90240 with no copy.
extern "C" const unsigned short *func_00271A00(void *strings, int id);
extern "C" void func_001D6C40(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, float size, const void *colour,
                              CGt2dFont *font, const unsigned short *text);
extern "C" void func_00382C00(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, int button);
extern "C" void func_0031FB10(CB3PromptsComponent *self, int button, int str, float handle);
extern "C" void func_0031F5E0(CB3PromptsComponent *self, int id, bool b);
extern "C" void func_0031F760(CB3PromptsComponent *self, bool b);
extern "C" void func_0031F970(CB3PromptsComponent *self);
extern "C" void func_0031E800(CB3PromptsComponent *self);
extern "C" int func_0035F660(void *);
extern "C" int func_0035F670(void *);
extern "C" int IsNewMailAvailable__22CGtBuddiesPS2DirtySockFv(void *);

// [G] placeholder inline: the button's half width plus a 5-unit gap. Retail computes it before loading the
// anchor x (an inline's result is evaluated ahead of the expression that uses it).
static inline float func_0031ECD0_inl1(int button)
{
    return 5.0f + 0.5f * func_00382BE0(button);
}

// 0x0031ECD0
// [L] identity: CB3PromptsComponent::Prepare(unsigned int, unsigned int) of the E maps (see B3PromptsComponent.h).
// Retail stores a1 with a plain `sd` to the 64-bit flag field (no zero-extension) and returns 1 in v0, so here the
// flags are `unsigned long` and the result `bool` [G]; B3PromptsComponent.h's `void (.., unsigned int, unsigned int)`
// declaration needs the same change before this joins that header's translation unit.
// Prepares one prompt per flag group; the 0x2000000 / 0x18000000 groups are the func_0031F760 shape (text + button).
bool func_0031ECD0(CB3PromptsComponent *self, unsigned long flags, int b)
{
    int id;
    self->Prepare();
    self->field_10 = flags;
    self->field_18 = b;
    self->field_A4 = 0;
    switch (D_01E90424.value) {
    case 5:
        self->field_A0 = D_004E08B0;
        break;
    case 2:
    case 3:
    case 4:
        self->field_A0 = D_004E08B0 * D_01E90420.value;
        break;
    case 0:
    case 1:
    default:
        self->field_A0 = 0.0f;
        break;
    }
    if (self->field_10 & 0x419E9003) {
        if (self->field_10 & 0x1) id = 0x152;
        else if (self->field_10 & 0x2) id = 0x153;
        else if (self->field_10 & 0x1000) id = 0x1C1;
        else if (self->field_10 & 0x8000) id = 0x1C2;
        else if (self->field_10 & 0x20000) id = 0x15D;
        else if (self->field_10 & 0x800000) id = 0x307;
        else if (self->field_10 & 0x40000) id = 0x302;
        else if (self->field_10 & 0x80000) id = 0x26D;
        else if (self->field_10 & 0x100000) id = 0x15B;
        else if (self->field_10 & 0x1000000) id = 0x73;
        else if (self->field_10 & 0x40000000) id = 0xC10;
        func_0031FB10(self, 0, id, -1.0f);
    }
    if (self->field_10 & 0x1C00020681CUL) {
        if (self->field_10 & 0x4) id = 0x154;
        else if (self->field_10 & 0x8) id = 0x155;
        else if (self->field_10 & 0x10) id = 0x159;
        else if (self->field_10 & 0x800) id = 0x1C0;
        else if (self->field_10 & 0x4000) id = 0x1BE;
        else if (self->field_10 & 0x2000) id = 0x1C2;
        else if (self->field_10 & 0x200000) id = 0x306;
        else if (self->field_10 & 0x4000000000UL) id = 0xC52;
        else if (self->field_10 & 0x8000000000UL) id = 0xC0B;
        else if (self->field_10 & 0x10000000000UL) id = 0x159;
        func_0031FB10(self, 1, id, -1.0f);
    }
    if (self->field_10 & 0x480) {
        float h = -1.0f;
        if (self->field_10 & 0x400) id = 0x3AB;
        else if (self->field_10 & 0x80) { h = D_004E0A18; id = 0x15A; }
        func_0031FB10(self, 2, id, h);
    }
    if (self->field_10 & 0x4000000)
        func_0031FB10(self, 6, 0x99B, -1.0f);
    if (self->field_10 & 0x200)
        func_0031F760(self, false);
    if (self->field_10 & 0x400000)
        func_0031F760(self, true);
    if (self->field_10 & 0x2000000) {
        CB3MenuPageManager *mgr = &D_01E90240;
        CGt2dScene *scene = &D_01E90240.field_1A0;
        CGt2dFrame *root = scene->field_14;
        int layer = self->field_8;
        float w = func_00382BE0(3);
        float tx = 5.0f + 0.5f * w + D_004C5348.marValues[0];
        if (self->field_74[2] == 0)
            self->field_74[2] = scene->ConstructObject(layer, root);
        const unsigned short *text = func_00271A00(&D_0051BA44, 0x15C);
        func_001D6C40(self->field_74[2], CGtV2d(tx, D_004C5348.marValues[1]), CGtV2d(0.0f, 0.5f), 24.0f,
                      &mgr->field_0[0], D_00665ED0.pFont, text);
        if (self->field_84[2] == 0)
            self->field_84[2] = scene->ConstructObject(layer, root);
        func_00382C00(self->field_84[2], D_004C5348, CGtV2d(0.5f, 0.5f), 3);
    }
    if (self->field_10 & 0x2000000000UL)
        func_0031F970(self);
    if (self->field_10 & 0x18000000) {
        CGt2dScene *scene = &D_01E90240.field_1A0;
        CGt2dFrame *root = scene->field_14;
        int layer = self->field_8;
        CB3MenuPageManager *mgr = &D_01E90240;
        int str;
        if ((self->field_10 & 0x10000000) == 0x10000000) str = 0x1DA;
        else str = 0x1DB;
        float tx = D_004C5350.marValues[0] - func_0031ECD0_inl1(8);
        if (self->field_74[3] == 0)
            self->field_74[3] = scene->ConstructObject(layer, root);
        const unsigned short *text = func_00271A00(&D_0051BA44, str);
        func_001D6C40(self->field_74[3], CGtV2d(tx, D_004C5350.marValues[1]), CGtV2d(1.0f, 0.5f), 24.0f,
                      &mgr->field_0[0], D_00665ED0.pFont, text);
        if (self->field_84[3] == 0)
            self->field_84[3] = scene->ConstructObject(layer, root);
        func_00382C00(self->field_84[3], D_004C5350, CGtV2d(0.5f, 0.5f), 8);
    }
    if (self->field_10 & 0x20) {
        if (self->field_10 & 0x20) id = 0x158;
        func_0031FB10(self, 3, id, -1.0f);
    }
    if (self->field_10 & 0x1000000040UL) {
        if (self->field_10 & 0x40) id = 3;
        else if (self->field_10 & 0x1000000000UL) id = 0xC05;
        func_0031FB10(self, 4, id, -1.0f);
    }
    if (self->field_10 & 0x10000) {
        if (self->field_10 & 0x10000) id = 0x426;
        func_0031FB10(self, 4, id, -1.0f);
    }
    if (self->field_10 & 0x100) {
        if (self->field_10 & 0x100) id = 0x156;
        func_0031F5E0(self, id, (self->field_10 & 0x80000000UL) != 0);
    }
    if (self->field_10 & 0x80000000UL)
        func_0031FB10(self, 7, 0x9E4, -1.0f);
    if (self->field_10 & 0x100000000UL)
        func_0031FB10(self, 9, 0x17, -1.0f);
    if (self->field_10 & 0x200000000UL)
        func_0031FB10(self, 9, 0x18, -1.0f);
    if (self->field_10 & 0x400000000UL)
        func_0031FB10(self, 10, 0xF, -1.0f);
    if (self->field_10 & 0x800000000UL)
        func_0031FB10(self, 9, 0xBF7, -1.0f);
    if (IsNewMailAvailable__22CGtBuddiesPS2DirtySockFv(&D_01E3D390))
        self->field_A8 = 1;
    else
        self->field_A8 = 0;
    if (func_0035F660(&D_01E3D390))
        self->field_A9 = 1;
    else
        self->field_A9 = 0;
    if (func_0035F670(&D_01E3D390))
        self->field_AA = 1;
    else
        self->field_AA = 0;
    func_0031E800(self);
    self->Update(0.0f);
    return true;
}
