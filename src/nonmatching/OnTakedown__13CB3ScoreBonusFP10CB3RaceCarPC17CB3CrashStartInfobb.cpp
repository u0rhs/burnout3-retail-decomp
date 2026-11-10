// NONMATCHING: OnTakedown__13CB3ScoreBonusFP10CB3RaceCarPC17CB3CrashStartInfobb -- retail 396 / ours 395 instructions, 18 in changed runs
// fix3 (2026-11-01): GetUnitOriginalID gets its int argument (the player's signed byte +0x216, retail a1); the draft passed the track only [C] retail 0x3689C4, matched callee 0x302610 | Before: near28: 24 off (was 38). The e->field_4<0 found block as goto fneg placed before the field_7 test (retail's out-of-line block, exact now); 'tid == e->field_8' operand order. Left: first-loop e/offset s6/s7 swap, the shared far 'b; addiu s5' continue stub (goto-form loop + inc1 after return made it worse), 2nd loop pl/a regs (v0/a1), spree OnEvent arg order | N274 GtMath::Min (gapJ)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


#include "b3/GtMath.h"
#include "b3/GtMathPs2Quat.h"
// NONMATCHING: OnTakedown__13CB3ScoreBonusFP10CB3RaceCarPC17CB3CrashStartInfobb -- retail 396 / ours 395 instructions, 24 in changed runs
// near28: 24 off (was 38). The e->field_4<0 found block as goto fneg placed before the field_7 test (retail's out-of-line block, exact now); 'tid == e->field_8' operand order. Left: first-loop e/offset s6/s7 swap, the shared far 'b; addiu s5' continue stub (goto-form loop + inc1 after return made it worse), 2nd loop pl/a regs (v0/a1), spree OnEvent arg order
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

extern "C" int OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(void *, int, int, int, bool);
extern "C" void AddScore__8CB3ScoreFii(void *, int, int, int);
extern "C" int GetUnitOriginalID__16CB3StreamedTrackFi(void *, int);   // fix3: (this, int) [C] retail 0x3689C4 lb a1, 0x216(v0); src/b3 B3StreamedTrack_00302610 reads p0
extern "C" int FindTrack__21CB3HardCodedTrackListFUl(unsigned long);
extern "C" int func_003EAA60(void *);
extern "C" int gmnTakedownBP__8CB3Score;
extern "C" int gmnAftertouchTakedownBP__8CB3Score;
extern "C" int gmnPsycheOutBP__8CB3Score;
extern "C" int gmnRevengeBP__8CB3Score;
extern "C" float gmrDoubleTakedownTime__8CB3Score;
extern "C" float gmrSpreeTakedownTime__8CB3Score;
extern "C" int gmanDoubleTakedownBP__8CB3Score[4];
extern "C" int gmanSpreeTakedownBP__8CB3Score[4];
struct UnkStruct_a169_tbl { unsigned char pad_0[0x10]; unsigned char field_10[8]; };
extern "C" UnkStruct_a169_tbl _kaaeBadSlamTypeEvents;
struct UnkStruct_D_0064D3A0 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064D3A0 D_0064D3A0;
struct UnkStruct_D_0064D370 { unsigned long field_0; unsigned char pad_8[0x8]; };
extern UnkStruct_D_0064D370 D_0064D370;
struct UnkStruct_a169_trk { unsigned long field_0[1]; unsigned char pad_8[8]; };
extern UnkStruct_a169_trk D_0055B7D0;
struct UnkStruct_a169_e1 { int field_0; int field_4; unsigned long field_8; int field_10; int field_14; };
extern UnkStruct_a169_e1 D_004C7FA0[];
extern int D_004C7FB0[];
struct UnkStruct_a169_b8 { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_a169_b8 D_004C7B78[];
struct UnkStruct_a169_e2 { unsigned long field_0; unsigned char field_8; unsigned char field_9; unsigned char field_A; unsigned char pad_B[5]; };
extern UnkStruct_a169_e2 D_004C7B70[];
struct UnkStruct_a169_sc { unsigned char pad_0[0x12A348]; unsigned char field_12A348[0x1CC]; };
extern UnkStruct_a169_sc D_00522660;
struct UnkStruct_a169_info { unsigned char field_0; unsigned char field_1; unsigned char pad_2[6]; void *field_8; };
struct UnkStruct_a169_x { unsigned char pad_0[0x2429]; unsigned char field_2429; };
struct UnkStruct_a169_z { unsigned char pad_0[0x2424]; UnkStruct_a169_x *field_2424; };
struct UnkStruct_a169_w { unsigned char pad_0[0xC]; UnkStruct_a169_z *field_C; };
struct UnkStruct_a169_vic {
    unsigned char pad_0[0x16C];
    UnkStruct_a169_w *field_16C;
    unsigned char pad_170[1];
    unsigned char field_171;
    unsigned char pad_172[1];
    signed char field_173;
    unsigned char pad_174[2];
    unsigned char field_176;
    unsigned char pad_177[0x15BC - 0x177];
    unsigned char field_15BC;
    unsigned char pad_15BD[0x19AC - 0x15BD];
    signed char field_19AC;
};
struct UnkStruct_a169_pl { unsigned char pad_0[0x216]; signed char field_216; signed char field_217; };
struct UnkStruct_a169_g {
    unsigned char pad_0[0x10CC]; float field_10CC;
    unsigned char pad_10D0[0x1168 - 0x10D0]; int field_1168;
    unsigned char pad_116C[0x10]; int field_117C; int field_1180; int field_1184;
    unsigned char pad_1188[0x1679 - 0x1188]; unsigned char field_1679[1];
};
struct UnkStruct_a169 {
    unsigned char pad_0[6];
    unsigned char field_6;
    unsigned char field_7;
    unsigned char field_8;
    unsigned char field_9;
    unsigned char pad_A[2];
    int field_C;
    unsigned char pad_10;
    bool field_11;
    unsigned char pad_12[0xE6];
    float field_F8[6];
    float field_110;
    int field_114;
    float field_118;
    int field_11C;
    unsigned char pad_120[8];
    int field_128;
    int field_12C;
    unsigned char pad_130[0x18];
    UnkStruct_a169_g *field_148;
};
static inline int a169_pminw(int a, int b) { int r; asm("pminw %0,%1,%2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline int a169_pextlw0(int a) { int r; asm("pextlw %0,$0,%1" : "=r"(r) : "r"(a)); return r; }
extern "C" void OnTakedown__13CB3ScoreBonusFP10CB3RaceCarPC17CB3CrashStartInfobb(UnkStruct_a169 *self, UnkStruct_a169_vic *car, const UnkStruct_a169_info *info, bool p2, bool p3)
{
    float t = self->field_148->field_10CC;
    bool isX = D_0064D3A0.field_0 == 1;
    if (info) {
        self->field_9 = info->field_0;
        self->field_C = (int)info->field_8;
    } else {
        self->field_9 = 0;
        self->field_C = 0;
    }
    self->field_7 = p2;
    self->field_8 = p3;
    self->field_6 = self->field_148->field_1679[car->field_19AC];
    self->field_F8[car->field_19AC] = t;
    bool found;
    int i;
    int ev = 0x93;
    int bp = gmnTakedownBP__8CB3Score;
    if (self->field_8 != 0) {
        int idx = (GtMath::Min(self->field_128, 4));
        self->field_128 = *(const int *)&self->field_128 + 1;
        int e = _kaaeBadSlamTypeEvents.field_10[idx];
        self->field_148->field_117C = self->field_148->field_117C + 1;
        bp = gmnAftertouchTakedownBP__8CB3Score;
        OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(self, e, bp, 3, 1);
    } else {
        found = false;
        if (info) {
            if (info->field_0 == 0) {
                if (info->field_1 != 0) {
                    car = (UnkStruct_a169_vic *)info->field_8;
                    switch (car->field_173) {
                    case 1: ev = 0x94; break;
                    case 2: ev = 0x95; break;
                    case 3: ev = 0x96; break;
                    case 4: ev = 0x97; break;
                    case 5: ev = 0x98; break;
                    case 7: ev = 0x99; break;
                    case 8: ev = 0x9A; break;
                    case 9: ev = 0x9B; break;
                    case 11: ev = 0x9C; break;
                    }
                    if (isX) {
                        if (*(const signed char *)&car->field_173 == 4) {
                            UnkStruct_a169_x *x = car->field_16C->field_C->field_2424;
                            if (x) {
                                car = (UnkStruct_a169_vic *)((char *)&D_00522660 + x->field_2429 * 0x180 + 0x175B0);
                            }
                        }
                        unsigned long tid = D_0055B7D0.field_0[car->field_176];
                        int fp = FindTrack__21CB3HardCodedTrackListFUl(D_0064D370.field_0);
                        if (fp != -1) {
                            for (i = 0; i < 8; i++) {
                                UnkStruct_a169_e1 *e = &D_004C7FA0[i];
                                int e0 = e->field_0;
                                if (e0 == func_003EAA60((void *)(fp)) && tid == e->field_8) {
                                    if (e->field_4 < 0) goto fneg;
                                    if (car->field_171 == (e->field_4 & 0xFF)) {
                                        bp = 0x5DC;
                                        ev = *(int *)((char *)D_004C7FB0 + i * 24);
                                        found = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                ev = 0x9D;
                if (isX && car->field_15BC == 1) {
                    for (int i = 0; i < 0x43; i++) {
                        UnkStruct_a169_e2 *e = &D_004C7B70[i];
                        if (e->field_0 == D_0064D370.field_0) {
                            UnkStruct_a169_pl *pl = *(UnkStruct_a169_pl **)((char *)&D_00522660 + car->field_19AC * 0x30 + 0x40000 - 0x3674);
                            int a = pl->field_216;
                        if (a >= 0) {
                                int id = GetUnitOriginalID__16CB3StreamedTrackFi((char *)&D_00522660 + pl->field_217 * 0x1CC + 0x12A348, a);
                                if (id >= e->field_9 && id <= e->field_A) {
                                    bp = 0x5DC;
                                    ev = D_004C7B78[i].field_0;
                                    found = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
        goto chk7;
    fneg:
        bp = 0x5DC;
        ev = D_004C7FB0[i * 6];
        found = true;
    chk7:
        if (self->field_7 != 0) {
            if (!found) {
                bp = gmnPsycheOutBP__8CB3Score;
                ev = 0xA9;
            }
        }
        OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(self, ev, bp, 3, self->field_11);
        self->field_12C = -1;
        if (found && ev >= 0xAF && ev < 0xC3) {
            self->field_12C = ev - 0xAF;
            self->field_148->field_1168 |= 1 << self->field_12C;
        }
        if (found) {
            self->field_148->field_1180 = self->field_148->field_1180 + 1;
        } else {
            self->field_148->field_1184 = self->field_148->field_1184 + 1;
        }
        float f = self->field_110;
        if (t < f || f == -1.0f) {
            self->field_114 = self->field_114 + 1;
            self->field_110 = t + gmrDoubleTakedownTime__8CB3Score;
            if (self->field_114 > 1) {
                int k = (GtMath::Min(self->field_114 - 2, 4));
                bp += gmanDoubleTakedownBP__8CB3Score[k];
                OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(self, k + 0xA3, bp, 3, self->field_11);
            }
        }
        f = self->field_118;
        if (t < f || f == -1.0f) {
            self->field_11C = self->field_11C + 1;
            self->field_118 = t + gmrSpreeTakedownTime__8CB3Score;
            if (self->field_11C > 1) {
                int k = (GtMath::Min(self->field_11C - 1, 4)) - 1;
                bp += gmanSpreeTakedownBP__8CB3Score[k];
                OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(self, k + 0x9F, bp, 3, self->field_11);
            }
        }
        if (self->field_6 != 0) {
            bp += gmnRevengeBP__8CB3Score;
            OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(self, 0xA7, bp, 3, self->field_11);
        }
    }
    AddScore__8CB3ScoreFii((char *)self->field_148 + 0x10C0, bp, 3, 0);
}



