// Hand-written; the lifter refused it (a82: cells array at +0x20 (Cell 0x50), CGtV2d temp assignments for dead stack stores, direct indexing, strs const ptr inside j loop, else-if order A/B/C).

// func_003774D0 -- [L] DNAT: CB3OnlineRecordsDisplayMenuPage::SetupTableData() (research/proto/new_names.csv, medium)
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;

struct UnkStruct_003774D0_cell {
    unsigned char pad_0[0x20];
    u_long128 field_20;
    CGtV2d field_30;
    unsigned char pad_38[0x8];
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
};
struct UnkStruct_003774D0_desc {
    float field_0;
    float field_4;
    unsigned char field_8;
};
struct UnkStruct_003774D0_entry {
    void * field_0;
    void * field_4;
    void * field_8;
};
struct UnkStruct_003774D0_rowinfo {
    unsigned char pad_0[0x10];
    CGtV2d field_10;
    CGtV2d field_18;
};
struct UnkStruct_003774D0 {
    unsigned char pad_0[0x20];
    UnkStruct_003774D0_cell field_20[7][5];
    int field_B10[7][5];
    unsigned char pad_B9C[0x4];
    UnkStruct_003774D0_rowinfo field_BA0[7];
    int field_C80;
    unsigned char pad_C84[0x4];
    CGtV2d field_C88;
    int field_C90;
    int field_C94;
    UnkStruct_003774D0_desc * field_C98;
    UnkStruct_003774D0_desc * field_C9C;
    UnkStruct_003774D0_entry * field_CA0;
    int field_CA4;
    UnkStruct_003774D0_desc field_CA8[7];
    UnkStruct_003774D0_desc field_CFC[5];
    UnkStruct_003774D0_entry field_D38[7][5];
};
struct UnkStruct_D_01E90240 {
    u_long128 field_0;
    unsigned char pad_10[0x30];
    u_long128 field_40;
};
struct UnkStruct_D_00665ED8 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };

extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_00665ED8 D_00665ED8;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern int D_004A4F50[];
extern "C" int func_00271A00(void *, int);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);

// 0x003774D0
extern "C" void func_003774D0(UnkStruct_003774D0 * self)
{
    UnkStruct_D_01E90240 * const colours = &D_01E90240;
    int i, j;
    self->field_C90 = 7;
    self->field_C94 = 5;
    self->field_C98 = self->field_CA8;
    self->field_C9C = self->field_CFC;
    self->field_CA0 = &self->field_D38[0][0];
    self->field_CA4 = self->field_C80;
    self->field_C88 = CGtV2d(-1.0f, -1.0f);
    self->field_CFC[0].field_0 = 12.0f; self->field_CFC[0].field_4 = 55.0f; self->field_CFC[0].field_8 = 0;
    self->field_CFC[1].field_0 = 5.0f; self->field_CFC[1].field_4 = 140.0f; self->field_CFC[1].field_8 = 0;
    self->field_CFC[2].field_0 = 20.0f; self->field_CFC[2].field_4 = 149.0f; self->field_CFC[2].field_8 = 0;
    self->field_CFC[3].field_0 = 5.0f; self->field_CFC[3].field_4 = 80.0f; self->field_CFC[3].field_8 = 0;
    self->field_CFC[4].field_0 = 5.0f; self->field_CFC[4].field_4 = 64.0f; self->field_CFC[4].field_8 = 0;
    self->field_CA8[0].field_0 = 0.0f; self->field_CA8[0].field_4 = 26.0f; self->field_CA8[0].field_8 = 0;
    self->field_CA8[1].field_0 = 18.0f; self->field_CA8[1].field_4 = 32.0f; self->field_CA8[1].field_8 = 1;
    self->field_CA8[2].field_0 = 2.0f; self->field_CA8[2].field_4 = 32.0f; self->field_CA8[2].field_8 = 0;
    self->field_CA8[3].field_0 = 8.0f; self->field_CA8[3].field_4 = 32.0f; self->field_CA8[3].field_8 = 0;
    self->field_CA8[4].field_0 = 8.0f; self->field_CA8[4].field_4 = 32.0f; self->field_CA8[4].field_8 = 0;
    self->field_CA8[5].field_0 = 8.0f; self->field_CA8[5].field_4 = 32.0f; self->field_CA8[5].field_8 = 0;
    self->field_CA8[6].field_0 = 8.0f; self->field_CA8[6].field_4 = 32.0f; self->field_CA8[6].field_8 = 0;
    for (i = 0; i < 7; i++) {
        self->field_BA0[i].field_18 = CGtV2d(64.0f, 32.0f);
        self->field_BA0[i].field_10 = CGtV2d(0.5f, 0.5f);
        for (j = 0; j < 5; j++) {
            UnkStruct_D_0051BA44 * const strs = &D_0051BA44;
            if (i == 1) {
                self->field_20[i][j].field_20 = colours->field_40;
                self->field_20[i][j].field_48 = func_00271A00(strs, D_004A4F50[j]);
            } else {
                self->field_20[i][j].field_20 = colours->field_0;
                self->field_20[i][j].field_48 = self->field_B10[i][j];
            }
            self->field_20[i][j].field_40 = 0x41D00000;
            self->field_20[i][j].field_44 = D_00665ED8.field_0;
            self->field_20[i][j].field_4C = 0;
            if (j == 1) {
                self->field_20[i][j].field_30 = CGtV2d(1.0f, 0.0f);
            } else if (j == 4) {
                self->field_20[i][j].field_30 = CGtV2d(0.5f, 0.0f);
            } else {
                self->field_20[i][j].field_30 = CGtV2d(0.0f, 0.0f);
            }
        }
    }
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 5; j++) {
            if (i != 1 && j == 4) {
                self->field_D38[i][j].field_0 = 0;
                self->field_D38[i][j].field_4 = 0;
                self->field_D38[i][j].field_8 = &self->field_BA0[i];
            } else if (i != 1) {
                self->field_D38[i][j].field_0 = 0;
                self->field_D38[i][j].field_4 = 0;
                self->field_D38[i][j].field_8 = &self->field_20[i][j];
            } else {
                self->field_D38[i][j].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                self->field_D38[i][j].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                self->field_D38[i][j].field_8 = &self->field_20[i][j];
            }
        }
    }
}
