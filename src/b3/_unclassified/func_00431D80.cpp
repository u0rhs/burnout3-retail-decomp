// Hand-written; the lifter refused it (a135: music-page Prepare; locals l3C,l38,l34 declared in that order).

#include "b3/classes/CB3PromptBarComponent.h"
#include "b3/classes/EB3BackgroundType.h"
struct UnkStruct_D_01E7A888 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E89518 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E89800 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E88A80 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004F507A { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_00431D80_e {
    unsigned char pad_0[0xC];
    unsigned short field_C[2];
    unsigned char pad_10[0x40];
    int field_50;
    unsigned char field_54;
};
struct UnkStruct_00431D80 {
    unsigned char pad_0[0x938];
    int field_938;
    int field_93C;
    unsigned char pad_940[8];
    int field_948;
    unsigned char pad_94C[0x14];
    int field_960;
    int field_964;
    unsigned char pad_968[0x50];
    int field_9B8;
    UnkStruct_00431D80_e *field_9BC;
    int field_9C0;
};
extern UnkStruct_D_01E7A888 D_01E7A888;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_004F507A D_004F507A;
extern CB3PromptBarComponent D_01E894FC;
extern unsigned int D_004D19F0[];
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" void Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(void *, const unsigned short *, int);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);
extern "C" void func_003FC040(int, void *, void *, void *);
extern "C" void func_003FA600(void *, int);
extern "C" void func_003FC470(void *);
extern "C" void func_003FBB50(void *, int, void *);
extern "C" int func_003FC060(void *, void *, int, int);
extern "C" void func_003FBC20(int, int);
extern "C" void func_003FBB00(int, int, void *, void *, int, int);
extern "C" void func_003FC520(void *);
extern "C" void func_00431860(void *);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

// 0x00431D80
extern "C" int func_00431D80(UnkStruct_00431D80 * self)
{
    int l3C;
    int l38;
    int l34;
    int s0;
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_9B8 = (int)&D_01E7A888;
    func_003FC040(self->field_9B8, &self->field_9BC, &l38, &l3C);
    if (D_004F507A.field_0 != 0) {
        self->field_9C0 = 2;
        s0 = 1;
    } else {
        self->field_9C0 = 1;
        s0 = 0;
    }
    self->field_93C = self->field_9BC->field_50;
    self->field_938 = 0;
    if (self->field_9BC->field_54 == 0) {
        Prepare__19CB3HeadingComponentFPCUsQ219CB3HeadingComponent12EHeadingType(&D_01E89518, self->field_9BC->field_C, 14);
        func_0031ECD0(&D_01E89800, D_004D19F0[s0], 3);
    } else {
        func_00319C80(&D_01E89518, 0x199, 14);
        func_0031ECD0(&D_01E89800, D_004D19F0[s0], 15);
    }
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)9);
    D_01E894FC.Prepare();
    func_003FA600(&D_01E7A888, 3);
    s0 = self->field_9BC->field_50;
    func_003FC470((void *)(self->field_9B8));
    func_003FBB50((void *)(self->field_9B8), s0, &self->field_960);
    if (self->field_964 == 0) {
        self->field_9BC = (UnkStruct_00431D80_e *)&self->field_960;
        s0 = self->field_938;
    } else {
        func_003FC060((void *)(self->field_9B8), &self->field_960, 0, self->field_9C0);
        func_003FC040(self->field_9B8, &self->field_9BC, &l34, &self->field_9C0);
        s0 = self->field_938;
    }
    func_003FC470((void *)(self->field_9B8));
    func_003FBC20(self->field_9B8, s0);
    func_003FBB00(self->field_9B8, s0, self->field_9BC, &self->field_948, 0, 0);
    func_003FC520((void *)(self->field_9B8));
    func_00431860(self);
    return 1;
}
