// NONMATCHING: func_0044E400 -- retail 1661 / ours 1659 instructions, 228 in changed runs
// fix3 (2026-11-01): D_01ECD9F0 layout: every field after field_38 0x10 high (retail D_01ECDA50..DAC6 = +0x60..+0xD6; the draft named them by the symbol suffix) | Before: draftQ+draftT: 1659/1661, 229 changed (was 404). draftQ: logic+block layout+frame exact; per-mode 'if (flags) { value = ..; break; }' first; colour CSE needs 'CB3MenuPageManager * const m = &D_01E90240' INSIDE the draw inline; 'float o = -30.0f; g + o'; draw inline takes the row index; D_01EA4690 padded. draftT: value text through an inlined Prepare wrapper (func_0044E400_inl5: by-value CGtV4d param, D_01E903C0 passed directly, render cb func_00453980) fixed the value-text schedule x12 (same fix as func_0044D6D0). Left: 2 instrs short; field_50 CSE'd from the sum into row 0x9D8 (retail reloads); stack-slot order of inlined temps
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] same calls/args/stores/CFG as retail; residue is scheduling, one CSE'd global reload and stack slots


// func_0044E400 -- hand-written from retail (not in the lifter's candidates). Same component family as
// func_0044D6D0 / func_0044D180 / func_0044CF90 (rows at self+0xC, stride 0x24; counters at 0x180/0x1A0;
// texts at 0x140). [L] memory-card/results breakdown page: per-mode value rows (mode 0: up to four flagged
// rows, mode 1: three rows + optional icon, mode 2: two rows + a multiplier caption), then a total row.
#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
using namespace GtMathPs2;
struct UnkStruct_0044E400_fr {
    CGtV2d field_0;
    CGtV2d field_8;
    CGtV4d field_10;
    unsigned char pad_20[0x18];
    UnkStruct_0044E400_fr * field_38;
};
struct UnkStruct_0044E400_txt {
    CGtV2d field_0;
    CGtV2d field_8;
    unsigned char pad_10[0x1C];
    int field_2C;
    CGtV2d field_30;
};
struct UnkStruct_0044E400_row {
    UnkStruct_0044E400_fr * field_0;
    UnkStruct_0044E400_fr * field_4;
    void * field_8;
    UnkStruct_0044E400_fr * field_C;
    UnkStruct_0044E400_fr * field_10[5];
};
struct UnkStruct_0044E400_row2 {
    UnkStruct_0044E400_fr * field_0;
    UnkStruct_0044E400_fr * field_4;
    void * field_8;
    UnkStruct_0044E400_fr * field_C;
    void * field_10;
    UnkStruct_0044E400_txt * field_14;
    void * field_18;
    UnkStruct_0044E400_fr * field_1C;
    UnkStruct_0044E400_fr * field_20;
};
union UnkStruct_0044E400_r {
    UnkStruct_0044E400_row a;
    UnkStruct_0044E400_row2 b;
};
struct UnkStruct_0044E400 {
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[2];
    UnkStruct_0044E400_r field_C[8];
    unsigned char pad_12C[0xC];
    int field_138;
    unsigned char pad_13C[4];
    const unsigned short * field_140[16];
    int field_180[8];
    int field_1A0[8];
};
struct UnkStruct_D_01ECD9F0 {
    unsigned char pad_0[0x28];
    int field_28[4];
    int field_38[3];
    unsigned char pad_44[0x1C];
    int field_60;
    int field_64;
    int field_68;
    unsigned char pad_6C[3];
    unsigned char field_6F;
    unsigned char pad_70[2];
    unsigned char field_72[4];
    unsigned char pad_76[2];
    int field_78;
    int field_7C;
    int field_80;
    unsigned char pad_84[0x52];
    unsigned char field_D6;
};  // fix3: offsets from retail's %hi/%lo(D_01ECDA50..D_01ECDAC6) = D_01ECD9F0 + 0x60..0xD6 [C]
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_4D3130 { CGtV2d field_0; unsigned char pad_8[8]; };
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_Pad16 D_0051BA44;
extern CB3MenuPageManager D_01E90240;
extern UnkStruct_D_int D_0051BF9C;
extern UnkStruct_D_01ECD9F0 D_01ECD9F0;
extern UnkStruct_D_4D3130 D_004D3130;
extern CGtV2d D_004D3180[2];
extern CGtV2d D_004D3190[2];
extern CGtV4d D_01E903C0;
extern int D_00665ED0[4];
struct UnkStruct_D_01EA4690 { void *field_0; unsigned char pad_4[0xC]; };  // [G] size: absolute addressing (N50)
extern UnkStruct_D_01EA4690 D_01EA4690;
extern "C" int func_0013B660(void *);
extern "C" int func_0013B570(void *);
extern "C" int func_0013B200(void *, unsigned long, int);
extern "C" int func_0042EE00(void *, int);
extern "C" void func_00453680(void *, int, int, int);
extern "C" void func_0044CF90(void *, int, float);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" UnkStruct_0044E400_fr * ConstructChild__10CGt2dFrameFv(void *);
extern "C" void func_0033D4E0(void *, const CGtV2d &, const CGtV2d &, float, const void *, void *, const void *, const CGtV2d *, int);
extern "C" void PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(void *, const CGtV2d &, const CGtV2d &, float, CGtV4d, void *, const void *, void *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, void *, const CGtV2d &, const CGtV2d &, unsigned int);
extern "C" void func_00453980(void *, const void *);

static inline void func_0044D6D0_inl1(UnkStruct_0044E400_fr *c, UnkStruct_0044E400_fr *p)
{
    if (c != 0) {
        c->field_0 = c->field_0 - p->field_0;
        c->field_38 = p;
    }
}

// the row's frame: centred on the row's background, every object re-parented to it
static inline void func_0044D6D0_inl3(UnkStruct_0044E400 *self)
{
    UnkStruct_0044E400_r *e2 = &self->field_C[self->field_138];
    CGtV2d p(e2->a.field_0->field_0.marValues[0] + 0.5f * e2->a.field_0->field_8.marValues[0], 0.0f);
    e2->a.field_C = ConstructChild__10CGt2dFrameFv(e2->a.field_8);
    e2->a.field_C->field_0 = p;
    func_0044D6D0_inl1(e2->a.field_4, e2->a.field_C);
    func_0044D6D0_inl1(e2->a.field_0, e2->a.field_C);
    int k = 0;
    do {
        func_0044D6D0_inl1(e2->a.field_10[k], e2->a.field_C);
        k++;
    } while (k < 5);
}

static inline void func_0044E400_inl5(UnkStruct_0044E400_txt *t, const CGtV2d &p0, const CGtV2d &p1, float p2, const CGtV4d p3, int p4, const unsigned short *p5)
{
    PrepareCommonData__21CGt2dObjectItalicTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(t, p0, p1, p2, p3, (void *)(p4), p5, (void *)func_00453980);
    t->field_30 = D_004D3130.field_0 / t->field_8;
    t->field_2C = 0;
}

// label at the row's left edge, value text right-aligned at its right edge
static inline UnkStruct_0044E400_r *func_0044E400_inl2(UnkStruct_0044E400 *self, int idx, const unsigned short *label, const unsigned short *txt)
{
    UnkStruct_0044E400_r *e = &self->field_C[idx];
    CB3MenuPageManager * const m = &D_01E90240;
    float z = 0.0f;
    float f = 30.0f + (e->b.field_0->field_0.marValues[0] + z * e->b.field_0->field_8.marValues[0]);
    e->b.field_10 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E90240.field_1A0, self->field_8 + 2, e->b.field_8);
    func_0033D4E0(e->b.field_10, CGtV2d(f, 0.0f), CGtV2d(0.0f, 0.5f), 22.0f, &m->field_0[1], (void *)(D_00665ED0[0]), label, &D_004D3130.field_0, 2);
    if (txt != 0) {
        float g = e->b.field_0->field_0.marValues[0] + e->b.field_0->field_8.marValues[0];
        e->b.field_14 = (UnkStruct_0044E400_txt *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E90240.field_1A0, self->field_8 + 2, e->b.field_8);
        float o = -30.0f;
        func_0044E400_inl5(e->b.field_14, CGtV2d(g + o, 0.0f), CGtV2d(1.0f, 0.5f), 36.0f, D_01E903C0, D_00665ED0[0], txt);
    }
    return e;
}

// a value row: counter target 0, current value; label text id
static inline UnkStruct_0044E400_r *func_0044E400_inl1(UnkStruct_0044E400 *self, int value, int id, int a, int b, const CGtV4d *col1)
{
    int idx = self->field_138;
    self->field_180[idx] = 0;
    self->field_1A0[idx] = value;
    func_0044CF90(self, idx, 0.0f);
    const unsigned short *txt = self->field_140[idx];
    func_00453680(self, idx, a, b);
    const unsigned short *label = func_00271A00(&D_0051BA44, id);
    return func_0044E400_inl2(self, idx, label, txt);
}

static inline void func_0044E400_inl4(UnkStruct_0044E400_r *e, UnkStruct_0044E400 *self, const CGtV2d *uv)
{
    float x = e->b.field_0->field_0.marValues[0];
    e->b.field_18 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E90240.field_1A0, self->field_8 + 2, e->b.field_8);
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(e->b.field_18, CGtV2d(x, 0.0f), CGtV2d(0.5f, 0.5f), CGtV2d(64.0f, 64.0f), D_01E90240.field_110, D_01EA4690.field_0, uv[0], uv[1], 0);
}

// 0x0044E400
extern "C" void func_0044E400(UnkStruct_0044E400 *self, int mode)
{
    int t0 = D_0051BF9C.field_0;
    const CGtV2d *uv2 = 0;
    int value = 0;
    switch (mode) {
    default: {
        if (D_01ECD9F0.field_6F != 0 || D_01ECD9F0.field_D6 != 0) {
            value = func_0013B660((void *)(t0)) - D_01ECD9F0.field_78;
            break;
        }
        int i = 0;
        do {
            if (D_01ECD9F0.field_72[i] != 0) {
                value += D_01ECD9F0.field_28[i];
            }
            i++;
        } while (i < 4);
        if (D_01ECD9F0.field_72[0] != 0) {
            func_0044E400_inl1(self, D_01ECD9F0.field_28[0], 0x9F1, 7, 2, &D_01E90240.field_0[1]);
            self->field_138++;
        }
        if (D_01ECD9F0.field_72[1] != 0) {
            func_0044E400_inl1(self, D_01ECD9F0.field_28[1], 0x9F2, 7, 2, &D_01E90240.field_0[1]);
            self->field_138++;
        }
        if (D_01ECD9F0.field_72[2] != 0) {
            func_0044E400_inl1(self, D_01ECD9F0.field_28[2], 0x9F4, 7, 2, &D_01E90240.field_0[1]);
            self->field_138++;
        }
        if (D_01ECD9F0.field_72[3] != 0) {
            func_0044E400_inl1(self, D_01ECD9F0.field_28[3], 0x9F3, 7, 2, &D_01E90240.field_0[1]);
            self->field_138++;
        }
        break;
    }
    case 1: {
        const CGtV2d *uv = 0;
        if (D_01ECD9F0.field_6F != 0 || D_01ECD9F0.field_D6 != 0) {
            value = func_0013B200((void *)(t0), 0, 1) + func_0013B200((void *)(t0), 0, 0) - D_01ECD9F0.field_7C;
            break;
        }
        if (func_0042EE00(&D_01ECD9F0, 2) > 0) {
            uv = D_004D3190;
        }
        int i = 0;
        do {
            value += D_01ECD9F0.field_38[i];
            i++;
        } while (i < 3);
        func_0044E400_inl1(self, D_01ECD9F0.field_38[0], 0x9F8, 7, 2, &D_01E90240.field_0[1]);
        self->field_138++;
        UnkStruct_0044E400_r *e = func_0044E400_inl1(self, D_01ECD9F0.field_38[1], 0x9F9, 7, 2, &D_01E90240.field_0[1]);
        if (uv != 0) {
            func_0044E400_inl4(e, self, uv);
        }
        self->field_138++;
        func_0044E400_inl1(self, D_01ECD9F0.field_38[2], 0x9FA, 7, 2, &D_01E90240.field_0[1]);
        self->field_138++;
        break;
    }
    case 2: {
        if (D_01ECD9F0.field_6F != 0 || D_01ECD9F0.field_D6 != 0) {
            value = func_0013B570((void *)(t0)) - D_01ECD9F0.field_80;
            break;
        }
        if (func_0042EE00(&D_01ECD9F0, 5) > 0) {
            uv2 = D_004D3180;
        }
        value = D_01ECD9F0.field_60 + D_01ECD9F0.field_64;
        switch (D_01ECD9F0.field_68) {
        case 4:
            value /= 2;
            break;
        case 6:
            value *= 4;
            break;
        case 5:
            value *= 2;
            break;
        }
        func_0044E400_inl1(self, D_01ECD9F0.field_60, 0x9D8, 7, 2, &D_01E90240.field_0[1]);
        self->field_138++;
        func_0044E400_inl1(self, D_01ECD9F0.field_64, 0x9D9, 7, 2, &D_01E90240.field_0[1]);
        self->field_138++;
        int id;
        switch (D_01ECD9F0.field_68) {
        case 4:
            id = 0x9E0;
            break;
        case 6:
            id = 0x9DF;
            break;
        case 5:
            id = 0x9DE;
            break;
        default:
            id = 0x9E1;
            break;
        }
        const unsigned short *txt = func_00271A00(&D_0051BA44, id);
        int idx = self->field_138;
        func_00453680(self, idx, 8, 2);
        const unsigned short *label = func_00271A00(&D_0051BA44, 0x2F1);
        func_0044E400_inl2(self, idx, label, txt);
        self->field_138++;
        break;
    }
    }
    UnkStruct_0044E400_r *e = func_0044E400_inl1(self, value, 0x9EF, 9, 0, &D_01E90240.field_0[1]);
    if (uv2 != 0) {
        func_0044E400_inl4(e, self, uv2);
    }
    func_0044D6D0_inl3(self);
    self->field_138++;
}
