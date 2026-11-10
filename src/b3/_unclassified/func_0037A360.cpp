// Hand-written; the lifter refused it (a86: OptimatchMenuPage::SetMode; stride arrays, GetTextSize pointer stored before RenderText, case order 0,1,4,3,2,5 + default).

#include "b3/classes/UnkStruct_D_0051BA44.h"

struct UnkStruct_0037A360_rec {
    int field_0;
    unsigned char pad_4[0x18C];
};

struct UnkStruct_0037A360_cb {
    void * field_0;
    void * field_4;
    unsigned char pad_8[0x34];
};

struct UnkStruct_0037A360 {
    unsigned char pad_0[0x5B8];
    UnkStruct_0037A360_rec field_5B8[1];
    unsigned char pad_748[0xF58];
    UnkStruct_0037A360_cb field_16A0[1];
};

extern UnkStruct_D_0051BA44 D_0051BA44;
extern "C" int func_00271A00(void *, int);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(void *, void *, unsigned short *, void *, const void *);  // CGt2dObjectTable::RenderText(...)
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, void *, const void *);  // CGt2dObjectTable::GetTextSize(...)

// 0x0037A360
extern "C" void func_0037A360(UnkStruct_0037A360 * self, int idx, int mode)
{
    self->field_16A0[idx].field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
    self->field_16A0[idx].field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
    switch (mode) {
    case 0:
        self->field_5B8[idx].field_0 = func_00271A00(&D_0051BA44, 0x2DA);
        break;
    case 1:
        self->field_5B8[idx].field_0 = func_00271A00(&D_0051BA44, 0x2DD);
        break;
    case 4:
        self->field_5B8[idx].field_0 = func_00271A00(&D_0051BA44, 0x2DE);
        break;
    case 3:
        self->field_5B8[idx].field_0 = func_00271A00(&D_0051BA44, 0x2DB);
        break;
    case 2:
        self->field_5B8[idx].field_0 = func_00271A00(&D_0051BA44, 0x2DF);
        break;
    case 5:
        self->field_5B8[idx].field_0 = 0;
        self->field_16A0[idx].field_0 = 0;
        self->field_16A0[idx].field_4 = 0;
        break;
    default:
        self->field_16A0[idx].field_0 = 0;
        self->field_16A0[idx].field_4 = 0;
        break;
    }
}
