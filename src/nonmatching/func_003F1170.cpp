// NONMATCHING: func_003F1170 -- retail 197 / ours 191 instructions, 43 in changed runs
// near33: 49->43. a/b/c CGtV2d declared c,b,a uninitialised + Set() -> retail's slots (a 0x60, b 0x68, c 0x70). Left: retail's dead CGtV4d(1,1,1,1) (lui + 4 sw + lq v0, the func_003F1FC0 family, unsolved), last-loop i/s1 in s1/s2 swapped (decl order, fresh loop var, inner int s1 tried), top-of-function t-register rotation (-1.0 in a3 vs t5)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_003F1170 -- retail 197 / ours 191 instructions, 49 in changed runs
// a226: N140 16-byte pad (declared after col) replaces the dead white temp: frame 0x90 = retail, 60->49. Left: retail's dead CGtV4d(1,1,1,1) 4xsw + lq (6 instrs, not reproducible), a/b/c slot order (retail a=96,b=104,c=112), constant regs
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// NONMATCHING: func_003F1170 -- retail 197 / ours 191 instructions, 60 in changed runs
// a153: logic exact (191 vs 197 instrs, 60 changed; class sibling SetupTable__22CB3OnlineOpenLobbyPageFv func_00396900 shape: desc/entry/cell arrays). Missing: retail keeps a dead CGtV4d(1,1,1,1) temp after the func_0033FF10 call (4 sw + a dead 'lq v0,0x40(sp)', frame 0x90 vs ours 0x80); every form (ctor/assign/u_long128 keep) is dropped by b119; the 16-byte shift cascades into register allocation (constants t5/a3, self s0 vs s2). Needs the dead-temp trick (N172 W()-like?) or a lead decision.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_003F1170_row { short field_0; unsigned char pad_2[0x3A]; };
struct UnkStruct_003F1170_el { short field_0; unsigned char pad_2[0x56]; };
struct UnkStruct_003F1170_cell {
    unsigned char pad_0[0x20];
    CGtV4d field_20;
    CGtV2d field_30;
    unsigned char pad_38[0x8];
    float field_40;
    int field_44;
    void * field_48;
    int field_4C;
};
struct UnkStruct_003F1170_desc {
    float field_0;
    float field_4;
    unsigned char field_8;
};
struct UnkStruct_003F1170_entry {
    void * field_0;
    void * field_4;
    void * field_8;
};
struct UnkStruct_003F1170 {
    unsigned char pad_0[0x4];
    UnkStruct_003F1170_row field_4[5];
    UnkStruct_003F1170_cell field_130[5];
    UnkStruct_003F1170_el field_2C0[5];
    unsigned char pad_478[0x8];
    UnkStruct_003F1170_cell field_480[5];
    int field_610;
    unsigned char pad_614[0x4];
    CGtV2d field_618;
    int field_620;
    int field_624;
    UnkStruct_003F1170_desc * field_628;
    UnkStruct_003F1170_desc * field_62C;
    UnkStruct_003F1170_entry * field_630;
    int field_634;
    UnkStruct_003F1170_desc field_638[5];
    UnkStruct_003F1170_desc field_674;
    UnkStruct_003F1170_desc field_680;
    UnkStruct_003F1170_entry field_68C[10];
    UnkStruct_003F1170_entry field_704[1];
    unsigned char pad_710[0x10];
    int field_720;
};
struct UnkStruct_D_01E90250 { CGtV4d field_0; };
struct UnkStruct_D_00665ED8 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E8D450 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E90250 D_01E90250;
extern UnkStruct_D_00665ED8 D_00665ED8;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(CGtV2d *, void *, const void *);
extern "C" int func_0033FF10(void *, void *, void *, void *, int, void *, void *, int);
extern "C" bool func_003F1490(void *, int, int);

struct UnkStruct_003F1170_pad { int x[4]; UnkStruct_003F1170_pad() {} ~UnkStruct_003F1170_pad() {} };
// 0x003F1170
extern "C" int func_003F1170(UnkStruct_003F1170 * self)
{
    CGtV4d col;
    UnkStruct_003F1170_pad pd;
    CGtV2d neg;
    int i;
    int s1;
    neg.Set(-1.0f, -1.0f);
    col = D_01E90250.field_0;
    self->field_620 = 5;
    self->field_624 = 2;
    self->field_628 = self->field_638;
    self->field_62C = &self->field_674;
    self->field_630 = self->field_68C;
    self->field_634 = self->field_610;
    self->field_618 = neg;
    self->field_674.field_0 = 48.0f;
    self->field_674.field_4 = 304.0f;
    self->field_674.field_8 = 0;
    self->field_680.field_0 = 0.0f;
    self->field_680.field_4 = 136.0f;
    self->field_680.field_8 = 0;
    for (i = 0; i < 5; i++) {
        if (i == 0) {
            self->field_638[i].field_0 = 0.0f;
        } else {
            self->field_638[i].field_0 = 24.0f;
        }
        self->field_638[i].field_4 = 24.0f;
        self->field_638[i].field_8 = 0;
    }
    CGtV2d q(0.0f, 0.5f);
    CGtV2d p(1.0f, 0.5f);
    for (i = 0; i < 5; i++) {
        self->field_480[i].field_30 = q;
        self->field_480[i].field_20 = col;
        self->field_480[i].field_48 = &self->field_2C0[i];
        self->field_480[i].field_40 = 24.0f;
        self->field_480[i].field_44 = D_00665ED8.field_0;
        self->field_480[i].field_4C = 0;
        self->field_130[i].field_30 = p;
        self->field_130[i].field_20 = col;
        self->field_130[i].field_48 = &self->field_4[i];
        self->field_130[i].field_40 = 24.0f;
        self->field_130[i].field_44 = D_00665ED8.field_0;
        self->field_130[i].field_4C = 0;
        self->field_68C[2 * i].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        self->field_68C[2 * i].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        self->field_68C[2 * i].field_8 = &self->field_480[i];
        self->field_68C[2 * i + 1].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        self->field_68C[2 * i + 1].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        self->field_68C[2 * i + 1].field_8 = &self->field_130[i];
    }
    CGtV2d c;
    CGtV2d b;
    CGtV2d a;
    a.Set(520.0f, 240.0f);
    b.Set(0.0f, 0.0f);
    c.Set(40.0f, 128.0f);
    func_0033FF10(&D_01E8D450, &c, &b, &a, 1, &self->field_618, &self->field_704, 1);
    for (i = 0; i < 5; i++) {
        s1 = self->field_720 + i;
        if (s1 >= 0 && s1 < 30) {
            func_003F1490(&self->field_2C0[i], s1, 0);
            func_003F1490(&self->field_4[i], s1, 1);
        } else {
            self->field_2C0[i].field_0 = 0;
            self->field_4[i].field_0 = 0;
        }
    }
    return 1;
}


