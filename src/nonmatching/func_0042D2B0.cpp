// NONMATCHING: func_0042D2B0 -- retail 494 / ours 497 instructions, 100 in changed runs
// L286: CB3CarouselComponent Prepare(self, int p1, int p2, int p3, int p4) returning 1; layout from archived sibling func_0042C600 (entry array really at +0xC stride 12: {obj*, c4, c5, pad, flag8}). Logic complete, 497/494, 100 changed. Left: (1) s0/s1/s2 rotation -- retail coalesces p3->frame (s0), p1->loop counter (s1), p2->tex (s2); ours p1->s0, p3->s1, p2->frame; sreg perm/run (default + V levers) and tex/frame declaration orders no help; (2) retail converts (float)594 once into f20 for the class block (same open issue as func_0042C600, L270); ours re-materialises li/mtc1/cvt per use; (3) li 6 scheduled before the lb in the pminw/pextlw % (int Min helper). Solved: g = &D_01E90240 held in s5 from the prologue with live re-definitions; int k = field_8 + 1 for the layer clip store; if (idx == 0) 1EC else 1F0.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

enum EB3MenuCarClasses {};

class CB3VehicleList {
public:
    unsigned long GetCarID(EB3MenuCarClasses, int);
    unsigned char pad_0[0x10];
};

struct UnkStruct_0042D2B0_o { unsigned char pad_0[0xA0]; unsigned char field_A0; };
struct UnkStruct_0042D2B0_e {
    UnkStruct_0042D2B0_o * field_0;
    signed char field_4;
    signed char field_5;
    unsigned char pad_6[0x2];
    signed char field_8;
    unsigned char pad_9[0x3];
};

struct UnkStruct_0042D2B0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    UnkStruct_0042D2B0_e field_C[20];
    UnkStruct_0042D2B0_e field_FC[19];
    unsigned char pad_1E0[0xC];
    CGt2dObject * field_1EC;
    CGt2dObject * field_1F0;
    unsigned char pad_1F4[0x18];
    CGt2dObject * field_20C;
    CGt2dObject * field_210;
    CGt2dFrame * field_214;
    CGt2dObject * field_218;
    CGt2dObject * field_21C;
    CGt2dObject * field_220;
    CGt2dObject * field_224;
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
    int field_250;
    int field_254;
    int field_258;
    int field_25C;
    int field_260;
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x40];
    CGtV4d field_40;
    CGtV4d field_50;
    unsigned char pad_60[0xB0];
    CGtV4d field_110;
};

struct UnkStruct_0042D2B0_2;
struct UnkStruct_0042D2B0_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};
struct UnkStruct_0042D2B0_2 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_0042D2B0_e0 * field_C;
};
struct UnkStruct_D_0051A868 {
    UnkStruct_0042D2B0_2 * field_0;
    unsigned char pad_4[0xC];
};
// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113, func_00427080).
struct UnkStruct_0042D2B0_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };

extern UnkStruct_D_0051A868 D_0051A868;
extern UnkStruct_D_01E90240 D_01E90240;
extern CGt2dScene D_01E903E0;
extern CB3VehicleList D_005186A0;
extern UnkStruct_P16 D_0051BA44;
extern const CGtV2d D_004D16D8;
extern const CGtV2d D_004D16E0;
extern const CGtV2d D_004D16E8;
extern const CGtV2d D_004D16F0;
extern const CGtV2d D_004D16F8;
extern const CGtV2d D_004D1700;
extern const CGtV2d D_004D1708;
extern const CGtV2d D_004D1710;
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
extern "C" void func_0042DAE0(UnkStruct_0042D2B0 *);
extern "C" void func_0042B7C0(UnkStruct_0042D2B0 *);
extern "C" void func_0042CD60(UnkStruct_0042D2B0 *);
extern "C" void func_003824D0(CGt2dObject * obj, const CGtV2d & a, const CGtV2d & b, float c, CGtV4d d, CGtV4d e,
                              const unsigned short * text, int f, float g, float h);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(
    CGt2dObject *self, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, CGtV4d colour,
    void *texture, const CGtV2d &uv0, const CGtV2d &uv1, unsigned int n);
#define CGt2dObjectImage_Prepare Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d

extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" void Prepare__16CB3Panel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dbb(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, bool, bool);
extern "C" void func_00372400(void *, const CGtV2d &, const CGtV2d &, const void *, float, float, float);
extern "C" void func_00427070(void *, int);

static inline int func_0042D2B0_pminw(int a, int b) { int r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline int func_0042D2B0_pextlw(int a) { int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }

static inline void * func_0042D2B0_inl1(const char * name)
{
    UnkStruct_0042D2B0_2 * t0 = D_0051A868.field_0;
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_0042D2B0_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return (void *)t2;
        }
    }
    return 0;
}

static inline unsigned long func_0042D2B0_inl3(UnkStruct_0042D2B0 * self)
{
    int idx = self->field_244;
    if (self->field_234 == 4 && (unsigned int)(self->field_238 - 3) <= 1) {
        if (idx < self->field_24C) {
            return D_005186A0.GetCarID((EB3MenuCarClasses)self->field_FC[idx].field_5, self->field_FC[idx].field_4);
        }
        return 0;
    }
    if (idx < self->field_248) {
        return D_005186A0.GetCarID((EB3MenuCarClasses)self->field_C[idx].field_5, self->field_C[idx].field_4);
    }
    return 0;
}

// 0x0042D2B0
extern "C" int func_0042D2B0(UnkStruct_0042D2B0 * self, int p1, int p2, int p3, int p4)
{
    float x0;
    float w;
    float h;
    float h2;
    float y;
    UnkStruct_D_01E90240 * g = &D_01E90240;
    CGt2dScene * const scene = &D_01E903E0;
    Prepare__20CB3MenuComponentBaseFv(self);
    self->field_244 = p3;
    self->field_240 = p3;
    self->field_238 = 0;
    self->field_23C = 0.0f;
    self->field_234 = p2;
    self->field_230 = p1;
    CGt2dFrame * frame = scene->field_14;
    if (p1 == 1) {
        x0 = 96.0f;
        h = 312.0f;
        y = 224.0f;
        w = 96.0f;
        h2 = 312.0f;
    } else {
        x0 = 32.0f;
        w = 128.0f;
        h = 344.0f;
        h2 = 280.0f;
        y = 224.0f;
    }
    if (p4 != 0) {
        self->field_20C = scene->ConstructObject(self->field_8, frame);
        Prepare__16CB3Panel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dbb(self->field_20C, CGtV2d(x0, 72.0f), CGtV2d(0.0f, 0.0f), CGtV2d(w, h), true, true);
    }
    func_0042B7C0(self);
    for (int i = 0; i < 2; i++) {
        self->field_C[i].field_8 = 0;
    }
    func_0042DAE0(self);
    if (p1 == 0) {
        if (self->field_250 != 0) {
            self->field_C[self->field_244].field_8 = self->field_250;
            if (self->field_260 == -1) {
                int idx = self->field_244;
                unsigned char m = self->field_C[idx].field_0->field_A0;
                if (m != 0) {
                    int dv = func_0042D2B0_pextlw(func_0042D2B0_pminw(m, 6));
                    int r = self->field_C[idx].field_8 % dv;
                    if (idx == 0) {
                        func_00427070(self->field_1EC, r);
                    } else {
                        func_00427070(self->field_1F0, r);
                    }
                }
            }
        }
        void * tex = func_0042D2B0_inl1(D_004D1768);
        if (self->field_260 == -1) {
            self->field_220 = scene->ConstructObject(self->field_8 + 3, frame);
            self->field_224 = scene->ConstructObject(self->field_8 + 3, frame);
        }
        if (self->field_25C == 9) {
            self->field_228 = scene->ConstructObject(self->field_8 + 3, frame);
            self->field_22C = scene->ConstructObject(self->field_8 + 3, frame);
        }
        if (self->field_260 == -1) {
            CGt2dObjectImage_Prepare(self->field_220, D_004D16E0, D_004D16D8, D_004D16F0, g->field_110, tex, D_004D16F8, D_004D1710, 0);
            CGt2dObjectImage_Prepare(self->field_224, D_004D16E8, D_004D16D8, D_004D16F0, g->field_110, tex, D_004D1708, D_004D1700, 0);
        }
    }
    self->field_214 = frame->ConstructChild();
    self->field_214->field_0.SetIdentity();
    self->field_214->field_0.field_0 = CGtV2d(x0, 72.0f);
    self->field_214->field_0.field_8 = CGtV2d(w, h2);
    int k = self->field_8 + 1;
    scene->field_2c[k].field_c = self->field_214;
    if (p4 != 0) {
        self->field_210 = scene->ConstructObject(self->field_8 + 2, frame);
        func_00372400(self->field_210, CGtV2d(0.0f, y), CGtV2d(0.0f, 0.0f), &g->field_110, 300.0f, x0 - 8.0f, 16.0f + w);
    }
    self->field_218 = 0;
    self->field_21C = 0;
    if (self->field_230 == 0) {
        if (self->field_25C == 9) {
            self->field_218 = scene->ConstructObject(self->field_8 + 2, frame);
            if (self->field_25C == 9) {
                g = &D_01E90240;
                const unsigned short * cls = func_00271A00(&D_0051BA44,
                    GetClassString__20CB3CarouselComponentF17EB3MenuCarClasses(self->field_258));
                void * tex = func_0042D2B0_inl1(D_004D1768);
                float x = 594;
                CGt2dObjectImage_Prepare(self->field_22C, CGtV2d(x, 89.0f), CGtV2d(1.0f, 0.5f), D_004D1718, g->field_110,
                                         tex, D_004D1728, D_004D1730, 0);
                func_003824D0(self->field_218, CGtV2d(x - (8.0f + D_004D1718.marValues[0]), 76.0f), CGtV2d(1.0f, 0.0f),
                              26.0f, g->field_40, g->field_50, cls, 0x21, 1.5f, 3.402823466e+38f);
                CGt2dObjectImage_Prepare(self->field_228,
                                         CGtV2d(self->field_218->mObjectSpace.mTopLeftPos.marValues[0] - 8.0f, 89.0f),
                                         CGtV2d(1.0f, 0.5f), D_004D1718, g->field_110, tex, D_004D1720, D_004D1738, 0);
            }
        }
        self->field_21C = scene->ConstructObject(self->field_8 + 2, frame);
        g = &D_01E90240;
        if (self->field_230 == 0) {
            const unsigned short * s = func_00271A00(&D_0051BA44, func_003EAE40(func_003EB060(func_0042D2B0_inl3(self)), 1));
            func_003824D0(self->field_21C, CGtV2d(594, 380.0f), CGtV2d(1.0f, 1.0f), 26.0f, g->field_40, g->field_50,
                          s, 0x21, 1.5f, 3.402823466e+38f);
        }
    }
    func_0042CD60(self);
    return 1;
}
