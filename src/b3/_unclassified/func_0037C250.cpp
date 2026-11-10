// Hand-written; the lifter refused it (a83: CB3OnlineOptimatchMenuPage::Prepare [L] DNAT; entry via byte-offset base, split first alloc).

// func_0037C250 -- CB3OnlineOptimatchMenuPage::Prepare(bool) [L] DNAT (research/proto/new_names.csv, medium; retail takes two extra ints).
enum EB3BackgroundType {};
class CB3PromptBarComponent {
public:
    void Prepare();
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E3D596 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E3CD44 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0(int, int, int, void *, void *);
    unsigned char pad_4[0xC];
};
struct UnkStruct_0037C250_ent {
    unsigned char pad_0[0x60];
    char field_0[0x20];
    unsigned long field_20;
    unsigned long field_28;
    int field_30;
    int field_34;
    unsigned char pad_38[4];
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    unsigned char pad_4C[4];
};
struct UnkStruct_0037C250 {
    unsigned char pad_0[0x60];
    unsigned char field_60[9 * 0x50];
    short field_330;
    short field_332;
    unsigned char pad_334[0x1520 - 0x334];
    int field_1520[10];
    int field_1548[10];
    int field_1570;
    int field_1574;
    unsigned char pad_1578[0x1920 - 0x1578];
    int field_1920;
    int field_1924;
    int field_1928;
    unsigned char field_192C[4];
    int field_1930;
    int field_1934;
    int field_1938;
    unsigned char pad_193C[4];
    unsigned char field_1940;
    unsigned char pad_1941;
    unsigned char field_1942;
};
extern UnkStruct_D_Pad16 D_01E90438, D_0051BA44, D_01E89518, D_01E88A80, D_01E89800, D_01E899C0, D_01E89788, D_01E8D4B0;
extern UnkStruct_D_Pad16 D_004C9148, D_004C9150, D_004C9158, D_004C9160, D_004C9168;
extern UnkStruct_D_01E3D596 D_01E3D596;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern CB3PromptBarComponent D_01E894FC;
extern char D_004C9218[];

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short *, bool, float);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_00271A00(void *, int);
extern "C" int Length__10CGtUnicodeFPCUs(int);
extern "C" int func_003517F0(void *);
extern "C" void SetupTable__26CB3OnlineOptimatchMenuPageFv(void *);
extern "C" int func_00339380(void *, void *);
extern "C" int func_0037C1C0(int, void *);
extern "C" bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);
extern "C" int sprintf(char *, const void *, ...);

// [L] DNAT: CB3OnlineOptimatchMenuPage::Prepare(bool) (research/proto/new_names.csv, medium)
// 0x0037C250
extern "C" int func_0037C250(UnkStruct_0037C250 *self, int p0, void *p1_)
{
    int p1 = (int)p1_;
    Prepare__15CB3MenuPageBaseFb(self, 0);
    D_01E3D596.field_0 = 0;
    for (int i = 1; i < 10; i++) {
        int a = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
        int *pa = &self->field_1548[i];
        *pa = a;
        self->field_1520[i] = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 6);
    }
    self->field_1570 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
    self->field_1574 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, Length__10CGtUnicodeFPCUs(func_00271A00(&D_0051BA44, 98)) + 32);
    self->field_1928 = p0;
    self->field_1924 = p1;
    if (self->field_1928 == 1) {
        func_00319C80(&D_01E89518, 90, 14);
    } else {
        func_00319C80(&D_01E89518, 3163, 14);
    }
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 65, 0);
    D_01E894FC.Prepare();
    func_003517F0(&D_01E899C0);
    SetupTable__26CB3OnlineOptimatchMenuPageFv(self);
    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short *)func_00271A00(&D_0051BA44, 95), 1, 80.0f);
    func_00351F00(&D_01E8D4B0, &D_004C9148, &D_004C9150, &D_004C9158, &D_004C9160, &D_004C9168, 95, 3, 1, 103, 0, 32.0f, 496.0f);
    self->field_1942 = 0;
    self->field_330 = 0;
    self->field_332 = 1;
    self->field_1920 = 0;
    for (int i = 0; i < 9; i++) {
        UnkStruct_0037C250_ent *e = (UnkStruct_0037C250_ent *)((char *)self + i * 0x50);
        e->field_30 = -1;
        sprintf(e->field_0, D_004C9218);
        e->field_20 = 0;
        e->field_28 = 0;
        e->field_3C = 0;
        e->field_40 = 0;
        e->field_34 = 0x7FFFFFFF;
        e->field_44 = 0;
        e->field_48 = -1;
    }
    ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_C0(500, -1, 0, (void *)&func_0037C1C0, self);
    func_00339380(&D_01E3CD44, self->field_192C);
    self->field_1934 = -1;
    self->field_1938 = 0;
    self->field_1940 = 0;
    self->field_1930 = 0;
    return 1;
}
