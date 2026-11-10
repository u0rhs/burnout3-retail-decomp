// Hand-written; the lifter refused it (a88: SetupTable (OpenLobby), sibling of func_003774D0).

// Hand-written; lifter refused (a88: SetupTable, sibling shape of func_003774D0).
// [L] DNAT: CB3OnlineOpenLobbyPage::SetupTable() (research/proto/new_names.csv, high)
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;

struct UnkStruct_00396900_cell {
    unsigned char pad_0[0x20];
    u_long128 field_20;
    CGtV2d field_30;
    unsigned char pad_38[0x8];
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
};
struct UnkStruct_00396900_desc {
    float field_0;
    float field_4;
    unsigned char field_8;
};
struct UnkStruct_00396900_entry {
    void * field_0;
    void * field_4;
    void * field_8;
};
struct UnkStruct_00396900 {
    unsigned char pad_0[0x58];
    CGtV2d field_58;
    int field_60;
    int field_64;
    UnkStruct_00396900_desc * field_68;
    UnkStruct_00396900_desc * field_6C;
    UnkStruct_00396900_entry * field_70;
    int field_74;
    UnkStruct_00396900_desc field_78[9];
    UnkStruct_00396900_desc field_E4;
    UnkStruct_00396900_entry field_F0[9];
    UnkStruct_00396900_cell field_160[9];
    int field_430[9];
};
struct UnkStruct_D_01E90240 { u_long128 field_0; unsigned char pad_10[0x30]; };
struct UnkStruct_D_00665ED8 { int field_0; unsigned char pad_4[0xC]; };

extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_00665ED8 D_00665ED8;
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);

// 0x00396900
extern "C" void SetupTable__22CB3OnlineOpenLobbyPageFv(UnkStruct_00396900 * self)
{
    UnkStruct_D_01E90240 * const colours = &D_01E90240;
    int i;
    self->field_60 = 9;
    self->field_64 = 1;
    self->field_68 = self->field_78;
    self->field_6C = &self->field_E4;
    self->field_70 = self->field_F0;
    self->field_74 = *(int *)((char *)self + 0x454);
    self->field_58 = CGtV2d(-1.0f, -1.0f);
    self->field_E4.field_0 = 8.0f; self->field_E4.field_4 = 216.0f; self->field_E4.field_8 = 0;
    self->field_78[0].field_0 = 8.0f; self->field_78[0].field_4 = 26.0f; self->field_78[0].field_8 = 0;
    for (i = 1; i < 9; i++) {
        self->field_78[i].field_0 = 0.0f; self->field_78[i].field_4 = 26.0f; self->field_78[i].field_8 = 0;
    }
    for (i = 0; i < 9; i++) {
        self->field_160[i].field_20 = colours->field_0;
        self->field_160[i].field_40 = 0x41D00000;
        self->field_160[i].field_44 = D_00665ED8.field_0;
        self->field_160[i].field_4C = 0;
        self->field_160[i].field_48 = self->field_430[i];
        self->field_160[i].field_30 = CGtV2d(0.0f, 0.5f);
        self->field_F0[i].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        self->field_F0[i].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        self->field_F0[i].field_8 = &self->field_160[i];
    }
}
