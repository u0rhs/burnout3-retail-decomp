// NONMATCHING: func_003BD760 -- retail 565 / ours 556 instructions, 174 in changed runs
// big1: logic complete, 556/565 instrs, 174 changed, block layout matches. Left: register pressure/spill choice -- retail keeps lb (field_8+3) in fp and item*20 in s7 and spills the slot pointers (&field_38[item] at sp+0xF0, &field_5C[item] at 0xD0/0xE0) with reloads (the 9 missing instrs); ours spills lb and keeps the slot pointer. Float regs: retail ay f20, y f21, x f22 (avail reuses it), tx f23, ax f24, ew f25 -- ours swaps x/ax (x param always highest). Found: index-first addressing needs (off + (int)self->field_38) with off = item*4; type 7 computes 0.046875f*(float)value before 'if (st == 1) st = 0x11' (float local); construct-if-null inline reads self->field_D8 inside; types 1-8 are an else-if chain (case 8 inline, 1-7 out of line); value is int (cvt.s.w).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): 64-bit hard-coded-list ids / prompt flags typed 64-bit in prototypes and locals (retail moves them in full 64-bit registers; docs/known.md N293); behaviour_audit quiet.

// func_003BD760 -- hand-written from retail (lifter refused). [L] a CB3VOptionsSelectComponent method (unit
// with CB3VOptionsSelectComponent::Update, DNAT); [G] research/nahelam_check.csv guesses
// CB3HOptionsSelectComponent::PreparePanel(int,uint,float). Prepares row `item`'s panel, then its value: a
// text (types 1-6, ellipsis-truncated to the panel width) or a two-part image bar (types 7/8).
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

class CGt2dFrame;
class CGtTexture;
extern CB3MenuPageManager D_01E90240;
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E903E0 D_01E903E0;
struct UnkStruct_D_00665ED8 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED8 D_00665ED8;
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0051BA44 D_0051BA44;
struct UnkStruct_D_004CA2D0 { CGtV2d field_0; unsigned char pad_8[0x8]; };
extern UnkStruct_D_004CA2D0 D_004CA2D0, D_004CA2D8, D_004CA2E0, D_004CA2E8;
struct UnkStruct_D_004CA2F0 { unsigned short field_0[8]; };
extern UnkStruct_D_004CA2F0 D_004CA2F0;
struct UnkStruct_D_004CA2F8 { char field_0[0x10]; };
extern UnkStruct_D_004CA2F8 D_004CA2F8;

struct UnkStruct_003BD760_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};
struct UnkStruct_003BD760_2 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_003BD760_e0 * field_C;
};
struct UnkStruct_D_00518688 {
    UnkStruct_003BD760_2 * field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_00518688 D_00518688;
// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113, B3HUDImpactTime_003D6AB0).
struct UnkStruct_003BD760_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

struct UnkStruct_003BD760_ent {
    unsigned char pad_0[0x4];
    unsigned short * field_4;
    void * field_8;
    unsigned char pad_C[0x1];
    unsigned char field_D;
    unsigned char field_E;
    unsigned char pad_F[0x5];
};
struct UnkStruct_003BD760_panel {
    unsigned char pad_0[0x8];
    float field_8;
};
struct UnkStruct_003BD760 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x6];
    UnkStruct_003BD760_ent * field_10;
    unsigned char pad_14[0x24];
    UnkStruct_003BD760_panel * field_38[9];
    CGt2dObject * field_5C[9];
    CGt2dObject * field_80[9];
    unsigned char pad_A4[0x8];
    unsigned short * field_AC[9];
    unsigned char pad_D0[0x8];
    CGt2dFrame * field_D8;
    int field_DC;
    unsigned char pad_E0[0x4];
    float field_E4;
};

extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, CGt2dFrame *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
extern "C" void Prepare__16CB3Panel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dbb(void *, const CGtV2d &, const CGtV2d &, const void *, bool, bool);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const CGtV2d &, const CGtV2d &, const void *, CGtV4d, CGtTexture *, const CGtV2d &, const CGtV2d &, unsigned int);
extern "C" void func_001D6C40(CGt2dObject *, const CGtV2d &, const CGtV2d &, float, CGtV4d, const CGt2dFont *, const unsigned short *);
extern "C" unsigned short * func_00271A00(void *, int);
extern "C" void PrintUInt__10CGtUnicodeFPUsUii(unsigned short *, unsigned int, int);
extern "C" unsigned short * Copy__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" unsigned short * Append__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" int Length__10CGtUnicodeFPCUs(const unsigned short *);
extern "C" int strcasecmp(const char *, const void *);

static inline void func_003BD760_inl1(UnkStruct_D_01E903E0 * scene, void ** pp, int layer, UnkStruct_003BD760 * self)  // [G] construct-if-null
{
    if (*pp == 0) *pp = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, layer, self->field_D8);
}

static inline CGtTexture * func_003BD760_inl2()  // [G] placeholder: an inlined find-texture-by-name
{
    UnkStruct_003BD760_2 * t0 = D_00518688.field_0;
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_003BD760_blk *)(t2 + 0x90))->field_18, &D_004CA2F8) == 0) {
            return (CGtTexture *)t2;
        }
    }
    return 0;
}

// 0x003BD760
extern "C" void func_003BD760(UnkStruct_003BD760 * self, int item, int value, float x)
{
    CB3MenuPageManager * const mgr = &D_01E90240;
    UnkStruct_D_01E903E0 * const scene = &D_01E903E0;
    unsigned short * text = 0;
    float ew;
    int off = item * 4;
    float tx = x + 5.0f;
    float ax = 0.0f;
    float y = 0.0f + self->field_E4 + 32.0f * (float)item;
    float ay;
    int lc = self->field_8 + 4;
    int lb = self->field_8 + 3;
    UnkStruct_003BD760_panel ** pp = (UnkStruct_003BD760_panel **)(off + (int)self->field_38);
    func_003BD760_inl1(scene, (void **)pp, self->field_8 + 2, self);
    if (self->field_10[item].field_D == 6) {
        ay = 0.5f;
        Prepare__16CB3Panel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dbb(*pp, CGtV2d(x, y), CGtV2d(0.0f, ay), &D_004CA2E8, true, true);
    } else {
        ay = 0.5f;
        Prepare__16CB3Panel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dbb(*pp, CGtV2d(x, y), CGtV2d(0.0f, ay), &D_004CA2D0, true, true);
    }
    int st;
    if (self->field_10[item].field_E)
        st = 2;
    else if (self->field_DC == item)
        st = 1;
    else
        st = 0;
    UnkStruct_003BD760_ent * e = &self->field_10[item];
    int type = e->field_D;
    if (type == 1 || type == 2) {
        text = (unsigned short *)e->field_8;
    } else if (type == 3) {
        text = ((unsigned short **)e->field_8)[value];
    } else if (type == 4) {
        text = func_00271A00(&D_0051BA44, ((int *)e->field_8)[value]);
    } else if (type == 5) {
        PrintUInt__10CGtUnicodeFPUsUii(self->field_AC[item], value, 1);
        text = self->field_AC[item];
    } else if (type == 6) {
        if (value == 0)
            text = func_00271A00(&D_0051BA44, 0x1BB);
        else
            text = func_00271A00(&D_0051BA44, 0x1BC);
        ax = 0.5f;
        tx = 0.0f + x + 0.5f * D_004CA2E8.field_0.marValues[0];
    } else if (type == 7) {
        CGt2dObject ** po = (CGt2dObject **)(off + (int)self->field_5C);
        func_003BD760_inl1(scene, (void **)po, lb, self);
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(*po, CGtV2d(tx, y), CGtV2d(0.0f, 0.5f), &D_004CA2D8, mgr->field_0[st], func_003BD760_inl2(), CGtV2d(0.0f, 0.5f), CGtV2d(0.9375f, 1.0f), 0);
        CGt2dObject ** pq = (CGt2dObject **)(off + (int)self->field_80);
        func_003BD760_inl1(scene, (void **)pq, lc, self);
        float w = 0.046875f * (float)value;
        if (st == 1) st = 0x11;
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(*pq, CGtV2d(tx, y), CGtV2d(0.0f, 0.5f), &CGtV2d(12.4f * (float)value, 16.0f), mgr->field_0[st], func_003BD760_inl2(), CGtV2d(0.0f, 0.0f), CGtV2d(w, 0.5f), 0);
        return;
    } else if (type == 8) {
        CGt2dObject ** po = (CGt2dObject **)(off + (int)self->field_5C);
        func_003BD760_inl1(scene, (void **)po, lb, self);
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(*po, CGtV2d(tx, y), CGtV2d(0.0f, 0.5f), &D_004CA2D8, mgr->field_0[st], func_003BD760_inl2(), CGtV2d(0.0f, 0.5f), CGtV2d(0.890625f, 1.0f), 0);
        CGt2dObject ** pq = (CGt2dObject **)(off + (int)self->field_80);
        func_003BD760_inl1(scene, (void **)pq, lc, self);
        if (st == 1) st = 0x11;
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(*pq, CGtV2d(0.0f + tx + 13.05263138f * (9.0f + (float)value), y), CGtV2d(0.0f, 0.5f), &D_004CA2E0, mgr->field_0[st], func_003BD760_inl2(), CGtV2d(0.0f, 0.0f), CGtV2d(0.046875f, 0.5f), 0);
        return;
    }
    if (text != 0 && *text != 0) {
        CGt2dObject ** po = (CGt2dObject **)(off + (int)self->field_5C);
        func_003BD760_inl1(scene, (void **)po, lb, self);
        float w = D_00665ED8.pFont->GetStringWidth(text);
        float avail = (*pp)->field_8 - 10.0f;
        unsigned short * buf = self->field_10[item].field_4;
        if (buf != 0 && w * 26.0f > avail) {
            Copy__10CGtUnicodeFPUsPCUs(buf, text);
            text = self->field_10[item].field_4;
            ew = 26.0f * D_00665ED8.pFont->GetStringWidth(D_004CA2F0.field_0);
            int n = Length__10CGtUnicodeFPCUs(text);
            float tw = 26.0f * D_00665ED8.pFont->GetStringWidth(text);
            while (n > 1 && tw + ew > avail) {
                n--;
                text[n] = 0;
                tw = 26.0f * D_00665ED8.pFont->GetStringWidth(text);
            }
            Append__10CGtUnicodeFPUsPCUs(text, D_004CA2F0.field_0);
        }
        func_001D6C40(*po, CGtV2d(tx, y), CGtV2d(ax, ay), 26.0f, mgr->field_0[st], D_00665ED8.pFont, text);
    } else {
        if (self->field_5C[item] != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, lb, self->field_5C[item]);
            self->field_5C[item] = 0;
        }
    }
}
