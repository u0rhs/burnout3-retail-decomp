// Hand-written; the lifter refused it (a152: CB3OnlineGameCreateOptionsPage::Prepare [L]; item array stride 0x14; hi local loaded after item-4 call).

// func_00399130 -- [L] DNAT: CB3OnlineGameCreateOptionsPage::Prepare() (research/proto/new_names.csv, low)
class CB3PromptBarComponent {
public:
    void Prepare();
    unsigned char pad_0[0x10];
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_S3 { short field_0; short field_2; short field_4; };
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E8D4B0 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_00399130_item {
    void *field_0;
    void *field_4;
    void *field_8;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char field_E;
    int field_10;
};
struct UnkStruct_00399130 {
    unsigned char pad_0[0x4];
    const char *field_4;
    const char *field_8;
    int field_C;
    unsigned char pad_10[0x10];
    unsigned char field_20;
    unsigned char pad_21[0x1F];
    unsigned short field_40;
    unsigned short field_42;
    UnkStruct_00399130_item field_44[4];
    unsigned short field_94;
    unsigned short field_96;
    unsigned short * field_98;
    unsigned short * field_9C;
    unsigned short * field_A0;
    unsigned short * field_A4;
    unsigned short * field_A8;
    char field_AC[0x20];
    char field_CC[0x11];
    unsigned char pad_DD[0x3];
    int field_E0;
    int field_E4;
    int field_E8;
};
struct UnkStruct_D_01EA2874 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_P D_01E90438, D_01E89518, D_01E88A80, D_01E89800, D_01E899C0, D_0051BA44, D_01E8961C, D_01E94C40;
extern UnkStruct_D_01EA2874 D_01EA2874;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E8D4B0 D_01E8D4B0;
extern UnkStruct_B D_01E8D4BA;
extern UnkStruct_S3 D_004E1E78;
extern UnkStruct_P D_004C99A0, D_004C99B0, D_004C99B8, D_004C99C0, D_004C99C8;
extern UnkStruct_F D_004C99D0;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" unsigned short * AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_003517F0(void *);
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, unsigned short *, int);
extern "C" unsigned short * func_00271A00(void *, int);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);
extern "C" int AppendN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, unsigned short *);
extern "C" bool func_00351E40(void *, void *, void *, void *, void *, void *, void *, int, int, int, int, float, float);

// 0x00399130
extern "C" int func_00399130(UnkStruct_00399130 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_98 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x20);
    self->field_9C = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x11);
    self->field_A0 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x20);
    self->field_A4 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x11);
    self->field_9C = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x11);
    self->field_A8 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x80);
    func_00319C80(&D_01E89518, 1068, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 0);
    func_0031ECD0(&D_01E89800, 273, 3);
    D_01E894FC.Prepare();
    func_003517F0(&D_01E899C0);
    self->field_94 = 2;
    self->field_96 = 8;
    self->field_E0 = 0;
    self->field_E4 = self->field_20;
    self->field_E8 = self->field_C;
    if (self->field_4 != 0) {
        strncpy(self->field_AC, self->field_4, 0x20);
    } else {
        strncpy(self->field_AC, (const char *)&D_01E94C40 + D_01EA2874.field_0 * 32 + 0xDC3C, 0x20);
    }
    if (self->field_8 != 0) {
        strncpy(self->field_CC, self->field_8, 0x11);
    } else {
        self->field_CC[0] = 0;
    }
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(self->field_AC, self->field_98, 0x20);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(self->field_CC, self->field_9C, 0x11);
    self->field_40 = 0;
    self->field_42 = 4;
    {
        unsigned short *s = self->field_98;
        self->field_44[0].field_0 = func_00271A00(&D_0051BA44, 974);
        self->field_44[0].field_8 = s;
        self->field_44[0].field_C = 1;
        self->field_44[0].field_D = 2;
        self->field_44[0].field_E = 0;
        self->field_44[0].field_10 = 0;
        self->field_44[0].field_4 = 0;
        self->field_44[0].field_4 = self->field_A0;
    }
    {
        unsigned short *s = self->field_9C;
        self->field_44[1].field_0 = func_00271A00(&D_0051BA44, 975);
        self->field_44[1].field_8 = s;
        self->field_44[1].field_C = 1;
        self->field_44[1].field_D = 2;
        self->field_44[1].field_E = 0;
        self->field_44[1].field_10 = 0;
        self->field_44[1].field_4 = 0;
        self->field_44[1].field_4 = self->field_A4;
    }
    {
        self->field_44[2].field_0 = func_00271A00(&D_0051BA44, 976);
        self->field_44[2].field_8 = &D_004C99A0;
        self->field_44[2].field_C = 4;
        self->field_44[2].field_D = 4;
        self->field_44[2].field_E = 0;
        self->field_44[2].field_10 = 0;
        self->field_44[2].field_4 = 0;
    }
    unsigned short hi;
    {
        self->field_44[3].field_0 = func_00271A00(&D_0051BA44, 977);
        self->field_44[3].field_8 = &self->field_94;
        hi = self->field_96;
        self->field_44[3].field_C = hi - self->field_94;
        self->field_44[3].field_D = 5;
        self->field_44[3].field_E = 0;
        self->field_44[3].field_10 = 0;
        self->field_44[3].field_4 = 0;
    }
    func_003BE5A0(&D_01E8961C, &self->field_40, &self->field_44[0]);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 2, self->field_E4);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 3, self->field_E8);
    UnkStruct_S3 buf = D_004E1E78;
    *self->field_A8 = 0;
    AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, func_00271A00(&D_0051BA44, 987));
    if (self->field_E8 < 7) {
        AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, func_00271A00(&D_0051BA44, 730));
        AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, (unsigned short *)&buf);
        AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, func_00271A00(&D_0051BA44, 733));
        AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, (unsigned short *)&buf);
        if (self->field_E8 == 2) {
            AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, func_00271A00(&D_0051BA44, 735));
            AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, (unsigned short *)&buf);
            AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, func_00271A00(&D_0051BA44, 731));
            AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, (unsigned short *)&buf);
        }
    }
    AppendN__10CGtUnicodeFPUsiPCUs(self->field_A8, 0x80, func_00271A00(&D_0051BA44, 734));
    if (D_01E8D4BA.field_0 != 0) {
        ((UnkStruct_D_01E8D4B0 *)&D_01E8D4B0)->vfunc_C();
    }
    func_00351E40(&D_01E8D4B0, &D_004C99B0, &D_004C99B8, &D_004C99C0, &D_004C99C8, &D_004C99D0, (void *)self->field_A8, 3, 1, 3, 0, 26.0f, D_004C99D0.field_0 - 16.0f);
    return 1;
}
