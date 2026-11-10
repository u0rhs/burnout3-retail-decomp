// CB3RewardImageComponent::Prepare(EB3RewardPageType,EB3RewardImageType,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3RewardImageComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (lit4fix: .lit4 externs as literals).


// CB3RewardImageComponent::Prepare(EB3RewardPageType,EB3RewardImageType,int) + 1 extra bool argument [G]
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

extern CGt2dScene D_01E903E0;

struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_D_0051BA44_x { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0051BA44_x D_0051BA44;
struct UnkStruct_D_01E90438_x { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E90438_x D_01E90438;

struct UnkStruct_3F60A0_tex {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
};
struct UnkStruct_3F60A0_a { int field_0; };
struct UnkStruct_3F60A0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    CGt2dObject * field_C;
    CGt2dObject * field_10;
    unsigned short * field_14;
    unsigned short * field_18[10];
};


extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" UnkStruct_3F60A0_tex * GetTexture__22CB3ImageReward2dObjectF18EB3RewardImageTypei(int, int);
extern "C" void *AllocUTF16String__19CB3MenuStringBufferFi(UnkStruct_D_01E90438_x *pool, int length);
extern "C" int GetHeadlineCrashDamage__24CB3HardCodedHeadlineListFi(int);
extern "C" int func_003F5E00(int);
extern "C" int func_00271A00(void *, int);
extern "C" void *func_001A3AA0(void *, void *, const UnkStruct_3F60A0_a *);
extern "C" int Length__10CGtUnicodeFPCUs(void *);
extern "C" void func_003D0710(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, CGtV4d colour,
                              int a, int b, int c, CGt2dFont *font, float d, float e, void *str, int f);
extern "C" void func_00427560(CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV2d &, const CGtV4d, int, int, int);

// 0x003F60A0
extern "C" bool Prepare__23CB3RewardImageComponentF17EB3RewardPageType18EB3RewardImageTypei(UnkStruct_3F60A0 * self, int pageType, int imageType, int idx, int flag)
{
    CGtV2d pos;
    CGtV2d size;
    CGtV2d tmp;
    if (self->field_18[0] == 0) goto init;
main:
    Prepare__20CB3MenuComponentBaseFv(self);
    {
        CGt2dScene * const scene = &D_01E903E0;
        CGt2dFrame * const frame = scene->field_14;
        if (pageType == 0) {
            pos.SetX(416.0f);
            pos.SetY(235.0f);
        } else {
            pos.SetX(320.0f);
            pos.SetY(225.0f);
        }
        UnkStruct_3F60A0_tex * t = GetTexture__22CB3ImageReward2dObjectF18EB3RewardImageTypei(imageType, idx);
        size.Set((float)t->field_C, (float)t->field_10);
        self->field_10 = scene->ConstructObject(self->field_8, frame);
        if (self->field_C != 0) {
            func_003D0710(self->field_C, CGtV2d(430.0f, 378.0f), CGtV2d(0.5f, 0.5f), CGtV4d(0.9f, 0.9f, 0.9f, 1.0f), 1, 0, 0, D_00665ED0.pFont, 38.0f, 3.4028235e+38f, 0, 0);
        }
        if (imageType == 1) goto one;
        if (imageType == 2) size *= 0.8f;
    after1:
        if (imageType == 2) goto two;
        tmp = size;
    after2:
        pos -= tmp * 0.5f;
        if (flag != 0) {
            func_00427560(self->field_10, pos, CGtV2d(0.0f, 0.0f), size, CGtV4d(0.15f, 0.15f, 0.15f, 0.92f), imageType, idx, 0);
        } else {
            func_00427560(self->field_10, pos, CGtV2d(0.0f, 0.0f), size, CGtV4d(1.0f, 1.0f, 1.0f, 1.0f), imageType, idx, 0);
        }
        return true;
    }
init:
    {
        self->field_14 = (unsigned short *)AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x400);
        unsigned short * p = self->field_14;
        int i = 0;
        do {
            UnkStruct_3F60A0_a a;
            self->field_18[i] = p;
            a.field_0 = GetHeadlineCrashDamage__24CB3HardCodedHeadlineListFi(i);
            func_001A3AA0(p, (void *)(func_00271A00(&D_0051BA44, func_003F5E00(i))), &a);
            p += Length__10CGtUnicodeFPCUs(p);
            p++;
            i++;
        } while (i < 10);
    }
    goto main;
one:
    size *= 1.3f;
    goto after1;
two:
    tmp.SetX(20.0f + size.X());
    tmp.SetY(70.0f + size.Y());
    goto after2;
}
