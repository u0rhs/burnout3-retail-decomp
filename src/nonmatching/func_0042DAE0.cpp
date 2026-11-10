// NONMATCHING: func_0042DAE0 -- retail 247 / ours 243 instructions, 120 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: a157: structured loop matches retail for the type==4 arm, nullpath and text far blocks; the type!=4 (else) arm is laid inline after the type==4 arm instead of after the tail loop/return (~100 instrs displaced), and the mgr spill is sw instead of sq. if/else swap, continue-forms, goto-forms all keep 
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (a157): carousel Update/refresh of the visible entries' 2D objects (4 slots around the cursor).
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_0042DAE0_e {
    unsigned char pad_0[0xC];
    void * field_C;
    signed char field_10;
    signed char field_11;
    unsigned char field_12;
    unsigned char pad_13;
    signed char field_14;
    unsigned char pad_15[3];
};
struct UnkStruct_0042DAE0_cls { unsigned char pad_0[0xA0]; unsigned char field_A0; };
struct UnkStruct_0042DAE0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x1E2];
    CGt2dObject * field_1EC[4];
    CGt2dObject * field_1FC[4];
    unsigned char pad_20C[0x28];
    int field_234;
    int field_238;
    unsigned char pad_23C[4];
    int field_240;
    int field_244;
    int field_248;
    unsigned char pad_24C[0x14];
    int field_260;
};
struct UnkStruct_tex { unsigned char pad_0[0xC]; int field_C; int field_10; };

extern CB3MenuPageManager D_01E90240;
extern CGt2dScene D_01E903E0;
extern const CGtV2d D_004D16D8;
extern const CGtV4d D_004D1740;
extern const CGtV4d D_004D1750;
extern const unsigned short D_004D1760[];

extern "C" void GetEntryPosition__20CB3CarouselComponentFi(CGtV2d * out, void * self, int idx);
extern "C" UnkStruct_tex * GetTexture__22CB3ImageReward2dObjectF18EB3RewardImageTypei(int, int);
extern "C" void func_00427080(CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV2d &, const CGtV4d, int, int, int);
extern "C" void func_00427560(CGt2dObject *, const CGtV2d &, const CGtV2d &, const CGtV2d &, const CGtV4d, int, int, int);
extern "C" void func_003824D0(CGt2dObject *obj, const CGtV2d &a, const CGtV2d &b, float c, CGtV4d d, CGtV4d e,
                              const unsigned short *text, int f, float g, float h);

static inline int func_0042DAE0_min(int a, int b) { int r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline int func_0042DAE0_zx(int a) { int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }

// 0x0042DAE0
extern "C" void func_0042DAE0(UnkStruct_0042DAE0 * self)
{
    int p5;
    int p6;
    CGt2dFrame * frame;
    CB3MenuPageManager * const mgr = &D_01E90240;
    if (self->field_234 == 4 && self->field_260 != -1) return;
    CGt2dScene * const scene = &D_01E903E0;
    frame = scene->field_14;
    int s3 = self->field_240 - 1;
    if (self->field_238 == 1) s3 = s3 - 1;
    int s2 = 0;
    int s7 = 0;
    CGt2dObject ** base;
    UnkStruct_0042DAE0_e * e;
    unsigned char * flag;
    CGt2dObject ** fp;
    CGt2dObject ** s1;
    CGtV2d pos4;
    CGtV2d size4;
    CGtV2d pos7;
    CGtV2d size7;
    CGtV4d col7;
    CGtV4d col4;
    do {
        if (s3 >= 0 && s3 < self->field_248) {
            e = (UnkStruct_0042DAE0_e *)((char *)self + s3 * 12);
            flag = &e->field_12;
            if (*flag == 0 && self->field_234 == 4) {
                base = (CGt2dObject **)((char *)self + s2 * 4);
                fp = (CGt2dObject **)((char *)base + 0x1FC);
                *fp = scene->ConstructObject(self->field_8 + 1, frame);
            } else {
                base = (CGt2dObject **)((char *)self + s2 * 4);
                *(CGt2dObject **)((char *)base + 0x1FC) = 0;
                fp = (CGt2dObject **)((char *)base + 0x1FC);
            }
            s1 = (CGt2dObject **)((char *)base + 0x1EC);
            *s1 = scene->ConstructObject(self->field_8 + 1, frame);
            if (self->field_234 == 4) {
                p5 = e->field_10;
                float f21 = 120.0f;
                float f20 = 60.0f;
                if (self->field_238 == 0 && s3 == self->field_244 && *flag != 0) {
                    f21 = f21 * 1.25f;
                    f20 = f20 * 1.25f;
                }
                p6 = e->field_14 % func_0042DAE0_zx(func_0042DAE0_min(((UnkStruct_0042DAE0_cls *)e->field_C)->field_A0, 6));
                GetEntryPosition__20CB3CarouselComponentFi(&pos4, self, s3);
                if (*flag == 0) {
                    func_003824D0(*fp, pos4, D_004D16D8, 0.5f * f20, D_004D1750, D_004D1750, D_004D1760, 0x21, 1.5f, 3.4028235e+38f);
                }
                size4.SetX(f21);
                CB3MenuPageManager * const m4 = &D_01E90240;
                size4.SetY(f20);
                if (*flag == 0) col4 = D_004D1740; else col4 = m4->field_110;
                func_00427080(*s1, pos4, D_004D16D8, size4, col4, e->field_11, p5, p6);
            } else {
                UnkStruct_tex * tex;
                float k;
                float h;
                if (*flag != 0) {
                    tex = GetTexture__22CB3ImageReward2dObjectF18EB3RewardImageTypei(self->field_234, s3);
                    k = 60.0f;
                    col7 = mgr->field_110;
                    h = k * (float)tex->field_10 / (float)tex->field_C;
                } else {
                    tex = GetTexture__22CB3ImageReward2dObjectF18EB3RewardImageTypei(self->field_234, s3);
                    col7 = CGtV4d(0.15f, 0.15f, 0.15f, 0.92f);
                    k = 60.0f;
                    h = k * (float)tex->field_10 / (float)tex->field_C;
                }
                size7.Set(k, h);
                GetEntryPosition__20CB3CarouselComponentFi(&pos7, self, s3);
                func_00427560(*s1, pos7, D_004D16D8, size7, col7, self->field_234, s3, 0);
            }
            s2++;
        }
        s3++;
    } while (++s7 < 4);
    for (; s2 < 4; s2++) {
        self->field_1EC[s2] = 0;
        self->field_1FC[s2] = 0;
    }
}
