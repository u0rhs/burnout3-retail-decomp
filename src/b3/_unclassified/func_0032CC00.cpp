// Hand-written; the lifter refused it (a148: single if(bad1||(p&&..)||(!p&&..)) fix-block (out of line), float locals xa/xb + const-float pun to stop CSE in third compare, 'a0 = E else 0' arm order, dead CGtV2d(0,0) temp for field_68).

#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Q { unsigned long field_0; unsigned char pad_8[8]; };
struct UnkStruct_Sc { unsigned char pad_0[0x14]; void * field_14; };
struct UnkStruct_obj { unsigned char pad_0[0x4]; float field_4; unsigned char pad_8[0x4]; float field_C; };
struct UnkStruct_A4A10 { int field_0; unsigned char pad_4[0x4]; };
struct UnkStruct_Mc {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x4];
    unsigned short field_E;
    unsigned char pad_10[0x10];
    UnkStruct_obj * field_20[2];
    UnkStruct_obj * field_28[3];
    unsigned char pad_34[0x10];
    int field_44;
    unsigned char pad_48[0x18];
    unsigned char field_60;
    unsigned char pad_61[0x7];
    CGtV2d field_68;
    float field_70;
    float field_74;
    int field_78;
    short field_7C;
    short field_7E;
    UnkStruct_obj * field_80;
    UnkStruct_obj * field_84;
    unsigned long field_88;
    int field_90;
    signed char field_94;
    unsigned char field_95;
};
extern UnkStruct_Sc D_01E903E0;
extern UnkStruct_I D_00665ED0;
extern UnkStruct_B D_01E8980A;
extern UnkStruct_Q D_01E89810;
extern UnkStruct_I D_01E89818;
extern UnkStruct_P D_01E89800;
extern UnkStruct_A4A10 D_004A4A10[];
extern char D_004C5618[];
extern char D_004C5620[];
extern char D_004C5628[];
extern char D_004C5630[];
extern char D_004C5638[];
extern char D_004C5640[];
extern "C" void Prepare__20CB3MenuComponentBaseFv(void *);
extern "C" UnkStruct_obj * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void func_0032C550(void *, char *, char *, char *, int, int, int, int);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x0032CC00
extern "C" int func_0032CC00(UnkStruct_Mc * self, int p1, int p2, int p3, int p4, int p5, unsigned char p6)
{
    int i;
    int j;
    Prepare__20CB3MenuComponentBaseFv(self);
    self->field_60 = p6;
    UnkStruct_Sc * const sc = &D_01E903E0;
    void * fr = sc->field_14;
    self->field_94 = p1;
    self->field_80 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(sc, self->field_8, fr);
    self->field_84 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(sc, self->field_8 + 1, fr);
    self->field_68 = CGtV2d(0.0f, 0.0f);
    self->field_78 = D_00665ED0.field_0;
    self->field_74 = 1.0f;
    self->field_70 = 30.0f;
    self->field_7C = -1;
    self->field_7E = -1;
    for (i = 0; i < 2; i++) {
        self->field_20[i] = 0;
    }
    for (j = 0; j < 3; j++) {
        self->field_28[j] = 0;
    }
    self->field_44 = 0;
    self->field_95 = 0;
    func_0032C550(self, D_004C5618, D_004C5620, D_004C5628, p2, p3, p4, p5);
    UnkStruct_obj * o2;
    UnkStruct_obj * o1 = self->field_80;
    o2 = self->field_84;
    float xa = o1->field_4;
    float xb = o2->field_4;
    if (xb < xa || (self->field_20[0] != 0 && !(xb + o2->field_C <= self->field_20[0]->field_4)) || (self->field_20[0] == 0 && !(*(const float *)&o2->field_4 + o2->field_C <= *(const float *)&o1->field_4 + o1->field_C))) {
        self->field_95 = 1;
        func_0032C550(self, D_004C5630, D_004C5638, D_004C5640, p2, p3, p4, p5);
    }
    int a0;
    {
        int m = self->field_94;
        if (m == 8) {
            a0 = 3;
        } else {
            if (D_004A4A10[m].field_0 != 0xF) {
                a0 = self->field_E;
            } else {
                a0 = 0;
            }
        }
    }
    if (self->field_60 == 0) {
        if (D_01E8980A.field_0 != 0) {
            self->field_88 = D_01E89810.field_0;
            self->field_90 = D_01E89818.field_0;
            if (a0 < 2) {
                if (a0 == 1) {
                    SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 4, 0);
                } else {
                    SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0, 0);
                }
            } else {
                SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, 0x104, 3);
            }
        } else {
            self->field_88 = 0;
            self->field_90 = 0;
            if (a0 < 2) {
                if (a0 == 1) {
                    func_0031ECD0(&D_01E89800, 4, 0);
                } else {
                    func_0031ECD0(&D_01E89800, 0, 0);
                }
            } else {
                func_0031ECD0(&D_01E89800, 0x104, 3);
            }
        }
    }
    return 1;
}
