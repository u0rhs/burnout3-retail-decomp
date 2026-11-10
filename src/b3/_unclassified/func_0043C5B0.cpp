// Hand-written; the lifter refused it (a135: jtbl switch (default shares case 0/7/11/16 block, source order by block address); vfunc_3C returns int (header says void)).

#include "b3/classes/CB3PromptBarComponent.h"
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };
struct UnkStruct_5 {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38();
    virtual int vfunc_3C();
};
struct UnkStruct_4 {
    unsigned char pad_0[0x68];
    unsigned long field_68;
    unsigned char pad_70[0x144];
    UnkStruct_5 *field_1B4;
};
struct UnkStruct_D_0051BA88 { UnkStruct_4 *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E65499 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_0043C5B0 {
    unsigned char pad_0[4];
    unsigned char field_4;
    unsigned char field_5;
};
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_01E65499 D_01E65499;
extern UnkStruct_P16 D_01E89518;
extern UnkStruct_P16 D_01E89800;
extern UnkStruct_P16 D_01E8E550;
extern UnkStruct_P16 D_0051BA44;
extern UnkStruct_P16 D_01E89788;
extern CB3PromptBarComponent D_01E894FC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int FindCrashStageName__26CB3HardCodedCrashStageListFUl(unsigned long);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_0039C570(void *, int);
extern "C" int func_00271A00(void *, int);
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short *, bool, float);

// 0x0043C5B0
extern "C" int func_0043C5B0(UnkStruct_0043C5B0 * self, int p0, int p1)
{
    UnkStruct_4 *g = D_0051BA88.field_0;
    int s1 = g->field_1B4->vfunc_3C();
    int id;
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_4 = p0;
    self->field_5 = p1;
    if (self->field_5 != 0) {
        self->field_4 = 0;
    }
    switch (s1) {
    case 0:
    case 7:
    case 11:
    case 16:
    default:
        id = 0x15F;
        break;
    case 1:
        id = 0x10E;
        break;
    case 2:
    case 9:
    case 12:
    case 17:
        id = 0x160;
        break;
    case 3:
        id = 0x110;
        break;
    case 5:
        id = 0x112;
        break;
    case 4:
        id = 0x111;
        break;
    case 6:
    case 10:
    case 13:
    case 14:
    case 15:
    case 18:
    case 19:
    case 20:
        id = FindCrashStageName__26CB3HardCodedCrashStageListFUl(g->field_68);
        break;
    case 8:
        id = 0x161;
        break;
    }
    func_00319C80(&D_01E89518, id, 5);
    if (self->field_4 != 0) {
        func_0031ECD0(&D_01E89800, 16, 3);
    } else {
        func_0031ECD0(&D_01E89800, 0, 3);
    }
    D_01E894FC.Prepare();
    func_0039C570(&D_01E8E550, s1);
    if (D_01E65499.field_0 != 0) {
        Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short *)func_00271A00(&D_0051BA44, 0x55B), 0, 80.0f);
    }
    return 1;
}
