// NONMATCHING: func_0042C600 -- retail 470 / ours 471 instructions, 96 in changed runs
// L270: logic/layout/switch/calls right (car text string as named local, scene declared after loop counter); left: retail computes (float)594 once into a saved f20 and keeps it across the class-text calls (frame +0x10, g in s1); every form tried (float/const/int local, literal twice, inline float param, named CGtV2d, opt_propagation off) rematerialises li/mtc1/cvt per use
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (L270): car-carousel component update (sibling of func_0042CD60 / func_0042DAE0, same member layout):
// advances the slide timer field_23C for states 1-4, and when a slide ends rebuilds the car name / class texts.
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

enum EB3MenuCarClasses {};

class CB3VehicleList {
public:
    unsigned long GetCarID(EB3MenuCarClasses, int);
    unsigned char pad_0[0x10];
};

struct UnkStruct_0042C600_e {
    signed char field_0;
    signed char field_1;
    unsigned char pad_2[0x2];
    unsigned char field_4;
    unsigned char pad_5[0x7];
};

struct UnkStruct_0042C600 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x6];
    UnkStruct_0042C600_e field_10[20];
    UnkStruct_0042C600_e field_100[19];
    unsigned char pad_1E4[0x8];
    CGt2dObject * field_1EC[4];
    CGt2dObject * field_1FC[4];
    unsigned char pad_20C[0xC];
    CGt2dObject * field_218;
    CGt2dObject * field_21C;
    unsigned char pad_220[0x8];
    CGt2dObject * field_228;
    CGt2dObject * field_22C;
    int field_230;
    int field_234;
    int field_238;
    float field_23C;
    int field_240;
    int field_244;
    int field_248;
    int field_24C;
    unsigned char pad_250[0x4];
    int field_254;
    int field_258;
    int field_25C;
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x40];
    CGtV4d field_40;
    CGtV4d field_50;
    unsigned char pad_60[0xB0];
    CGtV4d field_110;
};

struct UnkStruct_0042C600_2;
struct UnkStruct_0042C600_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};
struct UnkStruct_0042C600_2 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_0042C600_e0 * field_C;
};
struct UnkStruct_D_0051A868 {
    UnkStruct_0042C600_2 * field_0;
    unsigned char pad_4[0xC];
};
// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113, func_00427080).
struct UnkStruct_0042C600_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };

extern UnkStruct_D_0051A868 D_0051A868;
extern UnkStruct_D_01E90240 D_01E90240;
extern CGt2dScene D_01E903E0;
extern CB3VehicleList D_005186A0;
extern UnkStruct_P16 D_0051BA44;
extern const CGtV2d D_004D1718;
extern const CGtV2d D_004D1720;
extern const CGtV2d D_004D1728;
extern const CGtV2d D_004D1730;
extern const CGtV2d D_004D1738;
extern const char D_004D1768[];

extern "C" int strcasecmp(const char *, const char *);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" int func_003EB060(unsigned long);
extern "C" int func_003EAE40(int, int);
extern "C" int GetClassString__20CB3CarouselComponentF17EB3MenuCarClasses(int);
extern "C" void func_0042DAE0(UnkStruct_0042C600 *);
extern "C" void func_0042B7C0(UnkStruct_0042C600 *);
extern "C" void func_0042CD60(UnkStruct_0042C600 *);
extern "C" void func_003824D0(CGt2dObject * obj, const CGtV2d & a, const CGtV2d & b, float c, CGtV4d d, CGtV4d e,
                              const unsigned short * text, int f, float g, float h);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    void *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
#define CGt2dObjectImage_Prepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d

static inline void * func_0042C600_inl1(const char * name)
{
    UnkStruct_0042C600_2 * t0 = D_0051A868.field_0;
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_0042C600_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return (void *)t2;
        }
    }
    return 0;
}

static inline void func_0042C600_inl2(UnkStruct_0042C600 * self)
{
    int i;
    CGt2dScene * const scene = &D_01E903E0;
    for (i = 0; i < 4; i++) {
        if (self->field_1EC[i] != 0) {
            scene->DestructObject(self->field_8 + 1, self->field_1EC[i]);
            self->field_1EC[i] = 0;
        }
        if (self->field_1FC[i] != 0) {
            scene->DestructObject(self->field_8 + 1, self->field_1FC[i]);
            self->field_1FC[i] = 0;
        }
    }
}

static inline unsigned long func_0042C600_inl3(UnkStruct_0042C600 * self)
{
    int idx = self->field_244;
    if (self->field_234 == 4 && (unsigned int)(self->field_238 - 3) <= 1) {
        if (idx < self->field_24C) {
            return D_005186A0.GetCarID((EB3MenuCarClasses)self->field_100[idx].field_1, self->field_100[idx].field_0);
        }
        return 0;
    }
    if (idx < self->field_248) {
        return D_005186A0.GetCarID((EB3MenuCarClasses)self->field_10[idx].field_1, self->field_10[idx].field_0);
    }
    return 0;
}

static inline void func_0042C600_inl4(UnkStruct_0042C600 * self)
{
    UnkStruct_D_01E90240 * const g = &D_01E90240;
    if (self->field_230 == 0) {
        const unsigned short * s = func_00271A00(&D_0051BA44, func_003EAE40(func_003EB060(func_0042C600_inl3(self)), 1));
        func_003824D0(self->field_21C, CGtV2d(594, 380.0f), CGtV2d(1.0f, 1.0f), 26.0f, g->field_40, g->field_50,
                      s, 0x21, 1.5f, 3.402823466e+38f);
    }
    func_0042CD60(self);
}

// 0x0042C600
extern "C" void func_0042C600(UnkStruct_0042C600 * self, float dt)
{
    switch (self->field_238) {
    case 2:
    case 1:
        if (self->field_230 == 0) {
            self->field_23C += dt / 0.2f;
        } else {
            self->field_23C += dt / 0.1f;
        }
        if (!(self->field_23C < 1.0f)) goto doneA;
        func_0042C600_inl2(self);
        func_0042DAE0(self);
        break;
    case 3:
    case 4:
        self->field_23C += dt / 0.2f;
        if (!(self->field_23C < 1.0f)) goto doneB;
        func_0042C600_inl2(self);
        func_0042DAE0(self);
        break;
    doneA:
        self->field_240 = self->field_244;
        self->field_23C = 0.0f;
        self->field_238 = 0;
        func_0042C600_inl2(self);
        func_0042DAE0(self);
        func_0042C600_inl4(self);
        break;
    doneB:
        self->field_254 = self->field_258;
        self->field_244 = 0;
        self->field_240 = 0;
        self->field_23C = 0.0f;
        self->field_238 = 0;
        func_0042C600_inl2(self);
        func_0042B7C0(self);
        for (int i = 0; i < 2; i++) {
            self->field_10[i].field_4 = 0;
        }
        func_0042DAE0(self);
        if (self->field_25C == 9) {
            UnkStruct_D_01E90240 * const g = &D_01E90240;
            const unsigned short * cls = func_00271A00(&D_0051BA44,
                GetClassString__20CB3CarouselComponentF17EB3MenuCarClasses(self->field_258));
            void * tex = func_0042C600_inl1(D_004D1768);
            float x = 594;
            CGt2dObjectImage_Prepare(self->field_22C, CGtV2d(x, 89.0f), CGtV2d(1.0f, 0.5f), D_004D1718, g->field_110,
                                     tex, D_004D1728, D_004D1730, 0);
            func_003824D0(self->field_218, CGtV2d(x - (8.0f + D_004D1718.marValues[0]), 76.0f), CGtV2d(1.0f, 0.0f),
                          26.0f, g->field_40, g->field_50, cls, 0x21, 1.5f, 3.402823466e+38f);
            CGt2dObjectImage_Prepare(self->field_228,
                                     CGtV2d(self->field_218->mObjectSpace.mTopLeftPos.marValues[0] - 8.0f, 89.0f),
                                     CGtV2d(1.0f, 0.5f), D_004D1718, g->field_110, tex, D_004D1720, D_004D1738, 0);
        }
        func_0042C600_inl4(self);
        break;
    }
}
