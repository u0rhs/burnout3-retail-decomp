// Hand-written; the lifter refused it (CB3CreateAccount*MenuPage Prepare-like: item-init static inline (buf evaluated before call), const offset held in an int assigned separately in both if arms to force hoisted s0 constant).

enum EB3BackgroundType {};
class CB3PromptBarComponent {
public:
    void Prepare();
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_F_info {
    unsigned char pad_0[0xC];
    char field_C[0x20];
    char field_2C[0x20];
    char field_4C[0x80];
    char field_CC[0x6];
    unsigned char field_D2;
    unsigned char field_D3;
    unsigned char field_D4;
    unsigned char field_D5;
    unsigned char pad_D6[0xA];
};
struct UnkStruct_F_item {
    int field_0;
    int field_4;
    unsigned short * field_8;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char field_E;
    int field_10;
};
struct UnkStruct_F_tmp {
    char * field_0;
    char * field_4;
    char * field_8;
    unsigned char pad_C[0x14];
    unsigned char field_20;
    unsigned char field_21;
};
struct UnkStruct_0037F640 {
    unsigned char pad_0[0x4];
    char field_4[0x20];
    UnkStruct_F_item field_24[7];
    unsigned short * field_B0;
    unsigned short * field_B4;
    unsigned short * field_B8;
    unsigned short * field_BC;
    short field_C0;
    short field_C2;
    UnkStruct_F_info * field_C4;
    unsigned char field_C8;
    unsigned char field_C9;
};
extern UnkStruct_D_Pad16 D_01E90438, D_01E88A80, D_01E89800, D_0051BA44, D_01E89518, D_01E3CD44, D_01E8961C, D_01E899C0, D_004EE040;
extern UnkStruct_F_info D_01EA3078;
extern CB3PromptBarComponent D_01E894FC;
extern char D_004C92C8[];

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);
extern "C" void RegisterKeyboardCallbacks__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" unsigned short * AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(void *, void *, int);
extern "C" int func_00271A00(void *, int);
extern "C" int func_003517F0(void *);
extern "C" void func_0033ACD0(void *, void *);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" void func_003BC540(void *, int, int);
extern "C" void func_003BC360(void *, int, int);
extern "C" int func_0037E440(void *);
extern "C" unsigned int strlen(const char *);
extern "C" char * strncpy(char *, const char *, unsigned int);

static inline void func_0037F640_inl1(UnkStruct_F_item * it, unsigned short * buf, void * tbl, int id, unsigned char a, unsigned char b, unsigned char c)
{
    it->field_0 = func_00271A00(tbl, id);
    it->field_8 = buf;
    it->field_C = a;
    it->field_D = b;
    it->field_E = c;
    it->field_10 = 0;
    it->field_4 = 0;
}

// 0x0037F640
extern "C" int func_0037F640(UnkStruct_0037F640 * self, bool p0)
{
    Prepare__15CB3MenuPageBaseFb(self, false);
    self->field_C9 = p0;
    self->field_B0 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
    self->field_B0[0] = 0;
    self->field_B4 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
    self->field_B4[0] = 0;
    self->field_B8 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
    self->field_B8[0] = 0;
    self->field_BC = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 64);
    self->field_BC[0] = 0;
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 257, 3);
    D_01E894FC.Prepare();
    self->field_C4 = &D_01EA3078;
    if (self->field_C9 != 0) {
        UnkStruct_F_tmp tmp;
        func_0033ACD0(&D_01E3CD44, &tmp);
        strncpy(D_01EA3078.field_C, tmp.field_0, 32);
        strncpy(D_01EA3078.field_2C, tmp.field_4, 32);
        strncpy(D_01EA3078.field_4C, tmp.field_8, 64);
        strncpy(D_01EA3078.field_CC, D_004C92C8, 3);
        strncpy(D_01EA3078.field_CC + 3, D_004C92C8, 3);
        D_01EA3078.field_D2 = tmp.field_20;
        D_01EA3078.field_D3 = tmp.field_21;
        D_01EA3078.field_D4 = 1;
        D_01EA3078.field_D5 = 1;
        strncpy(self->field_4, D_004C92C8, 32);
        func_00319C80(&D_01E89518, 128, 14);
    } else {
        func_00319C80(&D_01E89518, 994, 14);
        self->field_4[0] = 0;
    }
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(self->field_C4->field_C, self->field_B0, 32);
    unsigned int i;
    for (i = 0; i < strlen(self->field_C4->field_2C); i++) {
        self->field_B4[i] = 42;
    }
    self->field_B4[i] = 0;
    for (i = 0; i < strlen(self->field_4); i++) {
        self->field_B8[i] = 42;
    }
    self->field_B8[i] = 0;
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(self->field_C4->field_4C, self->field_BC, 64);
    self->field_C0 = 0;
    self->field_C2 = 7;
    int off;
    if (self->field_C9 != 0) {
        off = 0x2DA04;
        func_0037F640_inl1(&self->field_24[0], self->field_B0, &D_0051BA44, 995, 1, 2, 1);
        func_0037F640_inl1(&self->field_24[1], self->field_B4, &D_0051BA44, 129, 1, 2, 0);
    } else {
        off = 0x2DA04;
        func_0037F640_inl1(&self->field_24[0], self->field_B0, &D_0051BA44, 995, 1, 2, 0);
        func_0037F640_inl1(&self->field_24[1], self->field_B4, &D_0051BA44, 996, 1, 2, 0);
    }
    func_0037F640_inl1(&self->field_24[2], self->field_B8, &D_0051BA44, 997, 1, 2, 0);
    func_0037F640_inl1(&self->field_24[3], self->field_BC, &D_0051BA44, 998, 1, 2, 0);
    func_0037F640_inl1(&self->field_24[4], 0, &D_0051BA44, 999, 0, 6, 0);
    func_0037F640_inl1(&self->field_24[5], 0, &D_0051BA44, 1000, 0, 6, 0);
    if (self->field_C9 != 0) {
        func_0037F640_inl1(&self->field_24[6], 0, (char *)&D_004EE040 + off, 1038, 0, 0, 1);
    } else {
        func_0037F640_inl1(&self->field_24[6], 0, (char *)&D_004EE040 + off, 307, 0, 0, 1);
    }
    func_003BE5A0(&D_01E8961C, &self->field_C0, self->field_24);
    func_003BC540(&D_01E8961C, 4, self->field_C4->field_D2);
    func_003BC540(&D_01E8961C, 5, self->field_C4->field_D3);
    func_003BC360(&D_01E8961C, 6, func_0037E440(self));
    self->field_C8 = 0;
    func_003517F0(&D_01E899C0);
    RegisterKeyboardCallbacks__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
    return 1;
}
