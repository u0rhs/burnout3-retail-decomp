// Hand-written; the lifter refused it (fresh3: 7x2 text table page Prepare; mgr const pointer for colours, SetA(1 - k*|i-3|) via pabsw/pextlw inlines, anchor CGtV2d temporaries in the loop (slot order)).

#include "b3/gamesource/Menu/DebugMenu/B3MenuPageManager.h"
using namespace GtMathPs2;

struct UnkStruct_0043A190_text {
    unsigned char pad_0[0x20];
    CGtV4d field_20;
    CGtV2d field_30;
    unsigned char pad_38[0x8];
    float field_40;
    void *field_44;
    unsigned short *field_48;
    int field_4C;
};
struct UnkStruct_0043A190_row { float field_0; float field_4; bool field_8; };
struct UnkStruct_0043A190_cell { void *field_0; void *field_4; void *field_8; };
struct UnkStruct_0043A190_data {
    CGtV2d field_0;
    int field_8;
    int field_C;
    UnkStruct_0043A190_row *field_10;
    UnkStruct_0043A190_row *field_14;
    UnkStruct_0043A190_cell *field_18;
    void *field_1C;
};
struct UnkStruct_0043A190 {
    unsigned char pad_0[0x440];
    void *field_440;
    unsigned char pad_444[0x1C8];
    unsigned short *field_60C[7];
    unsigned char pad_628[0x8];
    UnkStruct_0043A190_text field_630[7];
    unsigned short *field_860[7];
    unsigned char pad_87C[0x4];
    UnkStruct_0043A190_text field_880[7];
    UnkStruct_0043A190_data field_AB0;
    UnkStruct_0043A190_row field_AD0[7];
    UnkStruct_0043A190_row field_B24[2];
    UnkStruct_0043A190_cell field_B3C[7][2];
    unsigned char field_BE4[0x38];
    unsigned char field_C1C;
};
struct UnkStruct_D_01E8D450 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_0043A190_b { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_0043A190_p { void *field_0; unsigned char pad_4[0xC]; };
extern CB3MenuPageManager D_01E90240;
extern UnkStruct_D_01E8D450 D_01E8D450;
extern UnkStruct_0043A190_b D_01E8D45A;
extern UnkStruct_0043A190_p D_00665ED8;
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short*, const void *, const void*);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void*);
extern "C" int func_0033FF10(void *self, const CGtV2d &pos, const CGtV2d &p2, const CGtV2d &p3, bool flag, const void *data, void *objs, int p7);
extern "C" void func_0043A040(void *);

static inline int func_0043A190_inl1(int x)
{
    int r;
    asm("pabsw %0,%1" : "=r"(r) : "r"(x));
    return r;
}
static inline unsigned int func_0043A190_inl2(unsigned int x)
{
    unsigned int r;
    asm("pextlw %0,$0,%1" : "=r"(r) : "r"(x));
    return r;
}

// 0x0043A190
extern "C" int func_0043A190(UnkStruct_0043A190 *self)
{
    CB3MenuPageManager *const mgr = &D_01E90240;
    self->field_C1C = 2;
    self->field_AB0.field_8 = 7;
    self->field_AB0.field_C = 2;
    self->field_AB0.field_10 = self->field_AD0;
    self->field_AB0.field_14 = self->field_B24;
    self->field_AB0.field_18 = &self->field_B3C[0][0];
    self->field_AB0.field_1C = self->field_440;
    self->field_AB0.field_0 = CGtV2d(-1.0f, -1.0f);
    self->field_B24[0].field_0 = 48.0f;
    self->field_B24[0].field_4 = 304.0f;
    self->field_B24[0].field_8 = false;
    self->field_B24[1].field_0 = 0.0f;
    self->field_B24[1].field_4 = 176.0f;
    self->field_B24[1].field_8 = false;
    int i;
    for (i = 0; i < 7; i++) {
        self->field_AD0[i].field_0 = 8.0f;
        self->field_AD0[i].field_4 = 24.0f;
        self->field_AD0[i].field_8 = false;
    }
    for (i = 0; i < 7; i++) {
        CGtV4d col;
        if (i == 3) {
            col = mgr->field_0[1];
        } else {
            col = mgr->field_0[0];
            col.SetA(1.0f - 0.2333333343f * (float)(int)func_0043A190_inl2(func_0043A190_inl1(i - 3)));
        }
        self->field_880[i].field_30 = CGtV2d(0.0f, 0.5f);
        self->field_880[i].field_20 = col;
        self->field_880[i].field_48 = self->field_860[i];
        self->field_880[i].field_40 = 24.0f;
        self->field_880[i].field_44 = D_00665ED8.field_0;
        self->field_880[i].field_4C = 0;
        self->field_630[i].field_30 = CGtV2d(1.0f, 0.5f);
        self->field_630[i].field_20 = col;
        self->field_630[i].field_48 = self->field_60C[i];
        self->field_630[i].field_40 = 24.0f;
        self->field_630[i].field_44 = D_00665ED8.field_0;
        self->field_630[i].field_4C = 0;
        self->field_B3C[i][0].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        self->field_B3C[i][0].field_4 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        self->field_B3C[i][0].field_8 = &self->field_880[i];
        self->field_B3C[i][1].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
        self->field_B3C[i][1].field_4 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
        self->field_B3C[i][1].field_8 = &self->field_630[i];
    }
    if (D_01E8D45A.field_0 != 0) ((UnkStruct_D_01E8D450 *)&D_01E8D450)->vfunc_C();
    func_0033FF10(&D_01E8D450, CGtV2d(40.0f, 128.0f), CGtV2d(0.0f, 0.0f), CGtV2d(560.0f, 240.0f), true, &self->field_AB0, self->field_BE4, 0);
    func_0043A040(self);
    return 1;
}
