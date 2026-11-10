// Hand-written; the lifter refused it (near15: .lit4 D_004E0CC4 as literal 179.2f).

// func_00438520 -- page Prepare (hand-written, a135 + near15). The last func_00351F00 argument is the .lit4 float
// 179.2f (D_004E0CC4) written as a literal (.lit4 rule): the extern form scheduled its load after the stack stores.
// Types are placeholders [G].

enum EB3BackgroundType {};
#include "b3/classes/CB3PromptBarComponent.h"
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };
struct UnkStruct_a { int field_0; };
struct UnkStruct_E { int field_0; unsigned char field_4; unsigned char field_5; unsigned char pad_6[2]; };
struct UnkStruct_Sel { short field_0; short field_2; };
struct UnkStruct_D_004B0334 { UnkStruct_E field_0[1]; unsigned char pad_8[8]; };
struct UnkStruct_00438520 {
    unsigned char pad_0[4];
    UnkStruct_E field_4[8];
    UnkStruct_Sel field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
};
extern UnkStruct_P16 D_01E88A80;
extern UnkStruct_P16 D_01E89800;
extern UnkStruct_P16 D_01E90438;
extern UnkStruct_P16 D_0051BA44;
extern UnkStruct_P16 D_004D1C30;
extern UnkStruct_P16 D_01E89518;
extern UnkStruct_P16 D_01E89788;
extern UnkStruct_P16 D_01E89544;
extern UnkStruct_P16 D_01E8D4B0;
extern UnkStruct_P16 D_004D1C08;
extern UnkStruct_P16 D_004D1C10;
extern UnkStruct_P16 D_004D1C18;
extern UnkStruct_P16 D_004D1C20;
extern UnkStruct_P16 D_004D1C28;
extern UnkStruct_D_004B0334 D_004B0334;
extern UnkStruct_E D_004B0330[];
extern CB3PromptBarComponent D_01E894FC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(int, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_004387C0(int, void *, const UnkStruct_a *, const void *);
extern "C" void Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(void *, void *, int);
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short *, bool, float);
extern "C" void Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, bool, float, float, float, float, const void *, void *, float, int);
extern "C" bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);

// 0x00438520
extern "C" int func_00438520(UnkStruct_00438520 * self, void *p0_, int p1)
{
    int p0 = (int)p0_;
    UnkStruct_a l6C;
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_54 = p1;
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 261, 3);
    D_01E894FC.Prepare();
    self->field_48 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
    self->field_4C = p0;
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(self->field_4C, self->field_48, 32);
    int s0 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 64);
    l6C.field_0 = func_00271A00(&D_0051BA44, 1088);
    func_004387C0(s0, &D_004D1C30, &l6C, &self->field_48);
    Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(&D_01E89518, (void *)(s0), 14);
    if (self->field_54 == 1) goto one;
    if (self->field_54 == 0) {
        self->field_44.field_0 = 0;
        self->field_44.field_2 = 7;
    } else {
        self->field_44.field_0 = 0;
        self->field_44.field_2 = 8;
    }
    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short *)func_00271A00(&D_0051BA44, D_004B0334.field_0[0].field_0), 0, 80.0f);
    int i = 0;
    goto test;
body:
    {
        UnkStruct_E *e = (UnkStruct_E *)((char *)self + i * 8 + 4);
        e->field_0 = func_00271A00(&D_0051BA44, D_004B0330[i].field_0);
        i++;
        e->field_4 = 0;
        e->field_5 = 0;
    }
test:
    if (i < 8) goto body;
vsel:
    Prepare__19CB3VSelectComponentFbffffPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, 0, 84.0f, 240.0f, 30.0f, 40.0f, &self->field_44, &self->field_4[0], 256.0f, 0);
    func_00351F00(&D_01E8D4B0, &D_004D1C08, &D_004D1C10, &D_004D1C18, &D_004D1C20, &D_004D1C28, 973, 3, 1, 3, 0, 24.0f, 179.2f);
    self->field_50 = 0;
    return 1;
one:
    self->field_44.field_0 = 0;
    self->field_44.field_2 = 1;
    self->field_4[0].field_0 = func_00271A00(&D_0051BA44, 3090);
    self->field_4[0].field_4 = 0;
    self->field_4[0].field_5 = 0;
    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short *)func_00271A00(&D_0051BA44, 3091), 0, 80.0f);
    goto vsel;
}
