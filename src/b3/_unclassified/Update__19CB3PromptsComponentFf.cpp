// Hand-written; the lifter refused it (parkfix: tool-bug park fixed (N213)).

// Hand-written; the lifter refused it (a147 source + all-temporary Prepare args (pos/anchor/size slots) + named float x for ref.x (f3/f2 order); local class decl conflicts with B3PromptsComponent.h (field_10, field_A0..AA)).

// Hand-written (a147).
#include "b3/gamesource/Menu/DebugMenu/Components/B3MenuComponentBase.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern CB3MenuPageManager D_01E90240;
extern CGtTexture *D_01EA4470[];
extern CGtV4d D_01EA4790;
extern CGtV4d D_01EA4798;
struct UnkStruct_D_gen { unsigned char pad_0[0x10]; };
extern UnkStruct_D_gen D_01E3D390;
extern UnkStruct_D_gen D_01E7A800;
struct UnkStruct_D_01E90424 { int value; unsigned char pad[0x100]; };
extern UnkStruct_D_01E90424 D_01E90424;
extern float D_004E08B0;
extern float D_004E0A04;
extern "C" int func_0035F660(void *);
extern "C" int func_0035F670(void *);
extern "C" int IsNewMailAvailable__22CGtBuddiesPS2DirtySockFv(void *);
extern "C" void func_00284E10(void *);
extern "C" void SetTexture__16CGt2dObjectImageFP10CGtTexture(CGt2dObject *, CGtTexture *, int);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
extern "C" void func_0031E800(void *);

class CB3PromptsComponent : public CB3MenuComponentBase {
public:
    void Update(float dt);
    void Release();
    unsigned char pad_C[4];
    unsigned long field_10;
    unsigned char pad_18[4];
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

static inline void func_0031E300_slide(CGt2dObject *o, float target)
{
    o->mObjectSpace.mTopLeftPos = CGtV2d(o->mObjectSpace.mTopLeftPos.marValues[0], 0.0f + target - 0.5f * o->mObjectSpace.mSize.marValues[1]);
}

// 0x0031E300
void CB3PromptsComponent::Update(float dt)
{
    CGt2dScene * scene = &D_01E90240.field_1A0;
    CGt2dFrame * root;
    bool flag = false;
    int icon;
    root = scene->field_14;
    if ((field_10 & 0x40) != 0 || (field_10 & 0x1000000000UL) != 0) {
        if (func_0035F660(&D_01E3D390) != 0) {
            if (field_A9 == 0) { func_00284E10(&D_01E7A800); field_A9 = 1; }
            icon = 0x84;
            flag = true;
        }
        if (func_0035F670(&D_01E3D390) != 0) {
            if (field_AA == 0) { func_00284E10(&D_01E7A800); field_AA = 1; }
            if (!flag) { icon = 0x7E; flag = true; }
        }
        if (IsNewMailAvailable__22CGtBuddiesPS2DirtySockFv(&D_01E3D390) != 0) {
            if (field_A8 == 0) { func_00284E10(&D_01E7A800); field_A8 = 1; }
            if (!flag) { icon = 0x80; flag = true; }
        } else {
            field_A8 = 0;
        }
    }
    if (flag == 1) {
        if (field_9C != 0) {
            SetTexture__16CGt2dObjectImageFP10CGtTexture(field_9C, D_01EA4470[icon], 0);
        } else {
            field_9C = scene->ConstructObject(field_8, root);
            float x = field_48[4]->mObjectSpace.mTopLeftPos.marValues[0];
            Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
                field_9C, CGtV2d(x - 24.0f - 3.0f, D_004E0A04),
                CGtV2d(0.0f, 0.5f), CGtV2d(24.0f, 24.0f), CGtV4d(1.0f, 1.0f, 1.0f, 1.0f), D_01EA4470[icon],
                *(const CGtV2d *)&D_01EA4790, *(const CGtV2d *)&D_01EA4798, 0);
            func_0031E800(this);
        }
    }
    unsigned char show;
    switch (D_01E90424.value) {
    case 2:
    case 5:
        show = field_A4;
        break;
    case 3:
    case 4:
        show = 1;
        break;
    default:
        return;
    }
    float t;
    if (show) {
        float f = field_A0 - dt;
        field_A0 = f;
        if (f <= 0.0f) {
            field_A0 = 0.0f;
            t = 0.0f;
        } else {
            t = 2.5f * f;
        }
    } else {
        float f = field_A0;
        float lim = D_004E08B0;
        f = f + dt;
        field_A0 = f;
        if (f < lim) {
            t = 2.5f * f;
        } else {
            field_A0 = D_004E08B0;
            t = 1.0f;
        }
    }
    float target = 0.0f + 504.0f + -56.5f * t;
    for (unsigned long i = 0; i < 11; i++) {
        if (field_1C[i] != 0 && field_1C[i]->mObjectSpace.mTopLeftPos.marValues[1] >= 416.0f) {
            func_0031E300_slide(field_1C[i], target);
            func_0031E300_slide(field_48[i], target);
        }
    }
    for (unsigned long i = 0; i < 4; i++) {
        if (field_74[i] != 0 && field_74[i]->mObjectSpace.mTopLeftPos.marValues[1] >= 416.0f) {
            func_0031E300_slide(field_74[i], target);
            func_0031E300_slide(field_84[i], target);
        }
    }
    if (field_94 != 0) {
        func_0031E300_slide(field_94, target);
        func_0031E300_slide(field_98, target);
    }
    if (field_9C != 0) {
        func_0031E300_slide(field_9C, target);
    }
}
