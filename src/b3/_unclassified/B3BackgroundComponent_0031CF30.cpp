// CB3BackgroundComponent::Update(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BackgroundComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near1: case 10 as float d = 2.5f; d *= e - field_60; fixes f1/f2 numbering).

#include "b3/gamesource/Menu/DebugMenu/Components/B3BackgroundComponent.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GtMath.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_D_0051A6A8 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051A870 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051A9A0 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E91C3D { unsigned char value; unsigned char pad_1[0xF]; };

extern CB3MenuPageManager D_01E90240;
extern CGt2dScene D_01E903E0;
extern CGtV4d D_01E90350;
extern CGtV4d D_01E90330;
extern CGtTexture *D_01EA46B0[0x38];
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern UnkStruct_D_0051A870 D_0051A870;
extern UnkStruct_D_0051A9A0 D_0051A9A0;
extern UnkStruct_D_01E91C3D D_01E91C3D;
extern const CGtV4d kBackgroundBorderColourScale;
extern float D_004E06DC;

extern "C" float func_00324EF0(void *);
extern "C" bool func_00130EE0(void *);
extern "C" bool func_00130D50(void *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
#define CGt2dObjectImage_Prepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d
extern "C" void Prepare__21CGt2dObjectVideoImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP15CGtVideoDecoder(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour, void *dec);

// [G] probably GtMath::Interpolate(float,float,float) (B3O0PCH map, 0x48): no header body yet.
static inline float func_0031CF30_inl1(float a, float b, float t) { float z = 0.0f; return z + a + t * (b - a); }

// [C] fields past the header's declared members (offsets from this function's loads/stores); types from the widths.
struct UnkStruct_0031CF30_view {
    unsigned char pad_0[0x10];
    CGtV4d field_10;
    unsigned char pad_20[0x3C];
    float field_5C;
    unsigned char pad_60[0x4];
    unsigned char field_64;
    unsigned char pad_65[0x4];
    signed char field_69;
};
static inline void func_0031CF30_inl3(CGtV4d &c, const CGtV4d o) { asm("vmul.xyzw %0, %0, %1" : "+j"(c.mData) : "j"(o.mData)); }
#define V ((UnkStruct_0031CF30_view *)this)

static inline CGt2dObject *func_0031CF30_inl2(int layer) { CGt2dScene *s = &D_01E90240.field_1A0; return s->ConstructObject(layer, s->field_14); }

// 0x0031CF30
void CB3BackgroundComponent::Update(float dt)
{
    float target = D_004E06DC;
    switch (V->field_69) {
    case 10:
        if (field_60 > 0.0f) {
            float e = 0.4f + (0.04f + func_00324EF0(&D_0051A870));
            if (!(e <= field_60)) {
                float d = 2.5f;     // near1: constant first, then d *= (e - field_60): retail FP numbering (2.5 f2, diff f1) [G shape]
                d *= e - field_60;
                PrepareBorders(GtMath::Min(d, 1.0f));
                break;
            }
        }
    case 1:
        target = 0.0f;
        if (*(float *)pad_5C < 0.0f && field_24[4] != 0) {
            D_01E903E0.DestructObject(field_8 + 1, field_24[4]);
            field_24[4] = 0;
        }
    case 0: {
        if (!field_66) {
            field_66 = func_00130EE0(&D_0051A6A8);
            *(float *)pad_5C = 0.0f;
        } else if (!field_67) {
            field_67 = func_00130D50(&D_0051A6A8);
            *(float *)pad_5C = 0.0f;
        }
        float x = *(float *)pad_5C;
        if (!(x < 0.0f)) {
            float t;
            if (x < 0.4f) {
                t = 2.5f * x;
            } else {
                t = 1.0f;
                *(float *)pad_5C = -1.0f;
            }
            *(float *)pad_5C = *(float *)pad_5C + dt;
            PrepareBorders(func_0031CF30_inl1(1.0f, target, t));
        }
        if (field_65 && field_67 && field_66 && D_0051A9A0.field_0 == 23) {
            Prepare__21CGt2dObjectVideoImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP15CGtVideoDecoder(
                field_20, CGtV2d(0.0f, 64.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 352.0f), V->field_10, &D_0051A870);
            field_65 = false;
        }
        break;
    }
    case 8:
        if (pad_64[0] != D_01E91C3D.value) {
            if (D_01E91C3D.value == 0) {
                ReleaseObjects();
            } else {
                CGtV4d c;
                field_24[0] = func_0031CF30_inl2(field_8 + 1);
                c = kBackgroundBorderColourScale;
                func_0031CF30_inl3(c, D_01E90350);
                CGt2dObjectImage_Prepare(field_24[0], CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 480.0f),
                                         c, D_01EA46B0[1],
                                         CGtV2d(0.0f, 0.0f), CGtV2d(0.625f, 0.9375f), 0);
                field_38[0] = func_0031CF30_inl2(field_8 + 2);
                CGt2dObjectImage_Prepare(field_38[0], CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 0.0f), CGtV2d(656.0f, 496.0f),
                                         D_01E90330, D_01EA46B0[3],
                                         CGtV2d(0.0625f, 0.0625f), CGtV2d(40.9375f, 30.9375f), 0);
            }
            pad_64[0] = D_01E91C3D.value;
        }
        break;
    case 9:
        if (pad_64[0] != D_01E91C3D.value) {
            pad_64[0] = D_01E91C3D.value;
            if (pad_64[0])
                PrepareBorders(1.0f);
            else
                PrepareBorders(D_004E06DC);
        }
        break;
    }
}
