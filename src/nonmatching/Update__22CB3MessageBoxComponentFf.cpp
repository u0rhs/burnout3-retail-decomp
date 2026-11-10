// NONMATCHING: Update__22CB3MessageBoxComponentFf -- retail 931 / ours 893 instructions, 692 in changed runs
// draft4: call sequence identical; frame 0x180 vs 0x170, one extra s-register; our inlines reuse the caller's field_94/field_48 values where retail reloads them (38 fewer instrs); duplicated icon-prepare arm merged
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm and Ghidra draft, every branch, store and call accounted for; call sequence identical (calls.sh)

// CB3MessageBoxComponent::Update(float) -- draft4 (breadth-first draft).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3MessageBoxComponent.cpp.
// Classes are declared here with only what this function touches (as B3MessageBoxComponent_0032B530.cpp); field
// names are placeholders, types [G] by instruction widths.
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class CGt2dFont;
class CGtTexture;
class CGt2dObject {
public:
    CGtV2d mTopLeftPos;  // [C] CGt2dObject layout (Gt2dObject.h): pos 0x0, size 0x8, colour 0x10
    CGtV2d mSize;
    CGtV4d mColour;
};
class CB3HUDSoundManager {
public:
    unsigned char pad_0[0x100];
};
struct UnkStruct_D_01E90240 {
    CGtV4d field_0[3];   // [C] colours (B3MenuPageManager.h field_0)
    unsigned char pad_30[0xE0];
    CGtV4d field_110;    // [C] B3MenuPageManager.h field_110
};
struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
struct UnkStruct_D_004A4A10_e {
    int field_0;  // [C] compared with 0xF (8-byte entries indexed by field_94)
    unsigned char pad_4[0x4];
};

extern UnkStruct_D_01E90240 D_01E90240;
extern float D_01E90420[];             // [C] menu transition progress (D_01E90240 + 0x1E0)
extern UnkStruct_D_01E90424 D_01E90424;  // [C] menu transition state (2, 3/4, 5)
extern CB3HUDSoundManager D_01E7A800;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_004A4A10_e D_004A4A10[];
extern CGtTexture *D_01EA4470[];
// B3MessageBoxComponent.cpp's .rodata, zero in the file (set by its static initializer) [C]: 0x4C5650 a CGtV2d
// (FlashText outline [L]), 0x4C5658 a CGtV2d (icon size; its y read alone at 0x4C565C), 0x4C5660 a float (width [G]).
extern const CGtV2d D_004C5650;
extern const CGtV2d D_004C5658;
extern const float D_004C565C;
extern const float D_004C5660;

extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, CGtTexture *, const CGtV2d &, const CGtV2d &,
    unsigned int);  // CGt2dObjectImage::Prepare(...), plus retail's stack argument (N68)
extern "C" void Prepare__20CB3FlashText2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsRCQ29GtMathPs26CGtV2d(
    CGt2dObject *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const CGt2dFont *, const unsigned short *,
    const CGtV2d &);  // CB3FlashText2dObject::Prepare(...)
extern "C" void SetHFlashTimeScale__20CB3FlashText2dObjectFf(CGt2dObject *, float);
extern "C" void SetVFlashTimeScale__20CB3FlashText2dObjectFf(CGt2dObject *, float);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(CB3HUDSoundManager *, int);
extern "C" void FESelect__18CB3HUDSoundManagerFv(CB3HUDSoundManager *);
// CB3SelectionBar2dObject::Prepare [L, retail_names low]: bar, pos, anchor, three floats, colour.
extern "C" void func_00372400(CGt2dObject *bar, const CGtV2d *pos, const CGtV2d *anchor, float a, float b, float c,
                              const CGtV4d *colour);

struct UnkStruct_0032B6C0_e {
    const unsigned short *field_0;  // [C] the item's text (FlashText Prepare argument)
    unsigned char pad_4[0x4];
};

class CB3MessageBoxComponent {
public:
    void Update(float);
    // Inlines (names unknown): repeated verbatim in retail at every use.
    float func_0032B6C0_inl1(int i) {  // an item's row y
        if (field_94 == 8)
            return 0.0f + field_50 + 40.0f * (float)i;
        return 0.0f + field_50 + (float)i * (2.0f + D_004C565C);
    }
    void func_0032B6C0_inl2(int i) {  // prepare an icon item (field_94 == 8)
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
            field_28[i], CGtV2d(320.0f, func_0032B6C0_inl1(i)), CGtV2d(0.5f, 0.5f), D_004C5658, D_01E90240.field_110,
            D_01EA4470[i + 0x76], CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 1.0f), 0);
    }
    void func_0032B6C0_inl3(int i, bool sel) {  // prepare a text item
        if (sel) {
            CGtV2d pos(320.0f, func_0032B6C0_inl1(i));
            CGtV2d anchor(0.5f, 0.5f);
            field_5C = 0.0f;
            Prepare__20CB3FlashText2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsRCQ29GtMathPs26CGtV2d(
                field_20[i], pos, anchor, 40.0f, D_01E90240.field_0[1], D_00665ED0.pFont, field_10[i].field_0,
                D_004C5650);
        } else {
            CGtV2d pos(320.0f, func_0032B6C0_inl1(i));
            CGtV2d anchor(0.5f, 0.5f);
            Prepare__20CB3FlashText2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsRCQ29GtMathPs26CGtV2d(
                field_20[i], pos, anchor, 30.0f, D_01E90240.field_0[0], D_00665ED0.pFont, field_10[i].field_0,
                D_004C5650);
        }
    }
    void func_0032B6C0_inl4(float t) {  // place the selection bar behind the current item
        float half = 0.0f;
        int cur = field_C;
        float w;
        if (field_94 == 8) {
            w = field_28[cur]->mSize.marValues[0];
        } else {
            half = D_004C5660 / 2.0f;
            w = field_20[cur]->mSize.marValues[0];
        }
        float lp = 0.0f + 640.0f + t * ((D_004C5660 + w) - 640.0f);
        CGtV2d anchor(0.0f, 0.5f);
        CGtV2d pos(0.0f, func_0032B6C0_inl1(cur));
        func_00372400(field_44, &pos, &anchor, 640.0f, (half + (640.0f - lp)) / 2.0f, lp, &D_01E90240.field_110);
    }
    CGt2dObject *func_0032B6C0_inl5(int i) {  // the item's object
        if (field_94 == 8)
            return field_28[i];
        return field_20[i];
    }

    unsigned char pad_0[0xC];
    unsigned short field_C;   // [C] current item
    unsigned short field_E;   // [C] item count (when the kind table entry is not 0xF)
    UnkStruct_0032B6C0_e field_10[2];
    CGt2dObject *field_20[2];  // [C] text items (FlashText)
    CGt2dObject *field_28[3];  // [C] icon items (Image), field_94 == 8
    unsigned char pad_34[0x10];
    CGt2dObject *field_44;     // [C] the selection bar
    int field_48;              // [C] the prepared current item, -1 = none
    unsigned char pad_4C[0x4];
    float field_50;            // [C] first row y
    unsigned char pad_54[0x8];
    float field_5C;            // [C] flash timer (>= 0 running)
    unsigned char pad_60[0x34];
    signed char field_94;      // [C] message box kind (lb); 8 = three icons
};

// 0x0032B6C0
void CB3MessageBoxComponent::Update(float dt)
{
    int type = field_94;
    int count;
    if (D_004A4A10[type].field_0 == 0xF) {
        if (type == 8)
            count = 3;
        else
            count = 0;
    } else {
        count = field_E;
    }
    if (count == 0)
        return;

    int state = D_01E90424.field_0;
    switch (state) {
    case 2: {
        float t = D_01E90420[0];
        float step = 0.9f / (float)count;
        for (int i = 0; i < count; i++) {
            float start = step * (float)i;
            float f = GtMath::Min(GtMath::Max(t, start), 0.100000024f + start);
            float k = 0.0f + 1.0f - 9.999998f * (f - start);
            CGt2dObject *o = func_0032B6C0_inl5(i);
            CGtV2d p(0.0f + 320.0f - 320.0f * k - 0.5f * o->mSize.marValues[0], o->mTopLeftPos.marValues[1]);
            o->mTopLeftPos = p;
        }
        func_0032B6C0_inl4(t);
    } break;
    case 5: {
        if (field_48 != field_C) {
            if (field_48 < 0) {
                for (int i = 0; i < count; i++) {
                    CGt2dObject *o = func_0032B6C0_inl5(i);
                    CGtV2d p(320.0f - 0.5f * o->mSize.marValues[0], o->mTopLeftPos.marValues[1]);
                    o->mTopLeftPos = p;
                }
                FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            } else {
                if (type == 8)
                    func_0032B6C0_inl2(field_48);
                else
                    func_0032B6C0_inl3(field_48, false);
                FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            }
            field_48 = field_C;
            if (field_94 == 8)
                func_0032B6C0_inl2(field_48);
            else
                func_0032B6C0_inl3(field_48, true);
            func_0032B6C0_inl4(1.0f);
        }
        if (field_5C >= 0.0f && field_94 != 8) {
            field_5C += dt;
            float h;
            if (field_5C < 0.4f)
                h = 2.5f * field_5C;
            else
                h = -1.0f;
            SetHFlashTimeScale__20CB3FlashText2dObjectFf(field_20[field_48], h);
        }
    } break;
    case 3:
    case 4: {
        float t = D_01E90420[0];
        int sel;
        if (state == 3)
            sel = field_C;
        else
            sel = -1;
        if (field_48 >= 0) {
            field_48 = -1;
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            for (int i = 0; i < count; i++) {
                if (field_94 == 8) {
                    if (i == sel)
                        func_0032B6C0_inl2(i);
                    else
                        func_0032B6C0_inl2(i);
                } else if (i == sel) {
                    func_0032B6C0_inl3(i, true);
                    SetHFlashTimeScale__20CB3FlashText2dObjectFf(field_20[i], -1.0f);
                } else {
                    func_0032B6C0_inl3(i, false);
                }
            }
        }
        float a, b;
        if (t < 0.5f) {
            a = t / 0.5f;
            b = 1.0f - a;
        } else {
            a = 1.0f;
            b = -1.0f;
        }
        for (int i = 0; i < count; i++) {
            if (i == sel) {
                if (field_94 != 8)
                    SetVFlashTimeScale__20CB3FlashText2dObjectFf(field_20[i], b);
            } else if (field_94 == 8) {
                field_28[i]->mColour.SetA(a);
            } else {
                field_20[i]->mColour.SetA(a);
            }
        }
        func_0032B6C0_inl4(t);
    } break;
    }
}
