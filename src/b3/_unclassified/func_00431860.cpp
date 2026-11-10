// Hand-written; the lifter refused it (draftAC: 3x5 table page Prepare (func_0043A190 shape); i==1 colour via by-value inline keeps retail's dead slot 0x190; FINISH_FORCE: retail's &D_01E90240 is unlabelled (addiu 0x240), same bytes).

// func_00431860 -- hand-written from the retail asm (draftAC): a 3x5 table page's Prepare (row/column descriptors,
// per-row text/wrapped-text/image cells, then func_0033FF10 on D_01E8D450 and func_00431160) -- the shape of the
// proven func_0043A190's table setup.
// Unnamed in every table, so a placeholder with C linkage; file and Area unknown, so _unclassified/. Field names are
// placeholders and every type is [G] (instruction widths).
// [C] (draftAC, try.py) the i == 1 row colour goes through a by-value placeholder inline (func_00431860_inl1): its
// parameter keeps retail's dead 16-byte slot at sp+0x190 between col2 and the zero colour's temporary (frame 0x220);
// named locals, temporaries, CGtV4d(u_long128) copies and return-by-value inlines left the slot out (0x210) or added two.
// Retail's &D_01E90240 is unlabelled in the splat listing (lui 0x1E9 / addiu 0x240): same bytes, a100 flags it.
#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
using namespace GtMathPs2;

struct UnkStruct_00431860_text {
    unsigned char pad_0[0x20];
    CGtV4d field_20;
    CGtV2d field_30;
    unsigned char pad_38[0x8];
    float field_40;
    void *field_44;
    unsigned short *field_48;
    int field_4C;
};
struct UnkStruct_00431860_frame {
    CGtV2d field_0;
    float field_8;
    float field_C;
    void *field_10;
    short field_14;
    short field_16;
    unsigned char pad_18[0x8];
};
struct UnkStruct_00431860_wrap {
    CGtV4d field_0;
    CGtV2d field_10;
    float field_18;
    unsigned char pad_1C[0x4];
    unsigned short *field_20;
    UnkStruct_00431860_frame *field_24;
    int field_28;
    int field_2C;
};
struct UnkStruct_00431860_image {
    CGtV4d field_0;
    CGtV2d field_10;
    CGtV2d field_18;
    CGtV2d field_20;
    CGtV2d field_28;
    void *field_30;
    unsigned char pad_34[0xC];
};
struct UnkStruct_00431860_row { float field_0; float field_4; bool field_8; };
struct UnkStruct_00431860_cell { void *field_0; void *field_4; void *field_8; };
struct UnkStruct_00431860_data {
    CGtV2d field_0;
    int field_8;
    int field_C;
    UnkStruct_00431860_row *field_10;
    UnkStruct_00431860_row *field_14;
    UnkStruct_00431860_cell *field_18;
    void *field_1C;
};
struct UnkStruct_00431860 {
    unsigned char pad_0[0x4];
    unsigned short field_4[3][3];
    unsigned char pad_16[0xA];
    UnkStruct_00431860_text field_20[3];
    unsigned short field_110[3][0x80];
    UnkStruct_00431860_wrap field_410[3];
    UnkStruct_00431860_frame field_4A0;
    UnkStruct_00431860_image field_4C0[3];
    unsigned short field_580[3][0x20];
    UnkStruct_00431860_text field_640[3];
    UnkStruct_00431860_image field_730[3];
    void *field_7F0;
    unsigned char pad_7F4[0x4];
    UnkStruct_00431860_data field_7F8;
    UnkStruct_00431860_row field_818[3];
    UnkStruct_00431860_row field_83C[5];
    UnkStruct_00431860_cell field_878[3][5];
    unsigned char field_92C[0xC];
    int field_938;
};
struct UnkStruct_D_01E8D450 { unsigned char pad_0[0x10]; };
struct UnkStruct_00431860_p { void *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00431860_v { CGtV2d field_0; unsigned char pad_8[0x8]; };
extern CB3MenuPageManager D_01E90240;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_00431860_p D_00665ED0;
extern UnkStruct_00431860_p D_00665ED8;
extern UnkStruct_00431860_p D_01EA4724;
extern UnkStruct_00431860_v D_01EA48C0;
extern UnkStruct_00431860_v D_01EA48C8;
extern UnkStruct_00431860_v D_01EA48D0;
extern UnkStruct_00431860_v D_01EA48D8;
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short*, const void *, const void*);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void*);
extern "C" void RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short*, const void *, const void*);
extern "C" void GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void*);
extern "C" void func_0033E220(const CGtV2d &, const CGtV2d &, unsigned short *, void *, const void *);
extern "C" void func_0033DC80(CGtV2d *, void *, const void *);
extern "C" int func_0033FF10(void *self, const CGtV2d &pos, const CGtV2d &p2, const CGtV2d &p3, bool flag, const void *data, void *objs, int p7);
extern "C" void func_00431160(void *);

static inline void func_00431860_inl1(CGtV4d *c, CGtV4d v) { *c = v; }
// 0x00431860
extern "C" void func_00431860(UnkStruct_00431860 *self)
{
    CB3MenuPageManager *const mgr = &D_01E90240;
    self->field_938 = 0;
    self->field_7F8.field_8 = 3;
    self->field_7F8.field_C = 5;
    self->field_7F8.field_10 = self->field_818;
    self->field_7F8.field_14 = self->field_83C;
    self->field_7F8.field_18 = &self->field_878[0][0];
    self->field_7F8.field_1C = self->field_7F0;
    self->field_7F8.field_0 = CGtV2d(-1.0f, -1.0f);
    self->field_83C[0].field_0 = 64.0f;
    self->field_83C[0].field_4 = 2.0f;
    self->field_83C[0].field_8 = false;
    self->field_83C[1].field_0 = 36.8f;
    self->field_83C[1].field_4 = 288.0f;
    self->field_83C[1].field_8 = false;
    self->field_83C[2].field_0 = 3.2f;
    self->field_83C[2].field_4 = 16.0f;
    self->field_83C[2].field_8 = false;
    self->field_83C[3].field_0 = 1.6f;
    self->field_83C[3].field_4 = 112.0f;
    self->field_83C[3].field_8 = false;
    self->field_83C[4].field_0 = 1.6f;
    self->field_83C[4].field_4 = 16.0f;
    self->field_83C[4].field_8 = false;
    int i;
    for (i = 0; i < 3; i++) {
        self->field_818[i].field_0 = 8.0f;
        self->field_818[i].field_4 = 80.0f;
        self->field_818[i].field_8 = false;
    }
    self->field_4A0.field_0 = CGtV2d(2.0f, 2.0f);
    self->field_4A0.field_8 = 22.0f;
    self->field_4A0.field_C = -2.0f;
    self->field_4A0.field_10 = D_00665ED8.field_0;
    self->field_4A0.field_14 = -1;
    self->field_4A0.field_16 = -1;
    for (i = 0; i < 3; i++) {
        CGtV4d col;
        CGtV4d col2;
        if (i == 1) {
            col = mgr->field_0[1];
            func_00431860_inl1(&col2, mgr->field_110);
        } else {
            col = mgr->field_0[0];
            col2 = CGtV4d(0.0f, 0.0f, 0.0f, 0.0f);
        }
        self->field_20[i].field_30 = CGtV2d(1.0f, 0.5f);
        self->field_20[i].field_20 = col;
        self->field_20[i].field_48 = self->field_4[i];
        self->field_20[i].field_40 = 40.0f;
        self->field_20[i].field_44 = D_00665ED0.field_0;
        self->field_20[i].field_4C = 2;
        self->field_410[i].field_10 = CGtV2d(0.0f, 0.5f);
        self->field_410[i].field_0 = col;
        self->field_410[i].field_24 = &self->field_4A0;
        self->field_410[i].field_20 = self->field_110[i];
        self->field_410[i].field_18 = 336.0f;
        self->field_410[i].field_2C = 1;
        self->field_410[i].field_28 = 1;
        self->field_4C0[i].field_0 = col2;
        self->field_4C0[i].field_10 = CGtV2d(12.0f, 21.0f);
        self->field_4C0[i].field_18 = CGtV2d(0.5f, 0.5f);
        self->field_4C0[i].field_20 = D_01EA48C0.field_0;
        self->field_4C0[i].field_28 = D_01EA48C8.field_0;
        self->field_4C0[i].field_30 = D_01EA4724.field_0;
        self->field_640[i].field_30 = CGtV2d(0.5f, 0.5f);
        self->field_640[i].field_20 = col;
        self->field_640[i].field_48 = self->field_580[i];
        self->field_640[i].field_40 = 22.0f;
        self->field_640[i].field_44 = D_00665ED8.field_0;
        self->field_640[i].field_4C = 3;
        self->field_730[i].field_0 = col2;
        self->field_730[i].field_10 = CGtV2d(12.0f, 21.0f);
        self->field_730[i].field_18 = CGtV2d(0.5f, 0.5f);
        self->field_730[i].field_20 = D_01EA48D0.field_0;
        self->field_730[i].field_28 = D_01EA48D8.field_0;
        self->field_730[i].field_30 = D_01EA4724.field_0;
        self->field_878[i][0].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        self->field_878[i][0].field_4 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        self->field_878[i][0].field_8 = &self->field_20[i];
        self->field_878[i][1].field_0 = (void *)&func_0033E220;
        self->field_878[i][1].field_4 = (void *)&func_0033DC80;
        self->field_878[i][1].field_8 = &self->field_410[i];
        self->field_878[i][2].field_0 = (void *)&RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        self->field_878[i][2].field_4 = (void *)&GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        self->field_878[i][2].field_8 = &self->field_4C0[i];
        self->field_878[i][3].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        self->field_878[i][3].field_4 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        self->field_878[i][3].field_8 = &self->field_640[i];
        self->field_878[i][4].field_0 = (void *)&RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        self->field_878[i][4].field_4 = (void *)&GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        self->field_878[i][4].field_8 = &self->field_730[i];
    }
    func_0033FF10(&D_01E8D450, CGtV2d(40.0f, 128.0f), CGtV2d(0.0f, 0.0f), CGtV2d(560.0f, 240.0f), true, &self->field_7F8, self->field_92C, 0);
    func_00431160(self);
}
