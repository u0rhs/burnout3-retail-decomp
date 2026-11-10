// Hand-written; the lifter refused it (a152: CB3OnlineGameOptionsPage crash-stage options setup [L]; if(flag){far}else{near} order, goto entry loop, local ushort clamp).

// [L] DNAT: CB3OnlineGameOptionsPage::SetupCrashOptions-like (research/proto/new_names.csv row for 0039D5C0 is the track variant)
class CB3HardCodedCrashStageList {
public:
    static unsigned long GetCrashStageGtID(int);
};
struct UnkStruct_D_0051BF9C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E8961C {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E89810 { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_0039D900 {
    unsigned char pad_0[0x4];
    unsigned short field_4;
    unsigned short field_6;
    void * field_8;
    int field_C;
    void * field_10;
    unsigned char field_14;
    unsigned char field_15;
    unsigned char field_16;
    unsigned char pad_17;
    unsigned char * field_18;
    void * field_1C;
    int field_20;
    void * field_24;
    unsigned char field_28;
    unsigned char field_29;
    unsigned char field_2A;
    unsigned char pad_2B;
    int field_2C;
    void * field_30;
    int field_34;
    void * field_38;
    unsigned char field_3C;
    unsigned char field_3D;
    unsigned char field_3E;
    unsigned char pad_3F;
    int field_40;
    void * field_44;
    int field_48;
    void * field_4C;
    unsigned char field_50;
    unsigned char field_51;
    unsigned char field_52;
    unsigned char pad_53;
    int field_54;
    unsigned char pad_58[0x3C];
    unsigned short field_94;
    unsigned short field_96;
    unsigned char field_98[8];
    int field_A0[0x9];
    int field_C4[0x9];
    int field_E8;
    unsigned char pad_EC[0x12C];
    unsigned long field_218[0x66];
    int field_548[0x66];
    int field_6E0;
    unsigned int field_6E4;
    int field_6E8;
    int field_6EC;
    int field_6F0;
    int field_6F4;
};
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_P D_0051BA44, D_01E89800, D_004C9B30;
extern UnkStruct_D_01E8961C D_01E8961C;
extern UnkStruct_B D_01E89626;
extern UnkStruct_D_01E89810 D_01E89810;
extern int D_004C9B50[];
extern "C" unsigned long func_0039EC90(void *);
extern "C" int func_0013AD70(void *, int, int);
extern "C" int func_0013A6D0(void *, int);
extern "C" int func_003E9490(int, int);
extern "C" void *func_00271A00(void *, int);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);

static inline int func_0039D900_inl1(UnkStruct_0039D900 * self, int i)
{
    unsigned char *p = self->field_18;
    if (p == 0 || i < 0 || i > self->field_14) return 0;
    return *(unsigned char *)((char *)p + i);
}
static inline void func_0039D900_inl2(UnkStruct_0039D900 * self, int a, int b)
{
    self->field_A0[self->field_E8] = a;
    self->field_C4[self->field_E8] = b;
    self->field_E8 = self->field_E8 + 1;
}
static inline bool func_0039D900_inl3(int id, unsigned x)
{
    if (id != 8) return true;
    if (x < 2) return false;
    return true;
}

// 0x0039D900
extern "C" void func_0039D900(UnkStruct_0039D900 * self)
{
    int i;
    int prof;
    bool flag = false;
    if (self->field_6E4 == 2) flag = true;
    prof = D_0051BF9C.field_0;
    self->field_548[0] = 0x2E0;
    self->field_218[0] = func_0039EC90(self);
    self->field_6E0 = 1;
    for (i = 0; i < 100; i++) {
        if (func_0013AD70((void *)(prof), i, 0) == 0) {
            self->field_218[self->field_6E0] = CB3HardCodedCrashStageList::GetCrashStageGtID(i);
            self->field_548[self->field_6E0] = func_003E9490(i, 0);
            self->field_6E0 = self->field_6E0 + 1;
        }
    }
    unsigned short c = self->field_4;
    if (c >= 4) {
        self->field_4 = 3;
        self->field_6 = 4;
    } else {
        self->field_4 = c;
        self->field_6 = 4;
    }
    self->field_8 = func_00271A00(&D_0051BA44, 718);
    self->field_10 = &D_004C9B30;
    self->field_14 = 5;
    self->field_15 = 4;
    self->field_16 = 0;
    self->field_18 = self->field_98;
    self->field_C = 0;
    int s2 = func_0039D900_inl1(self, self->field_6E4);
    int s1 = (unsigned char)self->field_6E0;
    self->field_1C = func_00271A00(&D_0051BA44, 720);
    self->field_24 = &self->field_548[0];
    self->field_28 = s1;
    self->field_29 = 4;
    self->field_2A = s2;
    self->field_2C = 0;
    self->field_20 = 0;
    if (flag) {
        void *t = func_00271A00(&D_0051BA44, 956);
        self->field_30 = func_00271A00(&D_0051BA44, 722);
        self->field_38 = t;
        self->field_3C = 1;
        self->field_3D = 1;
        self->field_3E = 1;
        self->field_40 = 0;
        self->field_34 = 0;
    } else {
        s1 = func_0039D900_inl1(self, self->field_6E4);
        self->field_30 = func_00271A00(&D_0051BA44, 722);
        self->field_38 = &self->field_94;
        self->field_3C = self->field_96 - self->field_94;
        self->field_3D = 5;
        self->field_3E = s1;
        self->field_40 = 0;
        self->field_34 = 0;
    }
    self->field_E8 = 0;
    func_0039D900_inl2(self, 0x3D4, 0);
    func_0039D900_inl2(self, 0x3D3, 1);
    s2 = 0;
    goto test2;
body2:
    s1 = s2 + 2;
    if (func_0013A6D0((void *)(D_0051BF9C.field_0), s2)) {
        if (func_0039D900_inl3(s1, self->field_6E4)) {
            func_0039D900_inl2(self, D_004C9B50[s1], s1);
        }
    }
    s2++;
test2:
    if (s2 < 7) goto body2;
    s1 = func_0039D900_inl1(self, self->field_6E4);
    s2 = (unsigned char)self->field_E8;
    self->field_44 = func_00271A00(&D_0051BA44, 723);
    self->field_4C = &self->field_A0[0];
    self->field_50 = s2;
    self->field_51 = 4;
    self->field_52 = s1;
    self->field_54 = 0;
    self->field_48 = 0;
    if (D_01E89626.field_0 != 0) {
        ((UnkStruct_D_01E8961C *)&D_01E8961C)->vfunc_C();
    }
    func_003BE5A0(&D_01E8961C, &self->field_4, &self->field_8);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, self->field_6E4);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, self->field_6EC);
    if (!flag) {
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 2, self->field_6F0);
    }
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 3, self->field_6F4);
    if (func_0039D900_inl1(self, self->field_6E4)) {
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 & ~0x10UL, 3);
    } else {
        SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, D_01E89810.field_0 | 0x10, 3);
    }
}
