// NONMATCHING: SetupTable__26CB3OnlineOptimatchMenuPageFv -- retail 257 / ours 257 instructions, 17 in changed runs
// near21: 17 changed (was 21). D_01EA4820..482C are one 16-byte object (overlapping 16-byte externs before); the two row CGtV2d fields copied whole from it (*(CGtV2d *)&D_01EA4820.field_0 / field_8) fixes the f0/f1 order. Left: strs (&D_0051BA44) spill sw 0xC0(sp) placement in the i-loop preamble (tried top-level, per-j, uninitialised + assigned: no); colours->field_40 lq retail schedules after the cell address and sq in the jal delay slot
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// SetupTable__26CB3OnlineOptimatchMenuPageFv -- [L] DNAT: CB3OnlineOptimatchMenuPage::SetupTable() (research/proto/new_names.csv, high)
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;

struct UnkStruct_0037A500_cell {
    unsigned char pad_0[0x20];
    u_long128 field_20;
    CGtV2d field_30;
    unsigned char pad_38[0x8];
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
};
struct UnkStruct_0037A500_desc {
    float field_0;
    float field_4;
    unsigned char field_8;
};
struct UnkStruct_0037A500_entry {
    void * field_0;
    void * field_4;
    void * field_8;
};
struct UnkStruct_0037A500_rowinfo {
    u_long128 field_0;
    CGtV2d field_10;
    CGtV2d field_18;
    CGtV2d field_20;
    CGtV2d field_28;
    int field_30;
    unsigned char pad_34[0xC];
};
struct UnkStruct_0037A500 {
    unsigned char pad_0[0x340];
    UnkStruct_0037A500_cell field_340[10][5];
    UnkStruct_0037A500_rowinfo field_12E0[9];
    int field_1520[10];
    int field_1548[10];
    int field_1570;
    unsigned char pad_1574[0x4];
    CGtV2d field_1578;
    int field_1580;
    int field_1584;
    UnkStruct_0037A500_desc * field_1588;
    UnkStruct_0037A500_desc * field_158C;
    UnkStruct_0037A500_entry * field_1590;
    int field_1594;
    UnkStruct_0037A500_desc field_1598[10];
    UnkStruct_0037A500_desc field_1610[5];
    UnkStruct_0037A500_entry field_164C[10][5];
};
struct UnkStruct_D_01E90240 {
    u_long128 field_0;
    unsigned char pad_10[0x30];
    u_long128 field_40;
};
struct UnkStruct_F16 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_I16 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };

extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_I16 D_00665ED8;
extern UnkStruct_I16 D_01EA46F8;
struct UnkStruct_D_01EA4820 { float field_0; float field_4; float field_8; float field_C; };
extern UnkStruct_D_01EA4820 D_01EA4820;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern int D_004C91B0[];
extern "C" int func_00271A00(void *, int);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);

// 0x0037A500
extern "C" void SetupTable__26CB3OnlineOptimatchMenuPageFv(UnkStruct_0037A500 * self)
{
    UnkStruct_D_01E90240 * const colours = &D_01E90240;
    int i, j, k;
    self->field_1580 = 10;
    self->field_1584 = 5;
    self->field_1588 = self->field_1598;
    self->field_158C = self->field_1610;
    self->field_1590 = &self->field_164C[0][0];
    self->field_1594 = self->field_1570;
    self->field_1578 = CGtV2d(-1.0f, -1.0f);
    self->field_1610[0].field_0 = 7.0f; self->field_1610[0].field_4 = 11.0f; self->field_1610[0].field_8 = 0;
    self->field_1610[1].field_0 = 5.0f; self->field_1610[1].field_4 = 238.0f; self->field_1610[1].field_8 = 0;
    self->field_1610[2].field_0 = 10.0f; self->field_1610[2].field_4 = 105.0f; self->field_1610[2].field_8 = 0;
    self->field_1610[3].field_0 = 5.0f; self->field_1610[3].field_4 = 78.0f; self->field_1610[3].field_8 = 0;
    self->field_1610[4].field_0 = 5.0f; self->field_1610[4].field_4 = 70.0f; self->field_1610[4].field_8 = 0;
    self->field_1598[0].field_0 = 5.0f; self->field_1598[0].field_4 = 24.0f; self->field_1598[0].field_8 = 0;
    self->field_1598[1].field_0 = 0.0f; self->field_1598[1].field_4 = 24.0f; self->field_1598[1].field_8 = 0;
    for (k = 2; k < 10; k++) {
        self->field_1598[k].field_0 = 1.0f;
        self->field_1598[k].field_4 = 24.0f;
        self->field_1598[k].field_8 = 0;
    }
    for (i = 0; i < 10; i++) {
        UnkStruct_D_0051BA44 * const strs = &D_0051BA44;
        for (j = 0; j < 5; j++) {
            if (j == 0) {
                if (i > 0) {
                    self->field_12E0[i - 1].field_10 = CGtV2d(11.0f, 14.0f);
                    self->field_12E0[i - 1].field_0 = colours->field_0;
                    self->field_12E0[i - 1].field_30 = D_01EA46F8.field_0;
                    self->field_12E0[i - 1].field_20 = *(CGtV2d *)&D_01EA4820.field_0;
                    self->field_12E0[i - 1].field_28 = *(CGtV2d *)&D_01EA4820.field_8;
                    self->field_12E0[i - 1].field_18 = CGtV2d(0.5f, 0.5f);
                    self->field_164C[i][j].field_8 = &self->field_12E0[i - 1];
                }
                self->field_164C[i][j].field_0 = 0;
                self->field_164C[i][j].field_4 = 0;
            } else {
                if (i == 0) {
                    self->field_340[i][j].field_20 = colours->field_40;
                    self->field_340[i][j].field_48 = func_00271A00(strs, D_004C91B0[j]);
                    self->field_164C[i][j].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                    self->field_164C[i][j].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                } else {
                    self->field_340[i][j].field_20 = colours->field_0;
                    if (j == 1) {
                        self->field_340[i][j].field_48 = self->field_1548[i];
                        self->field_164C[i][j].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                        self->field_164C[i][j].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                    } else if (j == 4) {
                        self->field_340[i][j].field_48 = self->field_1520[i];
                        self->field_164C[i][j].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                        self->field_164C[i][j].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                    } else {
                        self->field_340[i][j].field_48 = 0;
                        self->field_164C[i][j].field_0 = 0;
                        self->field_164C[i][j].field_4 = 0;
                    }
                }
                if (j == 4) {
                    self->field_340[i][j].field_30 = CGtV2d(0.5f, 0.0f);
                } else {
                    self->field_340[i][j].field_30 = CGtV2d(0.0f, 0.0f);
                }
                self->field_340[i][j].field_40 = 0x41C00000;
                self->field_340[i][j].field_44 = D_00665ED8.field_0;
                self->field_340[i][j].field_4C = 0;
                self->field_164C[i][j].field_8 = &self->field_340[i][j];
            }
        }
    }
}
