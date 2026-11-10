// NONMATCHING: UpdateMessage__20CB3HUDPrimaryMessageFf -- retail 354 / ours 359 instructions, 118 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: a153: logic complete (359 vs 354 instrs, 118 changed). Declaration-order sweep of s-regs found (s1,s0,s7,ev,s5,s6,s4)=0142653 order (included). Left: (1) the _kaEventMap find loop: retail keeps 'li v1,206; beqz v1; addiu a2,v1,-1' (count not folded) and a 'bnez a1 -> find; b join; move s3,zero' stub
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// UpdateMessage__20CB3HUDPrimaryMessageFf -- hand-matched (a153).
#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;

enum EHUDAlign {};

class CB3HUD {
public:
    int IsDoingTransition();
    CGtV2d GetAlignPos(EHUDAlign);
    CGtV2d GetHandlePosition(const CGtV2d &);

    unsigned char pad_0[0x70];
};

struct UnkStruct_003D8280_hud {
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x168];
    int field_170;
};

struct UnkStruct_003D8280_arr {
    CB3HUD field_0[1];
};

struct UnkStruct_003D8280_sc {
    unsigned char pad_0[0x8];
    int field_8;
    float field_C;
    unsigned char pad_10[0x124];
    unsigned char field_134;
    unsigned char pad_135[0x11F];
    int field_254;
    int field_258;
    int field_25C;
    int field_260;
};

struct UnkStruct_003D8280_frame { unsigned char pad_0[0x8]; float field_8; float field_C; };

struct UnkStruct_003D8280_ev { unsigned char field_0; unsigned char field_1; unsigned short field_2; };

struct UnkStruct_D_01E7A800 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };

struct UnkStruct_003D8280 {
    unsigned char pad_0[0x4];
    UnkStruct_003D8280_arr * field_4;
    UnkStruct_003D8280_frame * field_8;
    unsigned char pad_C[0x14];
    int field_20;
    UnkStruct_003D8280_sc * field_24;
    void * field_28;
    unsigned char pad_2C[0x14];
    unsigned char field_40[0x0C];
    int field_4C;
    unsigned char pad_50[0x140];
    float field_190;
    float field_194;
};

extern UnkStruct_003D8280_ev _kaEventMap[0xCE];
extern UnkStruct_D_01E7A800 D_01E7A800;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_004EE040 D_004EE040;

extern "C" bool func_00131E40(void *);
extern "C" void ShowScore__11CB3HUDScoreFQ211CB3HUDScore11EScoreEventi(void *, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003D56D0(void *, CGtV2d *, void *, void *, int, int, int, int, unsigned long, unsigned long);
extern "C" void func_00285C00(void *, int, int, int);
extern "C" void ClearMessage__27CB3HUDPrimaryMessageHandlerFb(void *, bool);

static inline UnkStruct_003D8280_ev * func_003D8280_inl1(int id)
{
    int n = 0xCE;
    int i;
    int old;
    UnkStruct_003D8280_ev * e;
    if (n != 0) {
        i = n - 1;
        do {
            e = &_kaEventMap[i];
            if (id == e->field_0) return e;
            old = i;
            i = i - 1;
        } while (old != 0);
    }
    return 0;
}

extern "C" void UpdateMessage__20CB3HUDPrimaryMessageFf(UnkStruct_003D8280 * self, float p0)
{
    int s1;
    bool s0;
    int s5;
    int s7;
    int s4;
    int s6;
    UnkStruct_003D8280_ev * s3;
    UnkStruct_003D8280_sc * sc;
    UnkStruct_003D8280_hud * h;
    int mode;
    int v0;
    CGtV2d pos;
    s1 = 0;
    s0 = func_00131E40(&D_004EE040);
    s7 = 0;
    sc = self->field_24;
    if (sc->field_C < 0.01f || sc->field_8 != 0 || self->field_4->field_0[self->field_20].IsDoingTransition() != 0) return;
    sc = self->field_24;
    if (sc->field_134 != 0) {
        int a1 = sc->field_254;
        if (a1 == 0) s3 = 0;
        else s3 = func_003D8280_inl1(a1);
    } else {
        s3 = 0;
    }
    if (s3 == 0) return;
    h = (UnkStruct_003D8280_hud *)&self->field_4->field_0[self->field_20];
    mode = h->field_4;
    if (((unsigned char *)self->field_4)[0xE0] != 0 && !s0 && (unsigned)(mode - 2) < 2) {
        switch (s3->field_1) {
        case 12:
        case 11:
        case 10:
        case 3:
        case 4:
            goto set1;
        default:
            return;
        }
    }
    {
        bool act = self->field_4C != 0;
        if (act) {
            if (s0) goto clear1;
            if (self->field_190 < self->field_194) return;
            goto clear2;
        }
    }
zero:
    v0 = 0;
test:
    if (v0 != 0) {
        if ((unsigned)(s3->field_1 - 3) < 2) {
            s0 = false;
            CGtV2d r1 = self->field_4->field_0[self->field_20].GetAlignPos((EHUDAlign)1);
            pos = r1;
            pos.SetX(pos.X() + 64.0f);
            pos.SetY(pos.Y() + -4.0f);
        } else {
            CGtV2d r2 = self->field_4->field_0[self->field_20].GetAlignPos((EHUDAlign)1);
            s7 = 1;
            pos = r2;
            pos.SetX(pos.X() + 48.0f);
            pos.SetY(pos.Y() + -4.0f);
        }
    } else {
        s0 = true;
        if (((UnkStruct_003D8280_hud *)self->field_4)->field_170 != 2) {
            CGtV2d hp1(0.5f, 0.23f);
            CGtV2d r5 = self->field_4->field_0[self->field_20].GetHandlePosition(hp1);
            pos = r5;
        } else if (s3->field_1 == 3) {
            CGtV2d r3 = self->field_4->field_0[self->field_20].GetAlignPos((EHUDAlign)1);
            s0 = false;
            pos = r3;
            pos.SetX(pos.X() + 64.0f);
            pos.SetY(pos.Y() + -4.0f);
        } else {
            CGtV2d hp2(0.5f, 0.15f);
            CGtV2d r4 = self->field_4->field_0[self->field_20].GetHandlePosition(hp2);
            pos = r4;
        }
    }
    s6 = s3->field_2;
    switch (s3->field_1) {
    case 3:
        s5 = 7;
        break;
    case 4:
        s5 = 6;
        break;
    case 5:
    case 6:
        s5 = 0;
        break;
    case 7:
    case 8:
        s5 = 0;
        break;
    case 9:
        s5 = 1;
        break;
    case 10:
        s5 = 5;
        break;
    case 11:
        s5 = 4;
        break;
    case 12:
        s5 = 3;
        break;
    case 13:
        s1 = self->field_24->field_260;
        s5 = 2;
        if (s3->field_0 == 0x75) {
            s6 = s6 + s1;
            s1 = s1 + 1;
        }
        break;
    case 15:
        s5 = 9;
        break;
    case 16:
        s5 = 10;
        break;
    case 17:
        s5 = 11;
        break;
    case 18:
        s5 = 12;
        break;
    case 19:
        s5 = 13;
        break;
    case 20:
        s5 = 8;
        break;
    case 21:
        s5 = 14;
        break;
    case 22:
        s5 = 15;
        break;
    case 23:
        s5 = 16;
        break;
    default:
        s5 = 0;
        break;
    }
    s4 = self->field_24->field_258;
    if (self->field_28 == 0 || s4 == 0) {
        s4 = 0;
    } else {
        ShowScore__11CB3HUDScoreFQ211CB3HUDScore11EScoreEventi(self->field_28, 1, s4);
        ShowScore__11CB3HUDScoreFQ211CB3HUDScore11EScoreEventi(self->field_28, 1, 0);
    }
    pos.SetX(pos.X() / self->field_8->field_8);
    pos.SetY(pos.Y() / self->field_8->field_C);
    int text = func_00271A00(&D_0051BA44, s6);
    func_003D56D0(self->field_40, &pos, self->field_8, (void *)(text), s5, s4, s1, s0, 0, s7);
    func_00285C00(&D_01E7A800, s3->field_1, s3->field_0, s1);
    sc = self->field_24;
    sc->field_254 = 0;
    sc->field_258 = 0;
    sc->field_25C = 0;
    sc->field_134 = 0;
    return;
set1:
    v0 = 1;
    goto test;
clear1:
    ClearMessage__27CB3HUDPrimaryMessageHandlerFb(self->field_40, true);
    v0 = 0;
    goto test;
clear2:
    ClearMessage__27CB3HUDPrimaryMessageHandlerFb(self->field_40, true);
    goto zero;
}
