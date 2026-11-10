// func_003A8BF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (rewritten: sub-objects at 0x40/0x80, CGtV2d locals/temps by const ref, t0+11/12 hoisted, GetStageGtID returns unsigned long, bool func_0013AD70).

// from build/vt\try_func_003A8BF0_best.cpp
// func_003A8BF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
class CGt2dObject;

class CGt2dFrame;
class CGtTexture;

class CB3HardCodedRaceStageList;
struct UnkStruct_003A8BF0;
struct UnkStruct_003A8BF0_2;
struct UnkStruct_003A8BF0_3;
struct UnkStruct_003A8BF0_9;
struct UnkStruct_003A8BF0_e0;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_0051BF9C;
struct UnkStruct_D_00665ED0;
struct UnkStruct_D_01E7A800;
struct UnkStruct_D_01E88D40;
struct UnkStruct_D_01E893D6;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E903E0;
struct UnkStruct_D_01EA456C;

class CB3HardCodedRaceStageList {
public:
    unsigned long GetStageGtID(int, int);
    static unsigned long GetStageTrackID(unsigned long);
};

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    CGt2dFrame * field_14;
};

struct UnkStruct_003A8BF0_2 {
    float field_0;
    float field_4;
    int field_8;
    int field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    int field_20;
    int field_24;
};

struct UnkStruct_003A8BF0_3 {
    float field_0;
    float field_4;
};

struct UnkStruct_D_01E88D40 {
    unsigned short field_0;
    unsigned char pad_2[0xE];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003A8BF0_e0 {
    int field_0;
    unsigned char pad_4[0xC];
};

struct UnkStruct_D_00665ED0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E893D6 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003A8BF0_9 {
    unsigned char pad_0[0x10];
    unsigned long field_10;
    unsigned char pad_18[0x18];
    int field_30;
};

struct UnkStruct_D_01EA456C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E7A800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x110];
    GtMathPs2::CGtV4d field_110;
};

struct UnkStruct_003A8BF0_s40 {
    CGt2dObject * field_0;
    CGt2dObject * field_4;
    unsigned char pad_8[0x4];
    unsigned char field_C;
    unsigned char pad_D[0x33];
};

struct UnkStruct_003A8BF0_s80 {
    CGt2dObject * field_0;
    CGt2dObject * field_4;
    unsigned char pad_8[0x1A];
    unsigned char field_22;
    unsigned char pad_23[0x1];
};

struct UnkStruct_003A8BF0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x36];
    UnkStruct_003A8BF0_s40 field_40;
    UnkStruct_003A8BF0_s80 field_80;
    unsigned char pad_A4[0xC];
    UnkStruct_003A8BF0_e0 field_B0[1];  // [G] element count unknown
    unsigned char pad_C0[0x240];
    CB3HardCodedRaceStageList * field_300;
};

extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_01E88D40 D_01E88D40;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_01E893D6 D_01E893D6;
extern UnkStruct_D_01EA456C D_01EA456C;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" CGt2dObject * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, CGt2dFrame *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, CGtTexture *, const CGtV2d &, const CGtV2d &, unsigned int);
extern "C" void func_00285150(void *);
extern "C" CGtV2d * func_003EA7F0(unsigned long);
extern "C" int func_003E9C00(int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_001D6C40(CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV4d &, void *, void *, float);
extern "C" void Update__Q218CB3SatNavComponent9CPopupBoxFfRCQ29GtMathPs26CGtV2d(UnkStruct_003A8BF0_s40 *, const CGtV2d &, float);
extern "C" UnkStruct_003A8BF0_9 * func_003EA1D0(int);
extern "C" int func_0013AD30(void *, int, int);
extern "C" bool func_0013AD70(void *, int, int);

// 0x003A8BF0
extern "C" void func_003A8BF0(UnkStruct_003A8BF0 * self, int p0, int p1)
{
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    short t0 = self->field_8;
    CGt2dFrame * root = scene->field_14;
    CGtV2d zero(0.0f, 0.0f);
    int b = t0 + 11;
    int c = t0 + 12;
    unsigned long track = CB3HardCodedRaceStageList::GetStageTrackID(self->field_300->GetStageGtID(0, p1));
    func_00285150(&D_01E7A800);
    UnkStruct_003A8BF0_s40 * a = &self->field_40;
    a->field_0 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, t0 + 10, root);
    a->field_4 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, t0 + 13, root);
    a->field_C = 0;
    CGtV2d pos = *func_003EA7F0(track);
    func_001D6C40(a->field_4, zero, zero, mgr->field_110, (void *)(D_00665ED0.field_0), (void *)(func_00271A00(&D_0051BA44, func_003E9C00(self->field_B0[D_01E88D40.field_0].field_0))), 18.0f);
    Update__Q218CB3SatNavComponent9CPopupBoxFfRCQ29GtMathPs26CGtV2d(a, pos, 0.0f);
    UnkStruct_003A8BF0_s80 * bb = &self->field_80;
    UnkStruct_003A8BF0_9 * info = func_003EA1D0(self->field_B0[D_01E88D40.field_0].field_0);
    int x = D_0051BF9C.field_0;
    int n = func_0013AD30((void *)(x), self->field_B0[D_01E88D40.field_0].field_0, (D_01E893D6.field_0 != 0) ^ 1);
    bool f = func_0013AD70((void *)(x), self->field_B0[D_01E88D40.field_0].field_0, (D_01E893D6.field_0 != 0) ^ 1);
    if (D_01E893D6.field_0 == 0 && info != 0 && !f) {
        if ((info->field_10 != 0 && n != 3) || (info->field_30 == 2 && n <= 0)) {
            bb->field_4 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, b, root);
            bb->field_0 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, c, root);
            bb->field_22 = 0;
            Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(bb->field_0, zero, zero, CGtV2d(47.0f, 23.5f), mgr->field_110, (CGtTexture *)D_01EA456C.field_0, CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 1.0f), 0);
        }
    }
}
