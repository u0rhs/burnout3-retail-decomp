// NONMATCHING: SetupTable__21CB3OnlineJoinGamePageFv -- retail 257 / ours 249 instructions, 125 in changed runs
// a148: structure/offsets exact (10x5 table: row descs @1298, col descs @1310, entries @134C stride 12, cells @+0x40 stride 400/80, per-row header objects @0xFA0 stride 64, column-0 header, i==0 title cells from D_004C55B0 strings, j==1/4 text cells); 249 vs 257 instrs. Left: retail spills 3 pointers as quads (sq/lq 0xA0 this+4i, 0xB0 prev-row header, 0xC0 &D_0051BA44) under register pressure (fp,s0-s7) which ours does not reproduce; loop var regs swapped (retail s4=i,s3=j,s1=hdr base,s0=entry row,s7=colours); dead V2d temps at 0xD8-0xFC present
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
struct UnkStruct_cell {
    unsigned char pad_0[0x20];
    u_long128 field_20;
    CGtV2d field_30;
    unsigned char pad_38[0x8];
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
};
struct UnkStruct_rowhdr {
    u_long128 field_0;
    CGtV2d field_10;
    CGtV2d field_18;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    int field_30;
    unsigned char pad_34[0xC];
};
struct UnkStruct_desc {
    float field_0;
    float field_4;
    unsigned char field_8;
    unsigned char pad_9[0x3];
};
struct UnkStruct_entry {
    void * field_0;
    void * field_4;
    void * field_8;
};
struct UnkStruct_JT {
    unsigned char pad_0[0x1220];
    int field_1220[10];
    int field_1248[10];
    int field_1270;
    unsigned char pad_1274[0x4];
    CGtV2d field_1278;
    int field_1280;
    int field_1284;
    UnkStruct_desc * field_1288;
    UnkStruct_desc * field_128C;
    UnkStruct_entry * field_1290;
    int field_1294;
    UnkStruct_desc field_1298[10];
    UnkStruct_desc field_1310[5];
    UnkStruct_entry field_134C[10][5];
};
struct UnkStruct_hv { unsigned char pad_0[0xFA0]; UnkStruct_rowhdr h; };
struct UnkStruct_cv { unsigned char pad_0[0x40]; UnkStruct_cell c; };
struct UnkStruct_ev { unsigned char pad_0[0x134C]; UnkStruct_entry e[5]; };
struct UnkStruct_D_01E90240 { u_long128 field_0; unsigned char pad_10[0x30]; u_long128 field_40; };
struct UnkStruct_D_00665ED8 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_00665ED8 D_00665ED8;
extern UnkStruct_F D_01EA4820;
extern UnkStruct_F D_01EA4824;
extern UnkStruct_F D_01EA4828;
extern UnkStruct_F D_01EA482C;
extern UnkStruct_I D_01EA46F8;
extern int D_004C55B0[];
extern char D_0051BA44[];
extern "C" int func_00271A00(void *, int);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);

extern "C" void SetupTable__21CB3OnlineJoinGamePageFv(UnkStruct_JT * self)
{
    UnkStruct_D_01E90240 * const colours = &D_01E90240;
    int i;
    int j;
    self->field_1280 = 10;
    self->field_1284 = 5;
    self->field_1288 = self->field_1298;
    self->field_128C = self->field_1310;
    self->field_1290 = &self->field_134C[0][0];
    self->field_1294 = self->field_1270;
    self->field_1278 = CGtV2d(-1.0f, -1.0f);
    self->field_1310[0].field_0 = 7.0f; self->field_1310[0].field_4 = 11.0f; self->field_1310[0].field_8 = 0;
    self->field_1310[1].field_0 = 5.0f; self->field_1310[1].field_4 = 238.0f; self->field_1310[1].field_8 = 0;
    self->field_1310[2].field_0 = 10.0f; self->field_1310[2].field_4 = 105.0f; self->field_1310[2].field_8 = 0;
    self->field_1310[3].field_0 = 5.0f; self->field_1310[3].field_4 = 78.0f; self->field_1310[3].field_8 = 0;
    self->field_1310[4].field_0 = 5.0f; self->field_1310[4].field_4 = 70.0f; self->field_1310[4].field_8 = 0;
    self->field_1298[0].field_0 = 5.0f; self->field_1298[0].field_4 = 24.0f; self->field_1298[0].field_8 = 0;
    self->field_1298[1].field_0 = 0.0f; self->field_1298[1].field_4 = 24.0f; self->field_1298[1].field_8 = 0;
    for (i = 2; i < 10; i++) {
        self->field_1298[i].field_0 = 1.0f; self->field_1298[i].field_4 = 24.0f; self->field_1298[i].field_8 = 0;
    }
    for (i = 0; i < 10; i++) {
        UnkStruct_ev * ev = (UnkStruct_ev *)((char *)self + i * 60);
        UnkStruct_hv * hv = (UnkStruct_hv *)((char *)self + i * 64);
        UnkStruct_hv * hvp = (UnkStruct_hv *)((char *)self + (i - 1) * 64);
        int * pi = (int *)((char *)self + i * 4);
        char * fp = (char *)self + i * 400;
        char * const tab = D_0051BA44;
        for (j = 0; j < 5; j++) {
            UnkStruct_cv * cv = (UnkStruct_cv *)(fp + j * 80);
            if (j == 0) {
                if (i > 0) {
                    hv->h.field_10 = CGtV2d(11.0f, 14.0f);
                    hv->h.field_0 = colours->field_0;
                    hv->h.field_30 = D_01EA46F8.field_0;
                    hv->h.field_20 = D_01EA4820.field_0;
                    hv->h.field_24 = D_01EA4824.field_0;
                    hv->h.field_28 = D_01EA4828.field_0;
                    hv->h.field_2C = D_01EA482C.field_0;
                    hv->h.field_18 = CGtV2d(0.5f, 0.5f);
                    ev->e[j].field_8 = &hvp->h + 1;
                }
                ev->e[j].field_0 = 0;
                ev->e[j].field_4 = 0;
            } else {
                if (i == 0) {
                    cv->c.field_20 = colours->field_40;
                    cv->c.field_48 = func_00271A00(tab, D_004C55B0[j]);
                    ev->e[j].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                    ev->e[j].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                } else {
                    cv->c.field_20 = colours->field_0;
                    if (j == 1) {
                        cv->c.field_48 = pi[0x1248 / 4];
                        ev->e[j].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                        ev->e[j].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                    } else if (j == 4) {
                        cv->c.field_48 = pi[0x1220 / 4];
                        ev->e[j].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                        ev->e[j].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                    } else {
                        cv->c.field_48 = 0;
                        ev->e[j].field_0 = 0;
                        ev->e[j].field_4 = 0;
                    }
                }
                if (j == 4) {
                    cv->c.field_30 = CGtV2d(0.5f, 0.0f);
                } else {
                    cv->c.field_30 = CGtV2d(0.0f, 0.0f);
                }
                cv->c.field_40 = 0x41C00000;
                cv->c.field_44 = D_00665ED8.field_0;
                cv->c.field_4C = 0;
                ev->e[j].field_8 = &cv->c;
            }
        }
    }
}

