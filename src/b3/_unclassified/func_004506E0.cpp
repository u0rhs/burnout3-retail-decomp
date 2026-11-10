// Hand-written; the lifter refused it (near7: D_004E0C14 is the shared .lit4 FLT_MAX -> literal 3.402823466e+38f (as B3HelpBarComponent)).


#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"

using namespace GtMathPs2;

struct UnkStruct_D_00665ED0 {
    CGt2dFont *pFont;
    unsigned char pad[0x100];
};
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_D_16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_16 D_01E903E0;
extern UnkStruct_D_16 D_01E90438;
extern UnkStruct_D_16 D_0051BA44;
extern UnkStruct_D_16 D_01E90350;
struct UnkStruct_D_01E90240 { unsigned char pad_0[0x110]; CGtV4d field_110; };
extern UnkStruct_D_01E90240 D_01E90240;
extern "C" void func_00453680(void *, int, int, int);
extern "C" const unsigned short *func_00271A00(void *, int);
extern "C" void *AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void *func_001A3AA0(void *, const unsigned short *, int *);
extern "C" CGt2dObject *ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void func_003D0710(CGt2dObject *obj, const CGtV2d &pos, const CGtV2d &anchor, const void *colour,
                              int a, int b, int c, const CGt2dFont *font, float d, float e, void *str, int f);
extern "C" void Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, const void *, unsigned int);
struct UnkStruct_004506E0_row {
    CGt2dObject *field_0;
    unsigned char pad_4[4];
    void *field_8;
    unsigned char pad_C[4];
    CGt2dObject *field_10;
};
struct UnkStruct_004506E0 {
    unsigned char pad_0[8];
    short field_8;
};

// 0x004506E0
extern "C" void func_004506E0(UnkStruct_004506E0 *self, int row, int id, int s, int mode)
{
    UnkStruct_004506E0_row *r = (UnkStruct_004506E0_row *)((char *)self + row * 0x24 + 0xC);
    CGtV2d pos2;
    CGtV2d size2;
    CGtV2d pos1;
    CGtV2d anc1;
    CGtV2d anc2;
    u_long128 colq;
    void *str;
    func_00453680(self, row, 3, 4);
    if (mode == 1) {
        str = (void *)func_00271A00(&D_0051BA44, id);
    } else {
        str = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x40);
        func_001A3AA0(str, func_00271A00(&D_0051BA44, s), &mode);
    }
    r->field_10 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(&D_01E903E0, self->field_8 + 2, r->field_8);
    anc1.marValues[0] = 0.5f;
    anc1.marValues[1] = 0.5f;
    pos1.marValues[0] = 320.0f;
    pos1.marValues[1] = 0.0f;
    func_003D0710(r->field_10, pos1, anc1, &D_01E90350, 1, 1, 0, D_00665ED0.pFont, 28.0f, 3.402823466e+38f, str, 0);
    pos2 = r->field_0->mObjectSpace.mTopLeftPos;
    size2 = r->field_0->mObjectSpace.mSize;
    pos2.marValues[0] = r->field_10->mObjectSpace.mTopLeftPos.marValues[0] - 30.0f;
    size2.marValues[0] = 30.0f + (30.0f + r->field_10->mObjectSpace.mSize.marValues[0]);
    colq = *(const u_long128 *)&r->field_0->mObjectSpace.mColour;
    anc2.marValues[0] = 0.0f;
    anc2.marValues[1] = 0.0f;
    Prepare__24CB3HUDBackground2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dUi(r->field_0, pos2, anc2, size2, &colq, 3);
}
