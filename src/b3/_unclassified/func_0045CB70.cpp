// Hand-written; the lifter refused it (s323: func_0037E680 case-3 clone (switch default:ok, error exits return, last error break)).

// s323: rewritten on sibling func_0037E680 case 3 (switch on field_B8 with default: ok shared block, error exits via return, break after the last-char error).

// func_0045CB70 -- placeholder (a184, hand-matched). Email-address entry page: validate and report.
struct UnkStruct_D_16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E8CA94 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_0045CB70_rec {
    unsigned char pad_0[0x8C];
    char field_8C[0x40];
};
struct UnkStruct_0045CB70 {
    unsigned char pad_0[0xB8];
    unsigned short field_B8;
    unsigned char pad_BA[2];
    UnkStruct_0045CB70_rec * field_BC;
    unsigned char pad_C0[0x10];
    void * field_D0;
    unsigned char pad_D4[0x8];
    signed char field_DC;
    signed char field_DD;
};
extern UnkStruct_D_01E8CA94 D_01E8CA94;
extern UnkStruct_D_16 D_01E8961C, D_01E899C0, D_01E898E8;
extern "C" unsigned int strlen(const char *);
extern "C" char * strchr(const char *, int);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(int, void *, int);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(void *, int, int);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);
extern "C" void Show__28CB3OnScreenKeyboardComponentFbb(void *, bool, bool);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void func_003BC360(void *, int, bool);

static inline bool func_0045CB70_inl0(UnkStruct_0045CB70 * self)
{
    if (strlen(self->field_BC->field_8C) < 6) return false;
    if (strchr(self->field_BC->field_8C, 0x2E) == 0 || strchr(self->field_BC->field_8C, 0x40) == 0) return false;
    UnkStruct_0045CB70_rec * r = self->field_BC;
    if (r->field_8C[strlen(r->field_8C) - 1] == 0x2E || self->field_BC->field_8C[strlen(r->field_8C) - 1] == 0x40) return false;
    return true;
}

static inline void func_0045CB70_inl1(UnkStruct_0045CB70 * self, int code)
{
    self->field_DC = 3;
    self->field_DD = self->field_DC;
    Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, false, false);
    func_0032D080(&D_01E898E8, 2, code, 0, 0);
    func_003BC360(&D_01E8961C, 1, func_0045CB70_inl0(self));
}

static inline void func_0045CB70_inl2(UnkStruct_0045CB70 * self)
{
    self->field_DC = 6;
    Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, false, false);
    func_003BC360(&D_01E8961C, 1, func_0045CB70_inl0(self));
}

// 0x0045CB70
extern "C" void func_0045CB70(UnkStruct_0045CB70 * self)
{
    if (self->field_DC != 1) goto out;
    switch (self->field_B8) {
    case 0:
        ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, self->field_BC->field_8C, 0x40);
        CopyN__10CGtUnicodeFPUsiPCUs(self->field_D0, 0x40, D_01E8CA94.field_0);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 0, 0);
        if (strlen(self->field_BC->field_8C) < 6) {
            func_0045CB70_inl1(self, 0x3ED);
            return;
        }
        if (strchr(self->field_BC->field_8C, '.') == 0 || strchr(self->field_BC->field_8C, '@') == 0) {
            func_0045CB70_inl1(self, 0x3EE);
            return;
        }
        {
            UnkStruct_0045CB70_rec *s = self->field_BC;
            if (s->field_8C[strlen(s->field_8C) - 1] == '.' || self->field_BC->field_8C[strlen(s->field_8C) - 1] == '@') {
                func_0045CB70_inl1(self, 0x3EE);
                break;
            }
        }
    default:
    ok:
        func_0045CB70_inl2(self);
        return;
    }
out:
    return;
}
