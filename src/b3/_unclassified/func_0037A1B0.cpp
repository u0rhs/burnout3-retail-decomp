// Hand-written; the lifter refused it ([L] DNAT CB3OnlineNewsMenuPage::Prepare (low); buf[256]={0} declared late; 16-byte padded rodata externs).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
enum EGlobalStrings {};
struct UnkStruct_D_0x10 { unsigned char pad_0[0x10]; };
struct UnkStruct_7A1B0 {
    unsigned char pad_0[0x4];
    const unsigned short *field_4;
    unsigned char field_8;
    unsigned char field_9;
    unsigned char pad_A[0x2];
    const unsigned short *field_C;
    unsigned char field_10;
    unsigned char field_11;
    unsigned char pad_12[0x2];
    short field_14;
    short field_16;
    short field_18;
    short field_1A;
    int field_1C;
    int field_20;
    unsigned char pad_24[0x4];
    int field_28;
};
extern UnkStruct_D_0x10 D_01E89518, D_01E88A80, D_01E894FC, D_01E8D4F0, D_01E8EAF8, D_0051BA44, D_01E89544, D_01E3CD44;
extern UnkStruct_D_0x10 D_004C90E0, D_004C90E8, D_004C90F0, D_004C90F8;
struct UnkStruct_D_004C9100 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004C9100 D_004C9100;
extern char D_004C9110[];
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" void func_00319C80(void *, int, int);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" void Prepare__21CB3PromptBarComponentFv(void *);
extern "C" void Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d14EGlobalStringsUi(void *, const void *, const void *, EGlobalStrings, unsigned int);
extern "C" int GetNumLines__20CB3PageTextComponentFv(void *);
extern "C" void Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(void *, const void *, const void *, float, const void *);
extern "C" const unsigned short * func_00271A00(void *, int);
extern "C" void Prepare__19CB3VSelectComponentFfPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, float, float, const void *, const void *);
extern "C" int func_0033A6A0(void *, char *, int);
extern "C" void func_00336150(void *, const char *, int);
// 0x0037A1B0
extern "C" int func_0037A1B0(UnkStruct_7A1B0 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, false);
    self->field_20 = 0;
    self->field_1C = 0;
    func_00319C80(&D_01E89518, 0x3DC, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 0);
    Prepare__21CB3PromptBarComponentFv(&D_01E894FC);
    Prepare__20CB3PageTextComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d14EGlobalStringsUi(&D_01E8D4F0, &D_004C90E0, &D_004C90E8, (EGlobalStrings)0x3DF, 0x65);
    int nl = GetNumLines__20CB3PageTextComponentFv(&D_01E8D4F0);
    self->field_18 = 0;
    self->field_1A = nl;
    Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, &D_004C90F0, &D_004C90F8, D_004C9100.field_0, &self->field_18);
    self->field_14 = 0;
    self->field_16 = 2;
    self->field_4 = func_00271A00(&D_0051BA44, 0x3DD);
    self->field_8 = 0;
    self->field_9 = 0;
    self->field_C = func_00271A00(&D_0051BA44, 0x3DE);
    self->field_10 = 0;
    self->field_11 = 0;
    Prepare__19CB3VSelectComponentFfPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, 368.0f, 640.0f, &self->field_14, &self->field_4);
    char buf[256] = {0};
    const char *p = D_004C9110;
    func_0033A6A0(&D_01E3CD44, buf, 0x100);
    if (buf[0] != 0) p = buf;
    func_00336150(&D_01E3CD44, p, 0x708);
    self->field_28 = 2;
    return 1;
}
