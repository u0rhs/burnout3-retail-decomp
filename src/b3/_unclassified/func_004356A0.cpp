// Hand-written; the lifter refused it (a157: HUD voice icon update (sibling of func_00435AB0 members); decl order g,i,shadow,scene,layer; val before str stack order; bool b910 local; destroy/chk gotos with done fall-off).

// Hand-written (a157): HUD voice-chat icon component update (sibling of func_00435AB0's Prepare; same member layout).
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObjectText.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class CB3HUDComponent {
public:
    static CGt2dObjectText::COutlineDropShadow maOutlineDropShadow[3];
};

struct UnkStruct_004356A0_s {
    unsigned char pad_0[0x14];
    CGt2dScene field_14;
    unsigned char pad_end[0x70 - 0x14 - sizeof(CGt2dScene)];
};

struct UnkStruct_004356A0 {
    unsigned char pad_0[0x4];
    UnkStruct_004356A0_s * field_4;
    CGt2dFrame * field_8;
    unsigned char pad_C[0x4];
    short field_10;
    unsigned char pad_12[0xA];
    signed char field_1C;
    unsigned char pad_1D[0x3];
    CGt2dObject * field_20;
    CGt2dObject * field_24;
    unsigned short field_28[1];
    unsigned char pad_2A[0x26];
    CGtTexture * field_50;
    CGtTexture * field_54;
};

struct UnkStruct_player_4356A0 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual int vfunc_10();
    unsigned char pad_4[0x6D8];
    void * field_6DC;
};

struct UnkStruct_D_0066A4C0 {
    unsigned char pad_0[0x40];
    CGtV4d field_40;
};
struct UnkStruct_D_00665ED0 {
    CGt2dFont * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };

extern UnkStruct_D_0066A4C0 D_0066A4C0;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_P16 D_0051BA44;
extern UnkStruct_P16 D_01E33A8C;
extern UnkStruct_P16 D_01E32AE0;
extern UnkStruct_P16 D_0064D3B0;
extern UnkStruct_P16 D_004D1B00;
extern const CGtV2d D_01EA4810;
extern const CGtV2d D_01EA4818;
extern const CGtV2d D_004D1AF0;

extern "C" int func_0041E930(void *);
extern "C" float func_0041E8D0(void *);
extern "C" float func_0041E8C0(void *);
extern "C" bool func_0041E910(void *);
extern "C" int func_0041E8B0(void *);
extern "C" void * GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(int, unsigned short *, int);
extern "C" void func_00435CC0(void *, void *, void *, void *, void *);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" void func_001D6970(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const CGt2dFont *,
                              const unsigned short *, const CGt2dObjectText::COutlineDropShadow *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    CGtTexture *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
#define CGt2dObjectImage_Prepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d

// 0x004356A0
extern "C" void func_004356A0(UnkStruct_004356A0 * self)
{
    UnkStruct_D_0066A4C0 * const g = &D_0066A4C0;
    int i;
    const CGt2dObjectText::COutlineDropShadow * shadow = &CB3HUDComponent::maOutlineDropShadow[1];
    CGt2dScene * scene = &self->field_4[self->field_1C].field_14;
    int layer = self->field_10;
    bool b910;
    if (func_0041E930(&D_01E33A8C) >= 0) {
        UnkStruct_player_4356A0 * pl = (UnkStruct_player_4356A0 *)GetPlayerByID__23CGtNetworkPlayerManagerCFi(&D_01E32AE0, func_0041E930(&D_01E33A8C));
        void * car;
        unsigned short buf[16];
        const unsigned short * name;
        int val;
        const unsigned short * str;
        if (pl == 0) {
            if (func_0041E930(&D_01E33A8C) != GetMyPlayerID__23CGtNetworkPlayerManagerCFv(&D_01E32AE0)) return;
            car = &D_0064D3B0;
        } else {
            car = pl->field_6DC;
        }
        if (car == 0) {
            ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(pl->vfunc_10(), buf, 16);
            name = buf;
        } else {
            name = (const unsigned short *)((char *)car + 0x1974);
        }
        str = func_00271A00(&D_0051BA44, 0x7DB);
        val = (int)func_0041E8D0(&D_01E33A8C);
        func_00435CC0(self->field_28, &D_004D1B00, &name, &val, &str);
        for (i = 0; i < 2; i++) {
            if ((&self->field_20)[i] == 0) {
                (&self->field_20)[i] = scene->ConstructObject(layer, self->field_8);
            }
        }
        func_001D6970(self->field_24, CGtV2d(-10.0f, -70.0f), CGtV2d(1.0f, 1.0f), 22.0f, g->field_40,
                      D_00665ED0.field_0, self->field_28, shadow);
        CGt2dObjectImage_Prepare(self->field_20, CGtV2d(self->field_24->mObjectSpace.mTopLeftPos.marValues[0] - 10.0f, -70.0f),
                                 CGtV2d(1.0f, 1.0f), CGtV2d(14.0f, 14.0f), g->field_40, self->field_54,
                                 D_01EA4810, D_01EA4818, 0);
    } else {
        float z = 0.0f;
        float t = func_0041E8C0(&D_01E33A8C);
        if (z == t) goto chk;
    destroy:
    if (self->field_24 != 0) {
        scene->DestructObject(layer, self->field_24);
        self->field_24 = 0;
    }
    if (self->field_20 == 0) return;
    scene->DestructObject(layer, self->field_20);
    self->field_20 = 0;
    goto done;
    chk:
    b910 = func_0041E910(&D_01E33A8C);
    if (!b910) goto destroy;
    if (func_0041E8B0(&D_01E33A8C) != 0) goto destroy;
    {
        const unsigned short * text;
        for (i = 0; i < 2; i++) {
            if ((&self->field_20)[i] == 0) {
                (&self->field_20)[i] = scene->ConstructObject(layer, self->field_8);
            }
        }
        text = func_00271A00(&D_0051BA44, 0x84);
        func_001D6970(self->field_24, CGtV2d(-10.0f, -70.0f), CGtV2d(1.0f, 1.0f), 22.0f, g->field_40,
                      D_00665ED0.field_0, text, shadow);
        CGt2dObjectImage_Prepare(self->field_20, CGtV2d(self->field_24->mObjectSpace.mTopLeftPos.marValues[0] - 10.0f, -70.0f),
                                 CGtV2d(1.0f, 1.0f), D_004D1AF0, g->field_40, self->field_50,
                                 CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 1.0f), 0);
    }
    done:
    ;
    }
}
