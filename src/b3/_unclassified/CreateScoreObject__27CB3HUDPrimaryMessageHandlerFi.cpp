// Hand-written; the lifter refused it (mwperm: +'UnkStruct_003D53E0 * v0 = self;'; 'while (p0 >= p) { p = p * 10;' -> 'UnkStruct_003D53E0_2 * t7; CGtV2d pos; goto loop0_t; loop0: unsigned int t3; t3 '; 'CGtV2d pos = self->field_18; pos.SetX(12.0f + (0.0f + pos.X(' -> 'pos = self->field_18; float t4 = pos.X(); float t8 = ((0.0f + t4) + 0.5f * self-'; +'p = D_00665ED0.field_0; UnkStruct_003D53E0_2 * t1 = v0->field_14; UnkStruct_003D'; 'UnkStruct).

// Hand-written; lifter refused (a88: CB3HUDPrimaryMessageHandler::CreateScoreObject(int)).
// [L] DNAT: CB3HUDPrimaryMessageHandler::CreateScoreObject(int) (research/proto/new_names.csv, high)
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV2d;

struct UnkStruct_003D53E0_1 { unsigned char pad_0[0x38]; int field_38; };
struct UnkStruct_003D53E0_3 { unsigned char pad_0[0xC]; int field_C; float field_10; };
struct UnkStruct_003D53E0_2 {
    unsigned char pad_0[0x20];
    UnkStruct_003D53E0_3 field_20;
};
struct UnkStruct_003D53E0 {
    int field_0;
    int field_4;
    unsigned char pad_8[0x4];
    UnkStruct_003D53E0_1 * field_C;
    unsigned char pad_10[0x4];
    UnkStruct_003D53E0_2 * field_14;
    CGtV2d field_18;
    float field_20;
    unsigned char pad_24[0x118];
    unsigned short field_13C[1];
};
struct UnkStruct_D_00665ED0 { int field_0; unsigned char pad_4[0xC]; };
extern GtMathPs2::CGtV4d D_0066A4E0;
extern UnkStruct_D_00665ED0 D_00665ED0;
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void _Render__16CB3Score2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv(void *, const void *);
extern "C" void PrepareCommonData__15CGt2dObjectTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(void *, const void *, const void *, float, GtMathPs2::CGtV4d, void *, const unsigned short *, void *);

// 0x003D53E0
extern "C" void CreateScoreObject__27CB3HUDPrimaryMessageHandlerFi(UnkStruct_003D53E0 * self, int p0)
{
    UnkStruct_003D53E0 * v0 = self;
    int p = 10;
    unsigned short * w = self->field_13C;
    UnkStruct_003D53E0_2 * t7;
    CGtV2d pos;
    goto loop0_t;
loop0:
    unsigned int t3;
    t3 = t3;
    p = p * 10;
        
loop0_t:
    if (p <= p0) {
        goto loop0;
    }
    do {
        p = p / 10;
        int d = p0 / p;
        *w++ = d + '0';
        p0 = p0 - d * p;
    } while (p >= 2);
    *w = 0;
    pos = self->field_18;
    float t4 = pos.X();
    float t8 = ((0.0f + t4) + 0.5f * self->field_20) + 12.0f;
    float t6 = t8;
    pos.SetX(t6);
    UnkStruct_003D53E0_1 * t0 = v0->field_C;
    void * t5 = (void *)v0->field_0;
    t7 = (UnkStruct_003D53E0_2 *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(t5, v0->field_4, (void *)t0->field_38);
    t5 = (void *)_Render__16CB3Score2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv;
    self->field_14 = (0, t7);
    CGtV2d align(0.0f, 0.5f);
    p = D_00665ED0.field_0;
    UnkStruct_003D53E0_2 * t1 = v0->field_14;
    UnkStruct_003D53E0_2 * t10 = v0->field_14;
    UnkStruct_003D53E0_3 * q = &t10->field_20;
    GtMathPs2::CGtV4d col = D_0066A4E0;
    PrepareCommonData__15CGt2dObjectTextFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfQ29GtMathPs26CGtV4dPC9CGt2dFontPCUsPFRCQ211CGt2dObject16CGt2dObjectSpacePCv_v(t1, &pos, &align, 32.0f, col, (void *)(D_00665ED0.field_0), self->field_13C, (void *)_Render__16CB3Score2dObjectFRCQ211CGt2dObject16CGt2dObjectSpacePCv);
    q->field_C = 0;
    q->field_10 = 1.0f;
}
