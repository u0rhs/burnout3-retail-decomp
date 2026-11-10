// Hand-written; the lifter refused it (a169: matched; [L] DNAT CB3CreateAccount1MenuPage::OnKeyboardDone (low row, name uncertain). default: shares the ok block (switch default -> ok), early exits via goto out, error block as static inline).

// Hand-written (a169): func_0037E680 -- CB3CreateAccount1MenuPage keyboard-done validation [L] DNAT row (low) -- lifter refused.
extern "C" unsigned int strlen(const char *);
extern "C" int strcasecmp(const char *, const char *);
extern "C" char *strchr(const char *, int);
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_Byte16 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_Ptr16 { void *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_Pad16 D_01E899C0, D_01E898E8, D_01E8961C;
extern UnkStruct_D_Byte16 D_01E899DC;
extern UnkStruct_D_Ptr16 D_01E8CA94;
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(void *, char *, int);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(void *, int, void *);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, unsigned int);
extern "C" void Show__28CB3OnScreenKeyboardComponentFbb(void *, bool, bool);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_0037E440(void *);
extern "C" void func_003BC360(void *, int, int);
struct UnkStruct_a169_info {
    unsigned char pad_0[0xC];
    char field_C[0x20];
    char field_2C[0x20];
    char field_4C[0x80];
};
struct UnkStruct_a169 {
    unsigned char pad_0[4];
    char field_4[0x20];
    unsigned char pad_24[0x8C];
    void *field_B0;
    unsigned short *field_B4;
    unsigned short *field_B8;
    void *field_BC;
    unsigned short field_C0;
    unsigned char pad_C2[2];
    UnkStruct_a169_info *field_C4;
    unsigned char field_C8;
};
static inline void a169_err(UnkStruct_a169 *self, int id)
{
    self->field_C8 = 2;
    Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, false, false);
    func_0032D080(&D_01E898E8, 2, id, 0, 0);
    func_003BC360(&D_01E8961C, 6, func_0037E440(self));
}
// 0x0037E680
extern "C" void func_0037E680(UnkStruct_a169 *self)
{
    int i;
    if (self->field_C8 != 1) goto out;
    switch (self->field_C0) {
    case 0:
        ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, self->field_C4->field_C, 0x20);
        CopyN__10CGtUnicodeFPUsiPCUs(self->field_B0, 0x20, D_01E8CA94.field_0);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, 0);
        if (strlen(self->field_C4->field_C) > 0x10 || strlen(self->field_C4->field_C) < 4) {
            a169_err(self, 0x3E9);
            goto out;
        }
        {
            int c = self->field_C4->field_C[0];
            if (c < 0x30 || c >= 0x3A) goto ok;
        }
        a169_err(self, 0x3EA);
        break;
    case 1:
        ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, self->field_C4->field_2C, 0x20);
        for (i = 0; i < strlen(self->field_C4->field_2C); i++) {
            self->field_B4[i] = 0x2A;
        }
        self->field_B4[i] = 0;
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, 0);
        D_01E899DC.field_0 = 0;
        if (strlen(self->field_C4->field_2C) > 0x10 || strlen(self->field_C4->field_2C) < 4) {
            a169_err(self, 0x3EB);
            goto out;
        }
        D_01E899DC.field_0 = 0;
        if (strlen(self->field_C4->field_2C) == 0) goto ok;
        if (strlen(self->field_4) == 0) goto ok;
        if (strcasecmp(self->field_C4->field_2C, self->field_4) == 0) goto ok;
        a169_err(self, 0x3EC);
        goto out;
    case 2:
        ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, self->field_4, 0x20);
        for (i = 0; i < strlen(self->field_4); i++) {
            self->field_B8[i] = 0x2A;
        }
        self->field_B8[i] = 0;
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 2, 0);
        if (strlen(self->field_4) > 0x10 || strlen(self->field_4) < 4) {
            a169_err(self, 0x3EB);
            goto out;
        }
        D_01E899DC.field_0 = 0;
        if (strlen(self->field_C4->field_2C) == 0) goto ok;
        if (strlen(self->field_4) == 0) goto ok;
        if (strcasecmp(self->field_C4->field_2C, self->field_4) == 0) goto ok;
        a169_err(self, 0x3EC);
        goto out;
    case 3:
        ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, self->field_C4->field_4C, 0x40);
        CopyN__10CGtUnicodeFPUsiPCUs(self->field_BC, 0x40, D_01E8CA94.field_0);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 3, 0);
        if (strlen(self->field_C4->field_4C) < 6) {
            a169_err(self, 0x3ED);
            goto out;
        }
        if (strchr(self->field_C4->field_4C, '.') == 0 || strchr(self->field_C4->field_4C, '@') == 0) {
            a169_err(self, 0x3EE);
            goto out;
        }
        {
            UnkStruct_a169_info *s = self->field_C4;
            if (s->field_4C[strlen(s->field_4C) - 1] == '.' || self->field_C4->field_4C[strlen(s->field_4C) - 1] == '@') {
                a169_err(self, 0x3EE);
                break;
            }
        }
    default:
    ok:
        self->field_C8 = 0;
        Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, false, false);
        func_003BC360(&D_01E8961C, 6, func_0037E440(self));
        goto out;
    }
out:
    return;
}
