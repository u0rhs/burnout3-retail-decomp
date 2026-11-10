// NONMATCHING: Prepare__22CB3BackgroundComponentF17EB3BackgroundType -- retail 487 / ours 474 instructions, 440 in changed runs
// son8: first archive. Full switch (13 cases + default), flags b2/b3 for the border image objects, all callee args and rodata names (kB3DNASImage*, kBackgroundBorderColourScale) from asm; fixed CGtV2d arg order pos/anchor/size. Left: retail hoists layer+3/+4/+5 into saved regs (fp/s7) up front (tried l3/l4/l5, l1..l5 locals: worse), CGtV2d locals are stored as two sw/swc1 in a different stack order (frame 0x1D0 vs 0x1E0)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/gamesource/Menu/DebugMenu/Components/B3BackgroundComponent.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_0031D930_c {
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[6];
    CGtV4d field_10;
    CGt2dObject *field_20;
    CGt2dObject *field_24;
    unsigned char pad_28[0x10];
    CGt2dObject *field_38;
    unsigned char pad_3C[0x10];
    CGt2dObject *field_4C;
    CGt2dObject *field_50;
    unsigned char pad_54[4];
    CGt2dObject *field_58;
    float field_5C;
    float field_60;
    unsigned char field_64;
    unsigned char field_65;
    unsigned char field_66;
    unsigned char field_67;
    unsigned char field_68;
    unsigned char field_69;
};
struct UnkStruct_0031D930_e { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0031D930_m {
    unsigned char pad_0[0x100];
    CGtV4d field_100;
    CGtV4d field_110;
};

extern CB3MenuPageManager D_01E90240;
extern CGt2dScene D_01E903E0;
extern CGtTexture *D_01EA46B0[0x38];
extern UnkStruct_0031D930_e *D_01E9040C;
extern unsigned char D_01E91C3D;
extern int D_0051A9A0;
extern int D_0051A9A4;
extern unsigned char D_0051A6A8[0x10];
extern unsigned char D_0051A870[0x10];
extern unsigned char D_0051BA44[0x10];
extern int D_00665ED0;
extern float D_004E0A40;
extern const CGtV4d kBackgroundBorderColourScale;
extern const CGtV2d kB3DNASImageBackgroundPos;
extern const CGtV2d kB3DNASImageBackgroundHandle;
extern const CGtV2d kB3DNASImageBackgroundSize;
extern const CGtV2d kB3DNASImageTextPos;
extern const CGtV2d kB3DNASImageBTextHandle;
extern const CGtV2d kB3DNASImagePos;
extern const CGtV2d kB3DNASImageHandle;
extern const CGtV2d kB3DNASImageSize;
extern CGtV4d D_01E90330;
extern CGtV4d D_01EA4790;
extern CGtV4d D_01EA48E0;
extern CGtTexture *D_01EA462C;
extern float D_004E0B78;
extern float D_004E07C0;

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" void PrepareBorders__22CB3BackgroundComponentFf(void *, float);
extern "C" void func_0031D340(void *, float);
extern "C" void func_00130C70(void *);
extern "C" void func_00130C30(void *, int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_001D6C40(float, CGt2dObject *, const CGtV2d &, const CGtV2d &, CGtV4d, void *, void *);
extern "C" void Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(
    CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d);
extern "C" void Prepare__21CGt2dObjectVideoImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP15CGtVideoDecoder(
    CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, void *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, CGtTexture *, const CGtV2d &, const CGtV2d &, unsigned int);
extern "C" bool Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(
    CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV2d &, unsigned int, int);

#define BoxPrepare Prepare__14CGt2dObjectBoxFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d
#define VideoPrepare Prepare__21CGt2dObjectVideoImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP15CGtVideoDecoder
#define ImagePrepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d

extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(UnkStruct_0031D930_c *self, int type)
{
    Prepare__20CB3MenuComponentBaseFv(self);
    CGt2dScene *scene = &D_01E903E0;
    CGt2dFrame *root = scene->field_14;
    CB3MenuPageManager *mgr = &D_01E90240;
    int layer = self->field_8;
    bool b2 = false;
    bool b3 = false;
    self->field_69 = type;
    self->field_64 = D_01E91C3D;
    self->field_5C = -1.0f;
    self->field_60 = -1.0f;
    self->field_68 = 0;
    D_01E9040C[layer + 2].field_0 = 0x10;
    D_01E9040C[layer + 1].field_0 = 8;
    switch (type) {
    case 0:
        b3 = true;
        self->field_20 = scene->ConstructObject(layer, root);
        if (D_0051A9A4 != 0x1A) {
            func_00130C70(D_0051A6A8);
            func_00130C30(D_0051A6A8, 0x1A);
        }
        self->field_10 = mgr->field_110;
        if (D_0051A9A0 == 0x17) {
            VideoPrepare(self->field_20, CGtV2d(0.0f, 64.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 352.0f), self->field_10, D_0051A870);
        } else {
            self->field_67 = 0;
            self->field_66 = 0;
            self->field_65 = 1;
            BoxPrepare(self->field_20, CGtV2d(0.0f, 64.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 352.0f), mgr->field_100);
        }
        PrepareBorders__22CB3BackgroundComponentFf(self, D_004E0A40);
        break;
    case 1:
        b3 = true;
        self->field_20 = scene->ConstructObject(layer, root);
        func_00130C30(D_0051A6A8, 0x1A);
        self->field_10 = mgr->field_110;
        if (D_0051A9A0 == 0x17) {
            VideoPrepare(self->field_20, CGtV2d(0.0f, 64.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 352.0f), self->field_10, D_0051A870);
        } else {
            self->field_67 = 0;
            self->field_66 = 0;
            self->field_65 = 1;
            BoxPrepare(self->field_20, CGtV2d(0.0f, 64.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 352.0f), mgr->field_100);
        }
        PrepareBorders__22CB3BackgroundComponentFf(self, -1.0f);
        break;
    case 2:
        self->field_20 = scene->ConstructObject(layer, root);
        VideoPrepare(self->field_20, CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 480.0f), mgr->field_110, D_0051A870);
        break;
    case 3:
    case 6:
        self->field_20 = scene->ConstructObject(layer, root);
        BoxPrepare(self->field_20, CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 480.0f), mgr->field_100);
        break;
    case 4:
        b2 = true;
        b3 = true;
        break;
    case 5:
        self->field_20 = scene->ConstructObject(layer, root);
        ImagePrepare(self->field_20, CGtV2d(0.0f, 64.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 384.0f), mgr->field_110,
                     D_01EA46B0[0x33], *(CGtV2d *)&D_01EA4790.f[0], *(CGtV2d *)&D_01EA4790.f[2], 0);
        PrepareBorders__22CB3BackgroundComponentFf(self, -1.0f);
        func_0031D340(self, -1.0f);
        break;
    case 7:
        break;
    case 8:
        if (self->field_64 != 0) {
            b2 = true;
            b3 = true;
        }
        break;
    case 9:
        if (self->field_64 == 0) {
            PrepareBorders__22CB3BackgroundComponentFf(self, D_004E0A40);
        } else {
            PrepareBorders__22CB3BackgroundComponentFf(self, 1.0f);
        }
        b3 = true;
        break;
    case 10:
        self->field_67 = 1;
        self->field_66 = 1;
        b3 = true;
        self->field_5C = 0.0f;
        self->field_20 = scene->ConstructObject(layer, root);
        VideoPrepare(self->field_20, CGtV2d(0.0f, 64.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 352.0f), mgr->field_110, D_0051A870);
        PrepareBorders__22CB3BackgroundComponentFf(self, -1.0f);
        break;
    case 11:
        self->field_20 = 0;
        self->field_10 = mgr->field_110;
        PrepareBorders__22CB3BackgroundComponentFf(self, -1.0f);
        func_0031D340(self, -1.0f);
        break;
    case 12:
        b2 = true;
        b3 = true;
        self->field_58 = scene->ConstructObject(layer + 4, root);
        self->field_4C = scene->ConstructObject(layer + 3, root);
        self->field_50 = scene->ConstructObject(layer + 5, root);
        Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(
            self->field_4C, kB3DNASImageBackgroundPos, kB3DNASImageBackgroundHandle, kB3DNASImageBackgroundSize, 0x99, 0);
        {
            int s = func_00271A00(D_0051BA44, 0x430);
            func_001D6C40(17.0f, self->field_50, kB3DNASImageTextPos, kB3DNASImageBTextHandle, mgr->field_110, (void *)(D_00665ED0), (void *)(s));
        }
        ImagePrepare(self->field_58, kB3DNASImagePos, kB3DNASImageHandle, kB3DNASImageSize, mgr->field_110,
                     D_01EA462C, *(CGtV2d *)&D_01EA48E0.f[0], *(CGtV2d *)&D_01EA48E0.f[2], 0);
        break;
    default:
        b2 = true;
        b3 = true;
        break;
    }
    if (b2) {
        self->field_24 = scene->ConstructObject(layer + 1, root);
        CGtV4d col = kBackgroundBorderColourScale * mgr->field_110;
        ImagePrepare(self->field_24, CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 0.0f), CGtV2d(640.0f, 480.0f), col,
                     D_01EA46B0[1], CGtV2d(0.0f, 0.0f), CGtV2d(0.625f, 0.9375f), 0);
    }
    if (b3) {
        self->field_38 = scene->ConstructObject(layer + 2, root);
        ImagePrepare(self->field_38, CGtV2d(0.0f, 0.0f), CGtV2d(0.0f, 0.0f), CGtV2d(656.0f, 496.0f), D_01E90330,
                     D_01EA46B0[3], CGtV2d(0.0625f, 0.0625f), CGtV2d(D_004E0B78, D_004E07C0), 0);
    }
    return 1;
}
