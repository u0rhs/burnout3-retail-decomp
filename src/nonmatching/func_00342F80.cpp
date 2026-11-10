// NONMATCHING: func_00342F80 -- retail 464 / ours 465 instructions, 94 in changed runs
// Loading-screen component Prepare(type, id) fully reconstructed (texture find by name 'loading_bars', random tip id inline for types 0/1 -- the inline's early returns give retail's out-of-line blocks, two text+bar rows, width fit to 610, heading and two bars). Left: retail computes the row's string id (id+1+i) before the first ConstructObject and keeps it, the list pointer, layer+1 and the two bar-slot addresses in sw/lw stack homes (0xC0-0x100, frame 0x220) where ours propagates/sq-spills them (frame 0x210), plus the width-fit copy 'o' at 0x210. Tried: declaration orders, inline helper for the text row, lvalue-first assignments, string id as named/arg.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_00342F80: [L] the loading screen's component Prepare(type, id) (called by func_00321500 with the page's
// type and tip id). Unnamed in every table, so a placeholder with C linkage.

#include "b3/GtMathPs2.h"
#include "b3/_unclassified/GtRandom.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_00342F80_obj {
    CGtV2d field_0;  // [G] top-left
    CGtV2d field_8;  // [G] size
};

struct UnkStruct_00342F80_pair {
    UnkStruct_00342F80_obj * field_0;
    UnkStruct_00342F80_obj * field_4;
};

struct UnkStruct_00342F80 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    UnkStruct_00342F80_obj * field_C;
    UnkStruct_00342F80_obj * field_10;
    UnkStruct_00342F80_obj * field_14;
    UnkStruct_00342F80_obj * field_18[2];
    UnkStruct_00342F80_pair field_20[2];
};

struct UnkStruct_00342F80_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_00342F80_4 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_00342F80_e0 * field_C;
};

struct UnkStruct_00342F80_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

struct UnkStruct_D_00518688 {
    UnkStruct_00342F80_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00518680 {
    CGtRandom r;
    unsigned char pad_8[0x8];
};

struct UnkStruct_D_01E903E0 {
    unsigned char pad_0[0x14];
    void * field_14;
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x40];
    CGtV4d field_40;
    CGtV4d field_50;
    unsigned char pad_60[0xB0];
    CGtV4d field_110;
};

struct UnkStruct_00342F80_uv {
    CGtV2d field_0;
    CGtV2d field_8;
};

struct UnkStruct_D_00665ED0 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5D50 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_00518688 D_00518688;
extern UnkStruct_D_00518680 D_00518680;
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern UnkStruct_D_004C5D50 D_004C5D50;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern const CGtV2d D_004C5CC8;
extern const CGtV2d D_004C5CD0;
extern const CGtV2d D_004C5CD8;
extern const CGtV2d D_004C5CE0;
extern const CGtV2d D_004C5CE8;
extern const CGtV2d D_004C5CF0;
extern const UnkStruct_00342F80_uv D_004C5D10[3];
extern const UnkStruct_00342F80_uv D_004C5D40;

extern "C" int strcasecmp(const char *, const void *);
extern "C" bool Prepare__20CB3MenuComponentBaseFv(void *);  // CB3MenuComponentBase::Prepare()
extern "C" UnkStruct_00342F80_obj * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" void func_0033D4E0(UnkStruct_00342F80_obj *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const void *,
                              const unsigned short *, const CGtV2d &, int);
extern "C" void func_003824D0(UnkStruct_00342F80_obj *, const CGtV2d &, const CGtV2d &, float, CGtV4d, CGtV4d,
                              const unsigned short *, int, float, float);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    UnkStruct_00342F80_obj *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, int, const CGtV2d &, const CGtV2d &,
    unsigned int);
#define CGt2dObjectImage_Prepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d

// [G] placeholder inline: a random tip string id for the two random loading-screen types, else the given id
static inline int func_00342F80_inl1(int type, int id)
{
    if (type == 0) {
        return D_00518680.r.Random() % 14 * 3 + 0x8EB;
    }
    if (type == 1) {
        return D_00518680.r.Random() % 10 * 3 + 0x919;
    }
    return id;
}

// 0x00342F80
extern "C" int func_00342F80(UnkStruct_00342F80 * self, int type, int id)
{
    UnkStruct_D_01E90240 * mgr = &D_01E90240;
    UnkStruct_D_01E903E0 * scene = &D_01E903E0;
    UnkStruct_00342F80_4 * list = D_00518688.field_0;
    int tex;
    void * frame = scene->field_14;
    int layer = self->field_8;
    int layer1 = layer + 1;
    int i;
    for (i = 0; i < list->field_8; i++) {
        tex = list->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_00342F80_blk *)(tex + 0x90))->field_18, &D_004C5D50) == 0) {
            goto found;
        }
    }
    tex = 0;
found:
    Prepare__20CB3MenuComponentBaseFv(self);
    self->field_C = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer1, frame);
    if (type == 2) {
        func_003824D0(self->field_C, D_004C5CC8, CGtV2d(1.0f, 0.5f), 36.0f, mgr->field_40, mgr->field_50,
                      func_00271A00(&D_0051BA44, id), 0x33, 1.5f, 400.0f);
        return 1;
    }
    id = func_00342F80_inl1(type, id);
    for (i = 0; i < 2; i++) {
        int sid = id + 1 + i;
        float maxX = 610;
        UnkStruct_00342F80_obj ** text = &self->field_18[i];
        *text = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer1, frame);
        CGtV2d scale(1.2f, 1.2f);
        const unsigned short * str = func_00271A00(&D_0051BA44, sid);
        func_0033D4E0(*text, D_004C5CD8 + D_004C5CE0 * (float)i, CGtV2d(0.0f, 0.5f), 27.0f, mgr->field_110, D_00665ED0.field_0,
                      str, scale, 2);
        UnkStruct_00342F80_obj ** p20 = &self->field_20[i].field_0;
        *p20 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, frame);
        CGt2dObjectImage_Prepare(*p20, D_004C5CE8 + D_004C5CF0 * (float)i, CGtV2d(1.0f, 0.5f), CGtV2d(110.0f, 28.0f),
                                 mgr->field_110, tex, D_004C5D10[i + 1].field_0, D_004C5D10[i + 1].field_8, 0);
        UnkStruct_00342F80_obj ** p24 = &self->field_20[i].field_4;
        *p24 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, frame);
        CGt2dObjectImage_Prepare(*p24, D_004C5CE8 + D_004C5CF0 * (float)i, CGtV2d(0.0f, 0.5f), CGtV2d(500.0f, 28.0f),
                                 mgr->field_110, tex, D_004C5D40.field_0, D_004C5D40.field_8, 0);
        UnkStruct_00342F80_obj o = **text;
        if (o.field_0.marValues[0] + o.field_8.marValues[0] > maxX) {
            o.field_8 *= (maxX - o.field_0.marValues[0]) / o.field_8.marValues[0];
            (*text)->field_8 = o.field_8;
            (*text)->field_0 = (D_004C5CD8 + D_004C5CE0 * (float)i) - o.field_8 * CGtV2d(0.0f, 0.5f);
        }
    }
    func_003824D0(self->field_C, D_004C5CC8, CGtV2d(1.0f, 0.5f), 36.0f, mgr->field_40, mgr->field_50,
                  func_00271A00(&D_0051BA44, id), 0x33, 1.5f, 400.0f);
    self->field_10 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, frame);
    CGt2dObjectImage_Prepare(self->field_10, D_004C5CD0, CGtV2d(1.0f, 0.5f), CGtV2d(110.0f, 28.0f),
                             mgr->field_110, tex, D_004C5D10[0].field_0, D_004C5D10[0].field_8, 0);
    self->field_14 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, frame);
    CGt2dObjectImage_Prepare(self->field_14, D_004C5CD0, CGtV2d(0.0f, 0.5f), CGtV2d(500.0f, 28.0f),
                             mgr->field_110, tex, D_004C5D40.field_0, D_004C5D40.field_8, 0);
    return 1;
}
