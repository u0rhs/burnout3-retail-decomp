// Hand-written; the lifter refused it (SelectLogin keyboard-accept: close/err/inl helpers, goto labels inside switch placed after each case, good1 break).

struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E89626 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E898F2 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E899DC { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_01E8CA94 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E8961C { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E8D4F0 { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E3CD44 { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(char *); unsigned char pad_4[0xC]; };
class CB3OnScreenKeyboardComponent { public: void Show(bool, bool); unsigned char pad_0[0x10]; };
struct UnkStruct_Sel {
    unsigned char pad_0[0x4];
    char field_4[0x32];
    char field_36[0x32];
    unsigned char pad_68[0x8];
    unsigned char field_70;
    unsigned char field_71;
    unsigned char field_72;
    unsigned char pad_73[0x7D];
    int field_F0;
    unsigned char pad_F4[0x68];
    int field_15C;
    unsigned short *field_160;
};
extern UnkStruct_D_01E89626 D_01E89626;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E899DC D_01E899DC;
extern UnkStruct_D_01E8CA94 D_01E8CA94;
extern UnkStruct_D_01E8961C D_01E8961C;
extern UnkStruct_D_01E8D4F0 D_01E8D4F0;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_P D_01E898E8, D_004C6EB0;
extern "C" unsigned int strlen(const char *);
extern "C" int strcmp(const char *, const char *);
extern "C" char *strcpy(char *, const char *);
extern "C" char *strchr(const char *, int);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(int, void *, int);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(int, int, int);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" void func_003BC360(void *, int, bool);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, unsigned int);

static inline bool func_00347940_inl1(UnkStruct_Sel *self)
{
    if (strlen(self->field_4) < 4 || strlen(self->field_4) >= 17) return false;
    if (self->field_4[0] < '0' || self->field_4[0] > '9') return true;
    return false;
}
static inline bool func_00347940_inl2(UnkStruct_Sel *self)
{
    if (strlen(self->field_4) < 4 || strlen(self->field_4) >= 17) return false;
    if (self->field_4[0] >= '0' && self->field_4[0] <= '9') return false;
    if (strlen(self->field_36) > 16 || strlen(self->field_36) < 4) return false;
    if (strcmp(self->field_4, (const char *)&D_004C6EB0) == 0 || strcmp(self->field_36, (const char *)&D_004C6EB0) == 0) return false;
    return true;
}
static inline void func_00347940_inl3(UnkStruct_Sel *self)
{
    func_003BC360(&D_01E8961C, 4, func_00347940_inl2(self));
    func_003BC360(&D_01E8961C, 2, func_00347940_inl1(self));
}
static inline void func_00347940_err(UnkStruct_Sel *self, int k)
{
    self->field_71 = self->field_70;
    self->field_70 = 4;
    func_0032D080(&D_01E898E8, 2, k, 0, 0);
}
static inline void func_00347940_close(UnkStruct_Sel *self)
{
    if (D_01E89626.field_0 != 0) {
        ((UnkStruct_D_01E8961C *)&D_01E8961C)->vfunc_C();
    }
    func_003BE5A0(&D_01E8961C, ((char *)self + 0xF0), ((char *)self + 0xF8));
    if (self->field_72 == 2) {
        D_01E899DC.field_0 = 0;
    }
    self->field_72 = 0;
    D_01E899C0.Show(0, 0);
}

// 0x00347940
extern "C" void func_00347940(UnkStruct_Sel *self)
{
    char buf[0x40];
    switch (self->field_72) {
    case 1:
        func_00347940_close(self);
        ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, buf, 0x32);
        CopyN__10CGtUnicodeFPUsiPCUs(self->field_15C, 0x20, D_01E8CA94.field_0);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, 0);
        strcpy(self->field_4, buf);
        if (strlen(self->field_4) >= 17 || strlen(self->field_4) < 4) {
            func_00347940_err(self, 0x3E9);
            func_00347940_inl3(self);
            func_003BC360(&D_01E8961C, 2, 0);
            return;
        }
        if (self->field_4[0] < '0' || self->field_4[0] > '9') goto good1;
        func_00347940_err(self, 0x3EA);
        func_00347940_inl3(self);
        func_003BC360(&D_01E8961C, 2, 0);
        return;
    good1:
        func_003BC360(&D_01E8961C, 2, 0);
        func_00347940_inl3(self);
        break;
    case 2: {
        func_00347940_close(self);
        ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, buf, 0x32);
        unsigned int i;
        for (i = 0; i < strlen(buf); i++) {
            self->field_160[i] = '*';
        }
        self->field_160[i] = 0;
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, 0);
        strcpy(self->field_36, buf);
        if (strlen(self->field_36) >= 17 || strlen(self->field_36) < 4) {
            func_00347940_err(self, 0x3EB);
            func_00347940_inl3(self);
            return;
        }
        func_00347940_inl3(self);
        break;
    }
    case 3:
        func_00347940_close(self);
        ((UnkStruct_D_01E8D4F0 *)&D_01E8D4F0)->vfunc_C();
        ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, buf, 0x40);
        if (strlen(buf) < 6) goto bad3ED;
        if (strchr(buf, '.') == 0 || strchr(buf, '@') == 0) goto bad3EEa;
        {
            char *b = buf - 1;
            if (b[strlen(buf)] == '.' || b[strlen(buf)] == '@') goto bad3EEb;
        }
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_88(buf);
        self->field_70 = 2;
        func_0032D080(&D_01E898E8, 0, 0x4F, 0xF, 0);
        break;
    bad3ED:
        func_00347940_err(self, 0x3ED);
        return;
    bad3EEa:
        func_00347940_err(self, 0x3EE);
        return;
    bad3EEb:
        func_00347940_err(self, 0x3EE);
        return;
    default:
        break;
    }
}
