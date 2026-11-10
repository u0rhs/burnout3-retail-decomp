// Hand-written; the lifter refused it (a82: flat widget fields, field_BC pointer, char buf[256]={0} zero loop, name ptr set before the call, break-with-store find loops).

// func_0045F630 -- [L] DNAT: CB3CreateAccount2MenuPage::Prepare() (research/proto/new_names.csv, medium)
enum EB3BackgroundType {};

class CB3PromptBarComponent {
public:
    void Prepare();
    unsigned char pad_0[0x10];
};
class CB3OnScreenKeyboardComponent {
public:
    void RegisterKeyboardCallbacks();
    unsigned char pad_0[0x10];
};

struct UnkStruct_D_01EA3078 {
    int field_0;
    int field_4;
    int field_8;
    unsigned char pad_C[0x80];
    unsigned char field_8C;
    unsigned char pad_8D[0x3F];
    char field_CC[0x8];
    unsigned char field_D4;
    unsigned char field_D5;
    unsigned char pad_D6[0x2];
};
struct UnkStruct_0045F630 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    void * field_C;
    unsigned char field_10;
    unsigned char field_11;
    unsigned char field_12;
    unsigned char pad_13[0x1];
    int field_14;
    int field_18;
    int field_1C;
    unsigned short * field_20;
    unsigned char field_24;
    unsigned char field_25;
    unsigned char field_26;
    unsigned char pad_27[0x1];
    int field_28;
    int field_2C;
    int field_30;
    unsigned short * field_34;
    unsigned char field_38;
    unsigned char field_39;
    unsigned char field_3A;
    unsigned char pad_3B[0x1];
    int field_3C;
    int field_40;
    int field_44;
    void * field_48;
    unsigned char field_4C;
    unsigned char field_4D;
    unsigned char field_4E;
    unsigned char pad_4F[0x1];
    int field_50;
    int field_54;
    int field_58;
    void * field_5C;
    unsigned char field_60;
    unsigned char field_61;
    unsigned char field_62;
    unsigned char pad_63[0x1];
    int field_64;
    int field_68;
    int field_6C;
    void * field_70;
    unsigned char field_74;
    unsigned char field_75;
    unsigned char field_76;
    unsigned char pad_77[0x1];
    int field_78;
    int field_7C;
    int field_80;
    int field_84;
    unsigned char field_88;
    unsigned char field_89;
    unsigned char field_8A;
    unsigned char pad_8B[0x1];
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    unsigned char field_9C;
    unsigned char field_9D;
    unsigned char field_9E;
    unsigned char pad_9F[0x1];
    int field_A0;
    int field_A4;
    int field_A8;
    int field_AC;
    unsigned char field_B0;
    unsigned char field_B1;
    unsigned char field_B2;
    unsigned char pad_B3[0x1];
    int field_B4;
    unsigned short field_B8;
    unsigned short field_BA;
    UnkStruct_D_01EA3078 * field_BC;
    unsigned short field_C0;
    unsigned short field_C2;
    unsigned short field_C4;
    unsigned short field_C6;
    unsigned char pad_C8[0x4];
    int field_CC;
    short * field_D0;
    int field_D4;
    unsigned char pad_D8[0x4];
    unsigned char field_DC;
    unsigned char pad_DD[0x7];
    signed char field_E4;
    signed char field_E5;
    unsigned char field_E6;
};
struct UnkStruct_16 { unsigned char pad_0[0x10]; };

extern UnkStruct_16 D_01E90438;
extern UnkStruct_16 D_01E89518;
extern UnkStruct_16 D_01E88A80;
extern UnkStruct_16 D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01EA3078 D_01EA3078;
extern UnkStruct_16 D_0051BA44;
extern UnkStruct_16 D_01E8961C;
extern UnkStruct_16 D_01E3CD44;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern int D_004D383C[];
extern UnkStruct_16 D_004D3870;
extern UnkStruct_16 D_004D38A0;
extern UnkStruct_16 D_004D3790;
extern UnkStruct_16 D_004D37F0;
extern char D_004D37C0[];
extern char D_004D3820[];
extern char D_004D38D0[];

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_00271A00(void *, int);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);
extern "C" void func_003BC540(void *, int, int);
extern "C" int strcasecmp(const char *, const char *);
extern "C" int func_0033A730(void *, char *, int);
extern "C" void func_00336150(void *, char *, int);
extern "C" int func_003517F0(void *);

// 0x0045F630
extern "C" int func_0045F630(UnkStruct_0045F630 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    self->field_D4 = 0;
    self->field_CC = 0;
    self->field_D0 = (short *)AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x40);
    *self->field_D0 = 0;
    func_00319C80(&D_01E89518, 0x3EF, 0xE);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 0x101, 3);
    D_01E894FC.Prepare();
    self->field_BC = &D_01EA3078;
    self->field_BC->field_8C = 0;
    self->field_B8 = 0;
    self->field_BA = 9;
    self->field_4 = func_00271A00(&D_0051BA44, 0x3F0);
    self->field_C = &D_004D3870;
    self->field_10 = 0xC;
    self->field_11 = 4;
    self->field_12 = 0;
    self->field_14 = 0;
    self->field_8 = 0;
    self->field_C0 = 1;
    self->field_C2 = D_004D383C[self->field_BC->field_0];
    self->field_C4 = 0x76C;
    self->field_C6 = 0x7D4;
    self->field_18 = func_00271A00(&D_0051BA44, 0x3F1);
    self->field_20 = &self->field_C0;
    self->field_24 = self->field_C2 - self->field_C0;
    self->field_25 = 5;
    self->field_26 = 0;
    self->field_28 = 0;
    self->field_1C = 0;
    self->field_2C = func_00271A00(&D_0051BA44, 0x3F2);
    self->field_34 = &self->field_C4;
    self->field_38 = self->field_C6 - self->field_C4;
    self->field_39 = 5;
    self->field_3A = 0;
    self->field_3C = 0;
    self->field_30 = 0;
    self->field_40 = func_00271A00(&D_0051BA44, 0x3F3);
    self->field_48 = &D_004D38A0;
    self->field_4C = 2;
    self->field_4D = 4;
    self->field_4E = 0;
    self->field_50 = 0;
    self->field_44 = 0;
    self->field_54 = func_00271A00(&D_0051BA44, 0x3F6);
    self->field_5C = &D_004D3790;
    self->field_60 = 0xB;
    self->field_61 = 4;
    self->field_62 = 0;
    self->field_64 = 0;
    self->field_58 = 0;
    self->field_68 = func_00271A00(&D_0051BA44, 0x402);
    self->field_70 = &D_004D37F0;
    self->field_74 = 0xA;
    self->field_75 = 4;
    self->field_76 = 0;
    self->field_78 = 0;
    self->field_6C = 0;
    self->field_7C = func_00271A00(&D_0051BA44, 0x3DE);
    self->field_84 = 0;
    self->field_88 = 0;
    self->field_89 = 0;
    self->field_8A = 0;
    self->field_8C = 0;
    self->field_80 = 0;
    self->field_90 = func_00271A00(&D_0051BA44, 0x40D);
    self->field_98 = 0;
    self->field_9C = 0;
    self->field_9D = 6;
    self->field_9E = 0;
    self->field_A0 = 0;
    self->field_94 = 0;
    bool b = !(self->field_BC->field_D5 != 0);
    self->field_A4 = func_00271A00(&D_0051BA44, 0x40E);
    self->field_AC = 0;
    self->field_B0 = 0;
    self->field_B1 = 0;
    self->field_B2 = b;
    self->field_B4 = 0;
    self->field_A8 = 0;
    func_003BE5A0(&D_01E8961C, &self->field_B8, &self->field_4);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, self->field_BC->field_0 - 1);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, self->field_BC->field_4);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 2, self->field_BC->field_8);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 3, !(self->field_BC->field_D4 != 0));
    for (int i = 0; i < 11; i++) {
        if (strcasecmp(self->field_BC->field_CC, D_004D37C0 + i * 3) == 0) {
            self->field_E4 = i;
            break;
        }
    }
    for (int j = 0; j < 10; j++) {
        if (strcasecmp(self->field_BC->field_CC + 3, D_004D3820 + j * 3) == 0) {
            self->field_E5 = j;
            break;
        }
    }
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 4, self->field_E4);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 5, self->field_E5);
    func_003BC540(&D_01E8961C, 7, self->field_BC->field_D5);
    self->field_DC = 0;
    self->field_E6 = 0;
    char buf[256] = {0};
    char * name = D_004D38D0;
    func_0033A730(&D_01E3CD44, buf, 0x100);
    if (buf[0] != 0) {
        name = buf;
    }
    func_00336150(&D_01E3CD44, name, 0x708);
    func_003517F0(&D_01E899C0);
    D_01E899C0.RegisterKeyboardCallbacks();
    return 1;
}
