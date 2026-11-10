// NONMATCHING: func_003B0870 -- retail 523 / ours 513 instructions, 428 in changed runs
// fix3 (2026-11-01): star icon shown when the entry's field_10 != 0 and icon != 0x3B (draft hid it); CGt2dObjectImage::Prepare gets retail's 9th stack argument 0 (N68) at both calls | Before: son9 first archive (523/511 instrs, 501 changed): logic/control flow/calls complete (race/crash challenge pick, 3 Gt2d children); left: s-register/t-register allocation of the nested search loops (loop index regs a3/t1 etc.), frame 0x140 vs 0x100 (CGtV2d arg temps: retail keeps separate stack slots per Prepare call), 64-bit hash compare constants via pcpyld in retail, globals declared as placeholders by address (D_004E2E98 is gp-rel guess)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)
// w64 (2026-11-02): callee prototypes set to the callees' own scalar widths (docs/known.md N293); behaviour_audit unchanged.


// func_003B0870 -- son9 first archive. SatNav-style challenge icon/label update: picks the next challenge (race or crash list),
// builds three CGt2dObject children (icon image, flash text, optional star image). Layout [G] from instruction widths;
// every global is a placeholder named by address.
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

enum EB3TrackRegion {};

struct UnkStruct_003B0870 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_003B0870_cfg {
    unsigned char pad_0[4];
    UnkStruct_003B0870_cfg * field_4_dummy;
};
struct UnkStruct_003B0870_cell {
    unsigned char pad_0[0x34];
    struct { unsigned char pad_0[8]; unsigned long field_8; } * field_34;
    unsigned char pad_38[8];
};
struct UnkStruct_003B0870_slot {
    unsigned char pad_0[0x10];
    UnkStruct_003B0870_cell * field_10;
    int field_14;
};
struct UnkStruct_003B0870_row {
    UnkStruct_003B0870_slot * field_0;
    int field_4;
};
struct UnkStruct_D_00518690 {
    unsigned char pad_0[4];
    UnkStruct_003B0870_row * field_4;
    int field_8;
};
struct UnkStruct_003EA1D0 {
    unsigned char pad_0[0x10];
    unsigned long field_10;
    unsigned char pad_18[0x18];
    int field_30;
};

extern UnkStruct_003B0870 D_01E88B94[];
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern int D_01E891FC;
extern short D_01E88AF8;
extern long * D_01EA2974;
extern unsigned char D_01E893D6;
extern unsigned char D_01E893D7;
extern unsigned char D_01E893D4;
extern int D_01E891F0;
extern int D_01E894A4;
extern UnkStruct_D_00518690 * D_00518690;
extern int D_01E88D44;
extern int D_01E88D54;
extern int D_01E88D3C;
extern int D_01E891BC[];
extern int D_01E89034[];
extern int D_01E893CC;
extern int D_01E894AC[];
extern signed char D_004E2E98;
extern int D_01E903E0;
extern unsigned char D_01E90240[];
extern unsigned char D_01E90350[];
extern void * D_01EA4470[];
extern void * D_01EA4564;
extern CGtV2d D_01EA4790;
extern CGtV2d D_01EA4798;
extern void * D_00665ED0;
extern unsigned char D_0051BA44[];

extern "C" unsigned long GetStageGtID__25CB3HardCodedRaceStageListFii(int, int);
extern "C" int IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni(int, int);
extern "C" int IsChallengeOnThisCircuit__25CB3HardCodedRaceStageListF14EB3TrackRegionii(int, int, int);
extern "C" int IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(int, int);
extern "C" int IsChallengeOnThisCircuit__26CB3HardCodedCrashStageListF14EB3TrackRegionii(int, int, int);
extern "C" int GetChallengeType__25CB3HardCodedRaceStageListFi(int);
extern "C" int func_003F5E40(unsigned long);
extern "C" int func_003E9C90(int, int);
extern "C" int func_003E9490(int, int);
extern "C" int func_0013AD30(void *, int, int);
extern "C" int func_0013AD70(void *, int, int);
extern "C" UnkStruct_003EA1D0 * func_003EA1D0(int);
extern "C" int func_00271A00(void *, int);
extern "C" void * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const CGtV2d *, const CGtV2d *, const CGtV2d *, CGtV4d, void *, const CGtV2d *, const CGtV2d *, unsigned int);   // fix3: + retail's stack argument (N68; sd $zero, 0($sp) at 0x3B0E88 / 0x3B0F9C)
extern "C" void Prepare__20CB3FlashText2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsRCQ29GtMathPs26CGtV2d(void *, const CGtV2d *, const CGtV2d *, float, CGtV4d, void *, unsigned long, const CGtV2d *);

// 0x003B0870
extern "C" void func_003B0870(UnkStruct_003B0870 * self, long flag, float x)
{
    unsigned int idx = ((unsigned int)((char *)self - (char *)D_01E88B94)) >> 4;
    CGtV2d zero(0.0f, 0.5f);
    int t0 = D_0051BF9C.field_0;
    float ypos = (float)idx * 33.5f + 144.0f;
    float fl;
    if (flag != 0) {
        D_01E891FC = 0;
        fl = 21.0f;
    } else {
        fl = 19.0f;
    }
    unsigned int flagi = flag != 0;
    bool ok = false;
    int sprite = D_01E88AF8 + 0x13;
    int sprite2 = D_01E88AF8 + 0x14;
    long id;
    if (D_01EA2974 == 0) id = 0x6D6123044330FCCFL;
    else id = *D_01EA2974;
    int label = 0;
    if (id == (long)0x94413FC15F5A6380UL
        || ((D_01EA2974 == 0 ? 0x6D6123044330FCCFL : *D_01EA2974) == (long)0x9441407F0FDC9797UL)) {
        if (D_01E893D6 == 0) return;
    }
    if (D_01E893D7 == 0) {
        int a = D_01E891F0;
        int b = D_01E894A4;
        if (D_01E893D6 == 0) {
            for (; a < 0x49; a++) {
                unsigned long gid = GetStageGtID__25CB3HardCodedRaceStageListFii(a, 0);
                bool hit = false;
                for (int r = 0; r < D_00518690->field_8; r++) {
                    UnkStruct_003B0870_row * row = &D_00518690->field_4[r];
                    for (int c = 0; c < row->field_4; c++) {
                        UnkStruct_003B0870_slot * s = &row->field_0[c];
                        for (int k = 0; k < s->field_14; k++) {
                            if (s->field_10[k].field_34->field_8 == gid) { hit = true; break; }
                        }
                        if (hit) break;
                    }
                    if (hit) break;
                }
                if (hit && IsCorrectRegion__25CB3HardCodedRaceStageListF14EB3TrackRegioni(D_01E88D44, a) != 0
                    && IsChallengeOnThisCircuit__25CB3HardCodedRaceStageListF14EB3TrackRegionii(D_01E88D44, a, D_01E88D54) != 0) {
                    int ct = GetChallengeType__25CB3HardCodedRaceStageListFi(a);
                    ok = true;
                    if (func_003F5E40(GetStageGtID__25CB3HardCodedRaceStageListFii(a, 0)) == 0) {
                        D_01E891BC[idx] = func_003E9C90(a, D_01E89034[ct]);
                    } else {
                        D_01E891BC[idx] = 0x9BE;
                    }
                    label = D_01E891BC[idx];
                    D_01E891F0 = a + 1;
                    self->field_C = a;
                    if (D_01E893D4 == 5) D_01E89034[ct]++;
                    break;
                }
            }
        } else {
            for (; b < 100; b++) {
                if (IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(D_01E88D44, b) != 0
                    && IsChallengeOnThisCircuit__26CB3HardCodedCrashStageListF14EB3TrackRegionii(D_01E88D44, b, D_01E88D54) != 0) {
                    ok = true;
                    label = func_003E9490(b, 1);
                    self->field_C = b;
                    if (D_01E893D4 == 5 && (D_01E893CC++, D_004E2E98 == 0)) {
                        D_01E894AC[D_01E893CC] = b;
                        D_01E894AC[0] = D_01E893CC;
                    }
                    D_01E891F0 = b + 1;
                    D_01E894A4 = D_01E891F0;
                    break;
                }
            }
        }
    } else {
        ok = true;
        if (D_01E893D6 == 0) {
            GetChallengeType__25CB3HardCodedRaceStageListFi(self->field_C);
            label = D_01E891BC[idx];
            if (label == 0) ok = false;
        } else {
            label = func_003E9490(self->field_C, 1);
        }
    }
    if (!ok) {
        if (self->field_0 != 0) { DestructObject__10CGt2dSceneFiP11CGt2dObject(&D_01E903E0, sprite, (void *)self->field_0); self->field_0 = 0; }
        if (self->field_4 != 0) { DestructObject__10CGt2dSceneFiP11CGt2dObject(&D_01E903E0, sprite, (void *)self->field_4); self->field_4 = 0; }
        if (self->field_8 == 0) return;
        DestructObject__10CGt2dSceneFiP11CGt2dObject(&D_01E903E0, sprite2, (void *)self->field_8);
        self->field_8 = 0;
        return;
    }
    int icon;
    long st = func_0013AD30((void *)(t0), self->field_C, D_01E893D6 == 0);
    if (st == 3) icon = 0x3B;
    else if (st == 2) icon = 0x3A;
    else if (st == 1) icon = 0x39;
    else if (func_0013AD70((void *)(t0), self->field_C, D_01E893D6 == 0) == 0) icon = 0x38;
    else icon = 0x3E;
    if (self->field_4 == 0) self->field_4 = (int)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, sprite, (void *)D_01E88D3C);
    CGtV2d sz(26.0f, 26.0f);
    CGtV2d pos(x + 21.0f, ypos);
    Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d((void *)self->field_4, &pos, &zero, &sz, *(CGtV4d *)D_01E90350, D_01EA4470[icon], &D_01EA4790, &D_01EA4798, 0);
    if (self->field_0 == 0) self->field_0 = (int)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, sprite, (void *)D_01E88D3C);
    CGtV2d sc(3.0f, 3.0f);
    unsigned long txt = func_00271A00(D_0051BA44, label);
    CGtV2d tp(x + 52.0f, ypos);
    Prepare__20CB3FlashText2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsRCQ29GtMathPs26CGtV2d((void *)self->field_0, &tp, &zero, fl, *(CGtV4d *)(D_01E90240 + flagi * 0x10), D_00665ED0, txt, &sc);
    UnkStruct_003EA1D0 * r = func_003EA1D0(self->field_C);
    if (D_01E893D6 == 0 && r != 0 && icon != 0x3E) {
        int v;
        bool show;
        if (r->field_10 == 0) {
            v = r->field_30;
            show = !(v != 2 || icon != 0x38);
        } else if (icon == 0x3B) {
            v = r->field_30;
            show = !(v != 2 || icon != 0x38);
        } else {
            show = true;   // fix3 [C] retail 0x3B102C: field_10 != 0 and icon != 0x3B -> 0x3B0F60 (the star is shown)
        }
        if (show) {
            CGtV4d col = *(CGtV4d *)D_01E90350;
            col.SetA(0.0f);
            if (self->field_8 == 0) self->field_8 = (int)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, sprite2, (void *)D_01E88D3C);
            CGtV2d p2(x + 21.0f, ypos);
            Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d((void *)self->field_8, &p2, &zero, &sz, col, D_01EA4564, &D_01EA4790, &D_01EA4798, 0);
            return;
        }
    }
    if (self->field_8 != 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(&D_01E903E0, sprite2, (void *)self->field_8);
        self->field_8 = 0;
    }
}
